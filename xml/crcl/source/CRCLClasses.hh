/*********************************************************************/

#ifndef CRCL_HH
#define CRCL_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class CRCLProgramFile;
class AngleUnitType;
class CRCLCommandType;
class CRCLProgramType;
class CloseGripperType;
class CloseToolChangerType;
class DwellType;
class EndCanonType;
class InitCanonType;
class LengthUnitType;
class MessageType;
class MiddleCommandType;
class MoveStraightToType;
class MoveThroughToType;
class OpenGripperType;
class OpenToolChangerType;
class PointType;
class PoseType;
class SetAbsoluteAccelerationType;
class SetAbsoluteSpeedType;
class SetAngleUnitsType;
class SetEndAngleToleranceType;
class SetEndPointToleranceType;
class SetIntermediatePointToleranceType;
class SetLengthUnitsType;
class SetRelativeAccelerationType;
class SetRelativeSpeedType;
class VectorType;
class CRCLProgramType_1001_Type;
class CRCLProgramType_1001_TypeChoicePair;
class XmlHeaderForCRCLProgram;

/*********************************************************************/
/*********************************************************************/

class CRCLProgramFile :
  public XmlSchemaInstanceBase
{
public:
  CRCLProgramFile();
  CRCLProgramFile(
    XmlVersion * versionIn,
    XmlHeaderForCRCLProgram * headerIn,
    CRCLProgramType * CRCLProgramIn);
  ~CRCLProgramFile();
  void printSelf(FILE * outFile);

  XmlVersion * version;
  XmlHeaderForCRCLProgram * header;
  CRCLProgramType * CRCLProgram;
};

/*********************************************************************/

class AngleUnitType :
  public XmlNMTOKEN
{
public:
  AngleUnitType();
  AngleUnitType(
    char * valIn);
  ~AngleUnitType();
  bool AngleUnitTypeIsBad();
  void printSelf(FILE * outFile);
};

/*********************************************************************/

class CRCLCommandType :
  public XmlSchemaInstanceBase
{
public:
  CRCLCommandType();
  ~CRCLCommandType();
  void printSelf(FILE * outFile);

};

/*********************************************************************/

class CRCLProgramType :
  public XmlSchemaInstanceBase
{
public:
  CRCLProgramType();
  CRCLProgramType(
    InitCanonType * InitCanonIn,
    CRCLProgramType_1001_Type * CRCLProgramType_1001In,
    EndCanonType * EndCanonIn);
  ~CRCLProgramType();
  void printSelf(FILE * outFile);

  InitCanonType * InitCanon;
  CRCLProgramType_1001_Type * CRCLProgramType_1001;
  EndCanonType * EndCanon;
};

/*********************************************************************/

