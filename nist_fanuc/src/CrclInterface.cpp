// CrclInterface.cpp

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
#include <iostream>
#include <fstream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>       /* isnan, sqrt */

// xercesc
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/XMLGrammarPoolImpl.hpp>

// boost
#include <boost/regex.hpp>
#include <boost/exception/all.hpp>

// crcl
#include "CrclInterface.h"
//#include "Kinematics.h"
#include "Globals.h"
#include "Controller.h"


using namespace xsd;
using namespace xml_schema;
using namespace Crcl;



CrclStatus CrclDelegateInterface::crclwm;
unsigned long long CrclClientCmdInterface::_commandnum = 0;

// ------------------------------------------------------------------------------
// CrclDelegateInterface

std::string CrclDelegateInterface::FindLeadingElement(std::string xml) {
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
    return "";
}
void CrclDelegateInterface::CrclRunProgram(::CRCLProgramType::MiddleCommand_sequence cmds)
{
    for(size_t i=0; i< cmds.size(); i++){
                   
        ::CRCLCommandType & crclCommand(cmds[i]);
        DelegateCRCLCmd(crclCommand);
        //::MiddleCommandType  crclCommand( crclInstanceCommand->CRCLCommand());
    }
    
}
CrclReturn CrclDelegateInterface::DelegateCRCLCmd(std::string str) {
    std::istringstream istr(str);

    if (FindLeadingElement(str) == "</CRCLProgram>") {
        try {
            boost::shared_ptr<::CRCLProgramType> crclProgram(
                    CRCLProgram(istr, xml_schema::flags::dont_initialize | xml_schema::flags::dont_validate | xml_schema::flags::keep_dom)
                    );
            ::CRCLProgramType::MiddleCommand_sequence& cmds = crclProgram->MiddleCommand();
            CrclRunProgram(cmds);

        } catch (const xml_schema::exception& e) {
            // Most likely here due to illegal XML in Crcl program. Note, is not validated against XSD.
            std::cout << "Parse Exception RobotProgram::ExecuteProgram:" << e << std::endl;
        } catch (...) {
            std::cout << "Unhandled exception\n";
        }
        
    }
    else if (FindLeadingElement(str) == "</CRCLCommandInstance>") {
        try {
            std::auto_ptr<CRCLCommandInstanceType> crclInstanceCommand(
                    CRCLCommandInstance(istr, xml_schema::flags::dont_initialize | xml_schema::flags::dont_validate | xml_schema::flags::keep_dom)
                    );
            ::CRCLCommandType & crclCommand(crclInstanceCommand->CRCLCommand());

            //::MiddleCommandType  crclCommand( crclInstanceCommand->CRCLCommand());

            _nCommandNum = crclCommand.CommandID();

            if (GetStatusType * stat = dynamic_cast<GetStatusType *> (&(crclCommand))) {
                Globals.ErrorMessage(Logger.StrFormat("GetStatus id=%d\n", stat->CommandID()));
                return GetStatus();
            }
            return DelegateCRCLCmd(crclCommand);
        } catch (const xml_schema::exception& e) {
            // Most likely here due to illegal XML in Crcl program. Note, is not validated against XSD.
            std::cout << "Parse Exception RobotProgram::ExecuteProgram:" << e << std::endl;
        } 
    }
    else if (FindLeadingElement(str) == "</CRCLStatus>") {
        assert(0); // should never get status as server
        std::auto_ptr<CRCLStatusType> crclstat(
                CRCLStatus(istr, xml_schema::flags::dont_initialize | xml_schema::flags::dont_validate | xml_schema::flags::keep_dom)
                );
    }
}

