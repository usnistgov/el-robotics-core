/*
  Simple message client tester.

  Principles of operation: the foreground process reads simple message
  requests for joint moves and sends them to the server. Two
  background threads handle replies and joint states. The replies are
  printed when them come in, normally just after the foreground
  process sends the request. The states are read in and a global data
  structure is updated. This is printed out when the foreground
  process gets a blank line. The global state is mutexed so that a
  request to print out the state doesn't interfere with the state
  updating thread.

  The background process reply printing has the potential to
  interleave its output with the terminal, but normally the user would
  type in the request and then wait a bit before the next request, and
  the reply printing would finish before that. Interference would be
  an annoyance but would not be an error.
 */

#include <stddef.h>		// NULL, sizeof
#include <stdio.h>		// printf
#include <stdlib.h>		// atoi, strtof
#include <ctype.h>		// isspace

#include <ulapi.h>		// getopt, ulapi_socket_XXX

#include "simple_message_defs.h"

static bool debug = false;

// Reply message client code ----------------------

struct reply_client_thread_args {
  void *thread;
  int id;
};

static void reply_client_thread_code(reply_client_thread_args *args)
{
  void *thread;
  int id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  char *ptr;
  int nchars;
  int nleft;
  int length;
  int message_type;
  joint_traj_pt_reply_message jtp_rep;

  thread = args->thread;
  id = args->id;

  while (true) {
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
	break;
      case MESSAGE_JOINT_TRAJ_PT:
	jtp_rep.read_joint_traj_pt_reply(ptr);
	if (debug) jtp_rep.print_joint_traj_pt_reply();
	break;
      default:
	if (debug) printf("unknown reply type: %d\n", message_type);
	break;
      } // switch (message type)
      nleft -= (sizeof(length) + length);
      ptr += (sizeof(length) + length);
    } // while (nleft)
  }   // while (true)

  ulapi_socket_close(id);

  if (debug) printf("joint state client handler %d done\n", id);

  return;
}

// State client code that we read

struct state_client_thread_args {
  void *thread;
  int id;
};

static void state_client_thread_code(state_client_thread_args *args)
{
  void *thread;
  int id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  char *ptr;
  int nchars;
  int nleft;
  int length;
  int message_type;
  robot_status_message robot_status;
  joint_traj_pt_state_message jtp_state;

  thread = args->thread;
  id = args->id;

  while (true) {
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
      case MESSAGE_ROBOT_STATUS:
	robot_status.read_robot_status(ptr);
	if (debug) robot_status.print_robot_status();
	break;
	/* NOTE: JOINT_POSITION is deprecated, but JOINT_TRAJ_PT gives
	   an error in the industrial robot client. */
      case MESSAGE_JOINT_POSITION:
	jtp_state.read_joint_traj_pt_state(ptr);
	if (debug) jtp_state.print_joint_traj_pt_state();
	break;
      default:
	// unknown message
	if (debug) printf("unknown status type: %d\n", message_type);
	break;
      } // switch (message type)
      nleft -= (sizeof(length) + length);
      ptr += (sizeof(length) + length);
    } // while (nleft)
  }   // while (true)

  ulapi_socket_close(id);

  if (debug) printf("joint message client handler %d done\n", id);

  return;
}

/*
  Arguments:

  -h <name> -- host computer running simple message server
  -m <#>    -- joint message socket port
  -s <#>    -- joint state socket port
  -d        -- turn debug printing on
*/

int main(int argc, char *argv[])
{
  const char *host = "localhost";
  int option;
  int ival;
  int message_port = MESSAGE_PORT_DEFAULT;
  int state_port = STATE_PORT_DEFAULT;
  int message_client_id;
  int state_client_id;
  ulapi_task_struct reply_client_thread;
  ulapi_task_struct state_client_thread;
  reply_client_thread_args rc_args; 
  state_client_thread_args sc_args;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":h:m:s:d");
    if (option == -1) break;

    switch (option) {
    case 'h':
      host = optarg;
      break;

    case 'm':
      ival = atoi(optarg);
      message_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      state_port = ival;
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

  // connect to message server
  message_client_id = ulapi_socket_get_client_id(message_port, host);
  if (message_client_id < 0) {
    fprintf(stderr, "can't connect to %s on port %d\n", host, message_port);
    return 1;
  }

  // start message reply handler
  ulapi_task_init(&reply_client_thread);
  rc_args.thread = reinterpret_cast<void *>(reply_client_thread);
  rc_args.id = message_client_id;
  ulapi_task_start(&reply_client_thread, reinterpret_cast<ulapi_task_code>(reply_client_thread_code), reinterpret_cast<void *>(&rc_args), ulapi_prio_highest(), 0);

#if 0
  // connect to state server
  state_client_id = ulapi_socket_get_client_id(state_port, host);
  if (state_client_id < 0) {
    fprintf(stderr, "can't connect to %s on port %d\n", host, state_port);
    return 1;
  }

  // start state handler
  ulapi_task_init(&state_client_thread);
  sc_args.thread = reinterpret_cast<void *>(state_client_thread);
  sc_args.id = state_client_id;
  ulapi_task_start(&state_client_thread, reinterpret_cast<ulapi_task_code>(state_client_thread_code), reinterpret_cast<void *>(&sc_args), ulapi_prio_highest(), 0);
#endif

  // we in the foreground read input and update the robot model as needed
  bool done = false;
  while (! done) {
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    char *endptr;
    float fval;
    int nchars;
    joint_traj_pt_request_message jtp_req;

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
      if (0 == *ptr) break; // blank line

      if ('q' == *ptr) {	// quit
	done = true;
	break;
      }

      for (int t = 0; t < JOINT_MAX; t++) {
	fval = strtof(ptr, &endptr);
	if (endptr == ptr) break;
	jtp_req.set_pos(fval, t);
	ptr = endptr;
      }
      jtp_req.set_seq_number(jtp_req.get_seq_number()+1);
      nchars = ulapi_socket_write(message_client_id, reinterpret_cast<char *>(&jtp_req), sizeof(jtp_req));
      if (nchars <= 0) break;

    } while (false);		// do ... wrapper

  } // while (true)

  return 0;
}

