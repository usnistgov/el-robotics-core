#define NAMESIZE 200
#define TEXTSIZE 2000

/********************************************************************/

/* class xmlSchemaOwlPrinter

elementInfos is a list of elementInfo in alphabetical order by
element name.

classes is a list of all the XmlTypes in the schema (a class results from each)

*/

class xmlSchemaOwlPrinter
{
public:
  xmlSchemaOwlPrinter();
  ~xmlSchemaOwlPrinter();

  void buildClasses(XmlSchema * schema);
  void buildElementInfo();
  void deNameName(char * name, char * buffer);
  void deTypeName(char * name, char * buffer);
  void enterClass(XmlType * aClass);
  void enterKid(XmlComplexType * parent, XmlComplexType * kid);
  void enterKids();
  XmlComplexType * findComplexClass(char * name);
  XmlSimpleType * findSimpleClass(char * name);
  void printOwlAnnotation(XmlAnnotation * annotation, FILE * outFile);
  void printOwlChoSeqItem(XmlChoSeqItem * item, FILE * outFile);
  void printOwlClassFile(XmlSchema * schemaFile, char * URL, FILE * outFile);
  void printOwlComplexContent(XmlComplexContent * complxCont, FILE * outFile);
  void printOwlComplexContentItem (XmlComplexContentItem * item,
				   FILE * outFile);
  void printOwlComplexExtension(XmlComplexExtension * extend, FILE * outFile);
  void printOwlComplexType(XmlComplexType * complx, FILE * outFile);
  void printOwlComplexTypeItem(XmlComplexTypeItem * item, FILE * outFile);
  void printOwlDocumentation(XmlDocumentation * doc, FILE * outFile);
  void printOwlElementLocal(XmlElementLocal * element, FILE * outFile);
  void printOwlElementLocalBuiltIn(XmlElementLocal * element, FILE * outFile);
  void printOwlElementLocalComplex(XmlElementLocal * element, FILE * outFile);
  void printOwlElementLocalData(XmlElementLocal * element, FILE * outFile);
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
  void printOwlSchemaHeader(XmlSchemaHeader * header, char * URL,
			    FILE * outFile);
  void printOwlSequence(XmlSequence * sequence, FILE * outFile);
  void printOwlSimpleList(XmlSimpleList * aList, FILE * outFile);
  void printOwlSimpleRestriction(XmlSimpleRestriction * restrict,
				 FILE * outFile);
  void printOwlSimpleType(XmlSimpleType * simple, FILE * outFile);
  void saveOwlSchemaContent2(XmlSchemaContent2 * content2);

  std::list<XmlType *>        classes;
  char                        className[NAMESIZE];
  std::list<XmlComplexType *> complexTypes;
  std::list<XmlComplexType *> disjointClasses;
  char                        nameBuffer[NAMESIZE];
  char                        otherName[NAMESIZE];
  std::list<XmlSimpleType *>  simpleTypes;
  XmlElementRefable *         topElement;
};

/********************************************************************/
