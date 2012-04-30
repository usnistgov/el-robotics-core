#include "StockKeepingUnit.h"

StockKeepingUnit::StockKeepingUnit(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}std::string StockKeepingUnit::gethasSku_EndEffectorRefs[](){
return this->hasSku_EndEffectorRefs[];
}
std::string StockKeepingUnit::gethasSku_Description(){
return this->hasSku_Description;
}
std::string StockKeepingUnit::gethasSku_Id(){
return this->hasSku_Id;
}
float StockKeepingUnit::gethasSku_Weight(){
return this->hasSku_Weight;
}
std::string StockKeepingUnit::getname(){
return this->name;
}
int StockKeepingUnit::getid(){
return this->id;
}
DAO* StockKeepingUnit::getdao(){
return this->dao;
}
ShapeDesign* StockKeepingUnit::gethasSku_Shape(){
return this->hasSku_Shape;
}
void StockKeepingUnit::sethasSku_EndEffectorRefs(std::string _hasSku_EndEffectorRefs[]){
this->hasSku_EndEffectorRefs[]= _hasSku_EndEffectorRefs[];
}
void StockKeepingUnit::sethasSku_Description(std::string _hasSku_Description){
this->hasSku_Description= _hasSku_Description;
}
void StockKeepingUnit::sethasSku_Id(std::string _hasSku_Id){
this->hasSku_Id= _hasSku_Id;
}
void StockKeepingUnit::sethasSku_Weight(float _hasSku_Weight){
this->hasSku_Weight= _hasSku_Weight;
}
void StockKeepingUnit::setname(std::string _name){
this->name= _name;
}
void StockKeepingUnit::setid(int _id){
this->id= _id;
}
void StockKeepingUnit::setdao(DAO* _dao){
this->dao= _dao;
}
void StockKeepingUnit::sethasSku_Shape(ShapeDesign* _hasSku_Shape){
this->hasSku_Shape= _hasSku_Shape;
}
void StockKeepingUnit::get(std::string name){
 *dao  = DAO("StockKeepingUnit");
 const StockKeepingUnit temp = dao->get(name);
 copy(temp);
} void StockKeepingUnit::set(std::string name, StockKeepingUnit* obj){
 *dao  = DAO("StockKeepingUnit");
 dao->set(name, obj);
}
void StockKeepingUnit::copy(StockKeepingUnit const& object){
 if(this != &object){
hasSku_EndEffectorRefs[] = object.hasSku_EndEffectorRefs[];
hasSku_Description = object.hasSku_Description;
hasSku_Id = object.hasSku_Id;
hasSku_Weight = object.hasSku_Weight;
name = object.name;
id = object.id;
dao = object.dao;
hasSku_Shape = object.hasSku_Shape;
}
}