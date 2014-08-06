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
#ifndef __crclPortDefs
#define __crclPortDefs
#include "nist_core/crcl.h"

#define CRCL_CMD_PORT_DEFAULT 1234
#define CRCL_STATUS_PORT_DEFAULT 1235
#define KUKA_PORT 6008
//#define DEFAULT_FROM_KUKA "/home/stephen/projects/el-robotics-core/CRCL/FromKRC.xml"
//#define DEFAULT_TO_KUKA "/home/stephen/projects/el-robotics-core/CRCL/ToKRC.xml"
#define DEFAULT_FROM_KUKA "/home/gtrirobot/el-robotics-core/CRCL/FromKRC.xml"
#define DEFAULT_TO_KUKA "/home/gtrirobot/el-robotics-core/CRCL/ToKRC.xml"
#define KUKA_DEFAULT_CYCLE .01
//#define KUKA_DEFAULT_MAX_ACCEL 40
//#define KUKA_DEFAULT_MAX_VEL 75
#define KUKA_DEFAULT_CART_MAX_ACCEL 20
#define KUKA_DEFAULT_CART_MAX_VEL 15

#define HOME_JOINT1 0.
#define HOME_JOINT2 -60.
#define HOME_JOINT3 125.
#define HOME_JOINT4 -5.
#define HOME_JOINT5 23.
#define HOME_JOINT6 184.

typedef enum
  {
    CRCL_NOOP = 0,
    CRCL_DWELL,
    CRCL_END_CANON,
    CRCL_INIT_CANON,
    CRCL_MOVE_JOINT,
    CRCL_MOVE_TO,
    CRCL_SET_ABSOLUTE_ACC,
    CRCL_SET_ABSOLUTE_SPEED,
    CRCL_SET_GRIPPER,
    CRCL_STOP_MOTION,
    CRCL_UNKNOWN
  }CRCLCmd;

typedef enum
  {
    CRCL_ERROR = -1,
    CRCL_UNINITIALIZED = 0,
    CRCL_INITIALIZED
  }CRCLState;

typedef enum
  {
    CRCL_DONE = 0,
    CRCL_ABORT,
    CRCL_NEW_CMD,
    CRCL_WORKING
  }CRCLCmdStatus;

typedef struct
{
  CRCLCmd cmd;
  CRCLCmdStatus status;
  union
  {
    double absAcc;
    double absSpeed;
    double dwell;
    double gripperPos;
    double joints[6];
    robotPose pose;
  };
}CRCLCmdUnion;

typedef struct
{
  int device;
  int modId;
  float position;
}GripperStatus;

typedef struct
{
  robotPose pose;
  double joint[6];
}RobotStatus;

#endif
