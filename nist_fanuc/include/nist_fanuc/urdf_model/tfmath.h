//

// tfmath.h
//

// DISCLAIMER:
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied
// or intended.

#pragma once
#include <tf/transform_datatypes.h>

#include <boost/array.hpp>
#include <boost/format.hpp>

#ifndef CLOSESMALL
#define CLOSESMALL

struct Math {

    static double & COMPARE_EPSILON() {
        static double epsilon = 1.0e-7;
        return epsilon;
    }
};

inline bool TRAN_CLOSE(double x, double y) {
    return std::abs(x - y) < Math::COMPARE_EPSILON();
}

inline bool TRAN_SMALL(double x) {
    return std::abs(x) < Math::COMPARE_EPSILON();
}

inline bool ROT_CLOSE(double x, double y) {
    return std::abs(x - y) < Math::COMPARE_EPSILON();
}

inline bool ROT_SMALL(double x) {
    return std::abs(x) < Math::COMPARE_EPSILON();
}

inline bool CLOSE(double x, double y) {
    return std::abs(x - y) < Math::COMPARE_EPSILON();
}

inline bool SMALL(double x) {
    return std::abs(x) < Math::COMPARE_EPSILON();
}
#endif

// borrowed much from https://github.com/frederickproctor/gomotion/tree/master/src
#define REAL_EPSILON     ( 1.0e-7 )
#define TRAN_CLOSE(x, y)    ( fabs( ( x ) - ( y ) ) < REAL_EPSILON )
#define SINGULAR_FUZZ    ( 1.0e-6 )
#define FLAG_FUZZ        ( 1.0e-6 )

#ifndef HAVE_SINCOS
#define HAVE_SINCOS

inline void sincos(double x, double *sx, double *cx) {
    *sx = sin(x);
    *cx = cos(x);
}
#endif

#ifndef Deg2Rad
#define Deg2Rad(Ang)    ( (double) ( Ang * M_PI / 180.0 ) )
#define Rad2Deg(Ang)    ( (double) ( Ang * 180.0 / M_PI ) )
#define MM2Meter(d)     ( (double) ( d / 1000.00 ) )
#define Meter2MM(d)     ( (double) ( d * 1000.00 ) )
#endif

#ifndef ROSMATRIX
#define ROSMATRIX
typedef boost::array<double, 12> RosMatrix;
#endif

#if 0
bool _eq3(const tf::Vector3 & v0, const tf::Vector3 & v1, double fuzz);
double _magnitude3(const tf::Vector3 & v0);
double _dist3(const tf::Vector3 & v0, const tf::Vector3 & v1);
double _dot3(const tf::Vector3 & v0, const tf::Vector3 & v1);
tf::Vector3 _mult3(const tf::Vector3 & v0, double s);
tf::Vector3 _mult3(double s, const tf::Vector3 & v0);
tf::Vector3 _cross3(const tf::Vector3 & v0, const tf::Vector3 & v1);
tf::Vector3 _sub3(const tf::Vector3 & v0, const tf::Vector3 & v1);
tf::Vector3 _add3(const tf::Vector3 & v0, const tf::Vector3 & v1);
tf::Vector3 _normalize3(const tf::Vector3 & v0, double epsilon = 0.0001);
double _dist3(const tf::Vector3 & v0, const tf::Vector3 & v1);
tf::Vector3 _lerp3(tf::Vector3 v1, tf::Vector3 v2, double scale);
tf::Vector3 _normal3(const tf::Vector3 & v);
tf::Vector3 _projection(tf::Vector3 v1, tf::Vector3 v2);
 
RosMatrix _3x3matrixConvert(double m[9]);
RosMatrix _matrixFromQuat(const tf::Quaternion & quat);
RosMatrix _matrixFromRPY(double dRoll, double dPitch, double dYaw);
tf::Pose _poseFromMatrix(const boost::array<double, 12> & m);
RosMatrix _matrixFromPose(const tf::Pose & t);
RosMatrix _matrixMult(const RosMatrix & m0, const RosMatrix & m1);
tf::Vector3 _vectorMatrixMult(const RosMatrix & m, const tf::Vector3 & v);
RosMatrix _matrixIdentity();
void _matrixToRPY(RosMatrix & m, double &dRoll, double &dPitch, double &dYaw);

