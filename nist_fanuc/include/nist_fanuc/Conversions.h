

#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "geometry_msgs/PoseStamped.h"
#include "urdf_model/eigenmath.h"
#include "urdf_model/rosmath.h"
#include "RCS.h"

urdf::Pose              PoseMsg2UrdfPose(const geometry_msgs::Pose &m);
geometry_msgs::Pose     UrdfPose2PoseMsg(const  urdf::Pose  &m);
Eigen::Affine3d         PoseMsgToEigenAffine(const geometry_msgs::Pose &m);
geometry_msgs::Pose     poseEigenToGeomMsg(const Eigen::Affine3d &e);

std::vector<geometry_msgs::Pose>     UrdfPoses2PoseMsgs(const  std::vector<urdf::Pose>  &src);
std::vector<urdf::Pose>     PoseMsgs2UrdfPoses(const  std::vector<geometry_msgs::Pose>  &src);
std::vector<Eigen::Affine3d>     PoseMsgs2AffEigenPoses(const  std::vector<geometry_msgs::Pose>  &src);
std::vector<geometry_msgs::Pose>     AffEigenPoses2PoseMsgs(const  std::vector<Eigen::Affine3d>  &src);
JointState     Vector2JointState(const  std::vector<double>  &src);

inline JointState     JntPosVector2JointState(const  std::vector<double>  &src)
{
    JointState joints;
    joints.position=src;
    joints.velocity.resize(src.size(), 0.0);
    joints.effort.resize(src.size(), 0.0);
    return joints;
}

inline urdf::Pose PoseMsg2UrdfPose(const geometry_msgs::Pose &m) {
    urdf::Pose p;
    p.position.x = m.position.x;
    p.position.y = m.position.y;
    p.position.z = m.position.z;
    p.rotation.x = m.orientation.x;
    p.rotation.y = m.orientation.y;
    p.rotation.z = m.orientation.z;
    p.rotation.w = m.orientation.w;
    return p;
}

inline geometry_msgs::Pose UrdfPose2PoseMsg(const  urdf::Pose  &m) {
    geometry_msgs::Pose p;
    p.position.x = m.position.x;
    p.position.y = m.position.y;
    p.position.z = m.position.z;
    p.orientation.x = m.rotation.x;
    p.orientation.y = m.rotation.y;
    p.orientation.z = m.rotation.z;
    p.orientation.w = m.rotation.w;
    return p;
}

inline Eigen::Affine3d PoseMsgToEigenAffine(const geometry_msgs::Pose &m) {
    Eigen::Affine3d e = Eigen::Translation3d(m.position.x,
            m.position.y,
            m.position.z) *
            Eigen::Quaterniond(m.orientation.w,
            m.orientation.x,
            m.orientation.y,
            m.orientation.z);
    return e;
}

inline geometry_msgs::Pose poseEigenToGeomMsg(const Eigen::Affine3d &e) {
    geometry_msgs::Pose m;
    m.position.x = e.translation().x();
    m.position.y = e.translation().y();
    m.position.z = e.translation().z();
    MatrixEXd em = e.rotation();
    Eigen::Quaterniond q = EMatrix2Quaterion(em);
    m.orientation.x = q.x();
    m.orientation.y = q.y();
    m.orientation.z = q.z();
    m.orientation.w = q.w();
#if 0
    if (m.orientation.w < 0) {
        m.orientation.x *= -1;
        m.orientation.y *= -1;
        m.orientation.z *= -1;
        m.orientation.w *= -1;
    }
#endif
}

//------------------------------------------------
// vector conversions
inline std::vector<geometry_msgs::Pose>     UrdfPoses2PoseMsgs(const  std::vector<urdf::Pose>  &src)
{
    std::vector<geometry_msgs::Pose> dest;
    dest.resize(src.size());                         
    std::transform (src.begin(), src.end(), dest.begin(), UrdfPose2PoseMsg);
}
inline std::vector<urdf::Pose>     PoseMsgs2UrdfPoses(const  std::vector<geometry_msgs::Pose>  &src)
{
    std::vector<urdf::Pose> dest;
    dest.resize(src.size());                         
    std::transform (src.begin(), src.end(), dest.begin(), PoseMsg2UrdfPose);
}
inline std::vector<Eigen::Affine3d>     PoseMsgs2AffEigenPoses(const  std::vector<geometry_msgs::Pose>  &src)
{
    std::vector<Eigen::Affine3d> dest;
    dest.resize(src.size());                         
    std::transform (src.begin(), src.end(), dest.begin(), PoseMsgToEigenAffine);
}
inline std::vector<geometry_msgs::Pose>     AffEigenPoses2PoseMsgs(const  std::vector<Eigen::Affine3d>  &src)
{
    std::vector<geometry_msgs::Pose> dest;
    dest.resize(src.size());                         
    std::transform (src.begin(), src.end(), dest.begin(), poseEigenToGeomMsg);
}


