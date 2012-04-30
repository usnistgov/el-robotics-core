#include "LargeContainer.h"

LargeContainer::LargeContainer(std::string name) : BoxyObject(name){
this->name=name;
this->get(this->name);
}std::string LargeContainer::gethasLargeContainer_SkuRef(){
return this->hasLargeContainer_SkuRef;
}
std::string LargeContainer::gethasLargeContainer_SerialNumber(){
return this->hasLargeContainer_SerialNumber;
}
std::string LargeContainer::getname(){
return this->name;
}
int LargeContainer::getid(){
return this->id;
}
DAO* LargeContainer::getdao(){
return this->dao;
}
LargeBoxWithKits* LargeContainer::gethadByLargeContainer_LargeBoxWithKits(){
return this->hadByLargeContainer_LargeBoxWithKits;
}
LargeBoxWithEmptyKitTrays* LargeContainer::gethadByLargeContainer_LargeBoxWithEmptyKitTrays(){
return this->hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeContainer::sethasLargeContainer_SkuRef(std::string _hasLargeContainer_SkuRef){
this->hasLargeContainer_SkuRef= _hasLargeContainer_SkuRef;
}
void LargeContainer::sethasLargeContainer_SerialNumber(std::string _hasLargeContainer_SerialNumber){
this->hasLargeContainer_SerialNumber= _hasLargeContainer_SerialNumber;
}
void LargeContainer::setname(std::string _name){
this->name= _name;
}
void LargeContainer::setid(int _id){
this->id= _id;
}
void LargeContainer::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeContainer::sethadByLargeContainer_LargeBoxWithKits(LargeBoxWithKits* _hadByLargeContainer_LargeBoxWithKits){
this->hadByLargeContainer_LargeBoxWithKits= _hadByLargeContainer_LargeBoxWithKits;
}
void LargeContainer::sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByLargeContainer_LargeBoxWithEmptyKitTrays){
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays= _hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeContainer::get(std::string name){
 *dao  = DAO("LargeContainer");
 const LargeContainer temp = dao->get(name);
 copy(temp);
} void LargeContainer::set(std::string name, LargeContainer* obj){
 *dao  = DAO("LargeContainer");
 dao->set(name, obj);
}
void LargeContainer::copy(LargeContainer const& object){
 if(this != &object){
hasLargeContainer_SkuRef = object.hasLargeContainer_SkuRef;
hasLargeContainer_SerialNumber = object.hasLargeContainer_SerialNumber;
name = object.name;
id = object.id;
dao = object.dao;
hadByLargeContainer_LargeBoxWithKits = object.hadByLargeContainer_LargeBoxWithKits;
hadByLargeContainer_LargeBoxWithEmptyKitTrays = object.hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
}