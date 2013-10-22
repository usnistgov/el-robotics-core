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

#include "PartsVessel.h"


 #include "StockKeepingUnit.h"
 #include "DAO.h"
 #include "Part.h"

PartsVessel::PartsVessel(std::string name) : SkuObject(name){
dao = NULL;
hasPartsVessel_PartSku = NULL;

}PartsVessel::~PartsVessel(){
delete(hasPartsVessel_PartSku);
for(std::size_t i = 0; i < hadByPart_PartsVessel.size(); i++)
delete(hadByPart_PartsVessel[i]);
}
std::string PartsVessel::gethasPartsVessel_PartQuantity(){
return hasPartsVessel_PartQuantity;
}
std::string PartsVessel::gethasPartsVessel_SerialNumber(){
return hasPartsVessel_SerialNumber;
}
int PartsVessel::getPartsVesselID(){
return PartsVesselID;
}
DAO* PartsVessel::getdao(){
return dao;
}
StockKeepingUnit* PartsVessel::gethasPartsVessel_PartSku(){
return hasPartsVessel_PartSku;
}
std::vector<Part*> PartsVessel::gethadByPart_PartsVessel(){
return hadByPart_PartsVessel;
}
void PartsVessel::sethasPartsVessel_PartQuantity(std::string _hasPartsVessel_PartQuantity){
this->hasPartsVessel_PartQuantity= _hasPartsVessel_PartQuantity;
}
void PartsVessel::sethasPartsVessel_SerialNumber(std::string _hasPartsVessel_SerialNumber){
this->hasPartsVessel_SerialNumber= _hasPartsVessel_SerialNumber;
}
void PartsVessel::setPartsVesselID(int _PartsVesselID){
this->PartsVesselID= _PartsVesselID;
}
void PartsVessel::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsVessel::sethasPartsVessel_PartSku(StockKeepingUnit* _hasPartsVessel_PartSku){
this->hasPartsVessel_PartSku= _hasPartsVessel_PartSku;
}
void PartsVessel::sethadByPart_PartsVessel(std::vector<Part*> _hadByPart_PartsVessel){
this->hadByPart_PartsVessel= _hadByPart_PartsVessel;
}
void PartsVessel::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SkuObject");
 temp = dao->get(name);delete (dao);
 SkuObject::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("PartsVessel");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PartsVessel::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SkuObject* temp0 = (SkuObject*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["hasPartsVessel_PartQuantity"]="'" + hasPartsVessel_PartQuantity + "'";
data["hasPartsVessel_SerialNumber"]="'" + hasPartsVessel_SerialNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << PartsVesselID;
data["PartsVesselID"]=ss.str();
if(hasPartsVessel_PartSku!=NULL)
data["hasPartsVessel_PartSku"]="'" +hasPartsVessel_PartSku->getname() + "'";
else 
 data["hasPartsVessel_PartSku"]="null";
for(unsigned int i=0;i<hadByPart_PartsVessel.size();++i){
ss.str("");
hadByPart_PartsVessel[i]->get(hadByPart_PartsVessel[i]->getname());
ss << hadByPart_PartsVessel[i]->getPartID();
data["hadByPart_PartsVessel"]=data["hadByPart_PartsVessel"]+" "+ss.str();
}
dao  = new DAO("PartsVessel");
dao->set(data);
delete (dao);
}
void PartsVessel::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp1 = (SolidObject*) this;
temp1->insert(name);
temp1->get(name);
SkuObject* temp0 = (SkuObject*) this;
temp0->setSkuObjectID(temp1->getSolidObjectID());
temp0->insert(name);
data["hasPartsVessel_PartQuantity"]="'" + hasPartsVessel_PartQuantity+ "'";
data["hasPartsVessel_SerialNumber"]="'" + hasPartsVessel_SerialNumber+ "'";
ss.str("");
ss << temp1->getSolidObjectID();
data["PartsVesselID"]=ss.str();
if(hasPartsVessel_PartSku!=NULL)
data["hasPartsVessel_PartSku"]="'" + hasPartsVessel_PartSku->getname() + "'";
dao  = new DAO("PartsVessel");
dao->insert(data);
delete (dao);
this->set(name);
}

void PartsVessel::copy(std::map<std::string,std::string> object){hasPartsVessel_PartSku=NULL;
for(std::size_t i = 0; i < hadByPart_PartsVessel.size(); i++){
hadByPart_PartsVessel[i]=NULL;}
hadByPart_PartsVessel.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartsVessel*> tmp;
this->hasPartsVessel_PartQuantity = object["PartsVessel.hasPartsVessel_PartQuantity"];
this->hasPartsVessel_SerialNumber = object["PartsVessel.hasPartsVessel_SerialNumber"];
this->name = object["PartsVessel._NAME"];
this->PartsVesselID = std::atof(object["PartsVessel.PartsVesselID"].c_str());
if(this->hasPartsVessel_PartSku== NULL && object["hasPartsVessel_PartSku/StockKeepingUnit._NAME"]!=""){
this->hasPartsVessel_PartSku = new StockKeepingUnit(object["hasPartsVessel_PartSku/StockKeepingUnit._NAME"]);
}
if(this->hadByPart_PartsVessel.empty() && object["hadByPart_PartsVessel/Part._NAME"]!=""){
temp = Explode(object["hadByPart_PartsVessel/Part._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByPart_PartsVessel.push_back(new Part(temp[i]));
}
}

}std::vector<std::string> PartsVessel::Explode(const std::string & str, char separator )
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
