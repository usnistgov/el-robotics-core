#include "PhysicalLocation.h"

PhysicalLocation::PhysicalLocation(std::string name) : DataThing(name){
this->name=name;
}PhysicalLocation::~PhysicalLocation(){
delete(dao);
delete(hasPhysicalLocation_RefObject);
delete(hasSolidObject_PhysicalLocation);
}
std::string PhysicalLocation::getname(){
return this->name;
}
int PhysicalLocation::getPhysicalLocationID(){
return this->PhysicalLocationID;
}
DAO* PhysicalLocation::getdao(){
return this->dao;
}
SolidObject* PhysicalLocation::gethasPhysicalLocation_RefObject(){
return this->hasPhysicalLocation_RefObject;
}
SolidObject* PhysicalLocation::gethasSolidObject_PhysicalLocation(){
return this->hasSolidObject_PhysicalLocation;
}
void PhysicalLocation::setname(std::string _name){
this->name= _name;
}
void PhysicalLocation::setPhysicalLocationID(int _PhysicalLocationID){
this->PhysicalLocationID= _PhysicalLocationID;
}
void PhysicalLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PhysicalLocation::sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void PhysicalLocation::sethasSolidObject_PhysicalLocation(SolidObject* _hasSolidObject_PhysicalLocation){
this->hasSolidObject_PhysicalLocation= _hasSolidObject_PhysicalLocation;
}
void PhysicalLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void PhysicalLocation::set(std::string name){
 dao  = new DAO("PhysicalLocation");
 dao->set(name);
delete (dao);
}

void PhysicalLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["PhysicalLocation._NAME"];
this->PhysicalLocationID = std::atof(object["PhysicalLocation.PhysicalLocationID"].c_str());
this->hasPhysicalLocation_RefObject = new SolidObject(" ");
this->hasPhysicalLocation_RefObject->sethasPhysicalLocation_RefObject(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,30) == "hasPhysicalLocation_RefObject/"){
mapTemp[it->first.substr(30,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPhysicalLocation_RefObject->copy(mapTemp);
this->hasSolidObject_PhysicalLocation = new SolidObject(" ");
this->hasSolidObject_PhysicalLocation->sethasSolidObject_PhysicalLocation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,32) == "hasSolidObject_PhysicalLocation/"){
mapTemp[it->first.substr(32,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasSolidObject_PhysicalLocation->copy(mapTemp);

}std::vector<std::string> PhysicalLocation::Explode(const std::string & str, char separator )
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
