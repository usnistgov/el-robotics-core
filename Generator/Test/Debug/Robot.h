
#ifndef ROBOT_H_
#define ROBOT_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "BoxVolume.h"
 #include <vector>
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include "DAO.h"
 class DAO;
 #include <string>
class Robot: public SolidObject{private:
std::string hasRobot_Id;
float hasRobot_MaximumLoadWeight;
std::string hasRobot_Description;
std::string name;
int id;
DAO* dao;
KittingWorkstation* hadByRobot_Workstation;
std::vector<BoxVolume*> hasRobot_WorkVolume;
public:
Robot(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, Robot* obj);
void set(std::string name, Robot* obj);
std::string gethasRobot_Id();
void sethasRobot_Id(std::string _hasRobot_Id);
float gethasRobot_MaximumLoadWeight();
void sethasRobot_MaximumLoadWeight(float _hasRobot_MaximumLoadWeight);
std::string gethasRobot_Description();
void sethasRobot_Description(std::string _hasRobot_Description);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByRobot_Workstation();
void sethadByRobot_Workstation(KittingWorkstation* _hadByRobot_Workstation);
std::vector<BoxVolume*> gethasRobot_WorkVolume();
void sethasRobot_WorkVolume(std::vector<BoxVolume*> _hasRobot_WorkVolume);
void copy(const Robot &object);
}; 
#endif /* ROBOT_H_ */