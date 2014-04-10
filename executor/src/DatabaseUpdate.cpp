/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------

 *****************************************************************************/
/*!
 *	\file		DatabaseUpdate.cpp
 *	\brief 		Functions to update the mysql database
 *	\class		DatabaseUpdate
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 30, 2013
 *      \copyright      Georgia Tech Research Institute
 */
#include "DatabaseUpdate.hh"

/*
  set the solidObject's hasEndEffector_HeldObject
 */
void DatabaseUpdate::graspByRobot( std::string robotName, std::string solidObjectName, Frame referenceFrame )
{
  Robot* robot = new Robot(robotName);
  SolidObject* solidObject = new SolidObject(solidObjectName);
  EndEffector* endEffector;
  PhysicalLocation* physicalLocation;
  PoseLocation *poseLocation = new PoseLocation("foo");
  Point *mypoint;
  Vector *vectorXAxis, *vectorZAxis;

  // get the robot and solid object
  robot->get(robotName);
  solidObject->get(solidObjectName);

  // get gripper being used by robot
  endEffector = robot->gethadByEndEffector_Robot();
  endEffector->get(endEffector->getname());

  // delete any item that is currently being held
  endEffector->sethadByHeldObject_EndEffector(NULL);
  endEffector->set(endEffector->getname()); // write to database

  // set held object
  endEffector->sethadByHeldObject_EndEffector(solidObject);
  std::cout << "Effector " << endEffector->getname() << " holding " <<
    solidObject->getname() << std::endl;

  // get physical location and set new reference object and values
  physicalLocation = solidObject->gethasSolidObject_PrimaryLocation();
  physicalLocation->get(physicalLocation->getname());
  physicalLocation->sethasPhysicalLocation_RefObject(endEffector);

  // set reference point values
  poseLocation->get(physicalLocation->getname());
  mypoint = poseLocation->gethasPoseLocation_Point();
  mypoint->get(mypoint->getname());
  mypoint->sethasPoint_X(referenceFrame.pose.getPointX());
  mypoint->sethasPoint_Y(referenceFrame.pose.getPointY());
  mypoint->sethasPoint_Z(referenceFrame.pose.getPointZ());

  // set xAxis values
  vectorXAxis = poseLocation->gethasPoseLocation_XAxis();
  vectorXAxis->get(vectorXAxis->getname());
  vectorXAxis->sethasVector_I(referenceFrame.pose.getXAxisI());
  vectorXAxis->sethasVector_J(referenceFrame.pose.getXAxisJ());
  vectorXAxis->sethasVector_K(referenceFrame.pose.getXAxisK());

  // set zAxis values
  vectorZAxis = poseLocation->gethasPoseLocation_ZAxis();
  vectorZAxis->get(vectorZAxis->getname());
  vectorZAxis->sethasVector_I(referenceFrame.pose.getZAxisI());
  vectorZAxis->sethasVector_J(referenceFrame.pose.getZAxisJ());
  vectorZAxis->sethasVector_K(referenceFrame.pose.getZAxisK());


  // write objects back to database
  endEffector->set(endEffector->getname());
  physicalLocation->set(physicalLocation->getname());
  mypoint->set(mypoint->getname());
  vectorXAxis->set(vectorXAxis->getname());
  vectorZAxis->set(vectorZAxis->getname());

  //   delete robot; delete causes dump?
  delete solidObject;
  delete poseLocation;
}

bool DatabaseUpdate::matchSlot(Slot *slot, std::string kitName, std::string skuName)
{
  Kit *kit;
  PartRefAndPose* partRefAndPose;
  StockKeepingUnit* sku;
  Part *part;
  bool retValue;

  slot->get(slot->getname());

  // check for proper name
  kit = slot->gethadBySlot_Kit();
  if( kit->getname() != kitName )
    return false;

  // check for sku
  partRefAndPose = slot->gethasSlot_PartRefAndPose();
  partRefAndPose->get(partRefAndPose->getname());
  sku = partRefAndPose->gethasPartRefAndPose_Sku();  
  if( sku->getname() != skuName )
    return false;

  // check for occupied
  part = slot->gethasSlot_Part();
  if( part == NULL )
    retValue = true;
  else
    retValue = false;

  return retValue;
}

