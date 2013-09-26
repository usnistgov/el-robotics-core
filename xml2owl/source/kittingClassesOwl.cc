/* 

This file was prepared by starting with the kittingClasses.cc file
generated automatically by the GenXMiller and hand editing it severely.
All the printSelf functions for the classes defined in kittingClassesOwl.hh
were removed and replaced by hand-written printOwl functions.

All the functions in the OwlPrinter class were written from scratch.

This is a hierarchical descent printer where the printing follows the
hierarchy of the XML data file. The top level is
KittingWorkstationFile::printOwl

FIX - Get rid of all the printTypp in this file. They need to stay
in kittingClassesOwl.hh since the YACC populates them

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
std::set<std::string> BoxyShapeType::individuals;
std::set<std::string> CylindricalShapeType::individuals;
std::set<std::string> EndEffectorHolderType::individuals;
std::set<std::string> ExternalShapeType::individuals;
std::set<std::string> GripperEffectorType::individuals;
std::set<std::string> HumanType::individuals;
std::set<std::string> KitDesignType::individuals;
std::set<std::string> KitTrayType::individuals;
std::set<std::string> KitType::individuals;
std::set<std::string> LargeBoxWithEmptyKitTraysType::individuals;
std::set<std::string> LargeBoxWithKitsType::individuals;
std::set<std::string> LargeContainerType::individuals;
std::set<std::string> MechanicalComponentType::individuals;
std::set<std::string> PartRefAndPoseType::individuals;
std::set<std::string> PartsBinType::individuals;
std::set<std::string> PartsTrayType::individuals;
std::set<std::string> PartType::individuals;
std::set<std::string> PointType::individuals;
std::set<std::string> PoseLocationInType::individuals;
std::set<std::string> PoseLocationOnType::individuals;
std::set<std::string> PoseOnlyLocationType::individuals;
std::set<std::string> RelativeLocationInType::individuals;
std::set<std::string> RelativeLocationOnType::individuals;
std::set<std::string> SlotType::individuals;
std::set<std::string> StockKeepingUnitType::individuals;
std::set<std::string> VacuumEffectorMultiCupType::individuals;
std::set<std::string> VacuumEffectorSingleCupType::individuals;
std::set<std::string> VectorType::individuals;

/*********************************************************************/
/*********************************************************************/

/* OwlPrinter::checkRefObject

Returned Value: none

Called By:
  PoseLocationInType::printOwl
  PoseLocationOnType::printOwl
  PoseOnlyLocationType::printOwl
  RelativeLocationInType::printOwl
  RelativeLocationOnType::printOwl

This checks that the reference object, ref, for the location of an
object A is the same as the first entry on the locationStack, which is
what the reference object is supposed to be. In all cases, ref has A
as the value of an element.

Before January 2013, in the cases listed below, ref was a
sibling of A (i.e. they were both elements of another object).
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

Returned Value: none

Called By:
  EndEffectorChangingStationType::printOwl
  EndEffectorHolderType::printOwl
  GripperEffectorType::printOwl
  KitDesignType::printOwl
  KitTrayType::printOwl
  KitType::printOwl
  KittingWorkstationType::printOwl
  LargeBoxWithEmptyKitTraysType::printOwl
  LargeBoxWithKitsType::printOwl
  LargeContainerType::printOwl
  PartType::printOwl
  PartsBinType::printOwl
  PartsTrayType::printOwl
  RobotType::printOwl
  StockKeepingUnitType::printOwl
  VacuumEffectorMultiCupType::printOwl
  VacuumEffectorSingleCupType::printOwl
  WorkTableType::printOwl

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

Returned Value: none

Called By: KittingWorkstationFile::printOwl

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

Returned Value: none

Called By:
  EndEffectorChangingStationType::printOwl
  EndEffectorHolderType::printOwl
  GripperEffectorType::printOwl
  KitTrayType::printOwl
  KitType::printOwl
  KittingWorkstationType::printOwl
  LargeBoxWithEmptyKitTraysType::printOwl
  LargeBoxWithKitsType::printOwl
  LargeContainerType::printOwl
  PartType::printOwl
  PartsBinType::printOwl
  PartsTrayType::printOwl
  RobotType::printOwl
  VacuumEffectorMultiCupType::printOwl
  VacuumEffectorSingleCupType::printOwl
  WorkTableType::printOwl

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

Returned Value: none

Called By:
  BoxVolumeType::printOwl
  EndEffectorChangingStationType::printOwl
  EndEffectorHolderType::printOwl
  KitDesignType::printOwl
  KitType::printOwl
  KittingWorkstationType::printOwl
  LargeBoxWithEmptyKitTraysType::printOwl
  LargeBoxWithKitsType::printOwl
  PartRefAndPoseType::printOwl
  PoseLocationInType::printOwl
  PoseLocationOnType::printOwl
  PoseOnlyLocationType::printOwl
  RobotType::printOwl
  StockKeepingUnitType::printOwl
  WorkTableType::printOwl

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

Returned Value: none

Called By:
  KitDesignType::printOwl
  KitTrayType::printOwl
  KitType::printOwl
  LargeBoxWithKitsType::printOwl
  LargeContainerType::printOwl
  PartRefAndPoseType::printOwl
  PartType::printOwl
  PartsBinType::printOwl
  PartsTrayType::printOwl
  PoseLocationInType::printOwl
  PoseLocationOnType::printOwl
  PoseOnlyLocationType::printOwl
  RelativeLocationInType::printOwl
  RelativeLocationOnType::printOwl
  StockKeepingUnitType::printOwl

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

Returned Value: none

Called By:
  GripperEffectorType::printOwl
  RobotType::printOwl
  StockKeepingUnitType::printOwl
  VacuumEffectorMultiCupType::printOwl
  VacuumEffectorSingleCupType::printOwl

This prints a DataPropertyAssertion when the type of data is a
PositiveDecimalType. The equivalent property in OWL is positiveDecimal,
which is defined using a DatatypeDefinition that constrains xsd:decimal.
In an OWL instance file, data values cannot be declared using the name
of the DatatypeDefinition. The base type (xsd:decimal in this case) must
be used instead. Thus, this prints, for example:

DataPropertyAssertion(:hasBoxyShape_Height :empty_kit_tray_box "0.800000"^^xsd:decimal)

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
  fprintf(outFile, "\"^^xsd:decimal)\n");
}

/*********************************************************************/

