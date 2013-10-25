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
class ArithmeticComparisonBooleanExpressionType;
class ArithmeticExpressionType;
class AttachEndEffectorType;
class BinaryArithmeticExpressionType;
class BinaryBooleanExpressionType;
class BooleanConstantType;
class BooleanExpressionType;
class CreateKitType;
class DataThingType;
class DecimalType;
class DetachEndEffectorType;
class DivType;
class ElseType;
class EqualType;
class FalseType;
class GreaterOrEqualType;
class GreaterType;
class IfActionGroupType;
class KittingPlanType;
class LessOrEqualType;
class LessType;
class LocatePartType;
class MinusType;
class ModType;
class NegateType;
class NotEqualType;
class NotType;
class NumberedPlanElementType;
class OneOfActionGroupType;
class OrType;
class OrderedActionGroupType;
class PartiallyOrderedActionGroupType;
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
class SensorActionBaseType;
class SomeOfActionGroupType;
class StepWithPredecessorsType;
class TakeKitTrayType;
class TakeKitType;
class TakePartType;
class TestAndStepType;
class TimesType;
class TrueType;
class UnorderedActionGroupType;
class VarSetType;
class VarValType;
class VariableDeclarationType;
class VectorType;
class WhileActionGroupType;
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

class ElseType :
  public DataThingType
{
public:
  ElseType();
  ElseType(
    XmlID * NameIn,
    PlanElementBaseType * StepIn);
  ~ElseType();
  void printOwl(FILE * outFile);

  PlanElementBaseType * Step;
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
    std::list<XmlNMTOKEN *> * ObjectIn,
    std::list<VariableDeclarationType *> * VariableIn,
    PlanElementBaseType * PlanRootIn);
  ~KittingPlanType();
  void printOwl(FILE * outFile);

  XmlNMTOKEN * PlanId;
  XmlToken * PlanVersion;
  XmlDateTime * PlanDateAndTime;
  XmlToken * PlanAuthor;
  XmlString * PlanDescription;
  std::list<XmlNMTOKEN *> * Object;
  std::list<VariableDeclarationType *> * Variable;
  PlanElementBaseType * PlanRoot;
  static std::set<std::string> individuals;

  bool printTypp;
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

class PhysicalLocationType :
  public DataThingType
{
public:
  PhysicalLocationType();
  PhysicalLocationType(
    XmlID * NameIn,
    XmlNMTOKEN * RefObjectNameIn);
  ~PhysicalLocationType();

  XmlNMTOKEN * RefObjectName;

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
    XmlNMTOKEN * RefObjectNameIn,
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
    XmlNMTOKEN * RefObjectNameIn,
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
    XmlNMTOKEN * RefObjectNameIn,
    XmlString * DescriptionIn);
  ~RelativeLocationType();

  XmlString * Description;

  bool printTypp;
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

class IfActionGroupType :
  public ActionGroupBaseType
{
public:
  IfActionGroupType();
  IfActionGroupType(
    XmlID * NameIn,
    TestAndStepType * IfIn,
    std::list<TestAndStepType *> * ElseIfIn,
    ElseType * ElseIn);
  ~IfActionGroupType();
  void printOwl(FILE * outFile);

  TestAndStepType * If;
  std::list<TestAndStepType *> * ElseIf;
  ElseType * Else;
  static std::set<std::string> individuals;

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
    XmlNMTOKEN * RefObjectNameIn,
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
    XmlNMTOKEN * RefObjectNameIn,
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
    XmlNMTOKEN * RefObjectNameIn,
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
    XmlNMTOKEN * RefObjectNameIn,
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
