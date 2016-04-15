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

std::vector<JointState> RCSInterpreter::PlanCartesianMotion(std::vector<RCS::Pose> poses) {
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
#if 1
        if (RCS::Controller.MoveitPlanner()->Plan(poses)) {
            gotojoints = RCS::Controller.MoveitPlanner()->GetJtsPlan();
            return gotojoints;
        }
#else
        // assume first one is where were are already
        for(size_t j=1; j< poses.size(); j++) {
            if (RCS::Controller.MoveitPlanner()->Plan(poses[j-1], poses[j])) {
                std::vector<JointState> intermedjoints;
                intermedjoints = RCS::Controller.MoveitPlanner()->GetJtsPlan();
                gotojoints.insert(gotojoints.end(), intermedjoints.begin(), intermedjoints.end());
            }
        }
#endif
#ifdef DEBUG
        std::cout << "*******CARTESIAN MOVE TO POSE******\n";
        for (size_t k = 0; k < gotojoints.size(); k++) {
            std::cout << VectorDump<double> (gotojoints[k].position);
        }
#endif
        return gotojoints;

    } else // if (RCS::Controller.eCartesianMotionPlanner == RCS::CController::WAYPOINT) {
    {
        std::vector<double> oldjoints = RCS::Controller.status.currentjoints.position;
        for (size_t i = 0; i < poses.size(); i++) {

            //RCS::Controller.Kinematics()->SetJointValues(oldjoints);

            std::vector<double> joints = RCS::Controller.Kinematics()-> IK(poses[i], oldjoints);
#ifdef DEBUG
            std::cout << "GotoPose " << DumpPose(poses[i]).c_str();
            std::cout << "New Joints " << VectorDump<double>(joints).c_str();
#endif
            gotojoints.push_back(EmptyJointState(joints.size()));
            gotojoints.back().position = joints;
            oldjoints = joints;
        }
        return gotojoints;
    }
}

