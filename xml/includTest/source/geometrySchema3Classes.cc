/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "geometrySchema3Classes.hh"

#define INDENT 2

/*********************************************************************/
/*********************************************************************/

/* class CirclesAndSpheresFile

*/

CirclesAndSpheresFile::CirclesAndSpheresFile() {}

CirclesAndSpheresFile::CirclesAndSpheresFile(
  XmlVersion * versionIn,
  XmlHeaderForCirclesAndSpheres * headerIn,
  CirclesAndSpheresType * CirclesAndSpheresIn)
{
  version = versionIn;
  header = headerIn;
  CirclesAndSpheres = CirclesAndSpheresIn;
}

CirclesAndSpheresFile::~CirclesAndSpheresFile() {}

void CirclesAndSpheresFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<CirclesAndSpheres\n");
  header->printSelf(outFile);
  CirclesAndSpheres->printSelf(outFile);
  fprintf(outFile, "</CirclesAndSpheres>\n");
}

/*********************************************************************/

/* class CirclesAndSpheresType

*/

CirclesAndSpheresType::CirclesAndSpheresType() {}

CirclesAndSpheresType::CirclesAndSpheresType(
 XmlID * NameIn,
 std::list<CircleType *> * CircleInstanceIn,
 std::list<SphereType *> * SphereInstanceIn)
{
  Name = NameIn;
  CircleInstance = CircleInstanceIn;
  SphereInstance = SphereInstanceIn;
}

CirclesAndSpheresType::~CirclesAndSpheresType() {}

void CirclesAndSpheresType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<CircleType *>::iterator iter;
    for (iter = CircleInstance->begin(); iter != CircleInstance->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<CircleInstance");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</CircleInstance>\n");
      }
  }
  {
    std::list<SphereType *>::iterator iter;
    for (iter = SphereInstance->begin(); iter != SphereInstance->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SphereInstance");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SphereInstance>\n");
      }
  }
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

XmlHeaderForCirclesAndSpheres::XmlHeaderForCirclesAndSpheres() {}

XmlHeaderForCirclesAndSpheres::XmlHeaderForCirclesAndSpheres(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForCirclesAndSpheres::~XmlHeaderForCirclesAndSpheres() {}

void XmlHeaderForCirclesAndSpheres::printSelf(
  FILE * outFile)
{
  fprintf(outFile, "  xmlns=\"urn:geometry\"\n");
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

