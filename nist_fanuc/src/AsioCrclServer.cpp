
/*!
 *	\file		AsioCrclServer.cpp
 *	\brief          The CAsioCrclSession provides an boost asio session ( which listens for each connected client).
 *	\class		CAsioCrclServer
 *	\class		CAsioCrclSession
 *	\author		john michaloski, nist
 *	\date		January 30, 2015
 *      \copyright      Public Domain with disclaimer
 */

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



#include "CrclConfig.h"
#include "AsioCrclServer.h"
#include <boost/exception/all.hpp>
#include <boost/regex.hpp>
#include "Globals.h"
#include "Controller.h"

boost::asio::io_service myios;
bool CAsioCrclServer::bRunning = true;
int CAsioCrclServer::nCount = 0;

static unsigned int MyErrorMessage(std::string errmsg) {
    Logger.Fatal(errmsg.c_str());
    return -1;
}
#ifdef WIN32

static void trans_func(unsigned int u, EXCEPTION_POINTERS *pExp) {
    Logger.Fatal(Logger.StrFormat("PcDmisAdapter trans_func - Code = 0x%x\n",
            pExp->ExceptionRecord->ExceptionCode).c_str());
    throw std::exception();
}
#else

#endif
// --------------------------------------------------------
std::set<CAsioCrclSession *> CAsioCrclSession::_devices;
CAsioMessages CAsioCrclSession::_inmsgs; // remove static if you want sessions to save to own queue
CAsioMessages CAsioCrclSession::_outmsgs;

CAsioCrclSession::CAsioCrclSession(boost::asio::io_service & io_service) : _socket(io_service), _timer(io_service) {
    ErrorMessage = &MyErrorMessage;
    TagReset();
}
void CAsioCrclSession::Disconnect() {
    _timer.cancel();
    _socket.cancel();
    _socket.close();
    _bRunning = false;
    cMessage.notify_all();
}

static void wait_callback(const boost::system::error_code & error, tcp::socket & _socket) // boost::asio::ip::tcp::socket& _socket)
{
    if (error == boost::asio::error::operation_aborted) {
        // Data was read and this timeout was canceled
        return;
    } else if (error) {
        std::cout << "read_timeout Error - " << error.message() << std::endl;

        // Data was read and this timeout was canceled
        return;
    }
    _socket.cancel(); // will cause read_callback to fire with an timeout error_s
}

void CAsioCrclSession::TimerReset() {
    // Setup a deadline time to implement our timeout.
    _timer.expires_from_now(boost::posix_time::milliseconds(2000));
    _timer.async_wait(boost::bind(&wait_callback, boost::asio::placeholders::error, boost::ref(_socket)));
}

void CAsioCrclSession::StartAyncRead() {
    try {
        if (!_socket.is_open()) {
            DebugBreak();
            Disconnect();
        }
        boost::asio::async_read(_socket,
                boost::asio::buffer(data_, max_length), // buff, //boost::asio::buffer(&readBuffer[0], readBuffer.size()),
                boost::bind(&CAsioCrclSession::HandleRead,
                this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));

        TimerReset();
    }    catch (boost::exception & ex) {
        // http://theboostcpplibraries.com/boost.exception
        std::cerr << boost::diagnostic_information(ex);
        _socket.close();
    }    catch (...) {
        _socket.close();
    }
}

void CAsioCrclSession::AppendBuffer(std::string read) {
    if (_next.size() > 0) {
        _current.append(_next);
        _next.clear();
    }
    size_t oldsize = _current.size();
    _current.append(read);
}

void CAsioCrclSession::SaveMessage(std::string xmlmessage) {
    _inmsgs.AddMsgQueue(boost::make_tuple(xmlmessage, this));
    if (CAsioCrclServer::_bTrace)
        Globals.AppendFile(Globals.ExeDirectory + "xmltrace.txt", xmlmessage);
}

void CAsioCrclSession::BufferHandler(std::string & endtag) {
    std::size_t found;

    while ((found = _current.find(endtag)) != std::string::npos) {
        found = found + endtag.size();
        _next = _current.substr(found);
        _current = _current.substr(0, found);
        SaveMessage(_current);
        //_inmsgs.AddMsgQueue(boost::make_tuple(_current, this) );
        _current = _next; // MISSING? when messages are pumped out back to back
        _next.clear();
        endtag = FindLeadingElement(_current);
    }
}

size_t CAsioCrclSession::HandleRead(const error_code & error, size_t result) {
    // Cancel concurrent asio communication timer
    _timer.cancel();

    // Connection closed cleanly by peer
    // asio errors http://www.boost.org/doc/libs/1_44_0/doc/html/boost_asio/reference/error__basic_errors.html
    if ((error == boost::asio::error::eof) || (boost::asio::error::connection_reset == error)) {
        Disconnect();
        return 0;
    } else if (error == boost::asio::error::operation_aborted) {
        // ErrorMessage(" In HandleRead Timer expired error \n");
        // Let pass thru, as we can wait a while between messages
    } else if (error) {
        // This unspecified error stops asynchronous reads
        std::stringstream s;
        s << "unknown HandleRead error = (" << error << ") " << error.message() << std::endl;
        ErrorMessage(s.str());
        return 0;
    }

    if (result > 0) {
        AppendBuffer(std::string(data_, data_ + result));

        if (_endtag == NonsenseTag()) {
            _endtag = FindLeadingElement(_current);

            if (_endtag.empty()) {
                _endtag = NonsenseTag();
            }
        }
        BufferHandler(_endtag);
    }
    StartAyncRead();
    return result;
}

