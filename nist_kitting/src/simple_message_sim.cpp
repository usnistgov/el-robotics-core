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
#include <string.h>		// memcpy 

#include <ulapi.h>

enum {
  JOINT_MESSAGE_PORT_DEFAULT = 11000,
  JOINT_STATE_PORT_DEFAULT = 11002
};

static bool debug = false;

struct joint_info {
  double pos;
  double pmin;
  double pmax;
  double vel;
  double vmax;

  joint_info() {
    pos = 0;
    pmin = -1;
    pmax = 1;
    vel = 0;
    vmax = 1;
  }

  void print_joint_info(const char *prefix = "") {
    printf("%sPosition: %f\n", prefix, pos);
    printf("%sPos Min:  %f\n", prefix, pmin);
    printf("%sPos Max:  %f\n", prefix, pmax);
    printf("%sVelocity: %f\n", prefix, vel);
    printf("%sVel Max:  %f\n", prefix, vmax);
  };
};

struct robot_info {
  enum {JOINT_MAX = 10};
  joint_info joint[JOINT_MAX];
  unsigned int joints;

  robot_info(unsigned int j = JOINT_MAX) {
    joints = j;
  };

  void print_robot_info(const char *prefix = "") {
    for (int t = 0; t < joints; t++) {
      printf("%sJoint %d:\n", prefix, t+1);
      joint[t].print_joint_info("  ");
    }
  }
};

// global robot info, and its mutex
static robot_info the_robot;
static ulapi_mutex_struct robot_mutex;

/*
  Joint command:

  Client request:

  LENGTH [4 bytes] (the bytes in the message, not including this
  length specifier)

  10 [4 bytes[ (MSG_ID – JOINT MESSAGE)

  2 [4 bytes] (COMM_TYPE - REQUEST)
  0 [4 bytes] (REPLY_TYPE – N/A)

  SEQ_NUMBER [4 bytes] - The sequence number is the number assigned by
  ROS to each of the points (i.e. this is always 0 or positive). A
  value of -1 indicates the end of a trajectory, a value of -2
  indicates a stop (in both cases the controller stops, joint data is
  not valid for these special types)

  JOINT_DATA [10 x 4 bytes] (in rads (floats))

  Server reply:

  LENGTH [4 bytes] (the bytes in the message, not including this
  length specifier)

  10 [4 bytes] (MSG_ID – JOINT MESSAGE)

  3 [4 bytes] (COMM_TYPE – RESPONSE)

  REPLY [4 bytes] (1 = SUCCESS, 2 = FAILURE)

  UNUSED [4 bytes] (same position in message as SEQ NUMBER

  UNUSED [10 x 4 bytes] (same position in message as JOINT_DATA
*/

typedef enum {
  MESSAGE_JOINT = 10,
  MESSAGE_JOINT_STATE = 11
} message_types;

typedef enum {
  COMM_TOPIC = 1,
  COMM_REQUEST = 2,
  COMM_REPLY = 3
} comm_types;

typedef enum {
  REPLY_NA = 0,
  REPLY_SUCCESS = 1,
  REPLY_FAILURE = 2
} reply_types;

enum {JOINT_MAX = 10};

struct joint_request_message {
  int length;		  // 4 bytes, constant value should be 14x4 = 56
  int message_type;	  // 4 bytes, constant value 10, JOINT MESSAGE
  int comm_type;	  // 4 bytes, constant value 2, REQUEST
  int reply_type;	  // 4 bytes, N/A
  int seq_number;	  // 4 bytes, >= 0
  float joints[JOINT_MAX]; // 10 4-byte floats, one per joint

  joint_request_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(seq_number) +
      sizeof(joints);
    message_type = MESSAGE_JOINT;
    comm_type = COMM_REQUEST;
    reply_type = REPLY_NA;
    seq_number = 1;
    // caller will need to set joints with method below
  };

  void set_joint_request(int _joints[JOINT_MAX]) {
    memcpy(joints, _joints, sizeof(joints));
  };
};

struct joint_reply_message {
  int length;		  // 4 bytes, constant value should be 14x4 = 56
  int message_type;	  // 4 bytes, constant value 10, JOINT MESSAGE
  int comm_type;	  // 4 bytes, constant value 2, REQUEST
  int reply_type;	  // 4 bytes, 1 = SUCCESS, 2 = FAILURE
  int unused_1;		  // 4 bytes, N/A
  float unused_2[JOINT_MAX];	// 10 4-byte floats, N/A

  joint_reply_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(unused_1) +
      sizeof(unused_2);
    message_type = MESSAGE_JOINT;
    comm_type = COMM_REPLY;
    // caller will need to set reply_type with method below
  };

  void set_joint_reply(reply_types reply) {
    reply_type = reply;
  };
};

struct joint_state_message {
  int length;		  // 4 bytes, constant value should be 14x4 = 56
  int message_type;	  // 4 bytes, constant value 10, JOINT MESSAGE
  int comm_type;	  // 4 bytes, constant value 1, TOPIC
  int reply_type;	  // 4 bytes, N/A
  int unused_1;		  // 4 bytes, N/A
  float joints[JOINT_MAX];	// 10 4-byte floats, N/A

  joint_state_message() {
    length = sizeof(message_type) +
      sizeof(comm_type) + 
      sizeof(reply_type) +
      sizeof(unused_1) +
      sizeof(joints);
    message_type = MESSAGE_JOINT_STATE;
    comm_type = COMM_TOPIC;
    reply_type = REPLY_NA;
    // caller will need to set joints with method below
  };

