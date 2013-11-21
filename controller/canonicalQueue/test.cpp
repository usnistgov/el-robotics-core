// code currently broken!

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
/*!
  \file   test.cc
  \brief  test controller interface library by reading and writing commands to the queue

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include "ulapi.hh"
#include "controller.hh"
#include "canonicalMsg.hh"

Controller *ctrl; // from controller.hh don't like global, but I need it in the signal callback

void cmdStatusCheck(int sig)
{
  itimerval timeToWait;
  StatusMsg errReturn;
  statusReturn status;

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
  StatusMsg statusMsg;
  CanonicalMsg *canonicalPt;
  CanonicalHdr myHeader;
  static int once = 0;

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
      myHeader = errReturn.getHeader();
      printf( "Test::dequeueThread:Dequeued message %d of time %f with status %s\n",
	      myHeader.msgID, myHeader.time,
	      statusMsg.getError() );
      errReturn.setStatus(CmdComplete);
      if( once == 0 )
	{
	  sleep(5);
	  once++;
	  if( once > 3 ) once = 0;
	}
      dequeueCtrl->queueMsgStatus(&statusMsg);
    }
}

int
main ()
{
  CloseGripperMsg closeGripper;
  CloseToolChangerMsg closeToolChanger;
  DwellMsg dwell(987.654);
  EndCanonMsg endCanon(18);
  InitCanonMsg initCanon;
  OpenGripperMsg openGripper;
  OpenToolChangerMsg openToolChanger;
  MessageMsg message("This is a test message");
  void *dequeueTask = NULL;
  StatusMsg statusMsg;

  ctrl = new Controller();
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
  printf( "\tQueue InitCanon\n" );
  ctrl->queueMsgLow(&initCanon);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
    //  sleep(1);
  printf( "\tQueue dwell\n" );
  ctrl->queueMsgLow(&dwell);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  //  sleep(2);
  printf( "\tQueue openGripper\n" );
  ctrl->queueMsgLow(&openGripper);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  //  sleep(2);
  printf( "\tQueue closeGripper\n" );
  ctrl->queueMsgLow(&closeGripper);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  printf( "\tQueue messageMsg\n" );
  ctrl->queueMsgLow(&message);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  printf( "\tQueue openToolChanger\n" );
  ctrl->queueMsgLow(&openToolChanger);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  printf( "\tQueue closeToolChanger\n" );
  ctrl->queueMsgLow(&closeToolChanger);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  sleep(10);
  printf( "\tQueue endCanon\n" );
  ctrl->queueMsgLow(&endCanon);
  statusMsg = ctrl->dequeueMsgStatus();
  printf( "\tMainThread got status:msg: %d status %s\n",
	  statusMsg.getHeader().msgID, statusMsg.getError() );
  sleep(10);
  return 1;
}
