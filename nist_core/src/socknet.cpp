///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Behavior Server
//  Subsystem:       CommSocket
//  Workfile:        socknet.cpp
//  Revision:        1.0 - 6 April, 2006
//                   1.1 - 8 August, 2006 : Updated for different return types
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


#define _WIN32_WINNT 0x0500
#define _WINSOCKAPI_

#include <stdio.h>
#include <winsock2.h>
#include "socknet.h"

//#define NOISY

namespace Network
{
  //! *************************************************************************
  //!                              SOCKET METHODS
  //! *************************************************************************
  
	LIBRARY_API socketNet::socketNet (networkSettings *settings) :
    settings_(settings)
  {
  }


  LIBRARY_API socketNet::~socketNet ()
  {
    settings_ = NULL;
  }

  LIBRARY_API bool socketNet::dataWaiting (networkStruct &socket)
  {
    static char buff[REQUEST_MSG_SIZE];
    int nRead;
    u_long l = 1;
    ioctlsocket(socket.cFd, FIONBIO, &l);

    //! Peak at the buffer and return true if there is anything waiting
    nRead = recv (socket.cFd, buff, REQUEST_MSG_SIZE, MSG_PEEK);

    l = 0;
    ioctlsocket(socket.cFd, FIONBIO, &l);

    if (nRead == SOCKET_ERROR)
    {
      nRead = WSAGetLastError();
      if (nRead == WSAECONNRESET || nRead == WSAECONNABORTED || nRead == WSAENETRESET ||
          nRead == WSAENETUNREACH || nRead == WSAENOTCONN || nRead == WSAESHUTDOWN ||
          nRead == WSAEHOSTDOWN || nRead == WSAEHOSTUNREACH || nRead == WSAEDISCON ||
		  nRead == WSAENOTSOCK)
      {
        //! Connection shut down
        closeConnection (socket);
      }
      return false;
    } // if (resp < 0)
    return (nRead > 0) ? true : false;
  }


  LIBRARY_API bool socketNet::getData (char *buffer, networkStruct& socket)
  {
    int nRead;
    static char b2[32];
    buffer[0] = '\0';

    nRead = recv (socket.cFd, buffer, REQUEST_MSG_SIZE, 0);
	socket.bytesRead = nRead;
    if (nRead < 0)
    {
      nRead = WSAGetLastError();
 
      if (nRead == WSAECONNRESET || nRead == WSAECONNABORTED || nRead == WSAENETRESET ||
          nRead == WSAENETUNREACH || nRead == WSAENOTCONN || nRead == WSAESHUTDOWN ||
          nRead == WSAEHOSTDOWN || nRead == WSAEHOSTUNREACH || nRead == WSAEDISCON ||
          nRead == WSANOTINITIALISED || nRead == WSAENOTSOCK)
      {
        //! Check for error from read()
        sprintf (b2, "read %d", nRead);
        perror (b2);

        //! Connection shut down
        closeConnection (socket);
      }
      return false;
    } // if (nRead < 0)
    else if (nRead > 0) 
    {
      buffer[nRead] = '\0';
      return true;
    } // else if (nRead > 0)
    return false;
  }


  LIBRARY_API bool socketNet::sendData (char * buffer, struct networkStruct& socket, int bytes)
  {
    static char b2[32];
    int resp;
	if (bytes < 0)
	{
	    resp = send (socket.cFd, buffer, strlen(buffer)+1, 0);
	}
	else
	{
		resp = send (socket.cFd, buffer, bytes, 0);
	}
	socket.bytesSent = resp;

    if (resp < 0)
    {
      resp = WSAGetLastError();
      sprintf (b2, "send %d", resp);
      perror (b2);
      if (resp == WSAECONNRESET || resp == WSAECONNABORTED || resp == WSAENETRESET ||
          resp == WSAENETUNREACH || resp == WSAENOTCONN || resp == WSAESHUTDOWN ||
          resp == WSAEHOSTDOWN || resp == WSAEHOSTUNREACH || resp == WSAEDISCON ||
		  resp == WSAENOTSOCK)
      {
        //! Connection shut down
        closeConnection (socket);
		//socket.connected = false;
      }
      return false;
    } // if (resp < 0)
    return true;
  }


