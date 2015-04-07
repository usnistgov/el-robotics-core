/*
  This implements the simple message joint command and status interface
  described here: 

  http://wiki.ros.org/Industrial/Tutorials/\
  create_joint_position_streaming_interface_using_tcp_socket_libraries

  Two sockets are served. One at port 11000 by default is for
  receiving messages requesting that the robot move to a set of target
  joint angles. Another at port 11002 by default is for continuous
  sending of robot joint states.

  You ran these:

  rosrun nist_kitting simple_message_sim -d

  roslaunch industrial_robot_client robot_interface_streaming.launch robot_ip:=localhost

  rosrun nist_kitting irclient_sh

  In the irclient_sh, you typed:

  1 2 3 4 5 6

  and in the robot_interface_streaming window, got responses variously like this;

  [ INFO] [1420495468.523931743]: Received new goal
  [ERROR] [1420495468.524008975]: Joint trajectory action rejected: waiting for (initial) feedback from controller

  or this: 

  [ INFO] [1420495460.220963519]: Received new goal
  [ INFO] [1420495460.221227503]: Publishing trajectory
  [ WARN] [1420495460.221340846]: Ignoring goal time tolerance in action goal, may be supported in the future

  Sometimes it works, sometimes not. Figure out how to fix the "waiting for (initial) feedback from controller" error.

  *** There's a watchdog reset -- make it report faster ***
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

// Request message connection code ----------------------

struct request_connection_thread_args {
  void *thread;
  int id;
};

static void request_connection_thread_code(request_connection_thread_args *args)
{
  void *thread;
  int id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  char *ptr;
  int nchars;
  int nleft;
  int length;
  int message_type;
  ping_reply_message pingrep;
  joint_traj_pt_request_message jtreq;
  joint_traj_pt_reply_message jtrep;
  joint_info jinfo;
  cart_traj_pt_request_message ctreq;
  cart_traj_pt_reply_message ctrep;
  float f1, f2, f3, f4, f5, f6, f7;

  thread = args->thread;
  id = args->id;
  free(args);

  bool done = false;
  while (! done) {
    nchars = ulapi_socket_read(id, inbuf, sizeof(inbuf));
    if (nchars <= 0) break;
    inbuf[sizeof(inbuf)-1] = 0;
    ptr = inbuf;
    nleft = nchars;

    while (nleft > 0) {
      // get the length and type of the message
      memcpy(&length, ptr, sizeof(length));
      memcpy(&message_type, ptr + sizeof(length), sizeof(message_type));

      // switch on the message type and handle it
      switch (message_type) {
      case MESSAGE_PING:
	nchars = ulapi_socket_write(id, reinterpret_cast<char *>(&pingrep), sizeof(pingrep));
	if (nchars < 0) done = true;
	break;

      case MESSAGE_JOINT_TRAJ_PT:
	jtreq.read_joint_traj_pt_request(ptr);
	if (debug) {
	  printf("connection %d requested:\n", id);
	  jtreq.print_joint_traj_pt_request();
	}
	ulapi_mutex_take(&robot_mutex);
	for (int t = 0; t < JOINT_MAX; t++) {
	  if (! jtreq.get_pos(&f1, t)) break;
	  the_robot.set_robot_joint_pos(f1, t);
	}
	ulapi_mutex_give(&robot_mutex);
	jtrep.set_joint_traj_pt_reply(REPLY_SUCCESS);
	nchars = ulapi_socket_write(id, reinterpret_cast<char *>(&jtrep), sizeof(jtrep));
	if (debug) {
	  printf("replied to connection %d:\n", id);
	  jtrep.print_joint_traj_pt_reply();
	}
	if (nchars < 0) done = true;
	break;

      case MESSAGE_CART_TRAJ_PT:
	ctreq.read_cart_traj_pt_request(ptr);
	if (debug) {
	  printf("connection %d requested:\n", id);
	  ctreq.print_cart_traj_pt_request();
	}
	ulapi_mutex_take(&robot_mutex);
	if (! ctreq.get_pos(&f1, &f2, &f3, &f4, &f5, &f6, &f7)) break;
	the_robot.set_robot_cart_pos(f1, f2, f3, f4, f5, f6, f7);
	ulapi_mutex_give(&robot_mutex);
	ctrep.set_seq_number(ctreq.get_seq_number());
	ctrep.set_cart_traj_pt_reply(REPLY_SUCCESS);
	nchars = ulapi_socket_write(id, reinterpret_cast<char *>(&ctrep), sizeof(ctrep));
	if (debug) {
	  printf("replied to connection %d:\n", id);
	  ctrep.print_cart_traj_pt_reply();
	}
	if (nchars < 0) done = true;
	break;

      default:
	// unknown message
	if (debug) printf("unknown message type: %d\n", message_type);
	break;
      } // switch (message type)
      nleft -= (sizeof(length) + length);
      ptr += (sizeof(length) + length);
    }	// while (nleft)
  }	// while (true)

  ulapi_socket_close(id);

  if (debug) printf("simple message connection handler %d done\n", id);

  free(thread);

  return;
}

// State connection code ----------------------

struct state_connection_thread_args {
  void *thread;
  int id;
  double period;
};

static void state_connection_thread_code(state_connection_thread_args *args)
{
  void *thread;
  int id;
  double period;
  joint_traj_pt_state_message jsmsg;
  robot_status_message rsmsg;
  object_state_message obj_state(3);
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  int nchars, len;

  thread = args->thread;
  id = args->id;
  period = args->period;
  free(args);

  for (int t = 0; t < obj_state.object_number(); t++) {
    obj_state.objects[t].id = t + 1;
    obj_state.objects[t].x = t + 1.2;
    obj_state.objects[t].y = t - 3.4;
    obj_state.objects[t].z = t + 5.6;
    obj_state.objects[t].qx = 0;
    obj_state.objects[t].qy = 0;
    obj_state.objects[t].qz = 0;
    obj_state.objects[t].qw = 1;
  }

  while (true) {
    float p;
    int i;

    ulapi_mutex_take(&robot_mutex);
    for (int t = 0; t < JOINT_MAX; t++) {
      if (the_robot.get_robot_joint_pos(&p, t)) jsmsg.set_pos(p, t);
    }
    ulapi_mutex_give(&robot_mutex);
    nchars = ulapi_socket_write(id, reinterpret_cast<char *>(&jsmsg), sizeof(jsmsg));
    if (nchars < 0) break;

    ulapi_mutex_take(&robot_mutex);

    the_robot.get_drives_powered(&i);
    rsmsg.set_drives_powered(i);

    the_robot.get_e_stopped(&i);
    rsmsg.set_e_stopped(i);

    the_robot.get_in_error(&i);
    rsmsg.set_in_error(i);

    the_robot.get_in_motion(&i);
    rsmsg.set_in_motion(i);

    the_robot.get_mode(&i);
    rsmsg.set_mode(i);

    the_robot.get_motion_possible(&i);
    rsmsg.set_motion_possible(i);

    ulapi_mutex_give(&robot_mutex);

    nchars = ulapi_socket_write(id, reinterpret_cast<char *>(&rsmsg), sizeof(rsmsg));
    if (nchars < 0) break;

    len = obj_state.size();
    if (len <= sizeof(outbuf)) {
      obj_state.write_object_state(outbuf, sizeof(outbuf));
      nchars = ulapi_socket_write(id, outbuf, len);
    }

    ulapi_wait(period * 1e9);
  }

  ulapi_socket_close(id);

  if (debug) printf("joint state connection handler %d done\n", id);

  free(thread);

  return;
}

// Request message server code ----------------------

struct request_server_thread_args {
  int id;	      // socket id to serve up for connections
};

static void request_server_thread_code(request_server_thread_args *args)
{
  int id;
  int connection_id;
  ulapi_task_struct *request_connection_thread;
  request_connection_thread_args *request_connection_args; 

  id = args->id;

  while (true) {
    if (debug) printf("waiting for a trajectory point connection...\n");
    connection_id = ulapi_socket_get_connection_id(id);
    if (connection_id < 0) {
      fprintf(stderr, "can't get a trajectory point connecton\n");
      break;
    }
     
    if (debug) printf("got a trajectory point connection on id %d\n", connection_id);

    // spawn a connection thread
    request_connection_thread = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*request_connection_thread)));
    request_connection_args = reinterpret_cast<request_connection_thread_args *>(malloc(sizeof(*request_connection_args)));

    ulapi_task_init(request_connection_thread);
    request_connection_args->id = connection_id;
    request_connection_args->thread = request_connection_thread;
    ulapi_task_start(request_connection_thread, reinterpret_cast<ulapi_task_code>(request_connection_thread_code), reinterpret_cast<void *>(request_connection_args), ulapi_prio_highest(), 0);
  } // while (true)

  ulapi_socket_close(id);

  if (debug) printf("server on %d done\n", id);

  return;
}

// State server code ----------------------

struct state_server_thread_args {
  int id;		      // socket id to serve up for connections
  double period;
};

static void state_server_thread_code(state_server_thread_args *args)
{
  int id;
  double period;
  int connection_id;
  ulapi_task_struct *state_connection_thread;
  state_connection_thread_args *state_connection_args; 

  id = args->id;
  period = args->period;

  while (true) {
    if (debug) printf("waiting for a robot state connection...\n");
    connection_id = ulapi_socket_get_connection_id(id);
    if (connection_id < 0) {
      fprintf(stderr, "can't get a robot state connection\n");
      break;
    }
     
    if (debug) printf("got a robot state connection on id %d\n", connection_id);

    // spawn a connection thread
    state_connection_thread = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*state_connection_thread)));
    state_connection_args = reinterpret_cast<state_connection_thread_args *>(malloc(sizeof(*state_connection_args)));

    ulapi_task_init(state_connection_thread);
    state_connection_args->id = connection_id;
    state_connection_args->thread = state_connection_thread;
    state_connection_args->period = period;
    ulapi_task_start(state_connection_thread, reinterpret_cast<ulapi_task_code>(state_connection_thread_code), reinterpret_cast<void *>(state_connection_args), ulapi_prio_highest(), 0);
  } // while (true)

  ulapi_socket_close(id);

  if (debug) printf("server on %d done\n", id);

  return;
}

static void print_help(void)
{
  printf("Arguments:\n");
  printf("-m <#> : joint message socket port\n");
  printf("-s <#> : joint state socket port\n");
  printf("-t <#> : period for sending joint states, in seconds\n");
  printf("-d     : turn debug printing on\n");
  printf("-?     : print this help message\n");
  printf("\n");
  printf("Commands:\n");
  printf("<blank line> : prints out the current robot state\n");
  printf("set <#> pos | pmin | pmax | vmax : sets the joint's position or limits\n");
  printf("get <#> : prints the joint state\n");
  printf( "?      : print this help message\n");
}

/*
  Arguments:

  -m <#> : joint message socket port
  -s <#> : joint state socket port
  -t <#> : period for sending joint states, in seconds
  -d     : turn debug printing on
*/

