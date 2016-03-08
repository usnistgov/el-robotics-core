// ChainRobotModel.cpp

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

#include "ChainRobotModel.h"
#define STANDALONEURDF
#include "urdf_model/RobotModel.h"
#include "urdf_model/urdf_parse_model.cpp"
#include "Globals.h"
#include "urdf_model/eigenmath.h"

namespace RCS
{
std::string RdfJoint::DumpRdfJoint()
{
	static char * jointtypes[] = {     "UNKNOWN", "REVOLUTE", "CONTINUOUS", "PRISMATIC", "FLOATING", "PLANAR", "FIXED"};
	const RdfJoint & j(*this);
	std::stringstream s;
	s << " Name = " << j.name.c_str() << std::endl;
	s << " Type = " << jointtypes[j.type] << std::endl;
	s << " Axis = " << DumpEPosition(j.axis).c_str() << std::endl;
	s << " XYZ Origin = " << DumpEPosition(j.xyzorigin).c_str() << std::endl;
	s << " RPY Origin = " << DumpEPosition(j.rpyorigin).c_str() << std::endl;
	if(j.bounded)
	{
		s << " Lowerlimit = " << j.lowerlimit << std::endl;
		s << " Upperlimit = " << j.upperlimit << std::endl;
	}
	return s.str();
}
std::string ChainRobotModel::DumpRdfJoints(std::vector< RdfJoint>  &jointspec)
{
	std::stringstream s;
	for(size_t i=0; i< jointspec.size(); i++)
		s<< jointspec[i].DumpRdfJoint().c_str();
	return s.str();
}


static void SaveJointInfoFromUrdf(urdf::JointSharedPtr jointlink, urdf::LinkConstSharedPtr rootlink, std::vector<RdfJoint> &injointspec)
{
	RdfJoint jointspec;
	//jointspec.pJoint=jointlink;
	jointspec.name=jointlink->name;
	jointspec.index=injointspec.size();
	jointspec.type=(RdfJoint::JointType) jointlink->type;
	jointspec.axis=ConvertPosition(jointlink->axis);
	jointspec.bounded=false;
	if(jointlink->limits!=NULL)
	{
		jointspec.lowerlimit=jointlink->limits->lower;
		jointspec.upperlimit=jointlink->limits->upper;
		jointspec.bounded=true;
		if(jointspec.type == RdfJoint::CONTINUOUS) 
			jointspec.bounded=false;
	}
	jointspec.xyzorigin = ConvertPosition( jointlink->parent_to_joint_origin_transform.position);
	jointlink->parent_to_joint_origin_transform.rotation.getRPY (jointspec.rpyorigin(0),jointspec.rpyorigin(1),jointspec.rpyorigin(2)) ;
	injointspec.push_back(jointspec);

}

// assume single chain - not tree of link/joint definitions
static void GetAllJointInfo(urdf::LinkConstSharedPtr link, ChainRobotModel * model)
{
    model->jointspec.clear();	 model->prejointspec.clear();   model->postjointspec.clear();
	//prejointpose.clear();postjointpose.clear();prejointposeinv.clear();postjointposeinv.clear();
	// Get fixed links - use recursive descent assuming chain of link/joints
	std::vector<urdf::LinkSharedPtr>::const_iterator child = link->child_links.begin( );
	std::vector<urdf::LinkSharedPtr>::const_iterator endchild = link->child_links.end( );
	for ( ; child != endchild;  )
	{
		 urdf::JointSharedPtr jchild = (*child)->parent_joint;
		// look for fixed "joints" - premultiplied to goal pose
		if(jchild==NULL)
		{
			child++;
			continue;
		}
		if(jchild->type == urdf::Joint::FIXED )
		{
			//SaveJointInfoFromUrdf(jchild,  *child, prejointspec);
			child++;
			continue;
		}
		else
		{
			break;	
		}
	}
	for ( ; child != endchild;  )
	{
		 urdf::JointSharedPtr jchild = (*child)->parent_joint;
		// look for fixed "joints" - premultiplied to goal pose
		assert(jchild!=NULL);
		assert (jchild->type != urdf::Joint::UNKNOWN);
		if(jchild->type != urdf::Joint::FIXED )
		{
			SaveJointInfoFromUrdf(jchild,  *child, model->jointspec);
			endchild = (*child)->child_links.end( );
			child = (*child)->child_links.begin( );
			continue;
		}
		else
		{
			break;	
		}
	}
	for ( ;child != endchild; )
	{
		 urdf::JointSharedPtr jchild = (*child)->parent_joint;

		 // look for fixed "joints" - postmultiplied to goal pose
		assert(jchild!=NULL);
		assert (jchild->type != urdf::Joint::UNKNOWN);
		if(jchild->type == urdf::Joint::FIXED )
		{
			//SaveJointInfoFromUrdf(jchild,  *child, postjointspec);
			child++;
		}
		else
		{
			// there may be more, but we're done
			break;	
		}
	}
    // Skip pre and post joints and pose multiplies for now
#if 0
	// premultiply in reverse order - so add back to front
	for(int  i=model->prejointspec.size()-1 ; i>=0;  i--)
	{
		prejointpose.push_back( ECreatePose(prejointspec[i].xyzorigin, 
			//CreateQuaterian(prejointspec[i].rpyorigin(0), prejointspec[i].rpyorigin(1), prejointspec[i].rpyorigin(2))));
			EQuatFromRpy(prejointspec[i].rpyorigin(0), prejointspec[i].rpyorigin(1), prejointspec[i].rpyorigin(2) )));
	}
	for(size_t i=0; i< model->postjointspec.size() ; i++)
	{
		postjointpose.push_back( ECreatePose(postjointspec[i].xyzorigin, 
			CreateQuaterian(postjointspec[i].rpyorigin(0), postjointspec[i].rpyorigin(1), postjointspec[i].rpyorigin(2))));
			//EQuatFromRpy(postjointspec[i].rpyorigin(0), postjointspec[i].rpyorigin(1), postjointspec[i].rpyorigin(2) )));
	}
	for(size_t i=0; i< prejointpose.size() ; i++)
		prejointposeinv.push_back(EPoseInv(prejointpose[i]));
	for(size_t i=0; i< postjointpose.size() ; i++)
		postjointposeinv.push_back(EPoseInv(postjointpose[i]));
#endif
}
#if 0
static void GetJointInfo(urdf::LinkConstSharedPtr link,std::vector<urdf::JointSharedPtr> &  joints)
{
	static char * jointtypes[] = {     "UNKNOWN", "REVOLUTE", "CONTINUOUS", "PRISMATIC", "FLOATING", "PLANAR", "FIXED"};
	int count=0;
	for ( std::vector<urdf::LinkSharedPtr>::const_iterator child = link->child_links.begin( ); child != link->child_links.end( ); child++ )
	{
		if ( *child )
		{
			std::cout << "child(" << ( count++ ) + 1 << "):  " << ( *child )->name.c_str() << std::endl;
			for ( std::vector<urdf::JointSharedPtr>::const_iterator jchild = link->child_joints.begin( ); jchild != link->child_joints.end( ); jchild++ )
			{
				std::cout << (*jchild)->name.c_str() << " Type : " << jointtypes[(*jchild)->type] << std::endl; //  " Child:" << (*jchild)->child_link_name.c_str() << " Parent:" << (*jchild)->parent_link_name.c_str() << std::endl; 
				if((*jchild)->type != urdf::Joint::UNKNOWN && (*jchild)->type != urdf::Joint::FIXED )
				{
					std::string name = (*jchild)->name;
					if( std::find_if(joints.begin(), joints.end(),
						[name] (urdf::JointSharedPtr item) { 
							return item->name == name;
					}) == joints.end()) 
{
						joints.push_back(*jchild);
}
				}
			}
			// first grandchild
			GetJointInfo(*child, joints);
		}
		else
		{
			std::cout << "root link: " << link->name << " has a null child!" << *child << std::endl;
		}
	}
}
#endif
//  urdf::ModelInterfaceSharedPtr robot_model = urdf::parseURDFFile(Globals.ExeDirectory + "lrmate200id.urdf");

void ChainRobotModel::RdfFromXmlFile(std::string xml_string_file)
{
    urdf::ModelInterfaceSharedPtr robot_model;
    robot_model = urdf::parseURDFFile(xml_string_file);
   if ( !robot_model )
  {
    throw ( std::runtime_error("ERROR: Model Parsing the xml failed") );
  }
  // GetAllJointInfo(robot_model->getRoot());
  //GetJointInfo(robot_model->getRoot(), this->jointspec);
GetAllJointInfo(robot_model->getRoot(), this);

}

};
