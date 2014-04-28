#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <float.h>

#include <boost/thread/thread.hpp>

#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
#include "nist_kitting/prim_robot_cmd.h"
#include "nist_kitting/prim_robot_stat.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/crcl_client.h"

#define NODE_NAME_LEN 80
#define NODE_NAME_DEFAULT "kitting_prim_robot"
#define HOST_NAME_LEN 80
#define HOST_NAME_DEFAULT "localhost"
#define PORT_DEFAULT 1234
#define PERIOD_DEFAULT 0.05

static int debug = 0;

static nist_kitting::prim_robot_cmd prim_robot_cmd_buf;

static void prim_robot_cmd_callback(const nist_kitting::prim_robot_cmd::ConstPtr& msg)
{
  prim_robot_cmd_buf = *msg;

  if (debug) ROS_INFO("Got %s (%d)", kitting_cmd_to_string(prim_robot_cmd_buf.cmd.type), (int) prim_robot_cmd_buf.cmd.serial_number);
}

static void do_cmd_kitting_nop(nist_kitting::prim_robot_stat &prim_robot_stat)
{
  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    prim_robot_stat.stat.state = RCS_STATE_S0;
    prim_robot_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_init(nist_kitting::prim_robot_stat &prim_robot_stat)
{
  static double dcount;

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
    dcount = 3;			// take 3 seconds to fake an init
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    dcount -= prim_robot_stat.stat.period;
    if (dcount <= 0) {
      prim_robot_stat.stat.state = RCS_STATE_S0;
      prim_robot_stat.stat.status = RCS_STATUS_DONE;
    }
  }
  // else S0
}

static void do_cmd_halt(nist_kitting::prim_robot_stat &prim_robot_stat)
{
  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    prim_robot_stat.stat.state = RCS_STATE_S0;
    prim_robot_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static robotPose rosToCrcl(geometry_msgs::Pose &pose)
{
  robotPose rp;

  rp.position.x = pose.position.x;
  rp.position.y = pose.position.y;
  rp.position.z = pose.position.z;
  rp.orientation.x = pose.orientation.x;
  rp.orientation.y = pose.orientation.y;
  rp.orientation.z = pose.orientation.z;
  rp.orientation.w = pose.orientation.w;

  return rp;
}

static geometry_msgs::Pose crclToRos(robotPose pose)
{
  geometry_msgs::Pose rp;

  rp.position.x = pose.position.x;
  rp.position.y = pose.position.y;
  rp.position.z = pose.position.z;
  rp.orientation.x = pose.orientation.x;
  rp.orientation.y = pose.orientation.y;
  rp.orientation.z = pose.orientation.z;
  rp.orientation.w = pose.orientation.w;

  return rp;
}

static boost::thread *cmdExecThr = NULL;

static void do_cmd_prim_robot_moveto(geometry_msgs::Pose &pose, CRCL_Client &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    robotPose rp;
    if (debug) ROS_INFO("Moving to %f ...", pose.position.x);
    rp = rosToCrcl(pose);
    if (NULL != cmdExecThr) {
      cmdExecThr->interrupt();
      delete cmdExecThr;
    }
    cmdExecThr = new boost::thread(&CRCL_Client::MoveStraightTo, &client, rp);
    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (cmdExecThr->timed_join(boost::get_system_time())) {
      delete cmdExecThr;
      result = client.getResult();
      if (CANON_SUCCESS == result) {
	prim_robot_stat.stat.status = RCS_STATUS_DONE;
      } else if (CANON_FAILURE == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      } else if (CANON_REJECT == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      }
      prim_robot_stat.stat.state = RCS_STATE_S0;
    } // else keep waiting
  }
  // else S0
}

static void do_cmd_prim_robot_stop(int condition, CRCL_Client &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (NULL != cmdExecThr) {
      cmdExecThr->interrupt();
      delete cmdExecThr;
    }
    cmdExecThr = new boost::thread(&CRCL_Client::StopMotion, &client, condition);
    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (cmdExecThr->timed_join(boost::get_system_time())) {
      delete cmdExecThr;
      result = client.getResult();
      if (CANON_SUCCESS == result) {
	prim_robot_stat.stat.status = RCS_STATUS_DONE;
      } else if (CANON_FAILURE == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      } else if (CANON_REJECT == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      }
      prim_robot_stat.stat.state = RCS_STATE_S0;
    } // else keep waiting
  }
  // else S0
}

