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
  cmdQueue.clear();
}

Controller::~Controller()
{
}

int Controller::queueMsg( CanonicalMsg *msgIn )
{
  CloseGripperMsg *closeGripperMsgPt;
  DwellMsg *dwellMsgPt;
  EndCanonMsg *endCanonMsgPt;
  InitCanonMsg *initCanonMsgPt;
  MessageMsg *messageMsgPt;
  MoveSmoothlyToMsg *moveSmoothlyToMsgPt;
  MoveStraightToMsg *moveStraightToMsgPt;
  MoveToMsg *moveToMsgPt;
  OpenGripperMsg *openGripperMsgPt;
  SetAbsoluteAccelerationMsg *setAbsoluteAccelerationMsgPt;
  SetAngleUnitsMsg *setAngleUnitsMsgPt;
  SetEndAngleToleranceMsg *setEndAngleToleranceMsgPt;
  SetEndPointToleranceMsg *setEndPointToleranceMsgPt;
  SetIntermediatePointToleranceMsg *setIntermediatePointToleranceMsgPt;
  SetLengthUnitsMsg *setLengthUnitsMsgPt;
  SetRelativeAccelerationMsg *setRelativeAccelerationMsgPt;
  SetRelativeSpeedMsg *setRelativeSpeedMsgPt;

  msgIn->setHeader();
  if (dynamic_cast<CloseGripperMsg *>(msgIn))
    {
      closeGripperMsgPt = new CloseGripperMsg();
      *closeGripperMsgPt = *dynamic_cast<CloseGripperMsg *>(msgIn); 
      cmdQueue.push_back(closeGripperMsgPt);
    }
  else if (dynamic_cast<DwellMsg *>(msgIn))
    {
      dwellMsgPt = new DwellMsg();
      *dwellMsgPt = *dynamic_cast<DwellMsg *>(msgIn);
      cmdQueue.push_back(dwellMsgPt);
    }
  else if (dynamic_cast<EndCanonMsg *>(msgIn))
    {
      endCanonMsgPt = new EndCanonMsg();
      *endCanonMsgPt = *dynamic_cast<EndCanonMsg *>(msgIn);
      cmdQueue.push_back(endCanonMsgPt);
    }
  else if (dynamic_cast<InitCanonMsg *>(msgIn))
    {
      initCanonMsgPt = new InitCanonMsg();
      *initCanonMsgPt = *dynamic_cast<InitCanonMsg *>(msgIn);
      cmdQueue.push_back(initCanonMsgPt);
    }
  else if (dynamic_cast<MessageMsg *>(msgIn))
    {
      messageMsgPt = new MessageMsg();
      *messageMsgPt = *dynamic_cast<MessageMsg *>(msgIn);
      cmdQueue.push_back(messageMsgPt);
    }
  else if (dynamic_cast<MoveSmoothlyToMsg *>(msgIn))
    {
      moveSmoothlyToMsgPt = new MoveSmoothlyToMsg();
      *moveSmoothlyToMsgPt = *dynamic_cast<MoveSmoothlyToMsg *>(msgIn);
      cmdQueue.push_back(moveSmoothlyToMsgPt);
    }
  else if (dynamic_cast<MoveStraightToMsg*>(msgIn))
    {
      moveStraightToMsgPt = new MoveStraightToMsg();
      *moveStraightToMsgPt = *dynamic_cast<MoveStraightToMsg*>(msgIn);
      cmdQueue.push_back(moveStraightToMsgPt);
    }
  else if (dynamic_cast<MoveToMsg*>(msgIn))
    {
       moveToMsgPt = new MoveToMsg();
       *moveToMsgPt = *dynamic_cast<MoveToMsg*>(msgIn);
       cmdQueue.push_back(moveToMsgPt);
    }
  else if (dynamic_cast<OpenGripperMsg*>(msgIn))
    {
       openGripperMsgPt = new OpenGripperMsg();
       *openGripperMsgPt = *dynamic_cast<OpenGripperMsg*>(msgIn);
       cmdQueue.push_back(openGripperMsgPt);
    }
  else if (dynamic_cast<SetAbsoluteAccelerationMsg*>(msgIn))
    {
       setAbsoluteAccelerationMsgPt = new SetAbsoluteAccelerationMsg();
       *setAbsoluteAccelerationMsgPt = *dynamic_cast<SetAbsoluteAccelerationMsg*>(msgIn);
       cmdQueue.push_back(setAbsoluteAccelerationMsgPt);
    }
  else if (dynamic_cast<SetAngleUnitsMsg*>(msgIn))
    {
      setAngleUnitsMsgPt = new SetAngleUnitsMsg();
      *setAngleUnitsMsgPt = *dynamic_cast<SetAngleUnitsMsg*>(msgIn);
      cmdQueue.push_back(setAngleUnitsMsgPt);
    }
  else if (dynamic_cast<SetEndAngleToleranceMsg*>(msgIn))
    {
       setEndAngleToleranceMsgPt = new SetEndAngleToleranceMsg();
       *setEndAngleToleranceMsgPt = *dynamic_cast<SetEndAngleToleranceMsg*>(msgIn);
       cmdQueue.push_back(setEndAngleToleranceMsgPt);
    }
  else if (dynamic_cast<SetEndPointToleranceMsg*>(msgIn))
    {
       setEndPointToleranceMsgPt = new SetEndPointToleranceMsg();
       *setEndPointToleranceMsgPt = *dynamic_cast<SetEndPointToleranceMsg*>(msgIn);
       cmdQueue.push_back(setEndPointToleranceMsgPt);
    }
  else if (dynamic_cast<SetIntermediatePointToleranceMsg*>(msgIn))
    {
      setIntermediatePointToleranceMsgPt = new SetIntermediatePointToleranceMsg();
      *setIntermediatePointToleranceMsgPt = *dynamic_cast<SetIntermediatePointToleranceMsg*>(msgIn);
      cmdQueue.push_back(setIntermediatePointToleranceMsgPt);
    }
  else if (dynamic_cast<SetLengthUnitsMsg*>(msgIn))
  {
       setLengthUnitsMsgPt = new SetLengthUnitsMsg();
       *setLengthUnitsMsgPt = *dynamic_cast<SetLengthUnitsMsg*>(msgIn);
       cmdQueue.push_back(setLengthUnitsMsgPt);
  }
  else if (dynamic_cast<SetRelativeAccelerationMsg*>(msgIn))
    {
       setRelativeAccelerationMsgPt = new SetRelativeAccelerationMsg();
       *setRelativeAccelerationMsgPt = *dynamic_cast<SetRelativeAccelerationMsg*>(msgIn);
       cmdQueue.push_back(setRelativeAccelerationMsgPt);
    }
  else if (dynamic_cast<SetRelativeSpeedMsg*>(msgIn))
    {
      setRelativeSpeedMsgPt = new SetRelativeSpeedMsg();
      *setRelativeSpeedMsgPt = *dynamic_cast<SetRelativeSpeedMsg*>(msgIn);
      cmdQueue.push_back(setRelativeSpeedMsgPt);
    }
  else
    return 0;
  return 1;
}

