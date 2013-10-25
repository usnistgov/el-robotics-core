#include <stdio.h>   // fprintf
#include <string.h>  // strlen
#include <stdlib.h>  // exit
#include "owlInstancePrinter.hh"
#include "owlKittingWorkstationClasses.hh"

extern KittingWorkstationFile * KittingWorkstationTree;
extern FILE * yyin;
extern int yyparse();

OwlInstancePrinter printer;

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  FILE * outFile;
  int n;          // for finding beginning of file name

  if (argc != 5)
    {
      fprintf(stderr, "Usage: %s <xmlInst> <owlInst> <owlClass> <uri>\n",
              argv[0]);
      fprintf(stderr, "xmlInst = path to XML instance file to read\n");
      fprintf(stderr, "owlInst = name of OWL instance file to write\n");
      fprintf(stderr, "owlClass = name of OWL class file\n");
      fprintf(stderr, "uri = URI to put in header\n");
      fprintf(stderr, "example: owlKittingPrinter data/goal.xml goal.owl kitClas.owl http://el/ontol\n");
      exit(1);
    }
  n = (strlen(argv[1]) - 4);
  if (strcmp(argv[1] + n, ".xml"))
    {
      fprintf(stderr, "file name %s must end with .xml\n", argv[1]);
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
  printer.outFileName = argv[2];
  printer.classFileName = argv[3];
  printer.uri = argv[4];
  KittingWorkstationTree->printOwl(outFile);
  fclose(outFile);
  return 0;
}
