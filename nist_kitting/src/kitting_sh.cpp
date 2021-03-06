#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <readline/readline.h>	// readline
#include <readline/history.h>	// using_history

#include <ros/ros.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/ws_cmd.h"
#include "nist_kitting/ws_stat.h"
#include "nist_kitting/task_cmd.h"
#include "nist_kitting/task_stat.h"
#include "nist_kitting/emove_cmd.h"
#include "nist_kitting/emove_stat.h"
#include "nist_kitting/prim_robot_cmd.h"
#include "nist_kitting/prim_robot_stat.h"

#define NODE_NAME_LEN 80
#define NODE_NAME_DEFAULT "kittingsh"

static nist_kitting::ws_stat ws_stat_buf;
static nist_kitting::task_stat task_stat_buf;
static nist_kitting::emove_stat emove_stat_buf;
static nist_kitting::prim_robot_stat prim_robot_stat_buf;

static void ws_stat_callback(const nist_kitting::ws_stat::ConstPtr& msg)
{
  ws_stat_buf = *msg;
}

static void task_stat_callback(const nist_kitting::task_stat::ConstPtr& msg)
{
  task_stat_buf = *msg;
}

static void emove_stat_callback(const nist_kitting::emove_stat::ConstPtr& msg)
{
  emove_stat_buf = *msg;
}

static void prim_robot_stat_callback(const nist_kitting::prim_robot_stat::ConstPtr& msg)
{
  prim_robot_stat_buf = *msg;
}

static void print_ws_stat()
{
  printf("type:          %s\n", kitting_cmd_to_string(ws_stat_buf.stat.type));
  printf("serial_number: %d\n", (int) ws_stat_buf.stat.serial_number);
  printf("state:         %s\n", rcs_state_to_string(ws_stat_buf.stat.state));
  printf("status:        %s\n", rcs_status_to_string(ws_stat_buf.stat.status));
  printf("heartbeat:     %d\n", ws_stat_buf.stat.heartbeat);
  printf("period:        %f\n", ws_stat_buf.stat.period);
  printf("cycle:         %f\n", ws_stat_buf.stat.cycle);
  printf("duration:      %f\n", ws_stat_buf.stat.duration);
}

static void print_task_stat()
{
  printf("type:          %s\n", kitting_cmd_to_string(task_stat_buf.stat.type));
  printf("serial_number: %d\n", (int) task_stat_buf.stat.serial_number);
  printf("state:         %s\n", rcs_state_to_string(task_stat_buf.stat.state));
  printf("status:        %s\n", rcs_status_to_string(task_stat_buf.stat.status));
  printf("heartbeat:     %d\n", task_stat_buf.stat.heartbeat);
  printf("period:        %f\n", task_stat_buf.stat.period);
  printf("cycle:         %f\n", task_stat_buf.stat.cycle);
  printf("duration:      %f\n", task_stat_buf.stat.duration);
}

static void print_emove_stat()
{
  printf("type:          %s\n", kitting_cmd_to_string(emove_stat_buf.stat.type));
  printf("serial_number: %d\n", (int) emove_stat_buf.stat.serial_number);
  printf("state:         %s\n", rcs_state_to_string(emove_stat_buf.stat.state));
  printf("status:        %s\n", rcs_status_to_string(emove_stat_buf.stat.status));
  printf("heartbeat:     %d\n", emove_stat_buf.stat.heartbeat);
  printf("period:        %f\n", emove_stat_buf.stat.period);
  printf("cycle:         %f\n", emove_stat_buf.stat.cycle);
  printf("duration:      %f\n", emove_stat_buf.stat.duration);
}

