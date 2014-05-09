#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <float.h>

#include <ros/ros.h>

#include <ulapi.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
#include "nist_kitting/task_cmd.h"
#include "nist_kitting/task_stat.h"
#include "nist_kitting/emove_cmd.h"
#include "nist_kitting/emove_stat.h"

#define NODE_NAME_LEN 80
#define NODE_NAME_DEFAULT "kitting_task"
#define PERIOD_DEFAULT 0.4

static int debug = 0;

static nist_kitting::task_cmd task_cmd_buf;
static nist_kitting::emove_stat emove_stat_buf;

static void task_cmd_callback(const nist_kitting::task_cmd::ConstPtr& msg)
{
  task_cmd_buf = *msg;

  if (debug) ROS_INFO("Got %s (%d)", kitting_cmd_to_string(task_cmd_buf.cmd.type), (int) task_cmd_buf.cmd.serial_number);
}

static void emove_stat_callback(const nist_kitting::emove_stat::ConstPtr& msg)
{
  emove_stat_buf = *msg;
}

static int emove_cmd_serial_number = 18;

static void do_cmd_kitting_nop(nist_kitting::task_stat &task_stat)
{
  if (task_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    task_stat.stat.state = RCS_STATE_S0;
    task_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_init(nist_kitting::task_stat &task_stat, ros::Publisher &emove_cmd_pub, nist_kitting::emove_stat &emove_stat)
{
  nist_kitting::emove_cmd emove_cmd;

  if (task_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    emove_cmd.cmd.type = KITTING_INIT;
    emove_cmd.cmd.serial_number = ++emove_cmd_serial_number;
    emove_cmd_pub.publish(emove_cmd);
    task_stat.stat.state = RCS_STATE_S1;
    task_stat.stat.status = RCS_STATUS_EXEC;
  } else if (task_stat.stat.state == RCS_STATE_S1) {
    if (emove_stat.stat.serial_number == emove_cmd_serial_number) {
      if (emove_stat.stat.status == RCS_STATUS_DONE) {
	task_stat.stat.state = RCS_STATE_S0;
	task_stat.stat.status = RCS_STATUS_DONE;
      } else if (emove_stat.stat.status == RCS_STATUS_ERROR) {
	task_stat.stat.state = RCS_STATE_S0;
	task_stat.stat.status = RCS_STATUS_ERROR;
      }
    }
  }
  // else S0
}

static void do_cmd_halt(nist_kitting::task_stat &task_stat)
{
  if (task_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    task_stat.stat.state = RCS_STATE_S0;
    task_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_task_move_object(std::string name, nist_kitting::task_stat &task_stat)
{
  if (task_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    task_stat.stat.state = RCS_STATE_S1;
    task_stat.stat.status = RCS_STATUS_EXEC;
    if (debug) ROS_INFO("Moving to %s", name.c_str());
  } else if (task_stat.stat.state == RCS_STATE_S1) {
    if (debug) ROS_INFO("Got to %s", name.c_str());
    task_stat.stat.state = RCS_STATE_S0;
    task_stat.stat.status = RCS_STATUS_DONE;
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
  nist_kitting::task_stat task_stat_buf;

  task_stat_buf.stat.period = PERIOD_DEFAULT;

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
      task_stat_buf.stat.period = dval;
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
  ros::Subscriber task_cmd_sub;
  ros::Subscriber emove_stat_sub;
  ros::Publisher task_stat_pub;
  ros::Publisher emove_cmd_pub;
  ros::Rate loop_rate(1.0 / task_stat_buf.stat.period);

  task_cmd_sub = nh.subscribe(KITTING_TASK_CMD_TOPIC, TOPIC_QUEUE_LEN, task_cmd_callback);
  emove_stat_sub = nh.subscribe(KITTING_EMOVE_STAT_TOPIC, TOPIC_QUEUE_LEN, emove_stat_callback);
  task_stat_pub = nh.advertise<nist_kitting::task_stat>(KITTING_TASK_STAT_TOPIC, TOPIC_QUEUE_LEN);
  emove_cmd_pub = nh.advertise<nist_kitting::emove_cmd>(KITTING_EMOVE_CMD_TOPIC, TOPIC_QUEUE_LEN);

  // stuff a NOP command
  task_stat_buf.stat.type = task_cmd_buf.cmd.type = KITTING_NOP;
  task_stat_buf.stat.serial_number = task_cmd_buf.cmd.serial_number = 0;
  task_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
  task_stat_buf.stat.status = RCS_STATUS_EXEC; 
  task_stat_buf.stat.heartbeat = 0;

  signal(SIGINT, quit);

  double start, end, last_start = ulapi_time() - task_stat_buf.stat.period;

  while (true) {
    ros::spinOnce();
    start = ulapi_time();
    task_stat_buf.stat.cycle = start - last_start;
    last_start = start;

    if (task_stat_buf.stat.serial_number != task_cmd_buf.cmd.serial_number) {
      task_stat_buf.stat.type = task_cmd_buf.cmd.type;
      task_stat_buf.stat.serial_number = task_cmd_buf.cmd.serial_number;
      task_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
      task_stat_buf.stat.status = RCS_STATUS_EXEC; 
    }

    switch (task_cmd_buf.cmd.type) {
    case KITTING_NOP:
      do_cmd_kitting_nop(task_stat_buf);
      break;
    case KITTING_INIT:
      do_cmd_kitting_init(task_stat_buf, emove_cmd_pub, emove_stat_buf);
      break;
    case KITTING_HALT:
      do_cmd_halt(task_stat_buf);
      break;
    case KITTING_TASK_MOVE_OBJECT:
      do_cmd_kitting_task_move_object(task_cmd_buf.move_object.name, task_stat_buf);
      break;
    default:
      // unrecognized command -- FIXME
      break;
    }

    task_stat_buf.stat.heartbeat++;

    end = ulapi_time();
    task_stat_buf.stat.duration = ulapi_time() - start;

    task_stat_pub.publish(task_stat_buf);

    loop_rate.sleep();
  }

  return 0;
}
