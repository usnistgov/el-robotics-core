
#ifndef VACUUMEFFECTORMULTICUP_H_
#define VACUUMEFFECTORMULTICUP_H_
#include <cstdlib>
#include <iostream>

#include "VacuumEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class VacuumEffectorMultiCup: public VacuumEffector{private:
std::string hasMultiCup_ArrayNumber;
float hasMultiCup_ArrayRadius;
std::string name;
int id;
DAO* dao;
public:
VacuumEffectorMultiCup(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffectorMultiCup* obj);
void set(std::string name, VacuumEffectorMultiCup* obj);
std::string gethasMultiCup_ArrayNumber();
void sethasMultiCup_ArrayNumber(std::string _hasMultiCup_ArrayNumber);
float gethasMultiCup_ArrayRadius();
void sethasMultiCup_ArrayRadius(float _hasMultiCup_ArrayRadius);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const VacuumEffectorMultiCup &object);
}; 
#endif /* VACUUMEFFECTORMULTICUP_H_ */