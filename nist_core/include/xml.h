///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:       XML
//  Workfile:        xml.h
//  Revision:        1.0 - 21 January, 2008
//
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Handler for pure XML strings.  Calls specialized XML parsers.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef XML_H
#define XML_H

#include "portable.h"
#include "types.h"
#include "xmlTypes.h"
#include "reporter.h"

//#include "abb.h"
//#include "abb2.h"
#include "appOptions.h"
//#include "asm.h"
#include "mailman.h"
#include "surgery.h"
#include "Kuka_LWR.h"

using namespace Reporter;

namespace Xml
{
  //! @ingroup Xml
  //!
  //! @brief XML parsing class based on the SAX structure
  //!
  template <class T> class LIBRARY_API XmlParse
  {
  public:

    //! @brief Constructor
    //!
    //! @param strctr TODO
    //! @param logPtr TODO
    //!
    XmlParse (T *strctr, Logger *logPtr);

    //! @brief Destructor
    //!
    ~XmlParse ();

    //! @brief Parse a line of XML tagging, storing the tag value in tag and
    //!        the attribute value in attribute.  
    //!
    //! @param line The input string to be parsed
    //!
    //! @return True if parsing was successful, false otherwise
    //!
    //! The order of attributes coincides with the order of attribute tags
    //! @note Currently only has minimal error handling
    //!
    bool parse (const std::string& line);

    //! @brief Encode an XML string from an input schema
    //!
    //! @param line The output XML string
    //!
    //! @return True if encoding was successful, false otherwise
    //!
    bool encode (char* line);

  private:

    //! @brief Parse the text between the tag pair
    //!
    //! @param ch The string of character located between the tag pair
    //!
    //! @return True if parsing is successful
    //!
    bool characters (const std::vector<std::string>& ch);

    //! @brief Display an error message
    //!
    //! @param where The location where the error occurred
    //! @param what  The error type
    //!
    void exception (char *where, const char *what);

    //! @brief The schema structure being populated by the XML parser
    //!
    T *xmlData_;

    //! @brief TODO
    //!
    Logger *logger_;

  }; // XmlParse
} // Xml namespace

#endif
