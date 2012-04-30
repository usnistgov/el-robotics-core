#include "BoxVolume.h"

BoxVolume::BoxVolume(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}std::string BoxVolume::getname(){
return this->name;
}
int BoxVolume::getid(){
return this->id;
}
DAO* BoxVolume::getdao(){
return this->dao;
}
Point* BoxVolume::gethasBoxVolume_MaximumPoint(){
return this->hasBoxVolume_MaximumPoint;
}
Point* BoxVolume::gethasBoxVolume_MinimumPoint(){
return this->hasBoxVolume_MinimumPoint;
}
void BoxVolume::setname(std::string _name){
this->name= _name;
}
void BoxVolume::setid(int _id){
this->id= _id;
}
void BoxVolume::setdao(DAO* _dao){
this->dao= _dao;
}
void BoxVolume::sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint){
this->hasBoxVolume_MaximumPoint= _hasBoxVolume_MaximumPoint;
}
void BoxVolume::sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint){
this->hasBoxVolume_MinimumPoint= _hasBoxVolume_MinimumPoint;
}
void BoxVolume::get(std::string name){
 *dao  = DAO("BoxVolume");
 const BoxVolume temp = dao->get(name);
 copy(temp);
} void BoxVolume::set(std::string name, BoxVolume* obj){
 *dao  = DAO(BoxVolume);
 dao->set(name, obj);
}
void BoxVolume::copy(BoxVolume const& object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hasBoxVolume_MaximumPoint = object.hasBoxVolume_MaximumPoint;
hasBoxVolume_MinimumPoint = object.hasBoxVolume_MinimumPoint;
}
}