  void set_joint_state(int _joints[JOINT_MAX]) {
    memcpy(joints, _joints, sizeof(joints));
  };
};

// Joint message client code ----------------------

struct joint_message_client_thread_args {
  void *joint_message_client_thread;
  int joint_message_connection_id;
};

static void joint_message_client_thread_code(joint_message_client_thread_args *args)
{
  void *joint_message_client_thread;
  int joint_message_connection_id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  int nchars;

  joint_message_client_thread = args->joint_message_client_thread;
  joint_message_connection_id = args->joint_message_connection_id;
  free(args);

  while (true) {
    nchars = ulapi_socket_read(joint_message_connection_id, inbuf, sizeof(inbuf));
    if (nchars < 0) break;
    inbuf[sizeof(inbuf)-1] = 0;
    if (debug) printf("client %d requested ``%s''\n", joint_message_connection_id, inbuf);

    // FIXME -- need to parse requests

    snprintf(outbuf, sizeof(outbuf), "hello %d", joint_message_connection_id);
    outbuf[sizeof(outbuf)-1] = 0;
    nchars = ulapi_socket_write(joint_message_connection_id, outbuf, strlen(outbuf));
    if (nchars < 0) break;
    if (debug) printf("we responded ``%s''\n", outbuf);

    // FIXME -- need to write out replies
  }

  ulapi_socket_close(joint_message_connection_id);

  if (debug) printf("joint message client handler %d done\n", joint_message_connection_id);

  free(joint_message_client_thread);

  return;
}

// Joint state client code ----------------------

struct joint_state_client_thread_args {
  void *joint_state_client_thread;
  int joint_state_connection_id;
  double period;
};

static void joint_state_client_thread_code(joint_state_client_thread_args *args)
{
  void *joint_state_client_thread;
  int joint_state_connection_id;
  double period;
  enum {OUTBUF_LEN = 1024};
  char outbuf[OUTBUF_LEN];
  int nchars;

  joint_state_client_thread = args->joint_state_client_thread;
  joint_state_connection_id = args->joint_state_connection_id;
  period = args->period;
  free(args);

  while (true) {
    snprintf(outbuf, sizeof(outbuf), "hello %d", joint_state_connection_id);
    outbuf[sizeof(outbuf)-1] = 0;
    nchars = ulapi_socket_write(joint_state_connection_id, outbuf, strlen(outbuf));
    if (nchars < 0) break;
    if (debug) printf("we responded ``%s''\n", outbuf);

    ulapi_wait(period * 1e9);
  }

  ulapi_socket_close(joint_state_connection_id);

  if (debug) printf("joint state client handler %d done\n", joint_state_connection_id);

  free(joint_state_client_thread);

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
  ulapi_task_struct *joint_message_client_thread;
  joint_message_client_thread_args *joint_message_client_args; 

  joint_message_server_id = args->joint_message_server_id;

  while (true) {
    if (debug) printf("waiting for joint message client connection...\n");
    joint_message_connection_id = ulapi_socket_get_connection_id(joint_message_server_id);
    if (joint_message_connection_id < 0) {
      fprintf(stderr, "can't get joint message client connectons\n");
      break;
    }
     
    if (debug) printf("got a joint message client connection on id %d\n", joint_message_connection_id);

    // spawn a client thread
    joint_message_client_thread = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*joint_message_client_thread)));
    joint_message_client_args = reinterpret_cast<joint_message_client_thread_args *>(malloc(sizeof(*joint_message_client_args)));

    ulapi_task_init(joint_message_client_thread);
    joint_message_client_args->joint_message_connection_id = joint_message_connection_id;
    joint_message_client_args->joint_message_client_thread = joint_message_client_thread;
    ulapi_task_start(joint_message_client_thread, reinterpret_cast<ulapi_task_code>(joint_message_client_thread_code), reinterpret_cast<void *>(joint_message_client_args), ulapi_prio_highest(), 0);
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
  ulapi_task_struct *joint_state_client_thread;
  joint_state_client_thread_args *joint_state_client_args; 

  joint_state_server_id = args->joint_state_server_id;
  period = args->period;

  while (true) {
    if (debug) printf("waiting for joint state client connection...\n");
    joint_state_connection_id = ulapi_socket_get_connection_id(joint_state_server_id);
    if (joint_state_connection_id < 0) {
      fprintf(stderr, "can't get a joint state client connectons\n");
      break;
    }
     
    if (debug) printf("got a joint state client connection on id %d\n", joint_state_connection_id);

    // spawn a client thread
    joint_state_client_thread = reinterpret_cast<ulapi_task_struct *>(malloc(sizeof(*joint_state_client_thread)));
    joint_state_client_args = reinterpret_cast<joint_state_client_thread_args *>(malloc(sizeof(*joint_state_client_args)));

    ulapi_task_init(joint_state_client_thread);
    joint_state_client_args->joint_state_connection_id = joint_state_connection_id;
    joint_state_client_args->joint_state_client_thread = joint_state_client_thread;
    joint_state_client_args->period = period;
    ulapi_task_start(joint_state_client_thread, reinterpret_cast<ulapi_task_code>(joint_state_client_thread_code), reinterpret_cast<void *>(joint_state_client_args), ulapi_prio_highest(), 0);
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

  // we in the foreground read input and update the robot model as needed
  while (true) {
    if (NULL == fgets(inbuf, sizeof(inbuf)-1, stdin)) {
      // closed input
      break;
    }
    // FIXME -- add handing of robot info through the terminal
  }

  return 0;
}

