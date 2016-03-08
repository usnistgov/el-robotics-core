// RCSInterpreter.cpp

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
#include "CrclConfig.h"
#include "RCSInterpreter.h"
#include "Controller.h"
#include "Globals.h"
#include <algorithm>  // max
#include "urdf_model/eigenmath.h"
#include "Conversions.h"
#include "trajectoryMaker.h"

using namespace RCS;
using namespace descartes_core;
using namespace descartes_trajectory;
using namespace sensor_msgs;

RCSInterpreter::RCSInterpreter(IKinematicsSharedPtr pKinematics) {
    _kinematics = pKinematics; // hopefully can be null
    //    _kinematics = IKinematicsSharedPtr(new DummyKinematics());
    rates = IRate(DEFAULT_CART_MAX_VEL, DEFAULT_CART_MAX_ACCEL, DEFAULT_LOOP_CYCLE);

}

RCSInterpreter::~RCSInterpreter(void) {
}

void RCSInterpreter::AddJointCommands(std::vector<JointState > gotojoints) {
    for (size_t i = 0; i < gotojoints.size(); i++) {
        RCS::CanonCmd newcc;
        newcc.cmd = RCS::CANON_MOVE_JOINT;
        newcc.status = RCS::CANON_WAITING;
        newcc.joints.position = gotojoints[i].position;
#ifdef DEBUG
        std::cout << "New Joint Position " << VectorDump<double>(newcc.joints.position).c_str();
#endif
        newcc.joints.velocity = gotojoints[i].velocity;
        newcc.joints.effort = gotojoints[i].effort;
        Controller.robotcmds.AddMsgQueue(newcc);
    }
}

static JointState EmptyJointState(size_t n) {
    JointState js;
    js.position.resize(n, 0.0);
    js.velocity.resize(n, 0.0);
    js.effort.resize(n, 0.0);
    return js;
}

std::vector<JointState> RCSInterpreter::PlanCartesianMotion(std::vector<urdf::Pose> poses) {
    std::vector<JointState> gotojoints;
    if (poses.size() == 0)
        return gotojoints;
#ifdef DEBUG
    std::cout << "Current Pose " << DumpPose(poses[0]).c_str();
    std::cout << "Goal Pose " << DumpPose(poses[poses.size() - 1]).c_str();

    for (size_t i = 0; i < poses.size(); i++) {
        std::cout << "CartesianMotion  Poses " << DumpPose(poses[i]).c_str();
    }
#endif
    if (RCS::Controller.eCartesianMotionPlanner == RCS::CController::MOVEIT) {
        if (RCS::Controller.MoveitPlanner()->Plan(poses)) {
            gotojoints = RCS::Controller.MoveitPlanner()->GetJtsPlan();
            return gotojoints;
#ifdef DEBUG
            for (size_t k = 0; k < gotojoints.size(); k++) {
                std::cout << VectorDump<double> (gotojoints[k].position);
            }
#endif
        }
    } else // if (RCS::Controller.eCartesianMotionPlanner == RCS::CController::WAYPOINT) {
    {
        std::vector<double> oldjoints = RCS::Controller.status.currentjoints.position;
        for (size_t i = 0; i < poses.size(); i++) {

            //RCS::Controller.Kinematics()->SetJointValues(oldjoints);

            std::vector<double> joints = RCS::Controller.Kinematics()-> IK(poses[i], oldjoints);
            std::cout << "GotoPose " << DumpPose(poses[i]).c_str();
            std::cout << "New Joints " << VectorDump<double>(joints).c_str();
            gotojoints.push_back(EmptyJointState(joints.size()));
            gotojoints.back().position = joints;
            oldjoints = joints;
        }
        return gotojoints;
    }
}

