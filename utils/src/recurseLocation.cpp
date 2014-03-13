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

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
 *****************************************************************************/

/*!
 *	\file		recurseLocation.cpp
 *	\brief 		Recursively search for an object's location
 *	\class		RecLoc
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 30, 2013
 *      \copyright      Georgia Tech Research Institute
 */

#include "recurseLocation.h"
#include <stdio.h> // printf

/*!
  @brief Clear out the vectors for this structure
*/
void Frame::clear()
{
  pose.clear();
}

/*!
  @brief Clear out the vectors for this structure
*/
void RecLoc::clear()
{
  frame.clear();
}

/*!
 @brief Constructor
 The constructor will clear out the global location.
@return None
 */
RecurseLocation::RecurseLocation()
{
  initGlobalLoc();
  sensorConnected = 0;
}

void RecurseLocation::sensorConnect(std::string hostName, ulapi_integer port)
{
  usarTruth.connect(hostName, port);
  sensorConnected = 1;
}

/*!
  @ manually add location to recursive list
  @param recLocToAdd The location to add
  @return None
*/
void RecurseLocation::addRecLoc(RecLoc *recLocToAdd)
{
  recLoc.push_back(*recLocToAdd);
  printf( "recurseLocation::addRecLoc: pushed to position %d\n", (int)recLoc.size() );
}

/*!
 @brief Clears the location vector and global location
 The recursive chain of global locations is cleared and the
 global location is set to (0,0,0) with front along the x-axis
 and up along the z-axis.
@return None
 */
void RecurseLocation::clear()
{
  recLoc.clear();
  initGlobalLoc();
}

/*!
 @brief Computes the global location
 This function goes through the recursive
 list of locations and computes the global
 location of the item.
@return 1 on success and 0 on failure
 */
