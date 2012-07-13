#include <cstdio>
#include <sstream>
#include <string>

#include "navigationGoal.hh"

void NavigationGoal::movePosition(float xGoal, float yGoal, float zGoal)
{
	setGlobalPositionGoal(xGoal, yGoal, zGoal);
}
void NavigationGoal::moveOffset(float xGoal, float yGoal, float zGoal)
{
	if(useGlobalPositionFrame)
	{
		tf::StampedTransform effectorTransform;
		try
		{
			listener.waitForTransform("/odom",effectorFrame,ros::Time(0), ros::Duration(10.0));
			listener.lookupTransform("/odom",effectorFrame,ros::Time(0),effectorTransform);
		}catch(tf::TransformException ex)
		{
		}
		tf::Vector3 globalPoint(xGoal, yGoal, zGoal);
		globalPoint += effectorTransform.getOrigin();
		setGlobalPositionGoal(globalPoint.x(),globalPoint.y(),globalPoint.z());
	}else
	{
		goal.motion_plan_request.goal_constraints.position_constraints[0].position.x = xGoal;
		goal.motion_plan_request.goal_constraints.position_constraints[0].position.y = yGoal;
		goal.motion_plan_request.goal_constraints.position_constraints[0].position.z = zGoal;
	}
}
void NavigationGoal::moveOrientation(float roll, float pitch, float yaw)
{
	tf::Quaternion quat;
	quat.setRPY(roll, pitch, yaw);
	tf::quaternionTFToMsg(quat, goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation);
}
void NavigationGoal::moveOrientation(float x, float y, float z, float w)
{
	tf::quaternionTFToMsg(tf::Quaternion(x,y,z,w), 
		goal.motion_plan_request.goal_constraints.orientation_constraints[0].orientation);
}

NavigationGoal::NavigationGoal()
{
	std::stringstream linkSStream;	
	
	goal.motion_plan_request.goal_constraints.position_constraints.resize(1);
	goal.motion_plan_request.goal_constraints.orientation_constraints.resize(1);
	
	goal.motion_plan_request.planner_id = std::string("");
	goal.planner_service_name = std::string("ompl_planning/plan_kinematic_path");
	
	
	goal.motion_plan_request.num_planning_attempts = 1;
	goal.motion_plan_request.allowed_planning_time = ros::Duration(10.0);
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].weight = 1.0;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].weight = 0.0;
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].target_point_offset.x = 0;
	goal.motion_plan_request.goal_constraints.position_constraints[0].target_point_offset.y = 0;
	goal.motion_plan_request.goal_constraints.position_constraints[0].target_point_offset.z = 0;
	
	setPositionFrameType("global");
	setOrientationFrameType("local");
}
void NavigationGoal::setActuatorName(const std::string &actuatorName)
{
	effectorFrame = actuatorName + "_tip";
	
	goal.motion_plan_request.group_name = actuatorName;
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].link_name = effectorFrame;
	goal.motion_plan_request.goal_constraints.position_constraints[0].header.frame_id = effectorFrame;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].link_name = effectorFrame;
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
	{
		useGlobalOrientationFrame = true;
		goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.frame_id = "/base_link";
	}
	else if(frame == "local")
	{
		useGlobalOrientationFrame = false;
		goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.frame_id = effectorFrame;
	}	
	else
		ROS_WARN("Did not recognize frame type \"%s\"", frame.c_str());
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

void NavigationGoal::setTipOffset(float x, float y, float z)
{
	goal.motion_plan_request.goal_constraints.position_constraints[0].target_point_offset.x = x;
	goal.motion_plan_request.goal_constraints.position_constraints[0].target_point_offset.y = y;
	goal.motion_plan_request.goal_constraints.position_constraints[0].target_point_offset.z = z;
}

void NavigationGoal::setOrientationTolerance(double tolerance)
{
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_roll_tolerance = tolerance;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_pitch_tolerance = tolerance;
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].absolute_yaw_tolerance = tolerance;
}
arm_navigation_msgs::MoveArmGoal NavigationGoal::getGoal()
{
	goal.motion_plan_request.goal_constraints.orientation_constraints[0].header.stamp = ros::Time::now();
	goal.motion_plan_request.goal_constraints.position_constraints[0].header.stamp = ros::Time::now();
	return goal;
}

void NavigationGoal::setGlobalPositionGoal(float xGoal, float yGoal, float zGoal)
{
	tf::StampedTransform transform;
	try
	{
		listener.waitForTransform("/odom",effectorFrame,ros::Time(0), ros::Duration(10.0));
		listener.lookupTransform(effectorFrame,"/odom",ros::Time(0),transform);
	}catch(tf::TransformException ex)
	{
	}
	tf::Vector3 goalPoint = transform*tf::Vector3(xGoal, yGoal, zGoal);
	
	goal.motion_plan_request.goal_constraints.position_constraints[0].position.x = goalPoint.x();
	goal.motion_plan_request.goal_constraints.position_constraints[0].position.y = goalPoint.y();
	goal.motion_plan_request.goal_constraints.position_constraints[0].position.z = goalPoint.z();
}

