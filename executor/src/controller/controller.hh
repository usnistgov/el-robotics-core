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
  int queueMsg( CanonicalMsg *msgIn );
  int queueCloseGripper(CloseGripperMsg closeGripperMsg);
  int queueDwell(DwellMsg dwellMsg);
  int dequeueMsg();
  virtual int processCloseGripper(CloseGripperMsg *closeGripperMsg) = 0;
  virtual int processDwell(DwellMsg *dwellMsg)= 0;
  virtual int processEndCanon(EndCanonMsg *endCanonMsg)= 0;
  virtual int processInitCanon(InitCanonMsg *initCanonMsg)= 0;
  virtual int processMessage(MessageMsg *messageMsg)= 0;
  virtual int processMoveSmoothlyTo(MoveSmoothlyToMsg *moveSmoothlyToMsg)= 0;
  virtual int processMoveStraightTo(MoveStraightToMsg *moveStraightToMsg)= 0;
  virtual int processMoveTo(MoveToMsg *moveToMsg)= 0;
  virtual int processOpenGripper(OpenGripperMsg *openGripperMsg)= 0;
  virtual int processSetAbsoluteAcceleration(SetAbsoluteAccelerationMsg *setAbsoluteAccelerationMsg)= 0;
  virtual int processSetAngleUnits(SetAngleUnitsMsg *setAngleUnitsMsg)= 0;
  virtual int processSetEndAngleTolerance(SetEndAngleToleranceMsg *setEndAngleToleranceMsg)= 0;
  virtual int processSetEndPointTolerance(SetEndPointToleranceMsg *setEndPointToleranceMsg)= 0;
  virtual int processSetIntermediatePointTolerance(SetIntermediatePointToleranceMsg *setIntermediatePointToleranceMsg)= 0;
  virtual int processSetLengthUnits(SetLengthUnitsMsg *setLengthUnitsMsg)= 0;
  virtual int processSetRelativeAcceleration(SetRelativeAccelerationMsg *setRelativeAccelerationMsg)= 0;
  virtual int processSetRelativeSpeed(SetRelativeSpeedMsg *setRelativeSpeedMsg)= 0;
private:
  std::deque<void*> cmdQueue;
  int queue_length;
};
#endif
