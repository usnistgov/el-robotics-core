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
 *	\file		crclClient.cpp
 *	\brief 		Send CRCL commands to server
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 03, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <tinyxml.h>
#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <math.h>

#include <ulapi.h>

#include "CRCL/timer.hh"
#include "nist_core/crcl.h"
#include "CRCL/crclDefs.hh"
#include "CRCL/statusThread.hh"

int debug;

/********************************
Good Points 
Home position is: 417. 10. 267. 179. -3. -97.
Position over left of table is: 85. -50. 120. 0. 21. -95.
MoveTo 300 0 125 179 0 0  // safe position
MoveTo -111 -425 215 -179 0 0 // 84T-2
MoveTo 188. -349. 48. -178. 0. 0. // 60T-3

MoveTo 200. 351. 125 179 0 0 // PK-2


**********************************/
void statusThread(CRCLStatus *args)
{
  StatusThread *myStatus = new StatusThread(0); // 0 makes this a client
  myStatus->setDebug(debug);
  myStatus->threadStart(args);
}

#define buffSize 1024
int main(int argc, char *argv[])
{
  bool done;
  int option;
  int cmdConnection;
  int script = 1;
  char msgOut[buffSize];
  RCS_TIMER *cycleBlock = new RCS_TIMER(KUKA_DEFAULT_CYCLE);
  CRCLStatus status;
  ulapi_task_struct statusTask;
  RobotStatus robotStatus;
  GripperStatus gripperStatus;
  bool useFile = false;
  char *fileName;
  std::ifstream inFile;
  std::istream *inputSource;
  float counter = 0;

  debug = 1;
  while (true) 
    {
      option = getopt(argc, argv, ":cdf:");
      if (option == -1) break;
      switch (option) 
	{
	case 'd':
	  debug = 1;
	  break;
	case 'c':
	  script = 0;
	  break;
	case 'f':
	  script = 0;
	  useFile = true;
	  fileName = optarg;
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
      printf ("crclClient:: can't initialize ulapi");
      return 1;
    }
  cmdConnection = ulapi_socket_get_client_id(CRCL_CMD_PORT_DEFAULT, 
					     "localhost");
  if(cmdConnection < 0)
    return -1;

  // start status thread
  ulapi_task_init(&statusTask);
  ulapi_task_start(&statusTask, 
		   reinterpret_cast<ulapi_task_code>(statusThread), 
		   reinterpret_cast<void*>(&status), 
		   ulapi_prio_lowest(), 0);
  if(!script)
    {
      if( useFile )
	{
	  inFile.open(fileName);
	  inputSource = &inFile;
	  if( !inputSource->good() )
	    {
	      printf( "unable to open %s\n", fileName );
	      exit(1);
	    }
	}
      else
	inputSource = &std::cin;
      while(inputSource->good())
	{
	  inputSource->getline(msgOut, buffSize);
	  if( msgOut[0] == ' ' || msgOut[0] == '/' )
	    continue;
	  ulapi_socket_write(cmdConnection, msgOut, strlen(msgOut));
	  printf( "Sent: %s\n", msgOut);
	  done = false;
	  cycleBlock->wait();
	  while( !done )
	    {
	      cycleBlock->wait();
	      gripperStatus = status.getGripperStatus();
	      robotStatus = status.getRobotStatus();
	      if( !useFile || status.getCurrentStatus()==CRCL_DONE )
		done = true;
	      //	      printf( "Fmod: %f\n", fmod(counter, 100.));
	      if( fmod(counter++, 100.)==0 || done )
		{
		  printf( "Status Cmd: %s Status: %s\n", 
			  getCRCLCmdString((status.getCurrentCmd()).cmd).c_str(),
			  getCRCLStatusString(status.getCurrentStatus()).c_str());
		  printf( "\x1b[32mCart Status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
			  robotStatus.pose.x, robotStatus.pose.y, 
			  robotStatus.pose.z,
			  robotStatus.pose.xrot, robotStatus.pose.yrot, 
			  robotStatus.pose.zrot);
		  printf( "\x1b[32mJoint Status: <%4.1f, %4.1f, %4.1f> <%4.1f, %4.1f, %4.1f>\x1b[0m\n",
			  robotStatus.joint[0],
			  robotStatus.joint[1],
			  robotStatus.joint[2],
			  robotStatus.joint[3],
			  robotStatus.joint[4],
			  robotStatus.joint[5]);
		}
	    }
	}
    }
  for(int i=0; i<1; i++ )
    {
      ulapi_strncpy(msgOut, "InitCanon", strlen("InitCanon"));
      ulapi_socket_write(cmdConnection, msgOut, strlen(msgOut));
      /*
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "MoveTo 1. 2. 3. 4. 5. 6.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "Dwell 1";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "MoveTo 7. 8. 9. 10. 11. 12.";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "Dwell 4";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      msgOut = "EndCanon";
      ulapi_socket_write(cmdConnection, msgOut.c_str(), msgOut.length());
      printf( "crclClient writing: %s\n", msgOut.c_str());
      sleep(2);
      */
      cycleBlock->wait();
    }
}
