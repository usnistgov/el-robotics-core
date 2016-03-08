

#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
// Planner
// ROS Trajectory Action server definition
#include <control_msgs/FollowJointTrajectoryAction.h>
// Means by which we communicate with above action-server
#include <actionlib/client/simple_action_client.h>

// Includes the descartes robot model we will be using
#include <descartes_moveit/moveit_state_adapter.h>
#include <descartes_trajectory/axial_symmetric_pt.h>
#include <descartes_trajectory/cart_trajectory_pt.h>
#include <descartes_planner/dense_planner.h>
#include <descartes_planner/sparse_planner.h>
#include "RCS.h"

typedef std::vector<descartes_core::TrajectoryPtPtr> TrajectoryVec;
typedef TrajectoryVec::const_iterator TrajectoryIter;


// This is not in include files...
//#include <descartes_trajectory/cartesian_interpolator.h>
typedef  boost::shared_ptr<descartes_moveit::MoveitStateAdapter> MoveitStateAdapterPtr;

class CTrajectory {
public:
    CTrajectory();

    void Init(std::string robot_description,
            std::string group_name,
            std::string world_frame,
            std::string tcp_frame,
            std::vector<std::string> names,
            bool bCheckCollisions = true);

    TrajectoryVec PlanPath(TrajectoryVec);

//    trajectory_msgs::JointTrajectory
//    toROSJointTrajectory(const TrajectoryVec& trajectory,
//            const descartes_core::RobotModel& model,
//            const std::vector<std::string>& joint_names,
//            const std::vector<double>& time_delay);

    std::vector<JointState> JointTrajectorytoJointStateVector(const TrajectoryVec& trajectory);
    //trajectory_msgs::JointTrajectory JointTrajectorytoJointStateVector(const  std::vector<JointState>);

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

    MoveitStateAdapterPtr GetModel() {
        return _model;
    }

    descartes_planner::DensePlanner GetDensePlanner() {
        return _planner;
    }

    std::vector<std::string> GetJointNames() {
        return joint_names;
    }
    ////////////////////////////////////////////
    //descartes_core::RobotModelPtr _model;
    MoveitStateAdapterPtr _model;
    
    descartes_planner::DensePlanner _planner;
    //descartes_trajectory::CartesianInterpolator cart_interp;
    std::string _robot_description;
    std::string _group_name;
    std::string _world_frame;
    std::string _tcp_frame;
    std::vector<std::string> joint_names;
    bool _bInited;


};
