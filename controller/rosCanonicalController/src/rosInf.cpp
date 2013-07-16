#include "rosInf.hh"
#include <stdio.h>


RosInf::RosInf ()
{
  initialized = false;
  effectorAttached = false;
  navigationFailureCount = 0;
  armGoals.clear ();
  moveArmClient = NULL;
  lengthUnits = "mm";
  positionTolerance = 0.015;	//(meters)
  globalFrameName = "/odom";
}

RosInf::~RosInf ()
{
  if (moveArmClient != NULL)
    delete moveArmClient;
}

bool
RosInf::checkCommandDone ()
{
  return armGoals.empty ();
}

bool
RosInf::isInitialized ()
{
  return initialized;
}

void
RosInf::shutDown ()
{
  if (initialized)
    {
      initialized = false;
      if (moveArmClient != NULL)
	{
	  delete moveArmClient;
	  moveArmClient = NULL;
	}
    }
}

double
RosInf::getSensorFOV ()
{
  if (hasObjectSensor)
    {
      waitForObjectSensor ();
      return objectSensorFOV;
    }
  else
    {
      ROS_WARN
	("Called getSensorFOV on a robot without an initialized object sensor, returning 0");
      return 0;
    }
}

bool
RosInf::init ()
{
  initialized = false;
  if (initEffectors () && initArmNavigation () && initSensors ())
    {
      initialized = true;
      ROS_INFO ("ROS canonical controller initialized.\n");
      return true;
    }
  return false;
}
/*
  Set the goal for each effector with the given type to match a state
*/
void
RosInf::setEffectorGoal (const usarsim_inf::EffectorCommand & command,
			 EffectorType type)
{
  for (unsigned int i = 0; i < effectorControllers.size (); i++)
    {
      if (effectorControllers[i].isType (type))
	effectorControllers[i].goalState.state = command.state;
    }
}
/*
  Set the effector with this status topic to match a state.
*/
void 
RosInf::setEffectorGoal(const usarsim_inf::EffectorCommand & command,
	    std::string effectorTopic)
{
  for (unsigned int i = 0;i < effectorControllers.size (); i++) {
    if (effectorControllers[i].getStatusTopic() == effectorTopic)
    {
      effectorControllers[i].goalState.state = command.state;
      break;
    }
  }
}

int
RosInf::initArmNavigation ()
{
  NavigationGoal armGoal;
  armGoal.setupActuator ();
  moveArmClient =
    new actionlib::SimpleActionClient < arm_navigation_msgs::MoveArmAction >
    ("move_" + armGoal.getActName (), true);
  if (moveArmClient->waitForServer (ros::Duration (10.0)))
    {
      ROS_INFO ("Connected to navigation server.");
      return 1;
    }
  else
    {
      ROS_ERROR
	("RosInf::initArmNavigation() failed: could not connect to arm navigation server");
      return 0;
    }
}

int RosInf::initEffectors() {
  ros::master::V_TopicInfo topics;
  
  ROS_INFO ("Updating effector topics...");
  ros::master::getTopics (topics);
  
  unsigned int initEffectorNum = effectorControllers.size();
  effectorControllers.clear();
  
  for (unsigned int i = 0; i < topics.size (); ++i)
  {
    if (topics[i].datatype == "usarsim_inf/EffectorStatus")
    {
      effectorControllers.push_back (EffectorController ());
      effectorControllers.back ().initSubscriber<usarsim_inf::EffectorStatus>(topics[i].name, this, ROS_INF_GRIPPER);
      ROS_INFO ("Found status topic %s, subscribing.",
         topics[i].name.c_str ());
    }
    else if (topics[i].datatype == "usarsim_inf/ToolchangerStatus")
    {
      effectorControllers.push_back (EffectorController ());
      effectorControllers.back ().initSubscriber<usarsim_inf::ToolchangerStatus>(topics[i].name, this, ROS_INF_TOOLCHANGER);
      ROS_INFO ("Found status topic %s, subscribing.",
         topics[i].name.c_str ());
    }
  }
  //this has the potential to misbehave if two effectors are added and removed in the space of a single status message
  //which is unlikely.
  if (initEffectorNum != effectorControllers.size()) { //if an effector was either added or removed
    waitForEffectors ();	//wait for effectors to publish their current state before returning
  }
  ROS_INFO("Effectors initialized.");
  return 1;
}

