#include <stdio.h>
#include <Point.h>
#include <Vector.h>
#include <vector>
#include <sstream>
#include <ros/ros.h>
#include "rosInf.hh"
#include "ulapi.hh"
#include "controller.hh"
#include "commandParser.hh"
#include "canonicalMsg.hh"

void
dequeueThread (void *arg)
{
  int errReturn;
  Controller *ctrl = reinterpret_cast < Controller *>(arg);
  ros::init(ros::VP_string(), "canonicalController");
  RosInf rosControl;
  ros::start();
  while(ros::ok())
  {
  	  errReturn = ctrl->dequeueMsg(&rosControl);
      if( errReturn == 0)
      	  sleep(1);
	  else if( errReturn == 2 )
	  {
		  printf( "End of canon and thread\n" );
		  ros::shutdown();
	  	  return;
	  }
      else
	  {
		  printf( "Error from parser\n" );
		  ros::shutdown();
		  return;
	  }
	  ros::spinOnce();
  }
  ros::shutdown();
}
int
main (int argc, char* argv[])
{
  Controller *ctrl;
  
  void *dequeueTask = NULL;

  ctrl = new Controller();
  
  FILE * inFile;
  CommandParser parser;
  
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
  
  sleep(300);
  return 1;
}
