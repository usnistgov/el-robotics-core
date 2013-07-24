/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "kittingClasses.hh"

#define INDENT 2

/*********************************************************************/
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
  SolidObjectType(
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
  fprintf(outFile, "<Base");
  Base->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Base>\n");
  {
    std::list<EndEffectorHolderType *>::iterator iter;
    for (iter = EndEffectorHolder->begin(); iter != EndEffectorHolder->end(); iter++)
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
  SolidObjectType(
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
  SolidObjectType(
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
 XmlString * ModelTypeNameIn,
 XmlString * ModelFileNameIn,
 XmlString * ModelNameIn) :
  ShapeDesignType(
    NameIn,
    DescriptionIn,
    GraspPoseIn)
{
  ModelTypeName = ModelTypeNameIn;
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
  fprintf(outFile, "<ModelTypeName>");
  ModelTypeName->printSelf(outFile);
  fprintf(outFile, "</ModelTypeName>\n");
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
  SolidObjectType(
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
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  SkuName = SkuNameIn;
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
  SolidObjectType(
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
  SolidObjectType(
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
  doSpaces(-INDENT, outFile);
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
  SolidObjectType(
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
  SolidObjectType(
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
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  SkuName = SkuNameIn;
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
  SolidObjectType(
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
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  SkuName = SkuNameIn;
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
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn,
 XmlIDREF * PartSkuNameIn,
 XmlNonNegativeInteger * PartQuantityIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  SkuName = SkuNameIn;
  SerialNumber = SerialNumberIn;
  PartSkuName = PartSkuNameIn;
  PartQuantity = PartQuantityIn;
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
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  SkuName = SkuNameIn;
  SerialNumber = SerialNumberIn;
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

/* class PartsTrayWithPartsType

*/

PartsTrayWithPartsType::PartsTrayWithPartsType() {}

PartsTrayWithPartsType::PartsTrayWithPartsType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn,
 PartsTrayType * PartsTrayIn,
 std::list<PartType *> * PartIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  PartsTray = PartsTrayIn;
  Part = PartIn;
  printTypp = false;
}

PartsTrayWithPartsType::~PartsTrayWithPartsType() {}

void PartsTrayWithPartsType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"PartsTrayWithPartsType\"");
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
  fprintf(outFile, "<PartsTray");
  PartsTray->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</PartsTray>\n");
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
  SolidObjectType(
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

*/

SolidObjectType::SolidObjectType() {}

SolidObjectType::SolidObjectType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 InternalShapeType * InternalShapeIn,
 ExternalShapeType * ExternalShapeIn)
{
  Name = NameIn;
  PrimaryLocation = PrimaryLocationIn;
  SecondaryLocation = SecondaryLocationIn;
  InternalShape = InternalShapeIn;
  ExternalShape = ExternalShapeIn;
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

/* class StockKeepingUnitType

*/

StockKeepingUnitType::StockKeepingUnitType() {}

StockKeepingUnitType::StockKeepingUnitType(
 XmlID * NameIn,
 XmlString * DescriptionIn,
 ShapeDesignType * ShapeIn,
 PositiveDecimalType * WeightIn,
 std::list<XmlIDREF *> * EndEffectorNameIn) :
  DataThingType(
    NameIn)
{
  Description = DescriptionIn;
  Shape = ShapeIn;
  Weight = WeightIn;
  EndEffectorName = EndEffectorNameIn;
  printTypp = false;
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
  doSpaces(0, outFile);
  fprintf(outFile, "<Shape");
  Shape->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Shape>\n");
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
 std::list<SolidObjectType *> * SolidObjectIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    InternalShapeIn,
    ExternalShapeIn)
{
  SolidObject = SolidObjectIn;
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
    for (iter = SolidObject->begin(); iter != SolidObject->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<SolidObject");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</SolidObject>\n");
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