int RecurseLocation::computeGlobalLoc()
{
  std::vector<RecLoc>tempLoc;
  PoseInfo tempPose, tempPose2, tempPose3;
  Point *mypoint;
  Vector *vectorXAxis, *vectorZAxis;

  mypoint = new Point("foo");
  vectorXAxis = new Vector("foo1");
  vectorZAxis = new Vector("foo2");

  // if nothing in recLoc, then nothing to do
  if( recLoc.size() <= 0 )
    return 0;

  //copy recLoc vector, preserving the order (local first, global last)
  /* note that object i is located w.r.t. object i+1; object i's
     point's reference object is object i+1
  */
  for( unsigned int i=0; i<recLoc.size()-1; i++)
    {
      printf( "recurseLocation::computeGlobalLoc:Checking values for %s and %s\n",
	      recLoc[i].frame.pose.getPointName().c_str(),
	      recLoc[i+1].frame.pose.getPointName().c_str());
      if( recLoc[i+1].sensorReturn.valid && recLoc[i].sensorReturn.valid )
	{
	  /* if both sensor returns are valid, then we have sensed locations
	     in world coordinates for both the object (at location i) and object's
	     relative object (at location i+1). Therefore, we can reset object i's 
	     offsets and coordinate frame to actual values by translating the object
	     and rotating it by the difference of the rotations. This may be done
	     by setting the rotation matrix and then taking the inverse
	     of the pose at i+1 multiplied by the location of i
	  */

	  /* test code */
	  /*
	  recLoc[i+1].sensorReturn.pose.setRollPitchYaw(0,0,6.003);
	  tempPose = recLoc[i+1].sensorReturn.pose.invert();
	  poseProduct( &(recLoc[i+1].sensorReturn.pose), &tempPose,
		       &(recLoc[i+1].sensorReturn.pose));
	  recLoc[i+i].sensorReturn.pose.printMe(1, "recurseLocation:: this should be 0 " );
	  exit(1);

	  /* end of test */
	  tempPose = recLoc[i+1].sensorReturn.pose.invert();
	  poseProduct( &(recLoc[i].sensorReturn.pose), 
		       &tempPose,
		       &(recLoc[i].sensorReturn.pose));
	  // need to set point and vector tables
	  recLoc[i].sensorReturn.pose.printMe(1, "recurseLocation::computeGlobalLoc:(i,i+1)Setting location of point ");
	  mypoint->get(recLoc[i].frame.pose.getPointName());
	  mypoint->sethasPoint_X(recLoc[i].sensorReturn.pose.getPointX());
	  mypoint->sethasPoint_Y(recLoc[i].sensorReturn.pose.getPointY());
	  mypoint->sethasPoint_Z(recLoc[i].sensorReturn.pose.getPointZ());
	  mypoint->set(recLoc[i].frame.pose.getPointName());

	  vectorXAxis->get(recLoc[i].frame.pose.getXAxisName());
	  vectorXAxis->sethasVector_I(recLoc[i].sensorReturn.pose.getXAxisI());
	  vectorXAxis->sethasVector_J(recLoc[i].sensorReturn.pose.getXAxisJ());
	  vectorXAxis->sethasVector_K(recLoc[i].sensorReturn.pose.getXAxisK());
	  vectorXAxis->set(recLoc[i].frame.pose.getXAxisName());

	  vectorZAxis->get(recLoc[i].frame.pose.getZAxisName());
	  vectorZAxis->sethasVector_I(recLoc[i].sensorReturn.pose.getZAxisI());
	  vectorZAxis->sethasVector_J(recLoc[i].sensorReturn.pose.getZAxisJ());
	  vectorZAxis->sethasVector_K(recLoc[i].sensorReturn.pose.getZAxisK());
	  vectorZAxis->set(recLoc[i].frame.pose.getZAxisName());
	}
      else if(recLoc[i].sensorReturn.valid )
	{
	  /* since i is valid and i+1 is not, we can assume that
	     to object at i+i is fixed to the world and can't move.
	     We can still reset the relationship between i and its
	     relative frame using the coordinate frame that is fixed 
	     to the world. Note that this only works if object i+1's 
	     coordinate frame is in global coordinates 
	     (i.e. the kitting workstation)
	  */
	  tempPose = recLoc[i+1].frame.pose.invert();
	  poseProduct( &(recLoc[i].sensorReturn.pose), 
		       &tempPose,
		       &(recLoc[i].sensorReturn.pose));
	  // need to set point and vector tables
	  recLoc[i].sensorReturn.pose.printMe(1, "recurseLocation::computeGlobalLoc:(i)Setting location of point ");
	  mypoint->get(recLoc[i].frame.pose.getPointName());
	  mypoint->sethasPoint_X(recLoc[i].sensorReturn.pose.getPointX());
	  mypoint->sethasPoint_Y(recLoc[i].sensorReturn.pose.getPointY());
	  mypoint->sethasPoint_Z(recLoc[i].sensorReturn.pose.getPointZ());
	  mypoint->set(recLoc[i].frame.pose.getPointName());

	  vectorXAxis->get(recLoc[i].frame.pose.getXAxisName());
	  vectorXAxis->sethasVector_I(recLoc[i].sensorReturn.pose.getXAxisI());
	  vectorXAxis->sethasVector_J(recLoc[i].sensorReturn.pose.getXAxisJ());
	  vectorXAxis->sethasVector_K(recLoc[i].sensorReturn.pose.getXAxisK());
	  vectorXAxis->set(recLoc[i].frame.pose.getXAxisName());

	  vectorZAxis->get(recLoc[i].frame.pose.getZAxisName());
	  vectorZAxis->sethasVector_I(recLoc[i].sensorReturn.pose.getZAxisI());
	  vectorZAxis->sethasVector_J(recLoc[i].sensorReturn.pose.getZAxisJ());
	  vectorZAxis->sethasVector_K(recLoc[i].sensorReturn.pose.getZAxisK());
	  vectorZAxis->set(recLoc[i].frame.pose.getZAxisName());
	}
      /*
      else if(recLoc[i+1].sensorReturn.valid )
	{
	  tempPose = recLoc[i+1].sensorReturn.pose.invert();
	  poseProduct( &(recLoc[i].frame.pose), 
		       &tempPose,
		       &(recLoc[i].frame.pose));
	  // need to set point and vector tables
	  recLoc[i].frame.pose.printMe(1, "recurseLocation::computeGlobalLoc:(i+1)Setting location of point ");
	  mypoint->get(recLoc[i].frame.pose.getPointName());
	  mypoint->sethasPoint_X(recLoc[i].frame.pose.getPointX());
	  mypoint->sethasPoint_Y(recLoc[i].frame.pose.getPointY());
	  mypoint->sethasPoint_Z(recLoc[i].frame.pose.getPointZ());
	  mypoint->set(recLoc[i].frame.pose.getPointName());

	  vectorXAxis->get(recLoc[i].frame.pose.getXAxisName());
	  vectorXAxis->sethasVector_I(recLoc[i].frame.pose.getXAxisI());
	  vectorXAxis->sethasVector_J(recLoc[i].frame.pose.getXAxisJ());
	  vectorXAxis->sethasVector_K(recLoc[i].frame.pose.getXAxisK());
	  vectorXAxis->set(recLoc[i].frame.pose.getXAxisName());

	  vectorZAxis->get(recLoc[i].frame.pose.getZAxisName());
	  vectorZAxis->sethasVector_I(recLoc[i].frame.pose.getZAxisI());
	  vectorZAxis->sethasVector_J(recLoc[i].frame.pose.getZAxisJ());
	  vectorZAxis->sethasVector_K(recLoc[i].frame.pose.getZAxisK());
	  vectorZAxis->set(recLoc[i].frame.pose.getZAxisName());
	}
      */
      tempLoc.push_back(recLoc[i]);
    }
  delete mypoint;
  delete vectorXAxis;
  delete vectorZAxis;
  
  tempLoc.push_back(recLoc[recLoc.size()-1]);

  globalLoc = tempLoc.back();
  tempLoc.pop_back();
  while( !tempLoc.empty() )
    {
      poseProduct( &(globalLoc.frame.pose), &(globalLoc.frame.pose), &(tempLoc.back().frame.pose) );
      tempLoc.pop_back();
    }
  return 1;
}

