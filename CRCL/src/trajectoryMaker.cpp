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
/*!
 *	\file		trajectorMaker.cpp
 *	\brief 		This class keeps track of the positions of the 
 *                      robot and creates the trajectory of movement.
 *	\class		TrajectoryMaker
 *	\author		Kevin Lee, GTRI
 *	\date		June 02, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include "CRCL/trajectoryMaker.hh"

//! A member function that takes four double arguments and returns a vector of doubles.
/**
   This function creates a vector of doubles that determines the trajectory of the Robot
   depending on the start position, the end position, the max velocity, and the acceleration.
   Shows the position values at times incrementing by 25 milliseconds.
   \param start The start position of the Robot.
   \param end The desired end position of the Robot.
   \param maxSpeed The max velocity the Robot can reach.
   \param acc The acceleration of the Robot.
   \return The vector of doubles that show the position of the Robot every 10 milliseconds.
*/
std::vector<double> TrajectoryMaker::makePositionVector(double start, 
							double end, 
							double maxSpeed, 
							double acc)
{
  if (start > end) backwards[counter] = true;

  if (backwards[counter]) end = (start - end) + start;
  counter++;

  std::vector<double> v;
  double t1 = (maxSpeed / acc);
  double x1 = start + 0.5 * acc * t1 * t1;
  double x2 = start + end - x1;
  double t2 = t1 + ((x2 - x1) / maxSpeed);
  double tfinish = t2 + t1 + 0.010;
  double xfinish = x2 + x1 - start;
  double currentX = current.x;
  double previousX = 0;

  for (double t = 0; t <= tfinish; t += 0.010)
    {
      if (t < t1 + 0.010)
	{
	  currentX = start + (0.5 * acc * t * t);

	  if (currentX >= xfinish)
	    {
	      break;
	    }
	}

      else if (t <= t2 + 0.010)
	{
	  currentX = x1 + (maxSpeed * (t - t1));

	  if (currentX >= xfinish)
	    {
	      break;
	    }

	}

      else if (t > t2 + 0.010)
	{
	  currentX = x2 + (maxSpeed*(t - t2)) + (0.5 * -1 * acc * (t - t2) * (t - t2));


	  if (currentX >= xfinish)
	    {
	      break;
	    }

	}

      v.push_back(currentX);
    }

  if (v.empty()) v.push_back(start);
  return v;
}

//! A member function that takes one double argument and returns a vector of doubles.	
/**
   This function creates a vector that contain the time values depending on the length given.
   Time increments by 0.010 until the vector reaches the desired length.
   \param length The length of the position vector.
   \return A vector of time values.
*/
std::vector<double> TrajectoryMaker::makeTimeVector(double length)
{
  std::vector<double> v5;
  for (double t = 0; v5.size() < length; t = t + 0.010)
    {
      v5.push_back(t);
    }

  return v5;
}

