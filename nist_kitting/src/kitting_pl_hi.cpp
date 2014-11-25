/*
  kitting_pl_hi.cpp

  Hi-level planner for robotic kitting, combining all of WS and TASK,
  and EMOVE PL, into a single planner.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <float.h>

#include <string>

#include <ulapi.h>
#include <inifile.h>

#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
#include "nist_kitting/ws_cmd.h"
#include "nist_kitting/ws_stat.h"
#include "nist_kitting/emove_cmd.h"
#include "nist_kitting/emove_stat.h"
#include "nist_kitting/exec.h"

#define NODE_NAME_DEFAULT "kitting_pl_hi"
#define PERIOD_DEFAULT 1.0

static int debug = 0;

static std::string inifile_name("");
static void *planning_process = NULL;
static std::string planning_app("");
static std::string plan_file("");

static nist_kitting::ws_cmd ws_cmd_buf;
static nist_kitting::emove_stat emove_stat_buf;

static void ws_cmd_callback(const nist_kitting::ws_cmd::ConstPtr& msg)
{
  ws_cmd_buf = *msg;

  if (debug) ROS_INFO("Got %s (%d)", kitting_cmd_to_string(ws_cmd_buf.cmd.type), (int) ws_cmd_buf.cmd.serial_number);
}

static void emove_stat_callback(const nist_kitting::emove_stat::ConstPtr& msg)
{
  emove_stat_buf = *msg;
}

static int emove_cmd_serial_number = 18;

static void do_cmd_kitting_nop(nist_kitting::ws_stat &ws_stat)
{
  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    ws_stat.stat.state = RCS_STATE_S0;
    ws_stat.stat.status = RCS_STATUS_DONE;
  } 
  // else S0
}

static void do_cmd_kitting_init(nist_kitting::ws_stat &ws_stat, ros::Publisher &emove_cmd_pub, nist_kitting::emove_stat &emove_stat)
{
  nist_kitting::emove_cmd emove_cmd;

  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    emove_cmd.cmd.type = KITTING_INIT;
    emove_cmd.cmd.serial_number = ++emove_cmd_serial_number;
    emove_cmd_pub.publish(emove_cmd);
    ws_stat.stat.state = RCS_STATE_S1;
    ws_stat.stat.status = RCS_STATUS_EXEC;
  } else if (ws_stat.stat.state == RCS_STATE_S1) {
    if (emove_stat.stat.serial_number == emove_cmd_serial_number) {
      if (emove_stat.stat.status == RCS_STATUS_DONE) {
	ws_stat.stat.state = RCS_STATE_S0;
	ws_stat.stat.status = RCS_STATUS_DONE;
      } else if (emove_stat.stat.status == RCS_STATUS_ERROR) {
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

/*!
  \defgroup ASSEMBLE_KIT The Workstation Assemble Kit Command

  The Workstation Controller (WS) combines both WS and Emove functions,
  and the planning part of Emove.
*/

