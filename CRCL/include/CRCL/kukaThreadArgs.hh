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
*****************************************************************************/
#ifndef __kukaThreadArgs
#define __kukaThreadArgs

#include <ulapi.h>
#include "nist_core/crcl.h"
#include "CRCL/crclStatus.hh"

typedef struct
{
  double cartesian[6];
  double joint[6];
  double external[6];
}KukaState;

class KukaThreadArgs
{
private:
  bool cartesianMove;
  ulapi_mutex_struct poseCorrectionMutex;
  robotPose poseCorrection;
  KukaState currentState;
public:
  double jointMotorScale[6]; //bizarre numbers needed by KR5-6
  double cmdMotorScale[6];
  KukaThreadArgs();
  void addPose(robotPose poseIn);
  bool getCartesianMove();
  KukaState getCurrentState();
  robotPose getPoseCorrection(int zeroValues);
  void setCartesianMove(CRCLStatus *status);
  void setCmdMotorScale(double d1, double d2, double d3,
			  double d4, double d5, double d6);
  void setCurrentState(KukaState *stateIn);
  void setJointMotorScale(double d1, double d2, double d3,
			  double d4, double d5, double d6);
  void setJointMove(CRCLStatus *status);
  void setPoseCorrection(robotPose poseCorrectionIn);
};
#endif
