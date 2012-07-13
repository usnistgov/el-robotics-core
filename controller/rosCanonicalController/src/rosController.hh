#ifndef __rosController
#define __rosController

#include <ros/ros.h>
#include "navigationGoal.hh"
#include <usarsim_inf/EffectorStatus.h>
#include <usarsim_inf/EffectorCommand.h>
#include <actionlib/client/simple_action_client.h>
#include <controller.hh>
#include <Point.h>


class EffectorController
{
public:
	EffectorController();
	ros::Subscriber subscriber;
	ros::Publisher publisher;
	usarsim_inf::EffectorCommand goalState;
	usarsim_inf::EffectorStatus currentState;
	void initSubscriber(const std::string &topicName);
private:
	void statusCallback(const usarsim_inf::EffectorStatusConstPtr &msg);
	bool published;
};

class RosController
{
public:
  RosController();
  int initArmNavigation();
  int initEffectors();
  void waitForEffectors();
  bool isReady();
  void setEffectorGoal(const usarsim_inf::EffectorCommand &command);
  void shutDown();
  bool init();
private:
  bool ready;
  //arm navigation 
  NavigationGoal armGoal;
  actionlib::SimpleActionClient<arm_navigation_msgs::MoveArmAction> *moveArmClient;
  //ROS status and command topic subscribers and publishers 
  std::vector<EffectorController> effectorControllers;
};

#endif
