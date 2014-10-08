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
 *	\file		kukaThreadArgs.cpp
 *	\brief 		Argument class for Kuka robot
 *	\class		KukaThreadArgs
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 02, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <cstdlib> // exit()
#include "CRCL/kukaThreadArgs.hh"

KukaThreadArgs::KukaThreadArgs()
{
  ulapi_mutex_init(&poseCorrectionMutex, 1);  
  ulapi_mutex_give(&poseCorrectionMutex);

  ulapi_mutex_take(&poseCorrectionMutex);
  this->lockToolChanger = true;

  poseCorrection.x = 0;
  poseCorrection.y = 0;
  poseCorrection.z = 0;
  poseCorrection.xrot = 0;
  poseCorrection.yrot = 0;
  poseCorrection.zrot = 0;
  ulapi_mutex_give(&poseCorrectionMutex);
}

void KukaThreadArgs::addPose(const robotPose rhs)
{
  ulapi_mutex_take(&poseCorrectionMutex);
  poseCorrection.x += rhs.x;
  poseCorrection.y += rhs.y;
  poseCorrection.z += rhs.z;
  poseCorrection.xrot += rhs.xrot;
  poseCorrection.yrot += rhs.yrot;
  poseCorrection.zrot += rhs.zrot;
  ulapi_mutex_give(&poseCorrectionMutex);
  return;
}

bool KukaThreadArgs::getCartesianMove()
{
  return cartesianMove;
}

KukaState KukaThreadArgs::getCurrentState()
{
  KukaState retValue;

  ulapi_mutex_take(&poseCorrectionMutex);
  retValue = currentState;
  ulapi_mutex_give(&poseCorrectionMutex);
  return retValue;
}

robotPose KukaThreadArgs::getPoseCorrection(int zeroValues)
{
  robotPose retValue;

  ulapi_mutex_take(&poseCorrectionMutex);
  retValue = poseCorrection;
  if( zeroValues )
    {
      poseCorrection.x = 0;
      poseCorrection.y = 0;
      poseCorrection.z = 0;
      poseCorrection.xrot = 0;
      poseCorrection.yrot = 0;
      poseCorrection.zrot = 0;
    }
  ulapi_mutex_give(&poseCorrectionMutex);
  return retValue;
}

void KukaThreadArgs::setCartesianMove(CRCLStatus *status)
{
  cartesianMove = true;
  status->setMaxAccel(status->getMaxAccel(MOVE_CARTESIAN), MOVE_DEFAULT);
  status->setMaxVel(status->getMaxVel(MOVE_CARTESIAN), MOVE_DEFAULT);
}

void KukaThreadArgs::setCmdMotorScale(double d1, double d2, double d3,
				      double d4, double d5, double d6)
{
  cmdMotorScale[0] = d1;
  cmdMotorScale[1] = d2;
  cmdMotorScale[2] = d3;
  cmdMotorScale[3] = d4;
  cmdMotorScale[4] = d5;
  cmdMotorScale[5] = d6;
}

void KukaThreadArgs::setCurrentState(KukaState *stateIn)
{
  ulapi_mutex_take(&poseCorrectionMutex);
  currentState = *stateIn;
  ulapi_mutex_give(&poseCorrectionMutex);
}

void KukaThreadArgs::setJointMotorScale(double d1, double d2, double d3,
					double d4, double d5, double d6)
{
  jointMotorScale[0] = d1;
  jointMotorScale[1] = d2;
  jointMotorScale[2] = d3;
  jointMotorScale[3] = d4;
  jointMotorScale[4] = d5;
  jointMotorScale[5] = d6;
}

void KukaThreadArgs::setJointMove(CRCLStatus *status)
{
  cartesianMove = false;
  status->setMaxAccel(status->getMaxAccel(MOVE_JOINT), MOVE_DEFAULT);
  status->setMaxVel(status->getMaxVel(MOVE_JOINT), MOVE_DEFAULT);
}

void KukaThreadArgs::setPoseCorrection(robotPose poseCorrectionIn)
{
  ulapi_mutex_take(&poseCorrectionMutex);
  /*
  printf("Current PoseCorrection: <%f %f %f> New: <%f %f %f>\n",
	 poseCorrection.x,
	 poseCorrection.y,
	 poseCorrection.z,
	 poseCorrectionIn.x,
	 poseCorrectionIn.y,
	 poseCorrectionIn.z);
  */
  poseCorrection = poseCorrectionIn;
  ulapi_mutex_give(&poseCorrectionMutex);
}

void KukaThreadArgs::setToolChangerLocked(bool state)
{
  ulapi_mutex_take(&poseCorrectionMutex);
  lockToolChanger = state;
  ulapi_mutex_give(&poseCorrectionMutex);
}
