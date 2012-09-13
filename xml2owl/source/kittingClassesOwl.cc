/* 

This file was prepared by starting with the kittingClasses.cc file
generated automatically by the GenXMiller and hand editing it severely.
All the printSelf functions for the classes defined in kittingClassesOwl.hh
were removed and replaced by hand-written printOwl functions.

All the functions in the OwlPrinter class were written from scratch.

This is a hierarchical descent printer where the printing follows the
hierarchy of the XML data file. The top level is
KittingWorkStationFile::printOwl

*/

/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include <boost/regex.hpp>
#include "xmlSchemaInstance.hh"
#include "kittingClassesOwl.hh"

/*********************************************************************/
/*********************************************************************/

std::list<XmlID *> OwlPrinter:: locationStack;
bool OwlPrinter::primary = false;
char OwlPrinter::inFileName[200];

std::set<std::string> BoxVolumeType::individuals;
std::set<std::string> EndEffectorHolderType::individuals;
std::set<std::string> GripperEffectorType::individuals;
std::set<std::string> KitDesignType::individuals;
std::set<std::string> KitTrayType::individuals;
std::set<std::string> LargeContainerType::individuals;
std::set<std::string> PartRefAndPoseType::individuals;
std::set<std::string> PartsBinType::individuals;
std::set<std::string> PartsTrayType::individuals;
std::set<std::string> PartsTrayWithPartsType::individuals;
std::set<std::string> PartType::individuals;
std::set<std::string> PointType::individuals;
std::set<std::string> PoseLocationInType::individuals;
std::set<std::string> PoseLocationOnType::individuals;
std::set<std::string> PoseOnlyLocationType::individuals;
std::set<std::string> RelativeLocationInType::individuals;
std::set<std::string> RelativeLocationOnType::individuals;
std::set<std::string> ShapeDesignType::individuals;
std::set<std::string> StockKeepingUnitType::individuals;
std::set<std::string> VacuumEffectorMultiCupType::individuals;
std::set<std::string> VacuumEffectorSingleCupType::individuals;
std::set<std::string> VectorType::individuals;

/*********************************************************************/
/*********************************************************************/

/* OwlPrinter::

This checks that the reference object, ref, for the location of an
object A is the same as the first entry on the locationStack, which is
what the reference object is supposed to be. Except as listed below,
ref has A as the value of an element. In the cases listed below, ref
is a sibling of A (i.e. they are both elements of another object).
   ref             name    parent
   ----            ----    ------
   Tray            Part    KitType
   LargeContainer  Trays   LargeBoxWithEmptyKitTraysType
   LargeContainer  Kit     LargeBoxWithKitsType
   Parts Tray      Parts   PartsTrayWithPartsType

If the check fails, this prints an error message and exits.

*/

void OwlPrinter::checkRefObject( /* ARGUMENTS                */
  std::string name,              /* name of A                */
  std::string ref)               /* name of reference object */
{
  if (primary)
    {
      if (strcmp(ref.c_str(), locationStack.front()->val.c_str()))
	{
	  fprintf(stderr, "RefObject for %s should be %s but is %s\n",
		  name.c_str(), locationStack.front()->val.c_str(),
		  ref.c_str());
	  exit(1);
	}
    }
}

/*********************************************************************/

/* OwlPrinter::endIndi

This prints a two-line comment that ends a set of related statements about
a named individual. For example:

// end LargeBoxWithEmptyKitTrays
//*****************************************

*/

void OwlPrinter::endIndi( /* ARGUMENTS          */
 const char * aType,      /* type of individual */
 FILE * outFile)          /* file to print in   */
{
  fprintf(outFile, "// end %s\n", aType);
  fprintf(outFile, "//*****************************************\n\n");
}

/*********************************************************************/

/* OwlPrinter::printIndividuals

This prints, for example:

//*****************************************
// VacuumEffectorSingleCup individuals 
DifferentIndividuals(
 :part_gripper
 :tray_gripper)

*/

void OwlPrinter::printIndividuals(    /* ARGUMENTS            */
 const char * typeName,               /* type of individuals  */
 std::set<std::string> * individuals, /* names of individuals */
 FILE * outFile)                      /* file to print in     */
{
  std::set<std::string>::iterator iter;

  fprintf(outFile, "\n//*****************************************\n");
  fprintf(outFile, "// %s individuals ", typeName);
  fprintf(outFile, "\n");
  fprintf(outFile,"DifferentIndividuals(\n");
  for (iter = individuals->begin(); iter != individuals->end(); )
    {
      fprintf(outFile, " :%s", iter->c_str());
      iter++;
      fprintf(outFile, "%s\n", (iter == individuals->end()) ? ")" : "");
    }
}

