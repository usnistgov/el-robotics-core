#include "ShapeDesign.h"

ShapeDesign::ShapeDesign(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}std::string ShapeDesign::gethasShapeDesign_Description(){
return this->hasShapeDesign_Description;
}
std::string ShapeDesign::getname(){
return this->name;
}
int ShapeDesign::getid(){
return this->id;
}
DAO* ShapeDesign::getdao(){
return this->dao;
}
void ShapeDesign::sethasShapeDesign_Description(std::string _hasShapeDesign_Description){
this->hasShapeDesign_Description= _hasShapeDesign_Description;
}
void ShapeDesign::setname(std::string _name){
this->name= _name;
}
void ShapeDesign::setid(int _id){
this->id= _id;
}
void ShapeDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void ShapeDesign::get(std::string name){
 *dao  = DAO("ShapeDesign");
 const ShapeDesign temp = dao->get(name);
 copy(temp);
} void ShapeDesign::set(std::string name, ShapeDesign* obj){
 *dao  = DAO("ShapeDesign");
 dao->set(name, obj);
}
void ShapeDesign::copy(ShapeDesign const& object){
 if(this != &object){
hasShapeDesign_Description = object.hasShapeDesign_Description;
name = object.name;
id = object.id;
dao = object.dao;
}
}