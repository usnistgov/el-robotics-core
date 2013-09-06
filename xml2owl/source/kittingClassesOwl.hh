/*

This file was built by taking the kittingClasses.hh file that was
generated automatically by the GenXMiller and hand editing it.

The only class that was added is the OwlPrinter class. The printSelf
functions were all changed to printOwl functions, except that
printSelf functions that do nothing were defined for the two classes
(DataThingType and SolidObjectType) from which all other classes are
derived.

A set of strings that has the names of individuals in the class was
added to most leaf classes. Classes representing abstract types should
not have individuals since there are no individuals of abstract types,
and individuals of derived types are automatically different individuals
from the DisjointClasses declaration for the abstract parent type.

Classes representing abstract types also do not need printOwl
functions declared, since the printOwl functions are inherited
automatically and there is no definition for them.

*/

/*********************************************************************/

#ifndef KITTING_OWL_HH
#define KITTING_OWL_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class KittingWorkstationFile;
class AngleUnitType;
class BoxVolumeType;
class BoxyShapeType;
class CylindricalShapeType;
class DataThingType;
class EndEffectorChangingStationType;
class EndEffectorHolderType;
class EndEffectorType;
class ExternalShapeType;
class GripperEffectorType;
class HumanType;
class InternalShapeType;
class KitDesignType;
class KitTrayType;
class KitType;
class KittingWorkstationType;
class LargeBoxWithEmptyKitTraysType;
class LargeBoxWithKitsType;
class LargeContainerType;
class LengthUnitType;
class MechanicalComponentType;
class NoSkuObjectType;
class OwlPrinter;
class PartRefAndPoseType;
class PartType;
class PartsBinType;
class PartsTrayType;
class PartsVesselType;
class PhysicalLocationType;
class PointType;
class PoseLocationInType;
class PoseLocationOnType;
class PoseLocationType;
class PoseOnlyLocationType;
class PositiveDecimalType;
class RelativeLocationInType;
class RelativeLocationOnType;
class RelativeLocationType;
class RobotType;
class ShapeDesignType;
class SkuObjectType;
class SlotType;
class SolidObjectType;
class StockKeepingUnitType;
class VacuumEffectorMultiCupType;
class VacuumEffectorSingleCupType;
class VacuumEffectorType;
class VectorType;
class WeightUnitType;
class WorkTableType;
class XmlHeaderForKittingWorkstation;

/*********************************************************************/
/*********************************************************************/

class OwlPrinter
{
public:
  OwlPrinter() {}
  ~OwlPrinter() {}
  static void checkRefObject(
    std::string name,
    std::string ref);
  static void printIndividuals(
    const char * typeName,
    std::set<std::string> * individuals,
    FILE * outFile);
  static void printLocations(
    XmlID * Name,
    PhysicalLocationType * primary,
    std::list<PhysicalLocationType *> * secondary,
    FILE * outFile);
  static void startIndi(
    XmlID * Name,
    const char * aType,
    bool heading,
    FILE * outFile);
  static void endIndi(
    const char * aType,
    FILE * outFile);
  static void printObjProp(
    const char * property,
    XmlID * Name,
    XmlID * valName,
    FILE * outFile);
  static void printObjRefProp(
    const char * property,
    XmlID * Name,
    XmlIDREF * valName,
    FILE * outFile);
   static void printPosDecProp(
    const char * property,
    XmlID * Name,
    PositiveDecimalType * val,
    FILE * outFile);
  static void printShapes(
    InternalShapeType * InternalShape,
    ExternalShapeType * ExternalShape,
    XmlID * Name,
    FILE * outFile);
  static void printXmlBoolProp(
    const char * property,
    XmlID * Name,
    XmlBoolean * val,
    FILE * outFile);
  static void printXmlDateTimeProp(
    const char * property,
    XmlID * Name,
    XmlDateTime * val,
    FILE * outFile);
  static void printXmlDecProp(
    const char * property,
    XmlID * Name,
    XmlDecimal * val,
    FILE * outFile);
  static void printXmlIDProp(
    const char * property,
    XmlID * Name,
    XmlID * val,
    FILE * outFile);
  static void printXmlIDREFProp(
    const char * property,
    XmlID * Name,
    XmlIDREF * val,
    FILE * outFile);
  static void printXmlNMTOKENProp(
    const char * property,
    XmlID * Name,
    XmlNMTOKEN * val,
    FILE * outFile);
  static void printXmlNonNegIntProp(
    const char * property,
    XmlID * Name,
    XmlNonNegativeInteger * val,
    FILE * outFile);
  static void printXmlPosIntProp(
    const char * property,
    XmlID * Name,
    XmlPositiveInteger * val,
    FILE * outFile);
  static void printXmlStringProp(
    const char * property,
    XmlID * Name,
    XmlString * val,
    FILE * outFile);

