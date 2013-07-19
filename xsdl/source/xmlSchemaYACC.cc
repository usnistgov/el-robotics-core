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
    "XSINCLUDE",
    "XSKEY",
    "XSKEYREF",
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

This checks that the prefix in the first member of the prefixList,
which is the prefix found on the first xmlns line of the schema
(usually the third line of the schema file), is the same as the
XmlCppBase::wg3Prefix, which gets set when the schema line (usually
the second line of the file) gets read. If not, it prints an error
message and exits.

Then it checks that the location for the first prefix is 
"http://www.w3.org/2001/XMLSchema"
If not, it prints an error message and exits.

If there are 2 entries in the prefixList, this sets the
XmlCppBase::otherPrefix to the second prefix. It does not care what the
prefix is as long as it is a char *.  A 0 pointer is OK.

Otherwise, if there are more than 2 entries in the prefixList, this prints
an error message and exits. At some point it would be good to enhance the
system so it handles more xmlns's.

*/

void checkXmlns(                      /* ARGUMENTS                   */
 std::list<XmlNsPair *> * prefixList) /* list of XmlNsPairs to check */
{
  char * prefix;

  prefix = prefixList->front()->prefix;
  if (strcmp(XmlCppBase::wg3Prefix, prefix))
    {
      snprintf(errMessage, ERRSIZE,
	      "xmlns suffix \"%s\" differs from schema prefix \"%s\"",
	      prefix, XmlCppBase::wg3Prefix);
      yyerror(errMessage);
    }
  if (strcmp("http://www.w3.org/2001/XMLSchema",
	     prefixList->front()->location))
    {
      snprintf(errMessage, ERRSIZE, "xmlns location for xml schema must be\n"
	       "http://www.w3.org/2001/XMLSchema but is %s",
	       prefixList->front()->location);
      yyerror(errMessage);
    }
  if (prefixList->size() == 2)
    {
      XmlCppBase::otherPrefix = prefixList->back()->prefix;
    }
  else if (prefixList->size() > 2)
    yyerror("cannot handle more than 2 xmlns");
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
}