double _quatAngle(tf::Quaternion & q1, tf::Quaternion & q2);
tf::Vector3 _quatCartMult(const tf::Quaternion q1, const tf::Vector3 v2);
double _quatDot(const tf::Quaternion & left, const tf::Quaternion & right);
tf::Quaternion _quatScalarMult(const tf::Quaternion q1, double d);
tf::Quaternion _quatFromMatrix(RosMatrix & mat);
tf::Quaternion _quatFromRpy(double & roll, double & pitch, double & yaw);
tf::Quaternion _quatFromCartCart(const tf::Vector3 & v1, const tf::Vector3 & v2);
tf::Quaternion _quatInv(const tf::Quaternion q1);
tf::Quaternion _quatConjugate(const tf::Quaternion q1);
tf::Quaternion _quatIdentify();
bool _quatIsNorm(const tf::Quaternion q1);
double _quatMagnitude(const tf::Quaternion q1);
tf::Quaternion _quatMult(const tf::Quaternion & quat0, const tf::Quaternion & quat1);
tf::Quaternion _quatNormalize(const tf::Quaternion q1);
tf::Quaternion _quatSlerp(tf::Quaternion & qa, tf::Quaternion & qb, double t);
double _quatRotation(tf::Quaternion & qcurrent, tf::Quaternion & qgoal);
void _quatToRpy(tf::Quaternion & q1, double & roll, double & pitch, double & yaw);
tf::Quaternion _quatUnit(const tf::Quaternion q1);
tf::Vector3 _quatToAxisAngle(const tf::Quaternion q);
tf::Quaternion _quatFromAxisAngle(const tf::Vector3 & r);


tf::Vector3 _poseMult(const tf::Pose & p, const tf::Vector3 & v);
tf::Pose _poseInverse(const tf::Pose & p);
tf::Pose _poseMult(const tf::Pose & p0, const tf::Pose & p1);
tf::Pose _poseInv(const tf::Pose & p1);

//inline std::ostream & operator << (std::ostream & os, const tf::Pose & pose)
//{
//	os << "Translation = " << boost::format("%11.4f") % ( 1000.0 * pose.position.x ) << ":" << boost::format("%11.4f") % ( 1000.0 * pose.position.y ) << ":" << boost::format("%11.4f") % ( 1000.0 * pose.position.z ) << std::endl;
//
//	// os << "Rotation = "  << pose.rotation.x << ":"<<  pose.rotation.y  << ":"<< pose.rotation.z << ":"<< pose.rotation.w << std::endl;
//	double roll, pitch, yaw;
//	pose.rotation.getRPY(roll, pitch, yaw);
//	os << "Rotation    = " << boost::format("%11.4f") % Rad2Deg(roll) << ":" << boost::format("%11.4f") % Rad2Deg(pitch) << ":" << boost::format("%11.4f") % Rad2Deg(yaw) << std::endl;
//	return os;
//}

inline std::ostream & operator<<(std::ostream & os, const tf::Vector3 & v) {
    os << "Vector = " << boost::format("%11.4f") % v.x() << ":" << boost::format("%11.4f") % v.y() << ":" << boost::format("%11.4f") % v.z() << std::endl;
    return os;
}

inline bool operator==(const tf::Vector3 & v0, const tf::Vector3 & v1) {
    return _magnitude3(_sub3(v0, v1)) < REAL_EPSILON;
}

/*!
 * \brief _eq3 dfetermines if two vector are equal given a epsilon closeness factor.
 * \return true if two vectors are equal.
 */
inline bool _eq3(const tf::Vector3 & v0, const tf::Vector3 & v1, double fuzz) {
    return _magnitude3(_sub3(v0, v1)) < fuzz;
}

inline double _magnitude3(const tf::Vector3 & v0) {
    return sqrt(_dot3(v0, v0));
}

inline double _dist3(const tf::Vector3 & v0, const tf::Vector3 & v1) {
    tf::Vector3 vdiff = _sub3(v0, v1);

    return sqrt(_dot3(vdiff, vdiff));
}

inline double _dot3(const tf::Vector3 & v0, const tf::Vector3 & v1) {
    return v0.x() * v1.x() + v0.y() * v1.y() + v0.z() * v1.z();
}

inline tf::Vector3 _mult3(const tf::Vector3 & v0, double s) {
    tf::Vector3 v;

    v = v0;
    v.x() *= s;
    v.y() *= s;
    v.z() *= s;
    return v;
}

inline tf::Vector3 _mult3(double s, const tf::Vector3 & v0) {
    tf::Vector3 v;

    v = v0;
    v.x() *= s;
    v.y() *= s;
    v.z() *= s;
    return v;
}

inline tf::Vector3 _cross3(const tf::Vector3 & v0, const tf::Vector3 & v1) {
    tf::Vector3 v;

    v.x() = v0.y() * v1.z() - v0.z() * v1.y();
    v.y() = v0.z() * v1.x() - v0.x() * v1.z();
    v.z() = v0.x() * v1.y() - v0.y() * v1.x();
    return v;
}

inline tf::Vector3 _sub3(const tf::Vector3 & v0, const tf::Vector3 & v1) {
    tf::Vector3 v;

    v.x() = v0.x() - v1.x();
    v.y() = v0.y() - v1.y();
    v.z() = v0.z() - v1.z();
    return v;
}

inline tf::Vector3 _add3(const tf::Vector3 & v0, const tf::Vector3 & v1) {
    tf::Vector3 v;

    v.x() = v0.x() + v1.x();
    v.y() = v0.y() + v1.y();
    v.z() = v0.z() + v1.z();
    return v;
}

