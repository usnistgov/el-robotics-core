#include "rosInf.hh"
#define INCH_TO_METER 0.0254
RosInf::RosInf()
{
	ready = false;
	moveArmClient = NULL;
	lengthUnits = "meter";
}
RosInf::~RosInf()
{
	if(moveArmClient != NULL)
		delete moveArmClient;
}
bool RosInf::isReady()
{
	return ready;
}
void RosInf::shutDown()
{
  if(ready)
  {
	  ready = false;
	  if(moveArmClient != NULL)
	  {
		  delete moveArmClient;
		  moveArmClient = NULL;
	  }
  }
}
bool RosInf::init()
{
	ready = false;
	if(initArmNavigation() &&
		initEffectors())
	{
		ready = true;
		printf("ROS canonical controller initialized.\n");
		return true;
	}
	return false;
}
void RosInf::setEffectorGoal(const usarsim_inf::EffectorCommand &command, EffectorType type)
{
	for(unsigned int i = 0;i<effectorControllers.size();i++)
  	{
  		if(effectorControllers[i].isType(type))
  			effectorControllers[i].goalState.state = command.state;
  	}
}
int RosInf::initArmNavigation()
{
	ros::NodeHandle nh;
	XmlRpc::XmlRpcValue planningGroups;
	std::string actuatorName;
	if(nh.getParam("robot_description_planning/groups", planningGroups))
	{
		ROS_ASSERT(planningGroups.getType() == XmlRpc::XmlRpcValue::TypeArray);
		//just control the first planning group found
		if(planningGroups.size() > 0)
		{
			ROS_ASSERT(planningGroups[0]["name"].getType() == XmlRpc::XmlRpcValue::TypeString);
			actuatorName = static_cast<std::string>(planningGroups[0]["name"]);
		}
		else
		{
			printf("Could not find a planning group to control! Make sure your robot is active and arm navigation is running.\n");
			return 0;
		}
		
	}else
	{
		printf("Could not find a planning group to control! Make sure your robot is active and arm navigation is running.\n");
		return 0;
	}
	moveArmClient = new actionlib::SimpleActionClient<arm_navigation_msgs::MoveArmAction>("move_"+actuatorName, true);
	
	if(moveArmClient->waitForServer(ros::Duration(10.0)))
	{
		printf("Connected to navigation server.\n");
		armGoal.setActuatorName(actuatorName);
		armGoal.setPositionFrameType("global");
		armGoal.setOrientationFrameType("global");
		armGoal.setPositionTolerance(0.01);
		armGoal.setOrientationTolerance(0.04);
		return 1;
	}
	else
	{
		printf("InitCanon failed: could not connect to arm navigation server\n");
		return 0;
	}
}
int RosInf::initEffectors()
{
	ros::master::V_TopicInfo topics;
	
	effectorControllers.clear();
	
	printf("Searching for effector topics...\n");
	ros::master::getTopics(topics);	
	for(unsigned int i = 0;i<topics.size();++i)
	{
		if(topics[i].datatype == "usarsim_inf/EffectorStatus")
		{
			printf("Found status topic %s, subscribing.\n",topics[i].name.c_str());
			effectorControllers.push_back(EffectorController());
			effectorControllers.back().initGripperSubscriber(topics[i].name);
		}else if(topics[i].datatype == "usarsim_inf/ToolchangerStatus")
		{
			printf("Found status topic %s, subscribing.\n",topics[i].name.c_str());
			effectorControllers.push_back(EffectorController());
			effectorControllers.back().initToolchangerSubscriber(topics[i].name);
		}
	}
	return 1;
}
/*
	block until all effectors have reached their goal state.
*/
void RosInf::waitForEffectors()
{
	bool effectorsSet;
  	do
  	{
  		effectorsSet = true;
	  	for(unsigned int i = 0;i<effectorControllers.size();i++)
	  	{
	  		if(effectorControllers[i].currentState.state != effectorControllers[i].goalState.state)
	  		{
	  			effectorControllers[i].goalState.header.stamp = ros::Time::now();
	  			effectorControllers[i].publisher.publish(effectorControllers[i].goalState);
	  			effectorsSet = false;
	  		}
		}
		ros::spinOnce(); //need to spin so that callbacks are called even though this blocks
	}while(!effectorsSet);
	printf("All effectors are in their goal state.\n");
}
void RosInf::waitForArmGoal(double x, double y, double z, double xRot, double yRot, double zRot, double wRot)
{
	bool finishOnTime = false;
	armGoal.movePosition(x,y,z);
	armGoal.moveOrientation(xRot, yRot, zRot, wRot);
	
	moveArmClient->sendGoal(armGoal.getGoal());
	finishOnTime = moveArmClient->waitForResult(ros::Duration(15.0));
	if(!finishOnTime)
	{
		moveArmClient->cancelGoal();
		printf("Arm navigation goal timed out.");
	}
	else
	{
		//response from server
		actionlib::SimpleClientGoalState state = moveArmClient->getState();
		if(state == actionlib::SimpleClientGoalState::SUCCEEDED)
		{
			printf("Move arm action finished: %s\n",state.toString().c_str());
		}
		else
		{
			printf("Move arm action failed: %s\n",state.toString().c_str());
		}			
	}
}
void RosInf::setLengthUnits(std::string units)
{
	if(units == "inch")
		lengthUnits = "inch";
	else if(units == "mm")
		lengthUnits = "mm";
	else if(units == "meter")
		lengthUnits = "meter";
	else
		printf("Warning: unrecognized length unit \"%s,\" using \"%s\" instead\n", units.c_str(), lengthUnits.c_str());
}
void RosInf::setEndPointTolerance(double tolerance)
{
	if(lengthUnits == "meter")
		armGoal.setPositionTolerance(tolerance);
	else if(lengthUnits == "mm")
		armGoal.setPositionTolerance(tolerance * .001);
	else if(lengthUnits == "inch")
		armGoal.setPositionTolerance(tolerance * INCH_TO_METER);
}
EffectorController::EffectorController()
{	
	published = false;
}
void EffectorController::initGripperSubscriber(const std::string &topicName)
{
	ros::NodeHandle nh;
	type = ROS_INF_GRIPPER;
	subscriber = nh.subscribe(topicName, 10, &EffectorController::gripperCallback, this);
}
void EffectorController::initToolchangerSubscriber(const std::string &topicName)
{
	ros::NodeHandle nh;
	type = ROS_INF_TOOLCHANGER;
	subscriber = nh.subscribe(topicName, 10, &EffectorController::toolchangerCallback, this);
}
bool EffectorController::isType(EffectorType type)
{
	return (this->type == type);
}
void EffectorController::gripperCallback(const usarsim_inf::EffectorStatusConstPtr &msg)
{
	if(!published)
	{
		//if a publisher hasn't already been created for this effector, create one
		printf("Creating effector goal publisher for %s\n",msg->header.frame_id.c_str());
		ros::NodeHandle nh;
		publisher = nh.advertise<usarsim_inf::EffectorCommand>(msg->header.frame_id + "/command", 2);
		published = true;
		goalState.header.frame_id = msg->header.frame_id;
		goalState.state = msg->state;
	}
	currentState.state = msg->state;
}
void EffectorController::toolchangerCallback(const usarsim_inf::ToolchangerStatusConstPtr &msg)
{
	if(!published)
	{
		//if a publisher hasn't already been created for this effector, create one
		printf("Creating effector goal publisher for %s\n",msg->header.frame_id.c_str());
		ros::NodeHandle nh;
		publisher = nh.advertise<usarsim_inf::EffectorCommand>(msg->header.frame_id + "/command", 2);
		published = true;
		goalState.header.frame_id = msg->header.frame_id;
		goalState.state = msg->effector_status.state;
	}
	currentState.state = msg->effector_status.state;
}
