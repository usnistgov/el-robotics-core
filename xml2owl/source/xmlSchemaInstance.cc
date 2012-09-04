/*********************************************************************/

#include <stdio.h>              // for fprintf, etc.
#include <stdlib.h>             // for exit
#include <string.h>             // for strcmp
#include <boost/regex.hpp>      // for regexp, etc.
#include "xmlSchemaInstance.hh"

/*********************************************************************/

std::set<std::string> XmlID::allIDs;
int XmlID::lastAuto = 0;
const int XmlID::idSize = 100;
char XmlID::buffer[101];
std::set<std::string> XmlIDREF::allIDREFs;
const int XmlIDREF::idrefSize = 100;

/*********************************************************************/

/*

The printSelf functions here (which are used in printing XML data
files) call the xxxIsBad function before printing.  If the returned
value is true (meaning the data is bad), an error message is printed
to stderr, and this exits.

It might be a good idea to have a global "exit" flag that is checked
by the printSelf functions. If the exit flag is set to true, printSelf
will behave as described above. If the exit flag is set to false, the
printSelf will not print anything to the outFile, will print a warning
message to stderr, and will not exit.

The constructors here that take a char * argument read the argument.
If the argument is valid for the data type, val is set to the value
that is read, and bad is set to false. If the argument is not valid,
bad is set to true and a warning message is printed. The constructor
does not exit if there is an error. It is up to the caller of the
constructor to check the value of bad and decide what to do if bad
is true.

The XXXIsBad functions are necessary even though bad is public and
could be accessed directly because if a descendant type of a built in
type is defined, an XXXIsBad function will be defined for each member of
the chain of descendants, and each of those will call the XXXIsBad
function for its parent.

Although "val" cannot avoid being of the correct C++ type, "bad" may
be true if a value could not be read. Hence, if "val" is set in a
program, "bad" should first be set to false and then be set to xxxIsBad().

*/

/*********************************************************************/

/* class AttributePair

*/

AttributePair::AttributePair() {}

AttributePair::AttributePair(
 char * nameIn,
 char * valIn)
{
  name = nameIn;
  val = valIn;
}

AttributePair::~AttributePair() {}

/*********************************************************************/

/* class SchemaLocation

*/

SchemaLocation::SchemaLocation() {}

SchemaLocation::SchemaLocation(
  char * prefixIn,
  char * locationIn)
{
  prefix = prefixIn;
  location = locationIn;
}

SchemaLocation::~SchemaLocation() {}

void SchemaLocation::printSelf(FILE * outFile)
{
  fprintf(outFile, "  %s:schemaLocation=\"%s\"", prefix, location);
}

/*********************************************************************/

/* class XmlBoolean

This is a class for handling XML basic type boolean.
This is not allowing spaces inside the quotes around "true" and "false".
Might make the value of this be a logical, so that an unset boolean
could have an unknown value.

*/

XmlBoolean::XmlBoolean()
{
  val = true;
  bad = true;
}

XmlBoolean::XmlBoolean(
  char * valIn)
{
  if (strcmp(valIn, "true") == 0)
    {
      val = true;
      bad = false;
    }
  else if (strcmp(valIn, "false") == 0)
    {
      val = false;
      bad = false;
    }
  else
    {
      val = true;
      fprintf(stderr, "%s is not a valid boolean\n", valIn);
      bad = true;
    }
}

XmlBoolean::~XmlBoolean() {}

bool XmlBoolean::XmlBooleanIsBad()
{
  return bad;
}

