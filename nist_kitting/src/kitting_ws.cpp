#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <float.h>

#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
#include "nist_kitting/ws_cmd.h"
#include "nist_kitting/ws_stat.h"
#include "nist_kitting/task_cmd.h"
#include "nist_kitting/task_stat.h"

#define NODE_NAME_LEN 80
#define NODE_NAME_DEFAULT "kitting_ws"
#define PERIOD_DEFAULT 1.0

static int debug = 0;

static nist_kitting::ws_cmd ws_cmd_buf;
static nist_kitting::task_stat task_stat_buf;

static void ws_cmd_callback(const nist_kitting::ws_cmd::ConstPtr& msg)
{
  ws_cmd_buf = *msg;

  if (debug) ROS_INFO("Got %s (%d)", kitting_cmd_to_string(ws_cmd_buf.cmd.type), (int) ws_cmd_buf.cmd.serial_number);
}

static void task_stat_callback(const nist_kitting::task_stat::ConstPtr& msg)
{
  task_stat_buf = *msg;
}

static int task_cmd_serial_number = 18;

static void do_cmd_kitting_nop(nist_kitting::ws_stat &ws_stat)
{
  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    ws_stat.stat.state = RCS_STATE_S0;
    ws_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_init(nist_kitting::ws_stat &ws_stat, ros::Publisher &task_cmd_pub, nist_kitting::task_stat &task_stat)
{
  nist_kitting::task_cmd task_cmd;

  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    task_cmd.cmd.type = KITTING_INIT;
    task_cmd.cmd.serial_number = ++task_cmd_serial_number;
    task_cmd_pub.publish(task_cmd);
    ws_stat.stat.state = RCS_STATE_S1;
    ws_stat.stat.status = RCS_STATUS_EXEC;
  } else if (ws_stat.stat.state == RCS_STATE_S1) {
    if (task_stat.stat.serial_number == task_cmd_serial_number) {
      if (task_stat.stat.status == RCS_STATUS_DONE) {
	ws_stat.stat.state = RCS_STATE_S0;
	ws_stat.stat.status = RCS_STATUS_DONE;
      } else if (task_stat.stat.status == RCS_STATUS_ERROR) {
	ws_stat.stat.state = RCS_STATE_S0;
	ws_stat.stat.status = RCS_STATUS_ERROR;
      }
    }
  }
  // else S0
}

static void do_cmd_halt(nist_kitting::ws_stat &ws_stat)
{
  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    ws_stat.stat.state = RCS_STATE_S0;
    ws_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_ws_assemble_kit(nist_kitting::ws_assemble_kit &cmd, nist_kitting::ws_stat &ws_stat)
{
  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    ws_stat.stat.state = RCS_STATE_S1;
    ws_stat.stat.status = RCS_STATUS_EXEC;
    if (debug) ROS_INFO("Assembling kit %s, quantity %d", cmd.name.c_str(), (int) cmd.quantity);
  } else if (ws_stat.stat.state == RCS_STATE_S1) {
    if (debug) ROS_INFO("Assembled kit %s", cmd.name.c_str());
    ws_stat.stat.state = RCS_STATE_S0;
    ws_stat.stat.status = RCS_STATUS_DONE;
  }
  // else S0
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -h           : print this help>\n");
  printf("  -n <name>    : set the node name\n");
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
  int retval;
  int option;
  double dval;
  nist_kitting::ws_stat ws_stat_buf;

  ws_stat_buf.stat.period = PERIOD_DEFAULT;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":n:p:hd");
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
      ws_stat_buf.stat.period = dval;
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
  ros::Subscriber ws_cmd_sub;
  ros::Subscriber task_stat_sub;
  ros::Publisher ws_stat_pub;
  ros::Publisher task_cmd_pub;
  ros::Rate loop_rate(1.0 / ws_stat_buf.stat.period);

  ws_cmd_sub = nh.subscribe(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN, ws_cmd_callback);
  task_stat_sub = nh.subscribe(KITTING_TASK_STAT_TOPIC, TOPIC_QUEUE_LEN, task_stat_callback);
  ws_stat_pub = nh.advertise<nist_kitting::ws_stat>(KITTING_WS_STAT_TOPIC, TOPIC_QUEUE_LEN);
  task_cmd_pub = nh.advertise<nist_kitting::task_cmd>(KITTING_TASK_CMD_TOPIC, TOPIC_QUEUE_LEN);

  // stuff a NOP command
  ws_stat_buf.stat.type = ws_cmd_buf.cmd.type = KITTING_NOP;
  ws_stat_buf.stat.serial_number = ws_cmd_buf.cmd.serial_number = 0;
  ws_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
  ws_stat_buf.stat.status = RCS_STATUS_EXEC; 
  ws_stat_buf.stat.heartbeat = 0;

  signal(SIGINT, quit);

  double start, end, last_start = etime() - ws_stat_buf.stat.period;

  while (true) {
    ros::spinOnce();
    start = etime();
    ws_stat_buf.stat.cycle = start - last_start;
    last_start = start;

    if (ws_stat_buf.stat.serial_number != ws_cmd_buf.cmd.serial_number) {
      ws_stat_buf.stat.type = ws_cmd_buf.cmd.type;
      ws_stat_buf.stat.serial_number = ws_cmd_buf.cmd.serial_number;
      ws_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
      ws_stat_buf.stat.status = RCS_STATUS_EXEC; 
    }

    switch (ws_cmd_buf.cmd.type) {
    case KITTING_NOP:
      do_cmd_kitting_nop(ws_stat_buf);
      break;
    case KITTING_INIT:
      do_cmd_kitting_init(ws_stat_buf, task_cmd_pub, task_stat_buf);
      break;
    case KITTING_HALT:
      do_cmd_halt(ws_stat_buf);
      break;
    case KITTING_WS_ASSEMBLE_KIT:
      do_cmd_kitting_ws_assemble_kit(ws_cmd_buf.assemble_kit, ws_stat_buf);
      break;
    default:
      // unrecognized command -- FIXME
      break;
    }

    ws_stat_buf.stat.heartbeat++;

    end = etime();
    ws_stat_buf.stat.duration = etime() - start;

    ws_stat_pub.publish(ws_stat_buf);

    loop_rate.sleep();
  }

  return 0;
}