/*********************************************************************/

/* OwlPrinter::printLocations

This prints, for example:

ObjectPropertyAssertion(:hasSolidObject_PrimaryLocation :work_table_1 :work_table_pose)
Declaration(NamedIndividual(:work_table_pose))
ClassAssertion(:PoseOnlyLocation :work_table_pose)
ObjectPropertyAssertion(:hasPhysicalLocation_RefObject :work_table_pose :kitting_workstation_1)
ObjectPropertyAssertion(:hasPoseLocation_Point :work_table_pose :work_table_point)
ObjectPropertyAssertion(:hasPoseLocation_XAxis :work_table_pose :work_table_x_axis)
ObjectPropertyAssertion(:hasPoseLocation_ZAxis :work_table_pose :work_table_z_axis)
Declaration(NamedIndividual(:work_table_point))
ClassAssertion(:Point :work_table_point)
DataPropertyAssertion(:hasPoint_X :work_table_point "3.000000"^^xsd:decimal)
DataPropertyAssertion(:hasPoint_Y :work_table_point "0.000000"^^xsd:decimal)
DataPropertyAssertion(:hasPoint_Z :work_table_point "0.000000"^^xsd:decimal)
Declaration(NamedIndividual(:work_table_x_axis))
ClassAssertion(:Vector :work_table_x_axis)
DataPropertyAssertion(:hasVector_I :work_table_x_axis "1.000000"^^xsd:decimal)
DataPropertyAssertion(:hasVector_J :work_table_x_axis "0.000000"^^xsd:decimal)
DataPropertyAssertion(:hasVector_K :work_table_x_axis "0.000000"^^xsd:decimal)
Declaration(NamedIndividual(:work_table_z_axis))
ClassAssertion(:Vector :work_table_z_axis)
DataPropertyAssertion(:hasVector_I :work_table_z_axis "0.000000"^^xsd:decimal)
DataPropertyAssertion(:hasVector_J :work_table_z_axis "0.000000"^^xsd:decimal)
DataPropertyAssertion(:hasVector_K :work_table_z_axis "1.000000"^^xsd:decimal)

*/

void OwlPrinter::printLocations(                /* ARGUMENTS              */
 XmlID * Name,                                  /* name of located object */
 PhysicalLocationType * primary,                /* primary location       */
 std::list<PhysicalLocationType *> * secondary, /* secondary locations    */
 FILE * outFile)                                /* file to print in       */
{
  std::list<PhysicalLocationType *>::iterator iter;

  fprintf(outFile, "ObjectPropertyAssertion(:hasSolidObject_PrimaryLocation :");
  Name->printSelf(outFile);
  fprintf(outFile, " :");
  primary->Name->printSelf(outFile);
  fprintf(outFile, ")\n");
  for (iter = secondary->begin(); iter != secondary->end(); iter++)
    {
      fprintf(outFile,
	      "ObjectPropertyAssertion(:hasSolidObject_SecondaryLocation :");
      Name->printSelf(outFile);
      fprintf(outFile, " :");
      (*iter)->Name->printSelf(outFile);
      fprintf(outFile, ")\n");
    }
  OwlPrinter::primary = true;
  primary->printOwl(outFile);
  OwlPrinter::primary = false;
  for (iter = secondary->begin(); iter != secondary->end(); iter++)
    {
       (*iter)->printOwl(outFile);
    }

}

/*********************************************************************/

/* OwlPrinter::printObjProp

This prints an ObjectPropertyAssertion, for example:

ObjectPropertyAssertion(:hasLargeBoxWithEmptyKitTrays_LargeContainer :empty_kit_tray_supply :empty_kit_tray_box)

This is used when the value object is embedded in the named individual in
the XML data file.

*/

