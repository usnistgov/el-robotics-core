#define NAMESIZE 200
#define TEXTSIZE 2000

/********************************************************************/

/* class xmlSchemaOwlPrinter

Documentation of class functions is given in xmlSchemaOwlClassGenerator.cc.
Documentation of data members of this class follows.

"classes" is a list of all the XmlTypes in the schema (a class results
from each). It is kept in alphabetical order by class name. It is
built in buildClasses shortly after the input schema is parsed.
It is used in buildDisjointClasses, enterKids, findComplexClass,
and findSimpleClass.

"complexTypes" is a list of all the complex XmlTypes in the schema.
The order in which it is kept is not significant, but it is kept in
the order in which complex types occur in the schema. It is built in
saveOwlSchemaContent2.

"disjointClasses" is a list of all complex classes in the schema that
are not derived from a parent class.

"simpleTypes" is a list of all the simple XmlTypes in the schema.
The order in which it is kept is not significant, but it is kept in
the order in which simple types occur in the schema. It is built in
saveOwlSchemaContent2.

OWL allows any object to belong to many unrelated classes, whereas in
XML schema, an object belongs to at most one thread of derived
classes.  This generator is intended for use in making OWL models that
behave like XML schema models. OWL includes "DisjointClasses" and
"DisjointUnion" declarations that may be used to prevent objects from
belonging to unrelated classes. The "disjointClasses" list described
above is used to generate an OWL DisjointClasses declaration. The
DisjointUnion declarations are generated from the "extensions"
element of each complex type (see the documentation of XmlComplexType
in xmlSchemaClasses.hh). The extensions list is also used in
printOwlComplexType to print SubClassOf declarations. The extensions
lists of the complex types are built in enterKids.

"className", "nameBuffer", and "otherName" are all buffers that may be
reused. They are used in various places.

"owlPrefix" is the prefix for "this" xmlSchemaOwlPrinter. A tree of
xmlSchemaOwlPrinters is created if there is more than one XML schema file
in the input, one for each schema file. The OWL prefix must be given
in a documentation node near the beginning of the XML schema file.

"topElement" is a pointer to the root element of the schema. It is set
in saveOwlSchemaContent2 and used in printOwlClassFile.

*/

class xmlSchemaOwlPrinter
{
public:
  xmlSchemaOwlPrinter();
  ~xmlSchemaOwlPrinter();

  void buildClasses();
  void buildClassesIncluded();
  void buildDisjointClasses();
  void checkName(char * fileName, char * bassNameWithPath,
		 char * bassNameNoPath);
  void deNameName(char * name, char * buffer);
  void deTypeName(char * name, char * buffer);
  void enterClass(XmlType * aClass);
  void enterKid(XmlComplexType * parent, XmlComplexType * kid);
  void enterKids();
  XmlComplexType * findComplexClass(char * name);
  char * findHasName(char * haser, char * elementName);
  XmlSimpleType * findSimpleClass(char * name);
  void printOwlAnnotation(XmlAnnotation * annotation, FILE * outFile);
  void printOwlChoSeqItem(XmlChoSeqItem * item, FILE * outFile);
  void printOwlClassFile(char * URL, std::list<char *> * includeds,
			 std::list<char *> * prefixes, FILE * outFile);
  void printOwlClassFiles(char * URL, std::list<char *> * includeds,
			  std::list<char *> * prefixes);
  void printOwlComplexContent(XmlComplexContent * complxCont, FILE * outFile);
  void printOwlComplexContentItem (XmlComplexContentItem * item,
				   FILE * outFile);
  void printOwlComplexExtension(XmlComplexExtension * extend, FILE * outFile);
  void printOwlComplexType(XmlComplexType * complx, FILE * outFile);
  void printOwlComplexTypeItem(XmlComplexTypeItem * item, FILE * outFile);
  void printOwlDocumentation(XmlDocumentation * doc, FILE * outFile);
  void printOwlElementLocal(XmlElementLocal * element, FILE * outFile);
  void printOwlElementLocalBuiltIn(XmlElementLocal * element, FILE * outFile);
  void printOwlElementLocalComplex(XmlElementLocal * element,
				   XmlComplexType * complx, FILE * outFile);
  void printOwlElementLocalData(XmlElementLocal * element,
				XmlSimpleType * simple, FILE * outFile);
  void printOwlElementLocalIDREF(XmlElementLocal * element, FILE * outFile);
  void printOwlElementRefable(XmlElementRefable * element, FILE * outFile);
  void printOwlEnumeration(XmlEnumeration * enumeration, FILE * outFile);
  void printOwlIdConstraint(XmlIdConstraint * constraint, char * elementName,
			    FILE * outFile);
  void printOwlMaxExclusive(XmlMaxExclusive * maxExclusive, FILE * outFile);
  void printOwlMaxInclusive(XmlMaxInclusive * maxInclusive, FILE * outFile);
  void printOwlMaxLength(XmlMaxLength * maxLength, FILE * outFile);
  void printOwlMinExclusive(XmlMinExclusive * minExclusive, FILE * outFile);
  void printOwlMinInclusive(XmlMinInclusive * minInclusive, FILE * outFile);
  void printOwlMinLength(XmlMinLength * minLength, FILE * outFile);
  void printOwlOtherContent(XmlOtherContent * otherCont, FILE * outFile);
  void printOwlOtherContentBase(XmlOtherContentBase * base, FILE * outFile);
  void printOwlPattern(XmlPattern * pattern, FILE * outFile);
  void printOwlRestriction(XmlRestrictionType * restrict,  FILE * outFile);
  void printOwlSchemaContent1(XmlSchemaContent1 * content1, FILE * outFile);
  void printOwlSchemaHeader(char * URL, std::list<char *> * includeds,
			    std::list<char *> * prefixes, FILE * outFile);
  void printOwlSequence(XmlSequence * sequence, FILE * outFile);
  void printOwlSimpleList(XmlSimpleList * aList, FILE * outFile);
  void printOwlSimpleRestriction(XmlSimpleRestriction * restrict,
				 FILE * outFile);
  void printOwlSimpleType(XmlSimpleType * simple, FILE * outFile);
  void processIncludes(std::list<char *> * includeds,
		       std::list<char *> * prefixes);
  void readSchema(char * fileName, bool isTop);
  void saveOwlSchemaContent2(XmlSchemaContent2 * content2);

  char                             baseNameNoPath[NAMESIZE];
  char                             baseNameWithPath[NAMESIZE];
  std::list<XmlType *>             classes;
  std::list<XmlType *> *           classesMaster;
  char                             className[NAMESIZE];
  std::list<XmlComplexType *>      complexTypes;
  std::list<XmlSchemaContent1 *> * contents1;
  std::list<XmlSchemaContent2 *> * contents2;
  std::list<XmlComplexType * >     disjointClasses;
  std::list<char *>                includedSchemas;
  char                             nameBuffer[NAMESIZE];
  char                             otherName[NAMESIZE];
  char *                           owlPrefix;
  std::list<XmlSimpleType *>       simpleTypes;
  std::list<xmlSchemaOwlPrinter *> subordinates;
  XmlElementRefable *              topElement;
};

/********************************************************************/
