/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "owlInstancePrinter.hh"
#include "owlKittingPlanClasses.hh"

/*********************************************************************/
/*********************************************************************/

extern OwlInstancePrinter printer;

std::set<std::string> AndType::individuals;
std::set<std::string> AttachEndEffectorType::individuals;
std::set<std::string> BoxVolumeType::individuals;
std::set<std::string> BoxyShapeType::individuals;
std::set<std::string> CreateKitType::individuals;
std::set<std::string> CylindricalShapeType::individuals;
std::set<std::string> DecimalType::individuals;
std::set<std::string> DetachEndEffectorType::individuals;
std::set<std::string> DivType::individuals;
std::set<std::string> ElseType::individuals;
std::set<std::string> EndEffectorChangingStationType::individuals;
std::set<std::string> EndEffectorHolderType::individuals;
std::set<std::string> EqualType::individuals;
std::set<std::string> ExternalShapeType::individuals;
std::set<std::string> FalseType::individuals;
std::set<std::string> GreaterOrEqualType::individuals;
std::set<std::string> GreaterType::individuals;
std::set<std::string> GripperEffectorType::individuals;
std::set<std::string> HumanType::individuals;
std::set<std::string> IfActionGroupType::individuals;
std::set<std::string> KitDesignType::individuals;
std::set<std::string> KitTrayType::individuals;
std::set<std::string> KitType::individuals;
std::set<std::string> KittingPlanType::individuals;
std::set<std::string> KittingWorkstationType::individuals;
std::set<std::string> LargeBoxWithEmptyKitTraysType::individuals;
std::set<std::string> LargeBoxWithKitsType::individuals;
std::set<std::string> LargeContainerType::individuals;
std::set<std::string> LessOrEqualType::individuals;
std::set<std::string> LessType::individuals;
std::set<std::string> LocatePartType::individuals;
std::set<std::string> MechanicalComponentType::individuals;
std::set<std::string> MinusType::individuals;
std::set<std::string> ModType::individuals;
std::set<std::string> NegateType::individuals;
std::set<std::string> NotEqualType::individuals;
std::set<std::string> NotType::individuals;
std::set<std::string> NumberedPlanElementType::individuals;
std::set<std::string> OneOfActionGroupType::individuals;
std::set<std::string> OrType::individuals;
std::set<std::string> OrderedActionGroupType::individuals;
std::set<std::string> PartRefAndPoseType::individuals;
std::set<std::string> PartType::individuals;
std::set<std::string> PartiallyOrderedActionGroupType::individuals;
std::set<std::string> PartsBinType::individuals;
std::set<std::string> PartsTrayType::individuals;
std::set<std::string> PlusType::individuals;
std::set<std::string> PointType::individuals;
std::set<std::string> PoseLocationInType::individuals;
std::set<std::string> PoseLocationOnType::individuals;
std::set<std::string> PoseOnlyLocationType::individuals;
std::set<std::string> PropValType::individuals;
std::set<std::string> PutKitTrayType::individuals;
std::set<std::string> PutKitType::individuals;
std::set<std::string> PutPartType::individuals;
std::set<std::string> RelativeLocationInType::individuals;
std::set<std::string> RelativeLocationOnType::individuals;
std::set<std::string> RobotType::individuals;
std::set<std::string> SlotType::individuals;
std::set<std::string> SomeOfActionGroupType::individuals;
std::set<std::string> StepWithPredecessorsType::individuals;
std::set<std::string> StockKeepingUnitType::individuals;
std::set<std::string> TakeKitTrayType::individuals;
std::set<std::string> TakeKitType::individuals;
std::set<std::string> TakePartType::individuals;
std::set<std::string> TestAndStepType::individuals;
std::set<std::string> TimesType::individuals;
std::set<std::string> TrueType::individuals;
std::set<std::string> UnorderedActionGroupType::individuals;
std::set<std::string> VacuumEffectorMultiCupType::individuals;
std::set<std::string> VacuumEffectorSingleCupType::individuals;
std::set<std::string> VarSetType::individuals;
std::set<std::string> VarValType::individuals;
std::set<std::string> VariableDeclarationType::individuals;
std::set<std::string> VectorType::individuals;
std::set<std::string> WhileActionGroupType::individuals;
std::set<std::string> WorkTableType::individuals;

/*********************************************************************/

/* class KittingPlanFile

*/

KittingPlanFile::KittingPlanFile() {}

KittingPlanFile::KittingPlanFile(
  XmlVersion * versionIn,
  XmlHeaderForKittingPlan * headerIn,
  KittingPlanType * KittingPlanIn)
{
  version = versionIn;
  header = headerIn;
  KittingPlan = KittingPlanIn;
}

KittingPlanFile::~KittingPlanFile() {}

