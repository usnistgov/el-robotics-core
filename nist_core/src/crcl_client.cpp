#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>

#include <ulapi.h>

#include "nist_core/crcl.h"
#include "nist_core/crcl_robot.h"
#include "nist_core/crcl_client.h"

namespace crcl_robot {

  LIBRARY_API CrclClient::CrclClient()
  {
    ulapi_mutex_init(&mutex, 1);

    cmd_socket = -1;
    stat_socket = -1;

    cmdResult = CANON_SUCCESS;
    statResult = CANON_SUCCESS;
    cmdDoneFlag = true;
    statDoneFlag = true;
    connected = false;
  }

  LIBRARY_API CrclClient::~CrclClient()
  {
  }

  LIBRARY_API CanonReturn CrclClient::setCmdResult(const char *str)
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

  LIBRARY_API CanonReturn CrclClient::getCmdResult()
  {
    return cmdResult;
  }

  LIBRARY_API CanonReturn CrclClient::setStatResult(const char *str)
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

  LIBRARY_API CanonReturn CrclClient::getStatResult()
  {
    return statResult;
  }

  LIBRARY_API void CrclClient::startCmd()
  {
    cmdDoneFlag = false;
  }

  LIBRARY_API bool CrclClient::cmdDone()
  {
    return cmdDoneFlag;
  }

  LIBRARY_API void CrclClient::startStat()
  {
    statDoneFlag = false;
  }

  LIBRARY_API bool CrclClient::statDone()
  {
    return statDoneFlag;
  }

  LIBRARY_API CanonReturn CrclClient::MoveStraightTo(robotPose pose)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;

    snprintf(outbuf, sizeof(outbuf),
		    "MoveStraightTo %f %f %f %f %f %f", 
		    pose.x, pose.y, pose.z,
		    pose.xrot, pose.yrot, pose.zrot);

    ulapi_socket_write(cmd_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(cmd_socket, inbuf, sizeof(inbuf)-1);
  
    cmdDoneFlag = true;
    return setCmdResult(inbuf);
  }

  LIBRARY_API CanonReturn CrclClient::StopMotion (int condition)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;

    snprintf(outbuf, sizeof(outbuf), "StopMotion %d", condition);

    ulapi_socket_write(cmd_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(cmd_socket, inbuf, sizeof(inbuf)-1);

    cmdDoneFlag = true;
    return setCmdResult(inbuf);
  }

  LIBRARY_API CanonReturn CrclClient::SetTool (double percent)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;

    snprintf(outbuf, sizeof(outbuf), "SetTool %f", percent);

    ulapi_socket_write(cmd_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(cmd_socket, inbuf, sizeof(inbuf)-1);

    cmdDoneFlag = true;
    return setCmdResult(inbuf);
  }

  LIBRARY_API CanonReturn CrclClient::SetAbsoluteSpeed(double speed)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;

    snprintf(outbuf, sizeof(outbuf), "SetAbsoluteSpeed %f", speed);

    ulapi_socket_write(cmd_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(cmd_socket, inbuf, sizeof(inbuf)-1);
  
    cmdDoneFlag = true;
    return setCmdResult(inbuf);
  }

#define LOCKIT ulapi_mutex_take(&mutex)
#define UNLOCKIT ulapi_mutex_give(&mutex)

  LIBRARY_API CanonReturn CrclClient::GetRobotPose (robotPose *pose)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;
    double d1, d2, d3, d4, d5, d6, d7;
    CanonReturn result = CANON_FAILURE;

    snprintf(outbuf, sizeof(outbuf), "GetRobotPose");

