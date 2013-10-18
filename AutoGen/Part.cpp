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

#include "Part.h"


 #include "Slot.h"
 #include "Kit.h"
 #include "DAO.h"
 #include "PartsVessel.h"

Part::Part(std::string name) : SkuObject(name){
dao = NULL;
hadByPart_PartsVessel = NULL;
hadByPart_Kit = NULL;

}Part::~Part(){
delete(hadByPart_PartsVessel);
delete(hadByPart_Kit);
for(std::size_t i = 0; i < hasSlot_Part.size(); i++)
delete(hasSlot_Part[i]);
}
std::string Part::gethasPart_SerialNumber(){
return hasPart_SerialNumber;
}
int Part::getPartID(){
return PartID;
}
DAO* Part::getdao(){
return dao;
}
PartsVessel* Part::gethadByPart_PartsVessel(){
return hadByPart_PartsVessel;
}
Kit* Part::gethadByPart_Kit(){
return hadByPart_Kit;
}
std::vector<Slot*> Part::gethasSlot_Part(){
return hasSlot_Part;
}
void Part::sethasPart_SerialNumber(std::string _hasPart_SerialNumber){
this->hasPart_SerialNumber= _hasPart_SerialNumber;
}
void Part::setPartID(int _PartID){
this->PartID= _PartID;
}
void Part::setdao(DAO* _dao){
this->dao= _dao;
}
void Part::sethadByPart_PartsVessel(PartsVessel* _hadByPart_PartsVessel){
this->hadByPart_PartsVessel= _hadByPart_PartsVessel;
}
void Part::sethadByPart_Kit(Kit* _hadByPart_Kit){
this->hadByPart_Kit= _hadByPart_Kit;
}
void Part::sethasSlot_Part(std::vector<Slot*> _hasSlot_Part){
this->hasSlot_Part= _hasSlot_Part;
}
void Part::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SkuObject");
 temp = dao->get(name);delete (dao);
 SkuObject::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("Part");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Part::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SkuObject* temp0 = (SkuObject*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["hasPart_SerialNumber"]="'" + hasPart_SerialNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << PartID;
data["PartID"]=ss.str();
if(hadByPart_PartsVessel!=NULL)
data["hadByPart_PartsVessel"]="'" +hadByPart_PartsVessel->getname() + "'";
else 
 data["hadByPart_PartsVessel"]="null";
if(hadByPart_Kit!=NULL)
data["hadByPart_Kit"]="'" +hadByPart_Kit->getname() + "'";
else 
 data["hadByPart_Kit"]="null";
for(unsigned int i=0;i<hasSlot_Part.size();++i){
ss.str("");
hasSlot_Part[i]->get(hasSlot_Part[i]->getname());
ss << hasSlot_Part[i]->getSlotID();
data["hasSlot_Part"]=data["hasSlot_Part"]+" "+ss.str();
}
dao  = new DAO("Part");
dao->set(data);
delete (dao);
}
void Part::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp1 = (SolidObject*) this;
temp1->insert(name);
temp1->get(name);
SkuObject* temp0 = (SkuObject*) this;
temp0->setSkuObjectID(temp1->getSolidObjectID());
temp0->insert(name);
data["hasPart_SerialNumber"]="'" + hasPart_SerialNumber+ "'";
ss.str("");
ss << temp1->getSolidObjectID();
data["PartID"]=ss.str();
if(hadByPart_PartsVessel!=NULL)
data["hadByPart_PartsVessel"]="'" + hadByPart_PartsVessel->getname() + "'";
if(hadByPart_Kit!=NULL)
data["hadByPart_Kit"]="'" + hadByPart_Kit->getname() + "'";
dao  = new DAO("Part");
dao->insert(data);
delete (dao);
this->set(name);
}

void Part::copy(std::map<std::string,std::string> object){hadByPart_PartsVessel=NULL;
hadByPart_Kit=NULL;
for(std::size_t i = 0; i < hasSlot_Part.size(); i++){
hasSlot_Part[i]=NULL;}
hasSlot_Part.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Part*> tmp;
this->hasPart_SerialNumber = object["Part.hasPart_SerialNumber"];
this->name = object["Part._NAME"];
this->PartID = std::atof(object["Part.PartID"].c_str());
if(this->hadByPart_PartsVessel== NULL && object["hadByPart_PartsVessel/PartsVessel._NAME"]!=""){
this->hadByPart_PartsVessel = new PartsVessel(object["hadByPart_PartsVessel/PartsVessel._NAME"]);
}
if(this->hadByPart_Kit== NULL && object["hadByPart_Kit/Kit._NAME"]!=""){
this->hadByPart_Kit = new Kit(object["hadByPart_Kit/Kit._NAME"]);
}
if(this->hasSlot_Part.empty() && object["hasSlot_Part/Slot._NAME"]!=""){
temp = Explode(object["hasSlot_Part/Slot._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSlot_Part.push_back(new Slot(temp[i]));
}
}

}std::vector<std::string> Part::Explode(const std::string & str, char separator )
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
