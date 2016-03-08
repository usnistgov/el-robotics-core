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
//#include "Kinematics.h"
#include "Globals.h"
#include "CrclInterface.h"
#include "boost/array.hpp"
#include "urdf_model/rosmath.h"
#include <Eigen/Dense>
#include "urdf_model/eigenmath.h"

namespace Crcl {
    static const char *sStateEnums[] = {"Done", "Error", "Working"};

    RosMatrix GetXZRotMatrix(urdf::Vector3 Xrot, urdf::Vector3 Zrot) {

        RosMatrix rot;
        rot[4 * 0 + 0] = Xrot.x;
        rot[4 * 0 + 1] = Xrot.y;
        rot[4 * 0 + 2] = Xrot.z;
        rot[4 * 2 + 0] = Zrot.x;
        rot[4 * 2 + 1] = Zrot.y;
        rot[4 * 2 + 2] = Zrot.z;
        urdf::Vector3 Yrot = _cross3(Zrot, Xrot);
        rot[4 * 1 + 0] = Yrot.x;
        rot[4 * 1 + 1] = Yrot.y;
        rot[4 * 1 + 2] = Yrot.z;
        return rot;
    }

    Eigen::Matrix3d GetEigenRotMatrix(urdf::Vector3 Xrot, urdf::Vector3 Zrot) {

        double x, y, z;
        double xi, xj, xk;
        double zi, zj, zk;
        double r, p, w;
        xi = Xrot.x;
        xj = Xrot.y;
        xk = Xrot.z;
        Eigen::Vector3d xaxis(xi, xj, xk);
        zi = Zrot.x;
        zj = Zrot.y;
        zk = Zrot.z;
        Eigen::Vector3d zaxis(zi, zj, zk);
        Eigen::Vector3d yaxis = zaxis.cross(xaxis);
        Eigen::Matrix3d m(3, 3);

        m << xi, yaxis.x(), zi,
                xj, yaxis.y(), zj,
                xk, yaxis.z(), zk;
        return m;
    }

    bool GetRPY(Crcl::PoseType pose, double &roll, double &pitch, double &yaw) {
        Eigen::Matrix3d m = GetEigenRotMatrix(GetVector3D(pose.XAxis()), GetVector3D(pose.ZAxis()));
        Eigen::Vector3d ea = m.eulerAngles(0, 1, 2);
        roll = ea(0);
        pitch = ea(1);
        yaw = ea(2);
        return true;
    }

    bool GetRPY(urdf::Vector3 Xrot, urdf::Vector3 Zrot, double &roll, double &pitch, double &yaw) {
        Eigen::Matrix3d m = GetEigenRotMatrix(Xrot, Zrot);
        Eigen::Vector3d ea = m.eulerAngles(0, 1, 2);
        roll = ea(0);
        pitch = ea(1);
        yaw = ea(2);
        return true;

    }
#if 1

    urdf::Pose Convert(Crcl::PoseType & pose, double lengthConversion) {
        urdf::Pose p;

        p.position.x = pose.Point().X() * lengthConversion;
        p.position.y = pose.Point().Y() * lengthConversion;
        p.position.z = pose.Point().Z() * lengthConversion;

        Eigen::Matrix3d mat = GetEigenRotMatrix(GetVector3D(pose.XAxis()), GetVector3D(pose.ZAxis()));
        Eigen::Quaterniond q(mat);
        p.rotation.x = q.x();
        p.rotation.y = q.y();
        p.rotation.z = q.z();
        p.rotation.w = q.w();
        return p;
    }
#else

    urdf::Pose Convert(Crcl::PoseType & pose, double lengthConversion) {
        urdf::Pose p;

        p.position.x = pose.Point().X() * lengthConversion;
        p.position.y = pose.Point().Y() * lengthConversion;
        p.position.z = pose.Point().Z() * lengthConversion;
        double dRoll, dPitch, dYaw;
        GetPoseToRPY(pose, dRoll, dPitch, dYaw);
        // Orientation angles always appear to be in radians (NOT DEGREES?)
        //p.rotation.setFromRPY(dRoll * _angleConversion, dPitch * _angleConversion, dYaw * _angleConversion);
        p.rotation.setFromRPY(dRoll, dPitch, dYaw);
        return p;
    }
#endif