void KittingPlanFile::printOwl(FILE * outFile)
{
  std::set<std::string>::iterator iter;
  KittingPlan->printOwl(outFile);

  if (AndType::individuals.size() > 1)
    printer.printIndividuals("ktp:And",
       &AndType::individuals, outFile);
  if (AttachEndEffectorType::individuals.size() > 1)
    printer.printIndividuals("ktp:AttachEndEffector",
       &AttachEndEffectorType::individuals, outFile);
  if (BoxVolumeType::individuals.size() > 1)
    printer.printIndividuals("ktw:BoxVolume",
       &BoxVolumeType::individuals, outFile);
  if (BoxyShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:BoxyShape",
       &BoxyShapeType::individuals, outFile);
  if (CreateKitType::individuals.size() > 1)
    printer.printIndividuals("ktp:CreateKit",
       &CreateKitType::individuals, outFile);
  if (CylindricalShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:CylindricalShape",
       &CylindricalShapeType::individuals, outFile);
  if (DecimalType::individuals.size() > 1)
    printer.printIndividuals("ktp:Decimal",
       &DecimalType::individuals, outFile);
  if (DetachEndEffectorType::individuals.size() > 1)
    printer.printIndividuals("ktp:DetachEndEffector",
       &DetachEndEffectorType::individuals, outFile);
  if (DivType::individuals.size() > 1)
    printer.printIndividuals("ktp:Div",
       &DivType::individuals, outFile);
  if (ElseType::individuals.size() > 1)
    printer.printIndividuals("ktp:Else",
       &ElseType::individuals, outFile);
  if (EndEffectorChangingStationType::individuals.size() > 1)
    printer.printIndividuals("ktw:EndEffectorChangingStation",
       &EndEffectorChangingStationType::individuals, outFile);
  if (EndEffectorHolderType::individuals.size() > 1)
    printer.printIndividuals("ktw:EndEffectorHolder",
       &EndEffectorHolderType::individuals, outFile);
  if (EqualType::individuals.size() > 1)
    printer.printIndividuals("ktp:Equal",
       &EqualType::individuals, outFile);
  if (ExternalShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:ExternalShape",
       &ExternalShapeType::individuals, outFile);
  if (FalseType::individuals.size() > 1)
    printer.printIndividuals("ktp:False",
       &FalseType::individuals, outFile);
  if (GreaterOrEqualType::individuals.size() > 1)
    printer.printIndividuals("ktp:GreaterOrEqual",
       &GreaterOrEqualType::individuals, outFile);
  if (GreaterType::individuals.size() > 1)
    printer.printIndividuals("ktp:Greater",
       &GreaterType::individuals, outFile);
  if (GripperEffectorType::individuals.size() > 1)
    printer.printIndividuals("ktw:GripperEffector",
       &GripperEffectorType::individuals, outFile);
  if (HumanType::individuals.size() > 1)
    printer.printIndividuals("ktw:Human",
       &HumanType::individuals, outFile);
  if (IfActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:IfActionGroup",
       &IfActionGroupType::individuals, outFile);
  if (KitDesignType::individuals.size() > 1)
    printer.printIndividuals("ktw:KitDesign",
       &KitDesignType::individuals, outFile);
  if (KitTrayType::individuals.size() > 1)
    printer.printIndividuals("ktw:KitTray",
       &KitTrayType::individuals, outFile);
  if (KitType::individuals.size() > 1)
    printer.printIndividuals("ktw:Kit",
       &KitType::individuals, outFile);
  if (KittingPlanType::individuals.size() > 1)
    printer.printIndividuals("ktp:KittingPlan",
       &KittingPlanType::individuals, outFile);
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
  if (LessOrEqualType::individuals.size() > 1)
    printer.printIndividuals("ktp:LessOrEqual",
       &LessOrEqualType::individuals, outFile);
  if (LessType::individuals.size() > 1)
    printer.printIndividuals("ktp:Less",
       &LessType::individuals, outFile);
  if (LocatePartType::individuals.size() > 1)
    printer.printIndividuals("ktp:LocatePart",
       &LocatePartType::individuals, outFile);
  if (MechanicalComponentType::individuals.size() > 1)
    printer.printIndividuals("ktw:MechanicalComponent",
       &MechanicalComponentType::individuals, outFile);
  if (MinusType::individuals.size() > 1)
    printer.printIndividuals("ktp:Minus",
       &MinusType::individuals, outFile);
  if (ModType::individuals.size() > 1)
    printer.printIndividuals("ktp:Mod",
       &ModType::individuals, outFile);
  if (NegateType::individuals.size() > 1)
    printer.printIndividuals("ktp:Negate",
       &NegateType::individuals, outFile);
  if (NotEqualType::individuals.size() > 1)
    printer.printIndividuals("ktp:NotEqual",
       &NotEqualType::individuals, outFile);
  if (NotType::individuals.size() > 1)
    printer.printIndividuals("ktp:Not",
       &NotType::individuals, outFile);
  if (NumberedPlanElementType::individuals.size() > 1)
    printer.printIndividuals("ktp:NumberedPlanElement",
       &NumberedPlanElementType::individuals, outFile);
  if (OneOfActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:OneOfActionGroup",
       &OneOfActionGroupType::individuals, outFile);
  if (OrType::individuals.size() > 1)
    printer.printIndividuals("ktp:Or",
       &OrType::individuals, outFile);
  if (OrderedActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:OrderedActionGroup",
       &OrderedActionGroupType::individuals, outFile);
  if (PartRefAndPoseType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartRefAndPose",
       &PartRefAndPoseType::individuals, outFile);
  if (PartType::individuals.size() > 1)
    printer.printIndividuals("ktw:Part",
       &PartType::individuals, outFile);
  if (PartiallyOrderedActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:PartiallyOrderedActionGroup",
       &PartiallyOrderedActionGroupType::individuals, outFile);
  if (PartsBinType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartsBin",
       &PartsBinType::individuals, outFile);
  if (PartsTrayType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartsTray",
       &PartsTrayType::individuals, outFile);
  if (PlusType::individuals.size() > 1)
    printer.printIndividuals("ktp:Plus",
       &PlusType::individuals, outFile);
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
  if (PropValType::individuals.size() > 1)
    printer.printIndividuals("ktp:PropVal",
       &PropValType::individuals, outFile);
  if (PutKitTrayType::individuals.size() > 1)
    printer.printIndividuals("ktp:PutKitTray",
       &PutKitTrayType::individuals, outFile);
  if (PutKitType::individuals.size() > 1)
    printer.printIndividuals("ktp:PutKit",
       &PutKitType::individuals, outFile);
  if (PutPartType::individuals.size() > 1)
    printer.printIndividuals("ktp:PutPart",
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
  if (SlotType::individuals.size() > 1)
    printer.printIndividuals("ktw:Slot",
       &SlotType::individuals, outFile);
  if (SomeOfActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:SomeOfActionGroup",
       &SomeOfActionGroupType::individuals, outFile);
  if (StepWithPredecessorsType::individuals.size() > 1)
    printer.printIndividuals("ktp:StepWithPredecessors",
       &StepWithPredecessorsType::individuals, outFile);
  if (StockKeepingUnitType::individuals.size() > 1)
    printer.printIndividuals("ktw:StockKeepingUnit",
       &StockKeepingUnitType::individuals, outFile);
  if (TakeKitTrayType::individuals.size() > 1)
    printer.printIndividuals("ktp:TakeKitTray",
       &TakeKitTrayType::individuals, outFile);
  if (TakeKitType::individuals.size() > 1)
    printer.printIndividuals("ktp:TakeKit",
       &TakeKitType::individuals, outFile);
  if (TakePartType::individuals.size() > 1)
    printer.printIndividuals("ktp:TakePart",
       &TakePartType::individuals, outFile);
  if (TestAndStepType::individuals.size() > 1)
    printer.printIndividuals("ktp:TestAndStep",
       &TestAndStepType::individuals, outFile);
  if (TimesType::individuals.size() > 1)
    printer.printIndividuals("ktp:Times",
       &TimesType::individuals, outFile);
  if (TrueType::individuals.size() > 1)
    printer.printIndividuals("ktp:True",
       &TrueType::individuals, outFile);
  if (UnorderedActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:UnorderedActionGroup",
       &UnorderedActionGroupType::individuals, outFile);
  if (VacuumEffectorMultiCupType::individuals.size() > 1)
    printer.printIndividuals("ktw:VacuumEffectorMultiCup",
       &VacuumEffectorMultiCupType::individuals, outFile);
  if (VacuumEffectorSingleCupType::individuals.size() > 1)
    printer.printIndividuals("ktw:VacuumEffectorSingleCup",
       &VacuumEffectorSingleCupType::individuals, outFile);
  if (VarSetType::individuals.size() > 1)
    printer.printIndividuals("ktp:VarSet",
       &VarSetType::individuals, outFile);
  if (VarValType::individuals.size() > 1)
    printer.printIndividuals("ktp:VarVal",
       &VarValType::individuals, outFile);
  if (VariableDeclarationType::individuals.size() > 1)
    printer.printIndividuals("ktp:VariableDeclaration",
       &VariableDeclarationType::individuals, outFile);
  if (VectorType::individuals.size() > 1)
    printer.printIndividuals("ktw:Vector",
       &VectorType::individuals, outFile);
  if (WhileActionGroupType::individuals.size() > 1)
    printer.printIndividuals("ktp:WhileActionGroup",
       &WhileActionGroupType::individuals, outFile);
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
  PlanElementBaseType(
    NameIn)
{
}

ActionBaseType::~ActionBaseType() {}

/*********************************************************************/

/* class ActionGroupBaseType

*/

ActionGroupBaseType::ActionGroupBaseType() {}

ActionGroupBaseType::ActionGroupBaseType(
 XmlID * NameIn) :
  PlanElementBaseType(
    NameIn)
{
}

ActionGroupBaseType::~ActionGroupBaseType() {}

/*********************************************************************/

/* class AndType

*/

AndType::AndType() {}

AndType::AndType(
 XmlID * NameIn,
 BooleanExpressionType * B1In,
 BooleanExpressionType * B2In) :
  BinaryBooleanExpressionType(
    NameIn,
    B1In,
    B2In)
{
}

AndType::~AndType() {}

void AndType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:And", outFile);
  printer.printObjProp("ktp:hasBinaryBooleanExpression_B1",
                       Name, B1->Name, outFile);
  B1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryBooleanExpression_B2",
                       Name, B2->Name, outFile);
  B2->printOwl(outFile);
  printer.endIndi("ktp:And", outFile);
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

/* class ArithmeticComparisonBooleanExpressionType

*/

ArithmeticComparisonBooleanExpressionType::ArithmeticComparisonBooleanExpressionType() {}

ArithmeticComparisonBooleanExpressionType::ArithmeticComparisonBooleanExpressionType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  BooleanExpressionType(
    NameIn)
{
  A1 = A1In;
  A2 = A2In;
}

ArithmeticComparisonBooleanExpressionType::~ArithmeticComparisonBooleanExpressionType() {}

/*********************************************************************/

/* class ArithmeticExpressionType

*/

ArithmeticExpressionType::ArithmeticExpressionType() {}

ArithmeticExpressionType::ArithmeticExpressionType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
}

