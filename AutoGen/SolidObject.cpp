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


 #include "ExternalShape.h"
 #include "PhysicalLocation.h"
 #include "DAO.h"
 #include "InternalShape.h"
 #include "EndEffector.h"
 #include "WorkTable.h"

SolidObject::SolidObject(std::string name){
this->name=name;dao = NULL;
hasSolidObject_InternalShape = NULL;
hasSolidObject_PrimaryLocation = NULL;
hadBySolidObject_WorkTable = NULL;
hasSolidObject_ExternalShape = NULL;

}SolidObject::~SolidObject(){
delete(hasSolidObject_InternalShape);
delete(hasSolidObject_PrimaryLocation);
delete(hadBySolidObject_WorkTable);
delete(hasSolidObject_ExternalShape);
for(std::size_t i = 0; i < hasSolidObject_SecondaryLocation.size(); i++)
delete(hasSolidObject_SecondaryLocation[i]);
for(std::size_t i = 0; i < hasPhysicalLocation_RefObject.size(); i++)
delete(hasPhysicalLocation_RefObject[i]);
for(std::size_t i = 0; i < hasEndEffector_HeldObject.size(); i++)
delete(hasEndEffector_HeldObject[i]);
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
InternalShape* SolidObject::gethasSolidObject_InternalShape(){
return hasSolidObject_InternalShape;
}
PhysicalLocation* SolidObject::gethasSolidObject_PrimaryLocation(){
return hasSolidObject_PrimaryLocation;
}
WorkTable* SolidObject::gethadBySolidObject_WorkTable(){
return hadBySolidObject_WorkTable;
}
ExternalShape* SolidObject::gethasSolidObject_ExternalShape(){
return hasSolidObject_ExternalShape;
}
std::vector<PhysicalLocation*> SolidObject::gethasPhysicalLocation_RefObject(){
return hasPhysicalLocation_RefObject;
}
std::vector<EndEffector*> SolidObject::gethasEndEffector_HeldObject(){
return hasEndEffector_HeldObject;
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
void SolidObject::sethasSolidObject_InternalShape(InternalShape* _hasSolidObject_InternalShape){
this->hasSolidObject_InternalShape= _hasSolidObject_InternalShape;
}
void SolidObject::sethasSolidObject_PrimaryLocation(PhysicalLocation* _hasSolidObject_PrimaryLocation){
this->hasSolidObject_PrimaryLocation= _hasSolidObject_PrimaryLocation;
}
void SolidObject::sethadBySolidObject_WorkTable(WorkTable* _hadBySolidObject_WorkTable){
this->hadBySolidObject_WorkTable= _hadBySolidObject_WorkTable;
}
void SolidObject::sethasSolidObject_ExternalShape(ExternalShape* _hasSolidObject_ExternalShape){
this->hasSolidObject_ExternalShape= _hasSolidObject_ExternalShape;
}
void SolidObject::sethasPhysicalLocation_RefObject(std::vector<PhysicalLocation*> _hasPhysicalLocation_RefObject){
this->hasPhysicalLocation_RefObject= _hasPhysicalLocation_RefObject;
}
void SolidObject::sethasEndEffector_HeldObject(std::vector<EndEffector*> _hasEndEffector_HeldObject){
this->hasEndEffector_HeldObject= _hasEndEffector_HeldObject;
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
if(hasSolidObject_InternalShape!=NULL)
data["hasSolidObject_InternalShape"]=hasSolidObject_InternalShape->getname();
if(hasSolidObject_PrimaryLocation!=NULL)
data["hasSolidObject_PrimaryLocation"]=hasSolidObject_PrimaryLocation->getname();
if(hadBySolidObject_WorkTable!=NULL)
data["hadBySolidObject_WorkTable"]=hadBySolidObject_WorkTable->getname();
if(hasSolidObject_ExternalShape!=NULL)
data["hasSolidObject_ExternalShape"]=hasSolidObject_ExternalShape->getname();
for(unsigned int i=0;i<hasPhysicalLocation_RefObject.size();++i){
ss.str("");
hasPhysicalLocation_RefObject[i]->get(hasPhysicalLocation_RefObject[i]->getname());
ss << hasPhysicalLocation_RefObject[i]->getPhysicalLocationID();
data["hasPhysicalLocation_RefObject"]=data["hasPhysicalLocation_RefObject"]+" "+ss.str();
}
for(unsigned int i=0;i<hasEndEffector_HeldObject.size();++i){
ss.str("");
hasEndEffector_HeldObject[i]->get(hasEndEffector_HeldObject[i]->getname());
ss << hasEndEffector_HeldObject[i]->getEndEffectorID();
data["hasEndEffector_HeldObject"]=data["hasEndEffector_HeldObject"]+" "+ss.str();
}
dao  = new DAO("SolidObject");
dao->set(data);
delete (dao);
}

void SolidObject::copy(std::map<std::string,std::string> object){delete(hasSolidObject_InternalShape);
hasSolidObject_InternalShape=NULL;
delete(hasSolidObject_PrimaryLocation);
hasSolidObject_PrimaryLocation=NULL;
delete(hadBySolidObject_WorkTable);
hadBySolidObject_WorkTable=NULL;
delete(hasSolidObject_ExternalShape);
hasSolidObject_ExternalShape=NULL;
for(std::size_t i = 0; i < hasSolidObject_SecondaryLocation.size(); i++){
delete(hasSolidObject_SecondaryLocation[i]);
hasSolidObject_SecondaryLocation[i]=NULL;}
for(std::size_t i = 0; i < hasPhysicalLocation_RefObject.size(); i++){
delete(hasPhysicalLocation_RefObject[i]);
hasPhysicalLocation_RefObject[i]=NULL;}
for(std::size_t i = 0; i < hasEndEffector_HeldObject.size(); i++){
delete(hasEndEffector_HeldObject[i]);
hasEndEffector_HeldObject[i]=NULL;}
std::vector<std::string> temp;
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
if(this->hasSolidObject_InternalShape== NULL && object["hasSolidObject_InternalShape/InternalShape._NAME"]!=""){
this->hasSolidObject_InternalShape = new InternalShape(object["hasSolidObject_InternalShape/InternalShape._NAME"]);
}
if(this->hasSolidObject_PrimaryLocation== NULL && object["hasSolidObject_PrimaryLocation/PhysicalLocation._NAME"]!=""){
this->hasSolidObject_PrimaryLocation = new PhysicalLocation(object["hasSolidObject_PrimaryLocation/PhysicalLocation._NAME"]);
}
if(this->hadBySolidObject_WorkTable== NULL && object["hadBySolidObject_WorkTable/WorkTable._NAME"]!=""){
this->hadBySolidObject_WorkTable = new WorkTable(object["hadBySolidObject_WorkTable/WorkTable._NAME"]);
}
if(this->hasSolidObject_ExternalShape== NULL && object["hasSolidObject_ExternalShape/ExternalShape._NAME"]!=""){
this->hasSolidObject_ExternalShape = new ExternalShape(object["hasSolidObject_ExternalShape/ExternalShape._NAME"]);
}
if(this->hasPhysicalLocation_RefObject.empty() && object["hasPhysicalLocation_RefObject/PhysicalLocation._NAME"]!=""){
temp = Explode(object["hasPhysicalLocation_RefObject/PhysicalLocation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPhysicalLocation_RefObject.push_back(new PhysicalLocation(temp[i]));
}
}
if(this->hasEndEffector_HeldObject.empty() && object["hasEndEffector_HeldObject/EndEffector._NAME"]!=""){
temp = Explode(object["hasEndEffector_HeldObject/EndEffector._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasEndEffector_HeldObject.push_back(new EndEffector(temp[i]));
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
