#include "RollPitchYaw.h"

RollPitchYaw::RollPitchYaw(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}float RollPitchYaw::gethasRpy_Roll(){
return this->hasRpy_Roll;
}
float RollPitchYaw::gethasRpy_Pitch(){
return this->hasRpy_Pitch;
}
float RollPitchYaw::gethasRpy_Yaw(){
return this->hasRpy_Yaw;
}
std::string RollPitchYaw::getname(){
return this->name;
}
int RollPitchYaw::getid(){
return this->id;
}
DAO* RollPitchYaw::getdao(){
return this->dao;
}
void RollPitchYaw::sethasRpy_Roll(float _hasRpy_Roll){
this->hasRpy_Roll= _hasRpy_Roll;
}
void RollPitchYaw::sethasRpy_Pitch(float _hasRpy_Pitch){
this->hasRpy_Pitch= _hasRpy_Pitch;
}
void RollPitchYaw::sethasRpy_Yaw(float _hasRpy_Yaw){
this->hasRpy_Yaw= _hasRpy_Yaw;
}
void RollPitchYaw::setname(std::string _name){
this->name= _name;
}
void RollPitchYaw::setid(int _id){
this->id= _id;
}
void RollPitchYaw::setdao(DAO* _dao){
this->dao= _dao;
}
void RollPitchYaw::get(std::string name){
 *dao  = DAO("RollPitchYaw");
 const RollPitchYaw temp = dao->get(name);
 copy(temp);
} void RollPitchYaw::set(std::string name, RollPitchYaw* obj){
 *dao  = DAO(RollPitchYaw);
 dao->set(name, obj);
}
void RollPitchYaw::copy(RollPitchYaw const& object){
 if(this != &object){
hasRpy_Roll = object.hasRpy_Roll;
hasRpy_Pitch = object.hasRpy_Pitch;
hasRpy_Yaw = object.hasRpy_Yaw;
name = object.name;
id = object.id;
dao = object.dao;
}
}