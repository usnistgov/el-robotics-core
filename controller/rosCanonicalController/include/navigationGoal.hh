#ifndef __navigationGoal__
#define __navigationGoal__

#include "ros/ros.h"
#include "arm_navigation_msgs/MoveArmAction.h"
#include "tf/transform_listener.h"

#define COORDORIENT "global"
enum frame_type
{
	GLOBAL=0,
	LOCAL
};
/**
	\class NavigationGoal navigationGoal.hh
	\brief Wrapper class with helper methods for a MoveArmGoal message
	
	This class consists of an arm_navigation_msgs::MoveArmGoal message, and functions for initializing and manipulating it. The constructor checks the ROS parameter server (robot_description_planning/groups) for the name of the arm to control. When the getGoal() function is called, before returning the MoveArmGoal message, the object checks the current state of the arm to convert the goal pose to the correct coordinate system (since poses may be given to the arm either globally or locally).
*/
class NavigationGoal
{
public:
	NavigationGoal();
	~NavigationGoal(){};
	int setupActuator();
	void movePosition(float xGoal, float yGoal, float zGoal);
	void moveOffset(float xGoal, float yGoal, float zGoal);
	void moveOrientation(float roll, float pitch, float yaw);
	void moveOrientation(float x, float y, float z, float w);
	void setPositionFrameType(const std::string& frame);
	void setOrientationFrameType(const std::string& frame);
	void setGlobalFrame(const std::string& frame);
	void resetOrientation();
	void setPositionTolerance(double tolerance);
	void setOrientationTolerance(double tolerance);
	void setTargetPointFrame(std::string targetPointFrameIn);
	void setTransformListener(tf::TransformListener *listenerPtrIn);
	arm_navigation_msgs::MoveArmGoal getGoal();
	std::string getActName();
  tf::Vector3 getGoalPosition();
  tf::Quaternion getGoalOrientation();
private:
	tf::TransformListener *listenerPtr;
	arm_navigation_msgs::MoveArmGoal goal;
	bool useGlobalPositionFrame, useGlobalOrientationFrame;
	bool controlOffset;
	std::string actName;
	std::string targetPointFrame;
	std::string tipLink;
	std::string globalFrame;
	tf::Vector3 goalPosition;
	tf::Quaternion goalOrientation;
	void updateGoalTransformation();
};

#endif
