Compiling Fanuc Demo with Debug Information
-----------------------------
In the code, the stdout and stderr information is redirected to log file, because often the output streamed number of lines exceeds the limits of the terminal.
And you miss something.

    cd ~/catkin_ws
    catkin_make -DCMAKE_BUILD_TYPE=Debug &> log.log
    more log.log


How to build just one package using catkin_make?
-----------------------------
Use:

	catkin_make --pkg <my_package_name>

so 

    catkin_make --pkg nist_fanuc

Is there a way to enable c++11 support for catkin packages?
-----------------------------

    http://catkin-tools.readthedocs.org/en/latest/cheat_sheet.html (kinda wrong)

    set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS "-Wwrite-strings ${CMAKE_CXX_FLAGS}")

how to resolve g++ warning with -std=c++11: ‘auto_ptr’ is deprecated [duplicate]

    https://gcc.gnu.org/bugzilla/show_bug.cgi?id=59325

Using Netbeans IDE to Debug ROS executable
-----------------------------
After Compiling Fanuc Demo with Debug Information,
Use netbeans to create binary C++ project and read binary file to debug
(for example found at */home/michalos/catkin_ws/devel/lib/nist_fanuc/nist_fanuc*)


Running CRCL NIST Fanuc demo
================================================

     source ~/catkin_ws/devel/setup.bash
     cd catkin_ws
     roslaunch nist_fanuc lrmate200id_sim.launch



Diplay contents of rostopic to see current robot pose
--------------------------------------------------------
    rostopic echo  /move_group/goal

    header: 
      seq: 30
      stamp: 
        secs: 1456420731
        nsecs: 958832629
      frame_id: ''
    goal_id: 
      stamp: 
        secs: 1456420731
        nsecs: 958833341
      id: /rviz_rufous_6391_9202004766824814528-31-1456420731.958833341
    goal: 
      request: 
        workspace_parameters: 
          header: 
            seq: 0
            stamp: 
              secs: 1456420731
              nsecs: 958705952
            frame_id: /base_link
          min_corner: 
            x: -1.0
            y: -1.0
            z: -1.0
          max_corner: 
            x: 1.0
            y: 1.0
            z: 1.0
        start_state: 
          joint_state: 
            header: 
              seq: 0
              stamp: 
                secs: 0
                nsecs: 0
              frame_id: /base_link
            name: ['joint_1', 'joint_2', 'joint_3', 'joint_4', 'joint_5', 'joint_6']
            position: [-0.9951596824786128, -1.161361427138559, 0.6456418463565006, 3.1368453900839213, 2.0662861177525222, -1.4036373909368032]
            velocity: []
            effort: []
          multi_dof_joint_state: 
            header: 
              seq: 0
              stamp: 
                secs: 0
                nsecs: 0
              frame_id: /base_link
            joint_names: []
            transforms: []
            twist: []
            wrench: []
          attached_collision_objects: []
          is_diff: False
        goal_constraints: 
          - 
            name: ''
            joint_constraints: 
              - 
                joint_name: joint_1
                position: 1.75594190178
                tolerance_above: 0.0001
                tolerance_below: 0.0001
                weight: 1.0
              - 
                joint_name: joint_2
                position: -1.50958199864
                tolerance_above: 0.0001
                tolerance_below: 0.0001
                weight: 1.0
              - 
                joint_name: joint_3
                position: 2.60972229461
                tolerance_above: 0.0001
                tolerance_below: 0.0001
                weight: 1.0
              - 
                joint_name: joint_4
                position: -1.55001527988
                tolerance_above: 0.0001
                tolerance_below: 0.0001
                weight: 1.0
              - 
                joint_name: joint_5
                position: 1.68989821207
                tolerance_above: 0.0001
                tolerance_below: 0.0001
                weight: 1.0
              - 
                joint_name: joint_6
                position: 2.29309630865
                tolerance_above: 0.0001
                tolerance_below: 0.0001
                weight: 1.0
            position_constraints: []
            orientation_constraints: []
            visibility_constraints: []
        path_constraints: 
          name: ''
          joint_constraints: []
          position_constraints: []
          orientation_constraints: []
          visibility_constraints: []
        trajectory_constraints: 
          constraints: []
        planner_id: ''
        group_name: manipulator
        num_planning_attempts: 1
        allowed_planning_time: 1.0
        max_velocity_scaling_factor: 1.0
      planning_options: 
        planning_scene_diff: 
          name: ''
          robot_state: 
            joint_state: 
              header: 
                seq: 0
                stamp: 
                  secs: 0
                  nsecs: 0
                frame_id: ''
              name: []
              position: []
              velocity: []
              effort: []
            multi_dof_joint_state: 
              header: 
                seq: 0
                stamp: 
                  secs: 0
                  nsecs: 0
                frame_id: ''
              joint_names: []
              transforms: []
              twist: []
              wrench: []
            attached_collision_objects: []
            is_diff: True
          robot_model_name: ''
          fixed_frame_transforms: []
          allowed_collision_matrix: 
            entry_names: []
            entry_values: []
            default_entry_names: []
            default_entry_values: []
          link_padding: []
          link_scale: []
          object_colors: []
          world: 
            collision_objects: []
            octomap: 
              header: 
                seq: 0
                stamp: 
                  secs: 0
                  nsecs: 0
                frame_id: ''
              origin: 
                position: 
                  x: 0.0
                  y: 0.0
                  z: 0.0
                orientation: 
                  x: 0.0
                  y: 0.0
                  z: 0.0
                  w: 0.0
              octomap: 
                header: 
                  seq: 0
                  stamp: 
                    secs: 0
                    nsecs: 0
                  frame_id: ''
                binary: False
                id: ''
                resolution: 0.0
                data: []
          is_diff: True
        plan_only: False
        look_around: False
        look_around_attempts: 0
        max_safe_execution_cost: 0.0
        replan: False
        replan_attempts: 0
        replan_delay: 2.0
    ---