/* OwlPrinter::printShapes

Returned Value: none

Called By:
  EndEffectorHolderType::printOwl
  GripperEffectorType::printOwl
  HumanType::printOwl
  KitType::printOwl
  LargeBoxWithEmptyKitTraysType::printOwl
  LargeBoxWithKitsType::printOwl
  MechanicalComponentType::printOwl
  RobotType::printOwl
  VacuumEffectorMultiCupType::printOwl
  VacuumEffectorSingleCupType::printOwl
  WorkTableType::printOwl

*/

void OwlPrinter::printShapes(
 InternalShapeType * InternalShape,
 ExternalShapeType * ExternalShape,
 XmlID * Name,
 FILE * outFile)
{
  if (InternalShape)
    {
      OwlPrinter::printObjProp("hasNoSkuObject_InternalShape", Name,
			       InternalShape->Name, outFile);
    }
  if (ExternalShape)
    {
      OwlPrinter::printObjProp("hasNoSkuObject_ExternalShape", Name,
			       ExternalShape->Name, outFile);
    }
}

/*********************************************************************/

/* OwlPrinter::printXmlBoolProp

Returned Value: none

Called By:
  BoxyShapeType::printOwl
  KitType::printOwl

This prints a DataPropertyAssertion when the type of data is an
XmlBoolean, for example:

DataPropertyAssertion(:isKit_Finished :kit_1 "true"^^xsd:boolean)

*/

void OwlPrinter::printXmlBoolProp( /* ARGUMENTS                        */
 const char * property,            /* name of property                 */
 XmlID * Name,                     /* name of individual with property */
 XmlBoolean * val,                 /* value of property                */
 FILE * outFile)                   /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:boolean)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlDateTimeProp

Returned Value: none

Called By: 

This prints a DataPropertyAssertion when the type of data is an
XmlDateTime, for example:

DataPropertyAssertion(:hasPoseLocation_Timestamp :pose_1 "2012-06-25T04:00:00-05:00"^^xsd:dateTime)

*/

void OwlPrinter::printXmlDateTimeProp( /* ARGUMENTS                        */
 const char * property,                /* name of property                 */
 XmlID * Name,                         /* name of individual with property */
 XmlDateTime * val,                    /* value of property                */
 FILE * outFile)                       /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:dateTime)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlDecProp

Returned Value: none

Called By:
  PointType::printOwl
  VectorType::printOwl

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

Returned Value: none

Called By: 
  This is not currently being called since the only use of xsd:ID is for
  object names, and those are handled by OwlPrinter::startIndi.


This prints a DataPropertyAssertion when the type of data is an
XmlID, for example:

DataPropertyAssertion(:hasEndEffector_Id :part_gripper "ThePartGripper"^^xsd:NMTOKEN)

OWL does not include xsd:ID, so xsd:NMTOKEN is used.

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

Returned Value: none

Called By:
  This is not currently being called since references to objects are being
  used rather than references to names of objects.

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

Returned Value: none

Called By:
  ExternalShapeType::printOwl
  KitTrayType::printOwl
  LargeContainerType::printOwl
  PartType::printOwl
  PartsTrayType::printOwl

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