inline tf::Vector3 _normalize3(const tf::Vector3 & v0, double epsilon) {
    tf::Vector3 v;
    double norm = std::sqrt(v0.x() * v0.x() + v0.y() * v0.y() + v0.z() * v0.z());
    if (norm < epsilon)
        throw std::runtime_error("Cannot make unit vector out of zero vector");
    v.x() = v0.x() / norm;
    v.y() = v0.y() / norm;
    v.z() = v0.z() / norm;
    return v;
}

inline tf::Vector3 _projection(tf::Vector3 v1, tf::Vector3 v2) {
    tf::Vector3 v2u = _normalize3(v2);
    double d = _dot3(v1, v2u);
    return _mult3(d,v2u);
}

inline tf::Vector3 _lerp3(tf::Vector3 v1, tf::Vector3 v2, double scale) {
    tf::Vector3 tmp2;
    tmp2 = _sub3(v2, v1);
    tmp2 = _mult3(tmp2, scale);
    return _add3(v1, tmp2);
}

inline tf::Vector3 _normal3(const tf::Vector3 & v) {
    tf::Vector3 cart, vout;
    double min, ymin;

    /* pick the X, Y or Z vector that is most perpendicular to 'v' */
    cart.x() = 1, cart.y() = 0, cart.z() = 0; /* start with X */
    min = fabs(v.x());
    ymin = fabs(v.y());

    if (ymin < min) {
        min = ymin; /* Y is more perp */
        cart.x() = 0, cart.y() = 1, cart.z() = 0;
    }

    if (fabs(v.z) < min) {
        cart.x() = 0, cart.y() = 0, cart.z() = 1;
    }

    /* cross the most perp axis vector with 'v' to get a real perp */
    cart = _cross3(v, cart);

    /* unitize it into 'vout' and return */
    vout = _normalize3(cart);
    return vout;
}
// --------------------------------------------------------------------------------

inline RosMatrix _3x3matrixConvert(double m[9]) {
    boost::array<double, 12> rm;
    rm[4 * 0 + 0] = m[0];
    rm[4 * 0 + 1] = m[1];
    rm[4 * 0 + 2] = m[2];
    rm[4 * 0 + 3] = 0;
    rm[4 * 1 + 0] = m[3];
    rm[4 * 1 + 1] = m[4];
    rm[4 * 1 + 2] = m[5];
    rm[4 * 1 + 3] = 0;
    rm[4 * 2 + 0] = m[6];
    rm[4 * 2 + 1] = m[7];
    rm[4 * 2 + 2] = m[8];
    rm[4 * 2 + 3] = 0;
    return rm;
}
// From  http://docs.ros.org/jade/api/collada_parser/html/collada__parser_8cpp_source.html

inline RosMatrix _matrixFromQuat(const tf::Quaternion & quat) {
    boost::array<double, 12> m;
    double qq1 = 2 * quat.x * quat.x;
    double qq2 = 2 * quat.y * quat.y;
    double qq3 = 2 * quat.z * quat.z;
    m[4 * 0 + 0] = 1 - qq2 - qq3;
    m[4 * 0 + 1] = 2 * (quat.x() * quat.y() - quat.w() * quat.z());
    m[4 * 0 + 2] = 2 * (quat.x() * quat.z() + quat.w() * quat.y());
    m[4 * 0 + 3] = 0;
    m[4 * 1 + 0] = 2 * (quat.x() * quat.y() + quat.w() * quat.z());
    m[4 * 1 + 1] = 1 - qq1 - qq3;
    m[4 * 1 + 2] = 2 * (quat.y() * quat.z() - quat.w() * quat.x());
    m[4 * 1 + 3] = 0;
    m[4 * 2 + 0] = 2 * (quat.x() * quat.z() - quat.w() * quat.y());
    m[4 * 2 + 1] = 2 * (quat.y() * quat.z() + quat.w() * quat.x());
    m[4 * 2 + 2] = 1 - qq1 - qq2;
    m[4 * 2 + 3] = 0;
    return m;
}

