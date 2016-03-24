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

namespace Crcl {

    /**
     * \brief CrclDelegateInterface parses Crcl commands and interprets into robot motion.
     *   https://github.com/usnistgov/crcl/blob/master/doc/Reference.md
     */

    class CrclDelegateInterface {
    public:

        CrclDelegateInterface() {
        }

        unsigned long long & GetCommandNum() {
            return _nCommandNum;
        }

        CrclReturn DelegateCRCLCmd(std::string str);
        void CrclRunProgram(::CRCLProgramType::MiddleCommand_sequence cmds);
        CrclReturn DelegateCRCLCmd(::CRCLCommandType &crclCommand);
        static CrclStatus crclwm; // this is crcl wm different that controller wm

        // ////////////////////////////////////////////////////////////
        // These methods are called from  DelegateCRCLCmd after parsing XML


        /*!
         * \brief Actuate the joints of the robot as specified.
         * The joints argument is a list of instances of ActuateJointType. Each joint may appear at most once on the list. 
         * If a joint is not on the list, its actuation should be as previously set.
         * \param joints is codesynthesis C++ representation that contains:
         *  <BR> a JointNumber that identifies the joint
         *  <BR>a JointPosition that is the target position for the joint
         *  <BR>JointDetails that provides either(1) the speed and acceleration to use in getting to the position or (2) the force or torque and rate of change of force or torque to use in getting to the position.
         */
        virtual CrclReturn ActuateJoints(Crcl::ActuatorJointSequence joints);

        /*!
         * \brief Close the tool changer on the robot so that it attaches to an end effector..
         * The robot must be in an appropriate position with respect to the end 
         * effector for the changer mechanism on the robot to attach to the end effector.
         */
        virtual CrclReturn CloseToolChanger();

        /*!
         * \brief Specify how the status of the robot joints should be reported.
         * This may be used only if CRCL status is being reported.
         * The value of ResetAll is either true or false. Joints is a list of of instances of ConfigureJointReportType. 
         * Each joint may appear at most once on the list.      
         * */
        virtual CrclReturn ConfigureJointReports(std::vector<Crcl::JointReport> & jointReports);
        virtual CrclReturn Couple(char *targetID);
        /*!
         * \brief  Stay motionless for the given amount of time in seconds.
         * \param dwell time in seconds
         */
        virtual CrclReturn Dwell(double seconds);

        /*!
         * \brief  Do whatever is necessary to stop executing canonical robot commands.
         * No specific action is required. The robot controller should not 
         * execute any canonical robot command except InitCanon after 
         * executing EndCanon and should signal an error if it is given one. 
         * This command will normally be given when execution of a plan is 
         * complete but may also be given if an error is detected, or for any other reason.
         */
        virtual CrclReturn EndCanon();

        /*!
         * \brief  Command to retrieve status immediately.
         * This may be used only if CRCL status is being reported.
         */
        virtual CrclReturn GetStatus();

        /*!
         * \brief  Do whatever is necessary to get ready to move.
         * All units are set to the default units. This command will normally 
         * be given when a plan interpreter opens a plan to be executed.
         */
        virtual CrclReturn InitCanon();


        /*!
         * \brief  Display the given message on the operator console.
         * \param message to display on console
         * \return If there is no operator console, this command has no effect and should be reported as executed without error.
         */
        virtual CrclReturn Message(std::string message);

        /*!
         * \brief  Move the controlled point to the given pose, and stop there.
         * The robot must reach the pose within the tolerance established (1) 
         * by the tolerance given for the pose, if there is a tolerance in the 
         * pose, or if not (2) by the most recently executed instance of 
         * SetEndPoseTolerance. The speed and acceleration to use are set 
         * either in the pose or by previously executed CRCL commands.
         * \param bStraight if the value of straight is true, the controlled 
         * point must be moved in a straight line. If the value of straight is 
         * false, the controlled point may be moved along any convenient trajectory.
         * \param endpose  may include settings for speed, acceleration, and 
         * tolerance. Any such settings apply only while the command is being 
         * executed, after which the settings revert to what they were.
         */
        virtual CrclReturn MoveTo(Crcl::PoseType endpose, bool bStraight);

        /*!
         * \brief  Move the controlled point along a trajectory passing near all but the last of the given waypoints (poses), and stop at the last of the given waypoints. 
         * The robot must pass each waypoint within the tolerance established 
         * <BR> (1) by the tolerance given for the pose in the waypoint, if 
         * there is a tolerance in the waypoint, or if not 
         * <BR> (2) by the most recently executed instance of 
         * SetIntermediatePoseToleranceType (or by SetEndPoseToleranceType for 
         * the final waypoint).
         * The speed and acceleration to use are set either in the waypoint or 
         * by previously executed CRCL commands.
         * If the value of straight is true, the controlled point must be moved 
         * in a straight line between waypoints. If the value of straight is 
         * false, the controlled point may be moved along any convenient 
         * trajectory between waypoints. In either case, there are no 
         * restrictions on the values of XAxis and ZAxis between waypoints.
         * The numberWaypoints gives the number of waypoints.
         * \param waypoints list of poses to move thru
         * \param bStraight if the value of straight is true, the controlled 
         * point must be moved in a straight line. If the value of straight is 
         * false, the controlled point may be moved along any convenient trajectory.        */
        virtual CrclReturn MoveThroughTo(std::vector<Crcl::PoseType> & waypoints, bool bStraight);

