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

statusReturn CloseGripperMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::CLOSE;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return CmdComplete;
  }
  return SystemNoInit;
}

void CloseGripperMsg::printMe(int verbosity)
{
  printf( "\tCloseGripperMsg\n");
}

StatusMsg CloseGripperMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn CloseToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::CLOSE;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return CmdComplete;
  }
  return SystemNoInit;
}

void CloseToolChangerMsg::printMe(int verbosity)
{
  printf( "\tCloseToolChangerMsg\n");
}

StatusMsg CloseToolChangerMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn DwellMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
	  usleep((int)(time*1000000));
  }
  return CmdComplete;
}

void DwellMsg::printMe(int verbosity)
{
  printf( "\tDwellMsg of time: %lf\n", time);
}

StatusMsg DwellMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn EndCanonMsg::process(void *sendTo)
{
  if(sendTo != NULL)
  {
  	((RosInf*)sendTo)->shutDown();
  }
  ros::shutdown();
  return SystemDone;
}

void EndCanonMsg::printMe(int verbosity)
{
  printf( "\tEndCanonMsg reason: %d\n", reason);
}

StatusMsg EndCanonMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn InitCanonMsg::process(void *sendTo)
{
	if(sendTo != NULL)
	{
		((RosInf*)sendTo)->init();
		return CmdComplete;
	}
	printf("Could not initialize canon because controller is null\n");
	return SystemNoInit;
}

void InitCanonMsg::printMe(int verbosity)
{
      printf( "\tInitCanonMsg\n");
}

StatusMsg InitCanonMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn MessageMsg::process(void *sendTo)
{
  return CmdComplete;
}

void MessageMsg::printMe(int verbosity)
{
  printf( "\tMessageMsg: %s\n", message.c_str());
}

StatusMsg MessageMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn MoveStraightToMsg::process(void *sendTo)
{
  return CmdComplete;
}

void MoveStraightToMsg::printMe(int verbosity)
{
      printf( "\tMoveStraightToMsg\n");
}

StatusMsg MoveStraightToMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn MoveThroughToMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
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
	return CmdComplete;	
  }
  return SystemNoInit;
}

void MoveThroughToMsg::printMe(int verbosity)
{
      printf( "\tMoveThroughtToMsg\n");
}

StatusMsg MoveThroughToMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn MoveToMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
  	((RosInf*)sendTo)->addArmGoal(poseLocation->gethasPoseLocation_Point()->gethasPoint_X(),
							poseLocation->gethasPoseLocation_Point()->gethasPoint_Y(),
							poseLocation->gethasPoseLocation_Point()->gethasPoint_Z(),
							poseLocation->gethasPoseLocation_XAxis()->gethasVector_I(),
							poseLocation->gethasPoseLocation_XAxis()->gethasVector_J(),
							poseLocation->gethasPoseLocation_XAxis()->gethasVector_K(),
							poseLocation->gethasPoseLocation_ZAxis()->gethasVector_I(), 
							poseLocation->gethasPoseLocation_ZAxis()->gethasVector_J(),
							poseLocation->gethasPoseLocation_ZAxis()->gethasVector_K());
  }
  return CmdComplete;
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

StatusMsg MoveToMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn OpenGripperMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::OPEN;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return CmdComplete;
  }
  return SystemNoInit;
}

void OpenGripperMsg::printMe(int verbosity)
{
      printf( "\tOpenGripperMsg\n");
}

StatusMsg OpenGripperMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn OpenToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::OPEN;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return CmdComplete;
  }
  return SystemNoInit;
}

void OpenToolChangerMsg::printMe(int verbosity)
{
      printf( "\tOpenToolChangerMsg\n");
}

StatusMsg OpenToolChangerMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetAbsoluteAccelerationMsg::printMe(int verbosity)
{
      printf( "\tSetAbsoluteAccelerationMsg\n");
}

StatusMsg SetAbsoluteAccelerationMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetAbsoluteSpeedMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetAbsoluteSpeedMsg::printMe(int verbosity)
{
  printf( "\tSetAbsoluteSpeedMsg\n" );
}

StatusMsg SetAbsoluteSpeedMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetAngleUnitsMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetAngleUnitsMsg::printMe(int verbosity)
{
      printf( "\tSetAngleUnitsMsg\n");
}

StatusMsg SetAngleUnitsMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetEndAngleToleranceMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetEndAngleToleranceMsg::printMe(int verbosity)
{
      printf( "\tSetEndAngleToleranceMsg\n");
}

StatusMsg SetEndAngleToleranceMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetEndPointToleranceMsg::process(void *sendTo)
{
  ((RosInf*)sendTo)->setEndPointTolerance(tolerance);
  return CmdComplete;
}

void SetEndPointToleranceMsg::printMe(int verbosity)
{
      printf( "\tSetEndPointToleranceMsg\n");
}

StatusMsg SetEndPointToleranceMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetIntermediatePointToleranceMsg::printMe(int verbosity)
{
      printf( "\tSetIntermediatePointToleranceMsg\n");
}

StatusMsg SetIntermediatePointToleranceMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetLengthUnitsMsg::process(void *sendTo)
{
  ((RosInf*)sendTo)->setLengthUnits(unitName);
  return CmdComplete;
}

void SetLengthUnitsMsg::printMe(int verbosity)
{
      printf( "\tSetLengthUnitsMsg\n");
}

StatusMsg SetLengthUnitsMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetRelativeAccelerationMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetRelativeAccelerationMsg::printMe(int verbosity)
{
      printf( "\tSetRelativeAccelerationMsg\n");
}

StatusMsg SetRelativeAccelerationMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn SetRelativeSpeedMsg::process(void *sendTo)
{
  return CmdComplete;
}

void SetRelativeSpeedMsg::printMe(int verbosity)
{
      printf( "\tSetRelativeSpeedMsg\n");
}

StatusMsg SetRelativeSpeedMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn StartObjectScanMsg::process(void *sendTo)
{
  ((RosInf*)sendTo)->searchPart(objectName);
  return CmdComplete;
}

void StartObjectScanMsg::printMe(int verbosity)
{
      printf( "\tStartObjectScanMsg\n");
}

StatusMsg StartObjectScanMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn StopMotionMsg::process(void *sendTo)
{
	((RosInf*)sendTo)->stopMotion();
	return CmdComplete;
}

void StopMotionMsg::printMe(int verbosity)
{
      printf( "\tStopMotionMsg\n");
}

StatusMsg StopMotionMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}

statusReturn StopObjectScanMsg::process(void *sendTo)
{
	ROS_ERROR("STOP SCAN!");
	((RosInf*)sendTo)->stopSearch();
	return CmdComplete;
}

void StopObjectScanMsg::printMe(int verbosity)
{
      printf( "\tStopObjectScanMsg\n");
}

StatusMsg StopObjectScanMsg::timer(float *resetTime)
{
  StatusMsg status;
  resetTime = 0;
  return(status);
}
