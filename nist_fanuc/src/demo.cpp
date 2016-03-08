// Core ros functionality like ros::init and spin
#include <ros/ros.h>
// ROS Trajectory Action server definition
#include <control_msgs/FollowJointTrajectoryAction.h>
// Means by which we communicate with above action-server
#include <actionlib/client/simple_action_client.h>

// Includes the descartes robot model we will be using
#include <descartes_moveit/moveit_state_adapter.h>
// Includes the descartes trajectory type we will be using
#include <descartes_trajectory/axial_symmetric_pt.h>

#include <descartes_trajectory/cart_trajectory_pt.h>
// Includes the planner we will be using
#include <descartes_planner/dense_planner.h>
#include <descartes_planner/sparse_planner.h>

#include <descartes_trajectory/cartesian_interpolator.h>

//subscriber msgs
#include <std_msgs/String.h>

#include <stdio.h>      // stdin, stderr 
#include <stddef.h>     // NULL, sizeof, size_t 
#include <stdlib.h>     // atoi, atof, system
#include <ctype.h>      // isspace
#include <math.h>
#include <unistd.h>     //usleep
#include <fcntl.h>
#include <iostream>      //cout
#include <sstream>

typedef std::vector<descartes_core::TrajectoryPtPtr> TrajectoryVec;
typedef TrajectoryVec::const_iterator TrajectoryIter;

    trajectory_msgs::JointTrajectory
toROSJointTrajectory(const TrajectoryVec& trajectory,
        const descartes_core::RobotModel& model,
        const std::vector<std::string>& joint_names,
        const std::vector<double>& time_delay)
{
    // Fill out information about our trajectory
    trajectory_msgs::JointTrajectory result;
    result.header.stamp = ros::Time::now();
    result.header.frame_id = "world_frame";
    result.joint_names = joint_names;

    // For keeping track of time-so-far in the trajectory
    double time_offset = 0.0;
    // Loop through the trajectory
    int i = 0;
    for (TrajectoryIter it = trajectory.begin(); it != trajectory.end(); ++it, ++i)
    {
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
        time_offset += time_delay[i];
        ROS_WARN("time: %f\n", time_delay[i]);

        result.points.push_back(pt);
    }

    return result;
}

bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory, const std::string& trajectory_ns)
{
    // Create a Follow Joint Trajectory Action Client
    actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac(trajectory_ns, true);
    if (!ac.waitForServer(ros::Duration(2.0)))
    {
        ROS_ERROR("Could not connect to action server");
        return false;
    }

    control_msgs::FollowJointTrajectoryGoal goal;
    goal.trajectory = trajectory;
    goal.goal_time_tolerance = ros::Duration(1.0);

    ac.sendGoal(goal);

    if (ac.waitForResult(goal.trajectory.points[goal.trajectory.points.size()-1].time_from_start + ros::Duration(5)))
    {
        ROS_INFO("Action server reported successful execution");
        return true;
    } else {
        ROS_WARN("Action server could not execute trajectory");
        return false;
    }
}

