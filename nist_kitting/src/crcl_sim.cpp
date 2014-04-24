#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/crcl_sim.h"

CRCL_Sim::CRCL_Sim()
{
  simPose.position.x = 0;
  simPose.position.y = 0;
  simPose.position.z = 0;

  simPose.orientation.x = 0;
  simPose.orientation.y = 0;
  simPose.orientation.z = 0;
  simPose.orientation.w = 1;

  absoluteSpeed = 1;

  period = CRCL_SIM_PERIOD_DEFAULT;
}

double CRCL_Sim::setPeriod(double p)
{
  period = p;

  return period;
}

double CRCL_Sim::getPeriod()
{
  return period;
}

#define SQ(x) ((x)*(x))

static double robotPoseDiff(robotPose &p1, robotPose &p2)
{
  // ignore orientation part
  return sqrt(SQ(p1.position.x - p2.position.x) +
	      SQ(p1.position.y - p2.position.y) +
	      SQ(p1.position.z - p2.position.z));
}

CanonReturn CRCL_Sim::MoveStraightTo(robotPose end)
{
  double dist;
  double time;
  double xincr, yincr, zincr;
  double tfrac;

  dist = robotPoseDiff(end, simPose);

  if (absoluteSpeed < FLT_MIN) time = FLT_MAX;
  else time = dist / absoluteSpeed;

  if (time < period) {
    simPose = end;
    return result = CANON_SUCCESS;
  }

  tfrac = period / time;
  xincr = (end.position.x - simPose.position.x) * tfrac;
  yincr = (end.position.y - simPose.position.y) * tfrac;
  zincr = (end.position.z - simPose.position.z) * tfrac;
  time += etime();

  while (etime() < time) {
    simPose.position.x += xincr;
    simPose.position.y += xincr;
    simPose.position.z += xincr;

    esleep(period < FLT_MIN ? 1 : period);
  }
  simPose = end;

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::GetRobotPose (robotPose *pose)
{
  *pose = simPose;

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::SetAbsoluteSpeed(double speed)
{
  if (speed < 0) speed = 0;

  absoluteSpeed = speed;

  return result = CANON_SUCCESS;
}
