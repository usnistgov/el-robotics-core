#include <moveit/move_group_interface/move_group.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");

  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(1);
  spinner.start();
  
  moveit::planning_interface::MoveGroup group("manipulator");
  moveit::planning_interface::MoveGroup::Plan my_plan;

  group.setJointValueTarget(group.getCurrentJointValues());
  bool success = group.plan(my_plan);
  ROS_INFO("Cartesian goal: %s", success ? "OK" : "FAILED");    

  geometry_msgs::PoseStamped current_pose = group.getCurrentPose();
  ROS_INFO("Current pose is: %f", current_pose.pose.position.x);

  geometry_msgs::Pose target_pose = current_pose.pose;
  target_pose.position.z += 0.100;
  group.setPoseTarget(target_pose);
  success = group.plan(my_plan);
  ROS_INFO("Cartesian goal: %s", success ? "OK" : "FAILED");    

  ROS_INFO("moving\n");
  group.move();
  ROS_INFO("done\n");

  ros::shutdown();  
  return 0;
}
