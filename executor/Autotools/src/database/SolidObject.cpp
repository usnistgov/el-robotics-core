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

#include "SolidObject.h"


 #include "PhysicalLocation.h"
 #include "DAO.h"
 #include "WorkTable.h"

SolidObject::SolidObject(std::string name){
this->name=name;dao = NULL;
hasSolidObject_PrimaryLocation = NULL;
hadBySolidObject_WorkTable = NULL;

}SolidObject::~SolidObject(){
delete(dao);
delete(hasSolidObject_PrimaryLocation);
delete(hadBySolidObject_WorkTable);
for(std::size_t i = 0; i < hasSolidObject_SecondaryLocation.size(); i++)
delete(hasSolidObject_SecondaryLocation[i]);
for(std::size_t i = 0; i < hasPhysicalLocation_RefObject.size(); i++)
delete(hasPhysicalLocation_RefObject[i]);
}
int SolidObject::getSolidObjectID(){
return SolidObjectID;
}
DAO* SolidObject::getdao(){
return dao;
}
std::vector<PhysicalLocation*> SolidObject::gethasSolidObject_SecondaryLocation(){
return hasSolidObject_SecondaryLocation;
}
PhysicalLocation* SolidObject::gethasSolidObject_PrimaryLocation(){
return hasSolidObject_PrimaryLocation;
}
WorkTable* SolidObject::gethadBySolidObject_WorkTable(){
return hadBySolidObject_WorkTable;
}
std::vector<PhysicalLocation*> SolidObject::gethasPhysicalLocation_RefObject(){
return hasPhysicalLocation_RefObject;
}
std::string SolidObject::getname(){
return name;
}
void SolidObject::setdao(DAO* _dao){
this->dao= _dao;
}
void SolidObject::sethasSolidObject_SecondaryLocation(std::vector<PhysicalLocation*> _hasSolidObject_SecondaryLocation){
this->hasSolidObject_SecondaryLocation= _hasSolidObject_SecondaryLocation;
}
void SolidObject::sethasSolidObject_PrimaryLocation(PhysicalLocation* _hasSolidObject_PrimaryLocation){
this->hasSolidObject_PrimaryLocation= _hasSolidObject_PrimaryLocation;
}
void SolidObject::sethadBySolidObject_WorkTable(WorkTable* _hadBySolidObject_WorkTable){
this->hadBySolidObject_WorkTable= _hadBySolidObject_WorkTable;
}
void SolidObject::sethasPhysicalLocation_RefObject(std::vector<PhysicalLocation*> _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void SolidObject::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void SolidObject::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["name"]=name;
ss.str("");
ss << SolidObjectID;
data["SolidObjectID"]=ss.str();
for(unsigned int i=0;i<hasSolidObject_SecondaryLocation.size();++i){
ss.str("");
hasSolidObject_SecondaryLocation[i]->get(hasSolidObject_SecondaryLocation[i]->getname());
ss << hasSolidObject_SecondaryLocation[i]->getPhysicalLocationID();
data["hasSolidObject_SecondaryLocation"]=data["hasSolidObject_SecondaryLocation"]+" "+ss.str();
}
if(hasSolidObject_PrimaryLocation!=NULL)
data["hasSolidObject_PrimaryLocation"]=hasSolidObject_PrimaryLocation->getname();
if(hadBySolidObject_WorkTable!=NULL)
data["hadBySolidObject_WorkTable"]=hadBySolidObject_WorkTable->getname();
for(unsigned int i=0;i<hasPhysicalLocation_RefObject.size();++i){
ss.str("");
hasPhysicalLocation_RefObject[i]->get(hasPhysicalLocation_RefObject[i]->getname());
ss << hasPhysicalLocation_RefObject[i]->getPhysicalLocationID();
data["hasPhysicalLocation_RefObject"]=data["hasPhysicalLocation_RefObject"]+" "+ss.str();
}
dao  = new DAO("SolidObject");
dao->set(data);
delete (dao);
}

void SolidObject::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<SolidObject*> tmp;
this->name = object["SolidObject._NAME"];
this->SolidObjectID = std::atof(object["SolidObject.SolidObjectID"].c_str());
if(this->hasSolidObject_SecondaryLocation.empty() && object["hasSolidObject_SecondaryLocation/PhysicalLocation._NAME"]!=""){
temp = Explode(object["hasSolidObject_SecondaryLocation/PhysicalLocation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSolidObject_SecondaryLocation.push_back(new PhysicalLocation(temp[i]));
}
}
if(this->hasSolidObject_PrimaryLocation== NULL && object["hasSolidObject_PrimaryLocation/PhysicalLocation._NAME"]!=""){
this->hasSolidObject_PrimaryLocation = new PhysicalLocation(object["hasSolidObject_PrimaryLocation/PhysicalLocation._NAME"]);
}
if(this->hadBySolidObject_WorkTable== NULL && object["hadBySolidObject_WorkTable/WorkTable._NAME"]!=""){
this->hadBySolidObject_WorkTable = new WorkTable(object["hadBySolidObject_WorkTable/WorkTable._NAME"]);
}
if(this->hasPhysicalLocation_RefObject.empty() && object["hasPhysicalLocation_RefObject/PhysicalLocation._NAME"]!=""){
temp = Explode(object["hasPhysicalLocation_RefObject/PhysicalLocation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPhysicalLocation_RefObject.push_back(new PhysicalLocation(temp[i]));
}
}

}std::vector<std::string> SolidObject::Explode(const std::string & str, char separator )
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
