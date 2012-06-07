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
  \file   myController.hh
  \brief  Include file for myController class

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#ifndef __myController
#define __myController

#include "controller.hh"

class MyController:public Controller{
public:
  MyController():Controller(){};
  ~MyController(){};
  int processCloseGripper(CloseGripperMsg *closeGripperMsg);
  int processDwell(DwellMsg *dwellMsg);
  int processEndCanon(EndCanonMsg *endCanonMsg);
  int processInitCanon(InitCanonMsg *initCanonMsg);
  int processMessage(MessageMsg *messageMsg);
  int processMoveSmoothlyTo(MoveSmoothlyToMsg *moveSmoothlyToMsg);
  int processMoveStraightTo(MoveStraightToMsg *moveStraightToMsg);
  int processMoveTo(MoveToMsg *moveToMsg);
  int processOpenGripper(OpenGripperMsg *openGripperMsg);
  int processSetAbsoluteAcceleration(SetAbsoluteAccelerationMsg *setAbsoluteAccelerationMsg);
  int processSetAngleUnits(SetAngleUnitsMsg *setAngleUnitsMsg);
  int processSetEndAngleTolerance(SetEndAngleToleranceMsg *setEndAngleToleranceMsg);
  int processSetEndPointTolerance(SetEndPointToleranceMsg *setEndPointToleranceMsg);
  int processSetIntermediatePointTolerance(SetIntermediatePointToleranceMsg *setIntermediatePointToleranceMsg);
  int processSetLengthUnits(SetLengthUnitsMsg *setLengthUnitsMsg);
  int processSetRelativeAcceleration(SetRelativeAccelerationMsg *setRelativeAccelerationMsg);
  int processSetRelativeSpeed(SetRelativeSpeedMsg *setRelativeSpeedMsg);
};


#endif
