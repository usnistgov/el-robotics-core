#ifndef __recurseLocation
#define __recurseLocation
#endif
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
};

class RecurseLocation{
 private:
  std::vector<RecLoc>recLoc;
  RecLoc globalLoc;
  void cleanup();
 public:
  RecurseLocation();
  int computeGlobalLoc();
  void initGlobalLoc();
  void poseProduct( RecLoc * poseToSet, RecLoc * pose1, RecLoc * pose2);
  int printMe(int verbosity);
  int recurse(SolidObject *solidObject);
};
