/*
  This implements the simple message joint command and status interface
  described here: 

  http://wiki.ros.org/Industrial/Tutorials/\
  create_joint_position_streaming_interface_using_tcp_socket_libraries

  Two sockets are served. One at port 11000 by default is for
  receiving messages requesting that the robot move to a set of target
  joint angles. Another at port 11002 by default is for continuous
  sending of robot joint states.
*/

#include <stdio.h>		// stdin, stderr 
#include <stddef.h>		// NULL, sizeof, size_t 
#include <stdlib.h>		// atoi, atof 
#include <ctype.h>		// isspace

#include <ulapi.h>

#include "simple_message_defs.h"

static bool debug = false;

// global robot info, and its mutex
static robot_info the_robot;
static ulapi_mutex_struct robot_mutex;

// Joint message connection code ----------------------

struct joint_message_connection_thread_args {
  void *joint_message_connection_thread;
  int joint_message_connection_id;
};

static void joint_message_connection_thread_code(joint_message_connection_thread_args *args)
{
  void *joint_message_connection_thread;
  int joint_message_connection_id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  int nchars;
  joint_request_message reqmsg;
  joint_reply_message repmsg;
  joint_info jinfo;
  char *ptr;

  joint_message_connection_thread = args->joint_message_connection_thread;
  joint_message_connection_id = args->joint_message_connection_id;
  free(args);

  while (true) {
    nchars = ulapi_socket_read(joint_message_connection_id, inbuf, sizeof(inbuf));
    if (nchars < 0) break;
    inbuf[sizeof(inbuf)-1] = 0;

    reqmsg.read_joint_request(inbuf);
    if (debug) {
      printf("connection %d requested:\n", joint_message_connection_id);
      reqmsg.print_joint_request();
    }

    ulapi_mutex_take(&robot_mutex);
    for (int t = 0; t < JOINT_MAX; t++) {
      float p;
      if (! reqmsg.get_pos(&p, t)) break;
      the_robot.set_robot_pos(p, t);
    }
    ulapi_mutex_give(&robot_mutex);

    repmsg.set_joint_reply(REPLY_SUCCESS);
    nchars = ulapi_socket_write(joint_message_connection_id, reinterpret_cast<char *>(&repmsg), sizeof(repmsg));
    if (nchars < 0) break;
  }

  ulapi_socket_close(joint_message_connection_id);

  if (debug) printf("joint message connection handler %d done\n", joint_message_connection_id);

  free(joint_message_connection_thread);

  return;
}

// Joint state connection code ----------------------

struct joint_state_connection_thread_args {
  void *joint_state_connection_thread;
  int joint_state_connection_id;
  double period;
};

static void joint_state_connection_thread_code(joint_state_connection_thread_args *args)
{
  void *joint_state_connection_thread;
  int joint_state_connection_id;
  double period;
  joint_state_message jsmsg;
  int nchars;

  joint_state_connection_thread = args->joint_state_connection_thread;
  joint_state_connection_id = args->joint_state_connection_id;
  period = args->period;
  free(args);

  while (true) {
    ulapi_mutex_take(&robot_mutex);
    for (int t = 0; t < JOINT_MAX; t++) {
      float p;
      if (the_robot.get_robot_pos(&p, t)) jsmsg.set_pos(p, t);
    }
    ulapi_mutex_give(&robot_mutex);

    nchars = ulapi_socket_write(joint_state_connection_id, reinterpret_cast<char *>(&jsmsg), sizeof(jsmsg));
    if (nchars < 0) break;

    ulapi_wait(period * 1e9);
  }

  ulapi_socket_close(joint_state_connection_id);

  if (debug) printf("joint state connection handler %d done\n", joint_state_connection_id);

  free(joint_state_connection_thread);

  return;
}

// Joint message server code ----------------------

struct joint_message_server_thread_args {
  int joint_message_server_id;		// socket id to serve up for connections
};