int
RosInf::initSensors ()
{
  ros::master::V_TopicInfo topics;
  ros::NodeHandle nh;
  hasObjectSensor = false;
  scanActive = false;
  ROS_INFO ("Searching for object sensor topic...");
  ros::master::getTopics (topics);
  for (unsigned int i = 0; i < topics.size (); ++i)
    {
      if (topics[i].datatype == "usarsim_inf/SenseObject")
	{
	  ROS_DEBUG ("Found status topic %s, subscribing.",
		     topics[i].name.c_str ());
	  objectSensorSub =
	    nh.subscribe (topics[i].name, 10, &RosInf::objectSensorCallback,
			  this);
	  hasObjectSensor = true;
	}
    }
  if (hasObjectSensor)
    waitForObjectSensor ();
  return 1;
}

void
RosInf::objectSensorCallback (const usarsim_inf::SenseObjectConstPtr & msg)
{
  FILE *fp = NULL;
  objectSensorInitialized = true;
  objectSensorFOV = msg->fov;
  if (!findPartNames.empty () && !msg->object_names.empty ())
    {
      for (unsigned int i = 0; i < msg->object_names.size (); i++)
	{
	  std::vector < std::string >::iterator position =
	    std::find (findPartNames.begin (), findPartNames.end (),
		       msg->object_names[i]);
	  if (position != findPartNames.end ())
	    {

	      printf ("FOUND PART: %s  xyz %f, %f, %f rot %f, %f, %f, %f\n",
		      (*position).c_str (), msg->object_poses[i].position.x,
		      msg->object_poses[i].position.y,
		      msg->object_poses[i].position.z,
		      msg->object_poses[i].orientation.x,
		      msg->object_poses[i].orientation.y,
		      msg->object_poses[i].orientation.z,
		      msg->object_poses[i].orientation.w);
	      printf ("%s hit location: %f %f %f\n", (*position).c_str (),
		      msg->object_hit_locations[i].position.x,
		      msg->object_hit_locations[i].position.y,
		      msg->object_hit_locations[i].position.z);

	      //TODO: cancel arm navigation and update the mySQL database
	      //for now, write pick up commands to a file.
	      if (fp == NULL)
		fp = fopen ("output_commands.txt", "w");
	      if (fp != NULL)
		{
		  //convert quaternion to x/z axes 
		  tf::Transform partRotation (tf::
					      Quaternion (msg->
							  object_poses[i].
							  orientation.x,
							  msg->
							  object_poses[i].
							  orientation.y,
							  msg->
							  object_poses[i].
							  orientation.z,
							  msg->
							  object_poses[i].
							  orientation.w));
		  tf::Vector3 xAxis = partRotation * tf::Vector3 (1, 0, 0);
		  tf::Vector3 zAxis = partRotation * tf::Vector3 (0, 0, 1);

		  float dropX, dropY;
		  if (msg->object_names[i] == "PartA")
		    {
		      dropX = -0.1;
		      dropY = .35;
		    }
		  else if (msg->object_names[i] == "PartB")
		    {
		      dropX = 0.15;
		      dropY = 0.35;
		    }
		  else
		    {
		      dropX = -0.1;
		      dropY = 2.2;
		    }
		  fprintf (fp,
			   "Dwell(1)\nMoveTo({{%f, %f, %f},{%f, %f, %f},{%f, %f, %f}})\n\
					Dwell(.5)\n\
					CloseGripper()\n\
					MoveThroughTo({{{.12,1.2,-.5}, {0, 0, 1}, {1, 0, 0}},\n\
								   {{%f, %f,-.5}, {0, 0, 1}, {1, 0, 0}},\n\
								   {{%f, %f, 0.1}, {0, 0, 1}, {1, 0, 0}}}, 3)\n\
					Dwell(.5)\n\
					OpenGripper()\n\
					Dwell(.5)\n\
					MoveTo({{.12,1.2,-.6}, {0, 0, 1}, {1, 0, 0}})\n",
			   msg->object_poses[i].position.x, msg->object_poses[i].position.y, msg->object_poses[i].position.z, zAxis.x (), zAxis.y (), zAxis.z (), xAxis.x (), xAxis.y (), xAxis.z (), dropX, dropY, dropX, dropY);
		  fclose (fp);
		}


	      findPartNames.erase (position);


	    }
	}
      if (findPartNames.empty ())
	{
	  armGoals.erase (armGoals.begin () + 1, armGoals.end ());	//clear everything except for the current goal
	  printf ("Cleared findpartnames\n");
	}
    }
}

void
RosInf::searchPart (std::string partName)
{
  scanActive = true;
  //if the part name isn't already in the list of parts being looked for, add it
  if (findPartNames.empty ()
      || std::find (findPartNames.begin (), findPartNames.end (),
		    partName) == findPartNames.end ())
    {
      findPartNames.push_back (partName);
    }
}

