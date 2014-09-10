#include <string>
#include "database/DAO.h"
#include "database/WorkTable.h"
#include "database/BoxyShape.h"
#include "database/PoseLocation.h"
#include "database/StockKeepingUnit.h"
#include "database/KitTray.h"
#include "database/PartsTray.h"
#include "geometry_msgs/Pose.h"
#include "ros/ros.h"
#include "arm_navigation_msgs/CollisionObject.h"
#include "visualization_msgs/Marker.h"
#include "recurseLocation.h"
#include "tf/tf.h"

/// \file main.cpp

/**
  \brief Check the database for the name of the shape of solid object \a solidObjectName
  \param solidObjectName The name of the object
  \return the \c _NAME of the shape associated with the solid object, or an empty string if not found
  
  This function checks the hadbyInternalShape_SolidObject column of the InternalShape table for \a solidObjectName. If the name is found, the associated shape \c _NAME is returned. If not, the Part, KitTray, and PartsTray tables are checked for \a solidObjectName, and if the name is found, the StockKeepingUnit for the object is used to find the shape. 
*/
std::string getShapeName(const std::string &solidObjectName)
{
  DAO * dao = new DAO("InternalShape");
  std::vector<std::string> attributes;
  attributes.push_back("_NAME");
  attributes.push_back("hadByInternalShape_SolidObject");
  std::map<std::string, std::vector<std::string> > shapesMap = dao->getAll(attributes, "InternalShape");
	std::vector<std::string> objectNames = shapesMap["hadByInternalShape_SolidObject"];
	std::vector<std::string>::iterator it = std::find(objectNames.begin(), objectNames.end(), solidObjectName);
	if(it != objectNames.end())
	{
	  int index = std::distance(objectNames.begin(), it);
	  delete dao;
	  return shapesMap["_NAME"][index];
	}
	
	//if object is a part, kit tray, or parts tray, we can get the shape from the Sku
	attributes.clear();
	attributes.push_back("_NAME");
	std::map<std::string, std::vector<std::string> > partsMap = dao->getAll(attributes, "Part");
	it = std::find(partsMap["_NAME"].begin(), partsMap["_NAME"].end(), solidObjectName);
	if(it != partsMap["_NAME"].end())
	{
	  Part *part = new Part(*it);
	  part->get(*it);
	  StockKeepingUnit *sku = part->gethasPart_Sku();
	  sku->get(sku->getname());
	  std::string name = sku->gethasStockKeepingUnit_Shape()->getname();
	  delete part;
	  delete dao;
	  return name;
	}
	std::map<std::string, std::vector<std::string> > kitTraysMap = dao->getAll(attributes, "KitTray");
	it = std::find(kitTraysMap["_NAME"].begin(), kitTraysMap["_NAME"].end(), solidObjectName);
	if(it != kitTraysMap["_NAME"].end())
	{
	  KitTray *tray = new KitTray(*it);
	  tray->get(*it);
	  StockKeepingUnit *sku = tray->gethasKitTray_Sku();
	  sku->get(sku->getname());
	  std::string name = sku->gethasStockKeepingUnit_Shape()->getname();
	  delete tray;
	  delete dao;
	  return name;
	}
	std::map<std::string, std::vector<std::string> > partsTraysMap = dao->getAll(attributes, "PartsTray");
	it = std::find(partsTraysMap["_NAME"].begin(), partsTraysMap["_NAME"].end(), solidObjectName);
	if(it != partsTraysMap["_NAME"].end())
	{
	  PartsTray *tray = new PartsTray(*it);
	  tray->get(*it);
	  StockKeepingUnit *sku = tray->gethasPartsTray_Sku();
	  sku->get(sku->getname());
	  std::string name = sku->gethasStockKeepingUnit_Shape()->getname();
	  delete tray;
	  delete dao;
	  return name;
	}
	delete dao;
	return "";
}
/**
  \brief Check the BoxyShape table to see if \a shapeName belongs to a BoxyShape
  \return \c true if the shape is found in the BoxyShape table, \c false otherwise
*/
bool isBoxyShape(const std::string &shapeName)
{
  DAO * dao = new DAO("BoxyShape");
  std::vector<std::string> attributes;
  std::map<std::string, std::string> boxMap = dao->get(shapeName);
  delete dao;
  if(!boxMap.empty())
  {
    return true;
  }
  return false;
}
/**
  \brief Get a shape message suitable for ROS publishing from a BoxyShape pointer
  \param shape The BoxyShape object to convert
  \return The publishable Shape message
*/
arm_navigation_msgs::Shape getBoxShapeMsg(BoxyShape * shape)
{
  arm_navigation_msgs::Shape shapeMsg;
  shapeMsg.type = arm_navigation_msgs::Shape::BOX;
  shapeMsg.dimensions.push_back(shape->gethasBoxyShape_Length());
  shapeMsg.dimensions.push_back(shape->gethasBoxyShape_Width());
  shapeMsg.dimensions.push_back(shape->gethasBoxyShape_Height());
  return shapeMsg;
}
/**
  \brief Get a pose message suitable for ROS publishing from a RecLoc object
  \param loc The RecLoc to convert
  \return The publishable Pose message
*/
geometry_msgs::Pose getPoseMsg(RecLoc &loc)
{
  geometry_msgs::Pose poseMsg;
  poseMsg.position.x = loc.frame.pointXYZ[0];
  poseMsg.position.y = loc.frame.pointXYZ[1];
  poseMsg.position.z = loc.frame.pointXYZ[2];
  
  std::vector<double> yAxis = loc.frame.computeYAxis();
  
  //use tf matrix to convert to quaternion
  tf::Matrix3x3 rotation(
    loc.frame.xAxis[0], loc.frame.xAxis[1], loc.frame.xAxis[2],
    yAxis[0], yAxis[1], yAxis[2],
    loc.frame.zAxis[0], loc.frame.zAxis[1], loc.frame.zAxis[2]);
  tf::Quaternion quat;
  rotation.getRotation(quat);
  tf::quaternionTFToMsg(quat, poseMsg.orientation);
  
  return poseMsg;
}
/**
  \brief Get a pose message adjusted for the BoxyShape coordinate frame
  \param loc The RecLoc to convert to a pose
  \param shape The shape of the object
  
  The coordinate system of an object with a BoxyShape is defined such that the origin is in the center of the bottom of the box. A ROS CollisionObject has its origin in the center of the box. This function resolves this problem by adjusting the Pose message coordinates of the spawned collision object.
*/
geometry_msgs::Pose getPoseMsg(RecLoc &loc, BoxyShape * shape)
{
  geometry_msgs::Pose poseMsg = getPoseMsg(loc);
  //+z axis points into box, so moving "up" by .5 * height puts the bottom at the origin
  poseMsg.position.x += loc.frame.zAxis[0] * shape->gethasBoxyShape_Height()/2;
  poseMsg.position.y += loc.frame.zAxis[1] * shape->gethasBoxyShape_Height()/2;
  poseMsg.position.z += loc.frame.zAxis[2] * shape->gethasBoxyShape_Height()/2;
  return poseMsg;
}
/**
  \brief Build a ROS CollisionObject message from \a loc and \a shape
  \param loc The RecLoc to use as the CollisionObject pose
  \param shape The BoxyShape to use as the CollisionObject shape
  \param id String to use as the CollisionObject id
  \return The publishable CollisionObject message
  
  This function can be used to generate a message to publish on the collision_objects topic. When the message is published once, with the arm navigation node running, the navigation node will take the collision object into account when it computes constraint-aware kinematics trajectories.
  
  The message returned by this function has an unstamped header.
*/
arm_navigation_msgs::CollisionObject getCollisionMsg(RecLoc &loc, BoxyShape * shape, std::string id)
{
  arm_navigation_msgs::CollisionObject object;
  object.operation.operation = arm_navigation_msgs::CollisionObjectOperation::ADD;
  
  object.shapes.push_back (getBoxShapeMsg (shape));
  object.poses.push_back(getPoseMsg(loc, shape));
  object.id = id;
  return object;
}
/**
  \brief Builds a ROS Marker object from \a loc and \a shape
  \param loc The RecLoc to use as the Marker pose
  \param shape the BoxyShape to use as the Marker shape
  \param markerID Integer to set as the Marker id
  \return The publishable Marker message
  
  This function generates a message that can be published on a Marker topic to visualize objects in rviz. When the message is published, in order for it to have an effect, rviz must already be running and must have a marker object subscribed to the correct topic.
  
  The message returned by this function has an unstamped header.
*/
visualization_msgs::Marker getMarkerMsg(RecLoc &loc, BoxyShape * shape, int markerID)
{
  visualization_msgs::Marker markerMsg;
  markerMsg.pose = getPoseMsg(loc, shape);
  markerMsg.lifetime = ros::Duration();
  markerMsg.action = visualization_msgs::Marker::ADD;
  
  markerMsg.type = visualization_msgs::Marker::CUBE;
  printf("x,y,z %f %f %f\n",shape->gethasBoxyShape_Length(), shape->gethasBoxyShape_Width(), shape->gethasBoxyShape_Height());
  markerMsg.scale.x = shape->gethasBoxyShape_Length();
  markerMsg.scale.y = shape->gethasBoxyShape_Width();
  markerMsg.scale.z = shape->gethasBoxyShape_Height();
  
  //color the marker red
  markerMsg.color.r = 1.0;
  markerMsg.color.g = 0.0;
  markerMsg.color.b = 0.0;
  markerMsg.color.a = 1.0;
  
  markerMsg.id = markerID;
  
  return markerMsg;
}
/**
  \brief Set the timestamp and frame_id of a ROS header message
  \param header the header to stamp
  \param globalFrame the string to set the frame_id to
*/
void stampHeader(std_msgs::Header &header, const std::string &globalFrame)
{
  header.stamp = ros::Time::now();
  header.frame_id = globalFrame;
}

