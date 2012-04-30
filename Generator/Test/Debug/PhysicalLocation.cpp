#include "PhysicalLocation.h"

PhysicalLocation::PhysicalLocation(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}std::string PhysicalLocation::getname(){
return this->name;
}
int PhysicalLocation::getid(){
return this->id;
}
DAO* PhysicalLocation::getdao(){
return this->dao;
}
SolidObject* PhysicalLocation::gethasPhysicalLocation_RefObject(){
return this->hasPhysicalLocation_RefObject;
}
void PhysicalLocation::setname(std::string _name){
this->name= _name;
}
void PhysicalLocation::setid(int _id){
this->id= _id;
}
void PhysicalLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PhysicalLocation::sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void PhysicalLocation::get(std::string name){
 *dao  = DAO("PhysicalLocation");
 const PhysicalLocation temp = dao->get(name);
 copy(temp);
} void PhysicalLocation::set(std::string name, PhysicalLocation* obj){
 *dao  = DAO(PhysicalLocation);
 dao->set(name, obj);
}
void PhysicalLocation::copy(PhysicalLocation const& object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hasPhysicalLocation_RefObject = object.hasPhysicalLocation_RefObject;
}
}