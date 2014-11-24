#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <float.h>

#include <string>

#include <ros/ros.h>

#include <ulapi.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
#include "nist_kitting/emove_cmd.h"
#include "nist_kitting/emove_stat.h"
#include "nist_kitting/prim_robot_cmd.h"
#include "nist_kitting/prim_robot_stat.h"

#define NODE_NAME_DEFAULT "kitting_emove"
#define PERIOD_DEFAULT 0.1

static int debug = 0;

/*
  The external plan execution process called by the 'exec' command,
*/
static void *plan_exec_process = NULL;
static std::string plan_exec_app("");

static nist_kitting::emove_cmd emove_cmd_buf;
static nist_kitting::prim_robot_stat prim_robot_stat_buf;

static void emove_cmd_callback(const nist_kitting::emove_cmd::ConstPtr& msg)
{
  emove_cmd_buf = *msg;

  if (debug) ROS_INFO("Got %s (%d)", kitting_cmd_to_string(emove_cmd_buf.cmd.type), (int) emove_cmd_buf.cmd.serial_number);
}

static void prim_robot_stat_callback(const nist_kitting::prim_robot_stat::ConstPtr& msg)
{
  prim_robot_stat_buf = *msg;
}

static int prim_robot_cmd_serial_number = 18;

static void do_cmd_kitting_nop(nist_kitting::emove_stat &emove_stat)
{
  if (emove_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    emove_stat.stat.state = RCS_STATE_S0;
    emove_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_init(nist_kitting::emove_stat &emove_stat, ros::Publisher &prim_robot_cmd_pub, nist_kitting::prim_robot_stat &prim_robot_stat)
{
  nist_kitting::prim_robot_cmd prim_robot_cmd;

  if (emove_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    prim_robot_cmd.cmd.type = KITTING_INIT;
    prim_robot_cmd.cmd.serial_number = ++prim_robot_cmd_serial_number;
    prim_robot_cmd_pub.publish(prim_robot_cmd);
    emove_stat.stat.state = RCS_STATE_S1;
    emove_stat.stat.status = RCS_STATUS_EXEC;
  } else if (emove_stat.stat.state == RCS_STATE_S1) {
    if (prim_robot_stat.stat.serial_number == prim_robot_cmd_serial_number) {
      if (prim_robot_stat.stat.status == RCS_STATUS_DONE) {
	emove_stat.stat.state = RCS_STATE_S0;
	emove_stat.stat.status = RCS_STATUS_DONE;
      } else if (prim_robot_stat.stat.status == RCS_STATUS_ERROR) {
	emove_stat.stat.state = RCS_STATE_S0;
	emove_stat.stat.status = RCS_STATUS_ERROR;
      }
    }
  }
  // else S0
}

static void do_cmd_halt(nist_kitting::emove_stat &emove_stat)
{
  if (emove_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    emove_stat.stat.state = RCS_STATE_S0;
    emove_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_emove_move(std::string name, nist_kitting::emove_stat &emove_stat)
{
  if (emove_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    emove_stat.stat.state = RCS_STATE_S1;
    emove_stat.stat.status = RCS_STATUS_EXEC;
    if (debug) ROS_INFO("Moving to %s", name.c_str());
  } else if (emove_stat.stat.state == RCS_STATE_S1) {
    if (debug) ROS_INFO("Got to %s", name.c_str());
    emove_stat.stat.state = RCS_STATE_S0;
    emove_stat.stat.status = RCS_STATUS_DONE;
  }
  // else S0
}

static void do_cmd_kitting_emove_exec(std::string name, nist_kitting::emove_stat &emove_stat)
{
  std::string plan_exec_app_full;
  ulapi_integer retval;
  ulapi_integer result;

  if (emove_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (debug) ROS_INFO("Executing plan %s", name.c_str());
    if (NULL != plan_exec_process) {
      ulapi_process_stop(plan_exec_process);
      ulapi_process_delete(plan_exec_process);
    }
    plan_exec_app_full = plan_exec_app + " -f " + name;
    plan_exec_process = ulapi_process_new();
    if (ULAPI_OK == ulapi_process_start(plan_exec_process, const_cast<char *>(plan_exec_app_full.c_str()))) {
      emove_stat.stat.state = RCS_STATE_S1;
      emove_stat.stat.status = RCS_STATUS_EXEC;
      if (debug) printf("Starting '%s'\n", plan_exec_app_full.c_str());
    } else {
      emove_stat.stat.state = RCS_STATE_S0;
      emove_stat.stat.status = RCS_STATUS_ERROR;
      printf("Can't start process '%s'\n", plan_exec_app_full.c_str());
    }
  } else if (emove_stat.stat.state == RCS_STATE_S1) {
    retval = ulapi_process_done(plan_exec_process, &result);
    if (retval) {
      ulapi_process_delete(plan_exec_process);
      plan_exec_process = NULL;
      if (result) {
	emove_stat.stat.state = RCS_STATE_S0;
	emove_stat.stat.status = RCS_STATUS_ERROR;
	ROS_INFO("Could not execute plan '%s'", name.c_str());
      } else {
	emove_stat.stat.state = RCS_STATE_S0;
	emove_stat.stat.status = (result ? RCS_STATUS_ERROR : RCS_STATUS_DONE);
	if (debug) ROS_INFO("Executed plan '%s'", name.c_str());
      }
    } else {
      if (debug) printf("Waiting for '%s'\n", plan_exec_app_full.c_str());
    }
    // else still running
  }
  // else S0
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -h           : print this help>\n");
  printf("  -n <name>    : set the node name\n");
  printf("  -t <period>  : cycle time\n");
  printf("  -e <path>    : path to the plan execution app\n");
}

static void quit(int sig)
{
  exit(0);
}

int main(int argc, char **argv)
{
  int ros_argc;
  char **ros_argv;
  std::string node_name(NODE_NAME_DEFAULT);
  int retval;
  int option;
  int ival;
  double dval;
  nist_kitting::emove_stat emove_stat_buf;

  emove_stat_buf.stat.period = PERIOD_DEFAULT;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":n:t:e:hd");
    if (option == -1)
      break;

    switch (option) {
    case 'n':
      // first check for valid name
      if (optarg[0] == '-') {
	fprintf(stderr, "invalid node name: %s\n", optarg);
	return 1;
      }
      node_name = std::string(optarg);
      break;

    case 't':
      dval = atof(optarg);
      if (dval < FLT_EPSILON) {
	fprintf(stderr, "bad value for period: %s\n", optarg);
	return 1;
      }
      emove_stat_buf.stat.period = dval;
      break;

    case 'e':
      plan_exec_app = std::string(optarg);
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

  if (plan_exec_app.empty()) {
    fprintf(stderr, "no plan execution application provided\n");
    return 1;
  }

  if (debug) {
    ROS_INFO("Using pla executin application '%s'\n", plan_exec_app.c_str());
  }

  // pass everything after a '--' separator to ROS
  ros_argc = argc - optind;
  ros_argv = &argv[optind];
  ros::init(ros_argc, ros_argv, node_name);

  ros::NodeHandle nh;
  ros::Subscriber emove_cmd_sub;
  ros::Subscriber prim_robot_stat_sub;
  ros::Publisher emove_stat_pub;
  ros::Publisher prim_robot_cmd_pub;
  ros::Rate loop_rate(1.0 / emove_stat_buf.stat.period);

  emove_cmd_sub = nh.subscribe(KITTING_EMOVE_CMD_TOPIC, TOPIC_QUEUE_LEN, emove_cmd_callback);
  prim_robot_stat_sub = nh.subscribe(KITTING_PRIM_ROBOT_STAT_TOPIC, TOPIC_QUEUE_LEN, prim_robot_stat_callback);
  emove_stat_pub = nh.advertise<nist_kitting::emove_stat>(KITTING_EMOVE_STAT_TOPIC, TOPIC_QUEUE_LEN);
  prim_robot_cmd_pub = nh.advertise<nist_kitting::prim_robot_cmd>(KITTING_PRIM_ROBOT_CMD_TOPIC, TOPIC_QUEUE_LEN);

  // stuff a NOP command
  emove_stat_buf.stat.type = emove_cmd_buf.cmd.type = KITTING_NOP;
  emove_stat_buf.stat.serial_number = emove_cmd_buf.cmd.serial_number = 0;
  emove_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
  emove_stat_buf.stat.status = RCS_STATUS_EXEC; 
  emove_stat_buf.stat.heartbeat = 0;

  signal(SIGINT, quit);

  double start, end, last_start = ulapi_time() - emove_stat_buf.stat.period;

  while (true) {
    ros::spinOnce();
    start = ulapi_time();
    emove_stat_buf.stat.cycle = start - last_start;
    last_start = start;

    if (emove_stat_buf.stat.serial_number != emove_cmd_buf.cmd.serial_number) {
      emove_stat_buf.stat.type = emove_cmd_buf.cmd.type;
      emove_stat_buf.stat.serial_number = emove_cmd_buf.cmd.serial_number;
      emove_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
      emove_stat_buf.stat.status = RCS_STATUS_EXEC; 
    }

    switch (emove_cmd_buf.cmd.type) {
    case KITTING_NOP:
      do_cmd_kitting_nop(emove_stat_buf);
      break;
    case KITTING_INIT:
      do_cmd_kitting_init(emove_stat_buf, prim_robot_cmd_pub, prim_robot_stat_buf);
      break;
    case KITTING_HALT:
      do_cmd_halt(emove_stat_buf);
      break;
    case KITTING_EXEC:
      do_cmd_kitting_emove_exec(emove_cmd_buf.exec.name, emove_stat_buf);
      break;
    case KITTING_EMOVE_MOVE:
      do_cmd_kitting_emove_move(emove_cmd_buf.move.name, emove_stat_buf);
      break;
    default:
      // unrecognized command -- FIXME
      break;
    }

    emove_stat_buf.stat.heartbeat++;

    end = ulapi_time();
    emove_stat_buf.stat.duration = ulapi_time() - start;

    emove_stat_pub.publish(emove_stat_buf);

    loop_rate.sleep();
  }

  return 0;
}
