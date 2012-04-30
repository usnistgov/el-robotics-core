#include "KittingWorkstation.h"

KittingWorkstation::KittingWorkstation(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string KittingWorkstation::gethasWorkstation_LengthUnit(){
return this->hasWorkstation_LengthUnit;
}
std::string KittingWorkstation::gethasWorkstation_WeightUnit(){
return this->hasWorkstation_WeightUnit;
}
std::string KittingWorkstation::gethasWorkstation_AngleUnit(){
return this->hasWorkstation_AngleUnit;
}
std::string KittingWorkstation::getname(){
return this->name;
}
int KittingWorkstation::getid(){
return this->id;
}
DAO* KittingWorkstation::getdao(){
return this->dao;
}
EndEffectorChangingStation* KittingWorkstation::gethadByChangingStation_Workstation(){
return this->hadByChangingStation_Workstation;
}
BoxVolume* KittingWorkstation::gethasWorkstation_OtherObstacles(){
return this->hasWorkstation_OtherObstacles;
}
WorkTable* KittingWorkstation::gethadByWorkTable_Workstation(){
return this->hadByWorkTable_Workstation;
}
Robot* KittingWorkstation::gethadByRobot_Workstation(){
return this->hadByRobot_Workstation;
}
void KittingWorkstation::sethasWorkstation_LengthUnit(std::string _hasWorkstation_LengthUnit){
this->hasWorkstation_LengthUnit= _hasWorkstation_LengthUnit;
}
void KittingWorkstation::sethasWorkstation_WeightUnit(std::string _hasWorkstation_WeightUnit){
this->hasWorkstation_WeightUnit= _hasWorkstation_WeightUnit;
}
void KittingWorkstation::sethasWorkstation_AngleUnit(std::string _hasWorkstation_AngleUnit){
this->hasWorkstation_AngleUnit= _hasWorkstation_AngleUnit;
}
void KittingWorkstation::setname(std::string _name){
this->name= _name;
}
void KittingWorkstation::setid(int _id){
this->id= _id;
}
void KittingWorkstation::setdao(DAO* _dao){
this->dao= _dao;
}
void KittingWorkstation::sethadByChangingStation_Workstation(EndEffectorChangingStation* _hadByChangingStation_Workstation){
this->hadByChangingStation_Workstation= _hadByChangingStation_Workstation;
}
void KittingWorkstation::sethasWorkstation_OtherObstacles(BoxVolume* _hasWorkstation_OtherObstacles){
this->hasWorkstation_OtherObstacles= _hasWorkstation_OtherObstacles;
}
void KittingWorkstation::sethadByWorkTable_Workstation(WorkTable* _hadByWorkTable_Workstation){
this->hadByWorkTable_Workstation= _hadByWorkTable_Workstation;
}
void KittingWorkstation::sethadByRobot_Workstation(Robot* _hadByRobot_Workstation){
this->hadByRobot_Workstation= _hadByRobot_Workstation;
}
void KittingWorkstation::get(std::string name){
 *dao  = DAO("KittingWorkstation");
 const KittingWorkstation temp = dao->get(name);
 copy(temp);
} void KittingWorkstation::set(std::string name, KittingWorkstation* obj){
 *dao  = DAO("KittingWorkstation");
 dao->set(name, obj);
}
void KittingWorkstation::copy(KittingWorkstation const& object){
 if(this != &object){
hasWorkstation_LengthUnit = object.hasWorkstation_LengthUnit;
hasWorkstation_WeightUnit = object.hasWorkstation_WeightUnit;
hasWorkstation_AngleUnit = object.hasWorkstation_AngleUnit;
name = object.name;
id = object.id;
dao = object.dao;
hadByChangingStation_Workstation = object.hadByChangingStation_Workstation;
hasWorkstation_OtherObstacles = object.hasWorkstation_OtherObstacles;
hadByWorkTable_Workstation = object.hadByWorkTable_Workstation;
hadByRobot_Workstation = object.hadByRobot_Workstation;
}
}