static void print_prim_robot_stat()
{
  printf("type:          %s\n", kitting_cmd_to_string(prim_robot_stat_buf.stat.type));
  printf("serial_number: %d\n", (int) prim_robot_stat_buf.stat.serial_number);
  printf("state:         %s\n", rcs_state_to_string(prim_robot_stat_buf.stat.state));
  printf("status:        %s\n", rcs_status_to_string(prim_robot_stat_buf.stat.status));
  printf("heartbeat:     %d\n", prim_robot_stat_buf.stat.heartbeat);
  printf("period:        %f\n", prim_robot_stat_buf.stat.period);
  printf("cycle:         %f\n", prim_robot_stat_buf.stat.cycle);
  printf("duration:      %f\n", prim_robot_stat_buf.stat.duration);
  printf("pose:          %f %f %f ...\n", 
	 prim_robot_stat_buf.pose.position.x,
	 prim_robot_stat_buf.pose.position.y,
	 prim_robot_stat_buf.pose.position.z);
  printf("axes:          %f %f %f ...\n", 
	 prim_robot_stat_buf.axes.axis[0],
	 prim_robot_stat_buf.axes.axis[1],
	 prim_robot_stat_buf.axes.axis[2]);
  printf("gripper:       %s %f\n", prim_robot_stat_buf.gripper.closed ? "closed" : "open", prim_robot_stat_buf.gripper.value);
}

// find all of 'a' in 'b', and following chars of 'b' are space or 0
static int strwcmp(const char *a, const char *b)
{
  int i;

  i = strlen(a);
  if (0 != strncmp(a, b, i))
    return 1;
  if (0 == b[i] || isspace(b[i]))
    return 0;

  return 1;
}

static void print_help()
{
  printf("Usage: <args> {-- <ROS args>}\n");
  printf("  -h                  : print this help>\n");
  printf("  -n <name>           : set the node name\n");
  printf("  -t ws|task|emove|pr : target the specified node\n");
}

