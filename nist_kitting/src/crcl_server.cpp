#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>

#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include <nist_core/nist_core.h>
#include <nist_core/crcl.h>
#include <nist_core/crcl_client.h>
#include <nist_core/crcl_sim_robot.h>

using boost::asio::ip::tcp;

typedef boost::shared_ptr<tcp::socket> socket_ptr;

static bool debug = false;

using namespace crcl_robot;

static CrclSimRobot robot;

static void MoveStraightTo(const char *inbuf, socket_ptr sock)
{
  double d1, d2, d3, d4, d5, d6;
  robotPose p;
  CanonReturn result;
  enum {OUTBUF_LEN = 256};
  char outbuf[OUTBUF_LEN];

  if (6 == sscanf(inbuf, "%*s %lf %lf %lf %lf %lf %lf",
		  &d1, &d2, &d3, &d4, &d5, &d6)) {
    p.x = d1, p.y = d2, p.z = d3;
    p.xrot = d4, p.yrot = d5, p.zrot = d6;

    if (debug) printf("MoveStraightTo %f %f %f ...\n",
		      p.x, p.y, p.z);

    result = robot.MoveStraightTo(p);
  } else {
    result = CANON_REJECT;
  }

  snprintf(outbuf, sizeof(outbuf)-1,
	   "%s MoveStraightTo",
	   CANON_SUCCESS == result ? "Success" :
	   CANON_FAILURE == result ? "Failure" : "Reject");
  outbuf[sizeof(outbuf)-1] = 0;
  boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));

  if (debug) printf("MoveStraightTo done\n");
}

static void SetTool(const char *inbuf, socket_ptr sock)
{
  double d1;
  CanonReturn result;
  enum {OUTBUF_LEN = 256};
  char outbuf[OUTBUF_LEN];

  if (1 == sscanf(inbuf, "%*s %lf", &d1)) {
    if (debug) printf("SetTool %f\n", d1);
    result = robot.SetTool(d1);
  } else {
    result = CANON_REJECT;
  }

  snprintf(outbuf, sizeof(outbuf)-1,
	   "%s SetTool",
	   CANON_SUCCESS == result ? "Success" :
	   CANON_FAILURE == result ? "Failure" : "Reject");
  outbuf[sizeof(outbuf)-1] = 0;
  boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));

  if (debug) printf("SetTool done\n");
}

static void StopMotion(const char *inbuf, socket_ptr sock)
{
  int i1;
  CanonReturn result;
  enum {OUTBUF_LEN = 256};
  char outbuf[OUTBUF_LEN];

  if (1 == sscanf(inbuf, "%*s %d", &i1)) {
    if (debug) printf("StopMotion %d\n", i1);
    result = robot.StopMotion(i1);
  } else {
    result = CANON_REJECT;
  }

  snprintf(outbuf, sizeof(outbuf)-1,
	   "%s StopMotion",
	   CANON_SUCCESS == result ? "Success" :
	   CANON_FAILURE == result ? "Failure" : "Reject");
  outbuf[sizeof(outbuf)-1] = 0;
  boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));

  if (debug) printf("StopMotion done\n");
}

