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
  printf( "Received close gripper msg\n" );
}

void CloseToolChangerMsg::process(void *sendTo)
{
  printf( "Received close tool changer msg\n" );
}

void DwellMsg::process(void *sendTo)
{
  printf( "Received dwell message of time: %lf\n", time );
}

void EndCanonMsg::process(void *sendTo)
{
  printf( "Received endCanon message reason: %d\n", reason );
}

void InitCanonMsg::process(void *sendTo)
{
  printf( "Received initCanon message\n" );
}

void MessageMsg::process(void *sendTo)
{
  printf( "Received Message msg: %s\n", message.c_str() );
}

void MoveStraightToMsg::process(void *sendTo)
{
  printf( "Received MoveStraightTo msg\n" );
}

void MoveThroughToMsg::process(void *sendTo)
{
  printf( "Received MoveThroughTo msg\n" );
}

void MoveToMsg::process(void *sendTo)
{
  printf( "Received MoveTo msg\n" );
}

void OpenGripperMsg::process(void *sendTo)
{
  printf( "Received open gripper msg\n" );
}

void OpenToolChangerMsg::process(void *sendTo)
{
  printf( "Received open tool changer msg\n" );
}

void SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteAcceleration msg\n" );
}

void SetAbsoluteSpeedMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteSpeed msg\n" );
}

void SetAngleUnitsMsg::process(void *sendTo)
{
  printf( "Received SetAngleUnits msg\n" );
}

void SetEndAngleToleranceMsg::process(void *sendTo)
{
  printf( "Received SetEndAngleTolerance msg\n" );
}

void SetEndPointToleranceMsg::process(void *sendTo)
{
  printf( "Received SetEndPointTolerance msg\n" );
}

void SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  printf( "Received SetIntermediatePointTolerance msg\n" );
}

void SetLengthUnitsMsg::process(void *sendTo)
{
  printf( "Received SetLengthUnits msg\n" );
}

void SetRelativeAccelerationMsg::process(void *sendTo)
{
  printf( "Received SetRelativeAcceleration msg\n" );
}

void SetRelativeSpeedMsg::process(void *sendTo)
{
  printf( "Received SetRelativeSpeed msg\n" );
}
