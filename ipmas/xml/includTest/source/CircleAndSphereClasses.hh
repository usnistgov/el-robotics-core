/*********************************************************************/

#ifndef CIRCLEANDSPHERE_HH
#define CIRCLEANDSPHERE_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"
#include "PointAndVectorClasses.hh"

/*********************************************************************/

class CircleType;
class PointType;
class RoundThingType;
class SphereType;
class VectorType;

/*********************************************************************/
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
  void printSelf(FILE * outFile);

  VectorType * Normal;

  bool printTypp;
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
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

#endif // CIRCLEANDSPHERE_HH
