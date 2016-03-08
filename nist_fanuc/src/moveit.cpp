
//https://github.com/ros-planning/moveit_pr2/blob/hydro-devel/pr2_moveit_tutorials/planning/src/move_group_interface_tutorial.cpp

#include "moveit.h"
#include "Globals.h"
#include "Conversions.h"

MoveitPlanning::MoveitPlanning(ros::NodeHandle &nh) {
    _groupname = "manipulator";
    nh.getParam("controller_joint_names", joint_names);
    display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");

    kinematic_model = robot_model_loader.getModel(); //(robotmodel.getModel())
    kinematic_state = robot_state::RobotStatePtr(
            new robot_state::RobotState(kinematic_model));
    //	kinematic_state->setToDefaultValues();
    //moveit::planning_scene::PlanningScene planning_scene(kinematic_model);
    joint_model_group =  kinematic_model->getJointModelGroup( _groupname.c_str());
    group = boost::shared_ptr< moveit::planning_interface::MoveGroup>(new moveit::planning_interface::MoveGroup(_groupname.c_str()));
    std::cout << "Reference frame " << group->getPlanningFrame().c_str();
    std::cout << "EE frame " << group->getEndEffectorLink().c_str();

}
MoveitPlanning::~MoveitPlanning() {
     group=NULL;
    kinematic_model=NULL;
    kinematic_state=NULL;
    //joint_model_group=NULL;
}

std::vector<JointState> MoveitPlanning::GetJtsPlan() {
    return plannedjts;
}
urdf::Pose MoveitPlanning::ForwardKinematics() {
    Eigen::Affine3d end_effector_state = Eigen::Affine3d(
            kinematic_state->getGlobalLinkTransform(group->getEndEffectorLink().c_str()));
    return affine3d2UrdfPose(end_effector_state);
}

std::vector<double> MoveitPlanning::GetJointValues() {
    std::vector<double> joint_values;
    kinematic_state->copyJointGroupPositions(&*joint_model_group, joint_values);
    return joint_values;
 
}
std::vector<double> MoveitPlanning::SetRandomJoints() {
    robot_state::RobotStatePtr ks = robot_state::RobotStatePtr(
            new robot_state::RobotState(kinematic_model));
    ks->setToRandomPositions(&*joint_model_group);
    std::vector<double> joints;
    ks->copyJointGroupPositions(&*joint_model_group, joints);
    std::cout << "Random joints=" << VectorDump<double> (joints).c_str();
    return joints;
}
bool MoveitPlanning::Plan(JointState joints) {
    //http://docs.ros.org/indigo/api/moveit_ros_planning_interface/html/classmoveit_1_1planning__interface_1_1MoveGroup.html
    std::cout << "Plan to these joints=" << VectorDump<double> (joints.position).c_str();
    group->setJointValueTarget(joints.position);
    group->setNumPlanningAttempts(5);
    group->setPlanningTime(10.0);
    group->setGoalTolerance(0.01);
    if (!group->plan(my_plan))
        return false;
    //group->move();
    SavePlan();
    return true;
}

bool MoveitPlanning::Plan(JointState curjoints, JointState goaljoints) {
     //http://docs.ros.org/indigo/api/moveit_core/html/robot__state_8h_source.html
	robot_state::RobotState robotstate(kinematic_model);
	robotstate.setVariablePositions(joint_names, curjoints.position);
	group->setStartState (robotstate);

	// std::cout << "Plan to these joints=" << VectorDump<double> (joints.position).c_str();
    group->setJointValueTarget(curjoints.position);
    group->setNumPlanningAttempts(5);
    group->setPlanningTime(10.0);
    group->setGoalTolerance(0.01);
    if (!group->plan(my_plan))
        return false;
    //group->move();
    SavePlan();
    return true;
}

urdf::Pose MoveitPlanning::GetCurrentPose() {
    // http://answers.ros.org/question/89006/retrieve-end-effector-pose-in-moveit/

    geometry_msgs::PoseStamped current_pose =
            group->getCurrentPose();
    return PoseMsg2UrdfPose(current_pose.pose);
}
bool MoveitPlanning::Plan(geometry_msgs::Pose& pose) {
     group->setNumPlanningAttempts(20);
    group->setPlanningTime(15.0);
    group->setGoalTolerance(10.0);
    group->setPoseTarget(pose);

    if (!group->plan(my_plan))
        return false;
    SavePlan();
    return true;
}
bool MoveitPlanning::Plan(Eigen::Affine3d& pose) {
    
    group->setNumPlanningAttempts(10);
    group->setPlanningTime(15.0);
    group->setGoalTolerance(10.0);
    geometry_msgs::Pose target_pose1 = poseEigenToGeomMsg(pose);

    group->setPoseTarget(target_pose1);

    if (!group->plan(my_plan))
        return false;
     SavePlan();
     return true;
}
bool MoveitPlanning::Plan(urdf::Pose& pose) {
    // We will use the :planning_scene_interface:`PlanningSceneInterface`
    // class to deal directly with the world.
    group->setNumPlanningAttempts(10);
    group->setPlanningTime(15.0);
    group->setGoalTolerance(0.01);
    
    Eigen::Affine3d affpose = urdfPose2Affine3d(pose);
    geometry_msgs::Pose target_pose1 = poseEigenToGeomMsg(affpose);
    group->setPoseTarget(target_pose1);

    if (!group->plan(my_plan))
        return false;
    SavePlan();
    return true;
}

bool MoveitPlanning::Plan(urdf::Pose & curpose,urdf::Pose & goalpose)
{
	robot_state::RobotState robotstate(kinematic_model);
	robotstate.setFromIK(joint_model_group, UrdfPose2PoseMsg(curpose)) ; 
	group->setStartState (robotstate);
	return Plan(goalpose);
}
void MoveitPlanning::DisplayPlan() 
{
    moveit_msgs::DisplayTrajectory display_trajectory;
    display_trajectory.trajectory_start = my_plan.start_state_;
    display_trajectory.trajectory.push_back(my_plan.trajectory_);
    display_publisher.publish(display_trajectory);   
}
void MoveitPlanning::SavePlan() {
    plannedjts.clear();
    plannedjts.push_back(my_plan.start_state_.joint_state);
    int n = my_plan.trajectory_.joint_trajectory.points.size();
    for (size_t j = 0; j < n; j++) {
        JointState traj;
        traj.position = my_plan.trajectory_.joint_trajectory.points[j].positions;
        traj.velocity.resize(n, 0.0);
        traj.effort.resize(n, 0.0);
        plannedjts.push_back(traj);
    }
}
bool MoveitPlanning::Plan(std::vector<urdf::Pose>& pwaypoints) {
    std::vector<geometry_msgs::Pose> waypoints;
    for(size_t i=0; i< pwaypoints.size(); i++)
    {    
        waypoints.push_back(UrdfPose2PoseMsg(pwaypoints[i]));
    }

    moveit_msgs::RobotTrajectory trajectory;
    double fraction = group->computeCartesianPath(waypoints,
            0.001, // cartesian path to be interpolated at a resolution of 1 mm 
            //0.01, // cartesian path to be interpolated at a resolution of 1 cm 
            0.0, // NO jump_threshold
            trajectory);  // trajectory.joint_trajectory.points  (position)
    plannedjts.clear();
    for(size_t j=0; j< trajectory.joint_trajectory.points.size(); j++)
    {
        JointState traj;
        traj.position = trajectory.joint_trajectory.points[j].positions;
        plannedjts.push_back(traj);
    }
    return true;
}
