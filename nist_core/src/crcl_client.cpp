#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>

#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

#include "nist_core/crcl.h"
#include "nist_core/crcl_robot.h"
#include "nist_core/crcl_client.h"

namespace crcl_robot {

  LIBRARY_API CrclClient::CrclClient(const char *host, int cmd_port, int stat_port)
  {
    cmd_socket = new boost::asio::ip::tcp::socket(io_service);
    stat_socket = new boost::asio::ip::tcp::socket(io_service);

    boost::asio::ip::tcp::resolver resolver(io_service);

    boost::asio::ip::tcp::resolver::query cmd_query(boost::asio::ip::tcp::v4(), host, boost::lexical_cast<std::string>(cmd_port));
    boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(cmd_query);
    cmd_socket->connect(*iterator);

    boost::asio::ip::tcp::resolver::query stat_query(boost::asio::ip::tcp::v4(), host, boost::lexical_cast<std::string>(stat_port));
    iterator = resolver.resolve(stat_query);
    stat_socket->connect(*iterator);

    cmdResult = CANON_SUCCESS;
    statResult = CANON_SUCCESS;
    cmdDoneFlag = true;
    statDoneFlag = true;
    connected = true;
  }

  LIBRARY_API CrclClient::CrclClient()
  {
    CrclClient(CRCL_CLIENT_HOST_DEFAULT, CRCL_CLIENT_CMD_PORT_DEFAULT, CRCL_CLIENT_STAT_PORT_DEFAULT);
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

    try {
      boost::asio::write(*cmd_socket, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      cmd_socket->read_some(boost::asio::buffer(inbuf));
    } catch (std::exception &e) {
      cmdResult = CANON_FAILURE;
      cmdDoneFlag = true;
      return cmdResult;
    }
  
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

    try {
      boost::asio::write(*cmd_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
      cmd_socket->read_some(boost::asio::buffer(inbuf));
    } catch (std::exception &e) {
      cmdResult = CANON_FAILURE;
      cmdDoneFlag = true;
      return cmdResult;
    }

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

    try {
      boost::asio::write(*cmd_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
      cmd_socket->read_some(boost::asio::buffer(inbuf));
    } catch (std::exception &e) {
      cmdResult = CANON_FAILURE;
      cmdDoneFlag = true;
      return cmdResult;
    }

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

    try {
      boost::asio::write(*cmd_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
      cmd_socket->read_some(boost::asio::buffer(inbuf));
    } catch (std::exception &e) {
      cmdResult = CANON_FAILURE;
      cmdDoneFlag = true;
      return cmdResult;
    }

    cmdDoneFlag = true;
    return setCmdResult(inbuf);
  }

#define LOCKIT boost::mutex::scoped_lock lock(mutex)

  LIBRARY_API CanonReturn CrclClient::GetRobotPose (robotPose *pose)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;
    double d1, d2, d3, d4, d5, d6, d7;
    CanonReturn result = CANON_FAILURE;

    snprintf(outbuf, sizeof(outbuf), "GetRobotPose");

    {
      LOCKIT;
      try {
	boost::asio::write(*stat_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
	stat_socket->read_some(boost::asio::buffer(inbuf));
      } catch (std::exception &e) {
	statResult = CANON_FAILURE;
	statDoneFlag = true;
	return statResult;
      }
    }

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

    {
      LOCKIT;
      try {
	boost::asio::write(*stat_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
	stat_socket->read_some(boost::asio::buffer(inbuf));
      } catch (std::exception &e) {
	statResult = CANON_FAILURE;
	statDoneFlag = true;
	return statResult;
      }
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

  LIBRARY_API CanonReturn CrclClient::GetTool (double *percent)
  {
    enum {BUFFERLEN = 256};
    char inbuf[BUFFERLEN];
    char outbuf[BUFFERLEN];
    int nchars;
    double d1;
    CanonReturn result = CANON_FAILURE;

    snprintf(outbuf, sizeof(outbuf), "GetTool");

    {
      LOCKIT;
      try {
	boost::asio::write(*stat_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
	stat_socket->read_some(boost::asio::buffer(inbuf));
      } catch (std::exception &e) {
	statResult = CANON_FAILURE;
	statDoneFlag = true;
	return statResult;
      }
    }

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

    {
      LOCKIT;
      try {
	boost::asio::write(*stat_socket, boost::asio::buffer(outbuf, sizeof(outbuf)));
	stat_socket->read_some(boost::asio::buffer(inbuf));
      } catch (std::exception &e) {
	statResult = CANON_FAILURE;
	statDoneFlag = true;
	return statResult;
      }
    }

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

  LIBRARY_API bool CrclClient::isConnected()
  {
    return connected;
  }

} // namespace crcl_robot
