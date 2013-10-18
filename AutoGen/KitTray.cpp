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

KitTray::KitTray(std::string name) : SkuObject(name){
dao = NULL;
hasKit_KitTray = NULL;
hadByKitTray_LargeBoxWithEmptyKitTrays = NULL;

}KitTray::~KitTray(){
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
void KitTray::sethasKit_KitTray(Kit* _hasKit_KitTray){
this->hasKit_KitTray= _hasKit_KitTray;
}
void KitTray::sethadByKitTray_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByKitTray_LargeBoxWithEmptyKitTrays){
this->hadByKitTray_LargeBoxWithEmptyKitTrays= _hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void KitTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SkuObject");
 temp = dao->get(name);delete (dao);
 SkuObject::copy(temp);
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
SkuObject* temp0 = (SkuObject*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["hasKitTray_SerialNumber"]="'" + hasKitTray_SerialNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << KitTrayID;
data["KitTrayID"]=ss.str();
if(hasKit_KitTray!=NULL)
data["hasKit_KitTray"]="'" +hasKit_KitTray->getname() + "'";
else 
 data["hasKit_KitTray"]="null";
if(hadByKitTray_LargeBoxWithEmptyKitTrays!=NULL)
data["hadByKitTray_LargeBoxWithEmptyKitTrays"]="'" +hadByKitTray_LargeBoxWithEmptyKitTrays->getname() + "'";
else 
 data["hadByKitTray_LargeBoxWithEmptyKitTrays"]="null";
dao  = new DAO("KitTray");
dao->set(data);
delete (dao);
}
void KitTray::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp1 = (SolidObject*) this;
temp1->insert(name);
temp1->get(name);
SkuObject* temp0 = (SkuObject*) this;
temp0->setSkuObjectID(temp1->getSolidObjectID());
temp0->insert(name);
data["hasKitTray_SerialNumber"]="'" + hasKitTray_SerialNumber+ "'";
ss.str("");
ss << temp1->getSolidObjectID();
data["KitTrayID"]=ss.str();
if(hasKit_KitTray!=NULL)
data["hasKit_KitTray"]="'" + hasKit_KitTray->getname() + "'";
if(hadByKitTray_LargeBoxWithEmptyKitTrays!=NULL)
data["hadByKitTray_LargeBoxWithEmptyKitTrays"]="'" + hadByKitTray_LargeBoxWithEmptyKitTrays->getname() + "'";
dao  = new DAO("KitTray");
dao->insert(data);
delete (dao);
this->set(name);
}

void KitTray::copy(std::map<std::string,std::string> object){hasKit_KitTray=NULL;
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
