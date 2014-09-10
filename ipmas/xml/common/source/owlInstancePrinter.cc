/*********************************************************************/

#include <stdio.h>             // for printf, etc.
#include <string.h>            // for strdup
#include <stdlib.h>            // for exit
#include <list>
#include "xmlSchemaInstance.hh"
#include "owlInstancePrinter.hh"

/*********************************************************************/
/*********************************************************************/

/*

This file contains domain-independent printing functions for printing
OWL instance files.

The functions assume that names used as %s arguments to printing functions
include prefixes. The empty prefix is used for instances.

*/

/* OwlInstancePrinter::OwlInstancePrinter

*/

OwlInstancePrinter::OwlInstancePrinter()
{
  depth = 1;
}

/*********************************************************************/

/* OwlInstancePrinter::endIndi

Returned Value: none

This prints:
1. a numbered comment that ends the closest preceding "start" with the same
   number. The number indicates the depth of nesting in the XML file.
2. a comment row of asterisks

For example:

// 3 end LargeBoxWithEmptyKitTrays
// *****************************************

*/

void OwlInstancePrinter::endIndi( /* ARGUMENTS          */
 const char * aType,              /* type of individual */
 FILE * outFile)                  /* file to print in   */
{
  fprintf(outFile, "// %d end %s\n", --depth, aType);
  fprintf(outFile, "//*****************************************\n\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printIndividuals

Returned Value: none

This prints, for example:

// *****************************************
// VacuumEffectorSingleCup individuals 
DifferentIndividuals(
 :part_gripper
 :tray_gripper)

*/

void OwlInstancePrinter::printIndividuals( /* ARGUMENTS            */
 const char * typeName,                    /* type of individuals  */
 std::set<std::string> * individuals,      /* names of individuals */
 FILE * outFile)                           /* file to print in     */
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

/* OwlInstancePrinter::printObjProp

Returned Value: none

This prints an ObjectPropertyAssertion of the form:

ObjectPropertyAssertion(:hasOwnerType_ObjectType
                        :ownerInstance :objectInstance)

This is used when the value object is embedded in the named individual in
the XML data file.

*/

void OwlInstancePrinter::printObjProp( /* ARGUMENTS                         */
 const char * property,        /* name of object property                   */
 XmlID * Name,                 /* name of individual with property          */
 XmlID * valName,              /* name of individual that is property value */
 FILE * outFile)               /* file to print in                          */
{
  fprintf(outFile, "ObjectPropertyAssertion(%s\n", property);
  fprintf(outFile, "                        :");
  Name->printSelf(outFile);
  fprintf(outFile, " :");
  valName->printSelf(outFile);
  fprintf(outFile, ")\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printObjRefProp

Returned Value: none

This prints an ObjectPropertyAssertion of the form:

ObjectPropertyAssertion(pre:hasOwnerType_ObjType :ownerInstance :objInstance)

This is used when the value object is referenced by name, not embedded.

*/

void OwlInstancePrinter::printObjRefProp(/* ARGUMENTS                      */
 const char * property,       /* name of object property                   */
 XmlID * Name,                /* name of individual with property          */
 XmlIDREF * valName,          /* name of individual that is property value */
 FILE * outFile)              /* file to print in                          */
{
  fprintf(outFile, "ObjectPropertyAssertion(%s\n", property);
  fprintf(outFile, "                        :");
  Name->printSelf(outFile);
  fprintf(outFile, " :");
  valName->printSelf(outFile);
  fprintf(outFile, ")\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlBooleanProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlBoolean, for example:

DataPropertyAssertion(ktw:isKit_Finished :kit_1 "true"^^xsd:boolean)

*/

void OwlInstancePrinter::printXmlBooleanProp( /* ARGUMENTS                */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlBoolean * val,                    /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:boolean)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlDateTimeProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlDateTime, for example:

DataPropertyAssertion(ktw:hasPoseLocation_Timestamp :pose_1
                      "2012-06-25T04:00:00-05:00"^^xsd:dateTime)

*/

void OwlInstancePrinter::printXmlDateTimeProp( /* ARGUMENTS                */
 const char * property,                /* name of property                 */
 XmlID * Name,                         /* name of individual with property */
 XmlDateTime * val,                    /* value of property                */
 FILE * outFile)                       /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:dateTime)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlDecimalProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlDecimal, for example:

DataPropertyAssertion(ktw:hasVector_K :empty_kit_tray_box_z_axis
                      "1.000000"^^xsd:decimal)

*/

void OwlInstancePrinter::printXmlDecimalProp( /* ARGUMENTS                */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlDecimal * val,                    /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:decimal)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlDoubleProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlDouble, for example:

DataPropertyAssertion(ktw:hasVector_K :empty_kit_tray_box_z_axis
                      "1.000000"^^xsd:decimal)

OWL does not use the XML double type, so XmlDouble is converted by this
function to xsd:decimal for printing OWL.

*/

void OwlInstancePrinter::printXmlDoubleProp( /* ARGUMENTS                 */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlDouble * val,                     /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:decimal)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlIDProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlID, for example:

DataPropertyAssertion(ktw:hasEndEffector_Id :part_gripper
                      "ThePartGripper"^^xsd:NMTOKEN)

OWL does not include xsd:ID, so xsd:NMTOKEN is used.

*/

void OwlInstancePrinter::printXmlIDProp(  /* ARGUMENTS                */
 const char * property,           /* name of property                 */
 XmlID * Name,                    /* name of individual with property */
 XmlID * val,                     /* value of property                */
 FILE * outFile)                  /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlIDREFProp

Returned Value: none

This prints a DataPropertyAssertion when the XML type of data is an
XmlIDREF, for example:

DataPropertyAssertion(ktw:hasLargeContainer_SkuRef :empty_kit_tray_box
                      "SkuIdKitBox"^^xsd:NMTOKEN)

OWL does not include xsd:IDREF, so xsd:NMTOKEN is used.

*/

void OwlInstancePrinter::printXmlIDREFProp( /* ARGUMENTS                */
 const char * property,             /* name of property                 */
 XmlID * Name,                      /* name of individual with property */
 XmlIDREF * val,                    /* value of property                */
 FILE * outFile)                    /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlNMTOKENProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlNMTOKEN, for example:

DataPropertyAssertion(ktw:hasLargeContainer_SerialNumber :empty_kit_tray_box
                      "4"^^xsd:NMTOKEN)

*/

void OwlInstancePrinter::printXmlNMTOKENProp( /* ARGUMENTS                */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlNMTOKEN * val,                    /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:NMTOKEN)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlNonNegativeIntegerProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlNonNegativeInteger, for example:

DataPropertyAssertion(ktw:hasPartsTray_Quantity :parts_tray_a
                      "1"^^xsd:nonNegativeInteger)

*/

void OwlInstancePrinter::printXmlNonNegativeIntegerProp( /* ARGUMENTS       */
 const char * property,                 /* name of property                 */
 XmlID * Name,                          /* name of individual with property */
 XmlNonNegativeInteger * val,           /* value of property                */
 FILE * outFile)                        /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:nonNegativeInteger)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlPositiveIntegerProp

Returned Value: none

Called By:
  VacuumEffectorMultiCupType::printOwl

This prints a DataPropertyAssertion when the type of data is an
XmlPositiveInteger, for example:

DataPropertyAssertion(ktw:hasLargeBoxWithKits_Capacity :kit_box
                      "8"^^xsd:positiveInteger)

*/

void OwlInstancePrinter::printXmlPositiveIntegerProp( /* ARGUMENTS       */
 const char * property,              /* name of property                 */
 XmlID * Name,                       /* name of individual with property */
 XmlPositiveInteger * val,           /* value of property                */
 FILE * outFile)                     /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:positiveInteger)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlStringProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlString, for example:

DataPropertyAssertion(ktw:hasEndEffector_Description :part_gripper
                      "small single cup vacuum effector"^^xsd:string)

*/

void OwlInstancePrinter::printXmlStringProp(  /* ARGUMENTS                */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlString * val,                     /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:string)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::printXmlTokenProp

Returned Value: none

This prints a DataPropertyAssertion when the type of data is an
XmlToken, for example:

DataPropertyAssertion(ktw:hasLargeContainer_SerialNumber :empty_kit_tray_box
                      "4"^^xsd:token)

*/

void OwlInstancePrinter::printXmlTokenProp(   /* ARGUMENTS                */
 const char * property,               /* name of property                 */
 XmlID * Name,                        /* name of individual with property */
 XmlToken * val,                      /* value of property                */
 FILE * outFile)                      /* file to print in                 */
{
  fprintf(outFile, "DataPropertyAssertion(%s :", property);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "                      \"");
  val->printSelf(outFile);
  fprintf(outFile, "\"^^xsd:token)\n");
}

/*********************************************************************/

/* OwlInstancePrinter::startIndi

Returned Value: none

This prints: 
1. a comment row of asterisks
2. a numbered comment with the type and instance name of what follows
   The number indicates the depth of nesting in the XML file.
3. a NamedIndividual statement
4. a ClassAssertion statement

For example:

// *****************************************
// 3 start LargeBoxWithEmptyKitTrays empty_kit_tray_supply
Declaration(NamedIndividual(:empty_kit_tray_supply))
ClassAssertion(ktw:LargeBoxWithEmptyKitTrays :empty_kit_tray_supply)

This will be followed by a set of related statements concerning the
named individual.

*/

void OwlInstancePrinter::startIndi( /* ARGUMENTS           */
 XmlID * Name,                      /* name of individual  */
 const char * aType,                /* type of individual  */
 FILE * outFile)                    /* file to print in    */
{
  fprintf(outFile, "\n//*****************************************\n");
  fprintf(outFile, "// %d start %s ", depth++, aType);
  Name->printSelf(outFile);
  fprintf(outFile, "\n");
  fprintf(outFile, "Declaration(NamedIndividual(:");
  Name->printSelf(outFile);
  fprintf(outFile, "))\n");
  fprintf(outFile, "ClassAssertion(%s :", aType);
  Name->printSelf(outFile);
  fprintf(outFile, ")\n");
}

/*********************************************************************/