int main(int argc, char **argv)
{
  int ros_argc;
  char **ros_argv;
  char node_name[NODE_NAME_LEN] = NODE_NAME_DEFAULT;
  int debug = 0;
  enum {TARGET_WS, TARGET_TASK, TARGET_EMOVE, TARGET_PRIM_ROBOT} target = TARGET_WS;
  int retval;
  int option;
#define PROMPT_LEN 80
  char prompt[PROMPT_LEN];
  char *line;
  char *ptr;
  char *pptr;
  char delim[] = " \t\n\r";
  int i1;
  double d1, d2, d3, d4, d5, d6, d7;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":n:t:hd");
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
      
    case 't':
      if (! strcmp(optarg, "ws")) {
	target = TARGET_WS;
      } else if (! strcmp(optarg, "task")) {
	target = TARGET_TASK;
      } else if (! strcmp(optarg, "emove")) {
	target = TARGET_EMOVE;
      } else if (! strcmp(optarg, "pr")) {
	target = TARGET_PRIM_ROBOT;
      } else {
	fprintf(stderr, "invalid target: %s\n", optarg);
	return 1;
      }
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

  /*
    The ros::init() function needs to see argc and argv so that it can
    perform any ROS arguments and name remapping that were provided at
    the command line. For programmatic remappings you can use a
    different version of init() which takes remappings directly, but
    for most command-line programs, passing argc and argv is the
    easiest way to do it.  The third argument to init() is the name of
    the node.
   
    You must call one of the versions of ros::init() before using any
    other part of the ROS system.
  */
  if (debug) {
    printf("ros::init(");
    for (int t = 0; t < ros_argc; t++) {
      printf("%s ", ros_argv[t]);
    }
    printf("%s)\n", node_name);
  }
  ros::init(ros_argc, ros_argv, node_name);

  // defer the declaration and constructing until after ros::init()
  // just to be safe
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
  nist_kitting::ws_cmd ws_cmd;
  nist_kitting::task_cmd task_cmd;
  nist_kitting::emove_cmd emove_cmd;
  nist_kitting::prim_robot_cmd prim_robot_cmd;

  switch (target) {
  case TARGET_TASK:
    pub = nh.advertise<nist_kitting::task_cmd>(KITTING_TASK_CMD_TOPIC, TOPIC_QUEUE_LEN);
    sub = nh.subscribe(KITTING_TASK_STAT_TOPIC, TOPIC_QUEUE_LEN, task_stat_callback);
    sprintf(prompt, "task> ");
    break;
  case TARGET_EMOVE:
    pub = nh.advertise<nist_kitting::emove_cmd>(KITTING_EMOVE_CMD_TOPIC, TOPIC_QUEUE_LEN);
    sub = nh.subscribe(KITTING_EMOVE_STAT_TOPIC, TOPIC_QUEUE_LEN, emove_stat_callback);
    sprintf(prompt, "emove> ");
    break;
  case TARGET_PRIM_ROBOT:
    pub = nh.advertise<nist_kitting::prim_robot_cmd>(KITTING_PRIM_ROBOT_CMD_TOPIC, TOPIC_QUEUE_LEN);
    sub = nh.subscribe(KITTING_PRIM_ROBOT_STAT_TOPIC, TOPIC_QUEUE_LEN, prim_robot_stat_callback);
    sprintf(prompt, "pr> ");
    break;
  default:
    // catch anything else and set to TARGET_WS
    target = TARGET_WS;
    pub = nh.advertise<nist_kitting::ws_cmd>(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN);
    sub = nh.subscribe(KITTING_WS_STAT_TOPIC, TOPIC_QUEUE_LEN, ws_stat_callback);
    sprintf(prompt, "ws> ");
    break;
  }

  ros::Rate loop_rate(10);

  using_history();

  while (! feof(stdin) && ros::ok()) {
    switch (target) {
    case TARGET_TASK:
      sprintf(prompt, "task> ");
      break;
    case TARGET_EMOVE:
      sprintf(prompt, "emove> ");
      break;
    case TARGET_PRIM_ROBOT:
      sprintf(prompt, "pr> ");
      break;
    default:
      target = TARGET_WS;
      sprintf(prompt, "ws> ");
      break;
    }
    line = readline(prompt);
    if (NULL == line) break;
    if (*line) add_history(line);
    ptr = &line[strlen(line)] - 1;
    while (ptr > line && isspace(*ptr)) *ptr-- = 0; // zero trailing white space
    ptr = line;
    while (isspace(*ptr)) ptr++; // skip leading white space

    ros::spinOnce();

#define TRY(s) (! strwcmp(s, ptr))
#define TRYEM(s1,s2) (! strwcmp(s1, ptr) || ! strwcmp(s2, ptr))

    if (*ptr == 0) {		// blank line
      if (target == TARGET_WS) {
	print_ws_stat();
      } else if (target == TARGET_TASK) {
	print_task_stat();
      } else if (target == TARGET_EMOVE) {
	print_emove_stat();
      } else if (target == TARGET_PRIM_ROBOT) {
	print_prim_robot_stat();
      } else {
	printf("no target node selected\n");
      }
    } else if (*ptr == '#') {	// comment
      continue;
    } else if (TRYEM("q", "quit")) {
      break;
    } else if (TRY("ws")) {
      if (target != TARGET_WS) {
	pub = nh.advertise<nist_kitting::ws_cmd>(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN);
	sub = nh.subscribe(KITTING_WS_STAT_TOPIC, TOPIC_QUEUE_LEN, ws_stat_callback);
	target = TARGET_WS;
	sprintf(prompt, "ws> ");
      }
    } else if (TRY("task")) {
      if (target != TARGET_TASK) {
	pub = nh.advertise<nist_kitting::task_cmd>(KITTING_TASK_CMD_TOPIC, TOPIC_QUEUE_LEN);
	sub = nh.subscribe(KITTING_TASK_STAT_TOPIC, TOPIC_QUEUE_LEN, task_stat_callback);
	target = TARGET_TASK;
	sprintf(prompt, "task> ");
      }
    } else if (TRY("emove")) {
      if (target != TARGET_EMOVE) {
	pub = nh.advertise<nist_kitting::emove_cmd>(KITTING_EMOVE_CMD_TOPIC, TOPIC_QUEUE_LEN);
	sub = nh.subscribe(KITTING_EMOVE_STAT_TOPIC, TOPIC_QUEUE_LEN, emove_stat_callback);
	target = TARGET_EMOVE;
	sprintf(prompt, "emove> ");
      }
    } else if (TRY("pr")) {
      if (target != TARGET_PRIM_ROBOT) {
	pub = nh.advertise<nist_kitting::prim_robot_cmd>(KITTING_PRIM_ROBOT_CMD_TOPIC, TOPIC_QUEUE_LEN);
	sub = nh.subscribe(KITTING_PRIM_ROBOT_STAT_TOPIC, TOPIC_QUEUE_LEN, prim_robot_stat_callback);
	target = TARGET_PRIM_ROBOT;
	sprintf(prompt, "pr> ");
      }
    } else if (TRY("assemble")) {
      if (TARGET_WS != target) {
	pub = nh.advertise<nist_kitting::ws_cmd>(KITTING_WS_CMD_TOPIC, TOPIC_QUEUE_LEN);
	sub = nh.subscribe(KITTING_WS_STAT_TOPIC, TOPIC_QUEUE_LEN, ws_stat_callback);
	target = TARGET_WS;
	sprintf(prompt, "ws> ");
      }
      pptr = strtok(ptr, delim); // should be "assemble"
      pptr = strtok(NULL, delim); // should be kit name
      if (NULL == pptr) {
	printf("need a kit name\n");
      } else {
	ws_cmd.assemble_kit.name = std::string(pptr);
	pptr = strtok(NULL, delim);
	if ((NULL == pptr) || (1 != sscanf(pptr, "%i", &i1))) {
	  printf("need a number of kits\n");
	} else {
	  ws_cmd.cmd.type = KITTING_WS_ASSEMBLE_KIT;
	  ws_cmd.assemble_kit.quantity = i1;
	  ws_cmd.cmd.serial_number = ws_stat_buf.stat.serial_number;
	  ws_cmd.cmd.serial_number++; // make it a new one
	  pub.publish(ws_cmd);
	}
      }
    } else if (TRY("move")) {
      switch (target) {
      case TARGET_TASK:
	// skip over "move" and white space to get arg, if any
	while ((! isspace(*ptr)) && (0 != *ptr)) ptr++;
	while (isspace(*ptr)) ptr++;
	if (0 != *ptr) {
	  task_cmd.cmd.type = KITTING_TASK_MOVE_OBJECT;
	  task_cmd.move_object.name = ptr;
	  task_cmd.cmd.serial_number = task_stat_buf.stat.serial_number;
	  task_cmd.cmd.serial_number++; // make it a new one
	  pub.publish(task_cmd);
	} else {
	  printf("need a location name\n");
	}
	break;
      default:
	break;
      } // switch (target) for "move"
    } else if (TRY("moveto")) {
      switch (target) {
      case TARGET_PRIM_ROBOT:
	// skip over command and white space to get args
	if (7 == sscanf(ptr, "%*s %lf %lf %lf %lf %lf %lf %lf",
			&d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
	  prim_robot_cmd.cmd.type = KITTING_PRIM_ROBOT_MOVETO;
	  prim_robot_cmd.moveto.pose.position.x = d1;
	  prim_robot_cmd.moveto.pose.position.y = d2;
	  prim_robot_cmd.moveto.pose.position.z = d3;
	  prim_robot_cmd.moveto.pose.orientation.x = d4;
	  prim_robot_cmd.moveto.pose.orientation.y = d5;
	  prim_robot_cmd.moveto.pose.orientation.z = d6;
	  prim_robot_cmd.moveto.pose.orientation.w = d7;
	  prim_robot_cmd.cmd.serial_number = prim_robot_stat_buf.stat.serial_number;
	  prim_robot_cmd.cmd.serial_number++; // make it a new one
	  pub.publish(prim_robot_cmd);
	} else {
	  printf("need X Y Z Qx Qy Qz Qw\n");
	}
	break;
      default:
	break;
      }
    } else if (TRY("stop")) {
      switch (target) {
      case TARGET_PRIM_ROBOT:
	if (1 == sscanf(ptr, "%*s %d", &i1)) prim_robot_cmd.stop.condition = i1;
	else prim_robot_cmd.stop.condition = 0;
	prim_robot_cmd.cmd.type = KITTING_PRIM_ROBOT_STOP;
	prim_robot_cmd.cmd.serial_number = prim_robot_stat_buf.stat.serial_number;
	prim_robot_cmd.cmd.serial_number++;
	pub.publish(prim_robot_cmd);
      default:
	break;
      }
    } else if (TRY("open")) {
      switch (target) {
      case TARGET_PRIM_ROBOT:
	prim_robot_cmd.cmd.type = KITTING_PRIM_ROBOT_OPEN_GRIPPER;
	prim_robot_cmd.cmd.serial_number = prim_robot_stat_buf.stat.serial_number;
	prim_robot_cmd.cmd.serial_number++;
	pub.publish(prim_robot_cmd);
      default:
	break;
      }
    } else if (TRY("close")) {
      switch (target) {
      case TARGET_PRIM_ROBOT:
	prim_robot_cmd.cmd.type = KITTING_PRIM_ROBOT_CLOSE_GRIPPER;
	prim_robot_cmd.cmd.serial_number = prim_robot_stat_buf.stat.serial_number;
	prim_robot_cmd.cmd.serial_number++;
	pub.publish(prim_robot_cmd);
      default:
	break;
      }
    } else if (TRY("init")) {
      switch (target) {
      case TARGET_WS:
	ws_cmd.cmd.type = KITTING_INIT;
	ws_cmd.cmd.serial_number = ws_stat_buf.stat.serial_number;
	ws_cmd.cmd.serial_number++; // make it a new one
	pub.publish(ws_cmd);
	break;
      case TARGET_TASK:
	task_cmd.cmd.type = KITTING_INIT;
	task_cmd.cmd.serial_number = task_stat_buf.stat.serial_number;
	task_cmd.cmd.serial_number++; // make it a new one
	pub.publish(task_cmd);
	break;
      case TARGET_EMOVE:
	emove_cmd.cmd.type = KITTING_INIT;
	emove_cmd.cmd.serial_number = emove_stat_buf.stat.serial_number;
	emove_cmd.cmd.serial_number++; // make it a new one
	pub.publish(emove_cmd);
	break;
      case TARGET_PRIM_ROBOT:
	prim_robot_cmd.cmd.type = KITTING_INIT;
	prim_robot_cmd.cmd.serial_number = prim_robot_stat_buf.stat.serial_number;
	prim_robot_cmd.cmd.serial_number++; // make it a new one
	pub.publish(prim_robot_cmd);
	break;
      default:
	break;
      } // switch (target) for "init"
    } else if (TRY("halt")) {
      switch (target) {
      case TARGET_WS:
	ws_cmd.cmd.type = KITTING_HALT;
	ws_cmd.cmd.serial_number = ws_stat_buf.stat.serial_number;
	ws_cmd.cmd.serial_number++; // make it a new one
	pub.publish(ws_cmd);
	break;
      case TARGET_TASK:
	task_cmd.cmd.type = KITTING_HALT;
	task_cmd.cmd.serial_number = task_stat_buf.stat.serial_number;
	task_cmd.cmd.serial_number++; // make it a new one
	pub.publish(task_cmd);
	break;
      case TARGET_EMOVE:
	emove_cmd.cmd.type = KITTING_HALT;
	emove_cmd.cmd.serial_number = emove_stat_buf.stat.serial_number;
	emove_cmd.cmd.serial_number++; // make it a new one
	pub.publish(emove_cmd);
	break;
      case TARGET_PRIM_ROBOT:
	prim_robot_cmd.cmd.type = KITTING_HALT;
	prim_robot_cmd.cmd.serial_number = prim_robot_stat_buf.stat.serial_number;
	prim_robot_cmd.cmd.serial_number++; // make it a new one
	pub.publish(prim_robot_cmd);
	break;
      default:
	break;
      } // switch (target) for "init"
    } else {
      printf("?\n");
    }  // end of TRY(...)
  } // while (! feof(stdin))

  return 0;
}
