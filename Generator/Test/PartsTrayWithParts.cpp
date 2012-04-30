#include "PartsTrayWithParts.h"

PartsTrayWithParts::PartsTrayWithParts(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string PartsTrayWithParts::getname(){
return this->name;
}
int PartsTrayWithParts::getid(){
return this->id;
}
DAO* PartsTrayWithParts::getdao(){
return this->dao;
}
PartsTray* PartsTrayWithParts::gethadByPartsTray_PartsTrayWithParts(){
return this->hadByPartsTray_PartsTrayWithParts;
}
void PartsTrayWithParts::setname(std::string _name){
this->name= _name;
}
void PartsTrayWithParts::setid(int _id){
this->id= _id;
}
void PartsTrayWithParts::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTrayWithParts::sethadByPartsTray_PartsTrayWithParts(PartsTray* _hadByPartsTray_PartsTrayWithParts){
this->hadByPartsTray_PartsTrayWithParts= _hadByPartsTray_PartsTrayWithParts;
}
void PartsTrayWithParts::get(std::string name){
 *dao  = DAO("PartsTrayWithParts");
 const PartsTrayWithParts temp = dao->get(name);
 copy(temp);
} void PartsTrayWithParts::set(std::string name, PartsTrayWithParts* obj){
 *dao  = DAO("PartsTrayWithParts");
 dao->set(name, obj);
}
void PartsTrayWithParts::copy(PartsTrayWithParts const& object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hadByPartsTray_PartsTrayWithParts = object.hadByPartsTray_PartsTrayWithParts;
}
}