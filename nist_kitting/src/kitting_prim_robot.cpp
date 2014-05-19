#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <float.h>
#include <signal.h>

#include <ulapi.h>

#include <ros/ros.h>
#include <ros/console.h>

#include <nist_core/crcl.h>
#include <nist_core/crcl_client.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
#include "nist_kitting/prim_robot_cmd.h"
#include "nist_kitting/prim_robot_stat.h"

using namespace std;

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

  if (debug) ROS_DEBUG("Got %s (%d)", kitting_cmd_to_string(prim_robot_cmd_buf.cmd.type), (int) prim_robot_cmd_buf.cmd.serial_number);
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

  rp.x = pose.position.x;
  rp.y = pose.position.y;
  rp.z = pose.position.z;
  // FIXME -- ROS poses use quaternions
  rp.xrot = pose.orientation.x;
  rp.yrot = pose.orientation.y;
  rp.zrot = pose.orientation.z;

  return rp;
}

static geometry_msgs::Pose crclToRos(robotPose pose)
{
  geometry_msgs::Pose rp;

  rp.position.x = pose.x;
  rp.position.y = pose.y;
  rp.position.z = pose.z;
  // FIXES -- ROS poses use quaternions
  rp.orientation.x = pose.xrot;
  rp.orientation.y = pose.yrot;
  rp.orientation.z = pose.zrot;
  rp.orientation.w = 1;

  return rp;
}

using namespace crcl_robot;

struct moveto_task_args {
  CrclClient *client;
  robotPose pose;
};

static void moveto_task_code(moveto_task_args *args)
{
  CrclClient *client = args->client;
  robotPose pose = args->pose;
  delete args;

  client->MoveStraightTo(pose);
}

struct stop_task_args {
  CrclClient *client;
  int condition;
};

static void stop_task_code(stop_task_args *args)
{
  CrclClient *client = args->client;
  int condition = args->condition;
  delete args;

  client->StopMotion(condition);
}

struct set_tool_task_args {
  CrclClient *client;
  double percent;
};

static void set_tool_task_code(set_tool_task_args *args)
{
  CrclClient *client = args->client;
  double percent = args->percent;
  delete args;

  client->SetTool(percent);
}

static ulapi_task_struct *cmdExecThr = NULL;

static void do_cmd_prim_robot_moveto(geometry_msgs::Pose &pose, CrclClient &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  moveto_task_args *args;

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    robotPose rp;
    if (debug) ROS_DEBUG("Moving to %.2f ...", pose.position.x);
    rp = rosToCrcl(pose);
    if (NULL != cmdExecThr) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
    }
    cmdExecThr = ulapi_task_new();
    client.startCmd();

    args = new moveto_task_args;
    args->client = &client, args->pose = rp;
    ulapi_task_start(cmdExecThr, reinterpret_cast<ulapi_task_code>(moveto_task_code), reinterpret_cast<void *>(args), ulapi_prio_highest(), 0);

    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (client.cmdDone()) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
      cmdExecThr = NULL;
      result = client.getCmdResult();
      if (CANON_SUCCESS == result) {
	prim_robot_stat.stat.status = RCS_STATUS_DONE;
      } else if (CANON_FAILURE == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      } else if (CANON_REJECT == result) {
	prim_robot_stat.stat.status = RCS_STATUS_ERROR;
      } else {
	if (debug) ROS_DEBUG("Bad result from client: %d", result);
      }
      prim_robot_stat.stat.state = RCS_STATE_S0;
    } // else keep waiting
  }
  // else S0
}

static void do_cmd_prim_robot_stop(int condition, CrclClient &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  stop_task_args *args;

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (NULL != cmdExecThr) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
    }
    cmdExecThr = ulapi_task_new();
    client.startCmd();

    args = new stop_task_args;
    args->client = &client, args->condition = condition;
    ulapi_task_start(cmdExecThr, reinterpret_cast<ulapi_task_code>(stop_task_code), reinterpret_cast<void *>(args), ulapi_prio_highest(), 0);

    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (client.cmdDone()) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
      cmdExecThr = NULL;
      result = client.getCmdResult();
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

