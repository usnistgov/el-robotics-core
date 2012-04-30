#include "Pose.h"

Pose::Pose(std::string name) : PhysicalLocation(name){
this->name=name;
this->get(this->name);
}std::string Pose::getname(){
return this->name;
}
int Pose::getid(){
return this->id;
}
DAO* Pose::getdao(){
return this->dao;
}
Point* Pose::gethasPose_Point(){
return this->hasPose_Point;
}
RollPitchYaw* Pose::gethasPose_Rpy(){
return this->hasPose_Rpy;
}
void Pose::setname(std::string _name){
this->name= _name;
}
void Pose::setid(int _id){
this->id= _id;
}
void Pose::setdao(DAO* _dao){
this->dao= _dao;
}
void Pose::sethasPose_Point(Point* _hasPose_Point){
this->hasPose_Point= _hasPose_Point;
}
void Pose::sethasPose_Rpy(RollPitchYaw* _hasPose_Rpy){
this->hasPose_Rpy= _hasPose_Rpy;
}
void Pose::get(std::string name){
 *dao  = DAO("Pose");
 const Pose temp = dao->get(name);
 copy(temp);
} void Pose::set(std::string name, Pose* obj){
 *dao  = DAO("Pose");
 dao->set(name, obj);
}
void Pose::copy(Pose const& object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hasPose_Point = object.hasPose_Point;
hasPose_Rpy = object.hasPose_Rpy;
}
}