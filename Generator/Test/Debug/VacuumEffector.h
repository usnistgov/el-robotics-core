
#ifndef VACUUMEFFECTOR_H_
#define VACUUMEFFECTOR_H_
#include <cstdlib>
#include <iostream>

#include "EndEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class VacuumEffector: public EndEffector{private:
float hasVacuumEffector_CupDiameter;
float hasVacuumEffector_Length;
std::string name;
int id;
DAO* dao;
public:
VacuumEffector(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffector* obj);
void set(std::string name, VacuumEffector* obj);
float gethasVacuumEffector_CupDiameter();
void sethasVacuumEffector_CupDiameter(float _hasVacuumEffector_CupDiameter);
float gethasVacuumEffector_Length();
void sethasVacuumEffector_Length(float _hasVacuumEffector_Length);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const VacuumEffector &object);
}; 
#endif /* VACUUMEFFECTOR_H_ */