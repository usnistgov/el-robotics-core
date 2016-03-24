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

/*!
 *	\file		trajectorMaker.cpp
 *	\brief      This class keeps track of the positions of the
 *                      robot and creates the trajectory of movement.
 *	\class		TrajectoryMaker
 *	\author		based on work by Stephen Balakirsky, GTRI
 *	\date		July 30, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include "trajectoryMaker.h"
#include <numeric>    // std::accumulate
#include <functional> // std::minus
#include "Globals.h"
#include <algorithm>

using namespace RCS;


/**
Constructor for CurrentLocation that sets all points and velocity to 0.
 */
TrajectoryMaker::TrajectoryMaker() {
#if 1
    current.getOrigin().setX( 0.0); // .x = 0;
    current.getOrigin().setY(  0.0); // .y = 0;
    current.getOrigin().setZ( 0.0); // .z = 0;
//    current.getRotation().setX( 0); // .xrot = 0;
//    current.getRotation().setY(  0); // .yrot = 0;
//    current.getRotation().setZ(  0); // .zrot = 0;
#endif
}

std::vector<JointState> TrajectoryMaker::GetJtsPlan() {
    return plannedjts;
}

std::vector<RCS::Pose> TrajectoryMaker::GetPosesPlan() {
    return plannedposes;
}

void TrajectoryMaker::setRates(IRate rates) {
    currates = rates;
}

bool TrajectoryMaker::Plan(JointState curjoints, JointState goaljoints) {
    return makeJointPositionTrajectory(currates, curjoints, goaljoints);
}

bool TrajectoryMaker::Plan(RCS::Pose & curpose, RCS::Pose & goalpose) {
    plannedposes = makeCartesianTrajectory(currates, curpose, goalpose);
    return true;
}

bool TrajectoryMaker::Plan(std::vector<RCS::Pose>& waypoints) {
    assert(0);
    return true;
}

std::vector<double> TrajectoryMaker::makePositionRamp(double maxVel, double maxAccel, double cycletime) {
    double traverseIncrement;
    std::vector<double> ramp;
    ramp.clear();
    double currentVelocity = maxAccel * cycletime;

    while (currentVelocity < maxVel) {
        traverseIncrement = currentVelocity * cycletime;
        ramp.push_back(traverseIncrement);
        currentVelocity += maxAccel * cycletime;
    }

     return ramp; //  std::accumulate(ramp.begin(), ramp.end(), 0.0);
}

bool TrajectoryMaker::makeJointPositionTrajectory(IRate rates, JointState & curjoints, JointState & goaljoints) {
    assert(curjoints.position.size() == goaljoints.position.size());
    std::vector<std::vector<double> > displacements;
    for (size_t i = 0; i < curjoints.position.size(); i++)
    {
        std::vector<double> d = makeJointTrajectory(curjoints.position[i], goaljoints.position[i]);
        displacements.push_back(d);
    }
    updateJointCommands(curjoints.position, displacements);
    return true;

}

bool TrajectoryMaker::makeJointPositionTrajectory(IRate rates, std::vector<double> & curjoints, std::vector<double> & goaljoints) {
    assert(curjoints.size() == goaljoints.size());
    std::vector<std::vector<double> > displacements;
    for (size_t i = 0; i < curjoints.size(); i++) {
        std::vector<double> d = makeJointTrajectory(curjoints[i], goaljoints[i]);
        displacements.push_back(d);
    }
    updateJointCommands(curjoints, displacements);
    return true;
}

void TrajectoryMaker::updateJointCommands(std::vector<double> & curjoints, std::vector<std::vector<double> > & displacements) {
    // imax ends up being the number of new motion commands
    size_t imax = 0;
    plannedjts.clear();
    for (size_t i = 0; i < displacements.size(); i++) {
        imax = std::max(imax, displacements[i].size());
    }

    std::vector<double> lastjoints = curjoints;
    JointState joint;
    joint.position = curjoints;
    plannedjts.push_back(joint);

    for (size_t i = 0; i < imax; i++) {
        JointState joint;
        // initialize last joint position
        joint.position.insert(joint.position.begin(), lastjoints.begin(), lastjoints.end());

        // update new joint position
        for (size_t j = 0; j < displacements.size(); j++) {
            if ((displacements[j].size() > 0) && (displacements[j].size() <= imax)) {
                joint.position[j] += displacements[j][i];
            }
        }
        lastjoints = joint.position; // save last joint positions
        plannedjts.push_back(joint);
        //std::cout << "Joint Displacements" << VectorDump<double> (joint.position);
    }
   
}

