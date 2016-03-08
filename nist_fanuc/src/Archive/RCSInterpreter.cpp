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

using namespace RCS;

RCSInterpreter::RCSInterpreter(void)
{ 
     _kinematics = IKinematicsSharedPtr(new DummyKinematics());
}
RCSInterpreter::~RCSInterpreter(void)
{ }
template<typename T>
static void AppendTrajOutput (std::vector<T> v, std::string filename)
{
    std::stringstream s;

    for ( size_t i = 0; i < v.size( ); i++ )
    {
        s << v[i] << ":";
    }
    s << std::endl;
    Globals.AppendFile(filename, s.str( ) );
}
void RCSInterpreter::InsertJointCommands (std::vector<double> & joints, std::vector<std::vector<double> > & displacements)
{
    // imax ends up being the number of new motion commands
    size_t imax = 0;

    for ( size_t i = 0; i < displacements.size( ); i++ )
    {
        imax = std::max(imax, displacements[i].size( ) );
    }

    RCS::CanonCmd lastcc;
    lastcc.joints.position.insert(lastcc.joints.position.begin( ), joints.begin( ), joints.end( ) );

    for ( size_t i = 0; i < imax; i++ )
    {
        RCS::CanonCmd newcc;
        newcc.cmd    = RCS::CANON_MOVE_JOINT;
        newcc.status = RCS::CANON_WAITING;

        // initialize last joint position
        newcc.joints.position.insert(newcc.joints.position.begin( ), lastcc.joints.position.begin( ), lastcc.joints.position.end( ) );

        // update new joint position
        for ( size_t j = 0; j < displacements.size( ); j++ )
        {
            if ( ( displacements[j].size( ) > 0 ) && ( displacements[j].size( ) <= imax ) )
            {
                newcc.joints.position[j] += displacements[j][i];
            }
        }

        // update velocities for each joint
        newcc.joints.velocity = std::vector<double>(displacements.size( ), 0);

        for ( size_t j = 0; j < displacements.size( ); j++ )
        {
            newcc.joints.velocity[j] = newcc.joints.position[j] - lastcc.joints.position[j];
        }
       //FIXME:
        newcc.pose = _kinematics->FK(newcc.joints.position);
        Controller.robotcmds.AddMsgQueue(newcc);
        lastcc = newcc;
    }
}
void RCSInterpreter::ParseCommand (RCS::CanonCmd cc)
{
    Globals.ErrorMessage("RCSInterpreter::ParseCommand\n");
    TrajectoryMaker traj;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // MOVE JOINTS
    if ( cc.cmd = RCS::CANON_MOVE_JOINT )
    {
        urdf::JointState currentjoints = Controller.status.currentjoints;

        // FIXME: if currentjoints.size() < 1 no joints!

        std::vector<std::vector<double> > displacements(currentjoints.position.size( ), std::vector<double>( ) );
        size_t                            k = 0;

        for ( size_t i = 0; i < currentjoints.position.size( ); i++ )
        {
            std::vector<int>::iterator it;

            if ( ( it = std::find(cc.jointnum.begin( ), cc.jointnum.end( ), i) ) != cc.jointnum.end( ) )
            {
                double dCurrent = currentjoints.position[( *it )];
                double dGoal    = cc.joints.position[k++];
                displacements[i] = traj.makeJointTrajectory(&Controller.wm, dGoal, dCurrent);
            }
        }

        // Want the last position on the motion queue - hopefully a joinst
        std::vector<double> joints;

        if ( Controller.robotcmds.SizeMsgQueue( ) > 0 )
        {
            RCS::CanonCmd cmdedj(Controller.robotcmds.BackMsgQueue( ) );
            joints.insert(joints.begin( ), cmdedj.joints.position.begin( ), cmdedj.joints.position.end( ) );
        }
        else
        {
            joints.insert(joints.begin( ), currentjoints.position.begin( ), currentjoints.position.end( ) );
        }

        InsertJointCommands(joints, displacements);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // STOP MOTION
    else if ( cc.cmd = RCS::CANON_STOP_MOTION )
    {
        std::vector<std::vector<double> > displacements(Controller.status.currentjoints.velocity.size( ), std::vector<double>( ) );
        cc.jointnum.clear( );

        for ( size_t i = 0; i < Controller.status.currentjoints.velocity.size( ); i++ )
        {
            if ( Controller.status.currentjoints.velocity[i] > 0 )
            {
                cc.jointnum.push_back(i);
                displacements[i] = traj.makeStopJointTrajectory(Controller.status.currentjoints.velocity[i],
                    0.0,
                    4,
                    DEFAULT_LOOP_CYCLE,
                    Controller.status.currentjoints.position[i]);
            }
        }

        // clear motion queue   - we are stopping asap!
        Controller.robotcmds.ClearMsgQueue( );
        InsertJointCommands(Controller.status.currentjoints.position, displacements);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // MOVE CARTESIAN
    else if ( cc.cmd = RCS::CANON_MOVE_TO )
    {
        RCS::Pose goalpose = cc.pose;

        RCS::Pose currentpose;

        // Check if in middle of existing move - scuttle or append
        // I think crcl says use latest command - but not sure
        if ( Controller.robotcmds.SizeMsgQueue( ) > 0 )
        {
            currentpose = Controller.robotcmds.BackMsgQueue( ).pose;
        }
        else
        {
            currentpose = Controller.status.currentpose;
        }

        // plan trajectory from current(?) or should it be end of goal position to goal
        std::vector<RCS::Pose> poses = traj.makeTrajVector(0.0,                          // final_velocity,
            DEFAULT_CART_MAX_VEL,                                                        // current_feedrate,
            0.0,                                                                         // current_velocity,
            2,
            DEFAULT_LOOP_CYCLE,
            currentpose,
            goalpose);

        // Add poses to motion queue
        for ( size_t i = 0; i < poses.size( ); i++ )
        {
            RCS::CanonCmd newcc;
            newcc.cmd    = RCS::CANON_MOVE_TO;
            newcc.status = RCS::CANON_WAITING;
            newcc.pose   = poses[i];
			std::vector<std::vector<double> > alljointsolutions;
            // find IK using old joint values as guidance to select solution -bogus
            lastjointsolution=_kinematics->IK(newcc.pose, lastjointsolution);
#if 0
            //FIXME:
			_kinematics->PoseToJoints(newcc.pose, alljointsolutions);
			if(lastjointsolution.size()==0)
			{
				lastjointsolution=alljointsolutions[0];  // this wrong very wrong
			}
           //FIXME:
			lastjointsolution=_kinematics->NearestJoints(lastjointsolution,alljointsolutions);
#endif
            // if(alljointsolutions.size() >  0)
            newcc.joints.position = lastjointsolution;
            Controller.robotcmds.AddMsgQueue(newcc);
            std::cout << newcc;
        }
    }
}