int RCSInterpreter::ParseCommand(RCS::CanonCmd cc) {
    IfDebug(Globals.ErrorMessage("RCSInterpreter::ParseCommand\n"));

    // This approach should debounce multiple commands to same position - e.g., 0->30, 0->30
    JointState currentjoints;
    RCS::Pose currentpose; // = RCS::Controller.status.currentpose;

    //RCS::CanonCmd lastrobotcmd = Controller.GetLastRobotCommand();
    currentjoints = RCS::Controller.GetLastJointState(); //  open loop - "not actual"
    currentpose = RCS::Controller.Kinematics()->FK(currentjoints.position);
#ifdef HEAVYDEBUG
    std::cout << "Current Joints " << VectorDump<double>(currentjoints.position).c_str();
    std::cout << "Current Pose " << DumpPose(currentpose).c_str();
#endif

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // MOVE JOINTS
    if (cc.cmd == RCS::CANON_MOVE_JOINT) {
        rates = IRate(DEFAULT_JOINT_MAX_VEL, DEFAULT_JOINT_MAX_ACCEL, DEFAULT_LOOP_CYCLE);

        JointState joints;
        for (size_t i = 0; i < currentjoints.position.size(); i++) {
            joints.position.push_back(currentjoints.position[i]);
            joints.velocity.push_back(DEFAULT_JOINT_MAX_VEL);
            joints.effort.push_back(DEFAULT_JOINT_MAX_ACCEL);
        }

        std::vector<double> maxvel;
        std::vector<double> maxacc;
        // Check each joint, to see if joint is being actuated, if so, change goal position
        for (size_t i = 0; i < cc.jointnum.size(); i++) {
            size_t n = cc.jointnum[i];
            joints.position[n] = cc.joints.position[n]; // joint numbers already adjusted from CRCL to rcs model
            joints.velocity[n] = cc.joints.velocity[n];
            joints.effort[n] = cc.joints.effort[n];
            maxvel.push_back(cc.joints.velocity[n]);
            maxacc.push_back(cc.joints.effort[n]);
        }
        // not sure what happends if no elements in maxvel or maxacc... - should never happen
        double jointsmaxvel = *(std::min_element(std::begin(maxvel), std::end(maxvel)));
        double jointsmaxacc = *(std::min_element(std::begin(maxacc), std::end(maxacc)));
#ifdef HEAVYDEBUG
        std::cout << "Updated Joints Position " << VectorDump<double>(joints.position).c_str();
        std::cout << "Updated Joints Velocity " << VectorDump<double>(joints.velocity).c_str();
        std::cout << "Updated Joints Effort " << VectorDump<double>(joints.effort).c_str();
#endif
        std::vector<JointState > gotojoints;

        if (RCS::Controller.eJointMotionPlanner == RCS::CController::WAYPOINT) {
            gotojoints = motioncontrol.computeCoorindatedWaypoints(currentjoints.position, joints.position, 0.001, true);
        } else if (RCS::Controller.eJointMotionPlanner == RCS::CController::BASIC) {
            TrajectoryMaker maker;
            maker.Rates().CurrentFeedrate() = jointsmaxvel;
            maker.Rates().MaximumAccel() = jointsmaxacc;
            maker.setRates(rates);
            maker.makeJointPositionTrajectory(rates, currentjoints.position, joints.position);
            gotojoints = maker.GetJtsPlan();
        } else if (RCS::Controller.eJointMotionPlanner == RCS::CController::MOVEIT) {
            if (!RCS::Controller.MoveitPlanner()->Plan(joints))
                return -1;
            gotojoints = RCS::Controller.MoveitPlanner()->GetJtsPlan();
        } else {
            gotojoints = motioncontrol.computeCoorindatedWaypoints(currentjoints.position, joints.position, 0.001, true);
        }
        if(cc.bCoordinated)
        {
            AddJointCommands(gotojoints);
        }
        else
        {
            // uncoordinated motion - 1st 0 joint, then 1 joint motion, etc.
            // unlikely to crash into itself with this joint motion
            for(size_t k=0; k< currentjoints.position.size(); k++)
            {
                JointState  eachjoint;
                eachjoint.position = currentjoints.position;
                eachjoint.position[k]=joints.position[k];
                TrajectoryMaker maker;
                maker.Rates().CurrentFeedrate() = jointsmaxvel;
                maker.Rates().MaximumAccel() = jointsmaxacc;
                maker.setRates(rates);
                maker.makeJointPositionTrajectory(rates, currentjoints.position, eachjoint.position);
                gotojoints = maker.GetJtsPlan();
                AddJointCommands(gotojoints);
            }
        }
    }////////////////////////////////////////////////////////////////////////////////////////////////
        // STOP MOTION
    else if (cc.cmd == RCS::CANON_STOP_MOTION) {
        std::vector<std::vector<double> > displacements(Controller.status.currentjoints.velocity.size(), std::vector<double>());
        cc.jointnum.clear();

        // clear motion queue   - we are stopping asap!
        Controller.robotcmds.ClearMsgQueue();
    }////////////////////////////////////////////////////////////////////////////////////////////////
        // MOVE CARTESIAN
    else if (cc.cmd == RCS::CANON_MOVE_TO) {

        rates = cc.Rates(); // IRate(DEFAULT_CART_MAX_VEL, DEFAULT_CART_MAX_ACCEL, DEFAULT_LOOP_CYCLE);
        RCS::Pose goalpose = cc.pose;
        if (RCS::Controller.Kinematics()->IsSingular(goalpose, 0.0001)) {
            std::cout << "Is singular pose: " << DumpPose(goalpose).c_str();
        }
        std::vector<JointState> gotojoints;
        std::cout << "Current Pose " << DumpPose(currentpose).c_str();
        std::vector<RCS::Pose> poses = motioncontrol.computeWaypoints(currentpose, goalpose, 
                0.01, // cc.Rates().CurrentFeedrate() * DEFAULT_LOOP_CYCLE, //0.01, 
                true);
        for (size_t k = 0; k < poses.size(); k++)
            std::cout << "\n\nWaypoint[" << k << "]" << DumpPose(poses[k]).c_str();

        gotojoints = PlanCartesianMotion(poses);
        AddJointCommands(gotojoints);
    } else if (cc.cmd == RCS::CANON_MOVE_THRU) {
        rates = IRate(DEFAULT_CART_MAX_VEL, DEFAULT_CART_MAX_ACCEL, DEFAULT_LOOP_CYCLE);
        std::vector<JointState> gotojoints;
        std::vector<RCS::Pose> poses = cc.waypoints;
        poses.insert(poses.begin(), currentpose); // add beginning pose -again?
        // and in case interrupted
        gotojoints = PlanCartesianMotion(poses);
        AddJointCommands(gotojoints);
    } else if (cc.cmd == RCS::CANON_DWELL) {
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
