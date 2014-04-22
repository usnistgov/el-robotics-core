#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
#include "nist_kitting/msg_types.h"
#include "nist_kitting/crcl.h"
#include "nist_kitting/sim_robot.h"

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

extern "C" void sleep(int secs); // FIXME

CanonReturn Sim_Robot::MoveStraightTo(robotPose pose)
{
  simPose = pose;

  sleep(3);			// and me

  return CANON_SUCCESS;
}

CanonReturn Sim_Robot::GetRobotPose (robotPose *pose)
{
  *pose = simPose;
  return CANON_SUCCESS;
}
