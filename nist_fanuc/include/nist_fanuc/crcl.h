// crcl.h

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

#define _USE_MATH_DEFINES
#include <math.h>       /* isnan, sqrt */
#include "RCS.h"

// CRCL CodeSynthesis XML interface
#undef _GLIBCXX_DEPRECATED

#include "DataPrimitives.hxx"
#include "CRCLCommands.hxx"
#include "CRCLStatus.hxx"
#include "CRCLCommandInstance.hxx"
#include "CRCLProgramInstance.hxx"

#include "Globals.h"



namespace Crcl {
    struct CrclStatus;
    struct GripperStatus;
    struct JointReport;

    enum CRCLCmdStatus {
        CRCL_Done = 0,
        CRCL_Error,
        CRCL_Working,
        CRCL_Ready
    };

    enum CrclReturn {
        CANON_REJECT = -2,
        CANON_FAILURE = -1,
        CANON_SUCCESS = 0,
        CANON_STATUSREPLY = 1,
        CANON_MOTION = 2,
        CANON_RUNNING,
        CANON_NOT_IMPLEMENTED
    };

    typedef::ActuateJointsType::ActuateJoint_sequence ActuatorJointSequence;
    typedef::PoseType PoseType;
    typedef::JointStatusType JointStatus;
    typedef::CommandStateEnumType CommandStateEnum;
    typedef::PointType PointType;
    typedef::VectorType VectorType;
    typedef::CommandStateEnumType CommandStateEnum;
    typedef::JointStatusesType::JointStatus_sequence JointStatusSequence;
    typedef::PoseToleranceType PoseToleranceType;
    typedef RCS::Vector3 Vector3D;

    /*!
     * \brief ConvertToPositionVector converts codesynthesis actuator sequence into std vector of position as doubles.
     * \param  codesynthesis sequence of joints.
     * \param  conversion factor for each joint (e.g., degree to radian).
     * \return std vector of doubles representing position.
     */
    std::vector<double> ConvertToPositionVector(ActuatorJointSequence &, double dConversion);

    /*!
     * \brief Convert converts codesynthesis commanded actuator joint sequence into status actuator joint sequence .
     * \param  codesynthesis sequence of commanded joints.
     * \return codesynthesis sequence of status joints.
     */
    JointStatusSequence Convert(ActuatorJointSequence jin);

    /*!
     * \brief Convert converts codesynthesis status actuator joint sequence into ROS JointState.(Fills position).
     * \param  codesynthesis sequence of status joints.
     * \param  conversion factor for each joint (e.g., degree to radian).
     * \return ROS JointState with Joint positions filled.
     */
    sensor_msgs::JointState Convert(Crcl::JointStatusSequence jointStatusSeq, double angleConversion = 1.0);

    /*!
     * \brief Convert converts ROS JointState  (primarily position for now) and creates codesynthesis status actuator joint sequence.
     * \param ROS JointState with Joint positions filled.
     * \return  codesynthesis sequence of status joints.
     */
    Crcl::JointStatusSequence Convert(JointState joints);

    /*!
     * \brief Convert converts ROS/RCS pose into codesynthesis Crcl Pose.
     * Note, no angle conversion - rotation/orientation always in radians
     * \param  ROS/RCS pose.
     * \return  codesynthesis CRCL pose type.
     */
    Crcl::PoseType Convert(RCS::Pose pose);

    /*!
     * \brief Convert converts codesynthesis Crcl Pose into ROS/RCS pose using length conversion .
     * Note, no angle conversion - rotation/orientation always in radians
     * \param  codesynthesis CRCL pose type.
     * \param lengthConversion to make length in meters. (e.g., if mm input, conversion = 0.001).
     * \return  ROS/RCS pose.
     */
    RCS::Pose Convert(Crcl::PoseType & pose, double lengthConversion = 1.0);

    /*!
     * \brief Convert converts codesynthesis Crcl rotation (as x,z rotation vectors) into ROS/RCS rotation.
     * \param  codesynthesis CRCL x,z rotation vectors as used in pose.
     * \return   ROS/RCS rotation.
     */
    RCS::Rotation Convert(RCS::Vector3 Xrot, RCS::Vector3 Zrot);

    /*!
     * \brief Get roll,pitch,yaw orientation from codesynthesis Crcl pose.
     * \param  codesynthesis CRCL pose.
     * \param  roll,pitch, yaw reference to doubles that will be filled with angles in radians.
     * \return   true if sucessful, false otherwise.
     */
    bool GetPoseToRPY(Crcl::PoseType & pose, double & dRoll, double & dPitch, double & dYaw);


