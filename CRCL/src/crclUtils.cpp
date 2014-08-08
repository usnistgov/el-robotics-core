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
 *	\file		crclUtils.cpp
 *	\brief 		utils for use with CRCL commands and servers
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 07, 2014
 *      \copyright      Georgia Tech Research Institute
 */
////////////////////////////////////////////////////////
#include "CRCL/crclUtils.hh"

/* Copies one CRCLCmdUnion to another and sets the status done flag is necessary
 * returns true on success, false on failure
 * CRCLCmdUnion *from - copy from this location
 * CRCLCmdUnion *to   - copy to this location
 * bool setDone       - should done flag be set
 */
bool crclCmdUnionCopy(CRCLCmdUnion *from, CRCLCmdUnion *to, bool setDone)
{
  to->cmd = from->cmd;
  to->status = from->status;
  switch( from->cmd )
    {
    case CRCL_NOOP:
      break;
    case CRCL_DWELL:
      to->dwell = from->dwell;
      break;
    case CRCL_END_CANON:
      break;
    case CRCL_INIT_CANON:
      break;
    case CRCL_MOVE_TO:
      to->pose = from->pose;
      break;
    case CRCL_SET_MAX_CART_ACC:
      to->absAcc = from->absAcc;
      break;
    case CRCL_SET_MAX_CART_SPEED:
      to->absSpeed = from->absSpeed;
      break;
    case CRCL_SET_MAX_JOINT_ACC:
      to->absAcc = from->absAcc;
      break;
    case CRCL_SET_MAX_JOINT_SPEED:
      to->absSpeed = from->absSpeed;
      break;
    case CRCL_SET_GRIPPER:
      to->gripperPos = from->gripperPos;
      break;
    case CRCL_STOP_MOTION:
      break;
    case CRCL_UNKNOWN:
      break;
    default:
      return false;
      break;
    }
  if( setDone )
    from->status = CRCL_DONE;
  return true;
}

std::string getCRCLCmdString(CRCLCmd input)
{
  switch( input )
    {
    case CRCL_NOOP:
      return "CRCL_NOOP";
      break;
    case CRCL_DWELL:
      return "CRCL_DWELL";
      break;
    case CRCL_END_CANON:
      return "CRCL_END_CANON";
      break;
    case CRCL_INIT_CANON:
      return "CRCL_INIT_CANON";
      break;
    case CRCL_MOVE_JOINT:
      return "CRCL_MOVE_JOINT";
      break;
    case CRCL_MOVE_TO:
      return "CRCL_MOVE_TO";
      break;
    case CRCL_SET_MAX_CART_ACC:
      return "CRCL_SET_MAX_CART_ACC";
      break;
    case CRCL_SET_MAX_CART_SPEED:
      return "CRCL_SET_MAX_CART_SPEED";
      break;
    case CRCL_SET_MAX_JOINT_ACC:
      return "CRCL_SET_MAX_CART_ACC";
      break;
    case CRCL_SET_MAX_JOINT_SPEED:
      return "CRCL_SET_MAX_CART_SPEED";
      break;
    case CRCL_SET_GRIPPER:
      return "CRCL_SET_GRIPPER";
      break;
    case CRCL_STOP_MOTION:
      return "CRCL_STOP_MOTION";
      break;
    case CRCL_UNKNOWN:
      return "CRCL_UNKNOWN";
      break;
    default:
      return "Should not be here in crclUtils\n";
    }
}

std::string getCRCLStatusString(CRCLCmdStatus input)
{
  switch( input )
    {
    case CRCL_DONE:
      return "CRCL_DONE";
      break;
    case CRCL_ABORT:
      return "CRCL_ABORT";
      break;
    case CRCL_NEW_CMD:
      return "CRCL_NEW_CMD";
      break;
    case CRCL_WORKING:
      return "CRCL_WORKING";
      break;
    }
}
