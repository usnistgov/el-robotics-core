// RCS.cpp

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
#include "RCS.h"
#include "Globals.h"
#include "Controller.h"

namespace RCS {
	unsigned long long CanonCmd::_cmdid=0;
    void CanonWorldModel::Init() {
        _cycleTime = DEFAULT_LOOP_CYCLE;

        maxTransAccel = DEFAULT_CART_MAX_ACCEL;
        maxTransVel = DEFAULT_CART_MAX_VEL;
        maxRotAccel = DEFAULT_CART_MAX_ACCEL;
        maxRotVel = DEFAULT_CART_MAX_VEL;
        maxJointAccel = DEFAULT_JOINT_MAX_ACCEL;
        maxJointVel = DEFAULT_JOINT_MAX_VEL;

        //for (size_t i = 0; i < RCS::Controller.robot_model.GetMovingJoints(); i++) {
        for (size_t i = 0; i < RCS::Controller._NumJoints; i++) {
            currentjoints.position.push_back(0.0);
            currentjoints.velocity.push_back(0.0);
        }
    }
    // -----------------------------------------------------------------

    void CanonCmd::Init() {
        cmd = CANON_NOOP;
        status = CANON_WAITING;
        accprofile = MS_IS_UNSET;
        type = GOAL;
        stoptype = UNSET;
        bCoordinated = false;
        bStraight = false;

        // In theory these can change
        absTransAcc = DEFAULT_CART_MAX_ACCEL;
        absTransSpeed = DEFAULT_CART_MAX_VEL;
        absRotAcc = DEFAULT_CART_MAX_ACCEL;
        absRotSpeed = DEFAULT_CART_MAX_VEL;
        absJointAcc = DEFAULT_JOINT_MAX_ACCEL;
        absJointSpeed = DEFAULT_JOINT_MAX_VEL;
    }
};
