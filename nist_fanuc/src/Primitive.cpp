

#include "Primitive.h"
CPrimitive::CPrimitive(ros::NodeHandle nh,
		std::string groupname) :
			node(nh),  movegroup(groupname.c_str()), _groupname(groupname){
	robot_model_loader::RobotModelLoader robot_model_loader("robot_description");

    kinematic_model=robot_model_loader.getModel(); //(robotmodel.getModel())
		kinematic_state = robot_state::RobotStatePtr(
				new robot_state::RobotState(kinematic_model));
	//	kinematic_state->setToDefaultValues();
		planning_scene::PlanningScene planning_scene(kinematic_model);
		joint_model_group = kinematic_model->getJointModelGroup(
				_groupname.c_str());
		joint_names = joint_model_group->getJointModelNames();  // copy
		GetJointValues();
		ros::param::param<bool>("/move_group/allow_trajectory_execution",
				_bAllow_trajectory_execution, true);
		ros::param::param<bool>(
				"/move_group/allowed_execution_duration_scaling",
				_bAllowed_execution_duration_scaling, false);
		ros::param::param<double>("/move_group/jiggle_fraction",
				_dJiggle_fraction, 0.0);
		ros::param::param<std::string>("/move_group/capabilities",
				_sCapabilities, "nothing");
		ros::param::param<std::string>("/move_group/controller_list",
				_sController_list, "nothing");
		ros::param::param<double>(
				"/move_group/manipulator/longest_valid_segment_fraction",
				_d_longest_valid_segment_fraction, 0.0);
	}
	std::string CPrimitive::ToString() {
		std::stringstream str;
		str << "Allow_trajectory_execution = " << _bAllow_trajectory_execution
				<< std::endl;
		str << "Allowed_execution_duration_scaling = "
				<< _bAllowed_execution_duration_scaling << std::endl;
		str << "Jiggle fraction = " << _dJiggle_fraction << std::endl;
		// Mess that is capability strings
		str << "Capabilities = " << std::endl;
		ReplaceAll(_sCapabilities, "\n ", " ");
		ReplaceAll(_sCapabilities, "\r ", " ");
		ReplaceAll(_sCapabilities, "  ", " ");
		_capabilities = TrimmedTokenize(_sCapabilities, " ");
		for (size_t i = 0; i < _capabilities.size(); i++) {
			_capabilities[i] = Trim(_capabilities[i]);
			if (_capabilities[i].empty()) {
				_capabilities.erase(_capabilities.begin() + i);
				i--;
				continue;
			}
			str << "     " << _capabilities[i] << std::endl;

		}

		str << "controller_list = " << _sController_list << std::endl;
		str << "_longest_valid_segment_fraction = "
				<< _d_longest_valid_segment_fraction << std::endl;

		return str.str();
	}
	void CPrimitive::GetJointValues() {
		kinematic_state->copyJointGroupPositions(joint_model_group,
				joint_values);
		PrintJoints(joint_values, *joint_names);
	}
	geometry_msgs::Pose CPrimitive::GetRobotState_pose(
			const robot_state::RobotState &state) {
		Eigen::Affine3d eef_transform = state.getGlobalLinkTransform(
				movegroup.getEndEffectorLink());
		geometry_msgs::Pose pose;
		tf::poseEigenToMsg(eef_transform, pose);
		return pose;
	}

	void CPrimitive::ForwardKinematics() {
		end_effector_state = Eigen::Affine3d(
				kinematic_state->getGlobalLinkTransform("joint_6_link"));
		ROS_INFO_STREAM("Translation: " << end_effector_state.translation());
		ROS_INFO_STREAM("Rotation: " << end_effector_state.rotation());
	}
	// Set all joints to random values. Values will be within default bounds.
	std::vector<double>  CPrimitive::SetRandomJoints() {
		robot_state::RobotStatePtr ks = robot_state::RobotStatePtr(
				new robot_state::RobotState(kinematic_model));
		ks->setToRandomPositions(joint_model_group);
		std::vector<double> joints;
		ks->copyJointGroupPositions(joint_model_group, joints);
		return joints;
	}
	Eigen::Affine3d CPrimitive::ComputeForwardKinematics(std::vector<double>  jointvalues) {
		robot_state::RobotStatePtr ks = robot_state::RobotStatePtr(
				new robot_state::RobotState(kinematic_model));
		for(size_t i=0; i< jointvalues.size(); i++)
		 ks->setJointPositions(kinematic_model->getJointModel(i), &jointvalues[i]);
		const Eigen::Affine3d & fk = Eigen::Affine3d(
				ks->getGlobalLinkTransform("joint_6_link"));
		//ROS_INFO_STREAM("Translation: " << end_effector_state.translation());
		//ROS_INFO_STREAM("Rotation: " << end_effector_state.rotation());
		return fk;
	}
	std::vector<double> CPrimitive::InverseKinematics() {
		std::vector<double> joints;
		const Eigen::Affine3d &end_effector_state1 =
				kinematic_state->getGlobalLinkTransform("joint_6_link");
		bool found_ik = kinematic_state->setFromIK(joint_model_group,
				end_effector_state1, 10, 0.1);
		if (found_ik) {
			kinematic_state->copyJointGroupPositions(joint_model_group, joints);
			PrintJoints(joints, *joint_names);
		}
		return joints;
	}
	void CPrimitive::RandomGoal() {
		SetRandomJoints();
		const Eigen::Affine3d &end_effector_state1 =
				kinematic_state->getGlobalLinkTransform("joint_6_link");
		bool found_ik = kinematic_state->setFromIK(joint_model_group,
				end_effector_state1, 10, 0.1);
		//return const_cast < Eigen::Affine3d > ( end_effector_state1);
	}
	void CPrimitive::PlanPath(geometry_msgs::Pose &pose, double dGoalTolerance,
			int bMoveFlag = 1, int bRandomFlag = 1) {
		RosErrorCode ec;
		//moveit::planning_interface::MoveGroup movegroup(_groupname.c_str());
		moveit_msgs::DisplayTrajectory display_trajectory;
		moveit::planning_interface::MoveGroup::Plan my_plan;
		movegroup.setPoseTarget(pose);
		if (bRandomFlag)
		{
			std::vector<double>  joints = SetRandomJoints();
			Eigen::Affine3d cart = this->ComputeForwardKinematics(joints);

			//  After this call, the JointValueTarget is used instead of any
		    //  previously set Position, Orientation, or Pose targets
			//movegroup.setRandomTarget();

			//const robot_state::RobotState& state = movegroup.getJointValueTarget();
			//state.copyJointGroupPositions(joint_model_group, joints);
			//PrintJoints(joints, *joint_names);
			geometry_msgs::Pose target_pose1;
				// Not sure what coordinate frame planning is in - if end-effector, not world
				target_pose1.orientation.w = 1.0;
				target_pose1.position.x = cart.translation().x(); // end_effector_state.translation().x();
				target_pose1.position.y = cart.translation().y();  // end_effector_state.translation().y();
				target_pose1.position.z = cart.translation().z(); //  end_effector_state.translation().z();
			movegroup.setPoseTarget(target_pose1);
		}
		PrintPose();
		movegroup.setGoalTolerance(dGoalTolerance);
		movegroup.setPlanningTime(10.0);  // assuming obstacles
		bool success = movegroup.plan(my_plan);
		if (success & bMoveFlag)
			ec = movegroup.move();
	}
	void CPrimitive::PrintPose() {
		const geometry_msgs::PoseStamped& msg = movegroup.getPoseTarget();
		ROS_INFO("Pose x=%f y=%f z=%f %f %f %f %f\n", msg.pose.position.x,
				msg.pose.position.y,
				msg.pose.position.z,
				msg.pose.orientation.x,
				msg.pose.orientation.y,
				msg.pose.orientation.z,
				msg.pose.orientation.w);
	}
	void CPrimitive::PrintJoints(std::vector<double> &joint_values,
			const std::vector<std::string> &joint_names) {
		for (std::size_t i = 0; i < joint_names.size(); ++i) {
			ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
		}
	}
	void CPrimitive::SaveJointInfo(sensor_msgs::JointState & joint_state,
			std::vector<double> &joint_values,
			const std::vector<std::string> &joint_names) {
		joint_state.name.resize(joint_names.size());
		joint_state.position.resize(joint_names.size());
		for (std::size_t i = 0; i < joint_names.size(); ++i) {
			joint_state.name[i] = joint_names[i];
			joint_state.position[i] = joint_values[i];
		}
	}
	void CPrimitive::AddObstacle(std::string id) {
		moveit_msgs::CollisionObject collision_object;
		collision_object.header.frame_id = movegroup.getPlanningFrame();
		http: //docs.ros.org/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html#aa28a400ac63222f07598c53c685d7144
		/* The id of the object is used to identify it. */
		collision_object.id = id.c_str(); // "box1";

		/* Define a box to add to the world. */
		shape_msgs::SolidPrimitive primitive;
		primitive.type = primitive.BOX;
		primitive.dimensions.resize(3);
		primitive.dimensions[0] = 0.4;
		primitive.dimensions[1] = 0.1;
		primitive.dimensions[2] = 0.4;

		/* A pose for the box (specified relative to frame_id) */
		geometry_msgs::Pose box_pose;
		box_pose.orientation.w = 1.0;
		box_pose.position.x = 0.6;
		box_pose.position.y = -0.4;
		box_pose.position.z = 1.2;

		//http:docs.ros.org/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html#aa28a400ac63222f07598c53c685d7144		
		collision_object.primitives.push_back(primitive);
		collision_object.primitive_poses.push_back(box_pose);
		collision_object.operation = collision_object.ADD;

		std::vector<moveit_msgs::CollisionObject> collision_objects;
		collision_objects.push_back(collision_object);
		//Now, let’s add the collision object into the world 		ROS_INFO("Add an object into the world");
		planning_scene_interface.addCollisionObjects(collision_objects);
	}
	void CPrimitive::RemoveObstacle(std::string id) {
		ROS_INFO("Remove the object from the world");
		std::vector < std::string > object_ids;
		object_ids.push_back(id.c_str()); // collision_object.id);
		planning_scene_interface.removeCollisionObjects(object_ids);
		/* Sleep to give Rviz time to show the object is no longer there. */
		sleep(4.0);
	}
