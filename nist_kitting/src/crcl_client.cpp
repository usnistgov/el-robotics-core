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

static bool debug = true;

CRCL_Client::CRCL_Client(const char *host, int cmd_port, int stat_port)
{
  connected = false;

  cmd_socket_id = socket_get_client_id(cmd_port, host);
  if (cmd_socket_id < 0) return;

  stat_socket_id = socket_get_client_id(stat_port, host);
  if (stat_socket_id < 0) {
    socket_close(cmd_socket_id);
    cmd_socket_id = -1;
    return;
  }

  cmdResult = CANON_SUCCESS;
  statResult = CANON_SUCCESS;
  cmdDoneFlag = true;
  statDoneFlag = true;
  connected = true;
}

CRCL_Client::CRCL_Client()
{
  CRCL_Client(CRCL_CLIENT_HOST_DEFAULT, CRCL_CLIENT_CMD_PORT_DEFAULT, CRCL_CLIENT_STAT_PORT_DEFAULT);
}

CRCL_Client::~CRCL_Client()
{
  if (cmd_socket_id >= 0) socket_close(cmd_socket_id);
  if (stat_socket_id >= 0) socket_close(stat_socket_id);
}

CanonReturn CRCL_Client::setCmdResult(const char *str)
{
  if (! strncmp(str, "Success", strlen("Success"))) {
    return cmdResult = CANON_SUCCESS;
  } else if (! strncmp(str, "Failure", strlen("Failure"))) {
    return cmdResult = CANON_FAILURE;
  } else if (! strncmp(str, "Reject", strlen("Reject"))) {
    return cmdResult = CANON_REJECT;
  } else {
    return cmdResult = CANON_REJECT;
  }
}

CanonReturn CRCL_Client::getCmdResult()
{
  return cmdResult;
}

CanonReturn CRCL_Client::setStatResult(const char *str)
{
  if (! strncmp(str, "Success", strlen("Success"))) {
    return statResult = CANON_SUCCESS;
  } else if (! strncmp(str, "Failure", strlen("Failure"))) {
    return statResult = CANON_FAILURE;
  } else if (! strncmp(str, "Reject", strlen("Reject"))) {
    return cmdResult = CANON_REJECT;
  } else {
    return statResult = CANON_REJECT;
  }
}

CanonReturn CRCL_Client::getStatResult()
{
  return statResult;
}

void CRCL_Client::startCmd()
{
  cmdDoneFlag = false;
}

bool CRCL_Client::cmdDone()
{
  return cmdDoneFlag;
}

void CRCL_Client::startStat()
{
  statDoneFlag = false;
}

bool CRCL_Client::statDone()
{
  return statDoneFlag;
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

  if (debug) printf("MoveStraightTo done\n");
  
  cmdDoneFlag = true;
  return setCmdResult(inbuf);
}

CanonReturn CRCL_Client::StopMotion (int condition)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;

  socket_snprintf(outbuf, sizeof(outbuf), "StopMotion %d", condition);

  nchars = socket_write(cmd_socket_id, outbuf, strlen(outbuf) + 1);

  nchars = socket_read(cmd_socket_id, inbuf, sizeof(inbuf) - 1);

  cmdDoneFlag = true;
  return setCmdResult(inbuf);
}

CanonReturn CRCL_Client::SetTool (double percent)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;

  socket_snprintf(outbuf, sizeof(outbuf), "SetTool %f", percent);

  nchars = socket_write(cmd_socket_id, outbuf, strlen(outbuf) + 1);

  nchars = socket_read(cmd_socket_id, inbuf, sizeof(inbuf) - 1);

  cmdDoneFlag = true;
  return setCmdResult(inbuf);
}

#define LOCKIT boost::mutex::scoped_lock lock(mutex)

CanonReturn CRCL_Client::GetRobotPose (robotPose *pose)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;
  double d1, d2, d3, d4, d5, d6, d7;
  CanonReturn result = CANON_FAILURE;

  socket_snprintf(outbuf, sizeof(outbuf), "GetRobotPose");

  {
    LOCKIT;
    nchars = socket_write(stat_socket_id, outbuf, strlen(outbuf) + 1);
    nchars = socket_read(stat_socket_id, inbuf, sizeof(inbuf) - 1);
  }

  if (CANON_SUCCESS == setStatResult(inbuf)) {
    if (7 == sscanf(inbuf, "%*s %*s %lf %lf %lf %lf %lf %lf %lf",
		    &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
      pose->position.x = d1, pose->position.y = d2, pose->position.z = d3;
      pose->orientation.x = d4, pose->orientation.y = d5;
      pose->orientation.z = d6, pose->orientation.w = d7;
    }
  }

  statDoneFlag = true;
  return statResult;
}

CanonReturn CRCL_Client::GetRobotAxes (robotAxes *axes)
{
  enum {BUFFERLEN = 256};
  char inbuf[BUFFERLEN];
  char outbuf[BUFFERLEN];
  int nchars;
  double d1, d2, d3, d4, d5, d6; // FIXME -- handle variable number of axes
  CanonReturn result = CANON_FAILURE;

  socket_snprintf(outbuf, sizeof(outbuf), "GetRobotAxes");

  {
    LOCKIT;
    nchars = socket_write(stat_socket_id, outbuf, strlen(outbuf) + 1);
    nchars = socket_read(stat_socket_id, inbuf, sizeof(inbuf) - 1);
  }

  if (CANON_SUCCESS == setStatResult(inbuf)) {
    if (6 == sscanf(inbuf, "%*s %*s %lf %lf %lf %lf %lf %lf",
		    &d1, &d2, &d3, &d4, &d5, &d6)) {
      axes->axis[0] = d1, axes->axis[1] = d2, axes->axis[2] = d3,
	axes->axis[3] = d4, axes->axis[4] = d5, axes->axis[5] = d6;
    }
  }

  statDoneFlag = true;
  return statResult;
}

CanonReturn CRCL_Client::GetStatus (robotAxes *axes, robotPose *pose, double percent)
{
  statDoneFlag = true;
  statResult = CANON_SUCCESS;

  return statResult;
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

  cmdDoneFlag = true;
  return setCmdResult(inbuf);
}

bool CRCL_Client::isConnected()
{
  return connected;
}
