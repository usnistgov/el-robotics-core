/*********************************************************************/

#ifndef KITTING_HH
#define KITTING_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class KittingWorkstationFile;
class AngleUnitType;
class BoxVolumeType;
class BoxyShapeType;
class DataThingType;
class EndEffectorChangingStationType;
class EndEffectorHolderType;
class EndEffectorType;
class ExternalShapeType;
class GripperEffectorType;
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
class XmlHeaderForKittingWorkstation;

/*********************************************************************/
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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);
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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);

  XmlIDREF * KitTraySkuName;
  std::list<PartRefAndPoseType *> * PartRefAndPose;

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
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  PointType * Point;
  VectorType * XAxis;
  VectorType * ZAxis;

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);

  XmlDecimal * X;
  XmlDecimal * Y;
  XmlDecimal * Z;

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);
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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);

  XmlString * Description;
  PoseLocationType * GraspPose;

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
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn);
  ~SolidObjectType();
  void printSelf(FILE * outFile);

  XmlID * Name;
  PhysicalLocationType * PrimaryLocation;
  std::list<PhysicalLocationType *> * SecondaryLocation;
  InternalShapeType * InternalShape;
  ExternalShapeType * ExternalShape;
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
  void printSelf(FILE * outFile);

  XmlString * Description;
  ShapeDesignType * Shape;
  PositiveDecimalType * Weight;
  std::list<XmlIDREF *> * EndEffectorName;

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
  void printSelf(FILE * outFile);

  XmlDecimal * I;
  XmlDecimal * J;
  XmlDecimal * K;

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
  void printSelf(FILE * outFile);
};

/*********************************************************************/

class WorkTableType :
  public SolidObjectType
{
public:
  WorkTableType();
  WorkTableType(
    XmlID * NameIn,
    PhysicalLocationType * PrimaryLocationIn,
    std::list<PhysicalLocationType *> * SecondaryLocationIn,
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    std::list<SolidObjectType *> * SolidObjectIn);
  ~WorkTableType();
  void printSelf(FILE * outFile);

  std::list<SolidObjectType *> * SolidObject;

  bool printTypp;
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
  void printSelf(FILE * outFile);

  PointType * MaximumPoint;
  PointType * MinimumPoint;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    MechanicalComponentType * BaseIn,
    std::list<EndEffectorHolderType *> * EndEffectorHoldersIn);
  ~EndEffectorChangingStationType();
  void printSelf(FILE * outFile);

  MechanicalComponentType * Base;
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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    EndEffectorType * EndEffectorIn);
  ~EndEffectorHolderType();
  void printSelf(FILE * outFile);

  EndEffectorType * EndEffector;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn);
  ~EndEffectorType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  PositiveDecimalType * Weight;
  PositiveDecimalType * MaximumLoadWeight;
  SolidObjectType * HeldObject;

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
    XmlString * ModelTypeNameIn,
    XmlString * ModelFileNameIn,
    XmlString * ModelNameIn);
  ~ExternalShapeType();
  void printSelf(FILE * outFile);

  XmlString * ModelTypeName;
  XmlString * ModelFileName;
  XmlString * ModelName;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~KitTrayType();
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * DesignNameIn,
    KitTrayType * TrayIn,
    std::list<PartType *> * PartIn,
    XmlBoolean * FinishedIn);
  ~KitType();
  void printSelf(FILE * outFile);

  XmlIDREF * DesignName;
  KitTrayType * Tray;
  std::list<PartType *> * Part;
  XmlBoolean * Finished;

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
    WeightUnitType * WeightUnitIn,
    WorkTableType * WorkTableIn);
  ~KittingWorkstationType();
  void printSelf(FILE * outFile);

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    LargeContainerType * LargeContainerIn,
    std::list<KitTrayType *> * KitTraysIn);
  ~LargeBoxWithEmptyKitTraysType();
  void printSelf(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitTrayType *> * KitTrays;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    LargeContainerType * LargeContainerIn,
    std::list<KitType *> * KitIn,
    XmlIDREF * KitDesignNameIn,
    XmlPositiveInteger * CapacityIn);
  ~LargeBoxWithKitsType();
  void printSelf(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitType *> * Kit;
  XmlIDREF * KitDesignName;
  XmlPositiveInteger * Capacity;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~LargeContainerType();
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;

  bool printTypp;
};

/*********************************************************************/

class MechanicalComponentType :
  public SolidObjectType
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
  void printSelf(FILE * outFile);


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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~PartType();
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn,
    XmlIDREF * PartSkuNameIn,
    XmlNonNegativeInteger * PartQuantityIn);
  ~PartsBinType();
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;
  XmlIDREF * PartSkuName;
  XmlNonNegativeInteger * PartQuantity;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlIDREF * SkuNameIn,
    XmlNMTOKEN * SerialNumberIn);
  ~PartsTrayType();
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  XmlNMTOKEN * SerialNumber;

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    PartsTrayType * PartsTrayIn,
    std::list<PartType *> * PartIn);
  ~PartsTrayWithPartsType();
  void printSelf(FILE * outFile);

  PartsTrayType * PartsTray;
  std::list<PartType *> * Part;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    EndEffectorType * EndEffectorIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    std::list<BoxVolumeType *> * WorkVolumeIn);
  ~RobotType();
  void printSelf(FILE * outFile);

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
    InternalShapeType * InternalShapeIn,
    ExternalShapeType * ExternalShapeIn,
    XmlString * DescriptionIn,
    PositiveDecimalType * WeightIn,
    PositiveDecimalType * MaximumLoadWeightIn,
    SolidObjectType * HeldObjectIn,
    PositiveDecimalType * CupDiameterIn,
    PositiveDecimalType * LengthIn);
  ~VacuumEffectorType();
  void printSelf(FILE * outFile);

  PositiveDecimalType * CupDiameter;
  PositiveDecimalType * Length;

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
  void printSelf(FILE * outFile);

  PositiveDecimalType * Length;
  PositiveDecimalType * Width;
  PositiveDecimalType * Height;
  XmlBoolean * HasTop;

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
  void printSelf(FILE * outFile);

  XmlPositiveInteger * ArrayNumber;
  PositiveDecimalType * ArrayRadius;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // KITTING_HH
