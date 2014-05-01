///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:       Reporter
//  Workfile:        PrivateLogger.cpp
//  Revision:        1.0 - 21 January, 2008
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Private disk logger definition file.
//
///////////////////////////////////////////////////////////////////////////////

#include "reporter.h"

namespace Reporter
{
  LIBRARY_API PrivateLogger::PrivateLogger (const char* id)
  {
    char filename[64];
    sprintf (filename, "%s%s.log", NumDateStr (), id);
    out_.open (filename, ios_base::app);
    logMutex_ = CreateMutex (NULL, false, NULL);
  }


  LIBRARY_API PrivateLogger::~PrivateLogger ()
  {
    out_.close ();
  }


  LIBRARY_API void PrivateLogger::log (const char* line)
  {
    WaitForSingleObject (logMutex_, INFINITE);
    out_ << TimeStr () << " " << line << endl;
    ReleaseMutex (logMutex_);
  }


  LIBRARY_API void PrivateLogger::error (const char* line)
  {
    WaitForSingleObject (logMutex_, INFINITE);
    out_ << TimeStr() << " *** ERROR *** " << line << endl;
    ReleaseMutex (logMutex_);
  }
}