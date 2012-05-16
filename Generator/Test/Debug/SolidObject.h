
#ifndef SOLIDOBJECT_H_
#define SOLIDOBJECT_H_
#include <cstdlib>
#include <iostream>

 #include "PhysicalLocation.h"
 class PhysicalLocation;
 #include "DAO.h"
 class DAO;
 #include <string>
class SolidObject: public IObject {private:
std::string name;
int id;
DAO* dao;
PhysicalLocation* hasSolidObject_PhysicalLocation;
public:
SolidObject(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, SolidObject* obj);
void set(std::string name, SolidObject* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
PhysicalLocation* gethasSolidObject_PhysicalLocation();
void sethasSolidObject_PhysicalLocation(PhysicalLocation* _hasSolidObject_PhysicalLocation);
void copy(const SolidObject &object);
}; 
#endif /* SOLIDOBJECT_H_ */