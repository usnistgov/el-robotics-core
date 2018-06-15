#include "qtthreading.h"
#include <QApplication>
#include <QProcess>

#include "mainwindow.h"

#include "simple_message_defs.h"
#include <stddef.h>		// NULL, sizeof
#include <stdio.h>		// printf
#include <stdlib.h>		// atoi, strtof
#include <ctype.h>		// isspace
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */

#ifdef WIN32
# include <winsock2.h>
#include <conio.h>
//#include <winioctl.h>
#include <ws2tcpip.h>
#include <NIST/ioctl.h>
#undef SendMessage
#else
# include <sys/socket.h>
#include <sys/ioctl.h>
#endif
#include <fcntl.h>


#include "NIST/Globals.h"
#include "NIST/hexdump.h"
using namespace simple_message;
extern MainWindow * mainwin;
static bool debug = true;


////////////////////////////////////////////////////////////////////////////
//
QtSocketThreadBase::QtSocketThreadBase(QThread *parent) :
    QThread(parent), pause (false)
{
    mRunThread = false;
    socket=NULL;
    connect(this, SIGNAL(TypedMessageEmitted(int, QString)), mainwin, SLOT(TypedMessage(int, QString)));
}
void QtSocketThreadBase::SendMessage(std::string str, int type)
{
    QString s;
    s=QString::fromStdString(str);
    emit  TypedMessageEmitted(type, s);
}
void QtSocketThreadBase::connection(const QString &ipAddr, const ushort port )
{
    //Message = std::bind(&MainWindow::Message,mainwin,_1);
    mIP= ipAddr ;
    mPort= port ;
}
void QtSocketThreadBase::disconnect()
{
    if(!Globals.bQuitting)
        socket->close();
}

void QtSocketThreadBase::setRunThread(bool newVal )
{
    QMutexLocker lock( &mMutex );
    mRunThread = newVal;
}

bool QtSocketThreadBase::getRunThread()
{
    QMutexLocker lock( &mMutex );
    return mRunThread;
}
 bool QtSocketThreadBase::isRunning()
 {
    return getRunThread();
 }

void QtSocketThreadBase::startThread()
{
    setRunThread( true );
    start();
}

void QtSocketThreadBase::stopThread()
{
    setRunThread( false );
}

// THis is blocking read
int QtSocketThreadBase::readBytes(void *buffer, size_t size, bool nothrow)
{
    if(socket->state() != QAbstractSocket::ConnectedState)
    {
        std::string err = Globals.StrFormat("%s::%d socket closed\n", mIP.toStdString().c_str(), mPort);
        if(nothrow)
            return false;
        else
            throw std::runtime_error( tr(err.c_str()).toStdString());
     }

    socket->waitForReadyRead(-1);  // wait on any socket input
    qint64 csize= socket->read((char *) buffer, size);
    return csize;

}

void QtSocketThreadBase::suspend()
{
    sync.lock();
    pause = true;
    sync.unlock();
}
bool QtSocketThreadBase::writeBytes(void * buffer, size_t size, bool nothrow)
{
    QMutexLocker lock( &mMutex );
    if(socket==NULL)
    {
        SendMessage("Connect First", 3); // message box!
        return false;
    }
    if(socket->state() != QAbstractSocket::ConnectedState)
    {
        std::string err = Globals.StrFormat("%s::%d socket closed\n", mIP.toStdString().c_str(), mPort);
        // only run thread handles throw
        if(nothrow)
            return false;
        else
            throw std::runtime_error( tr(err.c_str()).toStdString());
    }
    socket->write((char *) buffer,size);
    socket->flush(); socket->flush();
    return true;
}
int QtSocketThreadBase::waitForInput( )
{
    int bytesAvail = -1;
    while (socket->state() == QAbstractSocket::ConnectedState && getRunThread() && bytesAvail < 0) {
        if (socket->waitForReadyRead( 100 )) {
            bytesAvail = socket->bytesAvailable();
        }
        else {
            sleep( 50 );
        }
    }
    return bytesAvail;
}


void QtSocketThreadBase::run()
{
    assert(0); // should be overridden
}
void QtSocketThreadBase::waitIfPaused()
{
    sync.lock();
    if(pause)
        pauseCond.wait(&sync); // in this place, your thread will stop to execute until someone calls resume
    sync.unlock();
}

void QtSocketThreadBase::multiline_ascii_write(std::string lines)
{
    std::istringstream f(lines);
    std::string line;
    QString msg;
    if(socket->state() != QAbstractSocket::ConnectedState)
    {
        std::string err = Globals.StrFormat("%s::%d socket closed\n", mIP.toStdString().c_str(), mPort);
        throw std::runtime_error( tr(err.c_str()).toStdString());
    }
    while (std::getline(f, line)) {
        msg= QString::fromStdString(line);
        qDebug(msg.toLatin1());
        socket->write( (msg + "\n").toLatin1().data() );
        socket->flush();
        sleep(1);

    }
}

