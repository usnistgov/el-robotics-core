#include "DataThing.h"

DataThing::DataThing(std::string name){
this->name=name;
this->get(this->name);
}std::string DataThing::getname(){
return this->name;
}
int DataThing::getid(){
return this->id;
}
DAO* DataThing::getdao(){
return this->dao;
}
void DataThing::setname(std::string _name){
this->name= _name;
}
void DataThing::setid(int _id){
this->id= _id;
}
void DataThing::setdao(DAO* _dao){
this->dao= _dao;
}
void DataThing::get(std::string name){
 *dao  = DAO("DataThing");
 const DataThing temp = dao->get(name);
 copy(temp);
} void DataThing::set(std::string name, DataThing* obj){
 *dao  = DAO("DataThing");
 dao->set(name, obj);
}
void DataThing::copy(DataThing const& object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
}
}