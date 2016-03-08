

#include "moveit.h"
#include "Globals.h"
#include "urdf_model/eigenmath.h"
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

void TestMoveit(ros::NodeHandle &nh)
{

    MoveitPlanning moveit(nh);
    std::vector<double> js = moveit.GetJointValues();
    std::cout << "Current joints=" << VectorDump<double> (js).c_str();
    urdf::Pose p = moveit.GetCurrentPose();
    std::cout << "Current pose=" << DumpUrdfPose(p); 
#if 0
    JointState joints;
    joints.position = ToVector<double>(6, 0.00, 0.0, 0.0, 0.0, 0.0, 0.0);
    //joints.position = ToVector<double>(6, 0.004, 16.690, -50.470, -0.012, -39.532, -0.002);
    // transform angles from degree to radians
//    std::transform(joints.position.begin(), joints.position.end(), joints.position.begin(),
//            std::bind1st(std::multiplies<double>(), M_PI / 180.0));
//    joints.position=moveit.SetRandomJoints();
   // joints.velocity.resize(6,0.0);
   //joints.effort.resize(6,0.0);
    moveit.Plan(joints);
    js = moveit.GetJointValues();
    std::cout << "Current joints=" << VectorDump<double> (js).c_str();
    sleep(15.0);

    joints.position = moveit.SetRandomJoints();
    std::cout << "Random assigned joints=" << VectorDump<double> (joints.position).c_str();
    moveit.Plan(joints);
    sleep(15.0);
    js = moveit.GetJointValues();
    std::cout << "Current joints=" << VectorDump<double> (js);

    Eigen::Affine3d pose;
    double Z_OFFSET=0;
    double f1= .464,f2= .0,f3= 0.696;
    double f4=0, f5=0.0, f6=0.0;
    f4 = -f4 * M_PI / 180;
    f5 = f5 * M_PI / 180;
    f6 = -f6 * M_PI / 180;
    std::cout << "f4" << f4 << "f5" << f5 << "f6" << f6 << std::endl;
    Eigen::Affine3d ax = Eigen::Affine3d(Eigen::AngleAxisd(f4, Eigen::Vector3d(1, 0, 0)));
    Eigen::Affine3d ay = Eigen::Affine3d(Eigen::AngleAxisd(f5, Eigen::Vector3d(0, 1, 0)));
    Eigen::Affine3d az = Eigen::Affine3d(Eigen::AngleAxisd(f6, Eigen::Vector3d(0, 0, 1)));
    //std::cout << ax << ay << az << std::endl;
    pose = Eigen::Translation3d(f1, f2, f3 + Z_OFFSET) * ax * ay * az;
    Eigen::Matrix3d m = pose.rotation();
    Eigen::Quaterniond q(m); //  = EMatrix2Quaterion(m);
    q.normalize();
    pose = Eigen::Translation3d(pose.translation()) *q;
   std::cout << DumpEPose(ConvertPose(affine3d2UrdfPose(pose))).c_str();
    moveit.Plan(pose);
#endif
    //geometry_msgs::Pose target_pose1;
    //    target_pose1.orientation.x = .0;
    //    target_pose1.orientation.y = .0;
    //    target_pose1.orientation.z = .0;
    //    target_pose1.orientation.w = 1.0;
    //    target_pose1.position.x = 0.28;
    //    target_pose1.position.y = 0.0;
    //    target_pose1.position.z = 0.38;
    urdf::Pose target_pose1;
    target_pose1.rotation.x = .0;
    target_pose1.rotation.y = .0;
    target_pose1.rotation.z = .0;
    target_pose1.rotation.w = 1.0;
    target_pose1.position.x = 0.28;
    target_pose1.position.y = 0.0;
    target_pose1.position.z = 0.38;
    moveit.Plan(target_pose1);

    sleep(15.0);
    js = moveit.GetJointValues();
    std::cout << "Current joints=" << VectorDump<double> (js);
                       
}
