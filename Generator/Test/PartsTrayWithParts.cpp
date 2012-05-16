#include "PartsTrayWithParts.h"

PartsTrayWithParts::PartsTrayWithParts(std::string name) : SolidObject(name){
this->name=name;
}PartsTrayWithParts::~PartsTrayWithParts(){
delete(dao);
delete(hadByPartsTray_PartsTrayWithParts);
}
std::string PartsTrayWithParts::getname(){
return this->name;
}
int PartsTrayWithParts::getPartsTrayWithPartsID(){
return this->PartsTrayWithPartsID;
}
DAO* PartsTrayWithParts::getdao(){
return this->dao;
}
PartsTray* PartsTrayWithParts::gethadByPartsTray_PartsTrayWithParts(){
return this->hadByPartsTray_PartsTrayWithParts;
}
void PartsTrayWithParts::setname(std::string _name){
this->name= _name;
}
void PartsTrayWithParts::setPartsTrayWithPartsID(int _PartsTrayWithPartsID){
this->PartsTrayWithPartsID= _PartsTrayWithPartsID;
}
void PartsTrayWithParts::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTrayWithParts::sethadByPartsTray_PartsTrayWithParts(PartsTray* _hadByPartsTray_PartsTrayWithParts){
this->hadByPartsTray_PartsTrayWithParts= _hadByPartsTray_PartsTrayWithParts;
}
void PartsTrayWithParts::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("PartsTrayWithParts");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void PartsTrayWithParts::set(std::string name){
 dao  = new DAO("PartsTrayWithParts");
 dao->set(name);
delete (dao);
}

void PartsTrayWithParts::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["PartsTrayWithParts._NAME"];
this->PartsTrayWithPartsID = std::atof(object["PartsTrayWithParts.PartsTrayWithPartsID"].c_str());
this->hadByPartsTray_PartsTrayWithParts = new PartsTray(" ");
this->hadByPartsTray_PartsTrayWithParts->sethadByPartsTray_PartsTrayWithParts(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,34) == "hadByPartsTray_PartsTrayWithParts/"){
mapTemp[it->first.substr(34,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByPartsTray_PartsTrayWithParts->copy(mapTemp);

}std::vector<std::string> PartsTrayWithParts::Explode(const std::string & str, char separator )
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
