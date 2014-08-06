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
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 30, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include "CRCL/trajectoryMaker.hh"

//! A member function that takes four double arguments and returns a vector 
//! of doubles.
/**
   This function creates a vector of doubles that determines the trajectory 
   of the Robot depending on the start position, the end position, the max 
   velocity, and the acceleration. Shows the position values at times 
   incrementing by the cycle time of the robot.

   \param start The start position of the Robot.
   \param end   The desired end position of the Robot.
   \param       maxSpeed The max velocity the Robot can reach.
   \param       acc The acceleration of the Robot.
   \return      The vector of doubles that show the position of the Robot every 
                cycleTime milliseconds.
**/
std::vector<double> TrajectoryMaker::makePositionVector(double start, 
							double end) 
{
  double distanceToMove;
  bool reverse = false;
  std::vector<double> displacements;
  std::vector<double> currentRamp;
  double currentRampLength;
  double totalDisplacement;
  double displacementRemaining;
  int counter;

  distanceToMove = fabs(start - end);
  if(start > end) reverse = true;

  counter = 0;
  currentRamp.clear();
  currentRampLength = 0;
  while( (distanceToMove > 2.*(currentRampLength+ramp[counter])) && 
	  (counter < ramp.size()))
    {
      currentRamp.push_back(ramp[counter]);
      currentRampLength += ramp[counter];
      counter++;
    }

  // copy ramp to beginning of new vector
  totalDisplacement = 0;
  displacements.clear();
  if( currentRamp.size() > 0)
    {
      for( counter=0; counter<currentRamp.size(); counter++ )
	{
	  displacements.push_back(currentRamp[counter]);
	  totalDisplacement += displacements.back();
	}
      // do I need to add max velocity segments?
      while( (totalDisplacement + currentRamp.back()) <= 
	     (distanceToMove-currentRampLength) )
	{
	  displacements.push_back(currentRamp.back());
	  totalDisplacement += currentRamp.back();
	}

      // add deceleration
      displacementRemaining = distanceToMove - 
	(totalDisplacement + currentRampLength);

      for( counter=currentRamp.size()-1; counter>=0; counter-- )
	{
	  displacements.push_back(currentRamp[counter]);
	  totalDisplacement += currentRamp[counter];
	  while( displacementRemaining >= currentRamp[counter] )
	    {
	      /*
		printf( "Current Ramp: %lf remaining: %lf diff: %lf\n",
		currentRamp[counter], displacementRemaining,
		displacementRemaining = currentRamp[counter]);
	      */
	      displacements.push_back(currentRamp[counter]);
	      totalDisplacement += currentRamp[counter];
	      displacementRemaining -= currentRamp[counter];
	    }
	}
    }
  if( totalDisplacement < distanceToMove )
    {
      displacements.push_back(distanceToMove-totalDisplacement);
      totalDisplacement += displacements.back();
    }
  printf( "Total displacement: %lf distance to move: %lf diff: %lf remain: %lf\n",
	  totalDisplacement, distanceToMove, 
	  fabs(totalDisplacement-distanceToMove),
	  displacementRemaining);
  
  // reverse if necessary
  if( reverse )
    {
      for( counter = 0; counter < displacements.size(); counter++ )
	displacements[counter] *= -1;
    }
  return displacements;
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
std::vector<robotPose> TrajectoryMaker::manipulateVector(std::vector<double> vX,
						 std::vector<double> vY, 
						 std::vector<double> vZ, 
						 std::vector<double> vRoll, 
						 std::vector<double> vPitch, 
						 std::vector<double> vYaw, 
						 int maxSize)
{
  std::vector<robotPose> PoseVector;
  robotPose point;
  for (std::vector<robotPose>::size_type i = 0; i != maxSize; i++)
    {
      if( vX.size() > i )
	point.x = vX[i];
      else
	point.x = 0;
      if( vY.size() > i )
	point.y = vY[i];
      else
	point.y = 0;
      if( vZ.size() > i )
	point.z = vZ[i];
      else
	point.z = 0;
      if( vRoll.size() > i )
	point.xrot = vRoll[i];
      else
	point.xrot = 0;
      if( vPitch.size() > i )
	point.yrot = vPitch[i];
      else
	point.yrot = 0;
      if( vYaw.size() > i )
	point.zrot = vYaw[i];
      else
	point.zrot = 0;
      PoseVector.push_back(point);
    }

  return PoseVector;
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
int TrajectoryMaker::maxVectorSize(std::vector<double> vX, 
				std::vector<double> vY, 
				std::vector<double> vZ, 
				std::vector<double> vRoll, 
				std::vector<double> vPitch, 
				std::vector<double> vYaw)
{
  double steps[] = { vX.size(), vY.size(), vZ.size(), vRoll.size(), 
		     vPitch.size(), vYaw.size() };
  return (*std::max_element(steps, steps + 6));
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
}

//! Computes an acceleration/decelleration ramp from robot parameters
/** This ramp is used to compute trajectories and represents operating
    at the max acceleration to achieve the maximum velocity. Note
    that ramp is computed in cartesian space which may still violate
    joint space velocity constraints on the actual robot system
    
    Algorithm:
    1) Compute the distance that the robot will travel in Cartesian space
       at current velocity for one cycle time
    2) While the velocity is less than the max, increase it by 
       acceleration times cycle time.

    \param parameters  The robot's parameters
    \return distance   The length of the ramp
**/
double TrajectoryMaker::makeRamp(CRCLStatus *parameters)
{
  double traverseIncrement;
  double currentVelocity = parameters->getMaxAccel() * 
    parameters->getCycleTime();
  double totalDistance = 0;

  ramp.clear();
  
  while( currentVelocity < parameters->getMaxVel() )
    {
      traverseIncrement = currentVelocity * parameters->getCycleTime();
      ramp.push_back(traverseIncrement);
      totalDistance += traverseIncrement;
      currentVelocity += parameters->getMaxAccel() * parameters->getCycleTime();
    }
  printf( "Ramp distance is: %lf\n", totalDistance);
  /*
  for( int ii=0; ii<ramp.size(); ii++)
    printf("ramp[%d]:%lf\n", ii, ramp[ii]);
  */
  return totalDistance;
}
	
//! Computes the movement trajectory of the robot
/**
   This function creates a vector of robot positions (robotPose) 
   that represents the movement trajectory of the Robot.
   Calls makeRamp, makePositionVector, and manipulateVector.
   \param parameters: contains the target robot pose and
                      the parameters of motion for the robot
   \return The vector of robot positions (robotPose) that represents 
   the movement trajectory.
**/
std::vector<robotPose> TrajectoryMaker::makeTrajectory(CRCLStatus *parameters,
						       robotPose pose)
{
  std::vector<double> vX, vY, vZ, vRoll, vPitch, vYaw;
  std::vector<robotPose> result;

  rampLength = makeRamp(parameters);
  vX = makePositionVector(current.x, pose.x); 
  vY = makePositionVector(current.y, pose.y); 
  vZ = makePositionVector(current.z, pose.z); 
  vRoll = makePositionVector(current.xrot, pose.xrot); 
  vPitch = makePositionVector(current.yrot, pose.yrot); 
  vYaw = makePositionVector(current.zrot, pose.zrot); 

  int maxSize = maxVectorSize(vX, vY, vZ, vRoll, vPitch, vYaw);
  if( maxSize > 0 )
    result = manipulateVector(vX, vY, vZ, vRoll, vPitch, vYaw, maxSize);
  else
    {
      robotPose tempPose;
      tempPose.x = 0;
      tempPose.y = 0;
      tempPose.z = 0;
      tempPose.xrot = 0;
      tempPose.yrot = 0;
      tempPose.zrot = 0;
      result.push_back(tempPose);
    }
  return result;
}
