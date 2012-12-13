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

#include "LargeContainer.h"


 #include "StockKeepingUnit.h"
 #include "LargeBoxWithKits.h"
 #include "LargeBoxWithEmptyKitTrays.h"
 #include "DAO.h"

LargeContainer::LargeContainer(std::string name) : SolidObject(name){
dao = NULL;
hasLargeBoxWithKits_LargeContainer = NULL;
hasLargeContainer_Sku = NULL;
hasLargeBoxWithEmptyKitTrays_LargeContainer = NULL;

}LargeContainer::~LargeContainer(){
delete(dao);
delete(hasLargeBoxWithKits_LargeContainer);
delete(hasLargeContainer_Sku);
delete(hasLargeBoxWithEmptyKitTrays_LargeContainer);
}
std::string LargeContainer::gethasLargeContainer_SerialNumber(){
return hasLargeContainer_SerialNumber;
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
StockKeepingUnit* LargeContainer::gethasLargeContainer_Sku(){
return hasLargeContainer_Sku;
}
LargeBoxWithEmptyKitTrays* LargeContainer::gethasLargeBoxWithEmptyKitTrays_LargeContainer(){
return hasLargeBoxWithEmptyKitTrays_LargeContainer;
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
void LargeContainer::sethasLargeContainer_Sku(StockKeepingUnit* _hasLargeContainer_Sku){
this->hasLargeContainer_Sku= _hasLargeContainer_Sku;
}
void LargeContainer::sethasLargeBoxWithEmptyKitTrays_LargeContainer(LargeBoxWithEmptyKitTrays* _hasLargeBoxWithEmptyKitTrays_LargeContainer){
this->hasLargeBoxWithEmptyKitTrays_LargeContainer= _hasLargeBoxWithEmptyKitTrays_LargeContainer;
}
void LargeContainer::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("LargeContainer");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void LargeContainer::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasLargeContainer_SerialNumber"]=hasLargeContainer_SerialNumber;
data["name"]=name;
ss.str("");
ss << LargeContainerID;
data["LargeContainerID"]=ss.str();
if(hasLargeBoxWithKits_LargeContainer!=NULL)
data["hasLargeBoxWithKits_LargeContainer"]=hasLargeBoxWithKits_LargeContainer->getname();
if(hasLargeContainer_Sku!=NULL)
data["hasLargeContainer_Sku"]=hasLargeContainer_Sku->getname();
if(hasLargeBoxWithEmptyKitTrays_LargeContainer!=NULL)
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
this->hasLargeContainer_SerialNumber = object["LargeContainer.hasLargeContainer_SerialNumber"];
this->name = object["LargeContainer._NAME"];
this->LargeContainerID = std::atof(object["LargeContainer.LargeContainerID"].c_str());
if(this->hasLargeBoxWithKits_LargeContainer== NULL && object["hasLargeBoxWithKits_LargeContainer/LargeBoxWithKits._NAME"]!=""){
this->hasLargeBoxWithKits_LargeContainer = new LargeBoxWithKits(object["hasLargeBoxWithKits_LargeContainer/LargeBoxWithKits._NAME"]);
}
if(this->hasLargeContainer_Sku== NULL && object["hasLargeContainer_Sku/StockKeepingUnit._NAME"]!=""){
this->hasLargeContainer_Sku = new StockKeepingUnit(object["hasLargeContainer_Sku/StockKeepingUnit._NAME"]);
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
