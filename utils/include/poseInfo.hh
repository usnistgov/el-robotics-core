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
private:
  std::string pointName;
  std::string xAxisName;
  std::string zAxisName;
  std::vector<double>pointXYZ;
  std::vector<double>xAxis;
  std::vector<double>zAxis;

public:
  PoseInfo();
  void clear();
  std::vector<double> computeYAxis();
  std::string getPointName();
  std::string getXAxisName();
  std::string getZAxisName();
  std::vector<double> getPoint();
  double getPointX();
  double getPointY();
  double getPointZ();
  void setPoint(double x, double y, double z);
  void setPointName(std::string pointNameIn);
  std::vector<double> getXAxis();
  double getXAxisI();
  double getXAxisJ();
  double getXAxisK();
  void setXAxis(double x, double y, double z);
  void setXAxisName(std::string xAxisNameIn);
  std::vector<double> getZAxis();
  double getZAxisI();
  double getZAxisJ();
  double getZAxisK();
  void setZAxis(double x, double y, double z);
  void setZAxisName(std::string zAxisNameIn);
  void getRollPitchYaw(double *roll, double *pitch, double *yaw);
  void setRollPitchYaw(double roll, double pitch, double yaw);
  PoseInfo invert();
  void printMe(int verbosity, std::string prefix="");
};

#endif
