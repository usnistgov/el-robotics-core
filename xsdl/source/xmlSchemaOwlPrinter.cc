/*

This reads an XML schema and writes an equivalent OWL file defining classes.
The usage of the XML schema language in the input file is constrained.

XML Schema Usage Rules
----------------------

1. The names of all types in the XML schema must end with "Type".

2. An XML complexType is translated into an OWL class. The OWL
class name is the same as the XML class name with "Type" removed
from the end.

3. An XML simpleType is translated into an OWL DatatypeDefinition.

4. In translating complex types, this skips elements named "Name"
because XML schema requires an explicit name in the class model but
OWL does not. In OWL, a name is assigned when an instance is created.
In kitting.xsd, the two base types, DataThingType and SolidObjectType,
both have a Name element, so that all complex types have it. By
removing the Name element from those two types, it is removed from all
complex types.

5. An annotation-documentation immediately following the header of a
schema is translated into an OWL AnnotationAssertion immediately
following the header of the OWL class file.

6. An annotation-documentation immediately following the beginning of
a complexType definition in the XML schema is translated into an OWL
AnnotationAssertion immediately following a Declaration(Class.

7. An annotation-documentation immediately following the beginning of
a simpleType definition in the XML schema is translated into an OWL
AnnotationAssertion immediately following a DatatypeDefinition.

8. An anotation-documentation immediately following an element in the
XML schema is translated into an OWL AnnotationAssertion immediately
following a Declaration(ObjectProperty or a Declaration(DataProperty.

9. The XML schema must not have any XML Attributes (i.e., only elements
are used).

10. The XML schema must be in venetian blind format so that all type
definitions are at the top level.

11. In an XML key:
A. The field xpaths must be only an element name. See example in
   documentation of printOwlIdConstraint.
B. When the key is in the root element, the selector xpath must be of
   the form .//XXX, where XXXType is the type of the XXX element.
C. When the key is in not in the root element, the selector xpath
   must be ".".

12. Elements whose name ends with "Name" (SkuName, for example) must
be of type IDREF, and the names of all elements of type IDREF must end
in "Name". Such elements must be pointers to instances of some complex type.

Limitations
-----------

This does not handle the following XML schema constructs:
  attribute
  choice
  complex restriction
  fixed
  include
  keyref
  maxLength
  maxOccurs of sequence
  minLength
  minOccurs of sequence
  pattern
  ref
  simpleList
  substitutionGroup
  unique

The handling of XSDL keys is complex. This is because XSDL keys are
element-based and apply only to specified instances of a type, while
OWL hasKey statements are type-based and apply to all instances of a
type.

An XSDL key can be made to apply to all instances of a type by using
the same element name XXX wherever the type is used and writing a key in
the root element of the schema using the selector xpath .//XXX 
That method does not work in some cases, as follows.
 
Since choice and substitution group are not available, it is not
possible from the top level element T to write a correct key on an
element E in the hierarchy of a type that is derived from a type that
is the type of an element F of T, since E is not visible from T.

For example, if items 1-4 below occur

1. The root of the schema is KittingWorkstation (of KittingWorkstationType
   which has the hierarchy)

     KittingWorkstationType           <-- T
        Object (SolidObjectType)      <-- F
        ...

2. PartsTrayWithPartsType is derived from SolidObjectType

3. PartsTrayWithPartsType has the hierarchy

     PartsTrayWithPartsType
       PartsTray (PartsTrayType)      <-- E
       ...

4. We want to write a key saying that the serial number and SkuName of a
PartsTray are its key (regardless of where the PartsTray occurs in the
instance file).

From the top level, we cannot write the xpath
kittingWorkstation/PartsTrayWithParts/PartsTray because there is no
PartsTrayWithParts element anywhere. Because that xpath does not exist,
we also cannot use the xpath .//PartsTray

What actually appears in an instance file (abbreviated) is
  <KittingWorkstation>
     <Object xsd:type="PartsTrayWithPartsType">
        <PartsTray>

To get around this problem, for each type that is to have a key but
the key cannot be placed at the top level, a key is placed in the
schema locally (in the PartsTray element in this case) with the
selector xpath ".". In generating OWL hasKey statements, the
xmlSchemaOwlPrinter treats the local key as though it were global.

Of course, utilities such as XMLSpy will apply the key only in the
specified context when checking instance files. Errors on the key in
other contexts will not be detected because the key will not apply in
those contexts.

*/

#include <stdio.h>   // fprintf
#include <string.h>  // strlen
#include <stdlib.h>  // exit
#include "xmlSchemaClasses.hh"
#include "xmlSchemaOwlPrinter.hh"

extern XmlSchemaFile * xmlSchemaFile;
extern FILE * yyin;
extern int yyparse();
extern int yyreparse();
extern FILE * yyrein;

/********************************************************************/

int XmlSchemaFile::printDoc = 0;
bool XmlSchemaFile::printComments = false;

/********************************************************************/

/* xmlSchemaOwlPrinter::buildClasses

Returned Value: none

Called By: main

This goes through the contents2 list of the schema. For each item on the
list:
1. If the item is a complex type or simple type, it is placed on the
   classes list.
2. If the item is the first item and is an XmlElementRefable, it is
   handled as described below.
3. If the item is not the first item and is an XmlElementRefable, or if
   the item is an XmlAttributeLoner, or if the item is an XmlAttributeGroup,
   an error message is printed, and the function exits.

The classes are the top-level complexTypes and the top-level simpleTypes.

The top level element (which must be XmlElementRefable) must have a
non-zero typ and must have a zero typeDef. This checks for that.

*/

