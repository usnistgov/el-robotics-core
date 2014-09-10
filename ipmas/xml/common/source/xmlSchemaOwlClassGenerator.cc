/*

This reads an XML schema file (and any included schema files) and, for
each XML schema file, writes an equivalent OWL file defining classes in
OWL functional syntax. The usage of the XML schema language for schema
files this can handle is constrained as follows.

XML Schema Usage Rules
----------------------

1. The names of all types in the XML schema must end with "Type".

2. An XML complexType is translated into an OWL class. The OWL
class name is the same as the XML class name with "Type" removed
from the end.

3. An XML simpleType is translated into an OWL DatatypeDefinition.

4. In translating complex types, this skips elements named "Name".
XML schema requires an explicit name in the class model in
order to have a name for an instance but OWL does not. In OWL, a name
is assigned when an instance is created. In kittingWorkstation.xsd,
for example, the two base types, DataThingType and SolidObjectType,
both have a Name element, so that all complex types have it.

5. An annotation-documentation appearing almost anywhere in the schema
is translated into an OWL AnnotationAssertion. However, the only
places annotation-documentations are expected are (1) immediately
following the header of the OWL class file, and (2) immediately
following the beginning of a complexType definition.

6. An annotation-documentation immediately following the beginning of
a complexType definition in the XML schema is translated into an OWL
AnnotationAssertion immediately following a class declaration. In order
to translate well, the annotation-documentation must be highly stylized.
See the documentation of printOwlDocumentation for details.

7. An annotation-documentation immediately following the beginning of
a simpleType definition in the XML schema is translated into an OWL
AnnotationAssertion immediately following a DatatypeDefinition.

8. An annotation-documentation immediately following an element in the
XML schema is translated into an OWL AnnotationAssertion immediately
following a Declaration(ObjectProperty or a Declaration(DataProperty.
However, because of the stylized translation of annotation-documentation,
which is intended for documentation of types rather than elements,
it is better if elements do not have annotation-documentation.

9. The XML schema must not have any XML Attributes (i.e., only elements
are used).

10. The XML schema must be in venetian blind format so that all type
definitions are at the top level.

11. In an XML key:
A. The key must be in an XmlElementRefable. In other words, the element
   must be at the top level of the schema.
B. The field xpaths must be only an element name. See example in
   documentation of printOwlIdConstraint.
C. The selector xpath must be ".".

12. Each element of type IDREF must end in "Name" and must be followed
by an annotation-appinfo. Such elements must be pointers to instances
of some complex type whose type name is the data in the appinfo. See the
documentation of printOwlElementLocalIDREF for details.

13. Because each OWL output file requires a separate OWL prefix but the XML
schema file(s) share a single XML prefix, each XML file must specify the
OWL prefix to use. The prefix is specified in a documentation node following
the XML schema header. The documentation node must be of the form:
<documentation>owlPrefix=XXX</documentation>
where XXX is the prefix. The documentation node, as always, must be inside
an annotation node. Other documentation nodes may be inside the same
annotation nodes.

14. The first bit of content (after the header and documentation) in
the top-level schema may be a global element (i.e. an
XmlElementRefable). This should be the root element. Nothing will be
generated from it. Other global elements in the top-level schema or
any included schemas may be used to contain keys but may not be used
via "ref". Thus, the only effect a global element can have anywhere
but at the beginning of the top-level schema is to carry a key.

15. A somewhat obscure feature of XML schema language is that many
items may have an id attribute. These id attributes are allowed in the
input schema. Any id attributes in the schema are not translated, but
an "id ignored" message is printed to stderr. OWL has nothing equivalent
to the id attribute.

Limitations
-----------

This does not handle the following XML schema constructs:
  attribute
  choice
  complex restriction
  fixed
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

Dealing with Keys
-----------------

The handling of XSDL keys is somewhat artificial because XSDL keys are
element-based and apply only to specified instances of a type, while
OWL hasKey statements are type-based and apply to all instances of a
type.

To make an OWL key that constrains an OWL class derived from an XML
type, a top-level element (an XmlElementRefable) using the type to be
constrained must be put into the schema in which the type is defined.
The name of the element is irrelevant because the element must not be
used elsewhere in the schema. The element is an orphan in the schema;
this is allowed in XSDL.

The way the OWL constraint is derived from the XML constraint is described
in the documentation of printOwlIdConstraint.

Example: The following element in the XML kittingWorkstation schema
(which uses the prefix ktw) that includes the roboticManufacturing
schema (which uses the prefix rm) results in the OWL key constraint shown
after that.

  <xs:element name="KitTray"
    type="KitTrayType">

    <xs:key name="KitTrayKey">
      <xs:selector xpath="."/>
      <xs:field xpath="SkuName"/>
      <xs:field xpath="SerialNumber"/>
    </xs:key>
  </xs:element>

HasKey(ktw:KitTray (rm:hasSkuObject_Sku) (ktw:hasKitTray_SerialNumber))

Dealing with Includes
---------------------

In both XSDL and OWL, dealing with includes entails prefix definitions
and include declarations. OWL uses "import" rather than "include", but
this section uses "include" for both.

In XSDL, as long as all directly or indirectly included schema files
use the same namespace (or no namespace), only one xmlns prefix
definition is needed to cover all the schema files. In OWL, a prefix
definition is needed for each directly or indirectly included OWL file.

In both XSDL and OWL, an include declaration is needed for each directly
included subordinate, and no include declaration is needed for indirectly
included subordinates (but it is not an error if indirectly included
subordinates are also directly included).

Dealing with Prefixes
---------------------

The OWL Spec (section 3.7 Functional-Style Syntax) requires a prefix
to be associated with each ontology (and each valid OWL file is an
ontology). The empty prefix (just a colon) may be used. The prefixes
in files connected by import statements must all be different. For
convenience, the empty prefix is reserved for OWL instance files.
Hence, every OWL class file must have a prefix. Each OWL instance file
must import one class file. That class file may import other OWL class
files. To specify the prefixes, each XML schema file must provide one
as described earlier.

Dealing with Multiple XML Schema Input Files
--------------------------------------------

An instance of xmlSchemaOwlPrinter is created for each XML schema
input file. A hierarchy of xmlSchemaOwlPrinters is created using the
"subordinates" data member of the xmlSchemaOwlPrinter class. The
included files of each XML schema correspond to its subordinates,
except that if a file is included in more that place, the corresponding
xmlSchemaOwlPrinter is the subordinate of only the first including
file processed. The instances of xmlSchemaOwlPrinter are created in
the main function and the processIncludes function.

The xmlSchemaOwlPrinter for each schema file maintains two
alphabetically arranged lists: complexClasses and simpleClasses. In
each OWL file that is written, the datatypes are printed first (from
the simpleClasses list). Then the classes are printed from the
complexClasses list. In addition, the main function has complexClassesAll
and simpleClassesAll lists, a pointer to which is shared among all
xmlSchemaOwlPrinters. These are also kept in alphabetical order. See
documentation in xmlSchemaOwlClassGenerator.hh for further information
about these four lists.

Because of the need to constrain OWL types tightly (which is necessitated
by the OWL open world assumption) an OWL file generated from an included
XML file may need to refer to classes in the including OWL file. The way
that can happen is described in the next paragraph. This makes the
included OWL file non-reusable; it is valid only among the set
of OWL files that are generated together.

If a type P is defined in an included schema ED and a derived type K
of P is defined in an including schema ING, the owl file generated
from ED will have (1) a subtype statement saying the OWL class KO for K
is a subtype of the OWL class PO for P, and (2) a disjoint union
statement for PO that includes KO (but only if P has at least two subtypes).
Thus, it would not work to run the xmlSchemaOwlClassGenerator first on
ED and second on ING and try to include the OWL file that results from
ED in the OWL file that results from ING. If that were done, any
disjoint union statement for PO would not include KO, but it needs to.
It is necessary to run the xmlSchemaOwlClassGenerator only on the
topmost schema file of a set of schema files connected by includes.
That will generate usable OWL files for members of the set.

*/

