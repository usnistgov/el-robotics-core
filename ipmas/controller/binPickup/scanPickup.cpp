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

RosInf *rosControl;

/**
  \addtogroup binPickup
  @{
  \file scanPickup.cpp
  
  This file contains the implementation of the controller dequeuing thread and main function for the binPickup node.
  @}
*/

//prototype for scanpickup function
void generateScanPattern(MoveThroughToMsg *scanPattern, RosInf* rosInf, Point *initPoint, double length, double width);

/**
  \brief Dequeueing loop for CRCL controller
  \param arg Pointer to the controller that dequeues command messages
*/
void
dequeueThread (void *arg)
{
  StatusMsg errReturn;
  Controller *ctrl = reinterpret_cast < Controller *>(arg);

  errReturn.setStatus(CmdComplete);
  while(ros::ok())
  {
    while(errReturn.getStatus() != QueueEmpty)
      errReturn = ctrl->dequeueMsgHigh(rosControl);
    errReturn = ctrl->dequeueMsgLow(rosControl);
    while(!rosControl->checkCommandDone())
      {
	errReturn = ctrl->dequeueMsgHigh(rosControl);
	sleep(.1);
	ros::spinOnce();
      }
    if(errReturn.getStatus() == QueueEmpty || errReturn.getStatus() == CmdComplete)
  	  {
  	  	//either no command to process or command was processed successfully
  	  }
	  else
  	  {
	    printf("Error in command queue %s.\n", errReturn.getError());
  	  	ros::shutdown();
  	  	return;
  	  }
	  ros::spinOnce();
  }
}
int
main (int argc, char* argv[])
{
  Controller *ctrl;
  
  void *dequeueTask = NULL;

  ctrl = new Controller();
  ros::init(ros::VP_string(), "canonicalController");
  ros::start();
  rosControl = new RosInf();
  FILE * inFile;
  CommandParser parser;
  CommandParser outputParser;
  CloseGripperMsg closeGripper;
  EndCanonMsg endCanon;
  StopObjectScanMsg stopScan;
  // this code uses the ULAPI library to provide portability
  // between different operating systems and architectures
  if (ULAPI_OK != ulapi_init (UL_USE_DEFAULT))
    {
      printf ("can't initialize ulapi");
      return 1;
    }
    
  dequeueTask = ulapi_task_new ();
  ulapi_task_start (dequeueTask, dequeueThread, (void *) ctrl, ulapi_prio_lowest (),
		    1);
  
  
  inFile = fopen(argv[1], "r");
  if (inFile == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
  if (parser.readCommandFile(inFile, ctrl))
    exit(1);
  fclose(inFile);
  
  
  sleep(2);
  
  remove("output_commands.txt");
  
  MoveThroughToMsg scanPattern;
  
  Point *startPoint = new Point("start_scan");
  startPoint->sethasPoint_X(-.163);
  startPoint->sethasPoint_Y(0.6205);
  startPoint->sethasPoint_Z(0.3);
  generateScanPattern(&scanPattern, rosControl, startPoint, .62, .9);
  
  ctrl->queueMsgLow(&scanPattern);
  ctrl->queueMsgLow(&stopScan);
  //spin on output file
  while(ros::ok())
  {
  	inFile = fopen("output_commands.txt", "r");
  	if (inFile != NULL)
  	{
  		if(outputParser.readCommandFile(inFile, ctrl))
  			exit(1);
  		fclose(inFile);
  		remove("output_commands.txt");
  	}
  	ros::Duration(0.1).sleep();
  }
  ros::shutdown();
  return 1;
}
