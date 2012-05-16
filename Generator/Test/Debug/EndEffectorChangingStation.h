
#ifndef ENDEFFECTORCHANGINGSTATION_H_
#define ENDEFFECTORCHANGINGSTATION_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include "DAO.h"
 class DAO;
 #include <string>
class EndEffectorChangingStation: public SolidObject{private:
std::string name;
int id;
DAO* dao;
KittingWorkstation* hadByChangingStation_Workstation;
public:
EndEffectorChangingStation(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, EndEffectorChangingStation* obj);
void set(std::string name, EndEffectorChangingStation* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByChangingStation_Workstation();
void sethadByChangingStation_Workstation(KittingWorkstation* _hadByChangingStation_Workstation);
void copy(const EndEffectorChangingStation &object);
}; 
#endif /* ENDEFFECTORCHANGINGSTATION_H_ */