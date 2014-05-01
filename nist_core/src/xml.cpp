///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:       XML
//  Workfile:        xml.cpp
//  Revision:        1.0 - 21 January, 2008
//                   1.1 - 4 February, 2008 : Modified to be an exported
//                                            template library for generic XML
//                                            parsing and encoding
//  Author:          J. Marvel
//
//  Description
//  ===========
//  XML parser class definition file.
//
///////////////////////////////////////////////////////////////////////////////

#include "xml.h"
#include <iostream>

using namespace std;

//! Explicit instantiations
//template class LIBRARY_API Xml::XmlParse<Xml::ABBParse>;
//template class LIBRARY_API Xml::XmlParse<Xml::ABB2Parse>;
//template class LIBRARY_API Xml::XmlParse<Xml::ASMParse>;
//template class LIBRARY_API Xml::XmlParse<Xml::MailmanParse>;
//template class LIBRARY_API Xml::XmlParse<Xml::optionParse>;
//template class LIBRARY_API Xml::XmlParse<Xml::SurgeryParse>;
template class LIBRARY_API Xml::XmlParse<Xml::KukaLWRParse>;

namespace Xml
{
  template <class T> XmlParse<T>::XmlParse (T *strctr, Logger *logPtr) :
    xmlData_(strctr),
    logger_(logPtr)
  {
  }


  template <class T> XmlParse<T>::~XmlParse ()
  {
    xmlData_ = NULL;
    logger_ = NULL;
  }


  template <class T> bool XmlParse<T>::characters(const vector<string>& ch)
  {
    vector<string>::const_iterator chIter = ch.begin();

    for (; chIter != ch.end(); ++chIter)
    {
    }

    return true;
  }


  template <class T> bool XmlParse<T>::encode (char *line)
  {
    return xmlData_->encode (line);
  }

  //***************************************************************************
  //                        END CONTEXT-SPECIFIC CODE
  //***************************************************************************

