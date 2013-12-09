/*********************************************************************/

#ifndef SOAP_OWL_HH
#define SOAP_OWL_HH
#include <stdio.h>
#include <list>
#include "xmlSchemaInstance.hh"

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
  void printOwl(FILE * outFile);
  void printSelf(FILE * outFile) {}

  XmlVersion * version;
  XmlHeaderForSOAP * header;
  SOAPType * SOAP;
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
  void printOwl(FILE * outFile);

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
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  std::list<XmlIDREF *> * PredicateName;
  std::list<XmlIDREF *> * NotPredicateName;
  XmlIDREF * FunctionName;
  FunctionOperationType * FunctionOperation;
  std::list<FunctionToFunctionLessType *> * F1LessF2;
  std::list<FunctionToFunctionEqualType *> * F1EqualF2;
  std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2;
  std::list<FunctionToFunctionGreaterType *> * F1GreaterF2;
  std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlIDREF * FunctionName;
  XmlNMTOKEN * Expression;
  XmlPositiveInteger * Value;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlIDREF * F1Name;
  XmlDecimal * A1;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlIDREF * F1Name;
  XmlIDREF * F2Name;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * ReferenceName;
  XmlNMTOKEN * TargetName;
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

class OrderingConstructType :
  public DataThingType
{
public:
  OrderingConstructType();
  OrderingConstructType(
    XmlID * NameIn);
  ~OrderingConstructType();
  void printOwl(FILE * outFile);

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
  void printOwl(FILE * outFile);

  std::list<XmlIDREF *> * PredicateName;
  XmlIDREF * FunctionName;
  FunctionOperationType * FunctionOperation;
  std::list<FunctionToFunctionLessType *> * F1LessF2;
  std::list<FunctionToFunctionEqualType *> * F1EqualF2;
  std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2;
  std::list<FunctionToFunctionGreaterType *> * F1GreaterF2;
  std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlNMTOKEN * ReferenceName;
  XmlNMTOKEN * TargetName;
  XmlIDREF * StateRelationName;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlString * Description;
  std::list<PredicateGroupElementType *> * PredicateGroupElement;
  static std::set<std::string> individuals;

  bool printTypp;
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
  void printOwl(FILE * outFile);

  KittingWorkstationType * KittingWorkstation;
  DomainType * Domain;
  InContactWithType * InContactWith;
  UnderWithContactType * UnderWithContact;
  PartiallyInType * PartiallyIn;
  OnTopWithContactType * OnTopWithContact;
  static std::set<std::string> individuals;

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

class StateRelationType :
  public DataThingType
{
public:
  StateRelationType();
  StateRelationType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~StateRelationType();
  void printOwl(FILE * outFile);

  XmlString * RCC8Set;
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

class UnderWithContactType :
  public StateRelationType
{
public:
  UnderWithContactType();
  UnderWithContactType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~UnderWithContactType();
  void printOwl(FILE * outFile);

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
  public DataThingType
{
public:
  ActionBaseType();
  ActionBaseType(
    XmlID * NameIn);
  ~ActionBaseType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  CountOrderingConstructType * CountOrderingConstruct;
  XmlPositiveInteger * PositionInOrderedList;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  PredicateType * Predicate;
  XmlPositiveInteger * PredicateOccurrence;
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
    XmlString * DescriptionIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * KitTrayParameterIn,
    XmlNMTOKEN * WorkTableParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~CreateKitType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * KitTrayParameter;
  XmlNMTOKEN * WorkTableParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  PredicateType * Predicate;
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

class InContactWithType :
  public StateRelationType
{
public:
  InContactWithType();
  InContactWithType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~InContactWithType();
  void printOwl(FILE * outFile);

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

class OnTopWithContactType :
  public StateRelationType
{
public:
  OnTopWithContactType();
  OnTopWithContactType(
    XmlID * NameIn,
    XmlString * RCC8SetIn);
  ~OnTopWithContactType();
  void printOwl(FILE * outFile);

  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  ExistOrderingConstructType * ExistOrderingConstruct;
  AnyOrderOrderingConstructType * AnyOrderOrderingConstruct;
  static std::set<std::string> individuals;

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
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitTrayParameter;
  XmlNMTOKEN * LargeBoxWithEmptyKitTraysParameter;
  XmlNMTOKEN * EndEffectorParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~TakeKitType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * EndEffectorParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * PartParameterIn,
    XmlNMTOKEN * PartsTrayParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~TakePartType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * PartParameter;
  XmlNMTOKEN * PartsTrayParameter;
  XmlNMTOKEN * EndEffectorParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * EndEffectorParameter;
  XmlNMTOKEN * EndEffectorHolderParameter;
  XmlNMTOKEN * EndEffectorChangingStationParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
  static std::set<std::string> individuals;

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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * EndEffectorParameterIn,
    XmlNMTOKEN * EndEffectorHolderParameterIn,
    XmlNMTOKEN * EndEffectorChangingStationParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~DetachEndEffectorType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * EndEffectorParameter;
  XmlNMTOKEN * EndEffectorHolderParameter;
  XmlNMTOKEN * EndEffectorChangingStationParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitTrayParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * LargeBoxWithKitsParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~PutKitType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * LargeBoxWithKitsParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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
    XmlString * DescriptionIn,
    XmlNMTOKEN * RobotParameterIn,
    XmlNMTOKEN * PartParameterIn,
    XmlNMTOKEN * KitParameterIn,
    XmlNMTOKEN * PartsTrayParameterIn,
    PreconditionType * PreconditionIn,
    EffectType * EffectIn);
  ~PutPartType();
  void printOwl(FILE * outFile);

  XmlString * Description;
  XmlNMTOKEN * RobotParameter;
  XmlNMTOKEN * PartParameter;
  XmlNMTOKEN * KitParameter;
  XmlNMTOKEN * PartsTrayParameter;
  PreconditionType * Precondition;
  EffectType * Effect;
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

class XmlHeaderForSOAP
{
public:
  XmlHeaderForSOAP();
  XmlHeaderForSOAP(
    SchemaLocation * locationIn);
  ~XmlHeaderForSOAP();
  void printOwl(FILE * outFile);

  SchemaLocation * location;
};

/*********************************************************************/

#endif // SOAP_OWL_HH