//! A member function that takes two arguments and returns a vector.
/**
   This function determines which of the position movement takes the longest to complete.
   Then changes the trajectory of the other positions so that all movements end at the same time.
   Also calls interpolate, changeToCorrection, and goBackwards.
   \param vX The vector representing the x positions.
   \param vY The vector representing the y positions.
   \param vZ The vector representing the z positions.
   \param vRoll The vector representing the roll positions.
   \param vPitch The vector representing the pitch positions.
   \param vYaw The vector representing the yaw positions.
   \param maxEndTime The longest time the position movement takes.
   \return A vector of SingleLocation that now contains all the updated position correction values.
*/
std::vector<robotPose> TrajectoryMaker::manipulateVector(std::vector<double> vX, std::vector<double> vY, std::vector<double> vZ, std::vector<double> vRoll, std::vector<double> vPitch, std::vector<double> vYaw, double maxEndTime)
{

  std::vector<double> vXTime = makeTimeVector(vX.size());
  double endTime = vXTime.back();
  double multiple = maxEndTime / endTime;

  for (std::vector<double>::size_type i = 0; i != vX.size(); i++)
    {
      vXTime[i] = vXTime[i] * multiple;
    }

  std::vector<double> vYTime = makeTimeVector(vY.size());
  endTime = vYTime.back();
  multiple = maxEndTime / endTime;

  for (std::vector<double>::size_type i = 0; i != vY.size(); i++)
    {
      vYTime[i] = vYTime[i] * multiple;
    }

  std::vector<double> vZTime = makeTimeVector(vZ.size());
  endTime = vZTime.back();
  multiple = maxEndTime / endTime;

  for (std::vector<double>::size_type i = 0; i != vZ.size(); i++)
    {
      vZTime[i] = vZTime[i] * multiple;
    }

  std::vector<double> vRollTime = makeTimeVector(vRoll.size());
  endTime = vRollTime.back();
  multiple = maxEndTime / endTime;

  for (std::vector<double>::size_type i = 0; i != vRoll.size(); i++)
    {
      vRollTime[i] = vRollTime[i] * multiple;
    }

  std::vector<double> vPitchTime = makeTimeVector(vPitch.size());
  endTime = vPitchTime.back();
  multiple = maxEndTime / endTime;

  for (std::vector<double>::size_type i = 0; i != vPitch.size(); i++)
    {
      vPitchTime[i] = vPitchTime[i] * multiple;
    }

  std::vector<double> vYawTime = makeTimeVector(vYaw.size());
  if (vYaw.empty())
    {
      endTime = 0;
      multiple = 0;
    }
  else
    {
      endTime = vYawTime.back();
      multiple = maxEndTime / endTime;
    }

  for (std::vector<double>::size_type i = 0; i != vYaw.size(); i++)
    {
      vYawTime[i] = vYawTime[i] * multiple;
    }

  vX = interpolate(vX, vXTime, maxEndTime);
  vY = interpolate(vY, vYTime, maxEndTime);
  vZ = interpolate(vZ, vZTime, maxEndTime);
  vRoll = interpolate(vRoll, vRollTime, maxEndTime);
  vPitch = interpolate(vPitch, vPitchTime, maxEndTime);
  vYaw = interpolate(vYaw, vYawTime, maxEndTime);

  vX = changeToCorrection(vX);
  vY = changeToCorrection(vY);
  vZ = changeToCorrection(vZ);
  vRoll = changeToCorrection(vRoll);
  vPitch = changeToCorrection(vPitch);
  vYaw = changeToCorrection(vYaw);

  if (backwards[0]) vX = goBackwards(vX);
  if (backwards[1]) vY = goBackwards(vY);
  if (backwards[2]) vZ = goBackwards(vZ);
  if (backwards[3]) vRoll = goBackwards(vRoll);
  if (backwards[4]) vPitch = goBackwards(vPitch);
  if (backwards[5]) vYaw = goBackwards(vYaw);

  backwards[0] = false;
  backwards[1] = false;
  backwards[2] = false;
  backwards[3] = false;
  backwards[4] = false;
  backwards[5] = false;


  std::vector<robotPose> PoseVector;
  robotPose point;
  for (std::vector<robotPose>::size_type i = 0; i != vX.size(); i++)
    {
      point.x = vX[i];
      point.y = vY[i];
      point.z = vZ[i];
      point.xrot = vRoll[i];
      point.yrot = vPitch[i];
      point.zrot = vYaw[i];
      PoseVector.push_back(point);
    }

  return PoseVector;
}

//! A member function that takes three arguments and returns a vector of doubles.
/**
   This function does the actual interpolating of the positions when stretching the vectors
   depending on the longest time the position change requires. Calculates the correction values of the changed trajectories
   at every 10 milliseconds.
   Called by manipulateVector.
   \param realVector The position vector
   \param timeVector The time vector corresponding to the position vector.
   \param maxEndTime The longest time required by position change.
   \return The vector of double that now corresponds to the position at every 10 milliseconds.
*/
std::vector<double> TrajectoryMaker::interpolate(std::vector<double> realVector, std::vector<double> timeVector, double maxEndTime)
{

  double length = (maxEndTime / 0.010) - 0.010;
  std::vector<double> finalTimeVector;
  std::vector<double> finalRealVector;
  double ind = 0;
  double xfinal, yfinal;
  double x0 = 0;
  double x1 = 0;
  double y0 = 0;
  double y1 = 0;

  for (double t = 0; finalTimeVector.size() < length; t = t + 0.010)
    {
      finalTimeVector.push_back(t);
    }

  if (realVector.size() == 1)
    {
      for (int i = 0; i < finalTimeVector.size(); i++)
	{
	  finalRealVector.push_back(realVector[0]);
	}
			
      return finalRealVector;
    }


  for (int i = 0; i < finalTimeVector.size(); i++)
    {

      for (int j = 0; j < timeVector.size(); j++)
	{
	  if (timeVector[j] >= finalTimeVector[i])
	    {
	      ind = j;
	      break;
	    }
	}


      if (finalTimeVector[i] == timeVector[ind]) yfinal = realVector[ind];
      else
	{
	  y1 = realVector[ind];
	  y0 = realVector[ind - 1];
	  xfinal = finalTimeVector[i];
	  x1 = timeVector[ind];
	  x0 = timeVector[ind - 1];
	  yfinal = y0 + ((y1 - y0) * ((xfinal - x0) / (x1 - x0)));
	}

      finalRealVector.push_back(yfinal);

    }

  return finalRealVector;

}

