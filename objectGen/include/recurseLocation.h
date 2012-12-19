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

class RecLoc{
 public:
  std::string solidObjectName;
  std::string primaryLocationName;
  std::string posePointName;
  std::string xAxisName;
  std::string zAxisName;
  std::vector<double>pointXYZ;
  std::vector<int>xAxis;
  std::vector<int>zAxis;
  void getRollPitchYaw(double *roll, double *pitch, double *yaw);
};

class RecurseLocation{
 private:
  std::vector<RecLoc>recLoc;
  RecLoc globalLoc;
  void cleanup();
 public:
  RecurseLocation();
  void clear();
  int computeGlobalLoc();
  RecLoc getGlobalLoc();
  void initGlobalLoc();
  void poseProduct( RecLoc * poseToSet, RecLoc * pose1, RecLoc * pose2);
  void printMe(int verbosity);
  int recurse(SolidObject *solidObject);
};
#endif
