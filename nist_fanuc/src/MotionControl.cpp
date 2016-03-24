

#include "MotionControl.h"
//#include "urdf_model/rosmath.h"
#include <algorithm>
#include "Conversions.h"

double MotionControl::epsilon = 0.001;

bool MotionControl::executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory, const std::string& trajectory_ns) {
    // Create a Follow Joint Trajectory Action Client
    actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac(trajectory_ns, true);
    if (!ac.waitForServer(ros::Duration(2.0))) {
        ROS_ERROR("Could not connect to action server");
        return false;
    }

    control_msgs::FollowJointTrajectoryGoal goal;
    goal.trajectory = trajectory;
    goal.goal_time_tolerance = ros::Duration(1.0);

    ac.sendGoal(goal);

    if (ac.waitForResult(goal.trajectory.points[goal.trajectory.points.size() - 1].time_from_start + ros::Duration(5))) {
        ROS_INFO("Action server reported successful execution");
        return true;
    } else {
        ROS_WARN("Action server could not execute trajectory");
        return false;
    }
}

//template<typename T>

static bool epsiloncompare(double &i, double& j) {
    return (fabs(i - j) < MotionControl::epsilon);
}

template<typename T>
static bool VectorCompare(std::vector<T> vec1, std::vector<T> vec2) {
    return std::equal(vec1.begin(), vec1.end(), vec2.begin(), epsiloncompare);
}

bool MotionControl::AtGoal(JointState goal, JointState current, double epsilon) {
    MotionControl::epsilon = epsilon;
    return VectorCompare<double>(goal.position, current.position);
}

RCS::Pose MotionControl::computeTranslation(RCS::Pose & _curPos, RCS::Pose & _goalPos, double dIncrement) {
    RCS::Vector3 current(_curPos.getOrigin().x(), _curPos.getOrigin().y(), _curPos.getOrigin().z());
    RCS::Vector3 goal(_goalPos.getOrigin().x(), _goalPos.getOrigin().y(), _goalPos.getOrigin().z());
    RCS::Vector3 v = goal- current; //_sub3(goal, current);
    RCS::Pose pose;

    pose.getOrigin().setX(goal.x());
    pose.getOrigin().setY(goal.y());
    pose.getOrigin().setZ(goal.z());

    if (sqrt(v.dot(v)) < EPSILON) {
        return pose;
    }
    try {
        v = v.normalize();
        v = current + (v * dIncrement); // _add3(current, _mult3(v, dIncrement));
        pose.getOrigin().setX(v.x());
        pose.getOrigin().setY(v.y());
        pose.getOrigin().setZ(v.z());
    }    catch (...) {
        // Ignore zero vector normalization
    }
    return pose;
}
#if 0
static RCS::Rotation slerp(RCS::Rotation & qa, RCS::Rotation & qb, double t) {
    // quaternion to return
    RCS::Rotation qm;

    // Calculate angle beteen them.
    double costheta = qa.w * qb.w + qa.x * qb.x + qa.y * qb.y + qa.z * qb.z;
    double theta = acos(costheta);

    // if theta = 0 then return qa
    if (fabs(theta) < 0.01) {
        qm.w = qa.w;
        qm.x = qa.x;
        qm.y = qa.y;
        qm.z = qa.z;
        return qm;
    }

    // Calculate temporary values.
    double sinTheta = sqrt(1.0 - costheta * costheta);

    // if theta*2 = 180 degrees then result is undefined
    if (fabs(sinTheta) < 0.01) {
        qm.w = (qa.w * 0.5 + qb.w * 0.5);
        qm.x = (qa.x * 0.5 + qb.x * 0.5);
        qm.y = (qa.y * 0.5 + qb.y * 0.5);
        qm.z = (qa.z * 0.5 + qb.z * 0.5);
        return qm;
    }
    double ratioA = sin((1 - t) * theta) / sinTheta;
    double ratioB = sin(t * theta) / sinTheta;

    // calculate Quaternion.
    qm.w = (qa.w * ratioA + qb.w * ratioB);
    qm.x = (qa.x * ratioA + qb.x * ratioB);
    qm.y = (qa.y * ratioA + qb.y * ratioB);
    qm.z = (qa.z * ratioA + qb.z * ratioB);
    return qm;
}
#endif
std::vector<RCS::Pose>
MotionControl::computeWaypoints(RCS::Pose & _curPos, RCS::Pose & _goalPos, double dGap, bool bAddStart) {
    int nIncrements = computeIncrements(_curPos,_goalPos, dGap);
    double dIncrement = 1.0 / (double) nIncrements;
    std::vector<RCS::Pose> poses;
    int i = 1;
    i = (bAddStart) ? 0 : 1;
    for (; i <= nIncrements; i++) {
        RCS::Pose npose;
        RCS::Vector3 trans = _curPos.getOrigin().lerp( _goalPos.getOrigin(), i * dIncrement);
       //  npose.position = _lerp3(_curPos.position, _goalPos.position, i * dIncrement);
        //npose.rotation = slerp(_curPos.rotation, _goalPos.rotation, i * dIncrement);
        RCS::Rotation rot =  _curPos.getRotation().slerp(_goalPos.getRotation(), i * dIncrement);
        npose.setOrigin(trans);
        npose.setRotation(rot);
        poses.push_back(npose);
    }
    return poses;
}

