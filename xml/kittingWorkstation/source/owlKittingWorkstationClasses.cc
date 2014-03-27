/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "owlInstancePrinter.hh"
#include "owlKittingWorkstationClasses.hh"

/*********************************************************************/
/*********************************************************************/

extern OwlInstancePrinter printer;

std::set<std::string> BoxVolumeType::individuals;
std::set<std::string> BoxyShapeType::individuals;
std::set<std::string> CylindricalShapeType::individuals;
std::set<std::string> EndEffectorChangingStationType::individuals;
std::set<std::string> EndEffectorHolderType::individuals;
std::set<std::string> ExternalShapeType::individuals;
std::set<std::string> GripperEffectorType::individuals;
std::set<std::string> HumanType::individuals;
std::set<std::string> KitDesignType::individuals;
std::set<std::string> KitTrayType::individuals;
std::set<std::string> KitType::individuals;
std::set<std::string> KittingWorkstationType::individuals;
std::set<std::string> LargeBoxWithEmptyKitTraysType::individuals;
std::set<std::string> LargeBoxWithKitsType::individuals;
std::set<std::string> LargeContainerType::individuals;
std::set<std::string> MechanicalComponentType::individuals;
std::set<std::string> PartRefAndPoseType::individuals;
std::set<std::string> PartType::individuals;
std::set<std::string> PartsBinType::individuals;
std::set<std::string> PartsTrayType::individuals;
std::set<std::string> PointType::individuals;
std::set<std::string> PoseLocationInType::individuals;
std::set<std::string> PoseLocationOnType::individuals;
std::set<std::string> PoseOnlyLocationType::individuals;
std::set<std::string> RelativeLocationInType::individuals;
std::set<std::string> RelativeLocationOnType::individuals;
std::set<std::string> RobotType::individuals;
std::set<std::string> SlotType::individuals;
std::set<std::string> StockKeepingUnitType::individuals;
std::set<std::string> VacuumEffectorMultiCupType::individuals;
std::set<std::string> VacuumEffectorSingleCupType::individuals;
std::set<std::string> VectorType::individuals;
std::set<std::string> WorkTableType::individuals;

/*********************************************************************/

/* class KittingWorkstationFile

*/

KittingWorkstationFile::KittingWorkstationFile() {}

KittingWorkstationFile::KittingWorkstationFile(
  XmlVersion * versionIn,
  XmlHeaderForKittingWorkstation * headerIn,
  KittingWorkstationType * KittingWorkstationIn)
{
  version = versionIn;
  header = headerIn;
  KittingWorkstation = KittingWorkstationIn;
}

KittingWorkstationFile::~KittingWorkstationFile() {}

void KittingWorkstationFile::printOwl(FILE * outFile)
{
  std::set<std::string>::iterator iter;
  KittingWorkstation->printOwl(outFile);

  if (BoxVolumeType::individuals.size() > 1)
    printer.printIndividuals("ktw:BoxVolume",
       &BoxVolumeType::individuals, outFile);
  if (BoxyShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:BoxyShape",
       &BoxyShapeType::individuals, outFile);
  if (CylindricalShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:CylindricalShape",
       &CylindricalShapeType::individuals, outFile);
  if (EndEffectorChangingStationType::individuals.size() > 1)
    printer.printIndividuals("ktw:EndEffectorChangingStation",
       &EndEffectorChangingStationType::individuals, outFile);
  if (EndEffectorHolderType::individuals.size() > 1)
    printer.printIndividuals("ktw:EndEffectorHolder",
       &EndEffectorHolderType::individuals, outFile);
  if (ExternalShapeType::individuals.size() > 1)
    printer.printIndividuals("ktw:ExternalShape",
       &ExternalShapeType::individuals, outFile);
  if (GripperEffectorType::individuals.size() > 1)
    printer.printIndividuals("ktw:GripperEffector",
       &GripperEffectorType::individuals, outFile);
  if (HumanType::individuals.size() > 1)
    printer.printIndividuals("ktw:Human",
       &HumanType::individuals, outFile);
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
  if (PartRefAndPoseType::individuals.size() > 1)
    printer.printIndividuals("ktw:PartRefAndPose",
       &PartRefAndPoseType::individuals, outFile);
  if (PartType::individuals.size() > 1)
    printer.printIndividuals("ktw:Part",
       &PartType::individuals, outFile);
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
  if (StockKeepingUnitType::individuals.size() > 1)
    printer.printIndividuals("ktw:StockKeepingUnit",
       &StockKeepingUnitType::individuals, outFile);
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

/* class XmlHeaderForKittingWorkstation

*/

XmlHeaderForKittingWorkstation::XmlHeaderForKittingWorkstation() {}

XmlHeaderForKittingWorkstation::XmlHeaderForKittingWorkstation(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForKittingWorkstation::~XmlHeaderForKittingWorkstation() {}

void XmlHeaderForKittingWorkstation::printOwl(
  FILE * outFile)
{

}

/*********************************************************************/

