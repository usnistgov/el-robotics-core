
#ifndef SINGLELOCATION_DECL
#define SINGLELOCATION_DECL

struct SingleLocation
{
	double x; /*!< The delta x value. */
	double y; /*!< The delta y value. */
	double z; /*!< The delta z value. */
	double roll; /*!< The delta roll value. */
	double pitch; /*!< The delta pitch value. */
	double yaw; /*!< The delta yaw value. */	

	SingleLocation();
	SingleLocation(double xIn, double yIn, double zIn, double rollIn, double pitchIn, double yawIn);

};

#endif