void DatabaseUpdate::releaseByRobot( std::string robotName, std::string solidObjectName, std::string slotName )
{
  Robot* robot = new Robot(robotName);
  Slot* slot = new Slot(slotName);
  SolidObject* solidObject = new SolidObject(solidObjectName);
  SolidObject* kit;
  EndEffector* endEffector;
  PartRefAndPose* partRefAndPose;
  PhysicalLocation* physicalLocation;
  PoseLocation *poseLocation = new PoseLocation("foo");
  Point *myPoint, *mySetPoint;
  Vector *vector, *vectorSet;

  std::cout << "Robot: " << robotName << " part: " << solidObjectName << " slot: " << slotName << std::endl;
  // get the robot, slot, kit, and solid object
  robot->get(robotName);
  slot->get(slotName);
  solidObject->get(solidObjectName);
  kit = slot->gethadBySlot_Kit();  
  kit->get(kit->getname());

  // clear what is being held
  endEffector = robot->gethadByEndEffector_Robot();
  endEffector->get(endEffector->getname());
  endEffector->sethadByHeldObject_EndEffector(NULL);
  endEffector->set(endEffector->getname());

  // get partRefAndPose from slot and set new reference object and 
  // set values in physicalLocation of the solidobject
  partRefAndPose = slot->gethasSlot_PartRefAndPose();
  partRefAndPose->get(partRefAndPose->getname());

  physicalLocation = solidObject->gethasSolidObject_PrimaryLocation();
  physicalLocation->get(physicalLocation->getname());
  physicalLocation->sethasPhysicalLocation_RefObject(kit);
  physicalLocation->set(physicalLocation->getname());
  std::cout << "setting " << solidObject->getname() <<  " ref object to " <<
    kit->getname() << std::endl;

  // set reference point values
  myPoint = partRefAndPose->gethasPartRefAndPose_Point();
  myPoint->get(myPoint->getname());
  poseLocation->get(physicalLocation->getname());
  mySetPoint = poseLocation->gethasPoseLocation_Point();
  mySetPoint->get(mySetPoint->getname());
  mySetPoint->sethasPoint_X(myPoint->gethasPoint_X());
  mySetPoint->sethasPoint_Y(myPoint->gethasPoint_Y());
  mySetPoint->sethasPoint_Z(myPoint->gethasPoint_Z());
  mySetPoint->set(mySetPoint->getname());
  std::cout << "setting point " << mySetPoint->getname() << " to " <<
    mySetPoint->gethasPoint_X() << " " <<
    mySetPoint->gethasPoint_Y() << " " <<
    mySetPoint->gethasPoint_Z() << std::endl;
  mySetPoint->get(mySetPoint->getname());
  std::cout << "actually set point " << mySetPoint->getname() << " to " <<
    mySetPoint->gethasPoint_X() << " " <<
    mySetPoint->gethasPoint_Y() << " " <<
    mySetPoint->gethasPoint_Z() << std::endl;

  // set xAxis values
  vector = partRefAndPose->gethasPartRefAndPose_XAxis();
  vector->get(vector->getname());
  vectorSet = poseLocation->gethasPoseLocation_XAxis();
  vectorSet->get(vectorSet->getname());
  vectorSet->sethasVector_I(vector->gethasVector_I());
  vectorSet->sethasVector_J(vector->gethasVector_J());
  vectorSet->sethasVector_K(vector->gethasVector_K());
  vectorSet->set(vectorSet->getname());
  std::cout << "setting xAxis " << vectorSet->getname() << " to " <<
    vectorSet->gethasVector_I() << " " <<
    vectorSet->gethasVector_J() << " " <<
    vectorSet->gethasVector_K() << std::endl;

  // set zAxis values
  vector = partRefAndPose->gethasPartRefAndPose_ZAxis();
  vector->get(vector->getname());
  vectorSet = poseLocation->gethasPoseLocation_ZAxis();
  vectorSet->get(vectorSet->getname());
  vectorSet->sethasVector_I(vector->gethasVector_I());
  vectorSet->sethasVector_J(vector->gethasVector_J());
  vectorSet->sethasVector_K(vector->gethasVector_K());
  vectorSet->set(vectorSet->getname());
  std::cout << "setting xAxis " << vectorSet->getname() << " to " <<
    vectorSet->gethasVector_I() << " " <<
    vectorSet->gethasVector_J() << " " <<
    vectorSet->gethasVector_K() << std::endl;

  delete robot;
  delete solidObject;
  delete poseLocation;
  //   delete kit; causes dump?
}
