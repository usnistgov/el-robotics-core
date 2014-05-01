///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:       Reporter
//  Workfile:        Logger.cpp
//  Revision:        1.0 - 21 January, 2008
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Event logger definition file.
//
///////////////////////////////////////////////////////////////////////////////

#include "reporter.h"

namespace Reporter
{
  LIBRARY_API Logger::Logger ()
  {
    char filename[24];
    sprintf (filename, "%s.log", NumDateStr ());
    out_.open (filename, ios_base::app);
    logMutex_ = CreateMutex (NULL, false, NULL);
  }


  LIBRARY_API Logger::~Logger ()
  {
    out_.close ();
  }


  LIBRARY_API void Logger::log (const char* line)
  {
    WaitForSingleObject (logMutex_, INFINITE);
    out_ << TimeStr () << " " << line << endl;
    ReleaseMutex (logMutex_);
  }


  LIBRARY_API void Logger::error (const char* line)
  {
    WaitForSingleObject (logMutex_, INFINITE);
    out_ << TimeStr() << " *** ERROR *** " << line << endl;
    ReleaseMutex (logMutex_);
  }
}