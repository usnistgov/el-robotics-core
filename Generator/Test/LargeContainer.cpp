#include "LargeContainer.h"

LargeContainer::LargeContainer(std::string name) : BoxyObject(name){
this->name=name;
}LargeContainer::~LargeContainer(){
delete(dao);
delete(hadByLargeContainer_LargeBoxWithKits);
delete(hadByLargeContainer_LargeBoxWithEmptyKitTrays);
}
std::string LargeContainer::gethasLargeContainer_SkuRef(){
return this->hasLargeContainer_SkuRef;
}
std::string LargeContainer::gethasLargeContainer_SerialNumber(){
return this->hasLargeContainer_SerialNumber;
}
std::string LargeContainer::getname(){
return this->name;
}
int LargeContainer::getLargeContainerID(){
return this->LargeContainerID;
}
DAO* LargeContainer::getdao(){
return this->dao;
}
LargeBoxWithKits* LargeContainer::gethadByLargeContainer_LargeBoxWithKits(){
return this->hadByLargeContainer_LargeBoxWithKits;
}
LargeBoxWithEmptyKitTrays* LargeContainer::gethadByLargeContainer_LargeBoxWithEmptyKitTrays(){
return this->hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeContainer::sethasLargeContainer_SkuRef(std::string _hasLargeContainer_SkuRef){
this->hasLargeContainer_SkuRef= _hasLargeContainer_SkuRef;
}
void LargeContainer::sethasLargeContainer_SerialNumber(std::string _hasLargeContainer_SerialNumber){
this->hasLargeContainer_SerialNumber= _hasLargeContainer_SerialNumber;
}
void LargeContainer::setname(std::string _name){
this->name= _name;
}
void LargeContainer::setLargeContainerID(int _LargeContainerID){
this->LargeContainerID= _LargeContainerID;
}
void LargeContainer::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeContainer::sethadByLargeContainer_LargeBoxWithKits(LargeBoxWithKits* _hadByLargeContainer_LargeBoxWithKits){
this->hadByLargeContainer_LargeBoxWithKits= _hadByLargeContainer_LargeBoxWithKits;
}
void LargeContainer::sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByLargeContainer_LargeBoxWithEmptyKitTrays){
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays= _hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeContainer::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);
 BoxyObject::copy(temp);
delete (dao);
dao  = new DAO("LargeContainer");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void LargeContainer::set(std::string name){
 dao  = new DAO("LargeContainer");
 dao->set(name);
delete (dao);
}

void LargeContainer::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasLargeContainer_SkuRef = object["LargeContainer.hasLargeContainer_SkuRef"];
this->hasLargeContainer_SerialNumber = object["LargeContainer.hasLargeContainer_SerialNumber"];
this->name = object["LargeContainer._NAME"];
this->LargeContainerID = std::atof(object["LargeContainer.LargeContainerID"].c_str());
this->hadByLargeContainer_LargeBoxWithKits = new LargeBoxWithKits(" ");
this->hadByLargeContainer_LargeBoxWithKits->sethadByLargeContainer_LargeBoxWithKits(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,37) == "hadByLargeContainer_LargeBoxWithKits/"){
mapTemp[it->first.substr(37,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByLargeContainer_LargeBoxWithKits->copy(mapTemp);
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays = new LargeBoxWithEmptyKitTrays(" ");
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays->sethadByLargeContainer_LargeBoxWithEmptyKitTrays(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,46) == "hadByLargeContainer_LargeBoxWithEmptyKitTrays/"){
mapTemp[it->first.substr(46,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByLargeContainer_LargeBoxWithEmptyKitTrays->copy(mapTemp);

}std::vector<std::string> LargeContainer::Explode(const std::string & str, char separator )
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
