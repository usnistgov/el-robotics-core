/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/
/*

This implementation of the canonical robot commands simply has each
command print itself.

*/

#include <stdio.h>
#include "canonicalMsg.hh"

void CloseGripperMsg::process()
{
  printf("CloseGripper()\n");
}

void CloseToolChangerMsg::process()
{
  printf("CloseToolChanger()\n");
}

void DwellMsg::process()
{
  printf("Dwell(%lf)\n", time);
}

void EndCanonMsg::process()
{
  printf("EndCanon(%d)\n", reason);
}

void InitCanonMsg::process()
{
  printf("InitCanon()\n");
}

void MessageMsg::process()
{
  printf("Message(\"%s\")\n", message.c_str());
}

void MoveThroughToMsg::process()
{
  int n;
  Pose * pose;

  printf("MoveThroughTo({");
  pose = poses[0];
  printf("{{%f,%f,%f},{%f,%f,%f},{%f,%f,%f}}",
	 pose->origin.x, pose->origin.y, pose->origin.z,
	 pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	 pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
  for (n = 1; n < num; n++)
    {
      pose = poses[n];
      printf(",\n               {{%f,%f,%f},{%f,%f,%f},{%f,%f,%f}}",
	 pose->origin.x, pose->origin.y, pose->origin.z,
	 pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	 pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
    }
  printf("},%d)\n", num);
}

void MoveStraightToMsg::process()
{
  printf("MoveStraightTo({{%f,%f,%f},{%f,%f,%f},{%f,%f,%f}})\n",
	 pose->origin.x, pose->origin.y, pose->origin.z,
	 pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	 pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
}

void MoveToMsg::process()
{
  printf("MoveTo({{%f,%f,%f},{%f,%f,%f},{%f,%f,%f}})\n",
	 pose->origin.x, pose->origin.y, pose->origin.z,
	 pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	 pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
}

void OpenGripperMsg::process()
{
  printf("OpenGripper()\n" );
}

void OpenToolChangerMsg::process()
{
  printf("OpenToolChanger()\n" );
}

void SetAbsoluteAccelerationMsg::process()
{
  printf("SetAbsoluteAcceleration(%f)\n", acceleration);
}

void SetAbsoluteSpeedMsg::process()
{
  printf("SetAbsoluteSpeed(%f)\n", speed);
}

void SetAngleUnitsMsg::process()
{
  printf("SetAngleUnits(\"%s\")\n", unitName.c_str());
}

void SetEndAngleToleranceMsg::process()
{
  printf("SetEndAngleTolerance(%f)\n", tolerance);
}

void SetEndPointToleranceMsg::process()
{
  printf("SetEndPointTolerance(%f)\n", tolerance);
}

void SetIntermediatePointToleranceMsg::process()
{
  printf("SetIntermediatePointTolerance(%f)\n", tolerance);
}

void SetLengthUnitsMsg::process()
{
  printf("SetLengthUnits(\"%s\")\n", unitName.c_str());
}

void SetRelativeAccelerationMsg::process()
{
  printf("SetRelativeAcceleration(%f)\n", percent);
}

void SetRelativeSpeedMsg::process()
{
  printf("SetRelativeSpeed(%f)\n", percent);
}

void UnreadableMsg::process()
{
  printf("UnreadableMsg(\"%s\")\n", commandString.c_str());
}
