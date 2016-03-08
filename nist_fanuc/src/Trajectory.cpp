

#include "Trajectory.h"
#include "RCS.h"

CTrajectory::CTrajectory() {

    _bInited = false;
}

void CTrajectory::Init(std::string robot_description,
        std::string group_name,
        std::string world_frame,
        std::string tcp_frame,
        std::vector<std::string> names,
        bool bCheckCollisions) {
    joint_names=names;
    _robot_description = robot_description;
    _group_name = group_name;
    _world_frame = world_frame;
    _tcp_frame = tcp_frame;
    //_model = descartes_core::RobotModelPtr(new descartes_moveit::MoveitStateAdapter);
    _model = MoveitStateAdapterPtr(new descartes_moveit::MoveitStateAdapter);
    if (!_model->initialize(robot_description, group_name, world_frame, tcp_frame)) {
        ROS_INFO("Could not initialize descartes trajectory planner robot model");
        throw;
    }
    _model->setCheckCollisions(bCheckCollisions);
    // initialize trajectory planner with our robot model
    _planner.initialize(_model);
    _bInited = true;
}

TrajectoryVec CTrajectory::PlanPath(TrajectoryVec points) {
    TrajectoryVec result;
    if (!_planner.planPath(points)) {
        ROS_ERROR("Could not solve for a valid path");
        return result;
    }

 //   _model->updateScene(); // not sure whyere this disappeared to
    
    if (!_planner.getPath(result)) {
        ROS_ERROR("Could not retrieve path");
        return result;
    }
    return result;
}

std::vector<JointState>
CTrajectory::JointTrajectorytoJointStateVector(const TrajectoryVec& trajectory) {
    std::vector<JointState> result;

    // Loop through the trajectory
    int i = 0;
    for (TrajectoryIter it = trajectory.begin(); it != trajectory.end(); ++it, ++i) {
        // Find nominal joint solution at this point
        //std::vector<double> joints;
        JointState joint;
        it->get()->getNominalJointPose(std::vector<double>(), *_model, joint.position);

        // velocity, acceleration, and effort are given dummy values
        joint.velocity.resize(joint.position.size(), 0.0);
        joint.effort.resize(joint.position.size(), 0.0);
        result.push_back(joint);
    }

    return result;
}