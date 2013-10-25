/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
     XSLENGTH = 312,
     XSLIST = 313,
     XSMAXEXCLUSIVE = 314,
     XSMAXINCLUSIVE = 315,
     XSMAXLENGTH = 316,
     XSMINEXCLUSIVE = 317,
     XSMININCLUSIVE = 318,
     XSMINLENGTH = 319,
     XSPATTERN = 320,
     XSRESTRICTION = 321,
     XSSCHEMA = 322,
     XSSELECTOR = 323,
     XSSEQUENCE = 324,
     XSSIMPLECONTENT = 325,
     XSSIMPLETYPE = 326,
     XSUNIQUE = 327,
     XMLVERSION = 328
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
#define YYLAST   2061

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNRULES -- Number of states.  */
#define YYNSTATES  715

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

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
      65,    66,    67,    68,    69,    70,    71,    72,    73
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
     873,   878,   887,   892,   901,   906,   915,   920,   929,   934,
     943,   946,   948,   951,   953,   955,   958,   960,   962,   967,
     976,   978,   980,   982,   984,   986,   988,   990,   992,   994,
     996,   999,  1006,  1008,  1010,  1011,  1014,  1016,  1019,  1021,
    1024,  1026,  1029,  1031,  1034,  1036,  1039,  1041,  1044,  1050,
    1055,  1063,  1072,  1082,  1087,  1095,  1104,  1113,  1123,  1125,
    1127,  1132,  1140,  1149,  1158,  1168,  1173,  1181,  1190,  1199,
    1208,  1218,  1228,  1238,  1249,  1251,  1253,  1258,  1266,  1271,
    1279,  1288,  1297,  1307,  1317,  1328,  1339,  1351,  1356
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,   145,   128,    -1,   145,    96,   128,    -1,
      78,    35,    -1,    78,    41,    35,    -1,    -1,    77,    76,
      -1,     3,    -1,     4,    -1,     6,    -1,     7,    -1,     8,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    27,    -1,    33,    -1,    34,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    26,    35,    -1,   102,    -1,   143,    -1,    28,    77,
      11,    84,    31,    42,    11,    -1,    95,    28,    77,    11,
      84,    31,    42,    11,    -1,    95,    -1,    81,    -1,    82,
      81,    -1,   103,    -1,    85,    -1,    -1,    84,    83,    -1,
      30,    43,    77,    11,    35,    31,    43,    11,    -1,    30,
      43,    77,    11,    31,    43,    11,    -1,    30,    44,    77,
      12,    -1,    30,    44,    77,    11,    31,    44,    11,    -1,
      30,    44,    77,    11,   143,    31,    44,    11,    -1,    30,
      44,    77,    11,    81,    31,    44,    11,    -1,    30,    44,
      77,    11,    81,   143,    31,    44,    11,    -1,    30,    44,
      77,    12,    -1,    30,    44,    77,    11,   143,    31,    44,
      11,    -1,    30,    44,    77,    11,    81,    31,    44,    11,
      -1,    30,    44,    77,    11,    81,   143,    31,    44,    11,
      -1,    30,    45,    77,    12,    -1,    30,    45,    77,    11,
      91,    31,    45,    11,    -1,    30,    45,    77,    11,    81,
      31,    45,    11,    -1,    30,    45,    77,    11,    81,    91,
      31,    45,    11,    -1,    30,    45,    77,    12,    -1,    30,
      45,    77,    11,    91,    31,    45,    11,    -1,    30,    45,
      77,    11,    81,    31,    45,    11,    -1,    30,    45,    77,
      11,    81,    91,    31,    45,    11,    -1,    86,    -1,    88,
      -1,    90,    -1,    91,    90,    -1,    94,    -1,   104,    -1,
     135,    -1,    92,    -1,    93,    92,    -1,    30,    46,    77,
      11,    93,    31,    46,    11,    -1,    30,    46,    77,    11,
      81,    93,    31,    46,    11,    -1,    29,    10,    -1,    95,
      -1,    96,    95,    -1,    30,    47,    77,    11,    98,    31,
      47,    11,    -1,    30,    47,    77,    11,    81,    98,    31,
      47,    11,    -1,   100,    -1,    99,    -1,    30,    52,    77,
      12,    -1,    30,    52,    77,    11,    31,    52,    11,    -1,
      30,    52,    77,    11,    81,    31,    52,    11,    -1,    30,
      52,    77,    11,    81,   124,    31,    52,    11,    -1,    30,
      52,    77,    11,    81,    91,    31,    52,    11,    -1,    30,
      52,    77,    11,    81,   124,    91,    31,    52,    11,    -1,
      30,    52,    77,    11,   124,    31,    52,    11,    -1,    30,
      52,    77,    11,   124,    91,    31,    52,    11,    -1,    30,
      52,    77,    11,    91,    31,    52,    11,    -1,    30,    66,
      77,    12,    -1,    30,    66,    77,    11,    81,    31,    66,
      11,    -1,    30,    66,    77,    11,    81,   124,    31,    66,
      11,    -1,    30,    66,    77,    11,    81,    91,    31,    66,
      11,    -1,    30,    66,    77,    11,    81,   124,    91,    31,
      66,    11,    -1,    30,    66,    77,    11,   124,    31,    66,
      11,    -1,    30,    66,    77,    11,   124,    91,    31,    66,
      11,    -1,    30,    66,    77,    11,    91,    31,    66,    11,
      -1,    97,    -1,   123,    -1,   136,    -1,    30,    48,    77,
      12,    -1,    30,    48,    77,    11,    31,    48,    11,    -1,
      30,    48,    77,    11,   101,    31,    48,    11,    -1,    30,
      48,    77,    11,    81,    31,    48,    11,    -1,    30,    48,
      77,    11,    81,   101,    31,    48,    11,    -1,    30,    49,
      77,    11,    35,    31,    49,    11,    -1,    30,    49,    77,
      11,    31,    49,    11,    -1,    30,    50,    77,    11,    81,
      31,    50,    11,    -1,    30,    50,    77,    11,    80,    31,
      50,    11,    -1,    30,    50,    77,    11,    81,    80,    31,
      50,    11,    -1,    30,    50,    77,    11,   110,    31,    50,
      11,    -1,    30,    50,    77,    11,    81,   110,    31,    50,
      11,    -1,    30,    50,    77,    11,    80,   110,    31,    50,
      11,    -1,    30,    50,    77,    11,    81,    80,   110,    31,
      50,    11,    -1,    30,    50,    77,    11,    31,    50,    11,
      -1,    30,    50,    77,    12,    -1,    30,    50,    77,    11,
      81,    31,    50,    11,    -1,    30,    50,    77,    11,    80,
      31,    50,    11,    -1,    30,    50,    77,    11,    81,    80,
      31,    50,    11,    -1,    30,    50,    77,    11,    81,   110,
      31,    50,    11,    -1,    30,    50,    77,    11,    80,   110,
      31,    50,    11,    -1,    30,    50,    77,    11,    81,    80,
     110,    31,    50,    11,    -1,    30,    50,    77,    11,   110,
      31,    50,    11,    -1,    30,    50,    77,    12,    -1,    30,
      51,    77,    12,    -1,    30,    51,    77,    11,    81,    31,
      51,    11,    -1,    30,    53,    77,    12,    -1,    30,    53,
      77,    11,    31,    53,    11,    -1,   107,    -1,   108,   107,
      -1,   112,    -1,   113,    -1,   144,    -1,   109,    -1,   110,
     109,    -1,    30,    54,    79,    12,    -1,    30,    55,    77,
      11,   134,   108,    31,    55,    11,    -1,    96,    30,    55,
      77,    11,   134,   108,    31,    55,    11,    -1,    30,    55,
      77,    11,    81,   134,   108,    31,    55,    11,    -1,    96,
      30,    55,    77,    11,    81,   134,   108,    31,    55,    11,
      -1,    30,    56,    77,    11,   134,   108,    31,    56,    11,
      -1,    96,    30,    56,    77,    11,   134,   108,    31,    56,
      11,    -1,    30,    56,    77,    11,    81,   134,   108,    31,
      56,    11,    -1,    96,    30,    56,    77,    11,    81,   134,
     108,    31,    56,    11,    -1,    30,    57,    77,    12,    -1,
      30,    57,    77,    11,    81,    31,    57,    11,    -1,    30,
      59,    77,    12,    -1,    30,    59,    77,    11,    81,    31,
      59,    11,    -1,    30,    60,    77,    12,    -1,    30,    60,
      77,    11,    81,    31,    60,    11,    -1,    30,    61,    77,
      12,    -1,    30,    61,    77,    11,    81,    31,    61,    11,
      -1,    30,    62,    77,    12,    -1,    30,    62,    77,    11,
      81,    31,    62,    11,    -1,    30,    63,    77,    12,    -1,
      30,    63,    77,    11,    81,    31,    63,    11,    -1,    30,
      64,    77,    12,    -1,    30,    64,    77,    11,    81,    31,
      64,    11,    -1,    41,    35,    -1,   121,    -1,   122,   121,
      -1,   124,    -1,    91,    -1,   124,    91,    -1,    94,    -1,
     135,    -1,    30,    65,    77,    12,    -1,    30,    65,    77,
      11,    81,    31,    65,    11,    -1,   114,    -1,   115,    -1,
     116,    -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,
     125,    -1,   106,    -1,   126,    -1,   127,   126,    -1,   133,
     130,   132,    31,    67,    11,    -1,   111,    -1,    81,    -1,
      -1,   130,   129,    -1,   105,    -1,   105,    82,    -1,   102,
      -1,   102,    82,    -1,   143,    -1,   143,    82,    -1,    87,
      -1,    87,    82,    -1,    89,    -1,    89,    82,    -1,   131,
      -1,   132,   131,    -1,    30,    67,   122,    77,    11,    -1,
      30,    68,    77,    12,    -1,    30,    68,    77,    11,    31,
      68,    11,    -1,    30,    69,    77,    11,    93,    31,    69,
      11,    -1,    30,    69,    77,    11,    81,    93,    31,    69,
      11,    -1,    30,    70,    77,    12,    -1,    30,    70,    77,
      11,    31,    70,    11,    -1,    30,    70,    77,    11,    81,
      31,    70,    11,    -1,    30,    70,    77,    11,   137,    31,
      70,    11,    -1,    30,    70,    77,    11,    81,   137,    31,
      70,    11,    -1,   138,    -1,   139,    -1,    30,    52,    77,
      12,    -1,    30,    52,    77,    11,    31,    52,    11,    -1,
      30,    52,    77,    11,    81,    31,    52,    11,    -1,    30,
      52,    77,    11,    91,    31,    52,    11,    -1,    30,    52,
      77,    11,    81,    91,    31,    52,    11,    -1,    30,    66,
      77,    12,    -1,    30,    66,    77,    11,    31,    66,    11,
      -1,    30,    66,    77,    11,    81,    31,    66,    11,    -1,
      30,    66,    77,    11,   127,    31,    66,    11,    -1,    30,
      66,    77,    11,    91,    31,    66,    11,    -1,    30,    66,
      77,    11,    81,   127,    31,    66,    11,    -1,    30,    66,
      77,    11,    81,    91,    31,    66,    11,    -1,    30,    66,
      77,    11,   127,    91,    31,    66,    11,    -1,    30,    66,
      77,    11,    81,   127,    91,    31,    66,    11,    -1,   141,
      -1,   142,    -1,    30,    58,    77,    12,    -1,    30,    58,
      77,    11,    31,    58,    11,    -1,    30,    66,    77,    12,
      -1,    30,    66,    77,    11,    31,    66,    11,    -1,    30,
      66,    77,    11,   127,    31,    66,    11,    -1,    30,    71,
      77,    11,   140,    31,    71,    11,    -1,    30,    71,    77,
      11,    81,   140,    31,    71,    11,    -1,    30,    72,    77,
      11,   134,   108,    31,    72,    11,    -1,    96,    30,    72,
      77,    11,   134,   108,    31,    72,    11,    -1,    30,    72,
      77,    11,    81,   134,   108,    31,    72,    11,    -1,    96,
      30,    72,    77,    11,    81,   134,   108,    31,    72,    11,
      -1,    32,    73,    35,    13,    -1,    32,    73,    35,     9,
      35,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  2677,  2677,  2681,  2688,  2690,  2696,  2697,  2714,  2715,
    2716,  2717,  2718,  2719,  2720,  2721,  2722,  2723,  2724,  2725,
    2726,  2727,  2728,  2729,  2730,  2731,  2732,  2733,  2734,  2735,
    2736,  2737,  2738,  2742,  2747,  2748,  2752,  2760,  2769,  2777,
    2781,  2788,  2789,  2794,  2795,  2802,  2809,  2818,  2822,  2827,
    2834,  2841,  2852,  2856,  2863,  2870,  2881,  2886,  2893,  2900,
    2911,  2916,  2923,  2930,  2941,  2942,  2946,  2950,  2957,  2958,
    2959,  2963,  2967,  2974,  2981,  2992,  2997,  3001,  3008,  3015,
    3026,  3027,  3031,  3035,  3040,  3047,  3055,  3063,  3072,  3079,
    3087,  3097,  3101,  3108,  3116,  3124,  3133,  3140,  3148,  3158,
    3159,  3160,  3164,  3169,  3175,  3182,  3190,  3201,  3208,  3217,
    3224,  3233,  3243,  3250,  3258,  3268,  3279,  3284,  3291,  3298,
    3305,  3313,  3321,  3329,  3338,  3345,  3352,  3356,  3366,  3370,
    3378,  3382,  3389,  3391,  3393,  3398,  3402,  3409,  3414,  3421,
    3430,  3438,  3451,  3458,  3467,  3475,  3488,  3492,  3502,  3506,
    3516,  3520,  3530,  3534,  3544,  3548,  3559,  3563,  3573,  3577,
    3587,  3592,  3596,  3603,  3605,  3607,  3612,  3613,  3617,  3621,
    3631,  3632,  3633,  3634,  3635,  3636,  3637,  3638,  3639,  3643,
    3647,  3654,  3660,  3661,  3666,  3669,  3676,  3677,  3681,  3682,
    3686,  3687,  3691,  3692,  3696,  3697,  3704,  3708,  3715,  3727,
    3731,  3739,  3746,  3757,  3761,  3766,  3773,  3780,  3791,  3792,
    3796,  3800,  3805,  3812,  3819,  3830,  3835,  3841,  3849,  3856,
    3864,  3872,  3880,  3888,  3900,  3901,  3905,  3909,  3917,  3922,
    3928,  3938,  3945,  3956,  3963,  3972,  3980,  3993,  3998
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
  "XSFIELD", "XSINCLUDE", "XSKEY", "XSKEYREF", "XSLENGTH", "XSLIST",
  "XSMAXEXCLUSIVE", "XSMAXINCLUSIVE", "XSMAXLENGTH", "XSMINEXCLUSIVE",
  "XSMININCLUSIVE", "XSMINLENGTH", "XSPATTERN", "XSRESTRICTION",
  "XSSCHEMA", "XSSELECTOR", "XSSEQUENCE", "XSSIMPLECONTENT",
  "XSSIMPLETYPE", "XSUNIQUE", "XMLVERSION", "$accept", "xmlSchemaFile",
  "attributePair", "attributePairList", "attributeName", "schemaLocation",
  "typeDef", "xmlAnnotation", "xmlAnnotationList", "xmlAnnoType",
  "xmlAnnoTypeList", "xmlAppinfo", "xmlAttributeLoner",
  "xmlAttributeLonerRefable", "xmlAttributeGroup",
  "xmlAttributeGroupRefable", "xmlAttributor", "xmlAttributorList",
  "xmlChoSeqItem", "xmlChoSeqItemList", "xmlChoice", "xmlComment",
  "xmlCommentList", "xmlComplexContent", "xmlComplexContentItem",
  "xmlComplexExtension", "xmlComplexRestriction", "xmlComplexTypeItem",
  "xmlComplexType", "xmlDocumentation", "xmlElementLocal",
  "xmlElementRefable", "xmlEnumeration", "xmlField", "xmlFieldList",
  "xmlIdConstraint", "xmlIdConstraintList", "xmlInclude", "xmlKey",
  "xmlKeyref", "xmlLength", "xmlMaxExclusive", "xmlMaxInclusive",
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
     325,   326,   327,   328
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    93,    93,    94,    94,    95,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   102,   102,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   111,   112,   112,
     112,   112,   113,   113,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   129,   129,   130,   130,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   132,   132,   133,   134,
     134,   135,   135,   136,   136,   136,   136,   136,   137,   137,
     138,   138,   138,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   143,   143,   144,   144,   144,   144,   145,   145
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
       4,     8,     4,     8,     4,     8,     4,     8,     4,     8,
       2,     1,     2,     1,     1,     2,     1,     1,     4,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     6,     1,     1,     0,     2,     1,     2,     1,     2,
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
       0,     0,     0,     0,     0,     1,     0,     0,    76,     0,
       2,   184,     0,    75,     0,    77,     3,     0,     0,   237,
       0,   161,     6,     6,     0,   183,   192,   194,    38,   188,
     186,   182,   185,   196,     0,   190,     0,   160,     0,   162,
       0,     6,     6,     6,     6,     0,     6,    39,   193,   195,
       6,   189,   187,     0,     0,   197,   191,   238,     8,     9,
      10,    11,    12,   198,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     7,     0,    43,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     4,     0,     0,
       0,    52,     0,    60,     0,   102,     0,   125,    33,   137,
       0,    43,   181,     5,     0,     0,    44,    42,    41,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,     0,
       0,   164,   166,    99,     0,   100,   163,   167,   101,     0,
       0,     0,    38,     0,    34,   135,     0,   132,   133,    35,
     134,     0,     0,     0,   224,   225,     0,     6,     6,     0,
       0,     0,     0,     6,     6,     0,     0,     0,    67,     6,
       6,     6,     6,     0,     0,     0,     0,   165,     6,     6,
       6,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       6,     6,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     6,     6,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,    53,     0,    47,     0,
      56,    62,     0,    61,     0,     0,     0,     0,   203,   105,
       0,   104,     0,     0,     0,   119,     0,   118,     0,     0,
       0,     0,     0,     0,   124,     0,   226,     0,   228,     0,
     231,    37,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,    63,     0,     0,    71,     0,    68,    69,    70,
       0,     0,     0,    81,    80,     0,     0,     0,     0,     0,
       0,   208,   209,   106,     0,     0,     0,     0,     0,     0,
       0,   122,   120,     0,   121,     0,     0,     0,     0,     0,
       0,   178,   170,   171,   172,   173,   174,   175,   176,   177,
     179,     0,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,    72,     6,     6,
       0,     0,     0,     0,     6,     6,     0,     0,     0,     0,
       6,     0,     0,   130,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     0,     0,   180,    46,
       0,   108,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,     0,     0,     0,     6,     0,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     229,     0,    45,   107,    50,     0,    49,    58,     0,    57,
       0,   117,     0,    73,     0,    82,     0,    91,     0,    78,
       0,   201,     0,   210,     0,   215,   205,     0,   206,     0,
     199,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   146,     0,   148,
       0,   150,     0,   152,     0,   154,     0,   156,     0,   158,
       0,   168,   230,    51,    59,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    79,   202,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,     0,   128,   138,     0,   142,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,   144,   235,     0,
     139,     0,   143,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,     0,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   200,
       0,   141,   145,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,   109,     0,     0,     0,   112,
      84,     0,     0,     0,    90,    88,     0,    92,     0,     0,
       0,    98,    96,     0,   212,     0,   213,   217,     0,     0,
       0,   219,   218,     0,   129,   127,   147,   149,   151,   153,
     155,   157,   159,   169,   114,   111,     0,   113,    86,    85,
       0,    89,    94,    93,     0,    97,   214,   221,   220,     0,
     222,   115,    87,    95,   223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,    38,    85,    92,   140,    47,    48,   116,
      99,   117,   124,    26,   125,    27,   126,   131,   285,   286,
     287,    28,   143,   133,   292,   293,   294,   134,   144,   118,
     288,    30,   321,   363,   364,   145,   146,    31,   147,   148,
     322,   323,   324,   325,   326,   327,   328,    21,    22,   135,
     136,   329,   330,   331,    10,    32,    17,    33,    34,    11,
     306,   289,   138,   300,   301,   302,   153,   154,   155,   149,
     150,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -451
