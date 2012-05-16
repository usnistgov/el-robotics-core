#include "VacuumEffectorMultiCup.h"

VacuumEffectorMultiCup::VacuumEffectorMultiCup(std::string name) : VacuumEffector(name){
this->name=name;
this->get(this->name);
}std::string VacuumEffectorMultiCup::gethasMultiCup_ArrayNumber(){
return this->hasMultiCup_ArrayNumber;
}
float VacuumEffectorMultiCup::gethasMultiCup_ArrayRadius(){
return this->hasMultiCup_ArrayRadius;
}
std::string VacuumEffectorMultiCup::getname(){
return this->name;
}
int VacuumEffectorMultiCup::getid(){
return this->id;
}
DAO* VacuumEffectorMultiCup::getdao(){
return this->dao;
}
void VacuumEffectorMultiCup::sethasMultiCup_ArrayNumber(std::string _hasMultiCup_ArrayNumber){
this->hasMultiCup_ArrayNumber= _hasMultiCup_ArrayNumber;
}
void VacuumEffectorMultiCup::sethasMultiCup_ArrayRadius(float _hasMultiCup_ArrayRadius){
this->hasMultiCup_ArrayRadius= _hasMultiCup_ArrayRadius;
}
void VacuumEffectorMultiCup::setname(std::string _name){
this->name= _name;
}
void VacuumEffectorMultiCup::setid(int _id){
this->id= _id;
}
void VacuumEffectorMultiCup::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffectorMultiCup::get(std::string name){
 *dao  = DAO("VacuumEffectorMultiCup");
 const VacuumEffectorMultiCup* temp =(const VacuumEffectorMultiCup*) dao->get(name);
 copy(* temp);
} void VacuumEffectorMultiCup::set(std::string name, VacuumEffectorMultiCup* obj){
 *dao  = DAO("VacuumEffectorMultiCup");
 dao->set(name, (IObject) *obj);
}
void VacuumEffectorMultiCup::copy(const VacuumEffectorMultiCup &object){
 if(this != &object){
hasMultiCup_ArrayNumber = object.hasMultiCup_ArrayNumber;
hasMultiCup_ArrayRadius = object.hasMultiCup_ArrayRadius;
name = object.name;
id = object.id;
dao = object.dao;
}
}