/*!
 @brief Access to global location
 @return global location
 */
RecLoc RecurseLocation::getGlobalLoc()
{
  return globalLoc;
}

/*!
 @brief Initialized the global location.
 The global location is set to
 (0,0,0) with front along the x-axis
 and up along the z-axis.
@return None
 */
void RecurseLocation::initGlobalLoc()
{
  globalLoc.solidObjectName = "kitting_workstation_1";

  globalLoc.frame.pose.setPoint(0, 0, 0);
  globalLoc.frame.pose.setXAxis(1, 0, 0);
  globalLoc.frame.pose.setZAxis(0, 0, 1);
}

/*!
 @brief Build the recursive chain of locations
 Builds a chain of locations ending at "kitting_workstation_1"
\todo Fix the way that the chain ends in kitting_workstation_1
 @param solidObject Object that you are trying to find the position of
 @return 1 still working, 0 done
 */
int RecurseLocation::recurse(SolidObject *solidObject)
{
  PhysicalLocation *physicalLocation;
  PoseLocation *poseLocation = new PoseLocation("foo");
  RecLoc myrecLoc;
  Point *mypoint;
  Vector *vectorXAxis, *vectorZAxis;
  double doubleValue;
 
  myrecLoc.solidObjectName = solidObject->getname();
  if( solidObject->getname() == "kitting_workstation_1" )
    {
      myrecLoc.solidObjectType = "KittingWorkstation";
      myrecLoc.sensorReturn.valid = 0;
      myrecLoc.frame.pose.setPointName("kitting_workstation_1_point");
      myrecLoc.frame.pose.setPoint(0, 0, 0);
      myrecLoc.frame.pose.setXAxisName("kitting_workstation_1_x_axis");
      myrecLoc.frame.pose.setXAxis(1,0,0);
      myrecLoc.frame.pose.setZAxisName("kitting_workstation_1_z_axis");
      myrecLoc.frame.pose.setZAxis(0,0,1);
      recLoc.push_back(myrecLoc);
      return 0;
    }
  solidObject->get(solidObject->getname());
  myrecLoc.solidObjectType = GenericModel::getModel(solidObject);
  double roll, pitch, yaw;
  if( sensorConnected && myrecLoc.solidObjectType != "Unknown_model" )
    {
      myrecLoc.sensorReturn = usarTruth.getTruth(myrecLoc.solidObjectType,
						 myrecLoc.solidObjectName);
      if( myrecLoc.sensorReturn.valid )
	{
	  myrecLoc.sensorReturn.pose.getRollPitchYaw(&roll, &pitch, &yaw);
	  printf( "recurseLocation::recurse: %s <x y z> = <%f %f %f> <r p y> = <%f %f %f>\n",
		  myrecLoc.sensorReturn.name.c_str(),
		  myrecLoc.sensorReturn.pose.getPointX(),
		  myrecLoc.sensorReturn.pose.getPointY(),
		  myrecLoc.sensorReturn.pose.getPointZ(),
		  roll, pitch, yaw );
	}
      else
	printf( "recurseLocation::recurse: invalid return from USARSim\n" );
    }
  else
    myrecLoc.sensorReturn.valid = 0;
  /*
  printf( "Model chain: object: %s of type: %s\n", 
	  myrecLoc.solidObjectName.c_str(),
	  myrecLoc.solidObjectType.c_str());
  */

  physicalLocation = solidObject->gethasSolidObject_PrimaryLocation();
  physicalLocation->get(physicalLocation->getname());
  myrecLoc.primaryLocationName = physicalLocation->getname();

  poseLocation->get(physicalLocation->getname());

  /*
  printf( "object: %s physical location: %s poseLocation: %s ref: %s\n", 
	  solidObject->getname().c_str(),
	  physicalLocation->getname().c_str(),
	  poseLocation->getname().c_str(),
	  (physicalLocation->gethasPhysicalLocation_RefObject())->getname().c_str());
  */
  mypoint = poseLocation->gethasPoseLocation_Point();
  mypoint->get(mypoint->getname());
  myrecLoc.frame.pose.setPointName(mypoint->getname());
  myrecLoc.frame.pose.setPoint(mypoint->gethasPoint_X(),
			  mypoint->gethasPoint_Y(),
			  mypoint->gethasPoint_Z());

  vectorXAxis = poseLocation->gethasPoseLocation_XAxis();
  vectorXAxis->get(vectorXAxis->getname());
  myrecLoc.frame.pose.setXAxisName(vectorXAxis->getname());
  myrecLoc.frame.pose.setXAxis(vectorXAxis->gethasVector_I(),
			  vectorXAxis->gethasVector_J(),
			  vectorXAxis->gethasVector_K());

  vectorZAxis = poseLocation->gethasPoseLocation_ZAxis();
  vectorZAxis->get(vectorZAxis->getname());
  myrecLoc.frame.pose.setZAxisName(vectorZAxis->getname());
  myrecLoc.frame.pose.setZAxis(vectorZAxis->gethasVector_I(),
			  vectorZAxis->gethasVector_J(),
			  vectorZAxis->gethasVector_K());

  recLoc.push_back(myrecLoc);
  printf( "recurseLocation::recurse: pushed to position %d\n", (int)recLoc.size());
  if (recurse( physicalLocation->gethasPhysicalLocation_RefObject()) == 0)
    {
            delete poseLocation;
	    //	    printf( "End of chain\n" );
	    return 0;
    }
  return 1;
}