//! A member function that takes six arguments and returns a double
/**
   This function determines from the six vectors of doubles which is the longest
   and determines the longest time by multiplying it by 0.010.
   \param vX The vector representing x positions.
   \param vY The vector representing y positions.
   \param vZ The vector representing z positions.
   \param vRoll The vector representing roll positions.
   \param vPitch The vector representing pitch positions.
   \param vYaw The vector representing yaw positions.
   \return The longest duration of time of the movements.
*/
double TrajectoryMaker::maxTime(std::vector<double> vX, std::vector<double> vY, std::vector<double> vZ, std::vector<double> vRoll, std::vector<double> vPitch, std::vector<double> vYaw)
{
  double steps[] = { vX.size(), vY.size(), vZ.size(), vRoll.size(), vPitch.size(), vYaw.size() };
  return (*std::max_element(steps, steps + 6) * 0.010);
}

//! A member function that takes one argument and returns a vector of doubles.
/**
   This function changes the vector that represents the position values to a vector that represents the correction values.
   \param vectorIn The vector representing the position values.
   \return A vector that represents the correction of the position values.
*/
std::vector<double> TrajectoryMaker::changeToCorrection(std::vector<double> vectorIn)
{
  std::vector<double> corrections;
  double previous = vectorIn[0];

  for (int i = 0; i < vectorIn.size(); i++)
    {
      corrections.push_back(vectorIn[i] - previous);
      previous = vectorIn[i];
    }
  return corrections;
}
	
//! A member function that takes one argument and returns a vector of doubles.
/**
   This function checks if any positions have to go in the negative direction.
   Then the correction values are changed into negative numbers.
   \param vectorIn The vector representing the correction values.
   \return A vector that represents the correction of the position values.
*/
std::vector<double> TrajectoryMaker::goBackwards(std::vector<double> vectorIn)
{
  std::vector<double> result;
  for (int i = 0; i < vectorIn.size(); i++)
    {
      result.push_back(vectorIn[i] * -1);
    }

  return result;

}
//! Set current location
/**
   Set the current location from the input pose
*/
void TrajectoryMaker::setCurrent(robotPose poseIn)
{
  current.x = poseIn.x;
  current.y = poseIn.y;
  current.z = poseIn.z;
  current.xrot = poseIn.xrot;
  current.yrot = poseIn.yrot;
  current.zrot = poseIn.zrot;
}

//! CurrentLocation Constructor.
/**
   Constructor for CurrentLocation that sets all points and velocity to 0.
*/
TrajectoryMaker::TrajectoryMaker()
{
  current.x = 0;
  current.y = 0;
  current.z = 0;
  current.xrot = 0;
  current.yrot = 0;
  current.zrot = 0;
  counter = 0;

  for (int i = 0; i < 6; i++)
    {
      backwards.push_back(false);
    }
}
	
//! A member function that takes eight double arguments and returns a vector of SingleLocation.
/**
   This function creates a vector of SingleLocations that represents the movement trajectory of the Robot.
   Calls manipulateVector.
   \param finalX The destination x position.
   \param finalY The destination y position.
   \param finalZ The destination z position.
   \param finalRoll The destination roll position.
   \param finalPitch The destination pitch position.
   \param finalYaw The destination yaw position.
   \param maxSpeed The maximum speed of the Robot.
   \param acc The acceleration of the Robot.
   \return The vector of SingeLocation that represents the movement trajectory.
*/
std::vector<robotPose> TrajectoryMaker::makeTrajectory(robotPose final, 
						  double maxSpeed, double acc)
{
  std::vector<double> vX, vY, vZ, vRoll, vPitch, vYaw;
  vX = makePositionVector(current.x, final.x, maxSpeed, acc);
  vY = makePositionVector(current.y, final.y, maxSpeed, acc);
  vZ = makePositionVector(current.z, final.z, maxSpeed, acc);
  vRoll = makePositionVector(current.xrot, final.xrot, maxSpeed, acc);
  vPitch = makePositionVector(current.yrot, final.yrot, maxSpeed, acc);
  vYaw = makePositionVector(current.zrot, final.zrot, maxSpeed, acc);

  double maxEndTime = maxTime(vX, vY, vZ, vRoll, vPitch, vYaw);
  std::vector<robotPose> result = manipulateVector(vX, vY, vZ, vRoll, 
					      vPitch, vYaw, maxEndTime);
  counter = 0;
  return result;
}
