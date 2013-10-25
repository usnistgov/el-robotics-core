#define NAMESIZE 200
#define TEXTSIZE 2000

/********************************************************************/

/* class xml2owlGenerator

This is the C++ header file for the xml2owlGenerator.

Documentation of class functions is given in xml2owlGenerator.cc.
Documentation of data members of this class follows.

"classes" is a list of all the XmlTypes in the schema (a class results
from each). It is kept in alphabetical order by class name. It is
built in buildClasses shortly after the input schema is parsed.
It is used in checkClasses, enterClass, enterKids, findComplexClass,
findSimpleClass, printCodePrintIndividuals, printCodeSchemaClasses,
printCodeSetsOfIndividuals, printHeaderSchemaClasses, and
printHeaderSchemaClassNames.

The "ccFile" and "hhFile" are file pointers to the code and header files,
respectively. However, since some of the text of the code file is
identical to text in the header file, when the code file is being printed,
hhFile is set to point to the code file. That way, the header printing
functions may be used to print the code file also.

"className", "nameBuffer", and "otherName" are all buffers that may be
reused. They are used in various places.

"topElement" is a pointer to the root element of the schema. It is set
in buildClasses and used in printCodeEnd, printCodeStart, printHeaderEnd,
printHeaderStart, and main.

*/

class xml2owlGenerator
{
public:
  xml2owlGenerator();
  ~xml2owlGenerator();

  void allCaps(char * lowerName, char * upperName);
  void buildClasses(XmlSchema * schema);
  void checkBaseArgs(char * baseName, int * hasSequence);
  void checkClasses();
  void checkNumberRestrictions(std::list<XmlRestrictionType *> * restrictions);
  void deNameName(char * name, char * buffer);
  void deTypeName(char * name, char * buffer);
  void enterClass(XmlType * aClass);
  void enterKid(XmlComplexType * parent, XmlComplexType * kid);
  void enterKids();
  XmlComplexType * findComplexClass(char * name);
  void findCppTypeName(char * wg3TypeName, char * cppTypeName);
  void findRootXmlType(XmlSimpleType * simple, char * rootXmlTypeName);
  XmlSimpleType * findSimpleClass(char * name);
  bool isNumber(char * typeName);
  bool isStringy(char * typeName);
  void printCode(char * baseName);
  void printCodeBaseArgs(char * baseName, int * comma);
  void printCodeComplex(XmlComplexType * complx);
  void printCodeComplexExtend(XmlComplexExtension * extend,
			      XmlComplexType * complx, char * newName);
  void printCodeEnd();
  void printCodeOtherMinimal(char * newName);
  void printCodePrintElement(XmlElementLocal * element, char * haserName);
  void printCodePrintElementMulti(XmlElementLocal * element,
         char * haserName, XmlSimpleType * simple, bool isBasic);
  void printCodePrintElementSingle(XmlElementLocal * element,
         char * haserName, XmlSimpleType * simple, bool isBasic);
  void printCodePrintIndividuals();
  void printCodePrintItems(std::list<XmlChoSeqItem *> * items,
			   char * haserName);
  void printCodePrintParentItems(XmlComplexType * baseClass);
  void printCodeRestrictEnum(char * newName, char * parentName,
			     char * rootCppTypeName, char * rootXmlTypeName,
			     std::list<XmlRestrictionType *> * restrictions);
  void printCodeRestrictNumber(char * newName, char * basicName,
			       char * rootCppTypeName, char * rootXmlTypeName,
			       std::list<XmlRestrictionType *> * restrictions);
  void printCodeRestrictString(char * newName, char * newBase,
			       char * rootCppTypeName, char * rootXmlTypeName,
			       std::list<XmlRestrictionType *> * restrictions);
  void printCodeSchemaClasses();
  void printCodeSequence(XmlSequence * sequence, char * newName, bool abstract);
  void printCodeSequenceArgs(std::list<XmlChoSeqItem *> * items, int * comma);
  void printCodeSequenceSettings(std::list<XmlChoSeqItem *> * items);
  void printCodeSetsOfIndividuals();
  void printCodeSimple(XmlSimpleType * simple);
  void printCodeStart(char * baseName);
  void printDriver(char * baseName, char * treeName);
  void printHeader(char * baseName);
  void printHeaderBaseArgs(char * baseName, int * comma, const char * space);
  void printHeaderComplex(XmlComplexType * complx);
  void printHeaderComplexExtend(XmlComplexExtension * extend,
				char * newName, bool abstract);
  void printHeaderEnd();
  void printHeaderOtherMinimal(char * newName);
  void printHeaderRestrictEnum(char * newName, char * parentName,
			       std::list<XmlRestrictionType *> * restrictions);
  void printHeaderRestrictNumber(char * newName, char * parentName,
			       std::list<XmlRestrictionType *> * restrictions);
  void printHeaderRestrictString(char * newName,  char * parentName,
			       std::list<XmlRestrictionType *> * restrictions);
  void printHeaderSchemaClasses();
  void printHeaderSchemaClassesComplex(XmlComplexType * complx,
         unsigned int * totalPrinted, int * progress);
  void printHeaderSchemaClassesSimple(XmlSimpleType * simple,
         unsigned int * totalPrinted, int * progress);
  void printHeaderSchemaClassNames();
  void printHeaderSequence(XmlSequence * sequence, char * newName,
			   bool abstract);
  void printHeaderSequenceArgs(std::list<XmlChoSeqItem *> * items,
			       int * comma, const char * space);
  void printHeaderSequenceItems(std::list<XmlChoSeqItem *> * items);
  void printHeaderSimple(XmlSimpleType * simple);
  void printHeaderStart();
  void printStarLine(FILE * file, bool before, bool after);

  FILE *                      ccFile;
  std::list<XmlType *>        classes;
  char                        className[NAMESIZE];
  FILE *                      hhFile;
  char                        nameBuffer[NAMESIZE];
  char                        otherName[NAMESIZE];
  XmlElementRefable *         topElement;
};

/********************************************************************/
