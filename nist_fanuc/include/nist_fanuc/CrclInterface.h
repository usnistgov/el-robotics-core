// CrclInterface.h

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
#include <string>
#include "crcl.h"
#include <iostream>

/**
 * For crcl example xml files visit:
 * https://github.com/ros-industrial/crcl/blob/master/instances
 */

#include <string>
#include <vector>
#include "Globals.h"

class CAsioCrclSession;

namespace Crcl
{
    // -----------------------------------------------------=
    class CrclDelegateInterface
    {
public:
        CrclDelegateInterface() {}
 
        unsigned long long & GetCommandNum ( )
        {
            return _nCommandNum;
        }

        CrclReturn         DelegateCRCLCmd (std::string str);
        void               CrclRunProgram(::CRCLProgramType::MiddleCommand_sequence cmds);
        CrclReturn         DelegateCRCLCmd(::CRCLCommandType &crclCommand);
        static CrclStatus crclwm; // this is crcl wm different that controller wm

        // ////////////////////////////////////////////////////////////
        // These methods are called from  DelegateCRCLCmd after parsing XML

        virtual CrclReturn ActuateJoints (Crcl::ActuatorJointSequence joints);
        virtual CrclReturn CloseToolChanger ( );
        virtual CrclReturn ConfigureJointReports (std::vector<Crcl::JointReport> & jointReports);
        virtual CrclReturn Couple (char *targetID);
        virtual CrclReturn Dwell (double seconds);
        virtual CrclReturn EndCanon ( );
        virtual CrclReturn InitCanon ( );
        virtual CrclReturn GetStatus ( );
        virtual CrclReturn Message (std::string message);
        virtual CrclReturn MoveTo (Crcl::PoseType endpose, bool bStraight);
        virtual CrclReturn MoveThroughTo (std::vector<Crcl::PoseType> & poses, bool bStraight);
        virtual CrclReturn OpenToolChanger ( );
        virtual CrclReturn RunProgram (std::string programText);
        virtual CrclReturn SetAbsoluteAcceleration (double acceleration);
        virtual CrclReturn SetAbsoluteSpeed (double speed);
        virtual CrclReturn SetAngleUnits (std::string unitName);
        virtual CrclReturn SetAxialSpeeds (std::vector<double> speeds);
        virtual CrclReturn SetEndEffector (double percent);
        virtual CrclReturn SetEndEffectorTolerance (Crcl::PoseToleranceType dTolerance);
        virtual CrclReturn SetEndPoseTolerance (Crcl::PoseToleranceType tolerance);
        virtual CrclReturn SetForceUnits (std::string unitName);
        virtual CrclReturn SetIntermediatePoseTolerance (Crcl::PoseToleranceType tolerance);
        virtual CrclReturn SetLengthUnits (std::string unitName);
        virtual CrclReturn SetMotionCoordination (bool bCoordinatedMotion);
        virtual CrclReturn SetParameter (char *paramName, void *paramVal);
        virtual CrclReturn SetRelativeAcceleration (double percent);
        virtual CrclReturn SetRelativeSpeed (double percent);
        virtual CrclReturn SetRotAccel (double accel);
        virtual CrclReturn SetRotSpeed (double speed);
        virtual CrclReturn SetTorqueUnits (std::string unitName);
        virtual CrclReturn SetTransAccel (double accel);
        virtual CrclReturn SetTransSpeed (double speed);
        virtual CrclReturn StopMotion (int condition);

        // extensions
        virtual CrclReturn GetTool (double *percent)
        {
            return CANON_SUCCESS;
        }

        // enum JointMax { Num=6 };
       std::string        FindLeadingElement (std::string xml);
private:
 
        unsigned long long _nCommandNum;
        boost::thread      m_thread;
    };

    // -----------------------------------------------------=
    class CrclClientCmdInterface
    {
public:
        CrclClientCmdInterface( ) { }
        void SetCommandNum (unsigned long long n)
        {
            _commandnum = n;
        }

        // Command interface

        // std::string ActuateJoints (robotAxes joints);
        // std::string ActuateJoint (robotAxes joints, int jointnum);
        std::string CloseToolChanger ( );
        std::string Dwell (double seconds);
        std::string EndCanon (int reason);
        std::string GetStatus ( );
        std::string InitCanon ( );
        std::string Message (std::string message);

        std::string MoveScrew (Crcl::PoseType startPost, VectorType axisPoint, double dAxialDistanceFree, double dAxialDistanceScrew, double dTurn);
        std::string MoveTo (Crcl::PoseType pose, bool bStraight = true);
        std::string MoveThroughTo (Crcl::PoseType *poses,
            int                                    numPoses,
            double *                               accelerations = NULL,
            double *                               speeds = NULL,
            Crcl::PoseToleranceType *              tolerances = NULL);
        std::string OpenToolChanger ( );
        std::string RunProgram (std::string programText);
        std::string SetEndEffector (double fractionalSetting);
        std::string SetEndPoseTolerance (Crcl::PoseToleranceType toleranceSetting);
        std::string SetEndEffectorTolerance (Crcl::PoseToleranceType toleranceSetting);
        std::string SetAngleUnits (std::string UnitName);  // UnitName is a string that can be only the literals 'angle' or 'radian'.
        std::string SetLengthUnits (std::string UnitName); // UnitName is a string that can be only the literals 'meter',  'millimeter', or 'inch'.
        std::string SetMotionCoordination (bool bCoordinated);
        std::string SetRotAccel (double dAccel);
        std::string SetRotSpeed (double dSpeed);
        std::string StopMotion (int condition);  // 0=Immediate, Fast, Normal

        std::string GetStatusReply (CrclStatus *wm);
private:
        static unsigned long long _commandnum;
    };

    // -----------------------------------------------------=
    class CrclStatusMsgInterface
    {
public:
        CrclStatusMsgInterface( ) { }
        void        ParseCRCLStatus (std::string filename);
        void        ParseCRCLStatusString (std::string str);

        CrclStatus _status;
    };
};
