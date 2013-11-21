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
#include <stdlib.h>         // exit
#include <sys/time.h>
#include <signal.h>
#include "ulapi.hh"
#include "controller.hh"
#include "canonicalMsg.hh"
#include "commandParser.hh"

Controller *ctrl; // from controller.hh don't like global, but I need it in the signal callback

void cmdStatusCheck(int sig)
{
  itimerval timeToWait;
  StatusMsg errReturn;

  timeToWait = ctrl->cmdStatusCheck(errReturn);
  if( timeToWait.it_value.tv_sec <= 0 && timeToWait.it_value.tv_usec <= 0 )
    ctrl->queueMsgStatus(&errReturn);
  else
    setitimer(ITIMER_REAL, &timeToWait,NULL);
}

void
dequeueThread (void *arg)
{
  Controller *dequeueCtrl = reinterpret_cast < Controller *>(arg);	
  void *myVoid;
  StatusMsg errReturn;

  errReturn.setStatus(CmdComplete);

  for(;;)
    {
      dequeueCtrl->dequeueMsgLow(myVoid);
      cmdStatusCheck(SIGALRM);
      errReturn.setStatus(SystemWorking);
      while(errReturn.getStatus() != SystemDone ||
	    errReturn.getStatus() != CmdError ||
	    errReturn.getStatus() != CmdComplete )
	{
	  errReturn = dequeueCtrl->dequeueMsgStatus(1);
	  printf( "Received status\n" );
	  errReturn.print();
	}
      if( errReturn.getStatus() == SystemDone )
	{
	  printf( "End of canon and thread\n" );
	  ulapi_task_exit(0);
	}
      else if( errReturn.getStatus() == CmdError )
	{
	  printf( "Error from parser\n" );
	  ulapi_task_exit(1);
	}
    }
}

int main(
 int argc,
 char * argv[])
{
  FILE * inFile;
  CommandParser parser; // from commandParser.hh
  std::list<CanonicalMsg *> commands; //commands read from file
  void *dequeueTask = NULL;
  ulapi_integer result;
  struct sigaction action;

  action.sa_handler = cmdStatusCheck;

  // set up signal handler for command status checking
  sigaction (SIGALRM, &action, NULL);

  ctrl = new Controller();
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

  inFile = fopen(argv[1], "r");
  if (inFile == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }

  // read commands, parse, and place in queue
  if (parser.readCommandFile(inFile, ctrl))
    exit(1);
  fclose(inFile);
  
  //  sleep(30);
  ulapi_task_join(dequeueTask, &result);
  if( result == 0 )
    printf( "Sucessful completion\n" );
  else
    printf( "Error from commandParserMain thread\n" );
}
