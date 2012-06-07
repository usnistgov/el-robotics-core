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
  \file   canonicalMsg.hh
  \brief  Provide a generic class to base command processing routines for the canonical robot command language.
  This class will provide virtual routines that may be specialized for individual robot controllers.

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#ifndef __cannonicalMsg
#define __cannonicalMsg
#include <stdio.h>
#include <Pose.h>
#include "ulapi.hh"

enum CanonicalType {
  CloseGripper,
  Dwell,
  EndCanon,
  InitCanon,
  Message,
  MoveSmoothlyTo,
  MoveStraightTo,
  MoveTo,
  OpenGripper,
  SetAbsoluteAcceleration,
  SetAngleUnits,
  SetEndAngleTolerance,
  SetEndPointTolerance,
  SetIntermediatePointTolerance,
  SetLengthUnits,
  SetRelativeAcceleration,
  SetRelativeSpeed
};

typedef struct
{
  CanonicalType msgType; // type of this message
  unsigned int msgID; // sequential message number
  double time;        // time message was sent
}CanonicalHdr;

class CanonicalMsg{
public:
  CanonicalMsg(CanonicalType msgType){ hdr.msgType = msgType; };
  void setHeader(){ hdr.time = ulapi_time(); hdr.msgID = nextID++; printf( "setting time: %lf id:%d\n", hdr.time, hdr.msgID);};
  int getMsgID(){ return hdr.msgID; };
  double getTime(){ return hdr.time; };
  CanonicalType getType(){ return hdr.msgType; };
protected:
  static int nextID;
  CanonicalHdr hdr;
};

class CloseGripperMsg:public CanonicalMsg{
public:
  CloseGripperMsg():CanonicalMsg(CloseGripper){ hdr.msgType = CloseGripper; };
  ~CloseGripperMsg(){};
};

class DwellMsg:public CanonicalMsg{
 public:
  DwellMsg():CanonicalMsg(Dwell){};
  DwellMsg(double timeIn):CanonicalMsg(Dwell){ time = timeIn;};
  ~DwellMsg(){};
  double time;
};

class EndCanonMsg:public CanonicalMsg{
public:
  EndCanonMsg():CanonicalMsg(EndCanon){ };
  EndCanonMsg(int reasonIn):CanonicalMsg(EndCanon){ reason = reasonIn; };
  ~EndCanonMsg(){};
  int reason;
};

class InitCanonMsg:public CanonicalMsg{
public:
  InitCanonMsg():CanonicalMsg(InitCanon){};
  ~InitCanonMsg(){};
};

class MessageMsg:public CanonicalMsg{
public:
  MessageMsg():CanonicalMsg(Message){ };
  MessageMsg(std::string messageIn):CanonicalMsg(Message){ message = messageIn; };
  ~MessageMsg(){};
  std::string message;
};

class MoveSmoothlyToMsg:public CanonicalMsg{
public:
  MoveSmoothlyToMsg():CanonicalMsg(MoveSmoothlyTo){ };
  MoveSmoothlyToMsg(Pose **posesIn, int numIn):CanonicalMsg(MoveSmoothlyTo){ poses = posesIn; num = numIn; };
  ~MoveSmoothlyToMsg(){};
  Pose **poses;
  int num;
};

class MoveStraightToMsg:public CanonicalMsg{
public:
  MoveStraightToMsg():CanonicalMsg(MoveStraightTo){};
  MoveStraightToMsg(Pose *poseIn):CanonicalMsg(MoveStraightTo){  pose = poseIn; };
  ~MoveStraightToMsg(){};
  Pose *pose;
};

class MoveToMsg:public CanonicalMsg{
public:
  MoveToMsg():CanonicalMsg(MoveTo){};
  MoveToMsg(Pose *poseIn):CanonicalMsg(MoveTo){ pose = poseIn; };
  ~MoveToMsg(){};
  Pose *pose;
};

class OpenGripperMsg:public CanonicalMsg{
public:
  OpenGripperMsg():CanonicalMsg(OpenGripper){ };
  ~OpenGripperMsg(){};
};

class SetAbsoluteAccelerationMsg:public CanonicalMsg{
public:
  SetAbsoluteAccelerationMsg():CanonicalMsg(SetAbsoluteAcceleration){ };
  SetAbsoluteAccelerationMsg(double accelerationIn):CanonicalMsg(SetAbsoluteAcceleration){ acceleration = accelerationIn; };
  ~SetAbsoluteAccelerationMsg(){};
  double acceleration;
};

class SetAngleUnitsMsg:public CanonicalMsg{
public:
  SetAngleUnitsMsg():CanonicalMsg(SetAngleUnits){ hdr.msgType = SetAngleUnits; };
  SetAngleUnitsMsg(std::string unitNameIn):CanonicalMsg(SetAngleUnits){ unitName = unitNameIn; };
  ~SetAngleUnitsMsg(){};
  std::string unitName;
};

class SetEndAngleToleranceMsg:public CanonicalMsg{
public:
  SetEndAngleToleranceMsg():CanonicalMsg(SetEndAngleTolerance){ };
  SetEndAngleToleranceMsg(double toleranceIn):CanonicalMsg(SetEndAngleTolerance){ tolerance = toleranceIn; };
  ~SetEndAngleToleranceMsg(){};
  double tolerance;
};

class SetEndPointToleranceMsg:public CanonicalMsg{
public:
  SetEndPointToleranceMsg():CanonicalMsg(SetEndPointTolerance){ };
  SetEndPointToleranceMsg(double toleranceIn):CanonicalMsg(SetEndPointTolerance){ tolerance = toleranceIn; };
  ~SetEndPointToleranceMsg(){};
  double tolerance;
};

class SetIntermediatePointToleranceMsg:public CanonicalMsg{
public:
  SetIntermediatePointToleranceMsg():CanonicalMsg(SetIntermediatePointTolerance){};
  SetIntermediatePointToleranceMsg(double toleranceIn):CanonicalMsg(SetIntermediatePointTolerance){ tolerance = toleranceIn; };
  ~SetIntermediatePointToleranceMsg(){};
  double tolerance;
};

class SetLengthUnitsMsg:public CanonicalMsg{
public:
  SetLengthUnitsMsg():CanonicalMsg(SetLengthUnits){ };
  SetLengthUnitsMsg(std::string unitNameIn):CanonicalMsg(SetLengthUnits){ unitName = unitNameIn; };
  ~SetLengthUnitsMsg(){};
  std::string unitName;
};

class SetRelativeAccelerationMsg:public CanonicalMsg{
public:
  SetRelativeAccelerationMsg():CanonicalMsg(SetRelativeAcceleration){ };
  SetRelativeAccelerationMsg(double percentIn):CanonicalMsg(SetRelativeAcceleration){ percent = percentIn; };
  ~SetRelativeAccelerationMsg(){};
  double percent;
};

class SetRelativeSpeedMsg:public CanonicalMsg{
public:
  SetRelativeSpeedMsg():CanonicalMsg(SetRelativeSpeed){ };
  SetRelativeSpeedMsg(double percentIn):CanonicalMsg(SetRelativeSpeed){ percent = percentIn; };
  ~SetRelativeSpeedMsg(){};
  double percent;
};
#endif
