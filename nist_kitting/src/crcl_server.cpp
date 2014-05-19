#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>

#include <ulapi.h>

#include <nist_core/nist_core.h>
#include <nist_core/crcl.h>
#include <nist_core/crcl_client.h>
#include <nist_core/crcl_robot.h>
#include <nist_core/crcl_sim_robot.h>

static bool debug = false;

using namespace crcl_robot;

#undef DO_TEMPLATES

#ifdef DO_TEMPLATES
static CrclRobot<CrclSimRobot> robot("");
#else
static CrclSimRobot robot("");
#endif

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

struct stat_thread_args {
  int stat_server_id;
};

void stat_thread_code(stat_thread_args *args)
{
  int stat_server_id = args->stat_server_id;
  int stat_connection_id;

  if (debug) printf("waiting for status client connection...\n");
  stat_connection_id = ulapi_socket_get_connection_id(stat_server_id);
  if (stat_connection_id < 0) {
    fprintf(stderr, "can't get status client connecton\n");
    return;
  }
  if (debug) printf("got a status client connection on id %d\n", stat_connection_id);

  while (true) {
    enum {INBUF_LEN = 256};
    enum {OUTBUF_LEN = 256};
    char inbuf[INBUF_LEN];
    char outbuf[OUTBUF_LEN];
    int nchars;
    CanonReturn result;

    nchars = ulapi_socket_read(stat_connection_id, inbuf, sizeof(inbuf)-1);
    inbuf[sizeof(inbuf)-1] = 0;

    if (nchars <= 0) {
      if (debug) printf("status client disconnected\n");
      break;
    }

    if (! strncmp(inbuf, "GetRobotPose", strlen("GetRobotPose"))) {
      robotPose p;
      result = robot.GetRobotPose(&p);
      snprintf(outbuf, sizeof(outbuf)-1,
	       "%s GetRobotPose %f %f %f %f %f %f",
	       CANON_SUCCESS == result ? "Success" :
	       CANON_FAILURE == result ? "Failure" : "Reject",
	       p.x, p.y, p.z, p.xrot, p.yrot, p.zrot);
      ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf)+1);
    } else if (! strncmp(inbuf, "GetRobotAxes", strlen("GetRobotAxes"))) {
      robotAxes a;
      result = robot.GetRobotAxes(&a);
      snprintf(outbuf, sizeof(outbuf)-1,
	       "%s GetRobotAxes %f %f %f %f %f %f",
	       CANON_SUCCESS == result ? "Success" :
	       CANON_FAILURE == result ? "Failure" : "Reject",
	       a.axis[0], a.axis[1], a.axis[2],
	       a.axis[3], a.axis[4], a.axis[5]);
      ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf)+1);
    } else if (! strncmp(inbuf, "GetTool", strlen("GetTool"))) {
      double d;
      result = robot.GetTool(&d);
      snprintf(outbuf, sizeof(outbuf)-1,
	       "%s GetTool %f",
	       CANON_SUCCESS == result ? "Success" :
	       CANON_FAILURE == result ? "Failure" : "Reject", d);
      ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf)+1);
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
      ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf)+1);
    } else if (0 == *inbuf) {
      // empty command, the client probably disconnected
    } else {
      fprintf(stderr, "invalid client status request: ``%s''\n", inbuf);
      snprintf(outbuf, sizeof(outbuf)-1, "Reject %s", inbuf);
      ulapi_socket_write(stat_connection_id, outbuf, strlen(outbuf)+1);
    }
  } // while (true)

  if (debug) printf("status handler done\n");

  return;
}

struct cmd_thread_args {
  int cmd_connection_id;
  const char *inbuf;
};

static void MoveStraightTo(cmd_thread_args *args)
{
  int cmd_connection_id = args->cmd_connection_id;
  const char *inbuf = args->inbuf;
  double d1, d2, d3, d4, d5, d6;
  robotPose p;
  CanonReturn result;
  char outbuf[256];

  if (6 == sscanf(inbuf, "%*s %lf %lf %lf %lf %lf %lf",
		  &d1, &d2, &d3, &d4, &d5, &d6)) {
    p.x = d1, p.y = d2, p.z = d3;
    p.xrot = d4, p.yrot = d5, p.zrot = d6;
    if (debug) printf("MoveStraightTo %f %f %f ...\n", p.x, p.y, p.z);
    result = robot.MoveStraightTo(p);
  } else {
    result = CANON_REJECT;
  }

  snprintf(outbuf, sizeof(outbuf)-1,
	   "%s MoveStraightTo",
	   CANON_SUCCESS == result ? "Success" :
	   CANON_FAILURE == result ? "Failure" : "Reject");
  outbuf[sizeof(outbuf)-1] = 0;
  ulapi_socket_write(cmd_connection_id, outbuf, strlen(outbuf)+1);

  if (debug) printf("MoveStraightTo done\n");
}

static void SetTool(cmd_thread_args *args)
{
  int cmd_connection_id = args->cmd_connection_id;
  const char *inbuf = args->inbuf;
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
  ulapi_socket_write(cmd_connection_id, outbuf, strlen(outbuf)+1);

  if (debug) printf("SetTool done\n");
}