ArithmeticExpressionType::~ArithmeticExpressionType() {}

/*********************************************************************/

/* class AttachEndEffectorType

*/

AttachEndEffectorType::AttachEndEffectorType() {}

AttachEndEffectorType::AttachEndEffectorType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * EndEffectorNameIn,
 XmlNMTOKEN * EndEffectorHolderNameIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  EndEffectorName = EndEffectorNameIn;
  EndEffectorHolderName = EndEffectorHolderNameIn;
}

AttachEndEffectorType::~AttachEndEffectorType() {}

void AttachEndEffectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:AttachEndEffector", outFile);
  printer.printXmlNMTOKENProp("ktp:hasAttachEndEffector_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasAttachEndEffector_EndEffectorName",
                              Name, EndEffectorName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasAttachEndEffector_EndEffectorHolderName",
                              Name, EndEffectorHolderName, outFile);
  printer.endIndi("ktp:AttachEndEffector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class BinaryArithmeticExpressionType

*/

BinaryArithmeticExpressionType::BinaryArithmeticExpressionType() {}

BinaryArithmeticExpressionType::BinaryArithmeticExpressionType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticExpressionType(
    NameIn)
{
  A1 = A1In;
  A2 = A2In;
}

BinaryArithmeticExpressionType::~BinaryArithmeticExpressionType() {}

/*********************************************************************/

/* class BinaryBooleanExpressionType

*/

BinaryBooleanExpressionType::BinaryBooleanExpressionType() {}

BinaryBooleanExpressionType::BinaryBooleanExpressionType(
 XmlID * NameIn,
 BooleanExpressionType * B1In,
 BooleanExpressionType * B2In) :
  BooleanExpressionType(
    NameIn)
{
  B1 = B1In;
  B2 = B2In;
}

BinaryBooleanExpressionType::~BinaryBooleanExpressionType() {}

/*********************************************************************/

/* class BooleanConstantType

*/

BooleanConstantType::BooleanConstantType() {}

BooleanConstantType::BooleanConstantType(
 XmlID * NameIn) :
  BooleanExpressionType(
    NameIn)
{
}

BooleanConstantType::~BooleanConstantType() {}

/*********************************************************************/

/* class BooleanExpressionType

*/

BooleanExpressionType::BooleanExpressionType() {}

BooleanExpressionType::BooleanExpressionType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
}

