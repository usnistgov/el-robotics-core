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
#ifndef __crclStatus
#define __crclStatus

#include <ulapi.h>
#include "CRCL/crclDefs.hh"
#include "CRCL/crclUtils.hh"

typedef enum
  {
    MOVE_DEFAULT = 0,
    MOVE_CARTESIAN,
    MOVE_JOINT
  }MovementType;

class CRCLStatus
{
public:
  CRCLStatus();
  CRCLCmdUnion getCurrentCmd();
  CRCLState getCurrentState();
  CRCLCmdStatus getCurrentStatus();
  double getCycleTime();
  GripperStatus getGripperStatus();
  double getMaxAccel(MovementType mType);
  double getMaxVel(MovementType mType);
  RobotStatus getRobotStatus();
  void setCurrentCmd(CRCLCmdUnion *cmdIn);
  void setCurrentState(CRCLState state);
  void setCurrentStatus(CRCLCmdStatus status);
  void setGripperStatus(GripperStatus status);
  void setMaxAccel(double accelIn, MovementType mType);
  void setMaxVel(double velIn, MovementType mType);
  void setRobotStatus(RobotStatus status);
private:
  ulapi_mutex_struct statusMutex;
  CRCLCmdUnion currentCmd;
  CRCLState currentState;
  GripperStatus gripStatus;
  RobotStatus robotStatus;
  double cycleTime;
  double maxAccel[3];
  double maxVel[3];
};
#endif
