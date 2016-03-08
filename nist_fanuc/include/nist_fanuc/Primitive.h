
#include <string>
#include <vector>
#include <ros/ros.h>

#include <eigen_conversions/eigen_msg.h>
#include <Eigen/src/Geometry/Transform.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/robot_model/joint_model_group.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
//#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
//#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
//#include <moveit_msgs/MotionPlanRequest.h>
//#include <moveit_msgs/MotionPlanResponse.h>
//#include <moveit_msgs/PlanningScene.h>

#include <boost/shared_ptr.hpp>


class CPrimitive {
	typedef moveit::planning_interface::MoveItErrorCode RosErrorCode;
	robot_model::RobotModelPtr kinematic_model;
	robot_state::RobotStatePtr kinematic_state;
	boost::shared_ptr<robot_state::JointModelGroup> joint_model_group;
	std::vector<double> joint_values;
	const std::vector<std::string> joint_names;
	Eigen::Affine3d end_effector_state;
	std::string _groupname;
	Eigen::Affine3d dummy;
	moveit::planning_interface::MoveGroup movegroup;
	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
	ros::NodeHandle &node;

	bool _bAllow_trajectory_execution;
	bool _bAllowed_execution_duration_scaling;
	double _dJiggle_fraction;
	std::vector<std::string> _capabilities;
	std::string _sCapabilities;
	std::string _sController_list;
	double _d_longest_valid_segment_fraction;
    robot_model_loader::RobotModelLoader robotmodel;
public:
	CPrimitive(ros::NodeHandle nh,
			std::string groupname);
	std::string ToString() ;
	void GetJointValues();
	geometry_msgs::Pose GetRobotState_pose(
			const robot_state::RobotState &state) ;

	void ForwardKinematics() ;
	std::vector<double>  SetRandomJoints() ;
	Eigen::Affine3d ComputeForwardKinematics(std::vector<double>  jointvalues);
	std::vector<double> InverseKinematics() ;
	void RandomGoal() ;
	void PlanPath(geometry_msgs::Pose &pose, double dGoalTolerance,
			int bMoveFlag = 1, int bRandomFlag = 1) ;
	void PrintPose() ;
	static void PrintJoints(std::vector<double> &joint_values,
			const std::vector<std::string> &joint_names) ;
	static void SaveJointInfo(sensor_msgs::JointState & joint_state,
			std::vector<double> &joint_values,
			const std::vector<std::string> &joint_names) ;
	void AddObstacle(std::string id);
	void RemoveObstacle(std::string id);
};