        /*!
         * \brief   Open the tool changer on the robot.
         * If an end effector is attached to the robot when this command is given, 
         * executing the command releases the end effector.
         * This command is normally given only after an end effector attached to the robot has been moved into an end effector changer.
         */
        virtual CrclReturn OpenToolChanger();


        /*!
         * \brief  Run a program written in a non-CRCL language that the robot controller understands.
         * \programText is the program represented as a string of text.
         */
        virtual CrclReturn RunProgram(std::string programText);

        /*!
         * \brief 
         */
        virtual CrclReturn SetAbsoluteAcceleration(double acceleration);

        /*!
         * \brief 
         */
        virtual CrclReturn SetAbsoluteSpeed(double speed);

        /*!
         * \brief  Set angle units to the named unit.
         * \param unitName is the unit name must be either "degree" or "radian". 
         * After this command is executed, all commands that use angle units 
         * (for orientation or orientation tolerance) are in terms of 
         * the named angle unit. Existing values for orientation are converted 
         * automatically to the equivalent value in new angle units. 
         * The default angle unit is "radian".
         */
        virtual CrclReturn SetAngleUnits(std::string unitName);

        /*!
         * \brief 
         */
        virtual CrclReturn SetAxialSpeeds(std::vector<double> speeds);

        /*!
         * \brief  Set the effectivity of the end effector.
         * The setting is a number between zero and one.
         * If an end effector has multiple control modes, the control mode 
         * must be set using a SetEndEffectorParameters command, so that 
         * the meaning of SetEndEffector commands is unambiguous.
         * 
         * \param percent - for end effectors that have a continuously variable setting, the
         * setting means a fraction of maximum openness, force, torque, 
         * power, etc.
         * 
         *For end effectors that have only two choices (powered or unpowered, 
         * open or closed, on or off), a positive setting value means powered, 
         * open, or on, while a zero setting value means unpowered, closed, or
         *  off.
         */
        virtual CrclReturn SetEndEffector(double percent);

        /*!
         * \brief 
         */
        virtual CrclReturn SetEndEffectorTolerance(Crcl::PoseToleranceType dTolerance);

        /*!
         * \brief  et the tolerance for the position and orientation of the
         *  end of the arm (whenever there is no gripper there) or of the 
         * gripper (whenever a gripper is on the end of the arm) to the given 
         * value.
         * \param tolerance is the tolerance argument specifies both position 
         * tolerance in length units and orientation  tolerance in angle units. 
         */
        virtual CrclReturn SetEndPoseTolerance(Crcl::PoseToleranceType tolerance);

        /*!
         * \brief  Set force units to the named unit.
         * After this command is executed, all commands that use force units are
         *  in terms of the named force unit. The default force unit is "newton".
         *  \param unitName must be one of "newton", "pound", or "ounce". 
         */
        virtual CrclReturn SetForceUnits(std::string unitName);

        /*!
         * \brief  Set the tolerance for smooth motion near intermediate points.
         * \param tolerance argument specifies both position tolerance in 
         * length units and orientation tolerance in angle units.
         */
        virtual CrclReturn SetIntermediatePoseTolerance(Crcl::PoseToleranceType tolerance);

        /*!
         * \brief  Set length units to the named unit. 
         * After this command is executed, all commands that use length units (for location, tolerance, speed, and acceleration) are in terms of the named length unit. Existing values for speed, position, acceleration, etc. are converted automatically to the equivalent value in new length units. The default length unit is "meter".
         * \param unitName must be one of "inch", "mm" or "meter". 
         */
        virtual CrclReturn SetLengthUnits(std::string unitName);

        /*!
         * \brief  Either require rotational motion and translational motion to
         *  be coordinated or allow them to be uncoordinated.
         * Motion is coordinated when rotational motion and translational motion
         *  must finish simultaneously in motion commands (including each 
         * segment in a multiple segment motion command), except as possibly 
         * temporarily overridden in the the motion command.
         * \param bCoordinatedMotion is the coordinated parameter is a boolean value. True means require 
         * coordinated motion. False means allow uncoordinated motion.
         */
        virtual CrclReturn SetMotionCoordination(bool bCoordinatedMotion);

        /*!
         * \brief   Set one or more robot parameters as specified.
         * The meaning of the parameter is not known to CRCL, but 
         * the robot controller knows what it means.
         * This command is not to be used to set any parameter that can be set
         *  using a CRCL command.
         * \param paramName Each specified parameter has a name that is a string 
         * \param a value that is a string. 
         */
        virtual CrclReturn SetParameter(char *paramName, void *paramVal);

