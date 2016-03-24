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


using namespace RCS;
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
    std::vector<RCS::Pose> GetPosesPlan();

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
    bool Plan(RCS::Pose & curpose, RCS::Pose & goalpose);

    /**
     * \brief plan a cartesian trajectory given a vector of waypoint poses. Assumes rate already set.
     * \param  waypoints vector of intermediate pose definition.
     * \return true if successful cartesian trajectory was generated.
     */
    bool Plan(std::vector<RCS::Pose>& waypoints);

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
    std::vector<RCS::Pose> makeCartesianTrajectory(IRate rates,
            RCS::Pose _curPos,
            RCS::Pose _goalPos);

    /**
     * \brief Reference to rates data structure.
     */
    IRate &Rates() {
        return currates;
    }
protected:
    // -------------------------------------------------------------------------------------------------
    void updateJointCommands(std::vector<double> & curjoints, std::vector<std::vector<double> > & displacements);
    std::vector<RCS::Pose> makeTrajectory(RCS::CanonWorldModel *parameters, RCS::Pose goal, RCS::Pose current); // lame
    std::vector<double> makeJointValues(double current, std::vector<double> displacements);
    std::vector<double> makeJointTrajectory(double current, double goal);
    void setCurrent(RCS::Pose current); /*!< Set the current position. */

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
    std::vector<RCS::Pose> makeCartesianTrajectory(double final_velocity,
            double current_feedrate,
            double current_velocity,
            double maximum_accel,
            double cycleTime,
            RCS::Pose _curPos,
            RCS::Pose _goalPos);
#endif
    double runTrapezoidalCycle(IRate & trans, double distance_to_go);

    double makeNRamp(int N,
            double maxVelocity,
            double maxAcc,
            double cycleTime,
            std::vector<double> & acclramp);
private:
    RCS::Pose computeTranslation(RCS::Pose & current, RCS::Pose & goal, double dIncrement);
    std::vector<double> ramp; /*!< Ramp up or down to maximum velocity */
    double rampLength; /*!< The distance traveled over the ramp */
    RCS::Pose current;
    std::vector<JointState> plannedjts;
    std::vector<RCS::Pose> plannedposes;
    IRate currates;
};

#endif
