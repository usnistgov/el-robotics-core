#include "Point.h"

Point::Point(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}float Point::gethasPoint_X(){
return this->hasPoint_X;
}
float Point::gethasPoint_Y(){
return this->hasPoint_Y;
}
float Point::gethasPoint_Z(){
return this->hasPoint_Z;
}
std::string Point::getname(){
return this->name;
}
int Point::getid(){
return this->id;
}
DAO* Point::getdao(){
return this->dao;
}
void Point::sethasPoint_X(float _hasPoint_X){
this->hasPoint_X= _hasPoint_X;
}
void Point::sethasPoint_Y(float _hasPoint_Y){
this->hasPoint_Y= _hasPoint_Y;
}
void Point::sethasPoint_Z(float _hasPoint_Z){
this->hasPoint_Z= _hasPoint_Z;
}
void Point::setname(std::string _name){
this->name= _name;
}
void Point::setid(int _id){
this->id= _id;
}
void Point::setdao(DAO* _dao){
this->dao= _dao;
}
void Point::get(std::string name){
 *dao  = DAO("Point");
 const Point* temp =(const Point*) dao->get(name);
 copy(* temp);
} void Point::set(std::string name, Point* obj){
 *dao  = DAO("Point");
 dao->set(name, (IObject) *obj);
}
void Point::copy(const Point &object){
 if(this != &object){
hasPoint_X = object.hasPoint_X;
hasPoint_Y = object.hasPoint_Y;
hasPoint_Z = object.hasPoint_Z;
name = object.name;
id = object.id;
dao = object.dao;
}
}