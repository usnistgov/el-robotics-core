/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "kittingPlanClasses.hh"

#define INDENT 2

/*********************************************************************/
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

void KittingPlanFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<KittingPlan\n");
  header->printSelf(outFile);
  KittingPlan->printSelf(outFile);
  fprintf(outFile, "</KittingPlan>\n");
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

/* class ActionGroupBaseType

*/

ActionGroupBaseType::ActionGroupBaseType() {}

ActionGroupBaseType::ActionGroupBaseType(
 XmlID * NameIn) :
  PlanElementBaseType(
    NameIn)
{
  printTypp = false;
}

ActionGroupBaseType::~ActionGroupBaseType() {}

void ActionGroupBaseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ActionGroupBaseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

AndType::~AndType() {}

void AndType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"AndType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B1");
  B1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B2");
  B2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

ArithmeticComparisonBooleanExpressionType::~ArithmeticComparisonBooleanExpressionType() {}

void ArithmeticComparisonBooleanExpressionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ArithmeticComparisonBooleanExpressionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class ArithmeticExpressionType

*/

ArithmeticExpressionType::ArithmeticExpressionType() {}

ArithmeticExpressionType::ArithmeticExpressionType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
  printTypp = false;
}

ArithmeticExpressionType::~ArithmeticExpressionType() {}

void ArithmeticExpressionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ArithmeticExpressionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
}

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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorName>");
  EndEffectorName->printSelf(outFile);
  fprintf(outFile, "</EndEffectorName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorHolderName>");
  EndEffectorHolderName->printSelf(outFile);
  fprintf(outFile, "</EndEffectorHolderName>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

BinaryArithmeticExpressionType::~BinaryArithmeticExpressionType() {}

void BinaryArithmeticExpressionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BinaryArithmeticExpressionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

BinaryBooleanExpressionType::~BinaryBooleanExpressionType() {}

void BinaryBooleanExpressionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BinaryBooleanExpressionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B1");
  B1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B2");
  B2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B2>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class BooleanConstantType

*/

BooleanConstantType::BooleanConstantType() {}

BooleanConstantType::BooleanConstantType(
 XmlID * NameIn) :
  BooleanExpressionType(
    NameIn)
{
  printTypp = false;
}

BooleanConstantType::~BooleanConstantType() {}

void BooleanConstantType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BooleanConstantType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class BooleanExpressionType

*/

BooleanExpressionType::BooleanExpressionType() {}

BooleanExpressionType::BooleanExpressionType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
  printTypp = false;
}

BooleanExpressionType::~BooleanExpressionType() {}

void BooleanExpressionType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BooleanExpressionType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTrayName>");
  KitTrayName->printSelf(outFile);
  fprintf(outFile, "</KitTrayName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitName>");
  KitName->printSelf(outFile);
  fprintf(outFile, "</KitName>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

DecimalType::~DecimalType() {}

void DecimalType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"DecimalType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A>");
  A->printSelf(outFile);
  fprintf(outFile, "</A>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorName>");
  EndEffectorName->printSelf(outFile);
  fprintf(outFile, "</EndEffectorName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<EndEffectorHolderName>");
  EndEffectorHolderName->printSelf(outFile);
  fprintf(outFile, "</EndEffectorHolderName>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

DivType::~DivType() {}

void DivType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"DivType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class ElseDoType

*/

ElseDoType::ElseDoType() {}

ElseDoType::ElseDoType(
 XmlID * NameIn,
 PlanElementBaseType * StepIn) :
  DataThingType(
    NameIn)
{
  Step = StepIn;
  printTypp = false;
}

ElseDoType::~ElseDoType() {}

void ElseDoType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ElseDoType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Step");
  Step->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Step>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

EqualType::~EqualType() {}

void EqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"EqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

FalseType::~FalseType() {}

void FalseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"FalseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

GreaterOrEqualType::~GreaterOrEqualType() {}

void GreaterOrEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"GreaterOrEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

GreaterType::~GreaterType() {}

void GreaterType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"GreaterType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class IfActionGroupType

*/

IfActionGroupType::IfActionGroupType() {}

IfActionGroupType::IfActionGroupType(
 XmlID * NameIn,
 TestAndStepType * IfIn,
 std::list<TestAndStepType *> * ElseIfIn,
 ElseDoType * ElseDoIn) :
  ActionGroupBaseType(
    NameIn)
{
  If = IfIn;
  ElseIf = ElseIfIn;
  ElseDo = ElseDoIn;
  printTypp = false;
}

IfActionGroupType::~IfActionGroupType() {}

void IfActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"IfActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<If");
  If->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</If>\n");
  {
    std::list<TestAndStepType *>::iterator iter;
    for (iter = ElseIf->begin(); iter != ElseIf->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<ElseIf");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</ElseIf>\n");
      }
  }
  if (ElseDo)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ElseDo");
      ElseDo->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ElseDo>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

