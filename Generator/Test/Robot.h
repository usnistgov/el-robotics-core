
#ifndef ROBOT_H_
#define ROBOT_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "BoxVolume.h"
 class BoxVolume;
 #include <vector>
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include "DAO.h"
 class DAO;
 #include <string>
class Robot: public SolidObject{private:
std::string hasRobot_Id;
double hasRobot_MaximumLoadWeight;
std::string hasRobot_Description;
std::string name;
int RobotID;
DAO* dao;
KittingWorkstation* hadByRobot_Workstation;
std::vector<BoxVolume*> hasRobot_WorkVolume;
public:
Robot(std::string name);
~Robot();
 void get(int id);
 void get(std::string name);
void set(int id, Robot* obj);
void set(std::string name);
std::string gethasRobot_Id();
void sethasRobot_Id(std::string _hasRobot_Id);
double gethasRobot_MaximumLoadWeight();
void sethasRobot_MaximumLoadWeight(double _hasRobot_MaximumLoadWeight);
std::string gethasRobot_Description();
void sethasRobot_Description(std::string _hasRobot_Description);
std::string getname();
void setname(std::string _name);
int getRobotID();
void setRobotID(int _RobotID);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByRobot_Workstation();
void sethadByRobot_Workstation(KittingWorkstation* _hadByRobot_Workstation);
std::vector<BoxVolume*> gethasRobot_WorkVolume();
void sethasRobot_WorkVolume(std::vector<BoxVolume*> _hasRobot_WorkVolume);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ROBOT_H_ */