/* OwlPrinter::printXmlNonNegIntProp

Returned Value: none

Called By:
  PartsBinType::printOwl
  PartsTrayType::printOwl

This prints a DataPropertyAssertion when the type of data is an
XmlNonNegativeInteger, for example:

DataPropertyAssertion(:hasPartsTray_Quantity :parts_tray_a "1"^^xsd:nonNegativeInteger)

*/

void OwlPrinter::printXmlNonNegIntProp( /* ARGUMENTS                        */
 const char * property,                 /* name of property                 */
 XmlID * Name,                          /* name of individual with property */
 XmlNonNegativeInteger * val,           /* value of property                */
 FILE * outFile)                        /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:nonNegativeInteger)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlPosIntProp

Returned Value: none

Called By:
  VacuumEffectorMultiCupType::printOwl

This prints a DataPropertyAssertion when the type of data is an
XmlPositiveInteger, for example:

DataPropertyAssertion(:hasLargeBoxWithKits_Capacity :kit_box "8"^^xsd:positiveInteger)

*/

void OwlPrinter::printXmlPosIntProp( /* ARGUMENTS                        */
 const char * property,              /* name of property                 */
 XmlID * Name,                       /* name of individual with property */
 XmlPositiveInteger * val,           /* value of property                */
 FILE * outFile)                     /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(:%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, " \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:positiveInteger)\n");
}

/*********************************************************************/

