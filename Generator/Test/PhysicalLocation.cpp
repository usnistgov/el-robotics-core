#include "PhysicalLocation.h"

#include "SolidObject.h"
#include "DAO.h"

PhysicalLocation::PhysicalLocation(std::string name) :
	DataThing(name) {
	this->name = name;
	dao = NULL;
	hasPhysicalLocation_RefObject = NULL;

}
PhysicalLocation::~PhysicalLocation() {
	delete (dao);
	delete (hasPhysicalLocation_RefObject);
	for (std::size_t i = 0; i < hasSolidObject_PhysicalLocation.size(); i++)
		delete (hasSolidObject_PhysicalLocation[i]);
}
std::string PhysicalLocation::getname() {
	return name;
}
int PhysicalLocation::getPhysicalLocationID() {
	return PhysicalLocationID;
}
DAO* PhysicalLocation::getdao() {
	return dao;
}
SolidObject* PhysicalLocation::gethasPhysicalLocation_RefObject() {
	return hasPhysicalLocation_RefObject;
}
std::vector<SolidObject*>* PhysicalLocation::gethasSolidObject_PhysicalLocation() {
	return &hasSolidObject_PhysicalLocation;
}
void PhysicalLocation::setdao(DAO* _dao) {
	this->dao = _dao;
}
void PhysicalLocation::sethasPhysicalLocation_RefObject(
		SolidObject* _hasPhysicalLocation_RefObject) {
	this->hasPhysicalLocation_RefObject = _hasPhysicalLocation_RefObject;
}
void PhysicalLocation::sethasSolidObject_PhysicalLocation(std::vector<
		SolidObject*> _hasSolidObject_PhysicalLocation) {
	this->hasSolidObject_PhysicalLocation = _hasSolidObject_PhysicalLocation;
}
void PhysicalLocation::get(std::string name) {
	std::map<std::string, std::string> temp;
	dao = new DAO("DataThing");
	temp = dao->get(name);
	delete (dao);
	DataThing::copy(temp);
	dao = new DAO("PhysicalLocation");
	temp = dao->get(name);
	delete (dao);
	copy(temp);
}
void PhysicalLocation::set(std::string name) {
	std::map<std::string, std::string> data;
	std::stringstream ss;
	data["name"] = name;
	data["PhysicalLocationID"] = PhysicalLocationID;
	data["hasPhysicalLocation_RefObject"]
			= hasPhysicalLocation_RefObject->getname();
	for (unsigned int i = 0; i < hasSolidObject_PhysicalLocation.size(); ++i) {
		ss.flush();
		ss << hasSolidObject_PhysicalLocation[i]->getSolidObjectID();
		data["hasSolidObject_PhysicalLocation"]
				= data["hasSolidObject_PhysicalLocation"] + " " + ss.str();
	}
	dao = new DAO("PhysicalLocation");
	dao->set(data);
	delete (dao);
}

void PhysicalLocation::copy(std::map<std::string, std::string> object) {
	std::vector<std::string> temp;
	std::map<std::string, std::string> mapTemp;
	std::map<std::string, std::string> mapTempBis;
	int nbVal = 0;
	int nbValCurrent = 0;
	std::vector<PhysicalLocation*> tmp;
	this->name = object["PhysicalLocation._NAME"];
	this->PhysicalLocationID = std::atof(
			object["PhysicalLocation.PhysicalLocationID"].c_str());
	if (this->hasPhysicalLocation_RefObject == NULL
			&& object["hasPhysicalLocation_RefObject/SolidObject._NAME"] != "") {
		this->hasPhysicalLocation_RefObject = new SolidObject(
				object["hasPhysicalLocation_RefObject/SolidObject._NAME"]);
	}
	if (this->hasSolidObject_PhysicalLocation.empty()
			&& object["hasSolidObject_PhysicalLocation/SolidObject._NAME"]
					!= "") {
		temp = Explode(
				object["hasSolidObject_PhysicalLocation/SolidObject._NAME"],
				' ');
		for (unsigned int i = 0; i < temp.size(); i++) {
			this->hasSolidObject_PhysicalLocation.push_back(new SolidObject(
					temp[i]));
		}
	}

}
std::vector<std::string> PhysicalLocation::Explode(const std::string & str,
		char separator) {
	std::vector<std::string> result;
	std::size_t pos1 = 0;
	std::size_t pos2 = 0;
	while (pos2 != str.npos) {
		pos2 = str.find(separator, pos1);
		if (pos2 != str.npos) {
			if (pos2 > pos1)
				result.push_back(str.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
		}
	}
	result.push_back(str.substr(pos1, str.size() - pos1));
	return result;
}
