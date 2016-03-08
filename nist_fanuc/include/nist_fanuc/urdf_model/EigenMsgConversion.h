/*
* Copyright (c) 2009, Willow Garage, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the Willow Garage, Inc. nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

/*
* Author: Stuart Glaser
*/

#ifndef EIGEN_MSG_CONVERSIONS_H
#define EIGEN_MSG_CONVERSIONS_H

#include <std_msgs/Float64MultiArray.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Wrench.h>

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace tf {

	void pointMsgToEigen(const geometry_msgs::Point &m, Eigen::Vector3d &e);

	void pointEigenToMsg(const Eigen::Vector3d &e, geometry_msgs::Point &m);

	void poseMsgToEigen(const geometry_msgs::Pose &m, Eigen::Affine3d &e);

	void poseMsgToEigen(const geometry_msgs::Pose &m, Eigen::Isometry3d &e);

	void poseEigenToMsg(const Eigen::Affine3d &e, geometry_msgs::Pose &m);

	void poseEigenToMsg(const Eigen::Isometry3d &e, geometry_msgs::Pose &m);

	void quaternionMsgToEigen(const geometry_msgs::Quaternion &m, Eigen::Quaterniond &e);

	void quaternionEigenToMsg(const Eigen::Quaterniond &e, geometry_msgs::Quaternion &m);

	void transformMsgToEigen(const geometry_msgs::Transform &m, Eigen::Affine3d &e);

	void transformMsgToEigen(const geometry_msgs::Transform &m, Eigen::Isometry3d &e);

	void transformEigenToMsg(const Eigen::Affine3d &e, geometry_msgs::Transform &m);

	void transformEigenToMsg(const Eigen::Isometry3d &e, geometry_msgs::Transform &m);

	void twistMsgToEigen(const geometry_msgs::Twist &m, Eigen::Matrix<double,6,1> &e);

	void twistEigenToMsg(const Eigen::Matrix<double,6,1> &e, geometry_msgs::Twist &m);

	void vectorMsgToEigen(const geometry_msgs::Vector3 &m, Eigen::Vector3d &e);

	void vectorEigenToMsg(const Eigen::Vector3d &e, geometry_msgs::Vector3 &m);

	void wrenchMsgToEigen(const geometry_msgs::Wrench &m, Eigen::Matrix<double,6,1> &e);
	void wrenchEigenToMsg(const Eigen::Matrix<double,6,1> &e, geometry_msgs::Wrench &m);

	template <class Derived>
	void matrixEigenToMsg(const Eigen::MatrixBase<Derived> &e, std_msgs::Float64MultiArray &m)
	{
		if (m.layout.dim.size() != 2)
			m.layout.dim.resize(2);
		m.layout.dim[0].stride = e.rows() * e.cols();
		m.layout.dim[0].size = e.rows();
		m.layout.dim[1].stride = e.cols();
		m.layout.dim[1].size = e.cols();
		if ((int)m.data.size() != e.size())
			m.data.resize(e.size());
		int ii = 0;
		for (int i = 0; i < e.rows(); ++i)
			for (int j = 0; j < e.cols(); ++j)
				m.data[ii++] = e.coeff(i, j);
	}

} // namespace

namespace tf 
{

	void pointMsgToEigen(const geometry_msgs::Point &m, Eigen::Vector3d &e)
	{
		e(0) = m.x; 
		e(1) = m.y; 
		e(2) = m.z; 
	}

	void pointEigenToMsg(const Eigen::Vector3d &e, geometry_msgs::Point &m)
	{
		m.x = e(0);
		m.y = e(1);
		m.z = e(2);
	}

	namespace {
		template<typename T>
		inline void poseMsgToEigenImpl(const geometry_msgs::Pose &m, T &e)
		{
			e = Eigen::Translation3d(m.position.x,
				m.position.y,
				m.position.z) *
				Eigen::Quaterniond(m.orientation.w,
				m.orientation.x,
				m.orientation.y,
				m.orientation.z);
		}

		template<typename T>
		inline void poseEigenToMsgImpl(const T &e, geometry_msgs::Pose &m)
		{
			m.position.x = e.translation()[0];
			m.position.y = e.translation()[1];
			m.position.z = e.translation()[2];
			Eigen::Quaterniond q = (Eigen::Quaterniond)e.linear();
			m.orientation.x = q.x();
			m.orientation.y = q.y();
			m.orientation.z = q.z();
			m.orientation.w = q.w();
			if (m.orientation.w < 0) {
				m.orientation.x *= -1;
				m.orientation.y *= -1;
				m.orientation.z *= -1;
				m.orientation.w *= -1;
			}
		}