class EndCanonType :
  public CRCLCommandType
{
public:
  EndCanonType();
  ~EndCanonType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class InitCanonType :
  public CRCLCommandType
{
public:
  InitCanonType();
  ~InitCanonType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class LengthUnitType :
  public XmlNMTOKEN
{
public:
  LengthUnitType();
  LengthUnitType(
    char * valIn);
  ~LengthUnitType();
  bool LengthUnitTypeIsBad();
  void printSelf(FILE * outFile);
};

/*********************************************************************/

class MiddleCommandType :
  public CRCLCommandType
{
public:
  MiddleCommandType();
  ~MiddleCommandType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class MoveStraightToType :
  public MiddleCommandType
{
public:
  MoveStraightToType();
  MoveStraightToType(
    PoseType * EndPositionIn);
  ~MoveStraightToType();
  void printSelf(FILE * outFile);

  PoseType * EndPosition;

  bool printTypp;
};

/*********************************************************************/

class MoveThroughToType :
  public MiddleCommandType
{
public:
  MoveThroughToType();
  MoveThroughToType(
    std::list<PoseType *> * WaypointIn,
    XmlInteger * NumPositionsIn);
  ~MoveThroughToType();
  void printSelf(FILE * outFile);

  std::list<PoseType *> * Waypoint;
  XmlInteger * NumPositions;

  bool printTypp;
};

/*********************************************************************/

class OpenGripperType :
  public MiddleCommandType
{
public:
  OpenGripperType();
  ~OpenGripperType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class OpenToolChangerType :
  public MiddleCommandType
{
public:
  OpenToolChangerType();
  ~OpenToolChangerType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class PointType :
  public XmlSchemaInstanceBase
{
public:
  PointType();
  PointType(
    XmlDecimal * XIn,
    XmlDecimal * YIn,
    XmlDecimal * ZIn);
  ~PointType();
  void printSelf(FILE * outFile);

  XmlDecimal * X;
  XmlDecimal * Y;
  XmlDecimal * Z;
};

/*********************************************************************/

class PoseType :
  public XmlSchemaInstanceBase
{
public:
  PoseType();
  PoseType(
    PointType * PointIn,
    VectorType * ZAxisIn,
    VectorType * XAxisIn);
  ~PoseType();
  void printSelf(FILE * outFile);

  PointType * Point;
  VectorType * ZAxis;
  VectorType * XAxis;
};

/*********************************************************************/

class SetAbsoluteAccelerationType :
  public MiddleCommandType
{
public:
  SetAbsoluteAccelerationType();
  SetAbsoluteAccelerationType(
    XmlDecimal * AccelerationIn);
  ~SetAbsoluteAccelerationType();
  void printSelf(FILE * outFile);

  XmlDecimal * Acceleration;

  bool printTypp;
};

/*********************************************************************/

class SetAbsoluteSpeedType :
  public MiddleCommandType
{
public:
  SetAbsoluteSpeedType();
  SetAbsoluteSpeedType(
    XmlDecimal * SpeedIn);
  ~SetAbsoluteSpeedType();
  void printSelf(FILE * outFile);

  XmlDecimal * Speed;

  bool printTypp;
};

/*********************************************************************/

class SetAngleUnitsType :
  public MiddleCommandType
{
public:
  SetAngleUnitsType();
  SetAngleUnitsType(
    AngleUnitType * UnitNameIn);
  ~SetAngleUnitsType();
  void printSelf(FILE * outFile);

  AngleUnitType * UnitName;

  bool printTypp;
};

/*********************************************************************/

class SetEndAngleToleranceType :
  public MiddleCommandType
{
public:
  SetEndAngleToleranceType();
  SetEndAngleToleranceType(
    XmlDecimal * ToleranceIn);
  ~SetEndAngleToleranceType();
  void printSelf(FILE * outFile);

  XmlDecimal * Tolerance;

  bool printTypp;
};

/*********************************************************************/

class SetEndPointToleranceType :
  public MiddleCommandType
{
public:
  SetEndPointToleranceType();
  SetEndPointToleranceType(
    XmlDecimal * ToleranceIn);
  ~SetEndPointToleranceType();
  void printSelf(FILE * outFile);

  XmlDecimal * Tolerance;

  bool printTypp;
};

/*********************************************************************/

class SetIntermediatePointToleranceType :
  public MiddleCommandType
{
public:
  SetIntermediatePointToleranceType();
  SetIntermediatePointToleranceType(
    XmlDecimal * ToleranceIn);
  ~SetIntermediatePointToleranceType();
  void printSelf(FILE * outFile);

  XmlDecimal * Tolerance;

  bool printTypp;
};

/*********************************************************************/

class SetLengthUnitsType :
  public MiddleCommandType
{
public:
  SetLengthUnitsType();
  SetLengthUnitsType(
    LengthUnitType * UnitNameIn);
  ~SetLengthUnitsType();
  void printSelf(FILE * outFile);

  LengthUnitType * UnitName;

  bool printTypp;
};

/*********************************************************************/

class SetRelativeAccelerationType :
  public MiddleCommandType
{
public:
  SetRelativeAccelerationType();
  SetRelativeAccelerationType(
    XmlDecimal * PercentIn);
  ~SetRelativeAccelerationType();
  void printSelf(FILE * outFile);

  XmlDecimal * Percent;

  bool printTypp;
};

/*********************************************************************/

class SetRelativeSpeedType :
  public MiddleCommandType
{
public:
  SetRelativeSpeedType();
  SetRelativeSpeedType(
    XmlDecimal * PercentIn);
  ~SetRelativeSpeedType();
  void printSelf(FILE * outFile);

  XmlDecimal * Percent;

  bool printTypp;
};

/*********************************************************************/

class VectorType :
  public XmlSchemaInstanceBase
{
public:
  VectorType();
  VectorType(
    XmlDecimal * IIn,
    XmlDecimal * JIn,
    XmlDecimal * KIn);
  ~VectorType();
  void printSelf(FILE * outFile);

  XmlDecimal * I;
  XmlDecimal * J;
  XmlDecimal * K;
};

/*********************************************************************/

union CRCLProgramType_1001_TypeVal
{
  CloseGripperType * CloseGripper;
  CloseToolChangerType * CloseToolChanger;
  DwellType * Dwell;
  MessageType * Message;
  MoveStraightToType * MoveStraightTo;
  MoveThroughToType * MoveThroughTo;
  OpenGripperType * OpenGripper;
  OpenToolChangerType * OpenToolChanger;
  SetAbsoluteAccelerationType * SetAbsoluteAcceleration;
  SetAbsoluteSpeedType * SetAbsoluteSpeed;
  SetAngleUnitsType * SetAngleUnits;
  SetEndAngleToleranceType * SetEndAngleTolerance;
  SetEndPointToleranceType * SetEndPointTolerance;
  SetIntermediatePointToleranceType * SetIntermediatePointTolerance;
  SetLengthUnitsType * SetLengthUnits;
  SetRelativeAccelerationType * SetRelativeAcceleration;
  SetRelativeSpeedType * SetRelativeSpeed;
};

class CRCLProgramType_1001_TypeChoicePair :
  public XmlSchemaInstanceBase
{
public:
  enum whichOne {
    CloseGripperE,
    CloseToolChangerE,
    DwellE,
    MessageE,
    MoveStraightToE,
    MoveThroughToE,
    OpenGripperE,
    OpenToolChangerE,
    SetAbsoluteAccelerationE,
    SetAbsoluteSpeedE,
    SetAngleUnitsE,
    SetEndAngleToleranceE,
    SetEndPointToleranceE,
    SetIntermediatePointToleranceE,
    SetLengthUnitsE,
    SetRelativeAccelerationE,
    SetRelativeSpeedE };
  CRCLProgramType_1001_TypeChoicePair();
  CRCLProgramType_1001_TypeChoicePair(
    whichOne CRCLProgramType_1001_TypeTypeIn,
    CRCLProgramType_1001_TypeVal CRCLProgramType_1001_TypeValueIn);
  ~CRCLProgramType_1001_TypeChoicePair();
  void printSelf(FILE * outFile);

  whichOne CRCLProgramType_1001_TypeType;
  CRCLProgramType_1001_TypeVal CRCLProgramType_1001_TypeValue;
};

class CRCLProgramType_1001_Type :
  public XmlSchemaInstanceBase
{
public:
  CRCLProgramType_1001_Type();
  CRCLProgramType_1001_Type(
    std::list<CRCLProgramType_1001_TypeChoicePair *> * pairsIn);
  ~CRCLProgramType_1001_Type();
  void printSelf(FILE * outFile);

  std::list<CRCLProgramType_1001_TypeChoicePair *> * pairs;
};

/*********************************************************************/

class CloseGripperType :
  public MiddleCommandType
{
public:
  CloseGripperType();
  ~CloseGripperType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class CloseToolChangerType :
  public MiddleCommandType
{
public:
  CloseToolChangerType();
  ~CloseToolChangerType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class DwellType :
  public MiddleCommandType
{
public:
  DwellType();
  DwellType(
    XmlDecimal * DwellTimeIn);
  ~DwellType();
  void printSelf(FILE * outFile);

  XmlDecimal * DwellTime;

  bool printTypp;
};

/*********************************************************************/

class MessageType :
  public MiddleCommandType
{
public:
  MessageType();
  MessageType(
    XmlString * MessageIn);
  ~MessageType();
  void printSelf(FILE * outFile);

  XmlString * Message;

  bool printTypp;
};

/*********************************************************************/

class XmlHeaderForCRCLProgram
{
public:
  XmlHeaderForCRCLProgram();
  XmlHeaderForCRCLProgram(
    SchemaLocation * locationIn);
  ~XmlHeaderForCRCLProgram();
  void printSelf(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // CRCL_HH
