
#ifndef PHYSICALLOCATION_H_
#define PHYSICALLOCATION_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
 #include "SolidObject.h"
class PhysicalLocation: public DataThing {private:
std::string name;
int id;
DAO* dao;
SolidObject* hasPhysicalLocation_RefObject;
public:
PhysicalLocation(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, PhysicalLocation* obj);
void set(std::string name, PhysicalLocation* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject);
void copy(PhysicalLocation const& object);
}; 
#endif /* PHYSICALLOCATION_H_ */