Display only the pose of the robot
----------------------------------

    sudo apt-get install ros-indigo-robot-pose-publisher
    rosrun robot_pose_publisher robot_pose_publisher

FAILED!





rosparam - get list of ROS parameter from paramserver
------------
Does not provide the values....

    michalos@rufous:~/catkin_ws$ rosparam list
    /controller_joint_names
    /move_group/allow_trajectory_execution
    /move_group/allowed_execution_duration_scaling
    /move_group/allowed_goal_duration_margin
    /move_group/capabilities
    /move_group/controller_list
    /move_group/jiggle_fraction
    /move_group/manipulator/longest_valid_segment_fraction
    /move_group/manipulator/planner_configs
    /move_group/manipulator/projection_evaluator
    /move_group/max_range
    /move_group/max_safe_path_cost
    /move_group/moveit_controller_manager
    /move_group/moveit_manage_controllers
    /move_group/octomap_resolution
    /move_group/ompl/display_random_valid_states
    /move_group/ompl/link_for_exploration_tree
    /move_group/ompl/maximum_waypoint_distance
    /move_group/ompl/minimum_waypoint_count
    /move_group/ompl/simplify_solutions
    /move_group/plan_execution/max_replan_attempts
    /move_group/plan_execution/record_trajectory_state_frequency
    /move_group/planner_configs/BKPIECEkConfigDefault/border_fraction
    /move_group/planner_configs/BKPIECEkConfigDefault/failed_expansion_score_factor
    /move_group/planner_configs/BKPIECEkConfigDefault/min_valid_path_fraction
    /move_group/planner_configs/BKPIECEkConfigDefault/range
    /move_group/planner_configs/BKPIECEkConfigDefault/type
    /move_group/planner_configs/ESTkConfigDefault/goal_bias
    /move_group/planner_configs/ESTkConfigDefault/range
    /move_group/planner_configs/ESTkConfigDefault/type
    /move_group/planner_configs/KPIECEkConfigDefault/border_fraction
    /move_group/planner_configs/KPIECEkConfigDefault/failed_expansion_score_factor
    /move_group/planner_configs/KPIECEkConfigDefault/goal_bias
    /move_group/planner_configs/KPIECEkConfigDefault/min_valid_path_fraction
    /move_group/planner_configs/KPIECEkConfigDefault/range
    /move_group/planner_configs/KPIECEkConfigDefault/type
    /move_group/planner_configs/LBKPIECEkConfigDefault/border_fraction
    /move_group/planner_configs/LBKPIECEkConfigDefault/min_valid_path_fraction
    /move_group/planner_configs/LBKPIECEkConfigDefault/range
    /move_group/planner_configs/LBKPIECEkConfigDefault/type
    /move_group/planner_configs/PRMkConfigDefault/max_nearest_neighbors
    /move_group/planner_configs/PRMkConfigDefault/type
    /move_group/planner_configs/PRMstarkConfigDefault/type
    /move_group/planner_configs/RRTConnectkConfigDefault/range
    /move_group/planner_configs/RRTConnectkConfigDefault/type
    /move_group/planner_configs/RRTkConfigDefault/goal_bias
    /move_group/planner_configs/RRTkConfigDefault/range
    /move_group/planner_configs/RRTkConfigDefault/type
    /move_group/planner_configs/RRTstarkConfigDefault/delay_collision_checking
    /move_group/planner_configs/RRTstarkConfigDefault/goal_bias
    /move_group/planner_configs/RRTstarkConfigDefault/range
    /move_group/planner_configs/RRTstarkConfigDefault/type
    /move_group/planner_configs/SBLkConfigDefault/range
    /move_group/planner_configs/SBLkConfigDefault/type
    /move_group/planner_configs/TRRTkConfigDefault/frountierNodeRatio
    /move_group/planner_configs/TRRTkConfigDefault/frountier_threshold
    /move_group/planner_configs/TRRTkConfigDefault/goal_bias
    /move_group/planner_configs/TRRTkConfigDefault/init_temperature
    /move_group/planner_configs/TRRTkConfigDefault/k_constant
    /move_group/planner_configs/TRRTkConfigDefault/max_states_failed
    /move_group/planner_configs/TRRTkConfigDefault/min_temperature
    /move_group/planner_configs/TRRTkConfigDefault/range
    /move_group/planner_configs/TRRTkConfigDefault/temp_change_factor
    /move_group/planner_configs/TRRTkConfigDefault/type
    /move_group/planning_plugin
    /move_group/planning_scene_monitor/publish_geometry_updates
    /move_group/planning_scene_monitor/publish_planning_scene
    /move_group/planning_scene_monitor/publish_planning_scene_hz
    /move_group/planning_scene_monitor/publish_state_updates
    /move_group/planning_scene_monitor/publish_transforms_updates
    /move_group/request_adapters
    /move_group/sense_for_plan/discard_overlapping_cost_sources
    /move_group/sense_for_plan/max_cost_sources
    /move_group/sense_for_plan/max_look_attempts
    /move_group/sense_for_plan/max_safe_path_cost
    /move_group/start_state_max_bounds_error
    /move_group/trajectory_execution/allowed_execution_duration_scaling
    /move_group/trajectory_execution/execution_duration_monitoring
    /move_group/trajectory_execution/execution_velocity_scaling
    /robot_description
    /robot_description_kinematics/manipulator/kinematics_solver
    /robot_description_kinematics/manipulator/kinematics_solver_attempts
    /robot_description_kinematics/manipulator/kinematics_solver_search_resolution
    /robot_description_kinematics/manipulator/kinematics_solver_timeout
    /robot_description_planning/joint_limits/joint_1/has_acceleration_limits
    /robot_description_planning/joint_limits/joint_1/has_velocity_limits
    /robot_description_planning/joint_limits/joint_1/max_acceleration
    /robot_description_planning/joint_limits/joint_1/max_velocity
    /robot_description_planning/joint_limits/joint_2/has_acceleration_limits
    /robot_description_planning/joint_limits/joint_2/has_velocity_limits
    /robot_description_planning/joint_limits/joint_2/max_acceleration
    /robot_description_planning/joint_limits/joint_2/max_velocity
    /robot_description_planning/joint_limits/joint_3/has_acceleration_limits
    /robot_description_planning/joint_limits/joint_3/has_velocity_limits
    /robot_description_planning/joint_limits/joint_3/max_acceleration
    /robot_description_planning/joint_limits/joint_3/max_velocity
    /robot_description_planning/joint_limits/joint_4/has_acceleration_limits
    /robot_description_planning/joint_limits/joint_4/has_velocity_limits
    /robot_description_planning/joint_limits/joint_4/max_acceleration
    /robot_description_planning/joint_limits/joint_4/max_velocity
    /robot_description_planning/joint_limits/joint_5/has_acceleration_limits
    /robot_description_planning/joint_limits/joint_5/has_velocity_limits
    /robot_description_planning/joint_limits/joint_5/max_acceleration
    /robot_description_planning/joint_limits/joint_5/max_velocity
    /robot_description_planning/joint_limits/joint_6/has_acceleration_limits
    /robot_description_planning/joint_limits/joint_6/has_velocity_limits
    /robot_description_planning/joint_limits/joint_6/max_acceleration
    /robot_description_planning/joint_limits/joint_6/max_velocity
    /robot_description_semantic
    /rosdistro
    /roslaunch/uris/host_rufous__60560
    /rosversion
    /run_id
    /rviz_rufous_23871_3766625969024100662/manipulator/kinematics_solver
    /rviz_rufous_23871_3766625969024100662/manipulator/kinematics_solver_attempts
    /rviz_rufous_23871_3766625969024100662/manipulator/kinematics_solver_search_resolution
    /rviz_rufous_23871_3766625969024100662/manipulator/kinematics_solver_timeout
    /rviz_rufous_23871_3766625969024100662/motionplanning_planning_scene_monitor/publish_geometry_updates
    /rviz_rufous_23871_3766625969024100662/motionplanning_planning_scene_monitor/publish_planning_scene
    /rviz_rufous_23871_3766625969024100662/motionplanning_planning_scene_monitor/publish_planning_scene_hz
    /rviz_rufous_23871_3766625969024100662/motionplanning_planning_scene_monitor/publish_state_updates
    /rviz_rufous_23871_3766625969024100662/motionplanning_planning_scene_monitor/publish_transforms_updates
    michalos@rufous:~/catkin_ws$ 



