/*********************************************************************/

/*

This is a version of kittingWorkstationClasses.cc for use with the
kittingViewer. The printSelf functions should be deleted since they
are obsolete and unused.

1. The six lists and a map immediately below and commands that populate them
(found in the constructors) are added.

2. The various convertUnits functions are added.

3. The constructors for PoseLocationType have been modified.

4. The normalize function is added.

5. The constructor for KittingWorkstationType is modified.

*/

#include <math.h>              // for sqrt
#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "kittingWorkstationClassesView.hh"
#include "kittingViewer.hh"
#define strncpy strncpy_s

#define INDENT 2

/*********************************************************************/
/*********************************************************************/

std::list<BoxyShapeType *> BoxyShapeType::allBoxys;
std::list<CylindricalShapeType *> CylindricalShapeType::allCyls;
std::list<KitType *> KitType::allKits;
std::list<VacuumEffectorMultiCupType *> VacuumEffectorMultiCupType::allMulti;
std::list<PointType *> PointType::allPoints;
std::list<VacuumEffectorSingleCupType *> VacuumEffectorSingleCupType::allSingle;
std::list<StockKeepingUnitType *> StockKeepingUnitType::allSkus;
std::map<std::string, SolidObjectType *> SolidObjectType::objectMap;

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

void KittingWorkstationFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<KittingWorkstation\n");
  header->printSelf(outFile);
  KittingWorkstation->printSelf(outFile);
  fprintf(outFile, "</KittingWorkstation>\n");
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

void AngleUnitType::printSelf(FILE * outFile)
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
  printTypp = false;
}

BoxVolumeType::~BoxVolumeType() {}

void BoxVolumeType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BoxVolumeType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumPoint");
  MaximumPoint->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</MaximumPoint>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MinimumPoint");
  MinimumPoint->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</MinimumPoint>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
  allBoxys.push_back(this);
}

BoxyShapeType::~BoxyShapeType() {}

void BoxyShapeType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BoxyShapeType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (GraspPose)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<GraspPose");
      GraspPose->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</GraspPose>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Length>");
  Length->printSelf(outFile);
  fprintf(outFile, "</Length>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Width>");
  Width->printSelf(outFile);
  fprintf(outFile, "</Width>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Height>");
  Height->printSelf(outFile);
  fprintf(outFile, "</Height>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<HasTop>");
  HasTop->printSelf(outFile);
  fprintf(outFile, "</HasTop>\n");
  doSpaces(-INDENT, outFile);
}

void BoxyShapeType::convertUnits(
 double lengthFactor)
{
  Length->val *= lengthFactor;
  Width->val *= lengthFactor;
  Height->val *= lengthFactor;
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
  printTypp = false;
  allCyls.push_back(this);
}

CylindricalShapeType::~CylindricalShapeType() {}

void CylindricalShapeType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"CylindricalShapeType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (GraspPose)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<GraspPose");
      GraspPose->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</GraspPose>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Diameter>");
  Diameter->printSelf(outFile);
  fprintf(outFile, "</Diameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Height>");
  Height->printSelf(outFile);
  fprintf(outFile, "</Height>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<HasTop>");
  HasTop->printSelf(outFile);
  fprintf(outFile, "</HasTop>\n");
  doSpaces(-INDENT, outFile);
}

