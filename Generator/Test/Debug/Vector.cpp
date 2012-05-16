#include "Vector.h"

Vector::Vector(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}float Vector::gethasVector_K(){
return this->hasVector_K;
}
float Vector::gethasVector_J(){
return this->hasVector_J;
}
float Vector::gethasVector_I(){
return this->hasVector_I;
}
std::string Vector::getname(){
return this->name;
}
int Vector::getid(){
return this->id;
}
DAO* Vector::getdao(){
return this->dao;
}
void Vector::sethasVector_K(float _hasVector_K){
this->hasVector_K= _hasVector_K;
}
void Vector::sethasVector_J(float _hasVector_J){
this->hasVector_J= _hasVector_J;
}
void Vector::sethasVector_I(float _hasVector_I){
this->hasVector_I= _hasVector_I;
}
void Vector::setname(std::string _name){
this->name= _name;
}
void Vector::setid(int _id){
this->id= _id;
}
void Vector::setdao(DAO* _dao){
this->dao= _dao;
}
void Vector::get(std::string name){
 *dao  = DAO("Vector");
 const Vector* temp =(const Vector*) dao->get(name);
 copy(* temp);
} void Vector::set(std::string name, Vector* obj){
 *dao  = DAO("Vector");
 dao->set(name, (IObject) *obj);
}
void Vector::copy(const Vector &object){
 if(this != &object){
hasVector_K = object.hasVector_K;
hasVector_J = object.hasVector_J;
hasVector_I = object.hasVector_I;
name = object.name;
id = object.id;
dao = object.dao;
}
}