///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Behavior Server
//  Subsystem:       CommSocket
//  Workfile:        socknet.h
//  Revision:        1.0 - 6 April, 2006
//                   1.1 - 8 August, 2006 : Modified methods to return boolean
//                                          values instead of integers.
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Network connectivity - Socket class.  Note that the get and send functions
//  require a networkStruct object passed as an argument.  This way we can have
//  a single network object sending data to multiple destinations simply by
//  passing different network connection parameters.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef network_h
#define network_h

#include <conio.h>
#include "reporter.h"
#include "portable.h"
#include "types.h"

using namespace Reporter;

//! @brief Connection information for networking
//!
//! Formerly known as socketStruct
//!
struct LIBRARY_API networkStruct
{
  //! @brief Whether or not this structure has been populated with data
  //!
  bool defined;

  //! @brief Client's socket file descriptor
  //!
  SOCKET cFd;

  //! @brief Server's socket file descriptor
  //!
  SOCKET sFd;

  //! @brief Current computer's IP address
  //!
  char* serverAddress;

  //! @brief Attached computer's IP address
  //!
  char* address;

  //! @brief Client's port number
  //!
  unsigned int cP;

  //! @brief Server's port number
  //!
  unsigned int sP;

  //! @brief Whether we are currently connected (formerly in networkSettings)
  //!
  bool connected;

  //! @brief Whether the server file descriptor is currently bound
  //!
  bool bound;

  //! @brief Whether the socket is a server
  //!
  bool server;

  int bytesRead;
  int bytesSent;

  //! @brief Default constructor
  //!
  networkStruct() :
    defined(false),
    connected(false),
    bound(false),
    server(false),
	bytesRead(0),
	bytesSent(0)
  {
    serverAddress = new char[16];
  }
};



namespace Network
{
  //! @ingroup Network
  //!
  //! @brief Socket connectivity class
  //!
  class LIBRARY_API socketNet
  {
  public:

    //! @brief Constructor
    //!
    //! @param settings Pointer to the system settings structure owned by the
    //!                 parent process
    //!
    socketNet (networkSettings *settings);

    //! @brief Destructor
    //!
    ~socketNet ();

    //! @brief Create the communication socket
    //!
    //! @param socketData Network connection parameters
    //!
    //! @return TRUE if socket created successfully, FALSE otherwise
    //!
    //! @note This function blocks.  Kill/pause any time-sensitive processes
    //!       before calling this function.
    //!       socketData->sP must be defined before calling this function
    //!       Set socketData->bound to TRUE if reusing a socket for multiple
    //!       clients.
    //!
    bool create (networkStruct& socketData);

    //! @brief Connect to a server communication socket
    //!
    //! @param socketData Network connection parameters
    //!
    //! @return True if we connected to the server, False otherwise
    //!
    //! @note socketData->port must be set before calling this function
    //!
    bool attach (networkStruct &socketData);

    //! @brief Read from an open socket
    //!
    //! @param buffer The buffer to be filled with data from the socket
    //! @param socket The socket to query
    //!
    //! @return True if data was read successfully, False otherwise
    //!
    bool getData (char* buffer, networkStruct& socket);

    //! @brief Read raw bytes from an open socket
    //!
    //! @param bytes    TODO
    //! @param numBytes TODO
    //!
    //! @return True if data was read successfully. False otherwise
    //!
    bool getRawBytes (void *bytes, int &numBytes);

    //! @brief Query the socket to see if data is waiting to be read
    //!
    //! @param socket The specifics of the socket to be queried
    //!
    //! @return True if there is data waiting to be read from the socket
    //!
    bool dataWaiting (networkStruct &socket);

    //! @brief Write data to a socket connection
    //!
    //! @param buffer Data to be written to the socket
    //! @param socket Socket to be written to
    //!
    //! @return True if data was sent successfully, False otherwise
    //!
    bool sendData (char* buffer, networkStruct& socket, int bytes = -1);

    //! @brief Write raw bytes to an open socket connection
    //!
    //! @param bytes    TODO
    //! @param numBytes TODO
    //!
    //! @return True if data was sent successfully. False otherwise.
    //!
    bool sendRawBytes (void *bytes, int numBytes);

    //! @brief Close a specified socket connection
    //!
    //! @param socket The socket to be closed
    //!
    void closeConnection (networkStruct& socket);

  private:
    //! @brief Shared pointer to system settings
    //!
    networkSettings *settings_;
  };
}

#endif