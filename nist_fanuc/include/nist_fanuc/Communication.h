/* 
 * File:   Communication.h
 * Author: michalos
 *
 * Created on February 21, 2016, 5:51 PM
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H
#include <boost/thread/mutex.hpp>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <moveit/move_group_interface/move_group.h>
#include <actionlib/client/simple_action_client.h>

#include <std_msgs/Float64.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <control_msgs/JointTrajectoryControllerState.h>
#include <control_msgs/QueryTrajectoryState.h>

class CJointReader {
public:
    CJointReader(ros::NodeHandle &nh);
    sensor_msgs::JointState GetCurrentReadings();
    void Start();
    std::vector<double> GetJointValues();
    bool IsNewPosition();
    ////////////////////////////////////////////////////////////////////
    void callback(const sensor_msgs::JointState::ConstPtr& msg);
    ros::NodeHandle &_nh;
    sensor_msgs::JointState _latestreading;
    sensor_msgs::JointState _lastreading;
    ros::Subscriber sub;
    // Not sure why you'd want to keep ring of last n readings ...
    std::vector<sensor_msgs::JointState> _readings;
    static boost::mutex _reader_mutex;
};

class CJointWriter {
public:
    CJointWriter(ros::NodeHandle &nh);

    // POsition only for now
    bool JointTrajectoryWrite(std::vector<sensor_msgs::JointState>);
    bool JointTrajectoryPositionWrite(sensor_msgs::JointState joint);
    ////////////////////////////////
    ros::Publisher traj_pub;
    std::vector<std::string> jointnames;
    static boost::mutex _writer_mutex;
};

#endif	/* COMMUNICATION_H */

