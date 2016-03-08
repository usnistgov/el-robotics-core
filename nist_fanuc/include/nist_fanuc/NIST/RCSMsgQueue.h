//

// RCSMsgQueue.h
//

/*
DISCLAIMER:
This software was produced by the National Institute of Standards
and Technology (NIST), an agency of the U.S. government, and by statute is
not subject to copyright in the United States.  Recipients of this software
assume all responsibility associated with its operation, modification,
maintenance, and subsequent redistribution.

See NIST Administration Manual 4.09.07 b and Appendix I.
*/

#pragma once
#include <boost/thread/mutex.hpp>

namespace RCS
{
    template<typename T>
    class CMessageQueue
    {
public:
        typedef std::deque<T>   xml_message_queue;

        CMessageQueue( ) { }

        void ClearMsgQueue ( ) { boost::mutex::scoped_lock lock(m);    xml_msgs.clear( ); }
        size_t SizeMsgQueue ( ) { boost::mutex::scoped_lock lock(m); return xml_msgs.size( ); }

        T PopFrontMsgQueue ( )
        {
            boost::mutex::scoped_lock lock(m);
            T                         msg = xml_msgs.front( ); // .back();

            xml_msgs.pop_front( );
            return msg;
        }

        T BackMsgQueue ( )
        {
            boost::mutex::scoped_lock lock(m);

            assert(xml_msgs.size( ) > 0);
            return xml_msgs.back( );
        }

        void AddMsgQueue (T t)
        {
            boost::mutex::scoped_lock lock(m);

            xml_msgs.push_back(t);
        }
        void InsertFrontMsgQueue (T t)
        {
            boost::mutex::scoped_lock lock(m);

            xml_msgs.insert(xml_msgs.begin(), t);
        }
protected:
        boost::mutex      m;
        xml_message_queue xml_msgs;
    };
}
