#include "KitInstance.h"

KitInstance::KitInstance(std::string name) : SolidObject(name){
this->name=name;
this->get(this->name);
}bool KitInstance::getisKitInstance_Finished(){
return this->isKitInstance_Finished;
}
std::string KitInstance::gethasKitInstance_DesignRef(){
return this->hasKitInstance_DesignRef;
}
std::string KitInstance::getname(){
return this->name;
}
int KitInstance::getid(){
return this->id;
}
DAO* KitInstance::getdao(){
return this->dao;
}
KitTray* KitInstance::gethadByKitTray_KitInstance(){
return this->hadByKitTray_KitInstance;
}
void KitInstance::setisKitInstance_Finished(bool _isKitInstance_Finished){
this->isKitInstance_Finished= _isKitInstance_Finished;
}
void KitInstance::sethasKitInstance_DesignRef(std::string _hasKitInstance_DesignRef){
this->hasKitInstance_DesignRef= _hasKitInstance_DesignRef;
}
void KitInstance::setname(std::string _name){
this->name= _name;
}
void KitInstance::setid(int _id){
this->id= _id;
}
void KitInstance::setdao(DAO* _dao){
this->dao= _dao;
}
void KitInstance::sethadByKitTray_KitInstance(KitTray* _hadByKitTray_KitInstance){
this->hadByKitTray_KitInstance= _hadByKitTray_KitInstance;
}
void KitInstance::get(std::string name){
 *dao  = DAO("KitInstance");
 const KitInstance* temp =(const KitInstance*) dao->get(name);
 copy(* temp);
} void KitInstance::set(std::string name, KitInstance* obj){
 *dao  = DAO("KitInstance");
 dao->set(name, (IObject) *obj);
}
void KitInstance::copy(const KitInstance &object){
 if(this != &object){
isKitInstance_Finished = object.isKitInstance_Finished;
hasKitInstance_DesignRef = object.hasKitInstance_DesignRef;
name = object.name;
id = object.id;
dao = object.dao;
hadByKitTray_KitInstance = object.hadByKitTray_KitInstance;
}
}