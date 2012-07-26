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

#include "LargeBoxWithKits.h"


 #include "Kit.h"
 #include "LargeContainer.h"
 #include "DAO.h"

LargeBoxWithKits::LargeBoxWithKits(std::string name) : SolidObject(name){
dao = NULL;
hasLargeBoxWithKits_LargeContainer = NULL;

}LargeBoxWithKits::~LargeBoxWithKits(){
delete(dao);
delete(hasLargeBoxWithKits_LargeContainer);
for(std::size_t i = 0; i < hadByKit_LargeBoxWithKits.size(); i++)
delete(hadByKit_LargeBoxWithKits[i]);
}
std::string LargeBoxWithKits::gethasLargeBoxWithKits_Capacity(){
return hasLargeBoxWithKits_Capacity;
}
std::string LargeBoxWithKits::gethasLargeBoxWithKits_KitDesignRef(){
return hasLargeBoxWithKits_KitDesignRef;
}
int LargeBoxWithKits::getLargeBoxWithKitsID(){
return LargeBoxWithKitsID;
}
DAO* LargeBoxWithKits::getdao(){
return dao;
}
LargeContainer* LargeBoxWithKits::gethasLargeBoxWithKits_LargeContainer(){
return hasLargeBoxWithKits_LargeContainer;
}
std::vector<Kit*>* LargeBoxWithKits::gethadByKit_LargeBoxWithKits(){
return &hadByKit_LargeBoxWithKits;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_Capacity(std::string _hasLargeBoxWithKits_Capacity){
this->hasLargeBoxWithKits_Capacity= _hasLargeBoxWithKits_Capacity;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_KitDesignRef(std::string _hasLargeBoxWithKits_KitDesignRef){
this->hasLargeBoxWithKits_KitDesignRef= _hasLargeBoxWithKits_KitDesignRef;
}
void LargeBoxWithKits::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_LargeContainer(LargeContainer* _hasLargeBoxWithKits_LargeContainer){
this->hasLargeBoxWithKits_LargeContainer= _hasLargeBoxWithKits_LargeContainer;
}
void LargeBoxWithKits::sethadByKit_LargeBoxWithKits(std::vector<Kit*> _hadByKit_LargeBoxWithKits){
this->hadByKit_LargeBoxWithKits= _hadByKit_LargeBoxWithKits;
}
void LargeBoxWithKits::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("LargeBoxWithKits");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void LargeBoxWithKits::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp = (SolidObject*) this;
temp->set(name);
data["hasLargeBoxWithKits_Capacity"]=hasLargeBoxWithKits_Capacity;
data["hasLargeBoxWithKits_KitDesignRef"]=hasLargeBoxWithKits_KitDesignRef;
data["name"]=name;
ss.str("");
ss << LargeBoxWithKitsID;
data["LargeBoxWithKitsID"]=ss.str();
if(hasLargeBoxWithKits_LargeContainer!=NULL)
data["hasLargeBoxWithKits_LargeContainer"]=hasLargeBoxWithKits_LargeContainer->getname();
for(unsigned int i=0;i<hadByKit_LargeBoxWithKits.size();++i){
ss.str("");
hadByKit_LargeBoxWithKits[i]->get(hadByKit_LargeBoxWithKits[i]->getname());
ss << hadByKit_LargeBoxWithKits[i]->getKitID();
data["hadByKit_LargeBoxWithKits"]=data["hadByKit_LargeBoxWithKits"]+" "+ss.str();
}
dao  = new DAO("LargeBoxWithKits");
dao->set(data);
delete (dao);
}

void LargeBoxWithKits::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<LargeBoxWithKits*> tmp;
this->hasLargeBoxWithKits_Capacity = object["LargeBoxWithKits.hasLargeBoxWithKits_Capacity"];
this->hasLargeBoxWithKits_KitDesignRef = object["LargeBoxWithKits.hasLargeBoxWithKits_KitDesignRef"];
this->name = object["LargeBoxWithKits._NAME"];
this->LargeBoxWithKitsID = std::atof(object["LargeBoxWithKits.LargeBoxWithKitsID"].c_str());
if(this->hasLargeBoxWithKits_LargeContainer== NULL && object["hasLargeBoxWithKits_LargeContainer/LargeContainer._NAME"]!=""){
this->hasLargeBoxWithKits_LargeContainer = new LargeContainer(object["hasLargeBoxWithKits_LargeContainer/LargeContainer._NAME"]);
}
if(this->hadByKit_LargeBoxWithKits.empty() && object["hadByKit_LargeBoxWithKits/Kit._NAME"]!=""){
temp = Explode(object["hadByKit_LargeBoxWithKits/Kit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByKit_LargeBoxWithKits.push_back(new Kit(temp[i]));
}
}

}std::vector<std::string> LargeBoxWithKits::Explode(const std::string & str, char separator )
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