static void joint_message_server_thread_code(joint_message_server_thread_args *args)
{
  int joint_message_server_id;
  int joint_message_connection_id;
  ulapi_task_struct *joint_message_connection_thread;
  joint_message_connection_thread_args *joint_message_connection_args; 

  joint_message_server_id = args->joint_message_server_id;

  while (true) {
    if (debug) printf("waiting for joint message connection...\n");
    joint_message_connection_id = ulapi_socket_get_connection_id(joint_message_server_id);
    if (joint_message_connection_id < 0) {
      fprintf(stderr, "can't get joint message connection connectons\n");
      break;
    }
     
    if (debug) printf("got a joint message connection on id %d\n", joint_message_connection_id);

    // spawn a connection thread
    joint_message_connection_thread = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*joint_message_connection_thread)));
    joint_message_connection_args = reinterpret_cast<joint_message_connection_thread_args *>(malloc(sizeof(*joint_message_connection_args)));

    ulapi_task_init(joint_message_connection_thread);
    joint_message_connection_args->joint_message_connection_id = joint_message_connection_id;
    joint_message_connection_args->joint_message_connection_thread = joint_message_connection_thread;
    ulapi_task_start(joint_message_connection_thread, reinterpret_cast<ulapi_task_code>(joint_message_connection_thread_code), reinterpret_cast<void *>(joint_message_connection_args), ulapi_prio_highest(), 0);
  } // while (true)

  ulapi_socket_close(joint_message_server_id);

  if (debug) printf("server on %d done\n", joint_message_server_id);

  return;
}

// Joint state server code ----------------------

struct joint_state_server_thread_args {
  int joint_state_server_id;		// socket id to serve up for connections
  double period;
};

static void joint_state_server_thread_code(joint_state_server_thread_args *args)
{
  int joint_state_server_id;
  double period;
  int joint_state_connection_id;
  ulapi_task_struct *joint_state_connection_thread;
  joint_state_connection_thread_args *joint_state_connection_args; 

  joint_state_server_id = args->joint_state_server_id;
  period = args->period;

  while (true) {
    if (debug) printf("waiting for joint state connection...\n");
    joint_state_connection_id = ulapi_socket_get_connection_id(joint_state_server_id);
    if (joint_state_connection_id < 0) {
      fprintf(stderr, "can't get a joint state connection connectons\n");
      break;
    }
     
    if (debug) printf("got a joint state connection on id %d\n", joint_state_connection_id);

    // spawn a connection thread
    joint_state_connection_thread = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*joint_state_connection_thread)));
    joint_state_connection_args = reinterpret_cast<joint_state_connection_thread_args *>(malloc(sizeof(*joint_state_connection_args)));

    ulapi_task_init(joint_state_connection_thread);
    joint_state_connection_args->joint_state_connection_id = joint_state_connection_id;
    joint_state_connection_args->joint_state_connection_thread = joint_state_connection_thread;
    joint_state_connection_args->period = period;
    ulapi_task_start(joint_state_connection_thread, reinterpret_cast<ulapi_task_code>(joint_state_connection_thread_code), reinterpret_cast<void *>(joint_state_connection_args), ulapi_prio_highest(), 0);
  } // while (true)

  ulapi_socket_close(joint_state_server_id);

  if (debug) printf("server on %d done\n", joint_state_server_id);

  return;
}

/*
  Arguments:

  -m <#> -- joint message socket port
  -s <#> -- joint state socket port
  -t <#> -- period for sending joint states, in seconds
  -d     -- turn debug printing on
*/

