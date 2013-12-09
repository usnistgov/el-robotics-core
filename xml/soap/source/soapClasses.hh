/*********************************************************************/

#ifndef SOAP_HH
#define SOAP_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"
#include "kittingWorkstationClasses.hh"

/*********************************************************************/

class SOAPFile;
class ActionBaseType;
class AngleUnitType;
class AnyOrderOrderingConstructType;
class AttachEndEffectorType;
class BoxVolumeType;
class BoxyShapeType;
class CountOrderingConstructType;
class CreateKitType;
class CylindricalShapeType;
class DataThingType;
class DetachEndEffectorType;
class DomainType;
class EffectType;
class EndEffectorChangingStationType;
class EndEffectorHolderType;
class EndEffectorType;
class ExistOrderingConstructType;
class ExternalShapeType;
class FunctionBooleanExpressionType;
class FunctionOperationType;
class FunctionToDecimalBoolType;
class FunctionToDecimalEqualType;
class FunctionToDecimalGreaterOrEqualType;
class FunctionToDecimalGreaterType;
class FunctionToDecimalLessOrEqualType;
class FunctionToDecimalLessType;
class FunctionToFunctionBoolType;
class FunctionToFunctionEqualType;
class FunctionToFunctionGreaterOrEqualType;
class FunctionToFunctionGreaterType;
class FunctionToFunctionLessOrEqualType;
class FunctionToFunctionLessType;
class FunctionType;
class GripperEffectorType;
class HumanType;
class InContactWithType;
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
class OnTopWithContactType;
class OrderedListOrderingConstructType;
class OrderingConstructType;
class PartRefAndPoseType;
class PartType;
class PartiallyInType;
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
class PreconditionType;
class PredicateGroupElementType;
class PredicateType;
class PutKitTrayType;
class PutKitType;
class PutPartType;
class RelativeLocationInType;
class RelativeLocationOnType;
class RelativeLocationType;
class RobotActionBaseType;
class RobotType;
class SOAPType;
class ShapeDesignType;
class SkuObjectType;
class SlotType;
class SolidObjectType;
class StateRelationType;
class StockKeepingUnitType;
class TakeKitTrayType;
class TakeKitType;
class TakePartType;
class UnderWithContactType;
class VacuumEffectorMultiCupType;
class VacuumEffectorSingleCupType;
class VacuumEffectorType;
class VectorType;
class WeightUnitType;
class WorkTableType;
class XmlHeaderForSOAP;

/*********************************************************************/
/*********************************************************************/

class SOAPFile :
  public XmlSchemaInstanceBase
{
public:
  SOAPFile();
  SOAPFile(
    XmlVersion * versionIn,
    XmlHeaderForSOAP * headerIn,
    SOAPType * SOAPIn);
  ~SOAPFile();
  void printSelf(FILE * outFile);

  XmlVersion * version;
  XmlHeaderForSOAP * header;
  SOAPType * SOAP;
};

/*********************************************************************/

class ActionBaseType :
  public DataThingType
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

class CreateKitType :
  public ActionBaseType
{
public:
  CreateKitType();
  CreateKitType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * KitTrayParameterIn,
    XmlNMTOKEN * WorkTableParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~CreateKitType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * KitTrayParameter;
  XmlNMTOKEN * WorkTableParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

  bool printTypp;
};

/*********************************************************************/

class DomainType :
  public DataThingType
{
public:
  DomainType();
  DomainType(
    XmlID * NameIn,
    std::list<XmlNMTOKEN *> * RequirementIn,
    std::list<XmlNMTOKEN *> * VariableIn,
    std::list<PredicateType *> * PredicateIn,
    std::list<FunctionType *> * FunctionIn,
    AttachEndEffectorType * AttachEndEffectorIn,
    CreateKitType * CreateKitIn,
    DetachEndEffectorType * DetachEndEffectorIn,
    TakePartType * TakePartIn,
    TakeKitType * TakeKitIn,
    TakeKitTrayType * TakeKitTrayIn,
    PutPartType * PutPartIn,
    PutKitType * PutKitIn,
    PutKitTrayType * PutKitTrayIn);
  ~DomainType();
  void printSelf(FILE * outFile);

  std::list<XmlNMTOKEN *> * Requirement;
  std::list<XmlNMTOKEN *> * Variable;
  std::list<PredicateType *> * Predicate;
  std::list<FunctionType *> * Function;
  AttachEndEffectorType * AttachEndEffector;
  CreateKitType * CreateKit;
  DetachEndEffectorType * DetachEndEffector;
  TakePartType * TakePart;
  TakeKitType * TakeKit;
  TakeKitTrayType * TakeKitTray;
  PutPartType * PutPart;
  PutKitType * PutKit;
  PutKitTrayType * PutKitTray;

  bool printTypp;
};