///////////////////////////////////////////////////////////////
// State client code that we read

QtStatusConnection::QtStatusConnection(QThread *parent ): QtSocketThreadBase(parent)
{
    type=STATUS;
    // connect(this, SIGNAL(MessageEmitted(std::string)), mainwin, SLOT(Message(std::string)));
    // doesn't work
    //connect(this, SIGNAL(UpdateJointsEmitted(QStringList)), mainwin, SLOT(set_joint_display(QStringList)));
}
void QtStatusConnection::SendJoints()
{
    emit  UpdateJointsEmitted();
}





void QtStatusConnection::run()
{
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    int nchars;
    int length;
    int message_type;
    robot_status_message robot_status;
    joint_traj_pt_state_message jtp_state;
    object_state_message obj_state;
    int fd;

    setPriority(LowPriority);

    socket = new QTcpSocket(  );

    std::string msg = Globals.StrFormat("Status Connecting to %s::%d\n", mIP.toStdString().c_str(),  mPort);
    SendMessage(msg,STATUS);
    // Can't pass socket connection between threads :(
    int iTimeOut=10000; // in milliseconds
    do {
        socket->connectToHost(mIP,mPort);
    } while (!socket->waitForConnected(iTimeOut)); /// && ++iTrial < iMaxTrials);

#if 0
    fd= socket->socketDescriptor();
    int enabled = 1;;
    setsockopt(fd, SOL_SOCKET, SO_TIMESTAMP, &enabled, sizeof(enabled));
    socket->setSocketDescriptor(fd);
#endif

    msg = Globals.StrFormat("Status %s::%d connected\n", mIP.toStdString().c_str(),  mPort);
    SendMessage(msg,STATUS);
    std::string buffer;
    buffer.reserve(INBUF_LEN);

    while (getRunThread()) {
        waitIfPaused();  // wait if thread paused
        msleep(10);
        if( socket->state() != QTcpSocket::ConnectedState )
        {
            setRunThread(false);
            continue;
        }

        nchars = readBytes( inbuf, sizeof(inbuf));
        if( nchars< 0 )
        {
            setRunThread(false);
            continue;
        }
        if( nchars>0)
        {
            buffer.insert(buffer.size(), (const char*) inbuf, nchars);
#if 0
            struct timeval tv_ioctl;
            tv_ioctl.tv_sec = 0;
            tv_ioctl.tv_usec = 0;
            int error = ioctl(fd, SIOCGSTAMP, &tv_ioctl);
            qDebug(Globals.StrFormat("%ld.%ld - error = %d", (long int)tv_ioctl.tv_sec,
                                     (long int)tv_ioctl.tv_usec, error).c_str());
#endif

        }

        if(buffer.size()==0)
        {
            msleep(100);
            continue;
        }

        // use string as fifo buffer, inbuf to process with ptr
        memcpy(inbuf, &buffer[0], INBUF_LEN);
        ptr = inbuf;

        // get the length and type of the message
        memcpy(&length, ptr, sizeof(length));
        memcpy(&message_type, ptr + sizeof(length), sizeof(message_type));

        if(swap_byte_order)
        {
            swapbytes((void *) &length, sizeof(length));
            swapbytes((void *) &message_type, sizeof(message_type));
        }

        // switch on the message type and handle it
        switch (message_type) {
        case MESSAGE_ROBOT_STATUS:
            qDebug("Decode MESSAGE_ROBOT_STATUS");
            robot_status.read_robot_status(ptr);
           if(swap_byte_order)
                robot_status.byte_swap();
           the_robot.read(&robot_status);

            if (debug && (Globals.bDebugMask & DEBUG_STATE))
                SendMessage(robot_status.print_robot_status(), STATUS);
            if(Globals.bHexdump)
                SendMessage(NIST::HexDump(&robot_status, sizeof(robot_status), 20), STATUS);
            break;
            /* NOTE: JOINT_POSITION is deprecated, but JOINT_TRAJ_PT gives
       an error in the industrial robot client. */
        case MESSAGE_JOINT_POSITION:
            SendMessage("Decode MESSAGE_JOINT_POSITION", STATUS);
            jtp_state.read_joint_traj_pt_state(ptr);
            if(swap_byte_order)
                jtp_state.byte_swap();
            the_robot.read(&jtp_state);

            SendJoints();

            if (debug && (Globals.bDebugMask & DEBUG_FEEDBACK))
                SendMessage(jtp_state.print_joint_traj_pt_state(), STATUS);
            if(Globals.bHexdump)
                SendMessage(NIST::HexDump(&jtp_state, sizeof(jtp_state), 20), STATUS);
            break;
        case MESSAGE_OBJECT_STATE:
#if 0
            obj_state.read_object_state(ptr);
            if(swap_byte_order())
                obj_state.byte_swap();
            if (debug && (Globals.bDebugMask & DEBUG_STATE))
                SendMessage(obj_state.print_object_state(), STATUS);
#endif
            break;
        default:
            // unknown message
            qDebug("unknown status type: %d\n", message_type);
            break;
        } // switch (message type)
        buffer=buffer.substr(length+sizeof(length));
    }   // while (true)

    disconnect();

    if (debug && (Globals.bDebugMask & DEBUG_RUN))
        SendMessage("joint message client handler  done\n", STATUS);

    return;
}
/////////////////////////////////////////////////////////////////////////
/// \brief SimpleMessageTest::seqnum
///
///
///
QtCommandConnection::QtCommandConnection(QThread *parent ): QtSocketThreadBase(parent)
{
    type=COMMAND;
    // connect(this, SIGNAL(MessageEmitted(std::string)), mainwin, SLOT(Message(std::string)));
}



