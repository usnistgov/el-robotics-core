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
#include <stdio.h>
#include <vector>
#include <sstream>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

#include "database/Point.h"
#include "database/Vector.h"
#include "ros/ros.h"
#include "rosInf.hh"
#include "ulapi.hh"
#include "controller.hh"
#include "commandParser.hh"
#include "canonicalMsg.hh"
#include "CanonicalRobotCommand.hh"

RosInf *rosControl; // from rosInf.hh
Controller *ctrl; // from controller.hh don't like global, but I need it in the signal callback
  

/**
   \file canonicalController.cpp
   \author Stephen Balakirsky
   \date Jan 22, 2014
   This file contains the implementation of a controller that couples the executor's late binding 
   with execution.

   There are two threads: the dequeuing thread that pulls fully formed CRCL commands from a stack 
   and executes them and the main function that binds PDDL commands to actual instances and creates 
   the CRCL commands. Locations of objects are updated automatically through the sensor processing 
   system.
	
*/

/**
   \brief Checks to see if we have received a valid status from a command.
   
   If a status has been received, the "timeToWait" will be 0. This status will then be
   placed in the status message queue. If a status has not been received, a new
   timer will be set and we will then check again.

   \param sig Not used, but the signal facility returns it anyway!
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


/**
   \brief Dequeueing loop for CRCL controller
   \param arg Pointer to the controller that dequeues command messages
*/
void dequeueThread (void *arg)
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

int main (int argc, char* argv[])
{
  std::string fluentsFile = "a2b2c1/problem-fluents-a2b2c1.pddl";
  std::string outputFile;
  std::string planFile = "a2b2c1/plan_a2b2c1.txt";
  std::string filePrefix = "../PDDLplans/";
  std::string sensorHostName = "10.108.21.213";
  int useKeyboard = 0;
  int useRos = 1;
  int opt;
  CanonicalRobotCommand *canonicalRobotCommand = NULL;
  FileOperator *fileop = NULL;
  KittingPlan *kittingplan = NULL;
  KittingPDDLProblem *kittingProb = NULL;

  void *dequeueTask = NULL;

  ctrl = new Controller();
  FILE * inFile;
  CommandParser parser; // from commandParser.hh
  ulapi_integer result;
  struct sigaction action;

  action.sa_handler = cmdStatusCheck;

  // set up signal handler for command status checking
  sigaction (SIGALRM, &action, NULL);

  // this code uses the ULAPI library to provide portability
  // between different operating systems and architectures
  if (ULAPI_OK != ulapi_init (UL_USE_DEFAULT))
    {
      printf ("can't initialize ulapi");
      return 1;
    }

  /* read command arguments */    
  while ((opt = getopt (argc, argv, "f:i:ko:p:r:s:")) != -1)
    switch (opt)
      {
      case 'f': // problem fluents file
	fluentsFile = std::string(optarg);
	break;
      case 'i': // plan file
	planFile = std::string(optarg);
	break;
      case 'k': // use keyboard input
	useKeyboard = 1;
	break;
      case 'o': // plan file
	outputFile = std::string(optarg);
	break;
      case 'p': // file path prefix
	filePrefix = std::string(optarg);
	break;
      case 'r': // use ros?
	useRos = atoi(optarg);
	break;
      case 's': // sensor processing host
	sensorHostName = std::string(optarg);
	break;
      case '?':
	if( optopt == 'f' || optopt == 'i' || optopt == 'o' || 
	    optopt == 'p' || optopt == 'r' || optopt == 's')
	  printf("%s: option -%c requires an argument.\n", argv[0], optopt);
	else if(isprint(optopt))
	  printf("%s: unknown option '-%c'.\n", argv[0], optopt);
	else
	  printf("%s: unknown option character '\\x%x'.\n", argv[0], optopt);
	return 1;
      default:
	abort();
      }

  for( int i=optind; i<argc; i++)
    printf("%s: non-option argument %s\n", argv[0], argv[i]);
  if( optind != argc )
    {
      printf( "%s: exiting due to non-option arguments.\n", argv[0]);
      exit(1);
    }

  // add file prefix to filenames
  fluentsFile = filePrefix + fluentsFile;
  planFile = filePrefix + planFile;
  if(outputFile != "")
    outputFile = filePrefix + outputFile;
  if( useKeyboard)
    printf("%s: using stdio for input\n", argv[0]);
  else
    printf("%s: using fluentsFile: %s, planFile: %s, and outputFile: %s\n", argv[0], fluentsFile.c_str(),
	   planFile.c_str(), outputFile.c_str());

  //ROS configuration
  if( useRos )
    {
      ros::init(ros::VP_string(), "canonicalController");
      ros::start();
      rosControl = new RosInf();
      std::string globalFrame;
      ros::NodeHandle nh;
      if(!nh.getParam("usarsim/globalFrame", globalFrame))
	{
	  ROS_INFO("No global frame parameter specified, using default /odom");
	  globalFrame = "/odom";
	}
      rosControl->setGlobalFrame(globalFrame);
    }


  // start task that reads queue and executes commands
  dequeueTask = ulapi_task_new ();
  ulapi_task_start (dequeueTask, dequeueThread, (void *) ctrl, ulapi_prio_lowest (),
		    1);

  // initialize executor
  if( !useKeyboard )
    {
      canonicalRobotCommand = new CanonicalRobotCommand();
      fileop = new FileOperator;
      kittingplan = new KittingPlan;
      kittingProb = new KittingPDDLProblem;
      if( useRos )
	canonicalRobotCommand->setController(ctrl, sensorHostName);
      if( outputFile != "" )
	{
	  fileop->setCRCLFile(outputFile);
	  canonicalRobotCommand->setFileOperator(fileop);
	}
      //kittingProb->parsePDDLProblem(fluentsFile.c_str(), kittingplan);
      kittingplan->parsePlanInstance(planFile.c_str());
      kittingplan->storeParam();
      kittingProb->parsePDDLProblem(fluentsFile.c_str(), kittingplan);
      canonicalRobotCommand->interpretPlan(kittingplan);
      delete kittingplan;
      delete fileop;
      delete kittingProb;
      delete canonicalRobotCommand;
    }
  /*
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
*/  
  ulapi_task_join(dequeueTask, &result);
  if( result == 0 )
    printf( "Sucessful completion\n" );
  else
    printf( "Error from commandParserMain thread\n" );

  if( useRos )
    ros::shutdown();
  return 1;
}

