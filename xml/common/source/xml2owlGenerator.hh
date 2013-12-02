#define NAMESIZE 200
#define TEXTSIZE 2000

/********************************************************************/

/* class xml2owlGenerator

This is the C++ header file for the xml2owlGenerator.

Documentation of class functions is given in xml2owlGenerator.cc.
Documentation of data members of this class follows.

"classes" is a list of all the XmlTypes in the schema (a class results
from each). It is kept in alphabetical order by class name. It is
built by calling buildClasses shortly after each input schemas is parsed.
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

"contents1" and "contents2" are set in readSchema to the contents1 and
contents2 of the most recently read schema file. contents1 is processed
in processIncludes. contents2 is processed in buildClasses.

"haveRead" is a list of the names of schema files that have been read.
It is used in printDriver, processIncludes, and readSchema.

"prefixes" is a list of prefixes that correspond, in the same order,
to the file names in haveRead. It is used in printDriver and readSchema.

"topElement" is a pointer to the root element of the schema. It is set
in buildClasses and used in printCodeEnd, printCodeStart, printHeaderEnd,
printHeaderStart, and main.

"toRead" is a list of the names of schema files that must be read but have
not yet been read. It is used in processIncludes, readSchema, and main.

*/

class xml2owlGenerator
{
public:
  xml2owlGenerator();
  ~xml2owlGenerator();

  void allCaps(char * lowerName, char * upperName);
  void buildClasses(bool isTop);
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
  void printCodePrintElement(XmlElementLocal * element, char * haserName,
			     char * owlPrefix);
  void printCodePrintElementMulti(XmlElementLocal * element, char * haserName,
				  char * owlPrefix, XmlSimpleType * simple,
				  bool isBasic);
  void printCodePrintElementSingle(XmlElementLocal * element, char * haserName,
				   char * owlPrefix, XmlSimpleType * simple,
				   bool isBasic);
  void printCodePrintIndividuals();
  void printCodePrintItems(std::list<XmlChoSeqItem *> * items,
			   char * haserName, char * owlPrefix);
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
  void printCodeSequence(XmlSequence * sequence, XmlComplexType * complx);
  void printCodeSequenceArgs(std::list<XmlChoSeqItem *> * items, int * comma);
  void printCodeSequenceSettings(std::list<XmlChoSeqItem *> * items);
  void printCodeSetsOfIndividuals();
  void printCodeSimple(XmlSimpleType * simple);
  void printCodeStart(char * baseName);
  void printDriver(char * importName, char * baseName, char * treeName);
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
  void printHeaderSchemaClassComplex(XmlComplexType * complx,
         unsigned int * totalPrinted, int * progress);
  void printHeaderSchemaClasses();
  void printHeaderSchemaClassNames();
  void printHeaderSchemaClassSimple(XmlSimpleType * simple,
         unsigned int * totalPrinted, int * progress);
  void printHeaderSequence(XmlSequence * sequence, char * newName,
			   bool abstract);
  void printHeaderSequenceArgs(std::list<XmlChoSeqItem *> * items,
			       int * comma, const char * space);
  void printHeaderSequenceItems(std::list<XmlChoSeqItem *> * items);
  void printHeaderSimple(XmlSimpleType * simple);
  void printHeaderStart();
  void printStarLine(FILE * file, bool before, bool after);
  void processIncludes();
  void readSchema(bool isTop);

  FILE *                           ccFile;
  std::list<XmlType *>             classes;
  char                             className[NAMESIZE];
  std::list<XmlSchemaContent1 *> * contents1;
  std::list<XmlSchemaContent2 *> * contents2;
  std::list<char *>                haveRead;
  FILE *                           hhFile;
  char                             nameBuffer[NAMESIZE];
  char                             otherName[NAMESIZE];
  std::list<char *>                prefixes;
  XmlElementRefable *              topElement;
  std::list<char *>                toRead;
};

/********************************************************************/