BooleanExpressionType::~BooleanExpressionType() {}

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

/* class CreateKitType

*/

CreateKitType::CreateKitType() {}

CreateKitType::CreateKitType(
 XmlID * NameIn,
 XmlNMTOKEN * KitTrayNameIn,
 XmlNMTOKEN * KitNameIn) :
  ActionBaseType(
    NameIn)
{
  KitTrayName = KitTrayNameIn;
  KitName = KitNameIn;
}

CreateKitType::~CreateKitType() {}

void CreateKitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:CreateKit", outFile);
  printer.printXmlNMTOKENProp("ktp:hasCreateKit_KitTrayName",
                              Name, KitTrayName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasCreateKit_KitName",
                              Name, KitName, outFile);
  printer.endIndi("ktp:CreateKit", outFile);
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

/* class DecimalType

*/

DecimalType::DecimalType() {}

DecimalType::DecimalType(
 XmlID * NameIn,
 XmlDecimal * AIn) :
  ArithmeticExpressionType(
    NameIn)
{
  A = AIn;
}

DecimalType::~DecimalType() {}

void DecimalType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Decimal", outFile);
  printer.printXmlDecimalProp("ktp:hasDecimal_A",
                              Name, A, outFile);
  printer.endIndi("ktp:Decimal", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class DetachEndEffectorType

*/

DetachEndEffectorType::DetachEndEffectorType() {}

DetachEndEffectorType::DetachEndEffectorType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * EndEffectorNameIn,
 XmlNMTOKEN * EndEffectorHolderNameIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  EndEffectorName = EndEffectorNameIn;
  EndEffectorHolderName = EndEffectorHolderNameIn;
}

DetachEndEffectorType::~DetachEndEffectorType() {}

void DetachEndEffectorType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:DetachEndEffector", outFile);
  printer.printXmlNMTOKENProp("ktp:hasDetachEndEffector_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasDetachEndEffector_EndEffectorName",
                              Name, EndEffectorName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasDetachEndEffector_EndEffectorHolderName",
                              Name, EndEffectorHolderName, outFile);
  printer.endIndi("ktp:DetachEndEffector", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class DivType

*/

DivType::DivType() {}

DivType::DivType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  BinaryArithmeticExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

DivType::~DivType() {}

void DivType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Div", outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Div", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class ElseType

*/

ElseType::ElseType() {}

ElseType::ElseType(
 XmlID * NameIn,
 PlanElementBaseType * StepIn) :
  DataThingType(
    NameIn)
{
  Step = StepIn;
}

ElseType::~ElseType() {}

void ElseType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Else", outFile);
  printer.printObjProp("ktp:hasElse_Step",
                       Name, Step->Name, outFile);
  Step->printOwl(outFile);
  printer.endIndi("ktp:Else", outFile);
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

/* class EqualType

*/

EqualType::EqualType() {}

EqualType::EqualType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticComparisonBooleanExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

EqualType::~EqualType() {}

void EqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Equal", outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Equal", outFile);
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

/* class FalseType

*/

FalseType::FalseType() {}

FalseType::FalseType(
 XmlID * NameIn) :
  BooleanConstantType(
    NameIn)
{
}

FalseType::~FalseType() {}

void FalseType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:False", outFile);
  printer.endIndi("ktp:False", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class GreaterOrEqualType

*/

GreaterOrEqualType::GreaterOrEqualType() {}

GreaterOrEqualType::GreaterOrEqualType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticComparisonBooleanExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

GreaterOrEqualType::~GreaterOrEqualType() {}

void GreaterOrEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:GreaterOrEqual", outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:GreaterOrEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class GreaterType

*/

GreaterType::GreaterType() {}

GreaterType::GreaterType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticComparisonBooleanExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

GreaterType::~GreaterType() {}

void GreaterType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Greater", outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Greater", outFile);
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