static const yytype_int16 yypact[] =
{
      24,     3,    82,    88,    50,  -451,    90,    39,  -451,    88,
    -451,  -451,    18,  -451,    68,  -451,  -451,   118,    85,  -451,
      95,  -451,    68,  -451,    54,  -451,   107,   107,   111,   107,
     107,  -451,  -451,  -451,    16,   107,   139,  -451,  1489,  -451,
    1527,  -451,  -451,  -451,  -451,   128,  -451,  -451,   107,   107,
    -451,   107,   107,   -28,    89,  -451,   107,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,   -17,  -451,   216,   276,   523,
     601,   130,   159,  1565,  -451,  1603,   162,  -451,   144,   184,
     243,  -451,   289,  -451,   132,  -451,   297,  -451,  -451,  -451,
     300,  -451,  -451,  -451,    14,   149,  -451,  -451,  -451,   110,
     195,   175,   233,   255,  -451,  -451,  -451,   327,    21,   169,
     335,   191,  -451,  -451,   211,  -451,   191,  -451,  -451,    86,
     302,   305,   111,   359,  -451,  -451,   311,  -451,  -451,  -451,
    -451,    23,   214,   220,  -451,  -451,   364,  -451,  -451,   247,
     237,   229,   245,  -451,  -451,   257,   398,   259,  -451,  -451,
    -451,  -451,  -451,   341,   312,   344,   325,   191,  -451,  -451,
    -451,   -18,   360,   314,   363,   317,   320,   -11,   366,  -451,
    -451,  -451,   387,   352,   383,  1641,  1679,  -451,   430,   406,
     437,   643,   681,   445,   386,   454,  1717,  1755,  1793,   719,
    -451,   456,   412,   458,  1831,  1869,  1907,   460,   423,   466,
     433,   333,   439,  -451,  -451,  -451,   491,   805,   843,   436,
     500,   504,    62,    98,  -451,   506,  -451,   158,  -451,   289,
    -451,  -451,   508,  -451,   342,   350,   342,   172,  -451,  -451,
     510,  -451,   353,   353,   353,  -451,   514,  -451,   517,   486,
     547,  1945,  1983,  2021,  -451,   482,  -451,   414,  -451,   586,
    -451,  -451,   533,   518,   554,   520,  -451,   509,   421,   583,
     424,   428,  -451,    81,   597,  -451,   449,  -451,  -451,  -451,
      17,   606,   600,  -451,  -451,   597,   451,    93,   572,   457,
     617,  -451,  -451,  -451,   588,   639,   648,   639,   648,   639,
     648,  -451,  -451,   662,  -451,   353,   353,   353,   628,   148,
     645,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,   461,  -451,   683,   664,   705,   675,   721,   701,   718,
     710,   722,   463,   741,  -451,   465,   739,  -451,  -451,  -451,
     756,   743,   468,   723,  -451,  -451,   777,   724,   758,   725,
    -451,   648,   738,  -451,   470,   648,   493,   648,   502,  -451,
     639,   648,   639,   648,   639,   648,   782,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,   785,   744,  -451,  -451,
     795,  -451,   796,  -451,   803,   771,   807,   820,   788,   823,
     881,   789,   825,   919,   957,   793,   837,   783,   842,   995,
    1033,  -451,   845,   799,   860,  1071,   534,  -451,   817,  -451,
     536,   818,   538,   801,   648,   540,   648,   542,   648,   544,
    -451,  1109,  1147,  1185,  1223,  1261,  1299,  1337,  1375,  1413,
    -451,   864,  -451,  -451,  -451,   867,  -451,  -451,   875,  -451,
     217,  -451,   879,  -451,   234,  -451,   356,  -451,   880,  -451,
     883,  -451,   277,  -451,   293,  -451,  -451,   896,  -451,   878,
    -451,   855,  1451,   900,   856,   902,   844,   913,   549,   873,
     551,   876,   555,   857,   107,  -451,   107,  -451,   107,  -451,
     107,  -451,   107,  -451,   107,  -451,   107,  -451,   107,  -451,
     107,  -451,  -451,  -451,  -451,   895,   362,   368,   372,  -451,
     -10,   897,   557,   563,   565,   571,   599,   602,  -451,  -451,
     898,   622,   641,   133,   882,   644,   660,   679,  -451,   886,
     936,   920,  -451,  -451,   951,  -451,   955,  -451,   912,   959,
     927,   974,   914,   976,   958,   961,   969,   973,   977,   990,
     992,   993,   994,  1015,   938,   375,   980,   378,   404,   988,
    1016,   953,   682,   698,   991,  1007,   717,   996,   720,   730,
     997,   998,   732,  1031,  1009,   735,  1013,  1035,  1002,   740,
     742,  1010,  1014,   746,  1070,  -451,  1044,  -451,  -451,  1073,
    -451,  1088,  -451,  1089,  -451,  1050,  1045,  1047,  1043,  1053,
    1056,  1059,  1055,  1072,  -451,  1124,  1090,  1127,  1091,   408,
    1094,  1128,  -451,  1141,  1104,  1105,   748,  1149,  1162,  1123,
    1165,  1111,  1112,   751,  1168,  1171,  1129,  -451,  1179,  1142,
    1187,  -451,  1200,  1148,  1150,   753,  1202,  1204,  1151,  -451,
    1209,  -451,  -451,  -451,  1217,  1221,  1222,  1225,  1238,  1240,
    1241,  1242,  1243,  -451,  1244,  -451,  1247,  1216,  1259,  -451,
    -451,  1260,  1263,  1235,  -451,  -451,  1278,  -451,  1279,  1280,
    1226,  -451,  -451,  1282,  -451,  1285,  -451,  -451,  1293,  1297,
    1246,  -451,  -451,  1298,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  1314,  -451,  -451,  -451,
    1316,  -451,  -451,  -451,  1317,  -451,  -451,  -451,  -451,  1318,
    -451,  -451,  -451,  -451,  -451
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -451,  -451,  -451,   420,  -451,  -451,  -139,    22,   140,  -451,
    1219,  -451,  -451,  -451,  -451,  -451,  -126,   -95,  -273,  -231,
    -101,    -3,  1328,  -451,  1051,  -451,  -451,  1220,     8,  -451,
    -451,  -451,  -451,  -306,  -260,  -134,  -130,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  1312,  -451,  -451,
    -435,  -451,  -323,  -450,  1338,  -451,  -451,  1329,  -451,  -451,
    -221,  -100,  -451,  1066,  -451,  -451,  1194,  -451,  -451,    -8,
    -451,  -451
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       8,   168,   185,   132,   137,   168,    15,   127,   388,    35,
     183,   186,   189,   347,   527,   296,    41,    42,    97,   514,
      43,   517,    44,   347,    98,    29,    35,    18,   166,   132,
     137,    19,   308,   310,   163,   164,   169,   178,   179,    25,
     168,   177,    29,    46,   223,   224,    53,    54,   366,   189,
     368,   168,   189,   345,   180,   221,     1,   157,   419,   171,
     419,   225,   419,   158,   352,   163,   164,   169,   170,   348,
      94,    94,   347,    94,    94,   580,     4,   563,    94,   347,
     569,   190,     5,   349,   361,    12,   365,   189,   367,   191,
     171,   172,   121,   272,   371,   373,   375,   273,    41,    42,
      13,   416,    43,   142,    44,   420,    14,   422,    45,    20,
     419,   425,   161,   427,   419,   429,   419,     6,     7,   419,
      36,   419,   120,   419,   123,    46,   130,   169,   141,   274,
      37,   344,   152,   275,    43,    23,     6,     8,     8,    50,
      15,   178,   179,     8,   281,   354,    23,     6,    24,   424,
     171,   426,    57,   428,    91,   168,    96,    46,   180,   355,
      23,     6,   128,   129,   478,   108,   480,    49,   482,    51,
      52,   109,   419,   112,   419,    56,   419,   163,   164,   113,
       8,    46,     8,     8,   377,   342,    23,     6,   119,   277,
     378,   159,   379,   380,   381,   382,   383,   384,   385,   377,
      23,     6,   297,   298,   388,   378,   162,   379,   380,   381,
     382,   383,   384,   385,   114,   115,   168,   173,     8,    58,
      59,   122,    60,    61,    62,   119,   160,   100,   101,   279,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   176,    76,   151,    23,     6,   139,   505,    77,
      78,   193,    79,    80,    81,    82,    83,   388,   197,   278,
     199,   280,    23,     6,   510,   511,   284,   291,   295,   299,
     339,    23,     6,   119,   305,   307,   309,   163,   164,    58,
      59,   198,    60,    61,    62,   122,   165,   102,   103,   200,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   203,    76,   205,    23,     6,   122,   520,    77,
      78,   506,    79,    80,    81,    82,    83,    23,     6,   122,
     508,    23,     6,   523,   524,    23,     6,   139,    23,     6,
     151,     6,   181,   182,     6,   139,   184,   370,   372,   374,
       6,   181,   188,     6,   181,   218,     6,   181,   220,     6,
     181,   222,   210,   132,   137,   132,   137,   122,   167,   513,
     211,   516,     6,   181,   259,   128,   174,   522,   557,   526,
      23,     6,   283,   213,   189,   212,   555,   558,    23,     6,
     290,    23,     6,   304,    23,     6,   510,   168,     6,   187,
     168,     6,   181,   554,   114,   194,   168,     6,   139,   556,
     168,     6,   181,   559,     6,   181,   606,     6,   181,   608,
     217,   132,   137,   219,   132,   137,   226,   562,   229,   566,
     568,   189,   572,   230,   189,   231,   575,   609,   122,   204,
     579,   242,   583,     6,   181,   610,   168,     6,   181,   657,
     168,   234,   168,    40,   319,   320,   168,   142,   236,   168,
     235,   119,   338,   168,   122,   341,   241,   168,   122,   343,
     250,    87,    88,    89,    90,   243,    93,   249,   616,   251,
      95,   255,   507,   256,   623,   189,   512,   257,   515,   283,
     346,   283,   353,   258,   521,   635,   525,   297,   357,   260,
     168,   319,   387,   122,   398,   283,   401,   168,   283,   407,
     362,   418,   264,     8,     8,     8,   544,   269,   545,   168,
     546,   270,   547,   318,   548,   271,   549,   276,   550,   282,
     551,   303,   552,   362,   421,   311,    58,    59,   312,    60,
      61,    62,   362,   423,   104,   105,   313,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   334,
      76,   336,     8,   337,     8,     8,    77,    78,   314,    79,
      80,    81,    82,    83,   362,   471,   362,   474,   362,   476,
     362,   479,   362,   481,   362,   483,   333,   195,   196,   362,
     538,   362,   540,   201,   202,   362,   542,   510,   561,   206,
     207,   208,   209,   122,   564,   122,   565,   332,   214,   215,
     216,   510,   567,   335,    58,    59,     8,    60,    61,    62,
     227,   228,   106,   107,   340,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   283,    76,   122,
     570,   351,   122,   571,    77,    78,   290,    79,    80,    81,
      82,    83,   356,   261,   262,   263,    58,    59,   359,    60,
      61,    62,   122,   574,   237,   238,   360,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   304,
      76,   122,   576,   369,   523,   578,    77,    78,   362,    79,
      80,    81,    82,    83,    58,    59,   376,    60,    61,    62,
     122,   581,   239,   240,   389,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   390,    76,   523,
     582,   386,   122,   614,    77,    78,   391,    79,    80,    81,
      82,    83,    58,    59,   392,    60,    61,    62,   122,   615,
     247,   248,   393,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   394,    76,   122,   619,   395,
     122,   621,    77,    78,   396,    79,    80,    81,    82,    83,
     122,   622,   122,   626,   400,   122,   629,   397,   403,   404,
     122,   633,   523,   634,   409,   410,   122,   638,   122,   663,
     415,   122,   670,   122,   680,   402,   399,   405,   411,   413,
     406,   417,   408,   430,   412,   414,   440,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   442,   443,    58,    59,
     441,    60,    61,    62,   444,   445,   265,   266,   446,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   447,    76,   448,   449,   452,   453,   472,    77,    78,
     458,    79,    80,    81,    82,    83,    58,    59,   459,    60,
      61,    62,   460,   461,   267,   268,   466,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   467,
      76,   468,   473,   477,   475,   502,    77,    78,   503,    79,
      80,    81,    82,    83,    58,    59,   504,    60,    61,    62,
     509,   518,   450,   451,   519,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   528,    76,   529,
     530,   533,   534,   535,    77,    78,   536,    79,    80,    81,
      82,    83,    58,    59,   537,    60,    61,    62,   539,   543,
     454,   455,   541,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   553,    76,   585,   577,   560,
     573,   586,    77,    78,   584,    79,    80,    81,    82,    83,
      58,    59,   587,    60,    61,    62,   588,   589,   456,   457,
     590,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   591,    76,   592,   593,   594,   605,   595,
      77,    78,   596,    79,    80,    81,    82,    83,    58,    59,
     597,    60,    61,    62,   598,   613,   462,   463,   599,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   600,    76,   601,   602,   603,   604,   612,    77,    78,
     607,    79,    80,    81,    82,    83,    58,    59,   611,    60,
      61,    62,   627,   617,   464,   465,   631,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   618,
      76,   628,   620,   624,   625,   630,    77,    78,   632,    79,
      80,    81,    82,    83,    58,    59,   636,    60,    61,    62,
     637,   639,   469,   470,   641,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   640,    76,   642,
     643,   644,   645,   647,    77,    78,   646,    79,    80,    81,
      82,    83,    58,    59,   648,    60,    61,    62,   649,   651,
     484,   485,   650,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   653,    76,   652,   655,   659,
     654,   656,    77,    78,   658,    79,    80,    81,    82,    83,
      58,    59,   660,    60,    61,    62,   661,   662,   486,   487,
     664,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   665,    76,   666,   667,   668,   669,   671,
      77,    78,   672,    79,    80,    81,    82,    83,    58,    59,
     674,    60,    61,    62,   675,   673,   488,   489,   676,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   677,    76,   681,   678,   682,   679,   683,    77,    78,
     684,    79,    80,    81,    82,    83,    58,    59,   685,    60,
      61,    62,   686,   687,   490,   491,   688,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   689,
      76,   690,   691,   692,   693,   694,    77,    78,   695,    79,
      80,    81,    82,    83,    58,    59,   696,    60,    61,    62,
     697,   698,   492,   493,   699,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   700,    76,   701,
     702,   703,   704,   705,    77,    78,   706,    79,    80,    81,
      82,    83,    58,    59,   707,    60,    61,    62,   708,   710,
     494,   495,   709,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   711,    76,   712,   713,   714,
     156,     9,    77,    78,    39,    79,    80,    81,    82,    83,
      58,    59,   350,    60,    61,    62,   192,    16,   496,   497,
     175,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    55,    76,   358,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   498,   499,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   500,   501,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   531,   532,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
      63,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,    86,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   110,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   111,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   232,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     233,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,   244,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   245,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   246,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   252,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    58,    59,     0,    60,    61,    62,     0,     0,
     253,     0,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,     0,     0,
       0,     0,    77,    78,     0,    79,    80,    81,    82,    83,
      58,    59,     0,    60,    61,    62,     0,     0,   254,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,     0,     0,     0,     0,
      77,    78,     0,    79,    80,    81,    82,    83,    58,    59,
       0,    60,    61,    62,     0,     0,   315,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    58,    59,     0,    60,
      61,    62,     0,     0,   316,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,     0,     0,     0,     0,    77,    78,     0,    79,
      80,    81,    82,    83,    58,    59,     0,    60,    61,    62,
       0,     0,   317,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83
};

