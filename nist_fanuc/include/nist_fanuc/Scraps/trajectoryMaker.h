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

class IRate
{
public:
    IRate( ) { }
    IRate(double final_velocity, double current_feedrate, double current_velocity, double maximum_accel, double cycleTime) :
        _final_velocity(final_velocity), _current_feedrate(current_feedrate), _current_velocity(current_velocity), _cycleTime(cycleTime), _maximum_accel(maximum_accel)
    {
        _msflag = RCS::MS_IS_UNSET;
    }

    double               _final_velocity;
    double               _current_feedrate;
    double               _current_velocity;
    double               _maximum_accel;
    double               _cycleTime;
    RCS::CanonAccProfile _msflag;
    double               _current_accel;
    void setCurrentAcceleration (double accl) { _current_accel = accl; }
    void setCurrentVelocity (double vpgNewVel) { _current_velocity = vpgNewVel; }
    void setAccState (RCS::CanonAccProfile msflag) { _msflag = msflag; }
};

class TrajectoryMaker
{
public:
    TrajectoryMaker( );

    double                                             makeRamp (RCS::CanonWorldModel *parameters, RCS::MovementType);

    std::vector<double>                                makeJointValues (double current, std::vector<double> displacements);

    std::vector<double>                                makeJointTrajectory (RCS::CanonWorldModel *parameters, double goal, double current);

    std::vector<RCS::Pose>                             makeTrajectory (RCS::CanonWorldModel *parameters, RCS::Pose goal, RCS::Pose current);

    void                                               setCurrent (RCS::Pose current); /*!< Set the current position. */

    std::vector<double>                                makePositionVector (double start, double end);

    double                                             makeDeclRamp (double startingVelocity,
        double                                                              finalVelocity,
        double                                                              maxAcc,
        double                                                              cycleTime,
        std::vector<double> &                                               declRamp);

    double                                             makeAcclRamp (double startingVelocity,
        double                                                              finalVelocity,
        double                                                              maxVelocity,
        double                                                              maxAcc,
        double                                                              cycleTime,
        std::vector<double> &                                               acclRamp);

    std::vector<double>                                makeStopJointTrajectory (double startingVelocity,
        double                                                                         finalVelocity,
        double                                                                         maxAcc,
        double                                                                         cycleTime,
        double                                                                         current);

    std::vector<boost::tuple<double, double, double> > makeTupleRamp (double maxVelocity,
        double                                                               maxAcc,
        double                                                               cycleTime);

    std::vector<RCS::Pose>                             makeTrajVector (double final_velocity,
        double                                                                current_feedrate,
        double                                                                current_velocity,
        double                                                                maximum_accel,
        double                                                                cycleTime,
        RCS::Pose                                                             _curPos,
        RCS::Pose                                                             _goalPos);

    double                                             runTrapezoidalCycle (IRate & trans, double distance_to_go);

    double                                             makeNRamp (int N,
        double                                                        maxVelocity,
        double                                                        maxAcc,
        double                                                        cycleTime,
        std::vector<double> &                                         acclramp);
private:
    RCS::Pose                                          computeTranslation (RCS::Pose & current, RCS::Pose & goal, double dIncrement);
    std::vector<RCS::Pose>                             manipulateVector (std::vector<double> vX,
        std::vector<double>                                                                  vY,
        std::vector<double>                                                                  vZ,
        std::vector<double>                                                                  vRoll,
        std::vector<double>                                                                  vPitch,
        std::vector<double>                                                                  vYaw,
        int                                                                                  maxSize);
    size_t                                             maxVectorSize (std::vector<double> vX, std::vector<double> vY,
        std::vector<double> vZ,
        std::vector<double> vRoll, std::vector<double> vPitch,
        std::vector<double> vYaw);
    std::vector<double> ramp;       /*!< Ramp up or down to maximum velocity */
    double              rampLength; /*!< The distance traveled over the ramp */
    RCS::Pose           current;
};

#endif
