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

	/*!
	* \brief enumeration of  length units. Conversion into ROS compatible meters.
	*/
    enum CanonLengthUnit {
        METER = 0,
        MM,
        INCH
    };

	/*!
	* \brief enumeration of trajector pose points.
	*/
    enum TrajPointType {
        WAYPOINT = 1,
        GOAL
    };

	/*!
	* \brief enumeration of  angle units. Conversion into ROS compatible radians.
	*/
    enum CanonAngleUnit {
        RADIAN = 0,
        DEGREE
    };

	/*!
	* \brief enumeration of  force units. 
	*/
    enum CanonForceUnit {
        NEWTON = 0,
        POUND,
        OUNCE
    };

	/*!
	* \brief enumeration of  torque units. 
	*/
    enum CanonTorqueUnit {
        NEWTONMETER = 0,
        FOOTPOUND
    };

	/*!
	* \brief enumeration of  return type from Crcl intepretation. If statusreply, requires status
	* sent to Crcl client.
	*/
    enum CanonReturn {
        CANON_REJECT = -2,
        CANON_FAILURE = -1,
        CANON_SUCCESS = 0,
        CANON_STATUSREPLY = 1,
        CANON_RUNNING
    };

	/*!
	* \brief enumeration of   Crcl commands. Many Crcl commands are wm parameter setting
	* and require no motion component.
	*/
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

	/*!
	* \brief enumeration of  stopping motion, e.g., estop equivalent to immediate.
	*/
	enum CanonStopMotionType {
        UNSET = -1,
        IMMEDIATE = 0,
        FAST,
        NORMAL
    };

	/*!
	* \brief enumeration of  trajectory acceleration profile.
	*/
    enum CanonAccProfile {
        MS_IS_UNSET = 0,
        MS_IS_DONE = 1,
        MS_IS_ACCEL = 2,
        MS_IS_CONST = 3,
        MS_IS_DECEL = 4,
        MS_IS_ESTOPPING = 5,
        MS_IS_PAUSED = 6,
    };

	/*!
	* \brief enumeration of  trajectory motion type, joint or cartesian.
	*/
    enum MovementType {
        MOVE_DEFAULT = 0,
        MOVE_CARTESIAN,
        MOVE_JOINT
    };

	/*!
	* \brief enumeration of controller status types for individual commands. 
	* Note, even though command types are listed, not all used or supported.
	*/
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

	/*!
	* \brief CanonCmd is the controller command structure. 
	*/
	struct CanonCmd {

		/*!
		* \brief CanonCmd constructor. 
		*/
        CanonCmd() {
            Init();
			CommandID()=_cmdid++;
        }
        void Init();

		VAR(CommandID, unsigned long long);
		VAR(ParentCommandID, unsigned long long);
		VAR(StatusID, unsigned long long);
		static unsigned long long _cmdid;

        CanonCmdType cmd; /**<  command  type */
        CanonStatusType status; /**<  status type */
        TrajPointType type; /**<  trajectory points  type */
        CanonStopMotionType stoptype; /**<  stop trajectory choice */
        bool bCoordinated; /**<  coordinated joint trajectory motion boolean */
        bool bStraight; /**<  straigth cartesian trajectory motion boolean */
        double absTransAcc; /**<  cartesian translational acceleration */
        double absTransSpeed; /**<  cartesian translational velocity */
        double absRotAcc; /**<  cartesian rotation acceleration */
        double absRotSpeed; /**<  cartesian rotation velocity */
        double absJointAcc; /**<  joint max acceleration */
        double absJointSpeed; /**<  joint max velocity */
        double dwell; /**<  time for dwelling in seconds */
        double gripperPos; /**<  gripper position 0 to 1 */ 
        CanonAccProfile accprofile; /**<  current trajectory acceleration profile */ 
        std::vector<double> speed; /**<  vector of joint velocities */ 
        std::vector<int> jointnum; /**<  vector of joint numbers used by command */

        JointState joints; /**<  commanded joint state */
        urdf::Pose pose;  /**<  commanded pose state */
        urdf::Pose tolerance;  /**<  commanded tolerance */
        std::vector<urdf::Pose> waypoints; /**< commanded cartesian waypoints in trajectory */
    };

	/*!
	* \brief CanonWorldModel describes the controller state. Includes reference to robot model.
	*/
    struct CanonWorldModel {

		/*!
		* \brief CanonWorldModel constructor that initializes parameterization.
		*/
		CanonWorldModel() {
            Init();
        }
        void Init();

        CanonCmdType echo_cmd; /**<  copy of current command type */
        CanonStatusType echo_status; /**<  copy of current status type */

		/*!
		* \brief Cycletime of the world model. 
		* /fixme what is this
		*/
        double getCycleTime() {
            return _cycleTime; // milliseconds
        }

        ModelInterfaceSharedPtr robot_model; /**<  pointer to robot model */

        // //////////////////////
        // double maxAccel[3];
        // double maxVel[3];
        double maxTransAccel; /**<  max translation acceleration */
        double maxTransVel; /**<  max translation velocity */
        double maxRotAccel; /**<  max rotational acceleration */
        double maxRotVel; /**<  max rotational velocity */
        double maxJointAccel; /**<  max joint acceleration */
        double maxJointVel; /**<  max joint velocity */
        double _cycleTime;  /**<  cycle time */
        CanonCmd echocmd;  /**<  copy of current command */
        JointState currentjoints; /**<  current joint state */
        urdf::Pose currentpose; /**<  current robot pose */
    };

	/*!
	* \brief DumpPose takes a urdf pose  and generates a string describing pose. 
	* Can be used as std::cout << DumpPose(pose); 
	*/
    inline std::string DumpPose(urdf::Pose & pose) {
        std::stringstream s;

        s << "Translation = " << 1000.0 * pose.position.x << ":" << 1000.0 * pose.position.y << ":" << 1000.0 * pose.position.z << std::endl;

        // os << "Rotation = "  << pose.rotation.x << ":"<<  pose.rotation.y  << ":"<< pose.rotation.z << ":"<< pose.rotation.w << std::endl;
        double roll, pitch, yaw;
        _quatToRpy(pose.rotation,roll, pitch, yaw);
        s << "Rotation = " << Rad2Deg(roll) << ":" << Rad2Deg(pitch) << ":" << Rad2Deg(yaw) << std::endl;
        return s.str();
    }

	/*!
	* \brief DumpQuaterion takes a urdf quaterion  and generates a string describing x,y,z,w coordinates. 
	* Can be used as std::cout << DumpQuaterion(urdf::rotation); 
	*/
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

