#include "LargeBoxWithKits.h"

LargeBoxWithKits::LargeBoxWithKits(std::string name) : SolidObject(name){
this->name=name;
}LargeBoxWithKits::~LargeBoxWithKits(){
delete(dao);
delete(hadByLargeContainer_LargeBoxWithKits);
}
std::string LargeBoxWithKits::gethasLargeBoxWithKits_Capacity(){
return this->hasLargeBoxWithKits_Capacity;
}
std::string LargeBoxWithKits::gethasLargeBoxWithKits_KitDesignRef(){
return this->hasLargeBoxWithKits_KitDesignRef;
}
std::string LargeBoxWithKits::getname(){
return this->name;
}
int LargeBoxWithKits::getLargeBoxWithKitsID(){
return this->LargeBoxWithKitsID;
}
DAO* LargeBoxWithKits::getdao(){
return this->dao;
}
LargeContainer* LargeBoxWithKits::gethadByLargeContainer_LargeBoxWithKits(){
return this->hadByLargeContainer_LargeBoxWithKits;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_Capacity(std::string _hasLargeBoxWithKits_Capacity){
this->hasLargeBoxWithKits_Capacity= _hasLargeBoxWithKits_Capacity;
}
void LargeBoxWithKits::sethasLargeBoxWithKits_KitDesignRef(std::string _hasLargeBoxWithKits_KitDesignRef){
this->hasLargeBoxWithKits_KitDesignRef= _hasLargeBoxWithKits_KitDesignRef;
}
void LargeBoxWithKits::setname(std::string _name){
this->name= _name;
}
void LargeBoxWithKits::setLargeBoxWithKitsID(int _LargeBoxWithKitsID){
this->LargeBoxWithKitsID= _LargeBoxWithKitsID;
}
void LargeBoxWithKits::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeBoxWithKits::sethadByLargeContainer_LargeBoxWithKits(LargeContainer* _hadByLargeContainer_LargeBoxWithKits){
this->hadByLargeContainer_LargeBoxWithKits= _hadByLargeContainer_LargeBoxWithKits;
}
void LargeBoxWithKits::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("LargeBoxWithKits");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void LargeBoxWithKits::set(std::string name){
 dao  = new DAO("LargeBoxWithKits");
 dao->set(name);
delete (dao);
}

void LargeBoxWithKits::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasLargeBoxWithKits_Capacity = object["LargeBoxWithKits.hasLargeBoxWithKits_Capacity"];
this->hasLargeBoxWithKits_KitDesignRef = object["LargeBoxWithKits.hasLargeBoxWithKits_KitDesignRef"];
this->name = object["LargeBoxWithKits._NAME"];
this->LargeBoxWithKitsID = std::atof(object["LargeBoxWithKits.LargeBoxWithKitsID"].c_str());
this->hadByLargeContainer_LargeBoxWithKits = new LargeContainer(" ");
this->hadByLargeContainer_LargeBoxWithKits->sethadByLargeContainer_LargeBoxWithKits(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,37) == "hadByLargeContainer_LargeBoxWithKits/"){
mapTemp[it->first.substr(37,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByLargeContainer_LargeBoxWithKits->copy(mapTemp);

}std::vector<std::string> LargeBoxWithKits::Explode(const std::string & str, char separator )
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
