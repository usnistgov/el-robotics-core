/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/
/*!
  \file   myController.cc
  \brief  Provides a sample implementation of the controller
  This class will handle the queued messages and print out strings telling about
  the processing

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include <stdio.h>
#include "canonicalMsg.hh"

void CloseGripperMsg::process(void *sendTo)
{
  printf("CloseGripper()\n");
}

void CloseToolChangerMsg::process(void *sendTo)
{
  printf("CloseToolChanger()\n");
}

void DwellMsg::process(void *sendTo)
{
  printf("Dwell(%lf)\n", time);
}

void EndCanonMsg::process(void *sendTo)
{
  printf("EndCanon(%d)\n", reason);
}

void InitCanonMsg::process(void *sendTo)
{
  printf("InitCanon()\n");
}

void MessageMsg::process(void *sendTo)
{
  printf("Message(\"%s\")\n", message.c_str());
}

void MoveThroughToMsg::process(void *sendTo)
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

void MoveStraightToMsg::process(void *sendTo)
{
  printf("MoveStraightTo({{%f,%f,%f},{%f,%f,%f},{%f,%f,%f}})\n",
	 pose->origin.x, pose->origin.y, pose->origin.z,
	 pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	 pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
}

void MoveToMsg::process(void *sendTo)
{
  printf("MoveTo({{%f,%f,%f},{%f,%f,%f},{%f,%f,%f}})\n",
	 pose->origin.x, pose->origin.y, pose->origin.z,
	 pose->zAxis.i, pose->zAxis.j, pose->zAxis.k,
	 pose->xAxis.i, pose->xAxis.j, pose->xAxis.k);
}

void OpenGripperMsg::process(void *sendTo)
{
  printf("OpenGripper()\n" );
}

void OpenToolChangerMsg::process(void *sendTo)
{
  printf("OpenToolChanger()\n" );
}

void SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  printf("SetAbsoluteAcceleration(%f)\n", acceleration);
}

void SetAbsoluteSpeedMsg::process(void *sendTo)
{
  printf("SetAbsoluteSpeed(%f)\n", speed);
}

void SetAngleUnitsMsg::process(void *sendTo)
{
  printf("SetAngleUnits(\"%s\")\n", unitName.c_str());
}

void SetEndAngleToleranceMsg::process(void *sendTo)
{
  printf("SetEndAngleTolerance(%f)\n", tolerance);
}

void SetEndPointToleranceMsg::process(void *sendTo)
{
  printf("SetEndPointTolerance(%f)\n", tolerance);
}

void SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  printf("SetIntermediatePointTolerance(%f)\n", tolerance);
}

void SetLengthUnitsMsg::process(void *sendTo)
{
  printf("SetLengthUnits(\"%s\")\n", unitName.c_str());
}

void SetRelativeAccelerationMsg::process(void *sendTo)
{
  printf("SetRelativeAcceleration(%f)\n", percent);
}

void SetRelativeSpeedMsg::process(void *sendTo)
{
  printf("SetRelativeSpeed(%f)\n", percent);
}
