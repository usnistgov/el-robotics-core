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
      errReturn = ctrl->dequeueMsgLow(myVoid);
      if( errReturn == 0)
	sleep(1);
      else if( errReturn == 2 )
	{
	  printf( "End of canon and thread\n" );
	  ulapi_task_exit(0);
	}
      else
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
  Controller *ctrl; // from controller.hh
  void *dequeueTask = NULL;
  ulapi_integer result;

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
