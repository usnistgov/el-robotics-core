/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */



/******************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/

/*

Attributes of XML schema items (element, sequence, complexType, etc.)
may be given in any order, and many are optional. To list in the rules
of a YACC production all the possibilities for a set of attributes is
prohibitively long when there are 4 or more attributes (3 attributes
has 16 possible combinations). Hence, for each schema item, attributes
are collected in a list by the YACC rule, and then the YACC action
calls a doXml...Attributes function that sorts the attributes out.
The C++ class for each schema item contains slots for all the
attributes.  When a schema item is recognized by its YACC rule, the
action first builds a C++ class instance with all of its slots
containing default values (all of which are 0 or some typed equivalent
of nothing).  Then it runs a doXml...Attributes function.  When the
doXml...Attributes function runs, some or all default values may be
replaced. After that function runs, other (non-attribute) slots are
filled in by the action.

The wg3Prefix saved by xmlSchema.lex does not include the colon.

The schema for schemas is
http://www.w3.org/TR/xmlschema-1/#element-attribute

This saves all allowed comments for possible reprinting. The use of
comments is restricted from what is normally allowed in an XML schema,
as follows.

1. Multiple comments may appear immediately after the first line of the
file (which gives the XML version).

2. Multiple comments may appear immediately before a key or keyref
   (annotations are not allowed there).

3. A single comment may appear instead of or immediately before
an annotation. As a result:
3A. where a single annotation is allowed, there may be any of:
 (1) an annotation
 (2) a single comment (of any length)
 (3) a comment followed by an annotation.
3B. where multiple annotations are allowed, there may be multiple comments,
  possibly mixed with annotations.

*/

#include <stdio.h>             // for stderr
#include <string.h>            // for strcat
#include <stdlib.h>            // for malloc, free
#include "xmlSchemaClasses.hh" // for xml classes
#include "xmlSchemaYACC.hh"    // for token values

#define YYERROR_VERBOSE
#define YYDEBUG 1
#define ERRSIZE 100

/********************************************************************/

int yyerror(const char * s);

extern int yylex();
#ifndef NOPATTERN
extern int yyreparse();
extern FILE * yyrein;
#endif

void checkXmlns(char * prefix, char * location);
void doXmlAnnotationAttributes(XmlAnnotation * note,
			       std::list<XmlAttribPair *> * atts);
void doXmlAppinfoAttributes(XmlAppinfo * appinfo,
			    std::list<XmlAttribPair *> * atts);
void doXmlAttributeLonerAttributes(XmlAttributeLoner * attDecl,
				  std::list<XmlAttribPair *> * atts);
void doXmlAttributeLonerRefableAttributes(XmlAttributeLonerRefable * attTop,
					 std::list<XmlAttribPair *> * atts);
void doXmlAttributeGroupAttributes(XmlAttributeGroup * grup,
				   std::list<XmlAttribPair *> * atts);
void doXmlAttributeGroupRefableAttributes(XmlAttributeGroupRefable * grup,
					  std::list<XmlAttribPair *> * atts);
void doXmlChoiceAttributes(XmlChoice * choi,
			   std::list<XmlAttribPair *> * atts);
void doXmlComplexContentAttributes(XmlComplexContent * comp,
				   std::list<XmlAttribPair *> * atts);
void doXmlComplexExtensionAttributes(XmlComplexRestriction * comp,
				     std::list<XmlAttribPair *> * atts);
void doXmlComplexRestrictionAttributes(XmlComplexRestriction * comp,
				       std::list<XmlAttribPair *> * atts);
void doXmlComplexTypeAttributes(XmlComplexType * comp,
				std::list<XmlAttribPair *> * atts);
void doXmlDocumentationAttributes(XmlDocumentation * docu,
				  std::list<XmlAttribPair *> * atts);
void doXmlElementGroupAttributes(XmlElementGroup * group,
				 std::list<XmlAttribPair *> * atts);
void doXmlElementGroupRefAttributes(XmlElementGroupRef * group,
				    std::list<XmlAttribPair *> * atts);
void doXmlElementLocalAttributes(XmlElementLocal * elem,
				 std::list<XmlAttribPair *> * atts);
void doXmlElementRefableAttributes(XmlElementRefable * elem,
			       std::list<XmlAttribPair *> * atts);
void doXmlEnumerationAttributes(XmlEnumeration * nume,
				std::list<XmlAttribPair *> * atts);
void doXmlFieldAttributes(XmlField * field,
			  std::list<XmlAttribPair *> * atts);
void doXmlKeyAttributes(XmlKey * key,
			std::list<XmlAttribPair *> * atts);
void doXmlKeyrefAttributes(XmlKeyref * keyref,
			   std::list<XmlAttribPair *> * atts);
void doXmlLengthAttributes(XmlLength * leng,
			   std::list<XmlAttribPair *> * atts);
void doXmlMaxExclusiveAttributes(XmlMaxExclusive * maxe,
				 std::list<XmlAttribPair *> * atts);
void doXmlMaxInclusiveAttributes(XmlMaxInclusive * maxi,
				 std::list<XmlAttribPair *> * atts);
void doXmlMaxLengthAttributes(XmlMaxLength * maxl,
			      std::list<XmlAttribPair *> * atts);
void doXmlMinExclusiveAttributes(XmlMinExclusive * mine,
				 std::list<XmlAttribPair *> * atts);
void doXmlMinInclusiveAttributes(XmlMinInclusive * mini,
				 std::list<XmlAttribPair *> * atts);
void doXmlMinLengthAttributes(XmlMaxLength * minl,
			      std::list<XmlAttribPair *> * atts);
void doXmlPatternAttributes(XmlPattern * pat,
			    std::list<XmlAttribPair *> * atts);
void doXmlSchemaHeaderAttributes(XmlSchemaHeader * header,
				 std::list<XmlAttribPair *> * atts);
void doXmlSelectorAttributes(XmlSelector * sel,
			     std::list<XmlAttribPair *> * atts);
void doXmlSequenceAttributes(XmlSequence * seq,
			     std::list<XmlAttribPair *> * atts);
void doXmlSimpleContentAttributes(XmlSimpleContent * cont,
				  std::list<XmlAttribPair *> * atts);
void doXmlSimpleContentExtensionAttributes(XmlSimpleContentExtension * extend,
				    std::list<XmlAttribPair *> * atts);
void doXmlSimpleContentRestrictionAttributes(XmlSimpleContentRestriction * rest,
					     std::list<XmlAttribPair *> * atts);
void doXmlSimpleListAttributes(XmlSimpleList * liz,
			       std::list<XmlAttribPair *> * atts);
void doXmlSimpleRestrictionAttributes(XmlSimpleRestriction * rest,
				      std::list<XmlAttribPair *> * atts);
void doXmlSimpleTypeAttributes(XmlSimpleType * simp,
			       std::list<XmlAttribPair *> * atts);
void doXmlUniqueAttributes(XmlUnique * unique,
			std::list<XmlAttribPair *> * atts);

/********************************************************************/

char lexMessage[80]; // for communication with xmlSchema.lex
char commentString[40000]; // for communication with xmlSchema.lex
XmlSchemaFile * xmlSchemaFile; // the parse tree
char * globalOwlPrefix;
static char errMessage[ERRSIZE];

/*

The attNames (attribute names) array exists so that it is easy to 
print the names of attributes. Only the names in camel case are
used. The other names are in the array so that token values can be
used for indexing it. The names in the array are the same as those
of the tokens, except for case.

*/

static const char * attNames[] =
  {
    "abstract",
    "attributeFormDefault",
    "BAD",
    "base",
    "default",
    "elementFormDefault",
    "ENCODING",
    "ENDCOMMENT",
    "ENDITEM",
    "ENDWHOLEITEM",
    "ENDVERSION",
    "final",
    "fixed",
    "form",
    "id",
    "itemType",
    "maxOccurs",
    "minOccurs",
    "mixed",
    "name",
    "nillable",
    "ref",
    "refer",
    "schemaLocation",
    "source",
    "STARTANNOTATION",
    "STARTCOMMENT",
    "STARTINITEM",
    "STARTOUTITEM",
    "STARTVERSION",
    "substitutionGroup",
    "targetNamespace",
    "TERMINALSTRING",
    "type",
    "use",
    "value",
    "version",
    "xpath",
    "XMLNSPREFIX",
    "XSANNOTATION",
    "XSAPPINFO",
    "XSATTRIBUTE",
    "XSATTRIBUTEGROUP",
    "XSCHOICE",
    "XSCOMPLEXCONTENT",
    "XSCOMPLEXTYPE",
    "XSDOCUMENTATION",
    "XSELEMENT",
    "XSENUMERATION",
    "XSEXTENSION",
    "XSFIELD",
    "XSGROUP",
    "XSINCLUDE",
    "XSKEY",
    "XSKEYREF",
    "XSLENGTH",
    "XSLIST",
    "XSMAXEXCLUSIVE",
    "XSMAXINCLUSIVE",
    "XSMAXLENGTH",
    "XSMINEXCLUSIVE",
    "XSMININCLUSIVE",
    "XSMINLENGTH",
    "XSPATTERN",
    "XSRESTRICTION",
    "XSSCHEMA",
    "XSSELECTOR",
    "XSSEQUENCE",
    "XSSIMPLECONTENT",
    "XSSIMPLETYPE",
    "XMLVERSION"
  };

/********************************************************************/

/* checkXmlns

This checks that exactly one of the prefixes on the prefixList, is the
same as the XmlCppBase::wg3Prefix and is the prefix for
http://www.w3.org/2001/XMLSchema. It also checks that no other prefix
is the prefix for http://www.w3.org/2001/XMLSchema. If there is any
error, this prints an error message and exits.

The XmlCppBase::wg3Prefix (usually xs or xsd) gets set when the schema
line (usually the second line of the file) gets read.

*/

void checkXmlns(                      /* ARGUMENTS                   */
 std::list<XmlNsPair *> * prefixList) /* list of XmlNsPairs to check */
{
  
  char * prefix;
  std::list<XmlNsPair *>::iterator iter;
  bool foundWg3;

  foundWg3 = false;
  for (iter = prefixList->begin(); iter != prefixList->end(); iter++)
    {
      prefix = (*iter)->prefix;
      if (prefix && (strcmp(XmlCppBase::wg3Prefix, prefix) == 0))
	{ // this prefix is the wg3Prefix
	  if (foundWg3)
	    { // the wg3Prefix was already found
	      snprintf(errMessage, ERRSIZE, "wg3 prefix \"%s\" used twice",
		       XmlCppBase::wg3Prefix);
	      yyerror(errMessage);
	    }
	  else
	    {
	      foundWg3 = true;
	      if (strcmp("http://www.w3.org/2001/XMLSchema", (*iter)->location))
		{
		  snprintf(errMessage, ERRSIZE,
			   "xmlns location for xml schema must be\n"
			   "http://www.w3.org/2001/XMLSchema but is %s",
			   (*iter)->location);
		  yyerror(errMessage);
		}
	    }
	}
      else if (strcmp("http://www.w3.org/2001/XMLSchema", (*iter)->location)
	       == 0)
	{
	  snprintf(errMessage, ERRSIZE,
		   "prefix for http://www.w3.org/2001/XMLSchema \n"
		   "must be %s but is %s", XmlCppBase::wg3Prefix, prefix);
	  yyerror(errMessage);
	}
    }
  if (!foundWg3)
    {
      snprintf(errMessage, ERRSIZE,
	       "prefix %s for http://www.w3.org/2001/XMLSchema not found",
	       XmlCppBase::wg3Prefix);
      yyerror(errMessage);
    }
}

/********************************************************************/

/*

There follow a number of doXml...Attributes functions. In some of
these, the prefix in the attribute pair (which is really a triple, not a
pair) is transcribed into a class instance. The value of the prefix is
not checked. In particular, a zero value is OK.

*/

/********************************************************************/

void doXmlAnnotationAttributes(
 XmlAnnotation * note,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (note->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in annotation");
	      yyerror(errMessage);
	    }
	  note->id = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, 
		   "bad attribute name \"%s\" in annotation",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

void doXmlAppinfoAttributes(
 XmlAppinfo * appinfo,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == SOURCE)
	{
	  appinfo->source = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in appinfo",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}
 
/********************************************************************/

/* doXmlAttributeLonerAttributes

If an XmlAttributeLoner has ref, it must not have name, typ, typPrefix,
or simple.

*/

void doXmlAttributeLonerAttributes(
 XmlAttributeLoner * attDecl,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (attDecl->id)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "id used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  attDecl->id = (*iter)->val;
	}
      else if ((*iter)->name == DEFALT)
	{
	  if (attDecl->defalt)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "default used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  attDecl->defalt = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (attDecl->fixed)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "fixed used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  attDecl->fixed = (*iter)->val;
	}
      else if ((*iter)->name == FORM)
	{
	  if (strcmp((*iter)->val, "qualified") == 0)
	    attDecl->form = XmlCppBase::qualified;
	  else if (strcmp((*iter)->val, "unqualified") == 0)
	    attDecl->form = XmlCppBase::unqualified;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad form value \"%s\" in attribute declaration",
		       (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == NAME)
	{
	  if (attDecl->name)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "name used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  attDecl->name = (*iter)->val;
	  attDecl->newNameRef = XmlCppBase::modifyName(attDecl->name);
	}
      else if ((*iter)->name == REF)
	{
	  if (attDecl->ref)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "ref used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  attDecl->ref = (*iter)->val;
	  attDecl->newNameRef = XmlCppBase::modifyName(attDecl->ref);
	}
      else if ((*iter)->name == TYP)
	{
	  if (attDecl->typ)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "type used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  attDecl->typPrefix = (*iter)->pref;
	  attDecl->typ = (*iter)->val;
	  attDecl->newTyp = XmlCppBase::modifyName(attDecl->typ);
	}
      else if ((*iter)->name == USE)
	{
	  if (attDecl->use != XmlCppBase::useNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "use used twice in attribute declaration");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "required") == 0)
	    attDecl->use = XmlCppBase::required;
	  else if (strcmp((*iter)->val, "optional") == 0)
	    attDecl->use = XmlCppBase::optional;
	  else if (strcmp((*iter)->val, "prohibited") == 0)
	    attDecl->use = XmlCppBase::prohibited;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad use value \"%s\" in attribute declaration",
		       (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in attribute declaration",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if ((attDecl->name == 0) && (attDecl->ref == 0))
    yyerror("XML attribute must have name or ref");
  else if (attDecl->ref)
    {
      if (attDecl->name)
	yyerror("XML attribute must not have name and ref");
      if (attDecl->typPrefix || attDecl->typ)
	yyerror("XML attribute must not have type and ref");
      if (attDecl->simple)
	yyerror("XML attribute must not have simple type and ref");
    }
  if (attDecl->defalt && attDecl->fixed)
    yyerror("XML attribute must not have both default and fixed");
}

/********************************************************************/

/* doXmlAttributeLonerRefableAttributes

According to the section at 
in http://www.w3.org/TR/xmlschema-1 which is the schema for schemas:
ref, use, and form are not allowed, and name is required.

*/

void doXmlAttributeLonerRefableAttributes(
 XmlAttributeLonerRefable * attTop,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == DEFALT)
	{
	  if (attTop->defalt)
	    {
	      snprintf(errMessage, ERRSIZE, "default used twice in attribute");
	      yyerror(errMessage);
	    }
	  attTop->defalt = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (attTop->fixed)
	    {
	      snprintf(errMessage, ERRSIZE, "fixed used twice in attribute");
	      yyerror(errMessage);
	    }
	  attTop->fixed = (*iter)->val;
	}
      else if ((*iter)->name == ID)
	{
	  if (attTop->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in attribute");
	      yyerror(errMessage);
	    }
	  attTop->id = (*iter)->val;
	}
       else if ((*iter)->name == NAME)
	{
	  if (attTop->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in attribute");
	      yyerror(errMessage);
	    }
	  attTop->name = (*iter)->val;
	}
      else if ((*iter)->name == TYP)
	{
	  if (attTop->typ)
	    {
	      snprintf(errMessage, ERRSIZE, "type used twice in attribute");
	      yyerror(errMessage);
	    }
	  attTop->typPrefix = (*iter)->pref;
	  attTop->typ = (*iter)->val;
          attTop->newTyp = XmlCppBase::modifyName(attTop->typ);
	}
     else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in attribute declaration",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (attTop->defalt && attTop->fixed)
    yyerror("XML global attribute may not have both default and fixed");
  if (attTop->name == 0)
    yyerror("XML global attribute must have name");
}

/********************************************************************/

/* doXmlAttributeGroupAttributes

*/

void doXmlAttributeGroupAttributes(
 XmlAttributeGroup * grup,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (grup->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in attributeGroup");
	      yyerror(errMessage);
	    }
	  grup->id = (*iter)->val;
	}
      else if ((*iter)->name == REF)
	{
	  if (grup->ref)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "ref used twice in attributeGroup");
	      yyerror(errMessage);
	    }
	  grup->ref = (*iter)->val;
	}
     else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in attributeGroup",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (grup->ref == 0)
    yyerror("attribute group reference must have ref");
}

/********************************************************************/

/* doXmlAttributeGroupRefableAttributes

*/

void doXmlAttributeGroupRefableAttributes(
 XmlAttributeGroupRefable * grup,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (grup->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in attributeGroup");
	      yyerror(errMessage);
	    }
	  grup->id = (*iter)->val;
	}
      else if ((*iter)->name == NAME)
	{
	  if (grup->name)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "name used twice in attributeGroup");
	      yyerror(errMessage);
	    }
	  grup->name = (*iter)->val;
	}
     else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in attributeGroup",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (grup->name == 0)
    yyerror("attribute group definition must have name");
}

/********************************************************************/

void doXmlChoiceAttributes(
 XmlChoice * choi,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (choi->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in choice");
	      yyerror(errMessage);
	    }
	  choi->id = (*iter)->val;
	}
      else if ((*iter)->name == MAXOCCURS)
	{
	  if (choi->maxOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE, "maxOccurs used twice in choice");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "unbounded") == 0)
	    choi->maxOccurs = -1;
	  else
	    choi->maxOccurs = atoi((*iter)->val);
	}
      else if ((*iter)->name == MINOCCURS)
	{
	  if (choi->minOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE, "minOccurs used twice in choice");
	      yyerror(errMessage);
	    }
	  choi->minOccurs = atoi((*iter)->val);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, "bad attribute name \"%s\" in choice",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

