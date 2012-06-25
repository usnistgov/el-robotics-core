#include "BoxVolume.h"

#include "KittingWorkstation.h"
#include "Robot.h"
#include "DAO.h"
#include "Point.h"

BoxVolume::BoxVolume(std::string name) :
	DataThing(name) {
	this->name = name;
	dao = NULL;
	hasBoxVolume_MaximumPoint = NULL;
	hasBoxVolume_MinimumPoint = NULL;

}
BoxVolume::~BoxVolume() {
	delete (dao);
	delete (hasBoxVolume_MaximumPoint);
	delete (hasBoxVolume_MinimumPoint);
	for (std::size_t i = 0; i < hasWorkstation_OtherObstacles.size(); i++)
		delete (hasWorkstation_OtherObstacles[i]);
	for (std::size_t i = 0; i < hasRobot_WorkVolume.size(); i++)
		delete (hasRobot_WorkVolume[i]);
}
std::string BoxVolume::getname() {
	return name;
}
int BoxVolume::getBoxVolumeID() {
	return BoxVolumeID;
}
DAO* BoxVolume::getdao() {
	return dao;
}
Point* BoxVolume::gethasBoxVolume_MaximumPoint() {
	return hasBoxVolume_MaximumPoint;
}
Point* BoxVolume::gethasBoxVolume_MinimumPoint() {
	return hasBoxVolume_MinimumPoint;
}
std::vector<KittingWorkstation*>* BoxVolume::gethasWorkstation_OtherObstacles() {
	return &hasWorkstation_OtherObstacles;
}
std::vector<Robot*>* BoxVolume::gethasRobot_WorkVolume() {
	return &hasRobot_WorkVolume;
}
void BoxVolume::setdao(DAO* _dao) {
	this->dao = _dao;
}
void BoxVolume::sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint) {
	this->hasBoxVolume_MaximumPoint = _hasBoxVolume_MaximumPoint;
}
void BoxVolume::sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint) {
	this->hasBoxVolume_MinimumPoint = _hasBoxVolume_MinimumPoint;
}
void BoxVolume::sethasWorkstation_OtherObstacles(std::vector<
		KittingWorkstation*> _hasWorkstation_OtherObstacles) {
	this->hasWorkstation_OtherObstacles = _hasWorkstation_OtherObstacles;
}
void BoxVolume::sethasRobot_WorkVolume(std::vector<Robot*> _hasRobot_WorkVolume) {
	this->hasRobot_WorkVolume = _hasRobot_WorkVolume;
}
void BoxVolume::get(std::string name) {
	std::map<std::string, std::string> temp;
	dao = new DAO("DataThing");
	temp = dao->get(name);
	delete (dao);
	DataThing::copy(temp);
	dao = new DAO("BoxVolume");
	temp = dao->get(name);
	delete (dao);
	copy(temp);
}
void BoxVolume::set(std::string name) {
	std::map<std::string, std::string> data;
	std::stringstream ss;
	data["name"] = name;
	data["BoxVolumeID"] = BoxVolumeID;
	data["hasBoxVolume_MaximumPoint"] = hasBoxVolume_MaximumPoint->getname();
	data["hasBoxVolume_MinimumPoint"] = hasBoxVolume_MinimumPoint->getname();
	for (unsigned int i = 0; i < hasWorkstation_OtherObstacles.size(); ++i) {
		ss.flush();
		ss << hasWorkstation_OtherObstacles[i]->getKittingWorkstationID();
		data["hasWorkstation_OtherObstacles"]
				= data["hasWorkstation_OtherObstacles"] + " " + ss.str();
	}
	for (unsigned int i = 0; i < hasRobot_WorkVolume.size(); ++i) {
		ss.flush();
		ss << hasRobot_WorkVolume[i]->getRobotID();
		data["hasRobot_WorkVolume"] = data["hasRobot_WorkVolume"] + " "
				+ ss.str();
	}
	dao = new DAO("BoxVolume");
	dao->set(data);
	delete (dao);
}

void BoxVolume::copy(std::map<std::string, std::string> object) {
	std::vector<std::string> temp;
	std::map<std::string, std::string> mapTemp;
	std::map<std::string, std::string> mapTempBis;
	int nbVal = 0;
	int nbValCurrent = 0;
	std::vector<BoxVolume*> tmp;
	this->name = object["BoxVolume._NAME"];
	this->BoxVolumeID = std::atof(object["BoxVolume.BoxVolumeID"].c_str());
	if (this->hasBoxVolume_MaximumPoint == NULL
			&& object["hasBoxVolume_MaximumPoint/Point._NAME"] != "") {
		this->hasBoxVolume_MaximumPoint = new Point(
				object["hasBoxVolume_MaximumPoint/Point._NAME"]);
	}
	if (this->hasBoxVolume_MinimumPoint == NULL
			&& object["hasBoxVolume_MinimumPoint/Point._NAME"] != "") {
		this->hasBoxVolume_MinimumPoint = new Point(
				object["hasBoxVolume_MinimumPoint/Point._NAME"]);
	}
	if (this->hasWorkstation_OtherObstacles.empty()
			&& object["hasWorkstation_OtherObstacles/KittingWorkstation._NAME"]
					!= "") {
		temp
				= Explode(
						object["hasWorkstation_OtherObstacles/KittingWorkstation._NAME"],
						' ');
		for (unsigned int i = 0; i < temp.size(); i++) {
			this->hasWorkstation_OtherObstacles.push_back(
					new KittingWorkstation(temp[i]));
		}
	}
	if (this->hasRobot_WorkVolume.empty()
			&& object["hasRobot_WorkVolume/Robot._NAME"] != "") {
		temp = Explode(object["hasRobot_WorkVolume/Robot._NAME"], ' ');
		for (unsigned int i = 0; i < temp.size(); i++) {
			this->hasRobot_WorkVolume.push_back(new Robot(temp[i]));
		}
	}

}
std::vector<std::string> BoxVolume::Explode(const std::string & str,
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
