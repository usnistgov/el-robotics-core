// rosmath.h
//

// DISCLAIMER:
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied
// or intended.

#pragma once

#include <Eigen/Dense>

#ifdef STANDALONEURDF
#include "urdf_model/RobotModel.h"
#else
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <sensor_msgs/JointState.h>
#endif

#ifndef ROSMATRIX
#define ROSMATRIX
typedef boost::array<double, 12>   RosMatrix;
#endif


#ifndef CLOSESMALL
#define CLOSESMALL
inline bool CLOSE (double x, double y) { return std::abs(x - y) < std::numeric_limits<float>::epsilon();  }
inline bool SMALL (double x) { return std::abs(x) < std::numeric_limits<float>::epsilon(); }
#endif

#ifndef HAVE_SINCOS
#define HAVE_SINCOS
inline void sincos (double x, double *sx, double *cx)
{
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

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>  MatrixEXd;
typedef Eigen::VectorXd EJointVector;
typedef Eigen::VectorXd EigenPose;
typedef Eigen::Vector3d EigenPosition;

EJointVector              ToRadians(EJointVector joints);
Eigen::VectorXd           ConvertJoints(std::vector<double> v );
std::vector<double>       ConvertJoints(Eigen::VectorXd ev);
Eigen::VectorXd           ConvertPose(urdf::Pose p);
Eigen::VectorXd           ConvertPosition(urdf::Vector3 p);

std::string               DumpEMatrix( const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> & m);
std::string               DumpEPosition (const EigenPosition & v);
std::string               DumpEPose( const EigenPose & p);
std::string               DumpEJoints (const EJointVector & joints);

bool                      EQuatIsNorm(Eigen::Quaterniond &q1);
Eigen::Quaterniond        EPose2Quat(EigenPose p);
Eigen::Quaterniond        EQuatFromRpy (double & roll, double & pitch, double & yaw);
void                      EQuatToRpy (const Eigen::Quaterniond & q1, double & roll, double & pitch, double & yaw);
Eigen::Quaterniond        CreateQuaterian(double roll, double pitch, double yaw);

Eigen::VectorXd           EErrPosesAxisAngle(EigenPose current, EigenPose goal);
EigenPose                 ECreatePose(EigenPosition pos, Eigen::Quaterniond &q);
EigenPose                 EMatrix2Pose(MatrixEXd &m);
EigenPose                 EPoseAddQuat(EigenPose p, Eigen::Quaterniond & q);
EigenPose                 EPoseInv (const EigenPose & p1);
EigenPose                 EPoseMult (const EigenPose & p0, const EigenPose & p1);

EigenPosition             ECreatePosition(EigenPose pose);
EigenPosition             EPoseMult (const EigenPose & p, const EigenPosition & v);
EigenPosition             EQuatCartMult (Eigen::Quaterniond &q1, const EigenPosition v2);

//Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>  Ros2Eigen(RosMatrix m);
MatrixEXd                 Ros2Eigen(RosMatrix m);
MatrixEXd                 Create4x4IdentityMatrix();
MatrixEXd                 CreateMatrix(const double angle, Eigen::Vector3d axis);
MatrixEXd                 CreateMatrix(const EigenPosition translation);
MatrixEXd                 EPose2Matrix(EigenPose& p);
MatrixEXd                 EQuat2Matrix(Eigen::Quaterniond &q);
MatrixEXd	          PseudoInvertJacobian(const MatrixEXd &a) ;

Eigen::Affine3d           urdfPose2Affine3d(const urdf::Pose &pose);
urdf::Pose                affine3d2UrdfPose(const  Eigen::Affine3d &pose);

/*!
* \brief DumpEMatrix creates a string of the eigen matrix representation.
* \param m is the eigen matrix.
*/
inline std::string DumpEMatrix( const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> & m)
{
	std::stringstream s;

	for ( int j = 0; j < m.rows(); j++ )
	{
		for ( int i = 0; i < m.cols(); i++ )
		{
			s << boost::format("%8.5f") % m(j,i) << ":";
		}
		s << std::endl;
	}
	return s.str( );
}
/*!
* \brief DumpEPosition creates a string of the eigen position vector representation.
* \param v is the 3 element eigen vector3d.
*/
inline std::string DumpEPosition (const EigenPosition & v)
{
	std::stringstream s;
	for ( int j = 0; j < v.size(); j++ )
	{
		s << boost::format("%8.5f") % v(0) << boost::format("%8.5f") % v(1) << boost::format("%8.5f") % v(2) << "\n";
	}
	return s.str();
}
/*!
* \brief DumpEPose creates a string of the eigen pose representation.
* \param p is the 7 element eigen vectorXd.
*/
inline std::string DumpEPose( const EigenPose & p)
{
	std::stringstream s;
	s << "Translation = " << boost::format("%11.4f") % ( 1000.0 * p(0) ) << ":" << boost::format("%11.4f") % ( 1000.0 * p(1) ) << ":" << boost::format("%11.4f") % ( 1000.0 * p(2) ) << std::endl;
	double roll, pitch, yaw;
	Eigen::Quaterniond q = EPose2Quat(p);
	EQuatToRpy(q, roll, pitch, yaw);
	s << "Rotation    = " << boost::format("%11.4f") % Rad2Deg(roll) << ":" << boost::format("%11.4f") % Rad2Deg(pitch) << ":" << boost::format("%11.4f") % Rad2Deg(yaw) << std::endl;
	return s.str( );
}
/*!
* \brief DumpEJoints creates a string of the eigen joint representation in degrees.
* \param joints is the n element eigen vectorXd of joint values.
*/
inline std::string DumpEJoints (const EJointVector & joints)
{
	std::stringstream s;
	s << "Joints = ";

	for ( int i = 0; i < joints.size( ); i++ )
	{
		s << boost::format("%11.4f") % Rad2Deg(joints(i)) << ":";
	}
	s << std::endl;
	return s.str();
}
/*!
* \brief ToRadians converts an eigne vector of  joints in degrees to radian values.
* \param joints is the n element eigen vectorXd of joint values in degrees.
* \return  n element eigen vectorXd of joint values in radians.
*/ 
inline EJointVector ToRadians(EJointVector joints)
{
	EJointVector j(joints.size());
	for(int i =0; i< joints.size(); i++)
		j(i)=Deg2Rad(joints(i));
	return j;
}
/*!
* \brief ConvertJoints converts std vector of double into an eigen vector .
* \param v is vector of doubles
* \return the equivalent size_t n element eigen vectorXd .
*/ 
inline Eigen::VectorXd ConvertJoints(std::vector<double> v )
{
	Eigen::VectorXd p(v.size());
	for(size_t i =0; i< v.size(); i++)
		p(i)=v[i];
	return p;
}
/*!
* \brief ConvertJoints converts eigen vector into a std vector of double into an.
* \param the  n element eigen vectorXd .
* \return  v is vector of doubles
*/ 
inline std::vector<double> ConvertJoints(Eigen::VectorXd ev)
{
	std::vector<double> v; 
	for(int i =0; i< ev.size(); i++)
		v.push_back(ev(i));
	return v;
}
/*!
* \brief ConvertPose converts urdf pose into an eigen vectorXd pose representation.
* \param p is the urdf pose.
* \return   eigen vectorXd representing pose with translation and quaterion elements
*/ 
inline Eigen::VectorXd ConvertPose(urdf::Pose p)
{
	Eigen::VectorXd ep(7);
	ep << p.position.x, p.position.y, p.position.z, 
		p.rotation.x, p.rotation.y, p.rotation.z, p.rotation.w;
	return ep;
}
/*!
* \brief ConvertPosition converts urdf vector3D position into an eigen vectorXd position representation.
* \param p is the urdf position.
* \return   eigen vectorXd representing position with translation elements
*/ 
inline Eigen::VectorXd ConvertPosition(urdf::Vector3 p)
{
	Eigen::VectorXd ep(3);
	ep << p.x , p.y, p.z; 
	return ep;
}
/*!
* \brief Ros2Eigen converts 3x4 matrix (boost array) into an eigen matrix.
* \param m is the boost array equivalent to 3x4 matrix.
* \return   eigen 4x4 Matrix containing rotation and translation 
*/
inline Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>  Ros2Eigen(RosMatrix m)
{
	Eigen::Matrix<double, 4, 4, Eigen::RowMajor>  m4;
	m4 = Eigen::Matrix4d::Identity();
	m4   << m[4 * 0 + 0] , m[4 * 0 + 1] , m[4 * 0 + 2]  , m[4 * 0 + 3],
		m[4 * 1 + 0] , m[4 * 1+ 1] , m[4 * 1 + 2]  , m[4 * 1 + 3],
		m[4 * 2 + 0] , m[4 * 2 + 1] , m[4 * 2 + 2]  , m[4 * 2 + 3],
		0,0,0  , 1.0;

	return m4;
}
//Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>  Ros2Eigen(RosMatrix m)
//{
//	Eigen::Matrix<double, 4, 4, Eigen::RowMajor>  m4;
//	m4 = Matrix4d::Identity();const  Eigen::Affine3d pose
//	m4   << m[4 * 0 + 0] , m[4 * 1 + 0] , m[4 * 2 + 0]  , 0,
//	 m[4 * 0 + 1] , m[4 * 1 + 1] , m[4 * 2 + 1]  , 0,
//	 m[4 * 0 + 2] , m[4 * 1 + 2] , m[4 * 2 + 2]  , 0,
//	 m[4 * 0 + 3] , m[4 * 1 + 3] , m[4 * 2 + 3]  , 1.0;
//	return m4;
//}
inline std::ostream & operator << (std::ostream & os, const std::vector<Eigen::Vector3d> & v)
{
	std::stringstream s;

	for ( size_t j = 0; j < v.size(); j++ )
	{
		s << boost::format("%8.5f") % v[j](0) << boost::format("%8.5f") % v[j](1) << boost::format("%8.5f") % v[j](2) << "\n";
	}
	os << s.str( );
	return os;
}
/*!
* \brief EMatrix2Pose converts Eigen 4x4 matrix into an eigen pose.
* \param m is eigen 4x4 Matrix containing rotation and translation.
* \return   eigen vectorXd containing rotation and translation 
*/
inline EigenPose EMatrix2Pose(MatrixEXd& m)
{
	EigenPose p(7);
	Eigen::Vector3d trans ( m.block<3,1>(0, 3));
	Eigen::Quaterniond q(m.block<3,3>(0, 0));
	p << trans(0), trans(1), trans(2),q.x(),q.y(),q.z(),q.w();
	return p;
}
/*!
* \brief EMatrix2Quaterion converts Eigen 4x4 matrix into an eigen quaterion.
* \param m is eigen 4x4 Matrix containing rotation and translation.
* \return   eigen Quaterniond containing rotation 
*/
inline Eigen::Quaterniond EMatrix2Quaterion(MatrixEXd& m)
{
	Eigen::Quaterniond q(m.block<3,3>(0, 0));
	return q;
}
/*!
* \brief urdfPose2Affine3d converts urdf pose into an  Eigen affine 4x4 matrix  o represent the pose
* \param pose is the urdf pose with position and rotation.
* \return   eigen Affine3d pose 
*/
inline Eigen::Affine3d urdfPose2Affine3d(const urdf::Pose &pose)
{
	Eigen::Quaterniond q(pose.rotation.w, pose.rotation.x, pose.rotation.y, pose.rotation.z);
	Eigen::Affine3d af(Eigen::Translation3d(pose.position.x, pose.position.y, pose.position.z)*q.toRotationMatrix());
	return af;
}
/*!
* \brief affine3d2UrdfPose converts an  Eigen affine 4x4 matrix  o represent the pose into a urdf pose 
* vparam pose   eigen Affine3d pose 
* \return   urdf pose with position and rotation.
*/
inline urdf::Pose affine3d2UrdfPose(const  Eigen::Affine3d &pose)
{
    urdf::Pose p ;
    p.position.x = pose.translation().x();
    p.position.y = pose.translation().y();
    p.position.z = pose.translation().z();
    MatrixEXd m = pose.rotation();
    Eigen::Quaterniond q = EMatrix2Quaterion(m);
    p.rotation.x = q.x();
    p.rotation.y = q.y();
    p.rotation.z = q.z();
    p.rotation.w = q.w();
   return p;
}
/*!
* \brief Create4x4IdentityMatrix creates an  Eigen MatrixEXd identity matrix 
* \return   Eigen MatrixEXd identity matrix.
*/
inline MatrixEXd Create4x4IdentityMatrix()
{
	MatrixEXd m1(4,4);
	m1.setIdentity();
	return m1;
}
/*!
* \brief CreateMatrix creates an  Eigen MatrixEXd  matrix with translation defined
* \param translation Eigen position vector3d 
* \return   Eigen MatrixEXd  matrix.
*/
inline MatrixEXd CreateMatrix(const EigenPosition translation)
{
	MatrixEXd m1(4,4);
	m1.setIdentity();
	m1.block<3,1>(0,3)<< translation(0), translation(1), translation(2);
	return m1;
}
/*!
* \brief CreateMatrix creates an  Eigen MatrixEXd  4x4 matrix from an axis angle representation
* \param angle in radians 
* \param unit vector of direction given in Eigen position vector3d 
* \return   Eigen MatrixEXd  matrix.
*/
inline MatrixEXd CreateMatrix(const double angle, Eigen::Vector3d axis) 
{
	Eigen::Matrix3d t33;
	MatrixEXd m1(4,4);
	m1.setIdentity();
	t33 = Eigen::AngleAxisd(angle, axis);
	m1.block<3,3>(0,0) = t33;
	return m1;
}
/*!
* \brief PseudoInvertJacobian attempts does a pseudo invert of a Eigen MatrixEXd  matrix if not a square matrix.
* \param a Eigen MatrixEXd  matrix
* \return  pseudo inverted Eigen MatrixEXd  matrix.
*/
inline MatrixEXd	PseudoInvertJacobian(const MatrixEXd &a) 
{
	MatrixEXd aT= a.transpose();
	MatrixEXd aaT = a*aT;
	return aT*(aaT.inverse());
}
/*!
* \brief EQuat2Matrix converts an Eigen quaterion into an Eigen 4x4 matrix.
* \param q Eigen quaterion
* \return  Eigen MatrixEXd 4x4 matrix.
*/
inline MatrixEXd EQuat2Matrix(Eigen::Quaterniond &q)
{
	MatrixEXd m(4,4);
	m.setIdentity();
	m.block<3,3>(0, 0) = q.toRotationMatrix ();
	return m;
}
/*!
* \brief EPose2Matrix converts an Eigen pose into an Eigen 4x4 matrix.
* \param p EigenXd vector representing pose, as translation and quaterion elements
* \return  Eigen MatrixEXd 4x4 matrix.
*/
inline  MatrixEXd  EPose2Matrix(EigenPose& p)
{
	MatrixEXd m(4,4);
	m.setIdentity();
	Eigen::Vector3d trans ( p(0),  p(1), p(2));
	m.block<3,1>(0, 3)=trans;
	Eigen::Quaterniond q;
	q.x() = p(3); q.y() =  p(4); q.z() = p(5); q.w() = p(6);
	Eigen::Matrix3d m3 =	q.toRotationMatrix ();
	m.block<3,3>(0, 0)=m3;
	return m;
}
/*!
* \brief EPoseAddQuat stores an Eigen quaterion into a Eigen pose.
* \param p EigenXd vector representing pose, as translation and quaterion elements
* \param q Eigen quaterion
* \return  Eigen pose which is a 7D VectorXd.
*/
inline  EigenPose  EPoseAddQuat(EigenPose p, Eigen::Quaterniond &q)
{
	p(3)=q.x(); p(4)=q.y();p(5)=q.z();p(6)=q.w();
	return p;
}
/*!
* \brief EPose2Quat converts rotation element of an Eigen pose into an Eigen quaterion.
* \param pose is EigenXd vectorcontaining translation and quaterion elements
* \return Eigen quaterion .
*/
inline  Eigen::Quaterniond  EPose2Quat(EigenPose p)
{
	Eigen::Quaterniond q;
	q.x() = p(3); q.y() =  p(4); q.z() = p(5); q.w() = p(6);
	return q;
}
/*!
* \brief ECreatePose creates an Eigen pose from a Eigen position vector and an Eigen quaterion.
* \param pos is Eigendd vector containing translation 
* \param q Eigen quaterion describing rotation
* \return  Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
*/
inline EigenPose  ECreatePose(EigenPosition pos, Eigen::Quaterniond &q)
{
	EigenPose pose(7);
	pose(0)= pos(0);  pose(1)=pos(1); pose(2)=pos(2);
	return EPoseAddQuat(pose, q);
}
/*!
* \brief EPoseMult multiplies an Eigen pose by an Eigen position vector.
* \param p ispose which is a 7D VectorXd  as translation and quaterion elements. 
* \param v Eigen vector3D  describing tranlsation
* \return  Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
*/
inline EigenPosition EPoseMult (const EigenPose & p, const EigenPosition & v)
{
	double        ww = 2 * p(4) * p(3);
	double        wx = 2 * p(3) * p(4);
	double        wy = 2 * p(3) * p(5);
	double        wz = 2 * p(4) * p(6);
	double        xx = 2 * p(4) * p(4);
	double        xy = 2 * p(4) * p(5);
	double        xz = 2 * p(4) * p(6);
	double        yy = 2 * p(5) * p(5);
	double        yz = 2 * p(5) * p(6);
	EigenPosition vnew;

	vnew(0) = ( 1 - xx - yy ) * v(0) + ( wx - yz ) * v(1) + ( wy + xz ) * v(2) + p(0);
	vnew(1) = ( wx + yz ) * v(0) + ( 1 - ww - yy ) * v(1) + ( xy - wz ) * v(2) + p(1);
	vnew(2) = ( wy - xz ) * v(0) + ( xy + wz ) * v(1) + ( 1 - ww - xx ) * v(2) + p(2);
	return vnew;
}
/*!
* \brief ECreatePosition extracts and returns the translation element from an Eigen pose.
* \param pose Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
* \return  Eigen vector3D  describing tranlsation
*/
inline EigenPosition  ECreatePosition(EigenPose pose)
{
	EigenPosition p;
	p << pose(0), pose(1), pose(2);
	return p;
}
/*!
* \brief EPoseMult multiplies two Eigen poses.
* \param p0 Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
* \param p1 Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
* \return  multiply result as Eigen pose which is a 7D VectorXd  as translation and quaterion elements
*/
inline EigenPose EPoseMult (EigenPose & p0, EigenPose & p1)
{
	MatrixEXd m0 = EPose2Matrix(p0);
	MatrixEXd m1 = EPose2Matrix(p1);
	MatrixEXd m2 = m0 * m1;
	return EMatrix2Pose(m2);
#if 0 
	EigenPosition pos = EPoseMult(p0, ECreatePosition(p1));
	Eigen::Quaterniond q0=EPose2Quat(p0);
	Eigen::Quaterniond q1=EPose2Quat(p1);
	return ECreatePose(pos, q0*q1);
#endif
}
/*!
* \brief EQuatIsNorm determines if Eigen quaterion is normalized.
* \param q1 Eigen quaterion.
* \return  true if normalized
*/
inline bool EQuatIsNorm(Eigen::Quaterniond & q1)
{
	if(CLOSE( ( q1.w() * q1.w() )
		+ ( q1.x() * q1.x() )
		+ ( q1.y() * q1.y() )
		+ ( q1.z() * q1.z() ), 1.0))
		return true;
	return false;
}
/*!
* \brief EQuatCartMult multiplies an Eigen quaterion by a Eigen position.
* \param q1 Eigen quaterion.
* \param q1 Eigen position vector3d.
* \return   Eigen position vector3d
*/
inline EigenPosition EQuatCartMult (Eigen::Quaterniond & q1, const EigenPosition v2)
{
	EigenPosition c;
	EigenPosition vout(3);

	if ( !EQuatIsNorm(q1) )
	{
		throw "GO_RESULT_NORM_ERROR";
	}
	c.resize(3);
	c(0) = q1.y() * v2(2) - q1.z() * v2(1);
	c(1) = q1.z() * v2(0) - q1.x() * v2(2);
	c(2) = q1.x() * v2(1) - q1.y() * v2(0);

	vout.resize(3);
	vout(0) = v2(0) + 2 * ( q1.w() * c(0) + q1.y() * c(2) - q1.z() * c(1) );
	vout(1) = v2(1) + 2 * ( q1.w() * c(1) + q1.z() * c(0) - q1.x() * c(2) );
	vout(2) = v2(2) + 2 * ( q1.w() * c(2) + q1.x() * c(1) - q1.y() * c(0) );

	return vout;
}
/*!
* \brief EPoseInv computes the inverse of an Eigen Pose
* \param p1 Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
* \return  inverted  Eigen pose which is a 7D VectorXd  as translation and quaterion elements.
*/
inline EigenPose EPoseInv (const EigenPose & p1)
{
	Eigen::Quaterniond  q = EPose2Quat(p1);
	q=q.inverse();

	EigenPosition pos = EQuatCartMult(q, ECreatePosition(p1));

	pos(0) = -pos(0);
	pos(1) = -pos(1);
	pos(2) = -pos(2);
	return ECreatePose(pos, q);
}
/*!
* \brief CreateQuaterian from roll, pitch and yaw angles given in radians
* \param roll pitch yaw are angles.
* \return rotation as defined by Eigen quaterion.
*/
inline Eigen::Quaterniond CreateQuaterian(double roll, double pitch, double yaw)
{
	MatrixEXd mRoll, mPitch, mYaw;
	mRoll = CreateMatrix(roll, Eigen::Vector3d(1,0,0)); 
	mPitch = CreateMatrix(pitch, Eigen::Vector3d(0,1,0)); 
	mYaw = CreateMatrix(yaw, Eigen::Vector3d(0,0,1)); 
	MatrixEXd t =  mYaw *  mPitch *  mRoll  ;
	return EMatrix2Quaterion(t);
}
// quaterion to rpy
// https://github.com/mavlink/mavros/issues/444
/*!
* \brief EQuatFromRpy return Eigen quaterion from roll, pitch and yaw angles given in radians
* \param roll pitch yaw are angles.
* \return rotation as defined by Eigen quaterion.
*/
inline Eigen::Quaterniond EQuatFromRpy (double & roll, double & pitch, double & yaw) // Assuming the angles are in radians.
{
	Eigen::Quaterniond q;
	double         c1   = cos(roll / 2);
	double         s1   = sin(roll / 2);
	double         c2   = cos(pitch / 2);
	double         s2   = sin(pitch / 2);
	double         c3   = cos(yaw / 2);
	double         s3   = sin(yaw / 2);
	double         c1c2 = c1 * c2;
	double         s1s2 = s1 * s2;

	q.w() = c1c2 * c3 - s1s2 * s3;
	q.x() = c1c2 * s3 + s1s2 * c3;
	q.y() = s1 * c2 * c3 + c1 * s2 * s3;
	q.z() = c1 * s2 * c3 - s1 * c2 * s3;
	return q;
}
/*!
* \brief EQuatToRpy return  roll, pitch and yaw angles given in radians from Eigen quaterion
* \param roll pitch yaw references will be filled with equivalent angles in radians.
* \param rotation as defined by Eigen quaterion.
*/
inline void EQuatToRpy (const Eigen::Quaterniond & q1, double & roll, double & pitch, double & yaw)
{
	double sqw;
	double sqx;
	double sqy;
	double sqz;

	sqx = q1.x() * q1.x();
	sqy = q1.y() * q1.y();
	sqz = q1.z() * q1.z();
	sqw = q1.w() * q1.w();

	// Cases derived from https://orbitalstation.wordpress.com/tag/quaternion/
	double sarg = -2 * ( q1.x() * q1.z() - q1.w() * q1.y() );

	if ( sarg <= -0.99999 )
	{
		pitch = -0.5 * M_PI;
		roll  = 0;
		yaw   = 2 * atan2(q1.x(), -q1.y());
	}
	else if ( sarg >= 0.99999 )
	{
		pitch = 0.5 * M_PI;
		roll  = 0;
		yaw   = 2 * atan2(-q1.x(), q1.y());
	}
	else
	{
		pitch = asin(sarg);
		roll  = atan2(2 * ( q1.y() * q1.z() + q1.w() * q1.x() ), sqw - sqx - sqy + sqz);
		yaw   = atan2(2 * ( q1.x() * q1.y() + q1.w() * q1.z() ), sqw + sqx - sqy - sqz);
	}
}
/*!
* \brief EErrPosesAxisAngle computes the error vector from two Eigen poses
* \param current pose which is a 7D VectorXd  as translation and quaterion elements
* \param goal pose which is a 7D VectorXd  as translation and quaterion elements
* \return Eigen vector of difference between vectors
*/
inline Eigen::VectorXd EErrPosesAxisAngle(EigenPose current, EigenPose goal)
{
	Eigen::VectorXd err(6);
	MatrixEXd mxGoal=EPose2Matrix(goal);
	MatrixEXd mxCurrent=EPose2Matrix(current);
	MatrixEXd t =  mxGoal *mxCurrent.inverse();  // this kinda works
	//MatrixEXd t =  mxCurrent.inverse() * mxGoal;  // doesnt work..
	Eigen::AngleAxisd erraarot ( t.block<3,3>(0, 0));
	Eigen::Vector3d errtrans ( t.block<3,1>(0, 3));
	Eigen::Vector3d errrot = erraarot.axis()*erraarot.angle();
	err << errtrans(0) ,  errtrans(1), errtrans(2) ,  errrot(0) ,  errrot(1), errrot(2) ;
	return err;
}


