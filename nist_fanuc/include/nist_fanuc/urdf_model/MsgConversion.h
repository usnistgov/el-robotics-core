
// DISCLAIMER:
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied
// or intended.

#pragma once
#ifdef STANDALONEURDF
#include "urdf_model/RobotModel.h"
#else
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#endif
#include "urdf_model/rosmath.h"
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>


geometry_msgs::PoseStamped UrdfPose2MsgPose(urdf::Pose pose);

inline geometry_msgs::PoseStamped UrdfPose2MsgPose(urdf::Pose pose)
{
	geometry_msgs::PoseStamped msg ;
	msg.pose.position.x= pose.rotation.x;
	msg.pose.position.y= pose.rotation.y;
	msg.pose.position.z= pose.rotation.z;
	msg.pose.orientation.x= pose.rotation.x;
	msg.pose.orientation.y= pose.rotation.y;
	msg.pose.orientation.z= pose.rotation.z;
	msg.pose.orientation.w= pose.rotation.w;
	return msg;
}