/*

This file was built by taking the kittingClasses.hh file that was
generated automatically by the GenXMiller and hand editing it.

The only class that was added is the OwlPrinter class. The printSelf
functions were all changed to printOwl functions, except that
printSelf functions that do nothing were defined for the two classes
(DataThingType and SolidObjectType) from which all other classes are
derived.

A set of strings that has the names of individuals in the class was
added to most leaf classes.

*/

/*********************************************************************/

#ifndef KITTING_OWL_HH
#define KITTING_OWL_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class KittingWorkStationFile;
class AngleUnitType;
class BoxVolumeType;
class BoxyObjectType;
class BoxyShapeType;
class DataThingType;
class EndEffectorChangingStationType;
class EndEffectorHolderType;
class EndEffectorType;
class GripperEffectorType;
class KitDesignType;
class KitTrayType;
class KitType;
class KittingWorkstationType;
class LargeBoxWithEmptyKitTraysType;
class LargeBoxWithKitsType;
class LargeContainerType;
class LengthUnitType;
class OwlPrinter;
class PartRefAndPoseType;
class PartType;
class PartsBinType;
class PartsTrayType;
class PartsTrayWithPartsType;
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
class SolidObjectType;
class StockKeepingUnitType;
class VacuumEffectorMultiCupType;
class VacuumEffectorSingleCupType;
class VacuumEffectorType;
class VectorType;
class WeightUnitType;
class WorkTableType;
class XmlHeaderForKittingWorkStation;

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
  static void printXmlBoolProp(
    const char * property,
    XmlID * Name,
    XmlBoolean * val,
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

class KittingWorkStationFile :
  public XmlSchemaInstanceBase
{
public:
  KittingWorkStationFile();
  KittingWorkStationFile(
    XmlVersion * versionIn,
    XmlHeaderForKittingWorkStation * headerIn,
    KittingWorkstationType * KittingWorkStationIn);
  ~KittingWorkStationFile();
  void printOwl(FILE * outFile);
  void printSelf(FILE * outFile) {}

  XmlVersion * version;
  XmlHeaderForKittingWorkStation * header;
  KittingWorkstationType * KittingWorkStation;
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
    XmlIDREF * RefObjectIn);
  ~PhysicalLocationType();

  XmlIDREF * RefObject;

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
    XmlIDREF * RefObjectIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn);
  ~PoseLocationType();

  PointType * Point;
  VectorType * XAxis;
  VectorType * ZAxis;

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
    XmlIDREF * RefObjectIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn);
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
    XmlIDREF * RefObjectIn,
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
    XmlString * DescriptionIn);
  ~ShapeDesignType();

  XmlString * Description;

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
  virtual void printOwl(FILE * outFile) {};

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
    ShapeDesignType * ShapeIn,
    PositiveDecimalType * WeightIn,
    std::list<XmlIDREF *> * EndEffectorNameIn);
  ~StockKeepingUnitType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  ShapeDesignType * Shape;
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

class BoxyObjectType :
  public SolidObjectType
{
public:
  BoxyObjectType();
  BoxyObjectType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    PositiveDecimalType * LengthIn,
    PositiveDecimalType * WidthIn,
    PositiveDecimalType * HeightIn);
  ~BoxyObjectType();
  void printDimensions(FILE * outFile);

  PositiveDecimalType * Length;
  PositiveDecimalType * Width;
  PositiveDecimalType * Height;

  bool printTypp;
};

/*********************************************************************/

class BoxyShapeType :
  public ShapeDesignType
{
public:
  BoxyShapeType();
  BoxyShapeType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
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

class EndEffectorChangingStationType :
  public SolidObjectType
{
public:
  EndEffectorChangingStationType();
  EndEffectorChangingStationType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    std::list<EndEffectorHolderType *> * EndEffectorHoldersIn);
 ~EndEffectorChangingStationType();
  void printOwl(FILE * outFile);

  std::list<EndEffectorHolderType *> * EndEffectorHolders;

  bool printTypp;
};

/*********************************************************************/

