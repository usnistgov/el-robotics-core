/*********************************************************************/

#ifndef GEOMETRYSCHEMA3_OWL_HH
#define GEOMETRYSCHEMA3_OWL_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

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
  void printOwl(FILE * outFile);
  void printSelf(FILE * outFile) {}

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
  void printSelf(FILE * outFile) {}
  void printOwl(FILE * outFile);

  XmlID * Name;
  std::list<CircleType *> * CircleInstance;
  std::list<SphereType *> * SphereInstance;
  static std::set<std::string> individuals;
};

/*********************************************************************/

class PointType :
  public XmlSchemaInstanceBase
{
public:
  PointType();
  PointType(
    XmlID * NameIn,
    XmlDouble * XIn,
    XmlDouble * YIn,
    XmlDouble * ZIn);
  ~PointType();
  void printSelf(FILE * outFile) {}
  void printOwl(FILE * outFile);

  XmlID * Name;
  XmlDouble * X;
  XmlDouble * Y;
  XmlDouble * Z;
  static std::set<std::string> individuals;
};

/*********************************************************************/

class RoundThingType :
  public XmlSchemaInstanceBase
{
public:
  RoundThingType();
  RoundThingType(
    XmlID * NameIn,
    XmlDouble * RadiusIn,
    PointType * CenterIn);
  ~RoundThingType();
  void printSelf(FILE * outFile) {}
  void printOwl(FILE * outFile);

  XmlID * Name;
  XmlDouble * Radius;
  PointType * Center;
  static std::set<std::string> individuals;
};

/*********************************************************************/

class SphereType :
  public RoundThingType
{
public:
  SphereType();
  SphereType(
    XmlID * NameIn,
    XmlDouble * RadiusIn,
    PointType * CenterIn);
  ~SphereType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VectorType :
  public XmlSchemaInstanceBase
{
public:
  VectorType();
  VectorType(
    XmlID * NameIn,
    XmlDouble * IIn,
    XmlDouble * JIn,
    XmlDouble * KIn);
  ~VectorType();
  void printSelf(FILE * outFile) {}
  void printOwl(FILE * outFile);

  XmlID * Name;
  XmlDouble * I;
  XmlDouble * J;
  XmlDouble * K;
  static std::set<std::string> individuals;
};

/*********************************************************************/

class CircleType :
  public RoundThingType
{
public:
  CircleType();
  CircleType(
    XmlID * NameIn,
    XmlDouble * RadiusIn,
    PointType * CenterIn,
    VectorType * NormalIn);
  ~CircleType();
  void printOwl(FILE * outFile);

  VectorType * Normal;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class XmlHeaderForCirclesAndSpheres
{
public:
  XmlHeaderForCirclesAndSpheres();
  XmlHeaderForCirclesAndSpheres(
    SchemaLocation * locationIn);
  ~XmlHeaderForCirclesAndSpheres();
  void printOwl(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // GEOMETRYSCHEMA3_OWL_HH
