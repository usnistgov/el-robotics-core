/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced under the GNU Public license
------------------------------------------------------------------------------
*****************************************************************************/
/*!
 *     \file      sensorReturn.hh
 *     \brief     Structure for receiving sensed information on objects.
 *     \author    Stephen Balakirsky, GTRI
 *     \date      07Jan14
 *     \copyright Georgia Tech Research Institute
 */
#ifndef __sensorReturn
#define __sensorReturn

#include "poseInfo.hh"

class SensorReturn{
public:
  SensorReturn(){ valid = 0;};
  int valid;
  std::string name;
  std::string objectClass;
  double time;
  PoseInfo pose;
  double bone[6]; // only used by USARSim
};

#endif
