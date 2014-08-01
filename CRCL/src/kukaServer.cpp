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

#include <ulapi.h>

#include <nist_core/nist_core.h>
#include <nist_core/crcl.h>
//#include <nist_core/crcl_client.h>
#include <nist_core/crcl_robot.h>
#include <nist_core/crcl_sim_robot.h>
#include "CRCL/timer.hh"
#include "CRCL/kukaThread.hh"
#include "CRCL/crclDefs.hh"
#include "CRCL/crclUtils.hh"
#include "CRCL/trajectoryMaker.hh"
#include "schunk_libm5api/m5apiw32.h"

////////////////////////////////////////////////////////
// globals
int usePowerCube;
int debug;

////////////////////////////////////////////////////////
void crclDwell(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  static int doneCounter = 0;

  if( status->currentCmd.cmd != CRCL_DWELL )
    {
      printf( "Bad command type %d to crclDwell\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {
      printf( "Received dwell\n");
      doneCounter = (int)(status->currentCmd.dwell/status->cycleTime);
      status->currentCmd.status = CRCL_WORKING;
    }
  else if( status->currentCmd.status == CRCL_ABORT )
    {
      printf( "Aborting dwell with %f left\n", doneCounter*status->cycleTime);
      doneCounter = 0;
      if( crclCmdUnionCopy(nextCmd, &status->currentCmd, true ) != true )
	{
	  printf( "error from copy of new command\n");
	  exit(1);
	}
    }

  // decrement counter and see if done
  doneCounter--;
  if( doneCounter <=0 )
    {
      status->currentCmd.status = CRCL_DONE;
      printf( "Dwell done\n" );
    }
}

////////////////////////////////////////////////////////
void crclEndCanon(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  printf( "Received end canon\n");
  status->currentCmd.status = CRCL_DONE;
  status->currentState = CRCL_UNINITIALIZED;
}

////////////////////////////////////////////////////////
void crclInitCanon(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  int gripperReturn;

  if( status->currentCmd.cmd != CRCL_INIT_CANON )
    {
      printf( "Bad command type %d to crclInitCanon\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {
      printf( "Received init canon\n");
      status->currentCmd.status = CRCL_WORKING;
      if( usePowerCube )
	{
	  gripperReturn = PCube_homeModule( status->gripStatus.device, status->gripStatus.modId );
	}
    }
  else if( status->currentCmd.status == CRCL_ABORT )
    {
      printf( "Aborting Init\n");
      if( usePowerCube )
	gripperReturn = PCube_haltModule( status->gripStatus.device, status->gripStatus.modId );
      if( crclCmdUnionCopy(nextCmd, &status->currentCmd, true ) != true )
	{
	  printf( "error from copy of new command\n");
	  exit(1);
	}
    }
  else if( status->currentCmd.status == CRCL_WORKING )
    if( usePowerCube )
      {
	printf( "gripper position: %f\n", status->gripStatus.position);
	gripperReturn = PCube_waitForHomeEnd(status->gripStatus.device, status->gripStatus.modId, 0);
	PCube_getPos(status->gripStatus.device, status->gripStatus.modId, &status->gripStatus.position);
	if( gripperReturn == 0 )
	  {
	    status->currentCmd.status = CRCL_DONE;
	    status->currentState = CRCL_INITIALIZED;
	  }
      }
    else
      {
	status->currentCmd.status = CRCL_DONE;
	status->currentState = CRCL_INITIALIZED;
      }
}

////////////////////////////////////////////////////////
robotPose crclMoveTo(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  static int index = 0;
  static TrajectoryMaker trajectoryMaker;
  static vector<robotPose> movementTrajectory;
  vector<double> values;
  vector<bool> signs; //True = +, False = -
  robotPose singlePoint;
  double max_value, max_change;
  robotPose retValue;

  if( status->currentCmd.cmd != CRCL_MOVE_TO )
    {
      printf( "Bad command type %d to crclMoveTo\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      retValue.x = 0;
      retValue.y = 0;
      retValue.z = 0;
      retValue.xrot = 0;
      retValue.yrot = 0;
      retValue.zrot = 0;
      return retValue;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {
      /* load motion queue with decomposed motion that is
	 divided by the cycletime (status->cycleTime)
      */
      printf( "Received move to\n");
      movementTrajectory.clear();
      trajectoryMaker.setCurrent(status->robotStatus.pose);

      movementTrajectory = trajectoryMaker.makeTrajectory(status);
      status->currentCmd.status = CRCL_WORKING;
      //      if( debug )
      if(0)
	{
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
  else if( status->currentCmd.status == CRCL_ABORT )
    {
      /* clear motion queue and compute new trajectory
	 that brings us to zero velocity as quickly
	 as possible. This will be recomputed each
         cycle 
      */
      if( crclCmdUnionCopy(nextCmd, &status->currentCmd, true ) != true )
	{
	  printf( "error from copy of new command\n");
	  exit(1);
	}
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
  if(index < movementTrajectory.size())
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
      if( status->currentCmd.status == CRCL_ABORT )
	{
	  if( crclCmdUnionCopy(nextCmd, &status->currentCmd, true ) != true )
	    {
	      printf( "error from copy of new command\n");
	      exit(1);
	    }
	}
      else
	{
	  status->currentCmd.status = CRCL_DONE;
	  
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
void crclNoop(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( status->currentCmd.cmd != CRCL_NOOP )
    {
      printf( "Bad command type %d to crclNoop\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {
      printf( "Received NoOp cmd\n");
      status->currentCmd.status = CRCL_WORKING;
      status->currentCmd.status = CRCL_DONE;
    }
}

////////////////////////////////////////////////////////
void crclSetAbsoluteAcc(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( status->currentCmd.cmd != CRCL_SET_ABSOLUTE_ACC )
    {
      printf( "Bad command type %d to crclSetAbsoluteAcc\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  printf( "Received set absolute acc\n");
  status->maxAccel = status->currentCmd.absAcc;
  status->currentCmd.status = CRCL_DONE;
}

////////////////////////////////////////////////////////
void crclSetAbsoluteSpeed(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( status->currentCmd.cmd != CRCL_SET_ABSOLUTE_SPEED )
    {
      printf( "Bad command type %d to crclSetAbsoluteSpeed\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {
      printf( "Received set absolute speed\n");
      status->maxVel = status->currentCmd.absSpeed;
      status->currentCmd.status = CRCL_DONE;
    }
}

////////////////////////////////////////////////////////
void crclSetGripper(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  if( status->currentCmd.cmd != CRCL_SET_GRIPPER )
    {
      printf( "Bad command type %d to crclSetGripper\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {
      printf( "Received set gripper with position %f\n", status->currentCmd.gripperPos);
      status->currentCmd.status = CRCL_WORKING;
      if( usePowerCube )
	{
	  /*
	  PCube_movePos( status->gripStatus.device, status->gripStatus.modId, 
			 status->currentCmd.gripperPos );
	  */
	  PCube_moveRamp( status->gripStatus.device, status->gripStatus.modId, 
			  status->currentCmd.gripperPos, 1, 1 );
	}
    }
  else if( status->currentCmd.status == CRCL_ABORT )
    {
      printf( "Aborting CRCL_SET_GRIPPER\n");
      if( usePowerCube )
	{
	  PCube_haltModule( status->gripStatus.device, status->gripStatus.modId );
	  PCube_resetModule( status->gripStatus.device, status->gripStatus.modId );
	}
      if( crclCmdUnionCopy(nextCmd, &status->currentCmd, true ) != true )
	{
	  printf( "error from copy of new command\n");
	  exit(1);
	}
    }
  else if( status->currentCmd.status == CRCL_WORKING )
    {
      if( usePowerCube )
	{
	  PCube_getPos(status->gripStatus.device, status->gripStatus.modId, &status->gripStatus.position);
	  printf( "gripper position: %f\n", status->gripStatus.position);
	  if( fabs((status->gripStatus.position - status->currentCmd.gripperPos)) < 0.01 )
	    {
	      printf("Finished move\n");
	      status->currentCmd.status = CRCL_DONE;
	    }
	  else
	    printf( "Gripper error: %f\n", fabs(status->gripStatus.position - status->currentCmd.gripperPos));
	}
      else
	{
	  status->currentCmd.status = CRCL_DONE;
	}
    }
}

////////////////////////////////////////////////////////
void crclStopMotion(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  printf( "Received stop\n");
  status->currentCmd.status = CRCL_DONE;
}

////////////////////////////////////////////////////////
void crclUnknown(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  printf( "Received unknown\n");
  status->currentCmd.status = CRCL_DONE;
}

////////////////////////////////////////////////////////
int getCmdConnection(int port)
{
  int cmdServer;
  int cmdConnection;
  
  cmdServer = ulapi_socket_get_server_id(port);
  if (cmdServer < 0) 
    {
      fprintf(stderr, "kukaServer: can't serve kuka port %d\n", 
	      port);
      return -1;
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
int parseCmd(char *inbuf, CRCLCmdUnion *nextCmd)
{
  int retValue = 1;

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
  else if( !strncasecmp(inbuf, "Noop", strlen("Noop")))
    {
      nextCmd->cmd = CRCL_NOOP;
    }
  else if( !strncasecmp(inbuf, "SetAbsoluteAcc", strlen("SetAbsoluteAcc")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->absAcc) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_ABSOLUTE_ACC;
    }
  else if( !strncasecmp(inbuf, "SetAbsoluteSpeed", strlen("SetAbsoluteSpeed")))
    {
      if( sscanf(inbuf, "%*s %lf", &nextCmd->absSpeed) != 1)
	retValue = 0;
      nextCmd->cmd = CRCL_SET_ABSOLUTE_SPEED;
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
  ulapi_task_struct kukaTask;
  int cmdConnection;
  CRCLStatus status;
  CRCLCmdUnion nextCmd;
  // variables for gripper
  int gripperDev = 0;
  char pInitString[] = "RS232:1,9600";
  int gripperReturn;
  int deviceMap[MAX_MODULES];
  unsigned long serialNum;
  unsigned char moduleType;
  unsigned short moduleOS;
  unsigned long state;

  debug = 0;
  usePowerCube = false;
  status.currentCmd.cmd = CRCL_NOOP;
  status.currentCmd.status = CRCL_DONE;
  status.currentState = CRCL_UNINITIALIZED;
  status.cycleTime = KUKA_DEFAULT_CYCLE;
  status.maxAccel = KUKA_DEFAULT_MAX_ACCEL;
  status.maxVel = KUKA_DEFAULT_MAX_VEL;
  nextCmd.cmd = CRCL_NOOP;
  opterr = 0;
  while (true) 
    {
      option = getopt(argc, argv, ":c:gs:dh:");
      if (option == -1) break;
      switch (option) 
	{
	case 'c':
	  ival = atoi(optarg);
	  cmd_port = ival;
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
  ulapi_task_init(&kukaTask);
  ulapi_task_start(&kukaTask, 
		   reinterpret_cast<ulapi_task_code>(kukaThread), 
		   reinterpret_cast<void*>(&kukaThreadArgs), 
		   ulapi_prio_highest(), 0);
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
      status.gripStatus.device = gripperDev;
      status.gripStatus.modId = deviceMap[0];
      
      std::string typeStr = (moduleType == TYPEID_MOD_ROTARY) ? "ROTARY" : "LINEAR";
      printf("\nModule %d\n", deviceMap[0]);
      printf("\tSerial #:         %lu\n", serialNum);
      printf("\tModule Type:      %s\n", typeStr.c_str());
      printf("\tSoftware Version: %d\n", moduleOS);
      printf("\tModule State:     0x%lux\n", state);
    }

  // start up server for incoming commands
  cmdConnection = getCmdConnection(CRCL_CMD_PORT_DEFAULT);
  while( cmdConnection < 0 )
    {
      printf( "kukaServer:Bad client connection, retrying...\n" );
      cycleBlock->wait();
      cmdConnection = getCmdConnection(CRCL_CMD_PORT_DEFAULT);
    }
  ulapi_socket_set_nonblocking(cmdConnection);
  //  for(int i=0; i<10; i++)
  while(true)
    {
      enum {INBUF_LEN = 2048};
      char inbuf[INBUF_LEN];
      int nchars;

      nchars = ulapi_socket_read(cmdConnection, inbuf, sizeof(inbuf)-1);
      inbuf[nchars] = '\0';
      if(nchars == 0) 
	{
	  if(debug) printf("kukaServer::status client disconnected %d\n",
			   nchars);
	  break;
	}
      else if( nchars > 0 )
	{
	printf( "Message: %s\n", inbuf );
	if( status.currentCmd.status != CRCL_DONE )
	  {
	    status.currentCmd.status = CRCL_ABORT;
	    parseCmd(inbuf, &nextCmd);
	  }
	else
	  parseCmd(inbuf, &status.currentCmd);
	}
      //      else if(nchars == -1 )
      //	printf( "no message read\n" );
      else if( nchars < -1)
	{
	  printf("kukaServer:: strange return from socket, nchars: %d\n", nchars);
	  break;
	}
      switch( status.currentCmd.cmd )
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
	  crclInitCanon(&status, &nextCmd);
	  break;
	case CRCL_MOVE_TO:
	  kukaThreadArgs.addPose(crclMoveTo(&status, &nextCmd));
	  break;
	case CRCL_SET_ABSOLUTE_ACC:
	  crclSetAbsoluteAcc(&status, &nextCmd);
	  break;
	case CRCL_SET_ABSOLUTE_SPEED:
	  crclSetAbsoluteSpeed(&status, &nextCmd);
	  break;
	case CRCL_SET_GRIPPER:
	  crclSetGripper(&status, &nextCmd);
	  break;
	case CRCL_STOP_MOTION:
	  crclStopMotion(&status, &nextCmd);
	  break;
	case CRCL_UNKNOWN:
	  crclUnknown(&status, &nextCmd);
	  break;
	default:
	  printf("kukaServer:: unknown cmd received %d\n", status.currentCmd.cmd);
	  crclUnknown(&status, &nextCmd);
	  break;
	}
      /* set status information for robot */
      ulapi_mutex_take(&kukaThreadArgs.poseCorrectionMutex);
      status.robotStatus.pose.x = kukaThreadArgs.currentState.cartesian[0];
      status.robotStatus.pose.y = kukaThreadArgs.currentState.cartesian[1];
      status.robotStatus.pose.z = kukaThreadArgs.currentState.cartesian[2];
      status.robotStatus.pose.xrot = kukaThreadArgs.currentState.cartesian[3];
      status.robotStatus.pose.yrot = kukaThreadArgs.currentState.cartesian[4];
      status.robotStatus.pose.zrot = kukaThreadArgs.currentState.cartesian[5];
      ulapi_mutex_give(&kukaThreadArgs.poseCorrectionMutex);
      /*
      printf( "kukaServer::Timer loop %d\n", i );
      /*
      kukaThreadArgs.poseCorrection.x = i;
      kukaThreadArgs.poseCorrection.y = i + .1;
      kukaThreadArgs.poseCorrection.z = i + .2;
      kukaThreadArgs.poseCorrection.xrot = i + .3;
      kukaThreadArgs.poseCorrection.yrot = i + .4;
      kukaThreadArgs.poseCorrection.zrot = i + .5;
      printf( "\x1b[31mkukaServer status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
	      kukaThreadArgs.currentState.cartesian[0],
	      kukaThreadArgs.currentState.cartesian[1],
	      kukaThreadArgs.currentState.cartesian[2],
	      kukaThreadArgs.currentState.cartesian[5],
	      kukaThreadArgs.currentState.cartesian[4],
	      kukaThreadArgs.currentState.cartesian[3]);
      ulapi_mutex_give(&kukaThreadArgs.poseCorrectionMutex);
      */
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