  LIBRARY_API bool socketNet::create (struct networkStruct& socketData)
  {
    char ac[32];
    char *client_ip_address = NULL;
    HANDLE hTimer = NULL;
    LARGE_INTEGER liDueTime;
    liDueTime.QuadPart=-30000000;  //! 3 second timer for polling

    struct sockaddr_in serverAddr; //! server's socket address
    struct sockaddr_in clientAddr; //! client's socket address 
    int sockAddrSize;              //! size of socket address structure
    SOCKET newFd;                  //! socket descriptor from accept
    int ix = 0;                    //! counter for work task names
    int tcpServer_shutdown = 0;
    unsigned long l = 1;           //! to set sockets to nonblocking
    int ret, i;
    BOOL bOptVal = TRUE;
    int bOptLen = sizeof(BOOL);


    hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (NULL == hTimer)
    {
      //! Timer error
    }

    //! Set up the local address
    sockAddrSize = sizeof (struct sockaddr_in);

    WSADATA wsaData;
    int wsaret = WSAStartup(0x101, &wsaData);
    if (wsaret != 0)
    {
      return false;
    }
    //! Clear (zero-out) serverAddr
    memset((char *) &serverAddr, 0, sockAddrSize);
    serverAddr.sin_addr.s_addr = htons (INADDR_ANY);
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons ((u_short)socketData.sP); 

    gethostname(ac, sizeof(ac));
    struct hostent *phe = gethostbyname(ac);

    //socketData.serverAddress = new char[128];//inet_ntoa (serverAddr.sin_addr);
    struct in_addr a1;//, a2, a3, a4;

    i = 0;
    //while (phe->h_addr_list[i] != 0)
    {
      memcpy (&a1, phe->h_addr_list[i], sizeof(struct in_addr));
      sprintf (socketData.serverAddress, "%s", inet_ntoa(a1));
      ++i;
    }

    //! This allows us to have multiple clients attached to the same port
    if (!socketData.bound)
    {
      //! create a TCP-based socket
      ret = socketData.sFd = socket(AF_INET, SOCK_STREAM, 0); 
      if (ret < 0)
      {
#ifdef NOISY
        ret = WSAGetLastError();
        sprintf (ac, "socket %d", ret);
        perror (ac);
#endif
        closeConnection (socketData);
        return false; 
      } // if (ret < 0)

      if (setsockopt(socketData.sFd, SOL_SOCKET, SO_REUSEADDR, (char*)&bOptVal, bOptLen) != SOCKET_ERROR)
      {
        //! Error setting bind option
      }

      //! bind socket to local address
      ret = bind (socketData.sFd, (struct sockaddr *) &serverAddr, sockAddrSize);
      if (ret < 0)
      {
#ifdef NOISY
        ret = WSAGetLastError();
        sprintf (ac, "bind %d", ret);
        perror (ac);
#endif
        closeConnection (socketData); 

        return false; 
      } // if (ret < 0)
      socketData.bound = true;
    } // if (!socketData.bound)

    //ioctlsocket (socketData.sFd, FIONBIO, &l);
    
    //! Create queue for client connection requests
    if (listen (socketData.sFd, SERVER_MAX_CONNECTIONS) < 0)
    { 
      closeConnection (socketData);
      return false;
    } // if (listen (socketData.sFd, SERVER_MAX_CONNECTIONS) < 0)

    //! Accept new connect requests and spawn tasks to process them
    //! Accept the first connection and use it...
    newFd = 0;
    do
    {
      //! If we stop the connection attempt
      bool okay;
      okay = false;
      do
      {
        if (!settings_->globalRunServer)
        {
          closeConnection (socketData);
          return false;
        }

        unsigned long l = 1;
        ioctlsocket (socketData.sFd, FIONBIO, &l);
        while (settings_->globalRunServer)
        {
          ret = newFd = accept (socketData.sFd, (struct sockaddr*)&clientAddr, &sockAddrSize);
          if (ret > 0)
          {
            break;
          }
          else
          {
            ret = WSAGetLastError();
            if (ret != WSAEWOULDBLOCK)
            {
              break;
            }
          }
          Sleep (100);
        }
        l = 0;
        ioctlsocket (socketData.sFd, FIONBIO, &l);

        if (!settings_->globalRunServer)
        {
          closeConnection (socketData);
          return false;
        }

        if (ret < 0) 
        {
          printf ("%s\n", inet_ntoa (clientAddr.sin_addr));

#ifdef NOISY
          ret = WSAGetLastError();
          sprintf (ac, "accept %d", ret);
          perror (ac);
#endif

          //! We expect the error WSAEWOULDBLOCK since the socket is non-blocking
          if (ret != WSAEWOULDBLOCK)
          {
            closeConnection (socketData);
            return false; 
          }
          Sleep (100);
        }
        else
        {
          okay = true;
        }
      } while (!okay);

      if (newFd > 0)
      {
        client_ip_address = inet_ntoa (clientAddr.sin_addr);
        //! JAM: A problem encountered with Windows is that it constantly
        //!      thinks a connection from 204.204.204.204:52428 is being
        //!      made
        if (strcmp("204.204.204.204", client_ip_address) != 0)
        {
          //! fill out the struct
          socketData.cFd = newFd;
          socketData.address = client_ip_address;
          socketData.cP = ntohs (clientAddr.sin_port);

          //! Disable nonblocking by default
          //unsigned long l = 0;
          //ioctlsocket (socketData.cFd, FIONBIO, &l);
          tcpServer_shutdown = 1;  //! say we are done
        } // if (strcmp("204.204.204.204", client_ip_address) != 0)
      } // if (newFd > 0)
    } while (tcpServer_shutdown != 1);
    socketData.connected = true;
    settings_->connected = true;

    return true;
  } 


