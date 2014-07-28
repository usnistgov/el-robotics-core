//! SingleLocation structure.
/**
  A structure that represents a single position of the Robot.
  Contains the x, y, z, roll, pitch, and the yaw values.
*/

#include "CRCL/singleLocation.hh"

//! The constructor for SingleLocation with no arguments.
/**
  Initializes x, y, z, roll, pitch, yaw to 0.  
*/
SingleLocation::SingleLocation()
{
	x = 0;
	y = 0;
	z = 0;
	roll = 0;
	pitch = 0;
	yaw = 0;
}

//! The constructor for SingleLocation with six double arguments.
/**
  Constructor for SingleLocation that sets the x, y, z, roll, pitch, and yaw values with the values passed. 
*/
SingleLocation::SingleLocation(double xIn, double yIn, double zIn, double rollIn, double pitchIn, double yawIn)
{
	x = xIn;
	y = yIn;
	z = zIn;
	roll = rollIn;
	pitch = pitchIn;
	yaw = yawIn;
}