  static std::list<XmlID *>  locationStack;
  static bool primary;
  static char inFileName[200];
};

/*********************************************************************/

class KittingWorkstationFile :
  public XmlSchemaInstanceBase
{
public:
  KittingWorkstationFile();
  KittingWorkstationFile(
    XmlVersion * versionIn,
    XmlHeaderForKittingWorkstation * headerIn,
    KittingWorkstationType * KittingWorkstationIn);
  ~KittingWorkstationFile();
  void printOwl(FILE * outFile);
  void printSelf(FILE * outFile) {}

  XmlVersion * version;
  XmlHeaderForKittingWorkstation * header;
  KittingWorkstationType * KittingWorkstation;
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
  void printOwl(FILE * outFile);
};

/*********************************************************************/

class DataThingType :
  public XmlSchemaInstanceBase
{
public:
  DataThingType();
  DataThingType(
    XmlID * NameIn);
  ~DataThingType();
  void printSelf(FILE * outFile) {}
  virtual void printOwl(FILE * outFile) {}

  XmlID * Name;
};

/*********************************************************************/

class KitDesignType :
  public DataThingType
{
public:
  KitDesignType();
  KitDesignType(
    XmlID * NameIn,
    XmlIDREF * KitTraySkuNameIn,
    std::list<PartRefAndPoseType *> * PartRefAndPoseIn);
  ~KitDesignType();
  void printOwl(FILE * outFile);

  XmlIDREF * KitTraySkuName;
  std::list<PartRefAndPoseType *> * PartRefAndPose;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);
};

/*********************************************************************/

class PartRefAndPoseType :
  public DataThingType
{
public:
  PartRefAndPoseType();
  PartRefAndPoseType(
    XmlID * NameIn,
    XmlIDREF * SkuNameIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn);
  ~PartRefAndPoseType();
  void printOwl(FILE * outFile);

  XmlIDREF * SkuName;
  PointType * Point;
  VectorType * XAxis;
  VectorType * ZAxis;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PhysicalLocationType :
  public DataThingType
{
public:
  PhysicalLocationType();
  PhysicalLocationType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn);
  ~PhysicalLocationType();

  XmlIDREF * RefObjectName;
  XmlDateTime * Timestamp;

  bool printTypp;
};

/*********************************************************************/

class PointType :
  public DataThingType
{
public:
  PointType();
  PointType(
    XmlID * NameIn,
    XmlDecimal * XIn,
    XmlDecimal * YIn,
    XmlDecimal * ZIn);
  ~PointType();
  void printOwl(FILE * outFile);

  XmlDecimal * X;
  XmlDecimal * Y;
  XmlDecimal * Z;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PoseLocationType :
  public PhysicalLocationType
{
public:
  PoseLocationType();
  PoseLocationType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn,
    PositiveDecimalType * PositionStandardDeviationIn,
    PositiveDecimalType * OrientationStandardDeviationIn);
  ~PoseLocationType();

  PointType * Point;
  VectorType * XAxis;
  VectorType * ZAxis;
  PositiveDecimalType * PositionStandardDeviation;
  PositiveDecimalType * OrientationStandardDeviation;

  bool printTypp;
};

/*********************************************************************/

class PoseOnlyLocationType :
  public PoseLocationType
{
public:
  PoseOnlyLocationType();
  PoseOnlyLocationType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn,
    PositiveDecimalType * PositionStandardDeviationIn,
    PositiveDecimalType * OrientationStandardDeviationIn);
  ~PoseOnlyLocationType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PositiveDecimalType :
  public XmlDecimal
{
public:
  PositiveDecimalType();
  PositiveDecimalType(
    char * valIn);
  ~PositiveDecimalType();
  bool PositiveDecimalTypeIsBad();
  void printOwl(FILE * outFile);
};

/*********************************************************************/

class RelativeLocationType :
  public PhysicalLocationType
{
public:
  RelativeLocationType();
  RelativeLocationType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    XmlString * DescriptionIn);
  ~RelativeLocationType();

  XmlString * Description;

  bool printTypp;
};

/*********************************************************************/

class ShapeDesignType :
  public DataThingType
{
public:
  ShapeDesignType();
  ShapeDesignType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    PoseLocationType * GraspPoseIn);
  ~ShapeDesignType();

  XmlString * Description;
  PoseLocationType * GraspPose;

  bool printTypp;
};

/*********************************************************************/

