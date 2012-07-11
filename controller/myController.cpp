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

void CloseGripperMsg::process()
{
  printf( "Received close gripper msg\n" );
}

void DwellMsg::process()
{
  printf( "Received dwell message of time: %lf\n", time );
}

void EndCanonMsg::process()
{
  printf( "Received endCanon message reason: %d\n", reason );
}

void InitCanonMsg::process()
{
  printf( "Received initCanon message\n" );
}

void MessageMsg::process()
{
  printf( "Received Message msg: %s\n", message.c_str() );
}

void MoveSmoothlyToMsg::process()
{
  printf( "Received MoveSmoothlyTo msg\n" );
}

void MoveStraightToMsg::process()
{
  printf( "Received MoveStraightTo msg\n" );
}

void MoveToMsg::process()
{
  printf( "Received MoveTo msg\n" );
}

void OpenGripperMsg::process()
{
  printf( "Received open gripper msg\n" );
}

void SetAbsoluteAccelerationMsg::process()
{
  printf( "Received SetAbsoluteAcceleration msg\n" );
}

void SetAngleUnitsMsg::process()
{
  printf( "Received SetAngleUnits msg\n" );
}

void SetEndAngleToleranceMsg::process()
{
  printf( "Received SetEndAngleTolerance msg\n" );
}

void SetEndPointToleranceMsg::process()
{
  printf( "Received SetEndPointTolerance msg\n" );
}

void SetIntermediatePointToleranceMsg::process()
{
  printf( "Received SetIntermediatePointTolerance msg\n" );
}

void SetLengthUnitsMsg::process()
{
  printf( "Received SetLengthUnits msg\n" );
}

void SetRelativeAccelerationMsg::process()
{
  printf( "Received SetRelativeAcceleration msg\n" );
}

void SetRelativeSpeedMsg::process()
{
  printf( "Received SetRelativeSpeed msg\n" );
}
