#include <stdio.h>   // fprintf
#include <string.h>  // strlen
#include <stdlib.h>  // exit
#include "owlInstancePrinter.hh"
#include "owlSoapClasses.hh"

extern SOAPFile * SOAPTree;
extern FILE * yyin;
extern int yyparse();

OwlInstancePrinter printer;

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  FILE * outFile;
  int n;          // for finding beginning of file name

  if (argc != 4)
    {
      fprintf(stderr, "Usage: %s <xmlInstance> <owlInstance> <uri>\n",
              argv[0]);
      fprintf(stderr, "xmlInstance = path to XML instance file to read\n");
      fprintf(stderr, "owlInstance = name of OWL instance file to write\n");
      fprintf(stderr, "uri = URI to put in header\n");
      fprintf(stderr, "example: %s data/abc.xml abc.owl http://ont\n",
              argv[0]);
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
  fprintf(outFile,"Prefix(xsd:=<http://www.w3.org/2001/XMLSchema#>)\n"
	  "Prefix(owl:=<http://www.w3.org/2002/07/owl#>)\n"
	  "Prefix(xml:=<http://www.w3.org/XML/1998/namespace>)\n"
	  "Prefix(rdf:=<http://www.w3.org/1999/02/22-rdf-syntax-ns#>)\n"
	  "Prefix(rdfs:=<http://www.w3.org/2000/01/rdf-schema#>)\n");
  fprintf(outFile, "Prefix(:=<%s/%s#>)\n", argv[3], argv[2]);
  fprintf(outFile, "Prefix(soap:=<%s/soapClasses.owl#>)\n", argv[3]);
  fprintf(outFile, "Prefix(ktw:=<%s/kittingWorkstationClasses.owl#>)\n", argv[3]);
  fprintf(outFile, "Ontology(<%s/%s>\n", argv[3], argv[2]);
  fprintf(outFile, "Import(<file:soapClasses.owl>)\n");
  SOAPTree->printOwl(outFile);
  fclose(outFile);
  return 0;
}