/*********************************************************************/

class EffectType :
  public DataThingType
{
public:
  EffectType();
  EffectType(
    XmlID * NameIn,
    std::list<XmlIDREF *> * PredicateNameIn,
    std::list<XmlIDREF *> * NotPredicateNameIn,
    XmlIDREF * FunctionNameIn,
    FunctionOperationType * FunctionOperationIn,
    std::list<FunctionToFunctionLessType *> * F1LessF2In,
    std::list<FunctionToFunctionEqualType *> * F1EqualF2In,
    std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2In,
    std::list<FunctionToFunctionGreaterType *> * F1GreaterF2In,
    std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2In);
  ~EffectType();
  void printSelf(FILE * outFile);

  std::list<XmlIDREF *> * PredicateName;
  std::list<XmlIDREF *> * NotPredicateName;
  XmlIDREF * FunctionName;
  FunctionOperationType * FunctionOperation;
  std::list<FunctionToFunctionLessType *> * F1LessF2;
  std::list<FunctionToFunctionEqualType *> * F1EqualF2;
  std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2;
  std::list<FunctionToFunctionGreaterType *> * F1GreaterF2;
  std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2;

  bool printTypp;
};

/*********************************************************************/

class FunctionBooleanExpressionType :
  public DataThingType
{
public:
  FunctionBooleanExpressionType();
  FunctionBooleanExpressionType(
    XmlID * NameIn);
  ~FunctionBooleanExpressionType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionOperationType :
  public DataThingType
{
public:
  FunctionOperationType();
  FunctionOperationType(
    XmlID * NameIn,
    XmlIDREF * FunctionNameIn,
    XmlNMTOKEN * ExpressionIn,
    XmlPositiveInteger * ValueIn);
  ~FunctionOperationType();
  void printSelf(FILE * outFile);

  XmlIDREF * FunctionName;
  XmlNMTOKEN * Expression;
  XmlPositiveInteger * Value;

  bool printTypp;
};

/*********************************************************************/

class FunctionToDecimalBoolType :
  public FunctionBooleanExpressionType
{
public:
  FunctionToDecimalBoolType();
  FunctionToDecimalBoolType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlDecimal * A1In);
  ~FunctionToDecimalBoolType();
  void printSelf(FILE * outFile);

  XmlIDREF * F1Name;
  XmlDecimal * A1;

  bool printTypp;
};

/*********************************************************************/

class FunctionToDecimalEqualType :
  public FunctionToDecimalBoolType
{
public:
  FunctionToDecimalEqualType();
  FunctionToDecimalEqualType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlDecimal * A1In);
  ~FunctionToDecimalEqualType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToDecimalGreaterOrEqualType :
  public FunctionToDecimalBoolType
{
public:
  FunctionToDecimalGreaterOrEqualType();
  FunctionToDecimalGreaterOrEqualType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlDecimal * A1In);
  ~FunctionToDecimalGreaterOrEqualType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToDecimalGreaterType :
  public FunctionToDecimalBoolType
{
public:
  FunctionToDecimalGreaterType();
  FunctionToDecimalGreaterType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlDecimal * A1In);
  ~FunctionToDecimalGreaterType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToDecimalLessOrEqualType :
  public FunctionToDecimalBoolType
{
public:
  FunctionToDecimalLessOrEqualType();
  FunctionToDecimalLessOrEqualType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlDecimal * A1In);
  ~FunctionToDecimalLessOrEqualType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToDecimalLessType :
  public FunctionToDecimalBoolType
{
public:
  FunctionToDecimalLessType();
  FunctionToDecimalLessType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlDecimal * A1In);
  ~FunctionToDecimalLessType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToFunctionBoolType :
  public FunctionBooleanExpressionType
{
public:
  FunctionToFunctionBoolType();
  FunctionToFunctionBoolType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlIDREF * F2NameIn);
  ~FunctionToFunctionBoolType();
  void printSelf(FILE * outFile);

  XmlIDREF * F1Name;
  XmlIDREF * F2Name;

  bool printTypp;
};

/*********************************************************************/

