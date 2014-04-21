#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include "nist_kitting/socket_utils.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/crcl_robot.h"

class Sim_Robot : public CRCL_Robot {
 public:
  Sim_Robot();			// see below
  ~Sim_Robot() {};

  CanonReturn Couple (char *targetID) {};
  CanonReturn Dwell (int *events, double *params, int numEvents) {};
  CanonReturn EndCanon (int reason) {};
  CanonReturn InitCanon () {};
  CanonReturn Message (char *message) {};
  CanonReturn MoveStraightTo (robotPose pose); // see below
  CanonReturn MoveThroughTo (robotPose *poses,
			     int numPoses,
			     robotPose *accelerations = NULL,
			     robotPose *speeds = NULL,
			     robotPose *tolerances = NULL) {};
  CanonReturn Decouple (char *targetID) {};
  CanonReturn GetRobotAxes (robotAxes *axes) {};
  CanonReturn GetRobotPose (robotPose *pose); // see below
  CanonReturn MoveAttractor (robotPose pose) {};
  CanonReturn MoveToAxisTarget (robotAxes axes) {};
  CanonReturn RunProgram (char *programName, CRCLProgramParams params) {};
  CanonReturn SetAbsoluteAcceleration (double acceleration) {};
  CanonReturn SetAbsoluteSpeed (double speed) {};
  CanonReturn SetAngleUnits (char *unitName) {};
  CanonReturn SetAxialSpeeds (double *speeds) {};
  CanonReturn SetAxialUnits (char **unitNames) {};
  CanonReturn SetEndPoseTolerance (robotPose tolerance) {};
  CanonReturn SetIntermediatePoseTolerance (robotPose *tolerances) {};
  CanonReturn SetLengthUnits (char *unitName) {};
  CanonReturn SetParameter (char *paramName, void *paramVal) {};
  CanonReturn SetTool (double percent) {};
  CanonReturn SetRelativeSpeed (double percent) {};
  CanonReturn StopMotion (int condition); // see below

  CanonReturn SetRobotPose(robotPose pose); // see below
private:
  robotPose simPose;
};

Sim_Robot::Sim_Robot()
{
  simPose.position.x = 0;
  simPose.position.y = 0;
  simPose.position.z = 0;

  simPose.orientation.x = 0;
  simPose.orientation.y = 0;
  simPose.orientation.z = 0;
  simPose.orientation.w = 1;
}

CanonReturn Sim_Robot::MoveStraightTo(robotPose pose)
{
  simPose = pose;
  return CANON_OK;
}

CanonReturn Sim_Robot::GetRobotPose (robotPose *pose)
{
  *pose = simPose;
  return CANON_OK;
}

CanonReturn Sim_Robot::SetRobotPose (robotPose pose)
{
  simPose = pose;
  return CANON_OK;
}

CanonReturn Sim_Robot::StopMotion(int condition = 2)
{
  return CANON_OK;
}

static Sim_Robot simRobot;

/*
  Socket command protocol is null-terminated ASCII strings:

  <serial number> <cmd> { <arg> { <arg> }+ }* \000

  e.g.,

  "1 INIT"
  "2 MOVETO 1.0 2.3 4.5 0.0 -90.0 0.0"
  "17 HALT"

  Status messages are sent with serial number acks with DONE, EXEC, ERROR, 
  then the position:

  <serial number executing> <status> <x> <y> <z> <qx> <qy> <qz> <qw>

  "2 EXEC POS 0.5 1.7 2.3 0.0 -45.0 0.0"

  Status replies can be triggered with a "?" command, no serial number.
*/

static int handle_message(char *inbuf, int inbuf_len, int client_id)
{
  static int outbuf_len = 256;	// make this at least big enough for an int
  static char *outbuf = (char *) malloc(outbuf_len);
  static int cmdbuf_len = 256;
  static char *cmdbuf = (char *) malloc(cmdbuf_len);
  static int serial_number;
  static enum {DONE, EXEC, ERROR} status = DONE;
  char *inptr;
  int outchars;
  int i1;
  double d1, d2, d3, d4, d5, d6, d7;

  inbuf[inbuf_len - 1] = 0;

  inptr = inbuf;

#define DO_STATUS_STRING						\
  while (true) {							\
    robotPose r;							\
    simRobot.GetRobotPose(&r);						\
    outchars =								\
      snprintf(outbuf, outbuf_len, "%d %s %f %f %f %f %f %f %f",	\
	       serial_number,						\
	       DONE == status ? "DONE" :				\
	       EXEC == status ? "EXEC" : "ERROR",			\
	       r.position.x, r.position.y, r.position.z,		\
	       r.orientation.x, r.orientation.y,			\
	       r.orientation.z, r.orientation.w);			\
    if (outchars < outbuf_len) break;					\
    outbuf_len = 2 * outchars;						\
    outbuf = (char *) realloc(outbuf, outbuf_len);			\
  }

  if ('?' == inptr[0]) {
    robotPose r;
    simRobot.GetRobotPose(&r);
    DO_STATUS_STRING;
    socket_write(client_id, outbuf, strlen(outbuf) + 1);
    return 0;
  }

  if (cmdbuf_len < inbuf_len) {
    cmdbuf_len = 2 * inbuf_len;
    cmdbuf = (char *) realloc(cmdbuf, cmdbuf_len);
  }

  if (1 != sscanf(inptr, "%d", &i1)) return -1;
  serial_number = i1;

  while (! isspace(*inptr) && 0 != *inptr) inptr++;
  while (isspace(*inptr)) inptr++;

  if (! strncmp(inptr, "MOVETO ", strlen("MOVETO "))) {
    if (7 == sscanf(inptr, "%*s %lf %lf %lf %lf %lf %lf %lf",
		    &d1, &d2, &d3, &d4, &d5, &d6, &d7)) {
      robotPose p;
      p.position.x = d1, p.position.y = d2, p.position.z = d3;
      p.orientation.x = d4, p.orientation.y = d5, p.orientation.z = d6, p.orientation.w = d7;
      simRobot.SetRobotPose(p);
      status = DONE;
    } else {
      status = ERROR;
    }
    DO_STATUS_STRING;
    socket_write(client_id, outbuf, strlen(outbuf) + 1);
    return 0;
  }
}

int main(int argc, char *argv[])
{
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
      handle_message(inbuf, nchars, client_id);
    }

    socket_close(client_id);
    printf("closed %d\n", client_id);
  }

  return 0;
}

