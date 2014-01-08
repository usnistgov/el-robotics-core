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

#ifndef __poseInfo
#define __poseInfo

#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>

class PoseInfo{
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
  void getRollPitchYaw(double *roll, double *pitch, double *yaw);
  void setRollPitchYaw(double roll, double pitch, double yaw);
  PoseInfo invert();
  void printMe(int verbosity, std::string prefix="");
};

#endif