void xmlSchemaOwlPrinter::buildClasses( /* ARGUMENTS                   */
 XmlSchema * schema)                    /* schema to build classes for */
{
  std::list<XmlSchemaContent2 *>::iterator iter;
  XmlElementRefable * realTop;
  XmlComplexType * complx;
  XmlSimpleType * simple;
  
  iter = schema->contents2->begin();
  if ((realTop = dynamic_cast<XmlElementRefable *>(*iter)))
    {
      if (realTop->typeDef || (realTop->typ == 0))
	{
	  fprintf(stderr, "top element must have a typ and no typeDef\n");
	  exit(1);
	}
      else
	iter++;
    }
  for ( ; iter != schema->contents2->end(); iter++)
    {
      if ((complx = dynamic_cast<XmlComplexType *>(*iter)))
	{
	  enterClass(complx);
	}
      else if ((simple = dynamic_cast<XmlSimpleType *>(*iter)))
	{
	  enterClass(simple);
	}
      else if (((dynamic_cast<XmlElementRefable *>(*iter)))        ||
	       ((dynamic_cast<XmlAttributeLonerRefable *>(*iter))) ||
	       ((dynamic_cast<XmlAttributeGroupRefable *>(*iter))))
	{
	  fprintf(stderr, "cannot handle refables in buildClasses\n");
	  exit(1);
	}
      else
	{
	  fprintf(stderr, "unknown XmlSchemaContent2 type in buildClasses\n");
	  exit(1);
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::buildElementInfo

Returned Value: none

Called By:  main

This builds the disjointClasses list from the complexTypes in the
schema. This also checks for types that cannot be handled. It exits if
any such types are found.

This is allowing a choice, but choice is disallowed later.

*/

void xmlSchemaOwlPrinter::buildElementInfo()/* NO ARGUMENTS */
{
  XmlComplexType * complx;
  XmlOtherContent * other;
  XmlComplexContent * comp;
  XmlComplexExtension * extend;
  XmlSequence * sequence;
  XmlChoice * choice;
  XmlElementLocal * elementLocal;
  std::list<XmlType *>::iterator iter;
  std::list<XmlChoSeqItem *> * items;
  std::list<XmlChoSeqItem *>::iterator ator;

  for (iter = classes.begin(); iter != classes.end(); iter++)
    {
      if ((complx = dynamic_cast<XmlComplexType *>(*iter)))
	{
	  items = 0;
	  if ((other = dynamic_cast<XmlOtherContent *>(complx->item)))
	    {
	      disjointClasses.push_back(complx);
	      if ((sequence = dynamic_cast<XmlSequence *>(other->base)))
		items = sequence->items;
	      else if ((choice = dynamic_cast<XmlChoice *>(other->base)))
		items = choice->items;
	    }
	  else if ((comp = dynamic_cast<XmlComplexContent *>(complx->item)))
	    {
	      if ((extend = dynamic_cast<XmlComplexExtension *>(comp->item)))
		{
		  if ((sequence = dynamic_cast<XmlSequence *>(extend->item)))
		    items = sequence->items;
		}
	      else if ((dynamic_cast<XmlComplexRestriction *>(comp->item)))
		{
		  fprintf(stderr, "cannot handle complex restriction\n");
		  exit(1);
		}
	      else
		{
		  fprintf(stderr, "unknown type of XML complex content item\n");
		  exit(1);
		}
	    }
	  if (!items)
	    continue;
	  for (ator = items->begin(); ator != items->end(); ator++)
	    {
	      if ((elementLocal = dynamic_cast<XmlElementLocal *>(*ator)))
		{
		  if (elementLocal->ref)
		    {
		      fprintf(stderr, "cannot handle referenced element\n");
		      exit(1);
		    }
		  else if (elementLocal->newTyp == 0)
		    {
		      fprintf(stderr, "element %s has no type\n",
			      elementLocal->name);
		      exit(1);
		    }
		}
	    }
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::deNameName

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocalIDREF

This checks that the name ends in "Name". If so, it copies the name into
the buffer with "Name" removed. If not, it prints an error message and
exits.

*/

void xmlSchemaOwlPrinter::deNameName( /* ARGUMENTS                           */
 char * name,                         /* name that ends in "Name"            */
 char * buffer)                       /* buffer for name copy without "Name" */
{
  int nameSize;

  nameSize = strlen(name);
  if ((nameSize > 4) && (nameSize < NAMESIZE) && 
      (strcmp((name + nameSize - 4), "Name") == 0))
    {
      strncpy(buffer, name, NAMESIZE);
      buffer[nameSize - 4] = 0;
    }
  else
    {
      fprintf(stderr, "name %s must end in \"Name\" but does not\n", name);
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::deTypeName

Returned Value: none

Called By:
  xmlSchemaOwlPrinter::printOwlComplexType
  xmlSchemaOwlPrinter::printOwlElementLocalComplex
  xmlSchemaOwlPrinter::printOwlElementLocalData
  xmlSchemaOwlPrinter::printOwlClassFile

This checks that the name ends in "Type". If so, it copies the name into
the buffer with "Type" removed. If not, it prints an error message and
exits.

*/

void xmlSchemaOwlPrinter::deTypeName( /* ARGUMENTS                           */
 char * name,                         /* name that ends in "Type"            */
 char * buffer)                       /* buffer for name copy without "Type" */
{
  int nameSize;

  nameSize = strlen(name);
  if ((nameSize > 4) && (nameSize < NAMESIZE) && 
      (strcmp((name + nameSize - 4), "Type") == 0))
    {
      strncpy(buffer, name, NAMESIZE);
      buffer[nameSize - 4] = 0;
    }
  else
    {
      fprintf(stderr, "name %s must end in \"Type\" but does not\n", name);
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::enterClass

Returned Value: none

Called By:  xmlSchemaOwlPrinter::buildClasses

This inserts aClass in the classes list in alphabetical order (by newName).
If a duplicate class name is found, this prints an error message and exits.

*/

void xmlSchemaOwlPrinter::enterClass( /* ARGUMENTS                 */
 XmlType * aClass)                    /* class to put into classes */
{
  std::list<XmlType *>::iterator iter;
  XmlSimpleType * simple;
  XmlComplexType * complx;
  char * newName;
  int result;

  if ((complx = dynamic_cast<XmlComplexType *>(aClass)))
    newName = complx->newName;
  else if ((simple = dynamic_cast<XmlSimpleType *>(aClass)))
    newName = simple->newName;
  else
    {
      fprintf(stderr, "bug: class not XmlSimpleType or XmlComplexType\n");
      exit(1);
    }
  for (iter = classes.begin(); iter != classes.end(); iter++)
    {
      if ((complx = dynamic_cast<XmlComplexType *>(*iter)))
	{
	  result = strcmp(newName, complx->newName);
	  if (result < 0)
	    {
	      classes.insert(iter, aClass);
	      break;
	    }
	  else if (result == 0)
	    {
	      fprintf(stderr, "duplicate class name %s. Exiting\n", newName);
	      exit(1);
	    }
	}
      else if ((simple = dynamic_cast<XmlSimpleType *>(*iter)))
	{
	  result = strcmp(newName, simple->newName);
	  if (result < 0)
	    {
	      classes.insert(iter, aClass);
	      break;
	    }
	  else if (result == 0)
	    {
	      fprintf(stderr, "duplicate class name %s. Exiting\n", newName);
	      exit(1);
	    }
	}
    }
  if (iter == classes.end())
    classes.push_back(aClass);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::enterKid

Returned Value: none

Called By:  xmlSchemaOwlPrinter::enterKids

This enters the kid type in the extensions of the parent type if it is
not already there. The extensions list of an XmlComplexType is not
kept in any particular order.

*/

void xmlSchemaOwlPrinter::enterKid( /* ARGUMENTS                          */
 XmlComplexType * parent,           /* parent type for which to enter kid */
 XmlComplexType * kid)              /* kid type                           */
{
  std::list<XmlComplexType *> * extensions;
  std::list<XmlComplexType *>::iterator iter;
  
  extensions = parent->extensions;
  if (extensions)
    {
      for (iter = extensions->begin(); iter != extensions->end(); iter++)
	{
	  if (*iter == kid)
	    {
	      fprintf(stderr, "duplicate extension for %s\n", kid->name);
	      exit(1);
	    }
	}
      extensions->push_back(kid); // kid not already on list, so add kid
    }
  else
    {
      parent->extensions = new std::list<XmlComplexType *>;
      parent->extensions->push_back(kid);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::enterKids

Returned Value: none

Called By:  main

*/

void xmlSchemaOwlPrinter::enterKids() /* NO ARGUMENTS    */
{
  XmlComplexType * parent;
  XmlComplexType * kid;
  XmlComplexContent * comp;
  XmlComplexExtension * extend;
  std::list<XmlType *>::iterator iter;

  for (iter = classes.begin(); iter != classes.end(); iter++)
    {
      if (((kid = dynamic_cast<XmlComplexType *>(*iter))) &&
	  ((comp = dynamic_cast<XmlComplexContent *>(kid->item))) &&
	  ((extend = dynamic_cast<XmlComplexExtension *>(comp->item))))
	{
	  parent = findComplexClass(extend->base);
	  if (parent == 0)
	    {
	      fprintf(stderr, "base type %s not found\n", extend->base);
	      exit(1);
	    }
	  enterKid(parent, kid);
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::findComplexClass

Returned Value: XmlComplexType *
  This looks through the classes and returns the class with the given name,
  or null if it is not found.

Called By:
  xmlSchemaOwlPrinter::buildElementInfo
  xmlSchemaOwlPrinter::enterKids;
  xmlSchemaOwlPrinter::printOwlElementLocal
  xmlSchemaOwlPrinter::printOwlElementLocalComplex

*/

XmlComplexType * xmlSchemaOwlPrinter::findComplexClass( /* ARGUMENTS        */
 char * name)                                      /* name of class to find */
{
  std::list<XmlType *>::iterator iter;
  XmlComplexType * complx;

  for (iter = classes.begin(); iter != classes.end(); iter++)
    {
      if ((complx = dynamic_cast<XmlComplexType *>(*iter)) &&
	  (strcmp(name, complx->newName) == 0))
	break;
    }
  return ((iter == classes.end()) ? 0 : complx);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::findSimpleClass

Returned Value: XmlSimpleType *
  This returns the simple class with the given name.

Called By:
  xmlSchemaOwlPrinter::buildElementInfo
  xmlSchemaOwlPrinter::printOwlElementLocal

*/

XmlSimpleType * xmlSchemaOwlPrinter::findSimpleClass( /* ARGUMENTS          */
 char * name)                                      /* name of class to find */
{
  std::list<XmlType *>::iterator iter;
  XmlSimpleType * simple;

  for (iter = classes.begin(); iter != classes.end(); iter++)
    {
      if ((simple = dynamic_cast<XmlSimpleType *>(*iter)) &&
	  (strcmp(name, simple->newName) == 0))
	break;
    }
  return ((iter == classes.end()) ? 0 : simple);
}

/********************************************************************/

/* void xmlSchemaOwlPrinter::printOwlAnnotation

Returned Value: none

Called By:
  xmlSchemaOwlPrinter::printOwlComplexContent
  xmlSchemaOwlPrinter::printOwlComplexExtension
  xmlSchemaOwlPrinter::printOwlComplexType
  xmlSchemaOwlPrinter::printOwlElementLocal
  xmlSchemaOwlPrinter::printOwlElementRefable
  xmlSchemaOwlPrinter::printOwlEnumeration
  xmlSchemaOwlPrinter::printOwlMaxExclusive
  xmlSchemaOwlPrinter::printOwlMaxInclusive
  xmlSchemaOwlPrinter::printOwlMinExclusive
  xmlSchemaOwlPrinter::printOwlMinInclusive
  xmlSchemaOwlPrinter::printOwlSchemaContent1
  xmlSchemaOwlPrinter::printOwlSequence
  xmlSchemaOwlPrinter::printOwlSimpleRestriction
  xmlSchemaOwlPrinter::printOwlSimpleType

This function prints a separate OWL AnnotationAssertion for each
documentation node in the XmlAnnotation.

This does not print XmlAppinfo.

*/

void xmlSchemaOwlPrinter::printOwlAnnotation( /* ARGUMENTS            */
 XmlAnnotation * annotation,                  /* annotation to print  */
 FILE * outFile)                              /* OWL file to print in */
{
  std::list<XmlAnnoType *>::iterator iter;
  XmlDocumentation * doc;
  XmlAppinfo * appinfo;

  if (annotation->comment)
    {
      fprintf(outFile, "\n");
      fprintf(outFile, "<!--%s-->\n", annotation->comment->c_str());
    }
  if (annotation->content)
    {
      fprintf(outFile, "\n");
      for (iter = annotation->content->begin();
	   iter != annotation->content->end(); iter++)
	{
	  if ((doc = dynamic_cast<XmlDocumentation *>(*iter)))
	    {
	      if (className[0])
		{
		  fprintf(outFile, "AnnotationAssertion(rdfs:comment");
		  fprintf(outFile, " :%s\n", className);
		}
	      else 
		fprintf(outFile, "Annotation(rdfs:comment\n");
	      fprintf(outFile, "  \"");
	      printOwlDocumentation(doc, outFile);
	      fprintf(outFile, "\")\n");
	    }
	  else if ((appinfo = dynamic_cast<XmlAppinfo *>(*iter)));
	  else
	    {
              fprintf(stderr,
		      "cannot handle annotation type in printOwlAnnotation\n");
	      exit(1);
	    }
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlChoSeqItem

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlSequence

*/

void xmlSchemaOwlPrinter::printOwlChoSeqItem(/* ARGUMENTS                */
 XmlChoSeqItem * item,                       /* item to print            */
 FILE * outFile)                             /* OWL file to print in     */
{
  XmlChoice * choice;
  XmlElementLocal * element;
  XmlSequence * sequence;

  if ((sequence = dynamic_cast<XmlSequence *>(item)))
    printOwlSequence(sequence, outFile);
  else if ((element = dynamic_cast<XmlElementLocal *>(item)))
    printOwlElementLocal(element, outFile);
  else if ((choice = dynamic_cast<XmlChoice *>(item)))
        {
      fprintf(stderr, "cannot handle XmlChoice\n");
      exit(1);
    }
  else
    {
      fprintf(stderr, "unknown type in printOwlChoSeqItem\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlClassFile

Returned Value: none

Called By: main

*/

void xmlSchemaOwlPrinter::printOwlClassFile(/* ARGUMENTS                    */
 XmlSchema * schema,                        /* XML schema to print OWL from */
 char * URL,                                /* URL to use in header         */
 FILE * outFile)                            /* OWL file to print in         */
{
  std::list<XmlSchemaContent1 *>::iterator iter;
  std::list<XmlSchemaContent2 *>::iterator ator;
  std::list<XmlComplexType *>::iterator eter;
  std::list<XmlSimpleType *>::iterator otor;

  printOwlSchemaHeader(schema->header, URL, outFile);
  className[0] = 0;
  for (iter = schema->contents1->begin();
       iter != schema->contents1->end(); iter++)
    printOwlSchemaContent1(*iter, outFile);
  topElement = 0;
  for (ator = schema->contents2->begin();
       ator != schema->contents2->end(); ator++)
    saveOwlSchemaContent2(*ator);
  if (topElement == 0)
    {
      fprintf(stderr, "there must be one top-level element\n");
      exit(1);
    }
  printOwlElementRefable(topElement, outFile);
  if (simpleTypes.size())
    {
      fprintf(outFile, "\n\n");
      for (otor = simpleTypes.begin(); otor != simpleTypes.end(); otor++)
	printOwlSimpleType(*otor, outFile);
    }
  if (complexTypes.size())
    {
      for (eter = complexTypes.begin(); eter != complexTypes.end(); eter++)
	printOwlComplexType(*eter, outFile);
    }
  if (disjointClasses.size() > 1)
    {
      fprintf(outFile, "\nDisjointClasses(");
      eter = disjointClasses.begin();
      deTypeName((*eter)->name, nameBuffer);
      fprintf(outFile, ":%s", nameBuffer);
      for (eter++; eter != disjointClasses.end(); eter++)
	{
	  deTypeName((*eter)->name, nameBuffer);
	  fprintf(outFile, "\n                :%s", nameBuffer);
	}
      fprintf(outFile, ")\n");
    }
  fprintf(outFile, ")\n");
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexContent

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlComplexTypeItem

*/

void xmlSchemaOwlPrinter::printOwlComplexContent(/* ARGUMENTS                */
 XmlComplexContent * complxCont,                 /* complex content to print */
 FILE * outFile)                                 /* OWL file to print in     */
{
  if (complxCont->id)
    fprintf(stderr, "ignoring id\n");
  if (complxCont->mixed)
    {
      fprintf(stderr, "ComplexContent must not have mixed but does\n");
      exit(1);
    }
  if (complxCont->frontNote)
    printOwlAnnotation(complxCont->frontNote, outFile);
  if (complxCont->item)
    printOwlComplexContentItem(complxCont->item, outFile);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexContentItem

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlComplexContent

*/

void xmlSchemaOwlPrinter::printOwlComplexContentItem (/* ARGUMENTS        */
 XmlComplexContentItem * item,           /* complex content item to print */
 FILE * outFile)                         /* OWL file to print in          */
{
  XmlComplexExtension * extend;
  XmlComplexRestriction * restrict;

  if ((extend = dynamic_cast<XmlComplexExtension *>(item)))
    printOwlComplexExtension(extend, outFile);
  else if ((restrict = dynamic_cast<XmlComplexRestriction *>(item)))
    {
      fprintf(stderr, "cannot handle complex restriction\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexExtension

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlComplexContentItem

*/

void xmlSchemaOwlPrinter::printOwlComplexExtension( /* ARGUMENTS            */
 XmlComplexExtension * extend,                /* complex extension to print */
 FILE * outFile)                              /* OWL file to print in       */
{
  if (!extend->base)
    {
      fprintf(stderr, "complex extension must have base\n");
      exit(1);
    }
  if (extend->id)
    fprintf(stderr, "ignoring id\n");
  if (extend->frontNote)
    printOwlAnnotation(extend->frontNote, outFile);
  if(extend->item)
    printOwlOtherContentBase(extend->item, outFile);
  if (extend->attribs)
    {
      fprintf(stderr, "cannot handle attributes\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexType

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlClassFile

*/

void xmlSchemaOwlPrinter::printOwlComplexType( /* ARGUMENTS             */
 XmlComplexType * complx,                      /* complex type to print */
 FILE * outFile)                               /* OWL file to print in  */
{
  std::list<XmlComplexType *>::iterator iter;
  std::list<XmlAnnotation *>::iterator ator;

  if (complx->name)
    {
      deTypeName(complx->name, nameBuffer);
      fprintf(outFile, "\n\n\nDeclaration(Class(:%s))\n", nameBuffer);
      strncpy(className, nameBuffer, NAMESIZE);
    }
  else
    {
      fprintf(stderr, "ComplexType must have a name but does not\n");
      exit(1);
    }
  if (complx->frontNote)
    printOwlAnnotation(complx->frontNote, outFile);
  if (complx->extensions)
    {
      fprintf(outFile, "\n");
      for (iter = complx->extensions->begin();
	   iter != complx->extensions->end(); iter++)
	{
	  deTypeName((*iter)->name, nameBuffer);
	  fprintf(outFile, "SubClassOf(:%s :%s)\n", nameBuffer, className);
	}
      if (complx->extensions->size() > 1)
	{
	  fprintf(outFile, "DisjointUnion(:%s", className);
	  for (iter = complx->extensions->begin();
	       iter != complx->extensions->end(); iter++)
	    {
	      deTypeName((*iter)->name, nameBuffer);
	      fprintf(outFile, "\n              :%s", nameBuffer);
	    }
	  fprintf(outFile, ")\n");
	}
    }
  if (complx->id)
    fprintf(stderr, "ignoring id\n");
  if (complx->mixed)
    {
      fprintf(stderr, "ComplexType %s must not be mixed but is\n",
	      complx->name);
      exit(1);
    }
  if (complx->item)
    printOwlComplexTypeItem(complx->item, outFile);
  if (complx->backNotes)
    {
      for (ator = complx->backNotes->begin();
	   ator != complx->backNotes->end(); ator++)
	printOwlAnnotation(*ator, outFile);
    }
  className[0] = 0;
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexTypeItem

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlComplexType

*/

void xmlSchemaOwlPrinter::printOwlComplexTypeItem( /* ARGUMENTS             */
 XmlComplexTypeItem * item,                   /* complex type item to print */
 FILE * outFile)                              /* OWL file to print in       */
{
  XmlComplexContent * complxCont;
  XmlOtherContent * otherCont;

  if ((complxCont = dynamic_cast<XmlComplexContent *>(item)))
    printOwlComplexContent(complxCont, outFile);
  else if ((otherCont = dynamic_cast<XmlOtherContent *>(item)))
    printOwlOtherContent(otherCont, outFile);
  else if (dynamic_cast<XmlSimpleContent *>(item))
    {
      fprintf(stderr, "cannot handle XmlSimpleContent\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlDocumentation

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlAnnotation

This expects doc->text to be formatted with 8 or more spaces at the
beginning of each line. This echos the text while modifying it as
follows. The doc->text must be prepared so that the modifications are
what is needed to convert XML schema documentation to OWL
documentation.

1. Initial and trailing white space is removed so that the quotes printed
   by printOwlAnnotation are right next to the documentation text.
2. The string "Type" is removed everywhere.
3. The string "          Name\n" is removed everywhere.
4. The string "          Name (inherited)\n" is removed everywhere.
5. The string "Name (IDREF)" is removed everywhere.
6. The string "Name (IDREF, " is converted to " (" everywhere.
7. The string "following elements" is converted to "following" everywhere.
8. Six of the first eight spaces on each line are removed.

Example:

This in the XML schema

  <xs:complexType name="VectorType">
    <xs:annotation>
      <xs:documentation>
        VectorType is derived from DataThingType.
        An instance of VectorType has the following elements:
          Name (inherited)
          I
          J
          K.
 
        The I, J, and K elements represent the usual i, j, and k
        components of a 3D vector.
      </xs:documentation>
    </xs:annotation>
    ...

becomes this in the OWL class file

Declaration(Class(:Vector))
AnnotationAssertion(rdfs:comment :Vector
  "Vector is derived from DataThing.
  An instance of Vector has the following:
    I
    J
    K.
 
  The I, J, and K elements represent the usual i, j, and k
  components of a 3D vector.")
  ...

*/

void xmlSchemaOwlPrinter::printOwlDocumentation( /* ARGUMENTS              */
 XmlDocumentation * doc,                         /* documentation to print */
 FILE * outFile)                                 /* OWL file to print in   */
{
  int n;
  char * tex;

  tex = doc->text;
  if (tex == 0)
    return;
  for (n = (strlen(tex) - 1); // remove trailing white space
       ((tex[n] == 10) || (tex[n] == 13) ||
	(tex[n] == 32) || (tex[n] ==  9)); n--);
  tex[n+1] = 0;
  for (n = 0; ((tex[n] == 10) || (tex[n] == 13) ||      // skip initial
	       (tex[n] == 32) || (tex[n] ==  9)); n++); // white space
  while (tex[n])
    {
      if (tex[n] == ' ')
	{
	  if ((strncmp(tex+n, "          Name", 14) == 0) &&
	      ((tex[n+14] == 10) || (tex[n+14] == 13)))
	    {
	      n += 15;
	      for ( ; ((tex[n] == 10) || (tex[n] == 13)); n++);
	    }
	  else if ((strncmp(tex+n, "          Name (inherited)", 26) == 0) &&
	      ((tex[n+26] == 10) || (tex[n+26] == 13)))
	    {
	      n += 27;
	      for ( ; ((tex[n] == 10) || (tex[n] == 13)); n++);
	    }
	  else if (strncmp(tex+n, "        ", 8) == 0)
	    n += 6;
	  else
	    fputc(tex[n++], outFile);
	}
      else if ((tex[n] == 10) || (tex[n] == 13))
	{
	  for (n++; ((tex[n] == 10) || (tex[n] == 13)); n++);
	  fputc('\n', outFile);
	}
      else if (tex[n] == 'T')
	{
	  if (strncmp(tex+n, "Type", 4) == 0)
	    n += 4;
	  else
	    fputc(tex[n++], outFile);
	}
      else if (tex[n] == 'N')
	{
	  if (strncmp(tex+n, "Name (IDREF)", 12) == 0)
	    n += 12;
	  else if (strncmp(tex+n, "Name (IDREF, ", 13) == 0)
	    {
	      fprintf(outFile, " (");
	      n += 13;
	    }
	  else
	    fputc(tex[n++], outFile);
	}
      else if (tex[n] == 'f')
	{
	  if (strncmp(tex+n, "following elements", 18) == 0)
	    {
	      fprintf(outFile, "following");
	      n += 18;
	    }
	  else
	    fputc(tex[n++], outFile);
	}
      else
	{
	  fputc(tex[n++], outFile);
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocal

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlChoSeqItem

When this is called, className is the name of the class containing the
element.

This skips elements named "Name" because XML schema requires an
explicit name but OWL does not. In OWL, a name is assigned when an
instance is created. In kitting.xsd, the two base types, DataThingType
and SolidObjectType, both have a Name element, so that all complex types
have it. By removing the Name element from those two types, it is
removed from all complex types.

*/

void xmlSchemaOwlPrinter::printOwlElementLocal( /* ARGUMENTS            */
 XmlElementLocal * element,                     /* element to print     */
 FILE * outFile)                                /* OWL file to print in */
{
  std::list<XmlIdConstraint *>::iterator ator;

  if (element->ref)
    {
      fprintf(stderr, "cannot handle ref\n");
      exit(1);
    }
  if (!element->name)
    {
      fprintf(stderr, "element must have name\n");
      exit(1);
    }
  if (!element->typ)
    {
      fprintf(stderr, "element must have type\n");
      exit(1);
    }
  if (element->form)
    fprintf(stderr, "ignoring form\n");
  if (element->nillable)
    fprintf(stderr, "ignoring nillable\n");
  if (element->id)
    fprintf(stderr, "ignoring id\n");
  if (element->defalt)
    {
      if (element->fixed)
	{
	  fprintf(stderr, "element %s has default and fixed\n", element->name);
	  exit(1);
	}
      fprintf(stderr, "ignoring defalt\n");
    }
  if (element->fixed)
    fprintf(stderr, "ignoring fixed\n");
  if (element->typeDef)
    {
      fprintf(stderr, "cannot handle typeDef in a local element\n");
      exit(1);
    }
  if (element->frontNote)
    printOwlAnnotation(element->frontNote, outFile);
  if (element->idConstraints)
    {
      for (ator = element->idConstraints->begin();
	   ator != element->idConstraints->end(); ator++)
	printOwlIdConstraint(*ator, element->name, outFile);
    }
  if (findComplexClass(element->newTyp))
    {
      printOwlElementLocalComplex(element, outFile);
    }
  else if (findSimpleClass(element->newTyp))
    { 
      printOwlElementLocalData(element, outFile);
    }
  else if (element->typPrefix &&
	   (strcmp(element->typPrefix, XmlCppBase::wg3Prefix) == 0))
    { // deal with a built-in XML data type
      if (strcmp(element->newTyp, "IDREF") == 0)
	{ // deal with finding types for references
	  printOwlElementLocalIDREF(element, outFile);
	}
      else if (strcmp(element->name, "Name"))
	{ // skip elements named Name
	  printOwlElementLocalBuiltIn(element, outFile);
	}
    }
  else
    {
      fprintf(stderr, "unknown element type in printOwlElementLocal\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalBuiltIn

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This handles local elements of XML built-in data type other than IDREF.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalBuiltIn( /* ARGUMENTS          */
 XmlElementLocal * element,             /* element of built-in type to print */
 FILE * outFile)                        /* OWL file to print in              */
{
  char hasName[NAMESIZE];

  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  fprintf(outFile, "\nDeclaration(DataProperty(:%s))\n", hasName);
  fprintf(outFile, "DataPropertyDomain(:%s :%s)\n", hasName, className);
  fprintf(outFile, "DataPropertyRange(:%s xsd:%s)\n",
	  hasName, element->newTyp);
  if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
    { // zero or one value, so is functional
      fprintf(outFile, "FunctionalDataProperty(:%s)\n", hasName);
      if (element->minOccurs != 0)
	{
	  fprintf(outFile,
		  "EquivalentClasses(:%s ObjectIntersectionOf(\n",
		  className);
	  fprintf(outFile,
		  "  DataSomeValuesFrom(:%s xsd:%s)\n",
		  hasName, element->newTyp);
	  fprintf(outFile,
		  "  DataAllValuesFrom (:%s xsd:%s)))\n",
		  hasName, element->newTyp);
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalComplex

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This handles local elements of complex type.

1. It always prints a "has" function:
   Declaration(ObjectProperty
   ObjectPropertyDomain
   ObjectPropertyRange

2. If maxOccurs is 1 or is omitted:
2A. This also prints FunctionalObjectProperty
2B. If minOccurs is not zero, this also prints EquivalentClasses.

3. If the type of the class and the type of the element are both complex:
3A. A "hadBy" function is also printed with:
   Declaration(ObjectProperty
   ObjectPropertyDomain
   ObjectPropertyRange
3B. An InverseObjectProperties is printed by for the "has" and
    "hadBy" functions.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalComplex( /* ARGUMENTS          */
 XmlElementLocal * element,              /* element of complex type to print */
 FILE * outFile)                         /* OWL file to print in             */
{
  char hasName[NAMESIZE];
  char classType[NAMESIZE];
  char hadByName[NAMESIZE];

  deTypeName(element->newTyp, nameBuffer);
  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  fprintf(outFile, "\nDeclaration(ObjectProperty(:%s))\n", hasName);
  fprintf(outFile, "ObjectPropertyDomain(:%s :%s)\n", hasName, className);
  fprintf(outFile, "ObjectPropertyRange(:%s :%s)\n", hasName, nameBuffer);
  fprintf(outFile, "InverseFunctionalObjectProperty(:%s)\n", hasName);
  if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
    { // zero or one value, so is functional
      fprintf(outFile, "FunctionalObjectProperty(:%s)\n", hasName);
      if (element->minOccurs != 0)
	{
	  fprintf(outFile,
		  "EquivalentClasses(:%s ObjectIntersectionOf(\n",
		  className);
	  fprintf(outFile,
		  "  ObjectSomeValuesFrom(:%s :%s)\n",
		  hasName, nameBuffer);
	  fprintf(outFile,
		  "  ObjectAllValuesFrom (:%s :%s)))\n",
		  hasName, nameBuffer);
	}
    }
  // If classType and element->newTyp are both complex types, do hadBy
  snprintf(classType, NAMESIZE, "%sType", className);
  if (findComplexClass(classType) && findComplexClass(element->newTyp))
    {
      snprintf(hadByName, NAMESIZE, "hadBy%s_%s", element->name, className);
      fprintf(outFile, "\nDeclaration(ObjectProperty(:%s))\n", hadByName);
      fprintf(outFile, "InverseObjectProperties(:%s\n", hasName);
      fprintf(outFile, "                        :%s)\n", hadByName);
      fprintf(outFile, "ObjectPropertyDomain(:%s :%s)\n", hadByName,nameBuffer);
      fprintf(outFile, "ObjectPropertyRange(:%s :%s)\n", hadByName, className);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalData

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This handles local elements of user-defined data type.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalData( /* ARGUMENTS             */
 XmlElementLocal * element,             /* element of built-in type to print */
 FILE * outFile)                        /* OWL file to print in              */
{
  char hasName[NAMESIZE];

  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  deTypeName(element->newTyp, nameBuffer);
  nameBuffer[0] = tolower(nameBuffer[0]);
  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  fprintf(outFile, "\nDeclaration(DataProperty(:%s))\n", hasName);
  fprintf(outFile, "DataPropertyDomain(:%s :%s)\n", hasName, className);
  fprintf(outFile, "DataPropertyRange(:%s :%s)\n", hasName, nameBuffer);
  if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
    { // has zero or one value, so is functional
      fprintf(outFile, "FunctionalDataProperty(:%s)\n", hasName);
      if (element->minOccurs != 0)
	{
	  fprintf(outFile,
		  "EquivalentClasses(:%s ObjectIntersectionOf(\n",
		  className);
	  fprintf(outFile,
		  "  DataSomeValuesFrom(:%s :%s)\n",
		  hasName, nameBuffer);
	  fprintf(outFile,
		  "  DataAllValuesFrom (:%s :%s)))\n",
		  hasName, nameBuffer);
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalIDREF

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This is called when the newTyp of the element is IDREF. In this case,
the element must have an appinfo in its frontNote whose text is the name
of the type that is being referenced.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalIDREF( /* ARGUMENTS            */
 XmlElementLocal * element,       /* element whose type is xs:IDREF to print */
 FILE * outFile)                  /* OWL file to print in                    */
{
  XmlAppinfo * appinfo;
  char hasName[NAMESIZE];

  if (element->frontNote &&
      element->frontNote->content &&
      (appinfo =
       dynamic_cast<XmlAppinfo *>(element->frontNote->content->front())))
    {
      deTypeName(appinfo->text, nameBuffer);
      deNameName(element->name, otherName);
      snprintf(hasName, NAMESIZE, "has%s_%s", className, otherName);
      fprintf(outFile, "\nDeclaration(ObjectProperty(:%s))\n", hasName);
      fprintf(outFile, "ObjectPropertyDomain(:%s :%s)\n", hasName, className);
      fprintf(outFile, "ObjectPropertyRange(:%s :%s)\n", hasName, nameBuffer);
      if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
	{ // zero or one value, so is functional
	  fprintf(outFile, "FunctionalObjectProperty(:%s)\n", hasName);
	  if (element->minOccurs != 0)
	    {
	      fprintf(outFile,
		      "EquivalentClasses(:%s ObjectIntersectionOf(\n",
		      className);
	      fprintf(outFile,
		      "  ObjectSomeValuesFrom(:%s :%s)\n",
		      hasName, nameBuffer);
	      fprintf(outFile,
		      "  ObjectAllValuesFrom (:%s :%s)))\n",
		      hasName, nameBuffer);
	    }
	}
    }
  else
    {
      fprintf(stderr,
	      "element of type IDREF must use appinfo for type\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementRefable

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlClassFile

The root element of an XML schema (which, by convention, is the first
thing in the schema file after the header) is an XmlElementRefable.
This function does not print anything for the root element because the
OWL classes do not have a root element. However, any annotations
following the root element are the backNotes of the root element and
should be put into the OWL file. Hence, the printOwl function prints
them.

There should be no other XmlElementRefables in the schema. If there is one,
an error message will be printed in saveOwlSchemaContent2.

This also writes OWL HasKey declarations for any XML schema Keys in
the element Refable. The Key must:
1. have a selector with an xpath of the form ".//XXX"
2. have its fields have xpaths of the form "YYY"
3. have YYY be an element of the XXXType.

*/

void xmlSchemaOwlPrinter::printOwlElementRefable(/* ARGUMENTS                */
 XmlElementRefable * element,                    /* element refable to print */
 FILE * outFile)                                 /* OWL file to print in     */
{
  std::list<XmlAnnotation *>::iterator iter;
  std::list<XmlIdConstraint *>::iterator ator;

  if (element->backNotes)
    {
      for (iter = element->backNotes->begin();
	   iter != element->backNotes->end(); iter++)
	printOwlAnnotation(*iter, outFile);
    }
  if (element->idConstraints)
    {
      fprintf(outFile, "\n\n");
      for (ator = element->idConstraints->begin();
	   ator != element->idConstraints->end(); ator++)
	printOwlIdConstraint(*ator, 0, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlEnumeration

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

*/

void xmlSchemaOwlPrinter::printOwlEnumeration( /* ARGUMENTS            */
 XmlEnumeration * enumeration,                 /* enumeration to print */
 FILE * outFile)                               /* OWL file to print in */
{
  fprintf(outFile, "\"%s\"", enumeration->value);
  if (enumeration->id)
    {
      fprintf(stderr, "Enumeration must not have an id but does\n");
      exit(1);
    }
  if (enumeration->frontNote)
    {
      className[0] = 0;
      printOwlAnnotation(enumeration->frontNote, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlIdConstraint

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementRefable

This prints only XmlKey.

If elementName is 0, that means the constraint is in the top level element.
In this case, the selector xpath must be of the form .//XXX, where XXXType
is the type of the XXX element. Also, each field xpath must be only an
element name. For example:

    <xs:key name="KitTrayKey">
      <xs:selector xpath=".//KitTray"/>
      <xs:field xpath="SkuName"/>
      <xs:field xpath="SerialNumber"/>
    </xs:key>

If elementName is not 0, that means the constraint is not in the top level
element. In this case, the selector xpath must be ".". Also, each field
xpath must be only an element name. For example:

    <xs:key name="KitTrayKey">
      <xs:selector xpath="."/>
      <xs:field xpath="SkuName"/>
      <xs:field xpath="SerialNumber"/>
    </xs:key>

*/

void xmlSchemaOwlPrinter::printOwlIdConstraint( /* ARGUMENTS                 */
 XmlIdConstraint * constraint,      /* constraint to print                   */
 char * elementName,                /* element name, 0 for top level element */
 FILE * outFile)                    /* OWL file to print in                  */
{
  XmlKey * ky;
  char * haser;
  std::list<XmlField *>::iterator iter;
  char fieldName[NAMESIZE];
  int length;

  if ((ky = dynamic_cast<XmlKey *>(constraint)))
    {
      if (elementName)
	{
	  if ((ky->selector->xpath[0] != '.') || (ky->selector->xpath[1] != 0))
	    {
	      fprintf(stderr, "key selector must be \".\"\n");
	      exit(1);
	    }
	  haser = elementName;
	}
      else
	{
	  haser = ky->selector->xpath;
	  if ((haser[0] != '.') ||
	      (haser[1] != '/') ||
	      (haser[2] != '/'))
	    {
	      fprintf(stderr, "key selector must start with .//\n");
	      exit(1);
	    }
	  haser = (haser + 3);
	}
      fprintf(outFile, "\nHasKey(:%s", haser);
      for (iter = ky->fields->begin(); iter != ky->fields->end(); iter++)
	{ // if the field xpath ends in Name, get rid of Name
	  strncpy(fieldName, (*iter)->xpath, NAMESIZE);
	  length = strlen(fieldName) - 4;
	  if ((length > 0) && (strcmp((fieldName + length), "Name") == 0))
	    fieldName[length] = 0;
	  fprintf(outFile, " (:has%s_%s)", haser, fieldName);
	} 
      fprintf(outFile, ")\n");
    }
  else
    {
      fprintf(stderr, "ignoring identity constraint\n");
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMaxExclusive

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

*/

void xmlSchemaOwlPrinter::printOwlMaxExclusive( /* ARGUMENTS             */
 XmlMaxExclusive * maxExclusive,                /* maxExclusive to print */
 FILE * outFile)                                /* OWL file to print in  */
{
  fprintf(outFile, "xsd:maxExclusive \"%s\"^^xsd:%s",
	  maxExclusive->value, className);
  if (maxExclusive->fixed)
    {
      fprintf(stderr, "Cannot handle fixed MaxExclusive\n");
      exit(1);
    }
  if (maxExclusive->id)
    {
      fprintf(stderr, "MaxExclusive must not have an id but does\n");
      exit(1);
    }
  if (maxExclusive->note)
    {
      className[0] = 0;
      printOwlAnnotation(maxExclusive->note, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMaxInclusive

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

*/

void xmlSchemaOwlPrinter::printOwlMaxInclusive( /* ARGUMENTS             */
 XmlMaxInclusive * maxInclusive,                /* maxInclusive to print */
 FILE * outFile)                                /* OWL file to print in  */
{
  fprintf(outFile, "xsd:maxInclusive \"%s\"^^xsd:%s",
	  maxInclusive->value, className);
  if (maxInclusive->fixed)
    {
      fprintf(stderr, "Cannot handle fixed MaxInclusive\n");
      exit(1);
    }
  if (maxInclusive->id)
    {
      fprintf(stderr, "MaxInclusive must not have an id but does\n");
      exit(1);
    }
  if (maxInclusive->note)
    {
      className[0] = 0;
      printOwlAnnotation(maxInclusive->note, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMaxLength

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

This prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlMaxLength( /* ARGUMENTS            */
 XmlMaxLength * maxLength,                   /* maxLength to print   */
 FILE * outFile)                             /* OWL file to print in */
{
  fprintf(stderr, "cannot handle maxLength\n");
  exit(1);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMinExclusive

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

*/

void xmlSchemaOwlPrinter::printOwlMinExclusive( /* ARGUMENTS             */
 XmlMinExclusive * minExclusive,                /* minExclusive to print */
 FILE * outFile)                                /* OWL file to print in  */
{
  fprintf(outFile, "xsd:minExclusive \"%s\"^^xsd:%s",
	  minExclusive->value, className);
  if (minExclusive->fixed)
    {
      fprintf(stderr, "Cannot handle fixed MinExclusive\n");
      exit(1);
    }
  if (minExclusive->id)
    {
      fprintf(stderr, "MinExclusive must not have an id but does\n");
      exit(1);
    }
  if (minExclusive->note)
    {
      className[0] = 0;
      printOwlAnnotation(minExclusive->note, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMinInclusive

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

*/

void xmlSchemaOwlPrinter::printOwlMinInclusive( /* ARGUMENTS             */
 XmlMinInclusive * minInclusive,                /* minInclusive to print */
 FILE * outFile)                                /* OWL file to print in  */
{
  fprintf(outFile, "xsd:minInclusive \"%s\"^^xsd:%s",
	  minInclusive->value, className);
  if (minInclusive->fixed)
    {
      fprintf(stderr, "Cannot handle fixed MinInclusive\n");
      exit(1);
    }
  if (minInclusive->id)
    {
      fprintf(stderr, "MinInclusive must not have an id but does\n");
      exit(1);
    }
  if (minInclusive->note)
    {
      className[0] = 0;
      printOwlAnnotation(minInclusive->note, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMinLength

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

This prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlMinLength( /* ARGUMENTS            */
 XmlMinLength * minLength,                   /* minLength to print   */
 FILE * outFile)                             /* OWL file to print in */
{
  fprintf(stderr, "cannot handle minLength\n");
  exit(1);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlOtherContent

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlComplexTypeItem

*/

void xmlSchemaOwlPrinter::printOwlOtherContent( /* ARGUMENTS              */
 XmlOtherContent * otherCont,                   /* other content to print */
 FILE * outFile)                                /* OWL file to print in   */
{
  std::list<XmlAttributor *>::iterator iter;

  if (otherCont->base)
    printOwlOtherContentBase(otherCont->base, outFile);
  if (otherCont->attribs)
    {
      fprintf(stderr, "cannot handle attributes in printOwlOtherContent\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlOtherContentBase

Returned Value: none

Called By:
  xmlSchemaOwlPrinter::printOwlComplexExtension
  xmlSchemaOwlPrinter::printOwlOtherContent

*/

void xmlSchemaOwlPrinter::printOwlOtherContentBase( /* ARGUMENTS              */
 XmlOtherContentBase * base,                   /* other content base to print */
 FILE * outFile)                               /* OWL file to print in        */
{
  XmlSequence * sequence;
  XmlChoice * choice;

  if ((sequence = dynamic_cast<XmlSequence *>(base)))
    printOwlSequence(sequence, outFile);
  else if ((choice = dynamic_cast<XmlChoice *>(base)))
    {
      fprintf(stderr, "cannot handle XmlChoice\n");
      exit(1);
    }
  else
    {
      fprintf(stderr, "Unknown type in printOwlOtherContentBase\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlPattern

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

This prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlPattern( /* ARGUMENTS            */
 XmlPattern * pattern,                     /* pattern to print     */
 FILE * outFile)                           /* OWL file to print in */
{
  fprintf(stderr, "cannot handle pattern\n");
  exit(1);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlRestriction

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlSimpleRestriction

*/

void xmlSchemaOwlPrinter::printOwlRestriction( /* ARGUMENTS            */
 XmlRestrictionType * restrict,                /* restriction to print */
 FILE * outFile)                               /* OWL file to print in */
{
  XmlEnumeration * enumeration;
  XmlMaxExclusive * maxExclusive;
  XmlMaxInclusive * maxInclusive;
  XmlMaxLength * maxLength;
  XmlMinExclusive * minExclusive;
  XmlMinInclusive * minInclusive;
  XmlMinLength * minLength;
  XmlPattern * pattern;
  
  if ((enumeration = dynamic_cast<XmlEnumeration *>(restrict)))
    printOwlEnumeration(enumeration, outFile);
  else if ((maxExclusive = dynamic_cast<XmlMaxExclusive *>(restrict)))
    printOwlMaxExclusive(maxExclusive, outFile);
  else if ((maxInclusive = dynamic_cast<XmlMaxInclusive *>(restrict)))
    printOwlMaxInclusive(maxInclusive, outFile);
  else if ((maxLength = dynamic_cast<XmlMaxLength *>(restrict)))
    printOwlMaxLength(maxLength, outFile);
  else if ((minExclusive = dynamic_cast<XmlMinExclusive *>(restrict)))
    printOwlMinExclusive(minExclusive, outFile);
  else if ((minInclusive = dynamic_cast<XmlMinInclusive *>(restrict)))
    printOwlMinInclusive(minInclusive, outFile);
  else if ((minLength = dynamic_cast<XmlMinLength *>(restrict)))
    printOwlMinLength(minLength, outFile);
  else if ((pattern = dynamic_cast<XmlPattern *>(restrict)))
    printOwlPattern(pattern, outFile);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSchemaContent1

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlClassFile

*/

void xmlSchemaOwlPrinter::printOwlSchemaContent1( /* ARGUMENTS              */
XmlSchemaContent1 * content1,                     /* content1 item to print */
 FILE * outFile)                                  /* OWL file to print in   */
{
  XmlAnnotation * annotation;
  XmlInclude * included;

  if ((annotation = dynamic_cast<XmlAnnotation *>(content1)))
    printOwlAnnotation(annotation, outFile);
  else if ((included = dynamic_cast<XmlInclude *>(content1)))
    {
      fprintf(stderr, "cannot handle included file\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSchemaHeader

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlClassFile

*/

void xmlSchemaOwlPrinter::printOwlSchemaHeader( /* ARGUMENTS              */
 XmlSchemaHeader * header,                      /* schema header to print */
 char * URL,                                    /* URL to use in header   */
 FILE * outFile)                                /* OWL file to print in   */
{
    fprintf(outFile,
"Prefix(xsd:=<http://www.w3.org/2001/XMLSchema#>)\n"
"Prefix(owl:=<http://www.w3.org/2002/07/owl#>)\n"
"Prefix(xml:=<http://www.w3.org/XML/1998/namespace>)\n"
"Prefix(rdf:=<http://www.w3.org/1999/02/22-rdf-syntax-ns#>)\n"
"Prefix(rdfs:=<http://www.w3.org/2000/01/rdf-schema#>)\n"
"Prefix(:=<%s#>)\n"
"\n"
"Ontology(<%s>\n", URL, URL);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSequence

Returned Value: none

Called By:
  xmlSchemaOwlPrinter::printOwlChoSeqItem
  xmlSchemaOwlPrinter::printOwlOtherContentBase

*/

void xmlSchemaOwlPrinter::printOwlSequence( /* ARGUMENTS            */
 XmlSequence * sequence,                    /* sequence to print    */
 FILE * outFile)                            /* OWL file to print in */
{
  std::list<XmlChoSeqItem *>::iterator iter;

  if (sequence->id)
    {
      fprintf(stderr, "sequence must not have an id but does\n");
      exit(1);
    }
  if ((sequence->minOccurs > -1) || (sequence->maxOccurs > -1))
    {
      fprintf(stderr, "cannot handle maxOccurs or minOccurs for sequence\n");
      exit(1);
    }
  if (sequence->frontNote)
    printOwlAnnotation(sequence->frontNote, outFile);
  if (sequence->items)
    {
      for (iter = sequence->items->begin();
	   iter != sequence->items->end(); iter++)
	printOwlChoSeqItem(*iter, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSimpleList

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlSimpleType

This prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlSimpleList( /* ARGUMENTS            */
 XmlSimpleList * aList,                       /* list to print        */
 FILE * outFile)                              /* OWL file to print in */
{
  fprintf(stderr, "cannot handle simpleList\n");
  exit(1);
}    

/********************************************************************/

/*  xmlSchemaOwlPrinter::printOwlSimpleRestriction

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlSimpleType

Converting an XML restriction of a simpleType into an OWL datatype is
somewhat complex.

For enumerations, the OWL version does not mention the base type and
uses DataOneOf. To see if DataOneOf can be used, this checks whether
all the XML restrictions are XML enumerations. In that case, the 
XML base type is ignored.

*/

void xmlSchemaOwlPrinter::printOwlSimpleRestriction( /* ARGUMENTS            */
 XmlSimpleRestriction * restrict,                    /* restriction to print */
 FILE * outFile)                                     /* OWL file to print in */

{
  bool allEnums = false;
  std::list<XmlRestrictionType *>::iterator iter;

  if (restrict->restrictions && restrict->restrictions->size())
    {
      allEnums = true;
      for (iter = restrict->restrictions->begin();
	   iter != restrict->restrictions->end(); iter++)
	{
	  if (dynamic_cast<XmlEnumeration *>(*iter) == 0)
	    {
	      allEnums = false;
	      break;
	    }
	}
    }
  if (allEnums)
    {
      fprintf(outFile, "\n");
      fprintf(outFile, "  DataOneOf(");
      for (iter = restrict->restrictions->begin(); true ;)
	{
	  printOwlRestriction(*iter, outFile);
	  iter++;
	  if (iter == restrict->restrictions->end())
	    break;
	  else
	    fprintf(outFile, " ");
	}
      fprintf(outFile, ")");
    }
  else if ((restrict->basePrefix == 0) ||
           (strcmp(XmlCppBase::wg3Prefix, restrict->basePrefix)))
    {
      fprintf(stderr, "Simple restriction must restrict XML primitive type\n");
      exit(1);
    }
  else if (strcmp(restrict->base, "decimal") == 0) // add other number types
    {
      fprintf(outFile, "\n");
      for (iter = restrict->restrictions->begin();
	   iter != restrict->restrictions->end(); iter++)
	{
	  strcpy(className, restrict->base);
	  if ((dynamic_cast<XmlMaxInclusive *>(*iter)) ||
	      (dynamic_cast<XmlMaxExclusive *>(*iter)) ||
	      (dynamic_cast<XmlMinInclusive *>(*iter)) ||
	      (dynamic_cast<XmlMinExclusive *>(*iter)))
	    {
	      fprintf(outFile, "  DatatypeRestriction(xsd:%s ",
		      restrict->base);
	      printOwlRestriction(*iter, outFile);
	      fprintf(outFile, ")");
	    }
	  else
	    {
	      fprintf(stderr, "Cannot handle this restriction of a number\n");
	      fprintf(stderr, "Can handle max/min restrictions of numbers\n");
	    }
	}
    }
  else
    {
      fprintf(stderr, "Cannot handle this simple restriction\n");
      fprintf(stderr, "Can handle enumerations and max/min of numbers\n"); 
      exit(1);
    }
  if (restrict->id)
    {
      fprintf(stderr, "SimpleRestriction must not have an id but does\n");
      exit(1);
    }
  if (restrict->frontNote)
    {
      className[0] = 0;
      printOwlAnnotation(restrict->frontNote, outFile);
    }
  if (restrict->aSimple)
    {
      fprintf(stderr, "SimpleType must be at top level but is not\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSimpleType

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlClassFile

*/

void xmlSchemaOwlPrinter::printOwlSimpleType( /* ARGUMENTS            */
 XmlSimpleType * simple,                      /* simple type to print */
 FILE * outFile)                              /* OWL file to print in */
{
  std::list<XmlAnnotation *>::iterator iter;
  XmlSimpleList * aList;
  XmlSimpleRestriction * restrict;
  

  if (simple->name)
    {
      deTypeName(simple->name, nameBuffer);
      nameBuffer[0] = tolower(nameBuffer[0]);
      fprintf(outFile, "\nDatatypeDefinition(:%s ", nameBuffer);
      strncpy(className, nameBuffer, NAMESIZE);
    }
  else
    {
      fprintf(stderr, "SimpleType must have a name but does not\n");
      exit(1);
    }
  if ((aList = dynamic_cast<XmlSimpleList *>(simple->item)))
    printOwlSimpleList(aList, outFile);
  else if ((restrict = dynamic_cast<XmlSimpleRestriction *>(simple->item)))
    printOwlSimpleRestriction(restrict, outFile);
  else
    {
      fprintf(stderr, "unknown simple item in printOwlSimpleType\n");
      exit(1);
    }
  fprintf(outFile, ")\n");
  if (simple->frontNote)
    printOwlAnnotation(simple->frontNote, outFile);
  if (simple->backNotes)
    {
      for (iter = simple->backNotes->begin();
	   iter != simple->backNotes->end(); iter++)
	printOwlAnnotation(*iter, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::saveOwlSchemaContent2

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlClassFile

*/

void xmlSchemaOwlPrinter::saveOwlSchemaContent2( /* ARGUMENTS             */
XmlSchemaContent2 * content2)                    /* content2 item to save */
{
  XmlComplexType * complx;
  XmlSimpleType * simple;
  XmlElementRefable * top;

  if ((complx = dynamic_cast<XmlComplexType *>(content2)))
    complexTypes.push_back(complx);
  else if ((simple = dynamic_cast<XmlSimpleType *>(content2)))
    simpleTypes.push_back(simple);
  else if ((top = dynamic_cast<XmlElementRefable *>(content2)))
    {
      if (topElement)
	{
	  fprintf(stderr, "cannot handle more than one top-level element\n");
	  exit(1);
	}
      else
	topElement = top;
    }
  else
    {
      fprintf(stderr, "cannot handle type in saveOwlSchemaContent2\n");
      exit(1);
    }
}

/********************************************************************/

xmlSchemaOwlPrinter::xmlSchemaOwlPrinter() /* NO ARGUMENTS */
{
  className[0] = 0;
  nameBuffer[0] = 0;
}

/********************************************************************/

xmlSchemaOwlPrinter::~xmlSchemaOwlPrinter() {}

/********************************************************************/

/* main

The first argument (argv[1]) is the name of an XML schema file,
for example, kitting.xsd

The second argument (argv[2]) is the URL used in the OWL file,
for example, http://www.nist.gov/el/ontologies/kittingClasses.owl

*/

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  xmlSchemaOwlPrinter owler;
  char * outFileName;
  FILE * outFile;
  int nameLength;

  if (argc != 3)
    {
      fprintf(stderr, "Usage: %s <schema file name> <URL>\n", argv[0]);
      fprintf(stderr, "example: %s kit.xsd http://www.nist.gov/kit.owl\n",
	      argv[0]);
      exit(1);
    }
  yyin = fopen(argv[1], "r");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
  XmlCppBase::wg3Prefix = 0;

  yyparse();
  fclose(yyin);
  
  owler.buildClasses(xmlSchemaFile->schema);
  owler.enterKids();
  owler.buildElementInfo();
  nameLength = strlen(argv[1]);
  outFileName = new char[nameLength + 2];
  if (strcmp((argv[1] + nameLength - 4), ".xsd"))
    {
      fprintf(stderr, "file name %s must end in .xsd\n", argv[1]);
      exit(1);
    }
  snprintf(outFileName, (nameLength + 1), "%s", argv[1]);
  snprintf((outFileName + nameLength - 3), 4, "owl");
  outFile = fopen(outFileName, "w");
  owler.printOwlClassFile(xmlSchemaFile->schema, argv[2], outFile);
  fclose(outFile);
  return 0;
}

/********************************************************************/
