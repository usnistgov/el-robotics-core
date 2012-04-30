#include "Part.h"

Part::Part(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}std::string Part::gethasPart_SerialNumber(){
return this->hasPart_SerialNumber;
}
std::string Part::gethasPart_SkuRef(){
return this->hasPart_SkuRef;
}
std::string Part::getname(){
return this->name;
}
int Part::getid(){
return this->id;
}
DAO* Part::getdao(){
return this->dao;
}
void Part::sethasPart_SerialNumber(std::string _hasPart_SerialNumber){
this->hasPart_SerialNumber= _hasPart_SerialNumber;
}
void Part::sethasPart_SkuRef(std::string _hasPart_SkuRef){
this->hasPart_SkuRef= _hasPart_SkuRef;
}
void Part::setname(std::string _name){
this->name= _name;
}
void Part::setid(int _id){
this->id= _id;
}
void Part::setdao(DAO* _dao){
this->dao= _dao;
}
void Part::get(std::string name){
 *dao  = DAO("Part");
 const Part temp = dao->get(name);
 copy(temp);
} void Part::set(std::string name, Part* obj){
 *dao  = DAO(Part);
 dao->set(name, obj);
}
void Part::copy(Part const& object){
 if(this != &object){
hasPart_SerialNumber = object.hasPart_SerialNumber;
hasPart_SkuRef = object.hasPart_SkuRef;
name = object.name;
id = object.id;
dao = object.dao;
}
}