int RCSInterpreter::ParseCommand(RCS::CanonCmd cc) {
    Globals.ErrorMessage("RCSInterpreter::ParseCommand\n");
    //TrajectoryMaker traj;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // MOVE JOINTS
    if (cc.cmd == RCS::CANON_MOVE_JOINT) {
        JointState currentjoints = RCS::Controller.status.currentjoints;
        rates = IRate(DEFAULT_JOINT_MAX_VEL, DEFAULT_JOINT_MAX_ACCEL, DEFAULT_LOOP_CYCLE);

        //std::cout << "Current Joints " << VectorDump<double>(currentjoints.position).c_str();
        std::vector<double> joints;
        joints.insert(joints.begin(),
                currentjoints.position.begin(),
                currentjoints.position.end());

        // Check each joint, to see if joint is being actuated, if so, change goal position
        for (size_t i = 0; i < cc.jointnum.size(); i++) {
            joints[cc.jointnum[i]] = cc.joints.position[i]; // joint numbers already adjusted from CRCL to rcs model
            //std::cout << n << " cc.joints.position[i] " << cc.joints.position[i] << std::endl;
        }
        std::cout << "Updated Joints " << VectorDump<double>(joints).c_str();
        std::vector<JointState > gotojoints;

        if (RCS::Controller.eJointMotionPlanner == RCS::CController::WAYPOINT) {
            gotojoints = motioncontrol.computeCoorindatedWaypoints(currentjoints.position, joints, 0.001, true);
        } else if (RCS::Controller.eJointMotionPlanner == RCS::CController::BASIC) {
            TrajectoryMaker maker;
            maker.Rates().CurrentFeedrate() = rates.MaximumVelocity();
            maker.setRates(rates);
            maker.makeJointPositionTrajectory(rates, currentjoints.position, joints);
            gotojoints = maker.GetJtsPlan();
        } else if (RCS::Controller.eJointMotionPlanner == RCS::CController::MOVEIT) {
            JointState js = JntPosVector2JointState(joints);
            if (!RCS::Controller.MoveitPlanner()->Plan(js))
                return -1;
            gotojoints = RCS::Controller.MoveitPlanner()->GetJtsPlan();
        } else {
            gotojoints = motioncontrol.computeCoorindatedWaypoints(currentjoints.position, joints, 0.001, true);
        }
        AddJointCommands(gotojoints);
    }        ////////////////////////////////////////////////////////////////////////////////////////////////
        // STOP MOTION
    else if (cc.cmd == RCS::CANON_STOP_MOTION) {
        std::vector<std::vector<double> > displacements(Controller.status.currentjoints.velocity.size(), std::vector<double>());
        cc.jointnum.clear();

        // clear motion queue   - we are stopping asap!
        Controller.robotcmds.ClearMsgQueue();
    }////////////////////////////////////////////////////////////////////////////////////////////////
        // MOVE CARTESIAN
    else if (cc.cmd == RCS::CANON_MOVE_TO) {
        rates = IRate(DEFAULT_CART_MAX_VEL, DEFAULT_CART_MAX_ACCEL, DEFAULT_LOOP_CYCLE);
        urdf::Pose goalpose = cc.pose;
        urdf::Pose currentpose = RCS::Controller.status.currentpose;
        std::vector<JointState> gotojoints;
        std::vector<urdf::Pose> poses = motioncontrol.computeWaypoints(RCS::Controller.status.currentpose, goalpose, 0.1, true);
        gotojoints = PlanCartesianMotion(poses);
        AddJointCommands(gotojoints);
    } else if (cc.cmd == RCS::CANON_MOVE_THRU) {
        rates = IRate(DEFAULT_CART_MAX_VEL, DEFAULT_CART_MAX_ACCEL, DEFAULT_LOOP_CYCLE);
        urdf::Pose currentpose = RCS::Controller.status.currentpose;
        std::vector<JointState> gotojoints;
        std::vector<urdf::Pose> poses = cc.waypoints;
        poses.insert(poses.begin(), currentpose); // add beginning pose -again?
        // and in case interrupted
        gotojoints = PlanCartesianMotion(poses);
        AddJointCommands(gotojoints);
    }
    else  if (cc.cmd == RCS::CANON_DWELL) {
        // wait here or at robot command thread?
        // Could just copy over command to robot
        RCS::CanonCmd newcc;
        newcc.cmd = RCS::CANON_DWELL;
        newcc.status = RCS::CANON_WAITING;
        newcc.dwell = cc.dwell;
        Controller.robotcmds.AddMsgQueue(newcc);
    }
    return 0;
}
