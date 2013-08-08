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
 *	\file		DatabaseUpdate.h
 *	\brief 		Functions to update the mysql database
 *	\class		DatabaseUpdate
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 30, 2013
 *      \copyright      Georgia Tech Research Institute
 */

#ifndef DATABASEUPDATE_H_
#define DATABASEUPDATE_H_

#include "database/EndEffector.h"
#include "database/Kit.h"
#include "database/Robot.h"
#include "database/PartRefAndPose.h"
#include "database/Point.h"
#include "database/PoseLocation.h"
#include "database/StockKeepingUnit.h"
#include "database/Slot.h"
#include "database/SolidObject.h"
#include "recurseLocation.h"

class DatabaseUpdate{
 public:
  static void graspByRobot( std::string robot, std::string solidObjectName, 
			    Frame referenceFrame );
  static bool matchSlot(Slot *slot, std::string kitName, std::string skuName);
  static void releaseByRobot( std::string robot, std::string solidObjectName, std::string slotName );
};
#endif
