// crcl.cpp

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
#include "crcl.h"
#include "Globals.h"
#include "CrclInterface.h"
//#include "boost/array.hpp"
#define ROWMAJOR

// http://wiki.ros.org/APIs
// http://docs.ros.org/api/tf/html/c++/annotated.html
namespace Crcl {
static const char *sStateEnums[] = {"CRCL_Done", "CRCL_Error", "CRCL_Working", "CRCL_Ready"};

bool GetRPY(RCS::Vector3 Xrot, RCS::Vector3 Zrot, double & dRoll, double & dPitch, double & dYaw);
PoseType NullPose();
Crcl::VectorType VectorZero();
Crcl::PoseType IdentityPose();

inline RCS::Vector3 GetVector3D(Crcl::VectorType & vector) {
    return RCS::Vector3(vector.I(), vector.J(), vector.K());
}

inline RCS::Vector3 GetVector3D(Crcl::PointType & point) {
    return RCS::Vector3(point.X(), point.Y(), point.Z());
}

inline tf::Vector3 GetTfVector(Crcl::PointType & point) {
    return tf::Vector3(point.X(), point.Y(), point.Z());
}

inline tf::Vector3 GetTfVector(Crcl::VectorType & vector) {
    return tf::Vector3(vector.I(), vector.J(), vector.K());
}

inline ::PointType GetPoint(RCS::Vector3 & point) {
    return ::PointType(point.x(), point.y(), point.z());
}

inline ::VectorType GetVector(RCS::Vector3 & point) {
    return ::VectorType(point.x(), point.y(), point.z());
}

tf::Matrix3x3 GetTfRotMatrix(RCS::Vector3 Xrot, RCS::Vector3 Zrot) {

    tf::Vector3 YRot = Zrot.cross(Xrot);

    tf::Matrix3x3 m(Xrot.getX(), YRot.getX(), Zrot.getX(),
                    Xrot.getY(), YRot.getY(), Zrot.getY(),
                    Xrot.getZ(), YRot.getZ(), Zrot.getZ());
    return m;
}

bool GetRPY(RCS::Vector3 Xrot, RCS::Vector3 Zrot, double &roll, double &pitch, double &yaw) {
    tf::Matrix3x3 m = GetTfRotMatrix(Xrot, Zrot);
    m.getRPY(roll, pitch, yaw);
    return true;

}

RCS::Pose Convert(Crcl::PoseType & pose, double lengthConversion) {
    RCS::Pose p;
    p.setOrigin(GetTfVector(pose.Point()) * lengthConversion);
    p.setBasis(GetTfRotMatrix(GetVector3D(pose.XAxis()), GetVector3D(pose.ZAxis())));
    return p;
}

RCS::Pose Convert(Crcl::PoseToleranceType tolerance)
{
    RCS::Pose tolpose;
    double x = tolerance.XPointTolerance().present()? tolerance.XPointTolerance().get(): 0.0;
    double y = tolerance.YPointTolerance().present()? tolerance.YPointTolerance().get(): 0.0;
    double z = tolerance.ZPointTolerance().present()? tolerance.ZPointTolerance().get(): 0.0;

    // So what does nit mean
    double xrot = tolerance.XAxisTolerance().present()? tolerance.XAxisTolerance().get() : 0.0;
    double zrot = tolerance.ZAxisTolerance().present()? tolerance.ZAxisTolerance().get() : 0.0;

    // Assign permissible error pose tolerance
    tolpose.setOrigin(tf::Vector3(x,y,z));
    tolpose.setRotation(tf::Quaternion(0,0,0,1));  // x,y,z,w
    return tolpose;
}


inline Crcl::VectorType VectorZero() {
    return Crcl::VectorType(0.0, 0.0, 0.0);
}


bool GetPoseToRPY(Crcl::PoseType & pose, double & dRoll, double & dPitch, double & dYaw) {
    return GetRPY(GetVector3D(pose.XAxis()), GetVector3D(pose.ZAxis()), dRoll, dPitch, dYaw);
}

RCS::Rotation Convert(RCS::Vector3 Xrot, RCS::Vector3 Zrot) {
    double roll, pitch, yaw;
    GetRPY(Xrot, Zrot, roll, pitch, yaw);
    RCS::Rotation rotation;
    rotation.setRPY(roll, pitch, yaw);
    return rotation;
}

Crcl::PoseType Convert(RCS::Pose pose) {
    Crcl::PoseType crclPose(NullPose());
    crclPose.Point() = GetPoint(pose.getOrigin());
#if 0
    crclPose.Point().X() = pose.getOrigin().x();
    crclPose.Point().Y() = pose.getOrigin().y();
    crclPose.Point().Z() = pose.getOrigin().z();
#endif
    tf::Matrix3x3 m = pose.getBasis();
    tf::Vector3 v1, v2, v3;

    v1 = m.getColumn(0);
    v2 = m.getColumn(1);
    v3 = m.getColumn(2);
    crclPose.XAxis(GetVector(v1));
    crclPose.ZAxis(GetVector(v3));

    return crclPose;
}

std::string DumpCrclJoints(Crcl::JointStatusSequence jin) {
    std::stringstream str;
    for (unsigned int i = 0; i < jin.size(); i++) {
        double pos = jin[i].JointPosition().present() ? jin[i].JointPosition().get() : nan("");
        str << " [" << i << "]=" << pos;
    }
    return str.str();
}

sensor_msgs::JointState Convert(Crcl::JointStatusSequence jout, double angleConversion) {
    JointState joint;
    for (unsigned int i = 0; i < jout.size(); i++) {
        //::JointStatusType  jointstatus(jout[i ].JointNumber());
        double pos = jout[i].JointPosition().present() ? jout[i].JointPosition().get(): 0.0;
        //std::cout << "Joint[" << i << "]=" << pos << std::endl;
        joint.position.push_back(pos); // *(jout[i].JointPosition()) * angleConversion);
        // FIXME: how do you determine if there are values for velocity and force/torque
        //joint.velocity.push_back(*(jout[i].JointVelocity()));
        joint.effort.push_back(0.0);
    }
    return joint;
}

Crcl::JointStatusSequence Convert(JointState joints, double _angleConversion) {
    JointStatusSequence jout;

    for (unsigned int i = 0; i < joints.position.size(); i++) {
        ::JointStatusType jointstatus(i + 1);
        jointstatus.JointPosition(joints.position[i] * _angleConversion);
        jout.push_back(jointstatus);
    }
    return jout;
}

JointStatusSequence Convert(Crcl::ActuatorJointSequence joints, double _angleConversion) {
    JointStatusSequence jout;

    for (unsigned int i = 0; i < joints.size(); i++) {
        ::ActuateJointType & jointcmd(joints[i]);
        unsigned long long n = jointcmd.JointNumber();
        ::JointStatusType jointstatus(jointcmd.JointNumber());
        jointstatus.JointPosition(jointcmd.JointPosition() * _angleConversion);
        jout.push_back(jointstatus);
    }
    return jout;
}

Crcl::PoseType NullPose() {
    Crcl::PointType point(0.0, 0.0, 0.0);
    Crcl::VectorType xrot(1.0, 0.0, 0.0);
    Crcl::VectorType zrot(0.0, 0.0, 1.0);

    return Crcl::PoseType(point, xrot, zrot);
}

Crcl::PoseType IdentityPose() {
    Crcl::PointType point(0.0, 0.0, 0.0);
    Crcl::VectorType xrot(1.0, 0.0, 0.0);
    Crcl::VectorType zrot(0.0, 0.0, 1.0);

    return Crcl::PoseType(point, xrot, zrot);
}

Crcl::PoseType PoseHome() {
    static double home[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    std::vector<double> h;
    std::copy(&home[0], &home[6], std::back_inserter(h));
    RCS::Pose pose;
    // maybe hard code this
    pose.getOrigin() = RCS::Vector3(0, 0, 0);
    pose.getRotation().setRPY(0, 0, 0);
    //return Convert(IkFastKinematics::JointsToPose(h) );
    return Convert(pose);
}

std::vector<double> ConvertToAnglePositionVector(Crcl::ActuatorJointSequence & joints, double dAngleConversion) {
    std::vector<double> angles;

    for (unsigned int i = 0; i < joints.size(); i++) {
        ::ActuateJointType & jointcmd(joints[i]);
        angles.push_back(jointcmd.JointPosition() * dAngleConversion);
    }
    return angles;
}
std::string DumpRotationAsCrcl(RCS::Pose rcspose, std::string separator) {
    Crcl::PoseType pose = Convert(rcspose);
    return DumpRotationAsCrcl(pose);
}
std::string DumpRotationAsCrcl(Crcl::PoseType pose, std::string separator) {
    std::stringstream str;
    str << "XAxis = ";
    str << boost::format("%8.4f") % pose.XAxis().I() << separator.c_str();
    str << boost::format("%8.4f") % pose.XAxis().J() << separator.c_str();
    str << boost::format("%8.4f") % pose.XAxis().K() << separator.c_str();
    str << "\tZAxis = ";
    str << boost::format("%8.4f") % pose.ZAxis().I() << separator.c_str();
    str << boost::format("%8.4f") % pose.ZAxis().J() << separator.c_str();
    str << boost::format("%8.4f") % pose.ZAxis().K() << separator.c_str();
    return str.str();
}

std::string DumpCrclCommand(::CRCLCommandType & crclCommand) {
    std::stringstream str;
    try {
        if (crclCommand.Name().present())
            str << *crclCommand.Name();
    } catch (...) {
    }
    str << "CommandID=" << crclCommand.CommandID() << std::endl;
    return str.str();
}

std::string DumpStatusReply(CrclStatus *wm)
{
    std::stringstream str;
    //const char * sEnums[] = {"CRCL_Done", "CRCL_Error", "CRCL_Working", "CRCL_Ready"};
    str << "GetStatusReply=" << wm->CommandID() << ":";
    str << wm->CommandStatus() << std::endl;
    str<< "Crcl Status Joints       =" << Crcl::DumpCrclJoints(wm->_CurrentJoints).c_str()<< std::endl;
    str << "Crcl Status Position    ="  << Crcl::DumpPosition(wm->_CurrentPose).c_str()<< std::endl;
    tf::Matrix3x3 m =  GetTfRotMatrix(GetVector3D(wm->_CurrentPose.XAxis()), GetVector3D(wm->_CurrentPose.ZAxis()));
    tf::Quaternion q;
    m.getRotation(q);
    str << "Crcl Status Quaternion  ="  << q.x() <<":" << q.y() <<":" << q.z() <<":" <<  q.w() <<  std::endl;
    str << "Crcl Status Orientation ="  << Crcl::DumpRotationAsCrcl(wm->_CurrentPose).c_str()<< std::endl;
    double r,p,y; GetPoseToRPY(wm->_CurrentPose,r,p,y);
    str << "Crcl Status RPY         ="  << Globals.StrFormat("%8.4f,%8.4f,%8.4f",Rad2Deg(r),Rad2Deg(p),Rad2Deg(y)).c_str()<< std::endl;
    return str.str();
}
std::string DumpPosition(Crcl::PoseType pose, std::string separator) {
    std::stringstream str;
    str << boost::format("%8.4f") % pose.Point().X() << separator.c_str();
    str << boost::format("%8.4f") % pose.Point().Y() << separator.c_str();
    str << boost::format("%8.4f") % pose.Point().Z() << separator.c_str();
    return str.str();
}
std::string DumpPose(Crcl::PoseType pose, std::string separator) {
    std::stringstream str;
    str << boost::format("%8.4f") % pose.Point().X() << separator.c_str();
    str << boost::format("%8.4f") % pose.Point().Y() << separator.c_str();
    str << boost::format("%8.4f") % pose.Point().Z() << separator.c_str();
    str << boost::format("%8.4f") % pose.XAxis().I() << separator.c_str();
    str << boost::format("%8.4f") % pose.XAxis().J() << separator.c_str();
    str << boost::format("%8.4f") % pose.XAxis().K() << separator.c_str();
    str << boost::format("%8.4f") % pose.ZAxis().I() << separator.c_str();
    str << boost::format("%8.4f") % pose.ZAxis().J() << separator.c_str();
    str << boost::format("%8.4f") % pose.ZAxis().K() << separator.c_str();
    return str.str();
}
// ----------------------------------

CrclStatus::CrclStatus() :
    _CommandStatus("CRCL_Done"),
    _GoalPose(Crcl::PoseHome()),
    _CurrentPose(Crcl::PoseHome())
{
    _GoalJoints = JointsHome();
    _CurrentJoints = JointsHome();
    CommandID() = 1;
    StatusID() = 1;
    _lengthConversion = 1.0;

    // opposite of what documentation says are defaults
    _angleUnit = RCS::DEGREE;
    _angleConversion = M_PI / 180.0;

    _lengthUnit = RCS::METER;
    _lengthConversion = 1.0;

    _forceUnit = RCS::NEWTON;
    _forceConversion = 1.0;

    _torqueUnit = RCS::NEWTONMETER;
    _torqueConversion = 1.0;

    _bCoordinatedMotion = true;

    Rates().JointVelLimit().resize(8, DEFAULT_JOINT_MAX_VEL);
    Rates().JointAccLimit().resize(8, DEFAULT_JOINT_MAX_ACCEL);
}

void CrclStatus::Update(JointState & joints) {
#ifdef DEBUGJOINTSTATUSCRCLUPDATE
    std::cout << RCS::DumpJoints(joints);
#endif
    JointStatusSequence jout;

    for (unsigned int i = 0; i < joints.position.size(); i++) {

        ::JointStatusType jointstatus(i + 1);

        // Convert from radians to degrees?
        double dConverter = 1.0;

        if (_angleUnit == RCS::DEGREE) {
            dConverter = (double) (180.0 / M_PI);
        }
        jointstatus.JointPosition(dConverter * joints.position[i]);
        jout.push_back(jointstatus);
    }
    _CurrentJoints = _GoalJoints = jout;
}
// FIXME

Crcl::JointStatusSequence CrclStatus::JointsHome() {
    static double home[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    if (_GoalJoints.size() > 0) {
        _GoalJoints.clear();
    }

    for (int i = 0; i < 6; i++) {
        Crcl::JointStatus j(i + 1);
        j.JointPosition(home[i]);
        j.JointVelocity(0.0);
        j.JointTorqueOrForce(0.0);
        _GoalJoints.push_back(j);
    }
    return _GoalJoints;
}

void CrclStatus::Update(unsigned long long _CommandID) {
    StatusID() = CommandID() = _CommandID;
}

void CrclStatus::Update(Crcl::CommandStateEnum state) {
    CommandStatus() = state;
}

void CrclStatus::Update(Crcl::JointStatusSequence & joints, RCS::TrajPointType type) {
    if (type == RCS::WAYPOINT) {
        _CurrentJoints = joints;
    } else {
        _GoalJoints = joints;
    }
}

void CrclStatus::Update(Crcl::PoseType & pose, RCS::TrajPointType type) {
    if (type == RCS::WAYPOINT) {
        _GoalPose = pose;
        _CurrentPose = pose;
    } else {
        _CurrentPose = pose;
        _GoalPose = pose;
    }
}

void CrclStatus::Update(RCS::Pose & pose) {
    _CurrentPose = Convert(pose);
#if 0
    _CurrentPose.Point().X() = pose.getOrigin().x();
    _CurrentPose.Point().Y() = pose.getOrigin().y();
    _CurrentPose.Point().Z() = pose.getOrigin().z();
    boost::array<double, 12> m = _matrixFromQuat(pose.rotation);
    Crcl::VectorType xunitv(Crcl::VectorZero());
    xunitv.I(m[4 * 0 + 0]);
    xunitv.J(m[4 * 0 + 1]);
    xunitv.K(m[4 * 0 + 2]);
    _CurrentPose.XAxis(xunitv);

    Crcl::VectorType zunitv(Crcl::VectorZero());
    zunitv.I(m[4 * 2 + 0]);
    zunitv.J(m[4 * 2 + 1]);
    zunitv.K(m[4 * 2 + 2]);
    _CurrentPose.ZAxis(zunitv);
#endif
    _GoalPose = _CurrentPose;
}
};
