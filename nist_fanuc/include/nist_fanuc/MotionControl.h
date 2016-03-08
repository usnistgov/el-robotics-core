

#pragma once
// Motion control

#include <string>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <actionlib/client/simple_action_client.h>
#include "RCS.h"

class MotionControl {
public:
    bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory, const std::string& trajectory_ns);
    static bool AtGoal(JointState goal, JointState current, double epsilon = 0.001);
    urdf::Pose computeTranslation(urdf::Pose & _curPos, urdf::Pose & _goalPos, double dIncrement);
    std::vector<urdf::Pose> computeWaypoints(urdf::Pose & _curPos, urdf::Pose & _goalPos, double dGap = 0.001, bool bAddStart = false);
    std::vector<JointState > computeCoorindatedWaypoints(std::vector<double> & _curJts, std::vector<double> & _goalJts, double dGap = 0.001, bool bAddStart = false);
    std::vector<JointState > computeUncoorindatedWaypoints(std::vector<double> & _curJts, std::vector<double> & _goalJts, double dGap = 0.001, bool bAddStart = false);
    //////////////////////////
    static double epsilon;
    int computeIncrements(std::vector<double> & _curJts, std::vector<double> & _goalJts, double gap = 0.001); // 0.001=mm
    int computeIncrements(urdf::Pose & _curPos, urdf::Pose & _goalPos, double dGap = 0.001);

};
