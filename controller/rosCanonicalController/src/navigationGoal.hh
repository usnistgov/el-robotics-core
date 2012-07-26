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
	int setupActuator();
	void movePosition(float xGoal, float yGoal, float zGoal);
	void moveOffset(float xGoal, float yGoal, float zGoal);
	void moveOrientation(float roll, float pitch, float yaw);
	void moveOrientation(float x, float y, float z, float w);
	void setPositionFrameType(const std::string& frame);
	void setOrientationFrameType(const std::string& frame);
	void resetOrientation();
	void setPositionTolerance(double tolerance);
	void setOrientationTolerance(double tolerance);
	void setTargetPointFrame(std::string targetPointFrameIn);
	void setTransformListener(tf::TransformListener *listenerPtrIn);
	arm_navigation_msgs::MoveArmGoal getGoal();
	std::string getActName();
private:
	tf::TransformListener *listenerPtr;
	arm_navigation_msgs::MoveArmGoal goal;
	bool useGlobalPositionFrame, useGlobalOrientationFrame;
	bool controlOffset;
	std::string actName;
	std::string targetPointFrame;
	std::string tipLink;
	tf::Vector3 goalPosition;
	tf::Quaternion goalOrientation;
	void updateGoalTransformation();
};

#endif