        /*!
         * \brief 
         */
        virtual CrclReturn SetRelativeAcceleration(double percent);

        /*!
         * \brief  Set rotational acceleration to the given setting in current 
         * angle units per second per second.
         * \param accel is either an absolute value or a fraction of the 
         * maximum rotational acceleration.
         */
        virtual CrclReturn SetRotAccel(double accel);

        /*!
         * \brief  Set rotational speed to the given setting in current angle 
         * units per second.
         * \param speed is may be either an absolute value or a fraction of the 
         * maximum rotational speed.
         */
        virtual CrclReturn SetRotSpeed(double speed);

        /*!
         * \brief  Set torque units to the named unit.
         * This tells the robot that all further commands giving torque values 
         * will implicitly use the named unit. The default torque unit is "newtonMeter".
         * \param unitName must be one of "newtonMeter", or "footPound". 
         */
        virtual CrclReturn SetTorqueUnits(std::string unitName);

        /*!
         * \brief  Set translational acceleration to the given setting in current 
         * length units per second per second.
         * \param accel may be either an absolute value or a fraction of the maximum
         *  translational acceleration.
         */
        virtual CrclReturn SetTransAccel(double accel);

        /*!
         * \brief  Set translational speed to the given setting in current length 
         * units per second.
         * \param speed may be either an absolute value or a fraction of the 
         * maximum translational speed.
         */
        virtual CrclReturn SetTransSpeed(double speed);

        /*!
         * \brief  Stop the robot motion according to the given condition, Immediate, Fast, or Normal.
         * Immediate means the robot's drives are deactivated immediately and the 
         * brakes are applied. This may result in the controlled point being off 
         * the commanded path when the robot stops.
         * 
         * Fast means the robot and any external axes are brought to a fast, 
         * controlled stop. The drives are deactivated after one second, and 
         * the brakes are applied. The controlled point must be kept on the on 
         * the commanded path as the robot stops.
         * 
         * Normal means the robot and any external drives are stopped using a 
         * normal braking ramp. The drives are not deactivated, and the brakes 
         * are not applied. The controlled point must be kept on the on the commanded
         * path as the robot stops.
         * \param condition is either Immediate, Fast, or Normal
         */
        virtual CrclReturn StopMotion(int condition);

        // extensions

        virtual CrclReturn GetTool(double *percent) {
            return CANON_SUCCESS;
        }

        // enum JointMax { Num=6 };
        std::string FindLeadingElement(std::string xml);
    private:

        unsigned long long _nCommandNum;
        boost::thread m_thread;
    };

    /**
     * \brief CrclClientCmdInterface generates Crcl XML command message from 
     * to send to a Crcl server.
     */
    class CrclClientCmdInterface {
    public:

        CrclClientCmdInterface() {
        }

        void SetCommandNum(unsigned long long n) {
            _commandnum = n;
        }

        // Command interface

        // std::string ActuateJoints (robotAxes joints);
        // std::string ActuateJoint (robotAxes joints, int jointnum);
        std::string CloseToolChanger();
        std::string Dwell(double seconds);
        std::string EndCanon(int reason);
        std::string GetStatus();
        std::string InitCanon();
        std::string Message(std::string message);

        std::string MoveScrew(Crcl::PoseType startPost, VectorType axisPoint, double dAxialDistanceFree, double dAxialDistanceScrew, double dTurn);
        std::string MoveTo(Crcl::PoseType pose, bool bStraight = true);
        std::string MoveThroughTo(Crcl::PoseType *poses,
                int numPoses,
                double * accelerations = NULL,
                double * speeds = NULL,
                Crcl::PoseToleranceType * tolerances = NULL);
        std::string OpenToolChanger();
        std::string RunProgram(std::string programText);
        std::string SetEndEffector(double fractionalSetting);
        std::string SetEndPoseTolerance(Crcl::PoseToleranceType toleranceSetting);
        std::string SetEndEffectorTolerance(Crcl::PoseToleranceType toleranceSetting);
        std::string SetAngleUnits(std::string UnitName); // UnitName is a string that can be only the literals 'angle' or 'radian'.
        std::string SetLengthUnits(std::string UnitName); // UnitName is a string that can be only the literals 'meter',  'millimeter', or 'inch'.
        std::string SetMotionCoordination(bool bCoordinated);
        std::string SetRotAccel(double dAccel);
        std::string SetRotSpeed(double dSpeed);
        std::string StopMotion(int condition); // 0=Immediate, Fast, Normal

        std::string GetStatusReply(CrclStatus *wm);
    private:
        static unsigned long long _commandnum;
    };

    /**
     * \brief CrclStatusMsgInterface parses a Crcl XML status message from 
     * a Crcl server.
      */
    class CrclStatusMsgInterface {
    public:

        CrclStatusMsgInterface() {
        }
        void ParseCRCLStatus(std::string filename);
        void ParseCRCLStatusString(std::string str);

        CrclStatus _status;
    };
};