CrclReturn CrclDelegateInterface::DelegateCRCLCmd(::CRCLCommandType &crclCommand) {
    if (ActuateJointsType * actuateJoints = dynamic_cast<ActuateJointsType *> (&crclCommand)) // (&(*cmd)))
    {

        crclwm.Update(_nCommandNum);
        crclwm.Update(Crcl::CommandStateEnum("CRCL_Working"));
        ActuateJointsType::ActuateJoint_sequence & joints(actuateJoints->ActuateJoint());
        Globals.ErrorMessage(Logger.StrFormat("ActuateJoints id=%d joint=%d pos = %6.5f\n", crclCommand.CommandID(), joints[0].JointNumber(), joints[0].JointPosition()));
        return ActuateJoints(joints);

        // m_thread=boost::thread(&CrclDelegateInterface::CRCLActuateJoints, this, joints);
    }        // MoveToType
    else if (MoveToType * moveto = dynamic_cast<MoveToType *> (&(crclCommand))) {
        MoveToType::EndPosition_type & endpose(moveto->EndPosition());
        bool bStraight = moveto->MoveStraight();
        return  MoveTo(endpose, bStraight);
    } else if (EndCanonType * endcanon = dynamic_cast<EndCanonType *> (&(crclCommand))) {
        return  EndCanon();
    } else if (InitCanonType * init = dynamic_cast<InitCanonType *> (&(crclCommand))) {
        Globals.ErrorMessage(Logger.StrFormat("InitCanonType id=%d\n", init->CommandID()));
        return  InitCanon();
    } else if (MessageType * msg = dynamic_cast<MessageType *> (&(crclCommand))) {
        return Message(msg->Message());
    } else if (MoveThroughToType * movethrough = dynamic_cast<MoveThroughToType *> (&(crclCommand))) {
        size_t n = movethrough->NumPositions();
        bool bStraight = movethrough->MoveStraight();
        MoveThroughToType::Waypoint_sequence & waypoints = movethrough->Waypoint();
        // poses are copied - otherwise fault is thrown
        std::vector<Crcl::PoseType> poses;
        for (size_t i = 0; i < waypoints.size(); i++)
            poses.push_back(waypoints[i]);
        return MoveThroughTo(poses, bStraight);
    } else if (StopMotionType * stopmotion = dynamic_cast<StopMotionType *> (&(crclCommand))) {
        const char *sEnums[] = {"Immediate", "Fast", "Normal"};
        ::StopConditionEnumType & cond(stopmotion->StopCondition());
        int nCond = cond;
        std::string sUnit("Immediate");

        if ((nCond >= 0) && (nCond < 3)) {
            sUnit = sEnums[nCond];
        }
        return StopMotion(nCond);
    } else if (OpenToolChangerType * opentool = dynamic_cast<OpenToolChangerType *> (&(crclCommand))) {
        return OpenToolChanger();
    } else if (SetAngleUnitsType * angleUnits = dynamic_cast<SetAngleUnitsType *> (&(crclCommand))) {
        const char *sEnums[] = {"degree", "radian"};
        ::AngleUnitEnumType & units(angleUnits->UnitName());
        int nUnit = units;
        std::string sUnit("radian");

        if ((nUnit >= 0) && (nUnit < 2)) {
            sUnit = sEnums[nUnit];
        }
        return SetAngleUnits(sUnit);
    }  else if (SetLengthUnitsType * lengthUnits = dynamic_cast<SetLengthUnitsType *> (&(crclCommand))) {
        const char *sEnums[] = {"meter", "millimeter", "inch"};
        ::LengthUnitEnumType & units(lengthUnits->UnitName());
        int nUnit = units;
        std::string sUnit("meter");

        if ((nUnit >= 0) && (nUnit < 3)) {
            sUnit = sEnums[nUnit];
        }
        return SetLengthUnits(sUnit);
    } else if (CloseToolChangerType * closetool = dynamic_cast<CloseToolChangerType *> (&(crclCommand))) {
        return CloseToolChanger();
    } else if (ConfigureJointReportsType * configurereports = dynamic_cast<ConfigureJointReportsType *> (&(crclCommand))) {
        bool bResetAll = configurereports->ResetAll();
        ConfigureJointReportsType::ConfigureJointReport_sequence & report = configurereports->ConfigureJointReport();
        std::vector<Crcl::JointReport> jointReports;

        for (size_t i = 0; i < report.size(); i++) {
            Crcl::JointReport jr;
            jr._nJointNumber = report[i].JointNumber();
            jr._bReportPosition = report[i].ReportPosition();
            jr._bReportTorqueOrForce = report[i].ReportTorqueOrForce();
            jr._bReportVelocity = report[i].ReportVelocity();
            jointReports.push_back(jr);
        }
        return ConfigureJointReports(jointReports);
    } else if (DwellType * dwelltype = dynamic_cast<DwellType *> (&(crclCommand))) {
        double time = dwelltype->DwellTime();
        return Dwell(time);    
    } else if (MoveScrewType * movescrew = dynamic_cast<MoveScrewType *> (&(crclCommand))) {
    } else if (SetEndEffectorParametersType * endeeparamtype = dynamic_cast<SetEndEffectorParametersType *> (&(crclCommand))) {
    } else if (SetEndEffectorType * endeetype = dynamic_cast<SetEndEffectorType *> (&(crclCommand))) {
        double setting = endeetype->Setting();
        return SetEndEffector(setting);
    } else if (SetEndPoseToleranceType * setEndTolerance = dynamic_cast<SetEndPoseToleranceType *> (&(crclCommand))) {
        SetEndPoseToleranceType::Tolerance_type & tolerancepose(setEndTolerance->Tolerance());
        return SetEndPoseTolerance(tolerancepose);
    } else if (SetForceUnitsType * forceunits = dynamic_cast<SetForceUnitsType *> (&(crclCommand))) {
        //    newton,    pound,    ounce
        const char *sEnums[] = {"newton", "pound", "ounce"};
        ::ForceUnitEnumType & units(forceunits->UnitName());
        int nUnit = units;
        std::string sUnit("newton");

        if ((nUnit >= 0) && (nUnit < 3)) {
            sUnit = sEnums[nUnit];
        }
        return SetTorqueUnits(sUnit);
    } else if (SetIntermediatePoseToleranceType * posetol = dynamic_cast<SetIntermediatePoseToleranceType *> (&(crclCommand))) {
        return SetIntermediatePoseTolerance(posetol->Tolerance());
    } else if (SetMotionCoordinationType * coordtype = dynamic_cast<SetMotionCoordinationType *> (&(crclCommand))) {
        bool bCoordinatedMotion = coordtype->Coordinated();
        return SetMotionCoordination(bCoordinatedMotion);
    } else if (RotAccelAbsoluteType * absrotaccel = dynamic_cast<RotAccelAbsoluteType *> (&(crclCommand))) {
        double accel = absrotaccel->Setting();
        return SetRotAccel(accel);
    } else if (RotAccelRelativeType * relrotaccel = dynamic_cast<RotAccelRelativeType *> (&(crclCommand))) {
        double percent = relrotaccel->Fraction();
        double accel = RCS::Controller.wm.maxRotAccel * percent;
        return SetRotAccel(accel);
    } else if (RotSpeedAbsoluteType * rotspeed = dynamic_cast<RotSpeedAbsoluteType *> (&(crclCommand))) {
        double speed = rotspeed->Setting();
        return SetRotSpeed(speed);
    } else if (RotSpeedRelativeType * rotspeed = dynamic_cast<RotSpeedRelativeType *> (&(crclCommand))) {
        long percent = rotspeed->Fraction();
        double speed = RCS::Controller.wm.maxRotVel * percent;
        return SetRotSpeed(speed);
    } else if (SetTorqueUnitsType * torqueUnits = dynamic_cast<SetTorqueUnitsType *> (&(crclCommand))) {
        //   newtonMeter,    footPound
        const char *sEnums[] = {"newtonMeter", "footPound"};
        ::TorqueUnitEnumType & units(torqueUnits->UnitName());
        int nUnit = units;
        std::string sUnit("newtonMeter");

        if ((nUnit >= 0) && (nUnit < 2)) {
            sUnit = sEnums[nUnit];
        }
        return SetTorqueUnits(sUnit);
    } else if (SetTransAccelType * accltype = dynamic_cast<SetTransAccelType *> (&(crclCommand))) {
        double accel;

        if (TransAccelAbsoluteType * absAccltype = dynamic_cast<TransAccelAbsoluteType *> (&(accltype->TransAccel()))) {
            accel = absAccltype->Setting();
        } else if (TransAccelRelativeType * relAccltype = dynamic_cast<TransAccelRelativeType *> (&(accltype->TransAccel()))) {
            double percentage = relAccltype->Fraction();
            accel = RCS::Controller.wm.maxTransVel * percentage;
        }
        return SetTransAccel(accel);
    } else if (SetTransSpeedType * speedtype = dynamic_cast<SetTransSpeedType *> (&(crclCommand))) {
        double speed;

        if (TransSpeedAbsoluteType * absSpeedtype = dynamic_cast<TransSpeedAbsoluteType *> (&(speedtype->TransSpeed()))) {
            speed = absSpeedtype->Setting();
        } else if (TransSpeedRelativeType * relSpeedtype = dynamic_cast<TransSpeedRelativeType *> (&(speedtype->TransSpeed()))) {
            double percentage = relSpeedtype->Fraction();
            speed = RCS::Controller.wm.maxTransVel * percentage;
        }
        return SetTransSpeed(speed);
    }
    return CANON_NOT_IMPLEMENTED;
}

