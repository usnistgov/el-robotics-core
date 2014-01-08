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
 *	\file		poseInfo.cpp
 *	\brief 		Pose information and utilities
 *	\class		PoseInfo
 *	\author		Stephen Balakirsky, GTRI
 *	\date		Jan 8, 2014
 *      \copyright      Georgia Tech Research Institute
 */

#include "poseInfo.hh"
/*!
  @brief Invert the frame transform
  @return The inverted frame
 */
PoseInfo PoseInfo::invert()
{
  PoseInfo inverse;
  std::vector<double> yAxis;
  double pointx, pointy, pointz;
  
  yAxis = this->computeYAxis();
  inverse.setXAxis(this->xAxis[0], yAxis[0], this->zAxis[0]);
  inverse.setZAxis(this->xAxis[2], yAxis[2], this->zAxis[2]);
  
  pointx = -(this->xAxis[0]*this->pointXYZ[0] + 
	     yAxis[0]*this->pointXYZ[1] + 
	     this->zAxis[0]*this->pointXYZ[2]);
  pointy = -(this->xAxis[1]*this->pointXYZ[0] + 
	     yAxis[1]*this->pointXYZ[1] + 
	     this->zAxis[1]*this->pointXYZ[2]);
  pointz = -(this->xAxis[2]*this->pointXYZ[0] + 
	     yAxis[2]*this->pointXYZ[1] + 
	     this->zAxis[2]*this->pointXYZ[2]);
  inverse.setPoint(pointx, pointy, pointz);
  return inverse;
}

void PoseInfo::setPoint( double x, double y, double z )
{
  pointXYZ.clear();
  pointXYZ.push_back(x);
  pointXYZ.push_back(y);
  pointXYZ.push_back(z);
}

void PoseInfo::setPointName( std::string pointNameIn)
{
  pointName = pointNameIn;
}

/*!
  @brief Compute yAxis from x & z axis locations
  @param xAxis Vector that contains the xAxis values
  @param zAxis Vector that contains the zAxis values
  @return vector that contains y axis
*/
std::vector<double> PoseInfo::computeYAxis()
{
  std::vector<double>yAxis;

  double xi = xAxis[0];
  double xj = xAxis[1];
  double xk = xAxis[2];
  double zi = zAxis[0];
  double zj = zAxis[1];
  double zk = zAxis[2];

  yAxis.push_back((zj * xk) - (xj * zk));
  yAxis.push_back((zk * xi) - (xk * zi));
  yAxis.push_back((zi * xj) - (xi * zj));
  return yAxis;
}

void PoseInfo::setXAxis( double x, double y, double z )
{
  xAxis.clear();
  xAxis.push_back(x);
  xAxis.push_back(y);
  xAxis.push_back(z);
}

void PoseInfo::setXAxisName( std::string xAxisNameIn)
{
  xAxisName = xAxisNameIn;
}

void PoseInfo::setZAxis( double x, double y, double z )
{
  zAxis.clear();
  zAxis.push_back(x);
  zAxis.push_back(y);
  zAxis.push_back(z);
}

void PoseInfo::setZAxisName( std::string zAxisNameIn)
{
  zAxisName = zAxisNameIn;
}

/*!
  @brief Clear out the vectors for this structure
*/
void PoseInfo::clear()
{
  pointXYZ.clear();
  xAxis.clear();
  zAxis.clear();
}

/*!
 @brief Retreive the roll, pitch, and yaw from the pose.
 This function utilizes the forward and up vectors to compute
 the associated roll, pitch, and yaw.
@param roll Storage location for the computed roll
@param pitch Storage location for the computed roll
@param yaw Storage location for the computed roll
@return None
 */
void PoseInfo::getRollPitchYaw(double *roll, double *pitch, double *yaw)
{
  double cosPitch, cosYaw, sinYaw, cosRoll, sinRoll;

  *pitch = asin(-xAxis[2]);
  cosPitch = sqrt(1. - xAxis[2]*xAxis[2]);
    
  //Check if we are straight up or down
  if (cosPitch == 0 || fabs(xAxis[2]) >= 1)
    {
      if (*pitch > 0)
        {
	  *yaw = 0;
	  *roll = atan2(-zAxis[1], -zAxis[0]) + M_PI;
        }
      else
        {
	  yaw = 0;
	  *roll = -atan2(zAxis[1], zAxis[0]) + M_PI;    
        }
    }
    else
      {
        
        cosYaw = xAxis[0]/cosPitch;
        sinYaw = xAxis[1]/cosPitch;
        *yaw = atan2(sinYaw, cosYaw);
        
        cosRoll = zAxis[2]/cosPitch;
        if (fabs(cosYaw) < fabs(sinYaw))
	  {
            sinRoll = -(zAxis[0] + 
			xAxis[2]*cosRoll*cosYaw)/sinYaw;
	  }
        else
	  {
            sinRoll = (zAxis[1] + 
		       xAxis[2]*cosRoll*sinYaw)/cosYaw;
	  }
        *roll = atan2(sinRoll, cosRoll);
      }
    
    
    //Keep all angles in [0, 2pi]
    if (*yaw < 0)
      *yaw += 2*M_PI;
    else if (*yaw >= 2*M_PI)
      *yaw -= 2*M_PI;
    
    if (*pitch < 0)
      *pitch += 2*M_PI;
    else if (*pitch >= 2*M_PI)
      *pitch -= 2*M_PI;
        
    if (*roll < 0)
      *roll += 2*M_PI;
    else if (*roll >= 2*M_PI)
      *roll -= 2*M_PI;
    }

void PoseInfo::setRollPitchYaw(double roll, double pitch, double yaw)
{
	double cosRoll, sinRoll, cosPitch, sinPitch, cosYaw, sinYaw;
	
	cosRoll = cos(roll);
	sinRoll = sin(roll);
	cosPitch = cos(pitch);
	sinPitch = sin(pitch);
	cosYaw = cos(yaw);
	sinYaw = sin(yaw);
	
	double xi, xj, xk, zi, zj, zk;
	
	xi = cosYaw * cosPitch;
	xj = sinYaw * cosPitch;
	xk = -sinPitch;
	
	zi = cosYaw * sinPitch * cosRoll + sinYaw * sinRoll;
	zj = sinYaw * sinPitch * cosRoll - cosYaw * sinRoll;
	zk = cosPitch * cosRoll;
	
	setXAxis(xi, xj, xk);
	setZAxis(zi, zj, zk);
}

/*!
  @brief Pring information from class
  @param verbosity - 0 does not print much, 1 does
  @param prefix - This is added to all output lines
*/
void PoseInfo::printMe(int verbosity, std::string prefix)
{
  if( verbosity > 0 )
    {
      printf(" %sPoint:%s <%f %f %f>\n%sxAxis:%s <%f %f %f>\n%szAxis:%s <%f %f %f>\n",
	     prefix.c_str(),
	     pointName.c_str(),
	     pointXYZ[0],
	     pointXYZ[1],
	     pointXYZ[2],
	     prefix.c_str(),
	     xAxisName.c_str(),
	     xAxis[0],
	     xAxis[1],
	     xAxis[2],
	     prefix.c_str(),
	     zAxisName.c_str(),
	     zAxis[0],
	     zAxis[1],
	     zAxis[2] );
    }
}

