#include "LargeBoxWithKits.h"

LargeBoxWithKits::LargeBoxWithKits(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string LargeBoxWithKits::gethasLargeBoxWithKits_Capacity(){
return this->hasLargeBoxWithKits_Capacity;
}
std::string LargeBoxWithKits::gethasLargeBoxWithKits_KitDesignRef(){
return this->hasLargeBoxWithKits_KitDesignRef;
}
std::string LargeBoxWithKits::getname(){
return this->name;
}
int LargeBoxWithKits::getid(){
return this->id;
}
DAO* LargeBoxWithKits::getdao(){
return this->dao;
}
LargeContainer* LargeBoxWithKits::gethadByLargeContainer_LargeBoxWithKits(){
return this->hadByLargeContainer_LargeBoxWithKits;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_Capacity(std::string _hasLargeBoxWithKits_Capacity){
this->hasLargeBoxWithKits_Capacity= _hasLargeBoxWithKits_Capacity;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_KitDesignRef(std::string _hasLargeBoxWithKits_KitDesignRef){
this->hasLargeBoxWithKits_KitDesignRef= _hasLargeBoxWithKits_KitDesignRef;
}
void LargeBoxWithKits::setname(std::string _name){
this->name= _name;
}
void LargeBoxWithKits::setid(int _id){
this->id= _id;
}
void LargeBoxWithKits::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeBoxWithKits::sethadByLargeContainer_LargeBoxWithKits(LargeContainer* _hadByLargeContainer_LargeBoxWithKits){
this->hadByLargeContainer_LargeBoxWithKits= _hadByLargeContainer_LargeBoxWithKits;
}
void LargeBoxWithKits::get(std::string name){
 *dao  = DAO("LargeBoxWithKits");
 const LargeBoxWithKits* temp =(const LargeBoxWithKits*) dao->get(name);
 copy(* temp);
} void LargeBoxWithKits::set(std::string name, LargeBoxWithKits* obj){
 *dao  = DAO("LargeBoxWithKits");
 dao->set(name, (IObject) *obj);
}
void LargeBoxWithKits::copy(const LargeBoxWithKits &object){
 if(this != &object){
hasLargeBoxWithKits_Capacity = object.hasLargeBoxWithKits_Capacity;
hasLargeBoxWithKits_KitDesignRef = object.hasLargeBoxWithKits_KitDesignRef;
name = object.name;
id = object.id;
dao = object.dao;
hadByLargeContainer_LargeBoxWithKits = object.hadByLargeContainer_LargeBoxWithKits;
}
}