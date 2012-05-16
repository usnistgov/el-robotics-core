
#ifndef PHYSICALLOCATION_H_
#define PHYSICALLOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "DataThing.h"
 #include "DAO.h"
 class DAO;
 #include <string>
 #include "SolidObject.h"
 class SolidObject;
class PhysicalLocation: public DataThing{private:
std::string name;
int PhysicalLocationID;
DAO* dao;
SolidObject* hasPhysicalLocation_RefObject;
SolidObject* hasSolidObject_PhysicalLocation;
public:
PhysicalLocation(std::string name);
~PhysicalLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PhysicalLocation* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getPhysicalLocationID();
void setPhysicalLocationID(int _PhysicalLocationID);
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject);
SolidObject* gethasSolidObject_PhysicalLocation();
void sethasSolidObject_PhysicalLocation(SolidObject* _hasSolidObject_PhysicalLocation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PHYSICALLOCATION_H_ */