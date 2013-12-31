/*

Most of this file was generated automatically by the GenXMiller. Items
that have been added manually are marked with "added" in a comment.
All comments are added.

*/

/*********************************************************************/

#ifndef KITTINGWORKSTATION_HH
#define KITTINGWORKSTATION_HH
#include <stdio.h>
#include <list>
#include <map>     // added
#include "xmlSchemaInstance.hh"

/*********************************************************************/

struct col {float r, g, b; }; // added

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
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn);
  ~PhysicalLocationType();
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);
  void convertUnits(double lengthFactor); // added

  XmlDecimal * X;
  XmlDecimal * Y;
  XmlDecimal * Z;

  static std::list<PointType *> allPoints; // added
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
  void printSelf(FILE * outFile);

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
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
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
  void printSelf(FILE * outFile);

  XmlIDREF * PartRefAndPoseName;
  XmlIDREF * PartName;

  bool printTypp;
};

/*********************************************************************/

/* class SolidObjectType

The SolidObjectType class has a static objectMap that is a map from the
object name to the object. This is to make it easy to find a solid object
from a reference to it.

Each solid object has a color. The color is not specified in a kitting
data file; it is assigned by the kittingViewer.

The refFor list of a solid object S is a list of pointers to the solid
objects for which S is the refObject in the PrimaryLocation. Having this
list in each object enables tracing the location hierarchy downwards.
Having a refObject in each PrimaryLocation enables tracing the location
hierarchy upwards. The refFor list cannot be built by the
constructors since it may not exist when it is needed.

The refThing is a pointer to the reference object named in the
PrimaryLocation. The refThing cannot be recorded by the
constructors since it may not exist when it is needed.

*/

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
  void printSelf(FILE * outFile);

  XmlID * Name;
  PhysicalLocationType * PrimaryLocation;
  std::list<PhysicalLocationType *> * SecondaryLocation;

  static std::map<std::string, SolidObjectType *> objectMap; // added
  std::list<SolidObjectType *> refFor; //added
  SolidObjectType * refThing; // added
  col color; // added
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
  void printSelf(FILE * outFile);
  void convertUnits(double weightFactor); // added

  XmlString * Description;
  InternalShapeType * InternalShape;
  ExternalShapeType * ExternalShape;
  PositiveDecimalType * Weight;
  std::list<XmlIDREF *> * EndEffectorName;
  static std::list<StockKeepingUnitType *> allSkus; // added

  bool printTypp;
  col color; // added
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
  void normalize(); // added

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
  void printSelf(FILE * outFile);

  XmlString * ModelFormatName;
  XmlString * ModelFileName;
  XmlString * ModelName;

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
  void printSelf(FILE * outFile);

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
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    PointType * PointIn,
    VectorType * XAxisIn,
    VectorType * ZAxisIn,
    PositiveDecimalType * PositionStandardDeviationIn,
    PositiveDecimalType * OrientationStandardDeviationIn);
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
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
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
    XmlIDREF * RefObjectNameIn,
    XmlDateTime * TimestampIn,
    XmlString * DescriptionIn);
  ~RelativeLocationOnType();
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);

  XmlIDREF * SkuName;
  StockKeepingUnitType * sku; // added

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);
  void convertUnits(double lengthFactor);  // added

  PositiveDecimalType * Length;
  PositiveDecimalType * Width;
  PositiveDecimalType * Height;
  XmlBoolean * HasTop;
  static std::list<BoxyShapeType *> allBoxys; // added

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
  void printSelf(FILE * outFile);
  void convertUnits(double lengthFactor);  // added

  PositiveDecimalType * Diameter;
  PositiveDecimalType * Height;
  XmlBoolean * HasTop;
  static std::list<CylindricalShapeType *> allCyls; // added

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);

  EndEffectorType * EndEffector;

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * SerialNumber;

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
  void printSelf(FILE * outFile);

  XmlIDREF * DesignName;
  KitTrayType * KitTray;
  std::list<PartType *> * Part;
  std::list<SlotType *> * Slot;
  XmlBoolean * Finished;
  static std::list<KitType *> allKits; // added

  bool printTypp;
};

/*********************************************************************/

/* class KittingWorkstationType

Several of the classes in kittingClassesView.hh have a static map (or
list) of pointers to members of the class. This is done for a class if
a map or list of members of the class is needed for resolving
references, assigning colors, or adjusting values with units. The list
of members is built during parsing. After the initial workstation
model is read, these lists are copied into the initial workstation
model (which does not exist during parsing). Then the lists in the
classes are emptied so that they may be repopulated when the goal
workstation model is read.

The XmlID and XmlIDREF classes in xmlSchemaInstance.hh also have
lists of all members of the class. They are saved in the allIDs
and allIDREFs attributes in this KittingWorkstationType class.

Classes for which this is done include:

Class                         Item
----                          ----
BoxyShapeType                allBoxys
CylindricalShapeType         allCyls
XmlID                        allIDs         (from xmlSchemaInstance.hh)
XmlIDREF                     allIDREFs      (from xmlSchemaInstance.hh)
KitType                      allKits
VacuumEffectorMultiCupType   allMulti
PointType                    allPoints
VacuumEffectorSingleCupType  allSingle
StockKeepingUnitType         allSkus
SolidObjectType              allSolids      (AKA objectMap)

*/

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
  void printSelf(FILE * outFile);
  void convertUnits(bool setFactors); // added

  AngleUnitType * AngleUnit;
  EndEffectorChangingStationType * ChangingStation;
  std::list<KitDesignType *> * KitDesign;
  LengthUnitType * LengthUnit;
  std::list<SolidObjectType *> * Object;
  std::list<BoxVolumeType *> * OtherObstacle;
  RobotType * Robot;
  std::list<StockKeepingUnitType *> * Sku;
  WeightUnitType * WeightUnit;

  std::list<BoxyShapeType *>               allBoxys;  // added
  std::list<CylindricalShapeType *>        allCyls;   // added
  std::set<std::string>                    allIDs;    // added
  std::set<std::string>                    allIDREFs; // added
  std::list<KitType *>                     allKits;   // added
  std::list<VacuumEffectorMultiCupType *>  allMulti;  // added
  std::list<PointType *>                   allPoints; // added
  std::list<VacuumEffectorSingleCupType *> allSingle; // added
  std::list<StockKeepingUnitType *>        allSkus;   // added
  std::map<std::string, SolidObjectType *> allSolids; // added

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
    std::list<KitTrayType *> * KitTrayIn);
  ~LargeBoxWithEmptyKitTraysType();
  void printSelf(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitTrayType *> * KitTray;

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
  void printSelf(FILE * outFile);

  LargeContainerType * LargeContainer;
  std::list<KitType *> * Kit;
  XmlIDREF * KitDesignName;
  XmlPositiveInteger * Capacity;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * SerialNumber;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * SerialNumber;

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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

  void convertUnits( // added
    double lengthFactor, // added
    double weightFactor); // added

  XmlPositiveInteger * ArrayNumber;
  PositiveDecimalType * ArrayRadius;
  static std::list<VacuumEffectorMultiCupType *> allMulti; // added

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

  void convertUnits( // added
    double lengthFactor, // added
    double weightFactor); // added

  static std::list<VacuumEffectorSingleCupType *> allSingle; // added

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

#endif // KITTINGWORKSTATION_HH
