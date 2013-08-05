#include "ros/ros.h"
#include <urdf/model.h>

/**
  \namespace RobotDescription
  \brief This namespace contains functions to assist in reading relevant planning data from ROS parameters.
  \addtogroup RosControl
  @{
*/

namespace RobotDescription
{
  void walkToBaseLink(boost::shared_ptr<const urdf::Link> link, std::string baseName, std::vector<std::string> &joints);
  bool getPlanningInfo(std::string &actuatorName, std::string &tipName, std::string &baseName);
  void getJointNames(const std::string &tipName, const std::string &baseName, std::vector<std::string> &jointNames);
}


/** @} */
