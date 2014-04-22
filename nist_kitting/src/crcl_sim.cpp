#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string.h>
#include <ctype.h>
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
}

extern "C" void sleep(int secs); // FIXME

CanonReturn CRCL_Sim::MoveStraightTo(robotPose pose)
{
  simPose = pose;

  sleep(3);			// and me

  return CANON_SUCCESS;
}

CanonReturn CRCL_Sim::GetRobotPose (robotPose *pose)
{
  *pose = simPose;
  return CANON_SUCCESS;
}