void CAsioCrclSession::SyncWrite(std::string str) {
    // Write data to server that contains a delimiter.
    try {
        _socket.send(boost::asio::buffer(str, str.size()));
    }    catch (boost::system::system_error err) {
        std::cerr << boost::diagnostic_information(err);
    }    catch (...) {
        ErrorMessage("Aborted CAsioCrclSession::SyncWrite\n");
    }
}


void CAsioCrclSession::Session() {
    std::string info;

    try {
#ifdef WIN32
        _set_se_translator(trans_func); // correct thread?
#endif
        _bRunning = true;
        Join(this);
        StartAyncRead();
        boost::mutex::scoped_lock aLock(condMutex);
        cMessage.wait(aLock);
#if 0
        for (CAsioCrclServer::nCount++; CAsioCrclServer::bRunning && _bRunning;) {
            boost::this_thread::sleep(boost::posix_time::milliseconds(1000)); // sleeping 1 second!

            if (this->_inmsgs.SizeMsgQueue() > 0) {
                std::string cmd = _inmsgs.PopFrontMsgQueue();
                Crcl::CanonReturn ret = _inmsgs.Delegate(cmd);
                OutputDebugString(cmd.c_str());

                if (ret == Crcl::CANON_STATUSREPLY) {
                    Crcl::CStatus status = _inmsgs.Delegate()->wm;
                    std::string sStatus = Crcl::CrclMsgInterface().GetStatusReply(&status);
                    SyncWrite(sStatus);
                }
            }
        }
#endif
    }    catch (std::exception & e) {
        //Logger << "Exception in  CAsioCrclSession::Session() thread: " << e.what( ) << "\n";
    }    catch (...) {
        //Logger << "Exception in CAsioCrclSession::Session() thread\n";
    }
    CAsioCrclServer::nCount--;
    Leave(this);
}

// --------------------------------------------------------
// CAsioCrclServer
bool CAsioCrclServer::_bTrace = false;

CAsioCrclServer::CAsioCrclServer(boost::asio::io_service & io_service) :
_io_service(io_service) {
    ErrorMessage = &MyErrorMessage;
    _bInited = false;
    _nHeartbeat = 0;
}

int CAsioCrclServer::Init(std::string domain, long portnumber, std::string devicename) {
    _bInited = true;
    _domainname = domain;
    _portnumber = portnumber;
    _deviceName = devicename;
    return S_OK;
}

void CAsioCrclServer::Start() {
    boost::thread t(boost::bind(&CAsioCrclServer::server, this, boost::ref(_io_service), _portnumber));

}

void CAsioCrclServer::server(boost::asio::io_service & io_service, short port) {
    try {
        // only need one accept for this end point - can have multiple clients
        m_pAcceptor = new tcp::acceptor(io_service, tcp::endpoint(tcp::v4(), port));
        m_pAcceptor->set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
        StartAsyncAccept();

        // Thread will stop here... OR WILL IT - will it fall thru if nothing to process?
        while (CAsioCrclServer::bRunning) {
            _io_service.run(); // Run the io_service object's event processing loop.
        }
    }    catch (...) {
        // Logger << "Fatal Error in CAsioCrclServer::server\n";
    }
}


void CAsioCrclServer::StartAsyncAccept() {
    session_ptr pSession(new CAsioCrclSession(_io_service));

    // session_ptr pSession(_NewSession(_io_service));
    m_pAcceptor->async_accept(pSession->Socket(), bind(&CAsioCrclServer::HandleAsyncAccept, this, pSession, boost::asio::placeholders::error));
}

void CAsioCrclServer::HandleAsyncAccept(session_ptr pSession, const boost::system::error_code & error) // socket_ptr pSocket)
{
    if (CAsioCrclServer::bRunning) {
        //	pSession->_inmsgs.Delegate()->AssignSession(pSession.get());
        boost::thread t(boost::bind(&CAsioCrclSession::Session, pSession));

        if (CAsioCrclServer::bRunning) {
            StartAsyncAccept();
        }
    }
}


void CAsioCrclServer::StopAsyncAccept() {
    try {
        m_pAcceptor->cancel();
    }    catch (boost::system::system_error) {
    }
}

int CAsioCrclServer::Stop() {
    CAsioCrclServer::bRunning = false; // this stops all running threads
    StopAsyncAccept(); // this stops any current accept, i.e., no more future connections

    for (std::set<CAsioCrclSession *>::iterator it = CAsioCrclSession::_devices.begin(); it != CAsioCrclSession::_devices.end(); ++it) {
        (*it)->cMessage.notify_all();
    }

    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    return S_OK;
}

std::string CAsioCrclSession::FindLeadingElement(std::string xml) {
    boost::match_results<std::string::const_iterator> matchResult;
    bool found;
    boost::regex e("<[A-Za-z0-9_]+");
    found = boost::regex_search(xml, matchResult, e);

    if (found) {
        std::string elem(matchResult[0]);
        elem.insert(1, 1, '/');
        elem = Globals.Trim(elem);
        elem.append(">"); // not space
        return elem;
    }
    return NonsenseTag();
}
