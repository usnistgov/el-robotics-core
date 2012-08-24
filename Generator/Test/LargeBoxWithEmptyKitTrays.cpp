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

#include "LargeBoxWithEmptyKitTrays.h"


 #include "KitTray.h"
 #include "LargeContainer.h"
 #include "DAO.h"

LargeBoxWithEmptyKitTrays::LargeBoxWithEmptyKitTrays(std::string name) : SolidObject(name){
dao = NULL;
hasLargeBoxWithEmptyKitTrays_LargeContainer = NULL;

}LargeBoxWithEmptyKitTrays::~LargeBoxWithEmptyKitTrays(){
delete(dao);
delete(hasLargeBoxWithEmptyKitTrays_LargeContainer);
for(std::size_t i = 0; i < hadByKitTray_LargeBoxWithEmptyKitTrays.size(); i++)
delete(hadByKitTray_LargeBoxWithEmptyKitTrays[i]);
}
int LargeBoxWithEmptyKitTrays::getLargeBoxWithEmptyKitTraysID(){
return LargeBoxWithEmptyKitTraysID;
}
DAO* LargeBoxWithEmptyKitTrays::getdao(){
return dao;
}
LargeContainer* LargeBoxWithEmptyKitTrays::gethasLargeBoxWithEmptyKitTrays_LargeContainer(){
return hasLargeBoxWithEmptyKitTrays_LargeContainer;
}
std::vector<KitTray*> LargeBoxWithEmptyKitTrays::gethadByKitTray_LargeBoxWithEmptyKitTrays(){
return hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void LargeBoxWithEmptyKitTrays::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeBoxWithEmptyKitTrays::sethasLargeBoxWithEmptyKitTrays_LargeContainer(LargeContainer* _hasLargeBoxWithEmptyKitTrays_LargeContainer){
this->hasLargeBoxWithEmptyKitTrays_LargeContainer= _hasLargeBoxWithEmptyKitTrays_LargeContainer;
}
void LargeBoxWithEmptyKitTrays::sethadByKitTray_LargeBoxWithEmptyKitTrays(std::vector<KitTray*> _hadByKitTray_LargeBoxWithEmptyKitTrays){
this->hadByKitTray_LargeBoxWithEmptyKitTrays= _hadByKitTray_LargeBoxWithEmptyKitTrays;
}
void LargeBoxWithEmptyKitTrays::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("LargeBoxWithEmptyKitTrays");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void LargeBoxWithEmptyKitTrays::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]=name;
ss.str("");
ss << LargeBoxWithEmptyKitTraysID;
data["LargeBoxWithEmptyKitTraysID"]=ss.str();
if(hasLargeBoxWithEmptyKitTrays_LargeContainer!=NULL)
data["hasLargeBoxWithEmptyKitTrays_LargeContainer"]=hasLargeBoxWithEmptyKitTrays_LargeContainer->getname();
for(unsigned int i=0;i<hadByKitTray_LargeBoxWithEmptyKitTrays.size();++i){
ss.str("");
hadByKitTray_LargeBoxWithEmptyKitTrays[i]->get(hadByKitTray_LargeBoxWithEmptyKitTrays[i]->getname());
ss << hadByKitTray_LargeBoxWithEmptyKitTrays[i]->getKitTrayID();
data["hadByKitTray_LargeBoxWithEmptyKitTrays"]=data["hadByKitTray_LargeBoxWithEmptyKitTrays"]+" "+ss.str();
}
dao  = new DAO("LargeBoxWithEmptyKitTrays");
dao->set(data);
delete (dao);
}

void LargeBoxWithEmptyKitTrays::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<LargeBoxWithEmptyKitTrays*> tmp;
this->name = object["LargeBoxWithEmptyKitTrays._NAME"];
this->LargeBoxWithEmptyKitTraysID = std::atof(object["LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID"].c_str());
if(this->hasLargeBoxWithEmptyKitTrays_LargeContainer== NULL && object["hasLargeBoxWithEmptyKitTrays_LargeContainer/LargeContainer._NAME"]!=""){
this->hasLargeBoxWithEmptyKitTrays_LargeContainer = new LargeContainer(object["hasLargeBoxWithEmptyKitTrays_LargeContainer/LargeContainer._NAME"]);
}
if(this->hadByKitTray_LargeBoxWithEmptyKitTrays.empty() && object["hadByKitTray_LargeBoxWithEmptyKitTrays/KitTray._NAME"]!=""){
temp = Explode(object["hadByKitTray_LargeBoxWithEmptyKitTrays/KitTray._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByKitTray_LargeBoxWithEmptyKitTrays.push_back(new KitTray(temp[i]));
}
}

}std::vector<std::string> LargeBoxWithEmptyKitTrays::Explode(const std::string & str, char separator )
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
