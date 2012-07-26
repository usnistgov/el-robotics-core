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

#include "PhysicalLocation.h"


 #include "SolidObject.h"
 #include "DAO.h"

PhysicalLocation::PhysicalLocation(std::string name) : DataThing(name){
dao = NULL;
hasPhysicalLocation_RefObject = NULL;

}PhysicalLocation::~PhysicalLocation(){
delete(dao);
delete(hasPhysicalLocation_RefObject);
for(std::size_t i = 0; i < hasSolidObject_SecondaryLocation.size(); i++)
delete(hasSolidObject_SecondaryLocation[i]);
for(std::size_t i = 0; i < hasSolidObject_PrimaryLocation.size(); i++)
delete(hasSolidObject_PrimaryLocation[i]);
}
int PhysicalLocation::getPhysicalLocationID(){
return PhysicalLocationID;
}
DAO* PhysicalLocation::getdao(){
return dao;
}
SolidObject* PhysicalLocation::gethasPhysicalLocation_RefObject(){
return hasPhysicalLocation_RefObject;
}
std::vector<SolidObject*>* PhysicalLocation::gethasSolidObject_SecondaryLocation(){
return &hasSolidObject_SecondaryLocation;
}
std::vector<SolidObject*>* PhysicalLocation::gethasSolidObject_PrimaryLocation(){
return &hasSolidObject_PrimaryLocation;
}
void PhysicalLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PhysicalLocation::sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void PhysicalLocation::sethasSolidObject_SecondaryLocation(std::vector<SolidObject*> _hasSolidObject_SecondaryLocation){
this->hasSolidObject_SecondaryLocation= _hasSolidObject_SecondaryLocation;
}
void PhysicalLocation::sethasSolidObject_PrimaryLocation(std::vector<SolidObject*> _hasSolidObject_PrimaryLocation){
this->hasSolidObject_PrimaryLocation= _hasSolidObject_PrimaryLocation;
}
void PhysicalLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PhysicalLocation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp = (DataThing*) this;
temp->set(name);
data["name"]=name;
ss.str("");
ss << PhysicalLocationID;
data["PhysicalLocationID"]=ss.str();
if(hasPhysicalLocation_RefObject!=NULL)
data["hasPhysicalLocation_RefObject"]=hasPhysicalLocation_RefObject->getname();
for(unsigned int i=0;i<hasSolidObject_SecondaryLocation.size();++i){
ss.str("");
hasSolidObject_SecondaryLocation[i]->get(hasSolidObject_SecondaryLocation[i]->getname());
ss << hasSolidObject_SecondaryLocation[i]->getSolidObjectID();
data["hasSolidObject_SecondaryLocation"]=data["hasSolidObject_SecondaryLocation"]+" "+ss.str();
}
for(unsigned int i=0;i<hasSolidObject_PrimaryLocation.size();++i){
ss.str("");
hasSolidObject_PrimaryLocation[i]->get(hasSolidObject_PrimaryLocation[i]->getname());
ss << hasSolidObject_PrimaryLocation[i]->getSolidObjectID();
data["hasSolidObject_PrimaryLocation"]=data["hasSolidObject_PrimaryLocation"]+" "+ss.str();
}
dao  = new DAO("PhysicalLocation");
dao->set(data);
delete (dao);
}

void PhysicalLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PhysicalLocation*> tmp;
this->name = object["PhysicalLocation._NAME"];
this->PhysicalLocationID = std::atof(object["PhysicalLocation.PhysicalLocationID"].c_str());
if(this->hasPhysicalLocation_RefObject== NULL && object["hasPhysicalLocation_RefObject/SolidObject._NAME"]!=""){
this->hasPhysicalLocation_RefObject = new SolidObject(object["hasPhysicalLocation_RefObject/SolidObject._NAME"]);
}
if(this->hasSolidObject_SecondaryLocation.empty() && object["hasSolidObject_SecondaryLocation/SolidObject._NAME"]!=""){
temp = Explode(object["hasSolidObject_SecondaryLocation/SolidObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSolidObject_SecondaryLocation.push_back(new SolidObject(temp[i]));
}
}
if(this->hasSolidObject_PrimaryLocation.empty() && object["hasSolidObject_PrimaryLocation/SolidObject._NAME"]!=""){
temp = Explode(object["hasSolidObject_PrimaryLocation/SolidObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSolidObject_PrimaryLocation.push_back(new SolidObject(temp[i]));
}
}

}std::vector<std::string> PhysicalLocation::Explode(const std::string & str, char separator )
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
