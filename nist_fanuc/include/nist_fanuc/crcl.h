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



namespace Crcl
{
    enum CRCLCmdStatus
    {
        CRCL_DONE = 0,
        CRCL_WORKING,
        CRCL_ERROR
    };
    enum CrclReturn
    {
        CANON_REJECT      = -2,
        CANON_FAILURE     = -1,
        CANON_SUCCESS     = 0,
        CANON_STATUSREPLY = 1,
        CANON_RUNNING
    };

    typedef::ActuateJointsType::ActuateJoint_sequence   ActuatorJointSequence;
    typedef::PoseType                                   PoseType;
    typedef::JointStatusType                            JointStatus;
    typedef::CommandStateEnumType                       CommandStateEnum;
    typedef::PointType                                  PointType;
    typedef::VectorType                                 VectorType;
    typedef::CommandStateEnumType                       CommandStateEnum;
    typedef::JointStatusesType::JointStatus_sequence    JointStatusSequence;
    typedef::PoseToleranceType                          PoseToleranceType;
    typedef urdf::Vector3                               Vector3D;

    std::vector<double>             ConvertToPositionVector (ActuatorJointSequence &, double dConversion);
    JointStatusSequence             Convert (ActuatorJointSequence jin);
	// No angle conversion - rotation/orientation always in radians
    RCS::Pose                       Convert (Crcl::PoseType & pose, double lengthConversion = 1.0);
    Crcl::JointStatusSequence       Convert (JointState joints);
    sensor_msgs::JointState         Convert(Crcl::JointStatusSequence  jointStatusSeq, double angleConversion=1.0);
    Crcl::PoseType                  Init(std::vector<double> terms);
    Crcl::PoseType                  IdentityPose() ;
    std::string                     DumpPose (Crcl::PoseType pose, std::string separator);
    urdf::Vector3                   GetVector3D (Crcl::PointType & point);
    urdf::Vector3                   GetVector3D (Crcl::VectorType & vector);
    bool                            GetPoseToRPY (Crcl::PoseType & pose, double & dRoll, double & dPitch, double & dYaw);
    RosMatrix                       GetXZRotMatrix (urdf::Vector3 Xrot, urdf::Vector3 Zrot);
    bool                            GetRPY (urdf::Vector3 Xrot, urdf::Vector3 Zrot, double & dRoll, double & dPitch, double & dYaw);
    urdf::Rotation                  Convert (urdf::Vector3 Xrot, urdf::Vector3 Zrot);
    PoseType                        NullPose ( );
    PoseType                        PoseHome ( );
    Crcl::VectorType                VectorZero ( );
    struct GripperStatus
    {
        std::string _name;
        double      _dPosition; // 0..1
    };

    struct JointReport
    {
        size_t _nJointNumber;
        bool   _bReportPosition;
        bool   _bReportTorqueOrForce;
        bool   _bReportVelocity;
    };

    struct CrclStatus
    {
        CrclStatus( );
        Crcl::JointStatusSequence   JointsHome ( );
        Crcl::ActuatorJointSequence Merge (Crcl::ActuatorJointSequence, bool bIncremental = false);

        GripperStatus               gripper;
//        void                        Update (unsigned long long CommandID,
//            Crcl::CommandStateEnum                             state,
//            Crcl::JointStatusSequence &                        joints,
//            Crcl::PoseType &                                   _pose);
        void                        Update (unsigned long long CommandID);
        void                        Update (Crcl::CommandStateEnum state);
        void                        Update (Crcl::JointStatusSequence & joints, RCS::TrajPointType type = RCS::WAYPOINT);
        void                        Update (Crcl::PoseType & pose, RCS::TrajPointType type = RCS::WAYPOINT);
        void                        Update (JointState & joints);
        void                        Update (urdf::Pose & pose);

        //VAR(GoalPose, Crcl::PoseType);
        //VAR(CurrentPose, Crcl::PoseType);
        VAR(CommandID, unsigned long long);
        VAR(StatusID, unsigned long long);
        VAR(CommandStatus, Crcl::CommandStateEnum);

        // //////////////////////////////////////////////////
        Crcl::PoseType _CurrentPose, _GoalPose;
        Crcl::JointStatusSequence   _GoalJoints;
        Crcl::JointStatusSequence   _CurrentJoints;
        std::vector<double>         _speeds; // for each axis
        double                      _translationSpeed;
        double                      _translationAccel;
        double                      _rotSpeed;
        double                      _rotAccel;
        bool                        _bCoordinatedMotion;

        // Conversion variables
        RCS::CanonLengthUnit        _lengthUnit;
        double                      _lengthConversion;

        RCS::CanonAngleUnit         _angleUnit;
        double                      _angleConversion;

        RCS::CanonForceUnit         _forceUnit;
        double                      _forceConversion;

        RCS::CanonTorqueUnit        _torqueUnit;
        double                      _torqueConversion;

        Crcl::PoseToleranceType     _endPoseTolerance;
        Crcl::PoseToleranceType     _gripperPoseTolerance;
        Crcl::PoseToleranceType     _intermediatePoseTolerance;
        std::vector<JointReport>    _vJointReport;
        std::string                 sCommandState;
        std::string                 Alarm;
    };

    inline std::ostream & operator << (std::ostream & os, const Crcl::PoseType & pose)
    {
        os << "Pose = (";
        os << boost::format("X=%8.4f") % pose.Point( ).X( ) << ",";
        os << boost::format("X=%8.4f") % pose.Point( ).Y( ) << ",";
        os << boost::format("X=%8.4f") % pose.Point( ).Z( ) << ")(";
        os << boost::format("X=%8.4f") % pose.XAxis( ).I( ) << ",";
        os << boost::format("X=%8.4f") % pose.XAxis( ).J( ) << ",";
        os << boost::format("X=%8.4f") % pose.XAxis( ).K( ) << ")(";
        os << boost::format("X=%8.4f") % pose.ZAxis( ).I( ) << ",";
        os << boost::format("X=%8.4f") % pose.ZAxis( ).J( ) << ",";
        os << boost::format("X=%8.4f") % pose.ZAxis( ).K( ) << ")";
        os << std::endl;
        return os;
    }
};
