#include "EndEffectorChangingStation.h"

EndEffectorChangingStation::EndEffectorChangingStation(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string EndEffectorChangingStation::getname(){
return this->name;
}
int EndEffectorChangingStation::getid(){
return this->id;
}
DAO* EndEffectorChangingStation::getdao(){
return this->dao;
}
KittingWorkstation* EndEffectorChangingStation::gethadByChangingStation_Workstation(){
return this->hadByChangingStation_Workstation;
}
void EndEffectorChangingStation::setname(std::string _name){
this->name= _name;
}
void EndEffectorChangingStation::setid(int _id){
this->id= _id;
}
void EndEffectorChangingStation::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorChangingStation::sethadByChangingStation_Workstation(KittingWorkstation* _hadByChangingStation_Workstation){
this->hadByChangingStation_Workstation= _hadByChangingStation_Workstation;
}
void EndEffectorChangingStation::get(std::string name){
 *dao  = DAO("EndEffectorChangingStation");
 const EndEffectorChangingStation* temp =(const EndEffectorChangingStation*) dao->get(name);
 copy(* temp);
} void EndEffectorChangingStation::set(std::string name, EndEffectorChangingStation* obj){
 *dao  = DAO("EndEffectorChangingStation");
 dao->set(name, (IObject) *obj);
}
void EndEffectorChangingStation::copy(const EndEffectorChangingStation &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hadByChangingStation_Workstation = object.hadByChangingStation_Workstation;
}
}