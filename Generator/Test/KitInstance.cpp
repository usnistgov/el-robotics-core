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

#include "KitInstance.h"


 #include "LargeBoxWithKits.h"
 #include "KitTray.h"
 #include "DAO.h"
 #include "Part.h"

KitInstance::KitInstance(std::string name) : SolidObject(name){
this->name=name;dao = NULL;
hasKitInstance_Tray = NULL;
hadByKitInstance_LargeBoxWithKits = NULL;

}KitInstance::~KitInstance(){
delete(dao);
delete(hasKitInstance_Tray);
delete(hadByKitInstance_LargeBoxWithKits);
for(std::size_t i = 0; i < hadByPart_KitInstance.size(); i++)
delete(hadByPart_KitInstance[i]);
}
bool KitInstance::getisKitInstance_Finished(){
return isKitInstance_Finished;
}
std::string KitInstance::gethasKitInstance_DesignRef(){
return hasKitInstance_DesignRef;
}
std::string KitInstance::getname(){
return name;
}
int KitInstance::getKitInstanceID(){
return KitInstanceID;
}
DAO* KitInstance::getdao(){
return dao;
}
std::vector<Part*>* KitInstance::gethadByPart_KitInstance(){
return &hadByPart_KitInstance;
}
KitTray* KitInstance::gethasKitInstance_Tray(){
return hasKitInstance_Tray;
}
LargeBoxWithKits* KitInstance::gethadByKitInstance_LargeBoxWithKits(){
return hadByKitInstance_LargeBoxWithKits;
}
void KitInstance::setisKitInstance_Finished(bool _isKitInstance_Finished){
this->isKitInstance_Finished= _isKitInstance_Finished;
}
void KitInstance::sethasKitInstance_DesignRef(std::string _hasKitInstance_DesignRef){
this->hasKitInstance_DesignRef= _hasKitInstance_DesignRef;
}
void KitInstance::setdao(DAO* _dao){
this->dao= _dao;
}
void KitInstance::sethadByPart_KitInstance(std::vector<Part*> _hadByPart_KitInstance){
this->hadByPart_KitInstance= _hadByPart_KitInstance;
}
void KitInstance::sethasKitInstance_Tray(KitTray* _hasKitInstance_Tray){
this->hasKitInstance_Tray= _hasKitInstance_Tray;
}
void KitInstance::sethadByKitInstance_LargeBoxWithKits(LargeBoxWithKits* _hadByKitInstance_LargeBoxWithKits){
this->hadByKitInstance_LargeBoxWithKits= _hadByKitInstance_LargeBoxWithKits;
}
void KitInstance::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("KitInstance");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void KitInstance::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp = (SolidObject*) this;
temp->set(name);
ss.str("");
ss << isKitInstance_Finished;
data["isKitInstance_Finished"]=ss.str();
data["hasKitInstance_DesignRef"]=hasKitInstance_DesignRef;
data["name"]=name;
ss.str("");
ss << KitInstanceID;
data["KitInstanceID"]=ss.str();
for(unsigned int i=0;i<hadByPart_KitInstance.size();++i){
ss.str("");
hadByPart_KitInstance[i]->get(hadByPart_KitInstance[i]->getname());
ss << hadByPart_KitInstance[i]->getPartID();
data["hadByPart_KitInstance"]=data["hadByPart_KitInstance"]+" "+ss.str();
}
if(hasKitInstance_Tray!=NULL)
data["hasKitInstance_Tray"]=hasKitInstance_Tray->getname();
if(hadByKitInstance_LargeBoxWithKits!=NULL)
data["hadByKitInstance_LargeBoxWithKits"]=hadByKitInstance_LargeBoxWithKits->getname();
dao  = new DAO("KitInstance");
dao->set(data);
delete (dao);
}

void KitInstance::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<KitInstance*> tmp;
this->isKitInstance_Finished = std::atof(object["KitInstance.isKitInstance_Finished"].c_str());
this->hasKitInstance_DesignRef = object["KitInstance.hasKitInstance_DesignRef"];
this->name = object["KitInstance._NAME"];
this->KitInstanceID = std::atof(object["KitInstance.KitInstanceID"].c_str());
if(this->hadByPart_KitInstance.empty() && object["hadByPart_KitInstance/Part._NAME"]!=""){
temp = Explode(object["hadByPart_KitInstance/Part._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByPart_KitInstance.push_back(new Part(temp[i]));
}
}
if(this->hasKitInstance_Tray== NULL && object["hasKitInstance_Tray/KitTray._NAME"]!=""){
this->hasKitInstance_Tray = new KitTray(object["hasKitInstance_Tray/KitTray._NAME"]);
}
if(this->hadByKitInstance_LargeBoxWithKits== NULL && object["hadByKitInstance_LargeBoxWithKits/LargeBoxWithKits._NAME"]!=""){
this->hadByKitInstance_LargeBoxWithKits = new LargeBoxWithKits(object["hadByKitInstance_LargeBoxWithKits/LargeBoxWithKits._NAME"]);
}

}std::vector<std::string> KitInstance::Explode(const std::string & str, char separator )
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
