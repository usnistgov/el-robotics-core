#include <iostream>
#include "database/DAO.h"
#include "database/Part.h"
#include "database/PoseLocation.h"
#include "database/Point.h"
#include "partModel.h"
#include "recurseLocation.h"
#include "usarTruth.hh"

void getPartClasses(std::vector<std::string> &partClasses)
{
	partClasses.clear();
	
	//get all parts from database
	DAO *dao = new DAO("Part");
	std::vector<std::string> attributes;
	attributes.push_back("_NAME");
	std::vector<std::string> partNames = dao->getAll(attributes, "Part")["_NAME"];
	delete dao;
	
	//iterate through parts, adding a new name to the list whenever we find one
	std::string partClass;
	Part *part;
	if(!partNames.empty())
		part = new Part(partNames[0]);
	PartModel partModel;
	for(unsigned int i = 0;i<partNames.size();i++)
	{
		part->get(partNames[i]);
		partModel.setPart(part);
		partClass = partModel.getModel();
		
		std::vector<std::string>::iterator it = std::find(partClasses.begin(), partClasses.end(), partClass);
		if(it == partClasses.end())
		{
			partClasses.push_back(partClass);
		}
	}
	delete part;
}

int main(int argc, char ** argv)
{
	UsarTruth utruth("yosemite", 3989);
	utruth.connect();
	std::vector<UsarData> data;
	
	RecurseLocation recurseLocation;
	std::vector<std::string> partClasses;
	getPartClasses(partClasses);
	Part *part = new Part("");
	PoseLocation *pose = new PoseLocation("");
	Point *point = new Point("");
	Vector *xAxis = new Vector("");
	Vector *zAxis = new Vector("");
	for(unsigned int i = 0;i<partClasses.size();i++)
	{
		utruth.getData(data, partClasses[i]);
		for(unsigned int j = 0;j<data.size();j++)
		{
			//flip y/z values of data to match coordinate system
			data[j].location[1] = -1 * data[j].location[1];
			data[j].location[2] = -1 * data[j].location[2];
			
			part->get(data[j].objectName);
			//find the global position of the part
			recurseLocation.clear();
			recurseLocation.recurse(part);
			recurseLocation.computeGlobalLoc();
			RecLoc sqlGlobalInverse = recurseLocation.getGlobalLoc();
			sqlGlobalInverse.frame = sqlGlobalInverse.frame.invert();
			
			//find the local pose of the part in the database
			std::string poseName = part->gethasSolidObject_PrimaryLocation()->getname();
			pose->get(poseName);
			
			point = pose->gethasPoseLocation_Point();
			point->get(point->getname());
			xAxis = pose->gethasPoseLocation_XAxis();
			xAxis->get(xAxis->getname());
			zAxis = pose->gethasPoseLocation_ZAxis();
			zAxis->get(zAxis->getname());
			
			RecLoc localPartPose;
			localPartPose.frame.setPoint(point->gethasPoint_X(), point->gethasPoint_Y(), point->gethasPoint_Z());
			localPartPose.frame.setXAxis(xAxis->gethasVector_I(), xAxis->gethasVector_J(), xAxis->gethasVector_K());
			localPartPose.frame.setZAxis(zAxis->gethasVector_I(), zAxis->gethasVector_J(), zAxis->gethasVector_K());
			
			RecLoc usarsimGlobalLoc;
			usarsimGlobalLoc.frame.setPoint(data[j].location[0], data[j].location[1], data[j].location[2]);
			usarsimGlobalLoc.setRollPitchYaw(data[j].rotation[0], data[j].rotation[1], data[j].rotation[2]);
				
			RecLoc result;
			result.frame.setPoint(0,0,0);
			result.frame.setXAxis(1,0,0);
			result.frame.setZAxis(0,0,1);
			//the RecurseLocation object here is irrelevant (maybe poseProduct should be static, or a member of RecLoc?)
			recurseLocation.poseProduct(&result, &localPartPose, &sqlGlobalInverse);
			recurseLocation.poseProduct(&result, &result, &usarsimGlobalLoc);
			
			
			//update the pose in the mysql database with the new pose
			point->sethasPoint_X(result.frame.pointXYZ[0]);
			point->sethasPoint_Y(result.frame.pointXYZ[1]);
			point->sethasPoint_Z(result.frame.pointXYZ[2]);
			
			xAxis->sethasVector_I(result.frame.xAxis[0]);
			xAxis->sethasVector_J(result.frame.xAxis[1]);
			xAxis->sethasVector_K(result.frame.xAxis[2]);
			
			zAxis->sethasVector_I(result.frame.zAxis[0]);
			zAxis->sethasVector_J(result.frame.zAxis[1]);
			zAxis->sethasVector_K(result.frame.zAxis[2]);
			
			point->set(point->getname());
			xAxis->set(xAxis->getname());
			zAxis->set(zAxis->getname());
		}
	}
	//delete point;
	delete pose;
	delete part;
	
	return 0;
}
