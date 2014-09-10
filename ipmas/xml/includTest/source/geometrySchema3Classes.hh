/*********************************************************************/

#ifndef GEOMETRYSCHEMA3_HH
#define GEOMETRYSCHEMA3_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"
#include "CircleAndSphereClasses.hh"

/*********************************************************************/

class CirclesAndSpheresFile;
class CircleType;
class CirclesAndSpheresType;
class PointType;
class RoundThingType;
class SphereType;
class VectorType;
class XmlHeaderForCirclesAndSpheres;

/*********************************************************************/
/*********************************************************************/

class CirclesAndSpheresFile :
  public XmlSchemaInstanceBase
{
public:
  CirclesAndSpheresFile();
  CirclesAndSpheresFile(
    XmlVersion * versionIn,
    XmlHeaderForCirclesAndSpheres * headerIn,
    CirclesAndSpheresType * CirclesAndSpheresIn);
  ~CirclesAndSpheresFile();
  void printSelf(FILE * outFile);

  XmlVersion * version;
  XmlHeaderForCirclesAndSpheres * header;
  CirclesAndSpheresType * CirclesAndSpheres;
};

/*********************************************************************/

class CirclesAndSpheresType :
  public XmlSchemaInstanceBase
{
public:
  CirclesAndSpheresType();
  CirclesAndSpheresType(
    XmlID * NameIn,
    std::list<CircleType *> * CircleInstanceIn,
    std::list<SphereType *> * SphereInstanceIn);
  ~CirclesAndSpheresType();
  void printSelf(FILE * outFile);

  XmlID * Name;
  std::list<CircleType *> * CircleInstance;
  std::list<SphereType *> * SphereInstance;
};

/*********************************************************************/

class XmlHeaderForCirclesAndSpheres
{
public:
  XmlHeaderForCirclesAndSpheres();
  XmlHeaderForCirclesAndSpheres(
    SchemaLocation * locationIn);
  ~XmlHeaderForCirclesAndSpheres();
  void printSelf(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // GEOMETRYSCHEMA3_HH