inline tf::Quaternion _quatFromMatrix(RosMatrix & mat) {
    tf::Quaternion rot;
    double tr = mat[4 * 0 + 0] + mat[4 * 1 + 1] + mat[4 * 2 + 2];

    if (tr >= 0) {
        rot.w() = tr + 1;
        rot.x() = (mat[4 * 2 + 1] - mat[4 * 1 + 2]);
        rot.y() = (mat[4 * 0 + 2] - mat[4 * 2 + 0]);
        rot.z() = (mat[4 * 1 + 0] - mat[4 * 0 + 1]);
    } else {
        // find the largest diagonal element and jump to the appropriate case
        if (mat[4 * 1 + 1] > mat[4 * 0 + 0]) {
            if (mat[4 * 2 + 2] > mat[4 * 1 + 1]) {
                rot.z() = (mat[4 * 2 + 2] - (mat[4 * 0 + 0] + mat[4 * 1 + 1])) + 1;
                rot.x() = (mat[4 * 2 + 0] + mat[4 * 0 + 2]);
                rot.y() = (mat[4 * 1 + 2] + mat[4 * 2 + 1]);
                rot.w() = (mat[4 * 1 + 0] - mat[4 * 0 + 1]);
            } else {
                rot.y() = (mat[4 * 1 + 1] - (mat[4 * 2 + 2] + mat[4 * 0 + 0])) + 1;
                rot.z() = (mat[4 * 1 + 2] + mat[4 * 2 + 1]);
                rot.x() = (mat[4 * 0 + 1] + mat[4 * 1 + 0]);
                rot.w() = (mat[4 * 0 + 2] - mat[4 * 2 + 0]);
            }
        } else if (mat[4 * 2 + 2] > mat[4 * 0 + 0]) {
            rot.z() = (mat[4 * 2 + 2] - (mat[4 * 0 + 0] + mat[4 * 1 + 1])) + 1;
            rot.x() = (mat[4 * 2 + 0] + mat[4 * 0 + 2]);
            rot.y() = (mat[4 * 1 + 2] + mat[4 * 2 + 1]);
            rot.w() = (mat[4 * 1 + 0] - mat[4 * 0 + 1]);
        } else {
            rot.x() = (mat[4 * 0 + 0] - (mat[4 * 1 + 1] + mat[4 * 2 + 2])) + 1;
            rot.y() = (mat[4 * 0 + 1] + mat[4 * 1 + 0]);
            rot.z() = (mat[4 * 2 + 0] + mat[4 * 0 + 2]);
            rot.w() = (mat[4 * 2 + 1] - mat[4 * 1 + 2]);
        }
    }
    double fnorm = std::sqrt(rot.x() * rot.x() + rot.y() * rot.y() + rot.z() * rot.z() + rot.w() * rot.w());

    // don't touch the divides
    rot.x() /= fnorm;
    rot.y() /= fnorm;
    rot.z() /= fnorm;
    rot.w() /= fnorm;
    return rot;
}

inline tf::Vector3 _quatToAxisAngle(const tf::Quaternion q) {
    double sh;
    double mag;
    tf::Vector3 r;

    sh = sqrt(q.x() * q.x() + q.y() * q.y() + q.z() * q.z());

    if (SMALL(sh)) {
        r = tf::Vector3(0, 0, 0);
    } else {
        mag = 2 * atan2(sh, q.w()) / sh;
        r.x() = mag * q.x;
        r.y() = mag * q.y;
        r.z() = mag * q.z;
    }

    return r;
}
#if 0
#define GO_REAL_EPSILON    ( 1.0e-7 )
#define GO_TRAN_CLOSE(x, y)    ( fabs( ( x ) - ( y ) ) < GO_REAL_EPSILON )

go_flag go_mat_is_norm(const go_mat *m) {
    go_cart u;

    go_cart_cart_cross(&m->x, &m->y, &u);

#define COL_IS_UNIT(r)    GO_TRAN_CLOSE(go_sq( ( r ).x) + go_sq( ( r ).y) + go_sq( ( r ).z), 1)
    return COL_IS_UNIT(m->x) &&
            COL_IS_UNIT(m->y) &&
            COL_IS_UNIT(m->z) &&
            go_cart_cart_compare(&u, &m->z);

#undef COL_IS_UNIT
}

/*
from space book:

e1 = (c32 - c23) / 4*e4
e2 = (c13 - c31) / 4*e4
e3 = (c21 - c12) / 4*e4
e4 = sqrt(1 + c11 + c22 + c33) / 2

if e4 == 0
e1 = sqrt(1 + c11 - c33 - c22) / 2
e2 = sqrt(1 + c22 - c33 - c11) / 2
e3 = sqrt(1 + c33 - c11 - c22) / 2

to determine whether to take the positive or negative sqrt value
since e4 == 0 indicates a 180* rotation then (0 x y z) = (0 -x -y -z).
Thus some generalities can be used:
1) find which of e1, e2, or e3 has the largest magnitude and leave it pos
2) if e1 is largest then
if c21 < 0 then take the negative for e2
if c31 < 0 then take the negative for e3
3) else if e2 is largest then
if c21 < 0 then take the negative for e1
if c32 < 0 then take the negative for e3
4) else if e3 is larget then
if c31 < 0 then take the negative for e1
if c32 < 0 then take the negative for e2

Note: c21 in the space book is m.x.y in this C code
 */
