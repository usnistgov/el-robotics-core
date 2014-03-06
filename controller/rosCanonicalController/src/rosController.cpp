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
#include <stdio.h>
#include <sys/time.h>
#include "rosInf.hh"
#include "database/Vector.h"
#include "database/Point.h"
#include "tf/transform_datatypes.h"
/**
   \file rosController.cpp 
   \author Stephen Balakirsky

   This file contains the ROS controller implementations of CRCL messages. 
   The \c sendTo pointer is typecast to RosInf * in each of these implementations.
*/

void CloseGripperMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      usarsim_inf::EffectorCommand command;
      command.state = usarsim_inf::EffectorCommand::CLOSE;
      ((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
      return;
    }
  else
    printf("\n\nError from rosController::CloseGripperMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void CloseGripperMsg::printMe(int verbosity)
{
  printf( "\tCloseGripperMsg current status: %s\n", printCurrentStatus().c_str());
}

statusReturn CloseGripperMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      ((RosInf*)rosCtrlTime)->waitForEffectors(); // block until the goal state has been reached
      setCurrentStatus(CmdComplete);
    }

  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void CloseToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      usarsim_inf::EffectorCommand command;
      command.state = usarsim_inf::EffectorCommand::CLOSE;
      ((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
      setCurrentStatus(SystemWorking);
      return;
    }
  else
    printf("\n\nError from rosController::CloseToolChanger\n\n");
  setCurrentStatus(SystemNoInit);
}

void CloseToolChangerMsg::printMe(int verbosity)
{
  printf( "\tCloseToolChangerMsg current status: %s\n", printCurrentStatus().c_str());
}

statusReturn CloseToolChangerMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      ((RosInf*)rosCtrlTime)->waitForEffectors(); // block until the goal state has been reached
      setCurrentStatus(CmdComplete);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void DwellMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      return;
    }
  else
    printf("\n\nError from rosController::DwellMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void DwellMsg::printMe(int verbosity)
{
  printf( "\troscontroller::DwellMsg of time: %lf with current status: %s\n", time, printCurrentStatus().c_str());
}

statusReturn DwellMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      usleep((int)(time*1000000));
      setCurrentStatus(CmdComplete);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void EndCanonMsg::process(void *sendTo)
{
  if(sendTo != NULL)
    {

      ((RosInf*)sendTo)->shutDown();
    }
  else
    printf("\n\nError from rosController::EndCanonMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void EndCanonMsg::printMe(int verbosity)
{
  printf( "\troscontroller::EndCanonMsg reason: %d with current status: %s\n", reason, printCurrentStatus().c_str());
}

statusReturn EndCanonMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      ros::shutdown();
      setCurrentStatus(SystemDone);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void InitCanonMsg::process(void *sendTo)
{
  if(sendTo != NULL)
    {
      setCurrentStatus(SystemWorking);
      ((RosInf*)sendTo)->init();
      return;
    }
  else
    printf("\n\nError from rosController::InitCanonMsg\n\n");
  setCurrentStatus(CmdError);
}

void InitCanonMsg::printMe(int verbosity)
{
  printf( "\troscontroller::InitCanonMsg with current status %s\n", printCurrentStatus().c_str());
}

statusReturn InitCanonMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void MessageMsg::process(void *sendTo)
{
  setCurrentStatus(SystemWorking);
}

void MessageMsg::printMe(int verbosity)
{
  printf( "\troscontroller::MessageMsg: %s with current status: %s\n", message.c_str(), printCurrentStatus().c_str());
}

statusReturn MessageMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void MoveStraightToMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::MoveStraightToMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void MoveStraightToMsg::printMe(int verbosity)
{
  printf( "\troscontroller::MoveStraightToMsg with current status: %s\n", printCurrentStatus().c_str());
}

statusReturn MoveStraightToMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void MoveThroughToMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      for(int i = 0;i<num;i++)
	{
	  ((RosInf*)sendTo)->addArmGoal(poseLocations[i]->gethasPoseLocation_Point()->gethasPoint_X(),
					poseLocations[i]->gethasPoseLocation_Point()->gethasPoint_Y(),
					poseLocations[i]->gethasPoseLocation_Point()->gethasPoint_Z(),
					poseLocations[i]->gethasPoseLocation_XAxis()->gethasVector_I(),
					poseLocations[i]->gethasPoseLocation_XAxis()->gethasVector_J(),
					poseLocations[i]->gethasPoseLocation_XAxis()->gethasVector_K(),
					poseLocations[i]->gethasPoseLocation_ZAxis()->gethasVector_I(), 
					poseLocations[i]->gethasPoseLocation_ZAxis()->gethasVector_J(),
					poseLocations[i]->gethasPoseLocation_ZAxis()->gethasVector_K());
	}
      return;
    }
  else
    printf("\n\nError from rosController::MoveThroughToMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void MoveThroughToMsg::printMe(int verbosity)
{
  printf( "\tMoveThroughtToMsg\n");
}

statusReturn MoveThroughToMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      if( !((RosInf*)rosCtrlTime)->checkCommandDone())
	{
	  (*resetTime).it_interval.tv_sec = 0;
	  (*resetTime).it_interval.tv_usec = 0;
	  (*resetTime).it_value.tv_sec = 0;
	  (*resetTime).it_value.tv_usec = 500000;
	  return( getCurrentStatus() );
	}
      setCurrentStatus(CmdComplete);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void MoveToMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      ((RosInf*)sendTo)->addArmGoal(poseLocation->gethasPoseLocation_Point()->gethasPoint_X(),
				    poseLocation->gethasPoseLocation_Point()->gethasPoint_Y(),
				    poseLocation->gethasPoseLocation_Point()->gethasPoint_Z(),
				    poseLocation->gethasPoseLocation_XAxis()->gethasVector_I(),
				    poseLocation->gethasPoseLocation_XAxis()->gethasVector_J(),
				    poseLocation->gethasPoseLocation_XAxis()->gethasVector_K(),
				    poseLocation->gethasPoseLocation_ZAxis()->gethasVector_I(), 
				    poseLocation->gethasPoseLocation_ZAxis()->gethasVector_J(),
				    poseLocation->gethasPoseLocation_ZAxis()->gethasVector_K());
      return;
    }
  else
    printf("\n\nError from rosController::MoveToMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void MoveToMsg::printMe(int verbosity)
{
  printf( "\tMoveToMsg\n");
  printf( "\t Loc: <%f %f %f>\n", 
	  poseLocation->gethasPoseLocation_Point()->gethasPoint_X(),
	  poseLocation->gethasPoseLocation_Point()->gethasPoint_Y(),
	  poseLocation->gethasPoseLocation_Point()->gethasPoint_Z());

  tf::Vector3 xAxis (poseLocation->gethasPoseLocation_XAxis()->gethasVector_I(),
		     poseLocation->gethasPoseLocation_XAxis()->gethasVector_J(),
		     poseLocation->gethasPoseLocation_XAxis()->gethasVector_K());

  tf::Vector3 zAxis (poseLocation->gethasPoseLocation_ZAxis()->gethasVector_I(), 
		     poseLocation->gethasPoseLocation_ZAxis()->gethasVector_J(),
		     poseLocation->gethasPoseLocation_ZAxis()->gethasVector_K());

  //find equivalent quaternion for x/z vectors
  tf::Vector3 xRotationAxis (0, -1 * xAxis.z (), xAxis.y ());	//cross product of target point x axis and (1,0,0)
  float xAngle = acos (xAxis.x ());
  if (xRotationAxis.length () == 0)	//if target point x axis is parallel to world x
    {
      xRotationAxis = tf::Vector3 (0, 1, 0);	//rotate either pi or 0 about y axis
    }
  tf::Transform xTransform (tf::Quaternion (xRotationAxis, xAngle));
  tf::Vector3 transformedZ = xTransform * tf::Vector3 (0, 0, 1);
  float zAngle = acos (transformedZ.dot (zAxis) / zAxis.length ());
  tf::Transform zTransform (tf::
			    Quaternion (tf::Vector3 (1.0, 0.0, 0.0),
					zAngle));
  tf::Transform axisTransform = xTransform * zTransform;

  printf( "\t Rot: <%f %f %f %f>\n",
	  axisTransform.getRotation ().x (),
	  axisTransform.getRotation ().y (),
	  axisTransform.getRotation ().z (),
	  axisTransform.getRotation ().w ());
}

statusReturn MoveToMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      if( !((RosInf*)rosCtrlTime)->checkCommandDone())
	{
	  (*resetTime).it_interval.tv_sec = 0;
	  (*resetTime).it_interval.tv_usec = 0;
	  (*resetTime).it_value.tv_sec = 0;
	  (*resetTime).it_value.tv_usec = 500000;
	  //	  printf( "rosController::MoveToMsg: still working on command\n" );
	  return( getCurrentStatus() );
	}
      setCurrentStatus(CmdComplete);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  printf( "rosController::MoveToMsg: command complete\n" );
  return(getCurrentStatus());
}

void OpenGripperMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      usarsim_inf::EffectorCommand command;
      command.state = usarsim_inf::EffectorCommand::OPEN;
      ((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
      return;
    }
  else
    printf("\n\nError from rosController::OpenGripperMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void OpenGripperMsg::printMe(int verbosity)
{
  printf( "\tOpenGripperMsg\n");
}

statusReturn OpenGripperMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      ((RosInf*)rosCtrlTime)->waitForEffectors(); // block until the goal state has been reached
      setCurrentStatus(CmdComplete);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void OpenToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      usarsim_inf::EffectorCommand command;
      command.state = usarsim_inf::EffectorCommand::OPEN;
      ((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
      return;
    }
  else
    printf("\n\nError from rosController::OpenToolChangerMsg\n\n");
  setCurrentStatus(SystemNoInit);
}

void OpenToolChangerMsg::printMe(int verbosity)
{
  printf( "\tOpenToolChangerMsg\n");
}

statusReturn OpenToolChangerMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    {
      ((RosInf*)rosCtrlTime)->waitForEffectors(); // block until the goal state has been reached
      setCurrentStatus(CmdComplete);
    }
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetAbsoluteAccelerationMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetAbsoluteAccelerationMsg::printMe(int verbosity)
{
  printf( "\tSetAbsoluteAccelerationMsg\n");
}

statusReturn SetAbsoluteAccelerationMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetAbsoluteSpeedMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetAbsoluteSpeedMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetAbsoluteSpeedMsg::printMe(int verbosity)
{
  printf( "\tSetAbsoluteSpeedMsg\n" );
}

statusReturn SetAbsoluteSpeedMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetAngleUnitsMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetAngleUnitsMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetAngleUnitsMsg::printMe(int verbosity)
{
  printf( "\tSetAngleUnitsMsg\n");
}

statusReturn SetAngleUnitsMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetEndAngleToleranceMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetEndAngleToleranceMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetEndAngleToleranceMsg::printMe(int verbosity)
{
  printf( "\tSetEndAngleToleranceMsg\n");
}

statusReturn SetEndAngleToleranceMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetEndPointToleranceMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      ((RosInf*)sendTo)->setEndPointTolerance(tolerance);
    }
  else
    {
      printf("\n\nError from rosController::SetEndPointToleranceMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetEndPointToleranceMsg::printMe(int verbosity)
{
  printf( "\tSetEndPointToleranceMsg\n");
}

statusReturn SetEndPointToleranceMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetIntermediatePointTolerance\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetIntermediatePointToleranceMsg::printMe(int verbosity)
{
  printf( "\tSetIntermediatePointToleranceMsg\n");
}

statusReturn SetIntermediatePointToleranceMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetLengthUnitsMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      ((RosInf*)sendTo)->setLengthUnits(unitName);
    }
  else
    {
      printf("\n\nError from rosController::SetLengthUnitMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetLengthUnitsMsg::printMe(int verbosity)
{
  printf( "\tSetLengthUnitsMsg\n");
}

statusReturn SetLengthUnitsMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetRelativeAccelerationMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetRelativeAccelerationMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetRelativeAccelerationMsg::printMe(int verbosity)
{
  printf( "\tSetRelativeAccelerationMsg\n");
}

statusReturn SetRelativeAccelerationMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void SetRelativeSpeedMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    setCurrentStatus(SystemWorking);
  else
    {
      printf("\n\nError from rosController::SetRelativeSpeedMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void SetRelativeSpeedMsg::printMe(int verbosity)
{
  printf( "\tSetRelativeSpeedMsg\n");
}

statusReturn SetRelativeSpeedMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void StartObjectScanMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      ((RosInf*)sendTo)->searchPart(objectName);
    }
  else
    {
      printf("\n\nError from rosController::StartObjectScanMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void StartObjectScanMsg::printMe(int verbosity)
{
  printf( "\tStartObjectScanMsg\n");
}

statusReturn StartObjectScanMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void StopMotionMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      ((RosInf*)sendTo)->stopMotion();
    }
  else
    {
      printf("\n\nError from rosController::StopMotionMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }

}

void StopMotionMsg::printMe(int verbosity)
{
  printf( "\tStopMotionMsg\n");
}

statusReturn StopMotionMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}

void StopObjectScanMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
    {
      setCurrentStatus(SystemWorking);
      ROS_ERROR("STOP SCAN!");
      ((RosInf*)sendTo)->stopSearch();
    }
  else
    {
      printf("\n\nError from rosController::StopObjectScanMsg\n\n");
      setCurrentStatus(SystemNoInit);
    }
}

void StopObjectScanMsg::printMe(int verbosity)
{
  printf( "\tStopObjectScanMsg\n");
}

statusReturn StopObjectScanMsg::timer(itimerval *resetTime, void *rosCtrlTime)
{
  if( getCurrentStatus() == SystemWorking )
    setCurrentStatus(CmdComplete);
  (*resetTime).it_interval.tv_sec = 0;
  (*resetTime).it_interval.tv_usec = 0;
  (*resetTime).it_value.tv_sec = 0;
  (*resetTime).it_value.tv_usec = 0;
  return(getCurrentStatus());
}
