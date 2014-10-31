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

// Joint message client code ----------------------

struct joint_message_client_thread_args {
  void *joint_message_client_thread;
  int joint_message_client_id;
};

static void joint_message_client_thread_code(joint_message_client_thread_args *args)
{
  void *joint_message_client_thread;
  int joint_message_client_id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  int nchars;
  joint_reply_message repmsg;

  joint_message_client_thread = args->joint_message_client_thread;
  joint_message_client_id = args->joint_message_client_id;

  while (true) {
    nchars = ulapi_socket_read(joint_message_client_id, inbuf, sizeof(inbuf));
    if (nchars <= 0) break;

    repmsg.read_joint_reply(inbuf);
    if (debug) repmsg.print_joint_reply();
  }

  ulapi_socket_close(joint_message_client_id);

  if (debug) printf("joint message client handler %d done\n", joint_message_client_id);

  return;
}

// Joint state client code ----------------------

struct joint_state_client_thread_args {
  void *joint_state_client_thread;
  int joint_state_client_id;
};

static void joint_state_client_thread_code(joint_state_client_thread_args *args)
{
  void *joint_state_client_thread;
  int joint_state_client_id;
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  int nchars;
  joint_state_message jsmsg;

  joint_state_client_thread = args->joint_state_client_thread;
  joint_state_client_id = args->joint_state_client_id;

  while (true) {
    nchars = ulapi_socket_read(joint_state_client_id, inbuf, sizeof(inbuf));
    if (nchars <= 0) break;

    jsmsg.read_joint_state(inbuf);
    if (debug) jsmsg.print_joint_state();
  }

  ulapi_socket_close(joint_state_client_id);

  if (debug) printf("joint state client handler %d done\n", joint_state_client_id);

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
  int joint_message_client_port = JOINT_MESSAGE_PORT_DEFAULT;
  int joint_state_client_port = JOINT_STATE_PORT_DEFAULT;
  int joint_message_client_id;
  int joint_state_client_id;
  ulapi_task_struct joint_message_client_thread;
  ulapi_task_struct joint_state_client_thread;
  joint_message_client_thread_args joint_message_client_args; 
  joint_state_client_thread_args joint_state_client_args; 
  enum {INBUF_LEN = 1024};
  char inbuf[INBUF_LEN];
  joint_request_message reqmsg;

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
      joint_message_client_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      joint_state_client_port = ival;
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

  // start message reply handler
  joint_message_client_id = ulapi_socket_get_client_id(joint_message_client_port, host);
  if (joint_message_client_id < 0) {
    fprintf(stderr, "can't connect to %s on port %d\n", host, joint_message_client_port);
    return 1;
  }
  ulapi_task_init(&joint_message_client_thread);
  joint_message_client_args.joint_message_client_thread = reinterpret_cast<void *>(joint_message_client_thread);
  joint_message_client_args.joint_message_client_id = joint_message_client_id;
  ulapi_task_start(&joint_message_client_thread, reinterpret_cast<ulapi_task_code>(joint_message_client_thread_code), reinterpret_cast<void *>(&joint_message_client_args), ulapi_prio_highest(), 0);

  // start state reply handler
  joint_state_client_id = ulapi_socket_get_client_id(joint_state_client_port, host);
  if (joint_state_client_id < 0) {
    fprintf(stderr, "can't connect to %s on port %d\n", host, joint_state_client_port);
    return 1;
  }
  ulapi_task_init(&joint_state_client_thread);
  joint_state_client_args.joint_state_client_thread = reinterpret_cast<void *>(joint_state_client_thread);
  joint_state_client_args.joint_state_client_id = joint_state_client_id;
  ulapi_task_start(&joint_state_client_thread, reinterpret_cast<ulapi_task_code>(joint_state_client_thread_code), reinterpret_cast<void *>(&joint_state_client_args), ulapi_prio_highest(), 0);

  // we in the foreground read input and update the robot model as needed
  bool done = false;
  while (! done) {
    char *ptr;
    char *endptr;
    float fval;
    int nchars;

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
	reqmsg.set_pos(fval, t);
	ptr = endptr;
      }
      reqmsg.set_seq_number(reqmsg.get_seq_number()+1);
      nchars = ulapi_socket_write(joint_message_client_id, reinterpret_cast<char *>(&reqmsg), sizeof(reqmsg));
      if (nchars <= 0) break;

    } while (false);		// do ... wrapper

  } // while (true)

  return 0;
}

