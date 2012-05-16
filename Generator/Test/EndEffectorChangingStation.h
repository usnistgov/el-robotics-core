
#ifndef ENDEFFECTORCHANGINGSTATION_H_
#define ENDEFFECTORCHANGINGSTATION_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include "DAO.h"
 class DAO;
 #include <string>
class EndEffectorChangingStation: public SolidObject{private:
std::string name;
int EndEffectorChangingStationID;
DAO* dao;
KittingWorkstation* hadByChangingStation_Workstation;
public:
EndEffectorChangingStation(std::string name);
~EndEffectorChangingStation();
 void get(int id);
 void get(std::string name);
void set(int id, EndEffectorChangingStation* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getEndEffectorChangingStationID();
void setEndEffectorChangingStationID(int _EndEffectorChangingStationID);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByChangingStation_Workstation();
void sethadByChangingStation_Workstation(KittingWorkstation* _hadByChangingStation_Workstation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ENDEFFECTORCHANGINGSTATION_H_ */