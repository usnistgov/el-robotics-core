
#ifndef ENDEFFECTORCHANGINGSTATION_H_
#define ENDEFFECTORCHANGINGSTATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class KittingWorkstation;
 class DAO;
 class EndEffectorHolder;
class EndEffectorChangingStation: public SolidObject{private:
std::string name;
int EndEffectorChangingStationID;
DAO* dao;
std::vector<EndEffectorHolder*> hadByEndEffectorHolder_ChangingStation;
KittingWorkstation* hasWorkstation_ChangingStation;
public:
EndEffectorChangingStation(std::string name);
~EndEffectorChangingStation();
 void get(int id);
 void get(std::string name);
void set(int id, EndEffectorChangingStation* obj);
void set(std::string name);
std::string getname();
int getEndEffectorChangingStationID();
DAO* getdao();
void setdao(DAO* _dao);
std::vector<EndEffectorHolder*>* gethadByEndEffectorHolder_ChangingStation();
void sethadByEndEffectorHolder_ChangingStation(std::vector<EndEffectorHolder*> _hadByEndEffectorHolder_ChangingStation);
KittingWorkstation* gethasWorkstation_ChangingStation();
void sethasWorkstation_ChangingStation(KittingWorkstation* _hasWorkstation_ChangingStation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ENDEFFECTORCHANGINGSTATION_H_ */