void CylindricalShapeType::convertUnits(
 double lengthFactor)
{
  Diameter->val *= lengthFactor;
  Height->val *= lengthFactor;
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

void DataThingType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

EndEffectorChangingStationType::~EndEffectorChangingStationType() {}

void EndEffectorChangingStationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"EndEffectorChangingStationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
	 iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Base");
  Base->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Base>\n");
  {
    std::list<EndEffectorHolderType *>::iterator iter;
    for (iter = EndEffectorHolder->begin();
	 iter != EndEffectorHolder->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<EndEffectorHolder");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</EndEffectorHolder>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

EndEffectorHolderType::~EndEffectorHolderType() {}

void EndEffectorHolderType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"EndEffectorHolderType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  if (EndEffector)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<EndEffector");
      EndEffector->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</EndEffector>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

EndEffectorType::~EndEffectorType() {}

void EndEffectorType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"EndEffectorType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Weight>");
  Weight->printSelf(outFile);
  fprintf(outFile, "</Weight>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumLoadWeight>");
  MaximumLoadWeight->printSelf(outFile);
  fprintf(outFile, "</MaximumLoadWeight>\n");
  if (HeldObject)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<HeldObject");
      HeldObject->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</HeldObject>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

ExternalShapeType::~ExternalShapeType() {}

void ExternalShapeType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ExternalShapeType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (GraspPose)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<GraspPose");
      GraspPose->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</GraspPose>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<ModelFormatName>");
  ModelFormatName->printSelf(outFile);
  fprintf(outFile, "</ModelFormatName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ModelFileName>");
  ModelFileName->printSelf(outFile);
  fprintf(outFile, "</ModelFileName>\n");
  if (ModelName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ModelName>");
      ModelName->printSelf(outFile);
      fprintf(outFile, "</ModelName>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

GripperEffectorType::~GripperEffectorType() {}

void GripperEffectorType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"GripperEffectorType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Weight>");
  Weight->printSelf(outFile);
  fprintf(outFile, "</Weight>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumLoadWeight>");
  MaximumLoadWeight->printSelf(outFile);
  fprintf(outFile, "</MaximumLoadWeight>\n");
  if (HeldObject)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<HeldObject");
      HeldObject->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</HeldObject>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

HumanType::~HumanType() {}

void HumanType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"HumanType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

InternalShapeType::~InternalShapeType() {}

void InternalShapeType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"InternalShapeType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (GraspPose)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<GraspPose");
      GraspPose->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</GraspPose>\n");
    }
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

KitDesignType::~KitDesignType() {}

void KitDesignType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"KitDesignType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTraySkuName>");
  KitTraySkuName->printSelf(outFile);
  fprintf(outFile, "</KitTraySkuName>\n");
  {
    std::list<PartRefAndPoseType *>::iterator iter;
    for (iter = PartRefAndPose->begin(); iter != PartRefAndPose->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<PartRefAndPose");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</PartRefAndPose>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

KitTrayType::~KitTrayType() {}

void KitTrayType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"KitTrayType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SerialNumber>");
  SerialNumber->printSelf(outFile);
  fprintf(outFile, "</SerialNumber>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
  allKits.push_back(this);
}

KitType::~KitType() {}

void KitType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"KitType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<DesignName>");
  DesignName->printSelf(outFile);
  fprintf(outFile, "</DesignName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<KitTray");
  KitTray->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</KitTray>\n");
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin(); iter != Part->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Part");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Part>\n");
      }
  }
  {
    std::list<SlotType *>::iterator iter;
    for (iter = Slot->begin(); iter != Slot->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Slot");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Slot>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<Finished>");
  Finished->printSelf(outFile);
  fprintf(outFile, "</Finished>\n");
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class KittingWorkstationType

See documentation of this class in kittingWorkstationClassesView.hh.

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
  printTypp = false;
  
  allBoxys = BoxyShapeType::allBoxys;
  allCyls = CylindricalShapeType::allCyls;
  allIDs = XmlID::allIDs;
  allIDREFs = XmlIDREF::allIDREFs;
  allKits = KitType::allKits;
  allMulti = VacuumEffectorMultiCupType::allMulti;
  allPoints = PointType::allPoints;
  allSingle = VacuumEffectorSingleCupType::allSingle;
  allSkus = StockKeepingUnitType::allSkus;
  allSolids = SolidObjectType::objectMap;
}

KittingWorkstationType::~KittingWorkstationType() {}

void KittingWorkstationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"KittingWorkstationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<AngleUnit>");
  AngleUnit->printSelf(outFile);
  fprintf(outFile, "</AngleUnit>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ChangingStation");
  ChangingStation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ChangingStation>\n");
  {
    std::list<KitDesignType *>::iterator iter;
    for (iter = KitDesign->begin(); iter != KitDesign->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<KitDesign");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</KitDesign>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<LengthUnit>");
  LengthUnit->printSelf(outFile);
  fprintf(outFile, "</LengthUnit>\n");
  {
    std::list<SolidObjectType *>::iterator iter;
    for (iter = Object->begin(); iter != Object->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Object");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Object>\n");
      }
  }
  {
    std::list<BoxVolumeType *>::iterator iter;
    for (iter = OtherObstacle->begin(); iter != OtherObstacle->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<OtherObstacle");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</OtherObstacle>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<Robot");
  Robot->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Robot>\n");
  {
    std::list<StockKeepingUnitType *>::iterator iter;
    for (iter = Sku->begin(); iter != Sku->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Sku");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Sku>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<WeightUnit>");
  WeightUnit->printSelf(outFile);
  fprintf(outFile, "</WeightUnit>\n");
  doSpaces(0, outFile);
  doSpaces(-INDENT, outFile);
}

/*

convertUnits sets the the workstation length unit and the workstation
factors for units. Then it adjusts all workstation quantities that
have units. The internal units for the kittingViewer are millimeters,
grams, and degrees. This function should be called after the file of
initial workstation conditions has been read in (since it assumes
values have not yet been converted) but before any drawing is done
(since the drawers assume internal units).

Note that the robot has its own length units and length factor.
Converting positions in robot commands is done elsewhere.

*/

void KittingWorkstationType::convertUnits(
 bool setFactors)
{
  std::list<PointType *>::iterator pointIter;
  std::list<BoxyShapeType *>::iterator boxyIter;
  std::list<CylindricalShapeType *>::iterator cylIter;
  std::list<StockKeepingUnitType *>::iterator skuIter;
  std::list<VacuumEffectorMultiCupType *>::iterator multiIter;
  std::list<VacuumEffectorSingleCupType *>::iterator singlIter;

  if (setFactors)
    { // factors are set when reading the init file
      if (AngleUnit->val == "degree")
	{
	  strncpy(KittingViewer::angleUnits, "degree", TEXTSIZE);
	  KittingViewer::angleFactor = 1.0;
	}
      else if (AngleUnit->val == "radian")
	{
	  strncpy(KittingViewer::angleUnits, "radian", TEXTSIZE);
	  KittingViewer::angleFactor = 57.29577951308232;
	}
      else
	{
	  fprintf(stderr, "bad value %s for angle unit. Exiting\n",
		  AngleUnit->val.c_str());
	  exit(1);
	}
      if (LengthUnit->val == "millimeter")
	{
	  strncpy(KittingViewer::lengthUnits, "millimeter", TEXTSIZE);
	  KittingViewer::lengthFactor = 1.0;
	}
      else if (LengthUnit->val == "meter")
	{
	  strncpy(KittingViewer::lengthUnits, "meter", TEXTSIZE);
	  KittingViewer::lengthFactor = 1000.0;
	}
      else if (LengthUnit->val == "inch")
	{
	  strncpy(KittingViewer::lengthUnits, "inch", TEXTSIZE);
	  KittingViewer::lengthFactor = 25.4;
	}
      else
	{
	  fprintf(stderr, "bad value %s for length unit. Exiting\n",
		  LengthUnit->val.c_str());
	  exit(1);
	}
      if (WeightUnit->val == "kilogram")
	{
	  strncpy(KittingViewer::weightUnits, "kilogram", TEXTSIZE);
	  KittingViewer::weightFactor = 1000.0;
	}
      else if (WeightUnit->val == "gram")
	{
	  strncpy(KittingViewer::weightUnits, "gram", TEXTSIZE);
	  KittingViewer::weightFactor = 1.00;
	}
      else if (WeightUnit->val == "milligram")
	{
	  strncpy(KittingViewer::weightUnits, "milligram", TEXTSIZE);
	  KittingViewer::weightFactor = 0.001;
	}
      else if (WeightUnit->val == "pound")
	{
	  strncpy(KittingViewer::weightUnits, "pound", TEXTSIZE);
	  KittingViewer::weightFactor = 453.6;
	}
      else if (WeightUnit->val == "ounce")
	{
	  strncpy(KittingViewer::weightUnits, "ounce", TEXTSIZE);
	  KittingViewer::weightFactor = 28.35;
	}
      else
	{
	  fprintf(stderr, "bad value %s for weight unit. Exiting\n",
		  WeightUnit->val.c_str());
	  exit(1);
	}
      Robot->MaximumLoadWeight->val *= KittingViewer::weightFactor;
    }
  else
    {
      if (AngleUnit->val == "degree")
	{
	  if (KittingViewer::angleFactor != 1.0)
	    {
	      fprintf(stderr, "goal and init angle units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (AngleUnit->val == "radian")
	{
	  if (KittingViewer::angleFactor != 57.29577951308232)
	    {
	      fprintf(stderr, "goal and init angle units differ. Exiting\n");
	      exit(1);
	    }
	}
      else
	{
	  fprintf(stderr, "bad value %s for angle unit. Exiting\n",
		  AngleUnit->val.c_str());
	  exit(1);
	}
      if (LengthUnit->val == "millimeter")
	{
	  if (KittingViewer::lengthFactor != 1.0)
	    {
	      fprintf(stderr, "goal and init length units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (LengthUnit->val == "meter")
	{
	  if (KittingViewer::lengthFactor != 1000.0)
	    {
	      fprintf(stderr, "goal and init length units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (LengthUnit->val == "inch")
	{
	  if (KittingViewer::lengthFactor != 25.4)
	    {
	      fprintf(stderr, "goal and init length units differ. Exiting\n");
	      exit(1);
	    }
	}
      else
	{
	  fprintf(stderr, "bad value %s for length unit. Exiting\n",
		  LengthUnit->val.c_str());
	  exit(1);
	}
      if (WeightUnit->val == "kilogram")
	{
	  if (KittingViewer::weightFactor != 1000.0)
	    {
	      fprintf(stderr, "goal and init weight units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (WeightUnit->val == "gram")
	{
	  if (KittingViewer::weightFactor != 1.00)
	    {
	      fprintf(stderr, "goal and init weight units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (WeightUnit->val == "milligram")
	{
	  if (KittingViewer::weightFactor != 0.001)
	    {
	      fprintf(stderr, "goal and init weight units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (WeightUnit->val == "pound")
	{
	  if (KittingViewer::weightFactor != 453.6)
	    {
	      fprintf(stderr, "goal and init weight units differ. Exiting\n");
	      exit(1);
	    }
	}
      else if (WeightUnit->val == "ounce")
	{
	  if(KittingViewer::weightFactor != 28.35)
	    {
	      fprintf(stderr, "goal and init weight units differ. Exiting\n");
	      exit(1);
	    }
	}
      else
	{
	  fprintf(stderr, "bad value %s for weight unit. Exiting\n",
		  WeightUnit->val.c_str());
	  exit(1);
	}
      if ((Robot->MaximumLoadWeight->val * KittingViewer::weightFactor) !=
	  KittingViewer::nowModel->Robot->MaximumLoadWeight->val)
	{
	  fprintf(stderr, "goal and init Robot MaximumLoadWeight differ."
		  " Exiting\n");
	  exit(1);
	}
    }
  for (pointIter = allPoints.begin(); pointIter != allPoints.end(); pointIter++)
    (*pointIter)->convertUnits(KittingViewer::lengthFactor);
  for (boxyIter = allBoxys.begin(); boxyIter != allBoxys.end(); boxyIter++)
    (*boxyIter)->convertUnits(KittingViewer::lengthFactor);
  for (cylIter = allCyls.begin(); cylIter != allCyls.end(); cylIter++)
    (*cylIter)->convertUnits(KittingViewer::lengthFactor);
  for (skuIter = allSkus.begin(); skuIter != allSkus.end(); skuIter++)
    (*skuIter)->convertUnits(KittingViewer::weightFactor);
  for (multiIter = allMulti.begin(); multiIter != allMulti.end(); multiIter++)
    (*multiIter)->convertUnits(KittingViewer::lengthFactor,
			       KittingViewer::weightFactor);
  for (singlIter = allSingle.begin(); singlIter != allSingle.end(); singlIter++)
    (*singlIter)->convertUnits(KittingViewer::lengthFactor,
			       KittingViewer::weightFactor);
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
  printTypp = false;
}

LargeBoxWithEmptyKitTraysType::~LargeBoxWithEmptyKitTraysType() {}

void LargeBoxWithEmptyKitTraysType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"LargeBoxWithEmptyKitTraysType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<LargeContainer");
  LargeContainer->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</LargeContainer>\n");
  {
    std::list<KitTrayType *>::iterator iter;
    for (iter = KitTray->begin(); iter != KitTray->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<KitTray");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</KitTray>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

LargeBoxWithKitsType::~LargeBoxWithKitsType() {}

void LargeBoxWithKitsType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"LargeBoxWithKitsType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<LargeContainer");
  LargeContainer->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</LargeContainer>\n");
  {
    std::list<KitType *>::iterator iter;
    for (iter = Kit->begin(); iter != Kit->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Kit");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Kit>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<KitDesignName>");
  KitDesignName->printSelf(outFile);
  fprintf(outFile, "</KitDesignName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Capacity>");
  Capacity->printSelf(outFile);
  fprintf(outFile, "</Capacity>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

LargeContainerType::~LargeContainerType() {}

void LargeContainerType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"LargeContainerType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SerialNumber>");
  SerialNumber->printSelf(outFile);
  fprintf(outFile, "</SerialNumber>\n");
  doSpaces(-INDENT, outFile);
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

void LengthUnitType::printSelf(FILE * outFile)
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
  printTypp = false;
}

MechanicalComponentType::~MechanicalComponentType() {}

void MechanicalComponentType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"MechanicalComponentType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

NoSkuObjectType::~NoSkuObjectType() {}

void NoSkuObjectType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"NoSkuObjectType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartRefAndPoseType::~PartRefAndPoseType() {}

void PartRefAndPoseType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartRefAndPoseType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Point");
  Point->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Point>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<XAxis");
  XAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</XAxis>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ZAxis");
  ZAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ZAxis>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartType::~PartType() {}

void PartType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SerialNumber>");
  SerialNumber->printSelf(outFile);
  fprintf(outFile, "</SerialNumber>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartsBinType::~PartsBinType() {}

void PartsBinType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartsBinType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SerialNumber>");
  SerialNumber->printSelf(outFile);
  fprintf(outFile, "</SerialNumber>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartSkuName>");
  PartSkuName->printSelf(outFile);
  fprintf(outFile, "</PartSkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartQuantity>");
  PartQuantity->printSelf(outFile);
  fprintf(outFile, "</PartQuantity>\n");
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin(); iter != Part->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Part");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Part>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartsTrayType::~PartsTrayType() {}

void PartsTrayType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartsTrayType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SerialNumber>");
  SerialNumber->printSelf(outFile);
  fprintf(outFile, "</SerialNumber>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartSkuName>");
  PartSkuName->printSelf(outFile);
  fprintf(outFile, "</PartSkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartQuantity>");
  PartQuantity->printSelf(outFile);
  fprintf(outFile, "</PartQuantity>\n");
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin(); iter != Part->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Part");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Part>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PartsVesselType::~PartsVesselType() {}

void PartsVesselType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartsVesselType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<SerialNumber>");
  SerialNumber->printSelf(outFile);
  fprintf(outFile, "</SerialNumber>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartSkuName>");
  PartSkuName->printSelf(outFile);
  fprintf(outFile, "</PartSkuName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartQuantity>");
  PartQuantity->printSelf(outFile);
  fprintf(outFile, "</PartQuantity>\n");
  {
    std::list<PartType *>::iterator iter;
    for (iter = Part->begin(); iter != Part->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<Part");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</Part>\n");
      }
  }
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

PhysicalLocationType::~PhysicalLocationType() {}

void PhysicalLocationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PhysicalLocationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
  allPoints.push_back(this);
}

PointType::~PointType() {}

void PointType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PointType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<X>");
  X->printSelf(outFile);
  fprintf(outFile, "</X>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Y>");
  Y->printSelf(outFile);
  fprintf(outFile, "</Y>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Z>");
  Z->printSelf(outFile);
  fprintf(outFile, "</Z>\n");
  doSpaces(-INDENT, outFile);
}

void PointType::convertUnits(
 double lengthFactor)
{
  X->val *= lengthFactor;
  Y->val *= lengthFactor;
  Z->val *= lengthFactor;
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
  printTypp = false;
}

PoseLocationInType::~PoseLocationInType() {}

void PoseLocationInType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PoseLocationInType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Point");
  Point->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Point>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<XAxis");
  XAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</XAxis>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ZAxis");
  ZAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ZAxis>\n");
  if (PositionStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<PositionStandardDeviation>");
      PositionStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</PositionStandardDeviation>\n");
    }
  if (OrientationStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<OrientationStandardDeviation>");
      OrientationStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</OrientationStandardDeviation>\n");
    }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

PoseLocationOnType::~PoseLocationOnType() {}

void PoseLocationOnType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PoseLocationOnType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Point");
  Point->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Point>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<XAxis");
  XAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</XAxis>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ZAxis");
  ZAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ZAxis>\n");
  if (PositionStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<PositionStandardDeviation>");
      PositionStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</PositionStandardDeviation>\n");
    }
  if (OrientationStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<OrientationStandardDeviation>");
      OrientationStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</OrientationStandardDeviation>\n");
    }
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class PoseLocationType

The constructor taking no arguments creates a default pose in the
usual location with a null Name and a null refObjectName. The origin
and axes are created with "new", so this may leak memory.

The constructor taking arguments normalizes the XAxis and ZAxis
vectors and checks that they are orthogonal by checking that the the
cross product has a length close to 1. If the length of an axis vector
is zero or the vectors are not orthogonal, this prints an error
message and exits.

The destructor is not destructing the point or axes. It might be good
to make the destructor do that.

*/

PoseLocationType::PoseLocationType()
{ // details added, was {}
  Name = 0;
  RefObjectName = 0;
  Point = new PointType(0, new XmlDecimal(0.0),
			new XmlDecimal(0.0), new XmlDecimal(0.0));
  XAxis = new VectorType(0, new XmlDecimal(1.0),
			 new XmlDecimal(0.0), new XmlDecimal(0.0));
  ZAxis = new VectorType(0, new XmlDecimal(0.0),
			 new XmlDecimal(0.0), new XmlDecimal(1.0));
}

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
  XAxis->normalize();
  ZAxis->normalize();
  double xi = XAxis->I->val;
  double xj = XAxis->J->val;
  double xk = XAxis->K->val;
  double zi = ZAxis->I->val;
  double zj = ZAxis->J->val;
  double zk = ZAxis->K->val;
  double yi = ((zj * xk) - (xj * zk));
  double yj = ((zk * xi) - (xk * zi));
  double yk = ((zi * xj) - (xi * zj));
  double length = sqrt((yi * yi) + (yj * yj) + (yk * yk));
  if ((length > 1.0000001) || (length < 0.9999999))
    {
      fprintf(stderr,
	      "in Pose %s, X axis and Z axis are not orthogonal; exiting\n",
	      (Name ? Name->val.c_str() : "unnamed"));
      exit(1);
    }
  printTypp = false;
}

PoseLocationType::~PoseLocationType() {}

void PoseLocationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PoseLocationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Point");
  Point->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Point>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<XAxis");
  XAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</XAxis>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ZAxis");
  ZAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ZAxis>\n");
  if (PositionStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<PositionStandardDeviation>");
      PositionStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</PositionStandardDeviation>\n");
    }
  if (OrientationStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<OrientationStandardDeviation>");
      OrientationStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</OrientationStandardDeviation>\n");
    }
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

PoseOnlyLocationType::~PoseOnlyLocationType() {}

void PoseOnlyLocationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PoseOnlyLocationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Point");
  Point->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Point>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<XAxis");
  XAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</XAxis>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ZAxis");
  ZAxis->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</ZAxis>\n");
  if (PositionStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<PositionStandardDeviation>");
      PositionStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</PositionStandardDeviation>\n");
    }
  if (OrientationStandardDeviation)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<OrientationStandardDeviation>");
      OrientationStandardDeviation->printSelf(outFile);
      fprintf(outFile, "</OrientationStandardDeviation>\n");
    }
  doSpaces(-INDENT, outFile);
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

void PositiveDecimalType::printSelf(FILE * outFile)
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
  printTypp = false;
}

RelativeLocationInType::~RelativeLocationInType() {}

void RelativeLocationInType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"RelativeLocationInType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

RelativeLocationOnType::~RelativeLocationOnType() {}

void RelativeLocationOnType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"RelativeLocationOnType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

RelativeLocationType::~RelativeLocationType() {}

void RelativeLocationType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"RelativeLocationType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<RefObjectName>");
  RefObjectName->printSelf(outFile);
  fprintf(outFile, "</RefObjectName>\n");
  if (Timestamp)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<Timestamp>");
      Timestamp->printSelf(outFile);
      fprintf(outFile, "</Timestamp>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

RobotType::~RobotType() {}

void RobotType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"RobotType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (EndEffector)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<EndEffector");
      EndEffector->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</EndEffector>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumLoadWeight>");
  MaximumLoadWeight->printSelf(outFile);
  fprintf(outFile, "</MaximumLoadWeight>\n");
  {
    std::list<BoxVolumeType *>::iterator iter;
    for (iter = WorkVolume->begin(); iter != WorkVolume->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<WorkVolume");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</WorkVolume>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

ShapeDesignType::~ShapeDesignType() {}

void ShapeDesignType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"ShapeDesignType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (GraspPose)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<GraspPose");
      GraspPose->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</GraspPose>\n");
    }
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

SkuObjectType::~SkuObjectType() {}

void SkuObjectType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SkuObjectType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(0, outFile);
  fprintf(outFile, "<SkuName>");
  SkuName->printSelf(outFile);
  fprintf(outFile, "</SkuName>\n");
  doSpaces(-INDENT, outFile);
}

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
  printTypp = false;
}

SlotType::~SlotType() {}

void SlotType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"SlotType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PartRefAndPoseName>");
  PartRefAndPoseName->printSelf(outFile);
  fprintf(outFile, "</PartRefAndPoseName>\n");
  if (PartName)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<PartName>");
      PartName->printSelf(outFile);
      fprintf(outFile, "</PartName>\n");
    }
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

/* class SolidObjectType

The objectMap is not being checked for duplicates because the Name is an
XmlID, and the constructor for XmlIDs checks for duplicates.

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
  objectMap.insert(std::pair<std::string, SolidObjectType *>(Name->val, this));
  refThing = 0;
}

SolidObjectType::~SolidObjectType() {}

void SolidObjectType::printSelf(FILE * outFile)
{
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin();
	 iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
  color.g = 0.0f; // added
  allSkus.push_back(this); // added
}

StockKeepingUnitType::~StockKeepingUnitType() {}

void StockKeepingUnitType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"StockKeepingUnitType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Weight>");
  Weight->printSelf(outFile);
  fprintf(outFile, "</Weight>\n");
  {
    std::list<XmlIDREF *>::iterator iter;
    for (iter = EndEffectorName->begin(); iter != EndEffectorName->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<EndEffectorName>");
        (*iter)->printSelf(outFile);
        fprintf(outFile, "</EndEffectorName>\n");
      }
  }
  doSpaces(-INDENT, outFile);
}

void StockKeepingUnitType::convertUnits(
 double weightFactor)
{
  Weight->val *= weightFactor;
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
  printTypp = false;
  allMulti.push_back(this);     // added
}

VacuumEffectorMultiCupType::~VacuumEffectorMultiCupType() {}

void VacuumEffectorMultiCupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VacuumEffectorMultiCupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Weight>");
  Weight->printSelf(outFile);
  fprintf(outFile, "</Weight>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumLoadWeight>");
  MaximumLoadWeight->printSelf(outFile);
  fprintf(outFile, "</MaximumLoadWeight>\n");
  if (HeldObject)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<HeldObject");
      HeldObject->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</HeldObject>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<CupDiameter>");
  CupDiameter->printSelf(outFile);
  fprintf(outFile, "</CupDiameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Length>");
  Length->printSelf(outFile);
  fprintf(outFile, "</Length>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ArrayNumber>");
  ArrayNumber->printSelf(outFile);
  fprintf(outFile, "</ArrayNumber>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<ArrayRadius>");
  ArrayRadius->printSelf(outFile);
  fprintf(outFile, "</ArrayRadius>\n");
  doSpaces(-INDENT, outFile);
}

void VacuumEffectorMultiCupType::convertUnits(
 double lengthFactor,
 double weightFactor)
{
  Weight->val *= weightFactor;
  MaximumLoadWeight->val *= weightFactor;
  CupDiameter->val *= lengthFactor;
  Length->val *= lengthFactor;
  ArrayRadius->val *= lengthFactor;
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
  printTypp = false;
  allSingle.push_back(this);
}

VacuumEffectorSingleCupType::~VacuumEffectorSingleCupType() {}

void VacuumEffectorSingleCupType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VacuumEffectorSingleCupType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Weight>");
  Weight->printSelf(outFile);
  fprintf(outFile, "</Weight>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumLoadWeight>");
  MaximumLoadWeight->printSelf(outFile);
  fprintf(outFile, "</MaximumLoadWeight>\n");
  if (HeldObject)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<HeldObject");
      HeldObject->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</HeldObject>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<CupDiameter>");
  CupDiameter->printSelf(outFile);
  fprintf(outFile, "</CupDiameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Length>");
  Length->printSelf(outFile);
  fprintf(outFile, "</Length>\n");
  doSpaces(-INDENT, outFile);
}

void VacuumEffectorSingleCupType::convertUnits(
 double lengthFactor,
 double weightFactor)
{
  Weight->val *= weightFactor;
  MaximumLoadWeight->val *= weightFactor;
  CupDiameter->val *= lengthFactor;
  Length->val *= lengthFactor;
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
  printTypp = false;
}

VacuumEffectorType::~VacuumEffectorType() {}

void VacuumEffectorType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VacuumEffectorType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<Description>");
  Description->printSelf(outFile);
  fprintf(outFile, "</Description>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Weight>");
  Weight->printSelf(outFile);
  fprintf(outFile, "</Weight>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<MaximumLoadWeight>");
  MaximumLoadWeight->printSelf(outFile);
  fprintf(outFile, "</MaximumLoadWeight>\n");
  if (HeldObject)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<HeldObject");
      HeldObject->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</HeldObject>\n");
    }
  doSpaces(0, outFile);
  fprintf(outFile, "<CupDiameter>");
  CupDiameter->printSelf(outFile);
  fprintf(outFile, "</CupDiameter>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Length>");
  Length->printSelf(outFile);
  fprintf(outFile, "</Length>\n");
  doSpaces(-INDENT, outFile);
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
  printTypp = false;
}

VectorType::~VectorType() {}

void VectorType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"VectorType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<I>");
  I->printSelf(outFile);
  fprintf(outFile, "</I>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<J>");
  J->printSelf(outFile);
  fprintf(outFile, "</J>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<K>");
  K->printSelf(outFile);
  fprintf(outFile, "</K>\n");
  doSpaces(-INDENT, outFile);
}

void VectorType::normalize()
{
  double length;
  double i;
  double j;
  double k;
  i = I->val;
  j = J->val;
  k = K->val;
  length = sqrt((i*i) + (j*j) + (k*k));
  if (length == 0.0)
    {
      fprintf(stderr, "cannot normalize zero length vector %s; exiting\n",
	      (Name ? Name->val.c_str() : "unnamed"));
      exit(1);
    }
  else
    {
      I->val = i/length;
      J->val = j/length;
      K->val = k/length;
    }
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

void WeightUnitType::printSelf(FILE * outFile)
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
  printTypp = false;
}

WorkTableType::~WorkTableType() {}

void WorkTableType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"WorkTableType\"");
  fprintf(outFile, ">\n");
  doSpaces(+INDENT, outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "<Name>");
  Name->printSelf(outFile);
  fprintf(outFile, "</Name>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<PrimaryLocation");
  PrimaryLocation->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PrimaryLocation>\n");
  {
    std::list<PhysicalLocationType *>::iterator iter;
    for (iter = SecondaryLocation->begin(); iter != SecondaryLocation->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SecondaryLocation");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SecondaryLocation>\n");
      }
  }
  if (InternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<InternalShape");
      InternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</InternalShape>\n");
    }
  if (ExternalShape)
    {
      doSpaces(0, outFile);
      fprintf(outFile, "<ExternalShape");
      ExternalShape->printSelf(outFile);
      doSpaces(0, outFile);
      fprintf(outFile, "</ExternalShape>\n");
    }
  {
    std::list<SolidObjectType *>::iterator iter;
    for (iter = ObjectOnTable->begin(); iter != ObjectOnTable->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<ObjectOnTable");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</ObjectOnTable>\n");
      }
  }
  doSpaces(-INDENT, outFile);
}

/*********************************************************************/

XmlHeaderForKittingWorkstation::XmlHeaderForKittingWorkstation() {}

XmlHeaderForKittingWorkstation::XmlHeaderForKittingWorkstation(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForKittingWorkstation::~XmlHeaderForKittingWorkstation() {}

void XmlHeaderForKittingWorkstation::printSelf(
  FILE * outFile)
{
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