Remove installed package from ubuntu
--------------------------------------
    sudo apt-get remove grip

Pose conversion tests
-------------------------

Old way:
    CRCL conversion tests
    CRCL Pose 0.4643,0.02436,1.275,0.01676,0.08284,0.9964,0.2896,0.9535,-0.08413,
    Urdf Pose Translation = 464.3:24.36:1275
    Rotation = -95.0423:16.8334:-88.9969

Eigen way: no rpy intermediary step
    CRCL Pose 0.4643,0.02436,1.275,0.01676,0.08284,0.9964,0.2896,0.9535,-0.08413,
    Urdf Pose Translation = 464.3:24.36:1275
    Rotation = 174.572:-85.1698:78.5552

    urdf::Pose Convert(Crcl::PoseType & pose, double lengthConversion) {
            urdf::Pose p;

            p.position.x = pose.Point().X() * lengthConversion;
            p.position.y = pose.Point().Y() * lengthConversion;
            p.position.z = pose.Point().Z() * lengthConversion;

            Eigen::Matrix3d mat=GetEigenRotMatrix(GetVector3D(pose.XAxis()), GetVector3D(pose.ZAxis()));
            Eigen::Quaterniond q(mat);
            p.rotation.x = q.x();
            p.rotation.y = q.y();
            p.rotation.z = q.z();
            p.rotation.w = q.w();
            return p;
        }

