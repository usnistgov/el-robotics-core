/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "soapClasses.hh"

#define INDENT 2

/*********************************************************************/
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

void SOAPFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<SOAP\n");
  header->printSelf(outFile);
  SOAP->printSelf(outFile);
  fprintf(outFile, "</SOAP>\n");
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
  printTypp = false;
}

ActionBaseType::~ActionBaseType() {}

void ActionBaseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ActionBaseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

AnyOrderOrderingConstructType::~AnyOrderOrderingConstructType() {}

void AnyOrderOrderingConstructType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"AnyOrderOrderingConstructType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<CountOrderingConstruct");
  CountOrderingConstruct->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</CountOrderingConstruct>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PositionInOrderedList>");
  PositionInOrderedList->printSelf(outFile);
  fprintf(outFile, "</PositionInOrderedList>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

AttachEndEffectorType::~AttachEndEffectorType() {}

void AttachEndEffectorType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"AttachEndEffectorType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorParameter>");
  EndEffectorParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorHolderParameter>");
  EndEffectorHolderParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorHolderParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorChangingStationParameter>");
  EndEffectorChangingStationParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorChangingStationParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

CountOrderingConstructType::~CountOrderingConstructType() {}

void CountOrderingConstructType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"CountOrderingConstructType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Predicate");
  Predicate->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Predicate>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PredicateOccurrence>");
  PredicateOccurrence->printSelf(outFile);
  fprintf(outFile, "</PredicateOccurrence>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

CreateKitType::~CreateKitType() {}

void CreateKitType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"CreateKitType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<KitParameter>");
  KitParameter->printSelf(outFile);
  fprintf(outFile, "</KitParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTrayParameter>");
  KitTrayParameter->printSelf(outFile);
  fprintf(outFile, "</KitTrayParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<WorkTableParameter>");
  WorkTableParameter->printSelf(outFile);
  fprintf(outFile, "</WorkTableParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

DetachEndEffectorType::~DetachEndEffectorType() {}

void DetachEndEffectorType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"DetachEndEffectorType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorParameter>");
  EndEffectorParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorHolderParameter>");
  EndEffectorHolderParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorHolderParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorChangingStationParameter>");
  EndEffectorChangingStationParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorChangingStationParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

DomainType::~DomainType() {}

