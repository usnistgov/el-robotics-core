
#ifndef VACUUMEFFECTORMULTICUP_H_
#define VACUUMEFFECTORMULTICUP_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "VacuumEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class VacuumEffectorMultiCup: public VacuumEffector{private:
std::string hasMultiCup_ArrayNumber;
double hasMultiCup_ArrayRadius;
std::string name;
int VacuumEffectorMultiCupID;
DAO* dao;
public:
VacuumEffectorMultiCup(std::string name);
~VacuumEffectorMultiCup();
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffectorMultiCup* obj);
void set(std::string name);
std::string gethasMultiCup_ArrayNumber();
void sethasMultiCup_ArrayNumber(std::string _hasMultiCup_ArrayNumber);
double gethasMultiCup_ArrayRadius();
void sethasMultiCup_ArrayRadius(double _hasMultiCup_ArrayRadius);
std::string getname();
void setname(std::string _name);
int getVacuumEffectorMultiCupID();
void setVacuumEffectorMultiCupID(int _VacuumEffectorMultiCupID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VACUUMEFFECTORMULTICUP_H_ */