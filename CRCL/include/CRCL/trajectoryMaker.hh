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
#ifndef TrajectoryMaker_DECL
#define TrajectoryMaker_DECL

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "CRCL/crclDefs.hh"
#include "CRCL/crclStatus.hh"

class TrajectoryMaker
{
private:
  std::vector<double> makePositionVector(double start, double end); 
  std::vector<robotPose> manipulateVector(std::vector<double> vX, 
					  std::vector<double> vY, 
					  std::vector<double> vZ, 
					  std::vector<double> vRoll, 
					  std::vector<double> vPitch, 
					  std::vector<double> vYaw,
					  int maxSize);
  int maxVectorSize(std::vector<double> vX, std::vector<double> vY, 
		 std::vector<double> vZ, 
		 std::vector<double> vRoll, std::vector<double> vPitch, 
		 std::vector<double> vYaw);
public:
  robotPose current;
  TrajectoryMaker();
  double makeRamp(CRCLStatus *parameters);
  std::vector<robotPose> makeTrajectory(CRCLStatus *parameters, robotPose pose);
  void setCurrent(robotPose current); /*!< Set the current position. */
private:
  std::vector<double>ramp; /*!< Ramp up or down to maximum velocity */
  double rampLength; /*!< The distance traveled over the ramp */
};

#endif
