#include "Robot.h"

Robot::Robot(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string Robot::gethasRobot_Id(){
return this->hasRobot_Id;
}
float Robot::gethasRobot_MaximumLoadWeight(){
return this->hasRobot_MaximumLoadWeight;
}
std::string Robot::gethasRobot_Description(){
return this->hasRobot_Description;
}
std::string Robot::getname(){
return this->name;
}
int Robot::getid(){
return this->id;
}
DAO* Robot::getdao(){
return this->dao;
}
KittingWorkstation* Robot::gethadByRobot_Workstation(){
return this->hadByRobot_Workstation;
}
BoxVolume* Robot::gethasRobot_WorkVolume(){
return this->hasRobot_WorkVolume;
}
void Robot::sethasRobot_Id(std::string _hasRobot_Id){
this->hasRobot_Id= _hasRobot_Id;
}
void Robot::sethasRobot_MaximumLoadWeight(float _hasRobot_MaximumLoadWeight){
this->hasRobot_MaximumLoadWeight= _hasRobot_MaximumLoadWeight;
}
void Robot::sethasRobot_Description(std::string _hasRobot_Description){
this->hasRobot_Description= _hasRobot_Description;
}
void Robot::setname(std::string _name){
this->name= _name;
}
void Robot::setid(int _id){
this->id= _id;
}
void Robot::setdao(DAO* _dao){
this->dao= _dao;
}
void Robot::sethadByRobot_Workstation(KittingWorkstation* _hadByRobot_Workstation){
this->hadByRobot_Workstation= _hadByRobot_Workstation;
}
void Robot::sethasRobot_WorkVolume(BoxVolume* _hasRobot_WorkVolume){
this->hasRobot_WorkVolume= _hasRobot_WorkVolume;
}
void Robot::get(std::string name){
 *dao  = DAO("Robot");
 const Robot temp = dao->get(name);
 copy(temp);
} void Robot::set(std::string name, Robot* obj){
 *dao  = DAO("Robot");
 dao->set(name, obj);
}
void Robot::copy(Robot const& object){
 if(this != &object){
hasRobot_Id = object.hasRobot_Id;
hasRobot_MaximumLoadWeight = object.hasRobot_MaximumLoadWeight;
hasRobot_Description = object.hasRobot_Description;
name = object.name;
id = object.id;
dao = object.dao;
hadByRobot_Workstation = object.hadByRobot_Workstation;
hasRobot_WorkVolume = object.hasRobot_WorkVolume;
}
}