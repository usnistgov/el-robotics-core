#include "KitTray.h"

KitTray::KitTray(std::string name) : BoxyObject(name){
this->name=name;
this->get(this->name);
}std::string KitTray::gethasKitTray_SerialNumber(){
return this->hasKitTray_SerialNumber;
}
std::string KitTray::gethasKitTray_SkuRef(){
return this->hasKitTray_SkuRef;
}
std::string KitTray::getname(){
return this->name;
}
int KitTray::getid(){
return this->id;
}
DAO* KitTray::getdao(){
return this->dao;
}
KitInstance* KitTray::gethadByKitTray_KitInstance(){
return this->hadByKitTray_KitInstance;
}
void KitTray::sethasKitTray_SerialNumber(std::string _hasKitTray_SerialNumber){
this->hasKitTray_SerialNumber= _hasKitTray_SerialNumber;
}
void KitTray::sethasKitTray_SkuRef(std::string _hasKitTray_SkuRef){
this->hasKitTray_SkuRef= _hasKitTray_SkuRef;
}
void KitTray::setname(std::string _name){
this->name= _name;
}
void KitTray::setid(int _id){
this->id= _id;
}
void KitTray::setdao(DAO* _dao){
this->dao= _dao;
}
void KitTray::sethadByKitTray_KitInstance(KitInstance* _hadByKitTray_KitInstance){
this->hadByKitTray_KitInstance= _hadByKitTray_KitInstance;
}
void KitTray::get(std::string name){
 *dao  = DAO("KitTray");
 const KitTray* temp =(const KitTray*) dao->get(name);
 copy(* temp);
} void KitTray::set(std::string name, KitTray* obj){
 *dao  = DAO("KitTray");
 dao->set(name, (IObject) *obj);
}
void KitTray::copy(const KitTray &object){
 if(this != &object){
hasKitTray_SerialNumber = object.hasKitTray_SerialNumber;
hasKitTray_SkuRef = object.hasKitTray_SkuRef;
name = object.name;
id = object.id;
dao = object.dao;
hadByKitTray_KitInstance = object.hadByKitTray_KitInstance;
}
}