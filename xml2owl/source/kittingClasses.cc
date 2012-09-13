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

/* class KittingWorkStationFile

*/

KittingWorkStationFile::KittingWorkStationFile() {}

KittingWorkStationFile::KittingWorkStationFile(
  XmlVersion * versionIn,
  XmlHeaderForKittingWorkStation * headerIn,
  KittingWorkstationType * KittingWorkStationIn)
{
  version = versionIn;
  header = headerIn;
  KittingWorkStation = KittingWorkStationIn;
}

KittingWorkStationFile::~KittingWorkStationFile() {}

void KittingWorkStationFile::printSelf(FILE * outFile)
{
  version->printSelf(outFile);
  fprintf(outFile, "<KittingWorkStation\n");
  header->printSelf(outFile);
  KittingWorkStation->printSelf(outFile);
  fprintf(outFile, "</KittingWorkStation>\n");
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

/* class BoxyObjectType

*/

BoxyObjectType::BoxyObjectType() {}

BoxyObjectType::BoxyObjectType(
 XmlID * NameIn,
 PhysicalLocationType * PrimaryLocationIn,
 std::list<PhysicalLocationType *> * SecondaryLocationIn,
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  Length = LengthIn;
  Width = WidthIn;
  Height = HeightIn;
  printTypp = false;
}

BoxyObjectType::~BoxyObjectType() {}

void BoxyObjectType::printSelf(FILE * outFile)
{
  if (printTypp)
    fprintf(outFile, " xsi:type=\"BoxyObjectType\"");
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
 std::list<EndEffectorHolderType *> * EndEffectorHoldersIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  EndEffectorHolders = EndEffectorHoldersIn;
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
  {
    std::list<EndEffectorHolderType *>::iterator iter;
    for (iter = EndEffectorHolders->begin(); iter != EndEffectorHolders->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<EndEffectorHolders");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</EndEffectorHolders>\n");
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
 EndEffectorType * EndEffectorIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
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
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  Description = DescriptionIn;
  Weight = WeightIn;
  MaximumLoadWeight = MaximumLoadWeightIn;
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
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn) :
  EndEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn)
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
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  BoxyObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    LengthIn,
    WidthIn,
    HeightIn)
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
 XmlIDREF * DesignNameIn,
 KitTrayType * TrayIn,
 std::list<PartType *> * PartIn,
 XmlBoolean * FinishedIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  DesignName = DesignNameIn;
  Tray = TrayIn;
  Part = PartIn;
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
  doSpaces(0, outFile);
  fprintf(outFile, "<DesignName>");
  DesignName->printSelf(outFile);
  fprintf(outFile, "</DesignName>\n");
  doSpaces(0, outFile);
  fprintf(outFile, "<Tray");
  Tray->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</Tray>\n");
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
 AngleUnitType * AngleUnitIn,
 EndEffectorChangingStationType * ChangingStationIn,
 std::list<KitDesignType *> * KitDesignIn,
 LengthUnitType * LengthUnitIn,
 std::list<SolidObjectType *> * ObjectIn,
 std::list<BoxVolumeType *> * OtherObstacleIn,
 RobotType * RobotIn,
 std::list<StockKeepingUnitType *> * SkuIn,
 WeightUnitType * WeightUnitIn,
 WorkTableType * WorkTableIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
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
  WorkTable = WorkTableIn;
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
  fprintf(outFile, "<WorkTable");
  WorkTable->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</WorkTable>\n");
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
 LargeContainerType * LargeContainerIn,
 std::list<KitTrayType *> * KitTraysIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  LargeContainer = LargeContainerIn;
  KitTrays = KitTraysIn;
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
  doSpaces(0, outFile);
  fprintf(outFile, "<LargeContainer");
  LargeContainer->printSelf(outFile);
  doSpaces(0, outFile);
  fprintf(outFile, "</LargeContainer>\n");
  {
    std::list<KitTrayType *>::iterator iter;
    for (iter = KitTrays->begin(); iter != KitTrays->end(); iter++)
      {
        doSpaces(0, outFile);
        fprintf(outFile, "<KitTrays");
        (*iter)->printSelf(outFile);
        doSpaces(0, outFile);
        fprintf(outFile, "</KitTrays>\n");
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
 LargeContainerType * LargeContainerIn,
 std::list<KitType *> * KitIn,
 XmlIDREF * KitDesignNameIn,
 XmlPositiveInteger * CapacityIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
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
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  BoxyObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    LengthIn,
    WidthIn,
    HeightIn)
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
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
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
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn,
 XmlIDREF * PartSkuNameIn,
 XmlNonNegativeInteger * PartQuantityIn) :
  BoxyObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    LengthIn,
    WidthIn,
    HeightIn)
{
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
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn,
 XmlIDREF * SkuNameIn,
 XmlNMTOKEN * SerialNumberIn) :
  BoxyObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    LengthIn,
    WidthIn,
    HeightIn)
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
 PartsTrayType * PartsTrayIn,
 std::list<PartType *> * PartIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
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
 XmlIDREF * RefObjectIn) :
  DataThingType(
    NameIn)
{
  RefObject = RefObjectIn;
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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
 XmlIDREF * RefObjectIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn) :
  PoseLocationType(
    NameIn,
    RefObjectIn,
    PointIn,
    XAxisIn,
    ZAxisIn)
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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

