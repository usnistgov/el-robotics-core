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

CRCL_Client::CRCL_Client(const char *host, int cmd_port, int stat_port)
{
  connected = false;

  cmd_socket_id = socket_get_client_id(cmd_port, host);
  if (cmd_socket_id < 0) return;

  stat_socket_id = socket_get_client_id(stat_port, host);
  if (stat_socket_id < 0) return;

  connected = true;
}

CRCL_Client::CRCL_Client()
{
  CRCL_Client(CRCL_CLIENT_HOST_DEFAULT, CRCL_CLIENT_CMD_PORT_DEFAULT, CRCL_CLIENT_STAT_PORT_DEFAULT);
}

CanonReturn CRCL_Client::setResult(const char *str)
{
  if (! strncmp(str, "Success", strlen("Success"))) {
    return CANON_SUCCESS;
  } else if (! strncmp(str, "Failure", strlen("Failure"))) {
    return CANON_FAILURE;
  } else if (! strncmp(str, "Reject", strlen("Reject"))) {
    return CANON_REJECT;
  } else {
    return CANON_REJECT;
  }
}

CanonReturn CRCL_Client::getResult()
{
  return result;
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

  nchars = socket_write(cmd_socket_id, outbuf, strlen(outbuf) + 1);

  nchars = socket_read(cmd_socket_id, inbuf, sizeof(inbuf) - 1);

  return setResult(inbuf);
}

#define LOCKIT boost::mutex::scoped_lock lock(mutex)

CanonReturn CRCL_Client::GetRobotPose (robotPose *pose)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;
  double d1, d2, d3, d4, d5, d6, d7;

  socket_snprintf(outbuf, sizeof(outbuf), "GetRobotPose");

  {
    LOCKIT;
    nchars = socket_write(stat_socket_id, outbuf, strlen(outbuf) + 1);
    nchars = socket_read(stat_socket_id, inbuf, sizeof(inbuf) - 1);
  }

  if (! strncmp(inbuf, "Success", strlen("Success"))) {
    if (7 == sscanf(inbuf, "%*s %*s %lf %lf %lf %lf %lf %lf %lf",
		    &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
      pose->position.x = d1, pose->position.y = d2, pose->position.z = d3;
      pose->orientation.x = d4, pose->orientation.y = d5;
      pose->orientation.z = d6, pose->orientation.w = d7;
      return result = CANON_SUCCESS;
    }
  }
  // else failure
  return result = CANON_FAILURE;
}

CanonReturn CRCL_Client::SetAbsoluteSpeed(double speed)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;

  socket_snprintf(outbuf, sizeof(outbuf), "SetAbsoluteSpeed %f", speed);

  nchars = socket_write(cmd_socket_id, outbuf, strlen(outbuf) + 1);

  nchars = socket_read(cmd_socket_id, inbuf, sizeof(inbuf) - 1);

  return setResult(inbuf);
}

bool CRCL_Client::isConnected()
{
  return connected;
}
