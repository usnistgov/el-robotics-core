#include "KitInstance.h"

KitInstance::KitInstance(std::string name) : SolidObject(name){
this->name=name;
}KitInstance::~KitInstance(){
delete(dao);
delete(hadByKitTray_KitInstance);
}
bool KitInstance::getisKitInstance_Finished(){
return this->isKitInstance_Finished;
}
std::string KitInstance::gethasKitInstance_DesignRef(){
return this->hasKitInstance_DesignRef;
}
std::string KitInstance::getname(){
return this->name;
}
int KitInstance::getKitInstanceID(){
return this->KitInstanceID;
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
void KitInstance::setKitInstanceID(int _KitInstanceID){
this->KitInstanceID= _KitInstanceID;
}
void KitInstance::setdao(DAO* _dao){
this->dao= _dao;
}
void KitInstance::sethadByKitTray_KitInstance(KitTray* _hadByKitTray_KitInstance){
this->hadByKitTray_KitInstance= _hadByKitTray_KitInstance;
}
void KitInstance::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("KitInstance");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void KitInstance::set(std::string name){
 dao  = new DAO("KitInstance");
 dao->set(name);
delete (dao);
}

void KitInstance::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->isKitInstance_Finished = std::atof(object["KitInstance.isKitInstance_Finished"].c_str());
this->hasKitInstance_DesignRef = object["KitInstance.hasKitInstance_DesignRef"];
this->name = object["KitInstance._NAME"];
this->KitInstanceID = std::atof(object["KitInstance.KitInstanceID"].c_str());
this->hadByKitTray_KitInstance = new KitTray(" ");
this->hadByKitTray_KitInstance->sethadByKitTray_KitInstance(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,25) == "hadByKitTray_KitInstance/"){
mapTemp[it->first.substr(25,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByKitTray_KitInstance->copy(mapTemp);

}std::vector<std::string> KitInstance::Explode(const std::string & str, char separator )
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
