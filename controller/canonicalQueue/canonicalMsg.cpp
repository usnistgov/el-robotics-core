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
  \file   canonicalMsg.cpp
  \brief  Provide a generic class to base command processing routines for the canonical robot command language.
  This class will provide virtual routines that may be specialized for individual robot controllers.

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include "canonicalMsg.hh"
void StatusMsg::print()
{
  printf( "StatusMsgMsg: msgID: %d time: %f error: %s\n",
	  hdr.msgID, hdr.time, getError() );
}

void StatusMsg::setHeader(CanonicalHdr headerIn)
{
  hdr.time = headerIn.time; 
  hdr.msgID = headerIn.msgID;
}

void StatusMsg::setStatus(statusReturn statusIn)
{
  status = statusIn;
}
statusReturn StatusMsg::getStatus()
{
    return status;
}
CanonicalHdr StatusMsg::getHeader()
{
  return hdr;
}
char *StatusMsg::getError()
{
    switch(status)
      {
      case QueueEmpty:
	return (char*)"QueueEmpty";
	break;
      case QueueError:
	return (char*)"QueueError";
	break;
      case CmdComplete:
	return (char*)"CmdComplete";
	break;
      case CmdError:
	return (char*)"CmdError";
	break;
      case CmdUnknown:
	return (char*)"CmdUnknown";
	break;
      case SystemNoInit:
	return (char*)"SystemNoInit";
	break;
      case SystemDone:
	return (char*)"SystemDone";
	break;
      default:
	return (char*)"UnknownStatus";
      }
    return (char*)"UnknownStatus";
}
