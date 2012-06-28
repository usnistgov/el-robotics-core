#include "SolidObject.h"


 #include "PhysicalLocation.h"
 #include "DAO.h"
 #include "WorkTable.h"

SolidObject::SolidObject(std::string name){
this->name=name;dao = NULL;
hadBySolidObject_WorkTable = NULL;
hasSolidObject_PhysicalLocation = NULL;

}SolidObject::~SolidObject(){
delete(dao);
delete(hadBySolidObject_WorkTable);
delete(hasSolidObject_PhysicalLocation);
for(std::size_t i = 0; i < hasPhysicalLocation_RefObject.size(); i++)
delete(hasPhysicalLocation_RefObject[i]);
}
std::string SolidObject::getname(){
return name;
}
int SolidObject::getSolidObjectID(){
return SolidObjectID;
}
DAO* SolidObject::getdao(){
return dao;
}
WorkTable* SolidObject::gethadBySolidObject_WorkTable(){
return hadBySolidObject_WorkTable;
}
PhysicalLocation* SolidObject::gethasSolidObject_PhysicalLocation(){
return hasSolidObject_PhysicalLocation;
}
std::vector<PhysicalLocation*>* SolidObject::gethasPhysicalLocation_RefObject(){
return &hasPhysicalLocation_RefObject;
}
void SolidObject::setdao(DAO* _dao){
this->dao= _dao;
}
void SolidObject::sethadBySolidObject_WorkTable(WorkTable* _hadBySolidObject_WorkTable){
this->hadBySolidObject_WorkTable= _hadBySolidObject_WorkTable;
}
void SolidObject::sethasSolidObject_PhysicalLocation(PhysicalLocation* _hasSolidObject_PhysicalLocation){
this->hasSolidObject_PhysicalLocation= _hasSolidObject_PhysicalLocation;
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
data["hadBySolidObject_WorkTable"]=hadBySolidObject_WorkTable->getname();
data["hasSolidObject_PhysicalLocation"]=hasSolidObject_PhysicalLocation->getname();
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
if(this->hadBySolidObject_WorkTable== NULL && object["hadBySolidObject_WorkTable/WorkTable._NAME"]!=""){
this->hadBySolidObject_WorkTable = new WorkTable(object["hadBySolidObject_WorkTable/WorkTable._NAME"]);
}
if(this->hasSolidObject_PhysicalLocation== NULL && object["hasSolidObject_PhysicalLocation/PhysicalLocation._NAME"]!=""){
this->hasSolidObject_PhysicalLocation = new PhysicalLocation(object["hasSolidObject_PhysicalLocation/PhysicalLocation._NAME"]);
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
