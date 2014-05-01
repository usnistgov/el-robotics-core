///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:       Reporter
//  Workfile:        reporter.h
//  Revision:        1.0 - 21 January, 2008
//                   1.1 - 5 August, 2008 : Added the screen drawer class
//                                          declaration
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Event logging class for reporting errors and program outputs for debugging
//  purposes.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef REPORTER_H
#define REPORTER_H

#include "..\..\portable.h"
#include <fstream>
#include <windows.h>
#include <vector>

#ifdef WIN32
//! JAM - For some reason, the inclusion of the variable out_ causes the
//!       compiler to spit out a warning concerning library interfaces in order
//!       for clients of the class to use the variable.  Since out_ is a
//!       private member, no clients should ever use it, so this warning can be
//!       safely ignored.
#pragma warning (disable: 4251)
#endif

using namespace std;

namespace Reporter
{
  //! @brief Display adapter for neural networks
  //!
  struct LIBRARY_API NNDisplayAdapter
  {
    //! @brief Collection of node outputs
    //!        [input layer], [hidden layer]...[hidden layer], [output layer]
    //!
    vector < vector <double> > nodeOuts;

    //! @brief Collection of network weights
    //!        [layer0to1] [layer1to2] ... [layern-1ton]
    //!        weights are ordered according to node j in layer K, as they
    //!        reference nodes i in layer K-1
    //!
    vector < vector <double> > linkWeights;

    //! @brief Default constructor
    //!
    NNDisplayAdapter ()
    {
      clear ();
    }

    //! @brief Default destructor
    //!
    ~NNDisplayAdapter ()
    {
      clear ();
    }

    void clear ()
    {
      nodeOuts.clear();
      linkWeights.clear();
    }
  };


  //! @brief Display adapter for neural tissues
  //!
  struct LIBRARY_API NTDisplayAdapter
  {
    //! @brief Collection of node outputs
    //!        [input layer], [hidden layer]...[hidden layer], [output layer]
    //!
    vector < vector < vector <double> > > nodeOuts;

    //! @brief Collection of network weights
    //!        [layer0to1] [layer1to2] ... [layern-1ton]
    //!        weights are ordered according to node j in layer K, as they
    //!        reference nodes i in layer K-1
    //!
    vector < vector < vector <double> > > linkWeights;

    //! @brief Default constructor
    //!
    NTDisplayAdapter ()
    {
      clear ();
    }

    //! @brief Default destructor
    //!
    ~NTDisplayAdapter ()
    {
      clear ();
    }

    void clear ()
    {
      nodeOuts.clear();
      linkWeights.clear();
    }
  };


  //! @ingroup Reporter
  //!
  //! @brief Logging class for error reporting and debugging purposes
  //!
  class LIBRARY_API Logger
  {
  public:
    //! @brief Default constructor
    //!
    Logger ();

    //! @brief Default destructor
    //!
    ~Logger ();

    //! @brief Keep a record of normal program execution
    //!
    //! @param line Reported output to be saved to disk
    //!
    void log (const char* line);

    //! @brief Log an error message
    //!
    //! @param line Reported error to be saved to disk
    //!
    void error (const char* line);

    //! @brief Copy operator
    //!
    //! @param lgr Source of the Logger copy
    //!
    //! @return Reference to the current object
    //!
//    Logger& operator=(const Logger &lgr);

  private:

    //! @brief Handle to the file writer
    //!
    ofstream out_;

    //! @brief Semaphore for properly handling the logger in a multithreaded
    //!        environment
    //!
    HANDLE logMutex_;
  };


  //! @ingroup Reporter
  //!
  //! @brief Logging class for writing individual logs for different processes
  //!
  class LIBRARY_API PrivateLogger
  {
  public:
    //! @brief Default constructor
    //!
    //! @param id A character string uniquely identifying the process that
    //!           owns the logger
    //!
    PrivateLogger (const char* id);

    //! @brief Default destructor
    //!
    ~PrivateLogger ();

    //! @brief Keep a record of normal program execution
    //!
    //! @param line Reported output to be saved to disk
    //!
    void log (const char* line);

    //! @brief Log an error message
    //!
    //! @param line Reported error to be saved to disk
    //!
    void error (const char* line);

  private:

    //! @brief Handle to the file writer
    //!
    ofstream out_;

    //! @brief Semaphore for properly handling the logger in a multithreaded
    //!        environment
    //!
    HANDLE logMutex_;
  };

  /*
  //! @ingroup Reporter
  //!
  //! @brief Logging class for displaying messages to the screen
  //!
  class LIBRARY_API ScreenWriter
  {
  public:
    //! @brief Default constructor
    //!
    ScreenWriter ();

    //! @brief Default destructor
    //!
    ~ScreenWriter ();

    //! @brief Keep a record of normal program execution
    //!
    //! @param line Reported output to be saved to disk
    //!
    void log (const char* line);

    //! @brief Log an error message
    //!
    //! @param line Reported error to be saved to disk
    //!
    void error (const char* line);

  private:

    //! @brief Handle to the file writer
    //!
    //ofstream out_;

    //! @brief Semaphore for properly handling the logger in a multithreaded
    //!        environment
    //!
    HANDLE logMutex_;
  };


  //! @ingroup Reporter
  //!
  //! @brief Graphical display class for neural tissues and networks
  //!
  //! @note Only one instance of this class may exist at a time per program
  //!
  class LIBRARY_API ScreenDrawer
  {
  public:
    //! @brief Default constructor
    //!
    ScreenDrawer ();

    //! @brief Default destructor
    //!
    ~ScreenDrawer ();

    //! @brief Configure the display space
    //!
    //! @param width  The width of the new display window
    //! @param height The height of the new dispaly window
    //! @param title  The text to write on the window title bar
    //!
    static void displayConfig (size_t width,
                               size_t height,
                               char *title = "Reporter");

    //! @brief TODO
    //!
    //! @param disp TODO
    //!
    static void display (NNDisplayAdapter &disp);

    //! @brief TODO
    //!
    static void show ();

  private:
    //! @brief The learning type, to which we will customize our displays as
    //!        the learning type dictates the structure of the graphical
    //!        representation
    //!
    LearnType learn_;
  };
  */
}

#endif