void doXmlComplexContentAttributes(
 XmlComplexContent * comp,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (comp->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in complexContent");
	      yyerror(errMessage);
	    }
	  comp->id = (*iter)->val;
	}
      else if ((*iter)->name == MIXED)
	{
	  if (comp->mixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "mixed used twice in complexContent");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    comp->mixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    comp->mixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad mixed \"%s\" in complexContent", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in complexContent",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

void doXmlComplexExtensionAttributes(
 XmlComplexExtension * comp,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (comp->id)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "id used twice in complexExtension");
	      yyerror(errMessage);
	    }
	  comp->id = (*iter)->val;
	}
      else if ((*iter)->name == BASE)
	{
	  if (comp->base)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "base used twice in complexExtension");
	      yyerror(errMessage);
	    }
	  comp->basePrefix = (*iter)->pref;
	  comp->base = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in complexExtension",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (comp->base == 0)
    yyerror("complexExtension must have base");
}

/********************************************************************/

void doXmlComplexRestrictionAttributes(
 XmlComplexRestriction * comp,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (comp->id)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "id used twice in complexRestriction");
	      yyerror(errMessage);
	    }
	  comp->id = (*iter)->val;
	}
      else if ((*iter)->name == BASE)
	{
	  if (comp->base)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "base used twice in complexRestriction");
	      yyerror(errMessage);
	    }
	  comp->base = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in complexRestriction",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (comp->base == 0)
    yyerror("complexRestriction must have base");
}

/********************************************************************/

/*

In addition to checking the attributes of an XmlComplexType, this sets
the value of owlPrefix of the XmlComplexType to the current value of
the globalOwlPrefix, which may be the empty string ("") or a prefix
with some characters.

*/

void doXmlComplexTypeAttributes(
 XmlComplexType * comp,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == NAME)
	{
	  if (comp->name)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "name used twice in complex type");
	      yyerror(errMessage);
	    }
	  comp->name = (*iter)->val;
	  comp->newName = XmlCppBase::modifyName(comp->name);
	}
      else if ((*iter)->name == ABSTRACT)
	{
	  if (comp->abstract != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "abstract used twice in complex type");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "true") == 0)
	    comp->abstract = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    comp->abstract = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad abstract \"%s\" in complexType", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == MIXED)
	{
	  if (comp->mixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "mixed used twice in complexType");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    comp->mixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    comp->mixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad mixed \"%s\" in complexType", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in complexType",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  comp->owlPrefix = globalOwlPrefix;
}

/********************************************************************/

/* doXmlDocumentationAttributes

This checks the attributes of an XmlDocumentation and sets the
globalOwlPrefix if it is the empty string and the XmlDocumentation
has a value for it.

The only attribute allowed for an XmlDocumentation is a SOURCE attribute.

In addition to checking the attributes of an XmlDocumentation, this
deals with an owlPrefix if one is given. If one is given, it should
occur in a documentation node in an XmlAnnotation immediately
following the schema header and be of the form
<xs:documentation>owlPrefix=XXX</xs:documentation>, where XXX is
the OWL prefix.

*/

void doXmlDocumentationAttributes(
 XmlDocumentation * docu,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == SOURCE)
	{
	  docu->source = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in documentation",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if ((globalOwlPrefix[0] == 0) && (strncmp(docu->text, "owlPrefix=", 10) == 0))
    {
      globalOwlPrefix = strdup(docu->text + 10);
    }
}
 
/********************************************************************/

/* doXmlElementGroupAttributes

*/

void doXmlElementGroupAttributes(
 XmlElementGroup * group,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == NAME)
	{
	  if (group->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in element group");
	      yyerror(errMessage);
	    }
	  group->name = (*iter)->val;
	  group->newName = XmlCppBase::modifyName(group->name);
	}
      else if ((*iter)->name == ID)
	{
	  if (group->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in element group");
	      yyerror(errMessage);
	    }
	  group->id = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in element group",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

/* doXmlElementGroupRefAttributes

*/

void doXmlElementGroupRefAttributes(
 XmlElementGroupRef * group,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == REF)
	{
	  if (group->ref)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in element group");
	      yyerror(errMessage);
	    }
	  group->ref = (*iter)->val;
	}
      else if ((*iter)->name == ID)
	{
	  if (group->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in element group");
	      yyerror(errMessage);
	    }
	  group->id = (*iter)->val;
	}
      else if ((*iter)->name == MAXOCCURS)
	{
	  if (group->maxOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "maxOccurs used twice in element group ref");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "unbounded") == 0)
	    group->maxOccurs = -1;
	  else
	    group->maxOccurs = atoi((*iter)->val);
	}
      else if ((*iter)->name == MINOCCURS)
	{
	  if (group->minOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "minOccurs used twice in element group ref");
	      yyerror(errMessage);
	    }
	  group->minOccurs = atoi((*iter)->val);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in element group ref",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

/* doXmlElementLocalAttributes

The checks of illegal combinations of attributes have to wait until all
the attributes have been recorded.

The only attributes allowed with ref are minOccurs, maxOccurs, and id.

*/

void doXmlElementLocalAttributes(
 XmlElementLocal * elem,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == DEFALT)
	{
	  if (elem->defalt)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "default used twice in local element");
	      yyerror(errMessage);
	    }
	  if (elem->fixed)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "cannot have both default and fixed in local element");
	      yyerror(errMessage);
	    }
	  elem->defalt = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (elem->fixed)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "fixed used twice in local element");
	      yyerror(errMessage);
	    }
	  if (elem->defalt)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "cannot have both default and fixed in local element");
	      yyerror(errMessage);
	    }
	  elem->fixed = (*iter)->val;
	}
      else if ((*iter)->name == FORM)
	{
	  if (elem->form != XmlCppBase::formNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "form used twice in local element");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "qualified") == 0)
	    elem->form = XmlCppBase::qualified;
	  else if (strcmp((*iter)->val, "unqualified") == 0)
	    elem->form = XmlCppBase::unqualified;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad form value \"%s\" in local element",
		       (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == NAME)
	{ // ref checked at end of function
	  if (elem->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in local element");
	      yyerror(errMessage);
	    }
	  elem->name = (*iter)->val;
	  elem->newName = XmlCppBase::modifyName(elem->name);
	}
      else if ((*iter)->name == TYP)
	{ // ref checked at end of function
	  if (elem->typ)
	    {
	      snprintf(errMessage, ERRSIZE, "type used twice in local element");
	      yyerror(errMessage);
	    }
	  elem->typPrefix = (*iter)->pref;
	  elem->typ = (*iter)->val;
	  elem->newTyp = XmlCppBase::modifyName(elem->typ);
	}
      else if ((*iter)->name == REF)
	{  // name checked at end of function
	  if (elem->ref)
	    {
	      snprintf(errMessage, ERRSIZE, "ref used twice in local element");
	      yyerror(errMessage);
	    }
	  elem->ref = (*iter)->val;
	  elem->newName = XmlCppBase::modifyName(elem->ref);
	}
      else if ((*iter)->name == ID)
	{
	  if (elem->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in local element");
	      yyerror(errMessage);
	    }
	  elem->id = (*iter)->val;
	}
      else if ((*iter)->name == MAXOCCURS)
	{
	  if (elem->maxOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "maxOccurs used twice in local element");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "unbounded") == 0)
	    elem->maxOccurs = -1;
	  else
	    elem->maxOccurs = atoi((*iter)->val);
	}
      else if ((*iter)->name == MINOCCURS)
	{
	  if (elem->minOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "minOccurs used twice in local element");
	      yyerror(errMessage);
	    }
	  elem->minOccurs = atoi((*iter)->val);
	}
      else if ((*iter)->name == NILLABLE)
	{
	  if (elem->nillable != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "nillable used twice in local element");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    elem->nillable = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    elem->nillable = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad nillable \"%s\" in local element",
		      (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in local element",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if ((elem->ref == 0) && (elem->name == 0))
    {
      snprintf(errMessage, ERRSIZE,
	       "local element must have either name or ref");
      yyerror(errMessage);
    }
  if (elem->ref && (elem->defalt ||
		    elem->fixed  ||
		    elem->form  ||
		    elem->typ    ||
		    elem->name   ||
		    (elem->nillable && (elem->nillable == XmlCppBase::yes))))
    {
      snprintf(errMessage, ERRSIZE,
	       "illegal attribute with ref %s in local element", (*iter)->val);
      yyerror(errMessage);
    }
  if (elem->defalt && elem->fixed)
    yyerror("XML local element may not have both default and fixed");
}

/********************************************************************/

void doXmlElementRefableAttributes(
 XmlElementRefable * elem,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ABSTRACT)
	{
	  if (strcmp((*iter)->val, "true") == 0)
	    elem->abstract = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    elem->abstract = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad abstract \"%s\"", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == DEFALT)
	{
	  if (elem->defalt)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "default used twice in global element");
	      yyerror(errMessage);
	    }
	  elem->defalt = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (elem->fixed)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "fixed used twice in global element");
	      yyerror(errMessage);
	    }
	  elem->fixed = (*iter)->val;
	}
      else if ((*iter)->name == NAME)
	{
	  if (elem->name)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "name used twice in global element");
	      yyerror(errMessage);
	    }
	  elem->name = (*iter)->val;
	  elem->newName = XmlCppBase::modifyName(elem->name);
	}
      else if ((*iter)->name == NILLABLE)
	{
	  if (elem->nillable != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "nillable used twice in global element");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    elem->nillable = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    elem->nillable = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad nillable \"%s\"", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == TYP)
	{
	  if (elem->typ)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "type used twice in global element");
	      yyerror(errMessage);
	    }
	  elem->typPrefix = (*iter)->pref;
	  elem->typ = (*iter)->val;
	  elem->newTyp = XmlCppBase::modifyName(elem->typ);
	}
      else if ((*iter)->name == ID)
	{
	  if (elem->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in global element");
	      yyerror(errMessage);
	    }
	  elem->id = (*iter)->val;
	}
      else if ((*iter)->name == SUBSTITUTIONGROUP)
	{
	  if (elem->substitutionGroup)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "substitutionGroup used twice in global element");
	      yyerror(errMessage);
	    }
	  elem->substitutionGroup = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in global element",
		  attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (elem->name == 0)
    yyerror("name missing in global element");
  if (elem->defalt && elem->fixed)
    yyerror("XML global element may not have both default and fixed");
}

/********************************************************************/

void doXmlEnumerationAttributes(
 XmlEnumeration * nume,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (nume->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in enumeration");
	      yyerror(errMessage);
	    }
	  nume->id = (*iter)->val;
	}
      else if ((*iter)->name == VALUE)
	{
	  if (nume->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in enumeration");
	      yyerror(errMessage);
	    }
	  nume->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in enumeration",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (nume->value == 0)
    yyerror("value missing in enumeration");
}

/********************************************************************/

void doXmlFieldAttributes(
 XmlField * field,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == XPATH)
	{
	  if (field->xpath)
	    {
	      snprintf(errMessage, ERRSIZE, "xpath used twice in field");
	      yyerror(errMessage);
	    }
	  field->xpath = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, "bad attribute name \"%s\" in field",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (field->xpath == 0)
    yyerror("xpath missing in field");
}

/********************************************************************/

void doXmlKeyAttributes(
 XmlKey * key,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (key->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in key");
	      yyerror(errMessage);
	    }
	  key->id = (*iter)->val;
	}
      else if ((*iter)->name == NAME)
	{
	  if (key->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in key");
	      yyerror(errMessage);
	    }
	  key->name = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, "bad attribute name \"%s\" in key",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (key->name == 0)
    yyerror("name missing in key");
}

/********************************************************************/

void doXmlKeyrefAttributes(
 XmlKeyref * keyref,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (keyref->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in keyref");
	      yyerror(errMessage);
	    }
	  keyref->id = (*iter)->val;
	}
      else if ((*iter)->name == NAME)
	{
	  if (keyref->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in keyref");
	      yyerror(errMessage);
	    }
	  keyref->name = (*iter)->val;
	}
      else if ((*iter)->name == REFER)
	{
	  if (keyref->refer)
	    {
	      snprintf(errMessage, ERRSIZE, "refer used twice in keyref");
	      yyerror(errMessage);
	    }
	  keyref->refer = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, "bad attribute name \"%s\" in keyref",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (keyref->name == 0)
    yyerror("name missing in keyref");
  if (keyref->refer == 0)
    yyerror("refer missing in keyref");
}

/********************************************************************/

/* doXmlLengthAttributes

This checks and sets the values of the attributes of an XmlLength.
If an attribute is used that is not allowed for XmlLength, this
exits.

This also sets the value of intVal by converting the value, which is a
string that must represent an unsigned integer.

*/

void doXmlLengthAttributes(
 XmlLength * leng,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (leng->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in length");
	      yyerror(errMessage);
	    }
	  leng->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (leng->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE, "fixed used twice in length");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    leng->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    leng->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in length", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (leng->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in length");
	      yyerror(errMessage);
	    }
	  leng->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in length",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (leng->value == 0)
    yyerror("value missing in length");
  if (sscanf(leng->value, "%u", &(leng->intVal)) == 0)
    {
      snprintf(errMessage, ERRSIZE,
	       "bad length value \"%s\"  in length", leng->value);
      yyerror(errMessage);
    }
}

/********************************************************************/

void doXmlMaxExclusiveAttributes(
 XmlMaxExclusive * maxe,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (maxe->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in maxExclusive");
	      yyerror(errMessage);
	    }
	  maxe->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (maxe->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE, "fixed used twice in maxExclusive");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    maxe->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    maxe->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in maxExclusive", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (maxe->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in maxExclusive");
	      yyerror(errMessage);
	    }
	  maxe->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in maxExclusive",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (maxe->value == 0)
    yyerror("value missing in maxExclusive");
}

/********************************************************************/

void doXmlMaxInclusiveAttributes(
 XmlMaxInclusive * maxi,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (maxi->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in maxInclusive");
	      yyerror(errMessage);
	    }
	  maxi->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (maxi->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE, "fixed used twice in maxInclusive");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    maxi->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    maxi->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in maxInclusive", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (maxi->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in maxInclusive");
	      yyerror(errMessage);
	    }
	  maxi->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in maxInclusive",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (maxi->value == 0)
    yyerror("value missing in maxInclusive");
}

/********************************************************************/

/* doXmlMaxLengthAttributes

This checks and sets the values of the attributes of an XmlMaxLength.
If an attribute is used that is not allowed for XmlMaxLength, this
exits.

This also sets the value of intVal by converting the value, which is a
string that must represent an unsigned integer.

*/

void doXmlMaxLengthAttributes(
 XmlMaxLength * maxl,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (maxl->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in maxLength");
	      yyerror(errMessage);
	    }
	  maxl->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (maxl->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE, "fixed used twice in maxLength");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    maxl->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    maxl->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in maxLength", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (maxl->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in maxLength");
	      yyerror(errMessage);
	    }
	  maxl->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in maxLength",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (maxl->value == 0)
    yyerror("value missing in maxLength");
  if (sscanf(maxl->value, "%u", &(maxl->intVal)) == 0)
    {
      snprintf(errMessage, ERRSIZE,
	       "bad length value \"%s\"  in maxLength", maxl->value);
      yyerror(errMessage);
    }
}

/********************************************************************/

void doXmlMinExclusiveAttributes(
 XmlMinExclusive * mine,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (mine->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in minExclusive");
	      yyerror(errMessage);
	    }
	  mine->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (mine->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "fixed used twice in minExclusive");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    mine->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    mine->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in minExclusive", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (mine->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in minExclusive");
	      yyerror(errMessage);
	    }
	  mine->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in minExclusive",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (mine->value == 0)
    yyerror("value missing in minExclusive");
}

/********************************************************************/

void doXmlMinInclusiveAttributes(
 XmlMinInclusive * mini,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (mini->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in minInclusive");
	      yyerror(errMessage);
	    }
	  mini->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (mini->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "fixed used twice in minInclusive");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "true") == 0)
	    mini->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    mini->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in minInclusive", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (mini->value)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "value used twice in minInclusive");
	      yyerror(errMessage);
	    }
	  mini->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in minInclusive",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (mini->value == 0)
    yyerror("value missing in minInclusive");
}

/********************************************************************/

/* doXmlMinLengthAttributes

This checks and sets the values of the attributes of an XmlMinLength.
If the value is missing or an attribute is used that is not allowed
for XmlMinLength, this exits.

This also sets the value of intVal by converting the value, which is a
string that must represent an unsigned integer.

*/

void doXmlMinLengthAttributes(
 XmlMinLength * minl,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (minl->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in minLength");
	      yyerror(errMessage);
	    }
	  minl->id = (*iter)->val;
	}
      else if ((*iter)->name == FIXED)
	{
	  if (minl->fixed != XmlCppBase::logicalNone)
	    {
	      snprintf(errMessage, ERRSIZE, "fixed used twice in minLength");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "true") == 0)
	    minl->fixed = XmlCppBase::yes;
	  else if (strcmp((*iter)->val, "false") == 0)
	    minl->fixed = XmlCppBase::no;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad fixed \"%s\" in minLength", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == VALUE)
	{
	  if (minl->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in minLength");
	      yyerror(errMessage);
	    }
	  minl->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in minLength",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (minl->value == 0)
    yyerror("value missing in minLength");
  if (sscanf(minl->value, "%u", &(minl->intVal)) == 0)
    {
      snprintf(errMessage, ERRSIZE,
	       "bad length value \"%s\"  in minLength", minl->value);
      yyerror(errMessage);
    }
}

/********************************************************************/