go_result go_mat_quat_convert(const go_mat *m, go_quat *q) {
    go_real discr;
    go_real a;

    if (!go_mat_is_norm(m)) {
        return GO_RESULT_NORM_ERROR;
    }

    discr = 1.0 + m->x.x + m->y.y + m->z.z;

    if (discr < 0.0) {
        discr = 0.0; /* give sqrt some slack for tiny negs */
    }
    q->s = 0.5 * sqrt(discr);

    if (GO_ROT_SMALL(q->s)) {
        q->s = 0;
        discr = 1.0 + m->x.x - m->y.y - m->z.z;

        if (discr < 0.0) {
            discr = 0.0;
        }
        q->x = sqrt(discr) / 2.0;
        discr = 1.0 + m->y.y - m->x.x - m->z.z;

        if (discr < 0.0) {
            discr = 0.0;
        }
        q->y = sqrt(discr) / 2.0;
        discr = 1.0 + m->z.z - m->y.y - m->x.x;

        if (discr < 0.0) {
            discr = 0.0;
        }
        q->z = sqrt(discr) / 2.0;

        if ((q->x > q->y) && (q->x > q->z)) {
            if (m->x.y < 0.0) {
                q->y *= -1;
            }

            if (m->x.z < 0.0) {
                q->z *= -1;
            }
        } else if (q->y > q->z) {
            if (m->x.y < 0.0) {
                q->x *= -1;
            }

            if (m->y.z < 0.0) {
                q->z *= -1;
            }
        } else {
            if (m->x.z < 0.0) {
                q->x *= -1;
            }

            if (m->y.z < 0.0) {
                q->y *= -1;
            }
        }
    } else {
        q->x = (m->y.z - m->z.y) / (a = 4 * q->s);
        q->y = (m->z.x - m->x.z) / a;
        q->z = (m->x.y - m->y.x) / a;
    }

    return go_quat_norm(q, q);
}
#endif

inline RosMatrix _matrixFromRPY(double dRoll, double dPitch, double dYaw) {
    tf::Quaternion rotation = _quatFromRpy(dRoll, dPitch, dYaw);

    return _matrixFromQuat(rotation);
}

inline void _matrixToRPY(RosMatrix & m, double &dRoll, double &dPitch, double &dYaw) {
    dPitch = atan2(-m[4 * 0 + 2], sqrt(m[4 * 0 + 0] * m[4 * 0 + 0] + m[4 * 0 + 1] * m[4 * 0 + 1]));

    if (CLOSE(dPitch, M_PI_2)) {
        dRoll = atan2(m[4 * 1 + 0], m[4 * 1 + 1]);
        dPitch = M_PI_2; /* force it */
        dYaw = 0;
    } else if (CLOSE(dPitch, -M_PI_2)) {
        dRoll = -atan2(m[4 * 1 + 0], m[4 * 1 + 1]);
        dPitch = -M_PI_2; /* force it */
        dYaw = 0;
    } else {
        dRoll = atan2(m[4 * 1 + 2], m[4 * 2 + 2]);
        dYaw = atan2(m[4 * 0 + 1], m[4 * 0 + 0]);
    }

}

inline tf::Pose _poseFromMatrix(const boost::array<double, 12> & m) {
    tf::Pose t;

    t.rotation = _quatFromMatrix((RosMatrix &) m);
    t.position.x() = m[3];
    t.position.y() = m[7];
    t.position.z() = m[11];
    return t;
}

inline RosMatrix _matrixFromPose(const tf::Pose & t) {
    boost::array<double, 12> m = _matrixFromQuat(t.rotation);
    m[3] = t.position.x();
    m[7] = t.position.y();
    m[11] = t.position.z();
    return m;
}

inline RosMatrix _matrixMult(const RosMatrix & m0, const RosMatrix & m1) {
    RosMatrix mres;

    mres[0 * 4 + 0] = m0[0 * 4 + 0] * m1[0 * 4 + 0] + m0[0 * 4 + 1] * m1[1 * 4 + 0] + m0[0 * 4 + 2] * m1[2 * 4 + 0];
    mres[0 * 4 + 1] = m0[0 * 4 + 0] * m1[0 * 4 + 1] + m0[0 * 4 + 1] * m1[1 * 4 + 1] + m0[0 * 4 + 2] * m1[2 * 4 + 1];
    mres[0 * 4 + 2] = m0[0 * 4 + 0] * m1[0 * 4 + 2] + m0[0 * 4 + 1] * m1[1 * 4 + 2] + m0[0 * 4 + 2] * m1[2 * 4 + 2];
    mres[1 * 4 + 0] = m0[1 * 4 + 0] * m1[0 * 4 + 0] + m0[1 * 4 + 1] * m1[1 * 4 + 0] + m0[1 * 4 + 2] * m1[2 * 4 + 0];
    mres[1 * 4 + 1] = m0[1 * 4 + 0] * m1[0 * 4 + 1] + m0[1 * 4 + 1] * m1[1 * 4 + 1] + m0[1 * 4 + 2] * m1[2 * 4 + 1];
    mres[1 * 4 + 2] = m0[1 * 4 + 0] * m1[0 * 4 + 2] + m0[1 * 4 + 1] * m1[1 * 4 + 2] + m0[1 * 4 + 2] * m1[2 * 4 + 2];
    mres[2 * 4 + 0] = m0[2 * 4 + 0] * m1[0 * 4 + 0] + m0[2 * 4 + 1] * m1[1 * 4 + 0] + m0[2 * 4 + 2] * m1[2 * 4 + 0];
    mres[2 * 4 + 1] = m0[2 * 4 + 0] * m1[0 * 4 + 1] + m0[2 * 4 + 1] * m1[1 * 4 + 1] + m0[2 * 4 + 2] * m1[2 * 4 + 1];
    mres[2 * 4 + 2] = m0[2 * 4 + 0] * m1[0 * 4 + 2] + m0[2 * 4 + 1] * m1[1 * 4 + 2] + m0[2 * 4 + 2] * m1[2 * 4 + 2];
    mres[3] = m1[3] * m0[0] + m1[7] * m0[1] + m1[11] * m0[2] + m0[3];
    mres[7] = m1[3] * m0[4] + m1[7] * m0[5] + m1[11] * m0[6] + m0[7];
    mres[11] = m1[3] * m0[8] + m1[7] * m0[9] + m1[11] * m0[10] + m0[11];
    return mres;
}

