// Controller.h

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
#include <boost/shared_ptr.hpp>
#include <list>

#include "AsioCrclServer.h"
#include "RCSThreadTemplate.h"
#include "CrclInterface.h"
#include "RCSInterpreter.h"
#include "ChainRobotModel.h"
#include "Trajectory.h"
#include "Communication.h"
#include "moveit.h"

namespace RCS {

    extern boost::mutex      cncmutex;
    struct CController : public RCS::Thread {
		typedef std::list<RCS::CanonCmd>   xml_message_list;
        CController(double cycletime);
        ~CController(void);

        static RCS::CanonWorldModel wm;
        static RCS::CanonWorldModel status;
        static RCS::CanonWorldModel laststatus;
        static RCS::CMessageQueue<RCS::CanonCmd> cmds;
        static xml_message_list donecmds;
        static RCS::CMessageQueue<RCS::CanonCmd> robotcmds;
        static size_t _NumJoints;
        static bool bGenerateProgram;
        bool Verify();
        virtual void Action();
        virtual void Init();

        std::string Dump(std::string separator = ",");
        std::string DumpHeader(std::string separator = ",");

        NVAR(CrclDelegate, boost::shared_ptr<Crcl::CrclDelegateInterface>,crclinterface);
        VAR(Kinematics, boost::shared_ptr<IKinematics>);
        VAR(TrajectoryModel, boost::shared_ptr<CTrajectory>);
        VAR(JointWriter, boost::shared_ptr<CJointWriter>);
        VAR(MoveitPlanner, boost::shared_ptr<MoveitPlanning>);
  
        void SetKinematics(boost::shared_ptr<IKinematics> k) {
            Kinematics() = k;
            _interpreter._kinematics = k;
        }

       RCSInterpreter _interpreter;
        
        RCS::CanonCmd _newcc;
        RCS::CanonCmd _lastcc;
        std::string lastlogstatus;

        enum DebugLevel {
            FATAL = 0, WARNING = 2, INFORM = 4, FULL = 5
        }; // ERROR, DEBUG #defines

        enum DebugType {
            CRCL = 0, RPY
        };
        static unsigned long _debugtype;
        static unsigned long _debuglevel;
        static unsigned long _csvlogFlag;
        static ALogger CsvLogging;
        enum MotionPlannerEnum { NOPLANNER=0, MOVEIT, DESCARTES, BASIC, WAYPOINT, GOMOTION };
        MotionPlannerEnum eCartesianMotionPlanner;
        MotionPlannerEnum eJointMotionPlanner;
   };
    //__declspec(selectany)  CController Controller;
    extern CController Controller;

    class RobotCommands : public RCS::Thread {
    public:

        RobotCommands() : RCS::Thread(10000000) {
        }
        virtual void Action();
    };

    class RobotStatus : public RCS::Thread {
    public:

        RobotStatus() ;
        NVAR(CrclDelegate, boost::shared_ptr<Crcl::CrclDelegateInterface>,_crclinterface);
        VAR(JointReader, boost::shared_ptr<CJointReader>);
        VAR(Kinematics, boost::shared_ptr<IKinematics>);
#if 0
        void SetCrclDelegate(boost::shared_ptr<Crcl::CrclDelegateInterface>crcl) {
            _crclinterface = crcl;
        }
        void SetJointReader(boost::shared_ptr<CJointReader>reader) {
            _jointReader = reader;
        }

        void SetKinematics(boost::shared_ptr<IKinematics> k) {
            _kinematics = k;
        }
#endif
        virtual void Action();
        bool Verify()
        {
            assert(CrclDelegate()!=NULL);
            assert(JointReader()!=NULL);
            assert(Kinematics()!=NULL);
        }
       // boost::shared_ptr<Crcl::CrclDelegateInterface> _crclinterface;
      // // boost::shared_ptr<CJointReader> _jointReader;
      //  boost::shared_ptr<IKinematics>  _kinematics;
        ;
    };

    class RobotProgram : public RCS::Thread {
    public:

        RobotProgram() ;
        virtual void ExecuteProgram(std::string programpath);
        virtual void Action();
        //////////////////////////////////////
        static boost::mutex _progmutex;
        std::string _programname;
        Crcl::CrclDelegateInterface _delegate;
        std::istringstream istr;
        int cmdnum;
        ::CRCLProgramType::MiddleCommand_sequence& cmds;
    };
}