int main(int argc, char *argv[])
{
  int option;
  int ival;
  double dval;
  int message_port = MESSAGE_PORT_DEFAULT;
  int state_port = STATE_PORT_DEFAULT;
  int request_server_id;
  int state_server_id;
  ulapi_task_struct request_server_thread;
  ulapi_task_struct state_server_thread;
  request_server_thread_args request_server_args; 
  state_server_thread_args state_server_args; 
  double period = 0.2;		// ROS recommends 2 Hz at least
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":m:s:t:d?");
    if (option == -1) break;

    switch (option) {
    case 'm':
      ival = atoi(optarg);
      message_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      state_port = ival;
      break;

    case 't':
      dval = atof(optarg);
      period = dval;
      break;

    case 'd':
      debug = true;
      break;

    case '?':
      print_help();
      return 0;
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

  request_server_id = ulapi_socket_get_server_id(message_port);
  if (request_server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", message_port);
    return 1;
  }
  ulapi_task_init(&request_server_thread);
  request_server_args.id = request_server_id;
  ulapi_task_start(&request_server_thread, reinterpret_cast<ulapi_task_code>(request_server_thread_code), reinterpret_cast<void *>(&request_server_args), ulapi_prio_highest(), 0);

  state_server_id = ulapi_socket_get_server_id(state_port);
  if (state_server_id < 0) {
    fprintf(stderr, "can't serve port %d\n", state_port);
    return 1;
  }
  ulapi_task_init(&state_server_thread);
  state_server_args.id = state_server_id;
  state_server_args.period = period;
  ulapi_task_start(&state_server_thread, reinterpret_cast<ulapi_task_code>(state_server_thread_code), reinterpret_cast<void *>(&state_server_args), ulapi_prio_highest(), 0);

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
    int ret;
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

      if ('?' == *ptr) {	// help
	print_help();
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
	  ret = the_robot.set_robot_joint_pos(fval, joint-1);
	  ulapi_mutex_give(&robot_mutex);
	  if (! ret) {
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
	  ret = the_robot.set_robot_joint_min(fval, joint-1);
	  ulapi_mutex_give(&robot_mutex);
	  if (! ret) {
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
	  ret = the_robot.set_robot_joint_max(fval, joint-1);
	  ulapi_mutex_give(&robot_mutex);
	  if (! ret) {
	    printf("can't set joint %d max value to %f\n", joint, dval);
	  }
	  break;
	}

	printf("need 'pos', 'pmin', or 'pmax' to set\n");
	break;
      }	// matches "set"
      printf("?\n");
    } while (false); // do ... wrapper
  } // while (! done)

  return 0;
}

