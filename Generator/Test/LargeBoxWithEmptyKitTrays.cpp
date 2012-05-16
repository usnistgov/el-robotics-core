#include "LargeBoxWithEmptyKitTrays.h"

LargeBoxWithEmptyKitTrays::LargeBoxWithEmptyKitTrays(std::string name) : SolidObject(name){
this->name=name;
}LargeBoxWithEmptyKitTrays::~LargeBoxWithEmptyKitTrays(){
delete(dao);
delete(hadByLargeContainer_LargeBoxWithEmptyKitTrays);
}
std::string LargeBoxWithEmptyKitTrays::getname(){
return this->name;
}
int LargeBoxWithEmptyKitTrays::getLargeBoxWithEmptyKitTraysID(){
return this->LargeBoxWithEmptyKitTraysID;
}
DAO* LargeBoxWithEmptyKitTrays::getdao(){
return this->dao;
}
LargeContainer* LargeBoxWithEmptyKitTrays::gethadByLargeContainer_LargeBoxWithEmptyKitTrays(){
return this->hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeBoxWithEmptyKitTrays::setname(std::string _name){
this->name= _name;
}
void LargeBoxWithEmptyKitTrays::setLargeBoxWithEmptyKitTraysID(int _LargeBoxWithEmptyKitTraysID){
this->LargeBoxWithEmptyKitTraysID= _LargeBoxWithEmptyKitTraysID;
}
void LargeBoxWithEmptyKitTrays::setdao(DAO* _dao){
this->dao= _dao;
}
void LargeBoxWithEmptyKitTrays::sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeContainer* _hadByLargeContainer_LargeBoxWithEmptyKitTrays){
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays= _hadByLargeContainer_LargeBoxWithEmptyKitTrays;
}
void LargeBoxWithEmptyKitTrays::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("LargeBoxWithEmptyKitTrays");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void LargeBoxWithEmptyKitTrays::set(std::string name){
 dao  = new DAO("LargeBoxWithEmptyKitTrays");
 dao->set(name);
delete (dao);
}

void LargeBoxWithEmptyKitTrays::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["LargeBoxWithEmptyKitTrays._NAME"];
this->LargeBoxWithEmptyKitTraysID = std::atof(object["LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID"].c_str());
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays = new LargeContainer(" ");
this->hadByLargeContainer_LargeBoxWithEmptyKitTrays->sethadByLargeContainer_LargeBoxWithEmptyKitTrays(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,46) == "hadByLargeContainer_LargeBoxWithEmptyKitTrays/"){
mapTemp[it->first.substr(46,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByLargeContainer_LargeBoxWithEmptyKitTrays->copy(mapTemp);

}std::vector<std::string> LargeBoxWithEmptyKitTrays::Explode(const std::string & str, char separator )
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
