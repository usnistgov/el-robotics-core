#include "SolidObject.h"

SolidObject::SolidObject(std::string name){
this->name=name;
this->get(this->name);
}std::string SolidObject::getname(){
return this->name;
}
int SolidObject::getid(){
return this->id;
}
DAO* SolidObject::getdao(){
return this->dao;
}
PhysicalLocation* SolidObject::gethasSolidObject_PhysicalLocation(){
return this->hasSolidObject_PhysicalLocation;
}
void SolidObject::setname(std::string _name){
this->name= _name;
}
void SolidObject::setid(int _id){
this->id= _id;
}
void SolidObject::setdao(DAO* _dao){
this->dao= _dao;
}
void SolidObject::sethasSolidObject_PhysicalLocation(PhysicalLocation* _hasSolidObject_PhysicalLocation){
this->hasSolidObject_PhysicalLocation= _hasSolidObject_PhysicalLocation;
}
void SolidObject::get(std::string name){
 *dao  = DAO("SolidObject");
 const SolidObject temp = dao->get(name);
 copy(temp);
} void SolidObject::set(std::string name, SolidObject* obj){
 *dao  = DAO(SolidObject);
 dao->set(name, obj);
}
void SolidObject::copy(SolidObject const& object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hasSolidObject_PhysicalLocation = object.hasSolidObject_PhysicalLocation;
}
}