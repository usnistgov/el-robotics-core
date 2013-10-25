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
  \file   controller.cc
  \brief  Provide a generic class to base executor controller modules off of.
  This class will provide routines to queue and dequeue commands as well as virtual functions
  for items such as emergency conditions and command handlers.

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include <stdio.h>
#include "controller.hh"

// static int needs to live somewhere!
int CanonicalMsg::nextID = 1;

Controller::Controller()
{
  cmdQueueHigh.clear();
  cmdQueueLow.clear();
  if (ULAPI_OK != ulapi_init (UL_USE_DEFAULT))
    {
      printf ("can't initialize ulapi");
      exit(1);
    }
  statusMsgMutex = ulapi_mutex_new(0);
  lowHighMsgMutex = ulapi_mutex_new(0);
  verbosity = 1;
}

Controller::~Controller()
{
}

void Controller::setVerbosity( int verbosityIn )
{
  verbosity = verbosityIn;
}

/*
 * returns the id of the message that was queued. This value is unique.
 */
int Controller::queueMsgLow(CanonicalMsg *msgIn)
{
  CanonicalMsg* msgPtr = getMsg(msgIn);
  if(msgPtr == NULL)
    return 0;
  ulapi_mutex_give(lowHighMsgMutex);
  cmdQueueLow.push_back(msgPtr);
  return msgPtr->getMsgID();
}

/*
 * returns the id of the message that was queued. This value is unique.
 */
