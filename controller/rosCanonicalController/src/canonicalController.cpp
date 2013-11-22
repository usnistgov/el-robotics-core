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
#include <stdio.h>
#include <vector>
#include <sstream>
#include <sys/time.h>
#include <signal.h>

#include "database/Point.h"
#include "database/Vector.h"
#include "ros/ros.h"
#include "rosInf.hh"
#include "ulapi.hh"
#include "controller.hh"
#include "commandParser.hh"
#include "canonicalMsg.hh"

RosInf *rosControl; // from rosInf.hh
Controller *ctrl; // from controller.hh don't like global, but I need it in the signal callback
  

/**
   \addtogroup rosCanonicalController
   @{
   \file canonicalController.cpp
	
   This file contains the implementation of the controller dequeuing thread and main function for the rosCanonicalController node.
	
*/

/**
   \brief Dequeueing loop for CRCL controller
   \param arg Pointer to the controller that dequeues command messages
*/
void cmdStatusCheck(int sig)
{
  itimerval timeToWait;
  StatusMsg errReturn;

  timeToWait = ctrl->cmdStatusCheck(errReturn, rosControl);
  if( timeToWait.it_value.tv_sec <= 0 && timeToWait.it_value.tv_usec <= 0 )
    ctrl->queueMsgStatus(&errReturn);
  else
    setitimer(ITIMER_REAL, &timeToWait,NULL);
}

void
dequeueThread (void *arg)
{
  StatusMsg errReturn;
  Controller *dequeueCtrl = reinterpret_cast < Controller *>(arg);

  while(ros::ok())
    {
      dequeueCtrl->dequeueMsgLow(rosControl, 1);
      
      cmdStatusCheck(SIGALRM);
      errReturn.setStatus(SystemWorking);
      while(errReturn.getStatus() != SystemDone &&
	    errReturn.getStatus() != CmdError &&
	    errReturn.getStatus() != CmdComplete )
	{
	  errReturn = dequeueCtrl->dequeueMsgStatus(1);
	  printf( "canonicalController.cpp: Received status " );
	  errReturn.print();
	  ros::spinOnce();
	}
      ros::spinOnce();
    }
}

int
main (int argc, char* argv[])
{
  void *dequeueTask = NULL;

  ctrl = new Controller();
  ros::init(ros::VP_string(), "canonicalController");
  ros::start();
  rosControl = new RosInf();
  FILE * inFile;
  CommandParser parser; // from commandParser.hh
  CloseGripperMsg closeGripper;
  ulapi_integer result;
  struct sigaction action;

  action.sa_handler = cmdStatusCheck;

  // set up signal handler for command status checking
  sigaction (SIGALRM, &action, NULL);

  //ROS configuration
  std::string globalFrame;
  ros::NodeHandle nh;
  if(!nh.getParam("usarsim/globalFrame", globalFrame))
    {
      ROS_INFO("No global frame parameter specified, using default /odom");
      globalFrame = "/odom";
    }
  rosControl->setGlobalFrame(globalFrame);

  // this code uses the ULAPI library to provide portability
  // between different operating systems and architectures
  if (ULAPI_OK != ulapi_init (UL_USE_DEFAULT))
    {
      printf ("can't initialize ulapi");
      return 1;
    }
    
  // start task that reads queue and executes commands
  dequeueTask = ulapi_task_new ();
  ulapi_task_start (dequeueTask, dequeueThread, (void *) ctrl, ulapi_prio_lowest (),
		    1);
  

  if( argc == 1 )
    {
      printf( "%s: Using stdio for input\n", argv[0] );
      inFile = stdin;
    }
  else if( argc == 2 )
    inFile = fopen(argv[1], "r");
  else
    {
      printf( "Usage: %s <file>\n\t If file is not specified, then keyboard input is read.\n", argv[0] );
      exit(1);
    }

  if (inFile == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }

  // read commands, parse, and place in queue
  if (parser.readCommandFile(inFile, ctrl))
    exit(1);
  fclose(inFile);
  
  ulapi_task_join(dequeueTask, &result);
  if( result == 0 )
    printf( "Sucessful completion\n" );
  else
    printf( "Error from commandParserMain thread\n" );

  ros::shutdown();
  return 1;
}

/** @} */