    RCS::Pose Convert(Crcl::PoseToleranceType);

    /*!
     * \brief Dump contents of codesynthesis Crcl pose.
     * \param  codesynthesis CRCL pose.
     * \param  separator defines character to use a separater between values (e.g., "," for csv).
     * \return   string with Crcl pose contents.
     */
    //std::string DumpCrclPose(Crcl::PoseType pose, std::string separator=",");
    std::string DumpPosition(Crcl::PoseType pose, std::string separator = ",");
    std::string DumpRotationAsCrcl(RCS::Pose rcspose, std::string separator= ",");
    std::string DumpRotationAsCrcl(Crcl::PoseType crclpose, std::string separator = ",");
    std::string DumpPose(Crcl::PoseType pose, std::string separator = ",");
    std::string DumpStatusReply(Crcl::CrclStatus *wm);
    std::string DumpCrclCommand(::CRCLCommandType & crclCommand);
    std::string DumpCrclJoints(Crcl::JointStatusSequence);

    /*!
     * \brief Create codesynthesis Crcl pose that is necessary for all codesynthesis Crcl pose constructors.
     * \return  empty codesynthesis Crcl pose.
     */
    PoseType PoseHome();
    Crcl::PoseType NullPose();

    /**
     * \brief GripperStatus  dummy class for future gripper information. 
     */
    struct GripperStatus {
        std::string _name;
        double _dPosition; // 0..1
    };
    
    /**
     * \brief JointReport  dummy class for future customization of Crcl status reports. 
     */
    struct JointReport {
        size_t _nJointNumber;
        bool _bReportPosition;
        bool _bReportTorqueOrForce;
        bool _bReportVelocity;
    };

    /**
     * \brief CrclStatus  is a class that encapsulates all the CRCL information. 
     * All lot of the knowledge is converting ROS oriented RCS data into codesynthesis Crcl representation and vice versa.
     * CrclStatus maintains the unit a crcl session uses to transmit robot commands,
     * latest robot status, etc. 
     */
    struct CrclStatus {
        CrclStatus();
        Crcl::JointStatusSequence JointsHome();
 
        GripperStatus gripper;
        //        void                        Update (unsigned long long CommandID,
        //            Crcl::CommandStateEnum                             state,
        //            Crcl::JointStatusSequence &                        joints,
        //            Crcl::PoseType &                                   _pose);
        void Update(unsigned long long CommandID);
        void Update(Crcl::CommandStateEnum state);
        void Update(Crcl::JointStatusSequence & joints, RCS::TrajPointType type = RCS::WAYPOINT);
        void Update(Crcl::PoseType & pose, RCS::TrajPointType type = RCS::WAYPOINT);
        void Update(JointState & joints);
        void Update(RCS::Pose & pose);

        //VAR(GoalPose, Crcl::PoseType);
        //VAR(CurrentPose, Crcl::PoseType);
        VAR(CommandID, unsigned long long);
        VAR(StatusID, unsigned long long);
        VAR(CommandStatus, Crcl::CommandStateEnum);
        VAR(Rates, RCS::IRate);

        // //////////////////////////////////////////////////
        Crcl::PoseType _CurrentPose, _GoalPose;
        Crcl::JointStatusSequence _GoalJoints;
        Crcl::JointStatusSequence _CurrentJoints;
        std::vector<double> _speeds; // for each axis
        double _translationSpeed;
        double _translationAccel;
        double _rotSpeed;
        double _rotAccel;
        bool _bCoordinatedMotion;

        // Conversion variables
        RCS::CanonLengthUnit _lengthUnit;
        double _lengthConversion;

        RCS::CanonAngleUnit _angleUnit;
        double _angleConversion;

        RCS::CanonForceUnit _forceUnit;
        double _forceConversion;

        RCS::CanonTorqueUnit _torqueUnit;
        double _torqueConversion;

        // Tolerance data structures
        //std::vector<Crcl::PoseToleranceType> _intermediatePoseTolerance; // one only
        Crcl::PoseToleranceType _endPoseTolerance;
        Crcl::PoseToleranceType _gripperPoseTolerance;
        Crcl::PoseToleranceType _intermediatePoseTolerance;

        std::vector<JointReport> _vJointReport;
        std::string sCommandState;
        std::string Alarm;
    };
};
