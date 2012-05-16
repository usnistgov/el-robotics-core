#include "KitTray.h"

KitTray::KitTray(std::string name) : BoxyObject(name){
this->name=name;
}KitTray::~KitTray(){
delete(dao);
delete(hadByKitTray_KitInstance);
}
std::string KitTray::gethasKitTray_SerialNumber(){
return this->hasKitTray_SerialNumber;
}
std::string KitTray::gethasKitTray_SkuRef(){
return this->hasKitTray_SkuRef;
}
std::string KitTray::getname(){
return this->name;
}
int KitTray::getKitTrayID(){
return this->KitTrayID;
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
void KitTray::setKitTrayID(int _KitTrayID){
this->KitTrayID= _KitTrayID;
}
void KitTray::setdao(DAO* _dao){
this->dao= _dao;
}
void KitTray::sethadByKitTray_KitInstance(KitInstance* _hadByKitTray_KitInstance){
this->hadByKitTray_KitInstance= _hadByKitTray_KitInstance;
}
void KitTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);
 BoxyObject::copy(temp);
delete (dao);
dao  = new DAO("KitTray");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void KitTray::set(std::string name){
 dao  = new DAO("KitTray");
 dao->set(name);
delete (dao);
}

void KitTray::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasKitTray_SerialNumber = object["KitTray.hasKitTray_SerialNumber"];
this->hasKitTray_SkuRef = object["KitTray.hasKitTray_SkuRef"];
this->name = object["KitTray._NAME"];
this->KitTrayID = std::atof(object["KitTray.KitTrayID"].c_str());
this->hadByKitTray_KitInstance = new KitInstance(" ");
this->hadByKitTray_KitInstance->sethadByKitTray_KitInstance(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,25) == "hadByKitTray_KitInstance/"){
mapTemp[it->first.substr(25,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByKitTray_KitInstance->copy(mapTemp);

}std::vector<std::string> KitTray::Explode(const std::string & str, char separator )
{
   std::vector< std::string > result;
   size_t pos1 = 0;
   size_t pos2 = 0;
   while ( pos2 != str.npos )
   {
      pos2 = str.find(separator, pos1);
      if ( pos2 != str.npos )
      {
         if ( pos2 > pos1 )
            result.push_back( str.substr(pos1, pos2-pos1) );
         pos1 = pos2+1;
      }
   }
   result.push_back( str.substr(pos1, str.size()-pos1) );
   return result;
}