static void do_cmd_kitting_ws_assemble_kit(nist_kitting::ws_assemble_kit &cmd, nist_kitting::ws_stat &ws_stat, ros::Publisher &emove_cmd_pub, nist_kitting::emove_stat &emove_stat)
{
  std::string planning_app_full;
  nist_kitting::emove_cmd emove_cmd;
  ulapi_integer retval;
  ulapi_integer result;

  if (ws_stat.stat.state == RCS_STATE_NEW_COMMAND) {
    if (debug) ROS_INFO("Assembling kit %s, quantity %d", cmd.name.c_str(), (int) cmd.quantity);
    if (planning_app.empty()) {
      if (debug) ROS_INFO("Planning application has not be set\n");
      ws_stat.stat.state = RCS_STATE_S0;
      ws_stat.stat.status = RCS_STATUS_ERROR;
      return;
    }
    planning_app_full = planning_app + " -i " + inifile_name + " -k " + cmd.name;
    if (NULL != planning_process) {
      ulapi_process_stop(planning_process);
      ulapi_process_delete(planning_process);
    }
    planning_process = ulapi_process_new();
    if (ULAPI_OK == ulapi_process_start(planning_process, const_cast<char *>(planning_app_full.c_str()))) {
      ws_stat.stat.state = RCS_STATE_S1;
      ws_stat.stat.status = RCS_STATUS_EXEC;
      if (debug) printf("Starting '%s'\n", planning_app_full.c_str());
    } else {
      ws_stat.stat.state = RCS_STATE_S0;
      ws_stat.stat.status = RCS_STATUS_ERROR;
      printf("Can't start process '%s'\n", planning_app_full.c_str());
    }
  } else if (ws_stat.stat.state == RCS_STATE_S1) {
    retval = ulapi_process_done(planning_process, &result);
    if (retval) {
      ulapi_process_delete(planning_process);
      planning_process = NULL;
      if (result) {
	ws_stat.stat.state = RCS_STATE_S0;
	ws_stat.stat.status = RCS_STATUS_ERROR;
	ROS_INFO("Could not plan kit '%s'", cmd.name.c_str());
      } else {
	ws_stat.stat.state = RCS_STATE_S2;
      }
    } else {
      if (debug) printf("Waiting for '%s'\n", planning_app.c_str());
    }
    // else still running
  } else if (ws_stat.stat.state == RCS_STATE_S2) {
    emove_cmd.cmd.type = KITTING_EXEC;
    emove_cmd.cmd.serial_number = ++emove_cmd_serial_number;
    emove_cmd.exec.name = plan_file;
    emove_cmd_pub.publish(emove_cmd);
    ws_stat.stat.state = RCS_STATE_S3;
  } else if (ws_stat.stat.state == RCS_STATE_S3) {
    if (emove_stat.stat.serial_number == emove_cmd_serial_number) {
      if (emove_stat.stat.status == RCS_STATUS_DONE) {
	ws_stat.stat.state = RCS_STATE_S0;
	ws_stat.stat.status = RCS_STATUS_DONE;
	if (debug) ROS_INFO("Assembled kit '%s'", cmd.name.c_str());
      } else if (emove_stat.stat.status == RCS_STATUS_ERROR) {
	ws_stat.stat.state = RCS_STATE_S0;
	ws_stat.stat.status = RCS_STATUS_ERROR;
	if (debug) ROS_INFO("Could not assemble kit '%s'", cmd.name.c_str());
      }
    }
  }
  // else S0
}