/* OwlPrinter::printXmlStringProp

Returned Value: none

Called By:
  BoxyShapeType::printOwl
  ExternalShapeType::printOwl
  GripperEffectorType::printOwl
  RelativeLocationInType::printOwl
  RelativeLocationOnType::printOwl
  RobotType::printOwl
  StockKeepingUnitType::printOwl
  VacuumEffectorMultiCupType::printOwl
  VacuumEffectorSingleCupType::printOwl

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

Returned Value: none

Called By: 
  BoxVolumeType::printOwl
  BoxyShapeType::printOwl
  EndEffectorChangingStationType::printOwl
  EndEffectorHolderType::printOwl
  GripperEffectorType::printOwl
  KitDesignType::printOwl
  KitType::printOwl
  KittingWorkstationType::printOwl
  LargeBoxWithEmptyKitTraysType::printOwl
  LargeBoxWithKitsType::printOwl
  LargeContainerType::printOwl
  PartRefAndPoseType::printOwl
  PartType::printOwl
  PartsBinType::printOwl
  PartsTrayType::printOwl
  PointType::printOwl
  PoseLocationInType::printOwl
  PoseLocationOnType::printOwl
  PoseOnlyLocationType::printOwl
  RelativeLocationInType::printOwl
  RelativeLocationOnType::printOwl
  RobotType::printOwl
  StockKeepingUnitType::printOwl
  VacuumEffectorMultiCupType::printOwl
  VacuumEffectorSingleCupType::printOwl
  VectorType::printOwl
  WorkTableType::printOwl

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

/* class KittingWorkstationFile

Returned Value: none

Called By: main (in owlPrinter.cc)

The printOwl function first prints the workstation (and everything in
it) and then prints the different individuals of every type. The sets
of individuals are built while the workstation is being printed.

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
  header->printOwl(outFile);
  KittingWorkstation->printOwl(outFile);

  if (BoxVolumeType::individuals.size() > 1)
    OwlPrinter::printIndividuals("BoxVolume",
				 &BoxVolumeType::individuals, outFile);
  if (BoxyShapeType::individuals.size() > 1)
    OwlPrinter::printIndividuals("BoxyShape",
				 &BoxyShapeType::individuals, outFile);
  if (CylindricalShapeType::individuals.size() > 1)
    OwlPrinter::printIndividuals("CylindricalShape",
				 &CylindricalShapeType::individuals, outFile);
  if (EndEffectorHolderType::individuals.size() > 1)
    OwlPrinter::printIndividuals("EndEffectorHolder",
				 &EndEffectorHolderType::individuals, outFile);
  if (ExternalShapeType::individuals.size() > 1)
    OwlPrinter::printIndividuals("ExternalShape",
				 &ExternalShapeType::individuals, outFile);
  if (GripperEffectorType::individuals.size() > 1)
    OwlPrinter::printIndividuals("GripperEffector",
				 &GripperEffectorType::individuals, outFile);
  if (KitDesignType::individuals.size() > 1)
    OwlPrinter::printIndividuals("KitDesign",
				 &KitDesignType::individuals, outFile);
  if (KitTrayType::individuals.size() > 1)
    OwlPrinter::printIndividuals("KitTray",
				 &KitTrayType::individuals, outFile);
  if (KitType::individuals.size() > 1)
    OwlPrinter::printIndividuals("Kit",
				 &KitType::individuals, outFile);
  if (LargeBoxWithEmptyKitTraysType::individuals.size() > 1)
    OwlPrinter::printIndividuals("LargeBoxWithEmptyKitTrays",
				 &LargeBoxWithEmptyKitTraysType::individuals,
				 outFile);
  if (LargeBoxWithKitsType::individuals.size() > 1)
    OwlPrinter::printIndividuals("LargeBoxWithKits",
				 &LargeBoxWithKitsType::individuals, outFile);
  if (LargeContainerType::individuals.size() > 1)
    OwlPrinter::printIndividuals("LargeContainer",
				 &LargeContainerType::individuals, outFile);
  if (MechanicalComponentType::individuals.size() > 1)
    OwlPrinter::printIndividuals("MechanicalComponent",
				 &MechanicalComponentType::individuals,outFile);
  if (PartRefAndPoseType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartRefAndPose",
				 &PartRefAndPoseType::individuals, outFile);
  if (PartsBinType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartsBin",
				 &PartsBinType::individuals, outFile);
  if (PartsTrayType::individuals.size() > 1)
    OwlPrinter::printIndividuals("PartsTray",
				 &PartsTrayType::individuals, outFile);
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
  if (SlotType::individuals.size() > 1)
    OwlPrinter::printIndividuals("Slot",
				 &SlotType::individuals, outFile);
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
  OwlPrinter::startIndi(Name, "BoxVolume", true, outFile);
  OwlPrinter::printObjProp("hasBoxVolume_MaximumPoint", Name,
			   MaximumPoint->Name, outFile);
  OwlPrinter::printObjProp("hasBoxVolume_MinimumPoint", Name,
			   MinimumPoint->Name, outFile);
  MaximumPoint->printOwl(outFile);
  MinimumPoint->printOwl(outFile);
  OwlPrinter::endIndi("BoxVolume", outFile);
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
  printTypp = false;
}

BoxyShapeType::~BoxyShapeType() {}

void BoxyShapeType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "BoxyShape", true, outFile);
  OwlPrinter::printXmlStringProp("hasShapeDesign_Description",
				 Name, Description, outFile);
  if (GraspPose)
    {
      OwlPrinter::printObjProp("hasShapeDesign_GraspPose",
			       Name, GraspPose->Name, outFile);
    }
  OwlPrinter::printPosDecProp("hasBoxyShape_Length", Name, Length, outFile);
  OwlPrinter::printPosDecProp("hasBoxyShape_Width", Name, Width, outFile);
  OwlPrinter::printPosDecProp("hasBoxyShape_Height", Name, Height, outFile);
  OwlPrinter::printXmlBoolProp("hasBoxyShape_Top", Name, HasTop, outFile);
  if (GraspPose)
    {
      GraspPose->printOwl(outFile);
    }
  OwlPrinter::endIndi("BoxyShape", outFile);
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
  printTypp = false;
}

CylindricalShapeType::~CylindricalShapeType() {}

void CylindricalShapeType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "CylindricalShape", true, outFile);
  OwlPrinter::printXmlStringProp("hasShapeDesign_Description",
				 Name, Description, outFile);
  if (GraspPose)
    {
      OwlPrinter::printObjProp("hasShapeDesign_GraspPose",
			       Name, GraspPose->Name, outFile);
    }
  OwlPrinter::printPosDecProp("hasCylindricalShape_Diameter", Name, Diameter, outFile);
  OwlPrinter::printPosDecProp("hasCylindricalShape_Height", Name, Height, outFile);
  OwlPrinter::printXmlBoolProp("hasCylindricalShape_Top", Name, HasTop, outFile);
  if (GraspPose)
    {
      GraspPose->printOwl(outFile);
    }
  OwlPrinter::endIndi("CylindricalShape", outFile);
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

The printOwl function prints the EndEffectorChangingStation and everything
in it (which includes the Base, EndEffectorHolders, and any EndEffectors
in the holders)

FIX - This is not printing the shapes - why? Even if the shape is determined
by the shapes of the components, if the XML instance file has shapes, the OWL
instance file should have them. 

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

void EndEffectorChangingStationType::printOwl(FILE * outFile)
{
  std::list<EndEffectorHolderType *>::iterator iter;

  OwlPrinter::startIndi(Name, "EndEffectorChangingStation", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjProp("hasEndEffectorChangingStation_Base", Name,
			   Base->Name, outFile);
  for (iter = EndEffectorHolder->begin();
       iter != EndEffectorHolder->end(); iter++)
    {
     OwlPrinter::printObjProp("hasEndEffectorChangingStation_EndEffectorHolder",
			      Name, (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("EndEffectorChangingStation", outFile);
  OwlPrinter::locationStack.push_front(Name);
  Base->printOwl(outFile);
  for (iter = EndEffectorHolder->begin();
       iter != EndEffectorHolder->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
}

/*********************************************************************/

