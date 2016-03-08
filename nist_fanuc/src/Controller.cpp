// Controller.cpp

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

#define BOOST_ALL_NO_LIB

#ifdef WIN32
#define _WIN32_WINNT_WIN7    0x0601
#define _WIN32_WINNT         _WIN32_WINNT_WIN7
#define _WIN32_WINDOWS       _WIN32_WINNT_WIN7
#endif

#include "Controller.h"
#include "urdf_model/rosmath.h"
#include <boost/exception/all.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <strstream>
//#include "Kinematics.h"
#include <iostream>
#include "urdf_model/eigenmath.h"
#include "CrclInterface.h"


// No namespace declarations
ALogger Logger;

void DebugBreak() {
}

namespace RCS {
    boost::mutex cncmutex;
    static const char *sStateEnums[] = {
        "Done", "Error", "Working"
    };
#ifdef WIN32

    static void trans_func(unsigned int u, EXCEPTION_POINTERS *pExp) {
        std::stringstream str;

        str << "CController trans_func - Code = " << pExp->ExceptionRecord->ExceptionCode << std::endl;

        OutputDebugString(str.str().c_str());
        throw std::exception();
    }
#else
#define S_OK 0
#endif
    RCS::CController Controller(DEFAULT_LOOP_CYCLE);

    RCS::CanonWorldModel CController::wm;
    RCS::CanonWorldModel CController::status;
    RCS::CanonWorldModel CController::laststatus;
    RCS::CMessageQueue<RCS::CanonCmd> CController::cmds;
    RCS::CMessageQueue<RCS::CanonCmd> CController::robotcmds;
    RCS::CController::xml_message_list CController::donecmds;
    bool RCS::CController::bGenerateProgram = false;
    //Trajectory CController::trajectory_model;

     size_t RCS::CController::_NumJoints;

    unsigned long CController::_debuglevel = 0;
    unsigned long CController::_debugtype = (unsigned long) RPY;
    unsigned long CController::_csvlogFlag = 0;
    ALogger CController::CsvLogging;

    CController::CController(double cycletime) : RCS::Thread(cycletime) {
        eJointMotionPlanner = NOPLANNER;
        eCartesianMotionPlanner = NOPLANNER;
    }

    CController::~CController(void) {
    }

    bool CController::Verify() {
        assert(crclinterface != NULL);
        assert(Kinematics() != NULL);
        assert(TrajectoryModel() != NULL);

    }

    void CController::Init() {
#ifdef WIN32
        _set_se_translator(trans_func); // correct thread?
#endif
        Name() = "CController";
        std::string sStatus = DumpHeader(",") + "\n";
        CsvLogging.Timestamping() = false;
        CsvLogging.LogMessage("Timestamp," + sStatus);
    }

