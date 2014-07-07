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
    case CRCL_SET_ABSOLUTE_ACC:
      to->absAcc = from->absAcc;
      break;
    case CRCL_SET_ABSOLUTE_SPEED:
      to->absSpeed = from->absSpeed;
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

