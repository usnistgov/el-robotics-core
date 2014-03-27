/*********************************************************************/

#ifndef KITTINGPLAN_HH
#define KITTINGPLAN_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"
#include "kittingWorkstationClasses.hh"

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
class DecimalType;
class DetachEndEffectorType;
class DivType;
class ElseDoType;
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
class PlanElementBaseType;
class PlusType;
class PropValType;
class PutKitTrayType;
class PutKitType;
class PutPartType;
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
  void printSelf(FILE * outFile);

  XmlVersion * version;
  XmlHeaderForKittingPlan * header;
  KittingPlanType * KittingPlan;
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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlDecimal * A;

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
  void printSelf(FILE * outFile);


  bool printTypp;
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
  void printSelf(FILE * outFile);

  PlanElementBaseType * Step;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * PlanId;
  XmlToken * PlanVersion;
  XmlDateTime * PlanDateAndTime;
  XmlToken * PlanAuthor;
  XmlString * PlanDescription;
  std::list<XmlID *> * Object;
  std::list<VariableDeclarationType *> * Variable;
  PlanElementBaseType * PlanRoot;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  ArithmeticExpressionType * A;

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
  void printSelf(FILE * outFile);

  BooleanExpressionType * B;

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
  void printSelf(FILE * outFile);

  XmlPositiveInteger * SequenceNumber;
  PlanElementBaseType * PlanElement;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * ThingName;
  XmlNMTOKEN * Property;

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
  void printSelf(FILE * outFile);

  XmlPositiveInteger * SequenceNumber;
  std::list<XmlPositiveInteger *> * Predecessor;
  PlanElementBaseType * PlanElement;

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
  void printSelf(FILE * outFile);

  BooleanExpressionType * Test;
  PlanElementBaseType * Step;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlIDREF * VarName;
  ArithmeticExpressionType * Val;

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
  void printSelf(FILE * outFile);

  XmlIDREF * VarName;

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
  void printSelf(FILE * outFile);

  XmlDecimal * Val;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  ArithmeticExpressionType * A1;
  ArithmeticExpressionType * A2;

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
  void printSelf(FILE * outFile);

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * KitTrayName;
  XmlNMTOKEN * KitName;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  TestAndStepType * If;
  std::list<TestAndStepType *> * ElseIf;
  ElseDoType * ElseDo;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  std::list<NumberedPlanElementType *> * Step;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  std::list<NumberedPlanElementType *> * Step;

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
  void printSelf(FILE * outFile);

  std::list<StepWithPredecessorsType *> * Step;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  std::list<PlanElementBaseType *> * Step;
  XmlPositiveInteger * NumberOfSteps;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitTrayName;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitName;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * PartName;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  std::list<PlanElementBaseType *> * Step;

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
  void printSelf(FILE * outFile);

  BooleanExpressionType * Test;
  PlanElementBaseType * Step;

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
  void printSelf(FILE * outFile);


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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * EndEffectorName;
  XmlNMTOKEN * EndEffectorHolderName;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * EndEffectorName;
  XmlNMTOKEN * EndEffectorHolderName;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * PartName;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitTrayName;
  PhysicalLocationType * Location;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * KitName;
  PhysicalLocationType * Location;

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
  void printSelf(FILE * outFile);

  XmlNMTOKEN * RobotName;
  XmlNMTOKEN * PartName;
  PhysicalLocationType * Location;

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
  void printSelf(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // KITTINGPLAN_HH
