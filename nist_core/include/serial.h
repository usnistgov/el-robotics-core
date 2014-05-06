///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Serial Communications
//  Workfile:        serial.h
//  Revision:        1.0 - 18 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  To Do
//
///////////////////////////////////////////////////////////////////////////////

#ifndef serial_h
#define serial_h

/*
#include <conio.h>
*/

#include "reporter.h"
#include "portable.h"
#include "types.h"
<<<<<<< HEAD

/* FMP */
#define EVENPARITY 0
#define ONESTOPBIT 1

typedef struct {
  int DCBlength;
  int BaudRate;
  int ByteSize;
  int Parity;
  int StopBits;
} DCB;

#define GetCommState(a,b) 0
#define SetCommState(a,b) 0
#define GetCommTimeouts(a,b) 0
#define SetCommTimeouts(a,b) 0

typedef struct {
    int ReadIntervalTimeout;  
    int ReadTotalTimeoutMultiplier;  
    int ReadTotalTimeoutConstant;    
    int WriteTotalTimeoutMultiplier;  
    int WriteTotalTimeoutConstant;
} COMMTIMEOUTS;
/* FMP */
=======
>>>>>>> a10c4a171ad417e95d6824ead9dacbd857bfa1ae

using namespace Reporter;

//! @brief Connection information for networking
//!
//! Formerly known as socketStruct
//!
struct LIBRARY_API serialStruct
{
  //! @brief Whether or not this structure has been populated with data
  //!
  bool defined;

  //! @brief Serial port handle
  //!
	HANDLE serial;

  //! @brief TODO
  //!
  DCB dcb;

  //! @brief Communication serial port
  //!
  char *COMChannel;

  //! @brief Baud rate for communication over serial connection
  //!
  DWORD BaudRate;

  //! @brief Whether we are currently connected
  //!
  bool connected;

  //! @brief Default constructor
  //!
  serialStruct() :
    defined(false),
    connected(false),
    COMChannel(NULL)
  {}

  //! @brief Set the COM channel for the serial connection
  //!
  //! @param 
  bool setChannel (int channel)
  {
    if (COMChannel == NULL)
    {
      COMChannel = new char[5];
    }

    sprintf (COMChannel, "COM%d", channel);
    return true;
  }

  //! @brief Set the baud rate for the serial connection
  //!
  //! @param baud The baud rate for the serial connection
  //!
  //! @return True if the baud rate was set successfully, false otherwise
  //!
  bool setBaud (int baud)
  {
#ifdef WIN32
    switch (baud)
    {
    case 110:
      BaudRate = CBR_110;
      break;
    case 300:
      BaudRate = CBR_300;
      break;
    case 1200:
      BaudRate = CBR_1200;
      break;
    case 2400:
      BaudRate = CBR_2400;
      break;
    case 4800:
      BaudRate = CBR_4800;
      break;
    case 9600:
      BaudRate = CBR_9600;
      break;
    case 19200:
      BaudRate = CBR_19200;
      break;
    case 38400:
      BaudRate = CBR_38400;
      break;
    case 57600: 
      BaudRate = CBR_57600;
      break;
    case 115200:
      BaudRate = CBR_115200;
      break;
    default:
      return false;
    }
#endif

    return true;
  }

};



namespace Network
{
  //! @ingroup Network
  //!
  //! @brief Socket connectivity class
  //!
  class LIBRARY_API serial
  {
  public:

    //! @brief Constructor
    //!
    //! @param settings (Not used with serial connection)
    //! @param rep      Pointer to the reporter class owned by the parent
    //!                 process
    //!
    serial (networkSettings *settings);

    //! @brief Default destructor
    //!
    ~serial ();

    //! @brief Create the communication serial connection
    //!
    //! @param serialData Serial connection parameters
    //!
    //! @return TRUE if serial connection created successfully, FALSE otherwise
    //!
    //! @note This function blocks.  Kill/pause any time-sensitive processes
    //!       before calling this function.
    //!       serialData->COMChannel must be defined before calling this function
    //!
    bool create (serialStruct& serialData);

    //! @brief Connect to a serial port
    //!
    //! @param serialData Serial connection parameters
    //!
    //! @return True if we connected to the remote host, False otherwise
    //!
    bool attach (serialStruct &serialData);

    //! @brief Read from an open serial connection
    //!
    //! @param buffer The buffer to be filled with data from the serial connection
    //! @param conn The serial connection to query
    //!
    //! @return True if data was read successfully, False otherwise
    //!
    bool getData (char* buffer, serialStruct conn);

    //! @brief Read raw bytes from an open serial connection (Not currently implemented)
    //!
    //! @param bytes    (Not used)
    //! @param numBytes (Not used)
    //!
    //! @return False
    //!
    bool getRawBytes (void *bytes, int &numBytes);

    //! @brief Query the serial connection to see if data is waiting to be read (Not currently implemented)
    //!
    //! @param conn (Not used)
    //!
    //! @return False
    //!
    bool dataWaiting (serialStruct &conn);

    //! @brief Write data to a serial connection
    //!
    //! @param buffer Data to be written to the socket
    //! @param conn   Serial connection to be written to
    //!
    //! @return True if data was sent successfully, False otherwise
    //!
    bool sendData (const char* buffer, serialStruct conn);

    //! @brief Write raw bytes to an open serial connection (Not currently implemented)
    //!
    //! @param bytes    (Not used)
    //! @param numBytes (Not used)
    //!
    //! @return False
    //!
    bool sendRawBytes (void *bytes, int numBytes);

    //! @brief Close a specified serial connection
    //!
    //! @param conn The serial connection to be closed
    //!
    void closeConnection (serialStruct& conn);

  private:

<<<<<<< HEAD
    //! @brief Display an error message
    //!
    //! @param where The location where the error occurred
    //! @param what  The error type
    //!
    void exception (const char *where, const char *what);

    //! @brief Local pointer to the common log writer from the parent application
    //!
    Logger *logger_;
=======
>>>>>>> a10c4a171ad417e95d6824ead9dacbd857bfa1ae
  };
}

#endif