int main(int argc, char** argv)
{
  ros::Publisher collisionPub;
  ros::Publisher markerPub;
  std::string globalFrame;
  
  std::vector<arm_navigation_msgs::CollisionObject> collisionMsgs;
  std::vector<visualization_msgs::Marker> markerMsgs;

  DAO * dao = new DAO("SolidObject");
  std::vector<std::string> attributes;
  
  //set up ROS publishers/parameters
	ros::init(argc, argv, "sqlToCollision");
	ros::NodeHandle nh;
	
	collisionPub = nh.advertise<arm_navigation_msgs::CollisionObject>("/collision_object", 10, true);
	markerPub = nh.advertise<visualization_msgs::Marker>("/collision_object/marker", 10, true);
	if(!nh.getParam("usarsim/globalFrame", globalFrame))
	{
	  ROS_WARN("Global frame parameter is not set. Using default \"odom\"");
	  globalFrame = "odom";
	}
	
	//get the names of every SolidObject in the database
	attributes.push_back("_NAME");
	std::map<std::string, std::vector<std::string> > objectsMap = dao->getAll(attributes, "SolidObject");
	
	RecurseLocation recurseLocation;
	
	//build CollisionObject and Marker message vectors for for each SolidObject with a BoxyShape
	for(unsigned int i = 0;i<objectsMap["_NAME"].size();i++)
	{
	  SolidObject * object = new SolidObject(objectsMap["_NAME"][i]);
	  object->get(objectsMap["_NAME"][i]);
	  std::string shapeName = getShapeName(object->getname());
	  if(isBoxyShape(shapeName))
	  {
	    BoxyShape * objectShape = new BoxyShape(shapeName);
	    objectShape->get(shapeName);
	    //get location
	    recurseLocation.clear();
	    recurseLocation.recurse(object);
	    recurseLocation.computeGlobalLoc();
	    RecLoc globalLoc = recurseLocation.getGlobalLoc();
	    
	    collisionMsgs.push_back(getCollisionMsg(globalLoc, objectShape, object->getname()));
	    markerMsgs.push_back(getMarkerMsg(globalLoc, objectShape, i));
	    
	    delete objectShape;
	  }
	  delete object;
	}
	
	delete dao;
	
	unsigned int currentCollisionSubCount = 0;
	unsigned int currentMarkerSubCount = 0;
	ROS_INFO("Collision objects generated. Leave this node running so it can publish objects to new subscribers as they connect.");
	ros::Rate rate(10); //keep loop at 10 hz
	//every time a new node subscribes, publish again
	while(ros::ok())
	{
	  if(collisionPub.getNumSubscribers() > currentCollisionSubCount)
	  {
	    for(unsigned int i = 0;i < collisionMsgs.size();i++)
	    {
	      stampHeader(collisionMsgs[i].header, globalFrame);
	      collisionPub.publish(collisionMsgs[i]);
	    }
	  }
	  if(markerPub.getNumSubscribers() > currentMarkerSubCount)
	  {
	    for(unsigned int i = 0;i < markerMsgs.size();i++)
	    {
	      stampHeader(markerMsgs[i].header, globalFrame);
	      markerPub.publish(markerMsgs[i]);
	    }
	  }
	  currentCollisionSubCount = collisionPub.getNumSubscribers();
	  currentMarkerSubCount = markerPub.getNumSubscribers();
	  rate.sleep();
	  ros::spinOnce();
	}
	
	return 0;
}
