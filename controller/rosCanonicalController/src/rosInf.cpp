#include "rosInf.hh"
#define INCH_TO_METER 0.0254
RosInf::RosInf()
{
	initialized = false;
	effectorAttached = false;
	armGoals.clear();
	moveArmClient = NULL;
	lengthUnits = "mm";
	positionTolerance = 0.01;//(meters)
}
RosInf::~RosInf()
{
	if(moveArmClient != NULL)
		delete moveArmClient;
}
bool RosInf::checkCommandDone()
{	
	return armGoals.empty();
}
bool RosInf::isInitialized()
{
	return initialized;
}
void RosInf::shutDown()
{
  if(initialized)
  {
	  initialized = false;
	  if(moveArmClient != NULL)
	  {
		  delete moveArmClient;
		  moveArmClient = NULL;
	  }
  }
}
double RosInf::getSensorFOV()
{
	if(hasObjectSensor)
	{
		waitForObjectSensor();
		return objectSensorFOV;
	}
	else
	{
		ROS_WARN("Called getSensorFOV on a robot without an object sensor, returning 0");
		return 0;
	}
}
bool RosInf::init()
{
	initialized = false;
	if(initArmNavigation() &&
		initEffectors() &&
		initSensors())
	{
		initialized = true;
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
	NavigationGoal armGoal;
	armGoal.setupActuator();
	moveArmClient = new actionlib::SimpleActionClient<arm_navigation_msgs::MoveArmAction>("move_"+armGoal.getActName(), true);
	if(moveArmClient->waitForServer(ros::Duration(10.0)))
	{
		ROS_INFO("Connected to navigation server.");
		return 1;
	}
	else
	{
		ROS_ERROR("InitCanon failed: could not connect to arm navigation server");
		return 0;
	}
}
int RosInf::initEffectors()
{
	ros::master::V_TopicInfo topics;
	bool foundEffector = false;
	effectorControllers.clear();
	
	ROS_DEBUG("Searching for effector topics...");
	ros::master::getTopics(topics);	
	for(unsigned int i = 0;i<topics.size();++i)
	{
		if(topics[i].datatype == "usarsim_inf/EffectorStatus")
		{
			ROS_DEBUG("Found status topic %s, subscribing.",topics[i].name.c_str());
			effectorControllers.push_back(EffectorController());
			effectorControllers.back().initGripperSubscriber(topics[i].name);
			foundEffector = true;
		}else if(topics[i].datatype == "usarsim_inf/ToolchangerStatus")
		{
			ROS_DEBUG("Found status topic %s, subscribing.",topics[i].name.c_str());
			effectorControllers.push_back(EffectorController());
			effectorControllers.back().initToolchangerSubscriber(topics[i].name);
			foundEffector = true;
		}
	}
	if(foundEffector)
		waitForEffectors();
	return 1;
}
int RosInf::initSensors()
{
	ros::master::V_TopicInfo topics;
	ros::NodeHandle nh;
	hasObjectSensor = false;
	ROS_INFO("Searching for object sensor topic...");
	ros::master::getTopics(topics);	
	for(unsigned int i = 0;i<topics.size();++i)
	{
		if(topics[i].datatype == "usarsim_inf/SenseObject")
		{
			ROS_DEBUG("Found status topic %s, subscribing.",topics[i].name.c_str());
			objectSensorSub = nh.subscribe(topics[i].name, 10, &RosInf::objectSensorCallback, this);
			hasObjectSensor = true;
		}
	}
	if(hasObjectSensor)
		waitForObjectSensor();
	return 1;
}

void RosInf::objectSensorCallback(const usarsim_inf::SenseObjectConstPtr &msg)
{
	objectSensorInitialized = true;
	objectSensorFOV = msg->fov;
	if(!findPartNames.empty() && !msg->object_names.empty())
	{
		for(unsigned int i = 0;i<msg->object_names.size();i++)
		{
			std::vector<std::string>::iterator position = std::find(findPartNames.begin(), findPartNames.end(), msg->object_names[i]);
			if(position != findPartNames.end())
			{
				printf("FOUND PART: %s  xyz %f, %f, %f rot %f, %f, %f, %f\n",(*position).c_str(), 
				msg->object_poses[i].position.x,
				msg->object_poses[i].position.y,
				msg->object_poses[i].position.z,
				msg->object_poses[i].orientation.x,
				msg->object_poses[i].orientation.y,
				msg->object_poses[i].orientation.z,
				msg->object_poses[i].orientation.w);
				findPartNames.erase(position);
				
				//TODO: cancel arm navigation
				//update the SQL database
			}
		}
		if(findPartNames.empty())
		{
			armGoals.erase(armGoals.begin() + 1, armGoals.end());//clear everything except for the current goal
			printf("Cleared findpartnames\n");
		}
	}
}

void RosInf::searchPart(std::string partName)
{
	//if the part name isn't already in the list of parts being looked for, add it
	if(findPartNames.empty() || std::find(findPartNames.begin(), findPartNames.end(), partName) == findPartNames.end())
	{
		findPartNames.push_back(partName);
	}
}

void RosInf::stopSearch()
{
	findPartNames.clear();
}

void RosInf::setEndPointTolerance(double tolerance)
{
	//always use meters internally
	if(lengthUnits == "meter")
		positionTolerance = tolerance;
	else if(lengthUnits == "mm")
		positionTolerance = tolerance * .001;
	else if(lengthUnits == "inch")
		positionTolerance = tolerance * INCH_TO_METER;
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
	  		if(!effectorControllers[i].isPublished())
	  		{
	  			effectorsSet = false;
	  		}
	  		else 
	  		{
	  			//active effector is always the last one discovered
	  			effectorAttached = true;
	  			activeEffectorName = effectorControllers[i].goalState.header.frame_id;
	  			if(effectorControllers[i].currentState.state != effectorControllers[i].goalState.state)
	  			{
		  			effectorControllers[i].goalState.header.stamp = ros::Time::now();
		  			effectorControllers[i].publisher.publish(effectorControllers[i].goalState);
		  			effectorsSet = false;
	  			}
	  		}
		}
		ros::spinOnce(); //need to spin so that callbacks are called even though this blocks
	}while(!effectorsSet);
	ROS_DEBUG("All effectors are in their goal state.");
}

