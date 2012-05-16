#include "RelativeLocationOn.h"

RelativeLocationOn::RelativeLocationOn(std::string name) : RelativeLocation(name){
this->name=name;
this->get(this->name);
}std::string RelativeLocationOn::gethasRelativeLocationOn_Description(){
return this->hasRelativeLocationOn_Description;
}
std::string RelativeLocationOn::getname(){
return this->name;
}
int RelativeLocationOn::getid(){
return this->id;
}
DAO* RelativeLocationOn::getdao(){
return this->dao;
}
void RelativeLocationOn::sethasRelativeLocationOn_Description(std::string _hasRelativeLocationOn_Description){
this->hasRelativeLocationOn_Description= _hasRelativeLocationOn_Description;
}
void RelativeLocationOn::setname(std::string _name){
this->name= _name;
}
void RelativeLocationOn::setid(int _id){
this->id= _id;
}
void RelativeLocationOn::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocationOn::get(std::string name){
 *dao  = DAO("RelativeLocationOn");
 const RelativeLocationOn* temp =(const RelativeLocationOn*) dao->get(name);
 copy(* temp);
} void RelativeLocationOn::set(std::string name, RelativeLocationOn* obj){
 *dao  = DAO("RelativeLocationOn");
 dao->set(name, (IObject) *obj);
}
void RelativeLocationOn::copy(const RelativeLocationOn &object){
 if(this != &object){
hasRelativeLocationOn_Description = object.hasRelativeLocationOn_Description;
name = object.name;
id = object.id;
dao = object.dao;
}
}