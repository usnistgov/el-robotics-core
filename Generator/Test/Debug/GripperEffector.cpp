#include "GripperEffector.h"

GripperEffector::GripperEffector(std::string name) : EndEffector(name){
this->name=name;
this->get(this->name);
}std::string GripperEffector::getname(){
return this->name;
}
int GripperEffector::getid(){
return this->id;
}
DAO* GripperEffector::getdao(){
return this->dao;
}
void GripperEffector::setname(std::string _name){
this->name= _name;
}
void GripperEffector::setid(int _id){
this->id= _id;
}
void GripperEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void GripperEffector::get(std::string name){
 *dao  = DAO("GripperEffector");
 const GripperEffector* temp =(const GripperEffector*) dao->get(name);
 copy(* temp);
} void GripperEffector::set(std::string name, GripperEffector* obj){
 *dao  = DAO("GripperEffector");
 dao->set(name, (IObject) *obj);
}
void GripperEffector::copy(const GripperEffector &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
}
}