class SlotType :
  public DataThingType
{
public:
  SlotType();
  SlotType(
    XmlID * NameIn,
    XmlIDREF * PartRefAndPoseNameIn,
    XmlIDREF * PartNameIn);
  ~SlotType();
  void printOwl(FILE * outFile);

  XmlIDREF * PartRefAndPoseName;
  XmlIDREF * PartName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class SolidObjectType :
  public XmlSchemaInstanceBase
{
public:
  SolidObjectType();
  SolidObjectType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn);
  ~SolidObjectType();
  void printSelf(FILE * outFile) {}
  virtual void printOwl(FILE * outFile) {}

  XmlID * Name;
  PhysicalLocationType * PrimaryLocation;
  std::list<PhysicalLocationType *> * SecondaryLocation;
};

/*********************************************************************/

class StockKeepingUnitType :
  public DataThingType
{
public:
  StockKeepingUnitType();
  StockKeepingUnitType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    PositiveDecimalType * WeightIn,
    std::list<XmlIDREF *> * EndEffectorNameIn);
  ~StockKeepingUnitType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  InternalShapeType * InternalShape;
  ExternalShapeType * ExternalShape;
  PositiveDecimalType * Weight;
  std::list<XmlIDREF *> * EndEffectorName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VectorType :
  public DataThingType
{
public:
  VectorType();
  VectorType(
    XmlID * NameIn,
    XmlDecimal * IIn,
    XmlDecimal * JIn,
    XmlDecimal * KIn);
  ~VectorType();
  void printOwl(FILE * outFile);

  XmlDecimal * I;
  XmlDecimal * J;
  XmlDecimal * K;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class WeightUnitType :
  public XmlNMTOKEN
{
public:
  WeightUnitType();
  WeightUnitType(
    char * valIn);
  ~WeightUnitType();
  bool WeightUnitTypeIsBad();
  void printOwl(FILE * outFile);
};

/*********************************************************************/

class BoxVolumeType :
  public DataThingType
{
public:
  BoxVolumeType();
  BoxVolumeType(
    XmlID * NameIn,
    PointType * MaximumPointIn,
    PointType * MinimumPointIn);
  ~BoxVolumeType();
  void printOwl(FILE * outFile);

  PointType * MaximumPoint;
  PointType * MinimumPoint;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class ExternalShapeType :
  public ShapeDesignType
{
public:
  ExternalShapeType();
  ExternalShapeType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    PoseLocationType * GraspPoseIn,
    XmlString * ModelFormatNameIn,
    XmlString * ModelFileNameIn,
    XmlString * ModelNameIn);
  ~ExternalShapeType();
  void printOwl(FILE * outFile);

  XmlString * ModelFormatName;
  XmlString * ModelFileName;
  XmlString * ModelName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class InternalShapeType :
  public ShapeDesignType
{
public:
  InternalShapeType();
  InternalShapeType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    PoseLocationType * GraspPoseIn);
  ~InternalShapeType();

  bool printTypp;
};

/*********************************************************************/

class NoSkuObjectType :
  public SolidObjectType
{
public:
  NoSkuObjectType();
  NoSkuObjectType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn);
  ~NoSkuObjectType();

  InternalShapeType * InternalShape;
  ExternalShapeType * ExternalShape;

  bool printTypp;
};

/*********************************************************************/

class PoseLocationInType :
  public PoseLocationType
{
public:
  PoseLocationInType();
  PoseLocationInType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn,
    PositiveDecimalType * PositionStandardDeviationIn,
    PositiveDecimalType * OrientationStandardDeviationIn);
  ~PoseLocationInType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PoseLocationOnType :
  public PoseLocationType
{
public:
  PoseLocationOnType();
  PoseLocationOnType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn,
    PositiveDecimalType * PositionStandardDeviationIn,
    PositiveDecimalType * OrientationStandardDeviationIn);
  ~PoseLocationOnType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class RelativeLocationInType :
  public RelativeLocationType
{
public:
  RelativeLocationInType();
  RelativeLocationInType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    XmlString * DescriptionIn);
  ~RelativeLocationInType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class RelativeLocationOnType :
  public RelativeLocationType
{
public:
  RelativeLocationOnType();
  RelativeLocationOnType(
    XmlID * NameIn,
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    XmlString * DescriptionIn);
  ~RelativeLocationOnType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class RobotType :
  public NoSkuObjectType
{
public:
  RobotType();
  RobotType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    EndEffectorType * EndEffectorIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    std::list<BoxVolumeType *> * WorkVolumeIn);
  ~RobotType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  EndEffectorType * EndEffector;
  PositiveDecimalType * MaximumLoadWeight;
  std::list<BoxVolumeType *> * WorkVolume;

  bool printTypp;
};

