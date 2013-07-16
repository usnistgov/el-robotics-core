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

#endif
