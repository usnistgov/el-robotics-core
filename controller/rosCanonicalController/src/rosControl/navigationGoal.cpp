#include <cstdio>
#include <sstream>
#include <string>
#include "navigationGoal.hh"
#include "robotDescription.hh"
/**
  \brief Sets the goal position with respect to the goal frame
  
  See updateGoalTransformation() for information on how this function is used
*/
void NavigationGoal::movePosition(float xGoal, float yGoal, float zGoal)
{
	controlOffset = false;
	goalPosition = tf::Vector3(xGoal, yGoal, zGoal);
}
/**
  \brief Sets the goal position of the arm as an offset from the current position
  
  See updateGoalTransformation() for information on how this function is used
*/
void NavigationGoal::moveOffset(float xGoal, float yGoal, float zGoal)
{
	controlOffset = true;
	goalPosition = tf::Vector3(xGoal, yGoal, zGoal);
}
/**
  \brief Sets the orientation of the goal point, using roll pitch yaw
  
  See updateGoalTransformation() for information on how this function is used.
*/
void NavigationGoal::moveOrientation(float roll, float pitch, float yaw)
{
	goalOrientation.setRPY(roll, pitch, yaw);
	originalOrientation = goalOrientation;
}
/**
  \brief Sets the orientation of the goal point, using a quaternion
  
  See updateGoalTransformation() for information on how this function is used.
*/
void NavigationGoal::moveOrientation(float x, float y, float z, float w)
{
	goalOrientation = tf::Quaternion(x,y,z,w);
	originalOrientation = goalOrientation;
}
/**
	\brief Constructor.
*/
NavigationGoal::NavigationGoal()
{
	listenerPtr = NULL;
	goal.motion_plan_request.goal_constraints.position_constraints.resize(1);
	goal.motion_plan_request.goal_constraints.orientation_constraints.resize(1);
	
	goal.motion_plan_request.planner_id = std::string("");
	goal.planner_service_name = std::string("ompl_planning/plan_kinematic_path");

	goal.motion_plan_request.num_planning_attempts = 5;
	goal.motion_plan_request.allowed_planning_time = ros::Duration(10.0);
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].weight = 1.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].weight = 1.0; // was 0
	
	setPositionFrameType("global");
	setOrientationFrameType(COORDORIENT);
	setGlobalFrame("/odom");
}
/**
	\brief Configures the goal for a particular actuator
	\return 1 on success, 0 on failure
	 
*/
int NavigationGoal::setupActuator()
{
	ros::NodeHandle nh;
	std::string robotDescription;
	urdf::Model robotModel;
	std::string baseLink;
	if(RobotDescription::getPlanningInfo(actName, tipLink, baseLink))
	{
	  RobotDescription::getJointNames(tipLink, baseLink, jointNames);
	}
	else
	{
		ROS_ERROR("Could not find a planning group to control! Make sure your robot is active and arm navigation is running.");
		return 0;
	}
	goal.motion_plan_request.group_name = actName;
	goal.motion_plan_request.num_planning_attempts = 2;
	goal.motion_plan_request.allowed_planning_time = ros::Duration(10.0);
	
	if(!goal.motion_plan_request.goal_constraints.position_constraints.empty())
	{
	  goal.motion_plan_request.goal_constraints.position_constraints[0].weight = 1.0;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].weight = 1.0;
	
	
	  goal.motion_plan_request.goal_constraints.position_constraints[0].link_name = tipLink;
	  goal.motion_plan_request.goal_constraints.position_constraints[0].header.frame_id = tipLink;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].link_name = tipLink;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.frame_id = tipLink;
	} else {
	  ROS_WARN("Attempting to adjust pose on a NavigationGoal with no pose goal! This will have no effect.");
	}
	//control arm tip by default
	targetPointFrame = actName + "_tip";
	setPositionFrameType("global");
	setOrientationFrameType(COORDORIENT);
	return 1;
}

