/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "PointAndVectorClasses.hh"

#define INDENT 2

/*********************************************************************/
/*********************************************************************/

/* class PointType

*/

PointType::PointType() {}

PointType::PointType(
 XmlID * NameIn,
 XmlDouble * XIn,
 XmlDouble * YIn,
 XmlDouble * ZIn)
{
  Name = NameIn;
  X = XIn;
  Y = YIn;
  Z = ZIn;
}

PointType::~PointType() {}

void PointType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<X>");
  X->printSelf(outFile);
  fprintf(outFile, "</X>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Y>");
  Y->printSelf(outFile);
  fprintf(outFile, "</Y>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Z>");
  Z->printSelf(outFile);
  fprintf(outFile, "</Z>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class RoundThingType

*/

RoundThingType::RoundThingType() {}

RoundThingType::RoundThingType(
 XmlID * NameIn,
 XmlDouble * RadiusIn,
 PointType * CenterIn)
{
  Name = NameIn;
  Radius = RadiusIn;
  Center = CenterIn;
}

RoundThingType::~RoundThingType() {}

void RoundThingType::printSelf(FILE * outFile)
{
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

/* class VectorType

*/

VectorType::VectorType() {}

VectorType::VectorType(
 XmlID * NameIn,
 XmlDouble * IIn,
 XmlDouble * JIn,
 XmlDouble * KIn)
{
  Name = NameIn;
  I = IIn;
  J = JIn;
  K = KIn;
}

VectorType::~VectorType() {}

void VectorType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<I>");
  I->printSelf(outFile);
  fprintf(outFile, "</I>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<J>");
  J->printSelf(outFile);
  fprintf(outFile, "</J>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<K>");
  K->printSelf(outFile);
  fprintf(outFile, "</K>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

