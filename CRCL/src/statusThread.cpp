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
 *	\file		statusThread.cpp
 *	\brief 		Communicate Status status to clients
 *	\class		statusThread
 *	\author		Stephen Balakirsky, GTRI
 *	\date		August 05, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <stdio.h>
#include <math.h>
#include "CRCL/statusThread.hh"
#include "CRCL/crclDefs.hh"

StatusThread::StatusThread(int isServerIn, double cycleTimeIn)
{
  debug = 0;
  isServer = isServerIn;
  statusThreadBlock = new RCS_TIMER(cycleTimeIn);

  if( isServer )
    statusServer = -1;
  else
    statusServer = 1;
}

void StatusThread::connectClient()
{
  if( statusServer < 0 )
    statusServer = ulapi_socket_get_server_id(CRCL_STATUS_PORT_DEFAULT);
  if (statusServer < 0) 
    {
      fprintf(stderr, "statusThread: can't serve status port %d\n", 
	      CRCL_STATUS_PORT_DEFAULT);
      return;
    }
  if(debug)
    printf("statusThread: status status on port %d, waiting...\n", 
	   CRCL_STATUS_PORT_DEFAULT);
  if( isServer )
    statusConnection = ulapi_socket_get_connection_id(statusServer);
  else
    statusConnection = ulapi_socket_get_client_id(CRCL_STATUS_PORT_DEFAULT, 
						  "localhost");

  if(statusConnection < 0) 
    {
      fprintf(stderr, "statusThread:: can't get status client connecton\n");
      return;
    }
  if(debug) 
    printf("statusThread: got a status client connection on id %d\n", 
	   statusConnection);
}

void StatusThread::threadStart(CRCLStatus *argsIn)
{
  CRCLStatus statusOut;
  CRCLCmdUnion tempCmdUnion;
  args = argsIn;
  int nchars;
  
  connectClient();
  while(true)
    {
      if( isServer )
	{
	  tempCmdUnion = args->getCurrentCmd();
	  statusOut.setCurrentCmd(&tempCmdUnion);
	  statusOut.setCurrentState(args->getCurrentState());
	  statusOut.setCurrentStatus(args->getCurrentStatus());
	  statusOut.setGripperStatus(args->getGripperStatus());
	  for(int ii=0; ii<3; ii++)
	    {
	      statusOut.setMaxAccel(args->getMaxAccel((MovementType)ii), 
				    (MovementType)ii);
	      statusOut.setMaxVel(args->getMaxVel((MovementType)ii), 
				  (MovementType)ii);
	    }
	  statusOut.setRobotStatus(args->getRobotStatus());
	  nchars = ulapi_socket_write(statusConnection, 
				      reinterpret_cast<char*>(&statusOut), 
				      sizeof(statusOut));
	  if( nchars <= 0 )
	    {
	      printf( "statusThread: socket closed\n" );
	      ulapi_socket_close(statusConnection);
	      connectClient();
	    }
	  statusThreadBlock->wait();
	}
      else
	{
	  ulapi_socket_read(statusConnection,
			    reinterpret_cast<char*>(argsIn),
			    sizeof(statusOut));
	}
    }
}

void StatusThread::setDebug(int debugLevel)
{
  debug = debugLevel;
  printf( "statusThread:: seting debug to %d\n", debug );
}
