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
//
// process must return 0 for no error
//
int CloseGripperMsg::process(void *sendTo)
{
  printf( "Received close gripper msg\n" );
  return 0;
}

void CloseGripperMsg::printMe()
{
  printf( "CloseGripperMsg\n");
}

int CloseToolChangerMsg::process(void *sendTo)
{
  printf( "Received close tool changer msg\n" );
  return 0;
}

void CloseToolChangerMsg::printMe()
{
  printf( "CloseToolChangerMsg\n");
}

int DwellMsg::process(void *sendTo)
{
  printf( "Received dwell message of time: %lf\n", time );
  return 0;
}

void DwellMsg::printMe()
{
      printf( "DwellMsg\n");
}

// return 2 to let processes know that we are done
int EndCanonMsg::process(void *sendTo)
{
  printf( "Received endCanon message reason: %d\n", reason );
  return 2;
}

void EndCanonMsg::printMe()
{
      printf( "EndCanonMsg\n");
}

int InitCanonMsg::process(void *sendTo)
{
  printf( "Received initCanon message\n" );
  return 0;
}

void InitCanonMsg::printMe()
{
      printf( "InitCanonMsg\n");
}

int MessageMsg::process(void *sendTo)
{
  printf( "Received Message msg: %s\n", message.c_str() );
  return 0;
}

void MessageMsg::printMe()
{
      printf( "MessageMsg\n");
}

int MoveStraightToMsg::process(void *sendTo)
{
  printf( "Received MoveStraightTo msg\n" );
  return 0;
}

void MoveStraightToMsg::printMe()
{
      printf( "MoveStraightToMsg\n");
}

int MoveThroughToMsg::process(void *sendTo)
{
  printf( "Received MoveThroughTo msg\n" );
  return 0;
}

void MoveThroughToMsg::printMe()
{
      printf( "MoveThroughtToMsg\n");
}

int MoveToMsg::process(void *sendTo)
{
  printf( "Received MoveTo msg\n" );
  return 0;
}

void MoveToMsg::printMe()
{
      printf( "MoveToMsg\n");
}

int OpenGripperMsg::process(void *sendTo)
{
  printf( "Received open gripper msg\n" );
  return 0;
}

void OpenGripperMsg::printMe()
{
      printf( "OpenGripperMsg\n");
}

int OpenToolChangerMsg::process(void *sendTo)
{
  printf( "Received open tool changer msg\n" );
  return 0;
}

void OpenToolChangerMsg::printMe()
{
      printf( "OpenToolChangerMsg\n");
}

int SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteAcceleration msg\n" );
  return 0;
}

void SetAbsoluteAccelerationMsg::printMe()
{
      printf( "SetAbsoluteAccelerationMsg\n");
}

int SetAbsoluteSpeedMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteSpeed msg\n" );
  return 0;
}

void SetAbsoluteSpeedMsg::printMe()
{
  printf( "SetAbsoluteSpeedMsg\n" );
}

int SetAngleUnitsMsg::process(void *sendTo)
{
  printf( "Received SetAngleUnits msg\n" );
  return 0;
}

void SetAngleUnitsMsg::printMe()
{
      printf( "SetAngleUnitsMsg\n");
}

int SetEndAngleToleranceMsg::process(void *sendTo)
{
  printf( "Received SetEndAngleTolerance msg\n" );
  return 0;
}

void SetEndAngleToleranceMsg::printMe()
{
      printf( "SetEndAngleToleranceMsg\n");
}

int SetEndPointToleranceMsg::process(void *sendTo)
{
  printf( "Received SetEndPointTolerance msg\n" );
  return 0;
}

void SetEndPointToleranceMsg::printMe()
{
      printf( "SetEndPointToleranceMsg\n");
}

int SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  printf( "Received SetIntermediatePointTolerance msg\n" );
  return 0;
}

void SetIntermediatePointToleranceMsg::printMe()
{
      printf( "SetIntermediatePointToleranceMsg\n");
}

int SetLengthUnitsMsg::process(void *sendTo)
{
  printf( "Received SetLengthUnits msg\n" );
  return 0;
}

void SetLengthUnitsMsg::printMe()
{
      printf( "SetLengthUnitsMsg\n");
}

int SetRelativeAccelerationMsg::process(void *sendTo)
{
  printf( "Received SetRelativeAcceleration msg\n" );
  return 0;
}

void SetRelativeAccelerationMsg::printMe()
{
      printf( "SetRelativeAccelerationMsg\n");
}

int SetRelativeSpeedMsg::process(void *sendTo)
{
  printf( "Received SetRelativeSpeed msg\n" );
  return 0;
}

void SetRelativeSpeedMsg::printMe()
{
      printf( "SetRelativeSpeedMsg\n");
}

int StartObjectScanMsg::process(void *sendTo)
{
	printf( "Received StartObjectScan msg for part %s\n", objectName.c_str() );
}

void StartObjectScanMsg::printMe()
{
      printf( "StartObjectScanMsg\n");
}

int StopMotionMsg::process(void *sendTo)
{
  if( isEmergency )
    printf( "Received emergency stop motion msg\n" );
  else
    printf( "Received non-emergency stop motion msg\n" );
  return 0;
}

void StopMotionMsg::printMe()
{
      printf( "StopMotionMsg\n");
}

int StopObjectScanMsg::process(void *sendTo)
{
	printf( "Received StopObjectScanMsg.\n");
}

void StopObjectScanMsg::printMe()
{
      printf( "StopObjectScanMsg\n");
}
