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
#include <math.h>
/*!
  @brief Invert the frame transform
  @return The inverted frame
 */
Frame Frame::invert()
{
  Frame inverse;
  std::vector<double> yAxis;
  double pointx, pointy, pointz;
  
  yAxis = this->computeYAxis();
  inverse.setXAxis(this->xAxis[0], yAxis[0], this->zAxis[0]);
  inverse.setZAxis(this->xAxis[2], yAxis[2], this->zAxis[2]);
  
  pointx = -(this->xAxis[0]*this->pointXYZ[0] + 
	     yAxis[0]*this->pointXYZ[1] + 
	     this->zAxis[0]*this->pointXYZ[2]);
  pointy = -(this->xAxis[1]*this->pointXYZ[0] + 
	     yAxis[1]*this->pointXYZ[1] + 
	     this->zAxis[1]*this->pointXYZ[2]);
  pointz = -(this->xAxis[2]*this->pointXYZ[0] + 
	     yAxis[2]*this->pointXYZ[1] + 
	     this->zAxis[2]*this->pointXYZ[2]);
  inverse.setPoint(pointx, pointy, pointz);
  return inverse;
}

void Frame::setPoint( double x, double y, double z )
{
  pointXYZ.clear();
  pointXYZ.push_back(x);
  pointXYZ.push_back(y);
  pointXYZ.push_back(z);
}

void Frame::setPointName( std::string pointNameIn)
{
  pointName = pointNameIn;
}

/*!
  @brief Compute yAxis from x & z axis locations
  @param xAxis Vector that contains the xAxis values
  @param zAxis Vector that contains the zAxis values
  @return vector that contains y axis
*/
std::vector<double> Frame::computeYAxis()
{
  std::vector<double>yAxis;

  double xi = xAxis[0];
  double xj = xAxis[1];
  double xk = xAxis[2];
  double zi = zAxis[0];
  double zj = zAxis[1];
  double zk = zAxis[2];

  yAxis.push_back((zj * xk) - (xj * zk));
  yAxis.push_back((zk * xi) - (xk * zi));
  yAxis.push_back((zi * xj) - (xi * zj));
  return yAxis;
}

void Frame::setXAxis( double x, double y, double z )
{
  xAxis.clear();
  xAxis.push_back(x);
  xAxis.push_back(y);
  xAxis.push_back(z);
}

void Frame::setXAxisName( std::string xAxisNameIn)
{
  xAxisName = xAxisNameIn;
}

void Frame::setZAxis( double x, double y, double z )
{
  zAxis.clear();
  zAxis.push_back(x);
  zAxis.push_back(y);
  zAxis.push_back(z);
}

void Frame::setZAxisName( std::string zAxisNameIn)
{
  zAxisName = zAxisNameIn;
}

/*!
  @brief Clear out the vectors for this structure
*/
void Frame::clear()
{
  pointXYZ.clear();
  xAxis.clear();
  zAxis.clear();
}

/*!
  @brief Clear out the vectors for this structure
*/
void RecLoc::clear()
{
  frame.clear();
}

/*!
 @brief Retreive the roll, pitch, and yaw from the RecLoc.
 This function utilizes the forward and up vectors to compute
 the associated roll, pitch, and yaw.
@param roll Storage location for the computed roll
@param pitch Storage location for the computed roll
@param yaw Storage location for the computed roll
@return None
 */
void RecLoc::getRollPitchYaw(double *roll, double *pitch, double *yaw)
{
  double cosPitch, cosYaw, sinYaw, cosRoll, sinRoll;

  *pitch = asin(-frame.xAxis[2]);
  cosPitch = sqrt(1. - frame.xAxis[2]*frame.xAxis[2]);
    
  //Check if we are straight up or down
  if (cosPitch == 0 || fabs(frame.xAxis[2]) >= 1)
    {
      if (*pitch > 0)
        {
	  *yaw = 0;
	  *roll = atan2(-frame.zAxis[1], -frame.zAxis[0]) + M_PI;
        }
      else
        {
	  yaw = 0;
	  *roll = -atan2(frame.zAxis[1], frame.zAxis[0]) + M_PI;    
        }
    }
    else
      {
        
        cosYaw = frame.xAxis[0]/cosPitch;
        sinYaw = frame.xAxis[1]/cosPitch;
        *yaw = atan2(sinYaw, cosYaw);
        
        cosRoll = frame.zAxis[2]/cosPitch;
        if (fabs(cosYaw) < fabs(sinYaw))
	  {
            sinRoll = -(frame.zAxis[0] + 
			frame.xAxis[2]*cosRoll*cosYaw)/sinYaw;
	  }
        else
	  {
            sinRoll = (frame.zAxis[1] + 
		       frame.xAxis[2]*cosRoll*sinYaw)/cosYaw;
	  }
        *roll = atan2(sinRoll, cosRoll);
      }
    
    
    //Keep all angles in [0, 2pi]
    if (*yaw < 0)
      *yaw += 2*M_PI;
    else if (*yaw >= 2*M_PI)
      *yaw -= 2*M_PI;
    
    if (*pitch < 0)
      *pitch += 2*M_PI;
    else if (*pitch >= 2*M_PI)
      *pitch -= 2*M_PI;
        
    if (*roll < 0)
      *roll += 2*M_PI;
    else if (*roll >= 2*M_PI)
      *roll -= 2*M_PI;
    }