void XmlBoolean::printSelf(FILE * outFile)
{
  if (XmlBooleanIsBad())
    {
      fprintf(stderr, "boolean value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%s", (val ? "true" : "false"));
}

/*********************************************************************/

/* class XmlDate

This is a class for handling XML basic type date. This is currently
not checking the requirements for a date and is allowing any string.

*/

XmlDate::XmlDate()
{
  val = "";
  bad = true;
}

XmlDate::XmlDate(
  char * valIn)
{
  val = valIn; // automatic conversion
  bad = false;
}

XmlDate::~XmlDate() {}

bool XmlDate::XmlDateIsBad()
{
  return bad;
}

void XmlDate::printSelf(FILE * outFile)
{
  if (XmlDateIsBad())
    {
      fprintf(stderr, "date value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%s", val.c_str());
}

/*********************************************************************/

/* class XmlDateTime

This is a class for handling XML basic type dateTime. This is currently
not checking the requirements for a dateTime and is allowing any string.

*/

XmlDateTime::XmlDateTime()
{
  val = "";
  bad = true;
}

XmlDateTime::XmlDateTime(
  char * valIn)
{
  val = valIn; // automatic conversion
  bad = false;
}

XmlDateTime::~XmlDateTime() {}

bool XmlDateTime::XmlDateTimeIsBad()
{
  return bad;
}

void XmlDateTime::printSelf(FILE * outFile)
{
  if (XmlDateTimeIsBad())
    {
      fprintf(stderr, "dateTime value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%s", val.c_str());
}

/*********************************************************************/

/* class XmlDecimal

This is a class for handling XML basic type decimal.
Might add fussier checks similar to the ones for unsignedInt.

*/

XmlDecimal::XmlDecimal()
{
  val = 0;
  bad = true;
}

XmlDecimal::XmlDecimal(
  char * valIn)
{
  if (sscanf(valIn, "%lf", &val) == 1)
    {
      bad = false;
    }
  else
    {
      fprintf(stderr, "%s is not a valid decimal\n", valIn);
      bad = true;
    }
}

XmlDecimal::~XmlDecimal() {}

bool XmlDecimal::XmlDecimalIsBad()
{
  return bad;
}

void XmlDecimal::printSelf(FILE * outFile)
{
  if (XmlDecimalIsBad())
    {
      fprintf(stderr, "decimal value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%f", val);
}

/*********************************************************************/

/* class XmlDouble

This is a class for handling XML basic type double.
Might add fussier checks similar to the ones for unsignedInt.

*/

XmlDouble::XmlDouble()
{
  val = 0;
  bad = true;
}

XmlDouble::XmlDouble(
  char * valIn)
{
  if (sscanf(valIn, "%lf", &val) == 1)
    {
      bad = false;
    }
  else
    {
      fprintf(stderr, "%s is not a valid double\n", valIn);
      bad = true;
    }
}

XmlDouble::~XmlDouble() {}

bool XmlDouble::XmlDoubleIsBad()
{
  return bad;
}

void XmlDouble::printSelf(FILE * outFile)
{
  if (XmlDoubleIsBad())
    {
      fprintf(stderr, "double value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%f", val);
}

/*********************************************************************/

/* class XmlFloat

This is a class for handling XML basic type float.
Might add fussier checks similar to the ones for unsignedInt.


*/

XmlFloat::XmlFloat()
{
  val = 0.0;
  bad = true;
}

XmlFloat::XmlFloat(
  char * valIn)
{
  if (sscanf(valIn, "%f", &val) == 1)
    {
      bad = false;
    }
  else
    {
      fprintf(stderr, "%s is not a valid float\n", valIn);
      bad = true;
    }
}

XmlFloat::~XmlFloat() {}

bool XmlFloat::XmlFloatIsBad()
{
  return bad;
}

void XmlFloat::printSelf(FILE * outFile)
{
  if (XmlFloatIsBad())
    {
      fprintf(stderr, "float value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%f", val);
}

/*********************************************************************/

/* class XmlID

This is a class for handling XML IDs, which are required to be unique
in any one instance file.

The allIDs, lastAuto, idSize, and buffer static attributes are 
defined at the beginning of this file.

The constructor that takes no arguments assigns a unique value to the
ID of the form autoIdN, where the N at the end is an integer. The
lastAuto attribute keeps the next value of N to use. Before using
that value, however, it is checked whether autoIdN already exists.
If so, N is increased by 1 and the process repeats. This is currently
not checking that all integers have been used up. The "bad" attribute
is set to false.

The constructor that takes the argument valIn checks the length of valIn.
If is is greater than idSize, val is set to "0", and bad is set to true.
Bad is set to true also if the valIn is already used in another XmlID

The allIDs set keeps track of all strings used in instances of
XmlID. Every time a new XmlID is created, its val is recorded in
allIDs. When the destructor is called, the string in the XmlID is
removed from allIDs.

The buffer is a place for constructing a string.

The bad attribute is set to false if the XmlID is OK. It is set to true
if the constructor with the valIn argument contains a value that is too
long (larger than idSize) or a value that is already used for another
XmlID.

It is expected that any program using XmlIDs will check the bad attribute
after calling the constructor with the valIn argument.

The limitation on the size of IDs is probably not necessary, but it may be
useful to the find and insert operations.

*/

XmlID::XmlID()
{
  for (lastAuto++; ; lastAuto++)
    {
      snprintf(buffer, idSize, "autoId%d", lastAuto);
      if (allIDs.find(buffer) == allIDs.end())
	break;
    }
  val = buffer;
  allIDs.insert(val);
  bad = false;
}

XmlID::XmlID(
 char * valIn)
{
  val = valIn; // automatic conversion
  if ((int)val.size() > idSize)
    {
      fprintf(stderr, "the following ID value is too long: %s\n", val.c_str());
      bad = true;
    }
  else if (allIDs.find(val) != allIDs.end())
    {
      fprintf(stderr, "ID value %s is already in use\n", val.c_str());
      bad = true;
    }
  else
    {
      bad = false;
      allIDs.insert(val);
    }
}

XmlID::~XmlID()
{
  allIDs.erase(val);
}

bool XmlID::XmlIDIsBad()
{
  if (bad)
    return true;
  else if ((int)val.size() > idSize)
    return true;
  else if (allIDs.find(val) == allIDs.end())
    return true;
  else
    return false;
}

void XmlID::printSelf(FILE * outFile)
{
  if (XmlIDIsBad())
    {
      fprintf(stderr, "ID %s is bad\n", val.c_str());
      exit(1);
    }
  fprintf(outFile, "%s", val.c_str());
}

/*********************************************************************/

/* class XmlIDREF

This is a class for handling XML IDREFs, which are required to match
XML IDs with the same val. Checking IDREFs agains IDs must be postponed
until an entire data file has been read, so this saves all the IDREFs
in the allIDREFs. The data file parser must do the checking.

Every time a new XmlIDREF is created, its val is recorded in
allIDREFs. When the destructor is called, the string in the XmlIDREF is
removed from allIDREFs.

The allIDREFs and idrefSize static attributes are defined at the
beginning of this file.

The bad attribute is set to false if the XmlIDREF is OK. It is set to true
if the constructor with the valIn argument contains a value that is too
long (larger than idrefSize).

It is expected that any program using XmlIDREFs will check the bad attribute
after calling the constructor with the valIn argument.

The limitation on the size of IDREFs is probably not necessary, but it may be
useful to the find and insert operations.

*/

XmlIDREF::XmlIDREF()
{
  val = "";
  bad = true;
}

XmlIDREF::XmlIDREF(
  char * valIn)
{
  val = valIn; // automatic conversion
  if ((int)val.size() > idrefSize)
    {
      fprintf(stderr, "the following IDREF value is too long: %s\n",
	      val.c_str());
      bad = true;
    }
  else
    {
      bad = false;
      allIDREFs.insert(val);
    }
}

XmlIDREF::~XmlIDREF()
{
  allIDREFs.erase(val);
}

bool XmlIDREF::XmlIDREFIsBad()
{
  if (bad)
    return true;
  else if ((int)val.size() > idrefSize)
    return true;
  else if (allIDREFs.find(val) == allIDREFs.end())
    return true;
  else
    return false;
}

void XmlIDREF::printSelf(FILE * outFile)
{
  if (XmlIDREFIsBad())
    {
      fprintf(stderr, "IDREF %s is bad\n", val.c_str());
      exit(1);
    }
  fprintf(outFile, "%s", val.c_str());
}

bool XmlIDREF::idMissing()
{
  std::set<std::string>::iterator iter;
  for (iter = allIDREFs.begin(); iter != allIDREFs.end(); iter++)
    {
      if (XmlID::allIDs.find(*iter) == XmlID::allIDs.end())
	{
	  fprintf(stderr, "referenced xs:ID %s is not defined\n",
		  iter->c_str());
	  return true;
	}
    }
  return false;
}

/*********************************************************************/

/* class XmlInt

This is a class for handling XML basic type int.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. an optional plus or minus sign followed by
3. a string of one or more digits followed by
4. a sequence of zero or more spaces and tabs

If that checks, it is checked that sscanf can read the number.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlInt::XmlInt()
{
  val = 0;
  bad = true;
}

XmlInt::XmlInt(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[+-]?[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%d", &val) == 1)
	{
	  bad = false;
	}
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid int\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid int\n", valIn);
    }
}

XmlInt::~XmlInt() {}

bool XmlInt::XmlIntIsBad()
{
  return bad;
}

void XmlInt::printSelf(FILE * outFile)
{
  if (XmlIntIsBad())
    {
      fprintf(stderr, "int value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%d", val);
}

/*********************************************************************/

/* class XmlInteger

This is a class for handling XML basic type integer.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. an optional plus or minus sign followed by
3. a string of one or more digits followed by
4. a sequence of zero or more spaces and tabs

If that checks, it is checked that sscanf can read the number.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlInteger::XmlInteger()
{
  val = 0;
  bad = true;
}

XmlInteger::XmlInteger(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[+-]?[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%d", &val) == 1)
	{
	  bad = false;
	}
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid integer\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid integer\n", valIn);
    }
}

XmlInteger::~XmlInteger() {}

bool XmlInteger::XmlIntegerIsBad()
{
  return bad;
}

void XmlInteger::printSelf(FILE * outFile)
{
  if (XmlIntegerIsBad())
    {
      fprintf(stderr, "integer value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%d", val);
}

/*********************************************************************/

/* class XmlLong

This is a class for handling XML basic type long.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. an optional plus or minus sign followed by
3. a string of one or more digits followed by
4. a sequence of zero or more spaces and tabs

If that checks, it is checked that sscanf can read the number.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlLong::XmlLong()
{
  val = 0;
  bad = true;
}

XmlLong::XmlLong(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[+-]?[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%ld", &val) == 1)
	bad = false;
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid long\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid long\n", valIn);
    }
}

XmlLong::~XmlLong() {}

bool XmlLong::XmlLongIsBad()
{
  return bad;
}

void XmlLong::printSelf(FILE * outFile)
{
  if (XmlLongIsBad())
    {
      fprintf(stderr, "long value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%ld", val);
}

/*********************************************************************/

/* class XmlNMTOKEN

This is a class for handling XML basic type NMTOKEN.

The constructor that takes an argument checks that valIn a valid NMTOKEN.
If so, val is set to valIn and bad is set to false.
If not, val is set to the empty string and bad is set to true.

*/

XmlNMTOKEN::XmlNMTOKEN()
{
  val = "";
  bad = true;
}

XmlNMTOKEN::XmlNMTOKEN(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[a-zA-Z0-9:_.-]*$",
			 boost::regex::extended|boost::regex::no_except);
  if(boost::regex_search(valIn, pattern))
    {
      val = valIn; // automatic conversion
      bad = false;
    }
  else
    {
      val = "";
      bad = true;
      fprintf(stderr, "%s is not a valid NMTOKEN\n", valIn);
    }
}

XmlNMTOKEN::~XmlNMTOKEN() {}

bool XmlNMTOKEN::XmlNMTOKENIsBad()
{
  boost::regex pattern;

  if (bad)
    return true;
  else
    {
      pattern = boost::regex("^[a-zA-Z0-9:_.-]*$",
			     boost::regex::extended|boost::regex::no_except);
      if(boost::regex_search(val.c_str(), pattern))
	return false;
      else
	return true;
    }
}

void XmlNMTOKEN::printSelf(FILE * outFile)
{
  if (XmlNMTOKENIsBad())
    {
      fprintf(stderr, "NMTOKEN value %s is bad\n", val.c_str());
      exit(1);
    }
  fprintf(outFile, "%s", val.c_str());
}

/*********************************************************************/

/* class XmlNonNegativeInteger

This is a class for handling XML basic type nonNegativeInteger.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. an optional plus or minus sign followed by
3. a string of one or more digits followed by
4. a sequence of zero or more  spaces and tabs

If that checks, it is checked that sscanf can read the number.
If that checks, it is checked that the value is not negative.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlNonNegativeInteger::XmlNonNegativeInteger()
{
  val = 0;
  bad = true;
}

XmlNonNegativeInteger::XmlNonNegativeInteger(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[+-]?[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%d", &val) == 1)
	{
	  if (val > -1)
	    bad = false;
	  else
	    {
	      val = 0;
	      bad = true;
	      fprintf(stderr, "%s is not a valid nonNegativeInteger\n", valIn);
	    }
	}
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid nonNegativeInteger\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid nonNegativeInteger\n", valIn);
    }
}

XmlNonNegativeInteger::~XmlNonNegativeInteger() {}

bool XmlNonNegativeInteger::XmlNonNegativeIntegerIsBad()
{
  if (bad)
    return true;
  else if (val < 0)
    return true;
  else
    return false;
}

void XmlNonNegativeInteger::printSelf(FILE * outFile)
{
  if (XmlNonNegativeIntegerIsBad())
    {
      fprintf(stderr, "nonNegativeInteger value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%d", val);
}

/*********************************************************************/

/* class XmlPositiveInteger

This is a class for handling XML basic type positiveInteger.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. an optional plus or minus sign followed by
3. a string of one or more digits followed by
4. a sequence of zero or more spaces and tabs

If that checks, it is checked that sscanf can read the number.
If that checks, it is checked that the value is positive.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlPositiveInteger::XmlPositiveInteger()
{
  val = 0;
  bad = true;
}

XmlPositiveInteger::XmlPositiveInteger(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[+-]?[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%d", &val) == 1)
	{
	  if (val > 0)
	    bad = false;
	  else
	    {
	      val = 0;
	      bad = true;
	      fprintf(stderr, "%s is not a valid positiveInteger\n", valIn);
	    }
	}
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid positiveInteger\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid positiveInteger\n", valIn);
    }
}

XmlPositiveInteger::~XmlPositiveInteger() {}

bool XmlPositiveInteger::XmlPositiveIntegerIsBad()
{
  if (bad)
    return true;
  else if (val < 1)
    return true;
  else
    return false;
}

void XmlPositiveInteger::printSelf(FILE * outFile)
{
  if (XmlPositiveIntegerIsBad())
    {
      fprintf(stderr, "positiveInteger value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%d", val);
}

/*********************************************************************/

/* class XmlSchemaInstanceBase

*/

XmlSchemaInstanceBase::XmlSchemaInstanceBase() {}

XmlSchemaInstanceBase::~XmlSchemaInstanceBase() {}

void XmlSchemaInstanceBase::doSpaces(int change, FILE * outFile)
{
  static int spaces = 0;
  static int n;

  if (change)
    spaces += change;
  else
    {
      for (n = 0; n < spaces; n++)
        fputc(' ', outFile);
    }
}

/*********************************************************************/

/* class XmlString

This is a class for handling XML basic type string. 

*/

XmlString::XmlString()
{
  val = "";
  bad = true;
}

XmlString::XmlString(
  char * valIn)
{
  val = valIn; // automatic conversion
  bad = false;
}

XmlString::~XmlString() {}

bool XmlString::XmlStringIsBad()
{
  return bad;
}

void XmlString::printSelf(FILE * outFile)
{
  if (XmlStringIsBad())
    {
      fprintf(stderr, "string value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%s", val.c_str());
}

/*********************************************************************/

/* class XmlUnsignedInt

This is a class for handling XML basic type unsignedInt.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. a string of one or more digits followed by
3. a sequence of zero or more spaces and tabs

If that checks, sscanf is called to read the number.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlUnsignedInt::XmlUnsignedInt()
{
  val = 0;
  bad = true;
}

XmlUnsignedInt::XmlUnsignedInt(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%u", &val) == 1)
	bad = false;
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid unsignedInt\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid unsignedInt\n", valIn);
    }
}

XmlUnsignedInt::~XmlUnsignedInt() {}

bool XmlUnsignedInt::XmlUnsignedIntIsBad()
{
  return bad;
}

void XmlUnsignedInt::printSelf(FILE * outFile)
{
  if (XmlUnsignedIntIsBad())
    {
      fprintf(stderr, "unsignedInt value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%u", val);
}

/*********************************************************************/

/* class XmlUnsignedLong

This is a class for handling XML basic type unsignedLong.

The constructor that takes an argument checks that valIn consists of
1. a sequence of zero or more spaces and tabs followed by
2. a string of one or more digits followed by
3. a sequence of zero or more spaces and tabs

If that checks, sscanf is called to read the number.
If all checks pass, bad is set to false and val is set to the number read.
If any check fails, bad is set to true and val is set to 0.

*/

XmlUnsignedLong::XmlUnsignedLong()
{
  val = 0;
  bad = true;
}

XmlUnsignedLong::XmlUnsignedLong(
  char * valIn)
{
  boost::regex pattern;

  pattern = boost::regex("^[ \t]*[0-9]+[ \t]*$",
			 boost::regex::extended|boost::regex::no_except);
  if (boost::regex_search(valIn, pattern))
    {
      if (sscanf(valIn, "%lu", &val) == 1)
	bad = false;
      else
	{
	  val = 0;
	  bad = true;
	  fprintf(stderr, "%s is not a valid unsignedLong\n", valIn);
	}
    }
  else
    {
      val = 0;
      bad = true;
      fprintf(stderr, "%s is not a valid unsignedLong\n", valIn);
    }
}

XmlUnsignedLong::~XmlUnsignedLong() {}

bool XmlUnsignedLong::XmlUnsignedLongIsBad()
{
  return bad;
}

void XmlUnsignedLong::printSelf(FILE * outFile)
{
  if (XmlUnsignedLongIsBad())
    {
      fprintf(stderr, "unsignedLong value is bad\n");
      exit(1);
    }
  fprintf(outFile, "%lu", val);
}

/*********************************************************************/

/* class XmlVersion

*/

XmlVersion::XmlVersion() {}

XmlVersion::XmlVersion(bool hasEncodingIn)
{
  hasEncoding = hasEncodingIn;
}

XmlVersion::~XmlVersion() {}

void XmlVersion::printSelf(FILE * outFile)
{
  if (hasEncoding)
    fprintf(outFile, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  else
    fprintf(outFile, "<?xml version=\"1.0\"?>\n");
}

/*********************************************************************/