// ! A member function that takes four double arguments and returns a vector
// ! of doubles.

/**
This function creates a vector of doubles that determines the trajectory
of the Robot depending on the start position, the end position, the max
velocity, and the acceleration. Shows the position values at times
incrementing by the cycle time of the robot.

\param start The start position of the Robot.
\param end   The desired end position of the Robot.
\param       maxSpeed The max velocity the Robot can reach.
\param       acc The acceleration of the Robot.
\return      The vector of doubles that show the position of the Robot every
cycleTime milliseconds.
 **/
std::vector<double> TrajectoryMaker::makePositionVector(std::vector<double> myramp, double start, double end) {
    double distanceToMove;
    bool reverse = false;
    std::vector<double> displacements;
    std::vector<double> currentRamp;
    double currentRampLength;
    double totalDisplacement;
    double displacementRemaining;
    int counter = 0; // must allow positive and negative

    distanceToMove = fabs(start - end);

    if (start > end) {
        reverse = true;
    }

    counter = 0;
    currentRamp.clear();
    currentRampLength = 0;

    while ( (counter < myramp.size() && 
            (distanceToMove > 2. * (currentRampLength + myramp[counter])))) {
        currentRamp.push_back(myramp[counter]);
        currentRampLength += myramp[counter];
        counter++;
    }

    // copy ramp to beginning of new vector
    totalDisplacement = 0;
    displacements.clear();

    if (currentRamp.size() > 0) {
        for (counter = 0; counter < currentRamp.size(); counter++) {
            displacements.push_back(currentRamp[counter]);
            totalDisplacement += displacements.back();
        }

        // do I need to add max velocity segments?
        while ((totalDisplacement + currentRamp.back()) <=
                (distanceToMove - currentRampLength)) {
            displacements.push_back(currentRamp.back());
            totalDisplacement += currentRamp.back();
        }

        // add deceleration
        displacementRemaining = distanceToMove
                - (totalDisplacement + currentRampLength);

        for (counter = (int) currentRamp.size() - 1; counter >= 0; counter--) {
            displacements.push_back(currentRamp[counter]);
            totalDisplacement += currentRamp[counter];

            while (displacementRemaining >= currentRamp[counter]) {
                /*
                printf( "Current Ramp: %lf remaining: %lf diff: %lf\n",
                currentRamp[counter], displacementRemaining,
                displacementRemaining = currentRamp[counter]);
                 */
                displacements.push_back(currentRamp[counter]);
                totalDisplacement += currentRamp[counter];
                displacementRemaining -= currentRamp[counter];
            }
        }
    }

    if (totalDisplacement < distanceToMove) {
        displacements.push_back(distanceToMove - totalDisplacement);
        totalDisplacement += displacements.back();
    }

    //  printf( "Total displacement: %lf distance to move: %lf diff: %lf remain: %lf\n",
    //	  totalDisplacement, distanceToMove,
    //	  fabs(totalDisplacement-distanceToMove),
    //	  displacementRemaining);

    // reverse if necessary
    if (reverse) {
        for (counter = 0; counter < displacements.size(); counter++) {
            displacements[counter] *= -1;
        }
    }
    //std::cout << "Displacements" << VectorDump<double> (displacements);
    return displacements;
}

std::vector<double> TrajectoryMaker::makeJointValues(double current, std::vector<double> displacements) {
    for (size_t i = 0; i < displacements.size(); i++) {
        displacements[i] += current;
    }
    return displacements;
}

