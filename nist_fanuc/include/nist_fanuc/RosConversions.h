

#pragma once
namespace NIST
{

inline void getRPY(const geometry_msgs::Quaternion &qmsg, double &roll, double &pitch, double &yaw)
{
  geometry_msgs::Pose pose;
  pose.orientation = qmsg;
  tf::Pose tf_pose;
  tf::poseMsgToTF(pose, tf_pose);
  tf_pose.getBasis().getRPY(roll,pitch,yaw);
}


};
