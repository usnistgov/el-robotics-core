/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "owlInstancePrinter.hh"
#include "owlGeometrySchema3Classes.hh"

/*********************************************************************/
/*********************************************************************/

extern OwlInstancePrinter printer;

std::set<std::string> CircleType::individuals;
std::set<std::string> CirclesAndSpheresType::individuals;
std::set<std::string> PointType::individuals;
std::set<std::string> RoundThingType::individuals;
std::set<std::string> SphereType::individuals;
std::set<std::string> VectorType::individuals;

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

void CirclesAndSpheresFile::printOwl(FILE * outFile)
{
  std::set<std::string>::iterator iter;
  CirclesAndSpheres->printOwl(outFile);

  if (CircleType::individuals.size() > 1)
    printer.printIndividuals("cir:Circle",
       &CircleType::individuals, outFile);
  if (CirclesAndSpheresType::individuals.size() > 1)
    printer.printIndividuals("geo:CirclesAndSpheres",
       &CirclesAndSpheresType::individuals, outFile);
  if (PointType::individuals.size() > 1)
    printer.printIndividuals("poi:Point",
       &PointType::individuals, outFile);
  if (RoundThingType::individuals.size() > 1)
    printer.printIndividuals("poi:RoundThing",
       &RoundThingType::individuals, outFile);
  if (SphereType::individuals.size() > 1)
    printer.printIndividuals("cir:Sphere",
       &SphereType::individuals, outFile);
  if (VectorType::individuals.size() > 1)
    printer.printIndividuals("poi:Vector",
       &VectorType::individuals, outFile);

  fprintf(outFile, ")\n");
}

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
}

CircleType::~CircleType() {}

void CircleType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "cir:Circle", outFile);
  printer.printXmlDoubleProp("poi:hasRoundThing_Radius",
                             Name, Radius, outFile);
  printer.printObjProp("poi:hasRoundThing_Center",
                       Name, Center->Name, outFile);
  Center->printOwl(outFile);
  printer.printObjProp("cir:hasCircle_Normal",
                       Name, Normal->Name, outFile);
  Normal->printOwl(outFile);
  printer.endIndi("cir:Circle", outFile);
  individuals.insert(Name->val);
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

void CirclesAndSpheresType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "geo:CirclesAndSpheres", outFile);
  {
    std::list<CircleType *>::iterator iter;
    for (iter = CircleInstance->begin();
         iter != CircleInstance->end(); iter++)
      {
        printer.printObjProp("geo:hasCirclesAndSpheres_CircleInstance",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<SphereType *>::iterator iter;
    for (iter = SphereInstance->begin();
         iter != SphereInstance->end(); iter++)
      {
        printer.printObjProp("geo:hasCirclesAndSpheres_SphereInstance",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("geo:CirclesAndSpheres", outFile);
  individuals.insert(Name->val);
}

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

void PointType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "poi:Point", outFile);
  printer.printXmlDoubleProp("poi:hasPoint_X",
                             Name, X, outFile);
  printer.printXmlDoubleProp("poi:hasPoint_Y",
                             Name, Y, outFile);
  printer.printXmlDoubleProp("poi:hasPoint_Z",
                             Name, Z, outFile);
  printer.endIndi("poi:Point", outFile);
  individuals.insert(Name->val);
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

void RoundThingType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "poi:RoundThing", outFile);
  printer.printXmlDoubleProp("poi:hasRoundThing_Radius",
                             Name, Radius, outFile);
  printer.printObjProp("poi:hasRoundThing_Center",
                       Name, Center->Name, outFile);
  Center->printOwl(outFile);
  printer.endIndi("poi:RoundThing", outFile);
  individuals.insert(Name->val);
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
}

SphereType::~SphereType() {}

void SphereType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "cir:Sphere", outFile);
  printer.printXmlDoubleProp("poi:hasRoundThing_Radius",
                             Name, Radius, outFile);
  printer.printObjProp("poi:hasRoundThing_Center",
                       Name, Center->Name, outFile);
  Center->printOwl(outFile);
  printer.endIndi("cir:Sphere", outFile);
  individuals.insert(Name->val);
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

void VectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "poi:Vector", outFile);
  printer.printXmlDoubleProp("poi:hasVector_I",
                             Name, I, outFile);
  printer.printXmlDoubleProp("poi:hasVector_J",
                             Name, J, outFile);
  printer.printXmlDoubleProp("poi:hasVector_K",
                             Name, K, outFile);
  printer.endIndi("poi:Vector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class XmlHeaderForCirclesAndSpheres

*/

XmlHeaderForCirclesAndSpheres::XmlHeaderForCirclesAndSpheres() {}

XmlHeaderForCirclesAndSpheres::XmlHeaderForCirclesAndSpheres(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForCirclesAndSpheres::~XmlHeaderForCirclesAndSpheres() {}

void XmlHeaderForCirclesAndSpheres::printOwl(
  FILE * outFile)
{

}

/*********************************************************************/