void
RosInf::stopMotion ()
{
  armGoals.erase (armGoals.begin () + 1, armGoals.end ());	//clear everything except for the current goal
}

void
RosInf::stopSearch ()
{
  findPartNames.clear ();
  scanActive = false;
}

void
RosInf::setEndPointTolerance (double tolerance)
{
  //always use meters internally
  if (lengthUnits == "meter")
    positionTolerance = tolerance;
  else if (lengthUnits == "mm")
    positionTolerance = tolerance * .001;
  else if (lengthUnits == "inch")
    positionTolerance = tolerance * INCH_TO_METER;
}

/*
	block until all effectors have reached their goal state, or until the timeout is reached
*/
void
RosInf::waitForEffectors ()
{
  bool effectorsSet;
  ros::Time timeout = ros::Time::now() + ros::Duration(EFFECTOR_TIMEOUT);
  do {
    effectorsSet = publishEffectors();
    ros::spinOnce ();		//need to spin so that callbacks are called even though this blocks
  }
  while (!effectorsSet && ros::Time::now() < timeout);
  if(effectorsSet) {
    ROS_DEBUG ("All effectors are in their goal state.");
  } else {
    ROS_WARN("At least one effector timed out on goal!");
  }
  
  //check to see if a new tool was added by the toolchanger
  initEffectors();
}

/*
  publish effector goal states once.
  Return 1 if published state matches goal state for all effectors, 0 otherwise.
*/
int
RosInf::publishEffectors()
{
  bool effectorsSet = true;
  for (unsigned int i = 0; i < effectorControllers.size (); i++) {
    if (!effectorControllers[i].isPublished ()) {
      effectorsSet = false;
    }
    else {
      //active effector is always the last one discovered
      //this should probably actually check to see if effectors have children & then walk up the tf tree
      effectorAttached = true;
      activeEffectorName =
      effectorControllers[i].goalState.header.frame_id;
      if (effectorControllers[i].currentState.state !=
      effectorControllers[i].goalState.state)
      {
        effectorControllers[i].goalState.header.stamp =
        ros::Time::now ();
        effectorControllers[i].publisher.
        publish (effectorControllers[i].goalState);
        effectorsSet = false;
      }
    }
  }
  return effectorsSet;
}

// called whenever arm navigation transitions to Active
void
RosInf::navigationActiveCallback ()
{
  //  printf( "Reached navigationActivateCallback of rosInf.cpp\n" );
}

// called whenever arm navigation gives feedback
void
RosInf::navigationFeedbackCallback (const arm_navigation_msgs::
				    MoveArmFeedbackConstPtr & feedback)
{
  //  printf( "Reached navigationFeedbackCallback of rosInf.cpp time to complete:%f state: %s\n", 
  //	  feedback->time_to_completion.toSec(), feedback->state.c_str() );
}