/********************************************************************/

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
     XSINCLUDE = 309,
     XSKEY = 310,
     XSKEYREF = 311,
     XSLIST = 312,
     XSMAXEXCLUSIVE = 313,
     XSMAXINCLUSIVE = 314,
     XSMAXLENGTH = 315,
     XSMINEXCLUSIVE = 316,
     XSMININCLUSIVE = 317,
     XSMINLENGTH = 318,
     XSPATTERN = 319,
     XSRESTRICTION = 320,
     XSSCHEMA = 321,
     XSSELECTOR = 322,
     XSSEQUENCE = 323,
     XSSIMPLECONTENT = 324,
     XSSIMPLETYPE = 325,
     XSUNIQUE = 326,
     XMLVERSION = 327
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
#define YYLAST   2089

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNRULES -- Number of states.  */
#define YYNSTATES  706

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

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
      65,    66,    67,    68,    69,    70,    71,    72
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
     280,   282,   284,   287,   296,   306,   309,   311,   314,   323,
     333,   335,   337,   342,   350,   359,   369,   379,   390,   399,
     409,   418,   423,   432,   442,   452,   463,   472,   482,   491,
     493,   495,   497,   502,   510,   519,   528,   538,   547,   555,
     564,   573,   583,   592,   602,   612,   623,   631,   636,   645,
     654,   664,   674,   684,   695,   704,   709,   714,   723,   728,
     736,   738,   741,   743,   745,   747,   749,   752,   757,   767,
     778,   789,   801,   811,   822,   833,   845,   850,   859,   864,
     873,   878,   887,   892,   901,   906,   915,   920,   929,   932,
     934,   937,   939,   941,   944,   946,   948,   953,   962,   964,
     966,   968,   970,   972,   974,   976,   978,   980,   983,   990,
     992,   994,   995,   998,  1000,  1003,  1005,  1008,  1010,  1013,
    1015,  1018,  1020,  1023,  1025,  1028,  1034,  1039,  1047,  1056,
    1066,  1071,  1079,  1088,  1097,  1107,  1109,  1111,  1116,  1124,
    1133,  1142,  1152,  1157,  1165,  1174,  1183,  1192,  1202,  1212,
    1222,  1233,  1235,  1237,  1242,  1250,  1255,  1263,  1272,  1281,
    1291,  1301,  1312,  1323,  1335,  1340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      74,     0,    -1,   143,   126,    -1,   143,    95,   126,    -1,
      77,    35,    -1,    77,    41,    35,    -1,    -1,    76,    75,
      -1,     3,    -1,     4,    -1,     6,    -1,     7,    -1,     8,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    27,    -1,    33,    -1,    34,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    26,    35,    -1,   101,    -1,   141,    -1,    28,    76,
      11,    83,    31,    42,    11,    -1,    94,    28,    76,    11,
      83,    31,    42,    11,    -1,    94,    -1,    80,    -1,    81,
      80,    -1,   102,    -1,    84,    -1,    -1,    83,    82,    -1,
      30,    43,    76,    11,    35,    31,    43,    11,    -1,    30,
      43,    76,    11,    31,    43,    11,    -1,    30,    44,    76,
      12,    -1,    30,    44,    76,    11,    31,    44,    11,    -1,
      30,    44,    76,    11,   141,    31,    44,    11,    -1,    30,
      44,    76,    11,    80,    31,    44,    11,    -1,    30,    44,
      76,    11,    80,   141,    31,    44,    11,    -1,    30,    44,
      76,    12,    -1,    30,    44,    76,    11,   141,    31,    44,
      11,    -1,    30,    44,    76,    11,    80,    31,    44,    11,
      -1,    30,    44,    76,    11,    80,   141,    31,    44,    11,
      -1,    30,    45,    76,    12,    -1,    30,    45,    76,    11,
      90,    31,    45,    11,    -1,    30,    45,    76,    11,    80,
      31,    45,    11,    -1,    30,    45,    76,    11,    80,    90,
      31,    45,    11,    -1,    30,    45,    76,    12,    -1,    30,
      45,    76,    11,    90,    31,    45,    11,    -1,    30,    45,
      76,    11,    80,    31,    45,    11,    -1,    30,    45,    76,
      11,    80,    90,    31,    45,    11,    -1,    85,    -1,    87,
      -1,    89,    -1,    90,    89,    -1,    93,    -1,   103,    -1,
     133,    -1,    91,    -1,    92,    91,    -1,    30,    46,    76,
      11,    92,    31,    46,    11,    -1,    30,    46,    76,    11,
      80,    92,    31,    46,    11,    -1,    29,    10,    -1,    94,
      -1,    95,    94,    -1,    30,    47,    76,    11,    97,    31,
      47,    11,    -1,    30,    47,    76,    11,    80,    97,    31,
      47,    11,    -1,    99,    -1,    98,    -1,    30,    52,    76,
      12,    -1,    30,    52,    76,    11,    31,    52,    11,    -1,
      30,    52,    76,    11,    80,    31,    52,    11,    -1,    30,
      52,    76,    11,    80,   122,    31,    52,    11,    -1,    30,
      52,    76,    11,    80,    90,    31,    52,    11,    -1,    30,
      52,    76,    11,    80,   122,    90,    31,    52,    11,    -1,
      30,    52,    76,    11,   122,    31,    52,    11,    -1,    30,
      52,    76,    11,   122,    90,    31,    52,    11,    -1,    30,
      52,    76,    11,    90,    31,    52,    11,    -1,    30,    65,
      76,    12,    -1,    30,    65,    76,    11,    80,    31,    65,
      11,    -1,    30,    65,    76,    11,    80,   122,    31,    65,
      11,    -1,    30,    65,    76,    11,    80,    90,    31,    65,
      11,    -1,    30,    65,    76,    11,    80,   122,    90,    31,
      65,    11,    -1,    30,    65,    76,    11,   122,    31,    65,
      11,    -1,    30,    65,    76,    11,   122,    90,    31,    65,
      11,    -1,    30,    65,    76,    11,    90,    31,    65,    11,
      -1,    96,    -1,   121,    -1,   134,    -1,    30,    48,    76,
      12,    -1,    30,    48,    76,    11,    31,    48,    11,    -1,
      30,    48,    76,    11,   100,    31,    48,    11,    -1,    30,
      48,    76,    11,    80,    31,    48,    11,    -1,    30,    48,
      76,    11,    80,   100,    31,    48,    11,    -1,    30,    49,
      76,    11,    35,    31,    49,    11,    -1,    30,    49,    76,
      11,    31,    49,    11,    -1,    30,    50,    76,    11,    80,
      31,    50,    11,    -1,    30,    50,    76,    11,    79,    31,
      50,    11,    -1,    30,    50,    76,    11,    80,    79,    31,
      50,    11,    -1,    30,    50,    76,    11,   109,    31,    50,
      11,    -1,    30,    50,    76,    11,    80,   109,    31,    50,
      11,    -1,    30,    50,    76,    11,    79,   109,    31,    50,
      11,    -1,    30,    50,    76,    11,    80,    79,   109,    31,
      50,    11,    -1,    30,    50,    76,    11,    31,    50,    11,
      -1,    30,    50,    76,    12,    -1,    30,    50,    76,    11,
      80,    31,    50,    11,    -1,    30,    50,    76,    11,    79,
      31,    50,    11,    -1,    30,    50,    76,    11,    80,    79,
      31,    50,    11,    -1,    30,    50,    76,    11,    80,   109,
      31,    50,    11,    -1,    30,    50,    76,    11,    79,   109,
      31,    50,    11,    -1,    30,    50,    76,    11,    80,    79,
     109,    31,    50,    11,    -1,    30,    50,    76,    11,   109,
      31,    50,    11,    -1,    30,    50,    76,    12,    -1,    30,
      51,    76,    12,    -1,    30,    51,    76,    11,    80,    31,
      51,    11,    -1,    30,    53,    76,    12,    -1,    30,    53,
      76,    11,    31,    53,    11,    -1,   106,    -1,   107,   106,
      -1,   111,    -1,   112,    -1,   142,    -1,   108,    -1,   109,
     108,    -1,    30,    54,    78,    12,    -1,    30,    55,    76,
      11,   132,   107,    31,    55,    11,    -1,    95,    30,    55,
      76,    11,   132,   107,    31,    55,    11,    -1,    30,    55,
      76,    11,    80,   132,   107,    31,    55,    11,    -1,    95,
      30,    55,    76,    11,    80,   132,   107,    31,    55,    11,
      -1,    30,    56,    76,    11,   132,   107,    31,    56,    11,
      -1,    95,    30,    56,    76,    11,   132,   107,    31,    56,
      11,    -1,    30,    56,    76,    11,    80,   132,   107,    31,
      56,    11,    -1,    95,    30,    56,    76,    11,    80,   132,
     107,    31,    56,    11,    -1,    30,    58,    76,    12,    -1,
      30,    58,    76,    11,    80,    31,    58,    11,    -1,    30,
      59,    76,    12,    -1,    30,    59,    76,    11,    80,    31,
      59,    11,    -1,    30,    60,    76,    12,    -1,    30,    60,
      76,    11,    80,    31,    60,    11,    -1,    30,    61,    76,
      12,    -1,    30,    61,    76,    11,    80,    31,    61,    11,
      -1,    30,    62,    76,    12,    -1,    30,    62,    76,    11,
      80,    31,    62,    11,    -1,    30,    63,    76,    12,    -1,
      30,    63,    76,    11,    80,    31,    63,    11,    -1,    41,
      35,    -1,   119,    -1,   120,   119,    -1,   122,    -1,    90,
      -1,   122,    90,    -1,    93,    -1,   133,    -1,    30,    64,
      76,    12,    -1,    30,    64,    76,    11,    80,    31,    64,
      11,    -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,
     117,    -1,   118,    -1,   123,    -1,   105,    -1,   124,    -1,
     125,   124,    -1,   131,   128,   130,    31,    66,    11,    -1,
     110,    -1,    80,    -1,    -1,   128,   127,    -1,   104,    -1,
     104,    81,    -1,   101,    -1,   101,    81,    -1,   141,    -1,
     141,    81,    -1,    86,    -1,    86,    81,    -1,    88,    -1,
      88,    81,    -1,   129,    -1,   130,   129,    -1,    30,    66,
     120,    76,    11,    -1,    30,    67,    76,    12,    -1,    30,
      67,    76,    11,    31,    67,    11,    -1,    30,    68,    76,
      11,    92,    31,    68,    11,    -1,    30,    68,    76,    11,
      80,    92,    31,    68,    11,    -1,    30,    69,    76,    12,
      -1,    30,    69,    76,    11,    31,    69,    11,    -1,    30,
      69,    76,    11,    80,    31,    69,    11,    -1,    30,    69,
      76,    11,   135,    31,    69,    11,    -1,    30,    69,    76,
      11,    80,   135,    31,    69,    11,    -1,   136,    -1,   137,
      -1,    30,    52,    76,    12,    -1,    30,    52,    76,    11,
      31,    52,    11,    -1,    30,    52,    76,    11,    80,    31,
      52,    11,    -1,    30,    52,    76,    11,    90,    31,    52,
      11,    -1,    30,    52,    76,    11,    80,    90,    31,    52,
      11,    -1,    30,    65,    76,    12,    -1,    30,    65,    76,
      11,    31,    65,    11,    -1,    30,    65,    76,    11,    80,
      31,    65,    11,    -1,    30,    65,    76,    11,   125,    31,
      65,    11,    -1,    30,    65,    76,    11,    90,    31,    65,
      11,    -1,    30,    65,    76,    11,    80,   125,    31,    65,
      11,    -1,    30,    65,    76,    11,    80,    90,    31,    65,
      11,    -1,    30,    65,    76,    11,   125,    90,    31,    65,
      11,    -1,    30,    65,    76,    11,    80,   125,    90,    31,
      65,    11,    -1,   139,    -1,   140,    -1,    30,    57,    76,
      12,    -1,    30,    57,    76,    11,    31,    57,    11,    -1,
      30,    65,    76,    12,    -1,    30,    65,    76,    11,    31,
      65,    11,    -1,    30,    65,    76,    11,   125,    31,    65,
      11,    -1,    30,    70,    76,    11,   138,    31,    70,    11,
      -1,    30,    70,    76,    11,    80,   138,    31,    70,    11,
      -1,    30,    71,    76,    11,   132,   107,    31,    71,    11,
      -1,    95,    30,    71,    76,    11,   132,   107,    31,    71,
      11,    -1,    30,    71,    76,    11,    80,   132,   107,    31,
      71,    11,    -1,    95,    30,    71,    76,    11,    80,   132,
     107,    31,    71,    11,    -1,    32,    72,    35,    13,    -1,
      32,    72,    35,     9,    35,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  2597,  2597,  2601,  2608,  2610,  2616,  2617,  2634,  2635,
    2636,  2637,  2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,
    2646,  2647,  2648,  2649,  2650,  2651,  2652,  2653,  2654,  2655,
    2656,  2657,  2658,  2662,  2667,  2668,  2672,  2680,  2689,  2697,
    2701,  2708,  2709,  2714,  2715,  2722,  2729,  2738,  2742,  2747,
    2754,  2761,  2772,  2776,  2783,  2790,  2801,  2806,  2813,  2820,
    2831,  2836,  2843,  2850,  2861,  2862,  2866,  2870,  2877,  2878,
    2879,  2883,  2887,  2894,  2901,  2912,  2917,  2921,  2928,  2935,
    2946,  2947,  2951,  2955,  2960,  2967,  2975,  2983,  2992,  2999,
    3007,  3017,  3021,  3028,  3036,  3044,  3053,  3060,  3068,  3078,
    3079,  3080,  3084,  3089,  3095,  3102,  3110,  3121,  3128,  3137,
    3144,  3153,  3163,  3170,  3178,  3188,  3199,  3204,  3211,  3218,
    3225,  3233,  3241,  3249,  3258,  3265,  3272,  3276,  3286,  3290,
    3298,  3302,  3309,  3311,  3313,  3318,  3322,  3329,  3334,  3341,
    3350,  3358,  3371,  3378,  3387,  3395,  3408,  3412,  3422,  3426,
    3436,  3440,  3450,  3454,  3465,  3469,  3479,  3483,  3493,  3498,
    3502,  3509,  3511,  3513,  3518,  3519,  3523,  3527,  3537,  3538,
    3539,  3540,  3541,  3542,  3543,  3544,  3548,  3552,  3559,  3565,
    3566,  3571,  3574,  3581,  3582,  3586,  3587,  3591,  3592,  3596,
    3597,  3601,  3602,  3609,  3613,  3620,  3632,  3636,  3644,  3651,
    3662,  3666,  3671,  3678,  3685,  3696,  3697,  3701,  3705,  3710,
    3717,  3724,  3735,  3740,  3746,  3754,  3761,  3769,  3777,  3785,
    3793,  3805,  3806,  3810,  3814,  3822,  3827,  3833,  3843,  3850,
    3861,  3868,  3877,  3885,  3898,  3903
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
  "XSFIELD", "XSINCLUDE", "XSKEY", "XSKEYREF", "XSLIST", "XSMAXEXCLUSIVE",
  "XSMAXINCLUSIVE", "XSMAXLENGTH", "XSMINEXCLUSIVE", "XSMININCLUSIVE",
  "XSMINLENGTH", "XSPATTERN", "XSRESTRICTION", "XSSCHEMA", "XSSELECTOR",
  "XSSEQUENCE", "XSSIMPLECONTENT", "XSSIMPLETYPE", "XSUNIQUE",
  "XMLVERSION", "$accept", "xmlSchemaFile", "attributePair",
  "attributePairList", "attributeName", "schemaLocation", "typeDef",
  "xmlAnnotation", "xmlAnnotationList", "xmlAnnoType", "xmlAnnoTypeList",
  "xmlAppinfo", "xmlAttributeLoner", "xmlAttributeLonerRefable",
  "xmlAttributeGroup", "xmlAttributeGroupRefable", "xmlAttributor",
  "xmlAttributorList", "xmlChoSeqItem", "xmlChoSeqItemList", "xmlChoice",
  "xmlComment", "xmlCommentList", "xmlComplexContent",
  "xmlComplexContentItem", "xmlComplexExtension", "xmlComplexRestriction",
  "xmlComplexTypeItem", "xmlComplexType", "xmlDocumentation",
  "xmlElementLocal", "xmlElementRefable", "xmlEnumeration", "xmlField",
  "xmlFieldList", "xmlIdConstraint", "xmlIdConstraintList", "xmlInclude",
  "xmlKey", "xmlKeyref", "xmlMaxExclusive", "xmlMaxInclusive",
  "xmlMaxLength", "xmlMinExclusive", "xmlMinInclusive", "xmlMinLength",
  "xmlNs", "xmlNsList", "xmlOtherContent", "xmlOtherContentBase",
  "xmlPattern", "xmlRestrictionType", "xmlRestrictionTypeList",
  "xmlSchema", "xmlSchemaContent1", "xmlSchemaContent1List",
  "xmlSchemaContent2", "xmlSchemaContent2List", "xmlSchemaHeader",
  "xmlSelector", "xmlSequence", "xmlSimpleContent", "xmlSimpleContentItem",
  "xmlSimpleContentExtension", "xmlSimpleContentRestriction",
  "xmlSimpleItem", "xmlSimpleList", "xmlSimpleRestriction",
  "xmlSimpleType", "xmlUnique", "xmlVersion", 0
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
     325,   326,   327
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   101,   101,   101,   101,   101,   102,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   109,   109,   110,   111,   111,
     111,   111,   112,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   120,
     120,   121,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   126,   127,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   130,   130,   131,   132,   132,   133,   133,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   140,   141,   141,
     142,   142,   142,   142,   143,   143
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
       1,     1,     2,     8,     9,     2,     1,     2,     8,     9,
       1,     1,     4,     7,     8,     9,     9,    10,     8,     9,
       8,     4,     8,     9,     9,    10,     8,     9,     8,     1,
       1,     1,     4,     7,     8,     8,     9,     8,     7,     8,
       8,     9,     8,     9,     9,    10,     7,     4,     8,     8,
       9,     9,     9,    10,     8,     4,     4,     8,     4,     7,
       1,     2,     1,     1,     1,     1,     2,     4,     9,    10,
      10,    11,     9,    10,    10,    11,     4,     8,     4,     8,
       4,     8,     4,     8,     4,     8,     4,     8,     2,     1,
       2,     1,     1,     2,     1,     1,     4,     8,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     6,     1,
       1,     0,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     5,     4,     7,     8,     9,
       4,     7,     8,     8,     9,     1,     1,     4,     7,     8,
       8,     9,     4,     7,     8,     8,     8,     9,     9,     9,
      10,     1,     1,     4,     7,     4,     7,     8,     8,     9,
       9,    10,    10,    11,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,    76,     0,
       2,   181,     0,    75,     0,    77,     3,     0,     0,   234,
       0,   159,     6,     6,     0,   180,   189,   191,    38,   185,
     183,   179,   182,   193,     0,   187,     0,   158,     0,   160,
       0,     6,     6,     6,     6,     0,     6,    39,   190,   192,
       6,   186,   184,     0,     0,   194,   188,   235,     8,     9,
      10,    11,    12,   195,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     7,     0,    43,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     4,     0,     0,
       0,    52,     0,    60,     0,   102,     0,   125,    33,   137,
       0,    43,   178,     5,     0,     0,    44,    42,    41,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,     0,
       0,   162,   164,    99,     0,   100,   161,   165,   101,     0,
       0,     0,    38,     0,    34,   135,     0,   132,   133,    35,
     134,     0,     0,     0,   221,   222,     0,     6,     6,     0,
       0,     0,     0,     6,     6,     0,     0,     0,    67,     6,
       6,     6,     6,     0,     0,     0,     0,   163,     6,     6,
       6,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       6,     6,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     6,     6,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,    53,     0,    47,     0,
      56,    62,     0,    61,     0,     0,     0,     0,   200,   105,
       0,   104,     0,     0,     0,   119,     0,   118,     0,     0,
       0,     0,     0,     0,   124,     0,   223,     0,   225,     0,
     228,    37,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,    63,     0,     0,    71,     0,    68,    69,    70,
       0,     0,     0,    81,    80,     0,     0,     0,     0,     0,
       0,   205,   206,   106,     0,     0,     0,     0,     0,     0,
       0,   122,   120,     0,   121,     0,     0,     0,     0,     0,
       0,   175,   168,   169,   170,   171,   172,   173,   174,   176,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,    72,     6,     6,     0,
       0,     0,     0,     6,     6,     0,     0,     0,     0,     6,
       0,     0,   130,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     6,     6,     6,     6,
       6,     6,     6,     6,     0,     0,   177,    46,     0,   108,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     6,     0,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,   226,     0,    45,
     107,    50,     0,    49,    58,     0,    57,     0,   117,     0,
      73,     0,    82,     0,    91,     0,    78,     0,   198,     0,
     207,     0,   212,   202,     0,   203,     0,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   146,     0,   148,     0,   150,     0,
     152,     0,   154,     0,   156,     0,   166,   227,    51,    59,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,    79,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   204,     0,     0,     0,   128,   138,     0,
     142,     0,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,   144,   232,     0,   139,     0,   143,     0,   231,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,     0,   197,     0,   141,   145,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,   109,     0,     0,
       0,   112,    84,     0,     0,     0,    90,    88,     0,    92,
       0,     0,     0,    98,    96,     0,   209,     0,   210,   214,
       0,     0,     0,   216,   215,     0,   129,   127,   147,   149,
     151,   153,   155,   157,   167,   114,   111,     0,   113,    86,
      85,     0,    89,    94,    93,     0,    97,   211,   218,   217,
       0,   219,   115,    87,    95,   220
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,    38,    85,    92,   140,    47,    48,   116,
      99,   117,   124,    26,   125,    27,   126,   131,   285,   286,
     287,    28,   143,   133,   292,   293,   294,   134,   144,   118,
     288,    30,   321,   362,   363,   145,   146,    31,   147,   148,
     322,   323,   324,   325,   326,   327,    21,    22,   135,   136,
     328,   329,   330,    10,    32,    17,    33,    34,    11,   306,
     289,   138,   300,   301,   302,   153,   154,   155,   149,   150,
       3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -448