inline tf::Vector3 _vectorMatrixMult(const RosMatrix & m, const tf::Vector3 & v) {
    tf::Vector3 vnew;

    vnew.x = m[4 * 0 + 0] * v.x + m[4 * 0 + 1] * v.y + m[4 * 0 + 2] * v.z + m[4 * 0 + 3];
    vnew.y = m[4 * 1 + 0] * v.x + m[4 * 1 + 1] * v.y + m[4 * 1 + 2] * v.z + m[4 * 1 + 3];
    vnew.z = m[4 * 2 + 0] * v.x + m[4 * 2 + 1] * v.y + m[4 * 2 + 2] * v.z + m[4 * 2 + 3];
    return vnew;
}

inline RosMatrix _matrixIdentity() {
    RosMatrix m = {
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0}
    };

    return m;
}

inline bool _quatIsNorm(const tf::Quaternion q1) {
    if (TRAN_CLOSE((q1.w() * q1.w())
            + (q1.x() * q1.x())
            + (q1.y() * q1.y())
            + (q1.z() * q1.z()), 1.0)) {
        return true;
    }
    return false;
}

inline tf::Vector3 _quatCartMult(const tf::Quaternion q1, const tf::Vector3 v2) {
    tf::Vector3 c;
    tf::Vector3 vout;

    if (!_quatIsNorm(q1)) {
        throw "GO_RESULT_NORM_ERROR";
    }

    c.x = q1.y() * v2.z() - q1.z() * v2.y();
    c.y = q1.z() * v2.x() - q1.x() * v2.z();
    c.z = q1.x() * v2.y() - q1.y() * v2.x();

    vout.x = v2.x() + 2 * (q1.w() * c.x() + q1.y() * c.z() - q1.z() * c.y());
    vout.y = v2.y() + 2 * (q1.w() * c.y() + q1.z() * c.x() - q1.x() * c.z());
    vout.z = v2.z() + 2 * (q1.w() * c.z() + q1.x() * c.y() - q1.y() * c.x());

    return vout;
}

inline void _quatToRpy(tf::Quaternion & q1, double & roll, double & pitch, double & yaw) {

#if 1
    RosMatrix m;
    m = _matrixFromQuat(q1);
    _matrixToRPY(m, roll, pitch, yaw);
#else
    // Not sure - the quaterion may have to be normalized 1st?
    q1.getRPY(roll, pitch, yaw);
#endif

}

inline tf::Quaternion _quatFromRpy(double & roll, double & pitch, double & yaw) // Assuming the angles are in radians.
{
    tf::Quaternion q;
#if 1
    double c1 = cos(roll / 2);
    double s1 = sin(roll / 2);
    double c2 = cos(pitch / 2);
    double s2 = sin(pitch / 2);
    double c3 = cos(yaw / 2);
    double s3 = sin(yaw / 2);
    double c1c2 = c1 * c2;
    double s1s2 = s1 * s2;

    q.w() = c1c2 * c3 - s1s2 * s3;
    q.x() = c1c2 * s3 + s1s2 * c3;
    q.y() = s1 * c2 * c3 + c1 * s2 * s3;
    q.z() = c1 * s2 * c3 - s1 * c2 * s3;
#else
    q.setFromRPY(roll, pitch, yaw);
#endif
    return q;
}

inline double _quatMagnitude(const tf::Quaternion q1) {
    double sh = sqrt(q1.x() * q1.x() + q1.y() * q1.y() + q1.z() * q1.z());
    return 2 * atan2(sh, q1.w());
}

inline tf::Quaternion _quatScalarMult(const tf::Quaternion q, double s) {
    tf::Quaternion qout;
    double sh; /* sine of half angle */
    double ha; /* half angle */
    double scale; /* new sh / old sh */

    sh = sqrt(q.x * q.x + q.y * q.y + q.z * q.z);
    ;
    if (SMALL(sh)) {
        /* zero rotation-- leave it alone */
        return q;
    }

    ha = atan2(sh, q.w);
    ha *= s;
    scale = sin(ha) / sh;

    qout.w() = cos(ha);
    qout.x() = scale * q.x();
    qout.y() = scale * q.y();
    qout.z() = scale * q.z();
    return qout;
}

inline tf::Quaternion _quatIdentify() {
    return tf::Quaternion(0.0, 0.0, 0.0, 1.0);
}

inline tf::Quaternion _quatConjugate(const tf::Quaternion q1) {
    tf::Quaternion qout;
    qout.w() = q1.w();
    qout.x() = -q1.x();
    qout.y() = -q1.y();
    qout.z() = -q1.z();
    return qout;
}

