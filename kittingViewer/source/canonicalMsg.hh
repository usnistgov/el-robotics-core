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
#include "Pose.h"
#include <string>

typedef struct
{
  unsigned int msgID; // sequential message number
  double time;        // time message was sent
}CanonicalHdr;

class CanonicalMsg{
public:
  void setHeader()
  { hdr.time = 1.0;
    hdr.msgID = nextID++;
    printf( "setting time: %lf id:%d\n", hdr.time, hdr.msgID);
  }
  int getMsgID(){ return hdr.msgID; }
  double getTime(){ return hdr.time; }
  virtual void process() = 0;
protected:
  static int nextID;
  CanonicalHdr hdr;
};

class CloseGripperMsg:public CanonicalMsg{
public:
  CloseGripperMsg(){}
  ~CloseGripperMsg(){}
  void process();
};

class CloseToolChangerMsg:public CanonicalMsg{
public:
  CloseToolChangerMsg(){}
  ~CloseToolChangerMsg(){}
  void process();
};

class DwellMsg:public CanonicalMsg{
 public:
  DwellMsg(){}
  DwellMsg(double timeIn){ time = timeIn;}
  ~DwellMsg(){}
  void process();
  double time;
};

class EndCanonMsg:public CanonicalMsg{
public:
  EndCanonMsg(){}
  EndCanonMsg(int reasonIn){ reason = reasonIn; }
  ~EndCanonMsg(){}
  void process();
  int reason;
};

class InitCanonMsg:public CanonicalMsg{
public:
  InitCanonMsg(){};
  ~InitCanonMsg(){};
  void process();
};

class MessageMsg:public CanonicalMsg{
public:
  MessageMsg(){}
  MessageMsg(std::string messageIn){ message = messageIn; }
  ~MessageMsg(){}
  void process();
  std::string message;
};

class MoveThroughToMsg:public CanonicalMsg{
public:
  MoveThroughToMsg(){}
  MoveThroughToMsg(Pose ** posesIn, int numIn)
  {
    poses = posesIn;
    num = numIn;
  }
  ~MoveThroughToMsg(){}
  void process();
  Pose ** poses;
  int num;
};

class MoveStraightToMsg:public CanonicalMsg{
public:
  MoveStraightToMsg(){}
  MoveStraightToMsg(Pose * poseIn){ pose = poseIn; }
  ~MoveStraightToMsg(){}
  void process();
  Pose * pose;
};

class MoveToMsg:public CanonicalMsg{
public:
  MoveToMsg(){}
  MoveToMsg(Pose * poseIn){ pose = poseIn; }
  ~MoveToMsg(){}
  void process();
  Pose * pose;
};

class OpenGripperMsg:public CanonicalMsg{
public:
  OpenGripperMsg(){}
  ~OpenGripperMsg(){}
  void process();
};

class OpenToolChangerMsg:public CanonicalMsg{
public:
  OpenToolChangerMsg(){}
  ~OpenToolChangerMsg(){}
  void process();
};

class SetAbsoluteAccelerationMsg:public CanonicalMsg{
public:
  SetAbsoluteAccelerationMsg(){ }
  SetAbsoluteAccelerationMsg(double accelerationIn)
    { acceleration = accelerationIn; }
  ~SetAbsoluteAccelerationMsg(){}
  void process();
  double acceleration;
};

class SetAbsoluteSpeedMsg:public CanonicalMsg{
public:
  SetAbsoluteSpeedMsg(){ }
  SetAbsoluteSpeedMsg(double speedIn)
    { speed = speedIn; }
  ~SetAbsoluteSpeedMsg(){}
  void process();
  double speed;
};

class SetAngleUnitsMsg:public CanonicalMsg{
public:
  SetAngleUnitsMsg(){}
  SetAngleUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; }
  ~SetAngleUnitsMsg(){}
  void process();
  std::string unitName;
};

class SetEndAngleToleranceMsg:public CanonicalMsg{
public:
  SetEndAngleToleranceMsg(){}
  SetEndAngleToleranceMsg(double toleranceIn){ tolerance = toleranceIn; }
  ~SetEndAngleToleranceMsg(){}
  void process();
  double tolerance;
};

class SetEndPointToleranceMsg:public CanonicalMsg{
public:
  SetEndPointToleranceMsg(){}
  SetEndPointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; }
  ~SetEndPointToleranceMsg(){};
  void process();
  double tolerance;
};

class SetIntermediatePointToleranceMsg:public CanonicalMsg{
public:
  SetIntermediatePointToleranceMsg(){}
  SetIntermediatePointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetIntermediatePointToleranceMsg(){};
  void process();
  double tolerance;
};

class SetLengthUnitsMsg:public CanonicalMsg{
public:
  SetLengthUnitsMsg(){}
  SetLengthUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; }
  ~SetLengthUnitsMsg(){};
  void process();
  std::string unitName;
};

class SetRelativeAccelerationMsg:public CanonicalMsg{
public:
  SetRelativeAccelerationMsg(){}
  SetRelativeAccelerationMsg(double percentIn){ percent = percentIn; }
  ~SetRelativeAccelerationMsg(){}
  void process();
  double percent;
};

class SetRelativeSpeedMsg:public CanonicalMsg{
public:
  SetRelativeSpeedMsg(){}
  SetRelativeSpeedMsg(double percentIn){ percent = percentIn; }
  ~SetRelativeSpeedMsg(){}
  void process();
  double percent;
};

class UnreadableMsg:public CanonicalMsg{
public:
  UnreadableMsg(){}
  UnreadableMsg(std::string commandStringIn){ commandString = commandStringIn; }
  ~UnreadableMsg(){}
  void process();
  std::string commandString;
};


#endif
