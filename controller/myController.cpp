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

int CloseToolChangerMsg::process(void *sendTo)
{
  printf( "Received close tool changer msg\n" );
  return 0;
}

int DwellMsg::process(void *sendTo)
{
  printf( "Received dwell message of time: %lf\n", time );
  return 0;
}

// return 2 to let processes know that we are done
int EndCanonMsg::process(void *sendTo)
{
  printf( "Received endCanon message reason: %d\n", reason );
  return 2;
}

int InitCanonMsg::process(void *sendTo)
{
  printf( "Received initCanon message\n" );
  return 0;
}

int MessageMsg::process(void *sendTo)
{
  printf( "Received Message msg: %s\n", message.c_str() );
  return 0;
}

int MoveStraightToMsg::process(void *sendTo)
{
  printf( "Received MoveStraightTo msg\n" );
  return 0;
}

int MoveThroughToMsg::process(void *sendTo)
{
  printf( "Received MoveThroughTo msg\n" );
  return 0;
}

int MoveToMsg::process(void *sendTo)
{
  printf( "Received MoveTo msg\n" );
  return 0;
}

int OpenGripperMsg::process(void *sendTo)
{
  printf( "Received open gripper msg\n" );
  return 0;
}

int OpenToolChangerMsg::process(void *sendTo)
{
  printf( "Received open tool changer msg\n" );
  return 0;
}

int SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteAcceleration msg\n" );
  return 0;
}

int SetAbsoluteSpeedMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteSpeed msg\n" );
  return 0;
}

int SetAngleUnitsMsg::process(void *sendTo)
{
  printf( "Received SetAngleUnits msg\n" );
  return 0;
}

int SetEndAngleToleranceMsg::process(void *sendTo)
{
  printf( "Received SetEndAngleTolerance msg\n" );
  return 0;
}

int SetEndPointToleranceMsg::process(void *sendTo)
{
  printf( "Received SetEndPointTolerance msg\n" );
  return 0;
}

int SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  printf( "Received SetIntermediatePointTolerance msg\n" );
  return 0;
}

int SetLengthUnitsMsg::process(void *sendTo)
{
  printf( "Received SetLengthUnits msg\n" );
  return 0;
}

int SetRelativeAccelerationMsg::process(void *sendTo)
{
  printf( "Received SetRelativeAcceleration msg\n" );
  return 0;
}

int SetRelativeSpeedMsg::process(void *sendTo)
{
  printf( "Received SetRelativeSpeed msg\n" );
  return 0;
}

int StopMotionMsg::process(void *sendTo)
{
  if( isEmergency )
    printf( "Received emergency stop motion msg\n" );
  else
    printf( "Received non-emergency stop motion msg\n" );
  return 0;
}
