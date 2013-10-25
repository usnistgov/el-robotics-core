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
std::set<std::string> CreateKitType::individuals;
std::set<std::string> DecimalType::individuals;
std::set<std::string> DetachEndEffectorType::individuals;
std::set<std::string> DivType::individuals;
std::set<std::string> ElseType::individuals;
std::set<std::string> EqualType::individuals;
std::set<std::string> FalseType::individuals;
std::set<std::string> GreaterOrEqualType::individuals;
std::set<std::string> GreaterType::individuals;
std::set<std::string> IfActionGroupType::individuals;
std::set<std::string> KittingPlanType::individuals;
std::set<std::string> LessOrEqualType::individuals;
std::set<std::string> LessType::individuals;
std::set<std::string> LocatePartType::individuals;
std::set<std::string> MinusType::individuals;
std::set<std::string> ModType::individuals;
std::set<std::string> NegateType::individuals;
std::set<std::string> NotEqualType::individuals;
std::set<std::string> NotType::individuals;
std::set<std::string> NumberedPlanElementType::individuals;
std::set<std::string> OneOfActionGroupType::individuals;
std::set<std::string> OrType::individuals;
std::set<std::string> OrderedActionGroupType::individuals;
std::set<std::string> PartiallyOrderedActionGroupType::individuals;
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
std::set<std::string> SomeOfActionGroupType::individuals;
std::set<std::string> StepWithPredecessorsType::individuals;
std::set<std::string> TakeKitTrayType::individuals;
std::set<std::string> TakeKitType::individuals;
std::set<std::string> TakePartType::individuals;
std::set<std::string> TestAndStepType::individuals;
std::set<std::string> TimesType::individuals;
std::set<std::string> TrueType::individuals;
std::set<std::string> UnorderedActionGroupType::individuals;
std::set<std::string> VarSetType::individuals;
std::set<std::string> VarValType::individuals;
std::set<std::string> VariableDeclarationType::individuals;
std::set<std::string> VectorType::individuals;
std::set<std::string> WhileActionGroupType::individuals;

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
  header->printOwl(outFile);
  KittingPlan->printOwl(outFile);

  if (AndType::individuals.size() > 1)
    printer.printIndividuals("And",
       &AndType::individuals, outFile);
  if (AttachEndEffectorType::individuals.size() > 1)
    printer.printIndividuals("AttachEndEffector",
       &AttachEndEffectorType::individuals, outFile);
  if (CreateKitType::individuals.size() > 1)
    printer.printIndividuals("CreateKit",
       &CreateKitType::individuals, outFile);
  if (DecimalType::individuals.size() > 1)
    printer.printIndividuals("Decimal",
       &DecimalType::individuals, outFile);
  if (DetachEndEffectorType::individuals.size() > 1)
    printer.printIndividuals("DetachEndEffector",
       &DetachEndEffectorType::individuals, outFile);
  if (DivType::individuals.size() > 1)
    printer.printIndividuals("Div",
       &DivType::individuals, outFile);
  if (ElseType::individuals.size() > 1)
    printer.printIndividuals("Else",
       &ElseType::individuals, outFile);
  if (EqualType::individuals.size() > 1)
    printer.printIndividuals("Equal",
       &EqualType::individuals, outFile);
  if (FalseType::individuals.size() > 1)
    printer.printIndividuals("False",
       &FalseType::individuals, outFile);
  if (GreaterOrEqualType::individuals.size() > 1)
    printer.printIndividuals("GreaterOrEqual",
       &GreaterOrEqualType::individuals, outFile);
  if (GreaterType::individuals.size() > 1)
    printer.printIndividuals("Greater",
       &GreaterType::individuals, outFile);
  if (IfActionGroupType::individuals.size() > 1)
    printer.printIndividuals("IfActionGroup",
       &IfActionGroupType::individuals, outFile);
  if (KittingPlanType::individuals.size() > 1)
    printer.printIndividuals("KittingPlan",
       &KittingPlanType::individuals, outFile);
  if (LessOrEqualType::individuals.size() > 1)
    printer.printIndividuals("LessOrEqual",
       &LessOrEqualType::individuals, outFile);
  if (LessType::individuals.size() > 1)
    printer.printIndividuals("Less",
       &LessType::individuals, outFile);
  if (LocatePartType::individuals.size() > 1)
    printer.printIndividuals("LocatePart",
       &LocatePartType::individuals, outFile);
  if (MinusType::individuals.size() > 1)
    printer.printIndividuals("Minus",
       &MinusType::individuals, outFile);
  if (ModType::individuals.size() > 1)
    printer.printIndividuals("Mod",
       &ModType::individuals, outFile);
  if (NegateType::individuals.size() > 1)
    printer.printIndividuals("Negate",
       &NegateType::individuals, outFile);
  if (NotEqualType::individuals.size() > 1)
    printer.printIndividuals("NotEqual",
       &NotEqualType::individuals, outFile);
  if (NotType::individuals.size() > 1)
    printer.printIndividuals("Not",
       &NotType::individuals, outFile);
  if (NumberedPlanElementType::individuals.size() > 1)
    printer.printIndividuals("NumberedPlanElement",
       &NumberedPlanElementType::individuals, outFile);
  if (OneOfActionGroupType::individuals.size() > 1)
    printer.printIndividuals("OneOfActionGroup",
       &OneOfActionGroupType::individuals, outFile);
  if (OrType::individuals.size() > 1)
    printer.printIndividuals("Or",
       &OrType::individuals, outFile);
  if (OrderedActionGroupType::individuals.size() > 1)
    printer.printIndividuals("OrderedActionGroup",
       &OrderedActionGroupType::individuals, outFile);
  if (PartiallyOrderedActionGroupType::individuals.size() > 1)
    printer.printIndividuals("PartiallyOrderedActionGroup",
       &PartiallyOrderedActionGroupType::individuals, outFile);
  if (PlusType::individuals.size() > 1)
    printer.printIndividuals("Plus",
       &PlusType::individuals, outFile);
  if (PointType::individuals.size() > 1)
    printer.printIndividuals("Point",
       &PointType::individuals, outFile);
  if (PoseLocationInType::individuals.size() > 1)
    printer.printIndividuals("PoseLocationIn",
       &PoseLocationInType::individuals, outFile);
  if (PoseLocationOnType::individuals.size() > 1)
    printer.printIndividuals("PoseLocationOn",
       &PoseLocationOnType::individuals, outFile);
  if (PoseOnlyLocationType::individuals.size() > 1)
    printer.printIndividuals("PoseOnlyLocation",
       &PoseOnlyLocationType::individuals, outFile);
  if (PropValType::individuals.size() > 1)
    printer.printIndividuals("PropVal",
       &PropValType::individuals, outFile);
  if (PutKitTrayType::individuals.size() > 1)
    printer.printIndividuals("PutKitTray",
       &PutKitTrayType::individuals, outFile);
  if (PutKitType::individuals.size() > 1)
    printer.printIndividuals("PutKit",
       &PutKitType::individuals, outFile);
  if (PutPartType::individuals.size() > 1)
    printer.printIndividuals("PutPart",
       &PutPartType::individuals, outFile);
  if (RelativeLocationInType::individuals.size() > 1)
    printer.printIndividuals("RelativeLocationIn",
       &RelativeLocationInType::individuals, outFile);
  if (RelativeLocationOnType::individuals.size() > 1)
    printer.printIndividuals("RelativeLocationOn",
       &RelativeLocationOnType::individuals, outFile);
  if (SomeOfActionGroupType::individuals.size() > 1)
    printer.printIndividuals("SomeOfActionGroup",
       &SomeOfActionGroupType::individuals, outFile);
  if (StepWithPredecessorsType::individuals.size() > 1)
    printer.printIndividuals("StepWithPredecessors",
       &StepWithPredecessorsType::individuals, outFile);
  if (TakeKitTrayType::individuals.size() > 1)
    printer.printIndividuals("TakeKitTray",
       &TakeKitTrayType::individuals, outFile);
  if (TakeKitType::individuals.size() > 1)
    printer.printIndividuals("TakeKit",
       &TakeKitType::individuals, outFile);
  if (TakePartType::individuals.size() > 1)
    printer.printIndividuals("TakePart",
       &TakePartType::individuals, outFile);
  if (TestAndStepType::individuals.size() > 1)
    printer.printIndividuals("TestAndStep",
       &TestAndStepType::individuals, outFile);
  if (TimesType::individuals.size() > 1)
    printer.printIndividuals("Times",
       &TimesType::individuals, outFile);
  if (TrueType::individuals.size() > 1)
    printer.printIndividuals("True",
       &TrueType::individuals, outFile);
  if (UnorderedActionGroupType::individuals.size() > 1)
    printer.printIndividuals("UnorderedActionGroup",
       &UnorderedActionGroupType::individuals, outFile);
  if (VarSetType::individuals.size() > 1)
    printer.printIndividuals("VarSet",
       &VarSetType::individuals, outFile);
  if (VarValType::individuals.size() > 1)
    printer.printIndividuals("VarVal",
       &VarValType::individuals, outFile);
  if (VariableDeclarationType::individuals.size() > 1)
    printer.printIndividuals("VariableDeclaration",
       &VariableDeclarationType::individuals, outFile);
  if (VectorType::individuals.size() > 1)
    printer.printIndividuals("Vector",
       &VectorType::individuals, outFile);
  if (WhileActionGroupType::individuals.size() > 1)
    printer.printIndividuals("WhileActionGroup",
       &WhileActionGroupType::individuals, outFile);

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
  printer.startIndi(Name, "And", outFile);
  printer.printObjProp("hasBinaryBooleanExpression_B1",
                       Name, B1->Name, outFile);
  B1->printOwl(outFile);
  printer.printObjProp("hasBinaryBooleanExpression_B2",
                       Name, B2->Name, outFile);
  B2->printOwl(outFile);
  printer.endIndi("And", outFile);
  individuals.insert(Name->val);
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
  printer.startIndi(Name, "AttachEndEffector", outFile);
  printer.printXmlNMTOKENProp("hasAttachEndEffector_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasAttachEndEffector_EndEffectorName",
                              Name, EndEffectorName, outFile);
  printer.printXmlNMTOKENProp("hasAttachEndEffector_EndEffectorHolderName",
                              Name, EndEffectorHolderName, outFile);
  printer.endIndi("AttachEndEffector", outFile);
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
  printer.startIndi(Name, "CreateKit", outFile);
  printer.printXmlNMTOKENProp("hasCreateKit_KitTrayName",
                              Name, KitTrayName, outFile);
  printer.printXmlNMTOKENProp("hasCreateKit_KitName",
                              Name, KitName, outFile);
  printer.endIndi("CreateKit", outFile);
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
  printer.startIndi(Name, "Decimal", outFile);
  printer.printXmlDecimalProp("hasDecimal_A",
                              Name, A, outFile);
  printer.endIndi("Decimal", outFile);
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
  printer.startIndi(Name, "DetachEndEffector", outFile);
  printer.printXmlNMTOKENProp("hasDetachEndEffector_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasDetachEndEffector_EndEffectorName",
                              Name, EndEffectorName, outFile);
  printer.printXmlNMTOKENProp("hasDetachEndEffector_EndEffectorHolderName",
                              Name, EndEffectorHolderName, outFile);
  printer.endIndi("DetachEndEffector", outFile);
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
  printer.startIndi(Name, "Div", outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Div", outFile);
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
  printer.startIndi(Name, "Else", outFile);
  printer.printObjProp("hasElse_Step",
                       Name, Step->Name, outFile);
  Step->printOwl(outFile);
  printer.endIndi("Else", outFile);
  individuals.insert(Name->val);
}

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
  printer.startIndi(Name, "Equal", outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Equal", outFile);
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
  printer.startIndi(Name, "False", outFile);
  printer.endIndi("False", outFile);
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
  printer.startIndi(Name, "GreaterOrEqual", outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("GreaterOrEqual", outFile);
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
  printer.startIndi(Name, "Greater", outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Greater", outFile);
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
  printer.startIndi(Name, "IfActionGroup", outFile);
  printer.printObjProp("hasIfActionGroup_If",
                       Name, If->Name, outFile);
  If->printOwl(outFile);
  {
    std::list<TestAndStepType *>::iterator iter;
    for (iter = ElseIf->begin();
         iter != ElseIf->end(); iter++)
      {
        printer.printObjProp("hasIfActionGroup_ElseIf",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  if (Else)
    {
      printer.printObjProp("hasIfActionGroup_Else",
                           Name, Else->Name, outFile);
      Else->printOwl(outFile);
    }
  printer.endIndi("IfActionGroup", outFile);
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
 std::list<XmlNMTOKEN *> * ObjectIn,
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
  printer.startIndi(Name, "KittingPlan", outFile);
  printer.printXmlNMTOKENProp("hasKittingPlan_PlanId",
                              Name, PlanId, outFile);
  printer.printXmlTokenProp("hasKittingPlan_PlanVersion",
                            Name, PlanVersion, outFile);
  printer.printXmlDateTimeProp("hasKittingPlan_PlanDateAndTime",
                               Name, PlanDateAndTime, outFile);
  printer.printXmlTokenProp("hasKittingPlan_PlanAuthor",
                            Name, PlanAuthor, outFile);
  printer.printXmlStringProp("hasKittingPlan_PlanDescription",
                             Name, PlanDescription, outFile);
  {
    std::list<XmlNMTOKEN *>::iterator iter;
    for (iter = Object->begin();
        iter != Object->end(); iter++)
      {
        printer.printXmlNMTOKENProp("hasKittingPlan_Object",
                                    Name, *iter, outFile);
      }
  }
  {
    std::list<VariableDeclarationType *>::iterator iter;
    for (iter = Variable->begin();
         iter != Variable->end(); iter++)
      {
        printer.printObjProp("hasKittingPlan_Variable",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printObjProp("hasKittingPlan_PlanRoot",
                       Name, PlanRoot->Name, outFile);
  PlanRoot->printOwl(outFile);
  printer.endIndi("KittingPlan", outFile);
  individuals.insert(Name->val);
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
  printer.startIndi(Name, "LessOrEqual", outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("LessOrEqual", outFile);
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
  printer.startIndi(Name, "Less", outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Less", outFile);
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
  printer.startIndi(Name, "LocatePart", outFile);
  printer.printXmlNMTOKENProp("hasLocatePart_PartName",
                              Name, PartName, outFile);
  printer.endIndi("LocatePart", outFile);
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
  printer.startIndi(Name, "Minus", outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Minus", outFile);
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
  printer.startIndi(Name, "Mod", outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Mod", outFile);
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
  printer.startIndi(Name, "Negate", outFile);
  printer.printObjProp("hasNegate_A",
                       Name, A->Name, outFile);
  A->printOwl(outFile);
  printer.endIndi("Negate", outFile);
  individuals.insert(Name->val);
}

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
  printer.startIndi(Name, "NotEqual", outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasArithmeticComparisonBooleanExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("NotEqual", outFile);
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
  printer.startIndi(Name, "Not", outFile);
  printer.printObjProp("hasNot_B",
                       Name, B->Name, outFile);
  B->printOwl(outFile);
  printer.endIndi("Not", outFile);
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
  printer.startIndi(Name, "NumberedPlanElement", outFile);
  printer.printXmlPositiveIntegerProp("hasNumberedPlanElement_SequenceNumber",
                                      Name, SequenceNumber, outFile);
  printer.printObjProp("hasNumberedPlanElement_PlanElement",
                       Name, PlanElement->Name, outFile);
  PlanElement->printOwl(outFile);
  printer.endIndi("NumberedPlanElement", outFile);
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
  printer.startIndi(Name, "OneOfActionGroup", outFile);
  {
    std::list<NumberedPlanElementType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("hasOneOfActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("OneOfActionGroup", outFile);
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
  printer.startIndi(Name, "Or", outFile);
  printer.printObjProp("hasBinaryBooleanExpression_B1",
                       Name, B1->Name, outFile);
  B1->printOwl(outFile);
  printer.printObjProp("hasBinaryBooleanExpression_B2",
                       Name, B2->Name, outFile);
  B2->printOwl(outFile);
  printer.endIndi("Or", outFile);
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
  printer.startIndi(Name, "OrderedActionGroup", outFile);
  {
    std::list<NumberedPlanElementType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("hasOrderedActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("OrderedActionGroup", outFile);
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
  printer.startIndi(Name, "PartiallyOrderedActionGroup", outFile);
  {
    std::list<StepWithPredecessorsType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("hasPartiallyOrderedActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("PartiallyOrderedActionGroup", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PhysicalLocationType

*/

PhysicalLocationType::PhysicalLocationType() {}

PhysicalLocationType::PhysicalLocationType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn) :
  DataThingType(
    NameIn)
{
  RefObjectName = RefObjectNameIn;
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
  printer.startIndi(Name, "Plus", outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Plus", outFile);
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
  printer.startIndi(Name, "Point", outFile);
  printer.printXmlDecimalProp("hasPoint_X",
                              Name, X, outFile);
  printer.printXmlDecimalProp("hasPoint_Y",
                              Name, Y, outFile);
  printer.printXmlDecimalProp("hasPoint_Z",
                              Name, Z, outFile);
  printer.endIndi("Point", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationInType

*/

PoseLocationInType::PoseLocationInType() {}

PoseLocationInType::PoseLocationInType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PoseLocationType(
    NameIn,
    RefObjectNameIn,
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
  printer.startIndi(Name, "PoseLocationIn", outFile);
  printer.printXmlNMTOKENProp("hasPhysicalLocation_RefObjectName",
                              Name, RefObjectName, outFile);
  printer.printObjProp("hasPoseLocation_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("hasPoseLocation_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("hasPoseLocation_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  if (PositionStandardDeviation)
    {
      PositionStandardDeviation->printProp("hasPoseLocation_PositionStandardDeviation",
                                           Name, outFile);
    }
  if (OrientationStandardDeviation)
    {
      OrientationStandardDeviation->printProp("hasPoseLocation_OrientationStandardDeviation",
                                              Name, outFile);
    }
  printer.endIndi("PoseLocationIn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationOnType

*/

PoseLocationOnType::PoseLocationOnType() {}

PoseLocationOnType::PoseLocationOnType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PoseLocationType(
    NameIn,
    RefObjectNameIn,
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
  printer.startIndi(Name, "PoseLocationOn", outFile);
  printer.printXmlNMTOKENProp("hasPhysicalLocation_RefObjectName",
                              Name, RefObjectName, outFile);
  printer.printObjProp("hasPoseLocation_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("hasPoseLocation_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("hasPoseLocation_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  if (PositionStandardDeviation)
    {
      PositionStandardDeviation->printProp("hasPoseLocation_PositionStandardDeviation",
                                           Name, outFile);
    }
  if (OrientationStandardDeviation)
    {
      OrientationStandardDeviation->printProp("hasPoseLocation_OrientationStandardDeviation",
                                              Name, outFile);
    }
  printer.endIndi("PoseLocationOn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationType

*/

PoseLocationType::PoseLocationType() {}

PoseLocationType::PoseLocationType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PhysicalLocationType(
    NameIn,
    RefObjectNameIn)
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
 XmlNMTOKEN * RefObjectNameIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn,
 PositiveDecimalType * PositionStandardDeviationIn,
 PositiveDecimalType * OrientationStandardDeviationIn) :
  PoseLocationType(
    NameIn,
    RefObjectNameIn,
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
  printer.startIndi(Name, "PoseOnlyLocation", outFile);
  printer.printXmlNMTOKENProp("hasPhysicalLocation_RefObjectName",
                              Name, RefObjectName, outFile);
  printer.printObjProp("hasPoseLocation_Point",
                       Name, Point->Name, outFile);
  Point->printOwl(outFile);
  printer.printObjProp("hasPoseLocation_XAxis",
                       Name, XAxis->Name, outFile);
  XAxis->printOwl(outFile);
  printer.printObjProp("hasPoseLocation_ZAxis",
                       Name, ZAxis->Name, outFile);
  ZAxis->printOwl(outFile);
  if (PositionStandardDeviation)
    {
      PositionStandardDeviation->printProp("hasPoseLocation_PositionStandardDeviation",
                                           Name, outFile);
    }
  if (OrientationStandardDeviation)
    {
      OrientationStandardDeviation->printProp("hasPoseLocation_OrientationStandardDeviation",
                                              Name, outFile);
    }
  printer.endIndi("PoseOnlyLocation", outFile);
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
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
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
  printer.startIndi(Name, "PropVal", outFile);
  printer.printXmlNMTOKENProp("hasPropVal_ThingName",
                              Name, ThingName, outFile);
  printer.printXmlNMTOKENProp("hasPropVal_Property",
                              Name, Property, outFile);
  printer.endIndi("PropVal", outFile);
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
  printer.startIndi(Name, "PutKitTray", outFile);
  printer.printXmlNMTOKENProp("hasPutKitTray_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasPutKitTray_KitTrayName",
                              Name, KitTrayName, outFile);
  printer.printObjProp("hasPutKitTray_Location",
                       Name, Location->Name, outFile);
  Location->printOwl(outFile);
  printer.endIndi("PutKitTray", outFile);
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
  printer.startIndi(Name, "PutKit", outFile);
  printer.printXmlNMTOKENProp("hasPutKit_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasPutKit_KitName",
                              Name, KitName, outFile);
  printer.printObjProp("hasPutKit_Location",
                       Name, Location->Name, outFile);
  Location->printOwl(outFile);
  printer.endIndi("PutKit", outFile);
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
  printer.startIndi(Name, "PutPart", outFile);
  printer.printXmlNMTOKENProp("hasPutPart_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasPutPart_PartName",
                              Name, PartName, outFile);
  printer.printObjProp("hasPutPart_Location",
                       Name, Location->Name, outFile);
  Location->printOwl(outFile);
  printer.endIndi("PutPart", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationInType

*/

RelativeLocationInType::RelativeLocationInType() {}

RelativeLocationInType::RelativeLocationInType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn,
 XmlString * DescriptionIn) :
  RelativeLocationType(
    NameIn,
    RefObjectNameIn,
    DescriptionIn)
{
}

RelativeLocationInType::~RelativeLocationInType() {}

void RelativeLocationInType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "RelativeLocationIn", outFile);
  printer.printXmlNMTOKENProp("hasPhysicalLocation_RefObjectName",
                              Name, RefObjectName, outFile);
  printer.printXmlStringProp("hasRelativeLocation_Description",
                             Name, Description, outFile);
  printer.endIndi("RelativeLocationIn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationOnType

*/

RelativeLocationOnType::RelativeLocationOnType() {}

RelativeLocationOnType::RelativeLocationOnType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn,
 XmlString * DescriptionIn) :
  RelativeLocationType(
    NameIn,
    RefObjectNameIn,
    DescriptionIn)
{
}

RelativeLocationOnType::~RelativeLocationOnType() {}

void RelativeLocationOnType::printOwl(FILE * outFile)
{
  printer.startIndi(Name, "RelativeLocationOn", outFile);
  printer.printXmlNMTOKENProp("hasPhysicalLocation_RefObjectName",
                              Name, RefObjectName, outFile);
  printer.printXmlStringProp("hasRelativeLocation_Description",
                             Name, Description, outFile);
  printer.endIndi("RelativeLocationOn", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationType

*/

RelativeLocationType::RelativeLocationType() {}

RelativeLocationType::RelativeLocationType(
 XmlID * NameIn,
 XmlNMTOKEN * RefObjectNameIn,
 XmlString * DescriptionIn) :
  PhysicalLocationType(
    NameIn,
    RefObjectNameIn)
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
  printer.startIndi(Name, "SomeOfActionGroup", outFile);
  {
    std::list<PlanElementBaseType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("hasSomeOfActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.printXmlPositiveIntegerProp("hasSomeOfActionGroup_NumberOfSteps",
                                      Name, NumberOfSteps, outFile);
  printer.endIndi("SomeOfActionGroup", outFile);
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
  printer.startIndi(Name, "StepWithPredecessors", outFile);
  printer.printXmlPositiveIntegerProp("hasStepWithPredecessors_SequenceNumber",
                                      Name, SequenceNumber, outFile);
  {
    std::list<XmlPositiveInteger *>::iterator iter;
    for (iter = Predecessor->begin();
        iter != Predecessor->end(); iter++)
      {
        printer.printXmlPositiveIntegerProp("hasStepWithPredecessors_Predecessor",
                                            Name, *iter, outFile);
      }
  }
  printer.printObjProp("hasStepWithPredecessors_PlanElement",
                       Name, PlanElement->Name, outFile);
  PlanElement->printOwl(outFile);
  printer.endIndi("StepWithPredecessors", outFile);
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
  printer.startIndi(Name, "TakeKitTray", outFile);
  printer.printXmlNMTOKENProp("hasTakeKitTray_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasTakeKitTray_KitTrayName",
                              Name, KitTrayName, outFile);
  printer.endIndi("TakeKitTray", outFile);
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
  printer.startIndi(Name, "TakeKit", outFile);
  printer.printXmlNMTOKENProp("hasTakeKit_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasTakeKit_KitName",
                              Name, KitName, outFile);
  printer.endIndi("TakeKit", outFile);
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
  printer.startIndi(Name, "TakePart", outFile);
  printer.printXmlNMTOKENProp("hasTakePart_RobotName",
                              Name, RobotName, outFile);
  printer.printXmlNMTOKENProp("hasTakePart_PartName",
                              Name, PartName, outFile);
  printer.endIndi("TakePart", outFile);
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
  printer.startIndi(Name, "TestAndStep", outFile);
  printer.printObjProp("hasTestAndStep_Test",
                       Name, Test->Name, outFile);
  Test->printOwl(outFile);
  printer.printObjProp("hasTestAndStep_Step",
                       Name, Step->Name, outFile);
  Step->printOwl(outFile);
  printer.endIndi("TestAndStep", outFile);
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
  printer.startIndi(Name, "Times", outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A1",
                       Name, A1->Name, outFile);
  A1->printOwl(outFile);
  printer.printObjProp("hasBinaryArithmeticExpression_A2",
                       Name, A2->Name, outFile);
  A2->printOwl(outFile);
  printer.endIndi("Times", outFile);
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
  printer.startIndi(Name, "True", outFile);
  printer.endIndi("True", outFile);
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
  printer.startIndi(Name, "UnorderedActionGroup", outFile);
  {
    std::list<PlanElementBaseType *>::iterator iter;
    for (iter = Step->begin();
         iter != Step->end(); iter++)
      {
        printer.printObjProp("hasUnorderedActionGroup_Step",
                             Name, (*iter)->Name, outFile);
        (*iter)->printOwl(outFile);
      }
  }
  printer.endIndi("UnorderedActionGroup", outFile);
  individuals.insert(Name->val);
}

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
  printer.startIndi(Name, "VarSet", outFile);
  printer.printObjRefProp("hasVarSet_Var",
                          Name, VarName, outFile);
  printer.printObjProp("hasVarSet_Val",
                       Name, Val->Name, outFile);
  Val->printOwl(outFile);
  printer.endIndi("VarSet", outFile);
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
  printer.startIndi(Name, "VarVal", outFile);
  printer.printObjRefProp("hasVarVal_Var",
                          Name, VarName, outFile);
  printer.endIndi("VarVal", outFile);
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
  printer.startIndi(Name, "VariableDeclaration", outFile);
  printer.printXmlDecimalProp("hasVariableDeclaration_Val",
                              Name, Val, outFile);
  printer.endIndi("VariableDeclaration", outFile);
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
  printer.startIndi(Name, "Vector", outFile);
  printer.printXmlDecimalProp("hasVector_I",
                              Name, I, outFile);
  printer.printXmlDecimalProp("hasVector_J",
                              Name, J, outFile);
  printer.printXmlDecimalProp("hasVector_K",
                              Name, K, outFile);
  printer.endIndi("Vector", outFile);
  individuals.insert(Name->val);
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
  printer.startIndi(Name, "WhileActionGroup", outFile);
  printer.printObjProp("hasWhileActionGroup_Test",
                       Name, Test->Name, outFile);
  Test->printOwl(outFile);
  printer.printObjProp("hasWhileActionGroup_Step",
                       Name, Step->Name, outFile);
  Step->printOwl(outFile);
  printer.endIndi("WhileActionGroup", outFile);
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
  printer.printHeader(outFile);
}

/*********************************************************************/

