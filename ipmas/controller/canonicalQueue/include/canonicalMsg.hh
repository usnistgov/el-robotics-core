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
  \file   canonicalMsg.hh
  \brief  Provide a generic class to base command processing routines for the canonical robot command language.
  This class will provide virtual routines that may be specialized for individual robot controllers.

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#ifndef __cannonicalMsg
#define __cannonicalMsg
#include <sys/time.h>
#include <stdio.h>
#include "database/PoseLocation.h"
#include <string>
#include "ulapi.hh"

typedef struct
{
  unsigned int msgID; // sequential message number
  double time;        // time message was sent
}CanonicalHdr;


enum statusReturn
  {
    QueueEmpty,
    QueueError,
    CmdComplete,
    CmdError,
    CmdUnknown,
    SystemNoInit,
    SystemWorking,
    SystemDone
  };

class StatusMsg{
public:
  void setHeader(CanonicalHdr headerIn);
  void setStatus(statusReturn statusIn);
  statusReturn getStatus();
  CanonicalHdr getHeader();
  char *getError();
  void print();
protected:
  CanonicalHdr hdr;
  statusReturn status;
};

class CanonicalMsg{
public:
  CanonicalHdr getHeader(){return hdr;};
  void setHeader(){ hdr.time = ulapi_time(); hdr.msgID = nextID++;};
  void setCurrentStatus(statusReturn statusIn){currentStatus=statusIn;};
  statusReturn getCurrentStatus(){return currentStatus;};
  int getMsgID(){ return hdr.msgID; };
  double getTime(){ return hdr.time; };
  virtual void process(void *sendTo) = 0;
  virtual void printMe(int verbosity) = 0;
  virtual statusReturn timer(itimerval *reset, void *rosCtrl) = 0;
  std::string printCurrentStatus();
protected:
  statusReturn currentStatus;
  static int nextID;
  CanonicalHdr hdr;
};

class CloseGripperMsg:public CanonicalMsg{
public:
  CloseGripperMsg(){};
  ~CloseGripperMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
};

class CloseToolChangerMsg:public CanonicalMsg{
public:
  CloseToolChangerMsg(){};
  ~CloseToolChangerMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
};

class DwellMsg:public CanonicalMsg{
 public:
  DwellMsg(){};
  DwellMsg(double timeIn){ time = timeIn;};
  ~DwellMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double time;
};

class EndCanonMsg:public CanonicalMsg{
public:
  EndCanonMsg(){};
  EndCanonMsg(int reasonIn){ reason = reasonIn; };
  ~EndCanonMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  int reason;
};

class InitCanonMsg:public CanonicalMsg{
public:
  InitCanonMsg(){};
  ~InitCanonMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
};

class MessageMsg:public CanonicalMsg{
public:
  MessageMsg(){};
  MessageMsg(std::string messageIn){ message = messageIn; };
  ~MessageMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  std::string message;
};

class MoveStraightToMsg:public CanonicalMsg{
public:
  MoveStraightToMsg(){};
  MoveStraightToMsg(PoseLocation *poseLocationIn){  poseLocation = poseLocationIn; };
  ~MoveStraightToMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  PoseLocation *poseLocation;
};

class MoveThroughToMsg:public CanonicalMsg{
public:
  MoveThroughToMsg(){};
  MoveThroughToMsg(PoseLocation **poseLocationsIn, int numIn){ poseLocations = poseLocationsIn; num = numIn; };
  ~MoveThroughToMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  PoseLocation **poseLocations;
  int num;
};

class MoveToMsg:public CanonicalMsg{
public:
  MoveToMsg(){};
  MoveToMsg(PoseLocation *poseLocationIn){ poseLocation = poseLocationIn; };
  ~MoveToMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  PoseLocation *poseLocation;
};

class OpenGripperMsg:public CanonicalMsg{
public:
  OpenGripperMsg(){};
  ~OpenGripperMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
};

class OpenToolChangerMsg:public CanonicalMsg{
public:
  OpenToolChangerMsg(){};
  ~OpenToolChangerMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
};

class SetAbsoluteAccelerationMsg:public CanonicalMsg{
public:
  SetAbsoluteAccelerationMsg(){};
  SetAbsoluteAccelerationMsg(double accelerationIn){ acceleration = accelerationIn; };
  ~SetAbsoluteAccelerationMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double acceleration;
};

class SetAbsoluteSpeedMsg:public CanonicalMsg{
public:
  SetAbsoluteSpeedMsg(){};
  SetAbsoluteSpeedMsg(double speedIn){ speed = speedIn; };
  ~SetAbsoluteSpeedMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double speed;
};

class SetAngleUnitsMsg:public CanonicalMsg{
public:
  SetAngleUnitsMsg(){};
  SetAngleUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; };
  ~SetAngleUnitsMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  std::string unitName;
};

class SetEndAngleToleranceMsg:public CanonicalMsg{
public:
  SetEndAngleToleranceMsg(){};
  SetEndAngleToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetEndAngleToleranceMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double tolerance;
};

class SetEndPointToleranceMsg:public CanonicalMsg{
public:
  SetEndPointToleranceMsg(){};
  SetEndPointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetEndPointToleranceMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double tolerance;
};

class SetIntermediatePointToleranceMsg:public CanonicalMsg{
public:
  SetIntermediatePointToleranceMsg(){};
  SetIntermediatePointToleranceMsg(double toleranceIn){ tolerance = toleranceIn; };
  ~SetIntermediatePointToleranceMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double tolerance;
};

class SetLengthUnitsMsg:public CanonicalMsg{
public:
  SetLengthUnitsMsg(){};
  SetLengthUnitsMsg(std::string unitNameIn){ unitName = unitNameIn; };
  ~SetLengthUnitsMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  std::string unitName;
};

class SetRelativeAccelerationMsg:public CanonicalMsg{
public:
  SetRelativeAccelerationMsg(){};
  SetRelativeAccelerationMsg(double percentIn){ percent = percentIn; };
  ~SetRelativeAccelerationMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double percent;
};

class SetRelativeSpeedMsg:public CanonicalMsg{
public:
  SetRelativeSpeedMsg(){};
  SetRelativeSpeedMsg(double percentIn){ percent = percentIn; };
  ~SetRelativeSpeedMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  double percent;
};

class StartObjectScanMsg:public CanonicalMsg{
public:
  StartObjectScanMsg(){};
  StartObjectScanMsg(std::string objectNameIn){objectName = objectNameIn; };
  ~StartObjectScanMsg(){};
  virtual void process(void* sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  std::string objectName;
};

class StopMotionMsg:public CanonicalMsg{
public:
  StopMotionMsg(){};
  StopMotionMsg(int isEmergencyIn){ isEmergency = isEmergencyIn; };
  ~StopMotionMsg(){};
  virtual void process(void *sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
  int isEmergency;
};

class StopObjectScanMsg:public CanonicalMsg{
public:
  StopObjectScanMsg(){};
  ~StopObjectScanMsg(){};
  virtual void process(void* sendTo);
  virtual void printMe(int verbosity);
  virtual statusReturn timer(itimerval *reset, void *rosCtrl);
};


#endif
