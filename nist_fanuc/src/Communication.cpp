

#include "Communication.h"
using namespace std;
boost::mutex CJointReader::_reader_mutex;

void CJointReader::callback(const sensor_msgs::JointState::ConstPtr& msg) {
     boost::unique_lock<boost::mutex> scoped_lock (_reader_mutex);
     _lastreading=_latestreading;
    _latestreading.position.clear();
    _latestreading.position.insert(_latestreading.position.begin(), msg->position.begin(),
            msg->position.end());
    _latestreading.velocity = msg->velocity;
    _latestreading.effort = msg->effort;
}

CJointReader::CJointReader(ros::NodeHandle &nh): _nh(nh) {
}

void CJointReader::Stop() {
    sub.shutdown();
}
sensor_msgs::JointState CJointReader::GetCurrentReadings() {
    boost::unique_lock<boost::mutex> scoped_lock(_reader_mutex);
    return _latestreading;
}

void CJointReader::Start() {
    sub = _nh.subscribe("joint_states", 10, &CJointReader::callback, this);
}

std::vector<double> CJointReader::GetJointValues() {
    return _latestreading.position;
}

//bool CJointReader::IsNewPosition() {
//    return std::equal(_latestreading.position.begin(), _latestreading.position.end(), _lastreading.position.begin());
//}
//-------------------------------------
boost::mutex CJointWriter::_writer_mutex;
CJointWriter::CJointWriter(ros::NodeHandle &nh) {
     nh.getParam("controller_joint_names", jointnames);
    // Trajectory publisher
    traj_pub = nh.advertise<trajectory_msgs::JointTrajectory>("joint_path_command", 1);
}
bool CJointWriter::JointTrajectoryPositionWrite(sensor_msgs::JointState joint) {

    boost::unique_lock<boost::mutex> scoped_lock(_writer_mutex);
    trajectory_msgs::JointTrajectory traj;
    std::vector<trajectory_msgs::JointTrajectoryPoint> points;
    size_t n_joints = joint.position.size();

    // Where we are going
    trajectory_msgs::JointTrajectoryPoint point;
    point.positions.resize(n_joints);
    point.positions = joint.position;
    point.velocities.resize(n_joints, 0.0);
    point.accelerations.resize(n_joints, 0.0);
    
    traj.joint_names = jointnames;
    traj.points.resize(1, point);
    // Send trajectory
    traj.header.stamp = ros::Time(0); // Start immediately
    traj_pub.publish(traj);
    return true;
}
bool CJointWriter::JointTrajectoryWrite(std::vector<sensor_msgs::JointState> joints ) {
    
   for (size_t i = 0; i < joints.size(); i++) {
        JointTrajectoryPositionWrite(joints[i]);
    }
    return true;
}
