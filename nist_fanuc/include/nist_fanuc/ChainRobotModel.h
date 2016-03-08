// ChainRobotModel.h

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
#include <string>
#include <vector>
//#include <urdf/model.h>
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>
#include <Eigen/Dense>

namespace RCS
{
	struct RdfJoint
	{
		std::string name;
		int index;
        std::string sLink;
		//urdf::LinkConstSharedPtr pLink;
		//urdf::JointSharedPtr pJoint;
		enum JointType
		{
			UNKNOWN = 0, REVOLUTE, CONTINUOUS, PRISMATIC, FLOATING, PLANAR, FIXED
		} type;
		Eigen::Vector3d axis;
		Eigen::Vector3d xyzorigin;
		Eigen::Vector3d rpyorigin;
		double lowerlimit;
		double upperlimit;
		double effortlimit;
		double velocitylimit;
		bool bounded;
		std::string DumpRdfJoint();
	};
	class ChainRobotModel
	{
	public:
		ChainRobotModel(){}
		size_t              GetJointNum() { return jointspec.size(); }
		size_t              GetMovingJoints() { return jointspec.size(); }
		RdfJoint&           GetJoint(int num) { assert(num < jointspec.size()); return jointspec[num]; }
		void                RdfFromXmlFile(std::string xml_string);

		//////////////////////////////////////////////////
//		void				GetJointInfoFromUrdf(boost::shared_ptr<const Link> link);
//     	void                GetAllJointInfo(boost::shared_ptr<const Link> link);
//		void                GetJointInfo(boost::shared_ptr<const Link> link, std::vector<boost::shared_ptr<const Joint> > &  joints);
		std::string DumpRdfJoints(std::vector< RdfJoint>  &jointspec);
		//urdf::Model _model;
		std::vector<RdfJoint> prejointspec;
		std::vector<RdfJoint> postjointspec;
		std::vector<RdfJoint> jointspec;
#if 0
		std::vector<EigenPose> prejointpose;
		std::vector<EigenPose> postjointpose;
		std::vector<EigenPose> prejointposeinv;
		std::vector<EigenPose> postjointposeinv;
#endif
	};

};
