#include "VacuumEffector.h"

VacuumEffector::VacuumEffector(std::string name) : EndEffector(name){
this->name=name;
this->get(this->name);
}float VacuumEffector::gethasVacuumEffector_CupDiameter(){
return this->hasVacuumEffector_CupDiameter;
}
float VacuumEffector::gethasVacuumEffector_Length(){
return this->hasVacuumEffector_Length;
}
std::string VacuumEffector::getname(){
return this->name;
}
int VacuumEffector::getid(){
return this->id;
}
DAO* VacuumEffector::getdao(){
return this->dao;
}
void VacuumEffector::sethasVacuumEffector_CupDiameter(float _hasVacuumEffector_CupDiameter){
this->hasVacuumEffector_CupDiameter= _hasVacuumEffector_CupDiameter;
}
void VacuumEffector::sethasVacuumEffector_Length(float _hasVacuumEffector_Length){
this->hasVacuumEffector_Length= _hasVacuumEffector_Length;
}
void VacuumEffector::setname(std::string _name){
this->name= _name;
}
void VacuumEffector::setid(int _id){
this->id= _id;
}
void VacuumEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffector::get(std::string name){
 *dao  = DAO("VacuumEffector");
 const VacuumEffector temp = dao->get(name);
 copy(temp);
} void VacuumEffector::set(std::string name, VacuumEffector* obj){
 *dao  = DAO("VacuumEffector");
 dao->set(name, obj);
}
void VacuumEffector::copy(VacuumEffector const& object){
 if(this != &object){
hasVacuumEffector_CupDiameter = object.hasVacuumEffector_CupDiameter;
hasVacuumEffector_Length = object.hasVacuumEffector_Length;
name = object.name;
id = object.id;
dao = object.dao;
}
}