/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------
 *****************************************************************************/
#ifndef TrajectoryMaker_DECL
#define TrajectoryMaker_DECL

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <boost/tuple/tuple.hpp>
#include "RCS.h"
#include "Globals.h"

/**
 * \brief IRate is an interface class for defining the allowed motion rates.
 */
class IRate {
public:

    IRate() {
        _maximum_velocity = DEFAULT_CART_MAX_VEL;
        _maximum_accel = DEFAULT_CART_MAX_ACCEL;
        _cycleTime = DEFAULT_CYCLE;
        Clear();
    }

    IRate(double maximum_velocity, double maximum_accel, double cycleTime) :
    _maximum_velocity(maximum_velocity), _cycleTime(cycleTime), _maximum_accel(maximum_accel) {
        Clear();
    }

    void SetCurrentMotion(double final_velocity, double current_feedrate, double current_velocity) {
        _final_velocity = final_velocity;
        _current_feedrate = current_feedrate;
        _current_velocity = current_velocity;
    }
    NVAR(FinalVelocity, double, _final_velocity);
    NVAR(CurrentFeedrate, double, _current_feedrate);
    NVAR(CurrentVelocity, double, _current_velocity);
    NVAR(MaximumVelocity, double, _maximum_velocity);
    NVAR(MaximumAccel, double, _maximum_accel);
    NVAR(CycleTime, double, _cycleTime);
    NVAR(CurrentAccel, double, _current_accel);
    NVAR(MsFlag, RCS::CanonAccProfile, _msflag);
private:

    void Clear() {
        _final_velocity = _current_feedrate = _current_velocity = _current_accel = 0.0;
        _msflag = RCS::MS_IS_UNSET;
    }
};

/**
 * \brief TrajectoryMaker generates simple trapezoidal velocities. Will accept non-zero final velocity.
 */
class TrajectoryMaker {
public:
    /**
     * \brief constuctor.
     */
    TrajectoryMaker();

    /**
     * \brief GetJtsPlan returns vector of generated joint state trajectories.
     * \return  returns vector of joint state
     */
    std::vector<JointState> GetJtsPlan();

    /**
     * \brief GetPosesPlan returns vector of generated pose trajectories.
     * \return  returns vector of poses
     */
    std::vector<urdf::Pose> GetPosesPlan();

    /**
     * \brief setRates defines the rate to use when generating trajectory.
     * \param  rates contains the IRate definition.
     */
    void setRates(IRate rates);

    /**
     * \brief plan a joint trajectory based on current and goal joint states. Assumes rate already set.
     * \param  curjoints current joint state definition.
     * \param  goaljoints goal joint state definition.
     * \return true if successful joint state trajectory was generated.
     */
    bool Plan(JointState curjoints, JointState goaljoints);

    /**
     * \brief plan a cartesian trajectory based on current and goal pose states. Assumes rate already set.
     * \param  curpose current pose definition.
     * \param  goalpose goal pose definition.
     * \return true if successful cartesian trajectory was generated.
     */
    bool Plan(urdf::Pose & curpose, urdf::Pose & goalpose);

    /**
     * \brief plan a cartesian trajectory given a vector of waypoint poses. Assumes rate already set.
     * \param  waypoints vector of intermediate pose definition.
     * \return true if successful cartesian trajectory was generated.
     */
    bool Plan(std::vector<urdf::Pose>& waypoints);

    /**
     * \brief makePositionVector  generates a vector of from start to end point.
     * \param  ramp vector of incremental distances up to max velocity attained.
     * \param start defines starting position
     * \param end defines ending position
     * \return vector of points defining trajectory of given velocity profile.
     */
    std::vector<double> makePositionVector(std::vector<double> ramp, double start, double end);

    /**
     * \brief makeJointPositionTrajectory constructs a joint trajectory based on current and goal joint states given a rate profile.
     * \param  rates defines motion characteristics.
     * \param  curjoints current joint state definition.
     * \param  goaljoints goal joint state definition.
     * \return true if successful joint state trajectory was generated.
     */
    bool makeJointPositionTrajectory(IRate rates,
            JointState & curjoints,
            JointState & goaljoints);
   /**
     * \brief makeJointPositionTrajectory constructs a joint trajectory based on current and goal joint states given a rate profile.
     * \param  rates defines motion characteristics.
     * \param  curjoints double vector of current joint position definition.
     * \param  goaljoints double vector of goal joint position definition.
     * \return true if successful joint state trajectory was generated.
     */
    bool makeJointPositionTrajectory(IRate rates, std::vector<double> & curjoints, std::vector<double> & goaljoints) ;

    /**
     * \brief makeStopJointTrajectory constructs a stopping  trajectory based on current velocity.
     * \param  finalVelocity should be zero.
     * \param  maxAcc given maximum deceleration rate.
     * \param  cycleTime gives the cycle time for the acceleration rate.
     * \param  current is the current double position
     * \return vector of offset distances from current position to stop.
     */
    std::vector<double> makeStopJointTrajectory(double startingVelocity,
            double finalVelocity,
            double maxAcc,
            double cycleTime,
            double current);
    /**
     * \brief makeCartesianTrajectory plans a cartesian trajectory based on current and goal pose states for the given rate profile.
     * \param  rates defines the motion parameters.
     * \param  curpose current pose definition.
     * \param  goalpose goal pose definition.
     * \return vector of generated  cartesian poses trajectory from start to goal.
     */
    std::vector<urdf::Pose> makeCartesianTrajectory(IRate rates,
            urdf::Pose _curPos,
            urdf::Pose _goalPos);

    /**
     * \brief Reference to rates data structure.
     */
    IRate &Rates() {
        return currates;
    }
protected:
    // -------------------------------------------------------------------------------------------------
    void updateJointCommands(std::vector<double> & curjoints, std::vector<std::vector<double> > & displacements);
    std::vector<urdf::Pose> makeTrajectory(RCS::CanonWorldModel *parameters, urdf::Pose goal, urdf::Pose current); // lame
    std::vector<double> makeJointValues(double current, std::vector<double> displacements);
    std::vector<double> makeJointTrajectory(double current, double goal);
    void setCurrent(urdf::Pose current); /*!< Set the current position. */

    std::vector<double> makePositionRamp(double maxVel, double maxAccel, double cycletime);
    double makeDeclRamp(double startingVelocity,
            double finalVelocity,
            double maxAcc,
            double cycleTime,
            std::vector<double> & declRamp);

    double makeAcclRamp(double startingVelocity,
            double finalVelocity,
            double maxVelocity,
            double maxAcc,
            double cycleTime,
            std::vector<double> & acclRamp);
    std::vector<boost::tuple<double, double, double> > makeTupleRamp(double maxVelocity,
            double maxAcc,
            double cycleTime);


#if 1
    std::vector<urdf::Pose> makeCartesianTrajectory(double final_velocity,
            double current_feedrate,
            double current_velocity,
            double maximum_accel,
            double cycleTime,
            urdf::Pose _curPos,
            urdf::Pose _goalPos);
#endif
    double runTrapezoidalCycle(IRate & trans, double distance_to_go);

    double makeNRamp(int N,
            double maxVelocity,
            double maxAcc,
            double cycleTime,
            std::vector<double> & acclramp);
private:
    urdf::Pose computeTranslation(urdf::Pose & current, urdf::Pose & goal, double dIncrement);
    std::vector<double> ramp; /*!< Ramp up or down to maximum velocity */
    double rampLength; /*!< The distance traveled over the ramp */
    urdf::Pose current;
    std::vector<JointState> plannedjts;
    std::vector<urdf::Pose> plannedposes;
    IRate currates;
};

#endif