KittingPlanType::~KittingPlanType() {}

void KittingPlanType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"KittingPlanType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanId>");
  PlanId->printSelf(outFile);
  fprintf(outFile, "</PlanId>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanVersion>");
  PlanVersion->printSelf(outFile);
  fprintf(outFile, "</PlanVersion>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanDateAndTime>");
  PlanDateAndTime->printSelf(outFile);
  fprintf(outFile, "</PlanDateAndTime>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanAuthor>");
  PlanAuthor->printSelf(outFile);
  fprintf(outFile, "</PlanAuthor>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanDescription>");
  PlanDescription->printSelf(outFile);
  fprintf(outFile, "</PlanDescription>\n");
  {
    std::list<XmlID *>::iterator iter;
    for (iter = Object->begin(); iter != Object->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Object>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</Object>\n");
      }
  }
  {
    std::list<VariableDeclarationType *>::iterator iter;
    for (iter = Variable->begin(); iter != Variable->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Variable");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Variable>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanRoot");
  PlanRoot->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PlanRoot>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

LessOrEqualType::~LessOrEqualType() {}

void LessOrEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"LessOrEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

LessType::~LessType() {}

void LessType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"LessType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

LocatePartType::~LocatePartType() {}

void LocatePartType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"LocatePartType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartName>");
  PartName->printSelf(outFile);
  fprintf(outFile, "</PartName>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

MinusType::~MinusType() {}

void MinusType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"MinusType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

ModType::~ModType() {}

void ModType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ModType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

NegateType::~NegateType() {}

void NegateType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"NegateType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A");
  A->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

NotEqualType::~NotEqualType() {}

void NotEqualType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"NotEqualType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

NotType::~NotType() {}

void NotType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"NotType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B");
  B->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

NumberedPlanElementType::~NumberedPlanElementType() {}

void NumberedPlanElementType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"NumberedPlanElementType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SequenceNumber>");
  SequenceNumber->printSelf(outFile);
  fprintf(outFile, "</SequenceNumber>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanElement");
  PlanElement->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PlanElement>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

OneOfActionGroupType::~OneOfActionGroupType() {}

void OneOfActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OneOfActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<NumberedPlanElementType *>::iterator iter;
    for (iter = Step->begin(); iter != Step->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Step");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Step>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

OrType::~OrType() {}

void OrType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OrType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B1");
  B1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<B2");
  B2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</B2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

OrderedActionGroupType::~OrderedActionGroupType() {}

void OrderedActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"OrderedActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<NumberedPlanElementType *>::iterator iter;
    for (iter = Step->begin(); iter != Step->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Step");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Step>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartiallyOrderedActionGroupType::~PartiallyOrderedActionGroupType() {}

void PartiallyOrderedActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartiallyOrderedActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<StepWithPredecessorsType *>::iterator iter;
    for (iter = Step->begin(); iter != Step->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Step");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Step>\n");
      }
  }
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class PlanElementBaseType

*/

PlanElementBaseType::PlanElementBaseType() {}

PlanElementBaseType::PlanElementBaseType(
 XmlID * NameIn) :
  DataThingType(
    NameIn)
{
  printTypp = false;
}

PlanElementBaseType::~PlanElementBaseType() {}

void PlanElementBaseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PlanElementBaseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

PlusType::~PlusType() {}

void PlusType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PlusType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PropValType::~PropValType() {}

