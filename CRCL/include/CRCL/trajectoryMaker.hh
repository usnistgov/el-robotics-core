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
#include "nist_core/crcl.h"

class TrajectoryMaker
{
private:
  std::vector<double> makePositionVector(double start, double end, 
				    double maxSpeed, double acc);
  std::vector<double> makeTimeVector(double length);
  std::vector<robotPose> manipulateVector(std::vector<double> vX, 
					  std::vector<double> vY, 
					  std::vector<double> vZ, 
					  std::vector<double> vRoll, 
					  std::vector<double> vPitch, 
					  std::vector<double> vYaw,
				     double maxEndTime);
  std::vector<double> interpolate(std::vector<double> realVector, 
				  std::vector<double> timeVector,
				  double maxEndTime);
  double maxTime(std::vector<double> vX, std::vector<double> vY, 
		 std::vector<double> vZ, 
		 std::vector<double> vRoll, std::vector<double> vPitch, 
		 std::vector<double> vYaw);
  std::vector<double> changeToCorrection(std::vector<double> vectorIn);
  std::vector<double> goBackwards(std::vector<double> vectorIn);

public:
  robotPose current;
  double maxSpeed; /*!< The maximum velocity of the Robot.*/
  double acceleration; /*!< The acceleration of the Robot.*/
  std::vector<bool> backwards; /*!< States whether positions are changing in positive or negative direction. */
  int counter; /*!< counter for the backwards vector.*/
  TrajectoryMaker();
  std::vector<robotPose> makeTrajectory(robotPose goal, 
					double maxSpeed, double acc);
  void setCurrent(robotPose current); /*!< Set the current position. */
};

#endif