int Controller::queueMsgHigh(CanonicalMsg *msgIn)
{
  CanonicalMsg* msgPtr = getMsg(msgIn);
  if(msgPtr == NULL)
    return 0;
  ulapi_mutex_give(lowHighMsgMutex);
  ulapi_mutex_give(statusMsgMutex);  // give status mutex to unblock if waiting 
                                     // on a status queue when a high message comes in

  cmdQueueHigh.push_back(msgPtr);
  return msgPtr->getMsgID();

}
int Controller::queueMsgStatus( StatusMsg *msgIn )
{
  statusQueue.push_back(*msgIn);
  if(msgIn == NULL)
    return 0;
  ulapi_mutex_give(statusMsgMutex);
  return 1;
}
CanonicalMsg* Controller::getMsg( CanonicalMsg *msgIn )
{
  CloseGripperMsg *closeGripperMsgPt;
  CloseToolChangerMsg *closeToolChangerMsgPt;
  DwellMsg *dwellMsgPt;
  EndCanonMsg *endCanonMsgPt;
  InitCanonMsg *initCanonMsgPt;
  MessageMsg *messageMsgPt;
  MoveStraightToMsg *moveStraightToMsgPt;
  MoveThroughToMsg *moveThroughToMsgPt;
  MoveToMsg *moveToMsgPt;
  OpenGripperMsg *openGripperMsgPt;
  OpenToolChangerMsg *openToolChangerMsgPt;
  SetAbsoluteAccelerationMsg *setAbsoluteAccelerationMsgPt;
  SetAbsoluteSpeedMsg *setAbsoluteSpeedMsgPt;
  SetAngleUnitsMsg *setAngleUnitsMsgPt;
  SetEndAngleToleranceMsg *setEndAngleToleranceMsgPt;
  SetEndPointToleranceMsg *setEndPointToleranceMsgPt;
  SetIntermediatePointToleranceMsg *setIntermediatePointToleranceMsgPt;
  SetLengthUnitsMsg *setLengthUnitsMsgPt;
  SetRelativeAccelerationMsg *setRelativeAccelerationMsgPt;
  SetRelativeSpeedMsg *setRelativeSpeedMsgPt;
  StartObjectScanMsg *startObjectScanMsgPt;
  StopMotionMsg *stopMotionMsgPt;
  StopObjectScanMsg *stopObjectScanMsgPt;

  msgIn->setHeader();
  if (dynamic_cast<CloseGripperMsg *>(msgIn))
    {
      closeGripperMsgPt = new CloseGripperMsg();
      *closeGripperMsgPt = *dynamic_cast<CloseGripperMsg *>(msgIn); 
      return closeGripperMsgPt;
    }
  else if (dynamic_cast<CloseToolChangerMsg *>(msgIn))
    {
      closeToolChangerMsgPt = new CloseToolChangerMsg();
      *closeToolChangerMsgPt = *dynamic_cast<CloseToolChangerMsg *>(msgIn); 
      return closeToolChangerMsgPt;
    }
  else if (dynamic_cast<DwellMsg *>(msgIn))
    {
      dwellMsgPt = new DwellMsg();
      *dwellMsgPt = *dynamic_cast<DwellMsg *>(msgIn);
      return dwellMsgPt;
    }
  else if (dynamic_cast<EndCanonMsg *>(msgIn))
    {
      endCanonMsgPt = new EndCanonMsg();
      *endCanonMsgPt = *dynamic_cast<EndCanonMsg *>(msgIn);
      return endCanonMsgPt;
    }
  else if (dynamic_cast<InitCanonMsg *>(msgIn))
    {
      initCanonMsgPt = new InitCanonMsg();
      *initCanonMsgPt = *dynamic_cast<InitCanonMsg *>(msgIn);
      return initCanonMsgPt;
    }
  else if (dynamic_cast<MessageMsg *>(msgIn))
    {
      messageMsgPt = new MessageMsg();
      *messageMsgPt = *dynamic_cast<MessageMsg *>(msgIn);
      return messageMsgPt;
    }
  else if (dynamic_cast<MoveStraightToMsg*>(msgIn))
    {
      moveStraightToMsgPt = new MoveStraightToMsg();
      *moveStraightToMsgPt = *dynamic_cast<MoveStraightToMsg*>(msgIn);
      return moveStraightToMsgPt;
    }
  else if (dynamic_cast<MoveThroughToMsg *>(msgIn))
    {
      moveThroughToMsgPt = new MoveThroughToMsg();
      *moveThroughToMsgPt = *dynamic_cast<MoveThroughToMsg *>(msgIn);
      return moveThroughToMsgPt;
    }
  else if (dynamic_cast<MoveToMsg*>(msgIn))
    {
      moveToMsgPt = new MoveToMsg();
      *moveToMsgPt = *dynamic_cast<MoveToMsg*>(msgIn);
      return moveToMsgPt;
    }
  else if (dynamic_cast<OpenGripperMsg*>(msgIn))
    {
      openGripperMsgPt = new OpenGripperMsg();
      *openGripperMsgPt = *dynamic_cast<OpenGripperMsg*>(msgIn);
      return openGripperMsgPt;
    }
  else if (dynamic_cast<OpenToolChangerMsg*>(msgIn))
    {
      openToolChangerMsgPt = new OpenToolChangerMsg();
      *openToolChangerMsgPt = *dynamic_cast<OpenToolChangerMsg*>(msgIn);
      return openToolChangerMsgPt;
    }
  else if (dynamic_cast<SetAbsoluteAccelerationMsg*>(msgIn))
    {
      setAbsoluteAccelerationMsgPt = new SetAbsoluteAccelerationMsg();
      *setAbsoluteAccelerationMsgPt = *dynamic_cast<SetAbsoluteAccelerationMsg*>(msgIn);
      return setAbsoluteAccelerationMsgPt;
    }
  else if (dynamic_cast<SetAbsoluteSpeedMsg*>(msgIn))
    {
      setAbsoluteSpeedMsgPt = new SetAbsoluteSpeedMsg();
      *setAbsoluteSpeedMsgPt = *dynamic_cast<SetAbsoluteSpeedMsg*>(msgIn);
      return setAbsoluteSpeedMsgPt;
    }
  else if (dynamic_cast<SetAngleUnitsMsg*>(msgIn))
    {
      setAngleUnitsMsgPt = new SetAngleUnitsMsg();
      *setAngleUnitsMsgPt = *dynamic_cast<SetAngleUnitsMsg*>(msgIn);
      return setAngleUnitsMsgPt;
    }
  else if (dynamic_cast<SetEndAngleToleranceMsg*>(msgIn))
    {
      setEndAngleToleranceMsgPt = new SetEndAngleToleranceMsg();
      *setEndAngleToleranceMsgPt = *dynamic_cast<SetEndAngleToleranceMsg*>(msgIn);
      return setEndAngleToleranceMsgPt;
    }
  else if (dynamic_cast<SetEndPointToleranceMsg*>(msgIn))
    {
      setEndPointToleranceMsgPt = new SetEndPointToleranceMsg();
      *setEndPointToleranceMsgPt = *dynamic_cast<SetEndPointToleranceMsg*>(msgIn);
      return setEndPointToleranceMsgPt;
    }
  else if (dynamic_cast<SetIntermediatePointToleranceMsg*>(msgIn))
    {
      setIntermediatePointToleranceMsgPt = new SetIntermediatePointToleranceMsg();
      *setIntermediatePointToleranceMsgPt = *dynamic_cast<SetIntermediatePointToleranceMsg*>(msgIn);
      return setIntermediatePointToleranceMsgPt;
    }
  else if (dynamic_cast<SetLengthUnitsMsg*>(msgIn))
    {
      setLengthUnitsMsgPt = new SetLengthUnitsMsg();
      *setLengthUnitsMsgPt = *dynamic_cast<SetLengthUnitsMsg*>(msgIn);
      return setLengthUnitsMsgPt;
    }
  else if (dynamic_cast<SetRelativeAccelerationMsg*>(msgIn))
    {
      setRelativeAccelerationMsgPt = new SetRelativeAccelerationMsg();
      *setRelativeAccelerationMsgPt = *dynamic_cast<SetRelativeAccelerationMsg*>(msgIn);
      return setRelativeAccelerationMsgPt;
    }
  else if (dynamic_cast<SetRelativeSpeedMsg*>(msgIn))
    {
      setRelativeSpeedMsgPt = new SetRelativeSpeedMsg();
      *setRelativeSpeedMsgPt = *dynamic_cast<SetRelativeSpeedMsg*>(msgIn);
      return setRelativeSpeedMsgPt;
    }
  else if (dynamic_cast<StartObjectScanMsg*>(msgIn))
    {
      startObjectScanMsgPt = new StartObjectScanMsg();
      *startObjectScanMsgPt = *dynamic_cast<StartObjectScanMsg*>(msgIn);
      return startObjectScanMsgPt;
    }
  else if (dynamic_cast<StopMotionMsg*>(msgIn))
    {
      stopMotionMsgPt = new StopMotionMsg();
      *stopMotionMsgPt = *dynamic_cast<StopMotionMsg*>(msgIn);
      return stopMotionMsgPt;
    }
  else if (dynamic_cast<StopObjectScanMsg*>(msgIn))
    {
      stopObjectScanMsgPt = new StopObjectScanMsg();
      *stopObjectScanMsgPt = *dynamic_cast<StopObjectScanMsg*>(msgIn);
      return stopObjectScanMsgPt;
    }
  else
    return NULL;
}
/* returns status structure */
/*! 
  \brief Grabs message off of high-priority message queue
  \param sendTo - a RosInf structure from the file rosInf.hh
  \param wait - automatically set to 0 which causes the system 
                to not block on an empty queue. To block, set this
		to be 1.
  \returns - StatusMsg that represents the result of the query.
 */
