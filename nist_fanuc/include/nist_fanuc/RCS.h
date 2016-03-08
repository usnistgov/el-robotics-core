// RCS.h
 
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


#ifdef STANDALONEURDF
#include "urdf_model/RobotModel.h"
#ifndef JointState
#define JointState urdf::JointState
#endif
#else
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include "/usr/include/urdf_model/model.h"ModelInterfaceSharedPtr
#include "/usr/include/urdf_model/joint.h"
#include "/usr/include/urdf_model/link.h"
#include "/opt/ros/indigo/include/sensor_msgs/JointState.h"

typedef boost::shared_ptr<urdf::Joint> JointSharedPtr;
typedef boost::shared_ptr<urdf::ModelInterface> ModelInterfaceSharedPtr;

typedef sensor_msgs::JointState_<std::allocator<void> > JointState;
typedef boost::shared_ptr<JointState> JointStateSharedPtr;

#if 0
#define URDF_TYPEDEF_CLASS_POINTER(Class)                           \
  class Class;                                                      \
  typedef boost::shared_ptr<Class> Class ##         SharedPtr;      
//  typedef boost::shared_ptr<const Class> Class ##   ConstSharedPtr; \
//  typedef boost::weak_ptr<Class> Class ## WeakPtr
namespace urdf {
    URDF_TYPEDEF_CLASS_POINTER(ModelInterface);
    // URDF_TYPEDEF_CLASS_POINTER(JointState);
    // URDF_TYPEDEF_CLASS_POINTER(Joint);
};
#endif
#endif

#include "urdf_model/rosmath.h"
#include <stdarg.h>
#include "Globals.h"


// These are defined as macros somewhere
#undef max
#undef min

#define LENGTHUNITS 1000
#define EPSILON                    1E-04
#define DEFAULT_CYCLE              0.010
#define DEFAULT_LOOP_CYCLE         0.10

#define DEFAULT_CART_MAX_ACCEL     20.0/LENGTHUNITS
#define DEFAULT_CART_MAX_VEL       200.0/LENGTHUNITS
#define DEFAULT_JOINT_MAX_ACCEL    20.0/LENGTHUNITS
#define DEFAULT_JOINT_MAX_VEL      150.0/LENGTHUNITS



namespace RCS {
    typedef urdf::Pose Pose;
    typedef urdf::Vector3 Position;
    typedef urdf::Rotation Rotation;
    typedef urdf::Vector3 Vector3;

    enum CanonLengthUnit {
        METER = 0,
        MM,
        INCH
    };

    enum TrajPointType {
        WAYPOINT = 1,
        GOAL
    };

    enum CanonAngleUnit {
        RADIAN = 0,
        DEGREE
    };

    enum CanonForceUnit {
        NEWTON = 0,
        POUND,
        OUNCE
    };

    enum CanonTorqueUnit {
        NEWTONMETER = 0,
        FOOTPOUND
    };

    enum CanonReturn {
        CANON_REJECT = -2,
        CANON_FAILURE = -1,
        CANON_SUCCESS = 0,
        CANON_STATUSREPLY = 1,
        CANON_RUNNING
    };

    enum CanonCmdType {
        CANON_NOOP = 0,
        CANON_DWELL,
        CANON_END_CANON,
        CANON_INIT_CANON,
        CANON_MOVE_JOINT,
        CANON_MOVE_TO,
        CANON_MOVE_THRU,
        CANON_SET_MAX_CART_ACC,
        CANON_SET_MAX_CART_SPEED,
        CANON_SET_MAX_JOINT_ACC,
        CANON_SET_MAX_JOINT_SPEED,
        CANON_SET_GRIPPER,
        CANON_STOP_MOTION,
        CANON_UNKNOWN
    };

    enum CanonStopMotionType {
        UNSET = -1,
        IMMEDIATE = 0,
        FAST,
        NORMAL
    };

    enum CanonAccProfile {
        MS_IS_UNSET = 0,
        MS_IS_DONE = 1,
        MS_IS_ACCEL = 2,
        MS_IS_CONST = 3,
        MS_IS_DECEL = 4,
        MS_IS_ESTOPPING = 5,
        MS_IS_PAUSED = 6,
    };

