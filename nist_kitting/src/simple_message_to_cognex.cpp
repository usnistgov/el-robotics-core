/*
  simple_message_to_cognex.cpp

  Connects to the Simple Message object server, and converts object
  messages to Cognex format for each connected client.
*/

#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof, size_t */
#include <stdlib.h>		/* atoi, atof */
#include <string.h>
#include <ctype.h>

#include <iostream>
#include <map>
#include <string>

#include <ulapi.h>
#include <nist_kitting/cognex_db.h>

#include "simple_message_defs.h"

static bool debug = false;

/*
  Arguments:

  -h <name> -- host computer running simple message server
  -s <#>    -- simple message state socket port
  -p <#>    -- port number to server up for Cognex connections
  -t <#>    -- time period to send out Cognex data
  -d        -- turn debug printing on
*/

int main(int argc, char *argv[])
{
  enum {HOST_LEN = 256};
  char host[HOST_LEN] = "localhost";
  int state_port = STATE_PORT_DEFAULT;
  int cognex_port = COGNEX_PORT_DEFAULT;
  double period = 1;
  int option;
  int ival;
  double dval;
  int state_client_id;
  ulapi_task_struct cognex_client_thread;
  cognex_object_info_db db;
  ulapi_task_struct *server_task;
  ulapi_integer retval;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":h:s:p:t:d");
    if (option == -1) break;

    switch (option) {
    case 'h':
      strncpy(host, optarg, sizeof(host));
      host[sizeof(host)-1] = 0;
      break;

    case 's':
      ival = atoi(optarg);
      state_port = ival;
      break;

    case 'p':
      ival = atoi(optarg);
      cognex_port = ival;
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

#undef TESTING
#ifdef TESTING
  db.add(1, cognex_object_info("alice", 0.4, 1.2, 3.4, 0.95));
  db.print();

  db.add(1, cognex_object_info("bob", -0.4, -1.2, -3.4, -0.95));
  db.add(2, cognex_object_info("carol", 0.57808, 123.45, -234.56, 0.99));
  db.print();

  db.remove(1);
  db.print();
  db.add(3, cognex_object_info("david", 1, 2, 3, 1));

  return 0;
#endif

  // connect to state server
  state_client_id = ulapi_socket_get_client_id(state_port, host);
  if (state_client_id < 0) {
    fprintf(stderr, "can't connect to %s on port %d\n", host, state_port);
    return 1;
  }

  server_task = db.serve(cognex_port, period * 1e9);
  if (server_task == NULL) {
    fprintf(stderr, "can't serve port %d\n", cognex_port);
    return 1;
  }

  while (true) {
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    int nchars;
    int nleft;
    int length;
    int message_type;
    object_state_message obj_state;

    nchars = ulapi_socket_read(state_client_id, inbuf, sizeof(inbuf));
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
      case MESSAGE_JOINT_POSITION:
	break;

      case MESSAGE_OBJECT_STATE:
	if (0 == obj_state.read_object_state(ptr)) {
	  if (debug) obj_state.print_object_state();
	  for (int t = 0; t < obj_state.number; t++) {
	    db.add(obj_state.objects[t].id, cognex_object_info("FIXME", 0.5708, obj_state.objects[t].x, obj_state.objects[t].y, 0.95));
	  }
	}
	break;

      default:
	// unknown message
	break;
      } // switch (message type)
      nleft -= (sizeof(length) + length);
      ptr += (sizeof(length) + length);
    } // while (nleft)
  }   // while (true)

  ulapi_task_join(server_task, &retval);

  return 0;
}