//called whenever an arm navigation goal is completed
#include <arm_navigation_msgs/convert_messages.h>
void
RosInf::navigationDoneCallback (const actionlib::
				SimpleClientGoalState & state,
				const arm_navigation_msgs::
				MoveArmResultConstPtr & result)
{
  FILE *fp = NULL;
  ROS_DEBUG ("Arm navigation goal complete: %s\n", state.toString ().c_str ());
  tf::Vector3 goalPosition = armGoals.front().getGoalPosition();
  tf::Quaternion goalOrientation = armGoals.front ().getGoalOrientation();
  //tf::Vector3 zAxis = tf::Vector3(0,0,1.0).rotate(goalOrientation.getAxis(), goalOrientation.getAngle());
  if( state == actionlib::SimpleClientGoalState::ABORTED && result->error_code.val != arm_navigation_msgs::ArmNavigationErrorCodes::SUCCESS)
  {
    navigationFailureCount++;
    //      btScalar roll, pitch, yaw;
    //      btMatrix3x3(goalOrientation).getRPY(roll, pitch, yaw );

    ROS_DEBUG ("Arm goal error code: %s on goal <%f %f %f> <%f %f %f %f>\n", 
    arm_navigation_msgs::armNavigationErrorCodeToString(result->error_code).c_str (),
    goalPosition.getX(), goalPosition.getY(), goalPosition.getZ(),
  	      goalOrientation.x(), goalOrientation.y(), goalOrientation.z(), goalOrientation.w());
    if(navigationFailureCount < MAX_NAVIGATION_FAILURES)
    {
      ROS_DEBUG("RosInf: Arm navigation failed to find a solution after %d tries, retrying...", navigationFailureCount);
      moveArmClient->sendGoal (armGoals.front ().getGoal (),
      boost::bind (&RosInf::navigationDoneCallback,
      this, _1, _2));
    } else {
      
      if(LOG_FAILURES) {
        fp = fopen("datfile","a");
        if(fp != NULL) {
          fprintf(fp, "%d\n", navigationFailureCount);
          fclose(fp);
        }
      }
      
      ROS_ERROR("RosInf: Arm navigation failed to complete properly. Normally this results in an exit, but for now we just record and move on.");
      armGoals.pop_front ();
      if (!armGoals.empty ())
      {
      navigationFailureCount = 0;
      moveArmClient->sendGoal (armGoals.front ().getGoal (),
        boost::bind (&RosInf::navigationDoneCallback,
        this, _1, _2));
      }
      
      //ROS_ERROR("RosInf: Arm navigation failed to complete properly.");
      //exit(1);
    }
  }
  else
  {
    tf::Vector3 goalPosition = armGoals.front().getGoalPosition();
    ROS_INFO ("Arm goal succeeded on goal <%f %f %f> <f f f>\n", 
    goalPosition.getX(), goalPosition.getY(), goalPosition.getZ());
    if(LOG_FAILURES) {
      fp = fopen("datfile","a");
        if(fp != NULL) {
          fprintf(fp, "%d\n",navigationFailureCount);
          fclose(fp);
        }
    }
    armGoals.pop_front ();
    if (!armGoals.empty ())
    {
      navigationFailureCount = 0;
      moveArmClient->sendGoal (armGoals.front ().getGoal (),
        boost::bind (&RosInf::navigationDoneCallback,
        this, _1, _2));
      /*
      moveArmClient->sendGoal (armGoals.front ().getGoal (),
        boost::bind (&RosInf::navigationDoneCallback,
        this, _1, _2),
        boost::bind (&RosInf::navigationActiveCallback,
        this),
        boost::bind (&RosInf::navigationFeedbackCallback,
        this, _1));
      */
    }
  }
}

void
RosInf::addArmGoal (double x, double y, double z, double xRot, double yRot,
		    double zRot, double wRot)
{
  NavigationGoal nextGoal;

  if (scanActive && findPartNames.empty ())
    printf
      ("Scan complete, ignoring movement command until scan is stopped\n");
  else
    {
      nextGoal.setupActuator ();
      nextGoal.setTransformListener (&listener);

      nextGoal.setPositionFrameType ("global");
      nextGoal.setOrientationFrameType (COORDORIENT);
      nextGoal.setGlobalFrame(globalFrameName);
      nextGoal.setPositionTolerance (positionTolerance);
      nextGoal.setOrientationTolerance (0.0001);

      if (effectorAttached)
      {
        nextGoal.setTargetPointFrame (activeEffectorName);
      }
      nextGoal.movePosition (x, y, z);
      //      nextGoal.moveOffset (x, y, z);
      nextGoal.moveOrientation (xRot, yRot, zRot, wRot);


      armGoals.push_back (nextGoal);
      if (armGoals.size () == 1)	// if there were no goals in the queue already, send this one immediately
      {
        navigationFailureCount = 0;
        moveArmClient->sendGoal (armGoals.front ().getGoal (),
			         boost::bind (&RosInf::navigationDoneCallback,
					      this, _1, _2));

        /*
        moveArmClient->sendGoal (nextGoal.getGoal (),
			         boost::bind (&RosInf::
					      navigationDoneCallback, this,
					      _1, _2),
			         boost::bind (&RosInf::navigationActiveCallback,
					      this),
			         boost::bind (&RosInf::navigationFeedbackCallback,
					      this, _1));
        */

      }
    }
}

/* this signature calls the above routine */
void
RosInf::addArmGoal (double x, double y, double z, double xAxisX,
		    double xAxisY, double xAxisZ, double zAxisX,
		    double zAxisY, double zAxisZ)
{
  if (scanActive && findPartNames.empty ())
    printf
      ("Scan complete, ignoring movement command until scan is stopped\n");
  else
    {
      tf::Vector3 xAxis (xAxisX, xAxisY, xAxisZ);
      tf::Vector3 zAxis (zAxisX, zAxisY, zAxisZ);
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
      addArmGoal (x, y, z, axisTransform.getRotation ().x (),
		  axisTransform.getRotation ().y (),
		  axisTransform.getRotation ().z (),
		  axisTransform.getRotation ().w ());
    }
}