    enum MovementType {
        MOVE_DEFAULT = 0,
        MOVE_CARTESIAN,
        MOVE_JOINT
    };

    enum CanonStatusType {
        CANON_DONE = 0,
        CANON_WORKING,
        CANON_PAUSED,
        CANON_ERROR,
        CANON_ABORT,
        CANON_WAITING,
    };

    typedef double Length;
    typedef double LinearVelocity;
    typedef double AngularVelocity;
    typedef std::vector<double> robotAxes;

    struct CanonCmd {

        CanonCmd() {
            Init();
			CommandID()=_cmdid++;
        }
        void Init();
		VAR(CommandID, unsigned long long);
		VAR(ParentCommandID, unsigned long long);
		VAR(StatusID, unsigned long long);
		static unsigned long long _cmdid;

        CanonCmdType cmd;
        CanonStatusType status;
        TrajPointType type;
        CanonStopMotionType stoptype;
        bool bCoordinated;
        bool bStraight;
        double absTransAcc;
        double absTransSpeed;
        double absRotAcc;
        double absRotSpeed;
        double absJointAcc;
        double absJointSpeed;
        double dwell;
        double gripperPos; // 0 to 1
        CanonAccProfile accprofile;
        std::vector<double> speed;
        std::vector<int> jointnum;

        JointState joints;
        urdf::Pose pose;
        urdf::Pose tolerance;
        std::vector<urdf::Pose> waypoints;
    };

    struct CanonWorldModel {

        CanonWorldModel() {
            Init();
        }
        void Init();

        CanonCmdType echo_cmd;
        CanonStatusType echo_status;

        // void setMaxAccel(double accelIn, MovementType mType);
        // void setMaxVel(double velIn, MovementType mType);
        // double getMaxAccel(MovementType mType);
        // double getMaxVel(MovementType mType);

        double getCycleTime() {
            return _cycleTime; // milliseconds
        }

        ModelInterfaceSharedPtr robot_model;

        // //////////////////////
        // double maxAccel[3];
        // double maxVel[3];
        double maxTransAccel;
        double maxTransVel;
        double maxRotAccel;
        double maxRotVel;
        double maxJointAccel;
        double maxJointVel;
        double _cycleTime;
        CanonCmd echocmd;
        JointState currentjoints;
        urdf::Pose currentpose;
    };

    inline std::string DumpPose(urdf::Pose & pose) {
        std::stringstream s;

        s << "Translation = " << 1000.0 * pose.position.x << ":" << 1000.0 * pose.position.y << ":" << 1000.0 * pose.position.z << std::endl;

        // os << "Rotation = "  << pose.rotation.x << ":"<<  pose.rotation.y  << ":"<< pose.rotation.z << ":"<< pose.rotation.w << std::endl;
        double roll, pitch, yaw;
        _quatToRpy(pose.rotation,roll, pitch, yaw);
        s << "Rotation = " << Rad2Deg(roll) << ":" << Rad2Deg(pitch) << ":" << Rad2Deg(yaw) << std::endl;
        return s.str();
    }
    inline std::string DumpQuaterion(std::ostream & os, const urdf::Rotation & rot) {
        std::stringstream s;
        s << "Quaterion = ";
        s << boost::format("X=%8.4f") % rot.x << ":";
        s << boost::format("Y=%8.4f") % rot.y << ":";
        s << boost::format("Z=%8.4f") % rot.z << ":";
        s << boost::format("W=%8.4f") % rot.w << ":";
        s << std::endl;
        return s.str();
    }
};

inline std::ostream & operator<<(std::ostream & os, const RCS::CanonCmd & cc) {
    os << "Cmd = " << cc.cmd << " Status = " << cc.status << std::endl << "Joints = ";

    for (size_t i = 0; i < cc.joints.position.size(); i++) {
        os << i << "=" << Rad2Deg(cc.joints.position[i]) << ":";
    }
    os << std::endl;
    return os;
}

//
//template<typename T>
//inline std::ostream & operator<<(std::ostream & os, const std::vector<T> & v) {
//    os << "Vector = ";
//
//    for (size_t j = 0; j < v.size(); j++) {
//        os << boost::format("%8.4f") % Rad2Deg(v[j]) << ":";
//    }
//    os << std::endl;
//    return os;
//}