    LOCKIT;
    ulapi_socket_write(stat_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(stat_socket, inbuf, sizeof(inbuf)-1);
    UNLOCKIT;

    if (CANON_SUCCESS == setStatResult(inbuf)) {
      if (6 == sscanf(inbuf, "%*s %*s %lf %lf %lf %lf %lf %lf",
		      &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
	pose->x = d1, pose->y = d2, pose->z = d3;
	pose->xrot = d4, pose->yrot = d5, pose->zrot = d6;
      }
    }

    statDoneFlag = true;
    return statResult;
  }

  LIBRARY_API CanonReturn CrclClient::GetRobotAxes (robotAxes *axes)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;
    double d1, d2, d3, d4, d5, d6; // FIXME -- handle variable number of axes
    CanonReturn result = CANON_FAILURE;

    snprintf(outbuf, sizeof(outbuf), "GetRobotAxes");

    LOCKIT;
    ulapi_socket_write(stat_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(stat_socket, inbuf, sizeof(inbuf)-1);
    UNLOCKIT;

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

  LIBRARY_API CanonReturn CrclClient::GetTool (double *percent)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;
    double d1;
    CanonReturn result = CANON_FAILURE;

    snprintf(outbuf, sizeof(outbuf), "GetTool");

    LOCKIT;
    ulapi_socket_write(stat_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(stat_socket, inbuf, sizeof(inbuf)-1);
    UNLOCKIT;

    if (CANON_SUCCESS == setStatResult(inbuf)) {
      if (1 == sscanf(inbuf, "%*s %*s %lf", &d1)) {
	*percent = d1;
      }
    }

    statDoneFlag = true;
    return statResult;
  }

  LIBRARY_API CanonReturn CrclClient::GetStatus (robotPose *pose, robotAxes *axes, double *percent)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;
    char *nptr;
    char *endptr;
    double d1;

    snprintf(outbuf, sizeof(outbuf), "GetStatus");

    LOCKIT;
    ulapi_socket_write(stat_socket, outbuf, strlen(outbuf)+1);
    ulapi_socket_read(stat_socket, inbuf, sizeof(inbuf)-1);
    UNLOCKIT;

    nptr = inbuf;
    if (! strncmp(nptr, "Success GetStatus", strlen("Success GetStatus"))) {
      nptr += strlen("Success GetStatus");
      while (true) {		// use a break-able scope as a clean 'goto'
#define MOVEDOWN(VAL)				\
	d1 = strtod(nptr, &endptr);		\
	if (endptr == nptr) break;		\
	VAL = d1;				\
	nptr = endptr;

	MOVEDOWN(pose->x);
	MOVEDOWN(pose->y);
	MOVEDOWN(pose->z);
	MOVEDOWN(pose->xrot);
	MOVEDOWN(pose->yrot);
	MOVEDOWN(pose->zrot);

	// FIXME -- we should loop on the number of axes, soon to be added
	MOVEDOWN(axes->axis[0]);
	MOVEDOWN(axes->axis[1]);
	MOVEDOWN(axes->axis[2]);
	MOVEDOWN(axes->axis[3]);
	MOVEDOWN(axes->axis[4]);
	MOVEDOWN(axes->axis[5]);

	MOVEDOWN(*percent);

	// if we got here, we got it all
	statResult = CANON_SUCCESS;
	break;			// we're done with the one pass
      } // while (true)
    } else {
      statResult = CANON_FAILURE;
    }

    statDoneFlag = true;
    return statResult;
  }

  bool LIBRARY_API CrclClient::connect(const char *host, int cmd_port, int stat_port)
  {
    cmd_socket = -1;
    stat_socket = -1;
    connected = false;

    cmd_socket = ulapi_socket_get_client_id(cmd_port, host);
    if (cmd_socket < 0) {
      cmd_socket = -1;
      return false;
    }

    stat_socket = ulapi_socket_get_client_id(stat_port, host);
    if (stat_socket < 0) {
      stat_socket = -1;
      ulapi_socket_close(cmd_socket);
      cmd_socket = -1;
      return false;
    }

    connected = true;

    return true;
  }

  bool LIBRARY_API CrclClient::connect()
  {
    return connect(CRCL_CLIENT_HOST_DEFAULT, CRCL_CLIENT_CMD_PORT_DEFAULT, CRCL_CLIENT_STAT_PORT_DEFAULT);
  }

  LIBRARY_API bool CrclClient::isConnected()
  {
    return connected;
  }

} // namespace crcl_robot