Using ROS whose RPY from quaterion doesnt work!
-------------------------------------------------
Instead use posemath, gomotion rpy from matrix via quaterion

    GotoCRCL Pose 0.465,0,0.745,-2.051e-10,-8.979e-11,1,1,0,2.051e-10,
    Goto urdf Pose Translation = 465:0:745
    Rotation = 180:-90:0

Position Only IK
------------------
Position only IK can easily be enabled (only if you are using the KDL Kinematics Plugin) by adding the following line to your kinematics.yaml file (for the particular group that you want to solve IK for):

position_only_ik: True

I suppose this is "easily" if you dont ever want to change it dynamically or programmatically without modifying the yaml file....


Problems with ikfast
-----------------------
http://answers.ros.org/question/205781/moveit-inverse_kinematics-c-api/ 
Side note: I am aware that FastIK is a possible alternative to KDL, however it requires to install OpenRave, 
which seems to be problematic under Ubuntu 14.04. Also the ros converter urdf_to_collada for indigo 
is broken and not working. There is just generally speaking a lot of hassle to get an IK solver at 
the moment under indigo.

JM: Agree!

Person used KDL IK directly

catkin_make clean
-----------------
problem with controller.o linking, clean & remake



creating doxygen documentation with catkin
----------------------------------------
1) Install

	sudo apt-get install ros-indigo-rosdoc-lite 

2) Run rosdoc-lite

	cd src/nist_fanuc
	rosdoc_lite ../nist_fanuc

3) Output in doc

4) cd doc/html  

5) double click index.html

Problems with exclude, so hard-coded doxygen use anyway ....



test crcl with catkin 
----------------------
1) Add /test folder,
2) Create testcrclmath.cpp file:

    #include <gtest/gtest.h>

    TEST(TestSuite, testCase1) {
        ASSERT_EQ(1, 1) << "Vectors 1 and 1 not equal";
    }

    int main(int argc, char ** argv) {

        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

3) Modify  CMakeLists.txt (catkin will handle rest of stuff)

	catkin_add_gtest(crclmathunittest test/crclmathtest.cpp)

4) Run individual gtest in package

	catkin_make run_tests_nist_fanuc






