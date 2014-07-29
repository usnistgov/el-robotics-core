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
#include "CRCL/kukaThreadArgs.hh"

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
