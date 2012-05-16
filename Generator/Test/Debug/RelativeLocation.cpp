#include "RelativeLocation.h"

RelativeLocation::RelativeLocation(std::string name) : PhysicalLocation(name){
this->name=name;
this->get(this->name);
}std::string RelativeLocation::getname(){
return this->name;
}
int RelativeLocation::getid(){
return this->id;
}
DAO* RelativeLocation::getdao(){
return this->dao;
}
void RelativeLocation::setname(std::string _name){
this->name= _name;
}
void RelativeLocation::setid(int _id){
this->id= _id;
}
void RelativeLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocation::get(std::string name){
 *dao  = DAO("RelativeLocation");
 const RelativeLocation* temp =(const RelativeLocation*) dao->get(name);
 copy(* temp);
} void RelativeLocation::set(std::string name, RelativeLocation* obj){
 *dao  = DAO("RelativeLocation");
 dao->set(name, (IObject) *obj);
}
void RelativeLocation::copy(const RelativeLocation &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
}
}