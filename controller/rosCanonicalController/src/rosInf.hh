#ifndef __rosInf
#define __rosInf

#include <ros/ros.h>
#include "navigationGoal.hh"
#include <usarsim_inf/EffectorStatus.h>
#include <usarsim_inf/ToolchangerStatus.h>
#include <usarsim_inf/EffectorCommand.h>
#include <actionlib/client/simple_action_client.h>
#include <controller.hh>
#include <Point.h>

enum EffectorType
{
	ROS_INF_GRIPPER = 1,
	ROS_INF_TOOLCHANGER
};
class EffectorController
{
public:
	EffectorController();
	ros::Subscriber subscriber;
	ros::Publisher publisher;
	usarsim_inf::EffectorCommand goalState;
	usarsim_inf::EffectorStatus currentState;
	void initGripperSubscriber(const std::string &topicName);
	void initToolchangerSubscriber(const std::string &topicName);
	bool isType(EffectorType type);
	bool isPublished();
private:
	void gripperCallback(const usarsim_inf::EffectorStatusConstPtr &msg);
	void toolchangerCallback(const usarsim_inf::ToolchangerStatusConstPtr &msg);
	bool published;
	EffectorType type;
};

class RosInf
{
public:
  RosInf();
  ~RosInf();
  int initArmNavigation();
  int initEffectors();
  void waitForEffectors();
  bool isReady();
  void setEffectorGoal(const usarsim_inf::EffectorCommand &command, EffectorType type);
  void shutDown();
  bool init();
  void setEndPointTolerance(double tolerance);
  void setLengthUnits(std::string units);
  void waitForArmGoal(double x,  double y, double z, double xRot, double yRot, double zRot, double wRot);
  void waitForArmGoal(double x,  double y, double z, double xAxisX, double xAxisY, double xAxisZ, double zAxisX,
  	double zAxisY, double zAxisZ);
private:
  std::string lengthUnits; //either "inch," "mm," or "meter"
  bool ready;
  //arm navigation 
  NavigationGoal armGoal;
  actionlib::SimpleActionClient<arm_navigation_msgs::MoveArmAction> *moveArmClient;
  //ROS status and command topic subscribers and publishers 
  std::vector<EffectorController> effectorControllers;
};

#endif