/* class PoseLocationOnType

*/

PoseLocationOnType::PoseLocationOnType() {}

PoseLocationOnType::PoseLocationOnType(
 XmlID * NameIn,
 XmlIDREF * RefObjectIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn) :
  PoseLocationType(
    NameIn,
    RefObjectIn,
    PointIn,
    XAxisIn,
    ZAxisIn)
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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

/* class PoseLocationType

*/

PoseLocationType::PoseLocationType() {}

PoseLocationType::PoseLocationType(
 XmlID * NameIn,
 XmlIDREF * RefObjectIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn) :
  PhysicalLocationType(
    NameIn,
    RefObjectIn)
{
  Point = PointIn;
  XAxis = XAxisIn;
  ZAxis = ZAxisIn;
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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

/* class PoseOnlyLocationType

*/

PoseOnlyLocationType::PoseOnlyLocationType() {}

PoseOnlyLocationType::PoseOnlyLocationType(
 XmlID * NameIn,
 XmlIDREF * RefObjectIn,
 PointType * PointIn,
 VectorType * XAxisIn,
 VectorType * ZAxisIn) :
  PoseLocationType(
    NameIn,
    RefObjectIn,
    PointIn,
    XAxisIn,
    ZAxisIn)
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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
 XmlIDREF * RefObjectIn,
 XmlString * DescriptionIn) :
  RelativeLocationType(
    NameIn,
    RefObjectIn)
{
  Description = DescriptionIn;
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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
 XmlIDREF * RefObjectIn,
 XmlString * DescriptionIn) :
  RelativeLocationType(
    NameIn,
    RefObjectIn)
{
  Description = DescriptionIn;
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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
 XmlIDREF * RefObjectIn) :
  PhysicalLocationType(
    NameIn,
    RefObjectIn)
{
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
  fprintf(outFile, "<RefObject>");
  RefObject->printSelf(outFile);
  fprintf(outFile, "</RefObject>\n");
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
 XmlString * DescriptionIn,
 EndEffectorType * EndEffectorIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 std::list<BoxVolumeType *> * WorkVolumeIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
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
 XmlString * DescriptionIn) :
  DataThingType(
    NameIn)
{
  Description = DescriptionIn;
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
  doSpaces(-INDENT, outFile);
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
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 PositiveDecimalType * CupDiameterIn,
 PositiveDecimalType * LengthIn,
 XmlPositiveInteger * ArrayNumberIn,
 PositiveDecimalType * ArrayRadiusIn) :
  VacuumEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn,
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
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 PositiveDecimalType * CupDiameterIn,
 PositiveDecimalType * LengthIn) :
  VacuumEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn,
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
 XmlString * DescriptionIn,
 PositiveDecimalType * WeightIn,
 PositiveDecimalType * MaximumLoadWeightIn,
 PositiveDecimalType * CupDiameterIn,
 PositiveDecimalType * LengthIn) :
  EndEffectorType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    DescriptionIn,
    WeightIn,
    MaximumLoadWeightIn)
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
 PositiveDecimalType * LengthIn,
 PositiveDecimalType * WidthIn,
 PositiveDecimalType * HeightIn,
 std::list<SolidObjectType *> * SolidObjectIn) :
  BoxyObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn,
    LengthIn,
    WidthIn,
    HeightIn)
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

XmlHeaderForKittingWorkStation::XmlHeaderForKittingWorkStation() {}

XmlHeaderForKittingWorkStation::XmlHeaderForKittingWorkStation(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForKittingWorkStation::~XmlHeaderForKittingWorkStation() {}

void XmlHeaderForKittingWorkStation::printSelf(
  FILE * outFile)
{
  fprintf(outFile, "  xmlns=\"urn:kitting\"\n");
  fprintf(outFile,
          "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n");
  location->printSelf(outFile);
}

/*********************************************************************/