/* class EndEffectorHolderType

The printOwl function prints the EndEffectorHolder and any EndEffector it
holds.

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

void EndEffectorHolderType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "EndEffectorHolder", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  if (EndEffector)
    OwlPrinter::printObjProp("hasEndEffectorHolder_EndEffector",
			     Name, EndEffector->Name, outFile);
  OwlPrinter::endIndi("EndEffectorHolder", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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

void ExternalShapeType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "ExternalShape", true, outFile);
  OwlPrinter::printXmlStringProp("hasShapeDesign_Description",
				 Name, Description, outFile);
  if (GraspPose)
    {
      OwlPrinter::printObjProp("hasShapeDesign_GraspPose",
			       Name, GraspPose->Name, outFile);
    }
  OwlPrinter::printXmlStringProp("hasExternalShape_ModelFormatName",
				 Name, ModelFormatName, outFile);
  OwlPrinter::printXmlStringProp("hasExternalShape_ModelFileName",
				  Name, ModelFileName, outFile);
  OwlPrinter::printXmlStringProp("hasExternalShape_ModelName",
				 Name, ModelName, outFile);
  if (GraspPose)
    {
      GraspPose->printOwl(outFile);
    }
  OwlPrinter::endIndi("ExternalShape", outFile);
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
  printTypp = false;
}

GripperEffectorType::~GripperEffectorType() {}

void GripperEffectorType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "GripperEffector", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::printXmlStringProp("hasEndEffector_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_Weight", Name, Weight, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_MaximumLoadWeight", Name,
			      MaximumLoadWeight, outFile);
  if (HeldObject)
    {
      OwlPrinter::printObjProp("hasEndEffector_HeldObject", Name,
			       HeldObject->Name, outFile);
    }
  OwlPrinter::endIndi("GripperEffector", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
  individuals.insert(Name->val);
  if (HeldObject)
    HeldObject->printOwl(outFile);
}

/*********************************************************************/

/* class HumanType

The printOwl function prints the WorkTable and any objects on it.

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

void HumanType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "Human", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation, SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::endIndi("Human", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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
  printTypp = false;
}

InternalShapeType::~InternalShapeType() {}

/*********************************************************************/

/* class KitDesignType

The printOwl function prints the KitDesign and all the PartRefAndPoses
it references.

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
      OwlPrinter::printObjProp("hasKitDesign_PartRefAndPose", Name,
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

void KitTrayType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "KitTray", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasSkuObject_Sku", Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasKitTray_SerialNumber",
				  Name, SerialNumber, outFile);
  OwlPrinter::endIndi("KitTray", outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class KitType

The printOwl function prints the Kit and the tray and parts in the Kit.

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
  Finished = FinishedIn;
  Slot = SlotIn;
  printTypp = false;
}

KitType::~KitType() {}

void KitType::printOwl(FILE * outFile)
{
  std::list<PartType *>::iterator iter;
  std::list<SlotType *>::iterator ator;

  OwlPrinter::startIndi(Name, "Kit", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::printObjRefProp("hasKit_Design", Name, DesignName, outFile);
  OwlPrinter::printObjProp("hasKit_KitTray", Name, KitTray->Name, outFile);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      OwlPrinter::printObjProp("hasKit_Part", Name, (*iter)->Name, outFile);
    }
  for (ator = Slot->begin(); ator != Slot->end(); ator++)
    {
      OwlPrinter::printObjProp("hasKit_Slot", Name, (*ator)->Name, outFile);
    }
  OwlPrinter::printXmlBoolProp("hasKit_Finished", Name, Finished, outFile);
  OwlPrinter::endIndi("Kit", outFile);
  OwlPrinter::locationStack.push_front(Name);
  KitTray->printOwl(outFile);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  for (ator = Slot->begin(); ator != Slot->end(); ator++)
    {
      (*ator)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class KittingWorkstationType

The printOwl function prints the workstation and everything in it.

Except in the constructor, this is ignoring any InternalShape or
ExternalShape.

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
}

KittingWorkstationType::~KittingWorkstationType() {}

/* KittingWorkstationType::printOwl

Returned Value: none

Called By:  KittingWorkstationFile::printOwl

*/

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
  OwlPrinter::printXmlNMTOKENProp("hasKittingWorkstation_AngleUnit",
				  Name, AngleUnit, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasKittingWorkstation_LengthUnit",
				  Name, LengthUnit, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasKittingWorkstation_WeightUnit",
				  Name, WeightUnit, outFile);
  OwlPrinter::printObjProp("hasKittingWorkstation_Robot",
			   Name, Robot->Name, outFile);
  OwlPrinter::printObjProp("hasKittingWorkstation_ChangingStation",
			   Name, ChangingStation->Name, outFile);
  for (designIter = KitDesign->begin();
       designIter != KitDesign->end(); designIter++)
    {
      OwlPrinter::printObjProp("hasKittingWorkstation_KitDesign",
			       Name, (*designIter)->Name, outFile);
    }
  for (skuIter = Sku->begin(); skuIter != Sku->end(); skuIter++)
    {
      OwlPrinter::printObjProp("hasKittingWorkstation_Sku",
			       Name, (*skuIter)->Name, outFile);
    }
  OwlPrinter::endIndi("KittingWorkstation", outFile);
  Robot->printOwl(outFile);
  ChangingStation->printOwl(outFile);
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

