#include "PartsBin.h"

PartsBin::PartsBin(std::string name) : BoxyObject(name){
this->name=name;
this->get(this->name);
}std::string PartsBin::gethasBin_PartQuantity(){
return this->hasBin_PartQuantity;
}
std::string PartsBin::gethasBin_PartSkuRef(){
return this->hasBin_PartSkuRef;
}
std::string PartsBin::getname(){
return this->name;
}
int PartsBin::getid(){
return this->id;
}
DAO* PartsBin::getdao(){
return this->dao;
}
void PartsBin::sethasBin_PartQuantity(std::string _hasBin_PartQuantity){
this->hasBin_PartQuantity= _hasBin_PartQuantity;
}
void PartsBin::sethasBin_PartSkuRef(std::string _hasBin_PartSkuRef){
this->hasBin_PartSkuRef= _hasBin_PartSkuRef;
}
void PartsBin::setname(std::string _name){
this->name= _name;
}
void PartsBin::setid(int _id){
this->id= _id;
}
void PartsBin::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsBin::get(std::string name){
 *dao  = DAO("PartsBin");
 const PartsBin temp = dao->get(name);
 copy(temp);
} void PartsBin::set(std::string name, PartsBin* obj){
 *dao  = DAO("PartsBin");
 dao->set(name, obj);
}
void PartsBin::copy(PartsBin const& object){
 if(this != &object){
hasBin_PartQuantity = object.hasBin_PartQuantity;
hasBin_PartSkuRef = object.hasBin_PartSkuRef;
name = object.name;
id = object.id;
dao = object.dao;
}
}