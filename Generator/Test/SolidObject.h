
#ifndef SOLIDOBJECT_H_
#define SOLIDOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>

 #include "PhysicalLocation.h"
 class PhysicalLocation;
 #include "DAO.h"
 class DAO;
 #include <string>
class SolidObject{private:
std::string name;
int SolidObjectID;
DAO* dao;
PhysicalLocation* hasSolidObject_PhysicalLocation;
PhysicalLocation* hasPhysicalLocation_RefObject;
public:
SolidObject(std::string name);
~SolidObject();
 void get(int id);
 void get(std::string name);
void set(int id, SolidObject* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getSolidObjectID();
void setSolidObjectID(int _SolidObjectID);
DAO* getdao();
void setdao(DAO* _dao);
PhysicalLocation* gethasSolidObject_PhysicalLocation();
void sethasSolidObject_PhysicalLocation(PhysicalLocation* _hasSolidObject_PhysicalLocation);
PhysicalLocation* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(PhysicalLocation* _hasPhysicalLocation_RefObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SOLIDOBJECT_H_ */