void QtCommandConnection::run()
{
    enum {INBUF_LEN = 1024};
    char inbuf[INBUF_LEN];
    char *ptr;
    int nchars;
    int length;
    int message_type;
    joint_traj_pt_reply_message jtp_rep;
    cart_traj_pt_reply_message ctp_rep;
    ping_reply_message ping_rep;

    socket = new QTcpSocket(  );
    std::string msg = Globals.StrFormat("Command Connecting to %s::%d\n", mIP.toStdString().c_str(),  mPort);
    SendMessage(msg,COMMAND);
    int iTimeOut=10000; // in milliseconds
    // Connecting should be done in this thread ....
    do {
        socket->connectToHost(mIP,mPort);
    } while (!socket->waitForConnected(iTimeOut)); /// && ++iTrial < iMaxTrials);

    SendMessage(Globals.StrFormat("%s::%d connected\n", mIP.toStdString().c_str(), mPort), COMMAND);
    std::string buffer;
    buffer.reserve(INBUF_LEN);

    while ( getRunThread()) {
        waitIfPaused();  // wait if thread paused
        msleep(10);
        if( socket->state() != QTcpSocket::ConnectedState )
        {
            setRunThread(false);
            continue;
        }

        nchars = readBytes( inbuf, sizeof(inbuf));
        if( nchars< 0 )
        {
            setRunThread(false);
            continue;
        }
        if( nchars>0)
        {
            qDebug(Globals.StrFormat("another %d n chars status buffer\n", nchars).c_str());
            buffer.insert(buffer.size(), (const char*) inbuf, nchars);
        }

        if(buffer.size()==0)
        {
            msleep(100);
            continue;
        }

        // ptr = &buffer[0];
        // If you use buffer.data() it will include the length in big endian
        memcpy(inbuf, &buffer[0], INBUF_LEN);
        ptr = inbuf;

        // get the length and type of the message
        memcpy(&length, ptr, sizeof(length));
        memcpy(&message_type, ptr + sizeof(length), sizeof(message_type));

        if(swap_byte_order)
        {
            // this only swaps length and message type
            swapbytes((void *) &length, sizeof(length));
            swapbytes((void *) &message_type, sizeof(message_type));
        }
            // switch on the message type and handle it
            switch (message_type)
            {
            case MESSAGE_PING:
                ping_rep.read_ping_reply(ptr);
                if(swap_byte_order)
                {
                    ping_rep.byte_swap();
                }
                SendMessage("Ping Reply", COMMAND);
                if(Globals.bHexdump)
                {
                    SendMessage(NIST::HexDump(&ping_rep, sizeof(ping_rep), 20), STATUS);
                }
                break;
            case MESSAGE_JOINT_TRAJ_PT:
                jtp_rep.read_joint_traj_pt_reply(ptr);
                if(swap_byte_order)
                {
                    jtp_rep.byte_swap();
                }

                if (debug && (Globals.bDebugMask & DEBUG_REPLY))
                    SendMessage(jtp_rep.print_joint_traj_pt_reply());
                if(Globals.bHexdump)
                {
                    SendMessage(NIST::HexDump(&jtp_rep, sizeof(jtp_rep), 20), STATUS);
                }
                break;
            case MESSAGE_CART_TRAJ_PT:
                ctp_rep.read_cart_traj_pt_reply(ptr);
                if(swap_byte_order)
                    ctp_rep.byte_swap();
                if (debug && (Globals.bDebugMask & DEBUG_REPLY))
                    SendMessage(ctp_rep.print_cart_traj_pt_reply());
                if(Globals.bHexdump)
                {
                    SendMessage(NIST::HexDump(&ctp_rep, sizeof(ctp_rep), 20), STATUS);
                }
                break;
           // case MESSAGE_ROBOT_STATUS: // only status channel message?

            default:
                qDebug("unknown reply type: %d\n", message_type);
                break;
            } // switch (message type)
            buffer=buffer.substr(length+sizeof(length));
    }   // while (true)

    disconnect();

    if (debug && (Globals.bDebugMask & DEBUG_RUN))
        SendMessage("joint state client handler done\n");

    return;
}

