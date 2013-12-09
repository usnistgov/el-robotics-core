/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "owlInstancePrinter.hh"
#include "owlSoapClasses.hh"

/*********************************************************************/
/*********************************************************************/

extern OwlInstancePrinter printer;

std::set<std::string> ActionBaseType::individuals;
std::set<std::string> AnyOrderOrderingConstructType::individuals;
std::set<std::string> AttachEndEffectorType::individuals;
std::set<std::string> BoxVolumeType::individuals;
std::set<std::string> BoxyShapeType::individuals;
std::set<std::string> CountOrderingConstructType::individuals;
std::set<std::string> CreateKitType::individuals;
std::set<std::string> CylindricalShapeType::individuals;
std::set<std::string> DetachEndEffectorType::individuals;
std::set<std::string> DomainType::individuals;
std::set<std::string> EffectType::individuals;
std::set<std::string> EndEffectorChangingStationType::individuals;
std::set<std::string> EndEffectorHolderType::individuals;
std::set<std::string> ExistOrderingConstructType::individuals;
std::set<std::string> ExternalShapeType::individuals;
std::set<std::string> FunctionBooleanExpressionType::individuals;
std::set<std::string> FunctionOperationType::individuals;
std::set<std::string> FunctionToDecimalBoolType::individuals;
std::set<std::string> FunctionToDecimalEqualType::individuals;
std::set<std::string> FunctionToDecimalGreaterOrEqualType::individuals;
std::set<std::string> FunctionToDecimalGreaterType::individuals;
std::set<std::string> FunctionToDecimalLessOrEqualType::individuals;
std::set<std::string> FunctionToDecimalLessType::individuals;
std::set<std::string> FunctionToFunctionBoolType::individuals;
std::set<std::string> FunctionToFunctionEqualType::individuals;
std::set<std::string> FunctionToFunctionGreaterOrEqualType::individuals;
std::set<std::string> FunctionToFunctionGreaterType::individuals;
std::set<std::string> FunctionToFunctionLessOrEqualType::individuals;
std::set<std::string> FunctionToFunctionLessType::individuals;
std::set<std::string> FunctionType::individuals;
std::set<std::string> GripperEffectorType::individuals;
std::set<std::string> HumanType::individuals;
std::set<std::string> InContactWithType::individuals;
std::set<std::string> KitDesignType::individuals;
std::set<std::string> KitTrayType::individuals;
std::set<std::string> KitType::individuals;
std::set<std::string> KittingWorkstationType::individuals;
std::set<std::string> LargeBoxWithEmptyKitTraysType::individuals;
std::set<std::string> LargeBoxWithKitsType::individuals;
std::set<std::string> LargeContainerType::individuals;
std::set<std::string> MechanicalComponentType::individuals;
std::set<std::string> OnTopWithContactType::individuals;
std::set<std::string> OrderedListOrderingConstructType::individuals;
std::set<std::string> OrderingConstructType::individuals;
std::set<std::string> PartRefAndPoseType::individuals;
std::set<std::string> PartType::individuals;
std::set<std::string> PartiallyInType::individuals;
std::set<std::string> PartsBinType::individuals;
std::set<std::string> PartsTrayType::individuals;
std::set<std::string> PointType::individuals;
std::set<std::string> PoseLocationInType::individuals;
std::set<std::string> PoseLocationOnType::individuals;
std::set<std::string> PoseOnlyLocationType::individuals;
std::set<std::string> PreconditionType::individuals;
std::set<std::string> PredicateGroupElementType::individuals;
std::set<std::string> PredicateType::individuals;
std::set<std::string> PutKitTrayType::individuals;
std::set<std::string> PutKitType::individuals;
std::set<std::string> PutPartType::individuals;
std::set<std::string> RelativeLocationInType::individuals;
std::set<std::string> RelativeLocationOnType::individuals;
std::set<std::string> RobotType::individuals;
std::set<std::string> SOAPType::individuals;
std::set<std::string> SlotType::individuals;
std::set<std::string> StateRelationType::individuals;
std::set<std::string> StockKeepingUnitType::individuals;
std::set<std::string> TakeKitTrayType::individuals;
std::set<std::string> TakeKitType::individuals;
std::set<std::string> TakePartType::individuals;
std::set<std::string> UnderWithContactType::individuals;
std::set<std::string> VacuumEffectorMultiCupType::individuals;
std::set<std::string> VacuumEffectorSingleCupType::individuals;
std::set<std::string> VectorType::individuals;
std::set<std::string> WorkTableType::individuals;

/*********************************************************************/

/* class SOAPFile

*/

SOAPFile::SOAPFile() {}

SOAPFile::SOAPFile(
  XmlVersion * versionIn,
  XmlHeaderForSOAP * headerIn,
  SOAPType * SOAPIn)
{
  version = versionIn;
  header = headerIn;
  SOAP = SOAPIn;
}

SOAPFile::~SOAPFile() {}

void SOAPFile::printOwl(FILE * outFile)
{
  std::set<std::string>::iterator iter;
  SOAP->printOwl(outFile);

  if (ActionBaseType::individuals.size() > 1)
    printer.printIndividuals("soap:ActionBase",
       &ActionBaseType::individuals, outFile);
  if (AnyOrderOrderingConstructType::individuals.size() > 1)
    printer.printIndividuals("soap:AnyOrderOrderingConstruct",
       &AnyOrderOrderingConstructType::individuals, outFile);
  if (AttachEndEffectorType::individuals.size() > 1)
    printer.printIndividuals("soap:AttachEndEffector",
       &AttachEndEffectorType::individuals, outFile);
  if (BoxVolumeType::individuals.size() > 1)
    printer.printIndividuals("ktw:BoxVolume",
       &BoxVolumeType::individuals, outFile);
  if (BoxyShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:BoxyShape",
       &BoxyShapeType::individuals, outFile);
  if (CountOrderingConstructType::individuals.size() > 1)
    printer.printIndividuals("soap:CountOrderingConstruct",
       &CountOrderingConstructType::individuals, outFile);
  if (CreateKitType::individuals.size() > 1)
    printer.printIndividuals("soap:CreateKit",
       &CreateKitType::individuals, outFile);
  if (CylindricalShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:CylindricalShape",
       &CylindricalShapeType::individuals, outFile);
  if (DetachEndEffectorType::individuals.size() > 1)
    printer.printIndividuals("soap:DetachEndEffector",
       &DetachEndEffectorType::individuals, outFile);
  if (DomainType::individuals.size() > 1)
    printer.printIndividuals("soap:Domain",
       &DomainType::individuals, outFile);
  if (EffectType::individuals.size() > 1)
    printer.printIndividuals("soap:Effect",
       &EffectType::individuals, outFile);
  if (EndEffectorChangingStationType::individuals.size() > 1)
    printer.printIndividuals("ktw:EndEffectorChangingStation",
       &EndEffectorChangingStationType::individuals, outFile);
  if (EndEffectorHolderType::individuals.size() > 1)
    printer.printIndividuals("ktw:EndEffectorHolder",
       &EndEffectorHolderType::individuals, outFile);
  if (ExistOrderingConstructType::individuals.size() > 1)
    printer.printIndividuals("soap:ExistOrderingConstruct",
       &ExistOrderingConstructType::individuals, outFile);
  if (ExternalShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:ExternalShape",
       &ExternalShapeType::individuals, outFile);
  if (FunctionBooleanExpressionType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionBooleanExpression",
       &FunctionBooleanExpressionType::individuals, outFile);
  if (FunctionOperationType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionOperation",
       &FunctionOperationType::individuals, outFile);
  if (FunctionToDecimalBoolType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToDecimalBool",
       &FunctionToDecimalBoolType::individuals, outFile);
  if (FunctionToDecimalEqualType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToDecimalEqual",
       &FunctionToDecimalEqualType::individuals, outFile);
  if (FunctionToDecimalGreaterOrEqualType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToDecimalGreaterOrEqual",
       &FunctionToDecimalGreaterOrEqualType::individuals, outFile);
  if (FunctionToDecimalGreaterType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToDecimalGreater",
       &FunctionToDecimalGreaterType::individuals, outFile);
  if (FunctionToDecimalLessOrEqualType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToDecimalLessOrEqual",
       &FunctionToDecimalLessOrEqualType::individuals, outFile);
  if (FunctionToDecimalLessType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToDecimalLess",
       &FunctionToDecimalLessType::individuals, outFile);
  if (FunctionToFunctionBoolType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToFunctionBool",
       &FunctionToFunctionBoolType::individuals, outFile);
  if (FunctionToFunctionEqualType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToFunctionEqual",
       &FunctionToFunctionEqualType::individuals, outFile);
  if (FunctionToFunctionGreaterOrEqualType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToFunctionGreaterOrEqual",
       &FunctionToFunctionGreaterOrEqualType::individuals, outFile);
  if (FunctionToFunctionGreaterType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToFunctionGreater",
       &FunctionToFunctionGreaterType::individuals, outFile);
  if (FunctionToFunctionLessOrEqualType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToFunctionLessOrEqual",
       &FunctionToFunctionLessOrEqualType::individuals, outFile);
  if (FunctionToFunctionLessType::individuals.size() > 1)
    printer.printIndividuals("soap:FunctionToFunctionLess",
       &FunctionToFunctionLessType::individuals, outFile);
  if (FunctionType::individuals.size() > 1)
    printer.printIndividuals("soap:Function",
       &FunctionType::individuals, outFile);
  if (GripperEffectorType::individuals.size() > 1)
    printer.printIndividuals("ktw:GripperEffector",
       &GripperEffectorType::individuals, outFile);
  if (HumanType::individuals.size() > 1)
    printer.printIndividuals("ktw:Human",
       &HumanType::individuals, outFile);
  if (InContactWithType::individuals.size() > 1)
    printer.printIndividuals("soap:InContactWith",
       &InContactWithType::individuals, outFile);
  if (KitDesignType::individuals.size() > 1)
    printer.printIndividuals("ktw:KitDesign",
       &KitDesignType::individuals, outFile);
  if (KitTrayType::individuals.size() > 1)
    printer.printIndividuals("ktw:KitTray",
       &KitTrayType::individuals, outFile);
  if (KitType::individuals.size() > 1)
    printer.printIndividuals("ktw:Kit",
       &KitType::individuals, outFile);
  if (KittingWorkstationType::individuals.size() > 1)
    printer.printIndividuals("ktw:KittingWorkstation",
       &KittingWorkstationType::individuals, outFile);
  if (LargeBoxWithEmptyKitTraysType::individuals.size() > 1)
    printer.printIndividuals("ktw:LargeBoxWithEmptyKitTrays",
       &LargeBoxWithEmptyKitTraysType::individuals, outFile);
  if (LargeBoxWithKitsType::individuals.size() > 1)
    printer.printIndividuals("ktw:LargeBoxWithKits",
       &LargeBoxWithKitsType::individuals, outFile);
  if (LargeContainerType::individuals.size() > 1)
    printer.printIndividuals("ktw:LargeContainer",
       &LargeContainerType::individuals, outFile);
  if (MechanicalComponentType::individuals.size() > 1)
    printer.printIndividuals("ktw:MechanicalComponent",
       &MechanicalComponentType::individuals, outFile);
  if (OnTopWithContactType::individuals.size() > 1)
    printer.printIndividuals("soap:OnTopWithContact",
       &OnTopWithContactType::individuals, outFile);
  if (OrderedListOrderingConstructType::individuals.size() > 1)
    printer.printIndividuals("soap:OrderedListOrderingConstruct",
       &OrderedListOrderingConstructType::individuals, outFile);
  if (OrderingConstructType::individuals.size() > 1)
    printer.printIndividuals("soap:OrderingConstruct",
       &OrderingConstructType::individuals, outFile);
  if (PartRefAndPoseType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartRefAndPose",
       &PartRefAndPoseType::individuals, outFile);
  if (PartType::individuals.size() > 1)
    printer.printIndividuals("ktw:Part",
       &PartType::individuals, outFile);
  if (PartiallyInType::individuals.size() > 1)
    printer.printIndividuals("soap:PartiallyIn",
       &PartiallyInType::individuals, outFile);
  if (PartsBinType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartsBin",
       &PartsBinType::individuals, outFile);
  if (PartsTrayType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartsTray",
       &PartsTrayType::individuals, outFile);
  if (PointType::individuals.size() > 1)
    printer.printIndividuals("ktw:Point",
       &PointType::individuals, outFile);
  if (PoseLocationInType::individuals.size() > 1)
    printer.printIndividuals("ktw:PoseLocationIn",
       &PoseLocationInType::individuals, outFile);
  if (PoseLocationOnType::individuals.size() > 1)
    printer.printIndividuals("ktw:PoseLocationOn",
       &PoseLocationOnType::individuals, outFile);
  if (PoseOnlyLocationType::individuals.size() > 1)
    printer.printIndividuals("ktw:PoseOnlyLocation",
       &PoseOnlyLocationType::individuals, outFile);
  if (PreconditionType::individuals.size() > 1)
    printer.printIndividuals("soap:Precondition",
       &PreconditionType::individuals, outFile);
  if (PredicateGroupElementType::individuals.size() > 1)
    printer.printIndividuals("soap:PredicateGroupElement",
       &PredicateGroupElementType::individuals, outFile);
  if (PredicateType::individuals.size() > 1)
    printer.printIndividuals("soap:Predicate",
       &PredicateType::individuals, outFile);
  if (PutKitTrayType::individuals.size() > 1)
    printer.printIndividuals("soap:PutKitTray",
       &PutKitTrayType::individuals, outFile);
  if (PutKitType::individuals.size() > 1)
    printer.printIndividuals("soap:PutKit",
       &PutKitType::individuals, outFile);
  if (PutPartType::individuals.size() > 1)
    printer.printIndividuals("soap:PutPart",
       &PutPartType::individuals, outFile);
  if (RelativeLocationInType::individuals.size() > 1)
    printer.printIndividuals("ktw:RelativeLocationIn",
       &RelativeLocationInType::individuals, outFile);
  if (RelativeLocationOnType::individuals.size() > 1)
    printer.printIndividuals("ktw:RelativeLocationOn",
       &RelativeLocationOnType::individuals, outFile);
  if (RobotType::individuals.size() > 1)
    printer.printIndividuals("ktw:Robot",
       &RobotType::individuals, outFile);
  if (SOAPType::individuals.size() > 1)
    printer.printIndividuals("soap:SOAP",
       &SOAPType::individuals, outFile);
  if (SlotType::individuals.size() > 1)
    printer.printIndividuals("ktw:Slot",
       &SlotType::individuals, outFile);
  if (StateRelationType::individuals.size() > 1)
    printer.printIndividuals("soap:StateRelation",
       &StateRelationType::individuals, outFile);
  if (StockKeepingUnitType::individuals.size() > 1)
    printer.printIndividuals("ktw:StockKeepingUnit",
       &StockKeepingUnitType::individuals, outFile);
  if (TakeKitTrayType::individuals.size() > 1)
    printer.printIndividuals("soap:TakeKitTray",
       &TakeKitTrayType::individuals, outFile);
  if (TakeKitType::individuals.size() > 1)
    printer.printIndividuals("soap:TakeKit",
       &TakeKitType::individuals, outFile);
  if (TakePartType::individuals.size() > 1)
    printer.printIndividuals("soap:TakePart",
       &TakePartType::individuals, outFile);
  if (UnderWithContactType::individuals.size() > 1)
    printer.printIndividuals("soap:UnderWithContact",
       &UnderWithContactType::individuals, outFile);
  if (VacuumEffectorMultiCupType::individuals.size() > 1)
    printer.printIndividuals("ktw:VacuumEffectorMultiCup",
       &VacuumEffectorMultiCupType::individuals, outFile);
  if (VacuumEffectorSingleCupType::individuals.size() > 1)
    printer.printIndividuals("ktw:VacuumEffectorSingleCup",
       &VacuumEffectorSingleCupType::individuals, outFile);
  if (VectorType::individuals.size() > 1)
    printer.printIndividuals("ktw:Vector",
       &VectorType::individuals, outFile);
  if (WorkTableType::individuals.size() > 1)
    printer.printIndividuals("ktw:WorkTable",
       &WorkTableType::individuals, outFile);

  fprintf(outFile, ")\n");
}