inline tf::Quaternion _quatInv(const tf::Quaternion q1) {
    tf::Quaternion qout;

    qout.w() = q1.w();
    qout.x() = -q1.x();
    qout.y() = -q1.y();
    qout.z() = -q1.z();

    if (!_quatIsNorm(q1)) {
        throw "RESULT_NORM_ERROR";
    }

    return qout;
}

inline tf::Quaternion _quatUnit(const tf::Quaternion q1) {
    double d = _quatMagnitude(q1);
    if (SMALL(d))
        throw "can't unit quaterion with zero magnitude";
    d = 1.0 / d;
    return _quatScalarMult(q1, d);
}

inline tf::Quaternion _quatNormalize(const tf::Quaternion q1) {
    double size;
    tf::Quaternion qout;

    size = sqrt(q1.w * q1.w + q1.x * q1.x + q1.y * q1.y + q1.z * q1.z);

    if (SMALL(size)) {
        qout = _quatIdentify();
        return qout;
    }
    size = 1.0 / size;

    if (q1.w >= 0) {
        qout.w() = q1.w() * size;
        qout.x() = q1.x() * size;
        qout.y() = q1.y() * size;
        qout.z() = q1.z() * size;
    } else {
        qout.w() = -q1.w() * size;
        qout.x() = -q1.x() * size;
        qout.y() = -q1.y() * size;
        qout.z() = -q1.z() * size;
    }
    return qout;
}

inline tf::Quaternion _quatSlerp(tf::Quaternion & qa, tf::Quaternion & qb, double t) {
    // quaternion to return
    tf::Quaternion qm;

    // Calculate angle beteen them.
    double costheta = qa.w * qb.w + qa.x * qb.x + qa.y * qb.y + qa.z * qb.z;
    double theta = acos(costheta);

    // if theta = 0 then return qa
    if (fabs(theta) < 0.01) {
        qm.w() = qa.w();
        qm.x() = qa.x();
        qm.y() = qa.y();
        qm.z() = qa.z();
        return qm;
    }
    // Calculate temporary values.
    double sinTheta = sqrt(1.0 - costheta * costheta);
    // if theta*2 = 180 degrees then result is undefined
    if (fabs(sinTheta) < 0.01) {
        qm.w() = (qa.w() * 0.5 + qb.w() * 0.5);
        qm.x() = (qa.x() * 0.5 + qb.x() * 0.5);
        qm.y() = (qa.y() * 0.5 + qb.y() * 0.5);
        qm.z() = (qa.z() * 0.5 + qb.z() * 0.5);
        return qm;
    }
    double ratioA = sin((1 - t) * theta) / sinTheta;
    double ratioB = sin(t * theta) / sinTheta;

    //calculate Quaternion.
    qm.w() = (qa.w() * ratioA + qb.w() * ratioB);
    qm.x() = (qa.x() * ratioA + qb.x() * ratioB);
    qm.y() = (qa.y() * ratioA + qb.y() * ratioB);
    qm.z() = (qa.z() * ratioA + qb.z() * ratioB);
    return qm;
}

inline double _quatDot(const tf::Quaternion & left, const tf::Quaternion & right) {
    return left.x() * right.x() + left.y() * right.y() + left.z() * right.z() + left.w() * right.w();
}

inline double _quatAngle(tf::Quaternion & q1, tf::Quaternion & q2) {
    tf::Quaternion q = _quatMult(_quatInv(q1), q2);
    return 2.0 * atan2(_quatMagnitude(q), q.w);
}

inline double _quatRotation(tf::Quaternion & qcurrent, tf::Quaternion & qgoal) {
    double s = _quatDot(qcurrent, qgoal);
    return acos(s);
}

inline tf::Quaternion _quatMult(const tf::Quaternion & quat0, const tf::Quaternion & quat1) {
    tf::Quaternion q;

    q.x() = quat0.w() * quat1.x() + quat0.x() * quat1.w() + quat0.y() * quat1.z() - quat0.z() * quat1.y();
    q.y() = quat0.w() * quat1.y() + quat0.y() * quat1.w() + quat0.z() * quat1.x() - quat0.x() * quat1.z();
    q.z() = quat0.w() * quat1.z() + quat0.z() * quat1.w() + quat0.x() * quat1.y() - quat0.y() * quat1.x();
    q.w() = quat0.w() * quat1.w() - quat0.x() * quat1.x() - quat0.y() * quat1.y() - quat0.z() * quat1.z();
    double fnorm = std::sqrt(q.x() * q.x() + q.y() * q.y() + q.z() * q.z() + q.w() * q.w());

    // don't touch the divides
    q.x() /= fnorm;
    q.y() /= fnorm;
    q.z() /= fnorm;
    q.w() /= fnorm;
    return q;
}

