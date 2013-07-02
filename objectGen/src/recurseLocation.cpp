/*****************************************************************************
 DISCLAIMER:
 This software was produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  Recipients of this software
 assume all responsibility associated with its operation, modification,
 maintenance, and subsequent redistribution.

 See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "recurseLocation.h"
#include <stdio.h> // printf
#include <math.h>
/*!
  @brief Clear out the vectors for this structure
*/
void RecLoc::clear()
{
  pointXYZ.clear();
  xAxis.clear();
  zAxis.clear();
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

  *pitch = asin(-xAxis[2]);
  cosPitch = sqrt(1. - xAxis[2]*xAxis[2]);
    
  //Check if we are straight up or down
  if (cosPitch == 0 || fabs(xAxis[2]) >= 1)
    {
      if (*pitch > 0)
        {
	  *yaw = 0;
	  *roll = atan2(-zAxis[1], -zAxis[0]) + M_PI;
        }
      else
        {
	  yaw = 0;
	  *roll = -atan2(zAxis[1], zAxis[0]) + M_PI;    
        }
    }
    else
      {
        
        cosYaw = xAxis[0]/cosPitch;
        sinYaw = xAxis[1]/cosPitch;
        *yaw = atan2(sinYaw, cosYaw);
        
        cosRoll = zAxis[2]/cosPitch;
        if (fabs(cosYaw) < fabs(sinYaw))
	  {
            sinRoll = -(zAxis[0] + 
			xAxis[2]*cosRoll*cosYaw)/sinYaw;
	  }
        else
	  {
            sinRoll = (zAxis[1] + 
		       xAxis[2]*cosRoll*sinYaw)/cosYaw;
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

/*!
 @brief Constructor
 The constructor will clear out the global location.
@return None
 */
RecurseLocation::RecurseLocation()
{
  initGlobalLoc();
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

  // reorder vector to make access more efficient and to
  // preserve the original vector
  for( int i=recLoc.size()-1; i>=0; i-- )
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

  globalLoc.pointXYZ.clear();
  globalLoc.pointXYZ.push_back(0.0);
  globalLoc.pointXYZ.push_back(0.0);
  globalLoc.pointXYZ.push_back(0.0);

  globalLoc.xAxis.clear();
  globalLoc.xAxis.push_back(1);
  globalLoc.xAxis.push_back(0);
  globalLoc.xAxis.push_back(0);

  globalLoc.zAxis.clear();
  globalLoc.zAxis.push_back(0);
  globalLoc.zAxis.push_back(0);
  globalLoc.zAxis.push_back(1);
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
      return 0;
    }
  solidObject->get(solidObject->getname());

  physicalLocation = solidObject->gethasSolidObject_PrimaryLocation();
  physicalLocation->get(physicalLocation->getname());
  myrecLoc.primaryLocationName = physicalLocation->getname();

  poseLocation->get(physicalLocation->getname());
  mypoint = poseLocation->gethasPoseLocation_Point();
  mypoint->get(mypoint->getname());
  myrecLoc.posePointName = mypoint->getname();
  doubleValue = mypoint->gethasPoint_X();
  myrecLoc.pointXYZ.push_back(doubleValue);
  doubleValue = mypoint->gethasPoint_Y();
  myrecLoc.pointXYZ.push_back(doubleValue);
  doubleValue = mypoint->gethasPoint_Z();
  myrecLoc.pointXYZ.push_back(doubleValue);

  vectorXAxis = poseLocation->gethasPoseLocation_XAxis();
  vectorXAxis->get(vectorXAxis->getname());
  doubleValue = vectorXAxis->gethasVector_I();
  myrecLoc.xAxis.push_back(doubleValue);
  doubleValue = vectorXAxis->gethasVector_J();
  myrecLoc.xAxis.push_back(doubleValue);
  doubleValue = vectorXAxis->gethasVector_K();
  myrecLoc.xAxis.push_back(doubleValue);
  myrecLoc.xAxisName = vectorXAxis->getname();

  vectorZAxis = poseLocation->gethasPoseLocation_ZAxis();
  vectorZAxis->get(vectorZAxis->getname());
  doubleValue = vectorZAxis->gethasVector_I();
  myrecLoc.zAxis.push_back(doubleValue);
  doubleValue = vectorZAxis->gethasVector_J();
  myrecLoc.zAxis.push_back(doubleValue);
  doubleValue = vectorZAxis->gethasVector_K();
  myrecLoc.zAxis.push_back(doubleValue);
  myrecLoc.zAxisName = vectorZAxis->getname();

  recLoc.push_back(myrecLoc);
  if (recurse( physicalLocation->gethasPhysicalLocation_RefObject()) == 0 )
    {
      //      delete poseLocation;
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
      for(int i=0; i<recLoc.size(); i++ )
	{
	  printf( "solidObject: %s\n\tprim: %s\n\tPoint:%s <%f %f %f>\n\txAxis:%s <%f %f %f>\n\tzAxis:%s <%f %f %f>\n",
		  recLoc[i].solidObjectName.c_str(),
		  recLoc[i].primaryLocationName.c_str(),
		  recLoc[i].posePointName.c_str(),
		  recLoc[i].pointXYZ[0],
		  recLoc[i].pointXYZ[1],
		  recLoc[i].pointXYZ[2],
		  recLoc[i].xAxisName.c_str(),
		  recLoc[i].xAxis[0],
		  recLoc[i].xAxis[1],
		  recLoc[i].xAxis[2],
		  recLoc[i].zAxisName.c_str(),
		  recLoc[i].zAxis[0],
		  recLoc[i].zAxis[1],
		  recLoc[i].zAxis[2] );
	}
    }
  printf( "\tGlobalLoc:\n\t\t <%f %f %f>\n\t\t <%f %f %f>\n\t\t <%f %f %f>\n",
	  globalLoc.pointXYZ[0],
	  globalLoc.pointXYZ[1],
	  globalLoc.pointXYZ[2],
	  globalLoc.xAxis[0],
	  globalLoc.xAxis[1],
	  globalLoc.xAxis[2],
	  globalLoc.zAxis[0],
	  globalLoc.zAxis[1],
	  globalLoc.zAxis[2] );
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
  
  double x1i = pose1->xAxis[0];
  double x1j = pose1->xAxis[1];
  double x1k = pose1->xAxis[2];
  double y1i = 0;
  double y1j = 0;
  double y1k = 0;
  double z1i = pose1->zAxis[0];
  double z1j = pose1->zAxis[1];
  double z1k = pose1->zAxis[2];

  double x2i = pose2->xAxis[0];
  double x2j = pose2->xAxis[1];
  double x2k = pose2->xAxis[2];
  double y2i = 0;
  double y2j = 0;
  double y2k = 0;
  double z2i = pose2->zAxis[0];
  double z2j = pose2->zAxis[1];
  double z2k = pose2->zAxis[2];

  double o1x = pose1->pointXYZ[0];
  double o1y = pose1->pointXYZ[1];
  double o1z = pose1->pointXYZ[2];

  double o2x = pose2->pointXYZ[0];
  double o2y = pose2->pointXYZ[1];
  double o2z = pose2->pointXYZ[2];
  
  y1i = ((z1j * x1k) - (x1j * z1k));
  y1j = ((z1k * x1i) - (x1k * z1i));
  y1k = ((z1i * x1j) - (x1i * z1j));
  y2i = ((z2j * x2k) - (x2j * z2k));
  y2j = ((z2k * x2i) - (x2k * z2i));
  y2k = ((z2i * x2j) - (x2i * z2j));
  poseToSet->xAxis[0] = ((x1i * x2i) + (y1i * x2j) + (z1i * x2k));
  poseToSet->xAxis[1] = ((x1j * x2i) + (y1j * x2j) + (z1j * x2k));
  poseToSet->xAxis[2] = ((x1k * x2i) + (y1k * x2j) + (z1k * x2k));
  poseToSet->zAxis[0] = ((x1i * z2i) + (y1i * z2j) + (z1i * z2k));
  poseToSet->zAxis[1] = ((x1j * z2i) + (y1j * z2j) + (z1j * z2k));
  poseToSet->zAxis[2] = ((x1k * z2i) + (y1k * z2j) + (z1k * z2k));
  poseToSet->pointXYZ[0] = ((x1i * o2x) + (y1i * o2y) + (z1i * o2z) + o1x);
  poseToSet->pointXYZ[1] = ((x1j * o2x) + (y1j * o2y) + (z1j * o2z) + o1y);
  poseToSet->pointXYZ[2] = ((x1k * o2x) + (y1k * o2y) + (z1k * o2z) + o1z);
}