/*********************************************************************/

/* class ActionBaseType

*/

ActionBaseType::ActionBaseType() {}

ActionBaseType::ActionBaseType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
}

ActionBaseType::~ActionBaseType() {}

void ActionBaseType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:ActionBase", outFile);
  printer.endIndi("soap:ActionBase", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class AngleUnitType

*/

AngleUnitType::AngleUnitType() :
  XmlNMTOKEN() {}

AngleUnitType::AngleUnitType(
 char * valIn) :
  XmlNMTOKEN(valIn)
{
  if (!bad)
    bad = (strcmp(val.c_str(), "degree") &&
           strcmp(val.c_str(), "radian"));
}

AngleUnitType::~AngleUnitType() {}

bool AngleUnitType::AngleUnitTypeIsBad()
{
  return (strcmp(val.c_str(), "degree") &&
          strcmp(val.c_str(), "radian"));
}

void AngleUnitType::printOwl(FILE * outFile)
{
  if (AngleUnitTypeIsBad())
    {
      fprintf(stderr, "bad AngleUnitType value, ");
      XmlNMTOKEN::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlNMTOKEN::printSelf(outFile);
}

void AngleUnitType::printProp(
 const char * property,
 XmlID * Name,
 FILE * outFile)
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  printOwl(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* class AnyOrderOrderingConstructType

*/

AnyOrderOrderingConstructType::AnyOrderOrderingConstructType() {}

AnyOrderOrderingConstructType::AnyOrderOrderingConstructType(
 XmlID * NameIn,
 CountOrderingConstructType * CountOrderingConstructIn,
 XmlPositiveInteger * PositionInOrderedListIn) :
  OrderingConstructType(
    NameIn)
{
  CountOrderingConstruct = CountOrderingConstructIn;
  PositionInOrderedList = PositionInOrderedListIn;
}

AnyOrderOrderingConstructType::~AnyOrderOrderingConstructType() {}

void AnyOrderOrderingConstructType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:AnyOrderOrderingConstruct", outFile);
  printer.printObjProp("soap:hasAnyOrderOrderingConstruct_CountOrderingConstruct",
                       Name, CountOrderingConstruct->Name, outFile);
  CountOrderingConstruct->printOwl(outFile);
  printer.printXmlPositiveIntegerProp("soap:hasAnyOrderOrderingConstruct_PositionInOrderedList",
                                      Name, PositionInOrderedList, outFile);
  printer.endIndi("soap:AnyOrderOrderingConstruct", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class AttachEndEffectorType

*/

AttachEndEffectorType::AttachEndEffectorType() {}

AttachEndEffectorType::AttachEndEffectorType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * EndEffectorParameterIn,
 XmlNMTOKEN * EndEffectorHolderParameterIn,
 XmlNMTOKEN * EndEffectorChangingStationParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  EndEffectorParameter = EndEffectorParameterIn;
  EndEffectorHolderParameter = EndEffectorHolderParameterIn;
  EndEffectorChangingStationParameter = EndEffectorChangingStationParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

AttachEndEffectorType::~AttachEndEffectorType() {}

void AttachEndEffectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:AttachEndEffector", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasAttachEndEffector_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasAttachEndEffector_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasAttachEndEffector_EndEffectorParameter",
                              Name, EndEffectorParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasAttachEndEffector_EndEffectorHolderParameter",
                              Name, EndEffectorHolderParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasAttachEndEffector_EndEffectorChangingStationParameter",
                              Name, EndEffectorChangingStationParameter, outFile);
  printer.printObjProp("soap:hasAttachEndEffector_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasAttachEndEffector_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:AttachEndEffector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class BoxVolumeType

*/

BoxVolumeType::BoxVolumeType() {}

BoxVolumeType::BoxVolumeType(
 XmlID * NameIn,
 PointType * MaximumPointIn,
 PointType * MinimumPointIn) :
  DataThingType(
    NameIn)
{
  MaximumPoint = MaximumPointIn;
  MinimumPoint = MinimumPointIn;
}

BoxVolumeType::~BoxVolumeType() {}

void BoxVolumeType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:BoxVolume", outFile);
  printer.printObjProp("ktw:hasBoxVolume_MaximumPoint",
                       Name, MaximumPoint->Name, outFile);
  MaximumPoint->printOwl(outFile);
  printer.printObjProp("ktw:hasBoxVolume_MinimumPoint",
                       Name, MinimumPoint->Name, outFile);
  MinimumPoint->printOwl(outFile);
  printer.endIndi("ktw:BoxVolume", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class BoxyShapeType

*/

BoxyShapeType::BoxyShapeType() {}

BoxyShapeType::BoxyShapeType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 PoseLocationType * GraspPoseIn,
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn,
 XmlBoolean * HasTopIn) :
  InternalShapeType(
    NameIn,
    DescriptionIn,
    GraspPoseIn)
{
  Length = LengthIn;
  Width = WidthIn;
  Height = HeightIn;
  HasTop = HasTopIn;
}

BoxyShapeType::~BoxyShapeType() {}

void BoxyShapeType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:BoxyShape", outFile);
  printer.printXmlStringProp("ktw:hasShapeDesign_Description",
                             Name, Description, outFile);
  if (GraspPose)
    {
      printer.printObjProp("ktw:hasShapeDesign_GraspPose",
                           Name, GraspPose->Name, outFile);
      GraspPose->printOwl(outFile);
    }
  Length->printProp("ktw:hasBoxyShape_Length",
                    Name, outFile);
  Width->printProp("ktw:hasBoxyShape_Width",
                   Name, outFile);
  Height->printProp("ktw:hasBoxyShape_Height",
                    Name, outFile);
  printer.printXmlBooleanProp("ktw:hasBoxyShape_HasTop",
                              Name, HasTop, outFile);
  printer.endIndi("ktw:BoxyShape", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class CountOrderingConstructType

*/

CountOrderingConstructType::CountOrderingConstructType() {}

CountOrderingConstructType::CountOrderingConstructType(
 XmlID * NameIn,
 PredicateType * PredicateIn,
 XmlPositiveInteger * PredicateOccurrenceIn) :
  OrderingConstructType(
    NameIn)
{
  Predicate = PredicateIn;
  PredicateOccurrence = PredicateOccurrenceIn;
}

CountOrderingConstructType::~CountOrderingConstructType() {}

void CountOrderingConstructType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:CountOrderingConstruct", outFile);
  printer.printObjProp("soap:hasCountOrderingConstruct_Predicate",
                       Name, Predicate->Name, outFile);
  Predicate->printOwl(outFile);
  printer.printXmlPositiveIntegerProp("soap:hasCountOrderingConstruct_PredicateOccurrence",
                                      Name, PredicateOccurrence, outFile);
  printer.endIndi("soap:CountOrderingConstruct", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class CreateKitType

*/

CreateKitType::CreateKitType() {}

CreateKitType::CreateKitType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * KitParameterIn,
 XmlNMTOKEN * KitTrayParameterIn,
 XmlNMTOKEN * WorkTableParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  ActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  KitParameter = KitParameterIn;
  KitTrayParameter = KitTrayParameterIn;
  WorkTableParameter = WorkTableParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

CreateKitType::~CreateKitType() {}

void CreateKitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:CreateKit", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasCreateKit_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasCreateKit_KitParameter",
                              Name, KitParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasCreateKit_KitTrayParameter",
                              Name, KitTrayParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasCreateKit_WorkTableParameter",
                              Name, WorkTableParameter, outFile);
  printer.printObjProp("soap:hasCreateKit_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasCreateKit_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:CreateKit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class CylindricalShapeType

*/

CylindricalShapeType::CylindricalShapeType() {}

CylindricalShapeType::CylindricalShapeType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 PoseLocationType * GraspPoseIn,
 PositiveDecimalType * DiameterIn,
 PositiveDecimalType * HeightIn,
 XmlBoolean * HasTopIn) :
  InternalShapeType(
    NameIn,
    DescriptionIn,
    GraspPoseIn)
{
  Diameter = DiameterIn;
  Height = HeightIn;
  HasTop = HasTopIn;
}

CylindricalShapeType::~CylindricalShapeType() {}

void CylindricalShapeType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:CylindricalShape", outFile);
  printer.printXmlStringProp("ktw:hasShapeDesign_Description",
                             Name, Description, outFile);
  if (GraspPose)
    {
      printer.printObjProp("ktw:hasShapeDesign_GraspPose",
                           Name, GraspPose->Name, outFile);
      GraspPose->printOwl(outFile);
    }
  Diameter->printProp("ktw:hasCylindricalShape_Diameter",
                      Name, outFile);
  Height->printProp("ktw:hasCylindricalShape_Height",
                    Name, outFile);
  printer.printXmlBooleanProp("ktw:hasCylindricalShape_HasTop",
                              Name, HasTop, outFile);
  printer.endIndi("ktw:CylindricalShape", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class DataThingType

*/

DataThingType::DataThingType() {}

DataThingType::DataThingType(
 XmlID * NameIn)
{
  Name = NameIn;
}

DataThingType::~DataThingType() {}

/*********************************************************************/

/* class DetachEndEffectorType

*/

DetachEndEffectorType::DetachEndEffectorType() {}

DetachEndEffectorType::DetachEndEffectorType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * EndEffectorParameterIn,
 XmlNMTOKEN * EndEffectorHolderParameterIn,
 XmlNMTOKEN * EndEffectorChangingStationParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  EndEffectorParameter = EndEffectorParameterIn;
  EndEffectorHolderParameter = EndEffectorHolderParameterIn;
  EndEffectorChangingStationParameter = EndEffectorChangingStationParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

DetachEndEffectorType::~DetachEndEffectorType() {}

void DetachEndEffectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:DetachEndEffector", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasDetachEndEffector_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasDetachEndEffector_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasDetachEndEffector_EndEffectorParameter",
                              Name, EndEffectorParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasDetachEndEffector_EndEffectorHolderParameter",
                              Name, EndEffectorHolderParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasDetachEndEffector_EndEffectorChangingStationParameter",
                              Name, EndEffectorChangingStationParameter, outFile);
  printer.printObjProp("soap:hasDetachEndEffector_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasDetachEndEffector_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:DetachEndEffector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class DomainType

*/

DomainType::DomainType() {}

DomainType::DomainType(
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
 PutKitTrayType * PutKitTrayIn) :
  DataThingType(
    NameIn)
{
  Requirement = RequirementIn;
  Variable = VariableIn;
  Predicate = PredicateIn;
  Function = FunctionIn;
  AttachEndEffector = AttachEndEffectorIn;
  CreateKit = CreateKitIn;
  DetachEndEffector = DetachEndEffectorIn;
  TakePart = TakePartIn;
  TakeKit = TakeKitIn;
  TakeKitTray = TakeKitTrayIn;
  PutPart = PutPartIn;
  PutKit = PutKitIn;
  PutKitTray = PutKitTrayIn;
}

DomainType::~DomainType() {}

void DomainType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:Domain", outFile);
  {
    std::list<XmlNMTOKEN *>::iterator iter;
    for (iter = Requirement->begin();
        iter != Requirement->end(); iter++)
      {
        printer.printXmlNMTOKENProp("soap:hasDomain_Requirement",
                                    Name, *iter, outFile);
      }
  }
  {
    std::list<XmlNMTOKEN *>::iterator iter;
    for (iter = Variable->begin();
        iter != Variable->end(); iter++)
      {
        printer.printXmlNMTOKENProp("soap:hasDomain_Variable",
                                    Name, *iter, outFile);
      }
  }
  {
    std::list<PredicateType *>::iterator iter;
    for (iter = Predicate->begin();
         iter != Predicate->end(); iter++)
      {
        printer.printObjProp("soap:hasDomain_Predicate",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionType *>::iterator iter;
    for (iter = Function->begin();
         iter != Function->end(); iter++)
      {
        printer.printObjProp("soap:hasDomain_Function",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjProp("soap:hasDomain_AttachEndEffector",
                       Name, AttachEndEffector->Name, outFile);
  AttachEndEffector->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_CreateKit",
                       Name, CreateKit->Name, outFile);
  CreateKit->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_DetachEndEffector",
                       Name, DetachEndEffector->Name, outFile);
  DetachEndEffector->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_TakePart",
                       Name, TakePart->Name, outFile);
  TakePart->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_TakeKit",
                       Name, TakeKit->Name, outFile);
  TakeKit->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_TakeKitTray",
                       Name, TakeKitTray->Name, outFile);
  TakeKitTray->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_PutPart",
                       Name, PutPart->Name, outFile);
  PutPart->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_PutKit",
                       Name, PutKit->Name, outFile);
  PutKit->printOwl(outFile);
  printer.printObjProp("soap:hasDomain_PutKitTray",
                       Name, PutKitTray->Name, outFile);
  PutKitTray->printOwl(outFile);
  printer.endIndi("soap:Domain", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class EffectType

*/

EffectType::EffectType() {}

EffectType::EffectType(
 XmlID * NameIn,
 std::list<XmlIDREF *> * PredicateNameIn,
 std::list<XmlIDREF *> * NotPredicateNameIn,
 XmlIDREF * FunctionNameIn,
 FunctionOperationType * FunctionOperationIn,
 std::list<FunctionToFunctionLessType *> * F1LessF2In,
 std::list<FunctionToFunctionEqualType *> * F1EqualF2In,
 std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2In,
 std::list<FunctionToFunctionGreaterType *> * F1GreaterF2In,
 std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2In) :
  DataThingType(
    NameIn)
{
  PredicateName = PredicateNameIn;
  NotPredicateName = NotPredicateNameIn;
  FunctionName = FunctionNameIn;
  FunctionOperation = FunctionOperationIn;
  F1LessF2 = F1LessF2In;
  F1EqualF2 = F1EqualF2In;
  F1GreaterOrEqualF2 = F1GreaterOrEqualF2In;
  F1GreaterF2 = F1GreaterF2In;
  F1LessOrEqualF2 = F1LessOrEqualF2In;
}

EffectType::~EffectType() {}

void EffectType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:Effect", outFile);
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = PredicateName->begin();
         iter != PredicateName->end(); iter++)
      {
        printer.printObjRefProp("soap:hasEffect_Predicate",
                                Name, *iter, outFile);
      }
  }
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = NotPredicateName->begin();
         iter != NotPredicateName->end(); iter++)
      {
        printer.printObjRefProp("soap:hasEffect_NotPredicate",
                                Name, *iter, outFile);
      }
  }
  if (FunctionName)
    {
      printer.printObjRefProp("soap:hasEffect_Function",
                              Name, FunctionName, outFile);
    }
  if (FunctionOperation)
    {
      printer.printObjProp("soap:hasEffect_FunctionOperation",
                           Name, FunctionOperation->Name, outFile);
      FunctionOperation->printOwl(outFile);
    }
  {
    std::list<FunctionToFunctionLessType *>::iterator iter;
    for (iter = F1LessF2->begin();
         iter != F1LessF2->end(); iter++)
      {
        printer.printObjProp("soap:hasEffect_F1LessF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionEqualType *>::iterator iter;
    for (iter = F1EqualF2->begin();
         iter != F1EqualF2->end(); iter++)
      {
        printer.printObjProp("soap:hasEffect_F1EqualF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionGreaterOrEqualType *>::iterator iter;
    for (iter = F1GreaterOrEqualF2->begin();
         iter != F1GreaterOrEqualF2->end(); iter++)
      {
        printer.printObjProp("soap:hasEffect_F1GreaterOrEqualF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionGreaterType *>::iterator iter;
    for (iter = F1GreaterF2->begin();
         iter != F1GreaterF2->end(); iter++)
      {
        printer.printObjProp("soap:hasEffect_F1GreaterF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionLessOrEqualType *>::iterator iter;
    for (iter = F1LessOrEqualF2->begin();
         iter != F1LessOrEqualF2->end(); iter++)
      {
        printer.printObjProp("soap:hasEffect_F1LessOrEqualF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("soap:Effect", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class EndEffectorChangingStationType

*/

EndEffectorChangingStationType::EndEffectorChangingStationType() {}

EndEffectorChangingStationType::EndEffectorChangingStationType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 MechanicalComponentType * BaseIn,
 std::list<EndEffectorHolderType *> * EndEffectorHolderIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  Base = BaseIn;
  EndEffectorHolder = EndEffectorHolderIn;
}

EndEffectorChangingStationType::~EndEffectorChangingStationType() {}

void EndEffectorChangingStationType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:EndEffectorChangingStation", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printObjProp("ktw:hasEndEffectorChangingStation_Base",
                       Name, Base->Name, outFile);
  Base->printOwl(outFile);
  {
    std::list<EndEffectorHolderType *>::iterator iter;
    for (iter = EndEffectorHolder->begin();
         iter != EndEffectorHolder->end(); iter++)
      {
        printer.printObjProp("ktw:hasEndEffectorChangingStation_EndEffectorHolder",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:EndEffectorChangingStation", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class EndEffectorHolderType

*/

EndEffectorHolderType::EndEffectorHolderType() {}

EndEffectorHolderType::EndEffectorHolderType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 EndEffectorType * EndEffectorIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  EndEffector = EndEffectorIn;
}

EndEffectorHolderType::~EndEffectorHolderType() {}

void EndEffectorHolderType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:EndEffectorHolder", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  if (EndEffector)
    {
      printer.printObjProp("ktw:hasEndEffectorHolder_EndEffector",
                           Name, EndEffector->Name, outFile);
      EndEffector->printOwl(outFile);
    }
  printer.endIndi("ktw:EndEffectorHolder", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class EndEffectorType

*/

EndEffectorType::EndEffectorType() {}

EndEffectorType::EndEffectorType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 SolidObjectType * HeldObjectIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  Description = DescriptionIn;
  Weight = WeightIn;
  MaximumLoadWeight = MaximumLoadWeightIn;
  HeldObject = HeldObjectIn;
}

EndEffectorType::~EndEffectorType() {}

/*********************************************************************/

/* class ExistOrderingConstructType

*/

ExistOrderingConstructType::ExistOrderingConstructType() {}

ExistOrderingConstructType::ExistOrderingConstructType(
 XmlID * NameIn,
 PredicateType * PredicateIn) :
  OrderingConstructType(
    NameIn)
{
  Predicate = PredicateIn;
}

ExistOrderingConstructType::~ExistOrderingConstructType() {}

void ExistOrderingConstructType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:ExistOrderingConstruct", outFile);
  printer.printObjProp("soap:hasExistOrderingConstruct_Predicate",
                       Name, Predicate->Name, outFile);
  Predicate->printOwl(outFile);
  printer.endIndi("soap:ExistOrderingConstruct", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class ExternalShapeType

*/

ExternalShapeType::ExternalShapeType() {}

ExternalShapeType::ExternalShapeType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 PoseLocationType * GraspPoseIn,
 XmlString * ModelFormatNameIn,
 XmlString * ModelFileNameIn,
 XmlString * ModelNameIn) :
  ShapeDesignType(
    NameIn,
    DescriptionIn,
    GraspPoseIn)
{
  ModelFormatName = ModelFormatNameIn;
  ModelFileName = ModelFileNameIn;
  ModelName = ModelNameIn;
}

ExternalShapeType::~ExternalShapeType() {}

void ExternalShapeType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:ExternalShape", outFile);
  printer.printXmlStringProp("ktw:hasShapeDesign_Description",
                             Name, Description, outFile);
  if (GraspPose)
    {
      printer.printObjProp("ktw:hasShapeDesign_GraspPose",
                           Name, GraspPose->Name, outFile);
      GraspPose->printOwl(outFile);
    }
  printer.printXmlStringProp("ktw:hasExternalShape_ModelFormatName",
                             Name, ModelFormatName, outFile);
  printer.printXmlStringProp("ktw:hasExternalShape_ModelFileName",
                             Name, ModelFileName, outFile);
  if (ModelName)
    {
      printer.printXmlStringProp("ktw:hasExternalShape_ModelName",
                                 Name, ModelName, outFile);
    }
  printer.endIndi("ktw:ExternalShape", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionBooleanExpressionType

*/

FunctionBooleanExpressionType::FunctionBooleanExpressionType() {}

FunctionBooleanExpressionType::FunctionBooleanExpressionType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
}

FunctionBooleanExpressionType::~FunctionBooleanExpressionType() {}

void FunctionBooleanExpressionType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionBooleanExpression", outFile);
  printer.endIndi("soap:FunctionBooleanExpression", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionOperationType

*/

FunctionOperationType::FunctionOperationType() {}

FunctionOperationType::FunctionOperationType(
 XmlID * NameIn,
 XmlIDREF * FunctionNameIn,
 XmlNMTOKEN * ExpressionIn,
 XmlPositiveInteger * ValueIn) :
  DataThingType(
    NameIn)
{
  FunctionName = FunctionNameIn;
  Expression = ExpressionIn;
  Value = ValueIn;
}

FunctionOperationType::~FunctionOperationType() {}

void FunctionOperationType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionOperation", outFile);
  printer.printObjRefProp("soap:hasFunctionOperation_Function",
                          Name, FunctionName, outFile);
  printer.printXmlNMTOKENProp("soap:hasFunctionOperation_Expression",
                              Name, Expression, outFile);
  printer.printXmlPositiveIntegerProp("soap:hasFunctionOperation_Value",
                                      Name, Value, outFile);
  printer.endIndi("soap:FunctionOperation", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToDecimalBoolType

*/

FunctionToDecimalBoolType::FunctionToDecimalBoolType() {}

FunctionToDecimalBoolType::FunctionToDecimalBoolType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlDecimal * A1In) :
  FunctionBooleanExpressionType(
    NameIn)
{
  F1Name = F1NameIn;
  A1 = A1In;
}

FunctionToDecimalBoolType::~FunctionToDecimalBoolType() {}

void FunctionToDecimalBoolType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToDecimalBool", outFile);
  printer.printObjRefProp("soap:hasFunctionToDecimalBool_F1",
                          Name, F1Name, outFile);
  printer.printXmlDecimalProp("soap:hasFunctionToDecimalBool_A1",
                              Name, A1, outFile);
  printer.endIndi("soap:FunctionToDecimalBool", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToDecimalEqualType

*/

FunctionToDecimalEqualType::FunctionToDecimalEqualType() {}

FunctionToDecimalEqualType::FunctionToDecimalEqualType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlDecimal * A1In) :
  FunctionToDecimalBoolType(
    NameIn,
    F1NameIn,
    A1In)
{
}

FunctionToDecimalEqualType::~FunctionToDecimalEqualType() {}

void FunctionToDecimalEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToDecimalEqual", outFile);
  printer.printObjRefProp("soap:hasFunctionToDecimalBool_F1",
                          Name, F1Name, outFile);
  printer.printXmlDecimalProp("soap:hasFunctionToDecimalBool_A1",
                              Name, A1, outFile);
  printer.endIndi("soap:FunctionToDecimalEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToDecimalGreaterOrEqualType

*/

FunctionToDecimalGreaterOrEqualType::FunctionToDecimalGreaterOrEqualType() {}

FunctionToDecimalGreaterOrEqualType::FunctionToDecimalGreaterOrEqualType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlDecimal * A1In) :
  FunctionToDecimalBoolType(
    NameIn,
    F1NameIn,
    A1In)
{
}

FunctionToDecimalGreaterOrEqualType::~FunctionToDecimalGreaterOrEqualType() {}

void FunctionToDecimalGreaterOrEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToDecimalGreaterOrEqual", outFile);
  printer.printObjRefProp("soap:hasFunctionToDecimalBool_F1",
                          Name, F1Name, outFile);
  printer.printXmlDecimalProp("soap:hasFunctionToDecimalBool_A1",
                              Name, A1, outFile);
  printer.endIndi("soap:FunctionToDecimalGreaterOrEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToDecimalGreaterType

*/

FunctionToDecimalGreaterType::FunctionToDecimalGreaterType() {}

FunctionToDecimalGreaterType::FunctionToDecimalGreaterType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlDecimal * A1In) :
  FunctionToDecimalBoolType(
    NameIn,
    F1NameIn,
    A1In)
{
}

FunctionToDecimalGreaterType::~FunctionToDecimalGreaterType() {}

void FunctionToDecimalGreaterType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToDecimalGreater", outFile);
  printer.printObjRefProp("soap:hasFunctionToDecimalBool_F1",
                          Name, F1Name, outFile);
  printer.printXmlDecimalProp("soap:hasFunctionToDecimalBool_A1",
                              Name, A1, outFile);
  printer.endIndi("soap:FunctionToDecimalGreater", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToDecimalLessOrEqualType

*/

FunctionToDecimalLessOrEqualType::FunctionToDecimalLessOrEqualType() {}

FunctionToDecimalLessOrEqualType::FunctionToDecimalLessOrEqualType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlDecimal * A1In) :
  FunctionToDecimalBoolType(
    NameIn,
    F1NameIn,
    A1In)
{
}

FunctionToDecimalLessOrEqualType::~FunctionToDecimalLessOrEqualType() {}

void FunctionToDecimalLessOrEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToDecimalLessOrEqual", outFile);
  printer.printObjRefProp("soap:hasFunctionToDecimalBool_F1",
                          Name, F1Name, outFile);
  printer.printXmlDecimalProp("soap:hasFunctionToDecimalBool_A1",
                              Name, A1, outFile);
  printer.endIndi("soap:FunctionToDecimalLessOrEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToDecimalLessType

*/

FunctionToDecimalLessType::FunctionToDecimalLessType() {}

FunctionToDecimalLessType::FunctionToDecimalLessType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlDecimal * A1In) :
  FunctionToDecimalBoolType(
    NameIn,
    F1NameIn,
    A1In)
{
}

FunctionToDecimalLessType::~FunctionToDecimalLessType() {}

void FunctionToDecimalLessType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToDecimalLess", outFile);
  printer.printObjRefProp("soap:hasFunctionToDecimalBool_F1",
                          Name, F1Name, outFile);
  printer.printXmlDecimalProp("soap:hasFunctionToDecimalBool_A1",
                              Name, A1, outFile);
  printer.endIndi("soap:FunctionToDecimalLess", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToFunctionBoolType

*/

FunctionToFunctionBoolType::FunctionToFunctionBoolType() {}

FunctionToFunctionBoolType::FunctionToFunctionBoolType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlIDREF * F2NameIn) :
  FunctionBooleanExpressionType(
    NameIn)
{
  F1Name = F1NameIn;
  F2Name = F2NameIn;
}

FunctionToFunctionBoolType::~FunctionToFunctionBoolType() {}

void FunctionToFunctionBoolType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToFunctionBool", outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F1",
                          Name, F1Name, outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F2",
                          Name, F2Name, outFile);
  printer.endIndi("soap:FunctionToFunctionBool", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToFunctionEqualType

*/

FunctionToFunctionEqualType::FunctionToFunctionEqualType() {}

FunctionToFunctionEqualType::FunctionToFunctionEqualType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlIDREF * F2NameIn) :
  FunctionToFunctionBoolType(
    NameIn,
    F1NameIn,
    F2NameIn)
{
}

FunctionToFunctionEqualType::~FunctionToFunctionEqualType() {}

void FunctionToFunctionEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToFunctionEqual", outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F1",
                          Name, F1Name, outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F2",
                          Name, F2Name, outFile);
  printer.endIndi("soap:FunctionToFunctionEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToFunctionGreaterOrEqualType

*/

FunctionToFunctionGreaterOrEqualType::FunctionToFunctionGreaterOrEqualType() {}

FunctionToFunctionGreaterOrEqualType::FunctionToFunctionGreaterOrEqualType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlIDREF * F2NameIn) :
  FunctionToFunctionBoolType(
    NameIn,
    F1NameIn,
    F2NameIn)
{
}

FunctionToFunctionGreaterOrEqualType::~FunctionToFunctionGreaterOrEqualType() {}

void FunctionToFunctionGreaterOrEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToFunctionGreaterOrEqual", outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F1",
                          Name, F1Name, outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F2",
                          Name, F2Name, outFile);
  printer.endIndi("soap:FunctionToFunctionGreaterOrEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToFunctionGreaterType

*/

FunctionToFunctionGreaterType::FunctionToFunctionGreaterType() {}

FunctionToFunctionGreaterType::FunctionToFunctionGreaterType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlIDREF * F2NameIn) :
  FunctionToFunctionBoolType(
    NameIn,
    F1NameIn,
    F2NameIn)
{
}

FunctionToFunctionGreaterType::~FunctionToFunctionGreaterType() {}

void FunctionToFunctionGreaterType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToFunctionGreater", outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F1",
                          Name, F1Name, outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F2",
                          Name, F2Name, outFile);
  printer.endIndi("soap:FunctionToFunctionGreater", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToFunctionLessOrEqualType

*/

FunctionToFunctionLessOrEqualType::FunctionToFunctionLessOrEqualType() {}

FunctionToFunctionLessOrEqualType::FunctionToFunctionLessOrEqualType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlIDREF * F2NameIn) :
  FunctionToFunctionBoolType(
    NameIn,
    F1NameIn,
    F2NameIn)
{
}

FunctionToFunctionLessOrEqualType::~FunctionToFunctionLessOrEqualType() {}

void FunctionToFunctionLessOrEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToFunctionLessOrEqual", outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F1",
                          Name, F1Name, outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F2",
                          Name, F2Name, outFile);
  printer.endIndi("soap:FunctionToFunctionLessOrEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionToFunctionLessType

*/

FunctionToFunctionLessType::FunctionToFunctionLessType() {}

FunctionToFunctionLessType::FunctionToFunctionLessType(
 XmlID * NameIn,
 XmlIDREF * F1NameIn,
 XmlIDREF * F2NameIn) :
  FunctionToFunctionBoolType(
    NameIn,
    F1NameIn,
    F2NameIn)
{
}

FunctionToFunctionLessType::~FunctionToFunctionLessType() {}

void FunctionToFunctionLessType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:FunctionToFunctionLess", outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F1",
                          Name, F1Name, outFile);
  printer.printObjRefProp("soap:hasFunctionToFunctionBool_F2",
                          Name, F2Name, outFile);
  printer.endIndi("soap:FunctionToFunctionLess", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class FunctionType

*/

FunctionType::FunctionType() {}

FunctionType::FunctionType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * ReferenceNameIn,
 XmlNMTOKEN * TargetNameIn) :
  DataThingType(
    NameIn)
{
  Description = DescriptionIn;
  ReferenceName = ReferenceNameIn;
  TargetName = TargetNameIn;
}

FunctionType::~FunctionType() {}

void FunctionType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:Function", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasFunction_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasFunction_ReferenceName",
                              Name, ReferenceName, outFile);
  if (TargetName)
    {
      printer.printXmlNMTOKENProp("soap:hasFunction_TargetName",
                                  Name, TargetName, outFile);
    }
  printer.endIndi("soap:Function", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class GripperEffectorType

*/

GripperEffectorType::GripperEffectorType() {}

GripperEffectorType::GripperEffectorType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 SolidObjectType * HeldObjectIn) :
  EndEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn,
    HeldObjectIn)
{
}

GripperEffectorType::~GripperEffectorType() {}

void GripperEffectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:GripperEffector", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printXmlStringProp("ktw:hasEndEffector_Description",
                             Name, Description, outFile);
  Weight->printProp("ktw:hasEndEffector_Weight",
                    Name, outFile);
  MaximumLoadWeight->printProp("ktw:hasEndEffector_MaximumLoadWeight",
                               Name, outFile);
  if (HeldObject)
    {
      printer.printObjProp("ktw:hasEndEffector_HeldObject",
                           Name, HeldObject->Name, outFile);
      HeldObject->printOwl(outFile);
    }
  printer.endIndi("ktw:GripperEffector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class HumanType

*/

HumanType::HumanType() {}

HumanType::HumanType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
}

HumanType::~HumanType() {}

void HumanType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Human", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.endIndi("ktw:Human", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class InContactWithType

*/

InContactWithType::InContactWithType() {}

InContactWithType::InContactWithType(
 XmlID * NameIn,
 XmlString * RCC8SetIn) :
  StateRelationType(
    NameIn,
    RCC8SetIn)
{
}

InContactWithType::~InContactWithType() {}

void InContactWithType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:InContactWith", outFile);
  printer.printXmlStringProp("soap:hasStateRelation_RCC8Set",
                             Name, RCC8Set, outFile);
  printer.endIndi("soap:InContactWith", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class InternalShapeType

*/

InternalShapeType::InternalShapeType() {}

InternalShapeType::InternalShapeType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 PoseLocationType * GraspPoseIn) :
  ShapeDesignType(
    NameIn,
    DescriptionIn,
    GraspPoseIn)
{
}

InternalShapeType::~InternalShapeType() {}

/*********************************************************************/

/* class KitDesignType

*/

KitDesignType::KitDesignType() {}

KitDesignType::KitDesignType(
 XmlID * NameIn,
 XmlIDREF * KitTraySkuNameIn,
 std::list<PartRefAndPoseType *> * PartRefAndPoseIn) :
  DataThingType(
    NameIn)
{
  KitTraySkuName = KitTraySkuNameIn;
  PartRefAndPose = PartRefAndPoseIn;
}

KitDesignType::~KitDesignType() {}

void KitDesignType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:KitDesign", outFile);
  printer.printObjRefProp("ktw:hasKitDesign_KitTraySku",
                          Name, KitTraySkuName, outFile);
  {
    std::list<PartRefAndPoseType *>::iterator iter;
    for (iter = PartRefAndPose->begin();
         iter != PartRefAndPose->end(); iter++)
      {
        printer.printObjProp("ktw:hasKitDesign_PartRefAndPose",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:KitDesign", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class KitTrayType

*/

KitTrayType::KitTrayType() {}

KitTrayType::KitTrayType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    SkuNameIn)
{
  SerialNumber = SerialNumberIn;
}

KitTrayType::~KitTrayType() {}

void KitTrayType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:KitTray", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjRefProp("ktw:hasSkuObject_Sku",
                          Name, SkuName, outFile);
  printer.printXmlNMTOKENProp("ktw:hasKitTray_SerialNumber",
                              Name, SerialNumber, outFile);
  printer.endIndi("ktw:KitTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class KitType

*/

KitType::KitType() {}

KitType::KitType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlIDREF * DesignNameIn,
 KitTrayType * KitTrayIn,
 std::list<PartType *> * PartIn,
 std::list<SlotType *> * SlotIn,
 XmlBoolean * FinishedIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  DesignName = DesignNameIn;
  KitTray = KitTrayIn;
  Part = PartIn;
  Slot = SlotIn;
  Finished = FinishedIn;
}

KitType::~KitType() {}

void KitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Kit", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printObjRefProp("ktw:hasKit_Design",
                          Name, DesignName, outFile);
  printer.printObjProp("ktw:hasKit_KitTray",
                       Name, KitTray->Name, outFile);
  KitTray->printOwl(outFile);
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin();
         iter != Part->end(); iter++)
      {
        printer.printObjProp("ktw:hasKit_Part",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<SlotType *>::iterator iter;
    for (iter = Slot->begin();
         iter != Slot->end(); iter++)
      {
        printer.printObjProp("ktw:hasKit_Slot",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printXmlBooleanProp("ktw:hasKit_Finished",
                              Name, Finished, outFile);
  printer.endIndi("ktw:Kit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class KittingWorkstationType

*/

KittingWorkstationType::KittingWorkstationType() {}

KittingWorkstationType::KittingWorkstationType(
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
 WeightUnitType * WeightUnitIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  AngleUnit = AngleUnitIn;
  ChangingStation = ChangingStationIn;
  KitDesign = KitDesignIn;
  LengthUnit = LengthUnitIn;
  Object = ObjectIn;
  OtherObstacle = OtherObstacleIn;
  Robot = RobotIn;
  Sku = SkuIn;
  WeightUnit = WeightUnitIn;
}

KittingWorkstationType::~KittingWorkstationType() {}

void KittingWorkstationType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:KittingWorkstation", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  AngleUnit->printProp("ktw:hasKittingWorkstation_AngleUnit",
                       Name, outFile);
  printer.printObjProp("ktw:hasKittingWorkstation_ChangingStation",
                       Name, ChangingStation->Name, outFile);
  ChangingStation->printOwl(outFile);
  {
    std::list<KitDesignType *>::iterator iter;
    for (iter = KitDesign->begin();
         iter != KitDesign->end(); iter++)
      {
        printer.printObjProp("ktw:hasKittingWorkstation_KitDesign",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  LengthUnit->printProp("ktw:hasKittingWorkstation_LengthUnit",
                        Name, outFile);
  {
    std::list<SolidObjectType *>::iterator iter;
    for (iter = Object->begin();
         iter != Object->end(); iter++)
      {
        printer.printObjProp("ktw:hasKittingWorkstation_Object",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<BoxVolumeType *>::iterator iter;
    for (iter = OtherObstacle->begin();
         iter != OtherObstacle->end(); iter++)
      {
        printer.printObjProp("ktw:hasKittingWorkstation_OtherObstacle",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjProp("ktw:hasKittingWorkstation_Robot",
                       Name, Robot->Name, outFile);
  Robot->printOwl(outFile);
  {
    std::list<StockKeepingUnitType *>::iterator iter;
    for (iter = Sku->begin();
         iter != Sku->end(); iter++)
      {
        printer.printObjProp("ktw:hasKittingWorkstation_Sku",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  WeightUnit->printProp("ktw:hasKittingWorkstation_WeightUnit",
                        Name, outFile);
  printer.endIndi("ktw:KittingWorkstation", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class LargeBoxWithEmptyKitTraysType

*/

LargeBoxWithEmptyKitTraysType::LargeBoxWithEmptyKitTraysType() {}

LargeBoxWithEmptyKitTraysType::LargeBoxWithEmptyKitTraysType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 LargeContainerType * LargeContainerIn,
 std::list<KitTrayType *> * KitTrayIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  LargeContainer = LargeContainerIn;
  KitTray = KitTrayIn;
}

LargeBoxWithEmptyKitTraysType::~LargeBoxWithEmptyKitTraysType() {}

void LargeBoxWithEmptyKitTraysType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:LargeBoxWithEmptyKitTrays", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printObjProp("ktw:hasLargeBoxWithEmptyKitTrays_LargeContainer",
                       Name, LargeContainer->Name, outFile);
  LargeContainer->printOwl(outFile);
  {
    std::list<KitTrayType *>::iterator iter;
    for (iter = KitTray->begin();
         iter != KitTray->end(); iter++)
      {
        printer.printObjProp("ktw:hasLargeBoxWithEmptyKitTrays_KitTray",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:LargeBoxWithEmptyKitTrays", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class LargeBoxWithKitsType

*/

LargeBoxWithKitsType::LargeBoxWithKitsType() {}

LargeBoxWithKitsType::LargeBoxWithKitsType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 LargeContainerType * LargeContainerIn,
 std::list<KitType *> * KitIn,
 XmlIDREF * KitDesignNameIn,
 XmlPositiveInteger * CapacityIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  LargeContainer = LargeContainerIn;
  Kit = KitIn;
  KitDesignName = KitDesignNameIn;
  Capacity = CapacityIn;
}

LargeBoxWithKitsType::~LargeBoxWithKitsType() {}

void LargeBoxWithKitsType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:LargeBoxWithKits", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printObjProp("ktw:hasLargeBoxWithKits_LargeContainer",
                       Name, LargeContainer->Name, outFile);
  LargeContainer->printOwl(outFile);
  {
    std::list<KitType *>::iterator iter;
    for (iter = Kit->begin();
         iter != Kit->end(); iter++)
      {
        printer.printObjProp("ktw:hasLargeBoxWithKits_Kit",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjRefProp("ktw:hasLargeBoxWithKits_KitDesign",
                          Name, KitDesignName, outFile);
  printer.printXmlPositiveIntegerProp("ktw:hasLargeBoxWithKits_Capacity",
                                      Name, Capacity, outFile);
  printer.endIndi("ktw:LargeBoxWithKits", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class LargeContainerType

*/

LargeContainerType::LargeContainerType() {}

LargeContainerType::LargeContainerType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    SkuNameIn)
{
  SerialNumber = SerialNumberIn;
}

LargeContainerType::~LargeContainerType() {}

void LargeContainerType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:LargeContainer", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjRefProp("ktw:hasSkuObject_Sku",
                          Name, SkuName, outFile);
  printer.printXmlNMTOKENProp("ktw:hasLargeContainer_SerialNumber",
                              Name, SerialNumber, outFile);
  printer.endIndi("ktw:LargeContainer", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class LengthUnitType

*/

LengthUnitType::LengthUnitType() :
  XmlNMTOKEN() {}

LengthUnitType::LengthUnitType(
 char * valIn) :
  XmlNMTOKEN(valIn)
{
  if (!bad)
    bad = (strcmp(val.c_str(), "meter") &&
           strcmp(val.c_str(), "millimeter") &&
           strcmp(val.c_str(), "inch"));
}

LengthUnitType::~LengthUnitType() {}

bool LengthUnitType::LengthUnitTypeIsBad()
{
  return (strcmp(val.c_str(), "meter") &&
          strcmp(val.c_str(), "millimeter") &&
          strcmp(val.c_str(), "inch"));
}

void LengthUnitType::printOwl(FILE * outFile)
{
  if (LengthUnitTypeIsBad())
    {
      fprintf(stderr, "bad LengthUnitType value, ");
      XmlNMTOKEN::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlNMTOKEN::printSelf(outFile);
}

void LengthUnitType::printProp(
 const char * property,
 XmlID * Name,
 FILE * outFile)
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  printOwl(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* class MechanicalComponentType

*/

MechanicalComponentType::MechanicalComponentType() {}

MechanicalComponentType::MechanicalComponentType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
}

MechanicalComponentType::~MechanicalComponentType() {}

void MechanicalComponentType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:MechanicalComponent", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.endIndi("ktw:MechanicalComponent", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class NoSkuObjectType

*/

NoSkuObjectType::NoSkuObjectType() {}

NoSkuObjectType::NoSkuObjectType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  InternalShape = InternalShapeIn;
  ExternalShape = ExternalShapeIn;
}

NoSkuObjectType::~NoSkuObjectType() {}

/*********************************************************************/

/* class OnTopWithContactType

*/

OnTopWithContactType::OnTopWithContactType() {}

OnTopWithContactType::OnTopWithContactType(
 XmlID * NameIn,
 XmlString * RCC8SetIn) :
  StateRelationType(
    NameIn,
    RCC8SetIn)
{
}

OnTopWithContactType::~OnTopWithContactType() {}

void OnTopWithContactType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:OnTopWithContact", outFile);
  printer.printXmlStringProp("soap:hasStateRelation_RCC8Set",
                             Name, RCC8Set, outFile);
  printer.endIndi("soap:OnTopWithContact", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class OrderedListOrderingConstructType

*/

OrderedListOrderingConstructType::OrderedListOrderingConstructType() {}

OrderedListOrderingConstructType::OrderedListOrderingConstructType(
 XmlID * NameIn,
 ExistOrderingConstructType * ExistOrderingConstructIn,
 AnyOrderOrderingConstructType * AnyOrderOrderingConstructIn) :
  OrderingConstructType(
    NameIn)
{
  ExistOrderingConstruct = ExistOrderingConstructIn;
  AnyOrderOrderingConstruct = AnyOrderOrderingConstructIn;
}

OrderedListOrderingConstructType::~OrderedListOrderingConstructType() {}

void OrderedListOrderingConstructType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:OrderedListOrderingConstruct", outFile);
  printer.printObjProp("soap:hasOrderedListOrderingConstruct_ExistOrderingConstruct",
                       Name, ExistOrderingConstruct->Name, outFile);
  ExistOrderingConstruct->printOwl(outFile);
  printer.printObjProp("soap:hasOrderedListOrderingConstruct_AnyOrderOrderingConstruct",
                       Name, AnyOrderOrderingConstruct->Name, outFile);
  AnyOrderOrderingConstruct->printOwl(outFile);
  printer.endIndi("soap:OrderedListOrderingConstruct", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class OrderingConstructType

*/

OrderingConstructType::OrderingConstructType() {}

OrderingConstructType::OrderingConstructType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
}

OrderingConstructType::~OrderingConstructType() {}

void OrderingConstructType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:OrderingConstruct", outFile);
  printer.endIndi("soap:OrderingConstruct", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartRefAndPoseType

*/

PartRefAndPoseType::PartRefAndPoseType() {}

PartRefAndPoseType::PartRefAndPoseType(
 XmlID * NameIn,
 XmlIDREF * SkuNameIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn) :
  DataThingType(
    NameIn)
{
  SkuName = SkuNameIn;
  Point = PointIn;
  XAxis = XAxisIn;
  ZAxis = ZAxisIn;
}

PartRefAndPoseType::~PartRefAndPoseType() {}

void PartRefAndPoseType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:PartRefAndPose", outFile);
  printer.printObjRefProp("ktw:hasPartRefAndPose_Sku",
                          Name, SkuName, outFile);
  printer.printObjProp("ktw:hasPartRefAndPose_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("ktw:hasPartRefAndPose_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("ktw:hasPartRefAndPose_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  printer.endIndi("ktw:PartRefAndPose", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartType

*/

PartType::PartType() {}

PartType::PartType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    SkuNameIn)
{
  SerialNumber = SerialNumberIn;
}

PartType::~PartType() {}

void PartType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Part", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjRefProp("ktw:hasSkuObject_Sku",
                          Name, SkuName, outFile);
  printer.printXmlNMTOKENProp("ktw:hasPart_SerialNumber",
                              Name, SerialNumber, outFile);
  printer.endIndi("ktw:Part", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartiallyInType

*/

PartiallyInType::PartiallyInType() {}

PartiallyInType::PartiallyInType(
 XmlID * NameIn,
 XmlString * RCC8SetIn) :
  StateRelationType(
    NameIn,
    RCC8SetIn)
{
}

PartiallyInType::~PartiallyInType() {}

void PartiallyInType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:PartiallyIn", outFile);
  printer.printXmlStringProp("soap:hasStateRelation_RCC8Set",
                             Name, RCC8Set, outFile);
  printer.endIndi("soap:PartiallyIn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartsBinType

*/

PartsBinType::PartsBinType() {}

PartsBinType::PartsBinType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn,
 XmlIDREF * PartSkuNameIn,
 XmlNonNegativeInteger * PartQuantityIn,
 std::list<PartType *> * PartIn) :
  PartsVesselType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    SkuNameIn,
    SerialNumberIn,
    PartSkuNameIn,
    PartQuantityIn,
    PartIn)
{
}

PartsBinType::~PartsBinType() {}

void PartsBinType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:PartsBin", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjRefProp("ktw:hasSkuObject_Sku",
                          Name, SkuName, outFile);
  printer.printXmlNMTOKENProp("ktw:hasPartsVessel_SerialNumber",
                              Name, SerialNumber, outFile);
  printer.printObjRefProp("ktw:hasPartsVessel_PartSku",
                          Name, PartSkuName, outFile);
  printer.printXmlNonNegativeIntegerProp("ktw:hasPartsVessel_PartQuantity",
                                         Name, PartQuantity, outFile);
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin();
         iter != Part->end(); iter++)
      {
        printer.printObjProp("ktw:hasPartsVessel_Part",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:PartsBin", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartsTrayType

*/

PartsTrayType::PartsTrayType() {}

PartsTrayType::PartsTrayType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn,
 XmlIDREF * PartSkuNameIn,
 XmlNonNegativeInteger * PartQuantityIn,
 std::list<PartType *> * PartIn) :
  PartsVesselType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    SkuNameIn,
    SerialNumberIn,
    PartSkuNameIn,
    PartQuantityIn,
    PartIn)
{
}

PartsTrayType::~PartsTrayType() {}

void PartsTrayType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:PartsTray", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjRefProp("ktw:hasSkuObject_Sku",
                          Name, SkuName, outFile);
  printer.printXmlNMTOKENProp("ktw:hasPartsVessel_SerialNumber",
                              Name, SerialNumber, outFile);
  printer.printObjRefProp("ktw:hasPartsVessel_PartSku",
                          Name, PartSkuName, outFile);
  printer.printXmlNonNegativeIntegerProp("ktw:hasPartsVessel_PartQuantity",
                                         Name, PartQuantity, outFile);
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin();
         iter != Part->end(); iter++)
      {
        printer.printObjProp("ktw:hasPartsVessel_Part",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:PartsTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartsVesselType

*/

PartsVesselType::PartsVesselType() {}

PartsVesselType::PartsVesselType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn,
 XmlIDREF * PartSkuNameIn,
 XmlNonNegativeInteger * PartQuantityIn,
 std::list<PartType *> * PartIn) :
  SkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    SkuNameIn)
{
  SerialNumber = SerialNumberIn;
  PartSkuName = PartSkuNameIn;
  PartQuantity = PartQuantityIn;
  Part = PartIn;
}

PartsVesselType::~PartsVesselType() {}

/*********************************************************************/

/* class PhysicalLocationType

*/

PhysicalLocationType::PhysicalLocationType() {}

PhysicalLocationType::PhysicalLocationType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn) :
  DataThingType(
    NameIn)
{
  RefObjectName = RefObjectNameIn;
  Timestamp = TimestampIn;
}

PhysicalLocationType::~PhysicalLocationType() {}

/*********************************************************************/

/* class PointType

*/

PointType::PointType() {}

PointType::PointType(
 XmlID * NameIn,
 XmlDecimal * XIn,
 XmlDecimal * YIn,
 XmlDecimal * ZIn) :
  DataThingType(
    NameIn)
{
  X = XIn;
  Y = YIn;
  Z = ZIn;
}

PointType::~PointType() {}

void PointType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Point", outFile);
  printer.printXmlDecimalProp("ktw:hasPoint_X",
                              Name, X, outFile);
  printer.printXmlDecimalProp("ktw:hasPoint_Y",
                              Name, Y, outFile);
  printer.printXmlDecimalProp("ktw:hasPoint_Z",
                              Name, Z, outFile);
  printer.endIndi("ktw:Point", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationInType

*/

PoseLocationInType::PoseLocationInType() {}

PoseLocationInType::PoseLocationInType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PoseLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn,
    PointIn,
    XAxisIn,
    ZAxisIn,
    PositionStandardDeviationIn,
    OrientationStandardDeviationIn)
{
}

PoseLocationInType::~PoseLocationInType() {}

void PoseLocationInType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:PoseLocationIn", outFile);
  printer.printObjRefProp("ktw:hasPhysicalLocation_RefObject",
                          Name, RefObjectName, outFile);
  if (Timestamp)
    {
      printer.printXmlDateTimeProp("ktw:hasPhysicalLocation_Timestamp",
                                   Name, Timestamp, outFile);
    }
  printer.printObjProp("ktw:hasPoseLocation_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("ktw:hasPoseLocation_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("ktw:hasPoseLocation_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  if (PositionStandardDeviation)
    {
      PositionStandardDeviation->printProp("ktw:hasPoseLocation_PositionStandardDeviation",
                                           Name, outFile);
    }
  if (OrientationStandardDeviation)
    {
      OrientationStandardDeviation->printProp("ktw:hasPoseLocation_OrientationStandardDeviation",
                                              Name, outFile);
    }
  printer.endIndi("ktw:PoseLocationIn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationOnType

*/

PoseLocationOnType::PoseLocationOnType() {}

PoseLocationOnType::PoseLocationOnType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PoseLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn,
    PointIn,
    XAxisIn,
    ZAxisIn,
    PositionStandardDeviationIn,
    OrientationStandardDeviationIn)
{
}

PoseLocationOnType::~PoseLocationOnType() {}

void PoseLocationOnType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:PoseLocationOn", outFile);
  printer.printObjRefProp("ktw:hasPhysicalLocation_RefObject",
                          Name, RefObjectName, outFile);
  if (Timestamp)
    {
      printer.printXmlDateTimeProp("ktw:hasPhysicalLocation_Timestamp",
                                   Name, Timestamp, outFile);
    }
  printer.printObjProp("ktw:hasPoseLocation_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("ktw:hasPoseLocation_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("ktw:hasPoseLocation_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  if (PositionStandardDeviation)
    {
      PositionStandardDeviation->printProp("ktw:hasPoseLocation_PositionStandardDeviation",
                                           Name, outFile);
    }
  if (OrientationStandardDeviation)
    {
      OrientationStandardDeviation->printProp("ktw:hasPoseLocation_OrientationStandardDeviation",
                                              Name, outFile);
    }
  printer.endIndi("ktw:PoseLocationOn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationType

*/

PoseLocationType::PoseLocationType() {}

PoseLocationType::PoseLocationType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PhysicalLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn)
{
  Point = PointIn;
  XAxis = XAxisIn;
  ZAxis = ZAxisIn;
  PositionStandardDeviation = PositionStandardDeviationIn;
  OrientationStandardDeviation = OrientationStandardDeviationIn;
}

PoseLocationType::~PoseLocationType() {}

/*********************************************************************/

/* class PoseOnlyLocationType

*/

PoseOnlyLocationType::PoseOnlyLocationType() {}

PoseOnlyLocationType::PoseOnlyLocationType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PoseLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn,
    PointIn,
    XAxisIn,
    ZAxisIn,
    PositionStandardDeviationIn,
    OrientationStandardDeviationIn)
{
}

PoseOnlyLocationType::~PoseOnlyLocationType() {}

void PoseOnlyLocationType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:PoseOnlyLocation", outFile);
  printer.printObjRefProp("ktw:hasPhysicalLocation_RefObject",
                          Name, RefObjectName, outFile);
  if (Timestamp)
    {
      printer.printXmlDateTimeProp("ktw:hasPhysicalLocation_Timestamp",
                                   Name, Timestamp, outFile);
    }
  printer.printObjProp("ktw:hasPoseLocation_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("ktw:hasPoseLocation_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("ktw:hasPoseLocation_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  if (PositionStandardDeviation)
    {
      PositionStandardDeviation->printProp("ktw:hasPoseLocation_PositionStandardDeviation",
                                           Name, outFile);
    }
  if (OrientationStandardDeviation)
    {
      OrientationStandardDeviation->printProp("ktw:hasPoseLocation_OrientationStandardDeviation",
                                              Name, outFile);
    }
  printer.endIndi("ktw:PoseOnlyLocation", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PositiveDecimalType

*/

PositiveDecimalType::PositiveDecimalType() :
  XmlDecimal() {}

PositiveDecimalType::PositiveDecimalType(
 char * valIn) : XmlDecimal(valIn)
{
  if (!bad)
    bad = ((val <= 0));
}

PositiveDecimalType::~PositiveDecimalType() {}

bool PositiveDecimalType::PositiveDecimalTypeIsBad()
{
  if (XmlDecimalIsBad())
    return true;
  return ((val <= 0));
}

void PositiveDecimalType::printOwl(FILE * outFile)
{
  if (PositiveDecimalTypeIsBad())
    {
      fprintf(stderr, "bad PositiveDecimalType value, ");
      XmlDecimal::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlDecimal::printSelf(outFile);
}

void PositiveDecimalType::printProp(
 const char * property,
 XmlID * Name,
 FILE * outFile)
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  printOwl(outFile);
  fprintf(outFile, "\"^^xsd:decimal)\n");
}

/*********************************************************************/

/* class PreconditionType

*/

PreconditionType::PreconditionType() {}

PreconditionType::PreconditionType(
 XmlID * NameIn,
 std::list<XmlIDREF *> * PredicateNameIn,
 XmlIDREF * FunctionNameIn,
 FunctionOperationType * FunctionOperationIn,
 std::list<FunctionToFunctionLessType *> * F1LessF2In,
 std::list<FunctionToFunctionEqualType *> * F1EqualF2In,
 std::list<FunctionToFunctionGreaterOrEqualType *> * F1GreaterOrEqualF2In,
 std::list<FunctionToFunctionGreaterType *> * F1GreaterF2In,
 std::list<FunctionToFunctionLessOrEqualType *> * F1LessOrEqualF2In) :
  DataThingType(
    NameIn)
{
  PredicateName = PredicateNameIn;
  FunctionName = FunctionNameIn;
  FunctionOperation = FunctionOperationIn;
  F1LessF2 = F1LessF2In;
  F1EqualF2 = F1EqualF2In;
  F1GreaterOrEqualF2 = F1GreaterOrEqualF2In;
  F1GreaterF2 = F1GreaterF2In;
  F1LessOrEqualF2 = F1LessOrEqualF2In;
}

PreconditionType::~PreconditionType() {}

void PreconditionType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:Precondition", outFile);
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = PredicateName->begin();
         iter != PredicateName->end(); iter++)
      {
        printer.printObjRefProp("soap:hasPrecondition_Predicate",
                                Name, *iter, outFile);
      }
  }
  if (FunctionName)
    {
      printer.printObjRefProp("soap:hasPrecondition_Function",
                              Name, FunctionName, outFile);
    }
  if (FunctionOperation)
    {
      printer.printObjProp("soap:hasPrecondition_FunctionOperation",
                           Name, FunctionOperation->Name, outFile);
      FunctionOperation->printOwl(outFile);
    }
  {
    std::list<FunctionToFunctionLessType *>::iterator iter;
    for (iter = F1LessF2->begin();
         iter != F1LessF2->end(); iter++)
      {
        printer.printObjProp("soap:hasPrecondition_F1LessF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionEqualType *>::iterator iter;
    for (iter = F1EqualF2->begin();
         iter != F1EqualF2->end(); iter++)
      {
        printer.printObjProp("soap:hasPrecondition_F1EqualF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionGreaterOrEqualType *>::iterator iter;
    for (iter = F1GreaterOrEqualF2->begin();
         iter != F1GreaterOrEqualF2->end(); iter++)
      {
        printer.printObjProp("soap:hasPrecondition_F1GreaterOrEqualF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionGreaterType *>::iterator iter;
    for (iter = F1GreaterF2->begin();
         iter != F1GreaterF2->end(); iter++)
      {
        printer.printObjProp("soap:hasPrecondition_F1GreaterF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  {
    std::list<FunctionToFunctionLessOrEqualType *>::iterator iter;
    for (iter = F1LessOrEqualF2->begin();
         iter != F1LessOrEqualF2->end(); iter++)
      {
        printer.printObjProp("soap:hasPrecondition_F1LessOrEqualF2",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("soap:Precondition", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PredicateGroupElementType

*/

PredicateGroupElementType::PredicateGroupElementType() {}

PredicateGroupElementType::PredicateGroupElementType(
 XmlID * NameIn,
 XmlNMTOKEN * ReferenceNameIn,
 XmlNMTOKEN * TargetNameIn,
 XmlIDREF * StateRelationNameIn) :
  DataThingType(
    NameIn)
{
  ReferenceName = ReferenceNameIn;
  TargetName = TargetNameIn;
  StateRelationName = StateRelationNameIn;
}

PredicateGroupElementType::~PredicateGroupElementType() {}

void PredicateGroupElementType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:PredicateGroupElement", outFile);
  printer.printXmlNMTOKENProp("soap:hasPredicateGroupElement_ReferenceName",
                              Name, ReferenceName, outFile);
  if (TargetName)
    {
      printer.printXmlNMTOKENProp("soap:hasPredicateGroupElement_TargetName",
                                  Name, TargetName, outFile);
    }
  if (StateRelationName)
    {
      printer.printObjRefProp("soap:hasPredicateGroupElement_StateRelation",
                              Name, StateRelationName, outFile);
    }
  printer.endIndi("soap:PredicateGroupElement", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PredicateType

*/

PredicateType::PredicateType() {}

PredicateType::PredicateType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 std::list<PredicateGroupElementType *> * PredicateGroupElementIn) :
  DataThingType(
    NameIn)
{
  Description = DescriptionIn;
  PredicateGroupElement = PredicateGroupElementIn;
}

PredicateType::~PredicateType() {}

void PredicateType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:Predicate", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasPredicate_Description",
                                 Name, Description, outFile);
    }
  {
    std::list<PredicateGroupElementType *>::iterator iter;
    for (iter = PredicateGroupElement->begin();
         iter != PredicateGroupElement->end(); iter++)
      {
        printer.printObjProp("soap:hasPredicate_PredicateGroupElement",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("soap:Predicate", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PutKitTrayType

*/

PutKitTrayType::PutKitTrayType() {}

PutKitTrayType::PutKitTrayType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * KitTrayParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  KitTrayParameter = KitTrayParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

PutKitTrayType::~PutKitTrayType() {}

void PutKitTrayType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:PutKitTray", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasPutKitTray_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasPutKitTray_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasPutKitTray_KitTrayParameter",
                              Name, KitTrayParameter, outFile);
  printer.printObjProp("soap:hasPutKitTray_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasPutKitTray_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:PutKitTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PutKitType

*/

PutKitType::PutKitType() {}

PutKitType::PutKitType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * KitParameterIn,
 XmlNMTOKEN * LargeBoxWithKitsParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  KitParameter = KitParameterIn;
  LargeBoxWithKitsParameter = LargeBoxWithKitsParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

PutKitType::~PutKitType() {}

void PutKitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:PutKit", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasPutKit_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasPutKit_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasPutKit_KitParameter",
                              Name, KitParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasPutKit_LargeBoxWithKitsParameter",
                              Name, LargeBoxWithKitsParameter, outFile);
  printer.printObjProp("soap:hasPutKit_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasPutKit_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:PutKit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PutPartType

*/

PutPartType::PutPartType() {}

PutPartType::PutPartType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * PartParameterIn,
 XmlNMTOKEN * KitParameterIn,
 XmlNMTOKEN * PartsTrayParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  PartParameter = PartParameterIn;
  KitParameter = KitParameterIn;
  PartsTrayParameter = PartsTrayParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

PutPartType::~PutPartType() {}

void PutPartType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:PutPart", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasPutPart_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasPutPart_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasPutPart_PartParameter",
                              Name, PartParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasPutPart_KitParameter",
                              Name, KitParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasPutPart_PartsTrayParameter",
                              Name, PartsTrayParameter, outFile);
  printer.printObjProp("soap:hasPutPart_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasPutPart_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:PutPart", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationInType

*/

RelativeLocationInType::RelativeLocationInType() {}

RelativeLocationInType::RelativeLocationInType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 XmlString * DescriptionIn) :
  RelativeLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn,
    DescriptionIn)
{
}

RelativeLocationInType::~RelativeLocationInType() {}

void RelativeLocationInType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:RelativeLocationIn", outFile);
  printer.printObjRefProp("ktw:hasPhysicalLocation_RefObject",
                          Name, RefObjectName, outFile);
  if (Timestamp)
    {
      printer.printXmlDateTimeProp("ktw:hasPhysicalLocation_Timestamp",
                                   Name, Timestamp, outFile);
    }
  printer.printXmlStringProp("ktw:hasRelativeLocation_Description",
                             Name, Description, outFile);
  printer.endIndi("ktw:RelativeLocationIn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationOnType

*/

RelativeLocationOnType::RelativeLocationOnType() {}

RelativeLocationOnType::RelativeLocationOnType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 XmlString * DescriptionIn) :
  RelativeLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn,
    DescriptionIn)
{
}

RelativeLocationOnType::~RelativeLocationOnType() {}

void RelativeLocationOnType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:RelativeLocationOn", outFile);
  printer.printObjRefProp("ktw:hasPhysicalLocation_RefObject",
                          Name, RefObjectName, outFile);
  if (Timestamp)
    {
      printer.printXmlDateTimeProp("ktw:hasPhysicalLocation_Timestamp",
                                   Name, Timestamp, outFile);
    }
  printer.printXmlStringProp("ktw:hasRelativeLocation_Description",
                             Name, Description, outFile);
  printer.endIndi("ktw:RelativeLocationOn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationType

*/

RelativeLocationType::RelativeLocationType() {}

RelativeLocationType::RelativeLocationType(
 XmlID * NameIn,
 XmlIDREF * RefObjectNameIn,
 XmlDateTime * TimestampIn,
 XmlString * DescriptionIn) :
  PhysicalLocationType(
    NameIn,
    RefObjectNameIn,
    TimestampIn)
{
  Description = DescriptionIn;
}

RelativeLocationType::~RelativeLocationType() {}

/*********************************************************************/

/* class RobotActionBaseType

*/

RobotActionBaseType::RobotActionBaseType() {}

RobotActionBaseType::RobotActionBaseType(
 XmlID * NameIn) :
  ActionBaseType(
    NameIn)
{
}

RobotActionBaseType::~RobotActionBaseType() {}

/*********************************************************************/

/* class RobotType

*/

RobotType::RobotType() {}

RobotType::RobotType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlString * DescriptionIn,
 EndEffectorType * EndEffectorIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 std::list<BoxVolumeType *> * WorkVolumeIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  Description = DescriptionIn;
  EndEffector = EndEffectorIn;
  MaximumLoadWeight = MaximumLoadWeightIn;
  WorkVolume = WorkVolumeIn;
}

RobotType::~RobotType() {}

void RobotType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Robot", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printXmlStringProp("ktw:hasRobot_Description",
                             Name, Description, outFile);
  if (EndEffector)
    {
      printer.printObjProp("ktw:hasRobot_EndEffector",
                           Name, EndEffector->Name, outFile);
      EndEffector->printOwl(outFile);
    }
  MaximumLoadWeight->printProp("ktw:hasRobot_MaximumLoadWeight",
                               Name, outFile);
  {
    std::list<BoxVolumeType *>::iterator iter;
    for (iter = WorkVolume->begin();
         iter != WorkVolume->end(); iter++)
      {
        printer.printObjProp("ktw:hasRobot_WorkVolume",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:Robot", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class SOAPType

*/

SOAPType::SOAPType() {}

SOAPType::SOAPType(
 XmlID * NameIn,
 KittingWorkstationType * KittingWorkstationIn,
 DomainType * DomainIn,
 InContactWithType * InContactWithIn,
 UnderWithContactType * UnderWithContactIn,
 PartiallyInType * PartiallyInIn,
 OnTopWithContactType * OnTopWithContactIn) :
  DataThingType(
    NameIn)
{
  KittingWorkstation = KittingWorkstationIn;
  Domain = DomainIn;
  InContactWith = InContactWithIn;
  UnderWithContact = UnderWithContactIn;
  PartiallyIn = PartiallyInIn;
  OnTopWithContact = OnTopWithContactIn;
}

SOAPType::~SOAPType() {}

void SOAPType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:SOAP", outFile);
  printer.printObjProp("soap:hasSOAP_KittingWorkstation",
                       Name, KittingWorkstation->Name, outFile);
  KittingWorkstation->printOwl(outFile);
  printer.printObjProp("soap:hasSOAP_Domain",
                       Name, Domain->Name, outFile);
  Domain->printOwl(outFile);
  printer.printObjProp("soap:hasSOAP_InContactWith",
                       Name, InContactWith->Name, outFile);
  InContactWith->printOwl(outFile);
  printer.printObjProp("soap:hasSOAP_UnderWithContact",
                       Name, UnderWithContact->Name, outFile);
  UnderWithContact->printOwl(outFile);
  printer.printObjProp("soap:hasSOAP_PartiallyIn",
                       Name, PartiallyIn->Name, outFile);
  PartiallyIn->printOwl(outFile);
  printer.printObjProp("soap:hasSOAP_OnTopWithContact",
                       Name, OnTopWithContact->Name, outFile);
  OnTopWithContact->printOwl(outFile);
  printer.endIndi("soap:SOAP", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class ShapeDesignType

*/

ShapeDesignType::ShapeDesignType() {}

ShapeDesignType::ShapeDesignType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 PoseLocationType * GraspPoseIn) :
  DataThingType(
    NameIn)
{
  Description = DescriptionIn;
  GraspPose = GraspPoseIn;
}

ShapeDesignType::~ShapeDesignType() {}

/*********************************************************************/

/* class SkuObjectType

*/

SkuObjectType::SkuObjectType() {}

SkuObjectType::SkuObjectType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 XmlIDREF * SkuNameIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  SkuName = SkuNameIn;
}

SkuObjectType::~SkuObjectType() {}

/*********************************************************************/

/* class SlotType

*/

SlotType::SlotType() {}

SlotType::SlotType(
 XmlID * NameIn,
 XmlIDREF * PartRefAndPoseNameIn,
 XmlIDREF * PartNameIn) :
  DataThingType(
    NameIn)
{
  PartRefAndPoseName = PartRefAndPoseNameIn;
  PartName = PartNameIn;
}

SlotType::~SlotType() {}

void SlotType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Slot", outFile);
  printer.printObjRefProp("ktw:hasSlot_PartRefAndPose",
                          Name, PartRefAndPoseName, outFile);
  if (PartName)
    {
      printer.printObjRefProp("ktw:hasSlot_Part",
                              Name, PartName, outFile);
    }
  printer.endIndi("ktw:Slot", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class SolidObjectType

*/

SolidObjectType::SolidObjectType() {}

SolidObjectType::SolidObjectType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn)
{
  Name = NameIn;
  PrimaryLocation = PrimaryLocationIn;
  SecondaryLocation = SecondaryLocationIn;
}

SolidObjectType::~SolidObjectType() {}

/*********************************************************************/

/* class StateRelationType

*/

StateRelationType::StateRelationType() {}

StateRelationType::StateRelationType(
 XmlID * NameIn,
 XmlString * RCC8SetIn) :
  DataThingType(
    NameIn)
{
  RCC8Set = RCC8SetIn;
}

StateRelationType::~StateRelationType() {}

void StateRelationType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:StateRelation", outFile);
  printer.printXmlStringProp("soap:hasStateRelation_RCC8Set",
                             Name, RCC8Set, outFile);
  printer.endIndi("soap:StateRelation", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class StockKeepingUnitType

*/

StockKeepingUnitType::StockKeepingUnitType() {}

StockKeepingUnitType::StockKeepingUnitType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 PositiveDecimalType * WeightIn,
 std::list<XmlIDREF *> * EndEffectorNameIn) :
  DataThingType(
    NameIn)
{
  Description = DescriptionIn;
  InternalShape = InternalShapeIn;
  ExternalShape = ExternalShapeIn;
  Weight = WeightIn;
  EndEffectorName = EndEffectorNameIn;
}

StockKeepingUnitType::~StockKeepingUnitType() {}

void StockKeepingUnitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:StockKeepingUnit", outFile);
  printer.printXmlStringProp("ktw:hasStockKeepingUnit_Description",
                             Name, Description, outFile);
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasStockKeepingUnit_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasStockKeepingUnit_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  Weight->printProp("ktw:hasStockKeepingUnit_Weight",
                    Name, outFile);
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = EndEffectorName->begin();
         iter != EndEffectorName->end(); iter++)
      {
        printer.printObjRefProp("ktw:hasStockKeepingUnit_EndEffector",
                                Name, *iter, outFile);
      }
  }
  printer.endIndi("ktw:StockKeepingUnit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TakeKitTrayType

*/

TakeKitTrayType::TakeKitTrayType() {}

TakeKitTrayType::TakeKitTrayType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * KitTrayParameterIn,
 XmlNMTOKEN * LargeBoxWithEmptyKitTraysParameterIn,
 XmlNMTOKEN * EndEffectorParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  KitTrayParameter = KitTrayParameterIn;
  LargeBoxWithEmptyKitTraysParameter = LargeBoxWithEmptyKitTraysParameterIn;
  EndEffectorParameter = EndEffectorParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

TakeKitTrayType::~TakeKitTrayType() {}

void TakeKitTrayType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:TakeKitTray", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasTakeKitTray_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasTakeKitTray_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakeKitTray_KitTrayParameter",
                              Name, KitTrayParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakeKitTray_LargeBoxWithEmptyKitTraysParameter",
                              Name, LargeBoxWithEmptyKitTraysParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakeKitTray_EndEffectorParameter",
                              Name, EndEffectorParameter, outFile);
  printer.printObjProp("soap:hasTakeKitTray_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasTakeKitTray_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:TakeKitTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TakeKitType

*/

TakeKitType::TakeKitType() {}

TakeKitType::TakeKitType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * KitParameterIn,
 XmlNMTOKEN * EndEffectorParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  KitParameter = KitParameterIn;
  EndEffectorParameter = EndEffectorParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

TakeKitType::~TakeKitType() {}

void TakeKitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:TakeKit", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasTakeKit_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasTakeKit_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakeKit_KitParameter",
                              Name, KitParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakeKit_EndEffectorParameter",
                              Name, EndEffectorParameter, outFile);
  printer.printObjProp("soap:hasTakeKit_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasTakeKit_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:TakeKit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TakePartType

*/

TakePartType::TakePartType() {}

TakePartType::TakePartType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 XmlNMTOKEN * RobotParameterIn,
 XmlNMTOKEN * PartParameterIn,
 XmlNMTOKEN * PartsTrayParameterIn,
 XmlNMTOKEN * EndEffectorParameterIn,
 PreconditionType * PreconditionIn,
 EffectType * EffectIn) :
  RobotActionBaseType(
    NameIn)
{
  Description = DescriptionIn;
  RobotParameter = RobotParameterIn;
  PartParameter = PartParameterIn;
  PartsTrayParameter = PartsTrayParameterIn;
  EndEffectorParameter = EndEffectorParameterIn;
  Precondition = PreconditionIn;
  Effect = EffectIn;
}

TakePartType::~TakePartType() {}

void TakePartType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:TakePart", outFile);
  if (Description)
    {
      printer.printXmlStringProp("soap:hasTakePart_Description",
                                 Name, Description, outFile);
    }
  printer.printXmlNMTOKENProp("soap:hasTakePart_RobotParameter",
                              Name, RobotParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakePart_PartParameter",
                              Name, PartParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakePart_PartsTrayParameter",
                              Name, PartsTrayParameter, outFile);
  printer.printXmlNMTOKENProp("soap:hasTakePart_EndEffectorParameter",
                              Name, EndEffectorParameter, outFile);
  printer.printObjProp("soap:hasTakePart_Precondition",
                       Name, Precondition->Name, outFile);
  Precondition->printOwl(outFile);
  printer.printObjProp("soap:hasTakePart_Effect",
                       Name, Effect->Name, outFile);
  Effect->printOwl(outFile);
  printer.endIndi("soap:TakePart", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class UnderWithContactType

*/

UnderWithContactType::UnderWithContactType() {}

UnderWithContactType::UnderWithContactType(
 XmlID * NameIn,
 XmlString * RCC8SetIn) :
  StateRelationType(
    NameIn,
    RCC8SetIn)
{
}

UnderWithContactType::~UnderWithContactType() {}

void UnderWithContactType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "soap:UnderWithContact", outFile);
  printer.printXmlStringProp("soap:hasStateRelation_RCC8Set",
                             Name, RCC8Set, outFile);
  printer.endIndi("soap:UnderWithContact", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class VacuumEffectorMultiCupType

*/

VacuumEffectorMultiCupType::VacuumEffectorMultiCupType() {}

VacuumEffectorMultiCupType::VacuumEffectorMultiCupType(
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
 PositiveDecimalType * ArrayRadiusIn) :
  VacuumEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn,
    HeldObjectIn,
    CupDiameterIn,
    LengthIn)
{
  ArrayNumber = ArrayNumberIn;
  ArrayRadius = ArrayRadiusIn;
}

VacuumEffectorMultiCupType::~VacuumEffectorMultiCupType() {}

void VacuumEffectorMultiCupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:VacuumEffectorMultiCup", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printXmlStringProp("ktw:hasEndEffector_Description",
                             Name, Description, outFile);
  Weight->printProp("ktw:hasEndEffector_Weight",
                    Name, outFile);
  MaximumLoadWeight->printProp("ktw:hasEndEffector_MaximumLoadWeight",
                               Name, outFile);
  if (HeldObject)
    {
      printer.printObjProp("ktw:hasEndEffector_HeldObject",
                           Name, HeldObject->Name, outFile);
      HeldObject->printOwl(outFile);
    }
  CupDiameter->printProp("ktw:hasVacuumEffector_CupDiameter",
                         Name, outFile);
  Length->printProp("ktw:hasVacuumEffector_Length",
                    Name, outFile);
  printer.printXmlPositiveIntegerProp("ktw:hasVacuumEffectorMultiCup_ArrayNumber",
                                      Name, ArrayNumber, outFile);
  ArrayRadius->printProp("ktw:hasVacuumEffectorMultiCup_ArrayRadius",
                         Name, outFile);
  printer.endIndi("ktw:VacuumEffectorMultiCup", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class VacuumEffectorSingleCupType

*/

VacuumEffectorSingleCupType::VacuumEffectorSingleCupType() {}

VacuumEffectorSingleCupType::VacuumEffectorSingleCupType(
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
 PositiveDecimalType * LengthIn) :
  VacuumEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn,
    HeldObjectIn,
    CupDiameterIn,
    LengthIn)
{
}

VacuumEffectorSingleCupType::~VacuumEffectorSingleCupType() {}

void VacuumEffectorSingleCupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:VacuumEffectorSingleCup", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  printer.printXmlStringProp("ktw:hasEndEffector_Description",
                             Name, Description, outFile);
  Weight->printProp("ktw:hasEndEffector_Weight",
                    Name, outFile);
  MaximumLoadWeight->printProp("ktw:hasEndEffector_MaximumLoadWeight",
                               Name, outFile);
  if (HeldObject)
    {
      printer.printObjProp("ktw:hasEndEffector_HeldObject",
                           Name, HeldObject->Name, outFile);
      HeldObject->printOwl(outFile);
    }
  CupDiameter->printProp("ktw:hasVacuumEffector_CupDiameter",
                         Name, outFile);
  Length->printProp("ktw:hasVacuumEffector_Length",
                    Name, outFile);
  printer.endIndi("ktw:VacuumEffectorSingleCup", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class VacuumEffectorType

*/

VacuumEffectorType::VacuumEffectorType() {}

VacuumEffectorType::VacuumEffectorType(
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
 PositiveDecimalType * LengthIn) :
  EndEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn,
    HeldObjectIn)
{
  CupDiameter = CupDiameterIn;
  Length = LengthIn;
}

VacuumEffectorType::~VacuumEffectorType() {}

/*********************************************************************/

/* class VectorType

*/

VectorType::VectorType() {}

VectorType::VectorType(
 XmlID * NameIn,
 XmlDecimal * IIn,
 XmlDecimal * JIn,
 XmlDecimal * KIn) :
  DataThingType(
    NameIn)
{
  I = IIn;
  J = JIn;
  K = KIn;
}

VectorType::~VectorType() {}

void VectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:Vector", outFile);
  printer.printXmlDecimalProp("ktw:hasVector_I",
                              Name, I, outFile);
  printer.printXmlDecimalProp("ktw:hasVector_J",
                              Name, J, outFile);
  printer.printXmlDecimalProp("ktw:hasVector_K",
                              Name, K, outFile);
  printer.endIndi("ktw:Vector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class WeightUnitType

*/

WeightUnitType::WeightUnitType() :
  XmlNMTOKEN() {}

WeightUnitType::WeightUnitType(
 char * valIn) :
  XmlNMTOKEN(valIn)
{
  if (!bad)
    bad = (strcmp(val.c_str(), "kilogram") &&
           strcmp(val.c_str(), "gram") &&
           strcmp(val.c_str(), "milligram") &&
           strcmp(val.c_str(), "ounce") &&
           strcmp(val.c_str(), "pound"));
}

WeightUnitType::~WeightUnitType() {}

bool WeightUnitType::WeightUnitTypeIsBad()
{
  return (strcmp(val.c_str(), "kilogram") &&
          strcmp(val.c_str(), "gram") &&
          strcmp(val.c_str(), "milligram") &&
          strcmp(val.c_str(), "ounce") &&
          strcmp(val.c_str(), "pound"));
}

void WeightUnitType::printOwl(FILE * outFile)
{
  if (WeightUnitTypeIsBad())
    {
      fprintf(stderr, "bad WeightUnitType value, ");
      XmlNMTOKEN::printSelf(stderr);
      fprintf(stderr, " exiting\n");
      exit(1);
    }
  XmlNMTOKEN::printSelf(outFile);
}

void WeightUnitType::printProp(
 const char * property,
 XmlID * Name,
 FILE * outFile)
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  printOwl(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* class WorkTableType

*/

WorkTableType::WorkTableType() {}

WorkTableType::WorkTableType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 std::list<SolidObjectType *> * ObjectOnTableIn) :
  NoSkuObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  ObjectOnTable = ObjectOnTableIn;
}

WorkTableType::~WorkTableType() {}

void WorkTableType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktw:WorkTable", outFile);
  printer.printObjProp("ktw:hasSolidObject_PrimaryLocation",
                       Name, PrimaryLocation->Name, outFile);
  PrimaryLocation->printOwl(outFile);
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
         iter != SecondaryLocation->end(); iter++)
      {
        printer.printObjProp("ktw:hasSolidObject_SecondaryLocation",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (InternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_InternalShape",
                           Name, InternalShape->Name, outFile);
      InternalShape->printOwl(outFile);
    }
  if (ExternalShape)
    {
      printer.printObjProp("ktw:hasNoSkuObject_ExternalShape",
                           Name, ExternalShape->Name, outFile);
      ExternalShape->printOwl(outFile);
    }
  {
    std::list<SolidObjectType *>::iterator iter;
    for (iter = ObjectOnTable->begin();
         iter != ObjectOnTable->end(); iter++)
      {
        printer.printObjProp("ktw:hasWorkTable_ObjectOnTable",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktw:WorkTable", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class XmlHeaderForSOAP

*/

XmlHeaderForSOAP::XmlHeaderForSOAP() {}

XmlHeaderForSOAP::XmlHeaderForSOAP(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForSOAP::~XmlHeaderForSOAP() {}

void XmlHeaderForSOAP::printOwl(
  FILE * outFile)
{

}

/*********************************************************************/