void doXmlPatternAttributes(
 XmlPattern * pat,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  FILE * patFile = 0;

  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (pat->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in pattern");
	      yyerror(errMessage);
	    }
	  pat->id = (*iter)->val;
	}
      else if ((*iter)->name == VALUE)
	{
	  if (pat->value)
	    {
	      snprintf(errMessage, ERRSIZE, "value used twice in pattern");
	      yyerror(errMessage);
	    }
	  pat->value = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, "bad attribute name \"%s\" in pattern",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (pat->value == 0)
    {
      yyerror("value missing in pattern");
    }
#ifndef NOPATTERN
  else
    {
      patFile = fopen("tempPatFile", "w");
      if (patFile == 0)
	{
	  fprintf(stderr, "cannot open tempPatFile for writing\n");
	  exit(1);
	}
      fprintf(patFile, "\"%s\"", pat->value);
      fclose(patFile);
      yyrein = fopen("tempPatFile", "r");
      if (yyreparse())
	{
	  fprintf(stderr, "pattern value %s is bad\n", pat->value);
	  exit(1);
	}
      fclose(yyrein);
    }
#endif
}

/********************************************************************/

void doXmlSchemaHeaderAttributes(
 XmlSchemaHeader * header,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (header->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in header");
	      yyerror(errMessage);
	    }
	  header->id = (*iter)->val;
	}
      else if ((*iter)->name == VERSION)
	{
	  if (header->version)
	    {
	      snprintf(errMessage, ERRSIZE, "version used twice in header");
	      yyerror(errMessage);
	    }
	  header->version = (*iter)->val;
	}
      else if ((*iter)->name == ATTRIBUTEFORMDEFAULT)
	{
	  if (header->attributeFormDefault != XmlCppBase::formNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "attributeFormDefault used twice in header");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "qualified") == 0)
	    header->attributeFormDefault = XmlCppBase::qualified;
	  else if (strcmp((*iter)->val, "unqualified") == 0)
	    header->attributeFormDefault = XmlCppBase::unqualified;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad attributeFormDefault \"%s\"", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == ELEMENTFORMDEFAULT)
	{
	  if (header->elementFormDefault != XmlCppBase::formNone)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "elementFormDefault used twice in header");
	      yyerror(errMessage);
	    }
	  else if (strcmp((*iter)->val, "qualified") == 0)
	    header->elementFormDefault = XmlCppBase::qualified;
	  else if (strcmp((*iter)->val, "unqualified") == 0)
	    header->elementFormDefault = XmlCppBase::unqualified;
	  else
	    {
	      snprintf(errMessage, ERRSIZE,
		       "bad elementFormDefault \"%s\"", (*iter)->val);
	      yyerror(errMessage);
	    }
	}
      else if ((*iter)->name == TARGETNAMESPACE)
	{
	  if (header->targetNamespace)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "targetNamespace used twice in header");
	      yyerror(errMessage);
	    }
	  if ((*iter)->pref)
	    yyerror("bug: targetNamespace should not have prefix");
	  header->targetNamespace = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in schema header",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

void doXmlSelectorAttributes(
 XmlSelector * sel,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == XPATH)
	{
	  if (sel->xpath)
	    {
	      snprintf(errMessage, ERRSIZE, "xpath used twice in selector");
	      yyerror(errMessage);
	    }
	  sel->xpath = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in selector",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (sel->xpath == 0)
    yyerror("xpath missing in selector");
}

/********************************************************************/

void doXmlSequenceAttributes(
 XmlSequence * seq,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (seq->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in sequence");
	      yyerror(errMessage);
	    }
	  seq->id = (*iter)->val;
	}
      else if ((*iter)->name == MAXOCCURS)
	{
	  if (seq->maxOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "maxOccurs used twice in sequence");
	      yyerror(errMessage);
	    }
	  if (strcmp((*iter)->val, "unbounded") == 0)
	    seq->maxOccurs = -1;
	  else
	    seq->maxOccurs = atoi((*iter)->val);
	}
      else if ((*iter)->name == MINOCCURS)
	{
	  if (seq->minOccurs != -2)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "minOccurs used twice in sequence");
	      yyerror(errMessage);
	    }
	  seq->minOccurs = atoi((*iter)->val);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in sequence",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}

/********************************************************************/

void doXmlSimpleContentAttributes(
 XmlSimpleContent * cont,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (cont->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in simpleContent");
	      yyerror(errMessage);
	    }
	  cont->id = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in simpleContent",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
}


/********************************************************************/

void doXmlSimpleContentExtensionAttributes(
 XmlSimpleContentExtension * extend,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (extend->id)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "id used twice in simple content extension");
	      yyerror(errMessage);
	    }
	  extend->id = (*iter)->val;
	}
      else if ((*iter)->name == BASE)
	{
	  if (extend->base)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "base used twice in simple content extension");
	      yyerror(errMessage);
	    }
	  extend->basePrefix = (*iter)->pref;
	  extend->base = (*iter)->val;
	  extend->newBase = XmlCppBase::modifyName(extend->base);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in simple content extension",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (extend->base == 0)
    yyerror("simpleContentExtension must have base");
}

/********************************************************************/

void doXmlSimpleContentRestrictionAttributes(
 XmlSimpleContentRestriction * rest,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (rest->id)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "id used twice in simple content restriction");
	      yyerror(errMessage);
	    }
	  rest->id = (*iter)->val;
	}
      else if ((*iter)->name == BASE)
	{
	  if (rest->base)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "base used twice in simple content restriction");
	      yyerror(errMessage);
	    }
	  rest->basePrefix = (*iter)->pref;
	  rest->base = (*iter)->val;
	  rest->newBase = XmlCppBase::modifyName(rest->base);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in simple content restriction",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (rest->base == 0)
    yyerror("simpleContentRestriction must have base");
}

/********************************************************************/

/* doXmlSimpleListAttributes

This exits if itemType is missing. The rules for XML schema and the
XmlSimpleList class allow an embedded type definition, but we are handling
only venetian blind format schemas, which (by definition) do not have
embedded types.

*/

void doXmlSimpleListAttributes(
 XmlSimpleList * liz,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (liz->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in simple list");
	      yyerror(errMessage);
	    }
	  liz->id = (*iter)->val;
	}
      else if ((*iter)->name == ITEMTYPE)
	{
	  if (liz->itemType)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "item type used twice in simple list");
	      yyerror(errMessage);
	    }
	  liz->typePrefix = (*iter)->pref;
	  liz->itemType = (*iter)->val;
	  liz->newItemType = XmlCppBase::modifyName(liz->itemType);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in simple list",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (liz->itemType == 0)
    yyerror("simpleList must have item type");
}

/********************************************************************/

void doXmlSimpleRestrictionAttributes(
 XmlSimpleRestriction * rest,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (rest->id)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "id used twice in simple restriction");
	      yyerror(errMessage);
	    }
	  rest->id = (*iter)->val;
	}
      else if ((*iter)->name == BASE)
	{
	  if (rest->base)
	    {
	      snprintf(errMessage, ERRSIZE,
		       "base used twice in simple restriction");
	      yyerror(errMessage);
	    }
	  rest->basePrefix = (*iter)->pref;
	  rest->base = (*iter)->val;
	  rest->newBase = XmlCppBase::modifyName(rest->base);
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in simple restriction",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (rest->base == 0)
    yyerror("simpleRestriction must have base");
}

/********************************************************************/

/* doXmlSimpleTypeAttributes

The value of the "final" attribute is a string that may have up to
three names separated by spaces. If the "final" attribute is used,
this function parses the string and builds an instance of the XmlFinal
class. The string may also be the empty string; in that case, no
instance of the XmlFinal class is built.

This exits if name is missing. We are assuming all schemas are in venetian
blind format, so no anonymous simple types may occur.

This also sets the simple type's value of owlPrefix for the
XmlSimpleType to the globalOwlPrefix, which may be the empty string
("") or a prefix with some characters.

*/

