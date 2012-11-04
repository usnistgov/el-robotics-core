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
#include "myController.hh"

int MyController::processCloseGripper(CloseGripperMsg *closeGripperMsg)
{
  printf( "Received close gripper msg\n" );
}

int MyController::processDwell(DwellMsg *dwellMsg)
{
  printf( "Received dwell message of time: %lf\n", dwellMsg->time );
}

int MyController::processEndCanon(EndCanonMsg *endCanonMsg)
{
  printf( "Received endCanon message reason: %d\n", endCanonMsg->reason );
}

int MyController::processInitCanon(InitCanonMsg *initCanonMsg)
{
  printf( "Received initCanon message\n" );
}

int MyController::processMessage(MessageMsg *messageMsg)
{
  printf( "Received Message msg\n" );
}
int MyController::processMoveSmoothlyTo(MoveSmoothlyToMsg *moveSmoothlyToMsg)
{
  printf( "Received MoveSmoothlyTo msg\n" );
}
int MyController::processMoveStraightTo(MoveStraightToMsg *moveStraightToMsg)
{
  printf( "Received MoveStraightTo msg\n" );
}
int MyController::processMoveTo(MoveToMsg *moveToMsg)
{
  printf( "Received MoveTo msg\n" );
}
int MyController::processOpenGripper(OpenGripperMsg *openGripperMsg)
{
  printf( "Received open gripper msg\n" );
}

int MyController::processSetAbsoluteAcceleration(SetAbsoluteAccelerationMsg *setAbsoluteAccelerationMsg)
{
  printf( "Received SetAbsoluteAcceleration msg\n" );
}
int MyController::processSetAngleUnits(SetAngleUnitsMsg *setAngleUnitsMsg)
{
  printf( "Received SetAngleUnits msg\n" );
}
int MyController::processSetEndAngleTolerance(SetEndAngleToleranceMsg *setEndAngleToleranceMsg)
{
  printf( "Received SetEndAngleTolerance msg\n" );
}
int MyController::processSetEndPointTolerance(SetEndPointToleranceMsg *setEndPointToleranceMsg)
{
  printf( "Received SetEndPointTolerance msg\n" );
}
int MyController::processSetIntermediatePointTolerance(SetIntermediatePointToleranceMsg *setIntermediatePointToleranceMsg)
{
  printf( "Received SetIntermediatePointTolerance msg\n" );
}
int MyController::processSetLengthUnits(SetLengthUnitsMsg *setLengthUnitsMsg)
{
  printf( "Received SetLengthUnits msg\n" );
}
int MyController::processSetRelativeAcceleration(SetRelativeAccelerationMsg *setRelativeAccelerationMsg)
{
  printf( "Received SetRelativeAcceleration msg\n" );
}
int MyController::processSetRelativeSpeed(SetRelativeSpeedMsg *setRelativeSpeedMsg)
{
  printf( "Received SetRelativeSpeed msg\n" );
}
