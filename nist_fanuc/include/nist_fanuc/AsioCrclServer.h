// AsioCrclServer.h

/*
 * DISCLAIMER:
 * This software was produced by the National Institute of Standards
 * and Technology (NIST), an agency of the U.S. government, and by statute is
 * not subject to copyright in the United States.  Recipients of this software
 * assume all responsibility associated with its operation, modification,
 * maintenance, and subsequent redistribution.
 *
 * See NIST Administration Manual 4.09.07 b and Appendix I.
 */
#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <deque>
#include <set>

#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "CrclInterface.h"
#include "RCSMsgQueue.h"

using boost::asio::ip::tcp;
typedef boost::system::error_code                      error_code;

class CAsioCrclSession;
class CAsioCrclServer;

typedef  boost::tuple<std::string, CAsioCrclSession *>   CrclMessage;
typedef RCS::CMessageQueue<CrclMessage>                CAsioMessages;

// --------------------------------------------------------
class CAsioCrclSession
{
public:
    CAsioCrclSession(boost::asio::io_service & io_service);

    void         AppendBuffer (std::string read);
    void         BufferHandler (std::string & endtag);
    void         Disconnect ( );
    std::string  FindLeadingElement (std::string xml);
    size_t       HandleRead (const error_code & error, size_t bytes_read);
    virtual void Session ( ); // /< This "allows" pluggable change to this class
    void         SaveMessage (std::string xmlmessage);
    tcp::socket & Socket ( )
    {
        return _socket;
    }

    static std::string NonsenseTag ( )
    {
        return "<XXXXX>";
    }
    void         StartAyncRead ( );
    void         SyncWrite (std::string str);

    void TagReset ( )
    {
        _endtag = NonsenseTag( );
    }

    void         TimerReset ( );

    static void Join (CAsioCrclSession *device)
    {
        _devices.insert(device);
    }

    static void Leave (CAsioCrclSession *device)
    {
        _devices.erase(device);
    }

    boost::condition_variable cMessage;
    boost::mutex              condMutex;
    static CAsioMessages &    InMessages ( )
    {
        return _inmsgs;
    }

    static std::set<CAsioCrclSession *> _devices;
protected:
    tcp::socket                 _socket;
    static CAsioMessages        _inmsgs; // remove static if you want sessions to save to own queue
    static CAsioMessages        _outmsgs;
    boost::asio::deadline_timer _timer;
    std::string                 _current;
    std::string                 _next;
    std::string                 _endtag;
    enum { max_length = 4096 };
    char         data_[max_length];
    unsigned int ( *ErrorMessage )(std::string);
    bool _bRunning;
    friend  CAsioCrclServer;
};

typedef boost::shared_ptr<CAsioCrclSession>   session_ptr;

// --------------------------------------------------------
class CAsioCrclServer
{
public:

    CAsioCrclServer(boost::asio::io_service & io_service);

    void server (boost::asio::io_service & io_service, short port);
    void HandleAsyncAccept (session_ptr pSession, const boost::system::error_code & error);
    void StartAsyncAccept ( );
    void StopAsyncAccept ( );
    int  Init (std::string domain, long portnumber, std::string devicename);
    int Quit(void);
    void Start();

    boost::asio::io_service & _io_service;
    tcp::acceptor *           m_pAcceptor;
    bool                      _bInited;
    int                       _portnumber;
    std::string               _domainname;
    std::string               _deviceName;
    bool                      _bLastConnected;
    unsigned int              _nHeartbeat;
    unsigned int              ( *ErrorMessage )(std::string);
    static bool               bRunning;
    static int                nCount;
    static bool               _bTrace;
};

extern boost::asio::io_service myios;