void RecLoc::setRollPitchYaw(double roll, double pitch, double yaw)
{
	double cosRoll, sinRoll, cosPitch, sinPitch, cosYaw, sinYaw;
	
	cosRoll = cos(roll);
	sinRoll = sin(roll);
	cosPitch = cos(pitch);
	sinPitch = sin(pitch);
	cosYaw = cos(yaw);
	sinYaw = sin(yaw);
	
	double xi, xj, xk, zi, zj, zk;
	
	xi = cosYaw * cosPitch;
	xj = sinYaw * cosPitch;
	xk = -sinPitch;
	
	zi = cosYaw * sinPitch * cosRoll + sinYaw * sinRoll;
	zj = sinYaw * sinPitch * cosRoll - cosYaw * sinRoll;
	zk = cosPitch * cosRoll;
	
	frame.setXAxis(xi, xj, xk);
	frame.setZAxis(zi, zj, zk);
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

void RecurseLocation::sensorConnect(std::string hostName)
{
  sensorHost = hostName;
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

  // if nothing in recLoc, then nothing to do
  if( recLoc.size() <= 0 )
    return 0;

  //copy recLoc vector, preserving the order (local first, global last)
  for( unsigned int i=0; i<recLoc.size(); i++)
    tempLoc.push_back(recLoc[i]);

  globalLoc = tempLoc.back();
  tempLoc.pop_back();
  while( !tempLoc.empty() )
    {
      poseProduct( &globalLoc, &globalLoc, &tempLoc.back() );
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

  globalLoc.frame.setPoint(0, 0, 0);
  globalLoc.frame.setXAxis(1, 0, 0);
  globalLoc.frame.setZAxis(0, 0, 1);
}

/*!
 @brief Build the recursive chain of locations
 Builds a chain of locations ending at "kitting_workstation_1"
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
      //      delete poseLocation;
      myrecLoc.solidObjectType = "KittingWorkstation";
      myrecLoc.sensorReturn.valid = 0;
      printf( "End of chain\n" );      
      return 0;
    }
  solidObject->get(solidObject->getname());
  myrecLoc.solidObjectType = GenericModel::getModel(solidObject);
  if( sensorConnected )
    myrecLoc.sensorReturn = usarTruth.getTruth(myrecLoc.solidObjectType,
					       myrecLoc.solidObjectName);
  else
    myrecLoc.sensorReturn.valid = 0;
  printf( "Model chain: object: %s of type: %s\n", 
	  myrecLoc.solidObjectName.c_str(),
	  myrecLoc.solidObjectType.c_str());

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
  myrecLoc.frame.setPointName(mypoint->getname());
  myrecLoc.frame.setPoint(mypoint->gethasPoint_X(),
			  mypoint->gethasPoint_Y(),
			  mypoint->gethasPoint_Z());

  //    printf( "past issue\n" );
  vectorXAxis = poseLocation->gethasPoseLocation_XAxis();
  vectorXAxis->get(vectorXAxis->getname());
  myrecLoc.frame.setXAxisName(vectorXAxis->getname());
  myrecLoc.frame.setXAxis(vectorXAxis->gethasVector_I(),
			  vectorXAxis->gethasVector_J(),
			  vectorXAxis->gethasVector_K());

  vectorZAxis = poseLocation->gethasPoseLocation_ZAxis();
  vectorZAxis->get(vectorZAxis->getname());
  myrecLoc.frame.setZAxisName(vectorZAxis->getname());
  myrecLoc.frame.setZAxis(vectorZAxis->gethasVector_I(),
			  vectorZAxis->gethasVector_J(),
			  vectorZAxis->gethasVector_K());

  recLoc.push_back(myrecLoc);
  if (recurse( physicalLocation->gethasPhysicalLocation_RefObject()) == 0 )
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
void RecurseLocation::printMe(int verbosity)
{
  if( verbosity > 0 )
    {
      for(unsigned int i=0; i<recLoc.size(); i++ )
	{
	  printf( "solidObject: %s\n\tprim: %s\n\tPoint:%s <%f %f %f>\n\txAxis:%s <%f %f %f>\n\tzAxis:%s <%f %f %f>\n",
		  recLoc[i].solidObjectName.c_str(),
		  recLoc[i].primaryLocationName.c_str(),
		  recLoc[i].frame.pointName.c_str(),
		  recLoc[i].frame.pointXYZ[0],
		  recLoc[i].frame.pointXYZ[1],
		  recLoc[i].frame.pointXYZ[2],
		  recLoc[i].frame.xAxisName.c_str(),
		  recLoc[i].frame.xAxis[0],
		  recLoc[i].frame.xAxis[1],
		  recLoc[i].frame.xAxis[2],
		  recLoc[i].frame.zAxisName.c_str(),
		  recLoc[i].frame.zAxis[0],
		  recLoc[i].frame.zAxis[1],
		  recLoc[i].frame.zAxis[2] );
	}
    }
  printf( "\tGlobalLoc:\n\t\t <%f %f %f>\n\t\t <%f %f %f>\n\t\t <%f %f %f>\n",
	  globalLoc.frame.pointXYZ[0],
	  globalLoc.frame.pointXYZ[1],
	  globalLoc.frame.pointXYZ[2],
	  globalLoc.frame.xAxis[0],
	  globalLoc.frame.xAxis[1],
	  globalLoc.frame.xAxis[2],
	  globalLoc.frame.zAxis[0],
	  globalLoc.frame.zAxis[1],
	  globalLoc.frame.zAxis[2] );
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
 RecLoc * poseToSet,
 RecLoc * pose1,
 RecLoc * pose2)
{
  std::vector<double>yAxis;
  double x1i = pose1->frame.xAxis[0];
  double x1j = pose1->frame.xAxis[1];
  double x1k = pose1->frame.xAxis[2];
  double y1i;
  double y1j;
  double y1k;
  double z1i = pose1->frame.zAxis[0];
  double z1j = pose1->frame.zAxis[1];
  double z1k = pose1->frame.zAxis[2];

  double x2i = pose2->frame.xAxis[0];
  double x2j = pose2->frame.xAxis[1];
  double x2k = pose2->frame.xAxis[2];
  //  double y2i;
  //  double y2j;
  //  double y2k;
  double z2i = pose2->frame.zAxis[0];
  double z2j = pose2->frame.zAxis[1];
  double z2k = pose2->frame.zAxis[2];

  double o1x = pose1->frame.pointXYZ[0];
  double o1y = pose1->frame.pointXYZ[1];
  double o1z = pose1->frame.pointXYZ[2];

  double o2x = pose2->frame.pointXYZ[0];
  double o2y = pose2->frame.pointXYZ[1];
  double o2z = pose2->frame.pointXYZ[2];
  
  yAxis = pose1->frame.computeYAxis();
  y1i = yAxis[0];
  y1j = yAxis[1];
  y1k = yAxis[2];
  yAxis.clear();

  //  yAxis = pose2->FRAME.computeYAxis();
  //  y2i = yAxis[0];
  //  y2j = yAxis[1];
  //  y2k = yAxis[2];

  poseToSet->frame.xAxis[0] = ((x1i * x2i) + (y1i * x2j) + (z1i * x2k));
  poseToSet->frame.xAxis[1] = ((x1j * x2i) + (y1j * x2j) + (z1j * x2k));
  poseToSet->frame.xAxis[2] = ((x1k * x2i) + (y1k * x2j) + (z1k * x2k));
  poseToSet->frame.zAxis[0] = ((x1i * z2i) + (y1i * z2j) + (z1i * z2k));
  poseToSet->frame.zAxis[1] = ((x1j * z2i) + (y1j * z2j) + (z1j * z2k));
  poseToSet->frame.zAxis[2] = ((x1k * z2i) + (y1k * z2j) + (z1k * z2k));
  poseToSet->frame.pointXYZ[0] = ((x1i * o2x) + (y1i * o2y) + (z1i * o2z) + o1x);
  poseToSet->frame.pointXYZ[1] = ((x1j * o2x) + (y1j * o2y) + (z1j * o2z) + o1y);
  poseToSet->frame.pointXYZ[2] = ((x1k * o2x) + (y1k * o2y) + (z1k * o2z) + o1z);
}
