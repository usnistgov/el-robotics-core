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
typedef boost::system::error_code error_code;

class CAsioCrclSession;
class CAsioCrclServer;

typedef boost::tuple<std::string, CAsioCrclSession *> CrclMessage;
typedef RCS::CMessageQueue<CrclMessage> CAsioMessages;

// --------------------------------------------------------

/**
 * \brief The CAsioCrclSession class provides an boost asio session ( which listens for each connected client).
 * The CAsioCrclSession listens for XML messages and constructs.
 * The CAsioCrclSession uses mostly asynchronous operation for waiting, reading, and timeout of a socket connection.
 * The operation is started by creating a session which starts an aynchronous thread, that is supplied IO communication 
 * events by the asio io service provider.  After connection to the socket client, an StartAyncRead() that is paired with a timer
 * is used to wait for communicatin from a socket. There is no trailing marker on CRCL XML so any socket communication must be buffered 
 * and when a complete message has been received, it is pushed onto the inmsgs message queue. During the socket communication, a timeout can 
 * occur, which at this point only causes a new  to beStartAyncRead()  initiated. Because CRCL Xml does not have a trailing marker (e.g., 
 * zero or line feed), the CAsioCrclSession must determine the trailing XML tag to search for, by inspecting the communication for a XML
 * leading tag. It works, but is dubious. However, if the communicating socket is disconnected, an error is returned by asio, and the session
 * is terminated cleanly.
 * <BR> Useful web sites:

<BR>asio read socket
<BR>http://stackoverflow.com/questions/4933610/boostasio-async-read-guarantee-all-bytes-are-read
<BR>http://www.tagwith.com/question_285175_when-do-i-call-boostasiostreambufconsume-and-boostasiostreambufcom
<BR>http://www.dahuatu.com/jdyjaPxKWQ.html
<BR>https://issues.apache.org/jira/browse/THRIFT-311
<BR>http://pastebin.com/Li3wbpvu
<BR>http://geekswithblogs.net/JoshReuben/archive/2014/11/17/c-boost-in-a-nutshell.aspx
<BR>http://pastebin.com/YXk9stVA
<BR>http://thisthread.blogspot.com/2013/09/simple-asio-tcp-clientserver-example.html
<BR>http://dolinked.com/questions/4792923/uninitialized-read-error-on-asio-tcp-socket
<BR>http://onnerby.se/~daniel/mC2/trunk/docs/core/html/_socket_8h-source.html
<BR>http://en.pudn.com/downloads245/sourcecode/internet/proxy/detail1143109_en.html
<BR>http://www.gamedev.net/topic/566670-c-implementing-ssl/
<BR>http://cpp.knowcoding.com/view/20682-tcp-socket.html
<BR>Buffering:
<BR>http://stackoverflow.com/questions/4294651/sending-an-xml-message-in-parts-through-a-tcp-socket-using-qt
<BR>http://www.codesynthesis.com/pipermail/xsde-users/2014-January/000631.html
<BR>Raw:
<BR>http://www.bogotobogo.com/cplusplus/sockets_server_client.php

 */
class CAsioCrclSession {
public:
    /*!
     * \brief Constructor for each listener on the socket.
     * \param io_service reference tot he asio service providers. only one per program.
     */
    CAsioCrclSession(boost::asio::io_service & io_service);

    /*!
     * \brief Appends a socket buffer. Add previous buffer is exists.
     * \param read buffer of characters
     */
    void AppendBuffer(std::string read);

    /*!
     * * \brief Looks for matching end xml tag. If found, saves message into queue, and restarts read process.
     * \param endtag is the ending tag, e.g., </ENDTAG to match against.  Includes backslash.
     */
    void BufferHandler(std::string & endtag);

    /*!
     * * \brief Disconnect timer, socket, and running flags.
     */
    void Disconnect();


    /*!
     *  \brief Finds the leading XML tag to create matching end tag. If none, return nonsense tag. Uses boost regex.
     * \oaram xml is the text to search for starting tag
     * \return end tag or nonsense tag if none. e.g., </TAG>
     */
    std::string FindLeadingElement(std::string xml);

    /*!
     * \brief Handles notification from asio via socket or timeout error or other error.
     * \param error is potential  communiationerror.
     * \param result is the buffer size of the socket read.
     *  \return size of buffer read.
     */
    size_t HandleRead(const error_code & error, size_t bytes_read);

    /*!
     * \brief  For each connection a new Session is started.
     */
    virtual void Session(); // /< This "allows" pluggable change to this class

    /*!
     * \brief Queues message onto message queue.
     * \param xmlmessage to queue onto this session message queue.
     */
    void SaveMessage(std::string xmlmessage);

    /*!
     *  \brief Return the TCP/IP socket from this session.
     */
    tcp::socket & Socket() {
        return _socket;
    }

    /*!
     *  \brief NonsenseTag to be used as dummy ending xml to test against.
     */
    static std::string NonsenseTag() {
        return "<XXXXX>";
    }

    /*!
     *  \brief Starts async read operation. Deadline timer going at same time.
     */
    void StartAyncRead();


    /*!
     *  \brief Handles synchronous socket write of string.
     * \param str is the string to write out on the socket.
     */
    void SyncWrite(std::string str);