/* class IfActionGroupType

*/

IfActionGroupType::IfActionGroupType() {}

IfActionGroupType::IfActionGroupType(
 XmlID * NameIn,
 TestAndStepType * IfIn,
 std::list<TestAndStepType *> * ElseIfIn,
 ElseType * ElseIn) :
  ActionGroupBaseType(
    NameIn)
{
  If = IfIn;
  ElseIf = ElseIfIn;
  Else = ElseIn;
}

IfActionGroupType::~IfActionGroupType() {}

void IfActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:IfActionGroup", outFile);
  printer.printObjProp("ktp:hasIfActionGroup_If",
                       Name, If->Name, outFile);
  If->printOwl(outFile);
  {
    std::list<TestAndStepType *>::iterator iter;
    for (iter = ElseIf->begin();
         iter != ElseIf->end(); iter++)
      {
        printer.printObjProp("ktp:hasIfActionGroup_ElseIf",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (Else)
    {
      printer.printObjProp("ktp:hasIfActionGroup_Else",
                           Name, Else->Name, outFile);
      Else->printOwl(outFile);
    }
  printer.endIndi("ktp:IfActionGroup", outFile);
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

/* class KittingPlanType

*/

KittingPlanType::KittingPlanType() {}

KittingPlanType::KittingPlanType(
 XmlID * NameIn,
 XmlNMTOKEN * PlanIdIn,
 XmlToken * PlanVersionIn,
 XmlDateTime * PlanDateAndTimeIn,
 XmlToken * PlanAuthorIn,
 XmlString * PlanDescriptionIn,
 std::list<XmlID *> * ObjectIn,
 std::list<VariableDeclarationType *> * VariableIn,
 PlanElementBaseType * PlanRootIn) :
  DataThingType(
    NameIn)
{
  PlanId = PlanIdIn;
  PlanVersion = PlanVersionIn;
  PlanDateAndTime = PlanDateAndTimeIn;
  PlanAuthor = PlanAuthorIn;
  PlanDescription = PlanDescriptionIn;
  Object = ObjectIn;
  Variable = VariableIn;
  PlanRoot = PlanRootIn;
}

KittingPlanType::~KittingPlanType() {}

void KittingPlanType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:KittingPlan", outFile);
  printer.printXmlNMTOKENProp("ktp:hasKittingPlan_PlanId",
                              Name, PlanId, outFile);
  printer.printXmlTokenProp("ktp:hasKittingPlan_PlanVersion",
                            Name, PlanVersion, outFile);
  printer.printXmlDateTimeProp("ktp:hasKittingPlan_PlanDateAndTime",
                               Name, PlanDateAndTime, outFile);
  printer.printXmlTokenProp("ktp:hasKittingPlan_PlanAuthor",
                            Name, PlanAuthor, outFile);
  printer.printXmlStringProp("ktp:hasKittingPlan_PlanDescription",
                             Name, PlanDescription, outFile);
  {
    std::list<XmlID *>::iterator iter;
    for (iter = Object->begin();
        iter != Object->end(); iter++)
      {
        printer.printXmlIDProp("ktp:hasKittingPlan_Object",
                               Name, *iter, outFile);
      }
  }
  {
    std::list<VariableDeclarationType *>::iterator iter;
    for (iter = Variable->begin();
         iter != Variable->end(); iter++)
      {
        printer.printObjProp("ktp:hasKittingPlan_Variable",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjProp("ktp:hasKittingPlan_PlanRoot",
                       Name, PlanRoot->Name, outFile);
  PlanRoot->printOwl(outFile);
  printer.endIndi("ktp:KittingPlan", outFile);
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

/* class LessOrEqualType

*/

LessOrEqualType::LessOrEqualType() {}

LessOrEqualType::LessOrEqualType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticComparisonBooleanExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

LessOrEqualType::~LessOrEqualType() {}

void LessOrEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:LessOrEqual", outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:LessOrEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class LessType

*/

LessType::LessType() {}

LessType::LessType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticComparisonBooleanExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

LessType::~LessType() {}

void LessType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Less", outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Less", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class LocatePartType

*/

LocatePartType::LocatePartType() {}

LocatePartType::LocatePartType(
 XmlID * NameIn,
 XmlNMTOKEN * PartNameIn) :
  SensorActionBaseType(
    NameIn)
{
  PartName = PartNameIn;
}

LocatePartType::~LocatePartType() {}

void LocatePartType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:LocatePart", outFile);
  printer.printXmlNMTOKENProp("ktp:hasLocatePart_PartName",
                              Name, PartName, outFile);
  printer.endIndi("ktp:LocatePart", outFile);
  individuals.insert(Name->val);
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

/* class MinusType

*/

MinusType::MinusType() {}

MinusType::MinusType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  BinaryArithmeticExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

MinusType::~MinusType() {}

void MinusType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Minus", outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Minus", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class ModType

*/

ModType::ModType() {}

ModType::ModType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  BinaryArithmeticExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

ModType::~ModType() {}

void ModType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Mod", outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Mod", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class NegateType

*/

NegateType::NegateType() {}

NegateType::NegateType(
 XmlID * NameIn,
 ArithmeticExpressionType * AIn) :
  ArithmeticExpressionType(
    NameIn)
{
  A = AIn;
}

NegateType::~NegateType() {}

void NegateType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Negate", outFile);
  printer.printObjProp("ktp:hasNegate_A",
                       Name, A->Name, outFile);
  A->printOwl(outFile);
  printer.endIndi("ktp:Negate", outFile);
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

/* class NotEqualType

*/

NotEqualType::NotEqualType() {}

NotEqualType::NotEqualType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  ArithmeticComparisonBooleanExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

NotEqualType::~NotEqualType() {}

void NotEqualType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:NotEqual", outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:NotEqual", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class NotType

*/

NotType::NotType() {}

NotType::NotType(
 XmlID * NameIn,
 BooleanExpressionType * BIn) :
  BooleanExpressionType(
    NameIn)
{
  B = BIn;
}

NotType::~NotType() {}

void NotType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Not", outFile);
  printer.printObjProp("ktp:hasNot_B",
                       Name, B->Name, outFile);
  B->printOwl(outFile);
  printer.endIndi("ktp:Not", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class NumberedPlanElementType

*/

NumberedPlanElementType::NumberedPlanElementType() {}

NumberedPlanElementType::NumberedPlanElementType(
 XmlID * NameIn,
 XmlPositiveInteger * SequenceNumberIn,
 PlanElementBaseType * PlanElementIn) :
  DataThingType(
    NameIn)
{
  SequenceNumber = SequenceNumberIn;
  PlanElement = PlanElementIn;
}

NumberedPlanElementType::~NumberedPlanElementType() {}

void NumberedPlanElementType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:NumberedPlanElement", outFile);
  printer.printXmlPositiveIntegerProp("ktp:hasNumberedPlanElement_SequenceNumber",
                                      Name, SequenceNumber, outFile);
  printer.printObjProp("ktp:hasNumberedPlanElement_PlanElement",
                       Name, PlanElement->Name, outFile);
  PlanElement->printOwl(outFile);
  printer.endIndi("ktp:NumberedPlanElement", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class OneOfActionGroupType

*/

OneOfActionGroupType::OneOfActionGroupType() {}

OneOfActionGroupType::OneOfActionGroupType(
 XmlID * NameIn,
 std::list<NumberedPlanElementType *> * StepIn) :
  ActionGroupBaseType(
    NameIn)
{
  Step = StepIn;
}

OneOfActionGroupType::~OneOfActionGroupType() {}

void OneOfActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:OneOfActionGroup", outFile);
  {
    std::list<NumberedPlanElementType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("ktp:hasOneOfActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktp:OneOfActionGroup", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class OrType

*/

OrType::OrType() {}

OrType::OrType(
 XmlID * NameIn,
 BooleanExpressionType * B1In,
 BooleanExpressionType * B2In) :
  BinaryBooleanExpressionType(
    NameIn,
    B1In,
    B2In)
{
}

OrType::~OrType() {}

void OrType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Or", outFile);
  printer.printObjProp("ktp:hasBinaryBooleanExpression_B1",
                       Name, B1->Name, outFile);
  B1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryBooleanExpression_B2",
                       Name, B2->Name, outFile);
  B2->printOwl(outFile);
  printer.endIndi("ktp:Or", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class OrderedActionGroupType

*/

OrderedActionGroupType::OrderedActionGroupType() {}

OrderedActionGroupType::OrderedActionGroupType(
 XmlID * NameIn,
 std::list<NumberedPlanElementType *> * StepIn) :
  ActionGroupBaseType(
    NameIn)
{
  Step = StepIn;
}

OrderedActionGroupType::~OrderedActionGroupType() {}

void OrderedActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:OrderedActionGroup", outFile);
  {
    std::list<NumberedPlanElementType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("ktp:hasOrderedActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktp:OrderedActionGroup", outFile);
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

/* class PartiallyOrderedActionGroupType

*/

PartiallyOrderedActionGroupType::PartiallyOrderedActionGroupType() {}

PartiallyOrderedActionGroupType::PartiallyOrderedActionGroupType(
 XmlID * NameIn,
 std::list<StepWithPredecessorsType *> * StepIn) :
  ActionGroupBaseType(
    NameIn)
{
  Step = StepIn;
}

PartiallyOrderedActionGroupType::~PartiallyOrderedActionGroupType() {}

void PartiallyOrderedActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:PartiallyOrderedActionGroup", outFile);
  {
    std::list<StepWithPredecessorsType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("ktp:hasPartiallyOrderedActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktp:PartiallyOrderedActionGroup", outFile);
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

/* class PlanElementBaseType

*/

PlanElementBaseType::PlanElementBaseType() {}

PlanElementBaseType::PlanElementBaseType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
}

PlanElementBaseType::~PlanElementBaseType() {}

/*********************************************************************/

/* class PlusType

*/

PlusType::PlusType() {}

PlusType::PlusType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  BinaryArithmeticExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

PlusType::~PlusType() {}

void PlusType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Plus", outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Plus", outFile);
  individuals.insert(Name->val);
}

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

/* class PropValType

*/

PropValType::PropValType() {}

PropValType::PropValType(
 XmlID * NameIn,
 XmlNMTOKEN * ThingNameIn,
 XmlNMTOKEN * PropertyIn) :
  ArithmeticExpressionType(
    NameIn)
{
  ThingName = ThingNameIn;
  Property = PropertyIn;
}

PropValType::~PropValType() {}

void PropValType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:PropVal", outFile);
  printer.printXmlNMTOKENProp("ktp:hasPropVal_ThingName",
                              Name, ThingName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasPropVal_Property",
                              Name, Property, outFile);
  printer.endIndi("ktp:PropVal", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PutKitTrayType

*/

PutKitTrayType::PutKitTrayType() {}

PutKitTrayType::PutKitTrayType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * KitTrayNameIn,
 PhysicalLocationType * LocationIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  KitTrayName = KitTrayNameIn;
  Location = LocationIn;
}

PutKitTrayType::~PutKitTrayType() {}

void PutKitTrayType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:PutKitTray", outFile);
  printer.printXmlNMTOKENProp("ktp:hasPutKitTray_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasPutKitTray_KitTrayName",
                              Name, KitTrayName, outFile);
  printer.printObjProp("ktp:hasPutKitTray_Location",
                       Name, Location->Name, outFile);
  Location->printOwl(outFile);
  printer.endIndi("ktp:PutKitTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PutKitType

*/

PutKitType::PutKitType() {}

PutKitType::PutKitType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * KitNameIn,
 PhysicalLocationType * LocationIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  KitName = KitNameIn;
  Location = LocationIn;
}

PutKitType::~PutKitType() {}

void PutKitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:PutKit", outFile);
  printer.printXmlNMTOKENProp("ktp:hasPutKit_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasPutKit_KitName",
                              Name, KitName, outFile);
  printer.printObjProp("ktp:hasPutKit_Location",
                       Name, Location->Name, outFile);
  Location->printOwl(outFile);
  printer.endIndi("ktp:PutKit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PutPartType

*/

PutPartType::PutPartType() {}

PutPartType::PutPartType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * PartNameIn,
 PhysicalLocationType * LocationIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  PartName = PartNameIn;
  Location = LocationIn;
}

PutPartType::~PutPartType() {}

void PutPartType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:PutPart", outFile);
  printer.printXmlNMTOKENProp("ktp:hasPutPart_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasPutPart_PartName",
                              Name, PartName, outFile);
  printer.printObjProp("ktp:hasPutPart_Location",
                       Name, Location->Name, outFile);
  Location->printOwl(outFile);
  printer.endIndi("ktp:PutPart", outFile);
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

/* class SensorActionBaseType

*/

SensorActionBaseType::SensorActionBaseType() {}

SensorActionBaseType::SensorActionBaseType(
 XmlID * NameIn) :
  ActionBaseType(
    NameIn)
{
}

SensorActionBaseType::~SensorActionBaseType() {}

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

/* class SomeOfActionGroupType

*/

SomeOfActionGroupType::SomeOfActionGroupType() {}

SomeOfActionGroupType::SomeOfActionGroupType(
 XmlID * NameIn,
 std::list<PlanElementBaseType *> * StepIn,
 XmlPositiveInteger * NumberOfStepsIn) :
  ActionGroupBaseType(
    NameIn)
{
  Step = StepIn;
  NumberOfSteps = NumberOfStepsIn;
}

SomeOfActionGroupType::~SomeOfActionGroupType() {}

void SomeOfActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:SomeOfActionGroup", outFile);
  {
    std::list<PlanElementBaseType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("ktp:hasSomeOfActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printXmlPositiveIntegerProp("ktp:hasSomeOfActionGroup_NumberOfSteps",
                                      Name, NumberOfSteps, outFile);
  printer.endIndi("ktp:SomeOfActionGroup", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class StepWithPredecessorsType

*/

StepWithPredecessorsType::StepWithPredecessorsType() {}

StepWithPredecessorsType::StepWithPredecessorsType(
 XmlID * NameIn,
 XmlPositiveInteger * SequenceNumberIn,
 std::list<XmlPositiveInteger *> * PredecessorIn,
 PlanElementBaseType * PlanElementIn) :
  DataThingType(
    NameIn)
{
  SequenceNumber = SequenceNumberIn;
  Predecessor = PredecessorIn;
  PlanElement = PlanElementIn;
}

StepWithPredecessorsType::~StepWithPredecessorsType() {}

void StepWithPredecessorsType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:StepWithPredecessors", outFile);
  printer.printXmlPositiveIntegerProp("ktp:hasStepWithPredecessors_SequenceNumber",
                                      Name, SequenceNumber, outFile);
  {
    std::list<XmlPositiveInteger *>::iterator iter;
    for (iter = Predecessor->begin();
        iter != Predecessor->end(); iter++)
      {
        printer.printXmlPositiveIntegerProp("ktp:hasStepWithPredecessors_Predecessor",
                                            Name, *iter, outFile);
      }
  }
  printer.printObjProp("ktp:hasStepWithPredecessors_PlanElement",
                       Name, PlanElement->Name, outFile);
  PlanElement->printOwl(outFile);
  printer.endIndi("ktp:StepWithPredecessors", outFile);
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
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * KitTrayNameIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  KitTrayName = KitTrayNameIn;
}

TakeKitTrayType::~TakeKitTrayType() {}

void TakeKitTrayType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:TakeKitTray", outFile);
  printer.printXmlNMTOKENProp("ktp:hasTakeKitTray_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasTakeKitTray_KitTrayName",
                              Name, KitTrayName, outFile);
  printer.endIndi("ktp:TakeKitTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TakeKitType

*/

TakeKitType::TakeKitType() {}

TakeKitType::TakeKitType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * KitNameIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  KitName = KitNameIn;
}

TakeKitType::~TakeKitType() {}

void TakeKitType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:TakeKit", outFile);
  printer.printXmlNMTOKENProp("ktp:hasTakeKit_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasTakeKit_KitName",
                              Name, KitName, outFile);
  printer.endIndi("ktp:TakeKit", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TakePartType

*/

TakePartType::TakePartType() {}

TakePartType::TakePartType(
 XmlID * NameIn,
 XmlNMTOKEN * RobotNameIn,
 XmlNMTOKEN * PartNameIn) :
  RobotActionBaseType(
    NameIn)
{
  RobotName = RobotNameIn;
  PartName = PartNameIn;
}

TakePartType::~TakePartType() {}

void TakePartType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:TakePart", outFile);
  printer.printXmlNMTOKENProp("ktp:hasTakePart_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("ktp:hasTakePart_PartName",
                              Name, PartName, outFile);
  printer.endIndi("ktp:TakePart", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TestAndStepType

*/

TestAndStepType::TestAndStepType() {}

TestAndStepType::TestAndStepType(
 XmlID * NameIn,
 BooleanExpressionType * TestIn,
 PlanElementBaseType * StepIn) :
  DataThingType(
    NameIn)
{
  Test = TestIn;
  Step = StepIn;
}

TestAndStepType::~TestAndStepType() {}

void TestAndStepType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:TestAndStep", outFile);
  printer.printObjProp("ktp:hasTestAndStep_Test",
                       Name, Test->Name, outFile);
  Test->printOwl(outFile);
  printer.printObjProp("ktp:hasTestAndStep_Step",
                       Name, Step->Name, outFile);
  Step->printOwl(outFile);
  printer.endIndi("ktp:TestAndStep", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TimesType

*/

TimesType::TimesType() {}

TimesType::TimesType(
 XmlID * NameIn,
 ArithmeticExpressionType * A1In,
 ArithmeticExpressionType * A2In) :
  BinaryArithmeticExpressionType(
    NameIn,
    A1In,
    A2In)
{
}

TimesType::~TimesType() {}

void TimesType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:Times", outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("ktp:hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("ktp:Times", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class TrueType

*/

TrueType::TrueType() {}

TrueType::TrueType(
 XmlID * NameIn) :
  BooleanConstantType(
    NameIn)
{
}

TrueType::~TrueType() {}

void TrueType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:True", outFile);
  printer.endIndi("ktp:True", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class UnorderedActionGroupType

*/

UnorderedActionGroupType::UnorderedActionGroupType() {}

UnorderedActionGroupType::UnorderedActionGroupType(
 XmlID * NameIn,
 std::list<PlanElementBaseType *> * StepIn) :
  ActionGroupBaseType(
    NameIn)
{
  Step = StepIn;
}

UnorderedActionGroupType::~UnorderedActionGroupType() {}

void UnorderedActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:UnorderedActionGroup", outFile);
  {
    std::list<PlanElementBaseType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("ktp:hasUnorderedActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("ktp:UnorderedActionGroup", outFile);
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

/* class VarSetType

*/

VarSetType::VarSetType() {}

VarSetType::VarSetType(
 XmlID * NameIn,
 XmlIDREF * VarNameIn,
 ArithmeticExpressionType * ValIn) :
  PlanElementBaseType(
    NameIn)
{
  VarName = VarNameIn;
  Val = ValIn;
}

VarSetType::~VarSetType() {}

void VarSetType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:VarSet", outFile);
  printer.printObjRefProp("ktp:hasVarSet_Var",
                          Name, VarName, outFile);
  printer.printObjProp("ktp:hasVarSet_Val",
                       Name, Val->Name, outFile);
  Val->printOwl(outFile);
  printer.endIndi("ktp:VarSet", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class VarValType

*/

VarValType::VarValType() {}

VarValType::VarValType(
 XmlID * NameIn,
 XmlIDREF * VarNameIn) :
  ArithmeticExpressionType(
    NameIn)
{
  VarName = VarNameIn;
}

VarValType::~VarValType() {}

void VarValType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:VarVal", outFile);
  printer.printObjRefProp("ktp:hasVarVal_Var",
                          Name, VarName, outFile);
  printer.endIndi("ktp:VarVal", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class VariableDeclarationType

*/

VariableDeclarationType::VariableDeclarationType() {}

VariableDeclarationType::VariableDeclarationType(
 XmlID * NameIn,
 XmlDecimal * ValIn) :
  DataThingType(
    NameIn)
{
  Val = ValIn;
}

VariableDeclarationType::~VariableDeclarationType() {}

void VariableDeclarationType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:VariableDeclaration", outFile);
  printer.printXmlDecimalProp("ktp:hasVariableDeclaration_Val",
                              Name, Val, outFile);
  printer.endIndi("ktp:VariableDeclaration", outFile);
  individuals.insert(Name->val);
}

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

/* class WhileActionGroupType

*/

WhileActionGroupType::WhileActionGroupType() {}

WhileActionGroupType::WhileActionGroupType(
 XmlID * NameIn,
 BooleanExpressionType * TestIn,
 PlanElementBaseType * StepIn) :
  ActionGroupBaseType(
    NameIn)
{
  Test = TestIn;
  Step = StepIn;
}

WhileActionGroupType::~WhileActionGroupType() {}

void WhileActionGroupType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "ktp:WhileActionGroup", outFile);
  printer.printObjProp("ktp:hasWhileActionGroup_Test",
                       Name, Test->Name, outFile);
  Test->printOwl(outFile);
  printer.printObjProp("ktp:hasWhileActionGroup_Step",
                       Name, Step->Name, outFile);
  Step->printOwl(outFile);
  printer.endIndi("ktp:WhileActionGroup", outFile);
  individuals.insert(Name->val);
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

/* class XmlHeaderForKittingPlan

*/

XmlHeaderForKittingPlan::XmlHeaderForKittingPlan() {}

XmlHeaderForKittingPlan::XmlHeaderForKittingPlan(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForKittingPlan::~XmlHeaderForKittingPlan() {}

void XmlHeaderForKittingPlan::printOwl(
  FILE * outFile)
{

}

/*********************************************************************/