/*!
 @brief Clean up allocated memory
 Unable to currently do this. Core
 dumps if we try to delete.
 @return None
 */
void RecurseLocation::cleanup()
{
}

/*!
 @brief Print information about the recurse location
 Based on the verbosity, either the entire chain
 of recursive locations will be printed or only 
 the global location.
 @param verbosity 0-print minimal information, 1-print a lot.
 @return None
 */
void RecurseLocation::printMe(int verbosity, std::string prefix)
{
  std::string newPrefix;

  if( verbosity > 0 )
    {
      for(unsigned int i=0; i<recLoc.size(); i++ )
	{
	  printf( "solidObject: %s\n\tprime: %s\n",
		  recLoc[i].solidObjectName.c_str(),
		  recLoc[i].primaryLocationName.c_str());
	  newPrefix = prefix + "\t";
	  recLoc[i].frame.pose.printMe(verbosity, newPrefix);

	  printf( "\tsensorReturn %s:%s valid: %d\n\t\ttime: %lf\n",
		  recLoc[i].sensorReturn.objectClass.c_str(),
		  recLoc[i].sensorReturn.name.c_str(),
		  recLoc[i].sensorReturn.valid,
		  recLoc[i].sensorReturn.time);
	  newPrefix = prefix + "\t\t";
	  recLoc[i].sensorReturn.pose.printMe(verbosity, newPrefix );
	}
    }
  printf( "GlobalLoc:\n");
  newPrefix = prefix + "\t";
  globalLoc.frame.pose.printMe(verbosity, newPrefix);
}