std::vector<double> TrajectoryMaker::makeJointTrajectory( double current, double goal) {
    std::vector<double> r = makePositionRamp(currates.MaximumVelocity(),currates.MaximumAccel(),currates.CycleTime());
    std::vector<double> v = makePositionVector(r, current, goal);
    return v;
}
// Which way is joint moving

std::vector<double> TrajectoryMaker::makeStopJointTrajectory(double startingVelocity,
        double finalVelocity,
        double maxAcc,
        double cycleTime,
        double current) {
    std::vector<double> declRamp;
    double distance = makeDeclRamp(startingVelocity, 0.0, maxAcc, cycleTime, declRamp); // RCS::MOVE_JOINT);
    // std::vector<double> v = makePositionVector(current, current+distance,acclRamp,declRamp);
    double start = current, end = current + distance;
    double distanceToMove = fabs(start - end);
    bool reverse = (start > end) ? true : false;
    std::vector<double> displacements;
    displacements.insert(displacements.begin(), declRamp.begin(), declRamp.end());


    // reverse if necessary
    if (reverse) {
        std::transform(displacements.begin(), displacements.end(), displacements.begin(),
                std::bind1st(std::multiplies<double>(), -1));
    }

    return displacements;
}


/**
Set the current location from the input pose
 */
void TrajectoryMaker::setCurrent(RCS::Pose poseIn) {
    current = poseIn;
}
// ! compute stop motion deceleration

/**
max accel is computed by parameters->getMaxAccel(movetype) *
parameters->getCycleTime();
 */
double TrajectoryMaker::makeDeclRamp(double startingVelocity,
        double finalVelocity,
        double maxAcc,
        double cycleTime,
        std::vector<double> & declRamp) {
    //	assert(startingVelocity<=maxVelocity);
    assert(finalVelocity <= startingVelocity);
    double traverseIncrement = 0.0;

    declRamp.clear();
    double currentVelocity = startingVelocity * cycleTime - (maxAcc * cycleTime);
    finalVelocity = finalVelocity * cycleTime; // this is actual velocity/sec

    while (currentVelocity - finalVelocity > EPSILON) {
        traverseIncrement = currentVelocity;
        declRamp.push_back(traverseIncrement);

        // totalDistance += traverseIncrement;
        currentVelocity -= maxAcc * cycleTime;
    }

    traverseIncrement = finalVelocity;

    if (traverseIncrement > EPSILON) {
        declRamp.push_back(traverseIncrement);

        // totalDistance += traverseIncrement;
    }
    return std::accumulate(declRamp.begin(), declRamp.end(), 0.0);
}
// ! compute stop motion deceleration

/**
max accel is computed by parameters->getMaxAccel(movetype) *
parameters->getCycleTime();
 */
double TrajectoryMaker::makeAcclRamp(double startingVelocity,
        double finalVelocity,
        double maxVelocity,
        double maxAcc,
        double cycleTime,
        std::vector<double> & acclRamp) {
    //	assert(startingVelocity<=maxVelocity);
    //	assert(finalVelocity<=startingVelocity);
    assert(finalVelocity >= startingVelocity);
    double traverseIncrement = 0.0;

    acclRamp.clear();
    double currentVelocity = startingVelocity * cycleTime + (maxAcc * cycleTime);
    finalVelocity = finalVelocity * cycleTime; // this is actual velocity/sec

    while (finalVelocity - currentVelocity > maxAcc * cycleTime) {
        traverseIncrement = currentVelocity;
        acclRamp.push_back(traverseIncrement);
        currentVelocity += maxAcc * cycleTime;
    }

    traverseIncrement = finalVelocity;

    if (traverseIncrement > EPSILON) {
        acclRamp.push_back(traverseIncrement);
    }
    return std::accumulate(acclRamp.begin(), acclRamp.end(), 0.0);
}
#if 0
// ! Computes an acceleration/decelleration ramp from robot parameters

/** This ramp is used to compute trajectories and represents operating
at the max acceleration to achieve the maximum velocity. Note
that ramp is computed in cartesian space which may still violate
joint space velocity constraints on the actual robot system

Algorithm:
1) Compute the distance that the robot will travel in Cartesian space
at current velocity for one cycle time
2) While the velocity is less than the max, increase it by
acceleration times cycle time.

\param parameters  The robot's parameters
\return distance   The length of the ramp
 **/
