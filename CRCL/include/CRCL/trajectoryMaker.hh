#ifndef TrajectoryMaker_DECL
#define TrajectoryMaker_DECL

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "singleLocation.hh"

using namespace std;

class TrajectoryMaker
{
private:
	vector<double> makePositionVector(double start, double end, double maxSpeed, double acc);
	vector<double> makeTimeVector(double length);
	vector<SingleLocation> manipulateVector(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vRoll, vector<double> vPitch, vector<double> vYaw, double maxEndTime);
	vector<double> interpolate(vector<double> realVector, vector<double> timeVector,double maxEndTime);
	double maxTime(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vRoll, vector<double> vPitch, vector<double> vYaw);
	vector<double> changeToCorrection(vector<double> vectorIn);
	vector<double> goBackwards(vector<double> vectorIn);

public:
	double x; /*!< X value.*/
	double y; /*!< Y value.*/
	double z; /*!< Z value.*/
	double roll; /*!< roll value.*/
	double pitch; /*!< pitch value.*/
	double yaw; /*!< yaw value.*/
	double maxSpeed; /*!< The maximum velocity of the Robot.*/
	double acceleration; /*!< The acceleration of the Robot.*/
	vector<bool> backwards; /*!< States whether positions are changing in positive or negative direction. */
	int counter; /*!< counter for the backwards vector.*/
	TrajectoryMaker();
	void setPositions(double correctionX, double correctionY, double correctionZ, double correctionRoll, double correctionPitch, double correctionYaw);
	vector<SingleLocation> makeTrajectory(double finalX, double finalY, double finalZ, double finalRoll, double finalPitch, double finalYaw, double maxSpeed, double acc);

};

#endif