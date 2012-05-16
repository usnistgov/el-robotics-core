
#ifndef VACUUMEFFECTORSINGLECUP_H_
#define VACUUMEFFECTORSINGLECUP_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "VacuumEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class VacuumEffectorSingleCup: public VacuumEffector{private:
std::string name;
int VacuumEffectorSingleCupID;
DAO* dao;
public:
VacuumEffectorSingleCup(std::string name);
~VacuumEffectorSingleCup();
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffectorSingleCup* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getVacuumEffectorSingleCupID();
void setVacuumEffectorSingleCupID(int _VacuumEffectorSingleCupID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VACUUMEFFECTORSINGLECUP_H_ */