double TrajectoryMaker::makeRamp(RCS::CanonWorldModel *parameters, RCS::MovementType movetype) {
    double traverseIncrement;

    ramp.clear();
    double maxVel = (movetype == RCS::MOVE_CARTESIAN) ? parameters->maxTransVel : parameters->maxJointVel;
    double maxAccel = (movetype == RCS::MOVE_CARTESIAN) ? parameters->maxTransAccel : parameters->maxJointAccel;
    double currentVelocity = maxAccel * parameters->getCycleTime();

    while (currentVelocity < maxVel) {
        traverseIncrement = currentVelocity * parameters->getCycleTime();
        ramp.push_back(traverseIncrement);
        currentVelocity += maxAccel * parameters->getCycleTime();
    }

    return std::accumulate(ramp.begin(), ramp.end(), 0.0);
}
#endif
std::vector<boost::tuple<double, double, double> > TrajectoryMaker::makeTupleRamp(double maxVelocity,
        double maxAcc,
        double cycleTime) {
    double traverseIncrement;
    double distanceTraveled = 0;
    double currentVelocity = maxAcc * cycleTime;

    maxVelocity = maxVelocity * cycleTime;
    std::vector<boost::tuple<double, double, double> > ramp;

    while (currentVelocity < maxVelocity) {
        distanceTraveled += traverseIncrement = currentVelocity * cycleTime;
        ramp.push_back(boost::make_tuple<double, double, double>(traverseIncrement, currentVelocity, distanceTraveled));

        currentVelocity += maxAcc * cycleTime;
    }

    return ramp;
}

double TrajectoryMaker::makeNRamp(int N,
        double maxVelocity,
        double maxAcc,
        double cycleTime, std::vector<double> & acclramp) {
    double traverseIncrement;
    double currentVelocity = maxAcc * cycleTime;

    std::vector<double> declramp;
    int odd = N % 2;
    int counter = 0;

    if (odd) {
        N = N - 1;
    }
    acclramp.clear();

    while (counter < N) {
        traverseIncrement = currentVelocity * cycleTime;
        acclramp.push_back(traverseIncrement);
        declramp.push_back(traverseIncrement);

        if (currentVelocity < maxAcc) {
            currentVelocity += maxAcc * cycleTime;
        }
        counter = counter + 2;
    }

    if (odd) {
        acclramp.push_back(currentVelocity);
    }
    std::reverse(declramp.begin(), declramp.end());
    acclramp.insert(acclramp.end(), declramp.begin(), declramp.end());
    return std::accumulate(acclramp.begin(), acclramp.end(), 0.0);
}

std::vector<RCS::Pose> TrajectoryMaker::makeCartesianTrajectory(double final_velocity,
        double current_feedrate,
        double current_velocity,
        double maximum_accel,
        double cycleTime,
        RCS::Pose _curPose,
        RCS::Pose _goalPose) {
    IRate translationParameters(DEFAULT_CART_MAX_VEL, maximum_accel, cycleTime);
    translationParameters.SetCurrentMotion(final_velocity, current_feedrate, current_velocity);
    return makeCartesianTrajectory(translationParameters, _curPose, _goalPose);
}

