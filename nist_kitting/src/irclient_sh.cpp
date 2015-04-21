/*
  irclient.cpp -- ROS-Industrial Industrial Robot Client Shell

  Publishes joint trajectory goals to the Industrial Robot Client,
  and subscribes to the feedback and results. 

  Information from ROS utilities: 

  rostopic info /joint_trajectory_action/goal
  Type: control_msgs/FollowJointTrajectoryActionGoal

  rosmsg show control_msgs/FollowJointTrajectoryActionGoal
  std_msgs/Header header
    uint32 seq
    time stamp
    string frame_id
  actionlib_msgs/GoalID goal_id
    time stamp
    string id
  control_msgs/FollowJointTrajectoryGoal goal
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

#include <string>
#include <sstream>
#include <vector>

#include <ulapi.h>
  
#include <ros/ros.h>
#include <control_msgs/FollowJointTrajectoryActionGoal.h>
#include <control_msgs/FollowJointTrajectoryActionFeedback.h>
#include <sensor_msgs/JointState.h>

enum {DEFAULT_JOINT_NUM = 6};

static bool debug = false;

template<typename T> std::string to_string(T t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

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
    std::cout << s.str() << std::endl;
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

struct rosloop_thread_args {
  double hz;
};

static void rosloop_thread_code(rosloop_thread_args *args)
{
  ros::Rate rate(args->hz);

  while (ros::ok()) {
    ros::spinOnce();
    rate.sleep();
  }

  return;
}

int main(int argc, char **argv)
{
  int ros_argc;
  char **ros_argv;
  const char *node_name = "irclient";
  double period = 1;
  int retval;
  int option;
  ulapi_task_struct rosloop_thread;
  rosloop_thread_args args;
  int joint_num = DEFAULT_JOINT_NUM;

  opterr = 0;
  while (true) {
    option = getopt(argc, argv, ":n:t:d");
    if (option == -1)
      break;

    switch (option) {
    case 'n':
      joint_num = atoi(optarg);
      if (joint_num < 1) joint_num = 1;
      break;

    case 't':
      period = atof(optarg);
      if (period < FLT_MIN) period = FLT_MIN;
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
  sub = nh.subscribe("joint_states", 1, joint_state_callback);

  ulapi_task_init(&rosloop_thread);
  args.hz = 1.0 / period;
  ulapi_task_start(&rosloop_thread, reinterpret_cast<ulapi_task_code>(rosloop_thread_code), reinterpret_cast<void *>(&args), ulapi_prio_highest(), 0);

  /*
    Here's our goal, which we'll set up with some defaults and then
    set with actual points as they are typed in
   */
  control_msgs::FollowJointTrajectoryActionGoal goal;
  /*
    Tolerances for goal position, speed, and accel
   */
  control_msgs::JointTolerance tol;

  for (int t = 0; t < joint_num; t++) {
    goal.goal.trajectory.joint_names.push_back(std::string("joint_") + to_string(t+1));
    // set to some reasonable initial values
    tol.position = 0.001;
    tol.velocity = 0.1;
    tol.acceleration = 0.1;
    tol.name = std::string("path_tolerance_") + to_string(t+1);
    goal.goal.path_tolerance.push_back(tol);
    tol.name = std::string("goal_tolerance_") + to_string(t+1);
    goal.goal.goal_tolerance.push_back(tol);
  }
  goal.goal.goal_time_tolerance = ros::Duration(0.1);
  if (debug) {
    std::stringstream s;
    std::string indent("0> ");
    ros::message_operations::Printer<control_msgs::FollowJointTrajectoryActionGoal> p;
    p.stream(s, indent, goal);
    std::cout << s.str() << std::endl;
  }

  bool done = false;
  float duration = 1;
  bool do_pos = true;
  trajectory_msgs::JointTrajectoryPoint jtp;

  while (! done) {
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    char *endptr;
    std::vector<double> dvec;
    double d1;
    static int goal_id = 1;

    // print prompt
    printf("> ");
    fflush(stdout);
    // get input line
    if (NULL == fgets(inbuf, sizeof(inbuf), stdin)) break;
    // skip leading whitespace
    ptr = inbuf;
    while (isspace(*ptr)) ptr++;
    // strip off trailing whitespace
    endptr = inbuf + strlen(inbuf);
    while ((isspace(*endptr) || 0 == *endptr) && endptr >= ptr) *endptr-- = 0;
    while (endptr >= ptr) *endptr = tolower(*endptr--);
    // now 'ptr' is the stripped input string

    do {
      if (0 == *ptr) break; // blank line

      if ('q' == *ptr) {	// quit
	done = true;
	break;
      }

      if ('d' == *ptr) {
	if (1 == sscanf(ptr, "%*s %lf", &d1)) {
	  duration = d1;
	  printf("using duration %f\n", duration);
	} else {
	  printf("need a duration\n");
	}
	break;
      }

      if ('p' == *ptr) {
	printf("setting positions\n");
	do_pos = true;
	break;
      }

      if ('v' == *ptr) {
	printf("setting velocities\n");
	do_pos = false;
	break;
      }

      if ('t' == *ptr) {
	while (!isspace(*ptr)) ptr++;
	if (0 == *ptr) {
	  printf("need tolerance values\n");
	  break;
	}

	goal.goal.goal_tolerance.clear();
	for (int t = 0; t < joint_num; t++) {
	  d1 = strtod(ptr, &endptr);
	  if (ptr == endptr) break;
	  tol.name = std::string("goal_tolerance_") + to_string(t+1);
	  tol.position = d1;
	  tol.velocity = 0.1;
	  tol.acceleration = 0.1;
	  printf("setting %s to %f\n", tol.name.c_str(), d1);
	  goal.goal.goal_tolerance.push_back(tol);
	  ptr = endptr;
	}
	break;
      }

      jtp.positions.clear();
      if (! do_pos) jtp.velocities.clear();

      do {
	d1 = strtod(ptr, &endptr);
	if (ptr == endptr) break;
	if (do_pos) jtp.positions.push_back(d1);
	else jtp.velocities.push_back(d1);
	ptr = endptr;
      } while (true);
      if (! jtp.positions.empty()) {
	goal.goal_id.stamp = ros::Time::now();
	goal.goal_id.id = std::string("goal_") + to_string(goal_id++);
	jtp.time_from_start = ros::Duration(duration);
	goal.goal.trajectory.points.clear();
	goal.goal.trajectory.points.push_back(jtp);
	pub.publish(goal);
	if (debug) {
	  std::stringstream s;
	  std::string indent("*> ");
	  ros::message_operations::Printer<control_msgs::FollowJointTrajectoryActionGoal> p;
	  p.stream(s, indent, goal);
	  std::cout << s.str() << std::endl;
	}
      }
    } while (false);		// do ... wrapper

  } // while (true)

  return 0;
}