void NavigationGoal::setPositionFrameType(const std::string& frame)
{

	if(frame == "global")
	    useGlobalPositionFrame = true;
	else if(frame == "local")
		useGlobalPositionFrame = false;
	else
		ROS_WARN("Did not recognize frame type \"%s\"", frame.c_str());
}
void NavigationGoal::setOrientationFrameType(const std::string& frame)
{
	if(frame == "global")
		useGlobalOrientationFrame = true;
	else if(frame == "local")
		useGlobalOrientationFrame = false;
	else
		ROS_WARN("Did not recognize frame type \"%s\"", frame.c_str());
}
void NavigationGoal::setGlobalFrame(const std::string& frame)
{
  globalFrame = frame;
}
/**
	\brief Set the frame to specify the position of the target point in.
	
	Due to what seems to be a bug in the ROS \c move_arm stack, this should always be set to match the frame of the tip link of the planning group being controlled. For instance, if the KR60 arm is being controlled, the target point frame should be set to \c KR60Arm_link6.
*/
void NavigationGoal::setTargetPointFrame(std::string targetPointFrameIn)
{
	targetPointFrame = targetPointFrameIn;
}
/**
	\brief Sets the orientation of the goal to the identity
*/
void NavigationGoal::resetOrientation()
{
  if(!goal.motion_plan_request.goal_constraints.orientation_constraints.empty())
  {
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.x = 0.0;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.y = 0.0;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.z = 0.0;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.w = 1.0;
	} else {
	  ROS_WARN("Attempting to adjust pose on a NavigationGoal with no pose goal! This will have no effect.");
	}
}
/**
	\brief Set the goal tolerance
	\param tolerance the size of the tolerance box
	
	This method sets the goal position tolerance to a cube, using the parameter as the length, width, and height
*/
void NavigationGoal::setPositionTolerance(double tolerance)
{
  if(!goal.motion_plan_request.goal_constraints.position_constraints.empty())
  {
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.type = arm_navigation_msgs::Shape::BOX;
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.dimensions.push_back(tolerance);
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.dimensions.push_back(tolerance);
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.dimensions.push_back(tolerance);
	
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.x = 0.0;
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.y = 0.0;
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.z = 0.0;
	  goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.w = 1.0;
	} else {
	  ROS_WARN("Attempting to adjust pose on a NavigationGoal with no pose goal! This will have no effect.");
	}
}
/**
	\brief Set the goal orientation tolerance
	\param tolerance The roll, pitch, and yaw tolerance, in radians
*/
void NavigationGoal::setOrientationTolerance(double tolerance)
{
  if(!goal.motion_plan_request.goal_constraints.orientation_constraints.empty())
  {
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_roll_tolerance = tolerance;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_pitch_tolerance = tolerance;
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_yaw_tolerance = tolerance;
	} else {
	  ROS_WARN("Attempting to adjust pose on a NavigationGoal with no pose goal! This will have no effect.");
	}
}
std::string NavigationGoal::getActName()
{
	return actName;
}

tf::Vector3 NavigationGoal::getGoalPosition()
{
  return goalPosition;
}

