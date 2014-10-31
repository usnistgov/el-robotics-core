/*
  irclient.cpp -- ROS-Industrial Industrial Robot Client Shell

  Publishes joint trajectory goals to the Industrial Robot Client,
  and subscribes to the feedback and results. 

  Information from ROS utilities: 

  rostopic info /joint_trajectory_action/goal
  Type: control_msgs/FollowJointTrajectoryActionGoal

  rosmsg show control_msgs/FollowJointTrajectoryGoal
  trajectory_msgs/JointTrajectory trajectory
    std_msgs/Header header
      uint32 seq
      time stamp
      string frame_id
    string[] joint_names
    trajectory_msgs/JointTrajectoryPoint[] points
      float64[] positions
      float64[] velocities
      float64[] accelerations
      float64[] effort
      duration time_from_start
  control_msgs/JointTolerance[] path_tolerance
    string name
    float64 position
    float64 velocity
    float64 acceleration
  control_msgs/JointTolerance[] goal_tolerance
    string name
    float64 position
    float64 velocity
    float64 acceleration
  duration goal_time_tolerance

  rostopic info /joint_trajectory_action/cancel 
  Type: actionlib_msgs/GoalID

  rosmsg show actionlib_msgs/GoalID 
  time stamp
  string id

  rostopic info /joint_trajectory_action/feedback 
  Type: control_msgs/FollowJointTrajectoryActionFeedback

  rosmsg show control_msgs/FollowJointTrajectoryActionFeedback
  std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  actionlib_msgs/GoalStatus status
    uint8 PENDING=0
    uint8 ACTIVE=1
    uint8 PREEMPTED=2
    uint8 SUCCEEDED=3
    uint8 ABORTED=4
    uint8 REJECTED=5
    uint8 PREEMPTING=6
    uint8 RECALLING=7
    uint8 RECALLED=8
    uint8 LOST=9
    actionlib_msgs/GoalID goal_id
      time stamp
      string id
    uint8 status
    string text
  control_msgs/FollowJointTrajectoryFeedback feedback
    std_msgs/Header header
      uint32 seq
      time stamp
      string frame_id
    string[] joint_names
    trajectory_msgs/JointTrajectoryPoint desired
      float64[] positions
      float64[] velocities
      float64[] accelerations
      float64[] effort
      duration time_from_start
    trajectory_msgs/JointTrajectoryPoint actual
      float64[] positions
      float64[] velocities
      float64[] accelerations
      float64[] effort
      duration time_from_start
    trajectory_msgs/JointTrajectoryPoint error
      float64[] positions
      float64[] velocities
      float64[] accelerations
      float64[] effort
      duration time_from_start

  rostopic info /joint_trajectory_action/result
  Type: control_msgs/FollowJointTrajectoryActionResult

  rosmsg show control_msgs/FollowJointTrajectoryActionResult
  rosmsg show control_msgs/FollowJointTrajectoryActionResult 
  std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  actionlib_msgs/GoalStatus status
    uint8 PENDING=0
    uint8 ACTIVE=1
    uint8 PREEMPTED=2
    uint8 SUCCEEDED=3
    uint8 ABORTED=4
    uint8 REJECTED=5
    uint8 PREEMPTING=6
    uint8 RECALLING=7
    uint8 RECALLED=8
    uint8 LOST=9
    actionlib_msgs/GoalID goal_id
      time stamp
      string id
    uint8 status
    string text
  control_msgs/FollowJointTrajectoryResult result
    int32 SUCCESSFUL=0
    int32 INVALID_GOAL=-1
    int32 INVALID_JOINTS=-2
    int32 OLD_HEADER_TIMESTAMP=-3
    int32 PATH_TOLERANCE_VIOLATED=-4
    int32 GOAL_TOLERANCE_VIOLATED=-5
    int32 error_code

  rostopic info /joint_states
  Type: sensor_msgs/JointState

  std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  string[] name
  float64[] position
  float64[] velocity
  float64[] effort
*/
  
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <float.h>

#include <sstream>
  
#include <ros/ros.h>
#include <control_msgs/FollowJointTrajectoryActionGoal.h>
#include <control_msgs/FollowJointTrajectoryActionFeedback.h>
#include <sensor_msgs/JointState.h>

static bool debug = false;

static control_msgs::FollowJointTrajectoryActionGoal goal_buf;

static control_msgs::FollowJointTrajectoryActionFeedback feedback_buf;

static sensor_msgs::JointState joint_state_buf;

static void feedback_callback(const control_msgs::FollowJointTrajectoryActionFeedback::ConstPtr& msg)
{
  feedback_buf = *msg;

  if (debug) {
    std::stringstream s;
    std::string indent("1> ");
    ros::message_operations::Printer<control_msgs::FollowJointTrajectoryActionFeedback> p;
    p.stream(s, indent, *msg);
    std::cout << s << std::endl;
  }
}

static void joint_state_callback(const sensor_msgs::JointState::ConstPtr& msg)
{
  joint_state_buf = *msg;

  if (debug) {
    std::stringstream s;
    std::string indent("2> ");
    ros::message_operations::Printer<sensor_msgs::JointState> p;
    p.stream(s, indent, *msg);
    std::cout << s.str() << std::endl;
  }
}

int main(int argc, char **argv)
{
  int ros_argc;
  char **ros_argv;
  const char *node_name = "irclient";
  double period = 1;
  int retval;
  int option;
#define PROMPT_LEN 80
  char prompt[PROMPT_LEN];
  char *line;
  char *ptr;
  int i1;
  double d1, d2, d3, d4, d5, d6, d7;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":t:d");
    if (option == -1)
      break;

    switch (option) {
    case 't':
      period = atof(optarg);
      if (period <= FLT_MIN) period = FLT_MIN;
      break;

    case 'd':
      debug = true;
      break;

    case ':':
      fprintf(stderr, "missing value for -%c\n", optopt);
      return 1;
      break;

    default:
      fprintf (stderr, "unrecognized option -%c\n", optopt);
      return 1;
      break;
    }
  }

  // pass everything after a '--' separator to ROS
  ros_argc = argc - optind;
  ros_argv = &argv[optind];

  if (debug) {
    printf("ros::init(");
    for (int t = 0; t < ros_argc; t++) {
      printf("%s ", ros_argv[t]);
    }
    printf("%s)\n", node_name);
  }
  ros::init(ros_argc, ros_argv, node_name);

  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;

  pub = nh.advertise<control_msgs::FollowJointTrajectoryActionGoal>("joint_trajectory_action/goal", 1);
  sub = nh.subscribe("joint_trajectory_action/feedback", 1, feedback_callback);
  sub = nh.subscribe("/joint_states", 1, joint_state_callback);

  ros::Rate loop_rate(1.0 / period);

  while (ros::ok()) {
    ros::spinOnce();
  }

  return 0;
}
