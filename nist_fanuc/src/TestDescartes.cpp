

#include "Trajectory.h"
// Includes the descartes robot model we will be using
#include <descartes_moveit/moveit_state_adapter.h>
// Includes the descartes trajectory type we will be using
#include <descartes_trajectory/axial_symmetric_pt.h>
#include <descartes_trajectory/cart_trajectory_pt.h>
// Includes the planner we will be using
#include <descartes_planner/dense_planner.h>

typedef std::vector<descartes_core::TrajectoryPtPtr> TrajectoryVec;
typedef TrajectoryVec::const_iterator TrajectoryIter;


/**
 * Generates an completely defined (zero-tolerance) cartesian point from a pose
 */
descartes_core::TrajectoryPtPtr makeCartesianPoint(const Eigen::Affine3d& pose);
/**
 * Generates a cartesian point with free rotation about the Z axis of the EFF frame
 */
descartes_core::TrajectoryPtPtr makeTolerancedCartesianPoint(const Eigen::Affine3d& pose);

/**
 * Translates a descartes trajectory to a ROS joint trajectory
 */
trajectory_msgs::JointTrajectory
toROSJointTrajectory(const TrajectoryVec& trajectory, const descartes_core::RobotModel& model,
                     const std::vector<std::string>& joint_names, double time_delay);

/**
 * Sends a ROS trajectory to the robot controller
 */
bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory);


descartes_core::TrajectoryPtPtr makeCartesianPoint(const Eigen::Affine3d& pose) {
    using namespace descartes_core;
    using namespace descartes_trajectory;

    return TrajectoryPtPtr(new CartTrajectoryPt(TolerancedFrame(pose)));
}

descartes_core::TrajectoryPtPtr makeTolerancedCartesianPoint(const Eigen::Affine3d& pose) {
    using namespace descartes_core;
    using namespace descartes_trajectory;

    return TrajectoryPtPtr(new AxialSymmetricPt(pose, M_PI / 2.0 - 0.0001, AxialSymmetricPt::Z_AXIS));
}

trajectory_msgs::JointTrajectory
toROSJointTrajectory(const TrajectoryVec& trajectory,
        const descartes_core::RobotModel& model,
        const std::vector<std::string>& joint_names,
        double time_delay) {
    // Fill out information about our trajectory
    trajectory_msgs::JointTrajectory result;
    result.header.stamp = ros::Time::now();
    result.header.frame_id = "world_frame";
    result.joint_names = joint_names;

    // For keeping track of time-so-far in the trajectory
    double time_offset = 0.0;
    // Loop through the trajectory
    for (TrajectoryIter it = trajectory.begin(); it != trajectory.end(); ++it) {
        // Find nominal joint solution at this point

        std::vector<double> joints;
        it->get()->getNominalJointPose(std::vector<double>(), model, joints);

        // Fill out a ROS trajectory point
        trajectory_msgs::JointTrajectoryPoint pt;
        pt.positions = joints;
        // velocity, acceleration, and effort are given dummy values
        // we'll let the controller figure them out
        pt.velocities.resize(joints.size(), 0.0);
        pt.accelerations.resize(joints.size(), 0.0);
        pt.effort.resize(joints.size(), 0.0);
        // set the time into the trajectory
        pt.time_from_start = ros::Duration(time_offset);
        // increment time
        time_offset += time_delay;

        result.points.push_back(pt);
    }

    return result;
}

bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory) {
    // Create a Follow Joint Trajectory Action Client
    actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac("joint_trajectory_action", true);
    if (!ac.waitForServer(ros::Duration(2.0))) {
        ROS_ERROR("Could not connect to action server");
        return false;
    }

    control_msgs::FollowJointTrajectoryGoal goal;
    goal.trajectory = trajectory;
    goal.goal_time_tolerance = ros::Duration(1.0);

    ac.sendGoal(goal);

    if (ac.waitForResult(goal.trajectory.points[goal.trajectory.points.size() - 1].time_from_start + ros::Duration(5))) {
        ROS_INFO("Action server reported successful execution");
        return true;
    } else {
        ROS_WARN("Action server could not execute trajectory");
        return false;
    }
}

