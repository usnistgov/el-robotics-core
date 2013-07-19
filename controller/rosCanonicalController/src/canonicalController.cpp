#include <stdio.h>
#include <vector>
#include <sstream>

#include "database/Point.h"
#include "database/Vector.h"
#include "ros/ros.h"
#include "rosInf.hh"
#include "ulapi.hh"
#include "controller.hh"
#include "commandParser.hh"
#include "canonicalMsg.hh"

RosInf *rosControl; // from rosInf.hh

/**
	\file canonicalController.cpp
	
	This file contains the implementation of the controller dequeuing thread and main function for the rosCanonicalController node.
*/

/**
  \brief Dequeueing loop for CRCL controller
  \param arg Pointer to the controller that dequeues command messages
*/
void
dequeueThread (void *arg)
{
  int errReturn = 0;
  Controller *ctrl = reinterpret_cast < Controller *>(arg);
  while(ros::ok())
  {
  	  while(errReturn == 0)
  	  	errReturn = ctrl->dequeueMsgHigh(rosControl);
  	  errReturn = ctrl->dequeueMsgLow(rosControl);
  	  while(!rosControl->checkCommandDone())
  	  {
  	    errReturn = ctrl->dequeueMsgHigh(rosControl);
  	    sleep(.1);
  	  	ros::spinOnce();
  	  }
  	  if(errReturn == 0 || errReturn == -1)
  	  {
  	  	//either no command to process or command was processed successfully
  	  }
  	  else if(errReturn == 1)
  	  {
  	  	printf("Error in command queue.\n");
  	  	ros::shutdown();
  	  	return;
  	  }
	  ros::spinOnce();
  }
}
int
main (int argc, char* argv[])
{
  Controller *ctrl; // from controller.hh
  
  void *dequeueTask = NULL;

  ctrl = new Controller();
  ros::init(ros::VP_string(), "canonicalController");
  ros::start();
  rosControl = new RosInf();
  FILE * inFile;
  CommandParser parser; // from commandParser.hh
  CloseGripperMsg closeGripper;
  EndCanonMsg endCanon;
  ulapi_integer result;

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
  
  /*Point *startPoint = new Point("start_scan");
  startPoint->sethasPoint_X(-.163);
  startPoint->sethasPoint_Y(0.6205);
  startPoint->sethasPoint_Z(0.3);*/
  
  //  sleep(300);
  ulapi_task_join(dequeueTask, &result);
  if( result == 0 )
    printf( "Sucessful completion\n" );
  else
    printf( "Error from commandParserMain thread\n" );

  ros::shutdown();
  return 1;
}
