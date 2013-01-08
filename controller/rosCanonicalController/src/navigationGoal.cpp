#include <cstdio>
#include <sstream>
#include <string>

#include "navigationGoal.hh"

void NavigationGoal::movePosition(float xGoal, float yGoal, float zGoal)
{
	controlOffset = false;
	goalPosition = tf::Vector3(xGoal, yGoal, zGoal);
}
void NavigationGoal::moveOffset(float xGoal, float yGoal, float zGoal)
{
	controlOffset = true;
	goalPosition = tf::Vector3(xGoal, yGoal, zGoal);
}
void NavigationGoal::moveOrientation(float roll, float pitch, float yaw)
{
	goalOrientation.setRPY(roll, pitch, yaw);
}
void NavigationGoal::moveOrientation(float x, float y, float z, float w)
{
	goalOrientation = tf::Quaternion(x,y,z,w);
}

NavigationGoal::NavigationGoal()
{
	listenerPtr = NULL;
	goal.motion_plan_request.goal_constraints.position_constraints.resize(1);
	goal.motion_plan_request.goal_constraints.orientation_constraints.resize(1);
	
	goal.motion_plan_request.planner_id = std::string("");
	goal.planner_service_name = std::string("ompl_planning/plan_kinematic_path");

	goal.motion_plan_request.num_planning_attempts = 1;
	goal.motion_plan_request.allowed_planning_time = ros::Duration(10.0);
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].weight = 1.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].weight = 0.0;
	
	setPositionFrameType("global");
	setOrientationFrameType("local");
}
int NavigationGoal::setupActuator()
{
	ros::NodeHandle nh;
	XmlRpc::XmlRpcValue planningGroups;
	if(nh.getParam("robot_description_planning/groups", planningGroups))
	{
		ROS_ASSERT(planningGroups.getType() == XmlRpc::XmlRpcValue::TypeArray);
		//just control the first planning group found
		if(planningGroups.size() > 0)
		{
			ROS_ASSERT(planningGroups[0]["name"].getType() == XmlRpc::XmlRpcValue::TypeString);
			actName = static_cast<std::string>(planningGroups[0]["name"]);
			tipLink = static_cast<std::string>(planningGroups[0]["tip_link"]);
		}
		else
		{
			ROS_ERROR("Could not find a planning group to control! Make sure your robot is active and arm navigation is running.");
			return 0;
		}
	}else
	{
		ROS_ERROR("Could not find a planning group to control! Make sure your robot is active and arm navigation is running.");
		return 0;
	}
	goal.motion_plan_request.group_name = actName;
	goal.motion_plan_request.num_planning_attempts = 2;
	goal.motion_plan_request.allowed_planning_time = ros::Duration(10.0);
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].weight = 1.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].weight = 1.0;
	
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].link_name = tipLink;
	goal.motion_plan_request.goal_constraints.position_constraints[0].header.frame_id = tipLink;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].link_name = tipLink;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.frame_id = tipLink;
	//control arm tip by default
	targetPointFrame = actName + "_tip";
	setPositionFrameType("global");
	setOrientationFrameType("local");
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
void NavigationGoal::setTargetPointFrame(std::string targetPointFrameIn)
{
	targetPointFrame = targetPointFrameIn;
}
void NavigationGoal::resetOrientation()
{
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.x = 0.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.y = 0.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.z = 0.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation.w = 1.0;
}

void NavigationGoal::setPositionTolerance(double tolerance)
{
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.type = arm_navigation_msgs::Shape::BOX;
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.dimensions.push_back(tolerance);
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.dimensions.push_back(tolerance);
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_shape.dimensions.push_back(tolerance);
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.x = 0.0;
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.y = 0.0;
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.z = 0.0;
	goal.motion_plan_request.goal_constraints.position_constraints[0].constraint_region_orientation.w = 1.0;
	
}

void NavigationGoal::setOrientationTolerance(double tolerance)
{
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_roll_tolerance = tolerance;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_pitch_tolerance = tolerance;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_yaw_tolerance = tolerance;
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

arm_navigation_msgs::MoveArmGoal NavigationGoal::getGoal()
{
	updateGoalTransformation();
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.stamp = ros::Time::now();
	goal.motion_plan_request.goal_constraints.position_constraints[0].header.stamp = ros::Time::now();
	return goal;
}

void NavigationGoal::setTransformListener(tf::TransformListener *listenerPtrIn)
{
	listenerPtr = listenerPtrIn;
}

void NavigationGoal::updateGoalTransformation()
{
	tf::StampedTransform tipTransform;
	tf::StampedTransform targetPointTransform;
	tf::Transform globalGoalTransform;
	tf::Transform goalTransform;
	try
	{
		listenerPtr->waitForTransform(targetPointFrame,"/odom",ros::Time(0), ros::Duration(10.0));
		listenerPtr->lookupTransform("/odom", tipLink, ros::Time(0), tipTransform);
		listenerPtr->lookupTransform(tipLink, targetPointFrame, ros::Time(0), targetPointTransform);
	}catch(tf::TransformException ex)
	{
	}
	
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
	goalTransform = tipTransform.inverseTimes(globalGoalTransform) * targetPointTransform.inverse();
	tf::pointTFToMsg(goalTransform.getOrigin(), goal.motion_plan_request.goal_constraints.position_constraints[0].position);
	tf::quaternionTFToMsg(goalTransform.getRotation(), goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation);
}