void OwlPrinter::printObjProp( /* ARGUMENTS                                 */
 const char * property,        /* name of object property                   */
 XmlID * Name,                 /* name of individual with property          */
 XmlID * valName,              /* name of individual that is property value */
 FILE * outFile)               /* file to print in                          */
{
  fprintf(outFile, "ObjectPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " :");
  valName->printSelf(outFile);
  fprintf(outFile, ")\n");
}

/*********************************************************************/

/* OwlPrinter::printObjRefProp

This prints an ObjectPropertyAssertion, for example:

ObjectPropertyAssertion(:hasPhysicalLocation_RefObject :empty_kit_tray_supply_pose :kitting_workstation_1)

This is used when the value object is referenced by name, not embedded.

*/

void OwlPrinter::printObjRefProp(/* ARGUMENTS                                 */
 const char * property,          /* name of object property                   */
 XmlID * Name,                   /* name of individual with property          */
 XmlIDREF * valName,             /* name of individual that is property value */
 FILE * outFile)                 /* file to print in                          */
{
  fprintf(outFile, "ObjectPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " :");
  valName->printSelf(outFile);
  fprintf(outFile, ")\n");
}

/*********************************************************************/

/* OwlPrinter::printPosDecProp

This prints a DataPropertyAssertion when the type of data is a
PositiveDecimalType, for example:

DataPropertyAssertion(:hasBox_Height :empty_kit_tray_box "0.800000"^^:positiveDecimal)

*/

void OwlPrinter::printPosDecProp(  /* ARGUMENTS                        */
 const char * property,            /* name of property                 */
 XmlID * Name,                     /* name of individual with property */
 PositiveDecimalType * val,        /* value of property                */
 FILE * outFile)                   /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printOwl(outFile);
  fprintf(outFile, "\"^^:positiveDecimal)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlDecProp

This prints a DataPropertyAssertion when the type of data is an
XmlDecimal, for example:

DataPropertyAssertion(:hasVector_K :empty_kit_tray_box_z_axis "1.000000"^^xsd:decimal)

*/

void OwlPrinter::printXmlDecProp(  /* ARGUMENTS                        */
 const char * property,            /* name of property                 */
 XmlID * Name,                     /* name of individual with property */
 XmlDecimal * val,                 /* value of property                */
 FILE * outFile)                   /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:decimal)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlIDProp

This prints a DataPropertyAssertion when the type of data is an
XmlID, for example:

DataPropertyAssertion(:hasEndEffector_Id :part_gripper "ThePartGripper"^^xsd:NMTOKEN)

OWL does not include xsd:ID, so xsd:NMTOKEN is used.

This is not currently being called since the only use of xsd:ID is for
object names, and those are handled by OwlPrinter::startIndi.

*/

void OwlPrinter::printXmlIDProp(  /* ARGUMENTS                        */
 const char * property,           /* name of property                 */
 XmlID * Name,                    /* name of individual with property */
 XmlID * val,                     /* value of property                */
 FILE * outFile)                  /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlIDREFProp

This prints a DataPropertyAssertion when the XML type of data is an
XmlIDREF, for example:

DataPropertyAssertion(:hasLargeContainer_SkuRef :empty_kit_tray_box "SkuIdKitBox"^^xsd:NMTOKEN)

OWL does not include xsd:IDREF, so xsd:NMTOKEN is used.

*/

void OwlPrinter::printXmlIDREFProp( /* ARGUMENTS                        */
 const char * property,             /* name of property                 */
 XmlID * Name,                      /* name of individual with property */
 XmlIDREF * val,                    /* value of property                */
 FILE * outFile)                    /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlNMTOKENProp

This prints a DataPropertyAssertion when the type of data is an
XmlNMTOKEN, for example:

DataPropertyAssertion(:hasLargeContainer_SerialNumber :empty_kit_tray_box "4"^^xsd:NMTOKEN)

*/

void OwlPrinter::printXmlNMTOKENProp( /* ARGUMENTS                        */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlNMTOKEN * val,                    /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlNMTOKENProp

This prints a DataPropertyAssertion when the type of data is an
XmlString, for example:

DataPropertyAssertion(:hasEndEffector_Description :part_gripper "small single cup vacuum effector"^^xsd:string)

*/

void OwlPrinter::printXmlStringProp(  /* ARGUMENTS                        */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlString * val,                     /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:string)\n");
}

/*********************************************************************/

/* OwlPrinter::startIndi

This prints a NamedIndividual statement and a ClassAssertion statement
that start a set of related statements concerning a named individual.
If heading is true, this also prints a two-line comment beforehand
to help with human readability.
For example:

//*****************************************
// start LargeBoxWithEmptyKitTrays empty_kit_tray_supply
Declaration(NamedIndividual(:empty_kit_tray_supply))
ClassAssertion(:LargeBoxWithEmptyKitTrays :empty_kit_tray_supply)

*/

void OwlPrinter::startIndi( /* ARGUMENTS                 */
 XmlID * Name,              /* name of individual        */
 const char * aType,        /* type of individual        */
 bool heading,              /* whether to print comments */
 FILE * outFile)            /* file to print in          */
{
  if (heading)
    {
      fprintf(outFile, "\n//*****************************************\n");
      fprintf(outFile, "// start %s ", aType);
      Name->printSelf(outFile);
      fprintf(outFile, "\n");
    }
  fprintf(outFile, "Declaration(NamedIndividual(:");
  Name->printSelf(outFile);
  fprintf(outFile, "))\n");
  fprintf(outFile, "ClassAssertion(:%s :", aType);
  Name->printSelf(outFile);
  fprintf(outFile, ")\n");
}

/*********************************************************************/
/*********************************************************************/

/* class KittingWorkStationFile

The KittingWorkStationFile::printOwl function first prints the
workstation (and everything in it) and then prints the different
individuals of every type.  The sets of individuals are built while
the workstation is being printed

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

void KittingWorkStationFile::printOwl(FILE * outFile)
{
  std::set<std::string>::iterator iter;
  header->printOwl(outFile);
  KittingWorkStation->printOwl(outFile);

  if (BoxVolumeType::individuals.size() > 1)
    OwlPrinter::printIndividuals("BoxVolume",
				 &BoxVolumeType::individuals, outFile);
  if (EndEffectorHolderType::individuals.size() > 1)
    OwlPrinter::printIndividuals("EndEffectorHolder",
				 &EndEffectorHolderType::individuals, outFile);
  if (GripperEffectorType::individuals.size() > 1)
    OwlPrinter::printIndividuals("GripperEffector",
				 &GripperEffectorType::individuals, outFile);
  if (KitDesignType::individuals.size() > 1)
    OwlPrinter::printIndividuals("KitDesign",
				 &KitDesignType::individuals, outFile);
  if (KitTrayType::individuals.size() > 1)
    OwlPrinter::printIndividuals("KitTray",
				 &KitTrayType::individuals, outFile);
  if (LargeContainerType::individuals.size() > 1)
    OwlPrinter::printIndividuals("LargeContainer",
				 &LargeContainerType::individuals, outFile);
  if (PartRefAndPoseType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartRefAndPose",
				 &PartRefAndPoseType::individuals, outFile);
  if (PartsBinType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartsBin",
				 &PartsBinType::individuals, outFile);
  if (PartsTrayType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartsTray",
				 &PartsTrayType::individuals, outFile);
  if (PartsTrayWithPartsType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartsTrayWithParts",
				 &PartsTrayWithPartsType::individuals, outFile);
  if (PartType::individuals.size() > 1)
    OwlPrinter::printIndividuals("Part",
				 &PartType::individuals, outFile);
  if (PointType::individuals.size() > 1)
    OwlPrinter::printIndividuals("Point",
				 &PointType::individuals, outFile);
  if (PoseLocationInType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PoseLocationIn",
				 &PoseLocationInType::individuals, outFile);
  if (PoseLocationOnType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PoseLocationOn",
				 &PoseLocationOnType::individuals, outFile);
  if (PoseOnlyLocationType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PoseOnlyLocation",
				 &PoseOnlyLocationType::individuals, outFile);
  if (RelativeLocationInType::individuals.size() > 1)
    OwlPrinter::printIndividuals("RelativeLocationIn",
				 &RelativeLocationInType::individuals, outFile);
  if (RelativeLocationOnType::individuals.size() > 1)
    OwlPrinter::printIndividuals("RelativeLocationOn",
				 &RelativeLocationOnType::individuals, outFile);
  if (ShapeDesignType::individuals.size() > 1)
    OwlPrinter::printIndividuals("ShapeDesign",
				 &ShapeDesignType::individuals, outFile);
  if (StockKeepingUnitType::individuals.size() > 1)
    OwlPrinter::printIndividuals("StockKeepingUnit",
				 &StockKeepingUnitType::individuals, outFile);
  if (VacuumEffectorMultiCupType::individuals.size() > 1)
    OwlPrinter::printIndividuals("VacuumEffectorMultiCup",
				 &VacuumEffectorMultiCupType::individuals,
				 outFile);
  if (VacuumEffectorSingleCupType::individuals.size() > 1)
    OwlPrinter::printIndividuals("VacuumEffectorSingleCup",
				 &VacuumEffectorSingleCupType::individuals,
				 outFile);
  if (VectorType::individuals.size() > 1)
    OwlPrinter::printIndividuals("Vector",
				 &VectorType::individuals, outFile);

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

void BoxVolumeType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "BoxVolume", false, outFile);
  OwlPrinter::printObjProp("hasBoxVolume_MaximumPoint", Name,
			   MaximumPoint->Name, outFile);
  OwlPrinter::printObjProp("hasBoxVolume_MinimumPoint", Name,
			   MinimumPoint->Name, outFile);
  MaximumPoint->printOwl(outFile);
  MinimumPoint->printOwl(outFile);
  fprintf(outFile, "\n");
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

void BoxyObjectType::printDimensions(FILE * outFile)
{
  OwlPrinter::printPosDecProp("hasBox_Height", Name, Height, outFile);
  OwlPrinter::printPosDecProp("hasBox_Length", Name, Length, outFile);
  OwlPrinter::printPosDecProp("hasBox_Width", Name, Width, outFile);
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

void EndEffectorChangingStationType::printOwl(FILE * outFile)
{
  std::list<EndEffectorHolderType *>::iterator iter;

  OwlPrinter::startIndi(Name, "EndEffectorChangingStation",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  for (iter = EndEffectorHolders->begin();
       iter != EndEffectorHolders->end(); iter++)
    {
      OwlPrinter::printObjProp("hasChangingStation_EndEffectorHolders", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("EndEffectorChangingStation", outFile);
  OwlPrinter::locationStack.push_front(Name);
  for (iter = EndEffectorHolders->begin();
       iter != EndEffectorHolders->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
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

void EndEffectorHolderType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "EndEffectorHolder", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  if (EndEffector)
    OwlPrinter::printObjProp("hasEndEffectorHolder_EndEffector",
			     Name, EndEffector->Name, outFile);
  OwlPrinter::endIndi("EndEffectorHolder", outFile);
  if (EndEffector)
    {
      OwlPrinter::locationStack.push_front(Name);
      EndEffector->printOwl(outFile);
      OwlPrinter::locationStack.pop_front();
    }
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

void GripperEffectorType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "GripperEffector", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printXmlStringProp("hasEndEffector_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_Weight", Name, Weight, outFile);
  OwlPrinter::printPosDecProp("hasEffector_MaximumLoadWeight", Name,
			      MaximumLoadWeight, outFile);
  OwlPrinter::endIndi("GripperEffector", outFile);
  individuals.insert(Name->val);
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

void KitDesignType::printOwl(FILE * outFile)
{
  std::list<PartRefAndPoseType *>::iterator iter;

  OwlPrinter::startIndi(Name, "KitDesign", true, outFile);
  OwlPrinter::printObjRefProp("hasKitDesign_KitTraySku", Name,
			      KitTraySkuName, outFile);
  for (iter = PartRefAndPose->begin(); iter != PartRefAndPose->end(); iter++)
    {
      OwlPrinter::printObjProp("hasKitDesign_PartRefAndPoses", Name,
			       (*iter)->Name, outFile);
    }
  for (iter = PartRefAndPose->begin(); iter != PartRefAndPose->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::endIndi("KitDesign", outFile);
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

void KitTrayType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "KitTray", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  printDimensions(outFile);
  OwlPrinter::printObjRefProp("hasKitTray_Sku", Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasKitTray_SerialNumber",
				  Name, SerialNumber, outFile);
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

void KitType::printOwl(FILE * outFile)
{
  std::list<PartType *>::iterator iter;

  OwlPrinter::startIndi(Name, "Kit", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasKit_Design", Name, DesignName, outFile);
  OwlPrinter::printObjProp("hasKit_Tray", Name, Tray->Name, outFile);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      OwlPrinter::printObjProp("hasKit_Parts", Name, (*iter)->Name, outFile);
     }
  fprintf(outFile, "DataPropertyAssertion(:isKit_Finished :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  Finished->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:boolean)\n");
  OwlPrinter::locationStack.push_front(Name);
  Tray->printOwl(outFile);
  OwlPrinter::locationStack.push_front(Tray->Name);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  OwlPrinter::locationStack.pop_front();
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

void KittingWorkstationType::printOwl(FILE * outFile)
{
  std::list<StockKeepingUnitType *>::iterator skuIter;
  std::list<KitDesignType *>::iterator designIter;
  std::list<BoxVolumeType *>::iterator boxIter;
  std::list<SolidObjectType *>::iterator objectIter;
  
  OwlPrinter::locationStack.push_front(Name);
  OwlPrinter::startIndi(Name, "KittingWorkstation", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  fprintf(outFile, "DataPropertyAssertion(:hasWorkstation_AngleUnit :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  AngleUnit->printOwl(outFile);
  fprintf(outFile, "\")\n");
  
  fprintf(outFile, "DataPropertyAssertion(:hasWorkstation_LengthUnit :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  LengthUnit->printOwl(outFile);
  fprintf(outFile, "\")\n");

  fprintf(outFile, "DataPropertyAssertion(:hasWorkstation_WeightUnit :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  WeightUnit->printSelf(outFile);
  fprintf(outFile, "\")\n");

  OwlPrinter::printObjProp("hasWorkstation_Robot", Name, Robot->Name, outFile);
  OwlPrinter::printObjProp("hasWorkstation_ChangingStation", Name,
			   ChangingStation->Name, outFile);
  OwlPrinter::printObjProp("hasWorkstation_WorkTable", Name,
			   WorkTable->Name, outFile);
  for (designIter = KitDesign->begin();
       designIter != KitDesign->end(); designIter++)
    {
      OwlPrinter::printObjProp("hasWorkstation_KitDesigns", Name,
			       (*designIter)->Name, outFile);
    }
  for (skuIter = Sku->begin(); skuIter != Sku->end(); skuIter++)
    {
      OwlPrinter::printObjProp("hasWorkstation_Skus", Name,
			       (*skuIter)->Name, outFile);
    }
  OwlPrinter::endIndi("KittingWorkstation", outFile);
  Robot->printOwl(outFile);
  ChangingStation->printOwl(outFile);
  WorkTable->printOwl(outFile);
  for (objectIter = Object->begin();
       objectIter != Object->end(); objectIter++)
    {
      (*objectIter)->printOwl(outFile);
    }
  for (boxIter = OtherObstacle->begin();
       boxIter != OtherObstacle->end(); boxIter++)
    {
      (*boxIter)->printOwl(outFile);
    }
  for (designIter = KitDesign->begin();
       designIter != KitDesign->end(); designIter++)
    {
      (*designIter)->printOwl(outFile);
    }
  for (skuIter = Sku->begin(); skuIter != Sku->end(); skuIter++)
    {
      (*skuIter)->printOwl(outFile);
    }
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
 std::list<KitTrayType *> * TraysIn) :
  SolidObjectType(
    NameIn,
    PrimaryLocationIn,
    SecondaryLocationIn)
{
  LargeContainer = LargeContainerIn;
  Trays = TraysIn;
  printTypp = false;
}

LargeBoxWithEmptyKitTraysType::~LargeBoxWithEmptyKitTraysType() {}

void LargeBoxWithEmptyKitTraysType::printOwl(FILE * outFile)
{
  std::list<KitTrayType *>::iterator iter;

  OwlPrinter::startIndi(Name, "LargeBoxWithEmptyKitTrays",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printObjProp("hasLargeBoxWithEmptyKitTrays_LargeContainer",
			   Name, LargeContainer->Name, outFile);
  for (iter = Trays->begin(); iter != Trays->end(); iter++)
    {
      OwlPrinter::printObjProp("hasLargeBoxWithEmptyKitTrays_KitTrays", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("LargeBoxWithEmptyKitTrays", outFile);
  OwlPrinter::locationStack.push_front(Name);
  LargeContainer->printOwl(outFile);
  OwlPrinter::locationStack.push_front(LargeContainer->Name);
  for (iter = Trays->begin(); iter != Trays->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  OwlPrinter::locationStack.pop_front();
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

void LargeBoxWithKitsType::printOwl(FILE * outFile)
{
  std::list<KitType *>::iterator iter;

  OwlPrinter::startIndi(Name, "LargeBoxWithKits", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printObjProp("hasLargeBoxWithKits_LargeContainer", Name,
			   LargeContainer->Name, outFile);
  for (iter = Kit->begin(); iter != Kit->end(); iter++)
    {
      OwlPrinter::printObjProp("hasLargeBoxWithKits_Kits", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::printObjRefProp("hasLargeBoxWithKits_KitDesign", Name,
				KitDesignName, outFile);
  fprintf(outFile, "DataPropertyAssertion(:hasLargeBoxWithKits_Capacity :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  Capacity->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:positiveInteger)\n");
  OwlPrinter::endIndi("LargeBoxWithKits", outFile);
  OwlPrinter::locationStack.push_front(Name);
  LargeContainer->printOwl(outFile);
  OwlPrinter::locationStack.push_front(LargeContainer->Name);
  for (iter = Kit->begin(); iter != Kit->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  OwlPrinter::locationStack.pop_front();
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

void LargeContainerType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "LargeContainer", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasLargeContainer_Sku",
			      Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasLargeContainer_SerialNumber",
				  Name, SerialNumber, outFile);
  printDimensions(outFile);
  OwlPrinter::endIndi("LargeContainer", outFile);
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

void PartRefAndPoseType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "PartRefAndPose", false, outFile);
  OwlPrinter::printObjRefProp("hasPartRefAndPose_Sku",
			      Name, SkuName, outFile);
  OwlPrinter::printObjProp("hasPartRefAndPose_Point", Name,
			   Point->Name, outFile);
  OwlPrinter::printObjProp("hasPartRefAndPose_ZAxis", Name,
			   ZAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPartRefAndPose_XAxis", Name,
			   XAxis->Name, outFile);
  Point->printOwl(outFile);
  XAxis->printOwl(outFile);
  ZAxis->printOwl(outFile);
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

void PartType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "Part", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasPart_Sku", Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasPart_SerialNumber",
				  Name, SerialNumber, outFile);
  OwlPrinter::endIndi("Part", outFile);
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

void PartsBinType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "PartsBin", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  printDimensions(outFile);
  OwlPrinter::printObjRefProp("hasPartsBin_PartSku", Name,
				PartSkuName, outFile);
  fprintf(outFile, "DataPropertyAssertion(:hasPartsBin_PartQuantity :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  PartQuantity->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:nonNegativeInteger)\n");
  OwlPrinter::endIndi("PartsBin", outFile);
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

void PartsTrayType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "PartsTray", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  printDimensions(outFile);
  OwlPrinter::printObjRefProp("hasPartsTray_Sku", Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasPartsTray_SerialNumber",
				  Name, SerialNumber, outFile);
  OwlPrinter::endIndi("PartsTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PartsTrayWithPartsType

The parts in a PartsTrayWithPartsType are located relative to the tray,
not to the PartsTrayWithPartsType, so in the printOwl function, the
tray is added to the locationStack before the parts are printed and
removed afterwards.

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

void PartsTrayWithPartsType::printOwl(FILE * outFile)
{
  std::list<PartType *>::iterator iter;

  OwlPrinter::startIndi(Name, "PartsTrayWithParts", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjProp("hasPartsTrayWithParts_Tray", Name,
			   PartsTray->Name, outFile);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      OwlPrinter::printObjProp("hasPartsTrayWithParts_Parts", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("PartsTrayWithParts", outFile);
  OwlPrinter::locationStack.push_front(Name);
  PartsTray->printOwl(outFile);
  OwlPrinter::locationStack.push_front(PartsTray->Name);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  OwlPrinter::locationStack.pop_front();
  individuals.insert(Name->val);
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

void PointType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "Point", false, outFile);
  OwlPrinter::printXmlDecProp("hasPoint_X", Name, X, outFile);
  OwlPrinter::printXmlDecProp("hasPoint_Y", Name, Y, outFile);
  OwlPrinter::printXmlDecProp("hasPoint_Z", Name, Z, outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationInType

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void PoseLocationInType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObject->val);
  OwlPrinter::startIndi(Name, "PoseLocationIn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
			      Name, RefObject, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_Point",
			   Name, Point->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_XAxis",
			   Name, XAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_ZAxis",
			   Name, ZAxis->Name, outFile);
  Point->printOwl(outFile);
  XAxis->printOwl(outFile);
  ZAxis->printOwl(outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationOnType

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void PoseLocationOnType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObject->val);
  OwlPrinter::startIndi(Name, "PoseLocationOn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
				Name, RefObject, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_Point",
			   Name, Point->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_XAxis",
			   Name, XAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_ZAxis",
			   Name, ZAxis->Name, outFile);
  Point->printOwl(outFile);
  XAxis->printOwl(outFile);
  ZAxis->printOwl(outFile);
  individuals.insert(Name->val);
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

/*********************************************************************/

/* class PoseOnlyLocationType

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void PoseOnlyLocationType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObject->val);
  OwlPrinter::startIndi(Name, "PoseOnlyLocation", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
				Name, RefObject, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_Point",
			   Name, Point->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_XAxis",
			   Name, XAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_ZAxis",
			   Name, ZAxis->Name, outFile);
  Point->printOwl(outFile);
  XAxis->printOwl(outFile);
  ZAxis->printOwl(outFile);
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

/*********************************************************************/

/* class RelativeLocationInType

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void RelativeLocationInType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObject->val);
  OwlPrinter::startIndi(Name, "RelativeLocationIn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
			      Name, RefObject, outFile);
  OwlPrinter::printXmlStringProp("hasRelativeLocation_Description",
				 Name, Description, outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class RelativeLocationOnType

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void RelativeLocationOnType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObject->val);
  OwlPrinter::startIndi(Name, "RelativeLocationOn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
			      Name, RefObject, outFile);
  OwlPrinter::printXmlStringProp("hasRelativeLocation_Description",
				 Name, Description, outFile);
  individuals.insert(Name->val);
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

void RobotType::printOwl(FILE * outFile)
{
  std::list<BoxVolumeType *>::iterator iter;
  
  OwlPrinter::startIndi(Name, "Robot", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printXmlStringProp("hasRobot_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasRobot_MaximumLoadWeight", Name,
			      MaximumLoadWeight, outFile);
  if (EndEffector)
    {
      OwlPrinter::printObjProp("hasRobot_EndEffector", Name,
			       EndEffector->Name, outFile);
    }
  for (iter = WorkVolume->begin(); iter != WorkVolume->end(); iter++)
    {
      OwlPrinter::printObjProp("hasRobot_WorkVolume", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::locationStack.push_front(Name);
  OwlPrinter::endIndi("Robot", outFile);
  if (EndEffector)
    {
      EndEffector->printOwl(outFile);
    }
  fprintf(outFile, "\n//*****************************************\n");
  fprintf(outFile, "// start Robot work volume\n");
  for (iter = WorkVolume->begin(); iter != WorkVolume->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  OwlPrinter::endIndi("Robot work volume", outFile);
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

void ShapeDesignType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "ShapeDesign", false, outFile);
  OwlPrinter::printXmlStringProp("hasShapeDesign_Description",
				 Name, Description, outFile);
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

void StockKeepingUnitType::printOwl(FILE * outFile)
{
  std::list<XmlIDREF *>::iterator iter;

  OwlPrinter::startIndi(Name, "StockKeepingUnit", true, outFile);
  OwlPrinter::printXmlStringProp("hasSku_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasSku_Weight", Name, Weight, outFile);
  OwlPrinter::printObjProp("hasSku_Shape", Name, Shape->Name, outFile);
  for (iter = EndEffectorName->begin(); iter != EndEffectorName->end(); iter++)
    {
      OwlPrinter::printObjRefProp("hasSku_EndEffectors",
				  Name, *iter, outFile);
    }
  Shape->printOwl(outFile);
  OwlPrinter::endIndi("StockKeepingUnit", outFile);
  
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

void VacuumEffectorMultiCupType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "VacuumEffectorMultiCup",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printXmlStringProp("hasEndEffector_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_Weight", Name, Weight, outFile);
  OwlPrinter::printPosDecProp("hasEffector_MaximumLoadWeight", Name,
			      MaximumLoadWeight, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_CupDiameter", Name,
			      CupDiameter, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_Length", Name,
			      Length, outFile);
  fprintf(outFile, "DataPropertyAssertion(:hasMultiCup_ArrayNumber :");
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  ArrayNumber->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:positiveInteger)\n");
  OwlPrinter::printPosDecProp("hasMultiCup_ArrayRadius", Name,
			      ArrayRadius, outFile);
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

void VacuumEffectorSingleCupType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "VacuumEffectorSingleCup",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printXmlStringProp("hasEndEffector_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_Weight", Name, Weight, outFile);
  OwlPrinter::printPosDecProp("hasEffector_MaximumLoadWeight", Name,
			      MaximumLoadWeight, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_CupDiameter", Name,
			      CupDiameter, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_Length", Name,
			      Length, outFile);
  OwlPrinter::endIndi("VacuumEffectorSingleCup", outFile);
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

void VectorType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "Vector", false, outFile);
  OwlPrinter::printXmlDecProp("hasVector_I", Name, I, outFile);
  OwlPrinter::printXmlDecProp("hasVector_J", Name, J, outFile);
  OwlPrinter::printXmlDecProp("hasVector_K", Name, K, outFile);
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

void WorkTableType::printOwl(FILE * outFile)
{
  std::list<SolidObjectType *>::iterator iter;

  OwlPrinter::startIndi(Name, "WorkTable", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation, SecondaryLocation, outFile);
  printDimensions(outFile);
  for (iter = SolidObject->begin(); iter != SolidObject->end(); iter++)
    {
      OwlPrinter::printObjProp("hasWorkTable_SolidObjects", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("WorkTable", outFile);
  OwlPrinter::locationStack.push_front(Name);
  for (iter = SolidObject->begin(); iter != SolidObject->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
}

/*********************************************************************/

XmlHeaderForKittingWorkStation::XmlHeaderForKittingWorkStation() {}

XmlHeaderForKittingWorkStation::XmlHeaderForKittingWorkStation(
  SchemaLocation * locationIn)
{
  location = locationIn;
}

XmlHeaderForKittingWorkStation::~XmlHeaderForKittingWorkStation() {}

void XmlHeaderForKittingWorkStation::printOwl(
  FILE * outFile)
{
  fprintf(outFile,
      "Prefix(xsd:=<http://www.w3.org/2001/XMLSchema#>)\n"
      "Prefix(owl:=<http://www.w3.org/2002/07/owl#>)\n"
      "Prefix(xml:=<http://www.w3.org/XML/1998/namespace>)\n"
      "Prefix(rdf:=<http://www.w3.org/1999/02/22-rdf-syntax-ns#>)\n"
      "Prefix(rdfs:=<http://www.w3.org/2000/01/rdf-schema#>)\n"
      "Prefix(:=<http://www.nist.gov/el/ontologies/%s.owl#>)\n"
      "Prefix(:=<http://www.nist.gov/el/ontologies/kittingClasses.owl#>)\n"

      "Ontology(<http://www.nist.gov/el/ontologies/%s.owl>\n"
      "Import(<file:kittingClasses.owl>)\n",
      OwlPrinter::inFileName, OwlPrinter::inFileName);
}

/*********************************************************************/