void DomainType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"DomainType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<XmlNMTOKEN *>::iterator iter;
    for (iter = Requirement->begin(); iter != Requirement->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Requirement>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</Requirement>\n");
      }
  }
  {
    std::list<XmlNMTOKEN *>::iterator iter;
    for (iter = Variable->begin(); iter != Variable->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Variable>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</Variable>\n");
      }
  }
  {
    std::list<PredicateType *>::iterator iter;
    for (iter = Predicate->begin(); iter != Predicate->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Predicate");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Predicate>\n");
      }
  }
  {
    std::list<FunctionType *>::iterator iter;
    for (iter = Function->begin(); iter != Function->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Function");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Function>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<AttachEndEffector");
  AttachEndEffector->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</AttachEndEffector>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<CreateKit");
  CreateKit->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</CreateKit>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<DetachEndEffector");
  DetachEndEffector->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</DetachEndEffector>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<TakePart");
  TakePart->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</TakePart>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<TakeKit");
  TakeKit->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</TakeKit>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<TakeKitTray");
  TakeKitTray->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</TakeKitTray>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PutPart");
  PutPart->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PutPart>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PutKit");
  PutKit->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PutKit>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PutKitTray");
  PutKitTray->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PutKitTray>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

EffectType::~EffectType() {}

void EffectType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"EffectType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = PredicateName->begin(); iter != PredicateName->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<PredicateName>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</PredicateName>\n");
      }
  }
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = NotPredicateName->begin(); iter != NotPredicateName->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<NotPredicateName>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</NotPredicateName>\n");
      }
  }
  if (FunctionName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<FunctionName>");
      FunctionName->printSelf(outFile);
      fprintf(outFile, "</FunctionName>\n");
    }
  if (FunctionOperation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<FunctionOperation");
      FunctionOperation->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</FunctionOperation>\n");
    }
  {
    std::list<FunctionToFunctionLessType *>::iterator iter;
    for (iter = F1LessF2->begin(); iter != F1LessF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1LessF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1LessF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionEqualType *>::iterator iter;
    for (iter = F1EqualF2->begin(); iter != F1EqualF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1EqualF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1EqualF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionGreaterOrEqualType *>::iterator iter;
    for (iter = F1GreaterOrEqualF2->begin(); iter != F1GreaterOrEqualF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1GreaterOrEqualF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1GreaterOrEqualF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionGreaterType *>::iterator iter;
    for (iter = F1GreaterF2->begin(); iter != F1GreaterF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1GreaterF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1GreaterF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionLessOrEqualType *>::iterator iter;
    for (iter = F1LessOrEqualF2->begin(); iter != F1LessOrEqualF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1LessOrEqualF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1LessOrEqualF2>\n");
      }
  }
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

ExistOrderingConstructType::~ExistOrderingConstructType() {}

void ExistOrderingConstructType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ExistOrderingConstructType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Predicate");
  Predicate->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Predicate>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionBooleanExpressionType::~FunctionBooleanExpressionType() {}

void FunctionBooleanExpressionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionBooleanExpressionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionOperationType::~FunctionOperationType() {}

void FunctionOperationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionOperationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<FunctionName>");
  FunctionName->printSelf(outFile);
  fprintf(outFile, "</FunctionName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Expression>");
  Expression->printSelf(outFile);
  fprintf(outFile, "</Expression>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Value>");
  Value->printSelf(outFile);
  fprintf(outFile, "</Value>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToDecimalBoolType::~FunctionToDecimalBoolType() {}

void FunctionToDecimalBoolType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToDecimalBoolType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1>");
  A1->printSelf(outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToDecimalEqualType::~FunctionToDecimalEqualType() {}

void FunctionToDecimalEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToDecimalEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1>");
  A1->printSelf(outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToDecimalGreaterOrEqualType::~FunctionToDecimalGreaterOrEqualType() {}

void FunctionToDecimalGreaterOrEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToDecimalGreaterOrEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1>");
  A1->printSelf(outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToDecimalGreaterType::~FunctionToDecimalGreaterType() {}

void FunctionToDecimalGreaterType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToDecimalGreaterType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1>");
  A1->printSelf(outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToDecimalLessOrEqualType::~FunctionToDecimalLessOrEqualType() {}

void FunctionToDecimalLessOrEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToDecimalLessOrEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1>");
  A1->printSelf(outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToDecimalLessType::~FunctionToDecimalLessType() {}

void FunctionToDecimalLessType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToDecimalLessType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1>");
  A1->printSelf(outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToFunctionBoolType::~FunctionToFunctionBoolType() {}

void FunctionToFunctionBoolType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToFunctionBoolType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F2Name>");
  F2Name->printSelf(outFile);
  fprintf(outFile, "</F2Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToFunctionEqualType::~FunctionToFunctionEqualType() {}

void FunctionToFunctionEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToFunctionEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F2Name>");
  F2Name->printSelf(outFile);
  fprintf(outFile, "</F2Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToFunctionGreaterOrEqualType::~FunctionToFunctionGreaterOrEqualType() {}

void FunctionToFunctionGreaterOrEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToFunctionGreaterOrEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F2Name>");
  F2Name->printSelf(outFile);
  fprintf(outFile, "</F2Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToFunctionGreaterType::~FunctionToFunctionGreaterType() {}

void FunctionToFunctionGreaterType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToFunctionGreaterType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F2Name>");
  F2Name->printSelf(outFile);
  fprintf(outFile, "</F2Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToFunctionLessOrEqualType::~FunctionToFunctionLessOrEqualType() {}

void FunctionToFunctionLessOrEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToFunctionLessOrEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F2Name>");
  F2Name->printSelf(outFile);
  fprintf(outFile, "</F2Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionToFunctionLessType::~FunctionToFunctionLessType() {}

void FunctionToFunctionLessType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionToFunctionLessType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F1Name>");
  F1Name->printSelf(outFile);
  fprintf(outFile, "</F1Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<F2Name>");
  F2Name->printSelf(outFile);
  fprintf(outFile, "</F2Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FunctionType::~FunctionType() {}

void FunctionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FunctionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<ReferenceName>");
  ReferenceName->printSelf(outFile);
  fprintf(outFile, "</ReferenceName>\n");
  if (TargetName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<TargetName>");
      TargetName->printSelf(outFile);
      fprintf(outFile, "</TargetName>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

InContactWithType::~InContactWithType() {}

void InContactWithType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"InContactWithType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RCC8Set>");
  RCC8Set->printSelf(outFile);
  fprintf(outFile, "</RCC8Set>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

OnTopWithContactType::~OnTopWithContactType() {}

void OnTopWithContactType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OnTopWithContactType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RCC8Set>");
  RCC8Set->printSelf(outFile);
  fprintf(outFile, "</RCC8Set>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

OrderedListOrderingConstructType::~OrderedListOrderingConstructType() {}

void OrderedListOrderingConstructType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OrderedListOrderingConstructType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ExistOrderingConstruct");
  ExistOrderingConstruct->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ExistOrderingConstruct>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<AnyOrderOrderingConstruct");
  AnyOrderOrderingConstruct->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</AnyOrderOrderingConstruct>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

OrderingConstructType::~OrderingConstructType() {}

void OrderingConstructType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OrderingConstructType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartiallyInType::~PartiallyInType() {}

void PartiallyInType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartiallyInType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RCC8Set>");
  RCC8Set->printSelf(outFile);
  fprintf(outFile, "</RCC8Set>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PreconditionType::~PreconditionType() {}

void PreconditionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PreconditionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = PredicateName->begin(); iter != PredicateName->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<PredicateName>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</PredicateName>\n");
      }
  }
  if (FunctionName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<FunctionName>");
      FunctionName->printSelf(outFile);
      fprintf(outFile, "</FunctionName>\n");
    }
  if (FunctionOperation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<FunctionOperation");
      FunctionOperation->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</FunctionOperation>\n");
    }
  {
    std::list<FunctionToFunctionLessType *>::iterator iter;
    for (iter = F1LessF2->begin(); iter != F1LessF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1LessF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1LessF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionEqualType *>::iterator iter;
    for (iter = F1EqualF2->begin(); iter != F1EqualF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1EqualF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1EqualF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionGreaterOrEqualType *>::iterator iter;
    for (iter = F1GreaterOrEqualF2->begin(); iter != F1GreaterOrEqualF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1GreaterOrEqualF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1GreaterOrEqualF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionGreaterType *>::iterator iter;
    for (iter = F1GreaterF2->begin(); iter != F1GreaterF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1GreaterF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1GreaterF2>\n");
      }
  }
  {
    std::list<FunctionToFunctionLessOrEqualType *>::iterator iter;
    for (iter = F1LessOrEqualF2->begin(); iter != F1LessOrEqualF2->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<F1LessOrEqualF2");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</F1LessOrEqualF2>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PredicateGroupElementType::~PredicateGroupElementType() {}

void PredicateGroupElementType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PredicateGroupElementType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ReferenceName>");
  ReferenceName->printSelf(outFile);
  fprintf(outFile, "</ReferenceName>\n");
  if (TargetName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<TargetName>");
      TargetName->printSelf(outFile);
      fprintf(outFile, "</TargetName>\n");
    }
  if (StateRelationName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<StateRelationName>");
      StateRelationName->printSelf(outFile);
      fprintf(outFile, "</StateRelationName>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PredicateType::~PredicateType() {}

void PredicateType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PredicateType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  {
    std::list<PredicateGroupElementType *>::iterator iter;
    for (iter = PredicateGroupElement->begin(); iter != PredicateGroupElement->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<PredicateGroupElement");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</PredicateGroupElement>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PutKitTrayType::~PutKitTrayType() {}

void PutKitTrayType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PutKitTrayType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTrayParameter>");
  KitTrayParameter->printSelf(outFile);
  fprintf(outFile, "</KitTrayParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PutKitType::~PutKitType() {}

void PutKitType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PutKitType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitParameter>");
  KitParameter->printSelf(outFile);
  fprintf(outFile, "</KitParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<LargeBoxWithKitsParameter>");
  LargeBoxWithKitsParameter->printSelf(outFile);
  fprintf(outFile, "</LargeBoxWithKitsParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PutPartType::~PutPartType() {}

void PutPartType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PutPartType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartParameter>");
  PartParameter->printSelf(outFile);
  fprintf(outFile, "</PartParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitParameter>");
  KitParameter->printSelf(outFile);
  fprintf(outFile, "</KitParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartsTrayParameter>");
  PartsTrayParameter->printSelf(outFile);
  fprintf(outFile, "</PartsTrayParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class RobotActionBaseType

*/

RobotActionBaseType::RobotActionBaseType() {}

RobotActionBaseType::RobotActionBaseType(
 XmlID * NameIn) :
  ActionBaseType(
    NameIn)
{
  printTypp = false;
}

RobotActionBaseType::~RobotActionBaseType() {}

void RobotActionBaseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"RobotActionBaseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

SOAPType::~SOAPType() {}

void SOAPType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SOAPType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KittingWorkstation");
  KittingWorkstation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</KittingWorkstation>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Domain");
  Domain->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Domain>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<InContactWith");
  InContactWith->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</InContactWith>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<UnderWithContact");
  UnderWithContact->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</UnderWithContact>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartiallyIn");
  PartiallyIn->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PartiallyIn>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<OnTopWithContact");
  OnTopWithContact->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</OnTopWithContact>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

StateRelationType::~StateRelationType() {}

void StateRelationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"StateRelationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RCC8Set>");
  RCC8Set->printSelf(outFile);
  fprintf(outFile, "</RCC8Set>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

TakeKitTrayType::~TakeKitTrayType() {}

void TakeKitTrayType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"TakeKitTrayType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTrayParameter>");
  KitTrayParameter->printSelf(outFile);
  fprintf(outFile, "</KitTrayParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<LargeBoxWithEmptyKitTraysParameter>");
  LargeBoxWithEmptyKitTraysParameter->printSelf(outFile);
  fprintf(outFile, "</LargeBoxWithEmptyKitTraysParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorParameter>");
  EndEffectorParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

TakeKitType::~TakeKitType() {}

void TakeKitType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"TakeKitType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitParameter>");
  KitParameter->printSelf(outFile);
  fprintf(outFile, "</KitParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorParameter>");
  EndEffectorParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

TakePartType::~TakePartType() {}

void TakePartType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"TakePartType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  if (Description)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Description>");
      Description->printSelf(outFile);
      fprintf(outFile, "</Description>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotParameter>");
  RobotParameter->printSelf(outFile);
  fprintf(outFile, "</RobotParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartParameter>");
  PartParameter->printSelf(outFile);
  fprintf(outFile, "</PartParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartsTrayParameter>");
  PartsTrayParameter->printSelf(outFile);
  fprintf(outFile, "</PartsTrayParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorParameter>");
  EndEffectorParameter->printSelf(outFile);
  fprintf(outFile, "</EndEffectorParameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Precondition");
  Precondition->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Precondition>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Effect");
  Effect->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Effect>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

UnderWithContactType::~UnderWithContactType() {}

void UnderWithContactType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"UnderWithContactType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RCC8Set>");
  RCC8Set->printSelf(outFile);
  fprintf(outFile, "</RCC8Set>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

XmlHeaderForSOAP::XmlHeaderForSOAP() {}

XmlHeaderForSOAP::XmlHeaderForSOAP(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForSOAP::~XmlHeaderForSOAP() {}

void XmlHeaderForSOAP::printSelf(
  FILE * outFile)
{
  fprintf(outFile, "  xmlns=\"urn:kitting\"\n");
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

