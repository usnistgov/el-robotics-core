/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
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
statusReturn CloseGripperMsg::process(void *sendTo)
{
  printf( "myController::Received close gripper msg\n" );
  return CmdComplete;
}

void CloseGripperMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:CloseGripperMsg\n");
}

statusReturn CloseGripperMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn CloseToolChangerMsg::process(void *sendTo)
{
  printf( "myController::Received close tool changer msg\n" );
  return CmdComplete;
}

void CloseToolChangerMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:CloseToolChangerMsg\n");
}

statusReturn CloseToolChangerMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn DwellMsg::process(void *sendTo)
{
  printf( "myController::Received dwell message of time: %lf\n", time );
  return CmdComplete;
}

void DwellMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:DwellMsg\n");
}

statusReturn DwellMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

// return 2 to let processes know that we are done
statusReturn EndCanonMsg::process(void *sendTo)
{
  printf( "myController::Received endCanon message reason: %d\n", reason );
  return SystemDone;
}

void EndCanonMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:EndCanonMsg\n");
}

statusReturn EndCanonMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn InitCanonMsg::process(void *sendTo)
{
  printf( "myController::Received initCanon message\n" );
  return CmdComplete;
}

void InitCanonMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:InitCanonMsg\n");
}

statusReturn InitCanonMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn MessageMsg::process(void *sendTo)
{
  printf( "myController::Received Message msg: %s\n", message.c_str() );
  return CmdComplete;
}

statusReturn MessageMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

void MessageMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:MessageMsg\n");
}

statusReturn MoveStraightToMsg::process(void *sendTo)
{
  printf( "myController::Received MoveStraightTo msg\n" );
  return CmdComplete;
}

void MoveStraightToMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:MoveStraightToMsg\n");
}

statusReturn MoveStraightToMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn MoveThroughToMsg::process(void *sendTo)
{
  printf( "myController::Received MoveThroughTo msg\n" );
  return CmdComplete;
}

void MoveThroughToMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:MoveThroughtToMsg\n");
}

statusReturn MoveThroughToMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn MoveToMsg::process(void *sendTo)
{
  printf( "myController::Received MoveTo msg\n" );
  return CmdComplete;
}

void MoveToMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:MoveToMsg\n");
}

statusReturn MoveToMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn OpenGripperMsg::process(void *sendTo)
{
  printf( "myController::Received open gripper msg\n" );
  return CmdComplete;
}

void OpenGripperMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:OpenGripperMsg\n");
}

statusReturn OpenGripperMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn OpenToolChangerMsg::process(void *sendTo)
{
  printf( "myController::Received open tool changer msg\n" );
  return CmdComplete;
}

void OpenToolChangerMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:OpenToolChangerMsg\n");
}

statusReturn OpenToolChangerMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  printf( "myController::Received SetAbsoluteAcceleration msg\n" );
  return CmdComplete;
}

void SetAbsoluteAccelerationMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetAbsoluteAccelerationMsg\n");
}

statusReturn SetAbsoluteAccelerationMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetAbsoluteSpeedMsg::process(void *sendTo)
{
  printf( "myController::Received SetAbsoluteSpeed msg\n" );
  return CmdComplete;
}

void SetAbsoluteSpeedMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetAbsoluteSpeedMsg\n" );
}

statusReturn SetAbsoluteSpeedMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetAngleUnitsMsg::process(void *sendTo)
{
  printf( "myController::Received SetAngleUnits msg\n" );
  return CmdComplete;
}

void SetAngleUnitsMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetAngleUnitsMsg\n");
}

statusReturn SetAngleUnitsMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetEndAngleToleranceMsg::process(void *sendTo)
{
  printf( "myController::Received SetEndAngleTolerance msg\n" );
  return CmdComplete;
}

void SetEndAngleToleranceMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetEndAngleToleranceMsg\n");
}

statusReturn SetEndAngleToleranceMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetEndPointToleranceMsg::process(void *sendTo)
{
  printf( "myController::Received SetEndPointTolerance msg\n" );
  return CmdComplete;
}

void SetEndPointToleranceMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetEndPointToleranceMsg\n");
}

statusReturn SetEndPointToleranceMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  printf( "myController::Received SetIntermediatePointTolerance msg\n" );
  return CmdComplete;
}

void SetIntermediatePointToleranceMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetIntermediatePointToleranceMsg\n");
}

statusReturn SetIntermediatePointToleranceMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetLengthUnitsMsg::process(void *sendTo)
{
  printf( "myController::Received SetLengthUnits msg\n" );
  return CmdComplete;
}

void SetLengthUnitsMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetLengthUnitsMsg\n");
}

statusReturn SetLengthUnitsMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetRelativeAccelerationMsg::process(void *sendTo)
{
  printf( "myController::Received SetRelativeAcceleration msg\n" );
  return CmdComplete;
}

void SetRelativeAccelerationMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetRelativeAccelerationMsg\n");
}

statusReturn SetRelativeAccelerationMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn SetRelativeSpeedMsg::process(void *sendTo)
{
  printf( "myController::Received SetRelativeSpeed msg\n" );
  return CmdComplete;
}

void SetRelativeSpeedMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:SetRelativeSpeedMsg\n");
}

statusReturn SetRelativeSpeedMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn StartObjectScanMsg::process(void *sendTo)
{
	printf( "myController::Received StartObjectScan msg for part %s\n", objectName.c_str() );
}

void StartObjectScanMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:StartObjectScanMsg\n");
}

statusReturn StartObjectScanMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn StopMotionMsg::process(void *sendTo)
{
  if( isEmergency )
    printf( "myController::Received emergency stop motion msg\n" );
  else
    printf( "myController::Received non-emergency stop motion msg\n" );
  return CmdComplete;
}

void StopMotionMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:StopMotionMsg\n");
}

statusReturn StopMotionMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}

statusReturn StopObjectScanMsg::process(void *sendTo)
{
	printf( "myController::Received StopObjectScanMsg.\n");
}

void StopObjectScanMsg::printMe(int verbosity)
{
  if( verbosity )
    printf( "myController::printMe:StopObjectScanMsg\n");
}

statusReturn StopObjectScanMsg::timer(itimerval *resetTime)
{
  statusReturn status;
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(status);
}