    /*!
     * \brief resets the XML ending tag to be non-matchable nonsense.
     */
    void TagReset() {
        _endtag = NonsenseTag();
    }

    /*!
     * \brief Restarts asio timeout timer for async read.  Set at 2 seconds. Invokes callback if timer expires.
     */
    void TimerReset();

    /*!
     * \brief Keeps track of devices that created an asio session.
     */
    static void Join(CAsioCrclSession *device) {
        _devices.insert(device);
    }

    /*!
     * \brief Keeps track of devices that left and are no longer an asio session.
     */
    static void Leave(CAsioCrclSession *device) {
        _devices.erase(device);
    }

    /*!
     *\brief Keeps track of devices that left and are no longer an asio session.
     */
    static CAsioMessages & InMessages() {
        return _inmsgs;
    }

protected:
    static std::set<CAsioCrclSession *> _devices; /**< list of devices being listened to */
    boost::condition_variable cMessage;
    boost::mutex condMutex; /**< mutex to  */
    tcp::socket _socket; /**<  tcp/ip asio socket  */
    static CAsioMessages _inmsgs; /**<  queue of inbound crcl xml messages from device */
    static CAsioMessages _outmsgs; /**<  queue of outbound crcl xml messages to device */
    boost::asio::deadline_timer _timer; /**<  socket reader timer */
    std::string _current; /**<  current string read from socket */
    std::string _next; /**<  leftover string after pulling out Crcl XML message */
    std::string _endtag; /**<  endtag to designate the end of Crcl XML message, found from beginning */

    enum {
        max_length = 4096
    };
    char data_[max_length]; /**<  asio tcp/ip character read buffer */
    unsigned int ( *ErrorMessage)(std::string); /**<  function pointer to error message emitter */
    bool _bRunning; /**<  boolean running loop flag */
    friend CAsioCrclServer;
};

typedef boost::shared_ptr<CAsioCrclSession> session_ptr;

/**
 * * \brief The CAsioCrclServer class provides a boost asio server which accepts new connections and starts a Crcl listener session.
 * The CAsioCrclServer class is based on the Boost Asio library which can process network communication  asynchronously. 
 * Because CRCL data can only be received after a connection has been established, and because a connection can only be established after the name has been resolved, 
 * the various asynchronous operations are started in separate callback handlers. 
 * Thus in boost asio a callback to async_connect() is then followed by a method call to the handler connect_handler() which starts a new Crcl session. 
 * Readers can read more at: http://theboostcpplibraries.com/boost.asio-network-programming 
 * The CAsioCrclServer is  divided into a number of main funcitons (e.g. wait for socket connection,  handle new session by spawning new CAsioCrclSession, 
 * repeat. These operations are done asynchronously on a separate  thread  with notification done by the boost asio io server
 * and it is assumed to be thread-safe.
 * The CAsioCrclServer listens for connections on port 64444 and when a connection is initiated 
 * starts a new Crcl session to read xml messages from the devices.  

 */
class CAsioCrclServer {
public:
    /*!
     * \brief Constructor for asio crcl server that listens on  socket port 64444, and spawns a new session.
     * \param io_service reference tot he asio service providers. only one per program.
     */
    CAsioCrclServer(boost::asio::io_service & io_service);

    /*! 
     *  brief Creates acceptor for tcp/ip endpoint, and starts async accept.
     * \param io_service is asio service.
     * \param port is tcp port to listen for connections on.
     */
    void server(boost::asio::io_service & io_service, short port);

    /*!
     * \brief  Handles new tcp/ip endpoint connection, and starts session thread.Restarts async accept.
     * \param pSession is the latest session pointer associated with connection.
     * \param error is asio error if any.
     */
    void HandleAsyncAccept(session_ptr pSession, const boost::system::error_code & error);

    /*! 
     * \brief Starts asio acceptor to wait for connections.
     */
    void StartAsyncAccept();

    /*!
     * \brief Stop async accept by cancelling asio acceptor.
     * */
    void StopAsyncAccept();


    /*!
     * \brief initializes the server.
     * \param domain gives the domain name (usually localhost).
     * \param portnumber is asio socket port number (usually 64444).
     * \param devicename is the name of the device running this server.
     * */
    int Init(std::string domain, long portnumber, std::string devicename);

    /*!
     * \brief Stop all connection session and future connections.
     * \return error or ok.
     */
    int Stop(void);

    /*!
     * \brief start the asynchronous thread  to listen for connections.
     */
    void Start();
    // ---------------------------------------------------
    boost::asio::io_service & _io_service; /**< reference to asio io server to be passed to each session */
    tcp::acceptor * m_pAcceptor; /**< pointer to asio acceptor   */
    bool _bInited; /**<  server initialized flag */
    int _portnumber; /**<  copy of socket port number to listen to*/
    std::string _domainname; /**<  copy of domain name */
    std::string _deviceName; /**<  copy of device name */
    bool _bLastConnected;
    unsigned int _nHeartbeat; /**<  heartbeat incremented to show server alive */
    unsigned int ( *ErrorMessage)(std::string);
    static bool bRunning; /**<  boolean that all sessions monitor for termination */
    static int nCount; /**<  count of active sessions */
    static bool _bTrace; /**<  trace input messages */
};

extern boost::asio::io_service myios;
