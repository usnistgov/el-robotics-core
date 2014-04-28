#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

#include <boost/thread/mutex.hpp>

#include "nist_kitting/msg_types.h"
#include "nist_kitting/kitting_utils.h"
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
  toolSetting = 0;

  period = CRCL_SIM_PERIOD_DEFAULT;
}

CRCL_Sim::~CRCL_Sim()
{
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

#define LOCKIT boost::mutex::scoped_lock lock(mutex)

CanonReturn CRCL_Sim::MoveStraightTo(robotPose end)
{
  robotPose here;
  double dist;
  double time;
  double xincr, yincr, zincr;
  double tfrac;

  {
    LOCKIT;
    here = simPose;
  }

  dist = robotPoseDiff(end, here);

  if (absoluteSpeed < FLT_MIN) time = FLT_MAX;
  else time = dist / absoluteSpeed;

  if (time < period) {
    LOCKIT;
    simPose = end;
    return result = CANON_SUCCESS;
  }

  tfrac = period / time;
  xincr = (end.position.x - here.position.x) * tfrac;
  yincr = (end.position.y - here.position.y) * tfrac;
  zincr = (end.position.z - here.position.z) * tfrac;
  time += etime();

  while (etime() < time) {
    {
      LOCKIT;
      simPose.position.x += xincr;
      simPose.position.y += xincr;
      simPose.position.z += xincr;
    }
    esleep(period < FLT_MIN ? 1 : period);
  }

  LOCKIT;
  simPose = end;

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::SetTool(double percent)
{
#define PERCENT_PER_SEC 33
  double here;
  double dist;
  double time;
  double incr;
  double tfrac;

  {
    LOCKIT;
    here = toolSetting;
  }

  dist = percent - here;
  time = fabs(dist) / PERCENT_PER_SEC;

  if (time < period) {
    LOCKIT;
    toolSetting = percent;
    return result = CANON_SUCCESS;
  }

  tfrac = period / time;
  incr = dist * tfrac;
  time += etime();

  while (etime() < time) {
    {
      LOCKIT;
      toolSetting += incr;
    }
    esleep(period < FLT_MIN ? 1 : period);
  }

  LOCKIT;
  toolSetting = percent;

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::StopMotion(int condition)
{
  // any other move command will have been interrupted by now,
  // so just return OK

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::GetRobotPose (robotPose *pose)
{
  LOCKIT;
  *pose = simPose;

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::GetRobotAxes (robotAxes *axes)
{
  LOCKIT;
  // so trivial
  axes->axis[0] = simPose.position.x * 2;
  axes->axis[1] = simPose.position.y * 0.5;
  axes->axis[2] = -simPose.position.z;
  axes->axis[3] = simPose.orientation.x * 10;
  axes->axis[4] = simPose.orientation.y * 20;
  axes->axis[5] = simPose.orientation.z * 30;

  return result = CANON_SUCCESS;
}

CanonReturn CRCL_Sim::SetAbsoluteSpeed(double speed)
{
  if (speed < 0) speed = 0;

  absoluteSpeed = speed;

  return result = CANON_SUCCESS;
}
