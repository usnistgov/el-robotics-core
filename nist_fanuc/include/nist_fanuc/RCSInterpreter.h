//

// RCSInterface.h
//

/*
 * DISCLAIMER:
 * This software was produced by the National Institute of Standards
 * and Technology (NIST), an agency of the U.S. government, and by statute is
 * not subject to copyright in the United States.  Recipients of this software
 * assume all responsibility associated with its operation, modification,
 * maintenance, and subsequent redistribution.
 *
 * See NIST Administration Manual 4.09.07 b and Appendix I.
 */
#pragma once

#include "RCS.h"
#include <vector>
#include "Kinematics.h"
#include "Trajectory.h"
#include "trajectoryMaker.h"
#include "MotionControl.h"


class RCSInterpreter
{
public:
    RCSInterpreter(IKinematicsSharedPtr k = NULL);
    ~RCSInterpreter(void);
    int ParseCommand(RCS::CanonCmd cmd);
    void AddJointCommands(std::vector<JointState > gotojoints);
    std::vector<JointState> PlanCartesianMotion(std::vector<urdf::Pose> poses);

    //////////////////////////////////////////////////
    IKinematicsSharedPtr _kinematics;
    TrajectoryVec results;
    std::vector<double> times;
    IRate rates;
    MotionControl motioncontrol;
 
};