void doXmlSimpleTypeAttributes(
 XmlSimpleType * simp,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  char item1[80];
  char item2[80];
  char item3[80];
  char item4[80];
  int numItems;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (simp->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in simpleType");
	      yyerror(errMessage);
	    }
	  simp->id = (*iter)->val;
	}
      else if ((*iter)->name == NAME)
	{
	  if (simp->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in simpleType");
	      yyerror(errMessage);
	    }
	  simp->name = (*iter)->val;
	  simp->newName = XmlCppBase::modifyName(simp->name);
	}
      else if ((*iter)->name == FINAL)
	{
	  numItems = sscanf((*iter)->val, "%s %s %s %s",
			    item1, item2, item3, item4);
	  if (numItems > 3)
	    yyerror("too many items in final of simpleType");
	  if (numItems > 2)
	    {
	      if ((strcmp(item3, item2) == 0) ||
		  (strcmp(item3, item1) == 0))
		yyerror("duplicate items in final of simpleType");
	      if (strcmp(item3, "#all") == 0)
		yyerror("other items with #all in final of simpleType");
	      simp->final = new XmlFinal();
	      if (strcmp(item3, "list") == 0)
		simp->final->list = true;
	      else if (strcmp(item3, "union") == 0)
		simp->final->younion = true;
	      else if (strcmp(item3, "restriction") == 0)
		simp->final->restriction = true;
	      else
		{
		  snprintf(errMessage, ERRSIZE,
			   "bad item %s in final of simpleType",
			   item3);
		  yyerror(errMessage);
		}
	    }
	  if (numItems > 1)
	    {
	      if (strcmp(item2, item1) == 0)
		yyerror("duplicate items in final of simpleType");
	      if (strcmp(item2, "#all") == 0)
		yyerror("other items with #all in final of simpleType");
	      if (simp->final == 0)
		simp->final = new XmlFinal();
	      if (strcmp(item2, "list") == 0)
		simp->final->list = true;
	      else if (strcmp(item2, "union") == 0)
		simp->final->younion = true;
	      else if (strcmp(item2, "restriction") == 0)
		simp->final->restriction = true;
	      else
		{
		  snprintf(errMessage, ERRSIZE,
			   "bad item %s in final of simpleType", item2);
		  yyerror(errMessage);
		}
	    }
	  if (numItems > 0)
	    {
	      if (simp->final == 0)
		simp->final = new XmlFinal();
	      else if (strcmp(item1, "#all") == 0)
		yyerror("other items with #all in final of simpleType");
	      if (strcmp(item1, "#all") == 0)
		simp->final->all = true;
	      else if (strcmp(item1, "list") == 0)
		simp->final->list = true;
	      else if (strcmp(item1, "union") == 0)
		simp->final->younion = true;
	      else if (strcmp(item1, "restriction") == 0)
		simp->final->restriction = true;
	      else
		{
		  snprintf(errMessage, ERRSIZE,
			   "bad item %s in final of simpleType", item1);
		  yyerror(errMessage);
		}
	    }
	}
      else
	{
	  snprintf(errMessage, ERRSIZE,
		   "bad attribute name \"%s\" in simpleType",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (simp->name == 0)
    yyerror("name missing in simpleType");
  simp->owlPrefix = globalOwlPrefix;
}

/********************************************************************/

void doXmlUniqueAttributes(
 XmlUnique * unique,
 std::list<XmlAttribPair *> * atts)
{
  std::list<XmlAttribPair *>::iterator iter;
  for (iter = atts->begin(); iter != atts->end(); iter++)
    {
      if ((*iter)->name == ID)
	{
	  if (unique->id)
	    {
	      snprintf(errMessage, ERRSIZE, "id used twice in unique");
	      yyerror(errMessage);
	    }
	  unique->id = (*iter)->val;
	}
      else if ((*iter)->name == NAME)
	{
	  if (unique->name)
	    {
	      snprintf(errMessage, ERRSIZE, "name used twice in unique");
	      yyerror(errMessage);
	    }
	  unique->name = (*iter)->val;
	}
      else
	{
	  snprintf(errMessage, ERRSIZE, "bad attribute name \"%s\" in unique",
		   attNames[(*iter)->name - ABSTRACT]);
	  yyerror(errMessage);
	}
    }
  if (unique->name == 0)
    yyerror("name missing in unique");
}

/********************************************************************/





/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ABSTRACT = 258,
     ATTRIBUTEFORMDEFAULT = 259,
     BAD = 260,
     BASE = 261,
     DEFALT = 262,
     ELEMENTFORMDEFAULT = 263,
     ENCODING = 264,
     ENDCOMMENT = 265,
     ENDITEM = 266,
     ENDWHOLEITEM = 267,
     ENDVERSION = 268,
     FINAL = 269,
     FIXED = 270,
     FORM = 271,
     ID = 272,
     ITEMTYPE = 273,
     MAXOCCURS = 274,
     MINOCCURS = 275,
     MIXED = 276,
     NAME = 277,
     NILLABLE = 278,
     REF = 279,
     REFER = 280,
     SCHEMALOCATION = 281,
     SOURCE = 282,
     STARTANNOTATION = 283,
     STARTCOMMENT = 284,
     STARTINITEM = 285,
     STARTOUTITEM = 286,
     STARTVERSION = 287,
     SUBSTITUTIONGROUP = 288,
     TARGETNAMESPACE = 289,
     TERMINALSTRING = 290,
     TYP = 291,
     USE = 292,
     VALUE = 293,
     VERSION = 294,
     XPATH = 295,
     XMLNSPREFIX = 296,
     XSANNOTATION = 297,
     XSAPPINFO = 298,
     XSATTRIBUTE = 299,
     XSATTRIBUTEGROUP = 300,
     XSCHOICE = 301,
     XSCOMPLEXCONTENT = 302,
     XSCOMPLEXTYPE = 303,
     XSDOCUMENTATION = 304,
     XSELEMENT = 305,
     XSENUMERATION = 306,
     XSEXTENSION = 307,
     XSFIELD = 308,
     XSGROUP = 309,
     XSINCLUDE = 310,
     XSKEY = 311,
     XSKEYREF = 312,
     XSLENGTH = 313,
     XSLIST = 314,
     XSMAXEXCLUSIVE = 315,
     XSMAXINCLUSIVE = 316,
     XSMAXLENGTH = 317,
     XSMINEXCLUSIVE = 318,
     XSMININCLUSIVE = 319,
     XSMINLENGTH = 320,
     XSPATTERN = 321,
     XSRESTRICTION = 322,
     XSSCHEMA = 323,
     XSSELECTOR = 324,
     XSSEQUENCE = 325,
     XSSIMPLECONTENT = 326,
     XSSIMPLETYPE = 327,
     XSUNIQUE = 328,
     XMLVERSION = 329
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  XmlAnnotation *                   annotationVal;
  std::list<XmlAnnotation *> *      annotationListVal;
  XmlAnnoType *                     annoTypeVal;
  std::list<XmlAnnoType *> *        annoTypeListVal;
  XmlAppinfo *                      appinfoVal;
  XmlAttributor *                   attributorVal;
  std::list<XmlAttributor *> *      attributorListVal;
  XmlAttribPair *                   attribPairVal;
  std::list<XmlAttribPair *> *      attribPairListVal;
  XmlAttributeLoner *               attributeLonerVal;
  XmlAttributeLonerRefable *        attributeLonerRefableVal;
  XmlAttributeGroup *               attributeGroupVal;
  XmlAttributeGroupRefable *        attributeGroupRefableVal;
  XmlChoice *                       choiceVal;
  XmlChoSeqItem *                   choSeqItemVal;
  std::list<XmlChoSeqItem *> *      choSeqItemListVal;
  std::string *                     commentVal;
  std::list<std::string *> *        commentListVal;
  XmlComplexContentItem *           complexContentItemVal;
  XmlComplexContent *               complexContentVal;
  XmlComplexExtension *             complexExtensionVal;
  XmlComplexRestriction *           complexRestrictionVal;
  XmlComplexTypeItem *              complexTypeItemVal;
  XmlComplexType *                  complexTypeVal;
  XmlCppBase *                      cppBaseVal;
  XmlCppBase::formE                 formEVal;
  XmlDocumentation *                documentationVal;
  XmlElementGroup *                 elementGroupVal;
  XmlElementGroupRef *              elementGroupRefVal;
  XmlElementLocal *                 elementLocalVal;
  XmlElementRefable *               elementRefableVal;
  XmlEnumeration *                  enumerationVal;
  XmlField *                        fieldVal;
  std::list<XmlField *> *           fieldListVal;
  XmlFinal *                        finalVal;
  XmlIdConstraint *                 idConstraintVal;
  std::list<XmlIdConstraint *> *    idConstraintListVal;
  XmlInclude *                      includeVal;
  XmlKey *                          keyVal;
  XmlKeyref *                       keyrefVal;
  XmlLength *                       lengthVal;
  XmlMaxExclusive *                 maxExclusiveVal;
  XmlMaxInclusive *                 maxInclusiveVal;
  XmlMaxLength *                    maxLengthVal;
  XmlMinExclusive *                 minExclusiveVal;
  XmlMinInclusive *                 minInclusiveVal;
  XmlMinLength *                    minLengthVal;
  XmlNsPair *                       nsPairVal;
  std::list<XmlNsPair *> *          nsPairListVal;
  XmlOtherContent *                 otherContentVal;
  XmlOtherContentBase *             otherContentBaseVal;
  XmlPattern *                      patternVal;
  XmlRestrictionType *              restrictionTypeVal;
  std::list<XmlRestrictionType *> * restrictionTypeListVal;
  XmlSchema *                       schemaVal;
  XmlSchemaContent1 *               schemaContent1Val;
  std::list<XmlSchemaContent1 *> *  schemaContent1ListVal;
  XmlSchemaContent2 *               schemaContent2Val;
  std::list<XmlSchemaContent2 *> *  schemaContent2ListVal;
  XmlSchemaFile *                   schemaFileVal;
  XmlSchemaHeader *                 schemaHeaderVal;
  XmlSelector *                     selectorVal;
  XmlSequence *                     sequenceVal;
  XmlSimpleContent *                simpleContentVal;
  XmlSimpleContentItem *            simpleContentItemVal;
  XmlSimpleContentExtension *       simpleContentExtensionVal;
  XmlSimpleContentRestriction *     simpleContentRestrictionVal;
  XmlSimpleItem *                   simpleItemVal;
  XmlSimpleList *                   simpleListVal;
  XmlSimpleRestriction *            simpleRestrictionVal;
  XmlSimpleType *                   simpleTypeVal;
  XmlType *                         typVal;
  XmlUnique *                       uniqueVal;
  XmlVersion *                      versionVal;
  
  double        dVal;
  int           iVal;
  char *        sVal;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  248
/* YYNRULES -- Number of states.  */
#define YYNSTATES  747

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    17,    18,    21,    23,
      25,    27,    29,    31,    33,    35,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    74,    76,    78,    86,    95,    97,
      99,   102,   104,   106,   107,   110,   119,   127,   132,   140,
     149,   158,   168,   173,   182,   191,   201,   206,   215,   224,
     234,   239,   248,   257,   267,   269,   271,   273,   276,   278,
     280,   282,   284,   286,   289,   298,   308,   311,   313,   316,
     325,   335,   337,   339,   344,   352,   361,   371,   381,   392,
     401,   411,   420,   425,   434,   444,   454,   465,   474,   484,
     493,   495,   497,   499,   504,   512,   521,   530,   540,   549,
     557,   567,   576,   581,   589,   598,   607,   616,   626,   635,
     645,   655,   666,   674,   679,   688,   697,   707,   717,   727,
     738,   747,   755,   760,   765,   773,   782,   787,   795,   797,
     800,   802,   804,   806,   808,   811,   816,   826,   837,   848,
     860,   870,   881,   892,   904,   909,   918,   923,   932,   937,
     946,   951,   960,   965,   974,   979,   988,   993,  1002,  1005,
    1007,  1010,  1012,  1014,  1017,  1019,  1021,  1026,  1035,  1037,
    1039,  1041,  1043,  1045,  1047,  1049,  1051,  1053,  1055,  1058,
    1065,  1067,  1069,  1070,  1073,  1075,  1078,  1080,  1083,  1085,
    1088,  1090,  1093,  1095,  1098,  1100,  1103,  1105,  1108,  1114,
    1119,  1127,  1136,  1146,  1151,  1159,  1168,  1177,  1187,  1189,
    1191,  1196,  1204,  1213,  1222,  1232,  1237,  1245,  1254,  1263,
    1272,  1282,  1292,  1302,  1313,  1315,  1317,  1322,  1330,  1335,
    1343,  1352,  1361,  1371,  1381,  1392,  1403,  1415,  1420
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      76,     0,    -1,   148,   131,    -1,   148,    97,   131,    -1,
      79,    35,    -1,    79,    41,    35,    -1,    -1,    78,    77,
      -1,     3,    -1,     4,    -1,     6,    -1,     7,    -1,     8,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    27,    -1,    33,    -1,    34,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    26,    35,    -1,   103,    -1,   146,    -1,    28,    78,
      11,    85,    31,    42,    11,    -1,    96,    28,    78,    11,
      85,    31,    42,    11,    -1,    96,    -1,    82,    -1,    83,
      82,    -1,   104,    -1,    86,    -1,    -1,    85,    84,    -1,
      30,    43,    78,    11,    35,    31,    43,    11,    -1,    30,
      43,    78,    11,    31,    43,    11,    -1,    30,    44,    78,
      12,    -1,    30,    44,    78,    11,    31,    44,    11,    -1,
      30,    44,    78,    11,   146,    31,    44,    11,    -1,    30,
      44,    78,    11,    82,    31,    44,    11,    -1,    30,    44,
      78,    11,    82,   146,    31,    44,    11,    -1,    30,    44,
      78,    12,    -1,    30,    44,    78,    11,   146,    31,    44,
      11,    -1,    30,    44,    78,    11,    82,    31,    44,    11,
      -1,    30,    44,    78,    11,    82,   146,    31,    44,    11,
      -1,    30,    45,    78,    12,    -1,    30,    45,    78,    11,
      92,    31,    45,    11,    -1,    30,    45,    78,    11,    82,
      31,    45,    11,    -1,    30,    45,    78,    11,    82,    92,
      31,    45,    11,    -1,    30,    45,    78,    12,    -1,    30,
      45,    78,    11,    92,    31,    45,    11,    -1,    30,    45,
      78,    11,    82,    31,    45,    11,    -1,    30,    45,    78,
      11,    82,    92,    31,    45,    11,    -1,    87,    -1,    89,
      -1,    91,    -1,    92,    91,    -1,    95,    -1,   106,    -1,
     107,    -1,   138,    -1,    93,    -1,    94,    93,    -1,    30,
      46,    78,    11,    94,    31,    46,    11,    -1,    30,    46,
      78,    11,    82,    94,    31,    46,    11,    -1,    29,    10,
      -1,    96,    -1,    97,    96,    -1,    30,    47,    78,    11,
      99,    31,    47,    11,    -1,    30,    47,    78,    11,    82,
      99,    31,    47,    11,    -1,   101,    -1,   100,    -1,    30,
      52,    78,    12,    -1,    30,    52,    78,    11,    31,    52,
      11,    -1,    30,    52,    78,    11,    82,    31,    52,    11,
      -1,    30,    52,    78,    11,    82,   127,    31,    52,    11,
      -1,    30,    52,    78,    11,    82,    92,    31,    52,    11,
      -1,    30,    52,    78,    11,    82,   127,    92,    31,    52,
      11,    -1,    30,    52,    78,    11,   127,    31,    52,    11,
      -1,    30,    52,    78,    11,   127,    92,    31,    52,    11,
      -1,    30,    52,    78,    11,    92,    31,    52,    11,    -1,
      30,    67,    78,    12,    -1,    30,    67,    78,    11,    82,
      31,    67,    11,    -1,    30,    67,    78,    11,    82,   127,
      31,    67,    11,    -1,    30,    67,    78,    11,    82,    92,
      31,    67,    11,    -1,    30,    67,    78,    11,    82,   127,
      92,    31,    67,    11,    -1,    30,    67,    78,    11,   127,
      31,    67,    11,    -1,    30,    67,    78,    11,   127,    92,
      31,    67,    11,    -1,    30,    67,    78,    11,    92,    31,
      67,    11,    -1,    98,    -1,   126,    -1,   139,    -1,    30,
      48,    78,    12,    -1,    30,    48,    78,    11,    31,    48,
      11,    -1,    30,    48,    78,    11,   102,    31,    48,    11,
      -1,    30,    48,    78,    11,    82,    31,    48,    11,    -1,
      30,    48,    78,    11,    82,   102,    31,    48,    11,    -1,
      30,    49,    78,    11,    35,    31,    49,    11,    -1,    30,
      49,    78,    11,    31,    49,    11,    -1,    30,    54,    78,
      11,    82,    93,    31,    54,    11,    -1,    30,    54,    78,
      11,    93,    31,    54,    11,    -1,    30,    54,    78,    12,
      -1,    30,    54,    78,    11,    31,    54,    11,    -1,    30,
      54,    78,    11,    82,    31,    54,    11,    -1,    30,    50,
      78,    11,    82,    31,    50,    11,    -1,    30,    50,    78,
      11,    81,    31,    50,    11,    -1,    30,    50,    78,    11,
      82,    81,    31,    50,    11,    -1,    30,    50,    78,    11,
     113,    31,    50,    11,    -1,    30,    50,    78,    11,    82,
     113,    31,    50,    11,    -1,    30,    50,    78,    11,    81,
     113,    31,    50,    11,    -1,    30,    50,    78,    11,    82,
      81,   113,    31,    50,    11,    -1,    30,    50,    78,    11,
      31,    50,    11,    -1,    30,    50,    78,    12,    -1,    30,
      50,    78,    11,    82,    31,    50,    11,    -1,    30,    50,
      78,    11,    81,    31,    50,    11,    -1,    30,    50,    78,
      11,    82,    81,    31,    50,    11,    -1,    30,    50,    78,
      11,    82,   113,    31,    50,    11,    -1,    30,    50,    78,
      11,    81,   113,    31,    50,    11,    -1,    30,    50,    78,
      11,    82,    81,   113,    31,    50,    11,    -1,    30,    50,
      78,    11,   113,    31,    50,    11,    -1,    30,    50,    78,
      11,    31,    50,    11,    -1,    30,    50,    78,    12,    -1,
      30,    51,    78,    12,    -1,    30,    51,    78,    11,    31,
      51,    11,    -1,    30,    51,    78,    11,    82,    31,    51,
      11,    -1,    30,    53,    78,    12,    -1,    30,    53,    78,
      11,    31,    53,    11,    -1,   110,    -1,   111,   110,    -1,
     115,    -1,   116,    -1,   147,    -1,   112,    -1,   113,   112,
      -1,    30,    55,    80,    12,    -1,    30,    56,    78,    11,
     137,   111,    31,    56,    11,    -1,    97,    30,    56,    78,
      11,   137,   111,    31,    56,    11,    -1,    30,    56,    78,
      11,    82,   137,   111,    31,    56,    11,    -1,    97,    30,
      56,    78,    11,    82,   137,   111,    31,    56,    11,    -1,
      30,    57,    78,    11,   137,   111,    31,    57,    11,    -1,
      97,    30,    57,    78,    11,   137,   111,    31,    57,    11,
      -1,    30,    57,    78,    11,    82,   137,   111,    31,    57,
      11,    -1,    97,    30,    57,    78,    11,    82,   137,   111,
      31,    57,    11,    -1,    30,    58,    78,    12,    -1,    30,
      58,    78,    11,    82,    31,    58,    11,    -1,    30,    60,
      78,    12,    -1,    30,    60,    78,    11,    82,    31,    60,
      11,    -1,    30,    61,    78,    12,    -1,    30,    61,    78,
      11,    82,    31,    61,    11,    -1,    30,    62,    78,    12,
      -1,    30,    62,    78,    11,    82,    31,    62,    11,    -1,
      30,    63,    78,    12,    -1,    30,    63,    78,    11,    82,
      31,    63,    11,    -1,    30,    64,    78,    12,    -1,    30,
      64,    78,    11,    82,    31,    64,    11,    -1,    30,    65,
      78,    12,    -1,    30,    65,    78,    11,    82,    31,    65,
      11,    -1,    41,    35,    -1,   124,    -1,   125,   124,    -1,
     127,    -1,    92,    -1,   127,    92,    -1,    95,    -1,   138,
      -1,    30,    66,    78,    12,    -1,    30,    66,    78,    11,
      82,    31,    66,    11,    -1,   117,    -1,   118,    -1,   119,
      -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,   128,
      -1,   109,    -1,   129,    -1,   130,   129,    -1,   136,   133,
     135,    31,    68,    11,    -1,   114,    -1,    82,    -1,    -1,
     133,   132,    -1,   105,    -1,   105,    83,    -1,   108,    -1,
     108,    83,    -1,   103,    -1,   103,    83,    -1,   146,    -1,
     146,    83,    -1,    88,    -1,    88,    83,    -1,    90,    -1,
      90,    83,    -1,   134,    -1,   135,   134,    -1,    30,    68,
     125,    78,    11,    -1,    30,    69,    78,    12,    -1,    30,
      69,    78,    11,    31,    69,    11,    -1,    30,    70,    78,
      11,    94,    31,    70,    11,    -1,    30,    70,    78,    11,
      82,    94,    31,    70,    11,    -1,    30,    71,    78,    12,
      -1,    30,    71,    78,    11,    31,    71,    11,    -1,    30,
      71,    78,    11,    82,    31,    71,    11,    -1,    30,    71,
      78,    11,   140,    31,    71,    11,    -1,    30,    71,    78,
      11,    82,   140,    31,    71,    11,    -1,   141,    -1,   142,
      -1,    30,    52,    78,    12,    -1,    30,    52,    78,    11,
      31,    52,    11,    -1,    30,    52,    78,    11,    82,    31,
      52,    11,    -1,    30,    52,    78,    11,    92,    31,    52,
      11,    -1,    30,    52,    78,    11,    82,    92,    31,    52,
      11,    -1,    30,    67,    78,    12,    -1,    30,    67,    78,
      11,    31,    67,    11,    -1,    30,    67,    78,    11,    82,
      31,    67,    11,    -1,    30,    67,    78,    11,   130,    31,
      67,    11,    -1,    30,    67,    78,    11,    92,    31,    67,
      11,    -1,    30,    67,    78,    11,    82,   130,    31,    67,
      11,    -1,    30,    67,    78,    11,    82,    92,    31,    67,
      11,    -1,    30,    67,    78,    11,   130,    92,    31,    67,
      11,    -1,    30,    67,    78,    11,    82,   130,    92,    31,
      67,    11,    -1,   144,    -1,   145,    -1,    30,    59,    78,
      12,    -1,    30,    59,    78,    11,    31,    59,    11,    -1,
      30,    67,    78,    12,    -1,    30,    67,    78,    11,    31,
      67,    11,    -1,    30,    67,    78,    11,   130,    31,    67,
      11,    -1,    30,    72,    78,    11,   143,    31,    72,    11,
      -1,    30,    72,    78,    11,    82,   143,    31,    72,    11,
      -1,    30,    73,    78,    11,   137,   111,    31,    73,    11,
      -1,    97,    30,    73,    78,    11,   137,   111,    31,    73,
      11,    -1,    30,    73,    78,    11,    82,   137,   111,    31,
      73,    11,    -1,    97,    30,    73,    78,    11,    82,   137,
     111,    31,    73,    11,    -1,    32,    74,    35,    13,    -1,
      32,    74,    35,     9,    35,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  2847,  2847,  2851,  2858,  2860,  2866,  2867,  2884,  2885,
    2886,  2887,  2888,  2889,  2890,  2891,  2892,  2893,  2894,  2895,
    2896,  2897,  2898,  2899,  2900,  2901,  2902,  2903,  2904,  2905,
    2906,  2907,  2908,  2912,  2917,  2918,  2922,  2930,  2939,  2947,
    2951,  2958,  2959,  2964,  2965,  2972,  2979,  2988,  2992,  2997,
    3004,  3011,  3022,  3026,  3033,  3040,  3051,  3056,  3063,  3070,
    3081,  3086,  3093,  3100,  3111,  3112,  3116,  3120,  3127,  3128,
    3129,  3130,  3134,  3138,  3145,  3152,  3163,  3168,  3172,  3179,
    3186,  3197,  3198,  3202,  3206,  3211,  3218,  3226,  3234,  3243,
    3250,  3258,  3268,  3272,  3279,  3287,  3295,  3304,  3311,  3319,
    3329,  3330,  3331,  3335,  3340,  3346,  3353,  3361,  3372,  3379,
    3388,  3396,  3406,  3410,  3415,  3425,  3432,  3441,  3451,  3458,
    3466,  3476,  3487,  3492,  3499,  3506,  3513,  3521,  3529,  3537,
    3546,  3553,  3558,  3565,  3569,  3574,  3584,  3588,  3596,  3600,
    3607,  3609,  3611,  3616,  3620,  3627,  3632,  3639,  3648,  3656,
    3669,  3676,  3685,  3693,  3706,  3710,  3720,  3724,  3734,  3738,
    3748,  3752,  3762,  3766,  3777,  3781,  3791,  3795,  3805,  3810,
    3814,  3821,  3823,  3825,  3830,  3831,  3835,  3839,  3849,  3850,
    3851,  3852,  3853,  3854,  3855,  3856,  3857,  3861,  3865,  3872,
    3878,  3879,  3884,  3887,  3894,  3895,  3899,  3900,  3904,  3905,
    3909,  3910,  3914,  3915,  3919,  3920,  3927,  3931,  3938,  3950,
    3954,  3962,  3969,  3980,  3984,  3989,  3996,  4003,  4014,  4015,
    4019,  4023,  4028,  4035,  4042,  4053,  4058,  4064,  4072,  4079,
    4087,  4095,  4103,  4111,  4123,  4124,  4128,  4132,  4140,  4145,
    4151,  4161,  4168,  4179,  4186,  4195,  4203,  4216,  4221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "ATTRIBUTEFORMDEFAULT",
  "BAD", "BASE", "DEFALT", "ELEMENTFORMDEFAULT", "ENCODING", "ENDCOMMENT",
  "ENDITEM", "ENDWHOLEITEM", "ENDVERSION", "FINAL", "FIXED", "FORM", "ID",
  "ITEMTYPE", "MAXOCCURS", "MINOCCURS", "MIXED", "NAME", "NILLABLE", "REF",
  "REFER", "SCHEMALOCATION", "SOURCE", "STARTANNOTATION", "STARTCOMMENT",
  "STARTINITEM", "STARTOUTITEM", "STARTVERSION", "SUBSTITUTIONGROUP",
  "TARGETNAMESPACE", "TERMINALSTRING", "TYP", "USE", "VALUE", "VERSION",
  "XPATH", "XMLNSPREFIX", "XSANNOTATION", "XSAPPINFO", "XSATTRIBUTE",
  "XSATTRIBUTEGROUP", "XSCHOICE", "XSCOMPLEXCONTENT", "XSCOMPLEXTYPE",
  "XSDOCUMENTATION", "XSELEMENT", "XSENUMERATION", "XSEXTENSION",
  "XSFIELD", "XSGROUP", "XSINCLUDE", "XSKEY", "XSKEYREF", "XSLENGTH",
  "XSLIST", "XSMAXEXCLUSIVE", "XSMAXINCLUSIVE", "XSMAXLENGTH",
  "XSMINEXCLUSIVE", "XSMININCLUSIVE", "XSMINLENGTH", "XSPATTERN",
  "XSRESTRICTION", "XSSCHEMA", "XSSELECTOR", "XSSEQUENCE",
  "XSSIMPLECONTENT", "XSSIMPLETYPE", "XSUNIQUE", "XMLVERSION", "$accept",
  "xmlSchemaFile", "attributePair", "attributePairList", "attributeName",
  "schemaLocation", "typeDef", "xmlAnnotation", "xmlAnnotationList",
  "xmlAnnoType", "xmlAnnoTypeList", "xmlAppinfo", "xmlAttributeLoner",
  "xmlAttributeLonerRefable", "xmlAttributeGroup",
  "xmlAttributeGroupRefable", "xmlAttributor", "xmlAttributorList",
  "xmlChoSeqItem", "xmlChoSeqItemList", "xmlChoice", "xmlComment",
  "xmlCommentList", "xmlComplexContent", "xmlComplexContentItem",
  "xmlComplexExtension", "xmlComplexRestriction", "xmlComplexTypeItem",
  "xmlComplexType", "xmlDocumentation", "xmlElementGroup",
  "xmlElementGroupRef", "xmlElementLocal", "xmlElementRefable",
  "xmlEnumeration", "xmlField", "xmlFieldList", "xmlIdConstraint",
  "xmlIdConstraintList", "xmlInclude", "xmlKey", "xmlKeyref", "xmlLength",
  "xmlMaxExclusive", "xmlMaxInclusive", "xmlMaxLength", "xmlMinExclusive",
  "xmlMinInclusive", "xmlMinLength", "xmlNs", "xmlNsList",
  "xmlOtherContent", "xmlOtherContentBase", "xmlPattern",
  "xmlRestrictionType", "xmlRestrictionTypeList", "xmlSchema",
  "xmlSchemaContent1", "xmlSchemaContent1List", "xmlSchemaContent2",
  "xmlSchemaContent2List", "xmlSchemaHeader", "xmlSelector", "xmlSequence",
  "xmlSimpleContent", "xmlSimpleContentItem", "xmlSimpleContentExtension",
  "xmlSimpleContentRestriction", "xmlSimpleItem", "xmlSimpleList",
  "xmlSimpleRestriction", "xmlSimpleType", "xmlUnique", "xmlVersion", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   112,   113,   113,   114,   115,   115,   115,   115,
     116,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   125,
     125,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   130,   130,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   140,   140,
     141,   141,   141,   141,   141,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   146,   146,   147,   147,   147,   147,   148,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     7,     8,     1,     1,
       2,     1,     1,     0,     2,     8,     7,     4,     7,     8,
       8,     9,     4,     8,     8,     9,     4,     8,     8,     9,
       4,     8,     8,     9,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     8,     9,     2,     1,     2,     8,
       9,     1,     1,     4,     7,     8,     9,     9,    10,     8,
       9,     8,     4,     8,     9,     9,    10,     8,     9,     8,
       1,     1,     1,     4,     7,     8,     8,     9,     8,     7,
       9,     8,     4,     7,     8,     8,     8,     9,     8,     9,
       9,    10,     7,     4,     8,     8,     9,     9,     9,    10,
       8,     7,     4,     4,     7,     8,     4,     7,     1,     2,
       1,     1,     1,     1,     2,     4,     9,    10,    10,    11,
       9,    10,    10,    11,     4,     8,     4,     8,     4,     8,
       4,     8,     4,     8,     4,     8,     4,     8,     2,     1,
       2,     1,     1,     2,     1,     1,     4,     8,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       1,     1,     0,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     5,     4,
       7,     8,     9,     4,     7,     8,     8,     9,     1,     1,
       4,     7,     8,     8,     9,     4,     7,     8,     8,     8,
       9,     9,     9,    10,     1,     1,     4,     7,     4,     7,
       8,     8,     9,     9,    10,    10,    11,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,    77,     0,
       2,   192,     0,    76,     0,    78,     3,     0,     0,   247,
       0,   169,     6,     6,     0,   191,   202,   204,    38,   198,
     194,   196,   190,   193,   206,     0,   200,     0,   168,     0,
     170,     0,     6,     6,     6,     6,     6,     0,     6,    39,
     203,   205,     6,   199,   195,   197,     0,     0,   207,   201,
     248,     8,     9,    10,    11,    12,   208,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     7,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     4,     0,     0,     0,    52,     0,    60,     0,   103,
       0,   132,     0,    33,   145,     0,    43,   189,     5,     0,
       0,    44,    42,    41,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     0,     0,   172,   174,   100,     0,
     101,   171,   175,   102,     0,     0,     0,     0,    38,     0,
      34,   143,     0,   140,   141,    35,   142,     0,     0,     0,
      68,    69,    70,    71,     0,     0,     0,   234,   235,     0,
       6,     6,     0,     0,     0,     0,     6,     6,     0,     0,
       0,    67,     6,     6,     6,     6,     0,     0,     0,     0,
     173,     6,     6,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,     6,     6,     0,     0,     6,     6,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,     6,     6,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,    53,
       0,    47,     0,    56,    62,     0,    61,     0,     0,     0,
       0,   213,   106,     0,   105,     0,     0,     0,   125,     0,
     124,     0,     0,     0,     0,     0,     0,   130,     0,   123,
       0,   112,     0,   111,     0,   236,     0,   238,     0,   241,
      37,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    63,     0,    72,     0,     0,     0,     0,    82,    81,
       0,     0,     0,     0,     0,     0,   218,   219,   107,     0,
       0,     0,     0,     0,     0,     0,   128,   126,     0,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,   186,   178,   179,   180,   181,   182,   183,
     184,   185,   187,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     6,
       6,     0,     0,     0,     0,     6,     6,     0,     0,     0,
       0,     6,     0,     0,   138,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     0,     0,   188,    46,
       0,   109,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     6,     0,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,   113,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,    45,   108,    50,     0,    49,    58,     0,    57,     0,
      74,     0,    83,     0,    92,     0,    79,     0,   211,     0,
     220,     0,   225,   215,     0,   216,     0,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   115,     0,     0,     0,   118,   114,     0,
     133,     0,   154,     0,   156,     0,   158,     0,   160,     0,
     162,     0,   164,     0,   166,     0,   176,   240,    51,    59,
      75,     0,     0,     0,     0,     0,     0,     0,     0,    80,
     212,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,   136,   146,     0,   150,     0,   243,     0,
       0,     0,     0,     0,     0,   120,   117,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,   152,   245,     0,   147,
       0,   151,     0,   244,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,   210,     0,   149,   153,   246,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,    91,    89,     0,    93,     0,     0,     0,    99,    97,
       0,   222,     0,   223,   227,     0,     0,     0,   229,   228,
       0,   137,   135,   155,   157,   159,   161,   163,   165,   167,
     177,    87,    86,     0,    90,    95,    94,     0,    98,   224,
     231,   230,     0,   232,    88,    96,   233
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    87,    39,    88,    96,   146,    49,    50,   121,
     103,   122,   129,    26,   130,    27,   131,   136,   313,   314,
     160,    28,   149,   138,   317,   318,   319,   139,   150,   123,
      30,   161,   162,    31,   353,   394,   395,   151,   152,    32,
     153,   154,   354,   355,   356,   357,   358,   359,   360,    21,
      22,   140,   141,   361,   362,   363,    10,    33,    17,    34,
      35,    11,   331,   163,   143,   325,   326,   327,   166,   167,
     168,   155,   156,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -497
static const yytype_int16 yypact[] =
{
     -30,   -49,    27,    25,    28,  -497,    79,    36,  -497,    25,
    -497,  -497,    29,  -497,    54,  -497,  -497,   191,    71,  -497,
      73,  -497,    54,  -497,   116,  -497,   127,   127,    94,   127,
     127,   127,  -497,  -497,  -497,    44,   127,   112,  -497,  1505,
    -497,  1543,  -497,  -497,  -497,  -497,  -497,   106,  -497,  -497,
     127,   127,  -497,   127,   127,   127,   -15,    67,  -497,   127,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,    31,  -497,
     344,   555,   593,   631,  1581,   113,   146,  1619,  -497,  1657,
     140,  -497,   130,   132,   265,  -497,   281,  -497,   197,  -497,
     215,  -497,   289,  -497,  -497,   297,  -497,  -497,  -497,    33,
     147,  -497,  -497,  -497,   100,   155,   150,   164,   199,  -497,
    -497,  -497,   217,    41,   143,   242,   163,  -497,  -497,   170,
    -497,   163,  -497,  -497,   139,   153,   138,   312,    94,   291,
    -497,  -497,   370,  -497,  -497,  -497,  -497,   152,   183,   201,
    -497,  -497,  -497,  -497,   -39,   211,   220,  -497,  -497,   298,
    -497,  -497,   259,   231,   246,   235,  -497,  -497,   236,   307,
     267,  -497,  -497,  -497,  -497,  -497,   276,   286,   318,   309,
     163,  -497,  -497,  -497,   359,   -25,   322,   384,   326,   387,
     393,    61,   335,  -497,  -497,  -497,   356,   341,  -497,  -497,
     366,   330,   368,  1695,  1733,  -497,   448,   376,   451,   669,
     707,   453,   386,   455,  1771,  1809,  1847,   745,  -497,   461,
     430,   469,  1885,  1923,  1961,  -497,   471,   440,   501,   473,
     396,   480,  -497,  -497,  -497,   517,   783,   821,   482,   521,
     859,   897,   466,   529,   531,    66,    72,  -497,   533,  -497,
     225,  -497,   281,  -497,  -497,   536,  -497,   289,   400,   289,
     233,  -497,  -497,   546,  -497,   408,   408,   408,  -497,   549,
    -497,   557,   535,   570,  1999,  2037,  2075,  -497,   255,  -497,
      99,  -497,   575,  -497,   559,  -497,   323,  -497,   587,  -497,
    -497,   563,   588,   574,   597,  -497,   592,   377,   613,   403,
     409,  -497,   183,  -497,   439,    -6,   627,   630,  -497,  -497,
     183,   464,    16,   595,   467,   643,  -497,  -497,  -497,   626,
     652,   674,   652,   674,   652,   674,  -497,  -497,   688,  -497,
     408,   408,   408,   662,   413,   417,   420,   666,   702,  -497,
     678,   328,   675,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,   475,  -497,   739,   715,   760,   726,   769,
     744,   765,   774,   764,   478,   768,   484,   780,  -497,  -497,
    -497,   803,   804,   488,   777,  -497,  -497,   845,   793,   841,
     814,  -497,   674,   836,  -497,   490,   674,   495,   674,   534,
    -497,   652,   674,   652,   674,   652,   674,   883,   852,   423,
     873,   426,   446,   877,   899,   878,   929,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,   937,   894,  -497,  -497,
     954,  -497,   959,  -497,   967,   942,   988,   992,   960,   993,
     962,  1005,   935,   973,   974,  1009,   969,  1013,  1011,  1049,
    -497,  1026,   970,  1029,  1087,   553,  -497,   986,  -497,   572,
     989,   591,   981,   674,   594,   674,   610,   674,   629,  -497,
    1032,  1008,  1048,  1012,   457,  1025,  1066,  -497,  1067,  -497,
    1125,  1163,  1201,  1239,  1277,  1315,  1353,  1391,  1429,  -497,
    1068,  -497,  -497,  -497,  1069,  -497,  -497,  1070,  -497,  1073,
    -497,   261,  -497,   474,  -497,  1081,  -497,  1085,  -497,   269,
    -497,   275,  -497,  -497,  1086,  -497,  1082,  -497,  1044,  1467,
    1104,  1059,  1106,  1045,  1108,   632,  1074,   648,  1065,   667,
    1061,  -497,  1124,  -497,  1127,  1101,  1142,  -497,  -497,   108,
    -497,   127,  -497,   127,  -497,   127,  -497,   127,  -497,   127,
    -497,   127,  -497,   127,  -497,   127,  -497,  -497,  -497,  -497,
    -497,    46,  1102,   670,   686,   705,   708,   724,   743,  -497,
    -497,  1103,   746,   762,   173,  1089,   781,   784,   800,  -497,
    1088,  1149,  1137,  -497,  -497,  1161,  -497,  1162,  -497,  1120,
    1178,  1134,  1181,  1121,  1182,  -497,  -497,  1184,  -497,  1147,
    1175,  1179,  1180,  1183,  1196,  1198,  1199,  1200,  1202,  1221,
    1192,   819,   822,  1197,  1213,   838,  1169,   857,   860,  1185,
    1203,   876,  1237,  1215,   895,  1216,  1258,  1204,   898,   914,
    1207,  1219,   933,  1271,  -497,  1234,  -497,  -497,  1279,  -497,
    1292,  -497,  1294,  -497,  -497,  1295,  1256,  1250,  1249,  1251,
    1262,  1257,  1261,  1263,  1275,  -497,  1332,  1293,  1298,   936,
    1333,  1335,  1306,  1336,  1296,  1299,   952,  1351,  1368,  1314,
    -497,  1371,  1331,  1373,  -497,  1374,  1321,  1329,   971,  1389,
    1390,  1337,  -497,  1406,  -497,  -497,  -497,  -497,  1408,  1409,
    1410,  1411,  1412,  1415,  1423,  1427,  1428,  -497,  1431,  1444,
    1405,  -497,  -497,  1447,  -497,  1448,  1449,  1394,  -497,  -497,
    1453,  -497,  1461,  -497,  -497,  1465,  1466,  1413,  -497,  -497,
    1482,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  1484,  -497,  -497,  -497,  1485,  -497,  -497,
    -497,  -497,  1486,  -497,  -497,  -497,  -497
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -497,  -497,  -497,   131,  -497,  -497,  -135,   -10,   114,  -497,
    1382,  -497,  -497,  -497,  -497,  -497,  -132,  -105,  -107,  -247,
     -98,     0,  1496,  -497,  1186,  -497,  -497,  1375,    -1,  -497,
    -497,  -497,  -497,  -497,  -497,  -335,  -283,  -141,  -129,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  1492,
    -497,  -497,  -482,  -497,  -355,  -496,  1506,  -497,  -497,  1483,
    -497,  -497,  -263,   -82,  -497,  1193,  -497,  -497,  1366,  -497,
    -497,   -11,  -497,  -497
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     181,   132,     1,     8,   181,   159,    36,    25,   428,    15,
     137,   203,   199,   333,   335,   578,    29,   197,   200,   565,
     208,   568,   321,   179,    36,     4,   142,     5,   209,    42,
      43,   191,   192,    44,    29,    45,   190,   137,    18,    46,
      98,    98,    19,    98,    98,    98,   379,   181,   193,    98,
     397,   206,   399,   142,     6,     7,   203,    48,   181,   203,
     458,   380,   458,    12,   458,   376,   101,   392,   385,   396,
     240,   398,   102,   383,    56,    57,   170,   402,   404,   406,
     629,   612,   171,   386,   618,   176,   177,   182,   183,    13,
     176,   177,   182,   126,   125,    20,   128,   301,   135,   203,
     147,   302,   158,   303,    14,   165,    37,   304,    38,   455,
     148,   184,   185,   459,   174,   461,   184,   242,   243,   464,
     458,   466,    52,   468,   458,    60,   458,    23,     6,   458,
     347,   458,    95,   458,   244,   100,    23,     6,   463,   599,
     465,    51,   467,    53,    54,    55,     8,     8,   113,    15,
      59,   117,     8,   344,    41,    23,     6,   310,   114,   346,
      42,    43,   119,   120,    44,   118,    45,     6,   195,   196,
      46,    47,    48,    90,    91,    92,    93,    94,   181,    97,
     525,   175,   527,    99,   529,   124,   173,    44,    48,   172,
     458,   186,   458,   127,   458,   191,   192,     8,   182,     8,
       8,   189,   204,   194,   374,   203,   205,   378,   176,   177,
     411,    48,   193,   157,   378,   409,   412,   176,   177,    23,
       6,    24,   184,   428,   417,    23,     6,   133,   134,   127,
     178,   418,   207,   419,   420,   421,   422,   423,   424,   425,
       8,   164,   181,    23,     6,   144,   145,   127,   180,   308,
     307,   211,   309,    23,     6,   124,   306,   312,   316,   320,
     324,    23,     6,   322,   323,   330,   332,   334,   203,   378,
     215,   203,   133,   187,   428,   216,   378,   217,   345,   218,
     348,   221,   474,    23,     6,   144,   343,   228,   148,    23,
       6,   561,   562,    23,     6,   124,   371,    23,     6,   127,
     571,   213,   214,    23,     6,   574,   575,   219,   220,    23,
       6,   127,   223,   224,   225,   226,   227,    23,     6,   157,
       6,   201,   232,   233,   234,    23,     6,   164,   119,   212,
     401,   403,   405,   203,   229,   246,   247,   127,   222,   250,
     251,     6,   144,   198,     8,     8,     8,    61,    62,   230,
      63,    64,    65,   351,   352,   104,   105,   231,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     235,    79,   236,   284,   285,   286,   238,    80,    81,   417,
      82,    83,    84,    85,    86,   245,   418,   248,   419,   420,
     421,   422,   423,   424,   425,   249,   564,   252,   567,     6,
     195,   202,   253,   137,   573,   137,   577,   124,   370,     8,
     254,     8,     8,     6,   195,   237,     6,   195,   239,   142,
     258,   142,     6,   195,   241,     6,   195,   282,    23,     6,
     315,   265,   181,   127,   373,   181,    23,     6,   329,   127,
     375,   181,     6,   195,   408,   181,     6,   144,   410,     6,
     195,   413,     6,   195,   471,     6,   195,   473,   611,   257,
     615,   617,   259,   621,   264,   137,   266,   624,   137,   157,
     377,   628,   272,   632,     8,     6,   195,   475,   273,   181,
     274,   142,   278,   181,   142,   181,     6,   195,   535,   181,
     279,   563,   181,   566,   157,   384,   181,   322,   388,   572,
     181,   576,    23,     6,   561,   351,   427,   659,   127,   438,
     442,   443,   280,   666,   157,   440,   448,   449,   157,   446,
     393,   457,   454,   281,   678,   393,   460,   181,   287,   600,
     283,   601,   293,   602,   181,   603,   292,   604,   298,   605,
     299,   606,   300,   607,   305,   608,   181,   311,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   328,    61,    62,
     336,    63,    64,    65,   393,   462,   106,   107,   337,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   339,    79,   393,   518,   338,   349,   519,    80,    81,
     350,    82,    83,    84,    85,    86,    61,    62,   364,    63,
      64,    65,   393,   521,   108,   109,   365,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   366,
      79,   393,   523,   367,   393,   526,    80,    81,   368,    82,
      83,    84,    85,    86,    61,    62,   369,    63,    64,    65,
     393,   528,   110,   111,   372,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   315,    79,   393,
     530,   382,   393,   589,    80,    81,   387,    82,    83,    84,
      85,    86,    61,    62,   390,    63,    64,    65,   393,   591,
     260,   261,   329,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   391,    79,   393,   593,   400,
     561,   610,    80,    81,   393,    82,    83,    84,    85,    86,
      61,    62,   407,    63,    64,    65,   127,   613,   262,   263,
     414,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   415,    79,   127,   614,   416,   561,   616,
      80,    81,   426,    82,    83,    84,    85,    86,    61,    62,
     429,    63,    64,    65,   127,   619,   270,   271,   430,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   431,    79,   127,   620,   432,   127,   623,    80,    81,
     433,    82,    83,    84,    85,    86,    61,    62,   434,    63,
      64,    65,   127,   625,   288,   289,   435,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   437,
      79,   574,   627,   439,   127,   630,    80,    81,   436,    82,
      83,    84,    85,    86,    61,    62,   441,    63,    64,    65,
     574,   631,   290,   291,   444,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   447,    79,   127,
     657,   445,   127,   658,    80,    81,   450,    82,    83,    84,
      85,    86,    61,    62,   451,    63,    64,    65,   127,   662,
     294,   295,   452,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   453,    79,   127,   664,   456,
     127,   665,    80,    81,   469,    82,    83,    84,    85,    86,
      61,    62,   470,    63,    64,    65,   127,   669,   296,   297,
     477,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   472,    79,   127,   672,   476,   127,   676,
      80,    81,   478,    82,    83,    84,    85,    86,    61,    62,
     479,    63,    64,    65,   574,   677,   501,   502,   489,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   490,    79,   127,   681,   491,   127,   700,    80,    81,
     492,    82,    83,    84,    85,    86,    61,    62,   493,    63,
      64,    65,   127,   707,   503,   504,   494,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   495,
      79,   127,   717,   496,   498,   497,    80,    81,   499,    82,
      83,    84,    85,    86,    61,    62,   500,    63,    64,    65,
     506,   505,   509,   510,   508,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   513,    79,   507,
     515,   514,   520,   531,    80,    81,   522,    82,    83,    84,
      85,    86,    61,    62,   524,    63,    64,    65,   532,   533,
     511,   512,   534,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   536,    79,   537,   538,   557,
     558,   559,    80,    81,   560,    82,    83,    84,    85,    86,
      61,    62,   569,    63,    64,    65,   570,   579,   516,   517,
     581,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   580,    79,   584,   585,   586,   587,   588,
      80,    81,   592,    82,    83,    84,    85,    86,    61,    62,
     590,    63,    64,    65,   594,   595,   539,   540,   596,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   597,    79,   598,   609,   622,   626,   633,    80,    81,
     634,    82,    83,    84,    85,    86,    61,    62,   635,    63,
      64,    65,   636,   637,   541,   542,   638,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   639,
      79,   640,   641,   643,   642,   644,    80,    81,   645,    82,
      83,    84,    85,    86,    61,    62,   646,    63,    64,    65,
     647,   648,   543,   544,   649,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   650,    79,   651,
     652,   653,   655,   654,    80,    81,   663,    82,    83,    84,
      85,    86,    61,    62,   656,    63,    64,    65,   670,   660,
     545,   546,   667,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   661,    79,   671,   673,   674,
     668,   675,    80,    81,   679,    82,    83,    84,    85,    86,
      61,    62,   682,    63,    64,    65,   680,   683,   547,   548,
     684,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   685,    79,   686,   687,   688,   689,   690,
      80,    81,   691,    82,    83,    84,    85,    86,    61,    62,
     693,    63,    64,    65,   692,   694,   549,   550,   695,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   696,    79,   697,   701,   698,   702,   704,    80,    81,
     699,    82,    83,    84,    85,    86,    61,    62,   703,    63,
      64,    65,   708,   705,   551,   552,   706,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   709,
      79,   710,   711,   712,   713,   714,    80,    81,   715,    82,
      83,    84,    85,    86,    61,    62,   716,    63,    64,    65,
     718,   719,   553,   554,   720,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   721,    79,   722,
     723,   724,   725,   726,    80,    81,   727,    82,    83,    84,
      85,    86,    61,    62,   728,    63,    64,    65,   729,   730,
     555,   556,   731,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   732,    79,   733,   734,   735,
     736,   737,    80,    81,   738,    82,    83,    84,    85,    86,
      61,    62,   739,    63,    64,    65,   740,   741,   582,   583,
     742,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   743,    79,   744,   745,   746,   169,     9,
      80,    81,   381,    82,    83,    84,    85,    86,    61,    62,
     188,    63,    64,    65,    40,    16,    66,   389,    58,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   210,    79,     0,     0,     0,     0,     0,    80,    81,
       0,    82,    83,    84,    85,    86,    61,    62,     0,    63,
      64,    65,     0,     0,    89,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      79,     0,     0,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,    86,    61,    62,     0,    63,    64,    65,
       0,     0,   112,     0,     0,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,    79,     0,
       0,     0,     0,     0,    80,    81,     0,    82,    83,    84,
      85,    86,    61,    62,     0,    63,    64,    65,     0,     0,
     115,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,    79,     0,     0,     0,
       0,     0,    80,    81,     0,    82,    83,    84,    85,    86,
      61,    62,     0,    63,    64,    65,     0,     0,   116,     0,
       0,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,    79,     0,     0,     0,     0,     0,
      80,    81,     0,    82,    83,    84,    85,    86,    61,    62,
       0,    63,    64,    65,     0,     0,   255,     0,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,    79,     0,     0,     0,     0,     0,    80,    81,
       0,    82,    83,    84,    85,    86,    61,    62,     0,    63,
      64,    65,     0,     0,   256,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      79,     0,     0,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,    86,    61,    62,     0,    63,    64,    65,
       0,     0,   267,     0,     0,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,    79,     0,
       0,     0,     0,     0,    80,    81,     0,    82,    83,    84,
      85,    86,    61,    62,     0,    63,    64,    65,     0,     0,
     268,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,    79,     0,     0,     0,
       0,     0,    80,    81,     0,    82,    83,    84,    85,    86,
      61,    62,     0,    63,    64,    65,     0,     0,   269,     0,
       0,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,    79,     0,     0,     0,     0,     0,
      80,    81,     0,    82,    83,    84,    85,    86,    61,    62,
       0,    63,    64,    65,     0,     0,   275,     0,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,    79,     0,     0,     0,     0,     0,    80,    81,
       0,    82,    83,    84,    85,    86,    61,    62,     0,    63,
      64,    65,     0,     0,   276,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      79,     0,     0,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,    86,    61,    62,     0,    63,    64,    65,
       0,     0,   277,     0,     0,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,    79,     0,
       0,     0,     0,     0,    80,    81,     0,    82,    83,    84,
      85,    86,    61,    62,     0,    63,    64,    65,     0,     0,
     340,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,    79,     0,     0,     0,
       0,     0,    80,    81,     0,    82,    83,    84,    85,    86,
      61,    62,     0,    63,    64,    65,     0,     0,   341,     0,
       0,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,    79,     0,     0,     0,     0,     0,
      80,    81,     0,    82,    83,    84,    85,    86,    61,    62,
       0,    63,    64,    65,     0,     0,   342,     0,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,    79,     0,     0,     0,     0,     0,    80,    81,
       0,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
     132,   106,    32,     3,   136,   112,    17,    17,   363,     9,
     108,   152,   147,   276,   277,   511,    17,   146,   147,   501,
      59,   503,   269,   128,    35,    74,   108,     0,    67,    44,
      45,    56,    57,    48,    35,    50,   141,   135,     9,    54,
      50,    51,    13,    53,    54,    55,    52,   179,    73,    59,
     333,   158,   335,   135,    29,    30,   197,    72,   190,   200,
     395,    67,   397,    35,   399,   312,    35,   330,    52,   332,
     199,   334,    41,   320,    30,    31,    43,   340,   341,   342,
     576,   563,    49,    67,   566,    44,    45,    46,    47,    10,
      44,    45,    46,   104,   104,    41,   106,    31,   108,   240,
     110,    35,   112,    31,    68,   115,    35,    35,    35,   392,
     110,    70,    71,   396,   125,   398,    70,    56,    57,   402,
     455,   404,    28,   406,   459,    13,   461,    28,    29,   464,
      31,   466,    26,   468,    73,    68,    28,    29,   401,    31,
     403,    27,   405,    29,    30,    31,   146,   147,    35,   149,
      36,    11,   152,   288,    23,    28,    29,   262,    12,   288,
      44,    45,    30,    31,    48,    35,    50,    29,    30,    31,
      54,    55,    72,    42,    43,    44,    45,    46,   310,    48,
     463,    31,   465,    52,   467,    30,    31,    48,    72,    42,
     525,    48,   527,    30,   529,    56,    57,   197,    46,   199,
     200,    31,    50,    50,   309,   346,    54,   314,    44,    45,
     345,    72,    73,    30,   321,   344,   345,    44,    45,    28,
      29,    30,    70,   578,    51,    28,    29,    30,    31,    30,
      31,    58,    31,    60,    61,    62,    63,    64,    65,    66,
     240,    30,   374,    28,    29,    30,    31,    30,    31,   260,
     260,    31,   262,    28,    29,    30,    31,   267,   268,   269,
     270,    28,    29,    30,    31,   275,   276,   277,   409,   376,
      11,   412,    30,    31,   629,    44,   383,    31,   288,    44,
     290,    45,   411,    28,    29,    30,    31,    11,   288,    28,
      29,    30,    31,    28,    29,    30,   307,    28,    29,    30,
      31,   170,   171,    28,    29,    30,    31,   176,   177,    28,
      29,    30,    45,   182,   183,   184,   185,    28,    29,    30,
      29,    30,   191,   192,   193,    28,    29,    30,    30,    31,
     340,   341,   342,   474,    48,   204,   205,    30,    31,   208,
     209,    29,    30,    31,   344,   345,   346,     3,     4,    31,
       6,     7,     8,    30,    31,    11,    12,    48,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      11,    27,    50,   242,   243,   244,    50,    33,    34,    51,
      36,    37,    38,    39,    40,    50,    58,    31,    60,    61,
      62,    63,    64,    65,    66,    54,   501,    31,   503,    29,
      30,    31,    72,   501,   509,   503,   511,    30,    31,   409,
      42,   411,   412,    29,    30,    31,    29,    30,    31,   501,
      44,   503,    29,    30,    31,    29,    30,    31,    28,    29,
      30,    45,   564,    30,    31,   567,    28,    29,    30,    30,
      31,   573,    29,    30,    31,   577,    29,    30,    31,    29,
      30,    31,    29,    30,    31,    29,    30,    31,   563,    11,
     565,   566,    11,   568,    11,   563,    11,   572,   566,    30,
      31,   576,    11,   578,   474,    29,    30,    31,    48,   611,
      11,   563,    11,   615,   566,   617,    29,    30,    31,   621,
      50,   501,   624,   503,    30,    31,   628,    30,    31,   509,
     632,   511,    28,    29,    30,    30,    31,   612,    30,    31,
     379,   380,    11,   618,    30,    31,   385,   386,    30,    31,
      30,    31,   391,    50,   629,    30,    31,   659,    11,   539,
      50,   541,    11,   543,   666,   545,    54,   547,    72,   549,
      11,   551,    11,   553,    11,   555,   678,    11,   417,   418,
     419,   420,   421,   422,   423,   424,   425,    11,     3,     4,
      11,     6,     7,     8,    30,    31,    11,    12,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    27,    30,    31,    50,    11,   456,    33,    34,
      31,    36,    37,    38,    39,    40,     3,     4,    11,     6,
       7,     8,    30,    31,    11,    12,    43,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    31,
      27,    30,    31,    49,    30,    31,    33,    34,    31,    36,
      37,    38,    39,    40,     3,     4,    44,     6,     7,     8,
      30,    31,    11,    12,    31,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    30,    27,    30,
      31,    31,    30,    31,    33,    34,    71,    36,    37,    38,
      39,    40,     3,     4,    31,     6,     7,     8,    30,    31,
      11,    12,    30,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    69,    27,    30,    31,    11,
      30,    31,    33,    34,    30,    36,    37,    38,    39,    40,
       3,     4,    50,     6,     7,     8,    30,    31,    11,    12,
      54,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    31,    27,    30,    31,    59,    30,    31,
      33,    34,    67,    36,    37,    38,    39,    40,     3,     4,
      11,     6,     7,     8,    30,    31,    11,    12,    43,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    27,    30,    31,    49,    30,    31,    33,    34,
      11,    36,    37,    38,    39,    40,     3,     4,    44,     6,
       7,     8,    30,    31,    11,    12,    31,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    45,
      27,    30,    31,    45,    30,    31,    33,    34,    44,    36,
      37,    38,    39,    40,     3,     4,    46,     6,     7,     8,
      30,    31,    11,    12,    31,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    70,    27,    30,
      31,    47,    30,    31,    33,    34,    11,    36,    37,    38,
      39,    40,     3,     4,    71,     6,     7,     8,    30,    31,
      11,    12,    31,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    71,    27,    30,    31,    53,
      30,    31,    33,    34,    11,    36,    37,    38,    39,    40,
       3,     4,    50,     6,     7,     8,    30,    31,    11,    12,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    50,    27,    30,    31,    50,    30,    31,
      33,    34,    54,    36,    37,    38,    39,    40,     3,     4,
      11,     6,     7,     8,    30,    31,    11,    12,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    67,    27,    30,    31,    11,    30,    31,    33,    34,
      11,    36,    37,    38,    39,    40,     3,     4,    11,     6,
       7,     8,    30,    31,    11,    12,    44,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    11,
      27,    30,    31,    11,    11,    45,    33,    34,    46,    36,
      37,    38,    39,    40,     3,     4,    11,     6,     7,     8,
      11,    47,    11,    12,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    27,    70,
      11,    71,    56,    11,    33,    34,    57,    36,    37,    38,
      39,    40,     3,     4,    73,     6,     7,     8,    50,    11,
      11,    12,    50,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    50,    27,    11,    11,    11,
      11,    11,    33,    34,    11,    36,    37,    38,    39,    40,
       3,     4,    11,     6,     7,     8,    11,    11,    11,    12,
      56,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    31,    27,    11,    57,    11,    73,    11,
      33,    34,    57,    36,    37,    38,    39,    40,     3,     4,
      56,     6,     7,     8,    73,    11,    11,    12,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    50,    27,    11,    52,    52,    67,    69,    33,    34,
      11,    36,    37,    38,    39,    40,     3,     4,    31,     6,
       7,     8,    11,    11,    11,    12,    56,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    11,
      27,    57,    11,    11,    73,    11,    33,    34,    51,    36,
      37,    38,    39,    40,     3,     4,    31,     6,     7,     8,
      31,    31,    11,    12,    31,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    31,    27,    31,
      31,    31,    11,    31,    33,    34,    67,    36,    37,    38,
      39,    40,     3,     4,    52,     6,     7,     8,    11,    52,
      11,    12,    67,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    52,    27,    52,    52,    11,
      67,    67,    33,    34,    67,    36,    37,    38,    39,    40,
       3,     4,    11,     6,     7,     8,    67,    53,    11,    12,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    11,    27,    11,    11,    51,    58,    60,
      33,    34,    61,    36,    37,    38,    39,    40,     3,     4,
      63,     6,     7,     8,    62,    64,    11,    12,    65,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    66,    27,    11,    11,    52,    11,    11,    33,    34,
      52,    36,    37,    38,    39,    40,     3,     4,    52,     6,
       7,     8,    11,    67,    11,    12,    67,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    11,
      27,    67,    11,    52,    11,    11,    33,    34,    67,    36,
      37,    38,    39,    40,     3,     4,    67,     6,     7,     8,
      11,    11,    11,    12,    67,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    27,    11,
      11,    11,    11,    11,    33,    34,    11,    36,    37,    38,
      39,    40,     3,     4,    11,     6,     7,     8,    11,    11,
      11,    12,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    11,    27,    52,    11,    11,
      11,    67,    33,    34,    11,    36,    37,    38,    39,    40,
       3,     4,    11,     6,     7,     8,    11,    11,    11,    12,
      67,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    11,    27,    11,    11,    11,   116,     3,
      33,    34,   316,    36,    37,    38,    39,    40,     3,     4,
     135,     6,     7,     8,    22,     9,    11,   324,    35,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   165,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
       3,     4,    -1,     6,     7,     8,    -1,    -1,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,     3,     4,
      -1,     6,     7,     8,    -1,    -1,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
       3,     4,    -1,     6,     7,     8,    -1,    -1,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,     3,     4,
      -1,     6,     7,     8,    -1,    -1,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
       3,     4,    -1,     6,     7,     8,    -1,    -1,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,     3,     4,
      -1,     6,     7,     8,    -1,    -1,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    76,   148,    74,     0,    29,    30,    96,    97,
     131,   136,    35,    10,    68,    96,   131,   133,     9,    13,
      41,   124,   125,    28,    30,    82,    88,    90,    96,   103,
     105,   108,   114,   132,   134,   135,   146,    35,    35,    78,
     124,    78,    44,    45,    48,    50,    54,    55,    72,    82,
      83,    83,    28,    83,    83,    83,    30,    31,   134,    83,
      13,     3,     4,     6,     7,     8,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    27,
      33,    34,    36,    37,    38,    39,    40,    77,    79,    11,
      78,    78,    78,    78,    78,    26,    80,    78,    82,    78,
      68,    35,    41,    85,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    35,    12,    11,    11,    11,    35,    30,
      31,    84,    86,   104,    30,    82,   146,    30,    82,    87,
      89,    91,    92,    30,    31,    82,    92,    95,    98,   102,
     126,   127,   138,   139,    30,    31,    81,    82,    96,    97,
     103,   112,   113,   115,   116,   146,   147,    30,    82,    93,
      95,   106,   107,   138,    30,    82,   143,   144,   145,    85,
      43,    49,    42,    31,   146,    31,    44,    45,    31,    92,
      31,    91,    46,    47,    70,    71,    48,    31,   102,    31,
      92,    56,    57,    73,    50,    30,    31,   113,    31,    81,
     113,    30,    31,   112,    50,    54,    93,    31,    59,    67,
     143,    31,    31,    78,    78,    11,    44,    31,    44,    78,
      78,    45,    31,    45,    78,    78,    78,    78,    11,    48,
      31,    48,    78,    78,    78,    11,    50,    31,    50,    31,
     113,    31,    56,    57,    73,    50,    78,    78,    31,    54,
      78,    78,    31,    72,    42,    11,    11,    11,    44,    11,
      11,    12,    11,    12,    11,    45,    11,    11,    11,    11,
      11,    12,    11,    48,    11,    11,    11,    11,    11,    50,
      11,    50,    31,    50,    78,    78,    78,    11,    11,    12,
      11,    12,    54,    11,    11,    12,    11,    12,    72,    11,
      11,    31,    35,    31,    35,    11,    31,    82,   146,    82,
      92,    11,    82,    93,    94,    30,    82,    99,   100,   101,
      82,    94,    30,    31,    82,   140,   141,   142,    11,    30,
      82,   137,    82,   137,    82,   137,    11,    11,    50,    11,
      11,    11,    11,    31,    81,    82,   113,    31,    82,    11,
      31,    30,    31,   109,   117,   118,   119,   120,   121,   122,
     123,   128,   129,   130,    11,    43,    31,    49,    31,    44,
      31,   146,    31,    31,    92,    31,    94,    31,    93,    52,
      67,    99,    31,    94,    31,    52,    67,    71,    31,   140,
      31,    69,   137,    30,   110,   111,   137,   111,   137,   111,
      11,    82,   137,    82,   137,    82,   137,    50,    31,   113,
      31,    81,   113,    31,    54,    31,    59,    51,    58,    60,
      61,    62,    63,    64,    65,    66,    67,    31,   129,    11,
      43,    11,    49,    11,    44,    31,    44,    45,    31,    45,
      31,    46,    78,    78,    31,    47,    31,    70,    78,    78,
      11,    71,    31,    71,    78,   111,    53,    31,   110,   111,
      31,   111,    31,   137,   111,   137,   111,   137,   111,    11,
      50,    31,    50,    31,   113,    31,    50,    11,    54,    11,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    11,
      67,    11,    11,    11,    44,    11,    11,    45,    11,    46,
      11,    11,    12,    11,    12,    47,    11,    70,    11,    11,
      12,    11,    12,    11,    71,    11,    11,    12,    31,    78,
      56,    31,    57,    31,    73,   111,    31,   111,    31,   111,
      31,    11,    50,    11,    50,    31,    50,    11,    11,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    11,    11,
      11,    30,    31,    82,    92,   127,    82,    92,   127,    11,
      11,    31,    82,    92,    30,    31,    82,    92,   130,    11,
      31,    56,    11,    12,    11,    57,    11,    73,    11,    31,
      56,    31,    57,    31,    73,    11,    11,    50,    11,    31,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    52,
      31,    92,   127,    31,    31,    92,    31,    92,   127,    31,
      31,    92,    52,    31,    92,    31,    67,    31,    92,   130,
      31,    31,    92,    69,    11,    31,    11,    11,    56,    11,
      57,    11,    73,    11,    11,    51,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    11,    52,    31,    31,    92,
      52,    52,    31,    67,    31,    31,    92,    67,    67,    31,
      11,    52,    31,    52,    11,    67,    31,    31,    92,    67,
      67,    31,    11,    53,    11,    11,    11,    11,    51,    58,
      60,    61,    62,    63,    64,    65,    66,    11,    52,    52,
      31,    11,    11,    52,    11,    67,    67,    31,    11,    11,
      67,    11,    52,    11,    11,    67,    67,    31,    11,    11,
      67,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    52,    11,    11,    11,    67,    11,    11,
      11,    11,    67,    11,    11,    11,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

/* User initialization code.  */

{
  globalOwlPrefix = strdup("");
}


  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {(yyval.schemaFileVal) = new XmlSchemaFile((yyvsp[(1) - (2)].versionVal), 0, (yyvsp[(2) - (2)].schemaVal));
	   xmlSchemaFile = (yyval.schemaFileVal);
	  ;}
    break;

  case 3:

    {(yyval.schemaFileVal) = new XmlSchemaFile((yyvsp[(1) - (3)].versionVal), (yyvsp[(2) - (3)].commentListVal), (yyvsp[(3) - (3)].schemaVal));
	   xmlSchemaFile = (yyval.schemaFileVal);
	  ;}
    break;

  case 4:

    {(yyval.attribPairVal) = new XmlAttribPair((yyvsp[(1) - (2)].iVal), 0, (yyvsp[(2) - (2)].sVal));;}
    break;

  case 5:

    {(yyval.attribPairVal) = new XmlAttribPair((yyvsp[(1) - (3)].iVal), (yyvsp[(2) - (3)].sVal), (yyvsp[(3) - (3)].sVal));;}
    break;

  case 6:

    {(yyval.attribPairListVal) = new std::list<XmlAttribPair *>;;}
    break;

  case 7:

    {(yyval.attribPairListVal) = (yyvsp[(1) - (2)].attribPairListVal);
	   std::list<XmlAttribPair *>::iterator iter;
	   for (iter = (yyvsp[(1) - (2)].attribPairListVal)->begin(); iter != (yyvsp[(1) - (2)].attribPairListVal)->end(); iter++)
	     { // check for duplicate names
	       if ((*iter)->name == (yyvsp[(2) - (2)].attribPairVal)->name)
		 {
		   snprintf(errMessage, ERRSIZE,
			    "attribute \"%s\" used twice",
			    attNames[(*iter)->name - ABSTRACT]);
		   yyerror(errMessage);
		 }
	     }
	   (yyvsp[(1) - (2)].attribPairListVal)->push_back((yyvsp[(2) - (2)].attribPairVal));;}
    break;

  case 8:

    {(yyval.iVal) = ABSTRACT;;}
    break;

  case 9:

    {(yyval.iVal) = ATTRIBUTEFORMDEFAULT;;}
    break;

  case 10:

    {(yyval.iVal) = BASE;;}
    break;

  case 11:

    {(yyval.iVal) = DEFALT;;}
    break;

  case 12:

    {(yyval.iVal) = ELEMENTFORMDEFAULT;;}
    break;

  case 13:

    {(yyval.iVal) = FINAL;;}
    break;

  case 14:

    {(yyval.iVal) = FIXED;;}
    break;

  case 15:

    {(yyval.iVal) = FORM;;}
    break;

  case 16:

    {(yyval.iVal) = ID;;}
    break;

  case 17:

    {(yyval.iVal) = ITEMTYPE;;}
    break;

  case 18:

    {(yyval.iVal) = MAXOCCURS;;}
    break;

  case 19:

    {(yyval.iVal) = MINOCCURS;;}
    break;

  case 20:

    {(yyval.iVal) = MIXED;;}
    break;

  case 21:

    {(yyval.iVal) = NAME;;}
    break;

  case 22:

    {(yyval.iVal) = NILLABLE;;}
    break;

  case 23:

    {(yyval.iVal) = REF;;}
    break;

  case 24:

    {(yyval.iVal) = REFER;;}
    break;

  case 25:

    {(yyval.iVal) = SOURCE;;}
    break;

  case 26:

    {(yyval.iVal) = SUBSTITUTIONGROUP;;}
    break;

  case 27:

    {(yyval.iVal) = TARGETNAMESPACE;;}
    break;

  case 28:

    {(yyval.iVal) = TYP;;}
    break;

  case 29:

    {(yyval.iVal) = USE;;}
    break;

  case 30:

    {(yyval.iVal) = VALUE;;}
    break;

  case 31:

    {(yyval.iVal) = VERSION;;}
    break;

  case 32:

    {(yyval.iVal) = XPATH;;}
    break;

  case 33:

    {(yyval.sVal) = (yyvsp[(2) - (2)].sVal);;}
    break;

  case 34:

    {(yyval.typVal) = (yyvsp[(1) - (1)].complexTypeVal);;}
    break;

  case 35:

    {(yyval.typVal) = (yyvsp[(1) - (1)].simpleTypeVal);;}
    break;

  case 36:

    {(yyval.annotationVal) = new XmlAnnotation();
	   doXmlAnnotationAttributes((yyval.annotationVal), (yyvsp[(2) - (7)].attribPairListVal));
           (yyval.annotationVal)->comment = 0;
	   (yyval.annotationVal)->content = (yyvsp[(4) - (7)].annoTypeListVal);
	  ;}
    break;

  case 37:

    {(yyval.annotationVal) = new XmlAnnotation();
	   doXmlAnnotationAttributes((yyval.annotationVal), (yyvsp[(3) - (8)].attribPairListVal));
           (yyval.annotationVal)->comment = (yyvsp[(1) - (8)].commentVal);
	   (yyval.annotationVal)->content = (yyvsp[(5) - (8)].annoTypeListVal);
	  ;}
    break;

  case 38:

    {(yyval.annotationVal) = new XmlAnnotation(); // makes shift/reduce conflict but is OK
	   (yyval.annotationVal)->comment = (yyvsp[(1) - (1)].commentVal);
	   (yyval.annotationVal)->content = 0;
	  ;}
    break;

  case 39:

    {(yyval.annotationListVal) = new std::list<XmlAnnotation *>;
	   (yyval.annotationListVal)->push_back((yyvsp[(1) - (1)].annotationVal));
          ;}
    break;

  case 40:

    {(yyval.annotationListVal) = (yyvsp[(1) - (2)].annotationListVal);
	   (yyvsp[(1) - (2)].annotationListVal)->push_back((yyvsp[(2) - (2)].annotationVal));
	  ;}
    break;

  case 41:

    {(yyval.annoTypeVal) = (yyvsp[(1) - (1)].documentationVal);;}
    break;

  case 42:

    {(yyval.annoTypeVal) = (yyvsp[(1) - (1)].appinfoVal);;}
    break;

  case 43:

    {(yyval.annoTypeListVal) = new std::list<XmlAnnoType *>;;}
    break;

  case 44:

    {(yyval.annoTypeListVal) = (yyvsp[(1) - (2)].annoTypeListVal);
	   (yyvsp[(1) - (2)].annoTypeListVal)->push_back((yyvsp[(2) - (2)].annoTypeVal));
	  ;}
    break;

  case 45:

    {(yyval.appinfoVal) = new XmlAppinfo();
	   doXmlAppinfoAttributes((yyval.appinfoVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.appinfoVal)->text = (yyvsp[(5) - (8)].sVal);
	  ;}
    break;

  case 46:

    {(yyval.appinfoVal) = new XmlAppinfo();
	   doXmlAppinfoAttributes((yyval.appinfoVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.appinfoVal)->text = strdup("");
	  ;}
    break;

  case 47:

    {(yyval.attributeLonerVal) = new XmlAttributeLoner();
	   doXmlAttributeLonerAttributes((yyval.attributeLonerVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 48:

    {(yyval.attributeLonerVal) = new XmlAttributeLoner();
	   doXmlAttributeLonerAttributes((yyval.attributeLonerVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 49:

    {(yyval.attributeLonerVal) = new XmlAttributeLoner();
	   doXmlAttributeLonerAttributes((yyval.attributeLonerVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeLonerVal)->simple = (yyvsp[(5) - (8)].simpleTypeVal);
	  ;}
    break;

  case 50:

    {(yyval.attributeLonerVal) = new XmlAttributeLoner();
	   doXmlAttributeLonerAttributes((yyval.attributeLonerVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeLonerVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 51:

    {(yyval.attributeLonerVal) = new XmlAttributeLoner();
	   doXmlAttributeLonerAttributes((yyval.attributeLonerVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.attributeLonerVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.attributeLonerVal)->simple = (yyvsp[(6) - (9)].simpleTypeVal);
	  ;}
    break;

  case 52:

    {(yyval.attributeLonerRefableVal) = new XmlAttributeLonerRefable();
	   doXmlAttributeLonerRefableAttributes((yyval.attributeLonerRefableVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 53:

    {(yyval.attributeLonerRefableVal) = new XmlAttributeLonerRefable();
	   doXmlAttributeLonerRefableAttributes((yyval.attributeLonerRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeLonerRefableVal)->simple = (yyvsp[(5) - (8)].simpleTypeVal);
	  ;}
    break;

  case 54:

    {(yyval.attributeLonerRefableVal) = new XmlAttributeLonerRefable();
	   doXmlAttributeLonerRefableAttributes((yyval.attributeLonerRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeLonerRefableVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 55:

    {(yyval.attributeLonerRefableVal) = new XmlAttributeLonerRefable();
	   doXmlAttributeLonerRefableAttributes((yyval.attributeLonerRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.attributeLonerRefableVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.attributeLonerRefableVal)->simple = (yyvsp[(6) - (9)].simpleTypeVal);
	  ;}
    break;

  case 56:

    {(yyval.attributeGroupVal) = new XmlAttributeGroup();
	   doXmlAttributeGroupAttributes((yyval.attributeGroupVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.attributeGroupVal)->xmlAttributes = new std::list<XmlAttributor *>;
	  ;}
    break;

  case 57:

    {(yyval.attributeGroupVal) = new XmlAttributeGroup();
	   doXmlAttributeGroupAttributes((yyval.attributeGroupVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeGroupVal)->xmlAttributes = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 58:

    {(yyval.attributeGroupVal) = new XmlAttributeGroup();
	   doXmlAttributeGroupAttributes((yyval.attributeGroupVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeGroupVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 59:

    {(yyval.attributeGroupVal) = new XmlAttributeGroup();
	   doXmlAttributeGroupAttributes((yyval.attributeGroupVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.attributeGroupVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.attributeGroupVal)->xmlAttributes = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 60:

    {(yyval.attributeGroupRefableVal) = new XmlAttributeGroupRefable();
	   doXmlAttributeGroupRefableAttributes((yyval.attributeGroupRefableVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.attributeGroupRefableVal)->xmlAttributes = new std::list<XmlAttributor *>;
	  ;}
    break;

  case 61:

    {(yyval.attributeGroupRefableVal) = new XmlAttributeGroupRefable();
	   doXmlAttributeGroupRefableAttributes((yyval.attributeGroupRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeGroupRefableVal)->xmlAttributes = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 62:

    {(yyval.attributeGroupRefableVal) = new XmlAttributeGroupRefable();
	   doXmlAttributeGroupRefableAttributes((yyval.attributeGroupRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.attributeGroupRefableVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 63:

    {(yyval.attributeGroupRefableVal) = new XmlAttributeGroupRefable();
	   doXmlAttributeGroupRefableAttributes((yyval.attributeGroupRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.attributeGroupRefableVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.attributeGroupRefableVal)->xmlAttributes = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 64:

    {(yyval.attributorVal) = (yyvsp[(1) - (1)].attributeLonerVal);;}
    break;

  case 65:

    {(yyval.attributorVal) = (yyvsp[(1) - (1)].attributeGroupVal);;}
    break;

  case 66:

    {(yyval.attributorListVal) = new std::list<XmlAttributor *>;
	   (yyval.attributorListVal)->push_back((yyvsp[(1) - (1)].attributorVal));
	  ;}
    break;

  case 67:

    {(yyval.attributorListVal) = (yyvsp[(1) - (2)].attributorListVal);
	   (yyvsp[(1) - (2)].attributorListVal)->push_back((yyvsp[(2) - (2)].attributorVal));
	  ;}
    break;

  case 68:

    {(yyval.choSeqItemVal) = (yyvsp[(1) - (1)].choiceVal);;}
    break;

  case 69:

    {(yyval.choSeqItemVal) = (yyvsp[(1) - (1)].elementGroupRefVal);;}
    break;

  case 70:

    {(yyval.choSeqItemVal) = (yyvsp[(1) - (1)].elementLocalVal);;}
    break;

  case 71:

    {(yyval.choSeqItemVal) = (yyvsp[(1) - (1)].sequenceVal);;}
    break;

  case 72:

    {(yyval.choSeqItemListVal) = new std::list<XmlChoSeqItem *>;
	   (yyval.choSeqItemListVal)->push_back((yyvsp[(1) - (1)].choSeqItemVal));
	  ;}
    break;

  case 73:

    {(yyval.choSeqItemListVal) = (yyvsp[(1) - (2)].choSeqItemListVal);
	   (yyvsp[(1) - (2)].choSeqItemListVal)->push_back((yyvsp[(2) - (2)].choSeqItemVal));
	  ;}
    break;

  case 74:

    {(yyval.choiceVal) = new XmlChoice(); // might add check that list is not empty
	   doXmlChoiceAttributes((yyval.choiceVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.choiceVal)->items = (yyvsp[(5) - (8)].choSeqItemListVal);
	  ;}
    break;

  case 75:

    {(yyval.choiceVal) = new XmlChoice(); // might add check that list is not empty
	   doXmlChoiceAttributes((yyval.choiceVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.choiceVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.choiceVal)->items = (yyvsp[(6) - (9)].choSeqItemListVal);
	  ;}
    break;

  case 76:

    {(yyval.commentVal) = new std::string(commentString);;}
    break;

  case 77:

    {(yyval.commentListVal) = new std::list<std::string *>;
	   (yyval.commentListVal)->push_back((yyvsp[(1) - (1)].commentVal));
	  ;}
    break;

  case 78:

    {(yyval.commentListVal) = (yyvsp[(1) - (2)].commentListVal);
	   (yyvsp[(1) - (2)].commentListVal)->push_back((yyvsp[(2) - (2)].commentVal));
	  ;}
    break;

  case 79:

    {(yyval.complexContentVal) = new XmlComplexContent();
	   doXmlComplexContentAttributes((yyval.complexContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexContentVal)->item = (yyvsp[(5) - (8)].complexContentItemVal);
	  ;}
    break;

  case 80:

    {(yyval.complexContentVal) = new XmlComplexContent();
	   doXmlComplexContentAttributes((yyval.complexContentVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexContentVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexContentVal)->item = (yyvsp[(6) - (9)].complexContentItemVal);
	  ;}
    break;

  case 81:

    {(yyval.complexContentItemVal) = (yyvsp[(1) - (1)].complexRestrictionVal);;}
    break;

  case 82:

    {(yyval.complexContentItemVal) = (yyvsp[(1) - (1)].complexExtensionVal);;}
    break;

  case 83:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 84:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 85:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 86:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexExtensionVal)->item = (yyvsp[(6) - (9)].otherContentBaseVal);
	  ;}
    break;

  case 87:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 88:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.complexExtensionVal)->item = (yyvsp[(6) - (10)].otherContentBaseVal);
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 89:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexExtensionVal)->item = (yyvsp[(5) - (8)].otherContentBaseVal);
	  ;}
    break;

  case 90:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexExtensionVal)->item = (yyvsp[(5) - (9)].otherContentBaseVal);
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 91:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 92:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 93:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 94:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexRestrictionVal)->item = (yyvsp[(6) - (9)].otherContentBaseVal);
	  ;}
    break;

  case 95:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 96:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.complexRestrictionVal)->item = (yyvsp[(6) - (10)].otherContentBaseVal);
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 97:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexRestrictionVal)->item = (yyvsp[(5) - (8)].otherContentBaseVal);
	  ;}
    break;

  case 98:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexRestrictionVal)->item = (yyvsp[(5) - (9)].otherContentBaseVal);
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 99:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 100:

    {(yyval.complexTypeItemVal) = (yyvsp[(1) - (1)].complexContentVal);;}
    break;

  case 101:

    {(yyval.complexTypeItemVal) = (yyvsp[(1) - (1)].otherContentVal);;}
    break;

  case 102:

    {(yyval.complexTypeItemVal) = (yyvsp[(1) - (1)].simpleContentVal);;}
    break;

  case 103:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   (yyval.complexTypeVal)->item = new XmlOtherContent(0, 0);
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 104:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   (yyval.complexTypeVal)->item = new XmlOtherContent(0, 0);
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 105:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexTypeVal)->item = (yyvsp[(5) - (8)].complexTypeItemVal);
	  ;}
    break;

  case 106:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   (yyval.complexTypeVal)->item = new XmlOtherContent(0, 0);
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexTypeVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 107:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexTypeVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexTypeVal)->item = (yyvsp[(6) - (9)].complexTypeItemVal);
	  ;}
    break;

  case 108:

    {(yyval.documentationVal) = new XmlDocumentation();
	   (yyval.documentationVal)->text = (yyvsp[(5) - (8)].sVal);
	   doXmlDocumentationAttributes((yyval.documentationVal), (yyvsp[(3) - (8)].attribPairListVal));
	  ;}
    break;

  case 109:

    {(yyval.documentationVal) = new XmlDocumentation();
	   (yyval.documentationVal)->text = strdup("");
	   doXmlDocumentationAttributes((yyval.documentationVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 110:

    {(yyval.elementGroupVal) = new XmlElementGroup();
	   doXmlElementGroupAttributes((yyval.elementGroupVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementGroupVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementGroupVal)->item = (yyvsp[(6) - (9)].choSeqItemVal);
	  ;}
    break;

  case 111:

    {(yyval.elementGroupVal) = new XmlElementGroup();
	   doXmlElementGroupAttributes((yyval.elementGroupVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementGroupVal)->item = (yyvsp[(5) - (8)].choSeqItemVal);
	  ;}
    break;

  case 112:

    {(yyval.elementGroupRefVal) = new XmlElementGroupRef();
	   doXmlElementGroupRefAttributes((yyval.elementGroupRefVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 113:

    {(yyval.elementGroupRefVal) = new XmlElementGroupRef();
	   doXmlElementGroupRefAttributes((yyval.elementGroupRefVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 114:

    {(yyval.elementGroupRefVal) = new XmlElementGroupRef();
	   doXmlElementGroupRefAttributes((yyval.elementGroupRefVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementGroupRefVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 115:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 116:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (8)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(5) - (8)].typVal);
	  ;}
    break;

  case 117:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (9)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(6) - (9)].typVal);
	  ;}
    break;

  case 118:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(5) - (8)].idConstraintListVal);
	  ;}
    break;

  case 119:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 120:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (9)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(5) - (9)].typVal);
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 121:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (10)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(6) - (10)].typVal);
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(7) - (10)].idConstraintListVal);
	  ;}
    break;

  case 122:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 123:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 124:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 125:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(5) - (8)].typVal);
	  ;}
    break;

  case 126:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(6) - (9)].typVal);
	  ;}
    break;

  case 127:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 128:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(5) - (9)].typVal);
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 129:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(6) - (10)].typVal);
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(7) - (10)].idConstraintListVal);
	  ;}
    break;

  case 130:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(5) - (8)].idConstraintListVal);
	  ;}
    break;

  case 131:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 132:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 133:

    {(yyval.enumerationVal) = new XmlEnumeration();
	   doXmlEnumerationAttributes((yyval.enumerationVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 134:

    {(yyval.enumerationVal) = new XmlEnumeration();
	   doXmlEnumerationAttributes((yyval.enumerationVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 135:

    {(yyval.enumerationVal) = new XmlEnumeration();
	   doXmlEnumerationAttributes((yyval.enumerationVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.enumerationVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 136:

    {(yyval.fieldVal) = new XmlField();
	   doXmlFieldAttributes((yyval.fieldVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 137:

    {(yyval.fieldVal) = new XmlField();
	   doXmlFieldAttributes((yyval.fieldVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 138:

    {(yyval.fieldListVal) = new std::list<XmlField *>;
	   (yyval.fieldListVal)->push_back((yyvsp[(1) - (1)].fieldVal));
	  ;}
    break;

  case 139:

    {(yyval.fieldListVal) = (yyvsp[(1) - (2)].fieldListVal);
	   (yyvsp[(1) - (2)].fieldListVal)->push_back((yyvsp[(2) - (2)].fieldVal));
	  ;}
    break;

  case 140:

    {(yyval.idConstraintVal) = (yyvsp[(1) - (1)].keyVal);;}
    break;

  case 141:

    {(yyval.idConstraintVal) = (yyvsp[(1) - (1)].keyrefVal);;}
    break;

  case 142:

    {(yyval.idConstraintVal) = (yyvsp[(1) - (1)].uniqueVal);;}
    break;

  case 143:

    {(yyval.idConstraintListVal) = new std::list<XmlIdConstraint *>;
	   (yyval.idConstraintListVal)->push_back((yyvsp[(1) - (1)].idConstraintVal));
	  ;}
    break;

  case 144:

    {(yyval.idConstraintListVal) = (yyvsp[(1) - (2)].idConstraintListVal);
	   (yyvsp[(1) - (2)].idConstraintListVal)->push_back((yyvsp[(2) - (2)].idConstraintVal));
	  ;}
    break;

  case 145:

    {(yyval.includeVal) = new XmlInclude((yyvsp[(3) - (4)].sVal), 0);;}
    break;

  case 146:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.keyVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 147:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.keyVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.keyVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 148:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.keyVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.keyVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 149:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(4) - (11)].attribPairListVal));
           (yyval.keyVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.keyVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.keyVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 150:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.keyrefVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 151:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.keyrefVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.keyrefVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 152:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.keyrefVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.keyrefVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 153:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(4) - (11)].attribPairListVal));
	   (yyval.keyrefVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.keyrefVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.keyrefVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 154:

    {(yyval.lengthVal) = new XmlLength();
	   doXmlLengthAttributes((yyval.lengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 155:

    {(yyval.lengthVal) = new XmlLength();
	   doXmlLengthAttributes((yyval.lengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.lengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 156:

    {(yyval.maxExclusiveVal) = new XmlMaxExclusive();
	   doXmlMaxExclusiveAttributes((yyval.maxExclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 157:

    {(yyval.maxExclusiveVal) = new XmlMaxExclusive();
	   doXmlMaxExclusiveAttributes((yyval.maxExclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxExclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 158:

    {(yyval.maxInclusiveVal) = new XmlMaxInclusive();
	   doXmlMaxInclusiveAttributes((yyval.maxInclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 159:

    {(yyval.maxInclusiveVal) = new XmlMaxInclusive();
	   doXmlMaxInclusiveAttributes((yyval.maxInclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxInclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 160:

    {(yyval.maxLengthVal) = new XmlMaxLength();
	   doXmlMaxLengthAttributes((yyval.maxLengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 161:

    {(yyval.maxLengthVal) = new XmlMaxLength();
	   doXmlMaxLengthAttributes((yyval.maxLengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxLengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 162:

    {(yyval.minExclusiveVal) = new XmlMinExclusive();
	   doXmlMinExclusiveAttributes((yyval.minExclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 163:

    {(yyval.minExclusiveVal) = new XmlMinExclusive();
	   doXmlMinExclusiveAttributes((yyval.minExclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minExclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 164:

    {(yyval.minInclusiveVal) = new XmlMinInclusive();
	   doXmlMinInclusiveAttributes((yyval.minInclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 165:

    {(yyval.minInclusiveVal) = new XmlMinInclusive();
	   doXmlMinInclusiveAttributes((yyval.minInclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minInclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 166:

    {(yyval.minLengthVal) = new XmlMinLength();
	   doXmlMinLengthAttributes((yyval.minLengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 167:

    {(yyval.minLengthVal) = new XmlMinLength();
	   doXmlMinLengthAttributes((yyval.minLengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minLengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 168:

    {(yyval.nsPairVal) = new XmlNsPair((yyvsp[(1) - (2)].sVal), (yyvsp[(2) - (2)].sVal));;}
    break;

  case 169:

    {(yyval.nsPairListVal) = new std::list<XmlNsPair *>;
	   (yyval.nsPairListVal)->push_back((yyvsp[(1) - (1)].nsPairVal));
	  ;}
    break;

  case 170:

    {(yyval.nsPairListVal) = (yyvsp[(1) - (2)].nsPairListVal);
	   (yyvsp[(1) - (2)].nsPairListVal)->push_back((yyvsp[(2) - (2)].nsPairVal));
	  ;}
    break;

  case 171:

    {(yyval.otherContentVal) = new XmlOtherContent((yyvsp[(1) - (1)].otherContentBaseVal), 0);;}
    break;

  case 172:

    {(yyval.otherContentVal) = new XmlOtherContent(0, (yyvsp[(1) - (1)].attributorListVal));;}
    break;

  case 173:

    {(yyval.otherContentVal) = new XmlOtherContent((yyvsp[(1) - (2)].otherContentBaseVal), (yyvsp[(2) - (2)].attributorListVal));;}
    break;

  case 174:

    {(yyval.otherContentBaseVal) = (yyvsp[(1) - (1)].choiceVal);;}
    break;

  case 175:

    {(yyval.otherContentBaseVal) = (yyvsp[(1) - (1)].sequenceVal);;}
    break;

  case 176:

    {(yyval.patternVal) = new XmlPattern();
	   doXmlPatternAttributes((yyval.patternVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 177:

    {(yyval.patternVal) = new XmlPattern();
	   doXmlPatternAttributes((yyval.patternVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.patternVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 178:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].lengthVal);;}
    break;

  case 179:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxExclusiveVal);;}
    break;

  case 180:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxInclusiveVal);;}
    break;

  case 181:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxLengthVal);;}
    break;

  case 182:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minExclusiveVal);;}
    break;

  case 183:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minInclusiveVal);;}
    break;

  case 184:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minLengthVal);;}
    break;

  case 185:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].patternVal);;}
    break;

  case 186:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].enumerationVal);;}
    break;

  case 187:

    {(yyval.restrictionTypeListVal) = new std::list<XmlRestrictionType *>;
	   (yyval.restrictionTypeListVal)->push_back((yyvsp[(1) - (1)].restrictionTypeVal));
	  ;}
    break;

  case 188:

    {(yyval.restrictionTypeListVal) = (yyvsp[(1) - (2)].restrictionTypeListVal);
	   (yyvsp[(1) - (2)].restrictionTypeListVal)->push_back((yyvsp[(2) - (2)].restrictionTypeVal));
	  ;}
    break;

  case 189:

    {(yyval.schemaVal) = new XmlSchema((yyvsp[(1) - (6)].schemaHeaderVal), (yyvsp[(2) - (6)].schemaContent1ListVal), (yyvsp[(3) - (6)].schemaContent2ListVal));;}
    break;

  case 190:

    {(yyval.schemaContent1Val) = (yyvsp[(1) - (1)].includeVal);;}
    break;

  case 191:

    {(yyval.schemaContent1Val) = (yyvsp[(1) - (1)].annotationVal);;}
    break;

  case 192:

    {(yyval.schemaContent1ListVal) = new std::list<XmlSchemaContent1 *>;
	    //$$->push_back($1);
	  ;}
    break;

  case 193:

    {(yyval.schemaContent1ListVal) = (yyvsp[(1) - (2)].schemaContent1ListVal);
	   (yyvsp[(1) - (2)].schemaContent1ListVal)->push_back((yyvsp[(2) - (2)].schemaContent1Val));
	  ;}
    break;

  case 194:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].elementGroupVal);;}
    break;

  case 195:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].elementGroupVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 196:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].elementRefableVal);;}
    break;

  case 197:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].elementRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 198:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].complexTypeVal);;}
    break;

  case 199:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].complexTypeVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 200:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].simpleTypeVal);;}
    break;

  case 201:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].simpleTypeVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 202:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].attributeLonerRefableVal);;}
    break;

  case 203:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].attributeLonerRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 204:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].attributeGroupRefableVal);;}
    break;

  case 205:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].attributeGroupRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 206:

    {(yyval.schemaContent2ListVal) = new std::list<XmlSchemaContent2 *>;
	   (yyval.schemaContent2ListVal)->push_back((yyvsp[(1) - (1)].schemaContent2Val));
	  ;}
    break;

  case 207:

    {(yyval.schemaContent2ListVal) = (yyvsp[(1) - (2)].schemaContent2ListVal);
	   (yyvsp[(1) - (2)].schemaContent2ListVal)->push_back((yyvsp[(2) - (2)].schemaContent2Val));
	  ;}
    break;

  case 208:

    { // note that this removes the first element from the xmlNsList
	    checkXmlns((yyvsp[(3) - (5)].nsPairListVal));
	    (yyval.schemaHeaderVal) = new XmlSchemaHeader(0, 0, (yyvsp[(3) - (5)].nsPairListVal)->front(), (yyvsp[(3) - (5)].nsPairListVal),
				     XmlCppBase::formNone,
				     XmlCppBase::formNone, 0);
	    doXmlSchemaHeaderAttributes((yyval.schemaHeaderVal), (yyvsp[(4) - (5)].attribPairListVal));
	    (yyvsp[(3) - (5)].nsPairListVal)->pop_front();
	  ;}
    break;

  case 209:

    {(yyval.selectorVal) = new XmlSelector();
	   doXmlSelectorAttributes((yyval.selectorVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 210:

    {(yyval.selectorVal) = new XmlSelector();
	   doXmlSelectorAttributes((yyval.selectorVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 211:

    {(yyval.sequenceVal) = new XmlSequence();
	   doXmlSequenceAttributes((yyval.sequenceVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.sequenceVal)->items = (yyvsp[(5) - (8)].choSeqItemListVal);
	  ;}
    break;

  case 212:

    {(yyval.sequenceVal) = new XmlSequence();
	   doXmlSequenceAttributes((yyval.sequenceVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.sequenceVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.sequenceVal)->items = (yyvsp[(6) - (9)].choSeqItemListVal);
	  ;}
    break;

  case 213:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 214:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 215:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 216:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentVal)->item = (yyvsp[(5) - (8)].simpleContentItemVal);
	  ;}
    break;

  case 217:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentVal)->item = (yyvsp[(6) - (9)].simpleContentItemVal);
	  ;}
    break;

  case 218:

    {(yyval.simpleContentItemVal) = (yyvsp[(1) - (1)].simpleContentExtensionVal);;}
    break;

  case 219:

    {(yyval.simpleContentItemVal) = (yyvsp[(1) - (1)].simpleContentRestrictionVal);;}
    break;

  case 220:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 221:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 222:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 223:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 224:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 225:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 226:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 227:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 228:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(5) - (8)].restrictionTypeListVal);
	  ;}
    break;

  case 229:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 230:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(6) - (9)].restrictionTypeListVal);
	  ;}
    break;

  case 231:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 232:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(5) - (9)].restrictionTypeListVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 233:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(6) - (10)].restrictionTypeListVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 234:

    {(yyval.simpleItemVal) = (yyvsp[(1) - (1)].simpleListVal);;}
    break;

  case 235:

    {(yyval.simpleItemVal) = (yyvsp[(1) - (1)].simpleRestrictionVal);;}
    break;

  case 236:

    {(yyval.simpleListVal) = new XmlSimpleList();
	   doXmlSimpleListAttributes((yyval.simpleListVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 237:

    {(yyval.simpleListVal) = new XmlSimpleList();
	   doXmlSimpleListAttributes((yyval.simpleListVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 238:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 239:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 240:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = (yyvsp[(5) - (8)].restrictionTypeListVal);
	  ;}
    break;

  case 241:

    {(yyval.simpleTypeVal) = new XmlSimpleType();
	   doXmlSimpleTypeAttributes((yyval.simpleTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleTypeVal)->item = (yyvsp[(5) - (8)].simpleItemVal);
	  ;}
    break;

  case 242:

    {(yyval.simpleTypeVal) = new XmlSimpleType();
	   doXmlSimpleTypeAttributes((yyval.simpleTypeVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleTypeVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleTypeVal)->item = (yyvsp[(6) - (9)].simpleItemVal);
	  ;}
    break;

  case 243:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.uniqueVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 244:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.uniqueVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 245:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.uniqueVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 246:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(4) - (11)].attribPairListVal));
           (yyval.uniqueVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.uniqueVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 247:

    {(yyval.versionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  ;}
    break;

  case 248:

    {(yyval.versionVal) = new XmlVersion(true);
	   if (strcmp((yyvsp[(3) - (6)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	   else if (strcmp((yyvsp[(5) - (6)].sVal), "UTF-8"))
	     yyerror("encoding must be UTF-8");
	  ;}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





/********************************************************************/

/* yyerror

Returned Value: int (0)

Called By: yyparse

This prints whatever string the parser provides.

*/

int yyerror(     /* ARGUMENTS       */
 const char * s) /* string to print */
{
  fflush(stdout);
  if (lexMessage[0])
    {
      printf("\n%s\n", lexMessage);
      lexMessage[0] = 0;
      exit(1);
    }
  else
    {
      fprintf(stderr, "\n%s\n", s);
      exit(1);
    }
  return 0;
}

/********************************************************************/


