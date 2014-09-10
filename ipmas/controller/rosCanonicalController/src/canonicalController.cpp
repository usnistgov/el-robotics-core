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
/**
   \defgroup controller Controller Node
   \file canonicalController.cpp
   \author Stephen Balakirsky
   \date Jan 22, 2014
   This file contains the implementation of a controller that couples the 
   executor's late binding with execution.


  The canonicalController contains two main threads. The first thread reads
  PDDL commands and parses them into Canonical Robot Command Language (CRCL) 
  commands. The thread works with the MySQL database to provide late binding
  of object locations to CRCL commands. The second thread provides for the
  execution of CRCL commands. The two threads communicate with each other
  through the use of semaphores that establish the success or failure of
  commands.

  Thread 1 details:
  Thread 1 is run from the main() routine of the canonicalController.cpp file.
  The process first reads command line options that include:
  'f': specifies the problem fluents file
  'i': specifies the plan file (PDDL commands)
  'k': specifies to use the keyboard instead of a file for input. Not working yet!
  'o': specifies a file to write the CRCL commands to. If not specified, stdio is used.
  'p': specifies a file prefix to use for all files.
  'r': should system attempt to connect to ros to control the actual robot?
  's': the host address of a system to use for sensor feedback.

  The process next parses the PDDL plan from the file (or keyboard) using parsePlanInstance()
  or parseLinePlanInstance(). The parameters are stored, fluents read, and problem file parsed.

  Next, the output CRCL plan is inialized with initializePlan. This automatically output commands
  such as InitCanon() and OpenGripper().

  The remainder of the main loop steps the plan one PDDL command at a time. Each PDDL command is 
  decomposed into one or more CRCL commands, and these are optionally sent to ROS for execution.
  The system waits for the completion of each CRCL command before transmitting the next for execution.
  ROS details are that the CommandParser queueCommand() function is called. This in turn
  parses the command's arguments and calls the controllers queueMsgLow() routine.
  The queueMsgLow() routine pushed the new command onto the cmdQueueLow and gives the
  lowHighMsgMutex.The routine then waits for the statusMsgMutex in order to return
  the command's execution status.

  Thread 2 details:
  Thread 2 is contained in the routine dequeueThread()
  This thread blocks on a call to dequeueMsgLow() which waits for and then executes 
  a command. The routine then kicks off the first call to the cmdStatusCheck alarm function 
  to see the command completion status. After kicking off this call, the routine returns to 
  blocking on the dequeueMsgLow() call.

*/
#include <stdio.h>
#include <vector>
#include <sstream>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

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

  timeToWait = ctrl->ctrlStatusCheck(errReturn, rosControl);
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
  struct sigaction action;
  Controller *dequeueCtrl = reinterpret_cast < Controller *>(arg);

  printf( "canonicalController::dequeueThread starting thread\n" );
  action.sa_handler = cmdStatusCheck;
  // set up signal handler for command status checking
  sigaction (SIGALRM, &action, NULL);

  while(ros::ok())
    {
      dequeueCtrl->dequeueMsgLow(rosControl, 1);
      //      printf("canonicalController::dequeueThread:dequeueThread pulled command from queue\n" );
      cmdStatusCheck(SIGALRM);
      ros::spinOnce();
    }
  printf( "canonicalController::dequeueThread exiting thread\n" );
}

int main (int argc, char* argv[])
{
  std::string fluentsFile = "a2b2c1/problem-fluents-a2b2c1.pddl";
  std::string outputFile;
  //  std::string planFile = "a2b2c1/plan_a2b2c1.txt";
  std::string planFile = "a2b2c1/testPlan.txt";
  std::string filePrefix = "../PDDLplans/";
  std::string sensorHostName = "10.108.21.213";
  std::string line;
  int useKeyboard = 0;
  int useRos = 1;
  int opt;
  int done;
  CanonicalRobotCommand *canonicalRobotCommand = NULL;
  FileOperator *fileop = NULL;
  KittingPlan *kittingplan = NULL;
  KittingPDDLProblem *kittingProb = NULL;

  void *dequeueTask = NULL;

  ctrl = new Controller();
  FILE * inFile;
  CommandParser parser(ctrl); // from commandParser.hh
  ulapi_integer result;
  struct sigaction action;
  std::string cmdString;

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
    printf("%s: using fluentsFile: %s, planFile: %s, and outputFile: %s\n", 
	   argv[0], fluentsFile.c_str(),
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

  done = 0;
  while(!done)
    {
      if( !useKeyboard )
	{
	  kittingplan->parsePlanInstance(planFile.c_str());
	  done = 1;
	}
      else
	{	
	  kittingplan->clearPlan();
	  getline(cin, line);
	  //	    done = 1;
	  printf( "Received: %s\n", line.c_str() );
	  kittingplan->parseLinePlanInstance(line);
	}
      kittingplan->storeParam();
      if( !kittingProb->readFluents(fluentsFile.c_str()))
	{
	  printf( "canonicalController:: error from readFluents, exiting!\n");
	  exit(1);
	}
      kittingProb->parsePDDLProblem(kittingplan);
      //      canonicalRobotCommand->interpretPlan(kittingplan);
      canonicalRobotCommand->initializePlan(kittingplan);

      StatusMsg errReturn;
      while(canonicalRobotCommand->stepPlan(kittingplan, ACTION))
	{
	  while( (cmdString=canonicalRobotCommand->getNextCRCL()) != "" )
	    {
	      printf( "\tcanonicalController::main: %s\n", cmdString.c_str() );
	      if( useRos )
		{
		errReturn.setStatus(SystemWorking);
		parser.queueCommand(cmdString);
		while(errReturn.getStatus() != SystemDone &&
		      errReturn.getStatus() != CmdError &&
		      errReturn.getStatus() != CmdComplete )
		  {
		    errReturn = ctrl->dequeueMsgStatus(1);
		    //		    printf( "\t\tcanonicalController.cpp: Received status " );
		    //		    errReturn.print();
		    ros::spinOnce();
		  }
		printf( "\tcanonicalController.cpp: Received status " );
		errReturn.print();
		}
	    }
	  canonicalRobotCommand->stepPlan(kittingplan, EFFECT);
	}
      delete kittingplan;
      delete fileop;
      delete kittingProb;
      delete canonicalRobotCommand;
    }
  /*
  // read commands, parse, and place in queue
  if (parser.readCommandFile(inFile, ctrl))
    exit(1);
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

