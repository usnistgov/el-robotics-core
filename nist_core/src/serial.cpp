///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Serial Communications
//  Workfile:        serial.cpp
//  Revision:        1.0 - 25 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Network connectivity - Serial class.  Note that the get and send functions
//  require a serialStruct object passed as an argument.  This way we can have
//  a single network object sending data to multiple destinations simply by
//  passing different serial connection parameters.
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "serial.h"

//#define NOISY

namespace Network
{
  //! *************************************************************************
  //!                       SERIAL COMMUNICATION METHODS
  //! *************************************************************************
  LIBRARY_API serial::serial (networkSettings *settings, Logger *logPtr) :
    logger_(logPtr)
  {
  }


  LIBRARY_API serial::~serial ()
  {
    //settings_ = NULL;
  }


  //! Note:  this function blocks
  LIBRARY_API bool serial::getData (char *buffer, serialStruct serialData)
  {
    DWORD dwBytes;
    do
    {
      ReadFile (serialData.serial, buffer, REQUEST_MSG_SIZE, &dwBytes, NULL);
#ifdef NOISY
      logger_->log (buffer);
#endif
    } while (dwBytes == 0);

    return true;
  }


  LIBRARY_API bool serial::getRawBytes (void *bytes, int &numBytes)
  {
    return false;
  }


  LIBRARY_API bool serial::dataWaiting (serialStruct &conn)
  {
    return false;
  }


  LIBRARY_API bool serial::sendData (const char * buffer, struct serialStruct serialData)
  {
    DWORD dwBytes;
    int resp;

    if (serialData.connected)
    {
#ifdef NOISY
      logger_->log (buffer);
#endif
      resp = WriteFile (serialData.serial, buffer, strlen(buffer) + 1, &dwBytes, NULL);
    }
    else
    {
      logger_->error ("serial::sendData Not connected");
      return false;
    }

    if (resp == ERROR_F)
    {
      return false;
    }

    return true;
  }


  LIBRARY_API bool serial::sendRawBytes (void *bytes, int numBytes)
  {
    return false;
  }


  LIBRARY_API bool serial::create (struct serialStruct& serialData)
  {
    return true;
  } 


  LIBRARY_API bool serial::attach (serialStruct &serialData)
  {
    if (serialData.connected)
    {
      //! We're already connected on this port
      return false;
    }

    serialData.serial = CreateFile (serialData.COMChannel,
                                    GENERIC_READ | GENERIC_WRITE,
                                    0,
                                    NULL,
                                    OPEN_EXISTING,
                                    FILE_ATTRIBUTE_NORMAL,
                                    0);

    //! Initialize serial port
    if (serialData.serial == INVALID_HANDLE_VALUE)
    {
      exception ("serial::attach", "Could not connect to serial port");
      return false;
    }

    serialData.dcb.DCBlength = sizeof (DCB);
    GetCommState (serialData.serial, &serialData.dcb);
    serialData.dcb.BaudRate = serialData.BaudRate;
    serialData.dcb.ByteSize = 8;
    serialData.dcb.Parity = EVENPARITY;
    serialData.dcb.StopBits = ONESTOPBIT;

    //! Initialize COM port
    if (!SetCommState (serialData.serial, &serialData.dcb))
    {
      exception ("serial::attach", "Could not set up COM port");
      return false;
    }

    //! Set up COM port timeouts
    COMMTIMEOUTS CommTimeouts;
    GetCommTimeouts (serialData.serial, &CommTimeouts);
    CommTimeouts.ReadIntervalTimeout = 50;  
    CommTimeouts.ReadTotalTimeoutMultiplier = 50;  
    CommTimeouts.ReadTotalTimeoutConstant = 50;    
    CommTimeouts.WriteTotalTimeoutMultiplier = 50;  
    CommTimeouts.WriteTotalTimeoutConstant = 50;

    //! Check if timeouts setup is valid
    if (!SetCommTimeouts (serialData.serial, &CommTimeouts))
    {
      exception ("serial::attach", "Unable to configure timeouts");
      return false;
    }

    serialData.connected = true;
    return true;
  }


  LIBRARY_API void serial::closeConnection (struct serialStruct& serialData)
  {
    CloseHandle (serialData.serial);
    serialData.connected = false;
  }


  LIBRARY_API void serial::exception (char *where, const char *what)
  {
    static char message[1024];
    sprintf (message, "Exception in \" %s \" : %s", where, what);
    logger_->error (message);
  }
}