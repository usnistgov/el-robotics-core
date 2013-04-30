/*********************************************************************/

#ifndef XMLSCHEMAINSTANCE_HH
#define XMLSCHEMAINSTANCE_HH

#include <stdio.h>
#include <set>
#include <string>

/*********************************************************************/

class AttributePair;
class SchemaLocation;
class XmlBoolean;
class XmlDate;
class XmlDateTime;
class XmlDecimal;
class XmlDouble;
class XmlFloat;
class XmlID;
class XmlIDREF;
class XmlInt;
class XmlInteger;
class XmlLong;
class XmlNMTOKEN;
class XmlNonNegativeInteger;
class XmlPositiveInteger;
class XmlSchemaInstanceBase;
class XmlString;
class XmlUnsignedInt;
class XmlUnsignedLong;
class XmlVersion;

/*********************************************************************/

class AttributePair
{
public:
  AttributePair();
  AttributePair(
    char * nameIn,
    char * valIn);
  ~AttributePair();

  char * name;
  char * val;
};

/*********************************************************************/

class XmlSchemaInstanceBase
{
public:
  XmlSchemaInstanceBase();
  virtual ~XmlSchemaInstanceBase();
  virtual void printSelf(FILE * outFile) = 0;
  static void doSpaces(int change, FILE * outFile);
};

/*********************************************************************/

class SchemaLocation :
  public XmlSchemaInstanceBase
{
public:
  SchemaLocation();
  SchemaLocation(
    char * prefixIn,
    char * locationIn);
  ~SchemaLocation();
  void printSelf(FILE * outFile);

  char * prefix;
  char * location;
};

/*********************************************************************/

/* class XmlBoolean

This is a class for handling XML basic type boolean.

*/

class XmlBoolean :
  public XmlSchemaInstanceBase
{
public:
  XmlBoolean();
  XmlBoolean(
    const char * valIn);
  ~XmlBoolean();
  void printSelf(FILE * outFile);
  bool XmlBooleanIsBad();

  bool val;
  bool bad;
};

/*********************************************************************/

/* class XmlDate

This is a class for handling XML basic type date.

*/

class XmlDate :
  public XmlSchemaInstanceBase
{
public:
  XmlDate();
  XmlDate(
    char * valIn);
  ~XmlDate();
  void printSelf(FILE * outFile);
  bool XmlDateIsBad();

  std::string val;
  bool bad;
};

/*********************************************************************/

/* class XmlDateTime

This is a class for handling XML basic type dateTime.

*/

class XmlDateTime :
  public XmlSchemaInstanceBase
{
public:
  XmlDateTime();
  XmlDateTime(
    char * valIn);
  ~XmlDateTime();
  void printSelf(FILE * outFile);
  bool XmlDateTimeIsBad();

  std::string val;
  bool bad;
};

/*********************************************************************/

/* class XmlDecimal

This is a class for handling XML basic type decimal.

*/

class XmlDecimal :
  public XmlSchemaInstanceBase
{
public:
  XmlDecimal();
  XmlDecimal(
    const char * valStringIn);
  XmlDecimal(
    double valIn);
  ~XmlDecimal();
  void printSelf(FILE * outFile);
  bool XmlDecimalIsBad();

  double val;
  bool bad;
};

/*********************************************************************/

/* class XmlDouble

This is a class for handling XML basic type double.

*/

class XmlDouble :
  public XmlSchemaInstanceBase
{
public:
  XmlDouble();
  XmlDouble(
    const char * valStringIn);
  XmlDouble(
    double valIn);
  ~XmlDouble();
  void printSelf(FILE * outFile);
  bool XmlDoubleIsBad();

  double val;
  bool bad;
};

/*********************************************************************/

/* class XmlFloat

This is a class for handling XML basic type float.

*/

class XmlFloat :
  public XmlSchemaInstanceBase
{
public:
  XmlFloat();
  XmlFloat(
    const char * valIn);
  ~XmlFloat();
  void printSelf(FILE * outFile);
  bool XmlFloatIsBad();

  float val;
  bool bad;
};

/*********************************************************************/

/* class XmlID

This is a class for handling XML IDs. See documentation in
xmlSchemaInstance.cc. This uses std::string to take advantage of the
built-in find and insert functions for a set of std::string. There are
no analogous built-in functions for a set of char*.

*/

class XmlID :
  public XmlSchemaInstanceBase
{
public:
  XmlID();
  XmlID(
    char * valIn);
  ~XmlID();
  void printSelf(FILE * outFile);
  bool XmlIDIsBad();
 
  static std::set<std::string> allIDs;
  static int lastAuto;
  static const int idSize;
  static char buffer[];
  std::string val;
  bool bad;
};

/*********************************************************************/

/* class XmlIDREF

This is a class for handling XML IDREFs. See documentation in
xmlSchemaInstance.cc. This uses std::string to take advantage of the
built-in find and insert functions for a set of std::string. There are
no analogous built-in functions for a set of char*.

*/

