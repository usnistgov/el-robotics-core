#include "BoxyObject.h"

BoxyObject::BoxyObject(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}float BoxyObject::gethasBox_Width(){
return this->hasBox_Width;
}
float BoxyObject::gethasBox_Height(){
return this->hasBox_Height;
}
float BoxyObject::gethasBox_Length(){
return this->hasBox_Length;
}
std::string BoxyObject::getname(){
return this->name;
}
int BoxyObject::getid(){
return this->id;
}
DAO* BoxyObject::getdao(){
return this->dao;
}
void BoxyObject::sethasBox_Width(float _hasBox_Width){
this->hasBox_Width= _hasBox_Width;
}
void BoxyObject::sethasBox_Height(float _hasBox_Height){
this->hasBox_Height= _hasBox_Height;
}
void BoxyObject::sethasBox_Length(float _hasBox_Length){
this->hasBox_Length= _hasBox_Length;
}
void BoxyObject::setname(std::string _name){
this->name= _name;
}
void BoxyObject::setid(int _id){
this->id= _id;
}
void BoxyObject::setdao(DAO* _dao){
this->dao= _dao;
}
void BoxyObject::get(std::string name){
 *dao  = DAO("BoxyObject");
 const BoxyObject temp = dao->get(name);
 copy(temp);
} void BoxyObject::set(std::string name, BoxyObject* obj){
 *dao  = DAO(BoxyObject);
 dao->set(name, obj);
}
void BoxyObject::copy(BoxyObject const& object){
 if(this != &object){
hasBox_Width = object.hasBox_Width;
hasBox_Height = object.hasBox_Height;
hasBox_Length = object.hasBox_Length;
name = object.name;
id = object.id;
dao = object.dao;
}
}