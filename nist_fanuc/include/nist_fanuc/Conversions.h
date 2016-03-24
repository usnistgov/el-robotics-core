

#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "urdf_model/tfmath.h"

#include "geometry_msgs/PoseStamped.h"
#include "RCS.h"

RCS::Pose              GeomMsgPose2UrdfPose(const geometry_msgs::Pose &m);
geometry_msgs::Pose     UrdfPose2GeomMsgPose(const  RCS::Pose  &m);
Eigen::Affine3d         GeomMsgPose2Affine3d(const geometry_msgs::Pose &m);
geometry_msgs::Pose     PoseAffineToGeomMsg(const Eigen::Affine3d &e);
RCS::Pose              Affine3d2UrdfPose(const  Eigen::Affine3d &pose);
Eigen::Affine3d         UrdfPose2Affine3d(const RCS::Pose &pose);

std::vector<geometry_msgs::Pose>     UrdfPoses2PoseMsgs(const  std::vector<RCS::Pose>  &src);
std::vector<RCS::Pose>     PoseMsgs2UrdfPoses(const  std::vector<geometry_msgs::Pose>  &src);
std::vector<Eigen::Affine3d>     PoseMsgs2AffEigenPoses(const  std::vector<geometry_msgs::Pose>  &src);
std::vector<geometry_msgs::Pose>     AffEigenPoses2PoseMsgs(const  std::vector<Eigen::Affine3d>  &src);
//JointState     Vector2JointState(const  std::vector<double>  &src);

inline JointState     JntPosVector2JointState(const  std::vector<double>  &src)
{
    JointState joints;
    joints.position=src;
    joints.velocity.resize(src.size(), 0.0);
    joints.effort.resize(src.size(), 0.0);
    return joints;
}

