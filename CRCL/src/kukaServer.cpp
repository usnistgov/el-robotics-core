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
/*!
 *	\file		kukaServer.cpp
 *	\brief 		Create CRCL controller for Kuka robot using ethernetXML
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 02, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <stdio.h>		/* stdin, stderr */
#include <math.h>               /* fabs */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string>
#include <ctype.h>
#include <unistd.h>             /* sleep */

#include <ulapi.h>

#include <nist_core/nist_core.h>
#include <nist_core/crcl.h>
//#include <nist_core/crcl_client.h>
#include <nist_core/crcl_robot.h>
#include <nist_core/crcl_sim_robot.h>
#include "CRCL/timer.hh"
#include "CRCL/kukaThread.hh"
#include "CRCL/statusThread.hh"
#include "CRCL/crclDefs.hh"
#include "CRCL/crclUtils.hh"
#include "CRCL/trajectoryMaker.hh"
#include "schunk_libm5api/m5apiw32.h"

////////////////////////////////////////////////////////
// globals
int usePowerCube;
int debug;
double safeOffset;


// was .2 and .1
#define P_GAIN 0.03
#define MAX_MOVE 0.2
#define GOOD_ENOUGH 0.08
////////////////////////////////////////////////////////
double pCtrlEngine( double statusVal, double cmdVal, int &done )
{
  double retValue;
  double distance;
  
  distance = fabs(statusVal - cmdVal);
  retValue = min(P_GAIN*distance, MAX_MOVE);
  if( statusVal > cmdVal )
    retValue *= -1;
  if( distance > GOOD_ENOUGH )
    done = 0;
  else
    retValue = 0;
  return retValue;
}