static void do_cmd_prim_robot_open_gripper(CRCL_Client &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (NULL != cmdExecThr) {
      cmdExecThr->interrupt();
      delete cmdExecThr;
    }
    cmdExecThr = new boost::thread(&CRCL_Client::SetTool, &client, 1);
    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (cmdExecThr->timed_join(boost::get_system_time())) {
      delete cmdExecThr;
      result = client.getResult();
      if (CANON_SUCCESS == result) {
	prim_robot_stat.stat.status = RCS_STATUS_DONE;
      } else if (CANON_FAILURE == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      } else if (CANON_REJECT == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      }
      prim_robot_stat.stat.state = RCS_STATE_S0;
    } // else keep waiting
  }
  // else S0
}

static void do_cmd_prim_robot_close_gripper(CRCL_Client &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (NULL != cmdExecThr) {
      cmdExecThr->interrupt();
      delete cmdExecThr;
    }
    cmdExecThr = new boost::thread(&CRCL_Client::SetTool, &client, 0);
    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (cmdExecThr->timed_join(boost::get_system_time())) {
      delete cmdExecThr;
      result = client.getResult();
      if (CANON_SUCCESS == result) {
	prim_robot_stat.stat.status = RCS_STATUS_DONE;
      } else if (CANON_FAILURE == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      } else if (CANON_REJECT == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      }
      prim_robot_stat.stat.state = RCS_STATE_S0;
    } // else keep waiting
  }
  // else S0
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -n <name>    : set the node name\n");
  printf("  -p <period>  : set the period\n");
  printf("  -h <host>    : connect to host robot controller\n");
  printf("  -c <port>    : command TCP port of robot controller\n");
  printf("  -s <port>    : status TCP port of robot controller\n");
  printf("  -d           : turn debug on\n");
  printf("  -?           : print this help>\n");
}

static void quit(int sig)
{
  exit(0);
}

