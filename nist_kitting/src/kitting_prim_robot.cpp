#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <getopt.h>
#include <signal.h>
#include <string.h>
#include <float.h>

#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/prim_robot_cmd.h"
#include "nist_kitting/prim_robot_stat.h"
#include "nist_kitting/socket_utils.h"
#include "nist_kitting/crcl_robot.h"

#define NODE_NAME_LEN 80
#define NODE_NAME_DEFAULT "kitting_prim_robot"
#define PERIOD_DEFAULT 0.05

// the socket server connected to the robot hardware
#define HOST_NAME_LEN 80
#define HOST_NAME_DEFAULT "localhost"

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

static void do_cmd_kitting_prim_robot_moveto(geometry_msgs::Pose &pose, int socket_id, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;

  if (prim_robot_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    socket_snprintf(outbuf, sizeof(outbuf),
		    "MOVETO(%f,%f,%f,%f,%f,%f,%f)", 
		    pose.position.x, pose.position.y, pose.position.z,
		    pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w);
    nchars = socket_write(socket_id, outbuf, strlen(outbuf) + 1);
    if (debug) ROS_INFO("Moving to %f ...\n", pose.position.x);
    prim_robot_stat.stat.state = RCS_STATE_S1;
    prim_robot_stat.stat.status = RCS_STATUS_EXEC;
  } else if (prim_robot_stat.stat.state == RCS_STATE_S1) {
    nchars = socket_read(socket_id, inbuf, sizeof(inbuf) - 1);
    if (-1 == nchars || 0 == nchars) {
      prim_robot_stat.stat.state = RCS_STATE_S0;
      prim_robot_stat.stat.status = RCS_STATUS_ERROR;
    } else {
      inbuf[nchars] = 0;
      if (debug) ROS_INFO("%s", inbuf);
      // FIXME -- use a real ack message
      prim_robot_stat.stat.state = RCS_STATE_S0;
      prim_robot_stat.stat.status = RCS_STATUS_DONE;
    }
  }
  // else S0
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -n <name>    : set the node name\n");
  printf("  -p <period>  : set the period\n");
  printf("  -H <host>    : connect to host robot controller\n");
  printf("  -P <port>    : TCP port of robot controller\n");
  printf("  -h           : print this help>\n");
  printf("  -d           : turn debug on\n");
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
  int retval;
  int option;
  int ival;
  double dval;
  int port = PRIM_ROBOT_PORT;
  int socket_id;
  nist_kitting::prim_robot_stat prim_robot_stat_buf;

  prim_robot_stat_buf.stat.period = PERIOD_DEFAULT;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":n:p:H:P:hd");
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

    case 'H':
      strncpy(host_name, optarg, HOST_NAME_LEN-1);
      host_name[HOST_NAME_LEN-1] - 0;
      break;

    case 'P':
      ival = atoi(optarg);
      if (ival < 0) {
	fprintf(stderr, "bad value for port: %s\n", optarg);
	return 1;
      }
      port = ival;
      break;

    case 'h':
      print_help();
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

  socket_id = socket_get_client_id(port, host_name);
  if (socket_id < 0) {
    fprintf(stderr, "can't connect to %s:%d\n", host_name, (int) port);
    return 1;
  }
  if (debug) ROS_INFO("connected to %s:%d", host_name, (int) port);

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
      do_cmd_kitting_prim_robot_moveto(prim_robot_cmd_buf.moveto.pose, socket_id, prim_robot_stat_buf);
      break;
    default:
      // unrecognized command -- FIXME
      break;
    }

    prim_robot_stat_buf.stat.heartbeat++;

    end = etime();
    prim_robot_stat_buf.stat.duration = etime() - start;

    prim_robot_stat_pub.publish(prim_robot_stat_buf);

    loop_rate.sleep();
  }

  return 0;
}
