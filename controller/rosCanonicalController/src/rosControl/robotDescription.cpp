#include "robotDescription.hh"

/**
  \brief Generate a list of joints between \a link and the link with name \a baseName
  
  \param link The link to start from
  \param tipName The name of the link to stop at
  \param joints A vector of joint names to populate
*/
void RobotDescription::walkToBaseLink(boost::shared_ptr<const urdf::Link> link, std::string baseName, std::vector<std::string> &joints)
{
  //support everything except for UNKNOWN, FIXED, and FREE
  if(link->parent_joint->type == urdf::Joint::PRISMATIC || 
     link->parent_joint->type == urdf::Joint::REVOLUTE  ||
     link->parent_joint->type == urdf::Joint::CONTINUOUS ||
     link->parent_joint->type == urdf::Joint::PLANAR)
  {
    joints.push_back(link->parent_joint->name);
  }
  if(link->getParent()->name != baseName)
  {
    walkToBaseLink(link->getParent(), baseName, joints);
  }
}
/**
  \brief Get basic planning information about the first group found
  \param actuatorName Reference to hold the name of the planning group found
  \param tipName Reference to hold the name of the planning group tip link
  \param tipName Reference to hold the name of the planning group base link
  \return true if the robot_description_planning/groups parameter is set properly, false otherwise
*/
bool RobotDescription::getPlanningInfo(std::string &actuatorName, std::string &tipName, std::string &baseName)
{
  ros::NodeHandle nh;
  XmlRpc::XmlRpcValue planningGroups;
  
  if(nh.getParam("robot_description_planning/groups", planningGroups))
	{
		ROS_ASSERT(planningGroups.getType() == XmlRpc::XmlRpcValue::TypeArray);
		//just control the first planning group found
		if(planningGroups.size() > 0)
		{
			ROS_ASSERT(planningGroups[0]["name"].getType() == XmlRpc::XmlRpcValue::TypeString);
			actuatorName = static_cast<std::string>(planningGroups[0]["name"]);
			tipName = static_cast<std::string>(planningGroups[0]["tip_link"]);
			baseName = static_cast<std::string>(planningGroups[0]["base_link"]);
			return true;
		}
	}
	return false;
}
/**
  \brief Get the names of the joints between the \a baseName and \a tipName
  
  This method reads the \c robot_description parameter to find the names of the joints.
*/
void RobotDescription::getJointNames(const std::string &tipName, const std::string &baseName, std::vector<std::string> &jointNames)
{
  ros::NodeHandle nh;
  std::string robotDescription;
  if(nh.getParam("robot_description", robotDescription))
	{
	  ROS_DEBUG("Searching for 1DOF joints between \"%s\" and \"%s\" in robot_description", baseName.c_str(), tipName.c_str());
	  urdf::Model robotModel;
	  robotModel.initString(robotDescription);
	  boost::shared_ptr<const urdf::Link> tipLinkModel = robotModel.getLink(tipName);
	  jointNames.clear();
	  walkToBaseLink(tipLinkModel, baseName, jointNames);
	  //reverse order (we want parent -> child)
	  std::reverse(jointNames.begin(), jointNames.end());
	}
}
