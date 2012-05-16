#include "RelativeLocationIn.h"

RelativeLocationIn::RelativeLocationIn(std::string name) : RelativeLocation(name){
this->name=name;
this->get(this->name);
}std::string RelativeLocationIn::gethasRelativeLocationIn_Description(){
return this->hasRelativeLocationIn_Description;
}
std::string RelativeLocationIn::getname(){
return this->name;
}
int RelativeLocationIn::getid(){
return this->id;
}
DAO* RelativeLocationIn::getdao(){
return this->dao;
}
void RelativeLocationIn::sethasRelativeLocationIn_Description(std::string _hasRelativeLocationIn_Description){
this->hasRelativeLocationIn_Description= _hasRelativeLocationIn_Description;
}
void RelativeLocationIn::setname(std::string _name){
this->name= _name;
}
void RelativeLocationIn::setid(int _id){
this->id= _id;
}
void RelativeLocationIn::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocationIn::get(std::string name){
 *dao  = DAO("RelativeLocationIn");
 const RelativeLocationIn* temp =(const RelativeLocationIn*) dao->get(name);
 copy(* temp);
} void RelativeLocationIn::set(std::string name, RelativeLocationIn* obj){
 *dao  = DAO("RelativeLocationIn");
 dao->set(name, (IObject) *obj);
}
void RelativeLocationIn::copy(const RelativeLocationIn &object){
 if(this != &object){
hasRelativeLocationIn_Description = object.hasRelativeLocationIn_Description;
name = object.name;
id = object.id;
dao = object.dao;
}
}