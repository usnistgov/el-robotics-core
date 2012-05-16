#include "LargeBoxWithEmptyKitTrays.h"

LargeBoxWithEmptyKitTrays::LargeBoxWithEmptyKitTrays(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string LargeBoxWithEmptyKitTrays::getname(){
return this->name;
}
int LargeBoxWithEmptyKitTrays::getid(){
return this->id;
}
DAO* LargeBoxWithEmptyKitTrays::getdao(){
return this->dao;
}
LargeContainer* LargeBoxWithEmptyKitTrays::gethadByLargeContainer_LargeBoxWithEmptyKitTrays(){
return this->hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeBoxWithEmptyKitTrays::setname(std::string _name){
this->name= _name;
}
void LargeBoxWithEmptyKitTrays::setid(int _id){
this->id= _id;
}
void LargeBoxWithEmptyKitTrays::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeBoxWithEmptyKitTrays::sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeContainer* _hadByLargeContainer_LargeBoxWithEmptyKitTrays){
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays= _hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeBoxWithEmptyKitTrays::get(std::string name){
 *dao  = DAO("LargeBoxWithEmptyKitTrays");
 const LargeBoxWithEmptyKitTrays* temp =(const LargeBoxWithEmptyKitTrays*) dao->get(name);
 copy(* temp);
} void LargeBoxWithEmptyKitTrays::set(std::string name, LargeBoxWithEmptyKitTrays* obj){
 *dao  = DAO("LargeBoxWithEmptyKitTrays");
 dao->set(name, (IObject) *obj);
}
void LargeBoxWithEmptyKitTrays::copy(const LargeBoxWithEmptyKitTrays &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hadByLargeContainer_LargeBoxWithEmptyKitTrays = object.hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
}