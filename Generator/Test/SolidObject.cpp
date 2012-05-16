#include "SolidObject.h"

SolidObject::SolidObject(std::string name){
this->name=name;
}SolidObject::~SolidObject(){
delete(dao);
delete(hasSolidObject_PhysicalLocation);
delete(hasPhysicalLocation_RefObject);
}
std::string SolidObject::getname(){
return this->name;
}
int SolidObject::getSolidObjectID(){
return this->SolidObjectID;
}
DAO* SolidObject::getdao(){
return this->dao;
}
PhysicalLocation* SolidObject::gethasSolidObject_PhysicalLocation(){
return this->hasSolidObject_PhysicalLocation;
}
PhysicalLocation* SolidObject::gethasPhysicalLocation_RefObject(){
return this->hasPhysicalLocation_RefObject;
}
void SolidObject::setname(std::string _name){
this->name= _name;
}
void SolidObject::setSolidObjectID(int _SolidObjectID){
this->SolidObjectID= _SolidObjectID;
}
void SolidObject::setdao(DAO* _dao){
this->dao= _dao;
}
void SolidObject::sethasSolidObject_PhysicalLocation(PhysicalLocation* _hasSolidObject_PhysicalLocation){
this->hasSolidObject_PhysicalLocation= _hasSolidObject_PhysicalLocation;
}
void SolidObject::sethasPhysicalLocation_RefObject(PhysicalLocation* _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void SolidObject::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void SolidObject::set(std::string name){
 dao  = new DAO("SolidObject");
 dao->set(name);
delete (dao);
}

void SolidObject::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["SolidObject._NAME"];
this->SolidObjectID = std::atof(object["SolidObject.SolidObjectID"].c_str());
this->hasSolidObject_PhysicalLocation = new PhysicalLocation(" ");
this->hasSolidObject_PhysicalLocation->sethasSolidObject_PhysicalLocation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,32) == "hasSolidObject_PhysicalLocation/"){
mapTemp[it->first.substr(32,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasSolidObject_PhysicalLocation->copy(mapTemp);
this->hasPhysicalLocation_RefObject = new PhysicalLocation(" ");
this->hasPhysicalLocation_RefObject->sethasPhysicalLocation_RefObject(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,30) == "hasPhysicalLocation_RefObject/"){
mapTemp[it->first.substr(30,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPhysicalLocation_RefObject->copy(mapTemp);

}std::vector<std::string> SolidObject::Explode(const std::string & str, char separator )
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