static void do_cmd_prim_robot_open_gripper(CrclClient &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  set_tool_task_args *args;

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (NULL != cmdExecThr) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
    }
    cmdExecThr = ulapi_task_new();
    client.startCmd();

    args = new set_tool_task_args;
    args->client = &client;
    args->percent = 0;
    ulapi_task_start(cmdExecThr, reinterpret_cast<ulapi_task_code>(set_tool_task_code), reinterpret_cast<void *>(args), ulapi_prio_highest(), 0);

    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (client.cmdDone()) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
      cmdExecThr = NULL;
      result = client.getCmdResult();
      if (CANON_SUCCESS == result) {
	// FIXME -- set this, and 'value', from a status message
	prim_robot_stat.gripper.closed = false;
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

static void do_cmd_prim_robot_close_gripper(CrclClient &client, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  set_tool_task_args *args;

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (NULL != cmdExecThr) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
    }
    cmdExecThr = ulapi_task_new();
    client.startCmd();

    args = new set_tool_task_args;
    args->client = &client;
    args->percent = 100;
    ulapi_task_start(cmdExecThr, reinterpret_cast<ulapi_task_code>(set_tool_task_code), reinterpret_cast<void *>(args), ulapi_prio_highest(), 0);

    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    CanonReturn result;
    if (client.cmdDone()) {
      ulapi_task_stop(cmdExecThr);
      ulapi_task_delete(cmdExecThr);
      cmdExecThr = NULL;
      result = client.getCmdResult();
      if (CANON_SUCCESS == result) {
	prim_robot_stat.gripper.closed = true;
	// FIXME -- set this, and 'value', from a status message
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

struct client_stat_task_args {
  CrclClient *client_ptr;
  robotPose *pose_ptr;
  robotAxes *axes_ptr;
  double *tool_setting_ptr;
};

static void client_stat_task_code(client_stat_task_args *args)
{
  CrclClient *client = args->client_ptr;
  robotPose *pose_ptr = args->pose_ptr;
  robotAxes *axes_ptr = args->axes_ptr;
  double *tool_setting_ptr = args->tool_setting_ptr;

  client->GetStatus(pose_ptr, axes_ptr, tool_setting_ptr);
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
  exit(sig);
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
	fprintf(stderr, "Invalid node name: %s\n", optarg);
	return 1;
      }
      strncpy(node_name, optarg, NODE_NAME_LEN-1);
      node_name[NODE_NAME_LEN-1] - 0;
      break;

    case 'p':
      dval = atof(optarg);
      if (dval < FLT_EPSILON) {
	fprintf(stderr, "Bad value for period: %s\n", optarg);
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
	fprintf(stderr, "Bad value for command port: %s\n", optarg);
	return 1;
      }
      cmd_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      if (ival < 0) {
	fprintf(stderr, "Bad value for status port: %s\n", optarg);
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
      fprintf(stderr, "Missing value for -%c\n", optopt);
      return 1;
      break;

    default:
      fprintf(stderr, "unrecognized option -%c\n", optopt);
      return 1;
      break;
    }
  }

  // pass everything after a '--' separator to ROS
  ros_argc = argc - optind;
  ros_argv = &argv[optind];

  try {
    ros::init(ros_argc, ros_argv, node_name);
  }
  catch (...) {
    cerr << "ros::init(): general exception" << endl;
    return 1;
  }

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
  CrclClient client;
  if (! client.connect(host_name, cmd_port, stat_port)) {
    ROS_INFO("Can't connect to CRCL server %s on ports %d, %d", host_name, cmd_port, stat_port);
    return 1;
  }

  robotPose clientPose;
  robotAxes clientAxes;
  double toolSetting;
  client_stat_task_args args;
  ulapi_task_struct *clientStatThr;

  // these are constant, so no need to new/delete the args each time
  args.client_ptr = &client, args.pose_ptr = &clientPose, args.axes_ptr = &clientAxes, args.tool_setting_ptr = &toolSetting;

  client.startStat();
  clientStatThr = ulapi_task_new();
  ulapi_task_start(clientStatThr, reinterpret_cast<ulapi_task_code>(client_stat_task_code), reinterpret_cast<void *>(&args), ulapi_prio_highest(), 0);

  double start, end, last_start = ulapi_time() - prim_robot_stat_buf.stat.period;

  signal(SIGINT, quit);

  while (true) {
    ros::spinOnce();
    start = ulapi_time();
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
      if (debug) ROS_DEBUG("Unrecognized command: %s", kitting_cmd_to_string(prim_robot_cmd_buf.cmd.type));
      break;
    }

    if (client.statDone()) {
      if (debug) ROS_DEBUG("statDone\n");
      if (CANON_SUCCESS == client.getStatResult()) {
	prim_robot_stat_buf.pose = crclToRos(clientPose);
	//
	prim_robot_stat_buf.axes.axis[0] = clientAxes.axis[0];
	prim_robot_stat_buf.axes.axis[1] = clientAxes.axis[1];
	prim_robot_stat_buf.axes.axis[2] = clientAxes.axis[2];
	prim_robot_stat_buf.axes.axis[3] = clientAxes.axis[3];
	prim_robot_stat_buf.axes.axis[4] = clientAxes.axis[4];
	prim_robot_stat_buf.axes.axis[5] = clientAxes.axis[5];
	//
	prim_robot_stat_buf.gripper.value = toolSetting;
	if (debug) ROS_DEBUG("GetStat: %.2f %.2f ... %.2f %.2f ... %.2f",
			     clientPose.x,
			     clientPose.y,
			     clientPose.z,
			     clientAxes.axis[0],
			     clientAxes.axis[1],
			     clientAxes.axis[2],
			     toolSetting);
      }
      // start a new one
      ulapi_task_stop(clientStatThr);
      ulapi_task_delete(clientStatThr);

      client.startStat();
      clientStatThr = ulapi_task_new();
      ulapi_task_start(clientStatThr, reinterpret_cast<ulapi_task_code>(client_stat_task_code), reinterpret_cast<void *>(&args), ulapi_prio_highest(), 0);
    } // client.statDone()

    prim_robot_stat_buf.stat.heartbeat++;
    end = ulapi_time();
    prim_robot_stat_buf.stat.duration = ulapi_time() - start;

    prim_robot_stat_pub.publish(prim_robot_stat_buf);

    loop_rate.sleep();
  } // while (true) main loop

  return 0;
}