class XmlIDREF :
  public XmlSchemaInstanceBase
{
public:
  XmlIDREF();
  XmlIDREF(
    char * valIn);
  ~XmlIDREF();
  void printSelf(FILE * outFile);
  bool XmlIDREFIsBad();
  static bool idMissing();

  static std::set<std::string> allIDREFs;
  static const int idrefSize;
  std::string val;
  bool bad;
};

/*********************************************************************/

/* class XmlInt

This is a class for handling XML basic type int.

*/

class XmlInt :
  public XmlSchemaInstanceBase
{
public:
  XmlInt();
  XmlInt(
    const char * valIn);
  ~XmlInt();
  void printSelf(FILE * outFile);
  bool XmlIntIsBad();

  int val;
  bool bad;
};

/*********************************************************************/

/* class XmlInteger

This is a class for handling XML basic type integer.
Currently, this cannot handle an arbitrarily large number (a
capability an XML integer is supposed to have).
Might change the type of val to long.

*/

class XmlInteger :
  public XmlSchemaInstanceBase
{
public:
  XmlInteger();
  XmlInteger(
    const char * valIn);
  ~XmlInteger();
  void printSelf(FILE * outFile);
  bool XmlIntegerIsBad();

  int val;
  bool bad;
};

/*********************************************************************/

/* class XmlLong

This is a class for handling XML basic type long.

*/

class XmlLong :
  public XmlSchemaInstanceBase
{
public:
  XmlLong();
  XmlLong(
    const char * valIn);
  ~XmlLong();
  void printSelf(FILE * outFile);
  bool XmlLongIsBad();

  long val;
  bool bad;
};

/*********************************************************************/

/* class XmlNMTOKEN

This is a class for handling XML basic type NMTOKEN.

*/

class XmlNMTOKEN :
  public XmlSchemaInstanceBase
{
public:
  XmlNMTOKEN();
  XmlNMTOKEN(
    char * valIn);
  ~XmlNMTOKEN();
  void printSelf(FILE * outFile);
  bool XmlNMTOKENIsBad();

  std::string val;
  bool bad;
};

/*********************************************************************/

/* class XmlNonNegativeInteger

This is a class for handling XML basic type nonNegativeInteger.
Currently, this cannot handle an arbitrarily large number (a
capability an XML integer is supposed to have).
Might change the type of val to long.

*/

class XmlNonNegativeInteger :
  public XmlSchemaInstanceBase
{
public:
  XmlNonNegativeInteger();
  XmlNonNegativeInteger(
    const char * valIn);
  ~XmlNonNegativeInteger();
  void printSelf(FILE * outFile);
  bool XmlNonNegativeIntegerIsBad();

  int val;
  bool bad;
};

/*********************************************************************/

/* class XmlPositiveInteger

This is a class for handling XML basic type positiveInteger.
Currently, this cannot handle an arbitrarily large number (a
capability an XML integer is supposed to have).
Might change the type of val to long.

*/

class XmlPositiveInteger :
  public XmlSchemaInstanceBase
{
public:
  XmlPositiveInteger();
  XmlPositiveInteger(
    const char * valIn);
  ~XmlPositiveInteger();
  void printSelf(FILE * outFile);
  bool XmlPositiveIntegerIsBad();

  int val;
  bool bad;
};

/*********************************************************************/

/* class XmlString

This is a class for handling XML basic type string.

*/

class XmlString :
  public XmlSchemaInstanceBase
{
public:
  XmlString();
  XmlString(
    char * valIn);
  ~XmlString();
  void printSelf(FILE * outFile);
  bool XmlStringIsBad();

  std::string val;
  bool bad;
};

/*********************************************************************/

/* class XmlUnsignedInt

This is a class for handling XML basic type unsignedInt.

*/

class XmlUnsignedInt :
  public XmlSchemaInstanceBase
{
public:
  XmlUnsignedInt();
  XmlUnsignedInt(
    const char * valIn);
  ~XmlUnsignedInt();
  void printSelf(FILE * outFile);
  bool XmlUnsignedIntIsBad();

  unsigned int val;
  bool bad;
};

/*********************************************************************/

/* class XmlUnsignedLong

This is a class for handling XML basic type unsignedLong.

*/

class XmlUnsignedLong :
  public XmlSchemaInstanceBase
{
public:
  XmlUnsignedLong();
  XmlUnsignedLong(
    const char * valIn);
  ~XmlUnsignedLong();
  void printSelf(FILE * outFile);
  bool XmlUnsignedLongIsBad();

  unsigned long val;
  bool bad;
};

/*********************************************************************/

class XmlVersion :
  public XmlSchemaInstanceBase
{
public:
  XmlVersion();
  XmlVersion(bool hasEncodingIn);
  ~XmlVersion();
  void printSelf(FILE * outFile);

  bool hasEncoding;
};

/*********************************************************************/

#endif // XMLSCHEMAINSTANCE_HH
