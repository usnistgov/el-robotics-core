/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "scoreKittingClasses.hh"

#define INDENT 2

/*********************************************************************/
/*********************************************************************/

/* class ScoreKittingFile

*/

ScoreKittingFile::ScoreKittingFile() {}

ScoreKittingFile::ScoreKittingFile(
  XmlVersion * versionIn,
  XmlHeaderForScoreKitting * headerIn,
  scoreKittingType * scoreKittingIn)
{
  version = versionIn;
  header = headerIn;
  scoreKitting = scoreKittingIn;
}

ScoreKittingFile::~ScoreKittingFile() {}

void ScoreKittingFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<scoreKitting\n");
  header->printSelf(outFile);
  scoreKitting->printSelf(outFile);
  fprintf(outFile, "</scoreKitting>\n");
}

/*********************************************************************/

/* class factorType

*/

factorType::factorType() {}

factorType::factorType(
 XmlBoolean * isAdditiveIn,
 XmlUnsignedInt * weightIn)
{
  isAdditive = isAdditiveIn;
  weight = weightIn;
}

factorType::~factorType() {}

void factorType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<isAdditive>");
  isAdditive->printSelf(outFile);
  fprintf(outFile, "</isAdditive>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<weight>");
  weight->printSelf(outFile);
  fprintf(outFile, "</weight>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class factorValueOptType

*/

factorValueOptType::factorValueOptType() {}

factorValueOptType::factorValueOptType(
 XmlBoolean * isAdditiveIn,
 XmlUnsignedInt * weightIn,
 valueFunctionType * valueFunctionIn) :
  factorType(
    isAdditiveIn,
    weightIn)
{
  valueFunction = valueFunctionIn;
  printTypp = false;
}

factorValueOptType::~factorValueOptType() {}

void factorValueOptType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"factorValueOptType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<isAdditive>");
  isAdditive->printSelf(outFile);
  fprintf(outFile, "</isAdditive>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<weight>");
  weight->printSelf(outFile);
  fprintf(outFile, "</weight>\n");
  if (valueFunction)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<valueFunction");
      valueFunction->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</valueFunction>\n");
    }
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class factorValueReqType

*/

factorValueReqType::factorValueReqType() {}

factorValueReqType::factorValueReqType(
 XmlBoolean * isAdditiveIn,
 XmlUnsignedInt * weightIn,
 valueFunctionType * valueFunctionIn) :
  factorType(
    isAdditiveIn,
    weightIn)
{
  valueFunction = valueFunctionIn;
  printTypp = false;
}

factorValueReqType::~factorValueReqType() {}

void factorValueReqType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"factorValueReqType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<isAdditive>");
  isAdditive->printSelf(outFile);
  fprintf(outFile, "</isAdditive>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<weight>");
  weight->printSelf(outFile);
  fprintf(outFile, "</weight>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<valueFunction");
  valueFunction->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</valueFunction>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class nonNegativeReal

*/

nonNegativeReal::nonNegativeReal() :
  XmlDouble() {}

nonNegativeReal::nonNegativeReal(
 char * valIn) : XmlDouble(valIn)
{
  if (!bad)
    bad = ((val < 0.0));
}

nonNegativeReal::~nonNegativeReal() {}

bool nonNegativeReal::nonNegativeRealIsBad()
{
  if (XmlDoubleIsBad())
    return true;
  return ((val < 0.0));
}

void nonNegativeReal::printSelf(FILE * outFile)
{
  if (nonNegativeRealIsBad())
    {
      fprintf(stderr, "bad nonNegativeReal value, ");
      XmlDouble::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlDouble::printSelf(outFile);
}

/*********************************************************************/

/* class scoreKittingType

*/

scoreKittingType::scoreKittingType() {}

scoreKittingType::scoreKittingType(
 factorValueOptType * rightStuffIn,
 factorValueOptType * commandExecutionIn,
 factorValueOptType * distanceIn,
 factorValueOptType * timeIn,
 factorValueReqType * uselessCommandsIn)
{
  rightStuff = rightStuffIn;
  commandExecution = commandExecutionIn;
  distance = distanceIn;
  time = timeIn;
  uselessCommands = uselessCommandsIn;
}

scoreKittingType::~scoreKittingType() {}

void scoreKittingType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<rightStuff");
  rightStuff->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</rightStuff>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<commandExecution");
  commandExecution->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</commandExecution>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<distance");
  distance->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</distance>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<time");
  time->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</time>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<uselessCommands");
  uselessCommands->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</uselessCommands>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class taperSideType

*/

taperSideType::taperSideType() :
  XmlString() {}

taperSideType::taperSideType(
 char * valIn) :
  XmlString(valIn)
{
  if (!bad)
    bad = (strcmp(val.c_str(), "plus") &&
           strcmp(val.c_str(), "minus") &&
           strcmp(val.c_str(), "both"));
}

taperSideType::~taperSideType() {}

bool taperSideType::taperSideTypeIsBad()
{
  return (strcmp(val.c_str(), "plus") &&
          strcmp(val.c_str(), "minus") &&
          strcmp(val.c_str(), "both"));
}

void taperSideType::printSelf(FILE * outFile)
{
  if (taperSideTypeIsBad())
    {
      fprintf(stderr, "bad taperSideType value, ");
      XmlString::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlString::printSelf(outFile);
}

/*********************************************************************/

/* class valueFunctionType

*/

valueFunctionType::valueFunctionType() {}

valueFunctionType::valueFunctionType(
 XmlDouble * bestValueIn,
 nonNegativeReal * widthIn,
 nonNegativeReal * taperIn,
 taperSideType * taperSideIn)
{
  bestValue = bestValueIn;
  width = widthIn;
  taper = taperIn;
  taperSide = taperSideIn;
}

valueFunctionType::~valueFunctionType() {}

void valueFunctionType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<bestValue>");
  bestValue->printSelf(outFile);
  fprintf(outFile, "</bestValue>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<width>");
  width->printSelf(outFile);
  fprintf(outFile, "</width>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<taper>");
  taper->printSelf(outFile);
  fprintf(outFile, "</taper>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<taperSide>");
  taperSide->printSelf(outFile);
  fprintf(outFile, "</taperSide>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

XmlHeaderForScoreKitting::XmlHeaderForScoreKitting() {}

XmlHeaderForScoreKitting::XmlHeaderForScoreKitting(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForScoreKitting::~XmlHeaderForScoreKitting() {}

void XmlHeaderForScoreKitting::printSelf(
  FILE * outFile)
{
  fprintf(outFile, "  xmlns=\"urn:Kitting\"\n");
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