    void CController::Action() {
        try {
            boost::mutex::scoped_lock lock(cncmutex);
            CAsioCrclSession *_pSession;

            /////////////////////////////////////////////////////////////////////////////////////////////
            // See if new CRCL commanded motion - if so, interpret as RCS command in session
            if (CAsioCrclSession::InMessages().SizeMsgQueue() > 0) {
                CrclMessage msg = CAsioCrclSession::InMessages().PopFrontMsgQueue();
                std::string crclcmd = boost::get<0>(msg);
                _pSession = boost::get<1>(msg);

                if (_debuglevel > INFORM) {
                    std::cerr << crclcmd.c_str();
                }

                Crcl::CrclReturn ret = crclinterface->DelegateCRCLCmd(crclcmd);

                if (ret == Crcl::CANON_STATUSREPLY) {
                    std::string sStatus = Crcl::CrclClientCmdInterface().GetStatusReply(&crclinterface->crclwm);
                    _pSession->SyncWrite(sStatus);
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////
            // interpret translated CRCL command. Commands in canonical form: standard units (mm, radians)
            if (Controller.cmds.SizeMsgQueue() > 0) {
                RCS::CanonCmd cc = Controller.cmds.PopFrontMsgQueue();
                _interpreter.ParseCommand(cc);
            }


            // Motion commands to robot - only joint at this point
            if (Controller.robotcmds.SizeMsgQueue() == 0) {
                crclinterface->crclwm.Update(Crcl::CommandStateEnum("Done"));
				_lastcc=_newcc;
				_lastcc.status=CANON_WORKING;
           } else {
                crclinterface->crclwm.Update(Crcl::CommandStateEnum("Working"));
				_lastcc=_newcc;
                _newcc = Controller.robotcmds.PopFrontMsgQueue();
				_newcc.status=CANON_WORKING;

                if (_newcc.cmd == RCS::CANON_DWELL) {
                    // This isn't very exact, as there will some time wasted until we are here
                    // Thread cycle time already adjusted to seconds
                    _newcc.dwell -= ((double)CycleTime()) ;
                    if (_newcc.dwell > 0.0) {
                        Controller.robotcmds.InsertFrontMsgQueue(_newcc);
                    }
                } else {
                    //Controller.trajectory_writer->JointTrajectoryWrite(newcc.joints);
                    Controller.JointWriter()->JointTrajectoryPositionWrite(_newcc.joints);
                }
            }

            /////////////////////////////////////////////////////////////////////////////////////////////
            // Save status to csv logging file?
            if (CsvLogging.DebugLevel() > INFORM) {
                std::string sStatus = Dump(",") + "\n";

                if (lastlogstatus != sStatus) {
                    CsvLogging.LogMessage(Logger.Timestamp() + "," + sStatus);
                }
                lastlogstatus = sStatus;
            }
        } catch (std::exception & e) {
            std::cerr << "Exception in  CController::Action() thread: " << e.what() << "\n";
        } catch (...) {
            std::cerr << "Exception in CController::Action() thread\n";
        }
    }

    std::string CController::DumpHeader(std::string separator) {
        std::stringstream str;
        const char * fields[] = {
            "CommandID", "StatusID", "State", "Pose-X", "Pose-Y", "Pose-Z",
            "Xrot-I", "Xrot-J", "Xrot-K", "Zrot-I", "Zrot-J", "Zrot-K"
        };
        const char *rpyfields[] = {"CommandID", "StatusID", "State", "Pose-X", "Pose-Y", "Pose-Z", "Roll", "Pitch", "Yaw"};

        if (_debugtype == CRCL) {
            for (size_t i = 0; i < sizeof ( fields) / sizeof ( fields[0]); i++) {
                str << fields[i] << separator.c_str();
            }
        } else {
            for (size_t i = 0; i < sizeof ( rpyfields) / sizeof ( rpyfields[0]); i++) {
                str << rpyfields[i] << separator.c_str();
            }
        }

        for (size_t i = 0; i < 6; i++) {
            str << ((i > 0) ? separator.c_str() : "") << "Joint" << i;
        }
        return str.str();
    }

    std::string CController::Dump(std::string separator) {
        std::stringstream str;

        str.precision(4);

        // str << Globals.GetTimeStamp(CGlobals::GMT_UV_SEC)   << separator.c_str();
        str << crclinterface->crclwm.CommandID() << separator.c_str();
        str << crclinterface->crclwm.StatusID() << separator.c_str();
        str << sStateEnums[crclinterface->crclwm.CommandStatus()] << separator.c_str();
        urdf::Pose pose = Crcl::Convert(crclinterface->crclwm._CurrentPose);
        str << pose.position.x << separator.c_str();
        str << pose.position.y << separator.c_str();
        str << pose.position.z << separator.c_str();

        if (_debugtype == CRCL) {
            str << crclinterface->crclwm._CurrentPose.XAxis().I() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.XAxis().J() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.XAxis().K() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.ZAxis().I() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.ZAxis().J() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.ZAxis().K();
        } else if (_debugtype == RPY) {
            double roll, pitch, yaw;
            pose.rotation.getRPY(roll, pitch, yaw);
            str << roll << separator.c_str();
            str << pitch << separator.c_str();
            str << yaw;
        }
        sensor_msgs::JointState joints = Crcl::Convert(crclinterface->crclwm._CurrentJoints);
        for (size_t i = 0; i < joints.position.size(); i++) {
            str << separator.c_str() << joints.position[i];
        }
        return str.str();
    }

    // ----------------------------------------------------

    void RobotCommands::Action() {
    }

    RobotStatus::RobotStatus() : RCS::Thread(DEFAULT_LOOP_CYCLE) {
        Name() = "RobotStatus";
    }

    void RobotStatus::Action() {
        try {
            boost::mutex::scoped_lock lock(cncmutex);
            sensor_msgs::JointState cjoints;
            if (JointReader() != NULL) {
                // Get latest joint readings
                cjoints = JointReader()->GetCurrentReadings();
                if (cjoints.position.size() == 0)
                    return;
                assert(cjoints.position.size() != 0);
                RCS::Controller.status.currentjoints = cjoints;

                // Use forward kinematics to get current pose
                RCS::Controller.status.currentpose = Kinematics()->FK(cjoints.position);
                //                std::cout << "Current Joints " << VectorDump<double>(cjoints.position).c_str();
                //                std::cout <<  DumpEPose( ConvertPose(RCS::Controller.status.currentpose));
                // Now update the CRCL world model which contains latest readings
                _crclinterface->crclwm.Update(RCS::Controller.status.currentpose);
                _crclinterface->crclwm.Update(cjoints);
            }
        } catch (...) {
            std::cout << "Exception in RobotStatus::Action()\n";
        }

    }
    //-------------------------------------------------------
    boost::mutex RobotProgram::_progmutex;

    ::CRCLProgramType::MiddleCommand_sequence & DummyInit() {
        static const ::CRCLProgramType::MiddleCommand_sequence &a = ::CRCLProgramType::MiddleCommand_sequence();
        return const_cast<::CRCLProgramType::MiddleCommand_sequence &>(a);
    }

    RobotProgram::RobotProgram() : RCS::Thread(1000),
    cmds(DummyInit()) {
        cmdnum = -1;
    }

    void RobotProgram::ExecuteProgram(std::string programpath) {
        boost::mutex::scoped_lock lock(_progmutex);
        _programname = programpath;
        std::string str;
        Globals.ReadFile(programpath, str);
        // Fails?
        //RCS::Controller.CrclDelegate()->DelegateCRCLCmd(contents);
        istr.str(str);
        try {

            cmdnum = -1; // resest program execution even if failed.
            if (_delegate.FindLeadingElement(str) == "</CRCLProgram>") {

                boost::shared_ptr<::CRCLProgramType> crclProgram(
                        CRCLProgram(istr, xml_schema::flags::dont_initialize | xml_schema::flags::dont_validate | xml_schema::flags::keep_dom));

                cmds = crclProgram->MiddleCommand();
                cmdnum = 0;

            }
        } catch (...) {
            std::cout << "Unhandled exception RobotProgram::ExecuteProgram\n";
        }
    }

    void RobotProgram::Action() {
        try {
            boost::mutex::scoped_lock lock(cncmutex);
            if (cmdnum >= 0) {
                ::CRCLCommandType & crclCommand(cmds[(size_t) cmdnum++]);
                _delegate.DelegateCRCLCmd(crclCommand);
            }

        } catch (...) {
            std::cout << "Unhandled exception in RobotProgram::Action()\n";
        }

    }

}