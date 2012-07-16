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
  printf("dwell\n");
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
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
  	for(int i = 0;i<num;i++)
  	{
  		((RosInf*)sendTo)->waitForArmGoal(poseLocations[i]->gethasPoseLocation_Point()->gethasPoint_X(),
							poseLocations[i]->gethasPoseLocation_Point()->gethasPoint_Y(),
							poseLocations[i]->gethasPoseLocation_Point()->gethasPoint_Z(),
							poseLocations[i]->gethasPoseLocation_XAxis()->gethasVector_I(),
							poseLocations[i]->gethasPoseLocation_XAxis()->gethasVector_J(),
							poseLocations[i]->gethasPoseLocation_XAxis()->gethasVector_K(),
							poseLocations[i]->gethasPoseLocation_ZAxis()->gethasVector_I(), 
							poseLocations[i]->gethasPoseLocation_ZAxis()->gethasVector_J(),
							poseLocations[i]->gethasPoseLocation_ZAxis()->gethasVector_K());
	}	
  }
}
void MoveStraightToMsg::process(void* sendTo)
{
  printf( "Received MoveStraightTo msg\n" );
}
void MoveToMsg::process(void* sendTo)
{
  if(sendTo != NULL && ((RosInf*)sendTo)->isReady())
  {
  	((RosInf*)sendTo)->waitForArmGoal(poseLocation->gethasPoseLocation_Point()->gethasPoint_X(),
							poseLocation->gethasPoseLocation_Point()->gethasPoint_Y(),
							poseLocation->gethasPoseLocation_Point()->gethasPoint_Z(),
							poseLocation->gethasPoseLocation_XAxis()->gethasVector_I(),
							poseLocation->gethasPoseLocation_XAxis()->gethasVector_J(),
							poseLocation->gethasPoseLocation_XAxis()->gethasVector_K(),
							poseLocation->gethasPoseLocation_ZAxis()->gethasVector_I(), 
							poseLocation->gethasPoseLocation_ZAxis()->gethasVector_J(),
							poseLocation->gethasPoseLocation_ZAxis()->gethasVector_K());
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

