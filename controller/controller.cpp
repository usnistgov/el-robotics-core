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
  \file   controller.cc
  \brief  Provide a generic class to base executor controller modules off of.
  This class will provide routines to queue and dequeue commands as well as virtual functions
  for items such as emergency conditions and command handlers.

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include <stdio.h>
#include "controller.hh"

// static int need to live somewhere!
int CanonicalMsg::nextID = 1;

Controller::Controller()
{
  cmdQueueHigh.clear();
  cmdQueueLow.clear();
}

Controller::~Controller()
{
}
int Controller::queueMsgLow(CanonicalMsg *msgIn)
{
	CanonicalMsg* msgPtr = getMsg(msgIn);
	if(msgPtr == NULL)
		return 0;
	cmdQueueLow.push_back(msgPtr);
	return 1;
}
int Controller::queueMsgHigh(CanonicalMsg *msgIn)
{
	CanonicalMsg* msgPtr = getMsg(msgIn);
	if(msgPtr == NULL)
		return 0;
	cmdQueueHigh.push_back(msgPtr);
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
  else
    return NULL;
}
/* returns 1 on error, -1 on empty queue, 0 no error */
int Controller::dequeueMsgHigh(void* sendTo)
{
	int isError = -1;
	CanonicalMsg *canonicalPt;
	if(!cmdQueueHigh.empty())
	{
		canonicalPt = cmdQueueHigh.front();
		if(canonicalPt != NULL)
			isError = processMsg(canonicalPt, sendTo);
		cmdQueueHigh.pop_front();
	}
	//high priority queue is empty
	return isError;
}
/* returns 1 on error, -1 on empty queue, 0 no error */
int Controller::dequeueMsgLow(void* sendTo)
{
    int isError = -1;
	CanonicalMsg *canonicalPt;
	if(!cmdQueueLow.empty())
	{
		canonicalPt = cmdQueueLow.front();
		if(canonicalPt != NULL)
			isError = processMsg(canonicalPt, sendTo);
		cmdQueueLow.pop_front();
	}
	//low priority queue is empty
	return isError;
}
/* returns 1 on error, 0 no error */
int Controller::processMsg(CanonicalMsg *canonicalPt, void *sendTo)
{
  int isError = 0;
  
  printf( "Processing msg number: %d from time: %lf\n",
	  canonicalPt->getMsgID(), canonicalPt->getTime() );

  if (dynamic_cast<CloseGripperMsg *>(canonicalPt))
    {
      isError = dynamic_cast<CloseGripperMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<CloseGripperMsg *>(canonicalPt);
    }
  else if (dynamic_cast<CloseToolChangerMsg *>(canonicalPt))
    {
      isError = dynamic_cast<CloseToolChangerMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<CloseToolChangerMsg *>(canonicalPt);
    }
  else if (dynamic_cast<DwellMsg *>(canonicalPt))
    {
      isError = dynamic_cast<DwellMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<DwellMsg *>(canonicalPt);
    }
  else if (dynamic_cast<EndCanonMsg *>(canonicalPt))
    {
      isError = dynamic_cast<EndCanonMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<EndCanonMsg *>(canonicalPt);
    }
  else if (dynamic_cast<InitCanonMsg *>(canonicalPt))
    {
      isError = dynamic_cast<InitCanonMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<InitCanonMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MessageMsg *>(canonicalPt))
    {
      isError = dynamic_cast<MessageMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MessageMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveStraightToMsg *>(canonicalPt))
    {
      isError = dynamic_cast<MoveStraightToMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MoveStraightToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveThroughToMsg *>(canonicalPt))
    {
      isError = dynamic_cast<MoveThroughToMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MoveThroughToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveToMsg *>(canonicalPt))
    {
      isError = dynamic_cast<MoveToMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<MoveToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<OpenGripperMsg *>(canonicalPt))
    {
      isError = dynamic_cast<OpenGripperMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<OpenGripperMsg *>(canonicalPt);
    }
  else if (dynamic_cast<OpenToolChangerMsg *>(canonicalPt))
    {
      isError = dynamic_cast<OpenToolChangerMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<OpenToolChangerMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetAbsoluteSpeedMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAngleUnitsMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetAngleUnitsMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetAngleUnitsMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetLengthUnitsMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetLengthUnitsMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetLengthUnitsMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt))
    {
      isError = dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt);
    }
  else if (dynamic_cast<StartObjectScanMsg *>(canonicalPt))
    {
      isError = dynamic_cast<StartObjectScanMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<StartObjectScanMsg *>(canonicalPt);
    }
  else if (dynamic_cast<StopMotionMsg *>(canonicalPt))
    {
      isError = dynamic_cast<StopMotionMsg *>(canonicalPt)->process(sendTo);
      delete dynamic_cast<StopMotionMsg *>(canonicalPt);
    }
  else
    {
      printf( "Error: unknown message\n" );
      isError = 1;
    }
  return isError;
}

