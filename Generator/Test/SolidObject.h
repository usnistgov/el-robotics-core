
#ifndef SOLIDOBJECT_H_
#define SOLIDOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


 class PhysicalLocation;
 class DAO;
 class WorkTable;
class SolidObject{private:
std::string name;
int SolidObjectID;
DAO* dao;
WorkTable* hadBySolidObject_WorkTable;
PhysicalLocation* hasSolidObject_PhysicalLocation;
std::vector<PhysicalLocation*> hasPhysicalLocation_RefObject;
public:
SolidObject(std::string name);
~SolidObject();
 void get(int id);
 void get(std::string name);
void set(int id, SolidObject* obj);
void set(std::string name);
std::string getname();
int getSolidObjectID();
DAO* getdao();
void setdao(DAO* _dao);
WorkTable* gethadBySolidObject_WorkTable();
void sethadBySolidObject_WorkTable(WorkTable* _hadBySolidObject_WorkTable);
PhysicalLocation* gethasSolidObject_PhysicalLocation();
void sethasSolidObject_PhysicalLocation(PhysicalLocation* _hasSolidObject_PhysicalLocation);
std::vector<PhysicalLocation*>* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(std::vector<PhysicalLocation*> _hasPhysicalLocation_RefObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SOLIDOBJECT_H_ */