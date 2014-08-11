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
 *	\file		crclStatus.cpp
 *	\brief 		status class for CRCL commands
 *	\class		CRCLStatus
 *	\author		Stephen Balakirsky, GTRI
 *	\date		August 05, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include "CRCL/crclStatus.hh"

CRCLStatus::CRCLStatus()
{
  ulapi_mutex_init(&statusMutex, 1);  
  ulapi_mutex_give(&statusMutex);

  ulapi_mutex_take(&statusMutex);

  currentCmd.cmd = CRCL_NOOP;
  currentCmd.status = CRCL_DONE;
  currentState = CRCL_UNINITIALIZED;
  cycleTime = DEFAULT_LOOP_CYCLE;
  maxAccel[MOVE_DEFAULT] = 0;
  maxVel[MOVE_DEFAULT] = 0;
  maxAccel[MOVE_CARTESIAN] = KUKA_DEFAULT_CART_MAX_ACCEL;
  maxVel[MOVE_CARTESIAN] = KUKA_DEFAULT_CART_MAX_VEL;
  maxAccel[MOVE_JOINT] = KUKA_DEFAULT_JOINT_MAX_ACCEL;
  maxVel[MOVE_JOINT] = KUKA_DEFAULT_JOINT_MAX_VEL;


  ulapi_mutex_give(&statusMutex);
}

CRCLCmdUnion CRCLStatus::getCurrentCmd()
{
  CRCLCmdUnion cmd;

  ulapi_mutex_take(&statusMutex);
  cmd = currentCmd;
  ulapi_mutex_give(&statusMutex);
  return cmd;
}

CRCLState CRCLStatus::getCurrentState()
{
  CRCLState retValue;

  ulapi_mutex_take(&statusMutex);
  retValue = currentState;
  ulapi_mutex_give(&statusMutex);
  return retValue;
}

CRCLCmdStatus CRCLStatus::getCurrentStatus()
{
  CRCLCmdStatus retValue;
  
  ulapi_mutex_take(&statusMutex);
  retValue = currentCmd.status;
  ulapi_mutex_give(&statusMutex);
  return retValue;
}

double CRCLStatus::getCycleTime()
{
  double cycleTimeOut;
  ulapi_mutex_take(&statusMutex);
  cycleTimeOut = cycleTime;
  ulapi_mutex_give(&statusMutex);
  return cycleTimeOut;
}

GripperStatus CRCLStatus::getGripperStatus()
{
  GripperStatus retValue;

  ulapi_mutex_take(&statusMutex);
  retValue = gripStatus;
  ulapi_mutex_give(&statusMutex);
  return retValue;
}

double CRCLStatus::getMaxAccel(MovementType mType)
{
  double retValue;

  ulapi_mutex_take(&statusMutex);
  retValue = maxAccel[mType];
  ulapi_mutex_give(&statusMutex);
  return retValue;
}

double CRCLStatus::getMaxVel(MovementType mType)
{
  double retValue;

  ulapi_mutex_take(&statusMutex);
  retValue = maxVel[(int)mType];
  ulapi_mutex_give(&statusMutex);
  return retValue;
}

RobotStatus CRCLStatus::getRobotStatus()
{
  RobotStatus retValue;

  ulapi_mutex_take(&statusMutex);
  retValue = robotStatus;
  ulapi_mutex_give(&statusMutex);
  return retValue;
}

void CRCLStatus::setCurrentCmd(CRCLCmdUnion *cmdIn)
{
  ulapi_mutex_take(&statusMutex);
  crclCmdUnionCopy(cmdIn, &currentCmd, 1);
  ulapi_mutex_give(&statusMutex);
}

void CRCLStatus::setCurrentState(CRCLState state)
{
  ulapi_mutex_take(&statusMutex);
  currentState = state;
  ulapi_mutex_give(&statusMutex);
}
void CRCLStatus::setCurrentStatus(CRCLCmdStatus status)
{
  ulapi_mutex_take(&statusMutex);
  currentCmd.status = status;
  ulapi_mutex_give(&statusMutex);
}

void CRCLStatus::setGripperStatus(GripperStatus status)
{
  ulapi_mutex_take(&statusMutex);
  gripStatus = status;
  ulapi_mutex_give(&statusMutex);
}

void CRCLStatus::setMaxAccel(double accelIn, MovementType mType)
{
  ulapi_mutex_take(&statusMutex);
  maxAccel[mType] = accelIn;
  ulapi_mutex_give(&statusMutex);
}

void CRCLStatus::setMaxVel(double VelIn, MovementType mType)
{
  ulapi_mutex_take(&statusMutex);
  maxVel[mType] = VelIn;
  ulapi_mutex_give(&statusMutex);
}

void CRCLStatus::setRobotStatus(RobotStatus status)
{
  ulapi_mutex_take(&statusMutex);
  robotStatus = status;
  ulapi_mutex_give(&statusMutex);
}
