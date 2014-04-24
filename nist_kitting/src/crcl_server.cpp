#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include <getopt.h>

#include <boost/thread/thread.hpp>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/socket_utils.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/crcl_client.h"
#include "nist_kitting/crcl_sim.h"

static bool debug = false;

static CRCL_Sim robot;

static void MoveStraightTo(const char *inbuf, int cmd_client_id)
{
  double d1, d2, d3, d4, d5, d6, d7;
  robotPose p;
  CanonReturn result;
  enum {OUTBUF_LEN = 256};
  char outbuf[OUTBUF_LEN];

  if (7 == sscanf(inbuf, "%*s %lf %lf %lf %lf %lf %lf %lf",
		  &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
    p.position.x = d1, p.position.y = d2, p.position.z = d3;
    p.orientation.x = d4, p.orientation.y = d5;
    p.orientation.z = d6, p.orientation.w = d7;

    if (debug) printf("MoveStraightTo %f ...\n", (double) p.position.x);

    result = robot.MoveStraightTo(p);
  } else {
    result = CANON_REJECT;
  }

  snprintf(outbuf, sizeof(outbuf) - 1,
	   "%s MoveStraightTo",
	   CANON_SUCCESS == result ? "Success" :
	   CANON_FAILURE == result ? "Failure" : "Reject");
  outbuf[sizeof(outbuf) - 1] = 0;
  socket_write(cmd_client_id, outbuf, strlen(outbuf) + 1);
}

/*
  Principles of Operation:

  The CRCL server has an instance of some CRCL_Robot, like a CRCL_Sim
  simulated robot. That's hand-coded now, but we could have a set of
  difference types and switch between them at run time, casting to the
  particular type in the handler code. The CRCL_Robot is a global. No
  mutexing is done, since that would defeat the purpose of having two
  independent sockets. The CRCL_Robot class must at least allow
  multi-threaded access so that the "get" and "set" commands can
  execute while the "do" commands are executing.

  There are two sockets served, one for commands and one for
  status. The command socket expects just one active command at a time
  from the client, will call the appropriate blocking CRCL_Robot
  method.  This is done via a command handler thread that will be
  interrupted if a new command is received, otherwise it runs to
  complettion and writes the status back. The "set" commands are
  executed immediately. These responses indicate "Success",
  "Failure", or "Reject" with the command included. 

  The status socket thread handles "get" commands just as the command
  socket handles "set" commands -- no additional threads are spawned
  to handle each command; they are called immediately and the results
  written back to the client, prefixed with "Success", etc. as with
  commands, plus the request string echoed back, and then the actual
  status requested.
*/

void status_handler_thread_code(int stat_port)
{
  int stat_socket_id;
  int stat_client_id;
  enum {INBUF_LEN = 256, OUTBUF_LEN = 256};
  char inbuf[INBUF_LEN];
  char outbuf[OUTBUF_LEN];
  int nchars;
  CanonReturn result;

  stat_socket_id = socket_get_server_id(stat_port);
  if (stat_socket_id < 0) {
    fprintf(stderr, "can't serve status port %d\n", (int) stat_port);
    exit(1);
  }

  while (true) {
    if (debug) printf("waiting for status connection on port %d...\n", (int) stat_port);
    stat_client_id = socket_get_connection_id(stat_socket_id);
    if (stat_client_id < 0) {
      break;
    }
    if (debug) printf("status client connected\n");

    while (true) {
      nchars = socket_read(stat_client_id, inbuf, sizeof(inbuf));
      if (-1 == nchars) {
	break;
      }
      if (0 == nchars) {
	break;
      }
      if (debug) printf("status request: ``%s''\n", inbuf);

      // handle status request
      if (! strncmp(inbuf, "GetRobotPose", strlen("GetRobotPose"))) {
	robotPose p;
	result = robot.GetRobotPose(&p);
	snprintf(outbuf, sizeof(outbuf) - 1,
		 "%s GetRobotPose %f %f %f %f %f %f %f",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject",
		 p.position.x, p.position.y, p.position.z,
		 p.orientation.x, p.orientation.y,
		 p.orientation.z, p.orientation.w);
	socket_write(stat_client_id, outbuf, strlen(outbuf) + 1);
	if (debug) printf("wrote ``%s''\n", outbuf);
      } else {
	fprintf(stderr, "invalid client status request: ``%s''\n", inbuf);
      }
    } // while (true) socket read loop

    socket_close(stat_client_id);
    if (debug) printf("status client disconnected\n");
  } // while (true) client connect loop

  socket_close(stat_socket_id);

  return;
}

/*
  Syntax:

  crcl_server <cmd port> <stat port>
*/
int main(int argc, char *argv[])
{
  int option;
  int ival;
  int cmd_port = CRCL_CLIENT_CMD_PORT_DEFAULT;
  int stat_port = CRCL_CLIENT_STAT_PORT_DEFAULT;
  int cmd_socket_id;
  int cmd_client_id;
  enum {INBUF_LEN = 256, OUTBUF_LEN = 256};
  char inbuf[INBUF_LEN];
  char outbuf[OUTBUF_LEN];
  int nchars;
  double d1;
  CanonReturn result;
  boost::thread *cmdExecThr = NULL;
  boost::thread *statExecThr = NULL;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":c:s:d");
    if (option == -1) break;

    switch (option) {
    case 'c':
      ival = atoi(optarg);
      cmd_port = ival;
      break;

    case 's':
      ival = atoi(optarg);
      stat_port = ival;
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
    } // switch (option)
  }   // while (true) for getopt

  // spawn status server thread
  statExecThr = new boost::thread(status_handler_thread_code, stat_port);

  // run command server thread here, spawning command handlers

  cmd_socket_id = socket_get_server_id(cmd_port);
  if (cmd_socket_id < 0) {
    fprintf(stderr, "can't serve command port %d\n", (int) cmd_port);
    return 1;
  }

  while (true) {
    if (debug) printf("waiting for command connection on port %d...\n", (int) cmd_port);
    cmd_client_id = socket_get_connection_id(cmd_socket_id);
    if (cmd_client_id < 0) {
      break;
    }
    if (debug) printf("client command connection on port\n", (int) cmd_port);

    while (true) {
      nchars = socket_read(cmd_client_id, inbuf, sizeof(inbuf));
      if (-1 == nchars) {
	break;
      }
      if (0 == nchars) {
	break;
      }
      if (debug) printf("client command: ``%s''\n", inbuf);

      // handle commands

      if (! strncmp(inbuf, "MoveStraightTo", strlen("MoveStraightTo"))) {
	if (NULL != cmdExecThr) {
	  cmdExecThr->interrupt();
	  delete cmdExecThr;
	}
	cmdExecThr = new boost::thread(MoveStraightTo, inbuf, cmd_client_id);
      } else if (! strncmp(inbuf, "SetAbsoluteSpeed", strlen("SetAbsoluteSpeed"))) {
	if (1 == sscanf(inbuf, "%*s %lf", &d1)) {
	  result = robot.SetAbsoluteSpeed(d1);
	} else {
	  fprintf(stderr, "invalid arguments: ``%s''\n", inbuf);
	  result = CANON_REJECT;
	}
	snprintf(outbuf, sizeof(outbuf) - 1,
		 "%s SetAbsoluteSpeed",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject");
	outbuf[sizeof(outbuf) - 1] = 0;
	socket_write(cmd_client_id, outbuf, strlen(outbuf) + 1);
      } else {
	fprintf(stderr, "unknown command: ``%s''\n", inbuf);
      } // if command ...
    } // while (true) socket read loop

    socket_close(cmd_client_id);
    if (debug) printf("closed %d\n", cmd_client_id);
  } // while (true) socket connect loop

  return 0;
}