StatusMsg Controller::dequeueMsgHigh(void* sendTo, int wait)
{
  StatusMsg statusMsg;
  CanonicalMsg *canonicalPt;
  statusMsg.setStatus(QueueEmpty);
  if(wait)
    {
      if(cmdQueueHigh.empty()) // need to wait
	{
	  ulapi_mutex_take(lowHighMsgMutex); // take mutex
	}
    }

  if(!cmdQueueHigh.empty())
    {
      canonicalPt = cmdQueueHigh.front();
      if(canonicalPt != NULL)
	statusMsg.setStatus(processMsg(canonicalPt, sendTo));
      cmdQueueHigh.pop_front();
      statusMsg.setHeader(canonicalPt->getHeader());
    }
  //high priority queue is empty
  return statusMsg;
}

/*! 
  \brief Grabs message off of low-priority message queue
  \param sendTo - a RosInf structure from the file rosInf.hh
  \param wait - automatically set to 1 which causes the system 
                to block on an empty queue. To block, set this
		to be 1.
  \returns - StatusMsg that represents the result of the query.
*/
StatusMsg Controller::dequeueMsgLow(void* sendTo, int wait)
{
  StatusMsg statusMsg;
  CanonicalMsg *canonicalPt;
  statusMsg.setStatus(QueueEmpty);

  printf( "in controller.cpp:dequeueMsgLow with wait %d\n", wait );
  if(wait)
    {
      if(cmdQueueLow.empty()) // need to wait
	{
	  ulapi_mutex_take(lowHighMsgMutex); // take mutex
	}
    }
	
  if(!cmdQueueLow.empty())
    {
      canonicalPt = cmdQueueLow.front();
      if(canonicalPt != NULL)
	statusMsg.setStatus(processMsg(canonicalPt, sendTo));
      cmdQueueLow.pop_front();
      statusMsg.setHeader(canonicalPt->getHeader());
    }
  //low priority queue is empty
  return statusMsg;
}

