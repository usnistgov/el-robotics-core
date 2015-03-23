///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       XML
//  Workfile:        crcl_xml.h
//  Revision:        1.0 - 21 January, 2008
//                   2.0 - 20 February, 2015 - Subversion integrated into CRPI
//                                             library.
//
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Handler for pure XML strings.  Calls specialized XML parsers.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CRCL_XML_H
#define CRLC_XML_H

#include <vector>
#include <string>
#include "nist_core/nist_core.h"
#include "nist_core/crpi.h"

namespace Xml
{
  //! @brief Inner-tag parameter attributes (ex <tag name="val">)
  //!
  struct xmlAttributes
  {
    //! @brief The list of parameter names
    //!
    std::vector<std::string> name;

    //! @brief The list of parameter values
    //!
    std::vector<std::string> val;
  };

  //! @brief Parsed CRPI commands based on CRCL XML schemas
  //!
  struct CrclXmlParams
  {
    //! @brief The CRPI command type
    //!
    CanonCommand cmd;

    //! @brief The X axis orientation vector (first column of rotation matrix)
    //!
    orientVect xaxis;

    //! @brief The Z axis orientation vector (third column of rotation matrix)
    //!
    orientVect zaxis;

    //! @brief Unknown what this value actually is.  CRCL uses it in a variety of
    //!        different ways.
    //!
    double numPositions;

    //! @brief Unknown what commands use this.
    //!
    double setting;

    //! @brief Commanded pose (X, Y, Z values only populated, orientation set using
    //!        xaxis and zaxis variables)
    //!
    robotPose *pose;

    //! @brief Commanded joint values
    //!
    robotAxes *axes;

    //! @brief TODO
    bool moveStraight;

    //! @brief Current robot status
    //!
    CanonReturn status;

    //! @brief String value for plain-text parameters
    //!
    std::string str;

    //! @brief The name of the gripper currently coupled to the robot
    //!
    std::string toolName;

    int commandID;

    //! @brief The commanded value for the tool
    //!
    double toolVal;

    unsigned int counter;

    CrclXmlParams()
    {
      pose = new robotPose();
      axes = new robotAxes();
      moveStraight = true;
      setting = numPositions = 0.0f;
      counter = 0;
    }
  };


  //! @ingroup Xml
  //!
  //! @brief XML parsing class based on the SAX structure
  //!
  class LIBRARY_API CrclXml
  {
  public:

    //! @brief Constructor
    //!
    CrclXml (CrclXmlParams *params);

    //! @brief Default destructor
    //!
    ~CrclXml ();

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

    CrclXmlParams *params_;

    bool xaxisactive;
    bool zaxisactive;

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

    //! @brief Parse the first tag of a tag pair
    //!
    //! @param tagName The tag label
    //! @param attr    String of additional attributes located within the tag
    //!
    //! @return True if parsing is successful
    //!
    bool startElement (const std::string& tagName, 
                       const xmlAttributes& attr);

    //! @brief Parse the first tag of a tag pair
    //!
    //! @param tagName The tag label
    //! @param attr    String of additional attributes located within the tag
    //!
    //! @return True if parsing is successful
    //!
    bool interTagElement (const std::string& tagName, 
                          const std::vector<std::string>& attr);

    //! @brief Parse the second tag of a tag pair
    //!
    //! @param tagName The tag label
    //!
    //! @return True if parsing is successful
    //!
    bool endElement (const std::string& tagName);

  }; // CrclXml
} // Xml namespace

#endif