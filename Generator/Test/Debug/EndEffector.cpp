#include "EndEffector.h"

EndEffector::EndEffector(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}float EndEffector::gethasEndEffector_Weight(){
return this->hasEndEffector_Weight;
}
float EndEffector::gethasEffector_MaximumLoadWeight(){
return this->hasEffector_MaximumLoadWeight;
}
std::string EndEffector::gethasEndEffector_Description(){
return this->hasEndEffector_Description;
}
std::string EndEffector::gethasEndEffector_Id(){
return this->hasEndEffector_Id;
}
std::string EndEffector::getname(){
return this->name;
}
int EndEffector::getid(){
return this->id;
}
DAO* EndEffector::getdao(){
return this->dao;
}
void EndEffector::sethasEndEffector_Weight(float _hasEndEffector_Weight){
this->hasEndEffector_Weight= _hasEndEffector_Weight;
}
void EndEffector::sethasEffector_MaximumLoadWeight(float _hasEffector_MaximumLoadWeight){
this->hasEffector_MaximumLoadWeight= _hasEffector_MaximumLoadWeight;
}
void EndEffector::sethasEndEffector_Description(std::string _hasEndEffector_Description){
this->hasEndEffector_Description= _hasEndEffector_Description;
}
void EndEffector::sethasEndEffector_Id(std::string _hasEndEffector_Id){
this->hasEndEffector_Id= _hasEndEffector_Id;
}
void EndEffector::setname(std::string _name){
this->name= _name;
}
void EndEffector::setid(int _id){
this->id= _id;
}
void EndEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffector::get(std::string name){
 *dao  = DAO("EndEffector");
 const EndEffector temp = dao->get(name);
 copy(temp);
} void EndEffector::set(std::string name, EndEffector* obj){
 *dao  = DAO(EndEffector);
 dao->set(name, obj);
}
void EndEffector::copy(EndEffector const& object){
 if(this != &object){
hasEndEffector_Weight = object.hasEndEffector_Weight;
hasEffector_MaximumLoadWeight = object.hasEffector_MaximumLoadWeight;
hasEndEffector_Description = object.hasEndEffector_Description;
hasEndEffector_Id = object.hasEndEffector_Id;
name = object.name;
id = object.id;
dao = object.dao;
}
}