
#ifndef ROBOT_H_
#define ROBOT_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "KittingWorkstation.h"
 #include "BoxVolume.h"
 #include "DAO.h"
class Robot: public SolidObject {private:
std::string hasRobot_Id;
float hasRobot_MaximumLoadWeight;
std::string hasRobot_Description;
std::string name;
int id;
DAO* dao;
KittingWorkstation* hadByRobot_Workstation;
BoxVolume* hasRobot_WorkVolume;
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
BoxVolume* gethasRobot_WorkVolume();
void sethasRobot_WorkVolume(BoxVolume* _hasRobot_WorkVolume);
void copy(Robot const& object);
}; 
#endif /* ROBOT_H_ */