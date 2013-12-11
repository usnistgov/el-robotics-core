/*********************************************************************/

#ifndef POINTANDVECTOR_HH
#define POINTANDVECTOR_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class PointType;
class RoundThingType;
class VectorType;

/*********************************************************************/
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
  void printSelf(FILE * outFile);

  XmlID * Name;
  XmlDouble * X;
  XmlDouble * Y;
  XmlDouble * Z;
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
  void printSelf(FILE * outFile);

  XmlID * Name;
  XmlDouble * Radius;
  PointType * Center;
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
  void printSelf(FILE * outFile);

  XmlID * Name;
  XmlDouble * I;
  XmlDouble * J;
  XmlDouble * K;
};

/*********************************************************************/

#endif // POINTANDVECTOR_HH
