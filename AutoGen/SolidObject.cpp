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


 #include "EndEffector.h"
 #include "KittingWorkstation.h"
 #include "PhysicalLocation.h"
 #include "DAO.h"
 #include "WorkTable.h"

SolidObject::SolidObject(std::string name){
this->name=name;dao = NULL;
hadByObject_KittingWorkstation = NULL;
hadByObjectOnTable_WorkTable = NULL;
hasSolidObject_PrimaryLocation = NULL;
hasEndEffector_HeldObject = NULL;

}SolidObject::~SolidObject(){
delete(hadByObject_KittingWorkstation);
delete(hadByObjectOnTable_WorkTable);
delete(hasSolidObject_PrimaryLocation);
delete(hasEndEffector_HeldObject);
for(std::size_t i = 0; i < hadBySecondaryLocation_SolidObject.size(); i++)
delete(hadBySecondaryLocation_SolidObject[i]);
for(std::size_t i = 0; i < hasPhysicalLocation_RefObject.size(); i++)
delete(hasPhysicalLocation_RefObject[i]);
}
int SolidObject::getSolidObjectID(){
return SolidObjectID;
}
DAO* SolidObject::getdao(){
return dao;
}
std::vector<PhysicalLocation*> SolidObject::gethadBySecondaryLocation_SolidObject(){
return hadBySecondaryLocation_SolidObject;
}
KittingWorkstation* SolidObject::gethadByObject_KittingWorkstation(){
return hadByObject_KittingWorkstation;
}
WorkTable* SolidObject::gethadByObjectOnTable_WorkTable(){
return hadByObjectOnTable_WorkTable;
}
PhysicalLocation* SolidObject::gethasSolidObject_PrimaryLocation(){
return hasSolidObject_PrimaryLocation;
}
EndEffector* SolidObject::gethasEndEffector_HeldObject(){
return hasEndEffector_HeldObject;
}
std::vector<PhysicalLocation*> SolidObject::gethasPhysicalLocation_RefObject(){
return hasPhysicalLocation_RefObject;
}
std::string SolidObject::getname(){
return name;
}
void SolidObject::setSolidObjectID(int _SolidObjectID){
this->SolidObjectID= _SolidObjectID;
}
void SolidObject::setdao(DAO* _dao){
this->dao= _dao;
}
void SolidObject::sethadBySecondaryLocation_SolidObject(std::vector<PhysicalLocation*> _hadBySecondaryLocation_SolidObject){
this->hadBySecondaryLocation_SolidObject= _hadBySecondaryLocation_SolidObject;
}
void SolidObject::sethadByObject_KittingWorkstation(KittingWorkstation* _hadByObject_KittingWorkstation){
this->hadByObject_KittingWorkstation= _hadByObject_KittingWorkstation;
}
void SolidObject::sethadByObjectOnTable_WorkTable(WorkTable* _hadByObjectOnTable_WorkTable){
this->hadByObjectOnTable_WorkTable= _hadByObjectOnTable_WorkTable;
}
void SolidObject::sethasSolidObject_PrimaryLocation(PhysicalLocation* _hasSolidObject_PrimaryLocation){
this->hasSolidObject_PrimaryLocation= _hasSolidObject_PrimaryLocation;
}
void SolidObject::sethasEndEffector_HeldObject(EndEffector* _hasEndEffector_HeldObject){
this->hasEndEffector_HeldObject= _hasEndEffector_HeldObject;
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
data["name"]="'" + name + "'";
ss.str("");
ss << SolidObjectID;
data["SolidObjectID"]=ss.str();
for(unsigned int i=0;i<hadBySecondaryLocation_SolidObject.size();++i){
ss.str("");
hadBySecondaryLocation_SolidObject[i]->get(hadBySecondaryLocation_SolidObject[i]->getname());
ss << hadBySecondaryLocation_SolidObject[i]->getPhysicalLocationID();
data["hadBySecondaryLocation_SolidObject"]=data["hadBySecondaryLocation_SolidObject"]+" "+ss.str();
}
if(hadByObject_KittingWorkstation!=NULL)
data["hadByObject_KittingWorkstation"]="'" +hadByObject_KittingWorkstation->getname() + "'";
else 
 data["hadByObject_KittingWorkstation"]="null";
if(hadByObjectOnTable_WorkTable!=NULL)
data["hadByObjectOnTable_WorkTable"]="'" +hadByObjectOnTable_WorkTable->getname() + "'";
else 
 data["hadByObjectOnTable_WorkTable"]="null";
if(hasSolidObject_PrimaryLocation!=NULL)
data["hasSolidObject_PrimaryLocation"]="'" +hasSolidObject_PrimaryLocation->getname() + "'";
else 
 data["hasSolidObject_PrimaryLocation"]="null";
if(hasEndEffector_HeldObject!=NULL)
data["hasEndEffector_HeldObject"]="'" +hasEndEffector_HeldObject->getname() + "'";
else 
 data["hasEndEffector_HeldObject"]="null";
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
void SolidObject::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

if(hadByObject_KittingWorkstation!=NULL)
data["hadByObject_KittingWorkstation"]="'" + hadByObject_KittingWorkstation->getname() + "'";
if(hadByObjectOnTable_WorkTable!=NULL)
data["hadByObjectOnTable_WorkTable"]="'" + hadByObjectOnTable_WorkTable->getname() + "'";
if(hasSolidObject_PrimaryLocation!=NULL)
data["hasSolidObject_PrimaryLocation"]="'" + hasSolidObject_PrimaryLocation->getname() + "'";
if(hasEndEffector_HeldObject!=NULL)
data["hasEndEffector_HeldObject"]="'" + hasEndEffector_HeldObject->getname() + "'";
dao  = new DAO("SolidObject");
dao->insert(data);
delete (dao);
this->set(name);
}

