#include "VacuumEffectorSingleCup.h"

VacuumEffectorSingleCup::VacuumEffectorSingleCup(std::string name) : VacuumEffector(name){
this->name=name;
this->get(this->name);
}std::string VacuumEffectorSingleCup::getname(){
return this->name;
}
int VacuumEffectorSingleCup::getid(){
return this->id;
}
DAO* VacuumEffectorSingleCup::getdao(){
return this->dao;
}
void VacuumEffectorSingleCup::setname(std::string _name){
this->name= _name;
}
void VacuumEffectorSingleCup::setid(int _id){
this->id= _id;
}
void VacuumEffectorSingleCup::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffectorSingleCup::get(std::string name){
 *dao  = DAO("VacuumEffectorSingleCup");
 const VacuumEffectorSingleCup* temp =(const VacuumEffectorSingleCup*) dao->get(name);
 copy(* temp);
} void VacuumEffectorSingleCup::set(std::string name, VacuumEffectorSingleCup* obj){
 *dao  = DAO("VacuumEffectorSingleCup");
 dao->set(name, (IObject) *obj);
}
void VacuumEffectorSingleCup::copy(const VacuumEffectorSingleCup &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
}
}