int MotionControl::computeIncrements(RCS::Pose & _curPos, RCS::Pose & _goalPos , double dGap) {
    RCS::Vector3 v = _goalPos.getOrigin() -  _curPos.getOrigin();
    v.setX(fabs(v.x()));
    v.setY(fabs(v.y()));
    v.setZ(fabs(v.z()));
    double dMax = std::max(v.x(), v.y());
    dMax = std::max(dMax, v.z());
    return dMax / dGap + 1;
}

static double lerp(double start, double end, double scale) {
    return start + ((end - start) * scale);
}

static std::vector<JointState > Clear(std::vector<JointState > & a, size_t jts, size_t n) {

    a.clear();
    a.resize(n);
    for (size_t j = 0; j <= n; j++) {
        a[j].position.resize(jts, 0.0);
        a[j].velocity.resize(jts, 0.0);
        a[j].effort.resize(jts, 0.0);
    }
    return a;
}
// FIXME:
std::vector<JointState>
MotionControl::computeUncoorindatedWaypoints(std::vector<double> & _curJts, std::vector<double> & _goalJts, double dGap, bool bAddStart) {
    std::vector<double> diffs;
    std::vector<int> incrs;
    std::vector<JointState > joints;
    assert(0);
    // Compute how far each joint must move
    for (size_t j = 0; j <= _curJts.size(); j++) {
        diffs.push_back(fabs(_curJts[j] - _goalJts[j]));
        incrs.push_back(fabs(_curJts[j] - _goalJts[j]) / dGap + 1);
    }
    int nUpper = *std::max_element(incrs.begin(), incrs.end());
    Clear(joints, _curJts.size(), nUpper); // assign table
    // for each joint compute traversal using increment size
    for (size_t j = 0; j <= _curJts.size(); j++) {
        for (size_t k = 0; k <= incrs[j]; k++)
            joints[k].position[j] = lerp(_curJts[j], _goalJts[j], (double) k / (double) incrs[j]);
        for (size_t k = incrs[j]+1; k <= nUpper; k++)
            joints[k].position[j] = _goalJts[j];
    }
    return joints;
}

std::vector<JointState>
MotionControl::computeCoorindatedWaypoints(std::vector<double> & _curJts, std::vector<double> & _goalJts, double dGap, bool bAddStart) {
    double dMax = 0.0;
    for (size_t j = 0; j <= _curJts.size(); j++) {
        dMax = std::max(dMax, fabs(_curJts[j] - _goalJts[j]));
    }

    int nIncrement = dMax / dGap; // assume > 0 (+1?)
    std::vector<JointState > joints;
    int i = 1;
    i = (bAddStart) ? 0 : 1;
    for (; i <= nIncrement; i++) {
        JointState jnts;
        for (size_t j = 0; j < _curJts.size(); j++)
            jnts.position.push_back(lerp(_curJts[j], _goalJts[j], (double) i / (double) nIncrement));
        joints.push_back(jnts);
    }
    return joints;
}

int MotionControl::computeIncrements(std::vector<double> & _curJts, std::vector<double> & _goalJts, double gap) {
    double dMax = 0;
    for (size_t i = 0; i < _curJts.size(); i++)
        dMax = std::max(dMax, fabs(_curJts[i] - _goalJts[i]));
    return dMax / gap + 1;
}
