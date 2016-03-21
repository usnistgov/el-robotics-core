

#pragma once

#include "RCS.h"
#include "Globals.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
/**
 * \brief The IKinematics provides is an abstract class with pure virtual functions that are
 * overriden by actual kinematic implementations.
 * */
class IKinematics {
public:
    virtual std::vector<double> GetJointValues() = 0;
    virtual void SetJointValues(std::vector<double> joint_values) = 0;
    virtual urdf::Pose FK(std::vector<double> jv) = 0;
    virtual std::vector<double> IK(RCS::Pose & pose,
            std::vector<double> oldjoints) = 0;
    virtual size_t AllPoseToJoints(RCS::Pose & pose,
            std::vector<std::vector<double> > & newjoints) = 0;
    virtual std::vector<double> NearestJoints(
            std::vector<double> oldjoints,
            std::vector<std::vector<double> > & newjoints) = 0;
    // THis is a dummy for now

    virtual void Init(
            std::string groupname,
            std::string eelinkname) {
    }


};
typedef boost::shared_ptr<IKinematics> IKinematicsSharedPtr;

class DummyKinematics : public IKinematics {
public:

    virtual std::vector<double> GetJointValues() {
        std::vector<double> joints = ToVector<double>(6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        return joints;
    }

    virtual void SetJointValues(std::vector<double> joint_values) {
    }

    virtual urdf::Pose FK(std::vector<double> jv) {
        return urdf::Pose();
    }

    virtual std::vector<double> IK(RCS::Pose & pose,
            std::vector<double> oldjoints) {
        std::vector<std::vector<double> > newjoints;
        size_t solutions = AllPoseToJoints(pose, newjoints);
        assert(solutions > 0);
        return NearestJoints(oldjoints, newjoints);

    }

    virtual size_t AllPoseToJoints(RCS::Pose & pose,
            std::vector<std::vector<double> > & newjoints) {
        newjoints.push_back(ToVector<double>(6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
        return 1;
    }

    virtual std::vector<double> NearestJoints(
            std::vector<double> oldjoints,
            std::vector<std::vector<double> > & newjoints) {
        assert(newjoints.size() > 0);
        return newjoints[0];
    }

};
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/robot_model/joint_model_group.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <ros/console.h>
#include <ros/init.h>
#include <ros/node_handle.h>
#include <ros/param.h>
#include <ros/rate.h>
#include <rosconsole/macros_generated.h>
#include <sensor_msgs/JointState.h>
#include <shape_msgs/SolidPrimitive.h>
#include <std_msgs/Header.h>


typedef moveit::planning_interface::MoveItErrorCode RosErrorCode;

class RosKinematics : public IKinematics {
public:
    RosKinematics();
    virtual void Init(
            std::string groupname,
            std::string eelinkname);
    virtual std::vector<double> GetJointValues();
    void SetJointValues(std::vector<double> joint_values);
    virtual urdf::Pose FK(std::vector<double> jv);
    virtual std::vector<double> IK(RCS::Pose & pose,
            std::vector<double> oldjoints);
    bool SatisfiesBounds();
    void EnforceBounds();

    virtual size_t AllPoseToJoints(RCS::Pose & pose,
            std::vector<std::vector<double> > & newjoints) {
        newjoints.push_back(ToVector<double>(6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
        return 1;
    }

    virtual std::vector<double> NearestJoints(
            std::vector<double> oldjoints,
            std::vector<std::vector<double> > & newjoints) {
        assert(newjoints.size() > 0);
        return newjoints[0];
    }

    robot_model::RobotModelPtr kinematic_model;
    robot_state::RobotStatePtr kinematic_state;
    robot_state::JointModelGroup* joint_model_group;
    std::vector<double> joint_values;
    std::vector<std::string> joint_names;
    std::string _groupname;
    std::string _eelinkname;
    //ros::NodeHandle &node;
    bool _bInit;
    boost::mutex kinmutex;
};

class MoveitKinematics : public IKinematics {
public:
    MoveitKinematics(ros::NodeHandle &nh);
    virtual std::vector<double> GetJointValues();
    virtual void SetJointValues(std::vector<double> joint_values);
    virtual urdf::Pose FK(std::vector<double> jv);
    virtual std::vector<double> IK(RCS::Pose & pose,
            std::vector<double> oldjoints);

    virtual size_t AllPoseToJoints(RCS::Pose & pose,
            std::vector<std::vector<double> > & newjoints) {
        return 0;
    }

    virtual std::vector<double> NearestJoints(
            std::vector<double> oldjoints,
            std::vector<std::vector<double> > & newjoints) {
        return std::vector<double>();
    }
    virtual void Init(
            std::string groupname,
            std::string eelinkname);
    /////////////////////////////////////////
    boost::shared_ptr<moveit::planning_interface::MoveGroup> group;
    robot_model::RobotModelPtr kinematic_model;
    robot_state::RobotStatePtr kinematic_state;
    robot_state::JointModelGroup* joint_model_group;
    std::vector<double> joint_values;
    std::vector<std::string> joint_names;
    std::string _groupname;
    std::string _eelinkname;
    ros::NodeHandle &_nh;
    bool _bInit;
    boost::mutex kinmutex;
};