std::vector<RCS::Pose> TrajectoryMaker::makeCartesianTrajectory(IRate rates,
        RCS::Pose _curPos,
        RCS::Pose _goalPos) {
    std::vector<RCS::Pose> poses;
    rates.MsFlag() = RCS::MS_IS_UNSET;
    double final_velocity = rates.FinalVelocity();
    double current_feedrate = rates.CurrentFeedrate();
    double current_velocity = rates.CurrentVelocity();
    double maximum_accel = rates.MaximumAccel();
    double cycleTime = rates.CycleTime();

    RCS::Vector3 current(_curPos.getOrigin().x(), _curPos.getOrigin().y(), _curPos.getOrigin().z());
    RCS::Vector3 goal(_goalPos.getOrigin().x(), _goalPos.getOrigin().y(), _goalPos.getOrigin().z());
    RCS::Pose pose;
    double totalIncrements = 0.0;

    while (rates.MsFlag() != RCS::MS_IS_DONE) {
      //  double dIncrement = runTrapezoidalCycle(rates, _dist3(goal, current));
        RCS::Vector3 diff =  goal- current;
        double dIncrement = runTrapezoidalCycle(rates, sqrt(diff.dot(diff)));
       Globals.DebugMessage(Logger.StrFormat("dIncrement=%6.4f\n", dIncrement));

        if (dIncrement < EPSILON) {
            rates.MsFlag() = RCS::MS_IS_DONE;
            continue;
        }
        totalIncrements += dIncrement;
        RCS::Pose pose = computeTranslation(_curPos, _goalPos, totalIncrements);
        poses.push_back(pose);
        current = RCS::Vector3(pose.getOrigin().x(), pose.getOrigin().y(), pose.getOrigin().z());
        Globals.DebugMessage(Logger.StrFormat("Current=%6.4f:%6.4f:%6.4f\n", pose.getOrigin().x(), pose.getOrigin().y(), pose.getOrigin().z()));
    }

    rates.CurrentAccel()=0.0;

    std::vector<double> rotramp;
    double dTotRotDistance = makeNRamp(poses.size(), current_feedrate, maximum_accel, cycleTime, rotramp);

    double dRotDistance = 0.0;

    for (size_t i = 0; i < poses.size(); i++) {
        dRotDistance += rotramp[i];
        double t = dRotDistance / dTotRotDistance;

        // Globals.DebugMessage(Logger.StrFormat("t= %8.4f\n", t));
        RCS::Rotation q = _curPos.getRotation().slerp(_goalPos.getRotation(), t);
        //poses[i].rotation.setFromQuaternion(q.x, q.y, q.z, q.w);
        poses[i].setRotation(q); // q.x, q.y, q.z, q.w);
    }
    return poses;
}
#if 0
static RCS::Rotation slerp(RCS::Rotation & qa, RCS::Rotation & qb, double t) {
    // quaternion to return
    RCS::Rotation qm;

    // Calculate angle beteen them.
    double costheta = qa.w() * qb.w() + qa.x() * qb.x() + qa.y() * qb.y() + qa.z() * qb.z();
    double theta = acos(costheta);

    // if theta = 0 then return qa
    if (fabs(theta) < 0.01) {
        qm.w() = qa.w();
        qm.x() = qa.x();
        qm.y() = qa.y();
        qm.z() = qa.z();
        return qm;
    }

    // Calculate temporary values.
    double sinTheta = sqrt(1.0 - costheta * costheta);

    // if theta*2 = 180 degrees then result is undefined
    if (fabs(sinTheta) < 0.01) {
        qm.w() = (qa.w() * 0.5 + qb.w() * 0.5);
        qm.x() = (qa.x() * 0.5 + qb.x() * 0.5);
        qm.y() = (qa.y() * 0.5 + qb.y() * 0.5);
        qm.z() = (qa.z() * 0.5 + qb.z() * 0.5);
        return qm;
    }
    double ratioA = sin((1 - t) * theta) / sinTheta;
    double ratioB = sin(t * theta) / sinTheta;

    // calculate Quaternion.
    qm.w() = (qa.w() * ratioA + qb.w() * ratioB);
    qm.x() = (qa.x() * ratioA + qb.x() * ratioB);
    qm.y() = (qa.y() * ratioA + qb.y() * ratioB);
    qm.z() = (qa.z() * ratioA + qb.z() * ratioB);
    return qm;
}
#endif
RCS::Pose TrajectoryMaker::computeTranslation(RCS::Pose & _curPos, RCS::Pose & _goalPos, double dIncrement) {
    RCS::Vector3 current(_curPos.getOrigin().x(), _curPos.getOrigin().y(), _curPos.getOrigin().z());
    RCS::Vector3 goal(_goalPos.getOrigin().x(), _goalPos.getOrigin().y(), _goalPos.getOrigin().z());
    RCS::Vector3 v = goal - current; //_sub3(goal, current);
    RCS::Pose pose;

    pose.getOrigin().setX(  goal.x());
    pose.getOrigin().setY(  goal.y());
    pose.getOrigin().setZ(  goal.z());

    //  if (_magnitude3(v) < EPSILON) {
    if (sqrt(v.dot(v)) < EPSILON) {
        return pose;
    }
    try {
        v = v.normalize(); // _normalize3(v);
        v = current + (v * dIncrement); // _add3(current, _mult3(v, dIncrement));
        pose.getOrigin().setX(v.x());
        pose.getOrigin().setY( v.y());
        pose.getOrigin().setZ( v.z());
    } catch (...) {
        // Ignore zero vector normalization
    }
    return pose;
}

