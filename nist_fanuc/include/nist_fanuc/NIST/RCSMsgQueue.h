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

namespace RCS {

    //* The CMessageQueue offers a thread safe message queue for buffering template types.

    /**
     * \brief The CMessageQueue offers a mutexed front to a stl deque. The queue is a LIFO data structure.
     *   Useful for safely sharing data between multiple threads.
     */
    template<typename T>
    class CMessageQueue {
    public:
        typedef std::deque<T> xml_message_queue;

        CMessageQueue() {
        }
        /// \brief ClearMsgQueue clears all contents in message queue. T

        void ClearMsgQueue() {
            boost::mutex::scoped_lock lock(m);
            xml_msgs.clear();
        }

        /// \brief SizeMsgQueue returns number of items in message queue.

        size_t SizeMsgQueue() {
            boost::mutex::scoped_lock lock(m);
            return xml_msgs.size();
        }

        /*!
         * \brief PopFrontMsgQueue mutex pop of front item of message queue.
         * \return  T       returns front item from message queue.
         */
        T PopFrontMsgQueue() {
            boost::mutex::scoped_lock lock(m);
            T msg = xml_msgs.front(); // .back();

            xml_msgs.pop_front();
            return msg;
        }

        /*!
         * \brief BackMsgQueue mutex pop of back item of message queue.
         * \return  T       returns back item from message queue.
         */
        T BackMsgQueue() {
            boost::mutex::scoped_lock lock(m);

            assert(xml_msgs.size() > 0);
            return xml_msgs.back();
        }

        /*!
         * \brief AddMsgQueue mutex push to back an item onto message queue.
         * \param  T       item to place in back of message queue.
         */
        void AddMsgQueue(T t) {
            boost::mutex::scoped_lock lock(m);

            xml_msgs.push_back(t);
        }

              /*!
         * \brief InsertFrontMsgQueue mutex push to front an item onto message queue.
         * \param  T       item to place in front of message queue.
         */ void InsertFrontMsgQueue(T t) {
            boost::mutex::scoped_lock lock(m);

            xml_msgs.insert(xml_msgs.begin(), t);
        }
    protected:
        boost::mutex m;
        xml_message_queue xml_msgs;
    };
}