  template <class T> bool XmlParse<T>::parse (const string &line)
  {
    static char buff[1024];
    bool readTags = false;
    bool state = true;
    bool error = false;

    xmlAttributes attr;
    vector<string> chars;

    int marker = 0;
    int openTags = 0;
    bool tagActive = false;
    bool start = false;
    bool single = false;
    bool validXML = false;

    int strLength = line.length();
    int count;
    string temp;
    string name;
    string attrname;
    string attrval;


    try
    {
      while (marker < strLength && !error && line[marker] != '\0')
      {
        if (line[marker] == '<')
        {
          //! ***** Handle tags *****
          tagActive = true;
          for (int i = 0; i < 20; i++)
          {
            buff[i] = ' ';
          }

          name = "";
          ++marker;

          //! Skip white space
          while (line[marker] == ' ' || line[marker] == '\t')
          {
            ++marker;
            if (marker >= (strLength - 1))
            {
              break;
            }
          }

          if (marker >= (strLength - 1))
          {
            //! Ill-formed XML string (end encountered before closing tags
            exception ("XML:parse", "End of string buffer reached before closing tags 1");
            exception ("XML:parse", line.c_str());
            error = true;
            break;
          }

          if (line[marker] == '/')
          {
            start = false;
            marker++;
          }
          else
          {
            start = true;
          }

          int count = 0;
          while (line[marker] != ' ' && line[marker] != '\t' &&
                 line[marker] != '/' && line[marker] != '>' &&
                 marker <= (strLength - 1))
          {
            buff[count] = line[marker];
            count++;
            marker++;
            if (marker >= (strLength - 1))
            {
              break;
            }
          }
          if (marker > (strLength - 1))
          {
            //! Ill-formed XML string (end encountered before closing tags
            exception ("XML:parse", "End of string buffer reached before closing tags 2");
            exception ("XML:parse", line.c_str());
            error = true;
            break;
          }

          buff[count] = '\0';
          name = buff;
          name = name.substr(0, count);

          if (start)
          {
            //! Look for attributes of opening tags
            while (line[marker] != '/' && line[marker] != '>' &&
                   marker <= (strLength -1))
            {
              if (line[marker] != ' ' && line[marker] != '\t' &&
                  line[marker] != '\n')
              {
                //! Non-white-space character & non-terminating element
                //! Ergo, an attribute
                count = 0;

                //! grab the attribute name
                while (line[marker] != '=' && line[marker] != ' ')
                {
                  buff[count++] = line[marker++];
                  if (marker >= strLength - 1)
                  {
                    break;
                  }
                }
                if (marker >= strLength - 1)
                {
                  break;
                }
                buff[count] = '\0';
                attrname = buff;
                attrname = attrname.substr(0, count);
                attr.name.push_back(attrname);

                //! grab the attribute value
                while (line[marker] != '\"')
                {
                  marker++;
                  if (marker >= strLength - 1)
                  {
                    break;
                  }
                }
                marker++;
                if (marker >= strLength - 1)
                {
                  break;
                }

                count = 0;
                while (line[marker] != '\"')
                {
                  buff[count++] = line[marker++];
                  if (marker >= strLength - 1)
                  {
                    break;
                  }
                }
                buff[count] = '\0';
                attrval = buff;
                attrval = attrval.substr(0, count);
                attr.val.push_back(attrval);
              } // if (line[marker] != ' ' && line[marker] != '\t' && line[marker] != '\n')
              marker++;
              if (marker > strLength - 1)
              {
                break;
              }
            } // while (line[marker] != '/' && line[marker] != '>')

            if (marker > (strLength - 1))
            {
              //! Ill-formed XML string (end encountered before closing tags
              exception ("XML:parse", "End of string buffer reached before closing tags 3");
              exception ("XML:parse", line.c_str());
              error = true;
              break;
            } // if (marker > (strLength - 1))

            //! Test for single-tag XML lines (ex. <tag/>
            if (line[marker] == '/')
            {
              single = true;
            }
            while (line[marker] != '>')
            {
              marker++;
              if (marker >= strLength - 1)
              {
                break;
              }
            } // while (line[marker] != '>')
          } // if (start)

          if (error)
          {
            break;
          }

          //! Pass tag information for data structure assignment
          if (start)
          {
            if (state && xmlData_->startElement (name, attr))
            {
              state = true;
              attr.name.clear();
              attr.val.clear();
            }
            else
            {
              state = false;
            }

            validXML = false;
            openTags++;
            readTags = true;
            if (single)
            {
              tagActive = false;
              validXML = true;
              if (state && xmlData_->endElement (name))
              {
                state = true;
              }
              else
              {
                state = false;
              }
              openTags--;
              start = false;
            }
          } // if (start)
          else
          {
            tagActive = false;
            validXML = true;
            if (state && xmlData_->endElement (name))
            {
              state = true;
            }
            else
            {
              state = false;
            }
            openTags--;
          } // if (start) ... else
        } // if (line[marker] == '<')
        else if (tagActive)
        {
          //! ***** Handle text between tags *****
          while(start)
          {
            if (marker > strLength || line[marker] == '<')
            {
              marker--;
              break;
            }

            //! Skip white space
            while (line[marker] == ' ' || line[marker] == '\t' ||
                   line[marker] == '\n' || line[marker] == ',')
            {
              marker++;
              if (marker >= strLength)
              {
                break;
              }
            }

            if (marker > strLength || line[marker] == '<')
            {
              marker--;
              break;
            }

            count = 0;
            while (line[marker] != ',' && line[marker] != '<')
            {
              buff[count++] = line[marker++];
              if (marker >= strLength - 1)
              {
                break;
              }
            }
            if (marker >= (strLength - 1))
            {
              //! Ill-formed XML string (end encountered before closing tags
              exception ("XML:parse", "End of string buffer reached before closing tags 4");
              exception ("XML:parse", line.c_str());
              error = true;
              break;
            }
            if (count > 0)
            {
              temp = buff;
              temp = temp.substr (0, count);
              chars.push_back (temp);
            }
          } // while(start)
          if (start)
          {
            if (state && characters (chars))
            {
              state = true;
            }
            else
            {
              state = false;
            }
            chars.clear ();
          }
          start = false;

        } // else if (tagActive)

        ++marker;
        if (openTags < 1 && readTags)
        {
//          break;
        }
      } // while (marker < strLength && marker < 1024)
/*
      if (state && validXML && (openTags == 0) && !error)
      {
        state = true;
      }
      else
      {
        state = false;
      }
*/
    } // try
    catch (...)
    {
      exception ("XML:parse", "unknown exception");
      exception ("XML:parse", line.c_str());
      return false;
    }

    if (error)
    {
      exception ("XML:parse", "exiting with error");
    }
    return state;
  }


  template <class T> void XmlParse<T>::exception (char *where, const char *what)
  {
    static char message[1024];
    sprintf (message, "Exception in \" %s \" : %s", where, what);
    logger_->error (message);
  }
} // XML