static void StopMotion(cmd_thread_args *args)
{
  int cmd_connection_id = args->cmd_connection_id;
  const char *inbuf = args->inbuf;
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
  ulapi_socket_write(cmd_connection_id, outbuf, strlen(outbuf)+1);

  if (debug) printf("StopMotion done\n");
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
  int stat_server_id;
  int stat_connection_id;
  int cmd_server_id;
  int cmd_connection_id;
  int nchars;
  ulapi_task_struct stat_thread;
  stat_thread_args stat_args;
  int taskret;

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

  // set up two servers, one for status and one for commands

  stat_server_id = ulapi_socket_get_server_id(stat_port);
  if (stat_server_id < 0) {
    fprintf(stderr, "can't serve status port %d\n", stat_port);
    return 1;
  }
  if (debug) printf("serving status port %d\n", stat_port);

  cmd_server_id = ulapi_socket_get_server_id(cmd_port);
  if (cmd_server_id < 0) {
    fprintf(stderr, "can't serve command port %d\n", (int) cmd_port);
    return 1;
  }
  if (debug) printf("serving command port %d\n", (int) cmd_port);

  // main connection loop
  while (true) {

    // spawn status server thread
    ulapi_task_init(&stat_thread);
    stat_args.stat_server_id = stat_server_id;
    ulapi_task_start(&stat_thread, reinterpret_cast<ulapi_task_code>(stat_thread_code), reinterpret_cast<void *>(&stat_args), ulapi_prio_highest(), 0);

    // get a command client connection
    if (debug) printf("waiting for command client connection...\n");
    cmd_connection_id = ulapi_socket_get_connection_id(cmd_server_id);
    if (cmd_connection_id < 0) {
      fprintf(stderr, "can't get command client connecton\n");
      return 1;
    }
    if (debug) printf("got a command client connection on id %d\n", stat_connection_id);

    // run the command handler here
    while (true) {
#define INBUF_LEN 256
#define OUTBUF_LEN 256
      char inbuf[INBUF_LEN];
      char outbuf[OUTBUF_LEN];
      int nchars;
      ulapi_task_struct *cmd_thr = NULL;
      cmd_thread_args cmd_args;
      CanonReturn result;
      double d1;

      cmd_args.inbuf = inbuf;
      cmd_args.cmd_connection_id = cmd_connection_id;

      nchars = ulapi_socket_read(cmd_connection_id, inbuf, sizeof(inbuf)-1);
      inbuf[sizeof(inbuf)-1] = 0;

      if (nchars <= 0) {
	if (debug) printf("command client disconnected\n");
	break;
      }

      if (debug) printf("client command: ``%s'' (%d)\n", inbuf, nchars);

      // handle commands
      if (! strncmp(inbuf, "MoveStraightTo", strlen("MoveStraightTo"))) {
	if (NULL != cmd_thr) {
	  ulapi_task_stop(cmd_thr);
	  ulapi_task_delete(cmd_thr);
	  ulapi_task_delete(cmd_thr);
	}
	cmd_thr = ulapi_task_new();
	ulapi_task_start(cmd_thr, reinterpret_cast<ulapi_task_code>(MoveStraightTo), reinterpret_cast<void *>(&cmd_args), ulapi_prio_highest(), 0);
      } else if (! strncmp(inbuf, "SetTool", strlen("SetTool"))) {
	if (NULL != cmd_thr) {
	  ulapi_task_stop(cmd_thr);
	  ulapi_task_delete(cmd_thr);
	  ulapi_task_delete(cmd_thr);
	}
	cmd_thr = ulapi_task_new();
	ulapi_task_start(cmd_thr, reinterpret_cast<ulapi_task_code>(SetTool), reinterpret_cast<void *>(&cmd_args), ulapi_prio_highest(), 0);
      } else if (! strncmp(inbuf, "StopMotion", strlen("StopMotion"))) {
	if (NULL != cmd_thr) {
	  ulapi_task_stop(cmd_thr);
	  ulapi_task_delete(cmd_thr);
	  ulapi_task_delete(cmd_thr);
	}
	cmd_thr = ulapi_task_new();
	ulapi_task_start(cmd_thr, reinterpret_cast<ulapi_task_code>(StopMotion), reinterpret_cast<void *>(&cmd_args), ulapi_prio_highest(), 0);
      } else if (! strncmp(inbuf, "SetAbsoluteSpeed", strlen("SetAbsoluteSpeed"))) {
	// handle this one directly -- it's quick
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
	// FIXME -- need to mutex this with the other command threads
	ulapi_socket_write(cmd_connection_id, outbuf, strlen(outbuf)+1);
      } else if (0 == *inbuf) {
	// empty command, client probably disconnected
      } else {
	fprintf(stderr, "invalid client command request: ``%s''\n", inbuf);
      }
    } // while (true)

    if (debug) printf("command handler done\n");
    ulapi_task_join(&stat_thread, &taskret);

  } // while (true) for main connection loop

  return 0;
}

