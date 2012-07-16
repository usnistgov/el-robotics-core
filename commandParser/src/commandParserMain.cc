#include <stdlib.h>         // exit
#include "commandParser.hh"

int main(
 int argc,
 char * argv[])
{
  FILE * inFile;
  CommandParser parser;
  std::list<CanonicalMsg *> commands; //commands read from file
  std::list<CanonicalMsg *>::iterator iter;
  void * uselessPointer;

  inFile = fopen(argv[1], "r");
  if (inFile == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
  if (parser.readCommandFile(inFile, &commands))
    exit(1);
  fclose(inFile);
  
  for (iter = commands.begin(); iter != commands.end(); iter++)
    (*iter)->process(uselessPointer);
}