double TrajectoryMaker::runTrapezoidalCycle(IRate & rates, double distance_to_go) {
    double vpgNewVel;
    double vpgTicks_to_stop;

    RCS::CanonAccProfile & msflag(rates.MsFlag());
    double & final_velocity(rates.FinalVelocity());
    double & current_feedrate(rates.CurrentFeedrate());
    double & current_velocity(rates.CurrentVelocity());
    double & maximum_accel(rates.MaximumAccel());
    double & cycle_time(rates.CycleTime());
    double decl_distance_to_final_velocity;
    double dIncrement = 0;

    if (distance_to_go < EPSILON) {
        msflag = RCS::MS_IS_DONE;
        return 0.0;
    }

    // while(msflag != RCS::MS_IS_DONE)
    {
        // Worst case
        vpgTicks_to_stop = (current_velocity - final_velocity) / (maximum_accel);

        // FIXME: is this d= Vo(t) + 1/2at^2
        // The value is zero when starting from rest
        //	distance_to_final_velocity=(final_velocity * vpgTicks_to_stop) + 0.5 *
        //		(maximum_accel * pow(vpgTicks_to_stop*cycle_time , 2 ) );

        decl_distance_to_final_velocity = (current_velocity - final_velocity) * cycle_time * 0.5 * vpgTicks_to_stop;

        // Test for end
        // if( distance_to_go <  (current_velocity + final_velocity) * .5 * cycle_time)
        if (distance_to_go < (final_velocity + maximum_accel) * .5 * cycle_time) {
            msflag = RCS::MS_IS_DONE;
            rates.CurrentAccel()=0.0;
            vpgNewVel = final_velocity;
            dIncrement = distance_to_go;
        } else {
            // Start declerating when we are within range
            if (distance_to_go < (decl_distance_to_final_velocity + /* fudge */ (maximum_accel * cycle_time * 0.5))) {
                // FIXME: or if trans->current_velocity  > current_velocity - changed
                msflag = RCS::MS_IS_DECEL;

                // This should be a smoother function
                vpgNewVel = current_velocity - maximum_accel;

                if (vpgNewVel <= final_velocity) {
                    vpgNewVel = final_velocity;
                }

                if (vpgNewVel < 0) {
                    vpgNewVel = 0;
                }
                dIncrement = (vpgNewVel + current_velocity) * 0.5 * cycle_time;

                if (dIncrement >= distance_to_go) {
                    // Solve: distance_to_go = (revisedVel + current_velocity) * 0.5 * cycle_time
                    vpgNewVel = 2.0 * (distance_to_go - (current_velocity * 0.5 * cycle_time)) / cycle_time;
                    dIncrement = distance_to_go;
                }
            } else {
                // keep accelerating if you can */
                // This should be a smoother function
                vpgNewVel = current_velocity + maximum_accel;

                msflag = RCS::MS_IS_ACCEL;

                if (vpgNewVel > current_feedrate) {
                    vpgNewVel = current_feedrate;
                    msflag = RCS::MS_IS_CONST;
                }

                dIncrement = fabs(vpgNewVel + current_velocity) * 0.5 * cycle_time;
            }
        }

        rates.CurrentAccel()=(vpgNewVel - current_velocity) / cycle_time;
        rates.CurrentVelocity()=vpgNewVel;
    }
    return dIncrement;
}