void RosInf::navigationDoneCallback(const actionlib::SimpleClientGoalState &state, const arm_navigation_msgs::MoveArmResultConstPtr &result)
{
	ROS_DEBUG("Arm navigation goal complete: %s",state.toString().c_str());
	armGoals.pop_front();
	if(!armGoals.empty())
	{
		moveArmClient->sendGoal(armGoals.front().getGoal(), boost::bind(&RosInf::navigationDoneCallback, this, _1, _2));
	}
}

void RosInf::addArmGoal(double x, double y, double z, double xRot, double yRot, double zRot, double wRot)
{
	NavigationGoal nextGoal;
	
	nextGoal.setupActuator();
	nextGoal.setTransformListener(&listener);
	
	nextGoal.setPositionFrameType("global");
	nextGoal.setOrientationFrameType("global");
	nextGoal.setPositionTolerance(positionTolerance);
	nextGoal.setOrientationTolerance(0.04);
	
	if(effectorAttached)
		nextGoal.setTargetPointFrame(activeEffectorName);
	
	nextGoal.movePosition(x,y,z);
	nextGoal.moveOrientation(xRot, yRot, zRot, wRot);
	
	
	armGoals.push_back(nextGoal);
	if(armGoals.size() == 1) // if there were no goals in the queue already, send this one immediately
	{
		moveArmClient->sendGoal(nextGoal.getGoal(), boost::bind(&RosInf::navigationDoneCallback, this, _1, _2));
	}
}
void RosInf::addArmGoal(double x,  double y, double z, double xAxisX, double xAxisY, double xAxisZ, double zAxisX,
  	double zAxisY, double zAxisZ)
{
	tf::Vector3 xAxis(xAxisX, xAxisY, xAxisZ);
	tf::Vector3 zAxis(zAxisZ, zAxisY, zAxisZ);
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
	addArmGoal(x,y,z, axisTransform.getRotation().x(),
					   axisTransform.getRotation().y(),
					   axisTransform.getRotation().z(),
					   axisTransform.getRotation().w());
	
}

void RosInf::waitForObjectSensor()
{
	while(!objectSensorInitialized)
	{
		ros::spinOnce();
		ros::Duration(0.1).sleep();
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
bool EffectorController::isPublished()
{
	return published;
}
