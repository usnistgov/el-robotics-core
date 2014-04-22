#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include "nist_kitting/msg_types.h"
#include "nist_kitting/socket_utils.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/crcl_robot.h"
#include "nist_kitting/crcl_client.h"

CRCL_Client::CRCL_Client()
{
  CRCL_Client(HOST_DEFAULT, PORT_DEFAULT);
}

CRCL_Client::CRCL_Client(const char *host, int port)
{
  socket_id = socket_get_client_id(port, host);
  if (socket_id < 0) {
    socket_id = -1;
    fprintf(stderr, "can't serve port %d\n", (int) port);
  }
}

CanonReturn CRCL_Client::MoveStraightTo(robotPose pose)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;

  socket_snprintf(outbuf, sizeof(outbuf),
		  "MoveStraightTo %f %f %f %f %f %f %f", 
		  pose.position.x, pose.position.y, pose.position.z,
		  pose.orientation.x, pose.orientation.y,
		  pose.orientation.z, pose.orientation.w);
  nchars = socket_write(socket_id, outbuf, strlen(outbuf) + 1);

  nchars = socket_read(socket_id, inbuf, sizeof(inbuf) - 1);
  if (! strncmp(inbuf, "Success", strlen("Success"))) {
    return CANON_SUCCESS;
  } else if (! strncmp(inbuf, "Failure", strlen("Failure"))) {
    return CANON_FAILURE;
  } else if (! strncmp(inbuf, "Reject", strlen("Reject"))) {
    return CANON_REJECT;
  } else {
    fprintf(stderr, "invalid return: %s\n", inbuf);
    return CANON_REJECT;
  }
}
