/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/
/*!
  \file   test.cc
  \brief  test controller interface library by reading and writing commands to the queue

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include <stdio.h>
#include "ulapi.hh"
#include "controller.hh"
#include "canonicalMsg.hh"

void
dequeueThread (void *arg)
{
  Controller *ctrl = reinterpret_cast < Controller *>(arg);	
  void *myVoid;

  for(;;)
    {
      if( ctrl->dequeueMsg(myVoid) == 0)
	sleep(1);
    }
}

int
main ()
{
  Controller *ctrl;
  CloseGripperMsg closeGripper;
  CloseToolChangerMsg closeToolChanger;
  DwellMsg dwell(987.654);
  EndCanonMsg endCanon(18);
  InitCanonMsg initCanon;
  OpenGripperMsg openGripper;
  OpenToolChangerMsg openToolChanger;
  MessageMsg message("This is a test message");
  void *dequeueTask = NULL;

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

  printf( "Queue InitCanon\n" );
  ctrl->queueMsg(&initCanon);
  //  sleep(1);
  printf( "Queue dwell\n" );
  ctrl->queueMsg(&dwell);
  //  sleep(2);
  printf( "Queue openGripper\n" );
  ctrl->queueMsg(&openGripper);
  //  sleep(2);
  printf( "Queue closeGripper\n" );
  ctrl->queueMsg(&closeGripper);
  printf( "Queue messageMsg\n" );
  ctrl->queueMsg(&message);
  printf( "Queue openToolChanger\n" );
  ctrl->queueMsg(&openToolChanger);
  printf( "Queue closeToolChanger\n" );
  ctrl->queueMsg(&closeToolChanger);
  sleep(10);
  printf( "Queue endCanon\n" );
  ctrl->queueMsg(&endCanon);
  sleep(10);
  return 1;
}