/*********************************************************************/

class SkuObjectType :
  public SolidObjectType
{
public:
  SkuObjectType();
  SkuObjectType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn);
  ~SkuObjectType();

  XmlIDREF * SkuName;

  bool printTypp;
};

/*********************************************************************/

class WorkTableType :
  public NoSkuObjectType
{
public:
  WorkTableType();
  WorkTableType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    std::list<SolidObjectType *> * ObjectOnTableIn);
  ~WorkTableType();
  void printOwl(FILE * outFile);

  std::list<SolidObjectType *> * ObjectOnTable;

  bool printTypp;
};

/*********************************************************************/

class BoxyShapeType :
  public InternalShapeType
{
public:
  BoxyShapeType();
  BoxyShapeType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    PoseLocationType * GraspPoseIn,
    PositiveDecimalType * LengthIn,
    PositiveDecimalType * WidthIn,
    PositiveDecimalType * HeightIn,
    XmlBoolean * HasTopIn);
  ~BoxyShapeType();
  void printOwl(FILE * outFile);

  PositiveDecimalType * Length;
  PositiveDecimalType * Width;
  PositiveDecimalType * Height;
  XmlBoolean * HasTop;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class CylindricalShapeType :
  public InternalShapeType
{
public:
  CylindricalShapeType();
  CylindricalShapeType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    PoseLocationType * GraspPoseIn,
    PositiveDecimalType * DiameterIn,
    PositiveDecimalType * HeightIn,
    XmlBoolean * HasTopIn);
  ~CylindricalShapeType();
  void printOwl(FILE * outFile);

  PositiveDecimalType * Diameter;
  PositiveDecimalType * Height;
  XmlBoolean * HasTop;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class EndEffectorChangingStationType :
  public NoSkuObjectType
{
public:
  EndEffectorChangingStationType();
  EndEffectorChangingStationType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    MechanicalComponentType * BaseIn,
    std::list<EndEffectorHolderType *> * EndEffectorHolderIn);
  ~EndEffectorChangingStationType();
  void printOwl(FILE * outFile);

  MechanicalComponentType * Base;
  std::list<EndEffectorHolderType *> * EndEffectorHolder;

  bool printTypp;
};

/*********************************************************************/

class EndEffectorHolderType :
  public NoSkuObjectType
{
public:
  EndEffectorHolderType();
  EndEffectorHolderType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    EndEffectorType * EndEffectorIn);
  ~EndEffectorHolderType();
  void printOwl(FILE * outFile);

  EndEffectorType * EndEffector;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class EndEffectorType :
  public NoSkuObjectType
{
public:
  EndEffectorType();
  EndEffectorType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn);
  ~EndEffectorType();

  XmlString * Description;
  PositiveDecimalType * Weight;
  PositiveDecimalType * MaximumLoadWeight;
  SolidObjectType * HeldObject;

  bool printTypp;
};

/*********************************************************************/

class GripperEffectorType :
  public EndEffectorType
{
public:
  GripperEffectorType();
  GripperEffectorType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn);
  ~GripperEffectorType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class HumanType :
  public NoSkuObjectType
{
public:
  HumanType();
  HumanType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn);
  ~HumanType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class KitTrayType :
  public SkuObjectType
{
public:
  KitTrayType();
  KitTrayType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~KitTrayType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class KitType :
  public NoSkuObjectType
{
public:
  KitType();
  KitType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * DesignNameIn,
    KitTrayType * KitTrayIn,
    std::list<PartType *> * PartIn,
    std::list<SlotType *> * SlotIn,
    XmlBoolean * FinishedIn);
  ~KitType();
  void printOwl(FILE * outFile);

  XmlIDREF * DesignName;
  KitTrayType * KitTray;
  std::list<PartType *> * Part;
  std::list<SlotType *> * Slot;
  XmlBoolean * Finished;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class KittingWorkstationType :
  public NoSkuObjectType
{
public:
  KittingWorkstationType();
  KittingWorkstationType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    AngleUnitType * AngleUnitIn,
    EndEffectorChangingStationType * ChangingStationIn,
    std::list<KitDesignType *> * KitDesignIn,
    LengthUnitType * LengthUnitIn,
    std::list<SolidObjectType *> * ObjectIn,
    std::list<BoxVolumeType *> * OtherObstacleIn,
    RobotType * RobotIn,
    std::list<StockKeepingUnitType *> * SkuIn,
    WeightUnitType * WeightUnitIn);
  ~KittingWorkstationType();
  void printOwl(FILE * outFile);

  AngleUnitType * AngleUnit;
  EndEffectorChangingStationType * ChangingStation;
  std::list<KitDesignType *> * KitDesign;
  LengthUnitType * LengthUnit;
  std::list<SolidObjectType *> * Object;
  std::list<BoxVolumeType *> * OtherObstacle;
  RobotType * Robot;
  std::list<StockKeepingUnitType *> * Sku;
  WeightUnitType * WeightUnit;

  bool printTypp;
};