static const yytype_int16 yypact[] =
{
     -19,   -54,    25,    99,    -8,  -448,    22,   -20,  -448,    99,
    -448,  -448,    30,  -448,     7,  -448,  -448,   124,    27,  -448,
      32,  -448,     7,  -448,    11,  -448,   107,   107,    29,   107,
     107,  -448,  -448,  -448,   111,   107,    47,  -448,  1517,  -448,
    1555,  -448,  -448,  -448,  -448,    62,  -448,  -448,   107,   107,
    -448,   107,   107,    69,    35,  -448,   107,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,    39,  -448,   274,   517,   605,
     643,    71,    96,  1593,  -448,  1631,   112,  -448,    83,   137,
     216,  -448,   219,  -448,   147,  -448,   222,  -448,  -448,  -448,
     232,  -448,  -448,  -448,    55,   102,  -448,  -448,  -448,   126,
     183,   127,   172,   223,  -448,  -448,  -448,   245,   119,   133,
     253,   130,  -448,  -448,   141,  -448,   130,  -448,  -448,   114,
     240,   273,    29,   276,  -448,  -448,   288,  -448,  -448,  -448,
    -448,     1,   159,   171,  -448,  -448,   317,  -448,  -448,   215,
     167,   225,   214,  -448,  -448,   218,   325,   234,  -448,  -448,
    -448,  -448,  -448,   289,   239,   284,   302,   130,  -448,  -448,
    -448,    56,   308,   291,   322,   294,   297,    60,   324,  -448,
    -448,  -448,   329,   296,   362,  1669,  1707,  -448,   395,   365,
     403,   681,   795,   406,   374,   410,  1745,  1783,  1821,   833,
    -448,   414,   379,   420,  1859,  1897,  1935,   422,   389,   439,
     402,   300,   409,  -448,  -448,  -448,   450,   871,   909,   387,
     455,   457,    52,    90,  -448,   459,  -448,   164,  -448,   219,
    -448,  -448,   467,  -448,   304,   310,   304,   170,  -448,  -448,
     471,  -448,   313,   313,   313,  -448,   493,  -448,   495,   447,
     497,  1973,  2011,  2049,  -448,   441,  -448,   332,  -448,   499,
    -448,  -448,   469,   483,   473,   512,  -448,   501,   338,   516,
     353,   359,  -448,   -30,   500,  -448,   372,  -448,  -448,  -448,
     -29,   522,   537,  -448,  -448,   500,   381,    -2,   520,   393,
     579,  -448,  -448,  -448,   551,   601,   610,   601,   610,   601,
     610,  -448,  -448,   637,  -448,   313,   313,   313,   599,   161,
     604,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
     407,  -448,   662,   635,   675,   645,   696,   667,   682,   668,
     671,   411,   677,  -448,   415,   678,  -448,  -448,  -448,   692,
     680,   418,   657,  -448,  -448,   715,   659,   698,   661,  -448,
     610,   683,  -448,   434,   610,   444,   610,   446,  -448,   601,
     610,   601,   610,   601,   610,   720,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,   721,   669,  -448,  -448,   722,  -448,
     724,  -448,   726,   694,   728,   729,   697,   730,   947,   699,
     732,   985,  1023,   700,   733,   684,   735,  1061,  1099,  -448,
     737,   685,   738,  1137,   454,  -448,   695,  -448,   456,   701,
     458,   687,   610,   461,   610,   463,   610,   465,  -448,  1175,
    1213,  1251,  1289,  1327,  1365,  1403,  1441,  -448,   740,  -448,
    -448,  -448,   742,  -448,  -448,   745,  -448,   200,  -448,   750,
    -448,   204,  -448,   316,  -448,   751,  -448,   752,  -448,   208,
    -448,   212,  -448,  -448,   753,  -448,   736,  -448,   713,  1479,
     758,   714,   761,   702,   763,   486,   723,   488,   719,   496,
     705,   107,  -448,   107,  -448,   107,  -448,   107,  -448,   107,
    -448,   107,  -448,   107,  -448,   107,  -448,  -448,  -448,  -448,
     727,   323,   347,   350,  -448,    88,   731,   528,   530,   532,
     534,   536,   541,  -448,  -448,   734,   543,   547,   146,   716,
     549,   555,   557,  -448,   712,   769,   754,  -448,  -448,   771,
    -448,   773,  -448,   741,   776,   744,   786,   755,   793,   774,
     777,   790,   792,   794,   799,   807,   811,   813,   796,   357,
     809,   363,   367,   812,   832,   816,   563,   565,   824,   828,
     567,   798,   570,   574,   800,   819,   576,   850,   829,   584,
     845,   853,   834,   603,   622,   835,   836,   641,   891,  -448,
     861,  -448,  -448,   892,  -448,   895,  -448,   907,  -448,   868,
     864,   876,   877,   878,   879,   875,   880,  -448,   929,   902,
     945,   910,   370,   923,   946,  -448,   964,   924,   925,   644,
     967,   968,   930,   979,   933,   948,   660,   983,   984,   949,
    -448,  1000,   963,  1005,  -448,  1006,   955,   971,   679,  1017,
    1021,   986,  -448,  1022,  -448,  -448,  -448,  1038,  1041,  1042,
    1043,  1044,  1047,  1055,  1059,  -448,  1060,  -448,  1063,  1037,
    1078,  -448,  -448,  1079,  1080,  1040,  -448,  -448,  1082,  -448,
    1085,  1093,  1062,  -448,  -448,  1097,  -448,  1098,  -448,  -448,
    1101,  1114,  1064,  -448,  -448,  1117,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  1119,  -448,  -448,
    -448,  1120,  -448,  -448,  -448,  1123,  -448,  -448,  -448,  -448,
    1131,  -448,  -448,  -448,  -448,  -448
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -448,  -448,  -448,   412,  -448,  -448,  -138,    20,   144,  -448,
    1035,  -448,  -448,  -448,  -448,  -448,  -126,   -94,  -274,  -231,
    -102,    -3,  1144,  -448,   859,  -448,  -448,  1033,     0,  -448,
    -448,  -448,  -448,  -318,  -275,  -142,  -131,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  1143,  -448,  -448,  -432,
    -448,  -319,  -447,  1157,  -448,  -448,  1133,  -448,  -448,  -223,
     -78,  -448,   869,  -448,  -448,  1020,  -448,  -448,   -10,  -448,
    -448
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       8,   168,   132,   185,   189,   168,    15,    35,   127,   183,
     186,   386,   346,     1,   522,   296,   169,    29,     4,   509,
     343,   512,   346,   347,    35,     5,   137,    12,   132,   166,
     308,   310,    13,   365,    29,   367,   348,    25,   171,    18,
     168,   189,   177,    19,   189,   417,    14,   417,    20,   417,
     353,   168,   137,   344,   221,    41,    42,    50,   190,    43,
      57,    44,    36,   354,   351,    45,   191,    37,    94,    94,
     346,    94,    94,   574,    97,   557,    94,   346,   563,   189,
      98,    46,   360,   272,   364,   414,   366,   273,    91,   418,
     121,   420,   370,   372,   374,   423,   417,   425,   157,   427,
     417,    96,   417,   142,   158,   417,   108,   417,   109,   417,
     161,   178,   179,    41,    42,   223,   224,    43,   113,    44,
     120,   274,   123,   112,   130,   275,   141,   180,     6,     7,
     152,   225,   163,   164,   169,    23,     6,     8,     8,    46,
      15,    53,    54,     8,   159,   281,   422,   475,   424,   477,
     426,   479,    23,     6,    24,   168,   171,   417,   162,   417,
     122,   417,    43,   163,   164,   169,   170,   114,   115,   178,
     179,    49,   176,    51,    52,    23,     6,   128,   129,    56,
       8,   173,     8,     8,    46,   180,   341,   171,   172,   151,
     163,   164,    23,     6,   119,   277,    46,   376,    23,     6,
     297,   298,   193,   386,   377,   378,   379,   380,   381,   382,
     383,   198,   376,   119,   160,   168,   163,   164,     8,   377,
     378,   379,   380,   381,   382,   383,   197,   279,    23,     6,
     139,   500,    23,     6,   505,   506,    23,     6,   122,   515,
      23,     6,   518,   519,    23,     6,   119,    23,     6,   122,
      23,     6,   139,   122,   165,   386,   199,   278,   200,   280,
      23,     6,   151,   203,   284,   291,   295,   299,   338,     6,
     181,   182,   305,   307,   309,   122,   167,    58,    59,   205,
      60,    61,    62,   128,   174,   100,   101,   211,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     210,    76,     6,   139,   184,     6,   187,    77,    78,   501,
      79,    80,    81,    82,    83,   212,   503,     6,   181,   188,
       6,   181,   218,     6,   181,   220,     6,   181,   222,     6,
     181,   259,    23,     6,   283,   369,   371,   373,    23,     6,
     290,    23,     6,   304,    23,     6,   505,   114,   194,   132,
     213,   132,     6,   181,   548,   122,   204,   508,   217,   511,
     229,   189,   319,   320,   551,   517,   230,   521,   119,   337,
     549,   552,   219,   137,   226,   137,     6,   139,   550,     6,
     181,   553,   168,   122,   340,   168,     6,   181,   599,   122,
     342,   168,     6,   181,   601,   168,     6,   181,   603,     6,
     181,   649,   283,   345,   231,   132,   234,   189,   132,   235,
     189,   283,   352,   556,   236,   560,   562,   241,   566,   242,
     602,   243,   569,   297,   356,   249,   573,   250,   577,   137,
     168,   251,   137,   255,   168,    40,   168,   319,   385,   256,
     168,   122,   396,   168,   142,   283,   399,   168,   283,   405,
     257,   168,   258,    87,    88,    89,    90,   269,    93,   260,
     189,   264,    95,   609,   361,   416,   270,   502,   271,   616,
     276,   507,   318,   510,   361,   419,   361,   421,   282,   516,
     628,   520,   303,   168,   361,   468,   361,   471,   361,   473,
     168,   361,   476,   361,   478,   361,   480,   313,     8,     8,
       8,   539,   168,   540,   311,   541,   312,   542,   314,   543,
     331,   544,   332,   545,   333,   546,   361,   533,   361,   535,
      58,    59,   334,    60,    61,    62,   361,   537,   102,   103,
     283,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   335,    76,   336,     8,   339,     8,     8,
      77,    78,   290,    79,    80,    81,    82,    83,   505,   555,
     122,   558,   122,   559,   505,   561,   122,   564,   350,   195,
     196,   122,   565,   122,   568,   201,   202,   122,   570,   518,
     572,   206,   207,   208,   209,   122,   575,   518,   576,   355,
     214,   215,   216,   122,   607,   122,   608,   122,   612,     8,
     122,   614,   227,   228,   122,   615,   122,   619,    58,    59,
     358,    60,    61,    62,   122,   622,   104,   105,   359,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   304,    76,   122,   626,   261,   262,   263,    77,    78,
     361,    79,    80,    81,    82,    83,    58,    59,   368,    60,
      61,    62,   518,   627,   106,   107,   375,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   384,
      76,   122,   631,   387,   122,   655,    77,    78,   388,    79,
      80,    81,    82,    83,    58,    59,   389,    60,    61,    62,
     122,   662,   237,   238,   390,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   391,    76,   122,
     672,   392,   394,   393,    77,    78,   395,    79,    80,    81,
      82,    83,   397,   403,   400,   406,   409,   404,   410,   411,
     412,   428,   437,   439,   438,   440,   415,   441,   442,   443,
     444,   446,   445,   450,   456,   449,   458,   455,   463,   465,
     470,   497,   457,   498,   464,   398,   499,   472,   474,   401,
     402,   504,   513,   514,   523,   407,   408,   524,   525,   528,
     529,   413,   530,   531,   532,   536,   538,   547,   534,   578,
     579,   571,   581,   554,   582,   580,   567,   584,   429,   430,
     431,   432,   433,   434,   435,   436,   583,   586,    58,    59,
     585,    60,    61,    62,   588,   589,   239,   240,   590,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   591,    76,   592,   597,   593,   587,   469,    77,    78,
     594,    79,    80,    81,    82,    83,    58,    59,   595,    60,
      61,    62,   596,   605,   247,   248,   598,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   600,
      76,   620,   604,   613,   624,   617,    77,    78,   606,    79,
      80,    81,    82,    83,    58,    59,   610,    60,    61,    62,
     611,   621,   265,   266,   618,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   623,    76,   625,
     629,   630,   632,   634,    77,    78,   635,    79,    80,    81,
      82,    83,    58,    59,   633,    60,    61,    62,   636,   637,
     267,   268,   638,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   639,    76,   640,   643,   641,
     645,   642,    77,    78,   644,    79,    80,    81,    82,    83,
      58,    59,   646,    60,    61,    62,   647,   651,   447,   448,
     648,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   650,    76,   652,   653,   654,   656,   657,
      77,    78,   658,    79,    80,    81,    82,    83,    58,    59,
     659,    60,    61,    62,   663,   664,   451,   452,   660,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   666,    76,   661,   665,   667,   668,   669,    77,    78,
     670,    79,    80,    81,    82,    83,    58,    59,   673,    60,
      61,    62,   674,   676,   453,   454,   671,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   677,
      76,   675,   678,   679,   680,   681,    77,    78,   682,    79,
      80,    81,    82,    83,    58,    59,   683,    60,    61,    62,
     684,   685,   459,   460,   686,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   687,    76,   688,
     689,   690,   691,   692,    77,    78,   693,    79,    80,    81,
      82,    83,    58,    59,   694,    60,    61,    62,   696,   697,
     461,   462,   698,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   699,    76,   695,   701,   700,
     702,   703,    77,    78,   704,    79,    80,    81,    82,    83,
      58,    59,   705,    60,    61,    62,   156,     9,   466,   467,
     349,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   175,    76,    39,    16,    55,   357,     0,
      77,    78,   192,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   481,   482,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   483,   484,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   485,   486,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     487,   488,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,   489,   490,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   491,   492,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   493,   494,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   495,   496,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     526,   527,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,    63,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,    86,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   110,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   111,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     232,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,   233,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   244,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   245,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   246,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     252,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,   253,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   254,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   315,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   316,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     317,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       3,   127,   104,   141,   146,   131,     9,    17,   102,   140,
     141,   330,   286,    32,   461,   246,    46,    17,    72,   451,
      50,   453,   296,    52,    34,     0,   104,    35,   130,   123,
     253,   254,    10,   308,    34,   310,    65,    17,    68,     9,
     166,   183,   136,    13,   186,   363,    66,   365,    41,   367,
      52,   177,   130,   284,   185,    44,    45,    28,    57,    48,
      13,    50,    35,    65,   295,    54,    65,    35,    48,    49,
     344,    51,    52,   520,    35,   507,    56,   351,   510,   221,
      41,    70,   305,    31,   307,   360,   309,    35,    26,   364,
     100,   366,   315,   316,   317,   370,   414,   372,    43,   374,
     418,    66,   420,   106,    49,   423,    35,   425,    12,   427,
     120,    55,    56,    44,    45,    55,    56,    48,    35,    50,
     100,    31,   102,    11,   104,    35,   106,    71,    29,    30,
     110,    71,    44,    45,    46,    28,    29,   140,   141,    70,
     143,    30,    31,   146,    42,   239,   369,   422,   371,   424,
     373,   426,    28,    29,    30,   281,    68,   475,    31,   477,
      30,   479,    48,    44,    45,    46,    47,    30,    31,    55,
      56,    27,    31,    29,    30,    28,    29,    30,    31,    35,
     183,    48,   185,   186,    70,    71,   280,    68,    69,    30,
      44,    45,    28,    29,    30,    31,    70,    51,    28,    29,
      30,    31,    31,   522,    58,    59,    60,    61,    62,    63,
      64,    44,    51,    30,    31,   341,    44,    45,   221,    58,
      59,    60,    61,    62,    63,    64,    11,   237,    28,    29,
      30,    31,    28,    29,    30,    31,    28,    29,    30,    31,
      28,    29,    30,    31,    28,    29,    30,    28,    29,    30,
      28,    29,    30,    30,    31,   574,    31,   237,    44,   239,
      28,    29,    30,    45,   244,   245,   246,   247,   278,    29,
      30,    31,   252,   253,   254,    30,    31,     3,     4,    45,
       6,     7,     8,    30,    31,    11,    12,    48,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      11,    27,    29,    30,    31,    29,    30,    33,    34,   447,
      36,    37,    38,    39,    40,    31,   447,    29,    30,    31,
      29,    30,    31,    29,    30,    31,    29,    30,    31,    29,
      30,    31,    28,    29,    30,   315,   316,   317,    28,    29,
      30,    28,    29,    30,    28,    29,    30,    30,    31,   451,
      48,   453,    29,    30,    31,    30,    31,   451,    50,   453,
      31,   503,    30,    31,   502,   459,    70,   461,    30,    31,
     501,   502,    50,   451,    50,   453,    29,    30,    31,    29,
      30,    31,   508,    30,    31,   511,    29,    30,    31,    30,
      31,   517,    29,    30,    31,   521,    29,    30,    31,    29,
      30,    31,    30,    31,    42,   507,    11,   549,   510,    44,
     552,    30,    31,   507,    11,   509,   510,    11,   512,    45,
     551,    11,   516,    30,    31,    11,   520,    48,   522,   507,
     556,    11,   510,    11,   560,    23,   562,    30,    31,    50,
     566,    30,    31,   569,   447,    30,    31,   573,    30,    31,
      11,   577,    50,    41,    42,    43,    44,    70,    46,    50,
     602,    11,    50,   557,    30,    31,    11,   447,    11,   563,
      11,   451,    31,   453,    30,    31,    30,    31,    11,   459,
     574,   461,    11,   609,    30,    31,    30,    31,    30,    31,
     616,    30,    31,    30,    31,    30,    31,    50,   501,   502,
     503,   481,   628,   483,    11,   485,    11,   487,    11,   489,
      11,   491,    43,   493,    31,   495,    30,    31,    30,    31,
       3,     4,    49,     6,     7,     8,    30,    31,    11,    12,
      30,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    31,    27,    44,   549,    31,   551,   552,
      33,    34,    30,    36,    37,    38,    39,    40,    30,    31,
      30,    31,    30,    31,    30,    31,    30,    31,    31,   157,
     158,    30,    31,    30,    31,   163,   164,    30,    31,    30,
      31,   169,   170,   171,   172,    30,    31,    30,    31,    69,
     178,   179,   180,    30,    31,    30,    31,    30,    31,   602,
      30,    31,   190,   191,    30,    31,    30,    31,     3,     4,
      31,     6,     7,     8,    30,    31,    11,    12,    67,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    30,    27,    30,    31,   223,   224,   225,    33,    34,
      30,    36,    37,    38,    39,    40,     3,     4,    11,     6,
       7,     8,    30,    31,    11,    12,    57,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    65,
      27,    30,    31,    11,    30,    31,    33,    34,    43,    36,
      37,    38,    39,    40,     3,     4,    11,     6,     7,     8,
      30,    31,    11,    12,    49,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    27,    30,
      31,    44,    44,    31,    33,    34,    45,    36,    37,    38,
      39,    40,    45,    31,    46,    68,    11,    47,    69,    31,
      69,    11,    11,    11,    65,    11,    53,    11,    44,    11,
      11,    11,    45,    11,    11,    46,    11,    47,    11,    11,
      55,    11,    68,    11,    69,   343,    11,    56,    71,   347,
     348,    11,    11,    11,    11,   353,   354,    31,    55,    11,
      56,   359,    11,    71,    11,    56,    71,    50,    55,    67,
      11,    65,    11,    52,    11,    31,    52,    11,   376,   377,
     378,   379,   380,   381,   382,   383,    55,    11,     3,     4,
      56,     6,     7,     8,    11,    31,    11,    12,    31,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    31,    27,    31,    11,    31,    71,   415,    33,    34,
      31,    36,    37,    38,    39,    40,     3,     4,    31,     6,
       7,     8,    31,    11,    11,    12,    50,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    50,
      27,    11,    50,    65,    11,    65,    33,    34,    52,    36,
      37,    38,    39,    40,     3,     4,    52,     6,     7,     8,
      52,    52,    11,    12,    65,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    52,    27,    65,
      65,    65,    11,    11,    33,    34,    11,    36,    37,    38,
      39,    40,     3,     4,    53,     6,     7,     8,    11,    51,
      11,    12,    58,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    59,    27,    60,    63,    61,
      11,    62,    33,    34,    64,    36,    37,    38,    39,    40,
       3,     4,    50,     6,     7,     8,    11,    11,    11,    12,
      50,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    50,    27,    11,    52,    52,    11,    11,
      33,    34,    52,    36,    37,    38,    39,    40,     3,     4,
      11,     6,     7,     8,    11,    11,    11,    12,    65,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    27,    65,    65,    52,    11,    11,    33,    34,
      65,    36,    37,    38,    39,    40,     3,     4,    11,     6,
       7,     8,    11,    11,    11,    12,    65,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    11,
      27,    65,    11,    11,    11,    11,    33,    34,    11,    36,
      37,    38,    39,    40,     3,     4,    11,     6,     7,     8,
      11,    11,    11,    12,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    50,    27,    11,
      11,    11,    52,    11,    33,    34,    11,    36,    37,    38,
      39,    40,     3,     4,    11,     6,     7,     8,    11,    11,
      11,    12,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    11,    27,    65,    11,    65,
      11,    11,    33,    34,    11,    36,    37,    38,    39,    40,
       3,     4,    11,     6,     7,     8,   111,     3,    11,    12,
     291,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   130,    27,    22,     9,    34,   299,    -1,
      33,    34,   152,    36,    37,    38,    39,    40,     3,     4,
      -1,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
       3,     4,    -1,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,     3,     4,
      -1,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,     3,     4,    -1,     6,     7,     8,    -1,    -1,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
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
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    74,   143,    72,     0,    29,    30,    94,    95,
     126,   131,    35,    10,    66,    94,   126,   128,     9,    13,
      41,   119,   120,    28,    30,    80,    86,    88,    94,   101,
     104,   110,   127,   129,   130,   141,    35,    35,    76,   119,
      76,    44,    45,    48,    50,    54,    70,    80,    81,    81,
      28,    81,    81,    30,    31,   129,    81,    13,     3,     4,
       6,     7,     8,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    27,    33,    34,    36,
      37,    38,    39,    40,    75,    77,    11,    76,    76,    76,
      76,    26,    78,    76,    80,    76,    66,    35,    41,    83,
      11,    12,    11,    12,    11,    12,    11,    12,    35,    12,
      11,    11,    11,    35,    30,    31,    82,    84,   102,    30,
      80,   141,    30,    80,    85,    87,    89,    90,    30,    31,
      80,    90,    93,    96,   100,   121,   122,   133,   134,    30,
      79,    80,    94,    95,   101,   108,   109,   111,   112,   141,
     142,    30,    80,   138,   139,   140,    83,    43,    49,    42,
      31,   141,    31,    44,    45,    31,    90,    31,    89,    46,
      47,    68,    69,    48,    31,   100,    31,    90,    55,    56,
      71,    30,    31,   109,    31,    79,   109,    30,    31,   108,
      57,    65,   138,    31,    31,    76,    76,    11,    44,    31,
      44,    76,    76,    45,    31,    45,    76,    76,    76,    76,
      11,    48,    31,    48,    76,    76,    76,    50,    31,    50,
      31,   109,    31,    55,    56,    71,    50,    76,    76,    31,
      70,    42,    11,    11,    11,    44,    11,    11,    12,    11,
      12,    11,    45,    11,    11,    11,    11,    11,    12,    11,
      48,    11,    11,    11,    11,    11,    50,    11,    50,    31,
      50,    76,    76,    76,    11,    11,    12,    11,    12,    70,
      11,    11,    31,    35,    31,    35,    11,    31,    80,   141,
      80,    90,    11,    30,    80,    91,    92,    93,   103,   133,
      30,    80,    97,    98,    99,    80,    92,    30,    31,    80,
     135,   136,   137,    11,    30,    80,   132,    80,   132,    80,
     132,    11,    11,    50,    11,    11,    11,    11,    31,    30,
      31,   105,   113,   114,   115,   116,   117,   118,   123,   124,
     125,    11,    43,    31,    49,    31,    44,    31,   141,    31,
      31,    90,    31,    50,    92,    31,    91,    52,    65,    97,
      31,    92,    31,    52,    65,    69,    31,   135,    31,    67,
     132,    30,   106,   107,   132,   107,   132,   107,    11,    80,
     132,    80,   132,    80,   132,    57,    51,    58,    59,    60,
      61,    62,    63,    64,    65,    31,   124,    11,    43,    11,
      49,    11,    44,    31,    44,    45,    31,    45,    76,    31,
      46,    76,    76,    31,    47,    31,    68,    76,    76,    11,
      69,    31,    69,    76,   107,    53,    31,   106,   107,    31,
     107,    31,   132,   107,   132,   107,   132,   107,    11,    76,
      76,    76,    76,    76,    76,    76,    76,    11,    65,    11,
      11,    11,    44,    11,    11,    45,    11,    11,    12,    46,
      11,    11,    12,    11,    12,    47,    11,    68,    11,    11,
      12,    11,    12,    11,    69,    11,    11,    12,    31,    76,
      55,    31,    56,    31,    71,   107,    31,   107,    31,   107,
      31,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    11,    11,
      31,    79,    80,   109,    11,    30,    31,    80,    90,   122,
      80,    90,   122,    11,    11,    31,    80,    90,    30,    31,
      80,    90,   125,    11,    31,    55,    11,    12,    11,    56,
      11,    71,    11,    31,    55,    31,    56,    31,    71,    80,
      80,    80,    80,    80,    80,    80,    80,    50,    31,   109,
      31,    79,   109,    31,    52,    31,    90,   122,    31,    31,
      90,    31,    90,   122,    31,    31,    90,    52,    31,    90,
      31,    65,    31,    90,   125,    31,    31,    90,    67,    11,
      31,    11,    11,    55,    11,    56,    11,    71,    11,    31,
      31,    31,    31,    31,    31,    31,    31,    11,    50,    31,
      50,    31,   109,    31,    50,    11,    52,    31,    31,    90,
      52,    52,    31,    65,    31,    31,    90,    65,    65,    31,
      11,    52,    31,    52,    11,    65,    31,    31,    90,    65,
      65,    31,    11,    53,    11,    11,    11,    51,    58,    59,
      60,    61,    62,    63,    64,    11,    50,    11,    50,    31,
      50,    11,    11,    52,    52,    31,    11,    11,    52,    11,
      65,    65,    31,    11,    11,    65,    11,    52,    11,    11,
      65,    65,    31,    11,    11,    65,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    50,    11,    11,
      11,    52,    11,    11,    11,    65,    11,    11,    11,    11,
      65,    11,    11,    11,    11,    11
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

    {(yyval.choSeqItemVal) = (yyvsp[(1) - (1)].elementLocalVal);;}
    break;

  case 70:

    {(yyval.choSeqItemVal) = (yyvsp[(1) - (1)].sequenceVal);;}
    break;

  case 71:

    {(yyval.choSeqItemListVal) = new std::list<XmlChoSeqItem *>;
	   (yyval.choSeqItemListVal)->push_back((yyvsp[(1) - (1)].choSeqItemVal));
	  ;}
    break;

  case 72:

    {(yyval.choSeqItemListVal) = (yyvsp[(1) - (2)].choSeqItemListVal);
	   (yyvsp[(1) - (2)].choSeqItemListVal)->push_back((yyvsp[(2) - (2)].choSeqItemVal));
	  ;}
    break;

  case 73:

    {(yyval.choiceVal) = new XmlChoice(); // might add check that list is not empty
	   doXmlChoiceAttributes((yyval.choiceVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.choiceVal)->items = (yyvsp[(5) - (8)].choSeqItemListVal);
	  ;}
    break;

  case 74:

    {(yyval.choiceVal) = new XmlChoice(); // might add check that list is not empty
	   doXmlChoiceAttributes((yyval.choiceVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.choiceVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.choiceVal)->items = (yyvsp[(6) - (9)].choSeqItemListVal);
	  ;}
    break;

  case 75:

    {(yyval.commentVal) = new std::string(commentString);;}
    break;

  case 76:

    {(yyval.commentListVal) = new std::list<std::string *>;
	   (yyval.commentListVal)->push_back((yyvsp[(1) - (1)].commentVal));
	  ;}
    break;

  case 77:

    {(yyval.commentListVal) = (yyvsp[(1) - (2)].commentListVal);
	   (yyvsp[(1) - (2)].commentListVal)->push_back((yyvsp[(2) - (2)].commentVal));
	  ;}
    break;

  case 78:

    {(yyval.complexContentVal) = new XmlComplexContent();
	   doXmlComplexContentAttributes((yyval.complexContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexContentVal)->item = (yyvsp[(5) - (8)].complexContentItemVal);
	  ;}
    break;

  case 79:

    {(yyval.complexContentVal) = new XmlComplexContent();
	   doXmlComplexContentAttributes((yyval.complexContentVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexContentVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexContentVal)->item = (yyvsp[(6) - (9)].complexContentItemVal);
	  ;}
    break;

  case 80:

    {(yyval.complexContentItemVal) = (yyvsp[(1) - (1)].complexRestrictionVal);;}
    break;

  case 81:

    {(yyval.complexContentItemVal) = (yyvsp[(1) - (1)].complexExtensionVal);;}
    break;

  case 82:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 83:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 84:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 85:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexExtensionVal)->item = (yyvsp[(6) - (9)].otherContentBaseVal);
	  ;}
    break;

  case 86:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 87:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.complexExtensionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.complexExtensionVal)->item = (yyvsp[(6) - (10)].otherContentBaseVal);
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 88:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexExtensionVal)->item = (yyvsp[(5) - (8)].otherContentBaseVal);
	  ;}
    break;

  case 89:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexExtensionVal)->item = (yyvsp[(5) - (9)].otherContentBaseVal);
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 90:

    {(yyval.complexExtensionVal) = new XmlComplexExtension();
	   doXmlComplexExtensionAttributes((yyval.complexExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexExtensionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 91:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 92:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 93:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexRestrictionVal)->item = (yyvsp[(6) - (9)].otherContentBaseVal);
	  ;}
    break;

  case 94:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 95:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.complexRestrictionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.complexRestrictionVal)->item = (yyvsp[(6) - (10)].otherContentBaseVal);
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 96:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexRestrictionVal)->item = (yyvsp[(5) - (8)].otherContentBaseVal);
	  ;}
    break;

  case 97:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexRestrictionVal)->item = (yyvsp[(5) - (9)].otherContentBaseVal);
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 98:

    {(yyval.complexRestrictionVal) = new XmlComplexRestriction();
	   doXmlComplexRestrictionAttributes((yyval.complexRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexRestrictionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 99:

    {(yyval.complexTypeItemVal) = (yyvsp[(1) - (1)].complexContentVal);;}
    break;

  case 100:

    {(yyval.complexTypeItemVal) = (yyvsp[(1) - (1)].otherContentVal);;}
    break;

  case 101:

    {(yyval.complexTypeItemVal) = (yyvsp[(1) - (1)].simpleContentVal);;}
    break;

  case 102:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   (yyval.complexTypeVal)->item = new XmlOtherContent(0, 0);
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 103:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   (yyval.complexTypeVal)->item = new XmlOtherContent(0, 0);
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 104:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexTypeVal)->item = (yyvsp[(5) - (8)].complexTypeItemVal);
	  ;}
    break;

  case 105:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   (yyval.complexTypeVal)->item = new XmlOtherContent(0, 0);
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.complexTypeVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 106:

    {(yyval.complexTypeVal) = new XmlComplexType();
	   doXmlComplexTypeAttributes((yyval.complexTypeVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.complexTypeVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.complexTypeVal)->item = (yyvsp[(6) - (9)].complexTypeItemVal);
	  ;}
    break;

  case 107:

    {(yyval.documentationVal) = new XmlDocumentation();
	   doXmlDocumentationAttributes((yyval.documentationVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.documentationVal)->text = (yyvsp[(5) - (8)].sVal);
	  ;}
    break;

  case 108:

    {(yyval.documentationVal) = new XmlDocumentation();
	   doXmlDocumentationAttributes((yyval.documentationVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.documentationVal)->text = strdup("");
	  ;}
    break;

  case 109:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 110:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (8)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(5) - (8)].typVal);
	  ;}
    break;

  case 111:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (9)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(6) - (9)].typVal);
	  ;}
    break;

  case 112:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(5) - (8)].idConstraintListVal);
	  ;}
    break;

  case 113:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 114:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (9)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(5) - (9)].typVal);
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 115:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (10)].attribPairListVal));
	   if (((yyval.elementLocalVal)->ref) || ((yyval.elementLocalVal)->typ))
	     yyerror("cannot have type definition with type or ref");
	   (yyval.elementLocalVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.elementLocalVal)->typeDef = (yyvsp[(6) - (10)].typVal);
	   (yyval.elementLocalVal)->idConstraints = (yyvsp[(7) - (10)].idConstraintListVal);
	  ;}
    break;

  case 116:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 117:

    {(yyval.elementLocalVal) = new XmlElementLocal();
	   doXmlElementLocalAttributes((yyval.elementLocalVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 118:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 119:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(5) - (8)].typVal);
	  ;}
    break;

  case 120:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(6) - (9)].typVal);
	  ;}
    break;

  case 121:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 122:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(5) - (9)].typVal);
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(6) - (9)].idConstraintListVal);
	  ;}
    break;

  case 123:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.elementRefableVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.elementRefableVal)->typeDef = (yyvsp[(6) - (10)].typVal);
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(7) - (10)].idConstraintListVal);
	  ;}
    break;

  case 124:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.elementRefableVal)->idConstraints = (yyvsp[(5) - (8)].idConstraintListVal);
	  ;}
    break;

  case 125:

    {(yyval.elementRefableVal) = new XmlElementRefable();
	   doXmlElementRefableAttributes((yyval.elementRefableVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 126:

    {(yyval.enumerationVal) = new XmlEnumeration();
	   doXmlEnumerationAttributes((yyval.enumerationVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 127:

    {(yyval.enumerationVal) = new XmlEnumeration();
	   doXmlEnumerationAttributes((yyval.enumerationVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.enumerationVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 128:

    {(yyval.fieldVal) = new XmlField();
	   doXmlFieldAttributes((yyval.fieldVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 129:

    {(yyval.fieldVal) = new XmlField();
	   doXmlFieldAttributes((yyval.fieldVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 130:

    {(yyval.fieldListVal) = new std::list<XmlField *>;
	   (yyval.fieldListVal)->push_back((yyvsp[(1) - (1)].fieldVal));
	  ;}
    break;

  case 131:

    {(yyval.fieldListVal) = (yyvsp[(1) - (2)].fieldListVal);
	   (yyvsp[(1) - (2)].fieldListVal)->push_back((yyvsp[(2) - (2)].fieldVal));
	  ;}
    break;

  case 132:

    {(yyval.idConstraintVal) = (yyvsp[(1) - (1)].keyVal);;}
    break;

  case 133:

    {(yyval.idConstraintVal) = (yyvsp[(1) - (1)].keyrefVal);;}
    break;

  case 134:

    {(yyval.idConstraintVal) = (yyvsp[(1) - (1)].uniqueVal);;}
    break;

  case 135:

    {(yyval.idConstraintListVal) = new std::list<XmlIdConstraint *>;
	   (yyval.idConstraintListVal)->push_back((yyvsp[(1) - (1)].idConstraintVal));
	  ;}
    break;

  case 136:

    {(yyval.idConstraintListVal) = (yyvsp[(1) - (2)].idConstraintListVal);
	   (yyvsp[(1) - (2)].idConstraintListVal)->push_back((yyvsp[(2) - (2)].idConstraintVal));
	  ;}
    break;

  case 137:

    {(yyval.includeVal) = new XmlInclude((yyvsp[(3) - (4)].sVal), 0);;}
    break;

  case 138:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.keyVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 139:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.keyVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.keyVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 140:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.keyVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.keyVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 141:

    {(yyval.keyVal) = new XmlKey();
           doXmlKeyAttributes((yyval.keyVal), (yyvsp[(4) - (11)].attribPairListVal));
           (yyval.keyVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.keyVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.keyVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.keyVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 142:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.keyrefVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 143:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.keyrefVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.keyrefVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 144:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.keyrefVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.keyrefVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 145:

    {(yyval.keyrefVal) = new XmlKeyref();
           doXmlKeyrefAttributes((yyval.keyrefVal), (yyvsp[(4) - (11)].attribPairListVal));
	   (yyval.keyrefVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.keyrefVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.keyrefVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.keyrefVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 146:

    {(yyval.maxExclusiveVal) = new XmlMaxExclusive();
	   doXmlMaxExclusiveAttributes((yyval.maxExclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 147:

    {(yyval.maxExclusiveVal) = new XmlMaxExclusive();
	   doXmlMaxExclusiveAttributes((yyval.maxExclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxExclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 148:

    {(yyval.maxInclusiveVal) = new XmlMaxInclusive();
	   doXmlMaxInclusiveAttributes((yyval.maxInclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 149:

    {(yyval.maxInclusiveVal) = new XmlMaxInclusive();
	   doXmlMaxInclusiveAttributes((yyval.maxInclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxInclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 150:

    {(yyval.maxLengthVal) = new XmlMaxLength();
	   doXmlMaxLengthAttributes((yyval.maxLengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 151:

    {(yyval.maxLengthVal) = new XmlMaxLength();
	   doXmlMaxLengthAttributes((yyval.maxLengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxLengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 152:

    {(yyval.minExclusiveVal) = new XmlMinExclusive();
	   doXmlMinExclusiveAttributes((yyval.minExclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 153:

    {(yyval.minExclusiveVal) = new XmlMinExclusive();
	   doXmlMinExclusiveAttributes((yyval.minExclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minExclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 154:

    {(yyval.minInclusiveVal) = new XmlMinInclusive();
	   doXmlMinInclusiveAttributes((yyval.minInclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 155:

    {(yyval.minInclusiveVal) = new XmlMinInclusive();
	   doXmlMinInclusiveAttributes((yyval.minInclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minInclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 156:

    {(yyval.minLengthVal) = new XmlMinLength();
	   doXmlMinLengthAttributes((yyval.minLengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 157:

    {(yyval.minLengthVal) = new XmlMinLength();
	   doXmlMinLengthAttributes((yyval.minLengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minLengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 158:

    {(yyval.nsPairVal) = new XmlNsPair((yyvsp[(1) - (2)].sVal), (yyvsp[(2) - (2)].sVal));;}
    break;

  case 159:

    {(yyval.nsPairListVal) = new std::list<XmlNsPair *>;
	   (yyval.nsPairListVal)->push_back((yyvsp[(1) - (1)].nsPairVal));
	  ;}
    break;

  case 160:

    {(yyval.nsPairListVal) = (yyvsp[(1) - (2)].nsPairListVal);
	   (yyvsp[(1) - (2)].nsPairListVal)->push_back((yyvsp[(2) - (2)].nsPairVal));
	  ;}
    break;

  case 161:

    {(yyval.otherContentVal) = new XmlOtherContent((yyvsp[(1) - (1)].otherContentBaseVal), 0);;}
    break;

  case 162:

    {(yyval.otherContentVal) = new XmlOtherContent(0, (yyvsp[(1) - (1)].attributorListVal));;}
    break;

  case 163:

    {(yyval.otherContentVal) = new XmlOtherContent((yyvsp[(1) - (2)].otherContentBaseVal), (yyvsp[(2) - (2)].attributorListVal));;}
    break;

  case 164:

    {(yyval.otherContentBaseVal) = (yyvsp[(1) - (1)].choiceVal);;}
    break;

  case 165:

    {(yyval.otherContentBaseVal) = (yyvsp[(1) - (1)].sequenceVal);;}
    break;

  case 166:

    {(yyval.patternVal) = new XmlPattern();
	   doXmlPatternAttributes((yyval.patternVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 167:

    {(yyval.patternVal) = new XmlPattern();
	   doXmlPatternAttributes((yyval.patternVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.patternVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 168:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxExclusiveVal);;}
    break;

  case 169:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxInclusiveVal);;}
    break;

  case 170:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxLengthVal);;}
    break;

  case 171:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minExclusiveVal);;}
    break;

  case 172:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minInclusiveVal);;}
    break;

  case 173:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minLengthVal);;}
    break;

  case 174:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].patternVal);;}
    break;

  case 175:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].enumerationVal);;}
    break;

  case 176:

    {(yyval.restrictionTypeListVal) = new std::list<XmlRestrictionType *>;
	   (yyval.restrictionTypeListVal)->push_back((yyvsp[(1) - (1)].restrictionTypeVal));
	  ;}
    break;

  case 177:

    {(yyval.restrictionTypeListVal) = (yyvsp[(1) - (2)].restrictionTypeListVal);
	   (yyvsp[(1) - (2)].restrictionTypeListVal)->push_back((yyvsp[(2) - (2)].restrictionTypeVal));
	  ;}
    break;

  case 178:

    {(yyval.schemaVal) = new XmlSchema((yyvsp[(1) - (6)].schemaHeaderVal), (yyvsp[(2) - (6)].schemaContent1ListVal), (yyvsp[(3) - (6)].schemaContent2ListVal));;}
    break;

  case 179:

    {(yyval.schemaContent1Val) = (yyvsp[(1) - (1)].includeVal);;}
    break;

  case 180:

    {(yyval.schemaContent1Val) = (yyvsp[(1) - (1)].annotationVal);;}
    break;

  case 181:

    {(yyval.schemaContent1ListVal) = new std::list<XmlSchemaContent1 *>;
	    //$$->push_back($1);
	  ;}
    break;

  case 182:

    {(yyval.schemaContent1ListVal) = (yyvsp[(1) - (2)].schemaContent1ListVal);
	   (yyvsp[(1) - (2)].schemaContent1ListVal)->push_back((yyvsp[(2) - (2)].schemaContent1Val));
	  ;}
    break;

  case 183:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].elementRefableVal);;}
    break;

  case 184:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].elementRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 185:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].complexTypeVal);;}
    break;

  case 186:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].complexTypeVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 187:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].simpleTypeVal);;}
    break;

  case 188:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].simpleTypeVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 189:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].attributeLonerRefableVal);;}
    break;

  case 190:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].attributeLonerRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 191:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].attributeGroupRefableVal);;}
    break;

  case 192:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].attributeGroupRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 193:

    {(yyval.schemaContent2ListVal) = new std::list<XmlSchemaContent2 *>;
	   (yyval.schemaContent2ListVal)->push_back((yyvsp[(1) - (1)].schemaContent2Val));
	  ;}
    break;

  case 194:

    {(yyval.schemaContent2ListVal) = (yyvsp[(1) - (2)].schemaContent2ListVal);
	   (yyvsp[(1) - (2)].schemaContent2ListVal)->push_back((yyvsp[(2) - (2)].schemaContent2Val));
	  ;}
    break;

  case 195:

    { // note that this removes the first element from the xmlNsList
	    checkXmlns((yyvsp[(3) - (5)].nsPairListVal));
	    (yyval.schemaHeaderVal) = new XmlSchemaHeader(0, 0, (yyvsp[(3) - (5)].nsPairListVal)->front(), (yyvsp[(3) - (5)].nsPairListVal),
				     XmlCppBase::formNone,
				     XmlCppBase::formNone, 0);
	    doXmlSchemaHeaderAttributes((yyval.schemaHeaderVal), (yyvsp[(4) - (5)].attribPairListVal));
	    (yyvsp[(3) - (5)].nsPairListVal)->pop_front();
	  ;}
    break;

  case 196:

    {(yyval.selectorVal) = new XmlSelector();
	   doXmlSelectorAttributes((yyval.selectorVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 197:

    {(yyval.selectorVal) = new XmlSelector();
	   doXmlSelectorAttributes((yyval.selectorVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 198:

    {(yyval.sequenceVal) = new XmlSequence();
	   doXmlSequenceAttributes((yyval.sequenceVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.sequenceVal)->items = (yyvsp[(5) - (8)].choSeqItemListVal);
	  ;}
    break;

  case 199:

    {(yyval.sequenceVal) = new XmlSequence();
	   doXmlSequenceAttributes((yyval.sequenceVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.sequenceVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.sequenceVal)->items = (yyvsp[(6) - (9)].choSeqItemListVal);
	  ;}
    break;

  case 200:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 201:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 202:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 203:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentVal)->item = (yyvsp[(5) - (8)].simpleContentItemVal);
	  ;}
    break;

  case 204:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentVal)->item = (yyvsp[(6) - (9)].simpleContentItemVal);
	  ;}
    break;

  case 205:

    {(yyval.simpleContentItemVal) = (yyvsp[(1) - (1)].simpleContentExtensionVal);;}
    break;

  case 206:

    {(yyval.simpleContentItemVal) = (yyvsp[(1) - (1)].simpleContentRestrictionVal);;}
    break;

  case 207:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 208:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 209:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 210:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 211:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 212:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 213:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 214:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 215:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(5) - (8)].restrictionTypeListVal);
	  ;}
    break;

  case 216:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 217:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(6) - (9)].restrictionTypeListVal);
	  ;}
    break;

  case 218:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 219:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(5) - (9)].restrictionTypeListVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 220:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(6) - (10)].restrictionTypeListVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 221:

    {(yyval.simpleItemVal) = (yyvsp[(1) - (1)].simpleListVal);;}
    break;

  case 222:

    {(yyval.simpleItemVal) = (yyvsp[(1) - (1)].simpleRestrictionVal);;}
    break;

  case 223:

    {(yyval.simpleListVal) = new XmlSimpleList();
	   doXmlSimpleListAttributes((yyval.simpleListVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 224:

    {(yyval.simpleListVal) = new XmlSimpleList();
	   doXmlSimpleListAttributes((yyval.simpleListVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 225:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 226:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 227:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = (yyvsp[(5) - (8)].restrictionTypeListVal);
	  ;}
    break;

  case 228:

    {(yyval.simpleTypeVal) = new XmlSimpleType();
	   doXmlSimpleTypeAttributes((yyval.simpleTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleTypeVal)->item = (yyvsp[(5) - (8)].simpleItemVal);
	  ;}
    break;

  case 229:

    {(yyval.simpleTypeVal) = new XmlSimpleType();
	   doXmlSimpleTypeAttributes((yyval.simpleTypeVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleTypeVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleTypeVal)->item = (yyvsp[(6) - (9)].simpleItemVal);
	  ;}
    break;

  case 230:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.uniqueVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 231:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.uniqueVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 232:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.uniqueVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 233:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(4) - (11)].attribPairListVal));
           (yyval.uniqueVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.uniqueVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 234:

    {(yyval.versionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  ;}
    break;

  case 235:

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


