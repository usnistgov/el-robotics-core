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

/**
 * \brief  The CJointReader is a thread to  accept joint update callbacks from ROS.
 * Uses a ros node handle to tell roscore we are subscribing to joint_state topic.
 * Then, when joint updates occur, the callback routine is invoked and the latest joint values saved.
 */

class CJointReader {
public:
    /*!
     * \brief CJointReader constructor that requires a ROS node handle.
     * \param nh  ros node handle so joint reader can tell roscore we are subscribing to joint_state topic.
     */
    CJointReader(ros::NodeHandle &nh);

    /*!
     * \brief GetCurrentReadings returns the latest joint readings for position, velocity, and effort. It is thread safe.
     */
    sensor_msgs::JointState GetCurrentReadings();

    /*!
     * \brief Start sets up subscriber to joint_state topic messages.
     */
    void Start();

    /*!
     * \brief Stop unsubscribes to joint_state topic.
     */
    void Stop();

    /*!
     * \brief GetJointValues sets up subscriber to joint_state topic messages.
     * \returns a std vector of double containing joint positions 
     */
    std::vector<double> GetJointValues();

    ////////////////////////////////////////////////////////////////////
    void callback(const sensor_msgs::JointState::ConstPtr& msg); /**< type of joint motion to use */
    ros::NodeHandle &_nh; /**< reference pointer to ROS node handle */
    sensor_msgs::JointState _latestreading; /**< latest joint readings */
    sensor_msgs::JointState _lastreading; /**< previous joint readings */
    ros::Subscriber sub; /**< ros subscriber information  */
    // Not sure why you'd want to keep ring of last n readings ...
    //std::vector<sensor_msgs::JointState> _readings; /**< ring of last readings  */
    static boost::mutex _reader_mutex; /**< for mutexed reading access  */
};

/**
 * \brief  The CJointWriter is a thread to  publish new joint values to ROS.
 * Uses a ros node handle to tell roscore we are pusblishing to the joint_path_command topic.
 * Then, when joint updates occur, these are published on joint_path_command the topic.
 */
class CJointWriter {
public:
    /*!
     * \brief CJointWriter constructor that requires a ROS node handle.
     * \param nh  ros node handle so joint reader can tell roscore we are advertising new joint values.
     */
    CJointWriter(ros::NodeHandle &nh);

    /*!
     * \brief JointTrajectoryWrite writes the joint values to joint_state topic messages.
     * \param a std vector of sensor_msgs::JointState describing a series of joints 
     * \return boolean if all writes occurred as expected.
     */
    bool JointTrajectoryWrite(std::vector<sensor_msgs::JointState>);

    /*!
     * \brief JointTrajectoryWrite writes the joint values to joint_state topic messages.
     * \param a sensor_msgs::JointState describing robot joints 
     * \return boolean if write occurred as expected.
     */
    bool JointTrajectoryPositionWrite(sensor_msgs::JointState joint);
    ////////////////////////////////
    ros::Publisher traj_pub; /**< ros publisher information used for joint updates */
    std::vector<std::string> jointnames; /**< ros requries joint names for each joint update  */
    static boost::mutex _writer_mutex; /**< for mutexed writing access to joint values */
};

#endif	/* COMMUNICATION_H */

