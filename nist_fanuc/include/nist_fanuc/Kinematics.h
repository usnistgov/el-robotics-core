

#pragma once

#include "RCS.h"
#include "Globals.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
/**
* \brief The IKinematics provides is an abstract class with pure virtual functions that are
* overriden by actual kinematic implementations.
* */
class IKinematics {
public:
	/*!
	* \brief GetJointValues returns latest reading of end effector.
	* \return vector of joint values in doubles.
	*/
	virtual std::vector<double> GetJointValues() = 0;
	/*!
	* \brief SetJointValues sets the latest joint values of the robot.
	* \param vector of all robot joint values in doubles.
	*/
	virtual void SetJointValues(std::vector<double> joint_values) = 0;
	/*!
	* \brief FK performs the forward kinematics using the joint values of the robot provided.
	* \param vector of all robot joint values in doubles.
	* \return corresponding Cartesian robot pose of end  effector.
	*/
	virtual RCS::Pose FK(std::vector<double> jv) = 0;
	/*!
	* \brief IK performs the inverse kinematics using the Cartesian pose provided.
	* \param  Cartesian robot pose of end  effector.
	* \param  optional seed joint values to use as best guess for IK joint values.
	* \return vector of all robot joint values in doubles.
	*/
	virtual std::vector<double> IK(RCS::Pose & pose,
		std::vector<double> oldjoints) = 0;

	/*!
	* \brief AllPoseToJoints solves  the inverse kinematics to find all solutions using the Cartesian pose provided.
	* \param  Cartesian robot pose of end  effector.
	* \param  vector of double vectos to hold all the IK joint solutions.
	* \return number of solutions found.
	*/
	virtual size_t AllPoseToJoints(RCS::Pose & pose,
		std::vector<std::vector<double> > & newjoints) = 0;
	/*!
	* \brief NearestJoints finds the joint set that is closest to the old joints.
	* \param  old seed  joint values to use as best guess for IK joint values.
	* \param  vector of double vectos that holds all the IK joint solutions.
	* \return vector of doubles with closest set to seed joints.
	*/
	virtual std::vector<double> NearestJoints(
		std::vector<double> oldjoints,
		std::vector<std::vector<double> > & newjoints) = 0;

	/*!
	* \brief Init is necessary for ROS to initialize it kinematics using robot model .
	* \param  groupname name of  chained joints in robot model.
	* \param  eelinkname name of end effector joint in robot model.
	*/
	virtual void Init(
		std::string groupname,
		std::string eelinkname) {
	}
 	/*!
	* \brief Returns true if the determinant of the jacobian is near zero. .
	* \param  groupname name of  chained joints in robot model.
	* \param  eelinkname name of end effector joint in robot model.
	*/       
        virtual bool IsSingular(RCS::Pose & pose, double threshold) =0;
};
typedef boost::shared_ptr<IKinematics> IKinematicsSharedPtr;

/**
* \brief The DummyKinematics class  instantiates the IKinematics abstract class
* and fills in the pure virtual functions with dummy methods.
* */
class DummyKinematics : public IKinematics {
public:

	virtual std::vector<double> GetJointValues() {
		std::vector<double> joints = ToVector<double>(6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		return joints;
	}

	virtual void SetJointValues(std::vector<double> joint_values) {
	}

	virtual RCS::Pose FK(std::vector<double> jv) {
		return RCS::Pose();
	}

	virtual std::vector<double> IK(RCS::Pose & pose,
		std::vector<double> oldjoints) {
			std::vector<std::vector<double> > newjoints;
			size_t solutions = AllPoseToJoints(pose, newjoints);
			assert(solutions > 0);
			return NearestJoints(oldjoints, newjoints);

	}

	virtual size_t AllPoseToJoints(RCS::Pose & pose,
		std::vector<std::vector<double> > & newjoints) {
			newjoints.push_back(ToVector<double>(6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
			return 1;
	}

	virtual std::vector<double> NearestJoints(
		std::vector<double> oldjoints,
		std::vector<std::vector<double> > & newjoints) {
			assert(newjoints.size() > 0);
			return newjoints[0];
	}
        virtual bool IsSingular(RCS::Pose & pose, double threshold) { return true; }

};
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/robot_model/joint_model_group.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <ros/console.h>
#include <ros/init.h>
#include <ros/node_handle.h>
#include <ros/param.h>
#include <ros/rate.h>
#include <rosconsole/macros_generated.h>
#include <sensor_msgs/JointState.h>
#include <shape_msgs/SolidPrimitive.h>
#include <std_msgs/Header.h>


typedef moveit::planning_interface::MoveItErrorCode RosErrorCode;
/**
* \brief The RosKinematics class  instantiates the IKinematics abstract class
* and fills in the pure virtual functions with Descartes kinematic methods.
* */
class RosKinematics : public IKinematics {
public:
	RosKinematics();
	virtual void Init(
		std::string groupname,
		std::string eelinkname);
	virtual std::vector<double> GetJointValues();
	void SetJointValues(std::vector<double> joint_values);
	virtual RCS::Pose FK(std::vector<double> jv);
	virtual std::vector<double> IK(RCS::Pose & pose,
		std::vector<double> oldjoints);
	bool SatisfiesBounds();
	void EnforceBounds();
        virtual bool IsSingular(RCS::Pose & pose, double threshold) { return true; }
	virtual size_t AllPoseToJoints(RCS::Pose & pose,
		std::vector<std::vector<double> > & newjoints) {
			newjoints.push_back(ToVector<double>(6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
			return 1;
	}

	virtual std::vector<double> NearestJoints(
		std::vector<double> oldjoints,
		std::vector<std::vector<double> > & newjoints) {
			assert(newjoints.size() > 0);
			return newjoints[0];
	}

	robot_model::RobotModelPtr kinematic_model;
	robot_state::RobotStatePtr kinematic_state;
	robot_state::JointModelGroup* joint_model_group;
	std::vector<double> joint_values;
	std::vector<std::string> joint_names;
	std::string _groupname;
	std::string _eelinkname;
	//ros::NodeHandle &node;
	bool _bInit;
	boost::mutex kinmutex;
};
/**
* \brief The MoveitKinematics class  instantiates the IKinematics abstract class
* and fills in the pure virtual functions with Moveit kinematic methods.
* */
class MoveitKinematics : public IKinematics {
public:
	MoveitKinematics(ros::NodeHandle &nh);
	virtual std::vector<double> GetJointValues();
	virtual void SetJointValues(std::vector<double> joint_values);
	virtual RCS::Pose FK(std::vector<double> jv);
	virtual std::vector<double> IK(RCS::Pose & pose,
		std::vector<double> oldjoints);

	virtual size_t AllPoseToJoints(RCS::Pose & pose,
		std::vector<std::vector<double> > & newjoints) {
			return 0;
	}

	virtual std::vector<double> NearestJoints(
		std::vector<double> oldjoints,
		std::vector<std::vector<double> > & newjoints) {
			return std::vector<double>();
	}
	virtual void Init(
		std::string groupname,
		std::string eelinkname);
        
        virtual bool IsSingular(RCS::Pose & pose,
            double threshold);
	/////////////////////////////////////////
	boost::shared_ptr<moveit::planning_interface::MoveGroup> group;
	robot_model::RobotModelPtr kinematic_model;
	robot_state::RobotStatePtr kinematic_state;
	robot_state::JointModelGroup* joint_model_group;
	std::vector<double> joint_values;
	std::vector<std::string> joint_names;
	std::string _groupname;
	std::string _eelinkname;
	ros::NodeHandle &_nh;
	bool _bInit;
	boost::mutex kinmutex;
};