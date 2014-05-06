///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:
//  Workfile:        portable.h
//  Revision:        1.0 - 21 January, 2008
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Variable configuration defintions and declarations for portability between
//  operating systems and compilers.  Also contains miscellaneous utility
//  functions.
//
///////////////////////////////////////////////////////////////////////////////


#ifndef PORTABLE_H
#define PORTABLE_H

#define LARGE_INTEGER long
#define LONGLONG long long

#include <time.h>

//! Define the library import/export 
#ifdef WIN32			/* FMP */

#ifdef LIBRARY_IMPORTS
#define LIBRARY_API __declspec(dllimport)
#else
#define LIBRARY_API __declspec(dllexport)
#endif

#else

#define LIBRARY_API		/* FMP */
typedef void *HANDLE;
typedef short int DWORD;

#define CreateMutex(a,b,c) NULL

#include <limits.h>
#define INFINITE INT_MAX
#define INVALID_HANDLE_VALUE ((void *) -1)

#define WaitForSingleObject(x,y)
#define ReleaseMutex(x)

#define Sleep(x)
#define ReadFile(a,b,c,d,e) 0
#define WriteFile(a,b,c,d,e) 0
#define CreateFile(a,b,c,d,e,f,g) 0
#define CloseHandle(a) 0

#endif

#ifdef WIN32
#include <windows.h>
//! JAM - This is to get rid of an annoying (but harmless) warning MSVC belches
//!       out whenever vectors are used as function parameters.
#pragma warning (disable: 4786)
#pragma warning (disable: 4996)
#pragma warning (disable: 4251)
#endif

//! @brief Enumerated CRCL return types
enum CanonReturn {SUCCESS, FAILURE, REJECT};


//! @brief Enumerated learning algorithm types
//!
enum LearnType {NEURAL_NET, NEURAL_TISSUE, GENETIC_ALGORITHM};

//! Defines
#define GAGENEVERSION 1
#define GAPARAMCOUNT 20

#define INET_ADDR_LEN          128
#define VERSION                1.0

//! Socket defines
#define SERVER_MAX_CONNECTIONS 8      //! max clients connected at a time 
#define REQUEST_MSG_SIZE       8192   //! max size of request message
#define BASE_CONNECTION_PORT   3000   //! default connection port
#define ERROR_F                -1     //! error signal

//! @brief Assembly default declarations
#define defaultTimeWeight        0.8
#define defaultForceWeight       0.2
#define defaultOutWeight         1.0
#define defaultMaxTime           20   //! Seconds
#define defaultMaxForce          80  //! Newtons
#define defaultPopulationSize 10
#define defaultSubpopulationSize 5
#define defaultClanCount 4
#define defaultEtaMinus 0.99
#define defaultEtaPlus 0.92

/*
//! ABB Genetic Algorithms Predefined values
//! @brief Gene descriptor index values
enum {MOVEMETHOD = 0, MOVEID = 1};

//! @brief Mode and search identification values
//!        Position control, natural admittance control, or accommodation
//!        control, or reset the 
enum {RESET = -1, PC = 0, NAC = 1, AC = 2};
//!        Spiral search, radial search, or linear move
enum {SPIRAL = 0, RADIAL = 1, LINEAR = 2};

//! @brief Array index aliases
//! Spiral search parameters
enum {ACSprZForce = 2, ACSprZDepth = 3, ACSprSpeed = 4, ACSprRadius = 5,
      ACSprTurns = 6, ACSprTimeout = 7};
//! Radial search parameters
enum {ACRadZForce = 2, ACRadZDepth = 3, ACRadSpeed = 4, ACRadRange = 5,
      ACRadHopAmp = 6, ACRadHopPer = 7, ACRadCirSpeed = 8, ACRadCirRad = 9,
      ACRadTimeout = 10};
//! Linear move parameters
enum {PCXOffset = 2, PCYOffset = 3, PCZOffset = 4,
      PCXRot = 5, PCYRot = 6, PCZRot = 7};
enum {ACLinXForce = 2, ACLinYForce = 3, ACLinZForce = 4, ACLinXOffset = 5,
      ACLinYOffset = 6, ACLinZOffset = 7, ACLinMinXForce = 8,
      ACLinMaxXForce = 9, ACLinMinYForce = 10, ACLinMaxYForce = 11,
      ACLinMinZForce = 12, ACLinMaxZForce = 13, ACLinTimeout = 14};
enum {NACXPos = 0, NACYPos = 1, NACZPos = 2, NACSpeed = 3, NACTimeout = 4,
      NACMaxForce = 5};
*/


enum statusFlag {None = 0, Move = 1, GetStatus = 2, Quit = 3, Error = 4};

enum methodFlag {PositionControl = 0, ForceControl = 1};



//! @brief Get the value of pi
//!
//! @return Pi to 54 decimal places
//!
inline double pi ()
{
  return 3.141592653589793238462643383279502884197169399375105820;
};