/*********************************************************************/

class LargeBoxWithEmptyKitTraysType :
  public NoSkuObjectType
{
public:
  LargeBoxWithEmptyKitTraysType();
  LargeBoxWithEmptyKitTraysType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    LargeContainerType * LargeContainerIn,
    std::list<KitTrayType *> * KitTraysIn);
  ~LargeBoxWithEmptyKitTraysType();
  void printOwl(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitTrayType *> * KitTray;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class LargeBoxWithKitsType :
  public NoSkuObjectType
{
public:
  LargeBoxWithKitsType();
  LargeBoxWithKitsType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    LargeContainerType * LargeContainerIn,
    std::list<KitType *> * KitIn,
    XmlIDREF * KitDesignNameIn,
    XmlPositiveInteger * CapacityIn);
  ~LargeBoxWithKitsType();
  void printOwl(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitType *> * Kit;
  XmlIDREF * KitDesignName;
  XmlPositiveInteger * Capacity;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class LargeContainerType :
  public SkuObjectType
{
public:
  LargeContainerType();
  LargeContainerType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~LargeContainerType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class MechanicalComponentType :
  public NoSkuObjectType
{
public:
  MechanicalComponentType();
  MechanicalComponentType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn);
  ~MechanicalComponentType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartType :
  public SkuObjectType
{
public:
  PartType();
  PartType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~PartType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartsVesselType :
  public SkuObjectType
{
public:
  PartsVesselType();
  PartsVesselType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn,
    XmlIDREF * PartSkuNameIn,
    XmlNonNegativeInteger * PartQuantityIn,
    std::list<PartType *> * PartIn);
  ~PartsVesselType();

  XmlNMTOKEN * SerialNumber;
  XmlIDREF * PartSkuName;
  XmlNonNegativeInteger * PartQuantity;
  std::list<PartType *> * Part;

  bool printTypp;
};

/*********************************************************************/

class VacuumEffectorType :
  public EndEffectorType
{
public:
  VacuumEffectorType();
  VacuumEffectorType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn,
    PositiveDecimalType * CupDiameterIn,
    PositiveDecimalType * LengthIn);
  ~VacuumEffectorType();

  PositiveDecimalType * CupDiameter;
  PositiveDecimalType * Length;

  bool printTypp;
};

/*********************************************************************/

class PartsBinType :
  public PartsVesselType
{
public:
  PartsBinType();
  PartsBinType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn,
    XmlIDREF * PartSkuNameIn,
    XmlNonNegativeInteger * PartQuantityIn,
    std::list<PartType *> * PartIn);
  ~PartsBinType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartsTrayType :
  public PartsVesselType
{
public:
  PartsTrayType();
  PartsTrayType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn,
    XmlIDREF * PartSkuNameIn,
    XmlNonNegativeInteger * PartQuantityIn,
    std::list<PartType *> * PartIn);
  ~PartsTrayType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VacuumEffectorMultiCupType :
  public VacuumEffectorType
{
public:
  VacuumEffectorMultiCupType();
  VacuumEffectorMultiCupType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn,
    PositiveDecimalType * CupDiameterIn,
    PositiveDecimalType * LengthIn,
    XmlPositiveInteger * ArrayNumberIn,
    PositiveDecimalType * ArrayRadiusIn);
  ~VacuumEffectorMultiCupType();
  void printOwl(FILE * outFile);

  XmlPositiveInteger * ArrayNumber;
  PositiveDecimalType * ArrayRadius;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VacuumEffectorSingleCupType :
  public VacuumEffectorType
{
public:
  VacuumEffectorSingleCupType();
  VacuumEffectorSingleCupType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn,
    PositiveDecimalType * CupDiameterIn,
    PositiveDecimalType * LengthIn);
  ~VacuumEffectorSingleCupType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class XmlHeaderForKittingWorkstation
{
public:
  XmlHeaderForKittingWorkstation();
  XmlHeaderForKittingWorkstation(
    SchemaLocation * locationIn);
  ~XmlHeaderForKittingWorkstation();
  void printOwl(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // KITTING_OWL_HH