tf::Quaternion NavigationGoal::getGoalOrientation()
{
  return goalOrientation;
}
/**
	\brief Get the arm navigation goal object
	
	\return A MoveArmGoal ROS message representing the internal state of this object
	
	This method updates the internal representation of the arm goal and returns a message that can be sent out on an actionserver to control the arm.
*/
arm_navigation_msgs::MoveArmGoal NavigationGoal::getGoal()
{
	if(!goal.motion_plan_request.goal_constraints.position_constraints.empty())
	{
		tf::StampedTransform tipTransform;
		tf::StampedTransform targetPointTransform;
		tf::Transform globalGoalTransform;
		
		getTransforms(tipTransform, targetPointTransform);
		globalGoalTransform = getGlobalGoalTransform(tipTransform, targetPointTransform);
		
	  updateGoalTransformation(tipTransform, targetPointTransform, globalGoalTransform);
	  goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.stamp = ros::Time::now();
	  goal.motion_plan_request.goal_constraints.position_constraints[0].header.stamp = ros::Time::now();
	  
	  //if start and goal state are reasonably close, set path orientation constraints to match goal orientation
	  /*tf::Quaternion rotDiff = (tipTransform * targetPointTransform).inverseTimes(globalGoalTransform).getRotation();
	  //angle here was picked pretty arbitrarily
	  if(rotDiff.getAngle() < 0.05)
	  {
			goal.motion_plan_request.path_constraints.orientation_constraints.resize(1);
			goal.motion_plan_request.path_constraints.orientation_constraints[0] = goal.motion_plan_request.goal_constraints.orientation_constraints[0];
	  	goal.motion_plan_request.path_constraints.orientation_constraints[0].absolute_roll_tolerance = 3.14;
	  	goal.motion_plan_request.path_constraints.orientation_constraints[0].absolute_pitch_tolerance = 3.14;
	  	goal.motion_plan_request.path_constraints.orientation_constraints[0].absolute_yaw_tolerance = 3.14;
	  }
	  else
	  {
	  	goal.motion_plan_request.path_constraints.orientation_constraints.clear();
	  }*/
	}
	return goal;
}
/**
  \brief Clear all position/orientation constraints on the goal
  
  This method should be called when intending to create a joint goal. 
*/
void NavigationGoal::clearPoseConstraints()
{
  goal.motion_plan_request.goal_constraints.orientation_constraints.clear();
  goal.motion_plan_request.goal_constraints.position_constraints.clear();
}
/**
  \brief Add a vector of joint goals
  \param jointNames Names of the target joints
  \param jointPositions Target angles for the joints, in radians
  
  clearPoseConstraints() should be called after directly setting joint goals, or IK may fail for 6DOF arms.
*/
void NavigationGoal::setJointConstraint(std::vector<double> jointPositions)
{
  if(jointNames.size () == jointPositions.size ())
  {
    for(unsigned int i = 0;i<jointNames.size(); i++)
    {
      arm_navigation_msgs::JointConstraint constraint;
      constraint.joint_name = jointNames[i];
      constraint.position = jointPositions[i];
      constraint.tolerance_above = 0.001;
      constraint.tolerance_below = 0.001;
      goal.motion_plan_request.goal_constraints.joint_constraints.push_back(constraint);
    }
  }
}
/**
	\brief Sets the tf transform listener to \a listenerPtrIn
	
	ROS encourages the use of a single tf transformation listener accross a single node, so the transformation listener used by a navigation goal must be set externally. 
*/
void NavigationGoal::setTransformListener(tf::TransformListener *listenerPtrIn)
{
	listenerPtr = listenerPtrIn;
}
/**
	\brief Update the internal representation of the goal point
	\param tipTransform global transform for the tip frame
	\param targetPointTransform transform from the tip frame to the target point frame
	\param globalGoalTransform global goal transformation
	
	The ROS arm_navigation package does not appear to function properly when the goal point for the arm is specified in anything other than the local coordinate frame of the tip link. This causes a problem when goal points are given in the global coordinate frame (which can be specified by setting the position or orientation frame type to "global").
	
	The NavigationGoal class solves this problem by converting points from the global coordinate frame to the local frame, when appropriate. Given the global transforms for the arm tip and the arm target point, the internal goal is converted to the local tip frame.
	
	This method will need to be called immediately before the arm goal is sent to the move_arm actionserver if the location of the arm tip has changed since the goal was created, since the local goal that was computed is no longer valid. For this reason, it is automatically called whenever a goal message is retrieved from the NavigationGoal object.
*/
void NavigationGoal::updateGoalTransformation(const tf::StampedTransform &tipTransform, const tf::StampedTransform &targetPointTransform, const tf::Transform &globalGoalTransform)
{
	tf::Transform goalTransform;

	goalTransform = tipTransform.inverseTimes(globalGoalTransform) * targetPointTransform.inverse();
	if(!goal.motion_plan_request.goal_constraints.position_constraints.empty())
	{
	  tf::pointTFToMsg(goalTransform.getOrigin(), goal.motion_plan_request.goal_constraints.position_constraints[0].position);
	  tf::quaternionTFToMsg(goalTransform.getRotation(), goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation);
	} else {
	  ROS_WARN("Attempting to adjust pose on a NavigationGoal with no pose goal! This will have no effect.");
	}
}
/**
	\brief get the transformations for the tip frame and target point frame
	\param tipTransform value to hold the global tip transformation
	\param targetPointTransform value to hold transformation from tip to target
	\return \c true if the tf listener succeeded, \c false otherwise
	
	This method listens on the tf topic for the transformations it returns.
*/
bool NavigationGoal::getTransforms(tf::StampedTransform &tipTransform, tf::StampedTransform &targetPointTransform)
{
	try
	{
		listenerPtr->waitForTransform(targetPointFrame, globalFrame ,ros::Time(0), ros::Duration(10.0));
		listenerPtr->lookupTransform(globalFrame, tipLink, ros::Time(0), tipTransform);
		listenerPtr->lookupTransform(tipLink, targetPointFrame, ros::Time(0), targetPointTransform);
	}catch(tf::TransformException ex)
	{
		return false;
	}
	return true;
}
/**
	\brief Get the global goal transformation, if the goal is not already in global coordinates
	\param tipTransform global transform for the tip frame
	\param targetPointTransform transform from the tip frame to the target point frame
	
	\return the goal transformation in frame \c globalFrame
*/
tf::Transform NavigationGoal::getGlobalGoalTransform(const tf::StampedTransform &tipTransform, const tf::StampedTransform &targetPointTransform)
{
	tf::Transform globalGoalTransform;
	
	if(useGlobalOrientationFrame)
		globalGoalTransform.setRotation(goalOrientation);
	else
	{
		globalGoalTransform.setRotation((tipTransform * targetPointTransform * tf::Transform(goalOrientation)).getRotation());
	}
	if(!controlOffset)
		globalGoalTransform.setOrigin(goalPosition);
	else
	{
		if(useGlobalPositionFrame)
			globalGoalTransform.setOrigin((tipTransform * targetPointTransform).getOrigin() + goalPosition);
		else
		{
			tf::Transform localGoalTransform = targetPointTransform;
			localGoalTransform.setOrigin(targetPointTransform.getOrigin() + goalPosition);
			globalGoalTransform.setOrigin((tipTransform * localGoalTransform).getOrigin());
		}
	}
	return globalGoalTransform;
}
/**
	\brief rotate the goal by a fixed angle about a random axis
	
	The goal rotated is the original goal provided by the user. Subsequent calls to this method will continue to adjust the original goal (that is, the adjustments will not be composed).
*/
void NavigationGoal::nudgeGoalOrientation()
{
	double x = ((double)rand())/RAND_MAX * 2.0 - 1.0;
	double y = ((double)rand())/RAND_MAX * 2.0 - 1.0;
	double z = ((double)rand())/RAND_MAX * 2.0 - 1.0;
	//double angle = ((double)rand())/RAND_MAX * 2.0 - 1.0;
	//anything less than about this seems to have no effect on success rate? Uncertain.
	double angle = 0.2;
	double n = 1/sqrt(x*x + y*y + z*z);
	x = x*n;
	y = y*n;
	z = z*n;
	tf::Quaternion nudgeQuat(tf::Vector3(x,y,z), angle);
	goalOrientation = originalOrientation * nudgeQuat;	
}