int main(int argc, char *argv[])
{
  int option;
  int ival;
  double dval;
  int joint_message_server_port = JOINT_MESSAGE_PORT_DEFAULT;
  int joint_state_server_port = JOINT_STATE_PORT_DEFAULT;
  int joint_message_server_id;
  int joint_state_server_id;
  ulapi_task_struct joint_message_server_thread;
  ulapi_task_struct joint_state_server_thread;
  joint_message_server_thread_args joint_message_server_args; 
  joint_state_server_thread_args joint_state_server_args; 
  double period = 1;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":m:s:t:d");
    if (option == -1) break;

    switch (option) {
    case 'm':
      ival = atoi(optarg);
      joint_message_server_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      joint_state_server_port = ival;
      break;

    case 't':
      dval = atof(optarg);
      period = dval;
      break;

    case 'd':
      debug = true;
      break;

    case ':':
      fprintf(stderr, "missing value for -%c\n", optopt);
      return 1;
      break;

    default:
      fprintf (stderr, "unrecognized option -%c\n", optopt);
      return 1;
      break;
    } // switch (option)
  }   // while (true) for getopt

  ulapi_mutex_init(&robot_mutex, 1);
  the_robot.print_robot_info();

  joint_message_server_id = ulapi_socket_get_server_id(joint_message_server_port);
  if (joint_message_server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", joint_message_server_port);
    return 1;
  }
  ulapi_task_init(&joint_message_server_thread);
  joint_message_server_args.joint_message_server_id = joint_message_server_id;
  ulapi_task_start(&joint_message_server_thread, reinterpret_cast<ulapi_task_code>(joint_message_server_thread_code), reinterpret_cast<void *>(&joint_message_server_args), ulapi_prio_highest(), 0);

  joint_state_server_id = ulapi_socket_get_server_id(joint_state_server_port);
  if (joint_state_server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", joint_state_server_port);
    return 1;
  }
  ulapi_task_init(&joint_state_server_thread);
  joint_state_server_args.joint_state_server_id = joint_state_server_id;
  joint_state_server_args.period = period;
  ulapi_task_start(&joint_state_server_thread, reinterpret_cast<ulapi_task_code>(joint_state_server_thread_code), reinterpret_cast<void *>(&joint_state_server_args), ulapi_prio_highest(), 0);

  /*
    In the foreground we read input and update the robot state.

    Things you can type, where <#> is the joint number, 1 .. max

    <blank line> : prints out the current robot state
    set <#> pos | pmin | pmax | vmax : sets the joint's position or limits
    get <#> : prints the joint state
  */

  bool done = false;
  while (! done) {
    char *ptr;
    char *endptr;
    int ival;
    float fval;
    bool bret;
    int joint;

    // print prompt
    printf("> ");
    fflush(stdout);
    // get input line
    if (NULL == fgets(inbuf, sizeof(inbuf), stdin)) break;
    // skip leading whitespace
    ptr = inbuf;
    while (isspace(*ptr)) ptr++;
    // strip off trailing whitespace
    endptr = inbuf + strlen(inbuf);
    while ((isspace(*endptr) || 0 == *endptr) && endptr >= ptr) *endptr-- = 0;
    while (endptr >= ptr) *endptr = tolower(*endptr--);
    // now 'ptr' is the stripped input string

    do {
      if (0 == *ptr) {		// blank line, print state
	ulapi_mutex_take(&robot_mutex);
	the_robot.print_robot_info();
	ulapi_mutex_give(&robot_mutex);
	break;
      }

      if ('q' == *ptr) {	// quit
	done = true;
	break;
      }

      if (! strncmp(ptr, "set", strlen("set"))) {
	ptr += strlen("set");
	if (! isspace(*ptr)) {
	  printf("need a joint and value to set\n");
	  break;
	}
	ival = strtol(ptr, &endptr, 0);
	if (endptr == ptr || isgraph(*endptr)) {
	  printf("need a joint to set\n");
	  break;
	}
	joint = ival;
	ptr = endptr;
	while (isspace(*ptr)) ptr++;

	if (! strncmp(ptr, "pos", strlen("pos"))) {
	  ptr += strlen("pos");
	  if (! isspace(*ptr)) {
	    printf("missing position value\n");
	    break;
	  }
	  fval = strtod(ptr, &endptr);
	  if (endptr == ptr || isgraph(*endptr)) {
	    printf("bad position value\n");
	    break;
	  }
	  ulapi_mutex_take(&robot_mutex);
	  bret = the_robot.set_robot_pos(fval, joint-1);
	  ulapi_mutex_give(&robot_mutex);
	  if (! bret) {
	    printf("can't set joint %d position to %f\n", joint, dval);
	  }
	  break;
	}

	if (! strncmp(ptr, "pmin", strlen("pmin"))) {
	  ptr += strlen("pmin");
	  if (! isspace(*ptr)) {
	    printf("missing min value\n");
	    break;
	  }
	  fval = strtod(ptr, &endptr);
	  if (endptr == ptr || isgraph(*endptr)) {
	    printf("bad min value\n");
	    break;
	  }
	  ulapi_mutex_take(&robot_mutex);
	  bret = the_robot.set_robot_pmin(fval, joint-1);
	  ulapi_mutex_give(&robot_mutex);
	  if (! bret) {
	    printf("can't set joint %d min value to %f\n", joint, dval);
	  }
	  break;
	}

	if (! strncmp(ptr, "pmax", strlen("pmax"))) {
	  ptr += strlen("pmax");
	  if (! isspace(*ptr)) {
	    printf("missing max value\n");
	    break;
	  }
	  fval = strtod(ptr, &endptr);
	  if (endptr == ptr || isgraph(*endptr)) {
	    printf("bad max value\n");
	    break;
	  }
	  ulapi_mutex_take(&robot_mutex);
	  bret = the_robot.set_robot_pmax(fval, joint-1);
	  ulapi_mutex_give(&robot_mutex);
	  if (! bret) {
	    printf("can't set joint %d max value to %f\n", joint, dval);
	  }
	  break;
	}

	printf("need 'pos', 'pmin', or 'pmax' to set\n");
	break;
      }	// matches "set"
    } while (false); // do ... wrapper
  } // while (! done)

  return 0;
}

