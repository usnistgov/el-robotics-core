#include <stdio.h>
#include "rosInf.hh"
#include <Vector.h>
#include <Point.h>
#include <tf/transform_datatypes.h>

int CloseGripperMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::CLOSE;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return 0;
  }
  return 1;
}

void CloseGripperMsg::printMe()
{
  printf( "\tCloseGripperMsg\n");
}

int CloseToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::CLOSE;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return 0;
  }
  return 1;
}

void CloseToolChangerMsg::printMe()
{
  printf( "\tCloseToolChangerMsg\n");
}

int DwellMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
	  usleep((int)(time*1000000));
  }
  return 0;
}

void DwellMsg::printMe()
{
  printf( "\tDwellMsg of time: %lf\n", time);
}

int EndCanonMsg::process(void *sendTo)
{
  if(sendTo != NULL)
  {
  	((RosInf*)sendTo)->shutDown();
  }
  ros::shutdown();
  return 2;
}

void EndCanonMsg::printMe()
{
  printf( "\tEndCanonMsg reason: %d\n", reason);
}

int InitCanonMsg::process(void *sendTo)
{
	if(sendTo != NULL)
	{
		((RosInf*)sendTo)->init();
		return 0;
	}
	printf("Could not initialize canon because controller is null\n");
	return 1;
}

void InitCanonMsg::printMe()
{
      printf( "\tInitCanonMsg\n");
}

int MessageMsg::process(void *sendTo)
{
  return 0;
}

void MessageMsg::printMe()
{
  printf( "\tMessageMsg: %s\n", message.c_str());
}

int MoveStraightToMsg::process(void *sendTo)
{
  return 0;
}

void MoveStraightToMsg::printMe()
{
      printf( "\tMoveStraightToMsg\n");
}

int MoveThroughToMsg::process(void *sendTo)
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
	return 0;	
  }
  return 1;
}

void MoveThroughToMsg::printMe()
{
      printf( "\tMoveThroughtToMsg\n");
}

int MoveToMsg::process(void *sendTo)
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
  return 0;
}

void MoveToMsg::printMe()
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

int OpenGripperMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::OPEN;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return 0;
  }
  return 1;
}

void OpenGripperMsg::printMe()
{
      printf( "\tOpenGripperMsg\n");
}

int OpenToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isInitialized())
  {
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::OPEN;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
  	((RosInf*)sendTo)->waitForEffectors(); // block until the goal state has been reached
  	return 0;
  }
  return 1;
}

void OpenToolChangerMsg::printMe()
{
      printf( "\tOpenToolChangerMsg\n");
}

int SetAbsoluteAccelerationMsg::process(void *sendTo)
{
  return 0;
}

void SetAbsoluteAccelerationMsg::printMe()
{
      printf( "\tSetAbsoluteAccelerationMsg\n");
}

int SetAbsoluteSpeedMsg::process(void *sendTo)
{
  return 0;
}

void SetAbsoluteSpeedMsg::printMe()
{
  printf( "\tSetAbsoluteSpeedMsg\n" );
}

int SetAngleUnitsMsg::process(void *sendTo)
{
  return 0;
}

void SetAngleUnitsMsg::printMe()
{
      printf( "\tSetAngleUnitsMsg\n");
}

int SetEndAngleToleranceMsg::process(void *sendTo)
{
  return 0;
}

void SetEndAngleToleranceMsg::printMe()
{
      printf( "\tSetEndAngleToleranceMsg\n");
}

int SetEndPointToleranceMsg::process(void *sendTo)
{
  ((RosInf*)sendTo)->setEndPointTolerance(tolerance);
  return 0;
}

void SetEndPointToleranceMsg::printMe()
{
      printf( "\tSetEndPointToleranceMsg\n");
}

int SetIntermediatePointToleranceMsg::process(void *sendTo)
{
  return 0;
}

void SetIntermediatePointToleranceMsg::printMe()
{
      printf( "\tSetIntermediatePointToleranceMsg\n");
}

int SetLengthUnitsMsg::process(void *sendTo)
{
  ((RosInf*)sendTo)->setLengthUnits(unitName);
  return 0;
}

void SetLengthUnitsMsg::printMe()
{
      printf( "\tSetLengthUnitsMsg\n");
}

int SetRelativeAccelerationMsg::process(void *sendTo)
{
  return 0;
}

void SetRelativeAccelerationMsg::printMe()
{
      printf( "\tSetRelativeAccelerationMsg\n");
}

int SetRelativeSpeedMsg::process(void *sendTo)
{
  return 0;
}

void SetRelativeSpeedMsg::printMe()
{
      printf( "\tSetRelativeSpeedMsg\n");
}

int StartObjectScanMsg::process(void *sendTo)
{
  ((RosInf*)sendTo)->searchPart(objectName);
  return 0;
}

void StartObjectScanMsg::printMe()
{
      printf( "\tStartObjectScanMsg\n");
}

int StopMotionMsg::process(void *sendTo)
{
	((RosInf*)sendTo)->stopMotion();
	return 0;
}

void StopMotionMsg::printMe()
{
      printf( "\tStopMotionMsg\n");
}

int StopObjectScanMsg::process(void *sendTo)
{
	ROS_ERROR("STOP SCAN!");
	((RosInf*)sendTo)->stopSearch();
	return 0;
}

void StopObjectScanMsg::printMe()
{
      printf( "\tStopObjectScanMsg\n");
}
