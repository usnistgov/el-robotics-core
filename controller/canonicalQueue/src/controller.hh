/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
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
  int dequeueMsgHigh(void *sendTo);
  int dequeueMsgLow(void* sendTo);
private:
  std::deque<CanonicalMsg *> cmdQueueLow;
  std::deque<CanonicalMsg *> cmdQueueHigh;
  int queue_length;
  int processMsg(CanonicalMsg *canonicalPt, void* sendTo);
  CanonicalMsg* getMsg(CanonicalMsg *msgIn);
};
#endif
