/*********************************************************************/

#ifndef KITTINGPLAN_OWL_HH
#define KITTINGPLAN_OWL_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

/*********************************************************************/

class KittingPlanFile;
class ActionBaseType;
class ActionGroupBaseType;
class AndType;
class AngleUnitType;
class ArithmeticComparisonBooleanExpressionType;
class ArithmeticExpressionType;
class AttachEndEffectorType;
class BinaryArithmeticExpressionType;
class BinaryBooleanExpressionType;
class BooleanConstantType;
class BooleanExpressionType;
class BoxVolumeType;
class BoxyShapeType;
class CreateKitType;
class CylindricalShapeType;
class DataThingType;
class DecimalType;
class DetachEndEffectorType;
class DivType;
class ElseDoType;
class EndEffectorChangingStationType;
class EndEffectorHolderType;
class EndEffectorType;
class EqualType;
class ExternalShapeType;
class FalseType;
class GreaterOrEqualType;
class GreaterType;
class GripperEffectorType;
class HumanType;
class IfActionGroupType;
class InternalShapeType;
class KitDesignType;
class KitTrayType;
class KitType;
class KittingPlanType;
class KittingWorkstationType;
class LargeBoxWithEmptyKitTraysType;
class LargeBoxWithKitsType;
class LargeContainerType;
class LengthUnitType;
class LessOrEqualType;
class LessType;
class LocatePartType;
class MechanicalComponentType;
class MinusType;
class ModType;
class NegateType;
class NoSkuObjectType;
class NotEqualType;
class NotType;
class NumberedPlanElementType;
class OneOfActionGroupType;
class OrType;
class OrderedActionGroupType;
class PartRefAndPoseType;
class PartType;
class PartiallyOrderedActionGroupType;
class PartsBinType;
class PartsTrayType;
class PartsVesselType;
class PhysicalLocationType;
class PlanElementBaseType;
class PlusType;
class PointType;
class PoseLocationInType;
class PoseLocationOnType;
class PoseLocationType;
class PoseOnlyLocationType;
class PositiveDecimalType;
class PropValType;
class PutKitTrayType;
class PutKitType;
class PutPartType;
class RelativeLocationInType;
class RelativeLocationOnType;
class RelativeLocationType;
class RobotActionBaseType;
class RobotType;
class SensorActionBaseType;
class ShapeDesignType;
class SkuObjectType;
class SlotType;
class SolidObjectType;
class SomeOfActionGroupType;
class StepWithPredecessorsType;
class StockKeepingUnitType;
class TakeKitTrayType;
class TakeKitType;
class TakePartType;
class TestAndStepType;
class TimesType;
class TrueType;
class UnorderedActionGroupType;
class VacuumEffectorMultiCupType;
class VacuumEffectorSingleCupType;
class VacuumEffectorType;
class VarSetType;
class VarValType;
class VariableDeclarationType;
class VectorType;
class WeightUnitType;
class WhileActionGroupType;
class WorkTableType;
class XmlHeaderForKittingPlan;

/*********************************************************************/
/*********************************************************************/

