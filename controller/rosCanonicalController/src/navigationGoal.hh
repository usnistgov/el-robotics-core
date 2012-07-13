#ifndef __navigationGoal__
#define __navigationGoal__

#include <ros/ros.h>
#include <arm_navigation_msgs/MoveArmAction.h>
#include <tf/transform_listener.h>

enum frame_type
{
	GLOBAL=0,
	LOCAL
};

class NavigationGoal
{
public:
	NavigationGoal();
	~NavigationGoal(){};
	void setActuatorName(const std::string &actuatorName);
	void movePosition(float xGoal, float yGoal, float zGoal);
	void moveOffset(float xGoal, float yGoal, float zGoal);
	void moveOrientation(float roll, float pitch, float yaw);
	void moveOrientation(float x, float y, float z, float w);
	void setTipOffset(float x, float y, float z);
	void setPositionFrameType(const std::string& frame);
	void setOrientationFrameType(const std::string& frame);
	void resetOrientation();
	void setPositionTolerance(double tolerance);
	void setOrientationTolerance(double tolerance);
	arm_navigation_msgs::MoveArmGoal getGoal();
private:
	tf::TransformListener listener;
	arm_navigation_msgs::MoveArmGoal goal;
	bool useGlobalPositionFrame, useGlobalOrientationFrame;
	std::string effectorFrame;
	void setGlobalPositionGoal(float xGoal, float yGoal, float zGoal);
};

#endif
