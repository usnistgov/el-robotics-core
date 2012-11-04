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

  switch( msgIn->getType() )
    {
    case CloseGripper:
      closeGripperMsgPt = new CloseGripperMsg();
      *closeGripperMsgPt = *reinterpret_cast<CloseGripperMsg*>(msgIn);
      closeGripperMsgPt->setHeader();
      cmdQueue.push_back((void*)closeGripperMsgPt);
      break;
    case Dwell:
      dwellMsgPt = new DwellMsg();
      *dwellMsgPt = *reinterpret_cast<DwellMsg*>(msgIn);
      dwellMsgPt->setHeader();      
      cmdQueue.push_back((void*)dwellMsgPt);
      break;
    case EndCanon:
      endCanonMsgPt = new EndCanonMsg();
      *endCanonMsgPt = *reinterpret_cast<EndCanonMsg*>(msgIn);
      endCanonMsgPt->setHeader();      
      cmdQueue.push_back((void*)endCanonMsgPt);
      break;
    case InitCanon:
      initCanonMsgPt = new InitCanonMsg();
      *initCanonMsgPt = *reinterpret_cast<InitCanonMsg*>(msgIn);
      initCanonMsgPt->setHeader();      
      cmdQueue.push_back((void*)initCanonMsgPt);
      break;
    case Message:
      messageMsgPt = new MessageMsg();
      *messageMsgPt = *reinterpret_cast<MessageMsg*>(msgIn);
      messageMsgPt->setHeader();      
      cmdQueue.push_back((void*)messageMsgPt);
      break;
    case MoveSmoothlyTo:
      moveSmoothlyToMsgPt = new MoveSmoothlyToMsg();
      *moveSmoothlyToMsgPt = *reinterpret_cast<MoveSmoothlyToMsg*>(msgIn);
      moveSmoothlyToMsgPt->setHeader();      
      cmdQueue.push_back((void*)moveSmoothlyToMsgPt);
      break;
    case MoveStraightTo:
      moveStraightToMsgPt = new MoveStraightToMsg();
      *moveStraightToMsgPt = *reinterpret_cast<MoveStraightToMsg*>(msgIn);
      moveStraightToMsgPt->setHeader();      
      cmdQueue.push_back((void*)moveStraightToMsgPt);
      break;
    case MoveTo:
      moveToMsgPt = new MoveToMsg();
      *moveToMsgPt = *reinterpret_cast<MoveToMsg*>(msgIn);
      moveToMsgPt->setHeader();      
      cmdQueue.push_back((void*)moveToMsgPt);
      break;
    case OpenGripper:
      openGripperMsgPt = new OpenGripperMsg();
      *openGripperMsgPt = *reinterpret_cast<OpenGripperMsg*>(msgIn);
      openGripperMsgPt->setHeader();      
      cmdQueue.push_back((void*)openGripperMsgPt);
      break;
    case SetAbsoluteAcceleration:
      setAbsoluteAccelerationMsgPt = new SetAbsoluteAccelerationMsg();
      *setAbsoluteAccelerationMsgPt = *reinterpret_cast<SetAbsoluteAccelerationMsg*>(msgIn);
      setAbsoluteAccelerationMsgPt->setHeader();      
      cmdQueue.push_back((void*)setAbsoluteAccelerationMsgPt);
      break;
    case SetAngleUnits:
      setAngleUnitsMsgPt = new SetAngleUnitsMsg();
      *setAngleUnitsMsgPt = *reinterpret_cast<SetAngleUnitsMsg*>(msgIn);
      setAngleUnitsMsgPt->setHeader();      
      cmdQueue.push_back((void*)setAngleUnitsMsgPt);
      break;
    case SetEndAngleTolerance:
      setEndAngleToleranceMsgPt = new SetEndAngleToleranceMsg();
      *setEndAngleToleranceMsgPt = *reinterpret_cast<SetEndAngleToleranceMsg*>(msgIn);
      setEndAngleToleranceMsgPt->setHeader();      
      cmdQueue.push_back((void*)setEndAngleToleranceMsgPt);
      break;
    case SetEndPointTolerance:
      setEndPointToleranceMsgPt = new SetEndPointToleranceMsg();
      *setEndPointToleranceMsgPt = *reinterpret_cast<SetEndPointToleranceMsg*>(msgIn);
      setEndPointToleranceMsgPt->setHeader();      
      cmdQueue.push_back((void*)setEndPointToleranceMsgPt);
      break;
    case SetIntermediatePointTolerance:
      setIntermediatePointToleranceMsgPt = new SetIntermediatePointToleranceMsg();
      *setIntermediatePointToleranceMsgPt = *reinterpret_cast<SetIntermediatePointToleranceMsg*>(msgIn);
      setIntermediatePointToleranceMsgPt->setHeader();      
      cmdQueue.push_back((void*)setIntermediatePointToleranceMsgPt);
      break;
    case SetLengthUnits:
      setLengthUnitsMsgPt = new SetLengthUnitsMsg();
      *setLengthUnitsMsgPt = *reinterpret_cast<SetLengthUnitsMsg*>(msgIn);
      setLengthUnitsMsgPt->setHeader();      
      cmdQueue.push_back((void*)setLengthUnitsMsgPt);
      break;
    case SetRelativeAcceleration:
      setRelativeAccelerationMsgPt = new SetRelativeAccelerationMsg();
      *setRelativeAccelerationMsgPt = *reinterpret_cast<SetRelativeAccelerationMsg*>(msgIn);
      setRelativeAccelerationMsgPt->setHeader();      
      cmdQueue.push_back((void*)setRelativeAccelerationMsgPt);
      break;
    case SetRelativeSpeed:
      setRelativeSpeedMsgPt = new SetRelativeSpeedMsg();
      *setRelativeSpeedMsgPt = *reinterpret_cast<SetRelativeSpeedMsg*>(msgIn);
      setRelativeSpeedMsgPt->setHeader();      
      cmdQueue.push_back((void*)setRelativeSpeedMsgPt);
      break;

    default:
      return 0;
    }
  return 1;
}