void SolidObject::copy(std::map<std::string,std::string> object){for(std::size_t i = 0; i < hadBySecondaryLocation_SolidObject.size(); i++){
hadBySecondaryLocation_SolidObject[i]=NULL;}
hadBySecondaryLocation_SolidObject.clear();
hadByObject_KittingWorkstation=NULL;
hadByObjectOnTable_WorkTable=NULL;
hasSolidObject_PrimaryLocation=NULL;
hasEndEffector_HeldObject=NULL;
for(std::size_t i = 0; i < hasPhysicalLocation_RefObject.size(); i++){
hasPhysicalLocation_RefObject[i]=NULL;}
hasPhysicalLocation_RefObject.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<SolidObject*> tmp;
this->name = object["SolidObject._NAME"];
this->SolidObjectID = std::atof(object["SolidObject.SolidObjectID"].c_str());
if(this->hadBySecondaryLocation_SolidObject.empty() && object["hadBySecondaryLocation_SolidObject/PhysicalLocation._NAME"]!=""){
temp = Explode(object["hadBySecondaryLocation_SolidObject/PhysicalLocation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadBySecondaryLocation_SolidObject.push_back(new PhysicalLocation(temp[i]));
}
}
if(this->hadByObject_KittingWorkstation== NULL && object["hadByObject_KittingWorkstation/KittingWorkstation._NAME"]!=""){
this->hadByObject_KittingWorkstation = new KittingWorkstation(object["hadByObject_KittingWorkstation/KittingWorkstation._NAME"]);
}
if(this->hadByObjectOnTable_WorkTable== NULL && object["hadByObjectOnTable_WorkTable/WorkTable._NAME"]!=""){
this->hadByObjectOnTable_WorkTable = new WorkTable(object["hadByObjectOnTable_WorkTable/WorkTable._NAME"]);
}
if(this->hasSolidObject_PrimaryLocation== NULL && object["hasSolidObject_PrimaryLocation/PhysicalLocation._NAME"]!=""){
this->hasSolidObject_PrimaryLocation = new PhysicalLocation(object["hasSolidObject_PrimaryLocation/PhysicalLocation._NAME"]);
}
if(this->hasEndEffector_HeldObject== NULL && object["hasEndEffector_HeldObject/EndEffector._NAME"]!=""){
this->hasEndEffector_HeldObject = new EndEffector(object["hasEndEffector_HeldObject/EndEffector._NAME"]);
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
