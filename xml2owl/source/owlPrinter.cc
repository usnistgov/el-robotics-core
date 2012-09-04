#include <stdio.h>   // fprintf
#include <string.h>  // strlen
#include <stdlib.h>  // exit
#include "kittingClassesOwl.hh"

extern KittingWorkStationFile * KittingWorkStationTree;
extern FILE * yyin;
extern int yyparse();

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  FILE * outFile;

  if (argc != 3)
    {
      fprintf(stderr, "Usage: %s <data file name> <owl file name>\n", argv[0]);
      exit(1);
    }
  yyin = fopen(argv[1], "r");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
  yyparse();
  fclose(yyin);
  outFile = fopen(argv[2], "w");
  if (outFile == 0)
    {
      fprintf(stderr, "unable to open file %s for writing\n", argv[2]);
      exit(1);
    }
  KittingWorkStationTree->printOwl(outFile);
  fclose(outFile);
  return 0;
}