int Controller::dequeueMsg()
{
  int errReturn = 1;
  void *msgOut;
  CanonicalMsg *canonicalPt;

  //  printf( "In controller dequeue\n" );
  msgOut = cmdQueue.front();
  if( msgOut == NULL )
    {
      printf("Error from dequeueMsg, no more elements\n");
      return 0;
    }
  
  canonicalPt = (CanonicalMsg*)msgOut;
  printf( "Dequeuing msg number: %d from time: %lf\n",
	  canonicalPt->getMsgID(), canonicalPt->getTime() );

  switch( canonicalPt->getType() )
    {
    case CloseGripper:
      processCloseGripper(static_cast<CloseGripperMsg*>(msgOut));
      delete static_cast<CloseGripperMsg*>(msgOut);
      break;
    case Dwell:
      processDwell(static_cast<DwellMsg*>(msgOut));
      delete static_cast<DwellMsg*>(msgOut);
      break;
    case EndCanon:
      processEndCanon(static_cast<EndCanonMsg*>(msgOut));
      delete static_cast<EndCanonMsg*>(msgOut);
      break;
    case InitCanon:
      processInitCanon(static_cast<InitCanonMsg*>(msgOut));
      delete static_cast<InitCanonMsg*>(msgOut);
      break;
    case Message:
      processMessage(static_cast<MessageMsg*>(msgOut));
      delete static_cast<MessageMsg*>(msgOut);
      break;
    case MoveSmoothlyTo:
      processMoveSmoothlyTo(static_cast<MoveSmoothlyToMsg*>(msgOut));
      delete static_cast<MoveSmoothlyToMsg*>(msgOut);
      break;
    case MoveStraightTo:
      processMoveStraightTo(static_cast<MoveStraightToMsg*>(msgOut));
      delete static_cast<MoveStraightToMsg*>(msgOut);
      break;
    case MoveTo:
      processMoveTo(static_cast<MoveToMsg*>(msgOut));
      delete static_cast<MoveToMsg*>(msgOut);
      break;
    case OpenGripper:
      processOpenGripper(static_cast<OpenGripperMsg*>(msgOut));
      delete static_cast<OpenGripperMsg*>(msgOut);
      break;
    case SetAbsoluteAcceleration:
      processSetAbsoluteAcceleration(static_cast<SetAbsoluteAccelerationMsg*>(msgOut));
      delete static_cast<SetAbsoluteAccelerationMsg*>(msgOut);
      break;
    case SetAngleUnits:
      processSetAngleUnits(static_cast<SetAngleUnitsMsg*>(msgOut));
      delete static_cast<SetAngleUnitsMsg*>(msgOut);
      break;
    case SetEndAngleTolerance:
      processSetEndAngleTolerance(static_cast<SetEndAngleToleranceMsg*>(msgOut));
      delete static_cast<SetEndAngleToleranceMsg*>(msgOut);
      break;
    case SetEndPointTolerance:
      processSetEndPointTolerance(static_cast<SetEndPointToleranceMsg*>(msgOut));
      delete static_cast<SetEndPointToleranceMsg*>(msgOut);
      break;
    case SetIntermediatePointTolerance:
      processSetIntermediatePointTolerance(static_cast<SetIntermediatePointToleranceMsg*>(msgOut));
      delete static_cast<SetIntermediatePointToleranceMsg*>(msgOut);
      break;
    case SetLengthUnits:
      processSetLengthUnits(static_cast<SetLengthUnitsMsg*>(msgOut));
      delete static_cast<SetLengthUnitsMsg*>(msgOut);
      break;
    case SetRelativeAcceleration:
      processSetRelativeAcceleration(static_cast<SetRelativeAccelerationMsg*>(msgOut));
      delete static_cast<SetRelativeAccelerationMsg*>(msgOut);
      break;
    case SetRelativeSpeed:
      processSetRelativeSpeed(static_cast<SetRelativeSpeedMsg*>(msgOut));
      delete static_cast<SetRelativeSpeedMsg*>(msgOut);
      break;

    default:
      printf( "Error: unknown message\n" );
      errReturn = 0;
      break;
    }
  cmdQueue.pop_front();
  return errReturn;
}