inline tf::Quaternion _quatFromAxisAngle(const tf::Vector3 & r) {
    tf::Quaternion q;
    tf::Vector3 vec;
    tf::Vector3 uvec;
    double mag;
    double sh;

    vec.x = r.x;
    vec.y = r.y;
    vec.z = r.z;
    uvec = _normalize3(vec);

    if (SMALL(_magnitude3(uvec))) {
        /* a zero vector */
        q.w() = 1;
        q.x() = q.y() = q.z() = 0;
        return q;
    }

    mag = _magnitude3(vec);

    sincos(0.5 * mag, &sh, &(q.w));

    if (q.w >= 0) {
        q.x() = uvec.x() * sh;
        q.y() = uvec.y() * sh;
        q.z() = uvec.z() * sh;
    } else {
        q.w() = -q.w();
        q.x() = -uvec.x() * sh;
        q.y() = -uvec.y() * sh;
        q.z() = -uvec.z() * sh;
    }

    return q;
}

inline tf::Quaternion _quatFromCartCart(const tf::Vector3 & v1,
        const tf::Vector3 & v2) {
    tf::Quaternion quat;
    tf::Vector3 u1;
    tf::Vector3 u2;
    tf::Vector3 cross;
    double mag;
    double dot;
    double th;
    tf::Vector3 rvec;

    /* unitize the input vectors */
    u1 = _normalize3(v1);
    u2 = _normalize3(v2);
    cross = _cross3(u1, u2); /* and cross the unit vectors to get the mutual normal */
    mag = _magnitude3(cross); /* the magnitude of the mutual normal is sin theta */
    th = asin(mag);
    dot = _dot3(u1, u2); /* dot them to get parallel (1) or antiparallel (-1) */
    /* make the cross a unit vector so we can theta-ize it */

    /* handle aligned vectors */
    if (SMALL(_magnitude3(cross))) {
        /* v1 and v2 are aligned, so th will be zero */
        if (dot > 0.0) /* would be -1 or 1 */ { /* parallel */
            quat.w() = 1.0;
            quat.x() = quat.y() = quat.z() = 0.0;
            return quat;
        }

        /* else antiparallel - set u2 to be normal to u1,
         * rotate about it PI rads */
        u2 = _normal3(u1);
        rvec.x() = M_PI * u2.x();
        rvec.y() = M_PI * u2.y();
        rvec.z() = M_PI * u2.z();
        quat = _quatFromAxisAngle(rvec);
        return quat;
    }
    cross = _normalize3(cross);

    /* else not aligned */
    if (dot < 0.0) {
        th = M_PI - th;
    }
    rvec.x() = th * cross.x();
    rvec.y() = th * cross.y();
    rvec.z() = th * cross.z();
    quat = _quatFromAxisAngle(rvec);
    return quat;
}
//----------------------------------------------------------------------------

inline tf::Pose _poseMult(const tf::Pose & p0, const tf::Pose & p1) {
    tf::Pose p;

    p.position = _poseMult(p0, p1.position);
    p.rotation = _quatMult(p0.rotation, p1.rotation);
    return p;
}

inline tf::Pose _poseInverse(const tf::Pose & p) {
    tf::Pose pinv;

    pinv.rotation.x() = -p.rotation.x();
    pinv.rotation.y() = -p.rotation.y();
    pinv.rotation.z() = -p.rotation.z();
    pinv.rotation.w() = p.rotation.w();
    tf::Vector3 t = _poseMult(pinv, p.position);
    pinv.position.x() = -t.x;
    pinv.position.y() = -t.y;
    pinv.position.z() = -t.z;
    return pinv;
}

inline tf::Vector3 _poseMult(const tf::Pose & p, const tf::Vector3 & v) {
    double ww = 2 * p.rotation.x() * p.rotation.x();
    double wx = 2 * p.rotation.x() * p.rotation.y();
    double wy = 2 * p.rotation.x() * p.rotation.z();
    double wz = 2 * p.rotation.x() * p.rotation.w();
    double xx = 2 * p.rotation.y() * p.rotation.y();
    double xy = 2 * p.rotation.y() * p.rotation.z();
    double xz = 2 * p.rotation.y() * p.rotation.w();
    double yy = 2 * p.rotation.z() * p.rotation.z();
    double yz = 2 * p.rotation.z() * p.rotation.w();
    tf::Vector3 vnew;

    vnew.x = (1 - xx - yy) * v.x + (wx - yz) * v.y + (wy + xz) * v.z + p.position.x();
    vnew.y = (wx + yz) * v.x + (1 - ww - yy) * v.y + (xy - wz) * v.z + p.position.y();
    vnew.z = (wy - xz) * v.x + (xy + wz) * v.y + (1 - ww - xx) * v.z + p.position.z();
    return vnew;
}

inline tf::Pose _poseInv(const tf::Pose & p1) {
    tf::Pose p2;

    p2.rotation = _quatInv(p1.rotation);

    p2.position = _quatCartMult(p2.rotation, p1.position);

    p2.position.x() = -p2.position.x();
    p2.position.y() = -p2.position.y();
    p2.position.z() = -p2.position.z();
    return p2;
}

// Convert joint angle degrees to radians

inline void ToRadians(std::vector<double> & motors) {
    std::transform(motors.begin(), motors.end(), motors.begin(),
            std::bind1st(std::multiplies<double>(), M_PI / 180.0));
}

#endif
