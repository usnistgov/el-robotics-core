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
#include <PoseLocation.h>
#include <string>
#include "ulapi.hh"

typedef struct
{
  unsigned int msgID; // sequential message number
  double time;        // time message was sent
}CanonicalHdr;

class CanonicalMsg{
public:
  void setHeader(){ hdr.time = ulapi_time(); hdr.msgID = nextID++; printf( "setting time: %lf id:%d\n", hdr.time, hdr.msgID);};
  int getMsgID(){ return hdr.msgID; };
  double getTime(){ return hdr.time; };
  virtual int process(void *sendTo) = 0;
protected:
  static int nextID;
  CanonicalHdr hdr;
};

class CloseGripperMsg:public CanonicalMsg{
public:
  CloseGripperMsg(){};
  ~CloseGripperMsg(){};
  virtual int process(void *sendTo);
};

class CloseToolChangerMsg:public CanonicalMsg{
public:
  CloseToolChangerMsg(){};
  ~CloseToolChangerMsg(){};
  virtual int process(void *sendTo);
};

class DwellMsg:public CanonicalMsg{
 public:
  DwellMsg(){};
  DwellMsg(double timeIn){ time = timeIn;};
  ~DwellMsg(){};
  virtual int process(void *sendTo);
  double time;
};

class EndCanonMsg:public CanonicalMsg{
public:
  EndCanonMsg(){};
  EndCanonMsg(int reasonIn){ reason = reasonIn; };
  ~EndCanonMsg(){};
  virtual int process(void *sendTo);
  int reason;
};

class InitCanonMsg:public CanonicalMsg{
public:
  InitCanonMsg(){};
  ~InitCanonMsg(){};
  virtual int process(void *sendTo);
};

class MessageMsg:public CanonicalMsg{
public:
  MessageMsg(){};
  MessageMsg(std::string messageIn){ message = messageIn; };
  ~MessageMsg(){};
  virtual int process(void *sendTo);
  std::string message;
};

class MoveStraightToMsg:public CanonicalMsg{
public:
  MoveStraightToMsg(){};
  MoveStraightToMsg(PoseLocation *poseLocationIn){  poseLocation = poseLocationIn; };
  ~MoveStraightToMsg(){};
  virtual int process(void *sendTo);
  PoseLocation *poseLocation;
};

class MoveThroughToMsg:public CanonicalMsg{
public:
  MoveThroughToMsg(){};
  MoveThroughToMsg(PoseLocation **poseLocationsIn, int numIn){ poseLocations = poseLocationsIn; num = numIn; };
  ~MoveThroughToMsg(){};
  virtual int process(void *sendTo);
  PoseLocation **poseLocations;
  int num;
};

class MoveToMsg:public CanonicalMsg{
public:
  MoveToMsg(){};
  MoveToMsg(PoseLocation *poseLocationIn){ poseLocation = poseLocationIn; };
  ~MoveToMsg(){};
  virtual int process(void *sendTo);
  PoseLocation *poseLocation;
};

class OpenGripperMsg:public CanonicalMsg{
public:
  OpenGripperMsg(){};
  ~OpenGripperMsg(){};
  virtual int process(void *sendTo);
};

class OpenToolChangerMsg:public CanonicalMsg{
public:
  OpenToolChangerMsg(){};
  ~OpenToolChangerMsg(){};
  virtual int process(void *sendTo);
};

class SetAbsoluteAccelerationMsg:public CanonicalMsg{
public:
  SetAbsoluteAccelerationMsg(){};
  SetAbsoluteAccelerationMsg(double accelerationIn){ acceleration = accelerationIn; };
  ~SetAbsoluteAccelerationMsg(){};
  virtual int process(void *sendTo);
  double acceleration;
};

class SetAbsoluteSpeedMsg:public CanonicalMsg{
public:
  SetAbsoluteSpeedMsg(){};
  SetAbsoluteSpeedMsg(double speedIn){ speed = speedIn; };
  ~SetAbsoluteSpeedMsg(){};
  virtual int process(void *sendTo);
  double speed;
};

class SetAngleUnitsMsg:public CanonicalMsg{
public:
  SetAngleUnitsMsg(){};
  SetAngleUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; };
  ~SetAngleUnitsMsg(){};
  virtual int process(void *sendTo);
  std::string unitName;
};

class SetEndAngleToleranceMsg:public CanonicalMsg{
public:
  SetEndAngleToleranceMsg(){};
  SetEndAngleToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetEndAngleToleranceMsg(){};
  virtual int process(void *sendTo);
  double tolerance;
};

class SetEndPointToleranceMsg:public CanonicalMsg{
public:
  SetEndPointToleranceMsg(){};
  SetEndPointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetEndPointToleranceMsg(){};
  virtual int process(void *sendTo);
  double tolerance;
};

class SetIntermediatePointToleranceMsg:public CanonicalMsg{
public:
  SetIntermediatePointToleranceMsg(){};
  SetIntermediatePointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetIntermediatePointToleranceMsg(){};
  virtual int process(void *sendTo);
  double tolerance;
};

class SetLengthUnitsMsg:public CanonicalMsg{
public:
  SetLengthUnitsMsg(){};
  SetLengthUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; };
  ~SetLengthUnitsMsg(){};
  virtual int process(void *sendTo);
  std::string unitName;
};

class SetRelativeAccelerationMsg:public CanonicalMsg{
public:
  SetRelativeAccelerationMsg(){};
  SetRelativeAccelerationMsg(double percentIn){ percent = percentIn; };
  ~SetRelativeAccelerationMsg(){};
  virtual int process(void *sendTo);
  double percent;
};

class SetRelativeSpeedMsg:public CanonicalMsg{
public:
  SetRelativeSpeedMsg(){};
  SetRelativeSpeedMsg(double percentIn){ percent = percentIn; };
  ~SetRelativeSpeedMsg(){};
  virtual int process(void *sendTo);
  double percent;
};

class StartObjectScanMsg:public CanonicalMsg{
public:
  StartObjectScanMsg(){};
  StartObjectScanMsg(std::string objectNameIn){objectName = objectNameIn; };
  ~StartObjectScanMsg(){};
  virtual int process(void* sendTo);
  std::string objectName;
};

class StopMotionMsg:public CanonicalMsg{
public:
  StopMotionMsg(){};
  StopMotionMsg(int isEmergencyIn){ isEmergency = isEmergencyIn; };
  ~StopMotionMsg(){};
  virtual int process(void *sendTo);
  int isEmergency;
};

class StopObjectScanMsg:public CanonicalMsg{
public:
  StopObjectScanMsg(){};
  ~StopObjectScanMsg(){};
  virtual int process(void* sendTo);
};


#endif