The printOwl function prints the LargeBoxWithEmptyKitTrays, the
LargeContainer in it, and the KitTrays in it.

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

void LargeBoxWithEmptyKitTraysType::printOwl(FILE * outFile)
{
  std::list<KitTrayType *>::iterator iter;

  OwlPrinter::startIndi(Name, "LargeBoxWithEmptyKitTrays",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::printObjProp("hasLargeBoxWithEmptyKitTrays_LargeContainer",
			   Name, LargeContainer->Name, outFile);
  for (iter = KitTray->begin(); iter != KitTray->end(); iter++)
    {
      OwlPrinter::printObjProp("hasLargeBoxWithEmptyKitTrays_KitTray", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("LargeBoxWithEmptyKitTrays", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
  OwlPrinter::locationStack.push_front(Name);
  LargeContainer->printOwl(outFile);
  for (iter = KitTray->begin(); iter != KitTray->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
}

/*********************************************************************/

/* class LargeBoxWithKitsType

The printOwl function prints the LargeBoxWithKits, the LargeContainer
in it, and the Kits in it.

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

void LargeBoxWithKitsType::printOwl(FILE * outFile)
{
  std::list<KitType *>::iterator iter;

  OwlPrinter::startIndi(Name, "LargeBoxWithKits", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::printObjProp("hasLargeBoxWithKits_LargeContainer", Name,
			   LargeContainer->Name, outFile);
  for (iter = Kit->begin(); iter != Kit->end(); iter++)
    {
      OwlPrinter::printObjProp("hasLargeBoxWithKits_Kit", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::printObjRefProp("hasLargeBoxWithKits_KitDesign", Name,
				KitDesignName, outFile);
  OwlPrinter::printXmlPosIntProp("hasLargeBoxWithKits_Capacity", Name,
				 Capacity, outFile);
  OwlPrinter::endIndi("LargeBoxWithKits", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
  OwlPrinter::locationStack.push_front(Name);
  LargeContainer->printOwl(outFile);
  for (iter = Kit->begin(); iter != Kit->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
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

void LargeContainerType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "LargeContainer", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasSkuObject_Sku",
			      Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasLargeContainer_SerialNumber",
				  Name, SerialNumber, outFile);
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

void MechanicalComponentType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "MechanicalComponent", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::endIndi("MechanicalComponent", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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

The printOwl function prints the PartRefAndPose, the Point in it, the
XAxis in it, and the ZAxis in it.

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

void PartType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "Part", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasSkuObject_Sku", Name, SkuName, outFile);
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

void PartsBinType::printOwl(FILE * outFile)
{
  std::list<PartType *>::iterator iter;

  OwlPrinter::startIndi(Name, "PartsBin", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasSkuObject_Sku", Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasPartsVessel_SerialNumber",
				  Name, SerialNumber, outFile);
  OwlPrinter::printObjRefProp("hasPartsVessel_PartSku", Name,
				PartSkuName, outFile);
  OwlPrinter::printXmlNonNegIntProp("hasPartsVessel_PartQuantity", Name,
				    PartQuantity, outFile);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      OwlPrinter::printObjProp("hasPartsVessel_Part",
			       Name, (*iter)->Name, outFile);
    }
  OwlPrinter::locationStack.push_front(Name);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
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

void PartsTrayType::printOwl(FILE * outFile)
{
  std::list<PartType *>::iterator iter;

  OwlPrinter::startIndi(Name, "PartsTray", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printObjRefProp("hasSkuObject_Sku", Name, SkuName, outFile);
  OwlPrinter::printXmlNMTOKENProp("hasPartsVessel_SerialNumber",
				  Name, SerialNumber, outFile);
  OwlPrinter::printObjRefProp("hasPartsVessel_PartSku", Name,
			      PartSkuName, outFile);
  OwlPrinter::printXmlNonNegIntProp("hasPartsVessel_PartQuantity", Name,
				    PartQuantity, outFile);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      OwlPrinter::printObjProp("hasPartsVessel_Part",
			       Name, (*iter)->Name, outFile);
    }
  OwlPrinter::locationStack.push_front(Name);
  for (iter = Part->begin(); iter != Part->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  OwlPrinter::endIndi("PartsTray", outFile);
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
  printTypp = false;
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

The printOwl function prints the PoseLocationIn, the Point in it, the
XAxis in it, and the ZAxis in it.

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void PoseLocationInType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObjectName->val);
  OwlPrinter::startIndi(Name, "PoseLocationIn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
			      Name, RefObjectName, outFile);
  if (Timestamp)
    {
      OwlPrinter::printXmlDateTimeProp("hasPhysicalLocation_Timestamp",
				       Name, Timestamp, outFile);
    }
  OwlPrinter::printObjProp("hasPoseLocation_Point",
			   Name, Point->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_XAxis",
			   Name, XAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_ZAxis",
			   Name, ZAxis->Name, outFile);
  if (PositionStandardDeviation)
    OwlPrinter::printPosDecProp("hasPoseLocation_PositionStandardDeviation",
				Name, PositionStandardDeviation, outFile);
  if (OrientationStandardDeviation)
    OwlPrinter::printPosDecProp("hasPoseLocation_OrientationStandardDeviation",
				Name, OrientationStandardDeviation, outFile);
  Point->printOwl(outFile);
  XAxis->printOwl(outFile);
  ZAxis->printOwl(outFile);
  individuals.insert(Name->val);
}

/*********************************************************************/

/* class PoseLocationOnType

The printOwl function prints the PoseLocationOn, the Point in it, the
XAxis in it, and the ZAxis in it.

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void PoseLocationOnType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObjectName->val);
  OwlPrinter::startIndi(Name, "PoseLocationOn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
				Name, RefObjectName, outFile);
  if (Timestamp)
    {
      OwlPrinter::printXmlDateTimeProp("hasPhysicalLocation_Timestamp",
				       Name, Timestamp, outFile);
    }
  OwlPrinter::printObjProp("hasPoseLocation_Point",
			   Name, Point->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_XAxis",
			   Name, XAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_ZAxis",
			   Name, ZAxis->Name, outFile);
  if (PositionStandardDeviation)
    OwlPrinter::printPosDecProp("hasPoseLocation_PositionStandardDeviation",
				Name, PositionStandardDeviation, outFile);
  if (OrientationStandardDeviation)
    OwlPrinter::printPosDecProp("hasPoseLocation_OrientationStandardDeviation",
				Name, OrientationStandardDeviation, outFile);
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

/*********************************************************************/

/* class PoseOnlyLocationType

The printOwl function prints the PoseOnlyLocation, the Point in it, the
XAxis in it, and the ZAxis in it.

If a primary location is being printed, the printOwl function checks
that its reference object is the object containing the object whose
location is being printed.

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

void PoseOnlyLocationType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObjectName->val);
  OwlPrinter::startIndi(Name, "PoseOnlyLocation", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
				Name, RefObjectName, outFile);
  if (Timestamp)
    {
      OwlPrinter::printXmlDateTimeProp("hasPhysicalLocation_Timestamp",
				       Name, Timestamp, outFile);
    }
  OwlPrinter::printObjProp("hasPoseLocation_Point",
			   Name, Point->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_XAxis",
			   Name, XAxis->Name, outFile);
  OwlPrinter::printObjProp("hasPoseLocation_ZAxis",
			   Name, ZAxis->Name, outFile);
  if (PositionStandardDeviation)
    OwlPrinter::printPosDecProp("hasPoseLocation_PositionStandardDeviation",
				Name, PositionStandardDeviation, outFile);
  if (OrientationStandardDeviation)
    OwlPrinter::printPosDecProp("hasPoseLocation_OrientationStandardDeviation",
				Name, OrientationStandardDeviation, outFile);
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

void RelativeLocationInType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObjectName->val);
  OwlPrinter::startIndi(Name, "RelativeLocationIn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
			      Name, RefObjectName, outFile);
  if (Timestamp)
    {
      OwlPrinter::printXmlDateTimeProp("hasPhysicalLocation_Timestamp",
				       Name, Timestamp, outFile);
    }
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

void RelativeLocationOnType::printOwl(FILE * outFile)
{
  OwlPrinter::checkRefObject(Name->val, RefObjectName->val);
  OwlPrinter::startIndi(Name, "RelativeLocationOn", false, outFile);
  OwlPrinter::printObjRefProp("hasPhysicalLocation_RefObject",
			      Name, RefObjectName, outFile);
  if (Timestamp)
    {
      OwlPrinter::printXmlDateTimeProp("hasPhysicalLocation_Timestamp",
				       Name, Timestamp, outFile);
    }
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

/*********************************************************************/

/* class RobotType

The printOwl function prints the robot, its work volume, and its
EndEffector (if it holds one). If the EndEffector holds something,
that is printed also.

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

void RobotType::printOwl(FILE * outFile)
{
  std::list<BoxVolumeType *>::iterator iter;
  
  OwlPrinter::startIndi(Name, "Robot", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
			     SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
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
  for (iter = WorkVolume->begin(); iter != WorkVolume->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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

void SlotType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "Slot", true, outFile);
  OwlPrinter::printObjRefProp("hasSlot_PartRefAndPose", Name,
			      PartRefAndPoseName, outFile);
  if (PartName)
    {
      OwlPrinter::printObjRefProp("hasSlot_Part", Name, PartName, outFile);
    }
  OwlPrinter::endIndi("Slot", outFile);
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
  printTypp = false;
}

StockKeepingUnitType::~StockKeepingUnitType() {}

void StockKeepingUnitType::printOwl(FILE * outFile)
{
  std::list<XmlIDREF *>::iterator iter;

  OwlPrinter::startIndi(Name, "StockKeepingUnit", true, outFile);
  OwlPrinter::printXmlStringProp("hasStockKeepingUnit_Description",
				 Name, Description, outFile);
  if (InternalShape)
    {
      OwlPrinter::printObjProp("hasStockKeepingUnit_InternalShape", Name,
			       InternalShape->Name, outFile);
    }
  if (ExternalShape)
    {
      OwlPrinter::printObjProp("hasStockKeepingUnit_ExternalShape", Name,
			       ExternalShape->Name, outFile);
    }
  OwlPrinter::printPosDecProp("hasStockKeepingUnit_Weight",
			      Name, Weight, outFile);
  for (iter = EndEffectorName->begin(); iter != EndEffectorName->end(); iter++)
    {
      OwlPrinter::printObjRefProp("hasStockKeepingUnit_EndEffector",
				  Name, *iter, outFile);
    }
  OwlPrinter::endIndi("StockKeepingUnit", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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
  printTypp = false;
}

VacuumEffectorMultiCupType::~VacuumEffectorMultiCupType() {}

void VacuumEffectorMultiCupType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "VacuumEffectorMultiCup",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::printXmlStringProp("hasEndEffector_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_Weight", Name, Weight, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_MaximumLoadWeight", Name,
			      MaximumLoadWeight, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_CupDiameter", Name,
			      CupDiameter, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_Length", Name,
			      Length, outFile);
  OwlPrinter::printXmlPosIntProp("hasVacuumEffectorMultiCup_ArrayNumber", Name,
				 ArrayNumber, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffectorMultiCup_ArrayRadius", Name,
			      ArrayRadius, outFile);
  OwlPrinter::endIndi("VacuumEffectorMultiCup", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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
  printTypp = false;
}

VacuumEffectorSingleCupType::~VacuumEffectorSingleCupType() {}

void VacuumEffectorSingleCupType::printOwl(FILE * outFile)
{
  OwlPrinter::startIndi(Name, "VacuumEffectorSingleCup",
				    true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation,
					 SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  OwlPrinter::printXmlStringProp("hasEndEffector_Description",
				 Name, Description, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_Weight", Name, Weight, outFile);
  OwlPrinter::printPosDecProp("hasEndEffector_MaximumLoadWeight",
			      Name, MaximumLoadWeight, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_CupDiameter",
			      Name, CupDiameter, outFile);
  OwlPrinter::printPosDecProp("hasVacuumEffector_Length",
			      Name, Length, outFile);
  OwlPrinter::endIndi("VacuumEffectorSingleCup", outFile);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
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

The printOwl function prints the WorkTable and any objects on it.

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

void WorkTableType::printOwl(FILE * outFile)
{
  std::list<SolidObjectType *>::iterator iter;

  OwlPrinter::startIndi(Name, "WorkTable", true, outFile);
  OwlPrinter::printLocations(Name, PrimaryLocation, SecondaryLocation, outFile);
  OwlPrinter::printShapes(InternalShape, ExternalShape, Name, outFile);
  for (iter = ObjectOnTable->begin(); iter != ObjectOnTable->end(); iter++)
    {
      OwlPrinter::printObjProp("hasWorkTable_ObjectOnTable", Name,
			       (*iter)->Name, outFile);
    }
  OwlPrinter::endIndi("WorkTable", outFile);
  OwlPrinter::locationStack.push_front(Name);
  if (InternalShape)
    InternalShape->printOwl(outFile);
  if (ExternalShape)
    ExternalShape->printOwl(outFile);
  for (iter = ObjectOnTable->begin(); iter != ObjectOnTable->end(); iter++)
    {
      (*iter)->printOwl(outFile);
    }
  OwlPrinter::locationStack.pop_front();
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

