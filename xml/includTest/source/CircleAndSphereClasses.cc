/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "CircleAndSphereClasses.hh"

#define INDENT 2

/*********************************************************************/
/*********************************************************************/

/* class CircleType

*/

CircleType::CircleType() {}

CircleType::CircleType(
 XmlID * NameIn,
 XmlDouble * RadiusIn,
 PointType * CenterIn,
 VectorType * NormalIn) :
  RoundThingType(
    NameIn,
    RadiusIn,
    CenterIn)
{
  Normal = NormalIn;
  printTypp = false;
}

CircleType::~CircleType() {}

void CircleType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"CircleType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Radius>");
  Radius->printSelf(outFile);
  fprintf(outFile, "</Radius>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Center");
  Center->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Center>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Normal");
  Normal->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Normal>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SphereType

*/

SphereType::SphereType() {}

SphereType::SphereType(
 XmlID * NameIn,
 XmlDouble * RadiusIn,
 PointType * CenterIn) :
  RoundThingType(
    NameIn,
    RadiusIn,
    CenterIn)
{
  printTypp = false;
}

SphereType::~SphereType() {}

void SphereType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SphereType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Radius>");
  Radius->printSelf(outFile);
  fprintf(outFile, "</Radius>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Center");
  Center->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Center>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

