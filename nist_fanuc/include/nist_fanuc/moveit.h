

#include <vector>
#include <boost/shared_ptr.hpp>

#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include "RCS.h"
#include "Globals.h"

#pragma once

class MoveitPlanning {
public:
    MoveitPlanning(ros::NodeHandle &nh);
    ~MoveitPlanning();

    std::vector<JointState> GetJtsPlan();
    bool Plan(JointState curjoints, JointState goaljoints);
    bool Plan(RCS::Pose & curpose, RCS::Pose & goalpose);
    bool Plan(RCS::Pose & pose);
    bool Plan(std::vector<RCS::Pose>& waypoints);

    bool Plan(JointState joints); // assumes robot in correct starting position
    bool Plan(Eigen::Affine3d& pose);
    bool Plan(geometry_msgs::Pose& pose);
    
    bool Plan(JointState curjoints, std::vector<RCS::Pose>& waypoints, double maxstep=0.01);

    RCS::Pose GetCurrentPose();
    std::vector<double> GetJointValues();
    RCS::Pose ForwardKinematics();
    std::vector<double> SetRandomJoints();
    void DisplayPlan();
    void SavePlan();

    boost::shared_ptr<moveit::planning_interface::MoveGroup> GetGroup() {
        return group;
    }

    std::vector<std::string> GetJointNames() {
        return joint_names;
    }

    VAR(NumPlanningAttempts, double);
    VAR(PlanningTime, double);
    VAR(GoalTolerance, double);
    VAR(CartesianInterpolationResolution, double);
    VAR(CartesianJumpThreshold, double);
    
    
    ////////////////////////////////
    moveit::planning_interface::MoveGroup::Plan my_plan;
    boost::shared_ptr<moveit::planning_interface::MoveGroup> group;
    robot_model::RobotModelPtr kinematic_model;
    robot_state::RobotStatePtr kinematic_state;
    robot_state::JointModelGroup * joint_model_group; // bug somewhere
    //moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    std::string _groupname;
    std::vector<std::string> joint_names;
    bool _bInited;
    ros::Publisher display_publisher;
    std::vector<JointState> plannedjts;

};