void PropValType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PropValType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ThingName>");
  ThingName->printSelf(outFile);
  fprintf(outFile, "</ThingName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Property>");
  Property->printSelf(outFile);
  fprintf(outFile, "</Property>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTrayName>");
  KitTrayName->printSelf(outFile);
  fprintf(outFile, "</KitTrayName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Location");
  Location->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Location>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitName>");
  KitName->printSelf(outFile);
  fprintf(outFile, "</KitName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Location");
  Location->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Location>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartName>");
  PartName->printSelf(outFile);
  fprintf(outFile, "</PartName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Location");
  Location->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Location>\n");
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

/* class SensorActionBaseType

*/

SensorActionBaseType::SensorActionBaseType() {}

SensorActionBaseType::SensorActionBaseType(
 XmlID * NameIn) :
  ActionBaseType(
    NameIn)
{
  printTypp = false;
}

SensorActionBaseType::~SensorActionBaseType() {}

void SensorActionBaseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SensorActionBaseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

SomeOfActionGroupType::~SomeOfActionGroupType() {}

void SomeOfActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SomeOfActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<PlanElementBaseType *>::iterator iter;
    for (iter = Step->begin(); iter != Step->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Step");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Step>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<NumberOfSteps>");
  NumberOfSteps->printSelf(outFile);
  fprintf(outFile, "</NumberOfSteps>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

StepWithPredecessorsType::~StepWithPredecessorsType() {}

void StepWithPredecessorsType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"StepWithPredecessorsType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SequenceNumber>");
  SequenceNumber->printSelf(outFile);
  fprintf(outFile, "</SequenceNumber>\n");
  {
    std::list<XmlPositiveInteger *>::iterator iter;
    for (iter = Predecessor->begin(); iter != Predecessor->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Predecessor>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</Predecessor>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<PlanElement");
  PlanElement->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PlanElement>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTrayName>");
  KitTrayName->printSelf(outFile);
  fprintf(outFile, "</KitTrayName>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitName>");
  KitName->printSelf(outFile);
  fprintf(outFile, "</KitName>\n");
  doSpaces(-INDENT, outFile);
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
  doSpaces(0, outFile);
  fprintf(outFile, "<RobotName>");
  RobotName->printSelf(outFile);
  fprintf(outFile, "</RobotName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartName>");
  PartName->printSelf(outFile);
  fprintf(outFile, "</PartName>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

TestAndStepType::~TestAndStepType() {}

void TestAndStepType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"TestAndStepType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Test");
  Test->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Test>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Step");
  Step->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Step>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

TimesType::~TimesType() {}

void TimesType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"TimesType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A1");
  A1->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A1>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<A2");
  A2->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</A2>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

TrueType::~TrueType() {}

void TrueType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"TrueType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

UnorderedActionGroupType::~UnorderedActionGroupType() {}

void UnorderedActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"UnorderedActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  {
    std::list<PlanElementBaseType *>::iterator iter;
    for (iter = Step->begin(); iter != Step->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Step");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Step>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

VarSetType::~VarSetType() {}

void VarSetType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VarSetType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<VarName>");
  VarName->printSelf(outFile);
  fprintf(outFile, "</VarName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Val");
  Val->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Val>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

VarValType::~VarValType() {}

void VarValType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VarValType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<VarName>");
  VarName->printSelf(outFile);
  fprintf(outFile, "</VarName>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

VariableDeclarationType::~VariableDeclarationType() {}

void VariableDeclarationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VariableDeclarationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Val>");
  Val->printSelf(outFile);
  fprintf(outFile, "</Val>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

WhileActionGroupType::~WhileActionGroupType() {}

void WhileActionGroupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"WhileActionGroupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Test");
  Test->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Test>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Step");
  Step->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Step>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

XmlHeaderForKittingPlan::XmlHeaderForKittingPlan() {}

XmlHeaderForKittingPlan::XmlHeaderForKittingPlan(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForKittingPlan::~XmlHeaderForKittingPlan() {}

void XmlHeaderForKittingPlan::printSelf(
  FILE * outFile)
{
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

