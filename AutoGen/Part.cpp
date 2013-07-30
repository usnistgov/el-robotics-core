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


 #include "StockKeepingUnit.h"
 #include "PartsTrayWithParts.h"
 #include "Slot.h"
 #include "Kit.h"
 #include "DAO.h"

Part::Part(std::string name) : SolidObject(name){
dao = NULL;
hadByPart_Kit = NULL;
hadByPart_PartsTrayWithParts = NULL;
hasPart_Sku = NULL;

}Part::~Part(){
delete(hadByPart_Kit);
delete(hadByPart_PartsTrayWithParts);
delete(hasPart_Sku);
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
Kit* Part::gethadByPart_Kit(){
return hadByPart_Kit;
}
PartsTrayWithParts* Part::gethadByPart_PartsTrayWithParts(){
return hadByPart_PartsTrayWithParts;
}
StockKeepingUnit* Part::gethasPart_Sku(){
return hasPart_Sku;
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
void Part::sethadByPart_Kit(Kit* _hadByPart_Kit){
this->hadByPart_Kit= _hadByPart_Kit;
}
void Part::sethadByPart_PartsTrayWithParts(PartsTrayWithParts* _hadByPart_PartsTrayWithParts){
this->hadByPart_PartsTrayWithParts= _hadByPart_PartsTrayWithParts;
}
void Part::sethasPart_Sku(StockKeepingUnit* _hasPart_Sku){
this->hasPart_Sku= _hasPart_Sku;
}
void Part::sethasSlot_Part(std::vector<Slot*> _hasSlot_Part){
this->hasSlot_Part= _hasSlot_Part;
}
void Part::get(std::string name){
std::map<std::string,std::string> temp;
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
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasPart_SerialNumber"]="'" + hasPart_SerialNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << PartID;
data["PartID"]=ss.str();
if(hadByPart_Kit!=NULL)
data["hadByPart_Kit"]=hadByPart_Kit->getname();
if(hadByPart_PartsTrayWithParts!=NULL)
data["hadByPart_PartsTrayWithParts"]=hadByPart_PartsTrayWithParts->getname();
if(hasPart_Sku!=NULL)
data["hasPart_Sku"]=hasPart_Sku->getname();
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

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
data["hasPart_SerialNumber"]="'" + hasPart_SerialNumber+ "'";
ss.str("");
ss << temp0->getSolidObjectID();
data["PartID"]=ss.str();
if(hadByPart_Kit!=NULL)
data["hadByPart_Kit"]=hadByPart_Kit->getname();
if(hadByPart_PartsTrayWithParts!=NULL)
data["hadByPart_PartsTrayWithParts"]=hadByPart_PartsTrayWithParts->getname();
if(hasPart_Sku!=NULL)
data["hasPart_Sku"]=hasPart_Sku->getname();
dao  = new DAO("Part");
dao->insert(data);
delete (dao);
this->set(name);
}

void Part::copy(std::map<std::string,std::string> object){delete(hadByPart_Kit);
hadByPart_Kit=NULL;
delete(hadByPart_PartsTrayWithParts);
hadByPart_PartsTrayWithParts=NULL;
delete(hasPart_Sku);
hasPart_Sku=NULL;
for(std::size_t i = 0; i < hasSlot_Part.size(); i++){
delete(hasSlot_Part[i]);
hasSlot_Part[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Part*> tmp;
this->hasPart_SerialNumber = object["Part.hasPart_SerialNumber"];
this->name = object["Part._NAME"];
this->PartID = std::atof(object["Part.PartID"].c_str());
if(this->hadByPart_Kit== NULL && object["hadByPart_Kit/Kit._NAME"]!=""){
this->hadByPart_Kit = new Kit(object["hadByPart_Kit/Kit._NAME"]);
}
if(this->hadByPart_PartsTrayWithParts== NULL && object["hadByPart_PartsTrayWithParts/PartsTrayWithParts._NAME"]!=""){
this->hadByPart_PartsTrayWithParts = new PartsTrayWithParts(object["hadByPart_PartsTrayWithParts/PartsTrayWithParts._NAME"]);
}
if(this->hasPart_Sku== NULL && object["hasPart_Sku/StockKeepingUnit._NAME"]!=""){
this->hasPart_Sku = new StockKeepingUnit(object["hasPart_Sku/StockKeepingUnit._NAME"]);
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