int Controller::dequeueMsg()
{
  int errReturn = 1;
  CanonicalMsg *canonicalPt;

  //  printf( "In controller dequeue\n" );
  canonicalPt = cmdQueue.front();
  if( canonicalPt == NULL )
    {
      //      printf("Error from dequeueMsg, no more elements\n");
      return 0;
    }
  
  printf( "Dequeuing msg number: %d from time: %lf\n",
	  canonicalPt->getMsgID(), canonicalPt->getTime() );

  if (dynamic_cast<CloseGripperMsg *>(canonicalPt))
    {
      dynamic_cast<CloseGripperMsg *>(canonicalPt)->process();
      delete dynamic_cast<CloseGripperMsg *>(canonicalPt);
    }
  else if (dynamic_cast<DwellMsg *>(canonicalPt))
    {
      dynamic_cast<DwellMsg *>(canonicalPt)->process();
      delete dynamic_cast<DwellMsg *>(canonicalPt);
    }
  else if (dynamic_cast<EndCanonMsg *>(canonicalPt))
    {
      dynamic_cast<EndCanonMsg *>(canonicalPt)->process();
      delete dynamic_cast<EndCanonMsg *>(canonicalPt);
    }
  else if (dynamic_cast<InitCanonMsg *>(canonicalPt))
    {
      dynamic_cast<InitCanonMsg *>(canonicalPt)->process();
      delete dynamic_cast<InitCanonMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MessageMsg *>(canonicalPt))
    {
      dynamic_cast<MessageMsg *>(canonicalPt)->process();
      delete dynamic_cast<MessageMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveSmoothlyToMsg *>(canonicalPt))
    {
      dynamic_cast<MoveSmoothlyToMsg *>(canonicalPt)->process();
      delete dynamic_cast<MoveSmoothlyToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveStraightToMsg *>(canonicalPt))
    {
      dynamic_cast<MoveStraightToMsg *>(canonicalPt)->process();
      delete dynamic_cast<MoveStraightToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<MoveToMsg *>(canonicalPt))
    {
      dynamic_cast<MoveToMsg *>(canonicalPt)->process();
      delete dynamic_cast<MoveToMsg *>(canonicalPt);
    }
  else if (dynamic_cast<OpenGripperMsg *>(canonicalPt))
    {
      dynamic_cast<OpenGripperMsg *>(canonicalPt)->process();
      delete dynamic_cast<OpenGripperMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt))
    {
      dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetAbsoluteAccelerationMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetAngleUnitsMsg *>(canonicalPt))
    {
      dynamic_cast<SetAngleUnitsMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetAngleUnitsMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt))
    {
      dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetEndAngleToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt))
    {
      dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetEndPointToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt))
    {
      dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetIntermediatePointToleranceMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetLengthUnitsMsg *>(canonicalPt))
    {
      dynamic_cast<SetLengthUnitsMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetLengthUnitsMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt))
    {
      dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetRelativeAccelerationMsg *>(canonicalPt);
    }
  else if (dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt))
    {
      dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt)->process();
      delete dynamic_cast<SetRelativeSpeedMsg *>(canonicalPt);
    }

  else
    {
      printf( "Error: unknown message\n" );
      errReturn = 0;
    }
  cmdQueue.pop_front();
  return errReturn;
}

