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

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
 *****************************************************************************/
/*!
  \file   controller.hh
  \brief  Provide a generic class to base executor controller modules off of.
  This class will provide routines to queue and dequeue commands as well as virtual functions
  for items such as emergency conditions and command handlers.

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#ifndef __controller
#define __controller
#include <deque>
#include "canonicalMsg.hh"

class Controller
{
public:
  Controller();
  ~Controller();
  int queueMsgLow( CanonicalMsg *msgIn );
  int queueMsgHigh( CanonicalMsg *msgIn );
  int queueMsgStatus( StatusMsg *statusOut );
  StatusMsg dequeueMsgHigh(void *sendTo, int wait=0);
  StatusMsg dequeueMsgLow(void* sendTo, int wait=1);
  StatusMsg dequeueMsgStatus(int wait=1); 
  void setVerbosity( int verbosityIn );
private:
  int verbosity;
  std::deque<CanonicalMsg *> cmdQueueLow;
  std::deque<CanonicalMsg *> cmdQueueHigh;
  std::deque<StatusMsg> statusQueue;
  int queue_length;
  statusReturn processMsg(CanonicalMsg *canonicalPt, void* sendTo);
  CanonicalMsg* getMsg(CanonicalMsg *msgIn);
  void *statusMsgMutex;
  void *lowHighMsgMutex;
};
#endif