// ------------------------------------------------------------

std::string CrclClientCmdInterface::GetStatusReply(CrclStatus *wm) {
    // CommandStateEnumType state((int) wm->_state);
    //const char * sEnums[] = {"CRCL_Done", "CRCL_Error", "CRCL_Working", "CRCL_Ready"};
    std::cout << "GetStatusReply=" << wm->CommandID() << ":" << wm->CommandStatus() << std::endl; 
    CommandStatusType status(wm->CommandID(), wm->CommandID(), 
            //sEnums[wm->CommandStatus()]);
            CommandStateEnumType::_xsd_CommandStateEnumType_literals_[wm->CommandStatus()]);
    CRCLStatusType cmd(status);

    cmd.CommandStatus(status);

    // CRCLStatusType::JointStatuses & jointStatuses(cmd.JointStatuses());
    CRCLStatusType::JointStatuses_type jointStatuses;
    jointStatuses.JointStatus(wm->_CurrentJoints);
    cmd.JointStatuses(jointStatuses);

    cmd.PoseStatus(wm->_CurrentPose);

    xml_schema::namespace_infomap map;
    std::ostringstream strfs;
    CRCLStatus(strfs, // std::cout,
            (CRCLStatusType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::CloseToolChanger() {
    CloseToolChangerType cmd(++_commandnum);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs, // std::cout,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::Dwell(double time ){ // int *events, double *params, int numEvents) {
   std::ostringstream strfs;
 #if 0
    if (numEvents < 1) {
        return "";
    }
    DwellType cmd(++_commandnum, *params);
    xml_schema::namespace_infomap map;
    CRCLCommandInstance(strfs, // std::cout,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
#endif
    return strfs.str();
}

std::string CrclClientCmdInterface::EndCanon(int reason) {
    EndCanonType cmd(++_commandnum);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs, // std::cout,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

/**
 * xercesc::XMLPlatformUtils::Initialize();
 * CrclClientCmdInterface crcl;
 * std::string text = crcl.CRCLGetStatusCmd();
 * xercesc::XMLPlatformUtils::Terminate ();
 */
std::string CrclClientCmdInterface::GetStatus() {
    GetStatusType cmd(++_commandnum);
    xml_schema::namespace_infomap map;

    // map[""].name = "http://www.w3.org/2001/XMLSchema";
    // map[""].schema = "http://www.w3.org/2001/XMLSchema ../CRCLStatus.xsd";
    std::ostringstream strfs;

    CRCLCommandInstance(strfs, // std::cout,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::InitCanon() {
    InitCanonType cmd(++_commandnum);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs, // std::cout,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::Message(std::string message) {
    MessageType cmd(++_commandnum, message);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::MoveScrew(Crcl::PoseType startPose, Crcl::VectorType axisPoint, double dAxialDistanceFree, double dAxialDistanceScrew, double dTurn) {
    assert(0);
    return "";
}

std::string CrclClientCmdInterface::MoveTo(Crcl::PoseType pose, bool bStraight) {
    // ::PoseType mypose (::PoseType(::PointType(pose.x, pose.y, pose.z),VectorType(1.0,0.0,0.0), VectorType(1.0,0.0,0.0) ));
    MoveToType cmd(++_commandnum, bStraight, pose);

    // cmd.EndPosition(pose);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::MoveThroughTo(Crcl::PoseType *poses,
        int numPoses,
        double * accelerations,
        double * speeds,
        Crcl::PoseToleranceType * tolerances) {
    std::ostringstream strfs;

    // FIXME:
    assert(0);
#if 0
    MoveThroughToType::Waypoint_sequence wpt;

    for (int i = 0; i < numPoses; i++) {
        ::PoseType pose(::PoseType(::PointType(poses[i].x, poses[i].y, poses[i].z), VectorType(1.0, 0.0, 0.0), VectorType(1.0, 0.0, 0.0)));
        wpt.push_back(pose);
    }
    MoveThroughToType cmd(++_commandnum, true, numPoses);
    cmd.Waypoint(wpt);
    xml_schema::namespace_infomap map;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
#endif
    return strfs.str();
}

std::string CrclClientCmdInterface::OpenToolChanger() {
    OpenToolChangerType cmd(++_commandnum);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::RunProgram(std::string programText) {
    RunProgramType cmd(++_commandnum, programText);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetEndEffector(double fractionalSetting) {
    SetEndEffectorType cmd(++_commandnum, fractionalSetting);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetEndEffectorTolerance(Crcl::PoseToleranceType toleranceSetting) {
    std::ostringstream strfs;

    // FIXME:
    assert(0);
#if 0

    // SetEndPoseToleranceType::Tolerance_type tolerancepose;
    // tolerancepose.XPointTolerance(toleranceSetting.x);
    // tolerancepose.YPointTolerance(toleranceSetting.y);
    // tolerancepose.ZPointTolerance(toleranceSetting.z);
    SetEndPoseToleranceType cmd(++_commandnum, toleranceSetting);
    xml_schema::namespace_infomap map;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
#endif
    return strfs.str();
}

std::string CrclClientCmdInterface::SetEndPoseTolerance(Crcl::PoseToleranceType toleranceSetting) {
    SetEndPoseToleranceType cmd(++_commandnum, toleranceSetting);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetAngleUnits(std::string sUnitName) {
    ::AngleUnitEnumType eUnitName = ::AngleUnitEnumType::radian;

    if (strncasecmp(sUnitName.c_str(), "radian", strlen("radian"))==0) {
        eUnitName = ::AngleUnitEnumType::radian;
    } else if (strncasecmp(sUnitName.c_str(), "degree", strlen("degree"))==0) {
        eUnitName = ::AngleUnitEnumType::degree;
    }
    SetAngleUnitsType cmd(++_commandnum, eUnitName);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetLengthUnits(std::string sUnitName) // UnitName is a string that can be only the literals 'meter',  'millimeter', or 'inch'.
{
    ::LengthUnitEnumType eUnitName = ::LengthUnitEnumType::meter;

    if (strncasecmp(sUnitName.c_str(), "meter", strlen("meter"))==0) {
        eUnitName = ::LengthUnitEnumType::meter;
    } else if (strncasecmp(sUnitName.c_str(), "millimeter", strlen("millimeter"))==0) {
        eUnitName = ::LengthUnitEnumType::millimeter;
    } else if (strncasecmp(sUnitName.c_str(), "inch", strlen("inch"))==0) {
        eUnitName = ::LengthUnitEnumType::inch;
    }
    SetLengthUnitsType cmd(++_commandnum, eUnitName);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetMotionCoordination(bool bCoordinated) {
    SetMotionCoordinationType cmd(++_commandnum, bCoordinated);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;

    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetRotAccel(double dAccel) {
    SetRotAccelType::RotAccel_type accel;

    accel.Name("");
    SetRotAccelType cmd(++_commandnum, accel);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::SetRotSpeed(double dSpeed) {
    SetRotSpeedType::RotSpeed_type speed;

    speed.Name("");
    SetRotSpeedType cmd(++_commandnum, speed);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}

std::string CrclClientCmdInterface::StopMotion(int condition) // 0=Immediate, Fast, Normal
{
    ::StopConditionEnumType eStopCondition = ::StopConditionEnumType::Normal;

    if (condition == 0) {
        eStopCondition = ::StopConditionEnumType::Immediate;
    } else if (condition == 1) {
        eStopCondition = ::StopConditionEnumType::Fast;
    } else if (condition == 2) {
        eStopCondition = ::StopConditionEnumType::Normal;
    }

    StopMotionType cmd(++_commandnum, eStopCondition);
    xml_schema::namespace_infomap map;
    std::ostringstream strfs;
    CRCLCommandInstance(strfs,
            (CRCLCommandType &) cmd,
            map,
            "UTF-8",
            xml_schema::flags::dont_initialize);
    return strfs.str();
}
// ---------------------------------------------------------------------------------------
// CrclDelegateInterface - handles CRCL command

CrclReturn CrclDelegateInterface::ActuateJoints(Crcl::ActuatorJointSequence joints) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::ActuateJoints\n"));
    std::string strcmd="";
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_MOVE_JOINT;
    cc.ParentCommandID() = crclwm.CommandID();
    cc.bCoordinated=crclwm._bCoordinatedMotion;
    cc.endPoseTol=Crcl::Convert(crclwm._endPoseTolerance); // not sure useful?

    for (int i = 0; i < joints.size(); i++) {
        int jn = joints[i].JointNumber() - 1;
        double speed, accel;
        speed = crclwm.Rates().JointVelLimit().at(jn);
        accel = crclwm.Rates().JointAccLimit().at(jn);
        double setting, changerate;
        std::string type;
        if (JointSpeedAccelType * speedacc = dynamic_cast<JointSpeedAccelType *> (&(joints[i].JointDetails()))) {
            type = "JointSpeedAccelType";
            speed = *speedacc->JointSpeed() * crclwm._lengthConversion;
            accel = *speedacc->JointAccel() * crclwm._lengthConversion;

        } else if (JointForceTorqueType * forcetorque = dynamic_cast<JointForceTorqueType *> (&(joints[i].JointDetails()))) {
            type = "JointForceTorqueType";
            setting = *forcetorque->Setting();
            changerate = *forcetorque->ChangeRate();
        }


        //if ( ( j.type == RCS::RdfJoint::REVOLUTE ) || ( j.type == RCS::RdfJoint::CONTINUOUS ) )
        {
            cc.jointnum.push_back(joints[i].JointNumber() - 1); // adjust back to zero based math
            double pos = joints[i].JointPosition() * crclwm._angleConversion;
            cc.joints.position.push_back(pos);
            cc.joints.velocity.push_back(speed); //  need conversion of velocity?
            cc.joints.effort.push_back(accel); //   need conversion of acc?Format()
            strcmd+=Globals.StrFormat(",%6.4f",pos);
        }
    }
    LogFile.LogFormatMessage("ActuateJoints In=%s\n", strcmd.c_str());
    LogFile.LogFormatMessage("ActuateJoints Rcs=%s\n", RCS::DumpJoints(cc.joints).c_str());

    RCS::Controller.cmds.AddMsgQueue(cc);

    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::CloseToolChanger() {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::CloseToolChanger\n"));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_SET_GRIPPER;
	cc.ParentCommandID() =  crclwm.CommandID();
    cc.gripperPos = 0.0;
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::ConfigureJointReports(std::vector<Crcl::JointReport> & jointReports) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::ConfigureJointReports\n"));
    crclwm._vJointReport.clear();
    crclwm._vJointReport.insert(crclwm._vJointReport.begin(), jointReports.begin(), jointReports.end());
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::Couple(char *targetID) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::Couple\n"));

    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::Dwell(double seconds) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::Dwell=%5.2f\n", seconds));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_DWELL;
    cc.ParentCommandID() = crclwm.CommandID();
    cc.dwell = seconds;
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::EndCanon() {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::EndCanon\n"));
    //signal(SIG_INT);
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::GetStatus() {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::GetStatus\n"));
    std::cout << "GetStatus\n";
    crclwm.Update(_nCommandNum);

    // this is redundant
    //std::string sStatus = Crcl::CrclClientCmdInterface().GetStatusReply(&crclwm);
    // _pAsioSession->SyncWrite(sStatus);

    return CANON_STATUSREPLY;
}

CrclReturn CrclDelegateInterface::InitCanon() {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::InitCanon\n"));
    crclwm.Update(_nCommandNum);
    crclwm.Update(Crcl::CommandStateEnum("CRCL_Done"));
    Crcl::JointStatusSequence jstat(CrclStatus().JointsHome());
    crclwm.Update(jstat);
    Crcl::PoseType poseref(Crcl::PoseHome());
    crclwm.Update(poseref);
    std::string sStatus = Crcl::CrclClientCmdInterface().GetStatusReply(&crclwm);

    // _pAsioSession->SyncWrite(sStatus);
    return CANON_STATUSREPLY;
}

CrclReturn CrclDelegateInterface::Message(std::string message) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::Message=%s\n",message.c_str()));

    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::MoveTo(Crcl::PoseType endpose, bool bStraight) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::MoveTo\n"));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_MOVE_TO;
    cc.ParentCommandID() = crclwm.CommandID();
    cc.bStraight=bStraight;
    cc.endPoseTol=Crcl::Convert(crclwm._endPoseTolerance);


    // default length units are Meters
    cc.pose = Convert(endpose, crclwm._lengthConversion);
    cc.Rates().CurrentFeedrate() = crclwm.Rates().CurrentFeedrate();
            
    std::cout << "GotoCRCL Pose " << Crcl::DumpPose(endpose, ",").c_str() << std::endl;
    std::cout << "Goto urdf Pose " << RCS::DumpPose(cc.pose).c_str();
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::MoveThroughTo(std::vector<Crcl::PoseType> & poses, bool bStraight) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::MoveThroughTo\n"));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_MOVE_THRU;
	cc.ParentCommandID() =  crclwm.CommandID();
    cc.bStraight=bStraight;
    cc.endPoseTol=Crcl::Convert(crclwm._endPoseTolerance);
    cc.intermediatePtTol=Crcl::Convert(crclwm._intermediatePoseTolerance);
    //cc.endposetolerance=Crcl::Convert(crclwm._gripperPoseTolerance);

    // default length and angular units are Meters and Radians
    for (size_t i = 0; i < poses.size(); i++) {
        std::cout << "GotoCRCL Pose " << Crcl::DumpPose(poses[i], ",").c_str() << std::endl;
        RCS::Pose waypoint = Convert(poses[i], crclwm._lengthConversion);
        cc.waypoints.push_back(waypoint);
        std::cout << "Goto urdf Pose " << RCS::DumpPose(waypoint).c_str();
    }

    // FIXME: add tolerance to each waypoint - blending distance?
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::OpenToolChanger() {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::OpenToolChanger\n"));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_SET_GRIPPER;
    cc.gripperPos = 1.0;
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::RunProgram(std::string programText) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::RunProgram=%s\n", programText.c_str()));

    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetAbsoluteAcceleration(double acceleration) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetAbsoluteAcceleration=%5.2f\n", acceleration));

    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetAbsoluteSpeed(double speed) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetAbsoluteSpeed=%5.2f\n", speed));

    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetAngleUnits(std::string unitName) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetAngleUnits=%s\n", unitName.c_str()));

    if (strncasecmp(unitName.c_str(), "RADIAN", unitName.size())==0) {
        crclwm._angleUnit = RCS::RADIAN;
        crclwm._angleConversion = 1.0;
    } else if (strncasecmp(unitName.c_str(), "DEGREE", unitName.size())==0) {
        crclwm._angleUnit = RCS::DEGREE;
        crclwm._angleConversion = M_PI / 180.0;
    } else {
        return CANON_FAILURE;
    }
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetAxialSpeeds(std::vector<double> speeds) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetAxialSpeeds\n"));
    crclwm._speeds.clear();
    copy(speeds.begin(), speeds.end(), std::back_inserter(crclwm._speeds));

    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_SET_MAX_JOINT_SPEED;
    cc.speed.clear();
    cc.ParentCommandID() = crclwm.CommandID();
    copy(speeds.begin(), speeds.end(), std::back_inserter(cc.speed));
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::SetEndPoseTolerance(Crcl::PoseToleranceType tolerance) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetEndPoseTolerance\n"));
    crclwm._endPoseTolerance = tolerance;

    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_SET_TOLERANCE;

    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::SetForceUnits(std::string unitName) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetForceUnits=%s\n",unitName.c_str()));

    if (strncasecmp(unitName.c_str(), "newton", unitName.size())==0) {
        crclwm._forceUnit = RCS::NEWTON;
        crclwm._forceConversion = 1.0;
    } else if (strncasecmp(unitName.c_str(), "pound", unitName.size())==0) {
        // FN = Flbf × 4.4482216152605
        crclwm._forceUnit = RCS::POUND;
        crclwm._forceConversion = 4.4482216152605;
    } else if (strncasecmp(unitName.c_str(), "ounce", unitName.size())==0) {
        crclwm._forceUnit = RCS::OUNCE;
        crclwm._forceConversion = 0.2780138509534;
    } else {
        return CANON_FAILURE;
    }
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetIntermediatePoseTolerance(Crcl::PoseToleranceType tolerance) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetIntermediatePoseTolerance\n"));
    crclwm._intermediatePoseTolerance = tolerance;
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetLengthUnits(std::string unitName) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetLengthUnits=%s\n", unitName.c_str()));

    if (strncasecmp(unitName.c_str(), "METER", unitName.size())==0) {
        crclwm._lengthUnit = RCS::METER;
        crclwm._lengthConversion = 1.0;
    } else if (strncasecmp(unitName.c_str(), "MM", unitName.size())==0) {
        crclwm._lengthUnit = RCS::MM;
        crclwm._lengthConversion = 0.001;
    } else if (strncasecmp(unitName.c_str(), "INCH", unitName.size())==0) {
        crclwm._lengthUnit = RCS::INCH;
        crclwm._lengthConversion = 0.0254;
    } else {
        return CANON_FAILURE;
    }
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetMotionCoordination(bool bCoordinatedMotion) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetMotionCoordination=%d\n",bCoordinatedMotion));
    crclwm._bCoordinatedMotion = bCoordinatedMotion;
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetParameter(char *paramName, void *paramVal) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetParameter\n"));

    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetRelativeAcceleration(double percent) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetRelativeAcceleration=%5.2f\n", percent));
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetEndEffector(double percent) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetEndEffector=%5.2f\n", percent));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_SET_GRIPPER;
	cc.ParentCommandID() =  crclwm.CommandID();
    cc.gripperPos = percent / 100.0;
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::SetEndEffectorTolerance(Crcl::PoseToleranceType dTolerance) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetEndEffectorTolerance\n"));
    crclwm._gripperPoseTolerance = dTolerance;
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::StopMotion(int condition) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::StopMotion\n"));
    RCS::CanonCmd cc;
    cc.cmd = RCS::CANON_STOP_MOTION;
    cc.stoptype = (RCS::CanonStopMotionType) condition;
    RCS::Controller.cmds.AddMsgQueue(cc);
    return CANON_MOTION;
}

CrclReturn CrclDelegateInterface::SetRotAccel(double accel) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetRotAccel=%5.2f\n", accel));
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetRotSpeed(double speed) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetRotSpeed=%5.2f\n", speed));
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetTorqueUnits(std::string unitName) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetTorqueUnits=%s\n", unitName.c_str()));

    //   newtonMeter,   footPound
    // 1.35581794833 × F * lbf-ft = F * N⋅m
    if (strncasecmp(unitName.c_str(), "newtonMeter", unitName.size())==0) {
        crclwm._torqueUnit = RCS::NEWTONMETER;
        crclwm._torqueConversion = 1.0;
    } else if (strncasecmp(unitName.c_str(), "footPound", unitName.size())==0) {
        crclwm._torqueUnit = RCS::FOOTPOUND;
        crclwm._torqueConversion = 1.35581794833;
    } else {
        return CANON_FAILURE;
    }
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetTransAccel(double accel) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetTransAccel=%5.2f\n",accel));
    return CANON_SUCCESS;
}

CrclReturn CrclDelegateInterface::SetTransSpeed(double speed) {
    IfDebug(LogFile.LogFormatMessage("CrclDelegateInterface::SetTransSpeed=%5.2f\n",speed));
    crclwm.Rates().CurrentFeedrate()=speed;
    return CANON_SUCCESS;
}
// -------------------------------------------------------------

void CrclStatusMsgInterface::ParseCRCLStatus(std::string filename) {
    std::string contents;

    Globals.ReadFile(filename, contents);
    ParseCRCLStatusString(contents);
}

void CrclStatusMsgInterface::ParseCRCLStatusString(std::string str) {
    try {
        std::istringstream istr(str);
        std::auto_ptr<CRCLStatusType> crclstat(
                CRCLStatus(istr, xml_schema::flags::dont_initialize | xml_schema::flags::dont_validate | xml_schema::flags::keep_dom)
                );

        // xercesc::DOMElement* e = static_cast<xercesc::DOMElement*> ((*crclstat)._node ());
        CLEANSTORE(_status.CommandID(), crclstat->CommandStatus().CommandID(), 0);
        CLEANSTORE(_status.StatusID(), crclstat->CommandStatus().StatusID(), 0);
        CLEANSTORE(_status.CommandStatus(), crclstat->CommandStatus().CommandState(), "");
        VALIDSTORE(_status._CurrentPose, (*crclstat->PoseStatus()).Pose()); // no change if not valid
        // _status.Dump();
    }    catch (const xml_schema::exception & e) {
        Globals.ErrorMessage(e.what());
    }    catch (...) {
        Globals.ErrorMessage("ParseCRCLStatusString error\n");
    }
}
