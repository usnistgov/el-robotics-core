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

/*!
* \brief RCSInterpreter parses a RCS command and generates robot motion commands.
*/
class RCSInterpreter
{
public:
	/*!
	* \brief RCSInterpreter constructor that optionally accepts pointer to kinematic instance.
	\param k is the kinematics pointer
	*/
    RCSInterpreter(IKinematicsSharedPtr k = NULL);
    ~RCSInterpreter(void);

	/*!
	* \brief ParseCommand parses a RCS command and queues robot motion commands.
	\param cmd is the command to interpret
	*/
    int ParseCommand(RCS::CanonCmd cmd);
protected:
	/*!
	* \brief AddJointCommands  accepts vector of joint trajectories and adds to robot motion queue.
	\param gotojoints is the vector of joint states describing the motion.
	*/
    void AddJointCommands(std::vector<JointState > gotojoints);

	/*!
	* \brief PlanCartesianMotion accepts vector of poses and generates a vector of joint trajectories.
	* Can use a couple of planning algorithms to generate trajectory.
	\param poses is the vector of cartesian motion.
	\return vector of planned joint states
	*/
    std::vector<JointState> PlanCartesianMotion(std::vector<RCS::Pose> poses);

    //////////////////////////////////////////////////
public:
    IKinematicsSharedPtr _kinematics; /**<  kinematics pointer */
    TrajectoryVec results; /**< descartes motion planner results */
    std::vector<double> times;  /**< descartes times for  trajectory results */
    IRate rates; /**< rates structure for simple motion planner  */
    MotionControl motioncontrol; /**< instance of simple motion control object  */
 
};