int main(int argc, char **argv)
{
  int ros_argc;
  char **ros_argv;
  char node_name[NODE_NAME_LEN] = NODE_NAME_DEFAULT;
  char host_name[HOST_NAME_LEN] = HOST_NAME_DEFAULT;
  int cmd_port = CRCL_CLIENT_CMD_PORT_DEFAULT;
  int stat_port = CRCL_CLIENT_STAT_PORT_DEFAULT;
  int retval;
  int option;
  int ival;
  double dval;
  nist_kitting::prim_robot_stat prim_robot_stat_buf;

  prim_robot_stat_buf.stat.period = PERIOD_DEFAULT;
  prim_robot_stat_buf.gripper.closed = false;
  prim_robot_stat_buf.gripper.value = 0;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":n:p:h:c:s:d?");
    if (option == -1)
      break;

    switch (option) {
    case 'n':
      // first check for valid name
      if (optarg[0] == '-') {
	fprintf(stderr, "invalid node name: %s\n", optarg);
	return 1;
      }
      strncpy(node_name, optarg, NODE_NAME_LEN-1);
      node_name[NODE_NAME_LEN-1] - 0;
      break;

    case 'p':
      dval = atof(optarg);
      if (dval < FLT_EPSILON) {
	fprintf(stderr, "bad value for period: %s\n", optarg);
	return 1;
      }
      prim_robot_stat_buf.stat.period = dval;
      break;

    case 'h':
      strncpy(host_name, optarg, HOST_NAME_LEN-1);
      host_name[HOST_NAME_LEN-1] - 0;
      break;

    case 'c':
      ival = atoi(optarg);
      if (ival < 0) {
	fprintf(stderr, "bad value for command port: %s\n", optarg);
	return 1;
      }
      cmd_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      if (ival < 0) {
	fprintf(stderr, "bad value for status port: %s\n", optarg);
	return 1;
      }
      stat_port = ival;
      break;

    case '?':
      print_help();
      return 0;
      break;

    case 'd':
      debug = 1;
      break;

    case ':':
      fprintf(stderr, "missing value for -%c\n", optopt);
      return 1;
      break;

    default:
      fprintf (stderr, "unrecognized option -%c\n", optopt);
      return 1;
      break;
    }
  }

  // pass everything after a '--' separator to ROS
  ros_argc = argc - optind;
  ros_argv = &argv[optind];
  ros::init(ros_argc, ros_argv, node_name);

  ros::NodeHandle nh;
  ros::Subscriber prim_robot_cmd_sub;
  ros::Publisher prim_robot_stat_pub;
  ros::Rate loop_rate(1.0 / prim_robot_stat_buf.stat.period);

  prim_robot_cmd_sub = nh.subscribe(KITTING_PRIM_ROBOT_CMD_TOPIC, TOPIC_QUEUE_LEN, prim_robot_cmd_callback);
  prim_robot_stat_pub = nh.advertise<nist_kitting::prim_robot_stat>(KITTING_PRIM_ROBOT_STAT_TOPIC, TOPIC_QUEUE_LEN);

  // stuff a NOP command
  prim_robot_stat_buf.stat.type = prim_robot_cmd_buf.cmd.type = KITTING_NOP;
  prim_robot_stat_buf.stat.serial_number = prim_robot_cmd_buf.cmd.serial_number = 0;
  prim_robot_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
  prim_robot_stat_buf.stat.status = RCS_STATUS_EXEC; 
  prim_robot_stat_buf.stat.heartbeat = 0;

  // connect to host robot controller
  CRCL_Client client(host_name, cmd_port, stat_port);

  if (! client.isConnected()) {
    fprintf(stderr, "can't connect to CRCL server %s on ports %d, %d\n", host_name, cmd_port, stat_port);
    return 1;
  }

  robotPose clientPose;
  boost::thread *clientPoseThr = new boost::thread(&CRCL_Client::GetRobotPose, &client, &clientPose);

  signal(SIGINT, quit);

  double start, end, last_start = etime() - prim_robot_stat_buf.stat.period;

  while (true) {
    ros::spinOnce();
    start = etime();
    prim_robot_stat_buf.stat.cycle = start - last_start;
    last_start = start;

    if (prim_robot_stat_buf.stat.serial_number != prim_robot_cmd_buf.cmd.serial_number) {
      prim_robot_stat_buf.stat.type = prim_robot_cmd_buf.cmd.type;
      prim_robot_stat_buf.stat.serial_number = prim_robot_cmd_buf.cmd.serial_number;
      prim_robot_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
      prim_robot_stat_buf.stat.status = RCS_STATUS_EXEC; 
    }

    switch (prim_robot_cmd_buf.cmd.type) {
    case KITTING_NOP:
      do_cmd_kitting_nop(prim_robot_stat_buf);
      break;
    case KITTING_INIT:
      do_cmd_kitting_init(prim_robot_stat_buf);
      break;
    case KITTING_HALT:
      do_cmd_halt(prim_robot_stat_buf);
      break;
    case KITTING_PRIM_ROBOT_MOVETO:
      do_cmd_prim_robot_moveto(prim_robot_cmd_buf.moveto.pose, client, prim_robot_stat_buf);
    case KITTING_PRIM_ROBOT_STOP:
      do_cmd_prim_robot_stop(prim_robot_cmd_buf.stop.condition, client, prim_robot_stat_buf);
      break;
    case KITTING_PRIM_ROBOT_OPEN_GRIPPER:
      do_cmd_prim_robot_open_gripper(client, prim_robot_stat_buf);
      break;
    case KITTING_PRIM_ROBOT_CLOSE_GRIPPER:
      do_cmd_prim_robot_close_gripper(client, prim_robot_stat_buf);
      break;
    default:
      if (debug) printf("unrecognized command: %s\n", kitting_cmd_to_string(prim_robot_cmd_buf.cmd.type));
      break;
    }

    prim_robot_stat_buf.stat.heartbeat++;
    end = etime();
    prim_robot_stat_buf.stat.duration = etime() - start;
    if (clientPoseThr->timed_join(boost::get_system_time())) {
      if (debug) printf("GetRobotPose: %f %f %f ...\n",
			clientPose.position.x,
			clientPose.position.y,
			clientPose.position.z);
      if (client.getResult() == CANON_SUCCESS) prim_robot_stat_buf.pose = crclToRos(clientPose);
      // start a new one
      delete clientPoseThr;
      clientPoseThr = new boost::thread(&CRCL_Client::GetRobotPose, &client, &clientPose);
    }
    prim_robot_stat_pub.publish(prim_robot_stat_buf);

    loop_rate.sleep();
  }

  return 0;
}