void
RosInf::waitForObjectSensor ()
{
  while (!objectSensorInitialized)
    {
      ros::spinOnce ();
      ros::Duration (0.1).sleep ();
    }
}

void
RosInf::setLengthUnits (std::string units)
{
  if (units == "inch")
    lengthUnits = "inch";
  else if (units == "mm")
    lengthUnits = "mm";
  else if (units == "meter")
    lengthUnits = "meter";
  else
    ROS_WARN
      ("Warning: unrecognized length unit \"%s,\" using \"%s\" instead\n",
       units.c_str (), lengthUnits.c_str ());
}

void 
RosInf::setGlobalFrame(const std::string &globalFrame)
{
  globalFrameName = globalFrame;
}
/*
  Fill a vector with the list of all effector status topics
*/
void
RosInf::getEffectorStatusNames(std::vector<std::string> &effectorNames)
{
  effectorNames.clear();
  for(unsigned int i = 0;i<effectorControllers.size();i++) {
    effectorNames.push_back(effectorControllers[i].getStatusTopic());
  }
}

template<class M>
void RosInf::effectorCallback(const M & msg, const std::string topicName) {
  ROS_ERROR("RosInf: unknown effector callback on status topic %s",topicName.c_str());
}

template<>
void RosInf::effectorCallback<const usarsim_inf::EffectorStatusConstPtr &>(const usarsim_inf::EffectorStatusConstPtr & msg, const std::string topicName) {
  ROS_DEBUG("getting status message from topic %s",topicName.c_str());
  //find the effector sending status updates to the given topic
  for(unsigned int i = 0;i<effectorControllers.size();i++) {
    if(effectorControllers[i].getStatusTopic() == topicName) {
      effectorControllers[i].gripperCallback (msg);
      return;
    }
  }
  ROS_ERROR("RosInf: effector callback received unexpected status topic %s",topicName.c_str());
}

template<>
void RosInf::effectorCallback<const usarsim_inf::ToolchangerStatusConstPtr &>(const usarsim_inf::ToolchangerStatusConstPtr & msg, const std::string topicName) {
  ROS_DEBUG("getting status message from topic %s",topicName.c_str());
  //find the effector sending status updates to the given topic
  for(unsigned int i = 0;i<effectorControllers.size();i++) {
    if(effectorControllers[i].getStatusTopic() == topicName) {
      effectorControllers[i].toolchangerCallback (msg);
      return;
    }
  }
  ROS_ERROR("RosInf: effector callback received unexpected status topic %s",topicName.c_str());
}

EffectorController::EffectorController ()
{
  published = false;
}

template <class M>
void
EffectorController::initSubscriber (const std::string & topicName, RosInf* const infHandle, EffectorType type)
{
  ros::NodeHandle nh;
  subscriber =
    nh.subscribe <M> (topicName, 
    10, 
    boost::bind(&RosInf::effectorCallback<const boost::shared_ptr< M const >&>, 
      infHandle, 
      _1, 
      topicName));
  this->type = type;
  statusTopic = topicName;
}

bool
EffectorController::isType (EffectorType type)
{
  return (this->type == type);
}
EffectorType EffectorController::getType() {
  return type;
}

void
EffectorController::toolchangerCallback (const usarsim_inf::ToolchangerStatusConstPtr & msg)
{
  if (!published)
    {
      //if a publisher hasn't already been created for this effector, create one
      ROS_INFO ("Creating effector goal publisher for %s\n",
	      msg->header.frame_id.c_str ());
      ros::NodeHandle nh;
      published = true;
      goalState.header.frame_id = msg->header.frame_id;
      goalState.state = msg->effector_status.state;
      
      publisher = nh.advertise < usarsim_inf::EffectorCommand >
      (msg->header.frame_id + "/command", 2);
    }
  currentState.state = msg->effector_status.state;
}

void
EffectorController::gripperCallback (const usarsim_inf::EffectorStatusConstPtr & msg)
{
  if (!published)
    {
      //if a publisher hasn't already been created for this effector, create one
      ROS_INFO ("Creating effector goal publisher for %s\n",
	      msg->header.frame_id.c_str ());
      ros::NodeHandle nh;
      published = true;
      goalState.header.frame_id = msg->header.frame_id;
      goalState.state = msg->state;
      
      publisher = nh.advertise < usarsim_inf::EffectorCommand >
      (msg->header.frame_id + "/command", 2);
    }
  currentState.state = msg->state;
}

bool
EffectorController::isPublished ()
{
  return published;
}
const std::string EffectorController::getStatusTopic () {
  return statusTopic;
}
