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


#ifndef __recurseLocation
#define __recurseLocation
/*!
The recurse location library works as follows:
1)	Allocate a new recurseLocation
2)	Call the clear() method
3)	Call the recurse() method with the SolidObject pointer to the item that you want the global location of.
4)	Call the computeGlobalLoc() method
5)	If desired, call the printMe() method to get a printout of the tree and final location
6)	The recurseLocation.getGlobalLoc() returns the computed global location as a RecLoc. RecLoc is also defined in these files.
7)	Repeat from 2 for more objects.
This may also be seen in the dataTest.cpp file.
*/

#include <vector>
#include <string>
#include "database/Part.h"
#include "database/Point.h"
#include "database/PoseLocation.h"
#include "database/PhysicalLocation.h"
#include "database/SolidObject.h"
#include "database/Vector.h"

class Frame{
 public:
  std::vector<double>pointXYZ;
  std::vector<double>xAxis;
  std::vector<double>zAxis;
  std::string pointName;
  std::string xAxisName;
  std::string zAxisName;

  void clear();
  std::vector<double> computeYAxis();
  void setPoint(double x, double y, double z);
  void setPointName(std::string pointNameIn);
  void setXAxis(double x, double y, double z);
  void setXAxisName(std::string xAxisNameIn);
  void setZAxis(double x, double y, double z);
  void setZAxisName(std::string zAxisNameIn);
  Frame invert();
};

class RecLoc{
 public:
  std::string solidObjectName;
  std::string primaryLocationName;
  Frame frame;
  void getRollPitchYaw(double *roll, double *pitch, double *yaw);
  void clear();
};

class RecurseLocation{
 private:
  std::vector<RecLoc>recLoc;
  RecLoc globalLoc;
  void cleanup();
 public:
  RecurseLocation();
  void addRecLoc(RecLoc *recLocToAdd);
  void clear();
  int computeGlobalLoc();
  RecLoc getGlobalLoc();
  void initGlobalLoc();
  void poseProduct( RecLoc * poseToSet, RecLoc * pose1, RecLoc * pose2);
  void printMe(int verbosity);
  int recurse(SolidObject *solidObject);
};
#endif
