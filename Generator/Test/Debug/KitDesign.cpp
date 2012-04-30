#include "KitDesign.h"

KitDesign::KitDesign(std::string name) : DataThing(name){
this->name=name;
this->get(this->name);
}std::string KitDesign::gethasKitDesign_Id(){
return this->hasKitDesign_Id;
}
std::string KitDesign::gethasKitDesign_KitTraySkuRef(){
return this->hasKitDesign_KitTraySkuRef;
}
std::string KitDesign::getname(){
return this->name;
}
int KitDesign::getid(){
return this->id;
}
DAO* KitDesign::getdao(){
return this->dao;
}
void KitDesign::sethasKitDesign_Id(std::string _hasKitDesign_Id){
this->hasKitDesign_Id= _hasKitDesign_Id;
}
void KitDesign::sethasKitDesign_KitTraySkuRef(std::string _hasKitDesign_KitTraySkuRef){
this->hasKitDesign_KitTraySkuRef= _hasKitDesign_KitTraySkuRef;
}
void KitDesign::setname(std::string _name){
this->name= _name;
}
void KitDesign::setid(int _id){
this->id= _id;
}
void KitDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void KitDesign::get(std::string name){
 *dao  = DAO("KitDesign");
 const KitDesign temp = dao->get(name);
 copy(temp);
} void KitDesign::set(std::string name, KitDesign* obj){
 *dao  = DAO(KitDesign);
 dao->set(name, obj);
}
void KitDesign::copy(KitDesign const& object){
 if(this != &object){
hasKitDesign_Id = object.hasKitDesign_Id;
hasKitDesign_KitTraySkuRef = object.hasKitDesign_KitTraySkuRef;
name = object.name;
id = object.id;
dao = object.dao;
}
}