class FunctionToFunctionEqualType :
  public FunctionToFunctionBoolType
{
public:
  FunctionToFunctionEqualType();
  FunctionToFunctionEqualType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlIDREF * F2NameIn);
  ~FunctionToFunctionEqualType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToFunctionGreaterOrEqualType :
  public FunctionToFunctionBoolType
{
public:
  FunctionToFunctionGreaterOrEqualType();
  FunctionToFunctionGreaterOrEqualType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlIDREF * F2NameIn);
  ~FunctionToFunctionGreaterOrEqualType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToFunctionGreaterType :
  public FunctionToFunctionBoolType
{
public:
  FunctionToFunctionGreaterType();
  FunctionToFunctionGreaterType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlIDREF * F2NameIn);
  ~FunctionToFunctionGreaterType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToFunctionLessOrEqualType :
  public FunctionToFunctionBoolType
{
public:
  FunctionToFunctionLessOrEqualType();
  FunctionToFunctionLessOrEqualType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlIDREF * F2NameIn);
  ~FunctionToFunctionLessOrEqualType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionToFunctionLessType :
  public FunctionToFunctionBoolType
{
public:
  FunctionToFunctionLessType();
  FunctionToFunctionLessType(
    XmlID * NameIn,
    XmlIDREF * F1NameIn,
    XmlIDREF * F2NameIn);
  ~FunctionToFunctionLessType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class FunctionType :
  public DataThingType
{
public:
  FunctionType();
  FunctionType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    XmlNMTOKEN * ReferenceNameIn,
    XmlNMTOKEN * TargetNameIn);
  ~FunctionType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * ReferenceName;
  XmlNMTOKEN * TargetName;

  bool printTypp;
};

/*********************************************************************/

