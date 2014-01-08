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
#include <stdio.h>
#include <string>
#include "Part.h"
#include "Point.h"
#include "PoseLocation.h"
#include "PhysicalLocation.h"
#include "SolidObject.h"
#include "Vector.h"
#include "genericModel.h"
#include "poseInfo.hh"
#include "sensorReturn.hh"
#include "USARTruth.hh"

class Frame{
 public:
  PoseInfo pose;
  //  SensorReturn sensorReturn; // provides location of object in world coordinates
                             // if available
  void clear();
};

class RecLoc{
 public:
  std::string solidObjectName;
  std::string solidObjectType;
  std::string primaryLocationName;
  SensorReturn sensorReturn;
  Frame frame;
  void clear();
};

class RecurseLocation{
 private:
  void cleanup();
  std::vector<RecLoc>recLoc;
  RecLoc globalLoc;
  USARTruth usarTruth;
  int sensorConnected;
 public:
  RecurseLocation();
  void sensorConnect(std::string sensorHostName, ulapi_integer portIn=3989);
  void addRecLoc(RecLoc *recLocToAdd);
  void clear();
  int computeGlobalLoc();
  RecLoc getGlobalLoc();
  void initGlobalLoc();
  void poseProduct( PoseInfo * poseToSet, PoseInfo * pose1, PoseInfo * pose2);
  void printMe(int verbosity, std::string prefix="");
  int recurse(SolidObject *solidObject);
};
#endif