class KittingPlanFile :
  public XmlSchemaInstanceBase
{
public:
  KittingPlanFile();
  KittingPlanFile(
    XmlVersion * versionIn,
    XmlHeaderForKittingPlan * headerIn,
    KittingPlanType * KittingPlanIn);
  ~KittingPlanFile();
  void printOwl(FILE * outFile);
  void printSelf(FILE * outFile) {}

  XmlVersion * version;
  XmlHeaderForKittingPlan * header;
  KittingPlanType * KittingPlan;
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
  void printProp(const char * property, XmlID * Name, FILE * outFile);
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

class ElseDoType :
  public DataThingType
{
public:
  ElseDoType();
  ElseDoType(
    XmlID * NameIn,
    PlanElementBaseType * StepIn);
  ~ElseDoType();
  void printOwl(FILE * outFile);

  PlanElementBaseType * Step;
  static std::set<std::string> individuals;

  bool printTypp;
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

class KittingPlanType :
  public DataThingType
{
public:
  KittingPlanType();
  KittingPlanType(
    XmlID * NameIn,
    XmlNMTOKEN * PlanIdIn,
    XmlToken * PlanVersionIn,
    XmlDateTime * PlanDateAndTimeIn,
    XmlToken * PlanAuthorIn,
    XmlString * PlanDescriptionIn,
    std::list<XmlID *> * ObjectIn,
    std::list<VariableDeclarationType *> * VariableIn,
    PlanElementBaseType * PlanRootIn);
  ~KittingPlanType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * PlanId;
  XmlToken * PlanVersion;
  XmlDateTime * PlanDateAndTime;
  XmlToken * PlanAuthor;
  XmlString * PlanDescription;
  std::list<XmlID *> * Object;
  std::list<VariableDeclarationType *> * Variable;
  PlanElementBaseType * PlanRoot;
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
  void printProp(const char * property, XmlID * Name, FILE * outFile);
};

/*********************************************************************/

class NumberedPlanElementType :
  public DataThingType
{
public:
  NumberedPlanElementType();
  NumberedPlanElementType(
    XmlID * NameIn,
    XmlPositiveInteger * SequenceNumberIn,
    PlanElementBaseType * PlanElementIn);
  ~NumberedPlanElementType();
  void printOwl(FILE * outFile);

  XmlPositiveInteger * SequenceNumber;
  PlanElementBaseType * PlanElement;
  static std::set<std::string> individuals;

  bool printTypp;
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

class PlanElementBaseType :
  public DataThingType
{
public:
  PlanElementBaseType();
  PlanElementBaseType(
    XmlID * NameIn);
  ~PlanElementBaseType();

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
  void printProp(const char * property, XmlID * Name, FILE * outFile);
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

class StepWithPredecessorsType :
  public DataThingType
{
public:
  StepWithPredecessorsType();
  StepWithPredecessorsType(
    XmlID * NameIn,
    XmlPositiveInteger * SequenceNumberIn,
    std::list<XmlPositiveInteger *> * PredecessorIn,
    PlanElementBaseType * PlanElementIn);
  ~StepWithPredecessorsType();
  void printOwl(FILE * outFile);

  XmlPositiveInteger * SequenceNumber;
  std::list<XmlPositiveInteger *> * Predecessor;
  PlanElementBaseType * PlanElement;
  static std::set<std::string> individuals;

  bool printTypp;
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

class TestAndStepType :
  public DataThingType
{
public:
  TestAndStepType();
  TestAndStepType(
    XmlID * NameIn,
    BooleanExpressionType * TestIn,
    PlanElementBaseType * StepIn);
  ~TestAndStepType();
  void printOwl(FILE * outFile);

  BooleanExpressionType * Test;
  PlanElementBaseType * Step;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VarSetType :
  public PlanElementBaseType
{
public:
  VarSetType();
  VarSetType(
    XmlID * NameIn,
    XmlIDREF * VarNameIn,
    ArithmeticExpressionType * ValIn);
  ~VarSetType();
  void printOwl(FILE * outFile);

  XmlIDREF * VarName;
  ArithmeticExpressionType * Val;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VariableDeclarationType :
  public DataThingType
{
public:
  VariableDeclarationType();
  VariableDeclarationType(
    XmlID * NameIn,
    XmlDecimal * ValIn);
  ~VariableDeclarationType();
  void printOwl(FILE * outFile);

  XmlDecimal * Val;
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
  void printProp(const char * property, XmlID * Name, FILE * outFile);
};

/*********************************************************************/

class ActionBaseType :
  public PlanElementBaseType
{
public:
  ActionBaseType();
  ActionBaseType(
    XmlID * NameIn);
  ~ActionBaseType();

  bool printTypp;
};

/*********************************************************************/

class ActionGroupBaseType :
  public PlanElementBaseType
{
public:
  ActionGroupBaseType();
  ActionGroupBaseType(
    XmlID * NameIn);
  ~ActionGroupBaseType();

  bool printTypp;
};

/*********************************************************************/

class ArithmeticExpressionType :
  public DataThingType
{
public:
  ArithmeticExpressionType();
  ArithmeticExpressionType(
    XmlID * NameIn);
  ~ArithmeticExpressionType();

  bool printTypp;
};

/*********************************************************************/

class BinaryArithmeticExpressionType :
  public ArithmeticExpressionType
{
public:
  BinaryArithmeticExpressionType();
  BinaryArithmeticExpressionType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~BinaryArithmeticExpressionType();

  ArithmeticExpressionType * A1;
  ArithmeticExpressionType * A2;

  bool printTypp;
};

/*********************************************************************/

class BooleanExpressionType :
  public DataThingType
{
public:
  BooleanExpressionType();
  BooleanExpressionType(
    XmlID * NameIn);
  ~BooleanExpressionType();

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
  void printOwl(FILE * outFile);

  PointType * MaximumPoint;
  PointType * MinimumPoint;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class CreateKitType :
  public ActionBaseType
{
public:
  CreateKitType();
  CreateKitType(
    XmlID * NameIn,
    XmlNMTOKEN * KitTrayNameIn,
    XmlNMTOKEN * KitNameIn);
  ~CreateKitType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * KitTrayName;
  XmlNMTOKEN * KitName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class DecimalType :
  public ArithmeticExpressionType
{
public:
  DecimalType();
  DecimalType(
    XmlID * NameIn,
    XmlDecimal * AIn);
  ~DecimalType();
  void printOwl(FILE * outFile);

  XmlDecimal * A;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class DivType :
  public BinaryArithmeticExpressionType
{
public:
  DivType();
  DivType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~DivType();
  void printOwl(FILE * outFile);

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

class IfActionGroupType :
  public ActionGroupBaseType
{
public:
  IfActionGroupType();
  IfActionGroupType(
    XmlID * NameIn,
    TestAndStepType * IfIn,
    std::list<TestAndStepType *> * ElseIfIn,
    ElseDoType * ElseDoIn);
  ~IfActionGroupType();
  void printOwl(FILE * outFile);

  TestAndStepType * If;
  std::list<TestAndStepType *> * ElseIf;
  ElseDoType * ElseDo;
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

class MinusType :
  public BinaryArithmeticExpressionType
{
public:
  MinusType();
  MinusType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~MinusType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class ModType :
  public BinaryArithmeticExpressionType
{
public:
  ModType();
  ModType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~ModType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class NegateType :
  public ArithmeticExpressionType
{
public:
  NegateType();
  NegateType(
    XmlID * NameIn,
    ArithmeticExpressionType * AIn);
  ~NegateType();
  void printOwl(FILE * outFile);

  ArithmeticExpressionType * A;
  static std::set<std::string> individuals;

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

class NotType :
  public BooleanExpressionType
{
public:
  NotType();
  NotType(
    XmlID * NameIn,
    BooleanExpressionType * BIn);
  ~NotType();
  void printOwl(FILE * outFile);

  BooleanExpressionType * B;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class OneOfActionGroupType :
  public ActionGroupBaseType
{
public:
  OneOfActionGroupType();
  OneOfActionGroupType(
    XmlID * NameIn,
    std::list<NumberedPlanElementType *> * StepIn);
  ~OneOfActionGroupType();
  void printOwl(FILE * outFile);

  std::list<NumberedPlanElementType *> * Step;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class OrderedActionGroupType :
  public ActionGroupBaseType
{
public:
  OrderedActionGroupType();
  OrderedActionGroupType(
    XmlID * NameIn,
    std::list<NumberedPlanElementType *> * StepIn);
  ~OrderedActionGroupType();
  void printOwl(FILE * outFile);

  std::list<NumberedPlanElementType *> * Step;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PartiallyOrderedActionGroupType :
  public ActionGroupBaseType
{
public:
  PartiallyOrderedActionGroupType();
  PartiallyOrderedActionGroupType(
    XmlID * NameIn,
    std::list<StepWithPredecessorsType *> * StepIn);
  ~PartiallyOrderedActionGroupType();
  void printOwl(FILE * outFile);

  std::list<StepWithPredecessorsType *> * Step;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PlusType :
  public BinaryArithmeticExpressionType
{
public:
  PlusType();
  PlusType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~PlusType();
  void printOwl(FILE * outFile);

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

class PropValType :
  public ArithmeticExpressionType
{
public:
  PropValType();
  PropValType(
    XmlID * NameIn,
    XmlNMTOKEN * ThingNameIn,
    XmlNMTOKEN * PropertyIn);
  ~PropValType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * ThingName;
  XmlNMTOKEN * Property;
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

class RobotActionBaseType :
  public ActionBaseType
{
public:
  RobotActionBaseType();
  RobotActionBaseType(
    XmlID * NameIn);
  ~RobotActionBaseType();

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
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class SensorActionBaseType :
  public ActionBaseType
{
public:
  SensorActionBaseType();
  SensorActionBaseType(
    XmlID * NameIn);
  ~SensorActionBaseType();

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

class SomeOfActionGroupType :
  public ActionGroupBaseType
{
public:
  SomeOfActionGroupType();
  SomeOfActionGroupType(
    XmlID * NameIn,
    std::list<PlanElementBaseType *> * StepIn,
    XmlPositiveInteger * NumberOfStepsIn);
  ~SomeOfActionGroupType();
  void printOwl(FILE * outFile);

  std::list<PlanElementBaseType *> * Step;
  XmlPositiveInteger * NumberOfSteps;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class TakeKitTrayType :
  public RobotActionBaseType
{
public:
  TakeKitTrayType();
  TakeKitTrayType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * KitTrayNameIn);
  ~TakeKitTrayType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitTrayName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class TakeKitType :
  public RobotActionBaseType
{
public:
  TakeKitType();
  TakeKitType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * KitNameIn);
  ~TakeKitType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class TakePartType :
  public RobotActionBaseType
{
public:
  TakePartType();
  TakePartType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * PartNameIn);
  ~TakePartType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * PartName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class TimesType :
  public BinaryArithmeticExpressionType
{
public:
  TimesType();
  TimesType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~TimesType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class UnorderedActionGroupType :
  public ActionGroupBaseType
{
public:
  UnorderedActionGroupType();
  UnorderedActionGroupType(
    XmlID * NameIn,
    std::list<PlanElementBaseType *> * StepIn);
  ~UnorderedActionGroupType();
  void printOwl(FILE * outFile);

  std::list<PlanElementBaseType *> * Step;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class VarValType :
  public ArithmeticExpressionType
{
public:
  VarValType();
  VarValType(
    XmlID * NameIn,
    XmlIDREF * VarNameIn);
  ~VarValType();
  void printOwl(FILE * outFile);

  XmlIDREF * VarName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class WhileActionGroupType :
  public ActionGroupBaseType
{
public:
  WhileActionGroupType();
  WhileActionGroupType(
    XmlID * NameIn,
    BooleanExpressionType * TestIn,
    PlanElementBaseType * StepIn);
  ~WhileActionGroupType();
  void printOwl(FILE * outFile);

  BooleanExpressionType * Test;
  PlanElementBaseType * Step;
  static std::set<std::string> individuals;

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
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class ArithmeticComparisonBooleanExpressionType :
  public BooleanExpressionType
{
public:
  ArithmeticComparisonBooleanExpressionType();
  ArithmeticComparisonBooleanExpressionType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~ArithmeticComparisonBooleanExpressionType();

  ArithmeticExpressionType * A1;
  ArithmeticExpressionType * A2;

  bool printTypp;
};

/*********************************************************************/

class AttachEndEffectorType :
  public RobotActionBaseType
{
public:
  AttachEndEffectorType();
  AttachEndEffectorType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * EndEffectorNameIn,
    XmlNMTOKEN * EndEffectorHolderNameIn);
  ~AttachEndEffectorType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * EndEffectorName;
  XmlNMTOKEN * EndEffectorHolderName;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class BinaryBooleanExpressionType :
  public BooleanExpressionType
{
public:
  BinaryBooleanExpressionType();
  BinaryBooleanExpressionType(
    XmlID * NameIn,
    BooleanExpressionType * B1In,
    BooleanExpressionType * B2In);
  ~BinaryBooleanExpressionType();

  BooleanExpressionType * B1;
  BooleanExpressionType * B2;

  bool printTypp;
};

/*********************************************************************/

class BooleanConstantType :
  public BooleanExpressionType
{
public:
  BooleanConstantType();
  BooleanConstantType(
    XmlID * NameIn);
  ~BooleanConstantType();

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

class DetachEndEffectorType :
  public RobotActionBaseType
{
public:
  DetachEndEffectorType();
  DetachEndEffectorType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * EndEffectorNameIn,
    XmlNMTOKEN * EndEffectorHolderNameIn);
  ~DetachEndEffectorType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * EndEffectorName;
  XmlNMTOKEN * EndEffectorHolderName;
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
  static std::set<std::string> individuals;

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

class EqualType :
  public ArithmeticComparisonBooleanExpressionType
{
public:
  EqualType();
  EqualType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~EqualType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class FalseType :
  public BooleanConstantType
{
public:
  FalseType();
  FalseType(
    XmlID * NameIn);
  ~FalseType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class GreaterOrEqualType :
  public ArithmeticComparisonBooleanExpressionType
{
public:
  GreaterOrEqualType();
  GreaterOrEqualType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~GreaterOrEqualType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class GreaterType :
  public ArithmeticComparisonBooleanExpressionType
{
public:
  GreaterType();
  GreaterType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~GreaterType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  static std::set<std::string> individuals;

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

class LessOrEqualType :
  public ArithmeticComparisonBooleanExpressionType
{
public:
  LessOrEqualType();
  LessOrEqualType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~LessOrEqualType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class LessType :
  public ArithmeticComparisonBooleanExpressionType
{
public:
  LessType();
  LessType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~LessType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class LocatePartType :
  public SensorActionBaseType
{
public:
  LocatePartType();
  LocatePartType(
    XmlID * NameIn,
    XmlNMTOKEN * PartNameIn);
  ~LocatePartType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * PartName;
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

class NotEqualType :
  public ArithmeticComparisonBooleanExpressionType
{
public:
  NotEqualType();
  NotEqualType(
    XmlID * NameIn,
    ArithmeticExpressionType * A1In,
    ArithmeticExpressionType * A2In);
  ~NotEqualType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class OrType :
  public BinaryBooleanExpressionType
{
public:
  OrType();
  OrType(
    XmlID * NameIn,
    BooleanExpressionType * B1In,
    BooleanExpressionType * B2In);
  ~OrType();
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

class PutKitTrayType :
  public RobotActionBaseType
{
public:
  PutKitTrayType();
  PutKitTrayType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * KitTrayNameIn,
    PhysicalLocationType * LocationIn);
  ~PutKitTrayType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitTrayName;
  PhysicalLocationType * Location;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PutKitType :
  public RobotActionBaseType
{
public:
  PutKitType();
  PutKitType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * KitNameIn,
    PhysicalLocationType * LocationIn);
  ~PutKitType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitName;
  PhysicalLocationType * Location;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class PutPartType :
  public RobotActionBaseType
{
public:
  PutPartType();
  PutPartType(
    XmlID * NameIn,
    XmlNMTOKEN * RobotNameIn,
    XmlNMTOKEN * PartNameIn,
    PhysicalLocationType * LocationIn);
  ~PutPartType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * PartName;
  PhysicalLocationType * Location;
  static std::set<std::string> individuals;

  bool printTypp;
};

/*********************************************************************/

class TrueType :
  public BooleanConstantType
{
public:
  TrueType();
  TrueType(
    XmlID * NameIn);
  ~TrueType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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

class AndType :
  public BinaryBooleanExpressionType
{
public:
  AndType();
  AndType(
    XmlID * NameIn,
    BooleanExpressionType * B1In,
    BooleanExpressionType * B2In);
  ~AndType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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

class XmlHeaderForKittingPlan
{
public:
  XmlHeaderForKittingPlan();
  XmlHeaderForKittingPlan(
    SchemaLocation * locationIn);
  ~XmlHeaderForKittingPlan();
  void printOwl(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // KITTINGPLAN_OWL_HH
