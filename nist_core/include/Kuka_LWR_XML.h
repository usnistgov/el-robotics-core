///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       XML
//  Workfile:        Kuka_LWR.h
//  Revision:        1.0 - 18 March, 2014
//
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Parser for XML strings for configuring the KUKA LWR
//
///////////////////////////////////////////////////////////////////////////////

#ifndef KUKA_LWR_XML_H
#define KUKA_LWR_XML_H

#include "portable.h"
#include "types.h"
#include "xmlTypes.h"
#include "reporter.h"
#include "serial.h"
#include "socknet.h"

using namespace Reporter;

namespace Xml
{
  class LIBRARY_API KukaLWRParse
  {

  public:

    //! @brief Constructor
    //!
    //! @param serdata  Pointer to a serial connection structure
    //! @param sockdata Pointer to a socket connection structure
    //!
    KukaLWRParse (serialStruct *serdata, networkStruct *sockdata);

    //! @brief Default destructor
    //!
    ~KukaLWRParse ();


    //! NOTE: On changing the XML schema, these are the only functions that
    //!       need to be modified.  Add new flags (*Active_) in the "private"
    //!       section to reflect additions.

    //! @brief Parse the first tag of a tag pair
    //!
    //! @param tagName The tag label
    //! @param attr    String of additional attributes located within the tag
    //!
    //! @return True if parsing is successful
    //!
    bool startElement (const std::string& tagName, 
                       const xmlAttributes& attr);


    //! @brief Parse the second tag of a tag pair
    //!
    //! @param tagName The tag label
    //!
    //! @return True if parsing is successful
    //!
    bool endElement (const std::string& tagName);


    //! @brief Encode an XML string from an input schema
    //!
    //! @param line The output XML string
    //!
    //! @return True if encoding was successful, false otherwise
    //!
    bool encode (char *line);

  private:

    //! @brief Serial connection information
    //!
    serialStruct *serdata_;

    //! @brief Socket connection information
    //!
    networkStruct *sockdata_;

  }; // KukaLWRParse
} // XML

#endif