#include <stdio.h>   // fprintf
#include <string.h>  // strlen
#include <stdlib.h>  // exit
#include "xmlSchemaClasses.hh"
#include "xmlSchemaOwlClassGenerator.hh"

extern XmlSchemaFile * xmlSchemaFile;
extern char * globalOwlPrefix;
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

Called By:
  main
  processIncludes

This goes through the contents2 list of the top level schema. For each
item on the list:
1. If the item is the first item and is an XmlElementRefable, and isTop
   is true, then the element must have a non-zero typ, and must have a
   zero typeDef. This checks for those conditions and exits if any of them
   does not hold. If the checks pass, the topElement is set to this element.
2a. If the item is a complex type, it is placed on the complexClasses
    and complexClassesAll lists.
2b. Otherwise, if the item is a simple type, it is placed on the
    simpleClasses  and simpleClassesAll lists.
2c. Otherwise, if the item is an XmlElementRefable, it is added to the
    refables list.
2d. Otherwise, if the item is an XmlAttributeLoner, or if the item is an
    XmlAttributeGroup, an error message is printed, and the function exits.
2e. Otherwise, the item must be some unknown thing, so an error message is
    printed, and the function exits.

*/

void xmlSchemaOwlPrinter::buildClasses( /* ARGUMENTS                        */
 bool isTop)                            /* true=top level schema, false=not */
{
  std::list<XmlSchemaContent2 *>::iterator iter;
  XmlElementRefable * refable;
  XmlComplexType * complx;
  XmlSimpleType * simple;
  
  if (isTop &&
      (refable = dynamic_cast<XmlElementRefable *>(contents2->front())))
    {
      if (refable->typeDef || (refable->typ == 0))
	{
	  fprintf(stderr, "top element must have a type and no typeDef\n");
	  exit(1);
	}
      topElement = refable;
    }
  for (iter = contents2->begin(); iter != contents2->end(); iter++)
    {
      if ((complx = dynamic_cast<XmlComplexType *>(*iter)))
	{
	  enterComplexClass(complx);
	}
      else if ((simple = dynamic_cast<XmlSimpleType *>(*iter)))
	{
	  enterSimpleClass(simple);
	}
      else if ((refable = dynamic_cast<XmlElementRefable *>(*iter)))
	{
	  refables.push_back(refable);
	}
      else if ((dynamic_cast<XmlAttributeLonerRefable *>(*iter)) ||
	       (dynamic_cast<XmlAttributeGroupRefable *>(*iter)))
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

/* xmlSchemaOwlPrinter::buildDisjointClasses

Returned Value: none

Called By:  main

This builds the disjointClasses list from the complexClassesAll in the
schema. This also checks for types that cannot be handled. It exits if
any such types are found.

This is allowing an XmlChoice, but XmlChoice is disallowed later.

*/

void xmlSchemaOwlPrinter::buildDisjointClasses()/* NO ARGUMENTS */
{
  XmlComplexType * complx;
  XmlOtherContent * other;
  XmlComplexContent * comp;
  XmlComplexExtension * extend;
  XmlSequence * sequence;
  XmlChoice * choice;
  XmlElementLocal * elementLocal;
  std::list<XmlComplexType *>::iterator iter;
  std::list<XmlChoSeqItem *> * items;
  std::list<XmlChoSeqItem *>::iterator ator;

  for (iter = complexClassesAll->begin();
       iter != complexClassesAll->end(); iter++)
    {
      complx = dynamic_cast<XmlComplexType *>(*iter);
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

/********************************************************************/

/* xmlSchemaOwlPrinter::checkName

Returned Value: none

Called By:
  generator::processIncludes
  generator::readSchema

This checks that the given fileName is not too long and ends with
.xsd. If the name fails either check, this prints an error message and
exits. If the name passes, this puts the base name (.xsd removed) with
path into the bassNameWithPath buffer and puts the base name without
path into the bassNameNoPath buffer.

*/

void xmlSchemaOwlPrinter::checkName( /* ARGUMENTS                         */
 char * fileName,              /* name of schema to read, including path  */
 char * bassNameWithPath,      /* buffer to put base name with path in    */
 char * bassNameNoPath)        /* buffer to put base name without path in */
{
  int n; 
  n = strlen(fileName);
  if (n > (NAMESIZE - 2))
    {
      fprintf(stderr, "schema file name must have fewer than %d characters\n",
	      (NAMESIZE - 1));
      exit(1);
    }
  n -= 4;
  if (strcmp(fileName+n, ".xsd"))
    {
      fprintf(stderr,
	      "schema file name %s must end with .xsd\n", fileName);
      exit(1);
    }
  strcpy(bassNameWithPath, fileName);
  bassNameWithPath[n] = 0;  // remove .xsd suffix from bassNameWithPath
  for ( ; n >= 0; n--)
    if ((bassNameWithPath[n] == ' ') ||
	(bassNameWithPath[n] == '\\') ||
	(bassNameWithPath[n] == '/'))
      break;
  strcpy(bassNameNoPath, (bassNameWithPath + n + 1));
}

/********************************************************************/

/* xmlSchemaOwlPrinter::deNameName

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocalIDREF

This checks whether the name ends in "Name". If so, it copies the name
into the buffer with "Name" removed. If not, it prints an error message
and exits.

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
  xmlSchemaOwlPrinter::printOwlClassFile
  xmlSchemaOwlPrinter::printOwlComplexType
  xmlSchemaOwlPrinter::printOwlElementLocalComplex
  xmlSchemaOwlPrinter::printOwlElementLocalData
  xmlSchemaOwlPrinter::printOwlElementLocalIDREF
  xmlSchemaOwlPrinter::printOwlIdConstraint
  xmlSchemaOwlPrinter::printOwlIdConstraints
  xmlSchemaOwlPrinter::printOwlSimpleType

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

/* xmlSchemaOwlPrinter::enterComplexClass

Returned Value: none

Called By:  xmlSchemaOwlPrinter::buildClasses

This inserts complx in the complexClasses and complexClassesAll lists
in alphabetical order by newName. If a duplicate class name is
found, this prints an error message and exits.

*/

void xmlSchemaOwlPrinter::enterComplexClass( /* ARGUMENTS                 */
 XmlComplexType * complx)             /* class to put into complexClasses */
{
  std::list<XmlComplexType *>::iterator iter;
  XmlComplexType * comp;
  char * newName;
  int result;

  newName = complx->newName;
  for (iter = complexClasses.begin(); iter != complexClasses.end(); iter++)
    {
      if ((comp = dynamic_cast<XmlComplexType *>(*iter)))
	{
	  result = strcmp(newName, comp->newName);
	  if (result < 0)
	    {
	      complexClasses.insert(iter, complx);
	      break;
	    }
	  else if (result == 0)
	    {
	      fprintf(stderr, "duplicate class name %s. Exiting\n", newName);
	      exit(1);
	    }
	}
    }
  if (iter == complexClasses.end())
    complexClasses.push_back(complx);
  for (iter = complexClassesAll->begin();
       iter != complexClassesAll->end(); iter++)
    {
      if ((comp = dynamic_cast<XmlComplexType *>(*iter)))
	{
	  result = strcmp(newName, comp->newName);
	  if (result < 0)
	    {
	      complexClassesAll->insert(iter, complx);
	      break;
	    }
	  else if (result == 0)
	    {
	      fprintf(stderr, "duplicate class name %s. Exiting\n", newName);
	      exit(1);
	    }
	}
    }
  if (iter == complexClassesAll->end())
    complexClassesAll->push_back(complx);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::enterSimpleClass

Returned Value: none

Called By:  xmlSchemaOwlPrinter::buildClasses

This inserts simple in the simpleClasses and simpleClasses lists in
alphabetical order by newName. If a duplicate class name is found,
this prints an error message and exits.

There is currently no check that the name of a simple class is not the
same as the name of a complex class.

*/

void xmlSchemaOwlPrinter::enterSimpleClass( /* ARGUMENTS                 */
 XmlSimpleType * simple)              /* class to put into simpleClasses */
{
  std::list<XmlSimpleType *>::iterator iter;
  char * newName;
  XmlSimpleType * simp;
  int result;

  newName = simple->newName;
  for (iter = simpleClasses.begin(); iter != simpleClasses.end(); iter++)
    {
      if ((simp = dynamic_cast<XmlSimpleType *>(*iter)))
	{
	  result = strcmp(newName, simp->newName);
	  if (result < 0)
	    {
	      simpleClasses.insert(iter, simple);
	      break;
	    }
	  else if (result == 0)
	    {
	      fprintf(stderr, "duplicate class name %s. Exiting\n", newName);
	      exit(1);
	    }
	}
    }
  if (iter == simpleClasses.end())
    simpleClasses.push_back(simple);
  for (iter = simpleClassesAll->begin();
       iter != simpleClassesAll->end(); iter++)
    {
      if ((simp = dynamic_cast<XmlSimpleType *>(*iter)))
	{
	  result = strcmp(newName, simp->newName);
	  if (result < 0)
	    {
	      simpleClassesAll->insert(iter, simple);
	      break;
	    }
	  else if (result == 0)
	    {
	      fprintf(stderr, "duplicate class name %s. Exiting\n", newName);
	      exit(1);
	    }
	}
    }
  if (iter == simpleClassesAll->end())
    simpleClassesAll->push_back(simple);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::enterKid

Returned Value: none

Called By:  xmlSchemaOwlPrinter::enterKids

This enters the kid type in the extensions of the parent type if it is
not already there. The extensions list of an XmlComplexType is not
kept in any particular order. If the kid is already on the parent's
extensions list, this prints an error message and exits.

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

This goes through the classes list, and for each complex type that is
an extension (the kid) this finds the parent and adds the kid to the
parent's extensions list. If the parent cannot be found, this prints
an error message and exits.

*/

void xmlSchemaOwlPrinter::enterKids() /* NO ARGUMENTS */
{
  XmlComplexType * parent;
  XmlComplexType * kid;
  XmlComplexContent * comp;
  XmlComplexExtension * extend;
  std::list<XmlComplexType *>::iterator iter;

  for (iter = complexClassesAll->begin();
       iter != complexClassesAll->end(); iter++)
    {
      kid = dynamic_cast<XmlComplexType *>(*iter);
      if (((comp = dynamic_cast<XmlComplexContent *>(kid->item))) &&
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

Returned Value: XmlComplexType * This looks through the
complexClassesAll list and returns a pointer to the complex class with
the given name, or 0 (a null pointer) if there is no such class.

Called By:
  xmlSchemaOwlPrinter::enterKids;
  xmlSchemaOwlPrinter::findHaser
  xmlSchemaOwlPrinter::printOwlElementLocal
  xmlSchemaOwlPrinter::printOwlElementLocalComplex
  printOwlElementLocalIDREF
  printOwlIdConstraints

This should not be called until all schemas have been parsed in main or
processIncludes since complexClassesAll is not complete until then.

*/

XmlComplexType * xmlSchemaOwlPrinter::findComplexClass( /* ARGUMENTS        */
 char * name)                                      /* name of class to find */
{
  std::list<XmlComplexType *>::iterator iter;
  XmlComplexType * complx;

  for (iter = complexClassesAll->begin();
       iter != complexClassesAll->end(); iter++)
    {
      if ((complx = dynamic_cast<XmlComplexType *>(*iter)) &&
	  (strcmp(name, complx->newName) == 0))
	break;
    }
  return ((iter == complexClassesAll->end()) ? 0 : complx);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::findHaser

Returned Value: char *
  This returns the XmlComplexType that is the most distant ancestor of
  the XmlComplexType complx that has an element with the given elementName.
  That may be complx itself.

Called By: xmlSchemaOwlPrinter::printOwlIdConstraint

A. If complx has complex content
A1. If complx is an extension
A1a. If complx has a sequence with items
A1a1. If elementName is the name of one of the elements in the sequence,
     this returns complx.
A1a2. Otherwise this calls itself recursively using the 
      base of the extension along with the elementName.
A1b. Otherwise this calls itself recursively using the
      base of the extension along with the elementName.
A2. If complx is not an extension, this prints an error message and exits.

B. If complx has other content, this returns complx.

C. If complx has neither complex content nor other content, this prints
   an error message and exits.

*/

XmlComplexType * xmlSchemaOwlPrinter::findHaser( /* ARGUMENTS               */
 XmlComplexType * complx,                /* type that has named element     */
 char * elementName)                     /* name of an element of that type */
{
  XmlComplexContent * complxCont;
  XmlOtherContent * otherCont;
  XmlComplexExtension * extend;
  XmlSequence * sequence;
  XmlElementLocal * element;
  XmlComplexType * base;
  std::list<XmlChoSeqItem *>::iterator iter;

  if ((complxCont = dynamic_cast<XmlComplexContent *>(complx->item)))
    {
      if ((extend = dynamic_cast<XmlComplexExtension *>(complxCont->item)))
	{
	  if (extend->item &&
	      (sequence = dynamic_cast<XmlSequence *>(extend->item)) &&
	      sequence->items)
	    {
	      for (iter = sequence->items->begin();
		   iter != sequence->items->end(); iter++)
		{
		  if ((element = dynamic_cast<XmlElementLocal *>(*iter)) &&
		      (strcmp(element->newName, elementName) == 0))
		    {
		      return complx;
		    }
		}
	    }
	  base = findComplexClass(extend->base);
	  if (base == 0)
	    {
	      fprintf(stderr, "cannot find complex type %s\n", extend->base);
	      exit(1);
	    }
	  return findHaser(base, elementName);
	}
      else
	{
	  fprintf(stderr, "findHaser can handle only extension\n");
	  exit(1);
	}
    }
  else if ((otherCont = dynamic_cast<XmlOtherContent *>(complx->item)))
    {
      return complx;
    }
  else
    {
      fprintf(stderr, "Unknown complex type in findHaser\n");
      exit(1);
    }
  return 0;
}

/********************************************************************/

/* xmlSchemaOwlPrinter::findSimpleClass

Returned Value: XmlSimpleType *
  This returns a pointer to the simple class with the given name. If there
  is no such class, this returns 0 (a null pointer).

Called By:  xmlSchemaOwlPrinter::printOwlElementLocal

This should not be called until all schemas have been parsed in main or
processIncludes since simpleClassesAll is not complete until then.

*/

XmlSimpleType * xmlSchemaOwlPrinter::findSimpleClass( /* ARGUMENTS          */
 char * name)                                      /* name of class to find */
{
  std::list<XmlSimpleType *>::iterator iter;
  XmlSimpleType * simple;

  for (iter = simpleClassesAll->begin();
       iter != simpleClassesAll->end(); iter++)
    {
      if ((simple = dynamic_cast<XmlSimpleType *>(*iter)) &&
	  (strcmp(name, simple->newName) == 0))
	break;
    }
  return ((iter == simpleClassesAll->end()) ? 0 : simple);
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

This allows comments in the XML schema but does not transcribe them
into the OWL file. Comments in XML may cover several lines, whereas
only one-line comments are enabled in OWL functional syntax, so it
would take some fiddling to transcribe them correctly.

If the content of the annotation includes an item that is neither a
documentation node nor an appinfo node, this prints an error
message and exits. That should never happen in practice since it
would not be possible to construct the annotation.

*/

void xmlSchemaOwlPrinter::printOwlAnnotation( /* ARGUMENTS            */
 XmlAnnotation * annotation,                  /* annotation to print  */
 FILE * outFile)                              /* OWL file to print in */
{
  std::list<XmlAnnoType *>::iterator iter;
  XmlDocumentation * doc;
  XmlAppinfo * appinfo;

  if (annotation->comment) {} // do not transcribe comments
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
		  fprintf(outFile, " %s:%s\n", owlPrefix, className);
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

This handles an item that is a sequence, an element, or a choice.
If the item is a sequence or an element, OWL text is printed. If
the item is a choice, this prints an error message and exits.
If the item is none of the three it knows about, it prints an
error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlChoSeqItem( /* ARGUMENTS            */
 XmlChoSeqItem * item,                        /* item to print        */
 FILE * outFile)                              /* OWL file to print in */
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

Called By: xmlSchemaOwlPrinter::printOwlClassFiles

This prints one OWL file (the one corresponding to the particular instance
of xmlSchemaOwlPrinter).

*/

void xmlSchemaOwlPrinter::printOwlClassFile(/* ARGUMENTS                     */
 char * URL,                                /* URL to use in header          */
 std::list<char *> * includeds,             /* list of all files in group    */
 std::list<char *> * prefixes,              /* list of all prefixes in group */
 FILE * outFile)                            /* OWL file to print in          */
{
  std::list<XmlSchemaContent1 *>::iterator iter;
  std::list<XmlSchemaContent2 *>::iterator ator;
  std::list<XmlComplexType *>::iterator eter;
  std::list<XmlSimpleType *>::iterator otor;
  std::list<XmlElementRefable *>::iterator utur;

  printOwlSchemaHeader(URL, includeds, prefixes, outFile);
  className[0] = 0;
  for (iter = contents1->begin(); iter != contents1->end(); iter++)
    printOwlSchemaContent1(*iter, outFile);
  if (topElement)
    {
      printOwlElementRefable(topElement, outFile);
    }
  if (refables.size())
    {
      for (utur = refables.begin(); utur != refables.end(); utur++)
	{
	  if ((*utur)->idConstraints)
	    printOwlIdConstraints((*utur)->idConstraints,
				  (*utur)->newTyp, outFile);
	}
    }
  if (simpleClasses.size())
    {
      fprintf(outFile, "\n\n");
      for (otor = simpleClasses.begin(); otor != simpleClasses.end(); otor++)
	printOwlSimpleType(*otor, outFile);
    }
  if (complexClasses.size())
    {
      for (eter = complexClasses.begin(); eter != complexClasses.end(); eter++)
	printOwlComplexType(*eter, outFile);
    }
  if (disjointClasses.size() > 1)
    {
      fprintf(outFile, "\nDisjointClasses(");
      eter = disjointClasses.begin();
      deTypeName((*eter)->name, nameBuffer);
      fprintf(outFile, "%s:%s", (*eter)->owlPrefix, nameBuffer);
      for (eter++; eter != disjointClasses.end(); eter++)
	{
	  deTypeName((*eter)->name, nameBuffer);
	  fprintf(outFile, "\n                %s:%s",
		  (*eter)->owlPrefix, nameBuffer);
	}
      fprintf(outFile, ")\n");
    }
  fprintf(outFile, ")\n");
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlClassFiles

Returned Value: none

Called By:
  xmlSchemaOwlPrinter::printOwlClassFiles (recursively)
  main

This is the top level function for printing the OWL file(s). First it
calls itself to print each of the subordinates of "this" xmlSchemaOwlPrinter
instance. Then it calls printOwlClassFile to print itself.

*/

void xmlSchemaOwlPrinter::printOwlClassFiles(/* ARGUMENTS                     */
 char * URL,                                 /* URL to use in header          */
 std::list<char *> * includeds,              /* list of all files in group    */
 std::list<char *> * prefixes)               /* list of all prefixes in group */
{
  static char outFileName[NAMESIZE];
  std::list<xmlSchemaOwlPrinter *>::iterator iter;
  FILE * outFile;

  for (iter = subordinates.begin(); iter != subordinates.end(); iter++)
    { // OK if list empty
      (*iter)->printOwlClassFiles(URL, includeds, prefixes);
    }
  sprintf(outFileName, "%sClasses.owl", baseNameWithPath);
  outFile = fopen(outFileName, "w");
  printOwlClassFile(URL, includeds, prefixes, outFile);
  fclose(outFile);
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexContent

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlComplexTypeItem

This prints one complex content item. If the item has "mixed", this
prints an error message and exits.

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

This prints the item inside a complex content item. If the inside item
is an extension, OWL is printed for it. If the inside item is a restriction
or anything else, this prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlComplexContentItem( /* ARGUMENTS        */
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
  else
    {
      fprintf(stderr, "unknown item in printOwlComplexContentItem\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexExtension

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlComplexContentItem

This prints OWL text for an XML extension. If the extension has attributes,
this prints an error message and exits.

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

This prints the OWL for one XML schema complex type, complx. If complx
does not have a name, or if it has mixed, this prints an error message
and exits.

This prints an OWL SubClassOf declaration for each extension of complx.

If complx has more than one extension, this prints a DisjointUnion
declaration. Note that the Protege OWL utility signals an error if there
is a DisjointUnion with only one member (i.e. every typeA parent is typeB
kid).

*/

void xmlSchemaOwlPrinter::printOwlComplexType( /* ARGUMENTS             */
 XmlComplexType * complx,                      /* complex type to print */
 FILE * outFile)                               /* OWL file to print in  */
{
  std::list<XmlComplexType *>::iterator iter;
  std::list<XmlAnnotation *>::iterator ator;

  if (complx->ccPrinted)
    return;
  if (complx->name)
    {
      deTypeName(complx->name, nameBuffer);
      fprintf(outFile, "\n\n\nDeclaration(Class(%s:%s))\n",
	      complx->owlPrefix, nameBuffer);
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
	  fprintf(outFile, "SubClassOf(%s:%s %s:%s)\n",
		  (*iter)->owlPrefix, nameBuffer, complx->owlPrefix, className);
	}
      if (complx->extensions->size() > 1)
	{
	  fprintf(outFile, "DisjointUnion(%s:%s", complx->owlPrefix, className);
	  for (iter = complx->extensions->begin();
	       iter != complx->extensions->end(); iter++)
	    {
	      deTypeName((*iter)->name, nameBuffer);
	      fprintf(outFile, "\n              %s:%s",
		      (*iter)->owlPrefix, nameBuffer);
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
  complx->ccPrinted = true;
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlComplexTypeItem

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlComplexType

This prints the item in a complex type if the item is complex content
(normally an extension) or other content (normally a sequence). If the
item is simple content (one or more attributes), or is none of the
three allowed types, this prints an error message and exits.

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
  else
    {
      fprintf(stderr, "unknown item in printOwlComplexTypeItem\n");
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
 
        The I, J, and K represent the usual i, j, and k
        components of a 3D vector.
      </xs:documentation>
    </xs:annotation>
    ...

becomes this in the OWL class file (if the owlPrefix for the file is ktw)

Declaration(Class(ktw:Vector))
AnnotationAssertion(rdfs:comment ktw:Vector
  "Vector is derived from DataThing.
  An instance of Vector has the following:
    I
    J
    K.
 
  The I, J, and K represent the usual i, j, and k
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

This prints a local element from a complex type.

An XML instance file conforming to a schema is a hierarchy of
instances, whereas an OWL instance file conforming to an OWL class
model is sequence of declarations, some of which create instances,
others of which give properties of instances. In OWL, a name is
assigned when an instance is created. The name of the instance is not
a property of the instance. In order to provide a name for each OWL
instance, each complex type in the XML schema is required to have a
Name element. This translator normally generates an OWL property for
each element of a complex type, but since the name of an OWL instance
is not a property, the Name elements in the XML complex types are not
translated. The values of the Names in an XML instance file are used
for assigning OWL names when an instance file translator is
translating an XML instance file into an OWL instance file.

This prints an error message and exits if any of the following occurs:
- The element does not have a name.
- The element uses ref.
- The element does not have a type.
- The element has both default and fixed.
- The element contains a type definition.
- The element type is not basic, simple, or complex.

*/

void xmlSchemaOwlPrinter::printOwlElementLocal( /* ARGUMENTS            */
 XmlElementLocal * element,                     /* element to print     */
 FILE * outFile)                                /* OWL file to print in */
{
  XmlComplexType * complx;
  XmlSimpleType * simple;

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
      fprintf(stderr, "ignoring idConstraints in local element\n");
    }
  if ((complx = findComplexClass(element->newTyp)))
    {
      printOwlElementLocalComplex(element, complx, outFile);
    }
  else if ((simple = findSimpleClass(element->newTyp)))
    { 
      printOwlElementLocalData(element, simple, outFile);
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
      fprintf(stderr, "unknown element type %s in printOwlElementLocal\n",
	      element->newTyp);
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalBuiltIn

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This handles local elements of XML built-in data type other than IDREF.

This always generates a DataProperty with Domain and Range declarations.
If the element can occur at most once, the data property is declared to
be functional. If the element must occur exactly once, an EquivalentClasses
declaration is made.

When this is called, the name of the OWL class equivalent to the XML type
containing the element is stored in the global className buffer.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalBuiltIn( /* ARGUMENTS          */
 XmlElementLocal * element,             /* element of built-in type to print */
 FILE * outFile)                        /* OWL file to print in              */
{
  char hasName[NAMESIZE];

  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  fprintf(outFile, "\nDeclaration(DataProperty(%s:%s))\n", owlPrefix, hasName);
  fprintf(outFile, "DataPropertyDomain(%s:%s %s:%s)\n",
	  owlPrefix, hasName, owlPrefix, className);
  fprintf(outFile, "DataPropertyRange(%s:%s xsd:%s)\n",
	  owlPrefix, hasName, element->newTyp);
  if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
    { // zero or one value, so is functional
      fprintf(outFile, "FunctionalDataProperty(%s:%s)\n", owlPrefix, hasName);
      if (element->minOccurs != 0)
	{
	  fprintf(outFile,
		  "EquivalentClasses(%s:%s ObjectIntersectionOf(\n",
		  owlPrefix, className);
	  fprintf(outFile,
		  "  DataSomeValuesFrom(%s:%s xsd:%s)\n",
		  owlPrefix, hasName, element->newTyp);
	  fprintf(outFile,
		  "  DataAllValuesFrom (%s:%s xsd:%s)))\n",
		  owlPrefix, hasName, element->newTyp);
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

When this is called, the name of the OWL class equivalent to the XML type
containing the element is stored in the global className buffer.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalComplex( /* ARGUMENTS          */
 XmlElementLocal * element,              /* element of complex type to print */
 XmlComplexType * complx,                /* type of element                  */
 FILE * outFile)                         /* OWL file to print in             */
{
  char hasName[NAMESIZE];
  char classType[NAMESIZE];
  char hadByName[NAMESIZE];

  deTypeName(element->newTyp, nameBuffer);
  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  fprintf(outFile, "\nDeclaration(ObjectProperty(%s:%s))\n",
	  owlPrefix, hasName);
  fprintf(outFile, "ObjectPropertyDomain(%s:%s %s:%s)\n",
	  owlPrefix, hasName, owlPrefix, className);
  fprintf(outFile, "ObjectPropertyRange(%s:%s %s:%s)\n",
	  owlPrefix, hasName, complx->owlPrefix, nameBuffer);
  fprintf(outFile, "InverseFunctionalObjectProperty(%s:%s)\n",
	  owlPrefix, hasName);
  if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
    { // zero or one value, so is functional
      fprintf(outFile, "FunctionalObjectProperty(%s:%s)\n", owlPrefix, hasName);
      if (element->minOccurs != 0)
	{
	  fprintf(outFile,
		  "EquivalentClasses(%s:%s ObjectIntersectionOf(\n",
		  owlPrefix, className);
	  fprintf(outFile,
		  "  ObjectSomeValuesFrom(%s:%s %s:%s)\n",
		  owlPrefix, hasName, complx->owlPrefix, nameBuffer);
	  fprintf(outFile,
		  "  ObjectAllValuesFrom (%s:%s %s:%s)))\n",
		  owlPrefix, hasName, complx->owlPrefix, nameBuffer);
	}
    }
  // If classType and element->newTyp are both complex types, do hadBy
  snprintf(classType, NAMESIZE, "%sType", className);
  if (findComplexClass(classType) && findComplexClass(element->newTyp))
    {
      snprintf(hadByName, NAMESIZE, "hadBy%s_%s", element->name, className);
      fprintf(outFile, "\nDeclaration(ObjectProperty(%s:%s))\n",
	      owlPrefix, hadByName);
      fprintf(outFile, "InverseObjectProperties(%s:%s\n",
	      owlPrefix, hasName);
      fprintf(outFile, "                        %s:%s)\n",
	      owlPrefix, hadByName);
      fprintf(outFile, "ObjectPropertyDomain(%s:%s %s:%s)\n",
	      owlPrefix, hadByName, complx->owlPrefix, nameBuffer);
      fprintf(outFile, "ObjectPropertyRange(%s:%s %s:%s)\n",
	      owlPrefix, hadByName, owlPrefix, className);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalData

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This handles local elements of user-defined data type.

This always generates a DataProperty with Domain and Range declarations.
If the element can occur at most once, the data property is declared to
be functional. If the element must occur exactly once, an EquivalentClasses
declaration is made.

When this is called, the name of the OWL class equivalent to the XML type
containing the element is stored in the global className buffer.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalData( /* ARGUMENTS             */
 XmlElementLocal * element,             /* element of built-in type to print */
 XmlSimpleType * simple,                /* type of element                   */
 FILE * outFile)                        /* OWL file to print in              */
{
  char hasName[NAMESIZE];

  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  deTypeName(element->newTyp, nameBuffer);
  nameBuffer[0] = tolower(nameBuffer[0]);
  snprintf(hasName, NAMESIZE, "has%s_%s", className, element->name);
  fprintf(outFile, "\nDeclaration(DataProperty(%s:%s))\n", owlPrefix, hasName);
  fprintf(outFile, "DataPropertyDomain(%s:%s %s:%s)\n",
	  owlPrefix, hasName, owlPrefix, className);
  fprintf(outFile, "DataPropertyRange(%s:%s %s:%s)\n",
	  owlPrefix, hasName, simple->owlPrefix, nameBuffer);
  if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
    { // has zero or one value, so is functional
      fprintf(outFile, "FunctionalDataProperty(%s:%s)\n", owlPrefix, hasName);
      if (element->minOccurs != 0)
	{
	  fprintf(outFile,
		  "EquivalentClasses(%s:%s ObjectIntersectionOf(\n",
		  owlPrefix, className);
	  fprintf(outFile,
		  "  DataSomeValuesFrom(%s:%s %s:%s)\n",
		  owlPrefix, hasName, simple->owlPrefix, nameBuffer);
	  fprintf(outFile,
		  "  DataAllValuesFrom (%s:%s %s:%s)))\n",
		  owlPrefix, hasName, simple->owlPrefix, nameBuffer);
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlElementLocalIDREF

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlElementLocal

This is called when the newTyp of the element is IDREF.

IDREF may be used as the type of an element in the XML schema to
indicate that an instance in an XML instance file will have the Name
of an instance elsewhere in the hierarchy than directly below. The
translated form of this in the OWL class file is exactly as if the
element being translated had the type to which the IDREF points. To
provide the name of that type, each element of IDREF type must have a
frontNote that is an annotation-appinfo containing the type name.

This always generates an ObjectProperty with Domain and Range declarations.
If the element can occur at most once, the object property is declared to
be functional. If the element must occur exactly once, an EquivalentClasses
declaration is made.

When this is called, the name of the OWL class equivalent to the XML type
containing the element is stored in the global className buffer.

*/

void xmlSchemaOwlPrinter::printOwlElementLocalIDREF( /* ARGUMENTS            */
 XmlElementLocal * element,       /* element whose type is xs:IDREF to print */
 FILE * outFile)                  /* OWL file to print in                    */
{
  XmlAppinfo * appinfo;
  XmlComplexType * complx;
  char hasName[NAMESIZE];
  char hadByName[NAMESIZE];

  if (element->frontNote &&
      element->frontNote->content &&
      (appinfo =
       dynamic_cast<XmlAppinfo *>(element->frontNote->content->front())))
    {
      complx = findComplexClass(appinfo->text);
      if (complx == 0)
	{
	  fprintf(stderr, "type %s not found in printOwlElementLocalIDREF\n",
		  appinfo->text);
	  exit(1);
	}
      deTypeName(appinfo->text, nameBuffer);
      deNameName(element->name, otherName);
      snprintf(hasName, NAMESIZE, "has%s_%s", className, otherName);
      fprintf(outFile, "\nDeclaration(ObjectProperty(%s:%s))\n",
	      owlPrefix, hasName);
      fprintf(outFile, "ObjectPropertyDomain(%s:%s %s:%s)\n",
	      owlPrefix, hasName, owlPrefix, className);
      fprintf(outFile, "ObjectPropertyRange(%s:%s %s:%s)\n",
	      owlPrefix, hasName, complx->owlPrefix, nameBuffer);
      if ((element->maxOccurs == -2) || (element->maxOccurs == 1))
	{ // zero or one value, so is functional
	  fprintf(outFile, "FunctionalObjectProperty(%s:%s)\n",
		  owlPrefix, hasName);
	  if (element->minOccurs != 0)
	    {
	      fprintf(outFile,
		      "EquivalentClasses(%s:%s ObjectIntersectionOf(\n",
		      owlPrefix, className);
	      fprintf(outFile,
		      "  ObjectSomeValuesFrom(%s:%s %s:%s)\n",
		      owlPrefix, hasName, complx->owlPrefix, nameBuffer);
	      fprintf(outFile,
		      "  ObjectAllValuesFrom (%s:%s %s:%s)))\n",
		      owlPrefix, hasName, complx->owlPrefix, nameBuffer);
	    }
	}
      snprintf(hadByName, NAMESIZE, "hadBy%s_%s", otherName, className);
      fprintf(outFile, "\nDeclaration(ObjectProperty(%s:%s))\n",
	      owlPrefix, hadByName);
      fprintf(outFile, "InverseObjectProperties(%s:%s\n",
	      owlPrefix, hasName);
      fprintf(outFile, "                        %s:%s)\n",
	      owlPrefix, hadByName);
      fprintf(outFile, "ObjectPropertyDomain(%s:%s %s:%s)\n",
	      owlPrefix, hadByName, complx->owlPrefix, nameBuffer);
      fprintf(outFile, "ObjectPropertyRange(%s:%s %s:%s)\n",
	      owlPrefix, hadByName, owlPrefix, className);
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
should be put into the OWL file. This function prints them.

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
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlEnumeration

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

This prints OWL for an XML enumeration value.

*/

void xmlSchemaOwlPrinter::printOwlEnumeration( /* ARGUMENTS            */
 XmlEnumeration * enumeration,                 /* enumeration to print */
 FILE * outFile)                               /* OWL file to print in */
{
  fprintf(outFile, "\"%s\"", enumeration->value);
  if (enumeration->id)
    fprintf(stderr, "ignoring id\n");
  if (enumeration->frontNote)
    {
      className[0] = 0;
      printOwlAnnotation(enumeration->frontNote, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlIdConstraint

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlIdConstraints

This prints OWL only for simple instances of XmlKey. If the constraint is
a keyref or unique constraint, this prints a warning message that the
constraint is being ignored.

This might print, for example

HasKey(ktw:KitTray (rm:hasSkuObject_Sku) (ktw:hasKitTray_SerialNumber))

The selector xpath in the XML schema must be ".". Also, each field xpath
must be only an element name. For example:

    <xs:key name="KitTrayKey">
      <xs:selector xpath="."/>
      <xs:field xpath="SkuName"/>
      <xs:field xpath="SerialNumber"/>
    </xs:key>

The field name YYY may be the name of an element inherited from an ancestor
type XXX. For example, SkuName might be inherited from SkuObjectType, which
is the parent type of KitTrayType. In that case, we need to find the
most distant ancestor that has the field in order to construct the
correct hasXXX_YYY property name, for example hasSkuObject_Sku. This is
made somewhat messier by the need to remove Name from the end of any field
that ends in Name.

*/

void xmlSchemaOwlPrinter::printOwlIdConstraint( /* ARGUMENTS                 */
 XmlIdConstraint * constraint,            /* XML constraint to print from    */
 char * owlClassName,                     /* name of constrained OWL class   */
 XmlComplexType * complx,                 /* XML type OWL class derived from */
 FILE * outFile)                          /* OWL file to print in            */
{
  XmlKey * ky;
  XmlComplexType * haser;   // the most ancestral type with the element
  std::list<XmlField *>::iterator iter;
  char fieldName[NAMESIZE]; // copy of the field xpath for removing "Name"
  char hasName[NAMESIZE];   // detyped name of haser
  int length;               // length of fieldName

  if ((ky = dynamic_cast<XmlKey *>(constraint)))
    {
      fprintf(outFile, "\nHasKey(%s:%s", owlPrefix, owlClassName);
      for (iter = ky->fields->begin(); iter != ky->fields->end(); iter++)
	{ // if the field xpath ends in Name, get rid of Name
	  haser = findHaser(complx, (*iter)->xpath);
	  strncpy(fieldName, (*iter)->xpath, NAMESIZE);
	  length = strlen(fieldName) - 4;
	  if ((length > 0) && (strcmp((fieldName + length), "Name") == 0))
	    fieldName[length] = 0;
	  deTypeName(haser->newName, hasName);
	  fprintf(outFile, " (%s:has%s_%s)",
		  haser->owlPrefix, hasName, fieldName);
	} 
      fprintf(outFile, ")\n");
    }
  else
    {
      fprintf(stderr, "ignoring identity constraint\n");
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlIdConstraints

Returned Value: none

Called By: printOwlClassFile

This prints OWL key constraints on the OWL class derived from the
XmlComplexType with the given typeName. The OWL class name is the
typeName with "Type" removed from the end.

*/

void xmlSchemaOwlPrinter::printOwlIdConstraints( /* ARGUMENTS            */
 std::list<XmlIdConstraint *> * idConstraints,   /* constraints to print */
 char * typeName,                                /* name of XML type     */
 FILE * outFile)                                 /* OWL file to print in */
{
  std::list<XmlIdConstraint *>::iterator iter;
  XmlComplexType * complx;
  char owlClassName[NAMESIZE];

  for (iter = idConstraints->begin(); iter != idConstraints->end(); iter++)
    {
      complx = findComplexClass(typeName);
      if (complx == 0)
	{
	  fprintf(stderr, "cannot find complex type %s\n", typeName);
	  exit(1);
	}
      deTypeName(typeName, owlClassName);
      printOwlIdConstraint(*iter, owlClassName, complx, outFile);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlMaxExclusive

Returned Value: none

Called By: xmlSchemaOwlPrinter::printOwlRestriction

This prints OWL for an XML maxExclusive restriction.

When this is called, the name of the XML basic type being restricted
is stored in the global className buffer.

If the maxExclusive is fixed, this prints an error message and exits.

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
    fprintf(stderr, "ignoring id\n");
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

This prints OWL for an XML maxInclusive restriction.

When this is called, the name of the XML basic type being restricted
is stored in the global className buffer.

If the maxInclusive is fixed, this prints an error message and exits.

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
    fprintf(stderr, "id ignored\n");
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

This prints OWL for an XML minExclusive restriction.

When this is called, the name of the XML basic type being restricted
is stored in the global className buffer.

If the minExclusive is fixed, this prints an error message and exits.

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
    fprintf(stderr, "id ignored\n");
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

This prints OWL for an XML minInclusive restriction.

When this is called, the name of the XML basic type being restricted
is stored in the global className buffer.

If the minInclusive is fixed, this prints an error message and exits.

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
    fprintf(stderr, "id ignored\n");
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

This prints OWL for an XmlOtherContent by calling printOwlOtherContentBase.
If the other content has attributes, this prints an error message and exits.

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

This prints OWL for an XmlOtherContentBase. If the base is not a sequence,
this prints an error message and exits.

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

This prints OWL for an XML restriction of a basic or simple type.

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

This handles an XmlSchemaContent1 item. If the item is an annotation,
an OWL annotation is printed. If the item is an include directive,
nothing is done (since includes are handled in printOwlSchemaHeader).
If the item is neither an annotation nor an include directive, this
prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlSchemaContent1( /* ARGUMENTS              */
XmlSchemaContent1 * content1,                     /* content1 item to print */
 FILE * outFile)                                  /* OWL file to print in   */
{
  XmlAnnotation * annotation;
  XmlInclude * included;

  if ((annotation = dynamic_cast<XmlAnnotation *>(content1)))
    printOwlAnnotation(annotation, outFile);
  else if ((included = dynamic_cast<XmlInclude *>(content1)));
  else
    {
      fprintf(stderr, "unknown XmlSchemaContent1 in printOwlSchemaContent1\n");
      exit(1);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSchemaHeader

Returned Value: none

Called By:  xmlSchemaOwlPrinter::printOwlClassFile

This prints the first few lines of the OWL file. After five fixed lines
of boilerplate, this prints:
1. the prefix declarations for all files in the group
2. the ontology declaration for "this" file
3. the Import declaration for each directly included file

The imported files should be in the same directory as "this" file, since
no path name is used in the Import statement. If the name of the XML
included file is XXX.xsd, then the name of the OWL included file will
be XXXClasses.owl.

*/

void xmlSchemaOwlPrinter::printOwlSchemaHeader( /* ARGUMENTS                 */
 char * URL,                                /* URL to use in header          */
 std::list<char *> * includeds,             /* list of all files in group    */
 std::list<char *> * prefixes,              /* list of all prefixes in group */
 FILE * outFile)                            /* OWL file to print in          */
{
  std::list<char *>::iterator iter;
  std::list<char *>::iterator ator;

  fprintf(outFile,
	  "Prefix(xsd:=<http://www.w3.org/2001/XMLSchema#>)\n"
	  "Prefix(owl:=<http://www.w3.org/2002/07/owl#>)\n"
	  "Prefix(xml:=<http://www.w3.org/XML/1998/namespace>)\n"
	  "Prefix(rdf:=<http://www.w3.org/1999/02/22-rdf-syntax-ns#>)\n"
	  "Prefix(rdfs:=<http://www.w3.org/2000/01/rdf-schema#>)\n");
  for (iter = includeds->begin(), ator = prefixes->begin();
       ((iter != includeds->end()) && (ator != prefixes->end()));
       iter++, ator++)
    {
      fprintf(outFile, "Prefix(%s:=<%s/%sClasses.owl#>)\n",
	      *ator, URL, *iter);
    }
  fprintf(outFile, "\n");
  fprintf(outFile, "Ontology(<%s/%sClasses.owl>\n", URL, baseNameNoPath);
  for (iter = includedSchemas.begin(); iter != includedSchemas.end(); iter++)
    {
      fprintf(outFile, "Import(<file:%sClasses.owl>)\n", *iter);
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::printOwlSequence

Returned Value: none

Called By:
  xmlSchemaOwlPrinter::printOwlChoSeqItem
  xmlSchemaOwlPrinter::printOwlOtherContentBase

This prints OWL for an XML sequence.

If the sequence has maxOccurs or minOccurs (which is unusual), this
prints an error message and exits.

*/

void xmlSchemaOwlPrinter::printOwlSequence( /* ARGUMENTS            */
 XmlSequence * sequence,                    /* sequence to print    */
 FILE * outFile)                            /* OWL file to print in */
{
  std::list<XmlChoSeqItem *>::iterator iter;

  if (sequence->id)
    fprintf(stderr, "id ignored\n");
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

This prints OWL for an XML simple restriction. It handles only (1)
enumerations and (2) max and min restrictions of the XML decimal
type. For anything else, this prints an error message and exits.

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

This prints an OWL DatatypeDefinition from an XML simple type.

If the simple type does not have a name or if the simple type is not
a simple list or a simple restriction, this prints an error message and
exits.

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
      fprintf(outFile, "\nDatatypeDefinition(%s:%s ",
	      simple->owlPrefix, nameBuffer);
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

/* xmlSchemaOwlPrinter::processIncludes

Returned Value: none

Called By:
  main
  xmlSchemaOwlPrinter::processIncludes (recursively)

This reads and processes (but does not print from) all directly or
indirectly included XML schemas of an XML schema. This function calls
itself recursively if necessary.

The includedSchemas std::list that belongs to "this"
xmlSchemaOwlPrinter has the base names (without paths or the .xsd
suffix) of all the schema files directly included by "this"
xmlSchemaOwlPrinter. That list is needed to construct the OWL includes
that go in the header of the OWL file built from the schema.

This saves the owlPrefix for "this" xmlSchemaOwlPrinter by copying
the globalOwlPrefix (which was set by reading the XML schema file
for "this" xmlSchemaOwlPrinter).

The global includeds std::list is a list of the base names of all the
schema files that have already been included from anywhere in the
graph of includes (plus the name of the top level schema file). If a
file already on the list is encountered again, it is not processed.
Thus, this handles circular includes (e.g. schema file A includes
schema file B and schema file B includes schema file A).

The complexClassesAll and simpleClassesAll lists are shared among all
schemas in a set. The pointers for those lists are passed from the
calling xmlSchemaOwlPrinter to its kids here.

*/

void xmlSchemaOwlPrinter::processIncludes( /* ARGUMENTS                      */
 std::list<char *> * includeds, /* list of names of included schema files    */
 std::list<char *> * prefixes)  /* list of prefixes of included schema files */
{
  std::list<XmlSchemaContent1 *>::iterator iter1A;
  std::list<XmlSchemaContent1 *>::iterator iter1B;
  std::list<XmlSchemaContent2 *>::iterator iter2;
  std::list<char *>::iterator iter3;
  xmlSchemaOwlPrinter * owler;
  XmlInclude * incl;
  char bassNameWithPath[NAMESIZE];
  char bassNameNoPath[NAMESIZE];

  for (iter1A = contents1->begin(); iter1A != contents1->end(); iter1A++)
    {
      if ((incl = dynamic_cast<XmlInclude *>(*iter1A)))
	{
	  for (iter3 = includeds->begin(); iter3 != includeds->end(); iter3++)
	    {
	      checkName(incl->schemaLocation, bassNameWithPath, bassNameNoPath);
	      if (strcmp(*iter3, bassNameNoPath) == 0)
		break;
	    }
	  if (iter3 != includeds->end())
	    { // already processed, but need to put name in includedSchemas
	      includedSchemas.push_back(strdup(bassNameNoPath));
	      continue;
	    }
	  owler = new xmlSchemaOwlPrinter;
	  owler->complexClassesAll = complexClassesAll;
	  owler->simpleClassesAll = simpleClassesAll;
	  owler->readSchema(incl->schemaLocation, false);
	  includedSchemas.push_back(owler->baseNameNoPath);
	  owler->owlPrefix = strdup(globalOwlPrefix);
	  prefixes->push_back(owler->owlPrefix);
	  includeds->push_back(owler->baseNameNoPath);
	  owler->processIncludes(includeds, prefixes);
	  owler->buildClasses(false);
	  subordinates.push_back(owler); // add owler to subordinates
	}
    }
}

/********************************************************************/

/* xmlSchemaOwlPrinter::readSchema

Returned Value: none

Called By:
  main
  processIncludes

This reads the schema with the given fileName and sets the following
data members of the xmlSchemaOwlPrinter that is calling:
  baseNameWithPath
  baseNameNoPath
  contents1
  contents2

When the caller is the xmlSchemaOwlPrinter in main, this also sets the
static class attribute XmlCppBase::wg3Prefix.

*/

void xmlSchemaOwlPrinter::readSchema( /* ARGUMENTS                          */
 char * fileName,         /* name of schema to read, including path         */
 bool isTop)              /* true=caller main, false=caller processIncludes */
{
  char * savedPrefix;

  checkName(fileName, baseNameWithPath, baseNameNoPath);
  yyin = fopen(fileName, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", fileName);
      exit(1);
    }
  if (isTop) // if zero, XmlCppBase::wg3Prefix is reset by yylex
    XmlCppBase::wg3Prefix = 0;
  else
    savedPrefix = XmlCppBase::wg3Prefix;
  yyparse();
  fclose(yyin);
  if (!isTop && strncmp(savedPrefix, XmlCppBase::wg3Prefix, NAMESIZE))
    { // should never get here since yylex makes the same check
      fprintf(stderr, 
	      "included files must use same wg3Prefix as including file\n");
      exit(1);
    }
  contents1 = xmlSchemaFile->schema->contents1;
  contents2 = xmlSchemaFile->schema->contents2;
}

/********************************************************************/

/* xmlSchemaOwlPrinter::xmlSchemaOwlPrinter

This is the constructor for the xmlSchemaOwlPrinter class. It puts a
zero in the first place of the className and nameBuffer global (to the
xmlSchemaOwlPrinter) buffers.

*/

xmlSchemaOwlPrinter::xmlSchemaOwlPrinter() /* NO ARGUMENTS */
{
  className[0] = 0;
  nameBuffer[0] = 0;
  topElement = 0;
}

/********************************************************************/

/* xmlSchemaOwlPrinter::~xmlSchemaOwlPrinter

This is the destructor for xmlSchemaOwlPrinter. It does nothing.

*/

xmlSchemaOwlPrinter::~xmlSchemaOwlPrinter() {}

/********************************************************************/

/* main

The first argument (argv[1]) is the name of the top-level XML schema
file to read -- for example, kitting.xsd

The second argument (argv[2]) is the URL to be used in the OWL file,
for example, http://www.nist.gov/el/ontologies
The second argument should not include a slash at the end or the
name of the XML schema file.

*/

int main(       /* ARGUMENTS                                      */
 int argc,      /* one more than the number of command arguments  */
 char * argv[]) /* array of executable name and command arguments */
{
  xmlSchemaOwlPrinter owler;
  std::list<char *> includeds; // list of included schema names
  std::list<char *> prefixes;  // list of prefixes in same order as includeds
  std::list<XmlComplexType *> complexClassesAll; // complex classes all schemas
  std::list<XmlSimpleType *> simpleClassesAll; // simple classes all schemas
  int nameLength;

  if (argc != 3)
    {
      fprintf(stderr, "Usage: %s <schema file name> <URL>\n", argv[0]);
      fprintf(stderr, "example: %s kit.xsd http://www.nist.gov/ontologies\n",
	      argv[0]);
      exit(1);
    }
  nameLength = strlen(argv[1]);
  if (strcmp((argv[1] + nameLength - 4), ".xsd"))
    {
      fprintf(stderr, "file name %s must end in .xsd\n", argv[1]);
      exit(1);
    }
  owler.complexClassesAll = &complexClassesAll;
  owler.simpleClassesAll = &simpleClassesAll;
  owler.readSchema(argv[1], true);
  owler.owlPrefix = strdup(globalOwlPrefix);
  prefixes.push_back(owler.owlPrefix);
  includeds.push_back(owler.baseNameNoPath);
  owler.processIncludes(&includeds, &prefixes);
  owler.buildClasses(true);
  owler.enterKids();
  owler.buildDisjointClasses();
  owler.printOwlClassFiles(argv[2], &includeds, &prefixes);
  return 0;
}

/********************************************************************/
