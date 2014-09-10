/*********************************************************************/

#ifndef SCOREKITTING_HH
#define SCOREKITTING_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class ScoreKittingFile;
class factorType;
class factorValueOptType;
class factorValueReqType;
class nonNegativeReal;
class scoreKittingType;
class taperSideType;
class valueFunctionType;
class XmlHeaderForScoreKitting;

/*********************************************************************/
/*********************************************************************/

class ScoreKittingFile :
  public XmlSchemaInstanceBase
{
public:
  ScoreKittingFile();
  ScoreKittingFile(
    XmlVersion * versionIn,
    XmlHeaderForScoreKitting * headerIn,
    scoreKittingType * scoreKittingIn);
  ~ScoreKittingFile();
  void printSelf(FILE * outFile);

  XmlVersion * version;
  XmlHeaderForScoreKitting * header;
  scoreKittingType * scoreKitting;
};

/*********************************************************************/

class factorType :
  public XmlSchemaInstanceBase
{
public:
  factorType();
  factorType(
    XmlBoolean * isAdditiveIn,
    XmlUnsignedInt * weightIn);
  ~factorType();
  void printSelf(FILE * outFile);

  XmlBoolean * isAdditive;
  XmlUnsignedInt * weight;
};

/*********************************************************************/

class factorValueOptType :
  public factorType
{
public:
  factorValueOptType();
  factorValueOptType(
    XmlBoolean * isAdditiveIn,
    XmlUnsignedInt * weightIn,
    valueFunctionType * valueFunctionIn);
  ~factorValueOptType();
  void printSelf(FILE * outFile);

  valueFunctionType * valueFunction;

  bool printTypp;
};

/*********************************************************************/

class factorValueReqType :
  public factorType
{
public:
  factorValueReqType();
  factorValueReqType(
    XmlBoolean * isAdditiveIn,
    XmlUnsignedInt * weightIn,
    valueFunctionType * valueFunctionIn);
  ~factorValueReqType();
  void printSelf(FILE * outFile);

  valueFunctionType * valueFunction;

  bool printTypp;
};

/*********************************************************************/

class nonNegativeReal :
  public XmlDouble
{
public:
  nonNegativeReal();
  nonNegativeReal(
    char * valIn);
  ~nonNegativeReal();
  bool nonNegativeRealIsBad();
  void printSelf(FILE * outFile);
};

/*********************************************************************/

class scoreKittingType :
  public XmlSchemaInstanceBase
{
public:
  scoreKittingType();
  scoreKittingType(
    factorValueOptType * rightStuffIn,
    factorValueOptType * commandExecutionIn,
    factorValueOptType * distanceIn,
    factorValueOptType * timeIn,
    factorValueReqType * uselessCommandsIn);
  ~scoreKittingType();
  void printSelf(FILE * outFile);

  factorValueOptType * rightStuff;
  factorValueOptType * commandExecution;
  factorValueOptType * distance;
  factorValueOptType * time;
  factorValueReqType * uselessCommands;
};

/*********************************************************************/

class taperSideType :
  public XmlString
{
public:
  taperSideType();
  taperSideType(
    char * valIn);
  ~taperSideType();
  bool taperSideTypeIsBad();
  void printSelf(FILE * outFile);
};

/*********************************************************************/

class valueFunctionType :
  public XmlSchemaInstanceBase
{
public:
  valueFunctionType();
  valueFunctionType(
    XmlDouble * bestValueIn,
    nonNegativeReal * widthIn,
    nonNegativeReal * taperIn,
    taperSideType * taperSideIn);
  ~valueFunctionType();
  void printSelf(FILE * outFile);

  XmlDouble * bestValue;
  nonNegativeReal * width;
  nonNegativeReal * taper;
  taperSideType * taperSide;
};

/*********************************************************************/

class XmlHeaderForScoreKitting
{
public:
  XmlHeaderForScoreKitting();
  XmlHeaderForScoreKitting(
    SchemaLocation * locationIn);
  ~XmlHeaderForScoreKitting();
  void printSelf(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // SCOREKITTING_HH
