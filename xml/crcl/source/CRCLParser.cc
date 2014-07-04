#include <stdio.h>   // fprintf
#include <string.h>  // strlen
#include <stdlib.h>  // exit
#include "CRCLClasses.hh"

extern CRCLProgramFile * CRCLProgramTree;
extern FILE * yyin;
extern int yyparse();

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  char * outFileName;
  FILE * outFile;

  if (argc != 2)
    {
      fprintf(stderr, "Usage: %s <data file name>\n", argv[0]);
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
  outFileName = new char[strlen(argv[1]) + 5];
  sprintf(outFileName, "%secho", argv[1]);
  outFile = fopen(outFileName, "w");
  CRCLProgramTree->printSelf(outFile);
  fclose(outFile);
  return 0;
}
