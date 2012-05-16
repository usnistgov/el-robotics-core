#include "WorkTable.h"

WorkTable::WorkTable(std::string name) : BoxyObject(name){
this->name=name;
this->get(this->name);
}std::string WorkTable::getname(){
return this->name;
}
int WorkTable::getid(){
return this->id;
}
DAO* WorkTable::getdao(){
return this->dao;
}
KittingWorkstation* WorkTable::gethadByWorkTable_Workstation(){
return this->hadByWorkTable_Workstation;
}
void WorkTable::setname(std::string _name){
this->name= _name;
}
void WorkTable::setid(int _id){
this->id= _id;
}
void WorkTable::setdao(DAO* _dao){
this->dao= _dao;
}
void WorkTable::sethadByWorkTable_Workstation(KittingWorkstation* _hadByWorkTable_Workstation){
this->hadByWorkTable_Workstation= _hadByWorkTable_Workstation;
}
void WorkTable::get(std::string name){
 *dao  = DAO("WorkTable");
 const WorkTable* temp =(const WorkTable*) dao->get(name);
 copy(* temp);
} void WorkTable::set(std::string name, WorkTable* obj){
 *dao  = DAO("WorkTable");
 dao->set(name, (IObject) *obj);
}
void WorkTable::copy(const WorkTable &object){
 if(this != &object){
name = object.name;
id = object.id;
dao = object.dao;
hadByWorkTable_Workstation = object.hadByWorkTable_Workstation;
}
}