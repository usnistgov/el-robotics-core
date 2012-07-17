#include <stdlib.h>         // exit
#include "ulapi.hh"
#include "controller.hh"
#include "canonicalMsg.hh"
#include "commandParser.hh"

void
dequeueThread (void *arg)
{
  Controller *ctrl = reinterpret_cast < Controller *>(arg);	
  void *myVoid;
  int errReturn;

  for(;;)
    {
      errReturn = ctrl->dequeueMsg(myVoid);
      if( errReturn == 0)
	sleep(1);
      else if( errReturn == 2 )
	{
	  printf( "End of canon and thread\n" );
	  return;
	}
      else
	{
	  printf( "Error from parser\n" );
	  return;
	}
    }
}

int main(
 int argc,
 char * argv[])
{
  FILE * inFile;
  CommandParser parser;
  std::list<CanonicalMsg *> commands; //commands read from file
  Controller *ctrl;
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

  inFile = fopen(argv[1], "r");
  if (inFile == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
  if (parser.readCommandFile(inFile, ctrl))
    exit(1);
  fclose(inFile);
  
  //  sleep(30);
  ulapi_task_join(dequeueTask);
}