		template<typename T>
		inline void transformMsgToEigenImpl(const geometry_msgs::Transform &m, T &e)
		{
			e = Eigen::Translation3d(m.translation.x,
				m.translation.y,
				m.translation.z) *
				Eigen::Quaterniond(m.rotation.w,
				m.rotation.x,
				m.rotation.y,
				m.rotation.z);
		}

		template<typename T>
		inline void transformEigenToMsgImpl(const T &e, geometry_msgs::Transform &m)
		{
			m.translation.x = e.translation()[0];
			m.translation.y = e.translation()[1];
			m.translation.z = e.translation()[2];
			Eigen::Quaterniond q = (Eigen::Quaterniond)e.linear();
			m.rotation.x = q.x();
			m.rotation.y = q.y();
			m.rotation.z = q.z();
			m.rotation.w = q.w();
			if (m.rotation.w < 0) {
				m.rotation.x *= -1;
				m.rotation.y *= -1;
				m.rotation.z *= -1;
				m.rotation.w *= -1;
			}
		}
	}

	inline void poseMsgToEigen(const geometry_msgs::Pose &m, Eigen::Affine3d &e)
	{
		poseMsgToEigenImpl(m, e);
	}

	inline void poseMsgToEigen(const geometry_msgs::Pose &m, Eigen::Isometry3d &e)
	{
		poseMsgToEigenImpl(m, e);
	}

	inline void poseEigenToMsg(const Eigen::Affine3d &e, geometry_msgs::Pose &m)
	{
		poseEigenToMsgImpl(e, m);
	}

	inline void poseEigenToMsg(const Eigen::Isometry3d &e, geometry_msgs::Pose &m)
	{
		poseEigenToMsgImpl(e, m);
	}

	inline void quaternionMsgToEigen(const geometry_msgs::Quaternion &m, Eigen::Quaterniond &e)
	{
		e = Eigen::Quaterniond(m.w, m.x, m.y, m.z);
	}

	inline void quaternionEigenToMsg(const Eigen::Quaterniond &e, geometry_msgs::Quaternion &m)
	{
		m.x = e.x();
		m.y = e.y();
		m.z = e.z();
		m.w = e.w();
	}

	void transformMsgToEigen(const geometry_msgs::Transform &m, Eigen::Affine3d &e)
	{
		transformMsgToEigenImpl(m, e);
	}

	inline void transformMsgToEigen(const geometry_msgs::Transform &m, Eigen::Isometry3d &e)
	{
		transformMsgToEigenImpl(m, e);
	}

	inline void transformEigenToMsg(const Eigen::Affine3d &e, geometry_msgs::Transform &m)
	{
		transformEigenToMsgImpl(e, m);
	}

	inline void transformEigenToMsg(const Eigen::Isometry3d &e, geometry_msgs::Transform &m)
	{
		transformEigenToMsgImpl(e, m);
	}

	inline void vectorMsgToEigen(const geometry_msgs::Vector3 &m, Eigen::Vector3d &e)
	{
		e(0) = m.x; 
		e(1) = m.y; 
		e(2) = m.z; 
	}

	inline void vectorEigenToMsg(const Eigen::Vector3d &e, geometry_msgs::Vector3 &m)
	{
		m.x = e(0);
		m.y = e(1);
		m.z = e(2);
	}

	inline void twistMsgToEigen(const geometry_msgs::Twist &m, Eigen::Matrix<double,6,1> &e)
	{
		e[0] = m.linear.x;
		e[1] = m.linear.y;
		e[2] = m.linear.z;
		e[3] = m.angular.x;
		e[4] = m.angular.y;
		e[5] = m.angular.z;
	}

	inline void twistEigenToMsg(const Eigen::Matrix<double,6,1> &e, geometry_msgs::Twist &m)
	{
		m.linear.x = e[0];
		m.linear.y = e[1];
		m.linear.z = e[2];
		m.angular.x = e[3];
		m.angular.y = e[4];
		m.angular.z = e[5];
	}

	inline void wrenchMsgToEigen(const geometry_msgs::Wrench &m, Eigen::Matrix<double,6,1> &e)
	{
		e[0] = m.force.x;
		e[1] = m.force.y;
		e[2] = m.force.z;
		e[3] = m.torque.x;
		e[4] = m.torque.y;
		e[5] = m.torque.z;
	}

	inline void wrenchEigenToMsg(const Eigen::Matrix<double,6,1> &e, geometry_msgs::Wrench &m)
	{
		m.force.x = e[0];
		m.force.y = e[1];
		m.force.z = e[2];
		m.torque.x = e[3];
		m.torque.y = e[4];
		m.torque.z = e[5];
	}

} // namespace

#endif