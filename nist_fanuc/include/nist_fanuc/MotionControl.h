

#pragma once
// Motion control

#include <string>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <actionlib/client/simple_action_client.h>
#include "RCS.h"
/**
* \brief MotionControl is a class that contains some useful motion control methods.
*/
class MotionControl {
public:
	/*!
	* \brief executeTrajectory will send a traject to ros to execute
	* \param trajectory 
	* \param trajectory_ns namespace of trajectory
	*\return boolean whether success or failure
	*/
    bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory, const std::string& trajectory_ns);

	/*!
	* \brief AtGoal will determine if a pair joint state values are equal (within an epsilon tolerance).
	* \param goal description of goal joint state 
	* \param current description of current joint state 
	* \param epsilon tolerance of equality
	*\return boolean whether robot is at the desired goal described in joint values.
	*/
    static bool AtGoal(JointState goal, JointState current, double epsilon = 0.001);

	/*!
	* \brief Return linear interpolation (lerp) between current and goal translation.
	* \param _curPos description of current pose 
	* \param _goalPos description of goal pose
	* \param dIncrement  translation amount from [0..1]
	* \return pose containing lerped pose translation.
	*/
    RCS::Pose computeTranslation(RCS::Pose & _curPos, RCS::Pose & _goalPos, double dIncrement);

	/*!
	* \brief Compute  waypoints between current and goal poses with assigned distance between poses.
	* \param _curPos description of current pose 
	* \param _goalPos description of goal pose
	* \param gap  distance between waypoints
	* \param bAddStart  boolean to determine if starting pose is included in waypoints
	* \return vector of waypoint poses with gap distance between poses.
	*/
    std::vector<RCS::Pose> computeWaypoints(RCS::Pose & _curPos, RCS::Pose & _goalPos, double dGap = 0.001, bool bAddStart = false);

	/*!
	* \brief computeCoorindatedWaypoints returns a vector of straightline waypoints between current and goal poses at a given distance.
	* Joints arrive a destination at the same time within the trajectory.
	* \param _curPos description of current pose 
	* \param _goalPos description of goal pose
	* \param gap  distance between waypoints
	* \param bAddStart  boolean to determine if starting pose is included in waypoints
	* \return vector of straighline waypoint poses with gap distance between poses.
	*/
    std::vector<JointState > computeCoorindatedWaypoints(std::vector<double> & _curJts, std::vector<double> & _goalJts, double dGap = 0.001, bool bAddStart = false);

	/*!
	* \brief computeUncoorindatedWaypoints returns a vector of waypoints between current and goal poses at a given distance.
	* Joints arrive a destination at various times in the trajectory.
	* \param _curPos description of current pose 
	* \param _goalPos description of goal pose
	* \param gap  distance between waypoints
	* \param bAddStart  boolean to determine if starting pose is included in waypoints
	* \return vector of straighline waypoint poses with gap distance between poses.
	*/
    std::vector<JointState > computeUncoorindatedWaypoints(std::vector<double> & _curJts, std::vector<double> & _goalJts, double dGap = 0.001, bool bAddStart = false);
    //////////////////////////
    static double epsilon; /**< allowable difference length in equality between two numbers */

    int computeIncrements(std::vector<double> & _curJts, std::vector<double> & _goalJts, double gap = 0.001); // 0.001=mm
    int computeIncrements(RCS::Pose & _curPos, RCS::Pose & _goalPos, double dGap = 0.001);

};
