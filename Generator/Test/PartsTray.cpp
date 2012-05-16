#include "PartsTray.h"

PartsTray::PartsTray(std::string name) : BoxyObject(name){
this->name=name;
}PartsTray::~PartsTray(){
delete(dao);
delete(hadByPartsTray_PartsTrayWithParts);
}
std::string PartsTray::gethasPartsTray_SkuRef(){
return this->hasPartsTray_SkuRef;
}
std::string PartsTray::gethasPartsTray_SerialNumber(){
return this->hasPartsTray_SerialNumber;
}
std::string PartsTray::getname(){
return this->name;
}
int PartsTray::getPartsTrayID(){
return this->PartsTrayID;
}
DAO* PartsTray::getdao(){
return this->dao;
}
PartsTrayWithParts* PartsTray::gethadByPartsTray_PartsTrayWithParts(){
return this->hadByPartsTray_PartsTrayWithParts;
}
void PartsTray::sethasPartsTray_SkuRef(std::string _hasPartsTray_SkuRef){
this->hasPartsTray_SkuRef= _hasPartsTray_SkuRef;
}
void PartsTray::sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber){
this->hasPartsTray_SerialNumber= _hasPartsTray_SerialNumber;
}
void PartsTray::setname(std::string _name){
this->name= _name;
}
void PartsTray::setPartsTrayID(int _PartsTrayID){
this->PartsTrayID= _PartsTrayID;
}
void PartsTray::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTray::sethadByPartsTray_PartsTrayWithParts(PartsTrayWithParts* _hadByPartsTray_PartsTrayWithParts){
this->hadByPartsTray_PartsTrayWithParts= _hadByPartsTray_PartsTrayWithParts;
}
void PartsTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);
 BoxyObject::copy(temp);
delete (dao);
dao  = new DAO("PartsTray");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void PartsTray::set(std::string name){
 dao  = new DAO("PartsTray");
 dao->set(name);
delete (dao);
}

void PartsTray::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasPartsTray_SkuRef = object["PartsTray.hasPartsTray_SkuRef"];
this->hasPartsTray_SerialNumber = object["PartsTray.hasPartsTray_SerialNumber"];
this->name = object["PartsTray._NAME"];
this->PartsTrayID = std::atof(object["PartsTray.PartsTrayID"].c_str());
this->hadByPartsTray_PartsTrayWithParts = new PartsTrayWithParts(" ");
this->hadByPartsTray_PartsTrayWithParts->sethadByPartsTray_PartsTrayWithParts(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,34) == "hadByPartsTray_PartsTrayWithParts/"){
mapTemp[it->first.substr(34,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByPartsTray_PartsTrayWithParts->copy(mapTemp);

}std::vector<std::string> PartsTray::Explode(const std::string & str, char separator )
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