class EndEffectorHolderType :
  public SolidObjectType
{
public:
  EndEffectorHolderType();
  EndEffectorHolderType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    EndEffectorType * EndEffectorIn);
  ~EndEffectorHolderType();
  void printOwl(FILE * outFile);

  EndEffectorType * EndEffector;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class EndEffectorType :
  public SolidObjectType
{
public:
  EndEffectorType();
  EndEffectorType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn);
  ~EndEffectorType();

  XmlString * Description;
  PositiveDecimalType * Weight;
  PositiveDecimalType * MaximumLoadWeight;

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
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn);
  ~GripperEffectorType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class KitTrayType :
  public SolidObjectType
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

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class KitType :
  public SolidObjectType
{
public:
  KitType();
  KitType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * DesignNameIn,
    KitTrayType * TrayIn,
    std::list<PartType *> * PartIn,
    XmlBoolean * FinishedIn);
  ~KitType();
  void printOwl(FILE * outFile);

  XmlIDREF * DesignName;
  KitTrayType * Tray;
  std::list<PartType *> * Part;
  XmlBoolean * Finished;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class KittingWorkstationType :
  public SolidObjectType
{
public:
  KittingWorkstationType();
  KittingWorkstationType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    AngleUnitType * AngleUnitIn,
    EndEffectorChangingStationType * ChangingStationIn,
    std::list<KitDesignType *> * KitDesignIn,
    LengthUnitType * LengthUnitIn,
    std::list<SolidObjectType *> * ObjectIn,
    std::list<BoxVolumeType *> * OtherObstacleIn,
    RobotType * RobotIn,
    std::list<StockKeepingUnitType *> * SkuIn,
    WeightUnitType * WeightUnitIn,
    WorkTableType * WorkTableIn);
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
  WorkTableType * WorkTable;

  bool printTypp;
};

/*********************************************************************/

class LargeBoxWithEmptyKitTraysType :
  public SolidObjectType
{
public:
  LargeBoxWithEmptyKitTraysType();
  LargeBoxWithEmptyKitTraysType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
     LargeContainerType * LargeContainerIn,
    std::list<KitTrayType *> * TraysIn);
  ~LargeBoxWithEmptyKitTraysType();
  void printOwl(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitTrayType *> * Trays;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class LargeBoxWithKitsType :
  public SolidObjectType
{
public:
  LargeBoxWithKitsType();
  LargeBoxWithKitsType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
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
  public SolidObjectType
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

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartType :
  public SolidObjectType
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
  
  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartsBinType :
  public SolidObjectType
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
    XmlNonNegativeInteger * PartQuantityIn);
  ~PartsBinType();
  void printOwl(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;
  XmlIDREF * PartSkuName;
  XmlNonNegativeInteger * PartQuantity;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartsTrayType :
  public SolidObjectType
{
public:
  PartsTrayType();
  PartsTrayType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~PartsTrayType();
  void printOwl(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartsTrayWithPartsType :
  public SolidObjectType
{
public:
  PartsTrayWithPartsType();
  PartsTrayWithPartsType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    PartsTrayType * PartsTrayIn,
    std::list<PartType *> * PartIn);
  ~PartsTrayWithPartsType();
  void printOwl(FILE * outFile);

  PartsTrayType * PartsTray;
  std::list<PartType *> * Part;
  static std::set<std::string> individuals;

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
    XmlIDREF * RefObjectIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn);
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
    XmlIDREF * RefObjectIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn);
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
    XmlIDREF * RefObjectIn,
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
    XmlIDREF * RefObjectIn,
    XmlString * DescriptionIn);
  ~RelativeLocationOnType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class RobotType :
  public SolidObjectType
{
public:
  RobotType();
  RobotType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
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

class VacuumEffectorType :
  public EndEffectorType
{
public:
  VacuumEffectorType();
  VacuumEffectorType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    PositiveDecimalType * CupDiameterIn,
    PositiveDecimalType * LengthIn);
  ~VacuumEffectorType();

  PositiveDecimalType * CupDiameter;
  PositiveDecimalType * Length;

  bool printTypp;
};

/*********************************************************************/

class WorkTableType :
  public BoxyObjectType
{
public:
  WorkTableType();
  WorkTableType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    PositiveDecimalType * LengthIn,
    PositiveDecimalType * WidthIn,
    PositiveDecimalType * HeightIn,
     std::list<SolidObjectType *> * SolidObjectIn);
 ~WorkTableType();
  void printOwl(FILE * outFile);

  std::list<SolidObjectType *> * SolidObject;

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
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
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
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    PositiveDecimalType * CupDiameterIn,
    PositiveDecimalType * LengthIn);
  ~VacuumEffectorSingleCupType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class XmlHeaderForKittingWorkStation
{
public:
  XmlHeaderForKittingWorkStation();
  XmlHeaderForKittingWorkStation(
    SchemaLocation * locationIn);
  ~XmlHeaderForKittingWorkStation();
  void printOwl(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // KITTING_OWL_HH
