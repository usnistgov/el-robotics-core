#ifndef __rosInf
#define __rosInf

#define INCH_TO_METER 0.0254
#define MAX_NAVIGATION_FAILURES 30

#define LOG_FAILURES 0
#define EFFECTOR_TIMEOUT 2.0

#include "ros/ros.h"
#include "navigationGoal.hh"
#include "usarsim_inf/EffectorStatus.h"
#include "usarsim_inf/ToolchangerStatus.h"
#include "usarsim_inf/EffectorCommand.h"
#include "usarsim_inf/SenseObject.h"
#include "actionlib/client/simple_action_client.h"
#include "controller.hh"
#include "database/Point.h"

class RosInf;

enum EffectorType
{
  ROS_INF_GRIPPER = 1,
  ROS_INF_TOOLCHANGER
};
/**
  \addtogroup RosControl
	@{
	\class EffectorController rosInf.hh "rosInf.hh"
	\brief Class to manage end effector subscriber callbacks and command publishers.
	
	This class holds state data for a single effector. State data is updated by subscriber callbacks listening on the effector's topic, and commands can be sent by updating the \c goalState member.
*/
class EffectorController
{
public:
  EffectorController ();
  ros::Subscriber subscriber;
  ros::Publisher publisher;
  usarsim_inf::EffectorCommand goalState;
  usarsim_inf::EffectorStatus currentState;
  template <class M>
  void initSubscriber (const std::string & topicName, RosInf* const infHandle, EffectorType type);
  bool isType (EffectorType type);
  EffectorType getType();
  bool isPublished ();
  const std::string getStatusTopic();
  void gripperCallback(const usarsim_inf::EffectorStatusConstPtr & msg);
  void toolchangerCallback(const usarsim_inf::ToolchangerStatusConstPtr & msg);
private:
  std::string statusTopic;
  bool published;
  EffectorType type;
};
/**
	\class RosInf rosInf.hh "rosInf.hh"
	\brief Interface between a Canonical controller and the USARSimROS node.
	
	This class provides a way to send common commands to the USARSimROS node using a combination of action clients and simple pairs of command/status ROS topics. It manages and updates a vector of EffectorControllers, adding and removing effectors whenever they start or stop publishing status messages on the \c effectorName/status topic.
	
	The class uses a SimpleActionClient to connect to a move_arm action server, and manages a queue of arm pose goals to send to the action server sequentially.
	
	It also provides some basic callbacks for an object sensor that may be attached to the robot. 
*/
class RosInf
{
public:
  RosInf ();
  ~RosInf ();
  int publishEffectors ();
  void waitForEffectors ();
  bool checkCommandDone ();
  bool isInitialized ();
  void setEffectorGoal (const usarsim_inf::EffectorCommand & command,
	    EffectorType type);
	void setEffectorGoal (const usarsim_inf::EffectorCommand & command,
	    std::string effectorTopic);
  void shutDown ();
  bool init ();
  void searchPart (std::string partName);
  void stopMotion ();
  void stopSearch ();
  void setEndPointTolerance (double tolerance);
  void setLengthUnits (std::string units);
  void addArmGoal (double x, double y, double z, double xRot, double yRot,
		   double zRot, double wRot);
  void addArmGoal (double x, double y, double z, double xAxisX, double xAxisY,
		   double xAxisZ, double zAxisX, double zAxisY,
		   double zAxisZ);
	void addArmJointGoal(std::vector<double> jointPosition);
  double getSensorFOV ();
  
  template<class M>
  void effectorCallback(const M & msg, const std::string topicName);
  
  void setGlobalFrame(const std::string &globalFrame);
  
  void getEffectorStatusNames(std::vector<std::string> &effectorNames);
  
private:
    std::string globalFrameName;
    std::string actuatorName;
    std::string lengthUnits;

    std::string activeEffectorName;
  bool effectorAttached;

    tf::TransformListener listener;
  double positionTolerance;

  int initArmNavigation ();
  int initEffectors ();
  int initSensors ();
  bool initialized;
  unsigned int navigationFailureCount;
  
  //arm navigation 
    std::deque < NavigationGoal > armGoals;
    actionlib::SimpleActionClient < arm_navigation_msgs::MoveArmAction >
    *moveArmClient;
  void navigationActiveCallback ();
  void navigationFeedbackCallback (const arm_navigation_msgs::
				   MoveArmFeedbackConstPtr & feedback);
  void navigationDoneCallback (const actionlib::SimpleClientGoalState & state,
			       const arm_navigation_msgs::
			       MoveArmResultConstPtr & result);

  //ROS status and command topic subscribers and publishers 
    std::vector < EffectorController > effectorControllers;  

  //object sensor
  bool hasObjectSensor;
  bool objectSensorInitialized;
  bool scanActive;
  double objectSensorFOV;
    ros::Subscriber objectSensorSub;
  void waitForObjectSensor ();
    std::vector < std::string > findPartNames;
  void objectSensorCallback (const usarsim_inf::SenseObjectConstPtr & msg);
};

/** @} */

#endif
