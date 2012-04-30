
#ifndef KITTINGWORKSTATION_H_
#define KITTINGWORKSTATION_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "Robot.h"
 #include "BoxVolume.h"
 #include "EndEffectorChangingStation.h"
 #include "DAO.h"
 #include "WorkTable.h"
class KittingWorkstation: public SolidObject {private:
std::string hasWorkstation_LengthUnit;
std::string hasWorkstation_WeightUnit;
std::string hasWorkstation_AngleUnit;
std::string name;
int id;
DAO* dao;
EndEffectorChangingStation* hadByChangingStation_Workstation;
BoxVolume* hasWorkstation_OtherObstacles;
BoxVolume* hasWorkstation_OtherObstacles;
WorkTable* hadByWorkTable_Workstation;
Robot* hadByRobot_Workstation;
public:
KittingWorkstation(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, KittingWorkstation* obj);
void set(std::string name, KittingWorkstation* obj);
std::string gethasWorkstation_LengthUnit();
void sethasWorkstation_LengthUnit(std::string _hasWorkstation_LengthUnit);
std::string gethasWorkstation_WeightUnit();
void sethasWorkstation_WeightUnit(std::string _hasWorkstation_WeightUnit);
std::string gethasWorkstation_AngleUnit();
void sethasWorkstation_AngleUnit(std::string _hasWorkstation_AngleUnit);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
EndEffectorChangingStation* gethadByChangingStation_Workstation();
void sethadByChangingStation_Workstation(EndEffectorChangingStation* _hadByChangingStation_Workstation);
BoxVolume* gethasWorkstation_OtherObstacles();
void sethasWorkstation_OtherObstacles(BoxVolume* _hasWorkstation_OtherObstacles);
BoxVolume* gethasWorkstation_OtherObstacles();
void sethasWorkstation_OtherObstacles(BoxVolume* _hasWorkstation_OtherObstacles);
WorkTable* gethadByWorkTable_Workstation();
void sethadByWorkTable_Workstation(WorkTable* _hadByWorkTable_Workstation);
Robot* gethadByRobot_Workstation();
void sethadByRobot_Workstation(Robot* _hadByRobot_Workstation);
void copy(KittingWorkstation const& object);
}; 
#endif /* KITTINGWORKSTATION_H_ */