//

// RCSThreadTemplate.h
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
#include <boost/thread.hpp>
#include "RCSTimer.h"

namespace RCS {
    // Notes:
    // https://www.quantnet.com/threads/c-multithreading-in-boost.10028/

    class Thread {
    public:

        Thread(double cycletime) : _timer(cycletime) {
            _bThread = true;
            _cycletime = cycletime;
            _debugLevel = 99;
        }
        std::string Name() { return _name; }
        virtual void Init() {
        }

        virtual void Cleanup() {
        }

        virtual void Action() {
        }

        void Start() {
            _bThread = true;
            m_thread = boost::thread(boost::bind(&Thread::Cycle, this));
        }

        void Stop() {
            _bThread = false;
        }

        void Suspend() {
            _timer.suspend();
        }

        void Resume() {
            _timer.resume();
        }

        double Load() {
            return _timer.load();
        }

        double &CycleTime() {
            return _cycletime;
        }

        void SetDebugLevel(int n) {
            _debugLevel = n;
        }

        int & DebugLevel() {
            return _debugLevel;
        }

        void Cycle() {
            Init();
            _timer.sync();

            try {
                while (_bThread) {
                    Action();
                    _timer.wait();
                }
            } catch (...) {
                std::cout << "Unhandled exception - " << Name().c_str() << std::endl;
            }
            Cleanup();
        }

    protected:
        std::string _name;
        double _cycletime;
        int _debugLevel;
        bool _bThread;
        RCS::Timer _timer;
        boost::thread m_thread;
    };
};