int main (int argc, char **argv)
{

    /*SET GLOBAL PROPERTIES*/

    double Z_OFFSET = .33;
    std::string robot_description = argv[1];
    std::string group_name = argv[2];
    std::string world_frame = argv[3];
    std::string tcp_frame = argv[4];
    std::string joint_trajectory_ns = argv[5];

    /* INITIALIZE ROS NODE AND DESCARTES MODEL */

    ros::init(argc, argv, "fanuc_demo");
    ros::AsyncSpinner spinner(1);
    spinner.start();
    ros::NodeHandle nh;

    //	    descartes_core::RobotModelPtr model (new descartes_moveit::MoveitStateAdapter);
    descartes_moveit::MoveitStateAdapterPtr model (new descartes_moveit::MoveitStateAdapter);
    if (!model->initialize(robot_description, group_name, world_frame, tcp_frame))
    {
        ROS_INFO("Could not initialize robot model");
        exit(-1);
    }
    model->setCheckCollisions(true);
    ROS_INFO("Robot initialized successfully!");

    descartes_planner::DensePlanner planner;

    descartes_trajectory::CartesianInterpolator cart_interp;
    cart_interp.initialize(model, .2, .1, .01);

    planner.initialize(model);

    // Get Joint Names
    std::vector<std::string> j_names;
    nh.getParam("controller_joint_names", j_names);

    /* CONSOLE SPECIFIC VARIABLES */

    enum TrajectoryType {JOINT, CART, AXIAL};
    TrajectoryType traj_flag = CART;
    descartes_trajectory::AxialSymmetricPt::FreeAxis axis = descartes_trajectory::AxialSymmetricPt::Z_AXIS;

    TrajectoryVec points;
    TrajectoryVec results;
    std::vector<double> times;


    printf("***Descartes Trajectory Tool***\n");
    printf("Type h for help\n");
    while (true)
    {
        printf("> ");
        using namespace descartes_core;
        using namespace descartes_trajectory;
        char inbuf[1024];
        double f1, f2, f3, f4, f5, f6, f7;
        if (NULL == fgets(inbuf, sizeof(inbuf), stdin)) break;
        // skip leading whitespace
        char *ptr = inbuf;
        while (isspace(*ptr)) ptr++;
        if ('q' == *ptr)
        {
            printf("Quitting...\n");
            break;
        }
        if ('h' == *ptr)
        {
            printf("Help:\n");
            printf("a - axial (Z axis)\n");
            printf("c - cartesian\n");
            printf("j - joint\n\n");
            printf("i - interpolate\n");
            printf("p - plan\n");
            printf("e - execute\n\n");
            printf("q - quit\n");
            printf("Enter 7 numbers (separated by spaces) to add a trajectory point\n");
            printf("Cart and Axial: <x> <y> <z> <r> <p> <y> <t>\n");
            printf("Joint: <j0> <j1> <j2> <j3> <j4> <j5> <t>\n\n");
            continue;
        }
        else if ('c' == *ptr)
        {
            traj_flag = CART;
            printf("Trajectory type set to Cartesian\n");
            continue;
        }
        else if ('j' == *ptr)
        {
            traj_flag = JOINT;
            printf("Trajectory type set to Joint\n");
            continue;
        }
        else if ('a' == *ptr)
        {
            traj_flag = AXIAL;
            printf("Trajectory type set to Axial Symmetric\n");
            continue;
        }
        else if ('r' == *ptr)
        {
            printf("Resetting trajectories...\n");
            results.clear();
            points.clear();
            times.clear();
            continue;
        }
        else if ('i' == *ptr)
        {
            TrajectoryVec interp_pts;
            if (cart_interp.interpolate(points, interp_pts))
            {
                std::vector<double> fake_times(interp_pts.size(), 1.0);
                times = fake_times;
                points.clear();
                points = interp_pts;
                printf("Interpolation successful\n");
            }
            else
            {
                printf("Interpolation failed\n");
            }
            continue;
        }
        else if ('e' == *ptr)
        {
            printf("Executing...\n");

            //add dummy start point (needed for gazebo, which drops first point)
            std::vector<double> joints;
            model->getState()->copyJointGroupPositions(group_name, joints);
            TrajectoryPtPtr current_pos = TrajectoryPtPtr(new JointTrajectoryPt(joints));
            results.insert(results.begin(),current_pos);
            times.push_back(1.0);
            if (!results.empty())
            {
                trajectory_msgs::JointTrajectory joint_solution = toROSJointTrajectory(results, *model, j_names, times);
                executeTrajectory(joint_solution, joint_trajectory_ns);
            }
            results.erase(results.begin());
            times.pop_back();
            continue;
        }
        else if ('p' == *ptr)
        {
            printf("Planning...\n");
            if (planner.planPath(points) && planner.getPath(results))
            {
                printf("Planned path successfully\n");
            }
        }
        else if (7 == sscanf(ptr, "%lf %lf %lf %lf %lf %lf %lf",
                    &f1, &f2, &f3, &f4, &f5, &f6, &f7)) {
            printf("Adding points...\n");
            TrajectoryPtPtr next_point;
            std::vector<double> joint_pt;
            joint_pt.clear();
            switch(traj_flag)
            {
                case JOINT:
                    {
                        joint_pt.push_back(f1);
                        joint_pt.push_back(f2);
                        joint_pt.push_back(f3);
                        joint_pt.push_back(f4);
                        joint_pt.push_back(f5);
                        joint_pt.push_back(f6);
                        next_point = TrajectoryPtPtr(new JointTrajectoryPt(joint_pt));
                    }; break;
                case CART:
                    {
                        f4 = -f4 * M_PI / 180;
                        f5 = f5 * M_PI / 180;
                        f6 = -f6 * M_PI / 180;
                        Eigen::Affine3d pose;
                        Eigen::Affine3d ax = Eigen::Affine3d(Eigen::AngleAxisd(f4, Eigen::Vector3d(1, 0, 0)));
                        Eigen::Affine3d ay = Eigen::Affine3d(Eigen::AngleAxisd(f5, Eigen::Vector3d(0, 1, 0)));
                        Eigen::Affine3d az = Eigen::Affine3d(Eigen::AngleAxisd(f6, Eigen::Vector3d(0, 0, 1)));
                        pose = Eigen::Translation3d(f1, f2, f3 + Z_OFFSET) * ax * ay * az;

                        next_point = TrajectoryPtPtr(new CartTrajectoryPt(TolerancedFrame(pose))) ;
                    }; break;
                case AXIAL:
                    {
                        next_point = TrajectoryPtPtr(new AxialSymmetricPt( f1, f2, f3 + Z_OFFSET,
                                    f4, f5, f6, M_PI/2.0, AxialSymmetricPt::Z_AXIS));
                    }; break;
            }
            points.push_back(std::move(next_point));
            times.push_back(std::move(f7));

            printf("Added point(s)\n");
            printf("Point Vector Size: %ld, Time Vector Size %ld\n", points.size(), times.size());
            continue;
        }
    }
}
