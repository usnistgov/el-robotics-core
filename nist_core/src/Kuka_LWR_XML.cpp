///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       XML
//  Workfile:        Kuka_LWR.cpp
//  Revision:        1.0 - 18 March, 2014
//
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Kuka LWR configuration XML parser definitions.
//
///////////////////////////////////////////////////////////////////////////////

// FMP
#include <string.h>		// strcmp
#include <stdlib.h>		// atoi

#include "Kuka_LWR_XML.h"	// FMP

using namespace std;

namespace Xml
{

  LIBRARY_API KukaLWRParse::KukaLWRParse (serialStruct *serdata,
                                          networkStruct *sockdata,
                                          Logger *logPtr) :
    serdata_(serdata),
    sockdata_(sockdata),
    logger_(logPtr)
  {
  }


  LIBRARY_API KukaLWRParse::~KukaLWRParse()
  {
    serdata_ = NULL;
    sockdata_ = NULL;
    logger_ = NULL;
  }


  //***************************************************************************
  //                       BEGIN CONTEXT-SPECIFIC CODE
  //   Modify these functions to reflect the structure of the input XML code
  //***************************************************************************

  /*
  <KUKA_LWR>
  <Serial COM="1" Baud="57600"/>
  <TCP Address="127.0.0.1" Port="1234"/>
  </KUKA_LWR>
  */
  LIBRARY_API bool KukaLWRParse::startElement (const string& tagName, 
                                               const xmlAttributes& attr)
  {
    bool flag = true;
    std::vector<std::string>::const_iterator nameiter = attr.name.begin();
    std::vector<std::string>::const_iterator valiter = attr.val.begin();

    try
    {
      if (strcmp (tagName.c_str(), "KUKA_LWR") == 0)
      {
        //! Kuka nametag - Verify that this XML string is for a Kuka LWR
      }
      else if (strcmp (tagName.c_str(), "Serial") == 0)
      {
        if (!sockdata_->defined)
        {
          serdata_->defined = true;
          for (; nameiter != attr.name.end(); ++nameiter, ++valiter)
          {
            if (strcmp (nameiter->c_str(), "COM") == 0)
            {
              //! Read COM port
              serdata_->setChannel(atoi (valiter->c_str()));
            }
            else if (strcmp (nameiter->c_str(), "Baud") == 0)
            {
              //! Read Baud rate
              serdata_->setBaud(atoi (valiter->c_str()));
            }
          } // for (; nameiter != attr.name.end(); ++nameiter, ++valiter)
        } // if (!sockdata_->defined)
      } // else if (strcmp (tagName.c_str(), "Serial") == 0)
      else if (strcmp (tagName.c_str(), "TCP") == 0)
      {
        //! TODO
      } // else if (strcmp (tagName.c_str(), "TCP") == 0)
      else
      {
        //! Unknown or unsupported tag
        return false;
      }
    } // try
    catch (...)
    {
      exception ("XML:Kuka_LWR startElement", "Unknown error");
      flag = false;
    }

    return flag;
  }


  LIBRARY_API bool KukaLWRParse::endElement(const string& tagName)
  {
    if (strcmp (tagName.c_str(), "KUKA_LWR") == 0)
    {
    }
    else if (strcmp (tagName.c_str(), "Serial") == 0)
    {
    }
    else if (strcmp (tagName.c_str(), "TCP") == 0)
    {
    }
    else
    {
      //! Unknown/unsupported XML tag
      return false;
    }

    return true;
  }


  LIBRARY_API bool KukaLWRParse::encode (char *line)
  {
    return true;
  }


  LIBRARY_API void KukaLWRParse::exception (char *where, char *what)
  {
    static char message[1024];
    sprintf (message, "Exception in \" %s \" : %s", where, what);
    logger_->error (message);
  }
}