class OrderingConstructType :
  public DataThingType
{
public:
  OrderingConstructType();
  OrderingConstructType(
    XmlID * NameIn);
  ~OrderingConstructType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class PreconditionType :
  public DataThingType
{
public:
  PreconditionType();
  PreconditionType(
    XmlID * NameIn,
    std::list<XmlIDREF *> * PredicateNameIn,
    XmlIDREF * FunctionNameIn,
    FunctionOperationType * FunctionOperationIn,
    std::list<FunctionToFunctionLessType *> * F1LessF2In,
    std::list<FunctionToFunctionEqualType *> * F1EqualF2In,
    std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2In,
    std::list<FunctionToFunctionGreaterType *> * F1GreaterF2In,
    std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2In);
  ~PreconditionType();
  void printSelf(FILE * outFile);

  std::list<XmlIDREF *> * PredicateName;
  XmlIDREF * FunctionName;
  FunctionOperationType * FunctionOperation;
  std::list<FunctionToFunctionLessType *> * F1LessF2;
  std::list<FunctionToFunctionEqualType *> * F1EqualF2;
  std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2;
  std::list<FunctionToFunctionGreaterType *> * F1GreaterF2;
  std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2;

  bool printTypp;
};

/*********************************************************************/

class PredicateGroupElementType :
  public DataThingType
{
public:
  PredicateGroupElementType();
  PredicateGroupElementType(
    XmlID * NameIn,
    XmlNMTOKEN * ReferenceNameIn,
    XmlNMTOKEN * TargetNameIn,
    XmlIDREF * StateRelationNameIn);
  ~PredicateGroupElementType();
  void printSelf(FILE * outFile);

  XmlNMTOKEN * ReferenceName;
  XmlNMTOKEN * TargetName;
  XmlIDREF * StateRelationName;

  bool printTypp;
};

/*********************************************************************/

class PredicateType :
  public DataThingType
{
public:
  PredicateType();
  PredicateType(
    XmlID * NameIn,
    XmlString * DescriptionIn,
    std::list<PredicateGroupElementType *> * PredicateGroupElementIn);
  ~PredicateType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  std::list<PredicateGroupElementType *> * PredicateGroupElement;

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

class SOAPType :
  public DataThingType
{
public:
  SOAPType();
  SOAPType(
    XmlID * NameIn,
    KittingWorkstationType * KittingWorkstationIn,
    DomainType * DomainIn,
    InContactWithType * InContactWithIn,
    UnderWithContactType * UnderWithContactIn,
    PartiallyInType * PartiallyInIn,
    OnTopWithContactType * OnTopWithContactIn);
  ~SOAPType();
  void printSelf(FILE * outFile);

  KittingWorkstationType * KittingWorkstation;
  DomainType * Domain;
  InContactWithType * InContactWith;
  UnderWithContactType * UnderWithContact;
  PartiallyInType * PartiallyIn;
  OnTopWithContactType * OnTopWithContact;

  bool printTypp;
};

/*********************************************************************/

class StateRelationType :
  public DataThingType
{
public:
  StateRelationType();
  StateRelationType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~StateRelationType();
  void printSelf(FILE * outFile);

  XmlString * RCC8Set;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * KitTrayParameterIn,
    XmlNMTOKEN * LargeBoxWithEmptyKitTraysParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~TakeKitTrayType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitTrayParameter;
  XmlNMTOKEN * LargeBoxWithEmptyKitTraysParameter;
  XmlNMTOKEN * EndEffectorParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~TakeKitType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * EndEffectorParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * PartParameterIn,
    XmlNMTOKEN * PartsTrayParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~TakePartType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * PartParameter;
  XmlNMTOKEN * PartsTrayParameter;
  XmlNMTOKEN * EndEffectorParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

  bool printTypp;
};

/*********************************************************************/

class UnderWithContactType :
  public StateRelationType
{
public:
  UnderWithContactType();
  UnderWithContactType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~UnderWithContactType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class AnyOrderOrderingConstructType :
  public OrderingConstructType
{
public:
  AnyOrderOrderingConstructType();
  AnyOrderOrderingConstructType(
    XmlID * NameIn,
    CountOrderingConstructType * CountOrderingConstructIn,
    XmlPositiveInteger * PositionInOrderedListIn);
  ~AnyOrderOrderingConstructType();
  void printSelf(FILE * outFile);

  CountOrderingConstructType * CountOrderingConstruct;
  XmlPositiveInteger * PositionInOrderedList;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    XmlNMTOKEN * EndEffectorHolderParameterIn,
    XmlNMTOKEN * EndEffectorChangingStationParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~AttachEndEffectorType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * EndEffectorParameter;
  XmlNMTOKEN * EndEffectorHolderParameter;
  XmlNMTOKEN * EndEffectorChangingStationParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

  bool printTypp;
};

/*********************************************************************/

class CountOrderingConstructType :
  public OrderingConstructType
{
public:
  CountOrderingConstructType();
  CountOrderingConstructType(
    XmlID * NameIn,
    PredicateType * PredicateIn,
    XmlPositiveInteger * PredicateOccurrenceIn);
  ~CountOrderingConstructType();
  void printSelf(FILE * outFile);

  PredicateType * Predicate;
  XmlPositiveInteger * PredicateOccurrence;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    XmlNMTOKEN * EndEffectorHolderParameterIn,
    XmlNMTOKEN * EndEffectorChangingStationParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~DetachEndEffectorType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * EndEffectorParameter;
  XmlNMTOKEN * EndEffectorHolderParameter;
  XmlNMTOKEN * EndEffectorChangingStationParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

  bool printTypp;
};

/*********************************************************************/

class ExistOrderingConstructType :
  public OrderingConstructType
{
public:
  ExistOrderingConstructType();
  ExistOrderingConstructType(
    XmlID * NameIn,
    PredicateType * PredicateIn);
  ~ExistOrderingConstructType();
  void printSelf(FILE * outFile);

  PredicateType * Predicate;

  bool printTypp;
};

/*********************************************************************/

class InContactWithType :
  public StateRelationType
{
public:
  InContactWithType();
  InContactWithType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~InContactWithType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class OnTopWithContactType :
  public StateRelationType
{
public:
  OnTopWithContactType();
  OnTopWithContactType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~OnTopWithContactType();
  void printSelf(FILE * outFile);


  bool printTypp;
};

/*********************************************************************/

class OrderedListOrderingConstructType :
  public OrderingConstructType
{
public:
  OrderedListOrderingConstructType();
  OrderedListOrderingConstructType(
    XmlID * NameIn,
    ExistOrderingConstructType * ExistOrderingConstructIn,
    AnyOrderOrderingConstructType * AnyOrderOrderingConstructIn);
  ~OrderedListOrderingConstructType();
  void printSelf(FILE * outFile);

  ExistOrderingConstructType * ExistOrderingConstruct;
  AnyOrderOrderingConstructType * AnyOrderOrderingConstruct;

  bool printTypp;
};

/*********************************************************************/

class PartiallyInType :
  public StateRelationType
{
public:
  PartiallyInType();
  PartiallyInType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~PartiallyInType();
  void printSelf(FILE * outFile);


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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * KitTrayParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~PutKitTrayType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitTrayParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * LargeBoxWithKitsParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~PutKitType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * LargeBoxWithKitsParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * PartParameterIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * PartsTrayParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~PutPartType();
  void printSelf(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * PartParameter;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * PartsTrayParameter;
  PreconditionType * Precondition;
  EffectType * Effect;

  bool printTypp;
};

/*********************************************************************/

class XmlHeaderForSOAP
{
public:
  XmlHeaderForSOAP();
  XmlHeaderForSOAP(
    SchemaLocation * locationIn);
  ~XmlHeaderForSOAP();
  void printSelf(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // SOAP_HH
