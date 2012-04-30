
#ifndef VACUUMEFFECTORSINGLECUP_H_
#define VACUUMEFFECTORSINGLECUP_H_
#include <cstdlib>
#include <iostream>

#include "VacuumEffector.h"
 #include "DAO.h"
class VacuumEffectorSingleCup: public VacuumEffector {private:
std::string name;
int id;
DAO* dao;
public:
VacuumEffectorSingleCup(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffectorSingleCup* obj);
void set(std::string name, VacuumEffectorSingleCup* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(VacuumEffectorSingleCup const& object);
}; 
#endif /* VACUUMEFFECTORSINGLECUP_H_ */