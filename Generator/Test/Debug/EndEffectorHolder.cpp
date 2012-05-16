#include "EndEffectorHolder.h"

EndEffectorHolder::EndEffectorHolder(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string EndEffectorHolder::getname(){
return this->name;
}
int EndEffectorHolder::getid(){
return this->id;
}
DAO* EndEffectorHolder::getdao(){
return this->dao;
}
void EndEffectorHolder::setname(std::string _name){
this->name= _name;
}
void EndEffectorHolder::setid(int _id){
this->id= _id;
}
void EndEffectorHolder::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorHolder::get(std::string name){
 *dao  = DAO("EndEffectorHolder");
 const EndEffectorHolder* temp =(const EndEffectorHolder*) dao->get(name);
 copy(* temp);
} void EndEffectorHolder::set(std::string name, EndEffectorHolder* obj){
 *dao  = DAO("EndEffectorHolder");
 dao->set(name, (IObject) *obj);
}
void EndEffectorHolder::copy(const EndEffectorHolder &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
}
}