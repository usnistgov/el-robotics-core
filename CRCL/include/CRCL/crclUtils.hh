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
 *	\file		crclUtils.hh
 *	\brief 		utils for use with CRCL commands and servers
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 07, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#ifndef __crclUtils
#define __crclUtils
#include "CRCL/crclDefs.hh"
bool crclCmdUnionCopy(CRCLCmdUnion *from, CRCLCmdUnion *to, bool setDone);
#endif