static int TestDescartes(ros::NodeHandle &nh) {

    // 1. Define sequence of points
    TrajectoryVec points;
    for (unsigned int i = 0; i < 5; ++i) {
        Eigen::Affine3d pose;
        pose = Eigen::Translation3d(0.050, 0.05, .33 + 0.005 * i);
        descartes_core::TrajectoryPtPtr pt = makeTolerancedCartesianPoint(pose);
        points.push_back(pt);
    }
    // 2. Create a robot model and initialize it
    descartes_moveit::MoveitStateAdapter model;

    // Name of description on parameter server. Typically just "robot_description".
    const std::string robot_description = "robot_description";

    // name of the kinematic group you defined when running MoveitSetupAssistant
    const std::string group_name = "manipulator";

    // Name of frame in which you are expressing poses. Typically "world_frame" or "base_link".
    const std::string world_frame = "/base_link";

    // tool center point frame (name of link associated with tool)
    const std::string tcp_frame = "tool0";

    if (!model.initialize(robot_description, group_name, world_frame, tcp_frame)) {
        //if (!model.initialize(robot_description, group_name, world_frame, tcp_frame)) {
        ROS_INFO("Could not initialize robot model");
        return -1;
    }

    // 3. Create a planner and initialize it with our robot model
    descartes_planner::DensePlanner planner;
    // planner.initialize(&model);
    planner.initialize(descartes_core::RobotModelConstPtr(&model));

    // 4. Feed the trajectory to the planner
    if (!planner.planPath(points)) {
        ROS_ERROR("Could not solve for a valid path");
        return -2;
    }

    TrajectoryVec result;
    if (!planner.getPath(result)) {
        ROS_ERROR("Could not retrieve path");
        return -3;
    }

    // 5. Translate the result into a type that ROS understands
    // Get Joint Names
    std::vector<std::string> names;
    nh.getParam("controller_joint_names", names);
    // Generate a ROS joint trajectory with the result path, robot model, given joint names,
    // a certain time delta between each trajectory point
    trajectory_msgs::JointTrajectory joint_solution = toROSJointTrajectory(result, model, names, 1.0);

    // 6. Send the ROS trajectory to the robot for execution
    if (!executeTrajectory(joint_solution)) {
        ROS_ERROR("Could not execute trajectory!");
        return -4;
    }
#if 0

    TrajectoryVec results;
    TrajectoryVec points;
    descartes_core::TrajectoryPtPtr next_point =
            descartes_core::TrajectoryPtPtr(new descartes_trajectory::JointTrajectoryPt(joints));
    points.push_back(std::move(next_point));
    if (RCS::Controller.trajectory_model->_planner.planPath(points)) {
        RCS::Controller.trajectory_model->_planner.getPath(results);
        printf("Planned path successfully\n");
    }
#endif
}

void TestKinematics(ros::NodeHandle &nh) {
    RosKinematics kin;
    kin.Init(std::string("manipulator"), std::string("tool0"));
    std::vector<double> currentjoints = kin.GetJointValues();
    std::cout << "Current=" << VectorDump<double> (currentjoints).c_str();
    //std::cout << "answer 384.987, 0.040, -0.007, -179.992, 0.001, 0.006\n";
    std::vector<double> joints = ToVector(6, 0.004, 16.690, -50.470, -0.012, -39.532, -0.002);
    // transform angles from degree to radians
    std::transform(joints.begin(), joints.end(), joints.begin(),
            std::bind1st(std::multiplies<double>(), M_PI / 180.0));
    RCS::Pose pose = kin.FK(joints);
    std::cout << DumpUrdfPose(pose).c_str();
    std::vector<double> joints1 = kin.IK(pose, currentjoints);
    // This works !?!!
    std::cout << "Test Fk/Ik=" << VectorDump<double> (joints1).c_str();
}