static int ini_load(const std::string inifile_name, 
		    std::string& planning_app,
		    std::string& plan_file)
{
  FILE *fp;
  const char *section;
  const char *key;
  const char *inistring;
  std::string str;

  if (NULL == (fp = fopen(inifile_name.c_str(), "r"))) {
    fprintf(stderr, "can't open ini file %s\n", inifile_name.c_str());
    return 1;
  }

  if (planning_app.empty()) {
    /* no argument overrode it, so we'll look for it */
    section = NULL;

    key = "PLANNING_APP";
    inistring = ini_find(fp, key, section);

    if (NULL == inistring) {
      fprintf(stderr, "missing ini file entry: %s\n", key);
      fclose(fp);
      return 1;
    } else {
      planning_app = std::string(inistring);
    }
      printf("set planning app to %s\n", planning_app.c_str());
  }

  if (plan_file.empty()) {
    /* no argument overrode it, so we'll look for it */
    section = NULL;

    key = "PATH_TO_FINAL_PLAN";
    inistring = ini_find(fp, key, section);

    if (NULL == inistring) {
      plan_file = std::string("");
    } else {
      plan_file = std::string(inistring);
    }

    key = "FINAL_PLAN_FILE";
    inistring = ini_find(fp, key, section);

    if (NULL == inistring) {
      fprintf(stderr, "missing ini file entry: %s\n", key);
      fclose(fp);
      return 1;
    } else {
      plan_file = plan_file + std::string(inistring);
    }
  }

  fclose(fp);
  return 0;
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -i <file>    : set the ini file name\n");
  printf("  -n <name>    : set the node name\n");
  printf("  -t <period>  : cycle time\n");
  printf("  -p <path>    : path to the planning application\n");
  printf("  -f <path>    : path to the plan file\n");
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
  std::string node_name(NODE_NAME_DEFAULT);
  int option;
  int ival;
  double dval;
  nist_kitting::ws_stat ws_stat_buf;

  ws_stat_buf.stat.period = PERIOD_DEFAULT;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":i:n:t:p:f:hd");
    if (option == -1)
      break;

    switch (option) {
    case 'i':
      inifile_name = std::string(optarg);
      break;

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
      ws_stat_buf.stat.period = dval;
      break;

    case 'p':
      planning_app = std::string(optarg);
      break;

    case 'f':
      plan_file = std::string(optarg);
      break;

    case 'h':
      print_help();
      break;

    case 'd':
      debug = 1;
      ulapi_set_debug(ULAPI_DEBUG_ALL);
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

  if (ULAPI_OK != ulapi_init()) {
    fprintf(stderr, "can't init ulapi\n");
    return 1;
  }

  if (inifile_name.empty()) {
    fprintf(stderr, "no ini file provided\n");
    return 1;
  }

  if (0 != ini_load(inifile_name, planning_app, plan_file)) {
    fprintf(stderr, "error reading ini file %s\n", inifile_name.c_str());
    return 1;
  }

  if (planning_app.empty()) {
    fprintf(stderr, "no planning application provided\n");
    return 1;
  }

  if (plan_file.empty()) {
    fprintf(stderr, "no plan file provided\n");
    return 1;
  }

  if (debug) {
    ROS_INFO("Using planning application '%s', plan file '%s'\n", planning_app.c_str(), plan_file.c_str());
  }

  // pass everything after a '--' separator to ROS
  ros_argc = argc - optind;
  ros_argv = &argv[optind];
  ros::init(ros_argc, ros_argv, node_name);

  ros::NodeHandle nh;
  ros::Subscriber ws_cmd_sub;
  ros::Subscriber emove_stat_sub;
  ros::Publisher ws_stat_pub;
  ros::Publisher emove_cmd_pub;
  ros::Rate loop_rate(1.0 / ws_stat_buf.stat.period);

  ws_cmd_sub = nh.subscribe(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN, ws_cmd_callback);
  emove_stat_sub = nh.subscribe(KITTING_EMOVE_STAT_TOPIC, TOPIC_QUEUE_LEN, emove_stat_callback);
  ws_stat_pub = nh.advertise<nist_kitting::ws_stat>(KITTING_WS_STAT_TOPIC, TOPIC_QUEUE_LEN);
  emove_cmd_pub = nh.advertise<nist_kitting::emove_cmd>(KITTING_EMOVE_CMD_TOPIC, TOPIC_QUEUE_LEN);

  // stuff a NOP command
  ws_stat_buf.stat.type = ws_cmd_buf.cmd.type = KITTING_NOP;
  ws_stat_buf.stat.serial_number = ws_cmd_buf.cmd.serial_number = 0;
  ws_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
  ws_stat_buf.stat.status = RCS_STATUS_EXEC; 
  ws_stat_buf.stat.heartbeat = 0;

  signal(SIGINT, quit);

  double start, end, last_start = ulapi_time() - ws_stat_buf.stat.period;

  while (true) {
    ros::spinOnce();
    start = ulapi_time();
    ws_stat_buf.stat.cycle = start - last_start;
    last_start = start;

    if (ws_stat_buf.stat.serial_number != ws_cmd_buf.cmd.serial_number) {
      ws_stat_buf.stat.type = ws_cmd_buf.cmd.type;
      ws_stat_buf.stat.serial_number = ws_cmd_buf.cmd.serial_number;
      ws_stat_buf.stat.state = RCS_STATE_NEW_COMMAND;
      ws_stat_buf.stat.status = RCS_STATUS_EXEC; 
      if (NULL != planning_process) {
	ulapi_process_stop(planning_process);
	ulapi_process_delete(planning_process);
	planning_process = NULL;
      }
    }

    switch (ws_cmd_buf.cmd.type) {
    case KITTING_NOP:
      do_cmd_kitting_nop(ws_stat_buf);
      break;
    case KITTING_INIT:
      do_cmd_kitting_init(ws_stat_buf, emove_cmd_pub, emove_stat_buf);
      break;
    case KITTING_HALT:
      do_cmd_halt(ws_stat_buf);
      break;
    case KITTING_WS_ASSEMBLE_KIT:
      do_cmd_kitting_ws_assemble_kit(ws_cmd_buf.assemble_kit, ws_stat_buf, emove_cmd_pub, emove_stat_buf);
      break;
    default:
      // unrecognized command -- FIXME
      break;
    }

    ws_stat_buf.stat.heartbeat++;

    end = ulapi_time();
    ws_stat_buf.stat.duration = ulapi_time() - start;

    ws_stat_pub.publish(ws_stat_buf);

    loop_rate.sleep();
  }

  return 0;
}
