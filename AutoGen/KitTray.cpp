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


 #include "StockKeepingUnit.h"
 #include "LargeBoxWithEmptyKitTrays.h"
 #include "Kit.h"
 #include "DAO.h"

KitTray::KitTray(std::string name) : SolidObject(name){
dao = NULL;
hasKitTray_Sku = NULL;
hasKit_KitTray = NULL;
hadByKitTray_LargeBoxWithEmptyKitTrays = NULL;

}KitTray::~KitTray(){
delete(hasKitTray_Sku);
delete(hasKit_KitTray);
delete(hadByKitTray_LargeBoxWithEmptyKitTrays);
}
std::string KitTray::gethasKitTray_SerialNumber(){
return hasKitTray_SerialNumber;
}
int KitTray::getKitTrayID(){
return KitTrayID;
}
DAO* KitTray::getdao(){
return dao;
}
StockKeepingUnit* KitTray::gethasKitTray_Sku(){
return hasKitTray_Sku;
}
Kit* KitTray::gethasKit_KitTray(){
return hasKit_KitTray;
}
LargeBoxWithEmptyKitTrays* KitTray::gethadByKitTray_LargeBoxWithEmptyKitTrays(){
return hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void KitTray::sethasKitTray_SerialNumber(std::string _hasKitTray_SerialNumber){
this->hasKitTray_SerialNumber= _hasKitTray_SerialNumber;
}
void KitTray::setKitTrayID(int _KitTrayID){
this->KitTrayID= _KitTrayID;
}
void KitTray::setdao(DAO* _dao){
this->dao= _dao;
}
void KitTray::sethasKitTray_Sku(StockKeepingUnit* _hasKitTray_Sku){
this->hasKitTray_Sku= _hasKitTray_Sku;
}
void KitTray::sethasKit_KitTray(Kit* _hasKit_KitTray){
this->hasKit_KitTray= _hasKit_KitTray;
}
void KitTray::sethadByKitTray_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByKitTray_LargeBoxWithEmptyKitTrays){
this->hadByKitTray_LargeBoxWithEmptyKitTrays= _hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void KitTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("KitTray");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void KitTray::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasKitTray_SerialNumber"]="'" + hasKitTray_SerialNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << KitTrayID;
data["KitTrayID"]=ss.str();
if(hasKitTray_Sku!=NULL)
data["hasKitTray_Sku"]=hasKitTray_Sku->getname();
if(hasKit_KitTray!=NULL)
data["hasKit_KitTray"]=hasKit_KitTray->getname();
if(hadByKitTray_LargeBoxWithEmptyKitTrays!=NULL)
data["hadByKitTray_LargeBoxWithEmptyKitTrays"]=hadByKitTray_LargeBoxWithEmptyKitTrays->getname();
dao  = new DAO("KitTray");
dao->set(data);
delete (dao);
}
void KitTray::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
data["hasKitTray_SerialNumber"]="'" + hasKitTray_SerialNumber+ "'";
ss.str("");
ss << temp0->getSolidObjectID();
data["KitTrayID"]=ss.str();
if(hasKitTray_Sku!=NULL)
data["hasKitTray_Sku"]=hasKitTray_Sku->getname();
if(hasKit_KitTray!=NULL)
data["hasKit_KitTray"]=hasKit_KitTray->getname();
if(hadByKitTray_LargeBoxWithEmptyKitTrays!=NULL)
data["hadByKitTray_LargeBoxWithEmptyKitTrays"]=hadByKitTray_LargeBoxWithEmptyKitTrays->getname();
dao  = new DAO("KitTray");
dao->insert(data);
delete (dao);
this->set(name);
}

void KitTray::copy(std::map<std::string,std::string> object){delete(hasKitTray_Sku);
hasKitTray_Sku=NULL;
delete(hasKit_KitTray);
hasKit_KitTray=NULL;
delete(hadByKitTray_LargeBoxWithEmptyKitTrays);
hadByKitTray_LargeBoxWithEmptyKitTrays=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<KitTray*> tmp;
this->hasKitTray_SerialNumber = object["KitTray.hasKitTray_SerialNumber"];
this->name = object["KitTray._NAME"];
this->KitTrayID = std::atof(object["KitTray.KitTrayID"].c_str());
if(this->hasKitTray_Sku== NULL && object["hasKitTray_Sku/StockKeepingUnit._NAME"]!=""){
this->hasKitTray_Sku = new StockKeepingUnit(object["hasKitTray_Sku/StockKeepingUnit._NAME"]);
}
if(this->hasKit_KitTray== NULL && object["hasKit_KitTray/Kit._NAME"]!=""){
this->hasKit_KitTray = new Kit(object["hasKit_KitTray/Kit._NAME"]);
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
