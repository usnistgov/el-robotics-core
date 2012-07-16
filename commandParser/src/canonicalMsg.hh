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
//TK#include <PoseLocation.h>
#include "Pose.h" //TK
#include <string>
//TK#include "ulapi.hh"

//TKtypedef struct
//TK{
//TK  unsigned int msgID; // sequential message number
//TK  double time;        // time message was sent
//TK}CanonicalHdr;

class CanonicalMsg{
public:
//TK  void setHeader(){ hdr.time = ulapi_time(); hdr.msgID = nextID++; printf( "setting time: %lf id:%d\n", hdr.time, hdr.msgID);};
//TK  int getMsgID(){ return hdr.msgID; };
//TK  double getTime(){ return hdr.time; };
  virtual void process(void *sendTo) = 0;
protected:
//TK  static int nextID;
//TK  CanonicalHdr hdr;
};

class CloseGripperMsg:public CanonicalMsg{
public:
  CloseGripperMsg(){};
  ~CloseGripperMsg(){};
  virtual void process(void *sendTo);
};

class CloseToolChangerMsg:public CanonicalMsg{
public:
  CloseToolChangerMsg(){};
  ~CloseToolChangerMsg(){};
  virtual void process(void *sendTo);
};

class DwellMsg:public CanonicalMsg{
 public:
  DwellMsg(){};
  DwellMsg(double timeIn){ time = timeIn;};
  ~DwellMsg(){};
  virtual void process(void *sendTo);
  double time;
};

class EndCanonMsg:public CanonicalMsg{
public:
  EndCanonMsg(){};
  EndCanonMsg(int reasonIn){ reason = reasonIn; };
  ~EndCanonMsg(){};
  virtual void process(void *sendTo);
  int reason;
};

class InitCanonMsg:public CanonicalMsg{
public:
  InitCanonMsg(){};
  ~InitCanonMsg(){};
  virtual void process(void *sendTo);
};

class MessageMsg:public CanonicalMsg{
public:
  MessageMsg(){};
  MessageMsg(std::string messageIn){ message = messageIn; };
  ~MessageMsg(){};
  virtual void process(void *sendTo);
  std::string message;
};

class MoveStraightToMsg:public CanonicalMsg{
public:
  MoveStraightToMsg(){};
  //TK  MoveStraightToMsg(PoseLocation *poseLocationIn){  poseLocation = poseLocationIn; };
  MoveStraightToMsg(Pose * poseIn){ pose = poseIn; } //TK
  ~MoveStraightToMsg(){};
  virtual void process(void *sendTo);
  //TK PoseLocation *poseLocation;
  Pose * pose; //TK
};

class MoveThroughToMsg:public CanonicalMsg{
public:
  MoveThroughToMsg(){};
  //TK  MoveThroughToMsg(PoseLocation **poseLocationsIn, int numIn){ poseLocations = poseLocationsIn; num = numIn; };
  MoveThroughToMsg(Pose ** posesIn, int numIn){poses = posesIn; num = numIn;} //TK
   ~MoveThroughToMsg(){};
  virtual void process(void *sendTo);
  //TK PoseLocation **poseLocations;
  Pose ** poses; //TK
   int num;
};

class MoveToMsg:public CanonicalMsg{
public:
  MoveToMsg(){};
  //TK MoveToMsg(PoseLocation *poseLocationIn){ poseLocation = poseLocationIn; };
  MoveToMsg(Pose * poseIn){ pose = poseIn; }  //TK
   ~MoveToMsg(){};
  virtual void process(void *sendTo);
  //TK PoseLocation *poseLocation;
  Pose * pose; //TK
};

class OpenGripperMsg:public CanonicalMsg{
public:
  OpenGripperMsg(){};
  ~OpenGripperMsg(){};
  virtual void process(void *sendTo);
};

class OpenToolChangerMsg:public CanonicalMsg{
public:
  OpenToolChangerMsg(){};
  ~OpenToolChangerMsg(){};
  virtual void process(void *sendTo);
};

class SetAbsoluteAccelerationMsg:public CanonicalMsg{
public:
  SetAbsoluteAccelerationMsg(){};
  SetAbsoluteAccelerationMsg(double accelerationIn){ acceleration = accelerationIn; };
  ~SetAbsoluteAccelerationMsg(){};
  virtual void process(void *sendTo);
  double acceleration;
};

class SetAbsoluteSpeedMsg:public CanonicalMsg{
public:
  SetAbsoluteSpeedMsg(){};
  SetAbsoluteSpeedMsg(double speedIn){ speed = speedIn; };
  ~SetAbsoluteSpeedMsg(){};
  virtual void process(void *sendTo);
  double speed;
};

class SetAngleUnitsMsg:public CanonicalMsg{
public:
  SetAngleUnitsMsg(){};
  SetAngleUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; };
  ~SetAngleUnitsMsg(){};
  virtual void process(void *sendTo);
  std::string unitName;
};

class SetEndAngleToleranceMsg:public CanonicalMsg{
public:
  SetEndAngleToleranceMsg(){};
  SetEndAngleToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetEndAngleToleranceMsg(){};
  virtual void process(void *sendTo);
  double tolerance;
};

class SetEndPointToleranceMsg:public CanonicalMsg{
public:
  SetEndPointToleranceMsg(){};
  SetEndPointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetEndPointToleranceMsg(){};
  virtual void process(void *sendTo);
  double tolerance;
};

class SetIntermediatePointToleranceMsg:public CanonicalMsg{
public:
  SetIntermediatePointToleranceMsg(){};
  SetIntermediatePointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetIntermediatePointToleranceMsg(){};
  virtual void process(void *sendTo);
  double tolerance;
};

class SetLengthUnitsMsg:public CanonicalMsg{
public:
  SetLengthUnitsMsg(){};
  SetLengthUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; };
  ~SetLengthUnitsMsg(){};
  virtual void process(void *sendTo);
  std::string unitName;
};

class SetRelativeAccelerationMsg:public CanonicalMsg{
public:
  SetRelativeAccelerationMsg(){};
  SetRelativeAccelerationMsg(double percentIn){ percent = percentIn; };
  ~SetRelativeAccelerationMsg(){};
  virtual void process(void *sendTo);
  double percent;
};

class SetRelativeSpeedMsg:public CanonicalMsg{
public:
  SetRelativeSpeedMsg(){};
  SetRelativeSpeedMsg(double percentIn){ percent = percentIn; };
  ~SetRelativeSpeedMsg(){};
  virtual void process(void *sendTo);
  double percent;
};
#endif
