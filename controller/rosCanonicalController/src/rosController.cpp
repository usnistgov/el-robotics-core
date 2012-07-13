#include <stdio.h>
#include "rosInf.hh"
#include <Vector.h>
#include <Point.h>
#include <tf/transform_datatypes.h>

void CloseGripperMsg::process(void* sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
    printf("Received CloseGripper msg, setting all effector goal states to CLOSE\n");
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::CLOSE;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
  	((RosInf*)sendTo)->waitForEffectors(); // could set a timeout here
  }
}

void DwellMsg::process(void* sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
	  printf( "Received dwell message of time: %lf\n", time );
	  usleep((int)(time*1000000));
  }
  printf("dwell");
}

void EndCanonMsg::process(void* sendTo)
{
  if(sendTo != NULL)
  {
  	((RosInf*)sendTo)->shutDown();
  }
  ros::shutdown();
  printf( "Received endCanon message reason: %d\n", reason );
}

void InitCanonMsg::process(void* sendTo)
{
	if(sendTo != NULL)
	{
		((RosInf*)sendTo)->init();
	}
	printf("initcanon\n");
}

void MessageMsg::process(void* sendTo)
{
  printf( "Received Message msg\n" );
}
void MoveThroughToMsg::process(void* sendTo)
{
  printf( "Received MoveSmoothlyTo msg\n" );
}
void MoveStraightToMsg::process(void* sendTo)
{
  printf( "Received MoveStraightTo msg\n" );
}
void MoveToMsg::process(void* sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
  	printf( "Received MoveTo msg\n" );
	
	tf::Vector3 xAxis(poseLocation->gethasPoseLocation_XAxis()->gethasVector_I(), 
	  				poseLocation->gethasPoseLocation_XAxis()->gethasVector_J(),
	  				poseLocation->gethasPoseLocation_XAxis()->gethasVector_K());
	tf::Vector3 zAxis(poseLocation->gethasPoseLocation_ZAxis()->gethasVector_I(), 
					poseLocation->gethasPoseLocation_ZAxis()->gethasVector_J(),
					poseLocation->gethasPoseLocation_ZAxis()->gethasVector_K());
	//find equivalent quaternion for x/z vectors
	tf::Vector3 xRotationAxis(0, -1*xAxis.z(),xAxis.y()); //cross product of target point x axis and (1,0,0)
	float xAngle = acos(xAxis.x());
	if(xRotationAxis.length() == 0) //if target point x axis is parallel to world x
	{
		xRotationAxis = tf::Vector3(0,1,0); //rotate either pi or 0 about y axis
	}
	tf::Transform xTransform(tf::Quaternion(xRotationAxis, xAngle));
	tf::Vector3 transformedZ = xTransform*tf::Vector3(0,0,1);
	float zAngle = acos(transformedZ.dot(zAxis));
	tf::Transform zTransform(tf::Quaternion(tf::Vector3(1.0,0.0,0.0), zAngle));
	tf::Transform axisTransform = xTransform*zTransform;
	
	((RosInf*)sendTo)->waitForArmGoal(poseLocation->gethasPoseLocation_Point()->gethasPoint_X(),
							poseLocation->gethasPoseLocation_Point()->gethasPoint_Y(),
							poseLocation->gethasPoseLocation_Point()->gethasPoint_Z(),
							axisTransform.getRotation().x(),
							axisTransform.getRotation().y(),
							axisTransform.getRotation().z(),
							axisTransform.getRotation().w());
  }

}
void OpenGripperMsg::process(void* sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
    printf("Received OpenGripper msg, setting all effector goal states to OPEN\n");
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::OPEN;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_GRIPPER);
  	((RosInf*)sendTo)->waitForEffectors(); // could set a timeout here
  }
}

void SetAbsoluteAccelerationMsg::process(void* sendTo)
{
  printf( "Received SetAbsoluteAcceleration msg\n" );
}

void SetAngleUnitsMsg::process(void* sendTo)
{
  printf( "Received SetAngleUnits msg\n" );
}

void SetEndAngleToleranceMsg::process(void* sendTo)
{
  printf( "Received SetEndAngleTolerance msg\n" );
}

void SetEndPointToleranceMsg::process(void* sendTo)
{
  ((RosInf*)sendTo)->setEndPointTolerance(tolerance);
}

void SetIntermediatePointToleranceMsg::process(void* sendTo)
{
  printf( "Received SetIntermediatePointTolerance msg\n" );
}

void SetLengthUnitsMsg::process(void* sendTo)
{
  ((RosInf*)sendTo)->setLengthUnits(unitName);
}

void SetRelativeAccelerationMsg::process(void* sendTo)
{
  printf( "Received SetRelativeAcceleration msg\n" );
}

void SetRelativeSpeedMsg::process(void* sendTo)
{
  printf( "Received SetRelativeSpeed msg\n" );
}

void SetAbsoluteSpeedMsg::process(void *sendTo)
{
  printf( "Received SetAbsoluteSpeed msg\n" );
}

void OpenToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
    printf("Received OpenGripper msg, setting all effector goal states to OPEN\n");
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::OPEN;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
  	((RosInf*)sendTo)->waitForEffectors(); // could set a timeout here
  }
}

void CloseToolChangerMsg::process(void *sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
    printf("Received CloseGripper msg, setting all effector goal states to CLOSE\n");
    usarsim_inf::EffectorCommand command;
    command.state = usarsim_inf::EffectorCommand::CLOSE;
  	((RosInf*)sendTo)->setEffectorGoal(command, ROS_INF_TOOLCHANGER);
  	((RosInf*)sendTo)->waitForEffectors(); // could set a timeout here
  }
}