inline double getCurrentTime ()
{
  long time_ll;

#ifdef WIN32
  //! Get time from processor in ticks
  time_ll = GetTickCount ();
  //time_ll = timeGetTime ();
#elif defined VXWORKS
  pentiumTscGet64 (&time_ll);
#elif defined LINUX
  //! TODO
#endif

  //! Set the current time in ms
  return ((double)time_ll * 1.0) / 500000.0;
}


//! @brief Return a formatted string specifying the current date
//!
//! @return The date in the form YYYY-MM-DD
//!
inline const char* NumDateStr ()
{
  static char buffer[12];
  static time_t rawtime;
  static struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  //! YYYY-MM-DD
  strftime (buffer, 12, "%Y-%m-%d", timeinfo);

  return buffer;
};


//! @brief Return a formatted string specifying the time of day
//!
//! @return The time in the form HH:MM:SS
//!
inline const char* TimeStr ()
{
  static char buffer[12];
  static time_t rawtime;
  static struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  //! HH:MM:SS
  strftime (buffer, 12, "%H:%M:%S", timeinfo);

  return buffer;
};


//! @brief Timer class, includes stopwatch and alarm functionality
//!
class timer
{
public:
  //! @brief Default constructor
  //!
  timer () :
    running_(false)
  {
#ifdef WIN32
    highRes_ = (QueryPerformanceFrequency (&frequency_) ? true : false);
    timeBeginPeriod (1);
#endif
  };

  //! @brief Default destructor
  //!
  ~timer ()
  {
#ifdef WIN32			/* FMP */
    timeEndPeriod (1);
#endif
  };

  //! @brief Start the timer if it isn't already running, otherwise
  //!        let it continue to run.
  //!
  inline void start ()
  {
    if (!running_)
    {
      running_ = true;
#ifdef WIN32
    if (highRes_)
    {
      QueryPerformanceCounter (&hRstart_);
    }
    else
    {
      lRstart_ = (long)getCurrentTime ();
    }
#endif
    }
  };

  //! @brief Turn off the timer and start it again from 0
  //!
  inline void restart ()
  {
    running_ = true;
#ifdef WIN32
    if (highRes_)
    {
      QueryPerformanceCounter (&hRstart_);
    }
    else
    {
      lRstart_ = (long)getCurrentTime ();
    }
#endif
  };

  //! @brief Stop the timer and return the elapsed time in ms
  //!
  //! @return The number of milliseconds since the timer was started,
  //!         0.0 if the timer is not currently running
  //!
  inline double stop ()
  {
    if (!running_)
    {
      return 0.0;
    }

#ifdef WIN32
    running_ = false;
    if (highRes_)
    {
      QueryPerformanceCounter (&hRsample_);
      timeDiff_ = hRsample_.QuadPart - hRstart_.QuadPart;
      return ((double)timeDiff_ * 1000.0 /
              (double)frequency_.QuadPart);
    }
    else
    {
      lRsample_ = (long)getCurrentTime ();
      return (lRsample_ - lRstart_);
    }
#endif    
  };

  //! @brief Sample the clock and report the length of time that has
  //!        passed since the timer was started/restarted.
  //!
  //! @return The number of milliseconds since the timer was started,
  //!         0.0 if the timer is not currently running
  //!
  inline double elapsedTime ()
  {
    if (!running_)
    {
      return 0.0;
    }

#ifdef WIN32
    if (highRes_)
    {
      QueryPerformanceCounter (&hRsample_);
      timeDiff_ = hRsample_.QuadPart - hRstart_.QuadPart;
      return ((double)timeDiff_ * 1000.0 /
              (double)frequency_.QuadPart);
    }
    else
    {
      lRsample_ = (long)getCurrentTime ();
      return (lRsample_ - lRstart_);
    }
#endif
  };

  //! @brief Wait until a specific amount of time has passed
  //!
  //! @param ms The time to wait in milliseconds
  //!
  inline void waitUntil (double ms)
  {
    if (highRes_)
    {
      restart ();
      while (elapsedTime () < ms)
      {
#ifdef WIN32
        Sleep (1);
#endif
      }
      stop ();
    }
    else
    {
#ifdef WIN32
      Sleep ((DWORD)ms);
#endif
    }
  };

private:
  //! @brief High resolution timer start time
  //!
  LARGE_INTEGER hRstart_;

  //! @brief High resolution timer sample time
  //!
  LARGE_INTEGER hRsample_;

  //! @brief High resolution system timer frequency
  //!
  LARGE_INTEGER frequency_;

  //! @brief Low resolution timer start time
  //!
  long lRstart_;

  //! @brief Low resolution timer sample time
  //!
  long lRsample_;

  //! @brief High resolution time sample difference variable
  //!
  LONGLONG timeDiff_;

  //! @brief Whether the timer is currently running
  //!
  bool running_;

  //! @brief Whether the system is capable of handling high
  //!        resolution clock sampling
  //!
  bool highRes_;
}; // class timer


inline double sgn (double a)
{
  return (a >= 0.0) ? 1.0 : -1.0;
}

#endif