  LIBRARY_API bool socketNet::attach (networkStruct &socketData)
  {
    int ret;
    sockaddr_in local, server;
    static char b2[32];
    BOOL bOptVal = TRUE;
    int bOptLen = sizeof(BOOL);

    //! Bind the socket to the system
    WSADATA wsaData;
    int wsaret;
  
    if ((wsaret = WSAStartup(0x101, &wsaData)) != 0)
    {
      return false; //! Could not bind
    }

    local.sin_family = AF_INET;
    local.sin_addr.s_addr = INADDR_ANY;
    local.sin_port = htons(socketData.cP);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(socketData.address);
    server.sin_port = htons(socketData.sP);

    //! create a TCP-based socket
    ret = socketData.cFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ret < 0) 
    {
      ret = WSAGetLastError();
      sprintf (b2, "socket %d", ret);
      perror (b2);

      return false; 
    }

    //! bind socket to local address
    if (setsockopt(socketData.cFd, SOL_SOCKET, SO_REUSEADDR, (char*)&bOptVal, bOptLen) != SOCKET_ERROR)
    {
      //! Error setting bind option
		int i = 13;
			//! place holder errer
    }

    ret = bind (socketData.cFd, (struct sockaddr *) &local, sizeof(local));
    if (ret < 0) 
    {
      ret = WSAGetLastError();
      sprintf (b2, "bind %d", ret);
      perror (b2);

      //! Win32:  closesocket (SOCKET s)
      closeConnection (socketData); 

      return false; 
    } // if (ret < 0) 
    socketData.sFd = connect(socketData.cFd, (struct sockaddr*)&server, sizeof(server));
    if (socketData.sFd >= 0)
    {
      //! fill out the struct
      unsigned long l = 1;
      ioctlsocket (socketData.sFd, FIONBIO, &l);
      socketData.connected = true;
      settings_->connected = true;
      return true;
    } // if (socketData.sFd >= 0)
    else
    {
      int x = WSAGetLastError();
      sprintf (b2, "connect %d", x);
      perror (b2);
    }

    socketData.connected = false;
    settings_->connected = false;
    return false;
  }


  LIBRARY_API void socketNet::closeConnection (struct networkStruct& socket)
  {
    /*
    int x;
    char b2[32];
    */

    //if (socket.server)
    {
      shutdown (socket.sFd, SD_BOTH);
      if (closesocket (socket.sFd) < 0)
      {
        //! close socket error
        /*
        x = WSAGetLastError();
        sprintf (b2, "closesocket %d", x);
        perror (b2);
        */
      }
    }
    //else
    {
      shutdown (socket.cFd, SD_BOTH);
      if (closesocket (socket.cFd) < 0)
      {
        //! close socket error
        /*
        x = WSAGetLastError();
        sprintf (b2, "closesocket %d", x);
        perror (b2);
        */
      }
    }

    //WSACleanup ();
    socket.bound = false;
    socket.connected = false;
    settings_->connected = false;
  }


  LIBRARY_API bool socketNet::sendRawBytes (void *bytes, int numBytes)
  {
	/*
	static char b2[32];
    int resp;
    resp = send (socket.cFd, buffer, numBytes, 0);

    if (resp < 0)
    {
      resp = WSAGetLastError();
      sprintf (b2, "send %d", resp);
      perror (b2);
      if (resp == WSAECONNRESET || resp == WSAECONNABORTED || resp == WSAENETRESET ||
          resp == WSAENETUNREACH || resp == WSAENOTCONN || resp == WSAESHUTDOWN ||
          resp == WSAEHOSTDOWN || resp == WSAEHOSTUNREACH || resp == WSAEDISCON ||
		  resp == WSAENOTSOCK)
      {
        //! Connection shut down
        closeConnection (socket);
		//socket.connected = false;
      }
      return false;
    } // if (resp < 0)
    */
    return true;
  }

  LIBRARY_API bool socketNet::getRawBytes (void *bytes, int &numBytes)
  {
	return true;
  }

}