/*! 
  \brief Grabs message off of status message queue
  \param wait - automatically set to 1 which causes the system 
                to block on an empty queue. To block, set this
		to be 1.
  \returns - StatusMsg that represents the result of the query.
*/
StatusMsg Controller::dequeueMsgStatus(int wait)
{
  int isError = -1;
  CanonicalHdr header;
  StatusMsg statusReturn;

  if(wait)
    {
      if(statusQueue.empty()) // need to wait
	{
	  ulapi_mutex_take(statusMsgMutex); // take mutex
	}
    }
  if(!statusQueue.empty())
    {
      statusReturn = statusQueue.front();
      statusQueue.pop_front();
      return statusReturn;
    }

  //status queue is empty
  header.msgID = -1;
  header.time = 0;
  statusReturn.setStatus(QueueEmpty);
  statusReturn.setHeader(header);
  return statusReturn;
}
/* returns 1 on error, 0 no error */
statusReturn Controller::processMsg(CanonicalMsg *canonicalPt, void *sendTo)
{
  statusReturn isError = CmdComplete;

  /*  
  printf( "controller.cpp::processMsg:Processing msg number: %d from time: %lf\n",
	  canonicalPt->getMsgID(), canonicalPt->getTime() );
  */

  if (dynamic_cast<CloseGripperMsg *>(canonicalPt))
    {
      dynamic_cast<CloseGripperMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<CloseGripperMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<CloseGripperMsg *>(canonicalPt);
    }
  else if (dynamic_cast<CloseToolChangerMsg *>(canonicalPt))
    {
      dynamic_cast<CloseToolChangerMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<CloseToolChangerMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<CloseToolChangerMsg *>(canonicalPt);
    }
  else if (dynamic_cast<DwellMsg *>(canonicalPt))
    {
      dynamic_cast<DwellMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<DwellMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<DwellMsg *>(canonicalPt);
    }
  else if (dynamic_cast<EndCanonMsg *>(canonicalPt))
    {
      dynamic_cast<EndCanonMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<EndCanonMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<EndCanonMsg *>(canonicalPt);
    }
  else if (dynamic_cast<InitCanonMsg *>(canonicalPt))
    {
      dynamic_cast<InitCanonMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<InitCanonMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<InitCanonMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MessageMsg *>(canonicalPt))
    {
      dynamic_cast<MessageMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<MessageMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MessageMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveStraightToMsg *>(canonicalPt))
    {
      dynamic_cast<MoveStraightToMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<MoveStraightToMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MoveStraightToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveThroughToMsg *>(canonicalPt))
    {
      dynamic_cast<MoveThroughToMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<MoveThroughToMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MoveThroughToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveToMsg *>(canonicalPt))
    {
      dynamic_cast<MoveToMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<MoveToMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MoveToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<OpenGripperMsg *>(canonicalPt))
    {
      dynamic_cast<OpenGripperMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<OpenGripperMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<OpenGripperMsg *>(canonicalPt);
    }
  else if (dynamic_cast<OpenToolChangerMsg *>(canonicalPt))
    {
      dynamic_cast<OpenToolChangerMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<OpenToolChangerMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<OpenToolChangerMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt))
    {
      dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt))
    {
      dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAngleUnitsMsg *>(canonicalPt))
    {
      dynamic_cast<SetAngleUnitsMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetAngleUnitsMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetAngleUnitsMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt))
    {
      dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt))
    {
      dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt))
    {
      dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetLengthUnitsMsg *>(canonicalPt))
    {
      dynamic_cast<SetLengthUnitsMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetLengthUnitsMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetLengthUnitsMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt))
    {
      dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt))
    {
      dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt);
    }
  else if (dynamic_cast<StartObjectScanMsg *>(canonicalPt))
    {
      dynamic_cast<StartObjectScanMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<StartObjectScanMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<StartObjectScanMsg *>(canonicalPt);
    }
  else if (dynamic_cast<StopMotionMsg *>(canonicalPt))
    {
      dynamic_cast<StopMotionMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<StopMotionMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<StopMotionMsg *>(canonicalPt);
    }
  else if (dynamic_cast<StopObjectScanMsg *>(canonicalPt))
    {
      dynamic_cast<StopObjectScanMsg *>(canonicalPt)->printMe(verbosity);
      isError = dynamic_cast<StopObjectScanMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<StopObjectScanMsg *>(canonicalPt);
    }
  else
    {
      printf( "Error: unknown message\n" );
      isError = CmdUnknown;
    }
  return isError;
}

