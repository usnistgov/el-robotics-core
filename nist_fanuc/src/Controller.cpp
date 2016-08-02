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
#include <boost/exception/all.hpp>
#include <boost/thread.hpp>
#include <strstream>
#include <iostream>

#include "urdf_model/rosmath.h"
#include "CrclInterface.h"
#include "RvizMarker.h"

// No namespace declarations
//////////////////////////////////
ALogger Logger;



// RCS namespace declarations
//////////////////////////////////
namespace RCS {
    boost::mutex cncmutex;
    static const char *sStateEnums[] = {
        "CRCL_Done", "CRCL_Error", "CRCL_Working", "CRCL_Ready"
    };
#ifdef WIN32

    static void trans_func(unsigned int u, EXCEPTION_POINTERS *pExp) {
        std::stringstream str;

        str << "CController trans_func - Code = " << pExp->ExceptionRecord->ExceptionCode << std::endl;

        OutputDebugString(str.str().c_str());
        throw std::exception();
    }
#else

#endif
    RCS::CController Controller(DEFAULT_LOOP_CYCLE);
    std::vector<std::string>  RCS::CController::links;
    RCS::CanonWorldModel CController::wm;
    RCS::CanonWorldModel CController::status;
    RCS::CanonWorldModel CController::laststatus;
    RCS::CMessageQueue<RCS::CanonCmd> CController::cmds;
    RCS::CMessageQueue<RCS::CanonCmd> CController::robotcmds;
    RCS::CController::xml_message_list CController::donecmds;
    bool RCS::CController::bGenerateProgram = false;
    bool RCS::CController::bSimulation = true;
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
        Name() = "Controller";
        // CSV Logging setup
        std::string sStatus = DumpHeader(",") + "\n";
        CsvLogging.Timestamping() = false;
        CsvLogging.LogMessage("Timestamp," + sStatus);
    }

    RCS::CanonCmd CController::GetLastRobotCommand() {
        try {
            RCS::CanonCmd cc = Controller.robotcmds.BackMsgQueue();
            return cc;
        } catch (...) {
            // exception if nothing in queue
        }
        return RCS::Controller.LastCC();
    }

    JointState CController::GetLastJointState() {
        // This assumes queue of motion commands, with last being last in queue.
        try {
            RCS::CanonCmd cc = Controller.robotcmds.BackMsgQueue();
            // could be dwell so no actual joint positions in cmd at this point??
            if(cc.joints.position.size()==0)
                throw std::runtime_error("Zero joint positions\n");
            return cc.joints;
        } catch(std::exception err){
            std::cout << "CController::GetLastJointState exception" << err.what(); 
        } catch (...) {
            // exception if nothing in queue
        }
        // use actual readings of joints
        return RCS::Controller.status.currentjoints;
    }

    RCS::Pose CController::GetLastCommandedPose() {
        JointState lastjoints = GetLastJointState();
        return EEPoseReader()->GetLinkValue(RCS::Controller.links.back());
        //return RCS::Controller.Kinematics()->FK(lastjoints.position);
    }
    int CController::Action() {
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
#ifdef DUMPCANON_STATUSREPLYCRCLJOINTS
                    std::cout <<  Crcl::DumpCrclJoints(crclinterface->crclwm._CurrentJoints).c_str();
#endif
                    // Dump status to log file if different than last time.
                    std::string s = DumpStatusReply(&crclinterface->crclwm);
                    std::string uniqueid = LOGNAME( __FILE__,__LINE__);
                    if(LogFile.properties[uniqueid]!=s)
                    {
                         LogFile.LogFormatMessage(s.c_str());
                    }
                    LogFile.properties[uniqueid] = s;
                   
                    
                        
                    std::string sStatus = Crcl::CrclClientCmdInterface().GetStatusReply(&crclinterface->crclwm);
                    // Should create zip and save reply to folder, with commands
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
                crclinterface->crclwm.Update(Crcl::CommandStateEnum("CRCL_Done"));
                _lastcc = _newcc;
                _lastcc.status = CANON_DONE;
            } else {
                crclinterface->crclwm.Update(Crcl::CommandStateEnum("CRCL_Working"));
                _lastcc = _newcc;
                _newcc = Controller.robotcmds.PopFrontMsgQueue();
                _newcc.status = CANON_WORKING;
                RCS::Controller.status.echocmd = _newcc;

                if (_newcc.cmd == RCS::CANON_DWELL) {
                    // This isn't very exact, as there will some time wasted until we are here
                    // Thread cycle time already adjusted to seconds
                    _newcc.dwell -= ((double) CycleTime());
                    if (_newcc.dwell > 0.0) {
                        Controller.robotcmds.InsertFrontMsgQueue(_newcc);
                    }
                } else {
                    //Controller.trajectory_writer->JointTrajectoryWrite(newcc.joints);
                    Controller.JointWriter()->JointTrajectoryPositionWrite(_newcc.joints);
#define MARKERS
#ifdef MARKERS
                    //RCS::Pose goalpose = Kinematics()->FK(_newcc.joints.position);
                    RCS::Pose goalpose = EEPoseReader()->GetLinkValue(RCS::Controller.links.back());
                    std::cout << "Marker Pose " << DumpPose(goalpose).c_str();
                    RvizMarker()->Send(goalpose);
#endif
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
        return 1;
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
        //str << sStateEnums[crclinterface->crclwm.CommandStatus()] << separator.c_str();
        str << crclinterface->crclwm.CommandStatus() << separator.c_str();
        RCS::Pose pose = Crcl::Convert(crclinterface->crclwm._CurrentPose);
        str << pose.getOrigin().x() << separator.c_str();
        str << pose.getOrigin().y() << separator.c_str();
        str << pose.getOrigin().z() << separator.c_str();

        if (_debugtype == CRCL) {
            str << crclinterface->crclwm._CurrentPose.XAxis().I() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.XAxis().J() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.XAxis().K() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.ZAxis().I() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.ZAxis().J() << separator.c_str();
            str << crclinterface->crclwm._CurrentPose.ZAxis().K();
        } else if (_debugtype == RPY) {
            double roll, pitch, yaw;
            getRPY(pose, roll, pitch, yaw);
            //tf::Matrix3x3 rot = pose.getBasis();
            //rot.getRPY(roll, pitch, yaw);
            //pose.rotation.getRPY(roll, pitch, yaw);
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

    RobotStatus::RobotStatus(double cycletime) : RCS::Thread(cycletime) {
        Name() = "RobotStatus";
    }

    int RobotStatus::Action() {
        try {
            static int i = 1;
            boost::mutex::scoped_lock lock(cncmutex);
            sensor_msgs::JointState cjoints;
            if (JointReader() != NULL) {
                // Get latest robot  joint readings
                cjoints = JointReader()->GetCurrentReadings();
                if (cjoints.position.size() == 0)
                    return 1;
                assert(cjoints.position.size() != 0);
                RCS::Controller.status.currentjoints = cjoints;
                // Use forward kinematics to get current pose
                //RCS::Controller.status.currentpose = Kinematics()->FK(cjoints.position);
                RCS::Controller.status.currentpose = RCS::Controller.EEPoseReader()->GetLinkValue(RCS::Controller.links.back());
#ifdef DEBUGCONTROLLERTOOL0POSE
                std::string str= RCS::DumpPose(RCS::Controller.status.currentpose);
                std::cout << str.c_str();
#endif
#if 0
                if (--i < 0) {
                    std::cout << "Current Joints " << VectorDump<double>(cjoints.position).c_str();
                    std::cout << "Canon pose " << DumpPose(RCS::Controller.status.currentpose);
                    std::cout << "Crcl Pose " << Crcl::DumpPose(Crcl::Convert(RCS::Controller.status.currentpose), ",");
                    i = 20;
                }
#endif
                // Now update the CRCL world model which contains latest readings
                _crclinterface->crclwm.Update(RCS::Controller.status.currentpose);
                _crclinterface->crclwm.Update(cjoints);
            }
        } catch (...) {
            std::cout << "Exception in RobotStatus::Action()\n";
        }
        return 1;
    }
    //-------------------------------------------------------
    boost::mutex RobotProgram::_progmutex;

    ::CRCLProgramType::MiddleCommand_sequence & DummyInit() {
        static const ::CRCLProgramType::MiddleCommand_sequence &a = ::CRCLProgramType::MiddleCommand_sequence();
        return const_cast< ::CRCLProgramType::MiddleCommand_sequence &> (a);
    }

    RobotProgram::RobotProgram(double cycletime) : RCS::Thread(cycletime),
    cmds(DummyInit()) {
    }
    void RobotProgram::ExecuteProgramFromFile(std::string programpath) {
        _programname = programpath;
        std::string str;
        Globals.ReadFile(programpath, str);
        return ExecuteProgram( str);
    }

    void RobotProgram::ExecuteProgram(std::string str) {
        // Fixme: what if not done with last commands?
        boost::mutex::scoped_lock lock(_progmutex);

        istr.str(str);
        try {

             if (_delegate.FindLeadingElement(str) == "</CRCLProgram>") {

                // codesynthesis parse of xml into C++ data structures
                boost::shared_ptr<::CRCLProgramType> crclProgram(
                        CRCLProgram(istr, xml_schema::flags::dont_initialize | xml_schema::flags::dont_validate | xml_schema::flags::keep_dom));
                // This is an array of crcl program commands
                cmds.insert(cmds.end(), crclProgram->MiddleCommand().begin(),crclProgram->MiddleCommand().end()) ;
                //cmdnum = 0;
                //lastcmdnum = -1;

            }            
        } catch (const xml_schema::exception& e) {
            // Most likely here due to illegal XML in Crcl program. Note, is not validated against XSD.
            std::cout << "Parse Exception RobotProgram::ExecuteProgram:" << e << std::endl;
        } catch (...) {
            // Most likely here due to illegal XML in Crcl program. Note, is not validated against XSD.
            std::cout << "Unhandled exception RobotProgram::ExecuteProgram" ;
        }
    }


    int RobotProgram::Action() {
        try {
            boost::mutex::scoped_lock lock(_progmutex); //? correct mutex?

            if (Controller.robotcmds.SizeMsgQueue() == 0) {
                // fixme poor mans wait til done 
                // No more quit?
                return 0;
            }
            if (CAsioCrclSession::InMessages().SizeMsgQueue() > 0)
                return 1;
            // wait until last Crcl XML message has finished being interpreted
#ifdef HEAVYDEBUG
            std::cout<< "Command num" << cmdnum << "Commands size=" << cmds.size() << std::endl;
#endif
            if (cmds.size()>0) {
                // Got new Crcl XML message
 
                Crcl::CrclReturn eRetMotion;
                // could we miss a cmd in a crcl xml -> cnc cmd -> robot motion cmd?
                do {
                    //cmdnum++;
                    ::CRCLCommandType & crclCommand(cmds.front()); // cmds[cmdnum - 1]);
                    cmds.erase(cmds.begin());
                    std::cout << Crcl::DumpCrclCommand(crclCommand) << std::endl;
                    // does this update my own crcl wm? or all?
                    eRetMotion = _delegate.DelegateCRCLCmd(crclCommand);
                }// if not motion command, nothing added to controller queue
                while (eRetMotion != Crcl::CANON_MOTION);
               
                // \fixme wait to do next command until last command is done
                // if( RCS::Controller.status.echocmd.ParentCommandID() 
                // Look for "Done" then allow new command - or rather almost done?
                // test lame first
                //if( RCS::Controller.LastCC().status == CANON_DONE)


            }

        } catch (...) {
            std::cout << "Unhandled exception in RobotProgram::Action()\n";
        }
        return 1;
    }
}
