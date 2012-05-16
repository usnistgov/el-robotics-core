
#ifndef VACUUMEFFECTOR_H_
#define VACUUMEFFECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "EndEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class VacuumEffector: public EndEffector{private:
double hasVacuumEffector_CupDiameter;
double hasVacuumEffector_Length;
std::string name;
int VacuumEffectorID;
DAO* dao;
public:
VacuumEffector(std::string name);
~VacuumEffector();
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffector* obj);
void set(std::string name);
double gethasVacuumEffector_CupDiameter();
void sethasVacuumEffector_CupDiameter(double _hasVacuumEffector_CupDiameter);
double gethasVacuumEffector_Length();
void sethasVacuumEffector_Length(double _hasVacuumEffector_Length);
std::string getname();
void setname(std::string _name);
int getVacuumEffectorID();
void setVacuumEffectorID(int _VacuumEffectorID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VACUUMEFFECTOR_H_ */