    inline Crcl::VectorType VectorZero() {
        return Crcl::VectorType(0.0, 0.0, 0.0);
    }

    inline urdf::Vector3 GetVector3D(Crcl::PointType & point) {
        return urdf::Vector3(point.X(), point.Y(), point.Z());
    }

    inline urdf::Vector3 GetVector3D(Crcl::VectorType & vector) {
        return urdf::Vector3(vector.I(), vector.J(), vector.K());
    }

    bool GetPoseToRPY(Crcl::PoseType & pose, double & dRoll, double & dPitch, double & dYaw) {
        // urdf::Pose outpose = Convert(pose, 1.0);
        // outpose.rotation.getRPY(dRoll,  dPitch,   dYaw);
        // return true;
        return GetRPY(GetVector3D(pose.XAxis()), GetVector3D(pose.ZAxis()), dRoll, dPitch, dYaw);
    }
    // returns radians
#if 0

    bool GetRPY(urdf::Vector3 Xrot, urdf::Vector3 Zrot, double & dRoll, double & dPitch, double & dYaw) {

        RosMatrix rot = GetXZRotMatrix(Xrot, Zrot);
        dYaw = atan2(rot[4 * 2 + 0], rot[4 * 2 + 1]);
        dPitch = acos(rot[4 * 2 + 2]);
        dRoll = -atan2(rot[4 * 0 + 2], rot[4 * 1 + 2]);

        urdf::Rotation q = Convert(Xrot, Zrot);
        _quatToRpy(q, dRoll, dPitch, dYaw);
        return true;
    }
#endif

    urdf::Rotation Convert(urdf::Vector3 Xrot, urdf::Vector3 Zrot) {
        //RosMatrix rot = GetXZRotMatrix(Xrot, Zrot);
        //return _quatFromMatrix(rot);
        Eigen::Matrix3d mat(GetEigenRotMatrix(Xrot, Zrot));
        Eigen::Quaterniond q(mat);
        urdf::Rotation rotation;
        rotation.x = q.x();
        rotation.y = q.y();
        rotation.z = q.z();
        rotation.w = q.w();
        return rotation;
    }

    Crcl::PoseType Init(std::vector<double> terms) {
        assert(terms.size() == 9);
        Crcl::PoseType crclPose(NullPose());
        crclPose.Point().X() = terms[0];
        crclPose.Point().Y() = terms[1];
        crclPose.Point().Z() = terms[2];
        Crcl::VectorType xunitv(Crcl::VectorZero());
        xunitv.I(terms[3]);
        xunitv.J(terms[4]);
        xunitv.K(terms[5]);
        crclPose.XAxis(xunitv);
        Crcl::VectorType zunitv(Crcl::VectorZero());
        zunitv.I(terms[6]);
        zunitv.J(terms[7]);
        zunitv.K(terms[8]);
        crclPose.ZAxis(zunitv);
        return crclPose;
    }

    Crcl::PoseType Convert(urdf::Pose pose) {
        Crcl::PoseType crclPose(NullPose());

        crclPose.Point().X() = pose.position.x;
        crclPose.Point().Y() = pose.position.y;
        crclPose.Point().Z() = pose.position.z;

        // NOTE!!! Rotation/orientation  must be in radians....
        RosMatrix m = _matrixFromPose(pose);
        Crcl::VectorType xunitv(Crcl::VectorZero());
        xunitv.I(m[4 * 0 + 0]);
        xunitv.J(m[4 * 0 + 1]);
        xunitv.K(m[4 * 0 + 2]);
        crclPose.XAxis(xunitv);

        Crcl::VectorType zunitv(Crcl::VectorZero());
        zunitv.I(m[4 * 2 + 0]);
        zunitv.J(m[4 * 2 + 1]);
        zunitv.K(m[4 * 2 + 2]);
        crclPose.ZAxis(zunitv);
        return crclPose;
    }

