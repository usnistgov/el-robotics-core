#include "PartsTray.h"

PartsTray::PartsTray(std::string name) : BoxyObject(name){
this->name=name;
this->get(this->name);
}std::string PartsTray::gethasPartsTray_SkuRef(){
return this->hasPartsTray_SkuRef;
}
std::string PartsTray::gethasPartsTray_SerialNumber(){
return this->hasPartsTray_SerialNumber;
}
std::string PartsTray::getname(){
return this->name;
}
int PartsTray::getid(){
return this->id;
}
DAO* PartsTray::getdao(){
return this->dao;
}
PartsTrayWithParts* PartsTray::gethadByPartsTray_PartsTrayWithParts(){
return this->hadByPartsTray_PartsTrayWithParts;
}
void PartsTray::sethasPartsTray_SkuRef(std::string _hasPartsTray_SkuRef){
this->hasPartsTray_SkuRef= _hasPartsTray_SkuRef;
}
void PartsTray::sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber){
this->hasPartsTray_SerialNumber= _hasPartsTray_SerialNumber;
}
void PartsTray::setname(std::string _name){
this->name= _name;
}
void PartsTray::setid(int _id){
this->id= _id;
}
void PartsTray::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTray::sethadByPartsTray_PartsTrayWithParts(PartsTrayWithParts* _hadByPartsTray_PartsTrayWithParts){
this->hadByPartsTray_PartsTrayWithParts= _hadByPartsTray_PartsTrayWithParts;
}
void PartsTray::get(std::string name){
 *dao  = DAO("PartsTray");
 const PartsTray temp = dao->get(name);
 copy(temp);
} void PartsTray::set(std::string name, PartsTray* obj){
 *dao  = DAO(PartsTray);
 dao->set(name, obj);
}
void PartsTray::copy(PartsTray const& object){
 if(this != &object){
hasPartsTray_SkuRef = object.hasPartsTray_SkuRef;
hasPartsTray_SerialNumber = object.hasPartsTray_SerialNumber;
name = object.name;
id = object.id;
dao = object.dao;
hadByPartsTray_PartsTrayWithParts = object.hadByPartsTray_PartsTrayWithParts;
}
}