static const yytype_int16 yycheck[] =
{
       3,   127,   141,   104,   104,   131,     9,   102,   331,    17,
     140,   141,   146,   286,   464,   246,    44,    45,    35,   454,
      48,   456,    50,   296,    41,    17,    34,     9,   123,   130,
     130,    13,   253,   254,    44,    45,    46,    55,    56,    17,
     166,   136,    34,    71,    55,    56,    30,    31,   308,   183,
     310,   177,   186,   284,    72,   185,    32,    43,   364,    69,
     366,    72,   368,    49,   295,    44,    45,    46,    47,    52,
      48,    49,   345,    51,    52,   525,    73,   512,    56,   352,
     515,    58,     0,    66,   305,    35,   307,   221,   309,    66,
      69,    70,   100,    31,   315,   316,   317,    35,    44,    45,
      10,   361,    48,   106,    50,   365,    67,   367,    54,    41,
     416,   371,   120,   373,   420,   375,   422,    29,    30,   425,
      35,   427,   100,   429,   102,    71,   104,    46,   106,    31,
      35,    50,   110,    35,    48,    28,    29,   140,   141,    28,
     143,    55,    56,   146,   239,    52,    28,    29,    30,   370,
      69,   372,    13,   374,    26,   281,    67,    71,    72,    66,
      28,    29,    30,    31,   424,    35,   426,    27,   428,    29,
      30,    12,   478,    11,   480,    35,   482,    44,    45,    35,
     183,    71,   185,   186,    51,   280,    28,    29,    30,    31,
      57,    42,    59,    60,    61,    62,    63,    64,    65,    51,
      28,    29,    30,    31,   527,    57,    31,    59,    60,    61,
      62,    63,    64,    65,    30,    31,   342,    48,   221,     3,
       4,    30,     6,     7,     8,    30,    31,    11,    12,   237,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    31,    27,    30,    28,    29,    30,    31,    33,
      34,    31,    36,    37,    38,    39,    40,   580,    11,   237,
      31,   239,    28,    29,    30,    31,   244,   245,   246,   247,
     278,    28,    29,    30,   252,   253,   254,    44,    45,     3,
       4,    44,     6,     7,     8,    30,    31,    11,    12,    44,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    45,    27,    45,    28,    29,    30,    31,    33,
      34,   450,    36,    37,    38,    39,    40,    28,    29,    30,
     450,    28,    29,    30,    31,    28,    29,    30,    28,    29,
      30,    29,    30,    31,    29,    30,    31,   315,   316,   317,
      29,    30,    31,    29,    30,    31,    29,    30,    31,    29,
      30,    31,    11,   454,   454,   456,   456,    30,    31,   454,
      48,   456,    29,    30,    31,    30,    31,   462,   507,   464,
      28,    29,    30,    48,   508,    31,   506,   507,    28,    29,
      30,    28,    29,    30,    28,    29,    30,   513,    29,    30,
     516,    29,    30,    31,    30,    31,   522,    29,    30,    31,
     526,    29,    30,    31,    29,    30,    31,    29,    30,    31,
      50,   512,   512,    50,   515,   515,    50,   512,    31,   514,
     515,   555,   517,    71,   558,    42,   521,   557,    30,    31,
     525,    45,   527,    29,    30,    31,   562,    29,    30,    31,
     566,    11,   568,    23,    30,    31,   572,   450,    11,   575,
      44,    30,    31,   579,    30,    31,    11,   583,    30,    31,
      48,    41,    42,    43,    44,    11,    46,    11,   563,    11,
      50,    11,   450,    50,   569,   609,   454,    11,   456,    30,
      31,    30,    31,    50,   462,   580,   464,    30,    31,    50,
     616,    30,    31,    30,    31,    30,    31,   623,    30,    31,
      30,    31,    11,   506,   507,   508,   484,    71,   486,   635,
     488,    11,   490,    31,   492,    11,   494,    11,   496,    11,
     498,    11,   500,    30,    31,    11,     3,     4,    11,     6,
       7,     8,    30,    31,    11,    12,    50,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    31,
      27,    31,   555,    44,   557,   558,    33,    34,    11,    36,
      37,    38,    39,    40,    30,    31,    30,    31,    30,    31,
      30,    31,    30,    31,    30,    31,    43,   157,   158,    30,
      31,    30,    31,   163,   164,    30,    31,    30,    31,   169,
     170,   171,   172,    30,    31,    30,    31,    11,   178,   179,
     180,    30,    31,    49,     3,     4,   609,     6,     7,     8,
     190,   191,    11,    12,    31,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    30,    27,    30,
      31,    31,    30,    31,    33,    34,    30,    36,    37,    38,
      39,    40,    70,   223,   224,   225,     3,     4,    31,     6,
       7,     8,    30,    31,    11,    12,    68,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    30,
      27,    30,    31,    11,    30,    31,    33,    34,    30,    36,
      37,    38,    39,    40,     3,     4,    58,     6,     7,     8,
      30,    31,    11,    12,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    43,    27,    30,
      31,    66,    30,    31,    33,    34,    11,    36,    37,    38,
      39,    40,     3,     4,    49,     6,     7,     8,    30,    31,
      11,    12,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    44,    27,    30,    31,    31,
      30,    31,    33,    34,    44,    36,    37,    38,    39,    40,
      30,    31,    30,    31,   344,    30,    31,    45,   348,   349,
      30,    31,    30,    31,   354,   355,    30,    31,    30,    31,
     360,    30,    31,    30,    31,    46,    45,    31,    11,    31,
      47,    53,    69,    11,    70,    70,    11,   377,   378,   379,
     380,   381,   382,   383,   384,   385,    11,    11,     3,     4,
      66,     6,     7,     8,    11,    44,    11,    12,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    27,    45,    11,    46,    11,   417,    33,    34,
      47,    36,    37,    38,    39,    40,     3,     4,    11,     6,
       7,     8,    69,    11,    11,    12,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    70,
      27,    11,    55,    72,    56,    11,    33,    34,    11,    36,
      37,    38,    39,    40,     3,     4,    11,     6,     7,     8,
      11,    11,    11,    12,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    27,    31,
      55,    11,    56,    11,    33,    34,    72,    36,    37,    38,
      39,    40,     3,     4,    11,     6,     7,     8,    55,    72,
      11,    12,    56,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    50,    27,    11,    66,    52,
      52,    31,    33,    34,    68,    36,    37,    38,    39,    40,
       3,     4,    11,     6,     7,     8,    11,    55,    11,    12,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    56,    27,    11,    72,    11,    50,    31,
      33,    34,    31,    36,    37,    38,    39,    40,     3,     4,
      31,     6,     7,     8,    31,    52,    11,    12,    31,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    31,    27,    31,    31,    31,    11,    11,    33,    34,
      50,    36,    37,    38,    39,    40,     3,     4,    50,     6,
       7,     8,    11,    52,    11,    12,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    52,
      27,    52,    66,    66,    66,    52,    33,    34,    66,    36,
      37,    38,    39,    40,     3,     4,    66,     6,     7,     8,
      66,    11,    11,    12,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    53,    27,    11,
      11,    51,    57,    60,    33,    34,    59,    36,    37,    38,
      39,    40,     3,     4,    61,     6,     7,     8,    62,    64,
      11,    12,    63,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    11,    27,    65,    11,    11,
      50,    50,    33,    34,    50,    36,    37,    38,    39,    40,
       3,     4,    11,     6,     7,     8,    52,    52,    11,    12,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    11,    27,    52,    11,    66,    66,    11,
      33,    34,    11,    36,    37,    38,    39,    40,     3,     4,
      11,     6,     7,     8,    52,    66,    11,    12,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    11,    27,    11,    66,    11,    66,    66,    33,    34,
      11,    36,    37,    38,    39,    40,     3,     4,    11,     6,
       7,     8,    11,    11,    11,    12,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    11,
      27,    11,    11,    11,    11,    11,    33,    34,    11,    36,
      37,    38,    39,    40,     3,     4,    50,     6,     7,     8,
      11,    11,    11,    12,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    52,    27,    11,
      11,    11,    66,    11,    33,    34,    11,    36,    37,    38,
      39,    40,     3,     4,    11,     6,     7,     8,    11,    11,
      11,    12,    66,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    11,    27,    11,    11,    11,
     111,     3,    33,    34,    22,    36,    37,    38,    39,    40,
       3,     4,   291,     6,     7,     8,   152,     9,    11,    12,
     130,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    34,    27,   299,    -1,    -1,    -1,    -1,
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
      -1,    36,    37,    38,    39,    40,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    75,   145,    73,     0,    29,    30,    95,    96,
     128,   133,    35,    10,    67,    95,   128,   130,     9,    13,
      41,   121,   122,    28,    30,    81,    87,    89,    95,   102,
     105,   111,   129,   131,   132,   143,    35,    35,    77,   121,
      77,    44,    45,    48,    50,    54,    71,    81,    82,    82,
      28,    82,    82,    30,    31,   131,    82,    13,     3,     4,
       6,     7,     8,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    27,    33,    34,    36,
      37,    38,    39,    40,    76,    78,    11,    77,    77,    77,
      77,    26,    79,    77,    81,    77,    67,    35,    41,    84,
      11,    12,    11,    12,    11,    12,    11,    12,    35,    12,
      11,    11,    11,    35,    30,    31,    83,    85,   103,    30,
      81,   143,    30,    81,    86,    88,    90,    91,    30,    31,
      81,    91,    94,    97,   101,   123,   124,   135,   136,    30,
      80,    81,    95,    96,   102,   109,   110,   112,   113,   143,
     144,    30,    81,   140,   141,   142,    84,    43,    49,    42,
      31,   143,    31,    44,    45,    31,    91,    31,    90,    46,
      47,    69,    70,    48,    31,   101,    31,    91,    55,    56,
      72,    30,    31,   110,    31,    80,   110,    30,    31,   109,
      58,    66,   140,    31,    31,    77,    77,    11,    44,    31,
      44,    77,    77,    45,    31,    45,    77,    77,    77,    77,
      11,    48,    31,    48,    77,    77,    77,    50,    31,    50,
      31,   110,    31,    55,    56,    72,    50,    77,    77,    31,
      71,    42,    11,    11,    11,    44,    11,    11,    12,    11,
      12,    11,    45,    11,    11,    11,    11,    11,    12,    11,
      48,    11,    11,    11,    11,    11,    50,    11,    50,    31,
      50,    77,    77,    77,    11,    11,    12,    11,    12,    71,
      11,    11,    31,    35,    31,    35,    11,    31,    81,   143,
      81,    91,    11,    30,    81,    92,    93,    94,   104,   135,
      30,    81,    98,    99,   100,    81,    93,    30,    31,    81,
     137,   138,   139,    11,    30,    81,   134,    81,   134,    81,
     134,    11,    11,    50,    11,    11,    11,    11,    31,    30,
      31,   106,   114,   115,   116,   117,   118,   119,   120,   125,
     126,   127,    11,    43,    31,    49,    31,    44,    31,   143,
      31,    31,    91,    31,    50,    93,    31,    92,    52,    66,
      98,    31,    93,    31,    52,    66,    70,    31,   137,    31,
      68,   134,    30,   107,   108,   134,   108,   134,   108,    11,
      81,   134,    81,   134,    81,   134,    58,    51,    57,    59,
      60,    61,    62,    63,    64,    65,    66,    31,   126,    11,
      43,    11,    49,    11,    44,    31,    44,    45,    31,    45,
      77,    31,    46,    77,    77,    31,    47,    31,    69,    77,
      77,    11,    70,    31,    70,    77,   108,    53,    31,   107,
     108,    31,   108,    31,   134,   108,   134,   108,   134,   108,
      11,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      11,    66,    11,    11,    11,    44,    11,    11,    45,    11,
      11,    12,    46,    11,    11,    12,    11,    12,    47,    11,
      69,    11,    11,    12,    11,    12,    11,    70,    11,    11,
      12,    31,    77,    55,    31,    56,    31,    72,   108,    31,
     108,    31,   108,    31,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    11,    11,    31,    80,    81,   110,    11,
      30,    31,    81,    91,   124,    81,    91,   124,    11,    11,
      31,    81,    91,    30,    31,    81,    91,   127,    11,    31,
      55,    11,    12,    11,    56,    11,    72,    11,    31,    55,
      31,    56,    31,    72,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    50,    31,   110,    31,    80,   110,    31,
      52,    31,    91,   124,    31,    31,    91,    31,    91,   124,
      31,    31,    91,    52,    31,    91,    31,    66,    31,    91,
     127,    31,    31,    91,    68,    11,    31,    11,    11,    55,
      11,    56,    11,    72,    11,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    11,    50,    31,    50,    31,   110,
      31,    50,    11,    52,    31,    31,    91,    52,    52,    31,
      66,    31,    31,    91,    66,    66,    31,    11,    52,    31,
      52,    11,    66,    31,    31,    91,    66,    66,    31,    11,
      53,    11,    11,    11,    51,    57,    59,    60,    61,    62,
      63,    64,    65,    11,    50,    11,    50,    31,    50,    11,
      11,    52,    52,    31,    11,    11,    52,    11,    66,    66,
      31,    11,    11,    66,    11,    52,    11,    11,    66,    66,
      31,    11,    11,    66,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    50,    11,    11,    11,
      52,    11,    11,    11,    66,    11,    11,    11,    11,    66,
      11,    11,    11,    11,    11
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

    {(yyval.lengthVal) = new XmlLength();
	   doXmlLengthAttributes((yyval.lengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 147:

    {(yyval.lengthVal) = new XmlLength();
	   doXmlLengthAttributes((yyval.lengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.lengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 148:

    {(yyval.maxExclusiveVal) = new XmlMaxExclusive();
	   doXmlMaxExclusiveAttributes((yyval.maxExclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 149:

    {(yyval.maxExclusiveVal) = new XmlMaxExclusive();
	   doXmlMaxExclusiveAttributes((yyval.maxExclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxExclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 150:

    {(yyval.maxInclusiveVal) = new XmlMaxInclusive();
	   doXmlMaxInclusiveAttributes((yyval.maxInclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 151:

    {(yyval.maxInclusiveVal) = new XmlMaxInclusive();
	   doXmlMaxInclusiveAttributes((yyval.maxInclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxInclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 152:

    {(yyval.maxLengthVal) = new XmlMaxLength();
	   doXmlMaxLengthAttributes((yyval.maxLengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 153:

    {(yyval.maxLengthVal) = new XmlMaxLength();
	   doXmlMaxLengthAttributes((yyval.maxLengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.maxLengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 154:

    {(yyval.minExclusiveVal) = new XmlMinExclusive();
	   doXmlMinExclusiveAttributes((yyval.minExclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 155:

    {(yyval.minExclusiveVal) = new XmlMinExclusive();
	   doXmlMinExclusiveAttributes((yyval.minExclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minExclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 156:

    {(yyval.minInclusiveVal) = new XmlMinInclusive();
	   doXmlMinInclusiveAttributes((yyval.minInclusiveVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 157:

    {(yyval.minInclusiveVal) = new XmlMinInclusive();
	   doXmlMinInclusiveAttributes((yyval.minInclusiveVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minInclusiveVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 158:

    {(yyval.minLengthVal) = new XmlMinLength();
	   doXmlMinLengthAttributes((yyval.minLengthVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 159:

    {(yyval.minLengthVal) = new XmlMinLength();
	   doXmlMinLengthAttributes((yyval.minLengthVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.minLengthVal)->note = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 160:

    {(yyval.nsPairVal) = new XmlNsPair((yyvsp[(1) - (2)].sVal), (yyvsp[(2) - (2)].sVal));;}
    break;

  case 161:

    {(yyval.nsPairListVal) = new std::list<XmlNsPair *>;
	   (yyval.nsPairListVal)->push_back((yyvsp[(1) - (1)].nsPairVal));
	  ;}
    break;

  case 162:

    {(yyval.nsPairListVal) = (yyvsp[(1) - (2)].nsPairListVal);
	   (yyvsp[(1) - (2)].nsPairListVal)->push_back((yyvsp[(2) - (2)].nsPairVal));
	  ;}
    break;

  case 163:

    {(yyval.otherContentVal) = new XmlOtherContent((yyvsp[(1) - (1)].otherContentBaseVal), 0);;}
    break;

  case 164:

    {(yyval.otherContentVal) = new XmlOtherContent(0, (yyvsp[(1) - (1)].attributorListVal));;}
    break;

  case 165:

    {(yyval.otherContentVal) = new XmlOtherContent((yyvsp[(1) - (2)].otherContentBaseVal), (yyvsp[(2) - (2)].attributorListVal));;}
    break;

  case 166:

    {(yyval.otherContentBaseVal) = (yyvsp[(1) - (1)].choiceVal);;}
    break;

  case 167:

    {(yyval.otherContentBaseVal) = (yyvsp[(1) - (1)].sequenceVal);;}
    break;

  case 168:

    {(yyval.patternVal) = new XmlPattern();
	   doXmlPatternAttributes((yyval.patternVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 169:

    {(yyval.patternVal) = new XmlPattern();
	   doXmlPatternAttributes((yyval.patternVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.patternVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 170:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].lengthVal);;}
    break;

  case 171:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxExclusiveVal);;}
    break;

  case 172:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxInclusiveVal);;}
    break;

  case 173:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].maxLengthVal);;}
    break;

  case 174:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minExclusiveVal);;}
    break;

  case 175:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minInclusiveVal);;}
    break;

  case 176:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].minLengthVal);;}
    break;

  case 177:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].patternVal);;}
    break;

  case 178:

    {(yyval.restrictionTypeVal) = (yyvsp[(1) - (1)].enumerationVal);;}
    break;

  case 179:

    {(yyval.restrictionTypeListVal) = new std::list<XmlRestrictionType *>;
	   (yyval.restrictionTypeListVal)->push_back((yyvsp[(1) - (1)].restrictionTypeVal));
	  ;}
    break;

  case 180:

    {(yyval.restrictionTypeListVal) = (yyvsp[(1) - (2)].restrictionTypeListVal);
	   (yyvsp[(1) - (2)].restrictionTypeListVal)->push_back((yyvsp[(2) - (2)].restrictionTypeVal));
	  ;}
    break;

  case 181:

    {(yyval.schemaVal) = new XmlSchema((yyvsp[(1) - (6)].schemaHeaderVal), (yyvsp[(2) - (6)].schemaContent1ListVal), (yyvsp[(3) - (6)].schemaContent2ListVal));;}
    break;

  case 182:

    {(yyval.schemaContent1Val) = (yyvsp[(1) - (1)].includeVal);;}
    break;

  case 183:

    {(yyval.schemaContent1Val) = (yyvsp[(1) - (1)].annotationVal);;}
    break;

  case 184:

    {(yyval.schemaContent1ListVal) = new std::list<XmlSchemaContent1 *>;
	    //$$->push_back($1);
	  ;}
    break;

  case 185:

    {(yyval.schemaContent1ListVal) = (yyvsp[(1) - (2)].schemaContent1ListVal);
	   (yyvsp[(1) - (2)].schemaContent1ListVal)->push_back((yyvsp[(2) - (2)].schemaContent1Val));
	  ;}
    break;

  case 186:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].elementRefableVal);;}
    break;

  case 187:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].elementRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 188:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].complexTypeVal);;}
    break;

  case 189:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].complexTypeVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 190:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].simpleTypeVal);;}
    break;

  case 191:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].simpleTypeVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 192:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].attributeLonerRefableVal);;}
    break;

  case 193:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].attributeLonerRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 194:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (1)].attributeGroupRefableVal);;}
    break;

  case 195:

    {(yyval.schemaContent2Val) = (yyvsp[(1) - (2)].attributeGroupRefableVal);
	   (yyval.schemaContent2Val)->backNotes = (yyvsp[(2) - (2)].annotationListVal);
	  ;}
    break;

  case 196:

    {(yyval.schemaContent2ListVal) = new std::list<XmlSchemaContent2 *>;
	   (yyval.schemaContent2ListVal)->push_back((yyvsp[(1) - (1)].schemaContent2Val));
	  ;}
    break;

  case 197:

    {(yyval.schemaContent2ListVal) = (yyvsp[(1) - (2)].schemaContent2ListVal);
	   (yyvsp[(1) - (2)].schemaContent2ListVal)->push_back((yyvsp[(2) - (2)].schemaContent2Val));
	  ;}
    break;

  case 198:

    { // note that this removes the first element from the xmlNsList
	    checkXmlns((yyvsp[(3) - (5)].nsPairListVal));
	    (yyval.schemaHeaderVal) = new XmlSchemaHeader(0, 0, (yyvsp[(3) - (5)].nsPairListVal)->front(), (yyvsp[(3) - (5)].nsPairListVal),
				     XmlCppBase::formNone,
				     XmlCppBase::formNone, 0);
	    doXmlSchemaHeaderAttributes((yyval.schemaHeaderVal), (yyvsp[(4) - (5)].attribPairListVal));
	    (yyvsp[(3) - (5)].nsPairListVal)->pop_front();
	  ;}
    break;

  case 199:

    {(yyval.selectorVal) = new XmlSelector();
	   doXmlSelectorAttributes((yyval.selectorVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 200:

    {(yyval.selectorVal) = new XmlSelector();
	   doXmlSelectorAttributes((yyval.selectorVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 201:

    {(yyval.sequenceVal) = new XmlSequence();
	   doXmlSequenceAttributes((yyval.sequenceVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.sequenceVal)->items = (yyvsp[(5) - (8)].choSeqItemListVal);
	  ;}
    break;

  case 202:

    {(yyval.sequenceVal) = new XmlSequence();
	   doXmlSequenceAttributes((yyval.sequenceVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.sequenceVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.sequenceVal)->items = (yyvsp[(6) - (9)].choSeqItemListVal);
	  ;}
    break;

  case 203:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 204:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 205:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 206:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentVal)->item = (yyvsp[(5) - (8)].simpleContentItemVal);
	  ;}
    break;

  case 207:

    {(yyval.simpleContentVal) = new XmlSimpleContent();
	   doXmlSimpleContentAttributes((yyval.simpleContentVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentVal)->item = (yyvsp[(6) - (9)].simpleContentItemVal);
	  ;}
    break;

  case 208:

    {(yyval.simpleContentItemVal) = (yyvsp[(1) - (1)].simpleContentExtensionVal);;}
    break;

  case 209:

    {(yyval.simpleContentItemVal) = (yyvsp[(1) - (1)].simpleContentRestrictionVal);;}
    break;

  case 210:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 211:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 212:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	  ;}
    break;

  case 213:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	  ;}
    break;

  case 214:

    {(yyval.simpleContentExtensionVal) = new XmlSimpleContentExtension();
	   doXmlSimpleContentExtensionAttributes((yyval.simpleContentExtensionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentExtensionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentExtensionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 215:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 216:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 217:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (8)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 218:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(5) - (8)].restrictionTypeListVal);
	  ;}
    break;

  case 219:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(5) - (8)].attributorListVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 220:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(6) - (9)].restrictionTypeListVal);
	  ;}
    break;

  case 221:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 222:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(5) - (9)].restrictionTypeListVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(6) - (9)].attributorListVal);
	  ;}
    break;

  case 223:

    {(yyval.simpleContentRestrictionVal) = new XmlSimpleContentRestriction();
	   doXmlSimpleContentRestrictionAttributes((yyval.simpleContentRestrictionVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.simpleContentRestrictionVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.simpleContentRestrictionVal)->restrictions = (yyvsp[(6) - (10)].restrictionTypeListVal);
	   (yyval.simpleContentRestrictionVal)->attribs = (yyvsp[(7) - (10)].attributorListVal);
	  ;}
    break;

  case 224:

    {(yyval.simpleItemVal) = (yyvsp[(1) - (1)].simpleListVal);;}
    break;

  case 225:

    {(yyval.simpleItemVal) = (yyvsp[(1) - (1)].simpleRestrictionVal);;}
    break;

  case 226:

    {(yyval.simpleListVal) = new XmlSimpleList();
	   doXmlSimpleListAttributes((yyval.simpleListVal), (yyvsp[(3) - (4)].attribPairListVal));
	  ;}
    break;

  case 227:

    {(yyval.simpleListVal) = new XmlSimpleList();
	   doXmlSimpleListAttributes((yyval.simpleListVal), (yyvsp[(3) - (7)].attribPairListVal));
	  ;}
    break;

  case 228:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (4)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 229:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (7)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = new std::list<XmlRestrictionType *>;
	  ;}
    break;

  case 230:

    {(yyval.simpleRestrictionVal) = new XmlSimpleRestriction();
	   doXmlSimpleRestrictionAttributes((yyval.simpleRestrictionVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleRestrictionVal)->restrictions = (yyvsp[(5) - (8)].restrictionTypeListVal);
	  ;}
    break;

  case 231:

    {(yyval.simpleTypeVal) = new XmlSimpleType();
	   doXmlSimpleTypeAttributes((yyval.simpleTypeVal), (yyvsp[(3) - (8)].attribPairListVal));
	   (yyval.simpleTypeVal)->item = (yyvsp[(5) - (8)].simpleItemVal);
	  ;}
    break;

  case 232:

    {(yyval.simpleTypeVal) = new XmlSimpleType();
	   doXmlSimpleTypeAttributes((yyval.simpleTypeVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.simpleTypeVal)->frontNote = (yyvsp[(5) - (9)].annotationVal);
	   (yyval.simpleTypeVal)->item = (yyvsp[(6) - (9)].simpleItemVal);
	  ;}
    break;

  case 233:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(3) - (9)].attribPairListVal));
	   (yyval.uniqueVal)->selector = (yyvsp[(5) - (9)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(6) - (9)].fieldListVal);
	  ;}
    break;

  case 234:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(4) - (10)].attribPairListVal));
	   (yyval.uniqueVal)->comments = (yyvsp[(1) - (10)].commentListVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 235:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(3) - (10)].attribPairListVal));
	   (yyval.uniqueVal)->frontNote = (yyvsp[(5) - (10)].annotationVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(6) - (10)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(7) - (10)].fieldListVal);
	  ;}
    break;

  case 236:

    {(yyval.uniqueVal) = new XmlUnique();
           doXmlUniqueAttributes((yyval.uniqueVal), (yyvsp[(4) - (11)].attribPairListVal));
           (yyval.uniqueVal)->comments = (yyvsp[(1) - (11)].commentListVal);
	   (yyval.uniqueVal)->frontNote = (yyvsp[(6) - (11)].annotationVal);
	   (yyval.uniqueVal)->selector = (yyvsp[(7) - (11)].selectorVal);
	   (yyval.uniqueVal)->fields = (yyvsp[(8) - (11)].fieldListVal);
	  ;}
    break;

  case 237:

    {(yyval.versionVal) = new XmlVersion(false);
	   if (strcmp((yyvsp[(3) - (4)].sVal), "1.0"))
	     yyerror("version number must be 1.0");
	  ;}
    break;

  case 238:

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


