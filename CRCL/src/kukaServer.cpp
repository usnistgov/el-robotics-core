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
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <numeric>

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
#include "CRCL/currentLocation.hh"

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
      crclCmdUnionCopy(nextCmd, &status->currentCmd, true );
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
  printf( "Received init canon\n");
  status->currentCmd.status = CRCL_DONE;
  status->currentState = CRCL_INITIALIZED;
}

////////////////////////////////////////////////////////
void crclMoveTo(CRCLStatus *status, CRCLCmdUnion *nextCmd, KukaThreadArgs *setPoint)
{
  static int motionQueueLength = 0; // temp variable for example
  static CurrentLocation maker;
  static vector<SingleLocation> movementTrajectory;
  static int index = 0;
  double sum;

  if( status->currentCmd.cmd != CRCL_MOVE_TO )
    {
      printf( "Bad command type %d to crclMoveTo\n", 
	      status->currentCmd.cmd );
      status->currentCmd.status = CRCL_DONE;
      status->currentState = CRCL_ERROR;
      return;
    }
  if( status->currentCmd.status == CRCL_NEW_CMD )
    {

      maker.x = setPoint->currentState.cartesian[0];
      maker.y = setPoint->currentState.cartesian[1];
      maker.z = setPoint->currentState.cartesian[2];
      maker.roll = setPoint->currentState.cartesian[3];
      maker.pitch = setPoint->currentState.cartesian[4];
      maker.yaw = setPoint->currentState.cartesian[5];

      movementTrajectory = maker.makeTrajectory( status->currentCmd.pose.x, status->currentCmd.pose.y, status->currentCmd.pose.z, 
        status->currentCmd.pose.xrot, status->currentCmd.pose.yrot, status->currentCmd.pose.zrot, status->maxVel, status->maxAccel);

      /* load motion queue with decomposed motion that is
	 divided by the cycletime (status->cycleTime)
      */

      printf( "Received move to\n");
      status->currentCmd.status = CRCL_WORKING;
      motionQueueLength = movementTrajectory.size();

    }
  else if( status->currentCmd.status == CRCL_ABORT )
    {
      //double xFinal = ((0 - pow(((movementTrajectory[index-1].x - movementTrajectory[index-2].x) / KUKA_DEFAULT_CYCLE),2)) / (2 * status->maxAccel)) + movementTrajectory[index-1].x;
      //double yFinal = ((0 - pow(((movementTrajectory[index-1].y - movementTrajectory[index-2].y) / KUKA_DEFAULT_CYCLE),2)) / (2 * status->maxAccel)) + movementTrajectory[index-1].y;
      //double zFinal = ((0 - pow(((movementTrajectory[index-1].z - movementTrajectory[index-2].z) / KUKA_DEFAULT_CYCLE),2)) / (2 * status->maxAccel)) + movementTrajectory[index-1].z;
      //double rollFinal = ((0 - pow(((movementTrajectory[index-1].roll - movementTrajectory[index-2].roll) / KUKA_DEFAULT_CYCLE),2)) / (2 * status->maxAccel)) + movementTrajectory[index-1].roll;
      //double pitchFinal = ((0 - pow(((movementTrajectory[index-1].pitch - movementTrajectory[index-2].pitch) / KUKA_DEFAULT_CYCLE),2)) / (2 * status->maxAccel)) + movementTrajectory[index-1].pitch;
      //double yawFinal = ((0 - pow(((movementTrajectory[index-1].yaw - movementTrajectory[index-2].yaw) / KUKA_DEFAULT_CYCLE),2)) / (2 * status->maxAccel)) + movementTrajectory[index-1].yaw;

      //movementTrajectory.clear();

      //movementTrajectory = maker.makeTrajectory(xFinal, yFinal, zFinal, rollFinal, pitchFinal, yawFinal, status->maxVel, status->maxAccel);

      //motionQueueLength = movementTrajectory.size();
      //index = 0;
      /* clear motion queue and compute new trajectory
	 that brings us to zero velocity as quickly
	 as possible. This will be recomputed each
         cycle 
      */
      printf( "Aborting moveTo\n");
    }
  // if items left in motion queue send them
  if( (index +1) != motionQueueLength)
  {


      ulapi_mutex_take(&setPoint->poseCorrectionMutex);
      setPoint->poseCorrection.x += movementTrajectory[index].x;
      setPoint->poseCorrection.y += movementTrajectory[index].y;
      setPoint->poseCorrection.z += movementTrajectory[index].z;
      setPoint->poseCorrection.xrot += movementTrajectory[index].roll;
      setPoint->poseCorrection.yrot += movementTrajectory[index].pitch;
      setPoint->poseCorrection.zrot += movementTrajectory[index].yaw;
      ulapi_mutex_give(&setPoint->poseCorrectionMutex);

      maker.setPositions(movementTrajectory[index].x, movementTrajectory[index].y, movementTrajectory[index].z,
        movementTrajectory[index].roll, movementTrajectory[index].pitch, movementTrajectory[index].yaw);

      index++;
  }
  // if no items left, then we are done.
  else if( (index+1) == motionQueueLength )
    {
      if( status->currentCmd.status == CRCL_ABORT )
	crclCmdUnionCopy(nextCmd, &status->currentCmd, true );
      else
	status->currentCmd.status = CRCL_DONE;
    }
}

////////////////////////////////////////////////////////
void crclNoop(CRCLStatus *status, CRCLCmdUnion *nextCmd)
{
  printf( "Received noop\n");
  status->currentCmd.status = CRCL_DONE;
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
  printf( "Received set absolute speed\n");
  status->maxVel = status->currentCmd.absSpeed;
  status->currentCmd.status = CRCL_DONE;
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
  int debug = true;
  std::string host = "localhost";
  KukaThreadArgs kukaThreadArgs;
  ulapi_task_struct kukaTask;
  int cmdConnection;
  CRCLStatus status;
  CRCLCmdUnion nextCmd;

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
      option = getopt(argc, argv, ":c:s:dh:");
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
	  crclMoveTo(&status, &nextCmd, &kukaThreadArgs);
	  break;
	case CRCL_SET_ABSOLUTE_ACC:
	  crclSetAbsoluteAcc(&status, &nextCmd);
	  break;
	case CRCL_SET_ABSOLUTE_SPEED:
	  crclSetAbsoluteSpeed(&status, &nextCmd);
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
      /*
      printf( "kukaServer::Timer loop %d\n", i );
      ulapi_mutex_take(&kukaThreadArgs.poseCorrectionMutex);
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
	      kukaThreadArgs.currentState.cartesian[3],
	      kukaThreadArgs.currentState.cartesian[4],
	      kukaThreadArgs.currentState.cartesian[5]);
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