    sensor_msgs::JointState Convert(Crcl::JointStatusSequence jout, double angleConversion) {
        JointState joint;
        for (unsigned int i = 0; i < jout.size(); i++) {
            //::JointStatusType  jointstatus(jout[i ].JointNumber());
            //std::cout << "Pos " << *(jout[i].JointPosition()) << std::endl;
            joint.position.push_back(*(jout[i].JointPosition()) * angleConversion);
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

    ::PointType GetPoint(RCS::Vector3 & point) {
        return ::PointType(point.x, point.y, point.z);
    }

    ::VectorType GetVector(RCS::Vector3 & point) {
        return ::VectorType(point.x, point.y, point.z);
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
        // FIXME: remove ikfast kinematics
        urdf::Pose pose;
        // maybe hard code this
        pose.position = RCS::Vector3(0, 0, 0);
        pose.rotation.setFromRPY(0, 0, 0);
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

    std::string DumpCrclPose(Crcl::PoseType pose, std::string separator) {
        std::stringstream str;

        str.precision(4);
        str << "Translation = ";
        str << pose.Point().X() << separator.c_str();
        str << pose.Point().Y() << separator.c_str();
        str << pose.Point().Z() << separator.c_str();
        str << "\nXAxis = ";
        str << pose.XAxis().I() << separator.c_str();
        str << pose.XAxis().J() << separator.c_str();
        str << pose.XAxis().K() << separator.c_str();
        str << "\nZAxis = ";
        str << pose.ZAxis().I() << separator.c_str();
        str << pose.ZAxis().J() << separator.c_str();
        str << pose.ZAxis().K() << separator.c_str();
        return str.str();
    }

    std::string DumpPose(Crcl::PoseType pose, std::string separator) {
        std::stringstream str;

        str.precision(4);
        str << pose.Point().X() << separator.c_str();
        str << pose.Point().Y() << separator.c_str();
        str << pose.Point().Z() << separator.c_str();
        str << pose.XAxis().I() << separator.c_str();
        str << pose.XAxis().J() << separator.c_str();
        str << pose.XAxis().K() << separator.c_str();
        str << pose.ZAxis().I() << separator.c_str();
        str << pose.ZAxis().J() << separator.c_str();
        str << pose.ZAxis().K() << separator.c_str();
        return str.str();
    }
    // ----------------------------------

    CrclStatus::CrclStatus() :
    _CommandStatus("Done"),
    _GoalPose(Crcl::PoseHome()),
    _CurrentPose(Crcl::PoseHome()) {
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
    }

    void CrclStatus::Update(JointState & joints) {
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

    Crcl::ActuatorJointSequence CrclStatus::Merge(Crcl::ActuatorJointSequence joints, bool bIncremental) {
        Crcl::ActuatorJointSequence alljoints;

        // First copy all of status into actuator joint sequence
        for (unsigned int i = 0; i < _GoalJoints.size(); i++) {
            ::xml_schema::positive_integer num = _GoalJoints[i].JointNumber();
            JointStatusType::JointPosition_optional & optpos = _GoalJoints[i].JointPosition();
            ActuateJointType::JointPosition_type pos(*optpos);
            ::ActuateJointType jointcmd(_GoalJoints[i].JointNumber(), pos, ::JointDetailsType());
            alljoints.push_back(jointcmd);
        }

        for (unsigned int i = 0; i < joints.size(); i++) {
            size_t n = joints[i].JointNumber() - 1;

            if (bIncremental) {
                double increment = joints[i].JointPosition();
                JointStatusType::JointPosition_optional & optpos = _GoalJoints[n].JointPosition();
                ActuateJointType::JointPosition_type pos(*optpos);
                pos += increment;

                ::ActuateJointType jointcmd(joints[i].JointNumber(), pos, ::JointDetailsType());
                alljoints[n] = jointcmd;
            } else {
                ::ActuateJointType jointcmd(joints[i].JointNumber(), joints[i].JointPosition(), ::JointDetailsType());
                alljoints[n] = jointcmd;
            }
        }
        return alljoints;
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

    void CrclStatus::Update(urdf::Pose & pose) {
        _CurrentPose.Point().X() = pose.position.x;
        _CurrentPose.Point().Y() = pose.position.y;
        _CurrentPose.Point().Z() = pose.position.z;
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
        _GoalPose = _CurrentPose;
    }
};
