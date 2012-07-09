/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "KitTray.h"


 #include "LargeBoxWithEmptyKitTrays.h"
 #include "Kit.h"
 #include "DAO.h"

KitTray::KitTray(std::string name) : BoxyObject(name){
this->name=name;dao = NULL;
hasKit_Tray = NULL;
hadByKitTray_LargeBoxWithEmptyKitTrays = NULL;

}KitTray::~KitTray(){
delete(dao);
delete(hasKit_Tray);
delete(hadByKitTray_LargeBoxWithEmptyKitTrays);
}
std::string KitTray::gethasKitTray_SkuRef(){
return hasKitTray_SkuRef;
}
std::string KitTray::gethasKitTray_SerialNumber(){
return hasKitTray_SerialNumber;
}
std::string KitTray::getname(){
return name;
}
int KitTray::getKitTrayID(){
return KitTrayID;
}
DAO* KitTray::getdao(){
return dao;
}
Kit* KitTray::gethasKit_Tray(){
return hasKit_Tray;
}
LargeBoxWithEmptyKitTrays* KitTray::gethadByKitTray_LargeBoxWithEmptyKitTrays(){
return hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void KitTray::sethasKitTray_SkuRef(std::string _hasKitTray_SkuRef){
this->hasKitTray_SkuRef= _hasKitTray_SkuRef;
}
void KitTray::sethasKitTray_SerialNumber(std::string _hasKitTray_SerialNumber){
this->hasKitTray_SerialNumber= _hasKitTray_SerialNumber;
}
void KitTray::setdao(DAO* _dao){
this->dao= _dao;
}
void KitTray::sethasKit_Tray(Kit* _hasKit_Tray){
this->hasKit_Tray= _hasKit_Tray;
}
void KitTray::sethadByKitTray_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByKitTray_LargeBoxWithEmptyKitTrays){
this->hadByKitTray_LargeBoxWithEmptyKitTrays= _hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void KitTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);delete (dao);
 BoxyObject::copy(temp);
dao  = new DAO("KitTray");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void KitTray::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
BoxyObject* temp = (BoxyObject*) this;
temp->set(name);
data["hasKitTray_SkuRef"]=hasKitTray_SkuRef;
data["hasKitTray_SerialNumber"]=hasKitTray_SerialNumber;
data["name"]=name;
ss.str("");
ss << KitTrayID;
data["KitTrayID"]=ss.str();
if(hasKit_Tray!=NULL)
data["hasKit_Tray"]=hasKit_Tray->getname();
if(hadByKitTray_LargeBoxWithEmptyKitTrays!=NULL)
data["hadByKitTray_LargeBoxWithEmptyKitTrays"]=hadByKitTray_LargeBoxWithEmptyKitTrays->getname();
dao  = new DAO("KitTray");
dao->set(data);
delete (dao);
}

void KitTray::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<KitTray*> tmp;
this->hasKitTray_SkuRef = object["KitTray.hasKitTray_SkuRef"];
this->hasKitTray_SerialNumber = object["KitTray.hasKitTray_SerialNumber"];
this->name = object["KitTray._NAME"];
this->KitTrayID = std::atof(object["KitTray.KitTrayID"].c_str());
if(this->hasKit_Tray== NULL && object["hasKit_Tray/Kit._NAME"]!=""){
this->hasKit_Tray = new Kit(object["hasKit_Tray/Kit._NAME"]);
}
if(this->hadByKitTray_LargeBoxWithEmptyKitTrays== NULL && object["hadByKitTray_LargeBoxWithEmptyKitTrays/LargeBoxWithEmptyKitTrays._NAME"]!=""){
this->hadByKitTray_LargeBoxWithEmptyKitTrays = new LargeBoxWithEmptyKitTrays(object["hadByKitTray_LargeBoxWithEmptyKitTrays/LargeBoxWithEmptyKitTrays._NAME"]);
}

}std::vector<std::string> KitTray::Explode(const std::string & str, char separator )
{
   std::vector< std::string > result;
   std::size_t pos1 = 0;
   std::size_t pos2 = 0;
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