/*!
  \defgroup CRCL_SERVER The CRCL Server

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

void stat_session(socket_ptr sock)
{
  try {
    while (true) {
#define INBUF_LEN 256
#define OUTBUF_LEN 256
      char inbuf[INBUF_LEN];
      char outbuf[OUTBUF_LEN];
      boost::system::error_code error;
      size_t length;
      CanonReturn result;

      length = sock->read_some(boost::asio::buffer(inbuf), error);

      if (boost::asio::error::eof == error) break;
      else if (error) throw boost::system::system_error(error);

      // else handle status request
      if (! strncmp(inbuf, "GetRobotPose", strlen("GetRobotPose"))) {
	robotPose p;
	result = robot.GetRobotPose(&p);
	snprintf(outbuf, sizeof(outbuf)-1,
		 "%s GetRobotPose %f %f %f %f %f %f",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject",
		 p.x, p.y, p.z, p.xrot, p.yrot, p.zrot);
	boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      } else if (! strncmp(inbuf, "GetRobotAxes", strlen("GetRobotAxes"))) {
	robotAxes a;
	result = robot.GetRobotAxes(&a);
	snprintf(outbuf, sizeof(outbuf)-1,
		 "%s GetRobotAxes %f %f %f %f %f %f",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject",
		 a.axis[0], a.axis[1], a.axis[2],
		 a.axis[3], a.axis[4], a.axis[5]);
	boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      } else if (! strncmp(inbuf, "GetTool", strlen("GetTool"))) {
	double d;
	result = robot.GetTool(&d);
	snprintf(outbuf, sizeof(outbuf)-1,
		 "%s GetTool %f",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject", d);
	boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      } else if (! strncmp(inbuf, "GetStatus", strlen("GetStatus"))) {
	robotPose p;
	robotAxes a;
	double t;
	result = robot.GetRobotPose(&p);
	if (CANON_SUCCESS == result) result = robot.GetRobotAxes(&a);
	if (CANON_SUCCESS == result) result = robot.GetTool(&t);
	snprintf(outbuf, sizeof(outbuf)-1,
		 "%s GetStatus %f %f %f %f %f %f %f %f %f %f %f %f %f",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject",
		 p.x, p.y, p.z,
		 p.xrot, p.yrot, p.zrot,
		 a.axis[0], a.axis[1], a.axis[2],
		 a.axis[3], a.axis[4], a.axis[5], t);
	boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      } else {
	fprintf(stderr, "invalid client status request: ``%s''\n", inbuf);
	snprintf(outbuf, sizeof(outbuf)-1, "Reject %s", inbuf);
	boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      }
    } // while (true)
  } catch (std::exception& e) {
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}

static void cmd_session(socket_ptr sock)
{
  boost::thread *cmd_exec_thr;

  try {
    while (true) {
#define INBUF_LEN 256
#define OUTBUF_LEN 256
      char inbuf[INBUF_LEN];
      char outbuf[OUTBUF_LEN];
      boost::system::error_code error;
      size_t length;
      CanonReturn result;
      double d1;

      length = sock->read_some(boost::asio::buffer(inbuf), error);

      if (boost::asio::error::eof == error) break;
      else if (error) throw boost::system::system_error(error);

      if (debug) printf("client command: ``%s''\n", inbuf);

      // handle commands
      if (! strncmp(inbuf, "MoveStraightTo", strlen("MoveStraightTo"))) {
	if (NULL != cmd_exec_thr) {
	  cmd_exec_thr->interrupt();
	  delete cmd_exec_thr;
	  cmd_exec_thr = NULL;
	}
	cmd_exec_thr = new boost::thread(MoveStraightTo, inbuf, sock);
      } else if (! strncmp(inbuf, "SetTool", strlen("SetTool"))) {
	if (NULL != cmd_exec_thr) {
	  cmd_exec_thr->interrupt();
	  delete cmd_exec_thr;
	  cmd_exec_thr = NULL;
	}
	cmd_exec_thr = new boost::thread(SetTool, inbuf, sock);
      } else if (! strncmp(inbuf, "StopMotion", strlen("StopMotion"))) {
	if (NULL != cmd_exec_thr) {
	  cmd_exec_thr->interrupt();
	  delete cmd_exec_thr;
	  cmd_exec_thr = NULL;
	}
	cmd_exec_thr = new boost::thread(StopMotion, inbuf, sock);
      } else if (! strncmp(inbuf, "SetAbsoluteSpeed", strlen("SetAbsoluteSpeed"))) {
	if (1 == sscanf(inbuf, "%*s %lf", &d1)) {
	  result = robot.SetAbsoluteSpeed(d1);
	} else {
	  fprintf(stderr, "invalid arguments: ``%s''\n", inbuf);
	  result = CANON_REJECT;
	}
	snprintf(outbuf, sizeof(outbuf)-1,
		 "%s SetAbsoluteSpeed",
		 CANON_SUCCESS == result ? "Success" :
		 CANON_FAILURE == result ? "Failure" : "Reject");
	outbuf[sizeof(outbuf)-1] = 0;
	boost::asio::write(*sock, boost::asio::buffer(outbuf, strlen(outbuf)+1));
      } else {
	fprintf(stderr, "unknown command: ``%s''\n", inbuf);
      }
    } // while (true)
  } catch (std::exception& e) {
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}

static void server(boost::asio::io_service *io_service, int port, void (*session)(socket_ptr))
{
  tcp::acceptor a(*io_service, tcp::endpoint(tcp::v4(), port));

  while (true) {
    socket_ptr sock(new tcp::socket(*io_service));
    a.accept(*sock);
    boost::thread t(boost::bind(session, sock));
  }
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
  boost::thread *stat_exec_thr = NULL;
  boost::asio::io_service io_service;

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
  stat_exec_thr = new boost::thread(server, &io_service, stat_port, stat_session);

  // run command server here, spawning command handlers
  server(&io_service, cmd_port, cmd_session);

  return 0;
}

