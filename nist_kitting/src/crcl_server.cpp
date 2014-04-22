#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include "nist_kitting/msg_types.h"
#include "nist_kitting/socket_utils.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/crcl_sim.h"

static int handle_message(char *inbuf, int inbuf_len, int client_id, CRCL_Sim &robot)
{
  enum {OUTBUF_LEN = 256};
  char outbuf[OUTBUF_LEN];
  double d1, d2, d3, d4, d5, d6, d7;

  if (! strncmp(inbuf, "MoveStraightTo", strlen("MoveStraightTo"))) {
    if (7 == sscanf(inbuf, "%*s %lf %lf %lf %lf %lf %lf %lf",
		    &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
      robotPose p;
      CanonReturn result;
      p.position.x = d1, p.position.y = d2, p.position.z = d3;
      p.orientation.x = d4, p.orientation.y = d5, p.orientation.z = d6, p.orientation.w = d7;
      result = robot.MoveStraightTo(p);
      if (CANON_SUCCESS == result) {
	snprintf(outbuf, sizeof(outbuf) - 1, "Success");
      } else if (CANON_FAILURE == result) {
	snprintf(outbuf, sizeof(outbuf) - 1, "Failure");
      } else if (CANON_REJECT == result) {
	snprintf(outbuf, sizeof(outbuf) - 1, "Reject");
      } else {
	snprintf(outbuf, sizeof(outbuf) - 1, "Reject");
	fprintf(stderr, "invalid return value from MoveStraightTo: %d\n", (int) result);
      }
      socket_write(client_id, outbuf, strlen(outbuf) + 1);
    } else {
      fprintf(stderr, "bad args to MoveStraightTo: %s\n", inbuf);
    }
  } else {
    fprintf(stderr, "unknown command: %s\n", inbuf);
  }

  return 0;
}

int main(int argc, char *argv[])
{
  CRCL_Sim robot;
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  int port = PRIM_ROBOT_PORT;
  int socket_id;
  int client_id;
  int nchars;

  if (argc == 2) {
    port = atoi(argv[1]);
    if (port < 0) {
    fprintf(stderr, "port must be a positive integer\n");
    return 1;
    }
  }

  socket_id = socket_get_server_id(port);
  if (socket_id < 0) {
    fprintf(stderr, "can't serve port %d\n", (int) port);
    return 1;
  }
  printf("serving port %d\n", (int) port);

  for (;;) {
    printf("waiting for client connection...\n");
    client_id = socket_get_connection_id(socket_id);
    if (client_id < 0) {
      break;
    }
    printf("got one on fd %d\n", client_id);

    for (;;) {
      nchars = socket_read(client_id, inbuf, sizeof(inbuf));
      if (-1 == nchars) {
	break;
      }
      if (0 == nchars) {
	break;
      }
      printf("got %d chars: ``%s''\n", nchars, inbuf);
      handle_message(inbuf, nchars, client_id, robot);
    }

    socket_close(client_id);
    printf("closed %d\n", client_id);
  }

  return 0;
}

