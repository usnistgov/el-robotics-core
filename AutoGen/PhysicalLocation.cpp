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


 #include "DAO.h"
 #include "SolidObject.h"

PhysicalLocation::PhysicalLocation(std::string name) : DataThing(name){
dao = NULL;
hadBySecondaryLocation_SolidObject = NULL;
hasPhysicalLocation_RefObject = NULL;
hasSolidObject_PrimaryLocation = NULL;

}PhysicalLocation::~PhysicalLocation(){
delete(hadBySecondaryLocation_SolidObject);
delete(hasPhysicalLocation_RefObject);
delete(hasSolidObject_PrimaryLocation);
}
std::string PhysicalLocation::gethasPhysicalLocation_Timestamp(){
return hasPhysicalLocation_Timestamp;
}
int PhysicalLocation::getPhysicalLocationID(){
return PhysicalLocationID;
}
DAO* PhysicalLocation::getdao(){
return dao;
}
SolidObject* PhysicalLocation::gethadBySecondaryLocation_SolidObject(){
return hadBySecondaryLocation_SolidObject;
}
SolidObject* PhysicalLocation::gethasPhysicalLocation_RefObject(){
return hasPhysicalLocation_RefObject;
}
SolidObject* PhysicalLocation::gethasSolidObject_PrimaryLocation(){
return hasSolidObject_PrimaryLocation;
}
void PhysicalLocation::sethasPhysicalLocation_Timestamp(std::string _hasPhysicalLocation_Timestamp){
this->hasPhysicalLocation_Timestamp= _hasPhysicalLocation_Timestamp;
}
void PhysicalLocation::setPhysicalLocationID(int _PhysicalLocationID){
this->PhysicalLocationID= _PhysicalLocationID;
}
void PhysicalLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PhysicalLocation::sethadBySecondaryLocation_SolidObject(SolidObject* _hadBySecondaryLocation_SolidObject){
this->hadBySecondaryLocation_SolidObject= _hadBySecondaryLocation_SolidObject;
}
void PhysicalLocation::sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void PhysicalLocation::sethasSolidObject_PrimaryLocation(SolidObject* _hasSolidObject_PrimaryLocation){
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
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["hasPhysicalLocation_Timestamp"]="'" + hasPhysicalLocation_Timestamp + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << PhysicalLocationID;
data["PhysicalLocationID"]=ss.str();
if(hadBySecondaryLocation_SolidObject!=NULL)
data["hadBySecondaryLocation_SolidObject"]="'" +hadBySecondaryLocation_SolidObject->getname() + "'";
else 
 data["hadBySecondaryLocation_SolidObject"]="null";
if(hasPhysicalLocation_RefObject!=NULL)
data["hasPhysicalLocation_RefObject"]="'" +hasPhysicalLocation_RefObject->getname() + "'";
else 
 data["hasPhysicalLocation_RefObject"]="null";
if(hasSolidObject_PrimaryLocation!=NULL)
data["hasSolidObject_PrimaryLocation"]="'" +hasSolidObject_PrimaryLocation->getname() + "'";
else 
 data["hasSolidObject_PrimaryLocation"]="null";
dao  = new DAO("PhysicalLocation");
dao->set(data);
delete (dao);
}
void PhysicalLocation::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
data["hasPhysicalLocation_Timestamp"]="'" + hasPhysicalLocation_Timestamp+ "'";
ss.str("");
ss << temp0->getDataThingID();
data["PhysicalLocationID"]=ss.str();
if(hadBySecondaryLocation_SolidObject!=NULL)
data["hadBySecondaryLocation_SolidObject"]="'" + hadBySecondaryLocation_SolidObject->getname() + "'";
if(hasPhysicalLocation_RefObject!=NULL)
data["hasPhysicalLocation_RefObject"]="'" + hasPhysicalLocation_RefObject->getname() + "'";
if(hasSolidObject_PrimaryLocation!=NULL)
data["hasSolidObject_PrimaryLocation"]="'" + hasSolidObject_PrimaryLocation->getname() + "'";
dao  = new DAO("PhysicalLocation");
dao->insert(data);
delete (dao);
this->set(name);
}

void PhysicalLocation::copy(std::map<std::string,std::string> object){delete(hadBySecondaryLocation_SolidObject);
hadBySecondaryLocation_SolidObject=NULL;
delete(hasPhysicalLocation_RefObject);
hasPhysicalLocation_RefObject=NULL;
delete(hasSolidObject_PrimaryLocation);
hasSolidObject_PrimaryLocation=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PhysicalLocation*> tmp;
this->hasPhysicalLocation_Timestamp = object["PhysicalLocation.hasPhysicalLocation_Timestamp"];
this->name = object["PhysicalLocation._NAME"];
this->PhysicalLocationID = std::atof(object["PhysicalLocation.PhysicalLocationID"].c_str());
if(this->hadBySecondaryLocation_SolidObject== NULL && object["hadBySecondaryLocation_SolidObject/SolidObject._NAME"]!=""){
this->hadBySecondaryLocation_SolidObject = new SolidObject(object["hadBySecondaryLocation_SolidObject/SolidObject._NAME"]);
}
if(this->hasPhysicalLocation_RefObject== NULL && object["hasPhysicalLocation_RefObject/SolidObject._NAME"]!=""){
this->hasPhysicalLocation_RefObject = new SolidObject(object["hasPhysicalLocation_RefObject/SolidObject._NAME"]);
}
if(this->hasSolidObject_PrimaryLocation== NULL && object["hasSolidObject_PrimaryLocation/SolidObject._NAME"]!=""){
this->hasSolidObject_PrimaryLocation = new SolidObject(object["hasSolidObject_PrimaryLocation/SolidObject._NAME"]);
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
