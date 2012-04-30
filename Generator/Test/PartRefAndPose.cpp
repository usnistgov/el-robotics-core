#include "PartRefAndPose.h"

PartRefAndPose::PartRefAndPose(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}std::string PartRefAndPose::gethasPartRefAndPose_Ref(){
return this->hasPartRefAndPose_Ref;
}
std::string PartRefAndPose::getname(){
return this->name;
}
int PartRefAndPose::getid(){
return this->id;
}
DAO* PartRefAndPose::getdao(){
return this->dao;
}
RollPitchYaw* PartRefAndPose::gethasPartRefAndPose_Rpy(){
return this->hasPartRefAndPose_Rpy;
}
Point* PartRefAndPose::gethasPartRefAndPose_Point(){
return this->hasPartRefAndPose_Point;
}
void PartRefAndPose::sethasPartRefAndPose_Ref(std::string _hasPartRefAndPose_Ref){
this->hasPartRefAndPose_Ref= _hasPartRefAndPose_Ref;
}
void PartRefAndPose::setname(std::string _name){
this->name= _name;
}
void PartRefAndPose::setid(int _id){
this->id= _id;
}
void PartRefAndPose::setdao(DAO* _dao){
this->dao= _dao;
}
void PartRefAndPose::sethasPartRefAndPose_Rpy(RollPitchYaw* _hasPartRefAndPose_Rpy){
this->hasPartRefAndPose_Rpy= _hasPartRefAndPose_Rpy;
}
void PartRefAndPose::sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point){
this->hasPartRefAndPose_Point= _hasPartRefAndPose_Point;
}
void PartRefAndPose::get(std::string name){
 *dao  = DAO("PartRefAndPose");
 const PartRefAndPose temp = dao->get(name);
 copy(temp);
} void PartRefAndPose::set(std::string name, PartRefAndPose* obj){
 *dao  = DAO("PartRefAndPose");
 dao->set(name, obj);
}
void PartRefAndPose::copy(PartRefAndPose const& object){
 if(this != &object){
hasPartRefAndPose_Ref = object.hasPartRefAndPose_Ref;
name = object.name;
id = object.id;
dao = object.dao;
hasPartRefAndPose_Rpy = object.hasPartRefAndPose_Rpy;
hasPartRefAndPose_Point = object.hasPartRefAndPose_Point;
}
}