////////////////////////////////////////////////////////
robotPose crclPCtrl(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  robotPose retValue;
  RobotStatus robotStatus;
  static int sendMe = 0;
  CRCLCmdUnion currentCmd;
  int done = 1;
  double distance;

  if( (status->getCurrentCmd()).cmd != CRCL_MOVE_TO )
    {
      printf( "Bad command type %d to crclPCtrl\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      retValue.x = 0;
      retValue.y = 0;
      retValue.z = 0;
      retValue.xrot = 0;
      retValue.yrot = 0;
      retValue.zrot = 0;
      return retValue;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      status->setCurrentStatus(CRCL_WORKING);
    }
  else if( (status->getCurrentCmd()).status == CRCL_WORKING )
    {
      if( sendMe++ == 0 )
	{
	  sendMe = 0;
	  //	  printf( "\n\n" );
	}
      else
	{
	  /*
	  printf( "Status: <%f %f %f>\n",
		  robotStatus.pose.x,
		  robotStatus.pose.y,
		  robotStatus.pose.z);
	  */
	  retValue.x = 0;
	  retValue.y = 0;
	  retValue.z = 0;
	  retValue.xrot = 0;
	  retValue.yrot = 0;
	  retValue.zrot = 0;
	  return retValue;
	}
      robotStatus = status->getRobotStatus();
      currentCmd = status->getCurrentCmd();

      retValue.x = pCtrlEngine(robotStatus.pose.x, 
			       currentCmd.pose.x, done );
      retValue.y = pCtrlEngine(robotStatus.pose.y, 
			       currentCmd.pose.y, done );
      retValue.z = pCtrlEngine(robotStatus.pose.z, 
			       currentCmd.pose.z, done );

      /*
      retValue.xrot = pCtrlEngine(robotStatus.pose.xrot, 
			       currentCmd.pose.xrot, done );
      retValue.yrot = pCtrlEngine(robotStatus.pose.yrot, 
			       currentCmd.pose.yrot, done );
      retValue.zrot = pCtrlEngine(robotStatus.pose.zrot, 
			       currentCmd.pose.zrot, done );
      */
      retValue.xrot = 0;
      retValue.yrot = 0;
      retValue.zrot = 0;
      if( done )
	status->setCurrentStatus(CRCL_DONE);	
      return retValue;
    }
  else
    status->setCurrentStatus(CRCL_DONE);
  retValue.x = 0;
  retValue.y = 0;
  retValue.z = 0;
  retValue.xrot = 0;
  retValue.yrot = 0;
  retValue.zrot = 0;
  return retValue;
}





////////////////////////////////////////////////////////
void crclDwell(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  static int doneCounter = 0;

  if( (status->getCurrentCmd()).cmd != CRCL_DWELL )
    {
      printf( "Bad command type %d to crclDwell\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received dwell\n");
      doneCounter = (int)((status->getCurrentCmd()).dwell/
			  status->getCycleTime());
      status->setCurrentStatus(CRCL_WORKING);
    }
  else if( (status->getCurrentCmd()).status == CRCL_ABORT )
    {
      printf( "Aborting dwell with %f left\n", doneCounter*
	      status->getCycleTime());
      doneCounter = 0;
      status->setCurrentCmd(nextCmd);
    }

  // decrement counter and see if done
  doneCounter--;
  if( doneCounter <=0 )
    {
      status->setCurrentStatus(CRCL_DONE);
      printf( "Dwell done\n" );
    }
}

////////////////////////////////////////////////////////
void crclEndCanon(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  printf( "Received end canon\n");
  status->setCurrentStatus(CRCL_DONE);
  status->setCurrentState(CRCL_UNINITIALIZED);
}

////////////////////////////////////////////////////////
robotPose crclMoveTo(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  static int index = 0;
  static TrajectoryMaker trajectoryMaker;
  static vector<robotPose> movementTrajectory;
  robotPose retValue, goalValue;
  UnitStatus unitStatus;

  if( (status->getCurrentCmd()).cmd != CRCL_MOVE_TO &&
      (status->getCurrentCmd()).cmd != CRCL_MOVE_JOINT &&
      (status->getCurrentCmd()).cmd != CRCL_INIT_CANON )
    {
      printf( "Bad command type %d to crclMoveTo\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      retValue.x = 0;
      retValue.y = 0;
      retValue.z = 0;
      retValue.xrot = 0;
      retValue.yrot = 0;
      retValue.zrot = 0;
      return retValue;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      if( (status->getCurrentCmd()).cmd == CRCL_MOVE_TO )
	{
	  trajectoryMaker.setCurrent((status->getRobotStatus()).pose);
	  goalValue = (status->getCurrentCmd()).pose;
	  unitStatus = status->getUnitStatus();
	  // expecting mm as units
	  goalValue.x *= unitStatus.lengthUnit;
	  goalValue.y *= unitStatus.lengthUnit;
	  goalValue.z *= unitStatus.lengthUnit;
	  goalValue.xrot *= unitStatus.angleUnit;
	  goalValue.yrot *= unitStatus.angleUnit;
	  goalValue.zrot *= unitStatus.angleUnit;
	  printf( "kukaThreadArgs:: Moving to: <%lf %lf %lf> <%lf %lf %lf>\n",
		  goalValue.x,
		  goalValue.y,
		  goalValue.z,
		  goalValue.xrot,
		  goalValue.yrot,
		  goalValue.zrot);
  	}
      else if( (status->getCurrentCmd()).cmd == CRCL_INIT_CANON )
	{
	  goalValue.x = (status->getRobotStatus()).joint[0];
	  goalValue.y = (status->getRobotStatus()).joint[1];
	  goalValue.z = (status->getRobotStatus()).joint[2];
	  goalValue.xrot = (status->getRobotStatus()).joint[3];
	  goalValue.yrot = (status->getRobotStatus()).joint[4];
	  goalValue.zrot = (status->getRobotStatus()).joint[5];
	  trajectoryMaker.setCurrent(goalValue);
	  goalValue.x = HOME_JOINT1;
	  goalValue.y = HOME_JOINT2;
	  goalValue.z = HOME_JOINT3;
	  goalValue.xrot = HOME_JOINT4;
	  goalValue.yrot = HOME_JOINT5;
	  goalValue.zrot = HOME_JOINT6;
	}
      else if( (status->getCurrentCmd()).cmd == CRCL_MOVE_JOINT )
	{
	  goalValue.x = (status->getRobotStatus()).joint[0];
	  goalValue.y = (status->getRobotStatus()).joint[1];
	  goalValue.z = (status->getRobotStatus()).joint[2];
	  goalValue.xrot = (status->getRobotStatus()).joint[3];
	  goalValue.yrot = (status->getRobotStatus()).joint[4];
	  goalValue.zrot = (status->getRobotStatus()).joint[5];
	  trajectoryMaker.setCurrent(goalValue);
	  goalValue.x = (status->getCurrentCmd()).joints[0];
	  goalValue.y = (status->getCurrentCmd()).joints[1];
	  goalValue.z = (status->getCurrentCmd()).joints[2];
	  goalValue.xrot = (status->getCurrentCmd()).joints[3];
	  goalValue.yrot = (status->getCurrentCmd()).joints[4];
	  goalValue.zrot = (status->getCurrentCmd()).joints[5];
	}

      /* load motion queue with decomposed motion that is
	 divided by the cycletime (status->cycleTime)
      */
      printf( "Received move to\n");
      movementTrajectory.clear();

      movementTrajectory = trajectoryMaker.makeTrajectory(status, goalValue);
      status->setCurrentStatus(CRCL_WORKING);
      if( debug )
	{
	  printf( "Moving Cart from: <%f %f %f> <%f %f %f> to <%f %f %f <%f %f %f>\n",
		  (status->getRobotStatus()).pose.x,
		  (status->getRobotStatus()).pose.y,
		  (status->getRobotStatus()).pose.z,
		  (status->getRobotStatus()).pose.xrot,
		  (status->getRobotStatus()).pose.yrot,
		  (status->getRobotStatus()).pose.zrot,
		  goalValue.x,
		  goalValue.y,
		  goalValue.z,
		  goalValue.xrot,
		  goalValue.yrot,
		  goalValue.zrot);
	  printf( "Moving Joint from: <%f %f %f> <%f %f %f> to <%f %f %f <%f %f %f>\n",
		  (status->getRobotStatus()).joint[0],
		  (status->getRobotStatus()).joint[1],
		  (status->getRobotStatus()).joint[2],
		  (status->getRobotStatus()).joint[3],
		  (status->getRobotStatus()).joint[4],
		  (status->getRobotStatus()).joint[5],
		  goalValue.x,
		  goalValue.y,
		  goalValue.z,
		  goalValue.xrot,
		  goalValue.yrot,
		  goalValue.zrot);
	  for( int ii=0; ii<movementTrajectory.size(); ii++ )
	    printf( "<%f %f %f> <%f %f %f>\n",
		    movementTrajectory[ii].x,
		    movementTrajectory[ii].y,
		    movementTrajectory[ii].z,
		    movementTrajectory[ii].xrot,
		    movementTrajectory[ii].yrot,
		    movementTrajectory[ii].zrot);
	}
      index = 0;
    }
  else if( (status->getCurrentCmd()).status == CRCL_ABORT )
    {
      /* clear motion queue and compute new trajectory
	 that brings us to zero velocity as quickly
	 as possible. This will be recomputed each
         cycle 
      */
      status->setCurrentCmd(nextCmd);
      movementTrajectory.clear();
      index = 0;
      /* clear motion queue and compute new trajectory
	 that brings us to zero velocity as quickly
	 as possible. This will be recomputed each
         cycle 
      */
      printf( "Aborting moveTo\n");
    }
  // if items left in motion queue send them
  if(index < movementTrajectory.size() && 
     (status->getCurrentCmd()).status == CRCL_WORKING)
    {
      /* corrections are offsets to current position. However,
	 it may occur that the corrections have not yet been sent
	 to the robot. Therefore, the corrections must be added to the current
	 values. Once sent, these are zeroed out by the kuka thread.
	 This addition occurs in the calling routine.
      */
      return movementTrajectory[index++];
    }
  // if no items left, then we are done.
  else if( index >= movementTrajectory.size()  )
    {
      if( (status->getCurrentCmd()).status == CRCL_ABORT )
	{
	  status->setCurrentCmd(nextCmd);
	}
      else
	{
	  status->setCurrentStatus(CRCL_DONE);
	  
	  retValue.x = 0;
	  retValue.y = 0;
	  retValue.z = 0;
	  retValue.xrot = 0;
	  retValue.yrot = 0;
	  retValue.zrot = 0;
	  return retValue;
	}
    }
}

////////////////////////////////////////////////////////
/*!
  Note that this method calls the crclMoveTo method in order
  to set the arm at its home position
 */
robotPose crclInitCanon(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  int gripperReturn;
  robotPose retValue;
  GripperStatus gripperStatus;

  if( (status->getCurrentCmd()).cmd != CRCL_INIT_CANON )
    {
      printf( "Bad command type %d to crclInitCanon\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      retValue.x = 0;
      retValue.y = 0;
      retValue.z = 0;
      retValue.xrot = 0;
      retValue.yrot = 0;
      retValue.zrot = 0;
      return retValue;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received init canon\n");
      //      status->setCurrentStatus(CRCL_WORKING);
      // home robot arm
      retValue = crclMoveTo( status, nextCmd );

      // home gripper
      if( usePowerCube )
	{
	  gripperStatus = status->getGripperStatus();
	  gripperReturn = PCube_homeModule( gripperStatus.device, 
					    gripperStatus.modId );
	}
    }
  else if( (status->getCurrentCmd()).status == CRCL_ABORT )
    {
      printf( "Aborting Init\n");
      if( usePowerCube )
	{
	  gripperStatus = status->getGripperStatus();
	  gripperReturn = PCube_haltModule( gripperStatus.device, 
					    gripperStatus.modId );
	}
      status->setCurrentCmd(nextCmd);
    }
  else if( (status->getCurrentCmd()).status == CRCL_WORKING )
    {
      // home robot arm
      retValue = crclMoveTo( status, nextCmd );

      // home gripper
      if( usePowerCube )
	{
	  gripperStatus = status->getGripperStatus();
	  gripperReturn = PCube_waitForHomeEnd(gripperStatus.device, 
					       gripperStatus.modId, 0);
	  PCube_getPos(gripperStatus.device, gripperStatus.modId, 
		       &(gripperStatus.position));
	  status->setGripperStatus(gripperStatus);
	  if( gripperReturn == 0 && 
	      (status->getCurrentCmd()).status == CRCL_DONE)
	    {
	      status->setCurrentState(CRCL_INITIALIZED);
	    }
	  else
	    status->setCurrentStatus(CRCL_WORKING);
	  if(debug)
	    printf( "gripper position: %f\n", gripperStatus.position);
	}
      else if((status->getCurrentCmd()).status == CRCL_DONE)
	{
	  status->setCurrentState(CRCL_INITIALIZED);
	}
    }
  else
    {
      retValue.x = 0;
      retValue.y = 0;
      retValue.z = 0;
      retValue.xrot = 0;
      retValue.yrot = 0;
      retValue.zrot = 0;
    }
  return retValue;
}

////////////////////////////////////////////////////////
void crclNoop(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( (status->getCurrentCmd()).cmd != CRCL_NOOP )
    {
      printf( "Bad command type %d to crclNoop\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received NoOp cmd\n");
      status->setCurrentStatus(CRCL_DONE);
    }
}

////////////////////////////////////////////////////////
void crclSetAngleUnits(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  UnitStatus unitStatus;

  if( (status->getCurrentCmd()).cmd != CRCL_SET_ANGLE_UNITS )
    {
      printf( "Bad command type %d to crclSetAngleUnits\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received SetAngleUnits cmd\n");
      unitStatus = status->getUnitStatus();
      status->setCurrentStatus(CRCL_DONE);
      unitStatus.angleUnit = (status->getCurrentCmd()).angleUnit;
      if( unitStatus.angleUnit == CRCL_RADIAN )
	unitStatus.angleMult = 180./M_PI;
      else
	unitStatus.angleMult = 1.;
      status->setUnitStatus(unitStatus);
    }
}

////////////////////////////////////////////////////////
void crclSetLengthUnits(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  UnitStatus unitStatus;

  if( (status->getCurrentCmd()).cmd != CRCL_SET_LENGTH_UNITS )
    {
      printf( "Bad command type %d to crclSetLengthUnits\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received SetLengthUnits cmd\n");
      status->setCurrentStatus(CRCL_DONE);
      status->getUnitStatus();
      unitStatus.lengthUnit = (status->getCurrentCmd()).lengthUnit;
      switch(unitStatus.lengthUnit)
	{
	case CRCL_METER:
	  unitStatus.lengthMult = 1000.;
	  break;
	case CRCL_CENTIMETER:
	  unitStatus.lengthMult = 100.;
	  break;
	case CRCL_MILLIMETER:
	  unitStatus.lengthMult = 1.;
	  break;
	case CRCL_INCH:
	  unitStatus.lengthMult = 25.4;
	  break;
	case CRCL_FOOT:
	  unitStatus.lengthMult = 304.8;
	  break;
	default:
	  printf( "Bad length unit to crclSetLengthUnits, bad!\n");
	  exit(1);
	  break;
	}
      status->setUnitStatus(unitStatus);
    }
}


////////////////////////////////////////////////////////
void crclSetMaxAcc(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( (status->getCurrentCmd()).cmd != CRCL_SET_MAX_CART_ACC  ||
      (status->getCurrentCmd()).cmd != CRCL_SET_MAX_JOINT_ACC )
    {
      printf( "Bad command type %d to crclSetMaxAcc\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      if( (status->getCurrentCmd()).cmd == CRCL_SET_MAX_CART_ACC )
	{
	  printf( "Received set max cartesian acc\n");
	  status->setMaxAccel((status->getCurrentCmd()).absAcc, MOVE_CARTESIAN);
	}
      else
	{
	  printf( "Received set max joint acc\n");
	  status->setMaxAccel((status->getCurrentCmd()).absAcc, MOVE_JOINT);
	}
      status->setCurrentStatus(CRCL_DONE);
    }
}

////////////////////////////////////////////////////////
void crclSetMaxSpeed(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( (status->getCurrentCmd()).cmd != CRCL_SET_MAX_CART_SPEED  ||
      (status->getCurrentCmd()).cmd != CRCL_SET_MAX_JOINT_SPEED )
    {
      printf( "Bad command type %d to crclSetMaxSpeed\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      if( (status->getCurrentCmd()).cmd == CRCL_SET_MAX_CART_SPEED )
	{
	  printf( "Received set max cartesian vel\n");
	  status->setMaxVel((status->getCurrentCmd()).absSpeed, MOVE_CARTESIAN);
	}
      else
	{
	  printf( "Received set max joint Vel\n");
	  status->setMaxVel((status->getCurrentCmd()).absSpeed, MOVE_JOINT);
	}
      status->setCurrentStatus(CRCL_DONE);
    }
}

////////////////////////////////////////////////////////
void crclSetGripper(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  GripperStatus gripperStatus;

  if( (status->getCurrentCmd()).cmd != CRCL_SET_GRIPPER )
    {
      printf( "Bad command type %d to crclSetGripper\n", 
	      (status->getCurrentCmd()).cmd );
      status->setCurrentStatus(CRCL_DONE);
      status->setCurrentState(CRCL_ERROR);
      return;
    }
  gripperStatus = status->getGripperStatus();
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received set gripper with position %f\n", (status->getCurrentCmd()).gripperPos);
      status->setCurrentStatus(CRCL_WORKING);
      if( usePowerCube )
	{
	  /*
	  PCube_movePos( gripperStatus.device, gripperStatus.modId, 
			 (status->getCurrentCmd()).gripperPos );
	  */
	  PCube_moveRamp( gripperStatus.device, gripperStatus.modId, 
			  (status->getCurrentCmd()).gripperPos, 1, 1 );
	}
    }
  else if( (status->getCurrentCmd()).status == CRCL_ABORT )
    {
      printf( "Aborting CRCL_SET_GRIPPER\n");
      if( usePowerCube )
	{
	  PCube_haltModule( gripperStatus.device, gripperStatus.modId );
	  PCube_resetModule( gripperStatus.device, gripperStatus.modId );
	}
      status->setCurrentCmd(nextCmd);
    }
  else if( (status->getCurrentCmd()).status == CRCL_WORKING )
    {
      if( usePowerCube )
	{
	  PCube_getPos(gripperStatus.device, gripperStatus.modId, 
		       &(gripperStatus.position));
	  status->setGripperStatus(gripperStatus);
	  if(debug)
	    printf( "gripper position: %f\n", gripperStatus.position);
	  if( fabs((gripperStatus.position - 
		    (status->getCurrentCmd()).gripperPos)) < 0.01 )
	    {
	      printf("Finished move\n");
	      status->setCurrentStatus(CRCL_DONE);
	    }
	  else
	    printf( "Gripper delta: %f\n", fabs(gripperStatus.position -
						(status->getCurrentCmd()).gripperPos));
	}
      else
	{
	  status->setCurrentStatus(CRCL_DONE);
	}
    }
}

////////////////////////////////////////////////////////
void crclStopMotion(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  printf( "Received stop\n");
  status->setCurrentStatus(CRCL_DONE);
}

////////////////////////////////////////////////////////
void crclUnknown(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( (status->getCurrentCmd()).status == CRCL_NEW_CMD )
    {
      printf( "Received unknown\n");
      status->setCurrentStatus(CRCL_DONE);
    }
}

////////////////////////////////////////////////////////
int getCmdConnection(int port, int &cmdServer)
{
  static bool firstTime = true;
  int cmdConnection;
  
  if( firstTime )
    {
      cmdServer = ulapi_socket_get_server_id(port);
      if (cmdServer < 0) 
	{
	  fprintf(stderr, "kukaServer: can't serve kuka port %d\n", 
		  port);
	  return -1;
	}
      firstTime = false;
    }
  //  if(debug)
  printf("kukaServer: serving cmd port %d, waiting...\n", port);
  cmdConnection = ulapi_socket_get_connection_id(cmdServer);
  if (cmdConnection < 0) 
    {
      fprintf(stderr, "kukaServer:: can't get status client connecton\n");
      return -1;
    }
  //  if(debug) 
  ulapi_socket_set_nonblocking(cmdConnection);
  printf("kukaServer: got a status client connection on id %d\n", 
	 cmdConnection);
  return cmdConnection;
}

////////////////////////////////////////////////////////
void kukaThread(KukaThreadArgs *args)
{
  KukaThread *myKuka = new KukaThread();
  myKuka->setDebug(debug);
  myKuka->threadStart(args);
}

////////////////////////////////////////////////////////
void statusThread(CRCLStatus *args)
{
  StatusThread *myStatus = new StatusThread(1); // 1 makes this a server
  myStatus->setDebug(debug);
  myStatus->threadStart(args);
}

////////////////////////////////////////////////////////
int parseCmd(char *inbuf, CRCLCmdUnion *nextCmd)
{
  int retValue = 1;
  double newDouble;
  string unitType(200, ' ');

  if( !strncasecmp(inbuf, "Dwell", strlen("Dwell")))
    {
      nextCmd->cmd = CRCL_DWELL;
      if( sscanf(inbuf, "%*s %lf", &nextCmd->dwell) != 1)
	retValue = 0;
    }
  else if( !strncasecmp(inbuf, "EndCanon", strlen("EndCanon")))
    {
      nextCmd->cmd = CRCL_END_CANON;
    }
  else if( !strncasecmp(inbuf, "InitCanon", strlen("InitCanon")))
    {
      nextCmd->cmd = CRCL_INIT_CANON;
    }
  else if( !strncasecmp(inbuf, "SetLengthUnits", strlen("SetLenghtUnits")))
    {
      nextCmd->cmd = CRCL_SET_LENGTH_UNITS;
      if( sscanf(inbuf, "%*s %s", &unitType[0]) != 1)
	retValue = 0;
      if( !strncasecmp(unitType.c_str(), "Meter", strlen("Meter") ))
	  nextCmd->lengthUnit = CRCL_METER;
      else if( !strncasecmp(unitType.c_str(), "Centimeter", 
			    strlen("Centimeter") ))
	nextCmd->lengthUnit = CRCL_CENTIMETER;
      else if( !strncasecmp(unitType.c_str(), "Millimeter", 
			    strlen("Millimeter") ))
	nextCmd->lengthUnit = CRCL_MILLIMETER;
      else if( !strncasecmp(unitType.c_str(), "Inch", 
			    strlen("Inch") ))
	nextCmd->lengthUnit = CRCL_INCH;
      else if( !strncasecmp(unitType.c_str(), "Foot", 
			    strlen("Foot") ))
	nextCmd->lengthUnit = CRCL_FOOT;
      else
	retValue = 0;
    }
  else if( !strncasecmp(inbuf, "SetAngleUnits", strlen("SetAngleUnits")))
    {
      nextCmd->cmd = CRCL_SET_ANGLE_UNITS;
      if( sscanf(inbuf, "%*s %s", &unitType[0] ) != 1)
	retValue = 0;
      if( !strncasecmp(unitType.c_str(), "Degree", strlen("Degree") ))
	  nextCmd->angleUnit = CRCL_DEGREE;
      else if( !strncasecmp(unitType.c_str(), "Radian", 
			    strlen("Radian") ))
	nextCmd->angleUnit = CRCL_RADIAN;
      else
	retValue = 0;
    }
  else if( !strncasecmp(inbuf, "MoveTo", strlen("MoveTo")))
    {
      nextCmd->cmd = CRCL_MOVE_TO;
      if( sscanf(inbuf, "%*s %lf %lf %lf %lf %lf %lf",
		 &nextCmd->pose.x,
		 &nextCmd->pose.y,
		 &nextCmd->pose.z,
		 &nextCmd->pose.xrot,
		 &nextCmd->pose.yrot,
		 &nextCmd->pose.zrot) != 6)
	retValue = 0;

    }
  else if( !strncasecmp(inbuf, "MoveJoint", strlen("MoveJoint")) ||
	   !strncasecmp(inbuf, "MoveJoints", strlen("MoveJoints")) )
    {
      nextCmd->cmd = CRCL_MOVE_JOINT;
      if( sscanf(inbuf, "%*s %lf %lf %lf %lf %lf %lf",
		 &nextCmd->joints[0],
		 &nextCmd->joints[1],
		 &nextCmd->joints[2],
		 &nextCmd->joints[3],
		 &nextCmd->joints[4],
		 &nextCmd->joints[5]) != 6)
	retValue = 0;
    }
  else if( !strncasecmp(inbuf, "Noop", strlen("Noop")))
    {
      nextCmd->cmd = CRCL_NOOP;
    }
  else if( !strncasecmp(inbuf, "SetMaxCartAcc", strlen("SetMaxCartAcc")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->absAcc) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_MAX_CART_ACC;
    }
  else if( !strncasecmp(inbuf, "SetMaxCartSpeed", strlen("SetMaxCartSpeed")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->absSpeed) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_MAX_CART_SPEED;
    }
  else if( !strncasecmp(inbuf, "SetMaxJointAcc", strlen("SetMaxJointAcc")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->absAcc) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_MAX_JOINT_ACC;
    }
  else if( !strncasecmp(inbuf, "SetMaxJointSpeed", strlen("SetMaxJointSpeed")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->absSpeed) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_MAX_JOINT_SPEED;
    }
  else if( !strncasecmp(inbuf, "SetGripper", strlen("SetGripper")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->gripperPos) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_GRIPPER;
    }
  else if( !strncasecmp(inbuf, "StopMotion", strlen("StopMotion")))
    {
      nextCmd->cmd = CRCL_STOP_MOTION;
    }
  
  else
    {
      printf("error from parser %s\n", inbuf );
      nextCmd->cmd = CRCL_UNKNOWN;
    }
  nextCmd->status = CRCL_NEW_CMD;
}

////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
  ulapi_integer result;
  RCS_TIMER *cycleBlock = new RCS_TIMER(KUKA_DEFAULT_CYCLE);
  int option;
  int ival;
  int cmd_port = CRCL_CMD_PORT_DEFAULT;
  //  int stat_port = CRCL_CLIENT_STAT_PORT_DEFAULT;
  std::string host = "localhost";
  KukaThreadArgs kukaThreadArgs;
  ulapi_task_struct kukaTask, statusTask;
  int cmdConnection;
  CRCLStatus status;
  CRCLCmdUnion nextCmd;
  CRCLCmdUnion tempCmd;
  // variables for gripper
  int gripperDev = 0;
  char pInitString[] = "RS232:1,9600";
  int gripperReturn;
  int deviceMap[MAX_MODULES];
  unsigned long serialNum;
  unsigned char moduleType;
  unsigned short moduleOS;
  unsigned long state;
  KukaState currentState;
  int cmdServer;
  GripperStatus gripperStatus;
  RobotStatus robotStatus;

  debug = 0;
  kukaThreadArgs.setJointMotorScale(80., 100., 80., 80., 80., 40.5);
  kukaThreadArgs.setCmdMotorScale(1.4, 1.74, 1.4, 1.4, 1.4, 0.87);
  usePowerCube = false;
  nextCmd.cmd = CRCL_NOOP;
  opterr = 0;
  safeOffset = 0;

  while (true) 
    {
      option = getopt(argc, argv, ":c:gk:dh:s");
      if (option == -1) break;
      switch (option) 
	{
	case 'c':
	  ival = atoi(optarg);
	  cmd_port = ival;
	  break;
	case 'k':
	  if( atoi(optarg) ) // turn on corrections
	    {
	      kukaThreadArgs.setJointMotorScale(80., 100., 80., 80., 80., 40.5);
	      kukaThreadArgs.setCmdMotorScale(1.4, 1.74, 1.4, 1.4, 1.4, 0.87);
	    }
	  else
	    {
	      kukaThreadArgs.setJointMotorScale(1., 1., 1., 1., 1., 1.);
	      kukaThreadArgs.setCmdMotorScale(1., 1., 1., 1., 1., 1.);
	    }
	  break;
	  case 's':
	    safeOffset = 20;
	    break;
	  /*
	case 's':
	  ival = atoi(optarg);
	  stat_port = ival;
	  break;
	  */
	case 'd':
	  debug = 1;
	  break;
	case 'g':
	  usePowerCube = true;
	  break;
	case 'h':
	  host = optarg;
	  break;
	case ':':
	  fprintf(stderr, "missing value for -%c\n", optopt);
	  return 1;
	  break;
	default:
	  fprintf (stderr, "unrecognized option -%c\n", optopt);
	  return 1;
	  break;
	} // switch (option)
    }   // while (true) for getopt

  // this code uses the ULAPI library to provide portability
  // between different operating systems and architectures
  if (ULAPI_OK != ulapi_init())
    {
      printf ("kukaServer:: can't initialize ulapi");
      return 1;
    }

  // start kuka robot thread
  ulapi_task_init(&kukaTask);
  ulapi_task_start(&kukaTask, 
		   reinterpret_cast<ulapi_task_code>(kukaThread), 
		   reinterpret_cast<void*>(&kukaThreadArgs), 
		   ulapi_prio_highest(), 0);
  // start status thread
  ulapi_task_init(&statusTask);
  ulapi_task_start(&statusTask, 
		   reinterpret_cast<ulapi_task_code>(statusThread), 
		   reinterpret_cast<void*>(&status), 
		   ulapi_prio_lowest(), 0);

  // initialize gripper
  if( usePowerCube )
    {
      PCube_setDllDebug(1, 0, 0);
      printf("Attempting to open device: %s\n", pInitString);
      gripperReturn = PCube_openDevice( &gripperDev, pInitString );
      if( gripperReturn != 0 )
	{
	  printf("Unable to open device: %s. Error %d\n", pInitString, gripperReturn);
	  return -1;
	}
      gripperReturn = PCube_getModuleIdMap( gripperDev, deviceMap );
      gripperReturn = PCube_getModuleSerialNo( gripperDev, deviceMap[0], &serialNum );
      gripperReturn = PCube_getModuleType( gripperDev, deviceMap[0], &moduleType );
      gripperReturn = PCube_getModuleVersion( gripperDev, deviceMap[0], &moduleOS );
      gripperReturn = PCube_getModuleState( gripperDev, deviceMap[0], &state );
      gripperStatus.device = gripperDev;
      gripperStatus.modId = deviceMap[0];
      status.setGripperStatus(gripperStatus);
      
      std::string typeStr = (moduleType == TYPEID_MOD_ROTARY) ? "ROTARY" : "LINEAR";
      printf("\nModule %d\n", deviceMap[0]);
      printf("\tSerial #:         %lu\n", serialNum);
      printf("\tModule Type:      %s\n", typeStr.c_str());
      printf("\tSoftware Version: %d\n", moduleOS);
      printf("\tModule State:     0x%lux\n", state);
    }

  // start up server for incoming commands
  cmdConnection = getCmdConnection(CRCL_CMD_PORT_DEFAULT, cmdServer);
  while( cmdConnection < 0 )
    {
      printf( "kukaServer:Bad client connection, retrying...\n" );
      cycleBlock->wait();
      cmdConnection = getCmdConnection(CRCL_CMD_PORT_DEFAULT, cmdServer);
    }
  //  for(int i=0; i<10; i++)
  while(true)
    {
      enum {INBUF_LEN = 2048};
      char inbuf[INBUF_LEN];
      int nchars;

      nchars = ulapi_socket_read(cmdConnection, inbuf, sizeof(inbuf)-1);
      if(nchars == 0) 
	{
	  printf("kukaServer::status client disconnected %d\n",
		 nchars);
	  ulapi_socket_close(cmdConnection);
	  cmdConnection = getCmdConnection(CRCL_CMD_PORT_DEFAULT, 
					   cmdServer);
	  while( cmdConnection < 0 )
	    {
	      printf( "kukaServer:Bad client connection, retrying...\n" );
	      cycleBlock->wait();
	      cmdConnection = getCmdConnection(CRCL_CMD_PORT_DEFAULT, 
					       cmdServer);
	    }
	  tempCmd.cmd = CRCL_NOOP;
	  status.setCurrentCmd(&tempCmd);
	}
      else if( nchars > 0 )
	{
	  inbuf[nchars] = '\0';
	  printf( "Message[%d]: %s\n", nchars, inbuf );
	  if( (status.getCurrentCmd()).status != CRCL_DONE )
	    {
	      status.setCurrentStatus(CRCL_ABORT);
	      parseCmd(inbuf, &nextCmd);
	    }
	  else
	    {
	      parseCmd(inbuf, &tempCmd);
	      status.setCurrentCmd(&tempCmd);
	    }
	}
      //      else if(nchars == -1 )
      //	printf( "no message read\n" );
      else if( nchars < -1)
	{
	  printf("kukaServer:: strange return from socket, nchars: %d\n", 
		 nchars);
	  break;
	}
      switch( (status.getCurrentCmd()).cmd )
	{
	case CRCL_NOOP:
	  crclNoop(&status, &nextCmd);
	  break;
	case CRCL_DWELL:
	  crclDwell(&status, &nextCmd);
	  break;
	case CRCL_END_CANON:
	  crclEndCanon(&status, &nextCmd);
	  break;
	case CRCL_INIT_CANON:
	  kukaThreadArgs.setJointMove(&status);
	  kukaThreadArgs.addPose(crclInitCanon(&status, &nextCmd));
	  break;
	case CRCL_MOVE_TO:
	  kukaThreadArgs.setCartesianMove(&status);
	  // temp code
	  //	  kukaThreadArgs.addPose(crclMoveTo(&status, &nextCmd));
	  kukaThreadArgs.setPoseCorrection(crclPCtrl(&status, &nextCmd));
	  // end of temp
	  break;
	case CRCL_MOVE_JOINT:
	  kukaThreadArgs.setJointMove(&status);
	  kukaThreadArgs.addPose(crclMoveTo(&status, &nextCmd));
	  break;
	case CRCL_SET_MAX_CART_ACC:
	  crclSetMaxAcc(&status, &nextCmd);
	  break;
	case CRCL_SET_MAX_CART_SPEED:
	  crclSetMaxSpeed(&status, &nextCmd);
	  break;
	case CRCL_SET_MAX_JOINT_ACC:
	  crclSetMaxAcc(&status, &nextCmd);
	  break;
	case CRCL_SET_MAX_JOINT_SPEED:
	  crclSetMaxSpeed(&status, &nextCmd);
	  break;
	case CRCL_SET_GRIPPER:
	  crclSetGripper(&status, &nextCmd);
	  break;
	case CRCL_SET_ANGLE_UNITS:
	  crclSetAngleUnits(&status, &nextCmd);
	  break;
	case CRCL_SET_LENGTH_UNITS:
	  crclSetLengthUnits(&status, &nextCmd);
	  break;
	case CRCL_STOP_MOTION:
	  crclStopMotion(&status, &nextCmd);
	  break;
	case CRCL_UNKNOWN:
	  crclUnknown(&status, &nextCmd);
	  break;
	default:
	  crclUnknown(&status, &nextCmd);
	  break;
	}
      /* set status information for robot */
      currentState = kukaThreadArgs.getCurrentState();
      robotStatus.pose.x = currentState.cartesian[0];
      robotStatus.pose.y = currentState.cartesian[1];
      robotStatus.pose.z = currentState.cartesian[2];
      robotStatus.pose.xrot = currentState.cartesian[3];
      robotStatus.pose.yrot = currentState.cartesian[4];
      robotStatus.pose.zrot = currentState.cartesian[5];
      robotStatus.joint[0] = currentState.joint[0];
      robotStatus.joint[1] = currentState.joint[1];
      robotStatus.joint[2] = currentState.joint[2];
      robotStatus.joint[3] = currentState.joint[3];
      robotStatus.joint[4] = currentState.joint[4];
      robotStatus.joint[5] = currentState.joint[5];
      status.setRobotStatus(robotStatus);
      cycleBlock->wait();
    }
  sleep(1);
  exit(1);
  ulapi_task_join(&kukaTask, &result);
  if( result == 0 )
    printf( "Sucessful completion\n" );
  else
    printf( "Error from kukaThread\n" );
}