/* RecurseLocation::poseProduct
 @brief This routine is from Tom Kramer's kittingViewer.cc file that is part of the kittingViewer program.
 This computes and sets the Point, XAxis, and ZAxis for poseToSet as
 the product of pose1 and pose2, treating all the poses as homogeneous
 matrices, and assuming the XAxis and ZAxis of pose1 and pose2 are
 normalized. A set of Y axis values are calculated for pose1 and pose2
 as an intermediate step, but those values are not saved.
 @param poseToSet Pose is returned here
 @param pose1 First pose of product.
 @param pose2 Second pose of product.
 @return None
*/

void RecurseLocation::poseProduct(
 PoseInfo * poseToSet,
 PoseInfo * pose1,
 PoseInfo * pose2)
{
  std::vector<double>yAxis;
  double x1i = pose1->getXAxisI();
  double x1j = pose1->getXAxisJ();
  double x1k = pose1->getXAxisK();
  double y1i;
  double y1j;
  double y1k;
  double z1i = pose1->getZAxisI();
  double z1j = pose1->getZAxisJ();
  double z1k = pose1->getZAxisK();

  double x2i = pose2->getXAxisI();
  double x2j = pose2->getXAxisJ();
  double x2k = pose2->getXAxisK();
  //  double y2i;
  //  double y2j;
  //  double y2k;
  double z2i = pose2->getZAxisI();
  double z2j = pose2->getZAxisJ();
  double z2k = pose2->getZAxisK();

  double o1x = pose1->getPointX();
  double o1y = pose1->getPointY();
  double o1z = pose1->getPointZ();

  double o2x = pose2->getPointX();
  double o2y = pose2->getPointY();
  double o2z = pose2->getPointZ();

  pose1->printMe(1, "recurseLocation::poseProduct: computing product arg 1 ");
  pose2->printMe(1, "recurseLocation::poseProduct: computing product arg 2 ");
  yAxis = pose1->computeYAxis();
  y1i = yAxis[0];
  y1j = yAxis[1];
  y1k = yAxis[2];
  yAxis.clear();

  //  yAxis = pose2->computeYAxis();
  //  y2i = yAxis[0];
  //  y2j = yAxis[1];
  //  y2k = yAxis[2];

  poseToSet->setXAxis( ((x1i * x2i) + (y1i * x2j) + (z1i * x2k)),
		       ((x1j * x2i) + (y1j * x2j) + (z1j * x2k)),
		       ((x1k * x2i) + (y1k * x2j) + (z1k * x2k)) );
  poseToSet->setZAxis( ((x1i * z2i) + (y1i * z2j) + (z1i * z2k)),
		       ((x1j * z2i) + (y1j * z2j) + (z1j * z2k)),
		       ((x1k * z2i) + (y1k * z2j) + (z1k * z2k)) );
  poseToSet->setPoint( ((x1i * o2x) + (y1i * o2y) + (z1i * o2z) + o1x), 
		       ((x1j * o2x) + (y1j * o2y) + (z1j * o2z) + o1y),
		       ((x1k * o2x) + (y1k * o2y) + (z1k * o2z) + o1z) );
}
