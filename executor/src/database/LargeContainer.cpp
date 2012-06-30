#include "LargeContainer.h"


 #include "LargeBoxWithKits.h"
 #include "LargeBoxWithEmptyKitTrays.h"
 #include "DAO.h"

LargeContainer::LargeContainer(std::string name) : BoxyObject(name){
this->name=name;dao = NULL;
hasLargeBoxWithKits_LargeContainer = NULL;
hasLargeBoxWithEmptyKitTrays_LargeContainer = NULL;

}LargeContainer::~LargeContainer(){
delete(dao);
delete(hasLargeBoxWithKits_LargeContainer);
delete(hasLargeBoxWithEmptyKitTrays_LargeContainer);
}
std::string LargeContainer::gethasLargeContainer_SkuRef(){
return hasLargeContainer_SkuRef;
}
std::string LargeContainer::gethasLargeContainer_SerialNumber(){
return hasLargeContainer_SerialNumber;
}
std::string LargeContainer::getname(){
return name;
}
int LargeContainer::getLargeContainerID(){
return LargeContainerID;
}
DAO* LargeContainer::getdao(){
return dao;
}
LargeBoxWithKits* LargeContainer::gethasLargeBoxWithKits_LargeContainer(){
return hasLargeBoxWithKits_LargeContainer;
}
LargeBoxWithEmptyKitTrays* LargeContainer::gethasLargeBoxWithEmptyKitTrays_LargeContainer(){
return hasLargeBoxWithEmptyKitTrays_LargeContainer;
}
void LargeContainer::sethasLargeContainer_SkuRef(std::string _hasLargeContainer_SkuRef){
this->hasLargeContainer_SkuRef= _hasLargeContainer_SkuRef;
}
void LargeContainer::sethasLargeContainer_SerialNumber(std::string _hasLargeContainer_SerialNumber){
this->hasLargeContainer_SerialNumber= _hasLargeContainer_SerialNumber;
}
void LargeContainer::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeContainer::sethasLargeBoxWithKits_LargeContainer(LargeBoxWithKits* _hasLargeBoxWithKits_LargeContainer){
this->hasLargeBoxWithKits_LargeContainer= _hasLargeBoxWithKits_LargeContainer;
}
void LargeContainer::sethasLargeBoxWithEmptyKitTrays_LargeContainer(LargeBoxWithEmptyKitTrays* _hasLargeBoxWithEmptyKitTrays_LargeContainer){
this->hasLargeBoxWithEmptyKitTrays_LargeContainer= _hasLargeBoxWithEmptyKitTrays_LargeContainer;
}
void LargeContainer::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);delete (dao);
 BoxyObject::copy(temp);
dao  = new DAO("LargeContainer");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void LargeContainer::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasLargeContainer_SkuRef"]=hasLargeContainer_SkuRef;
data["hasLargeContainer_SerialNumber"]=hasLargeContainer_SerialNumber;
data["name"]=name;
data["LargeContainerID"]=LargeContainerID;
data["hasLargeBoxWithKits_LargeContainer"]=hasLargeBoxWithKits_LargeContainer->getname();
data["hasLargeBoxWithEmptyKitTrays_LargeContainer"]=hasLargeBoxWithEmptyKitTrays_LargeContainer->getname();
dao  = new DAO("LargeContainer");
dao->set(data);
delete (dao);
}

void LargeContainer::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<LargeContainer*> tmp;
this->hasLargeContainer_SkuRef = object["LargeContainer.hasLargeContainer_SkuRef"];
this->hasLargeContainer_SerialNumber = object["LargeContainer.hasLargeContainer_SerialNumber"];
this->name = object["LargeContainer._NAME"];
this->LargeContainerID = std::atof(object["LargeContainer.LargeContainerID"].c_str());
if(this->hasLargeBoxWithKits_LargeContainer== NULL && object["hasLargeBoxWithKits_LargeContainer/LargeBoxWithKits._NAME"]!=""){
this->hasLargeBoxWithKits_LargeContainer = new LargeBoxWithKits(object["hasLargeBoxWithKits_LargeContainer/LargeBoxWithKits._NAME"]);
}
if(this->hasLargeBoxWithEmptyKitTrays_LargeContainer== NULL && object["hasLargeBoxWithEmptyKitTrays_LargeContainer/LargeBoxWithEmptyKitTrays._NAME"]!=""){
this->hasLargeBoxWithEmptyKitTrays_LargeContainer = new LargeBoxWithEmptyKitTrays(object["hasLargeBoxWithEmptyKitTrays_LargeContainer/LargeBoxWithEmptyKitTrays._NAME"]);
}

}std::vector<std::string> LargeContainer::Explode(const std::string & str, char separator )
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
