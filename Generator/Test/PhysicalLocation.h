
#ifndef PHYSICALLOCATION_H_
#define PHYSICALLOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class SolidObject;
 class DAO;
class PhysicalLocation: public DataThing{private:
std::string name;
int PhysicalLocationID;
DAO* dao;
SolidObject* hasPhysicalLocation_RefObject;
std::vector<SolidObject*> hasSolidObject_PhysicalLocation;
public:
PhysicalLocation(std::string name);
~PhysicalLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PhysicalLocation* obj);
void set(std::string name);
std::string getname();
int getPhysicalLocationID();
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject);
std::vector<SolidObject*>* gethasSolidObject_PhysicalLocation();
void sethasSolidObject_PhysicalLocation(std::vector<SolidObject*> _hasSolidObject_PhysicalLocation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PHYSICALLOCATION_H_ */