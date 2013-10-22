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

#include "SkuObject.h"


 #include "StockKeepingUnit.h"
 #include "DAO.h"

SkuObject::SkuObject(std::string name) : SolidObject(name){
dao = NULL;
hasSkuObject_Sku = NULL;

}SkuObject::~SkuObject(){
delete(hasSkuObject_Sku);
}
int SkuObject::getSkuObjectID(){
return SkuObjectID;
}
DAO* SkuObject::getdao(){
return dao;
}
StockKeepingUnit* SkuObject::gethasSkuObject_Sku(){
return hasSkuObject_Sku;
}
void SkuObject::setSkuObjectID(int _SkuObjectID){
this->SkuObjectID= _SkuObjectID;
}
void SkuObject::setdao(DAO* _dao){
this->dao= _dao;
}
void SkuObject::sethasSkuObject_Sku(StockKeepingUnit* _hasSkuObject_Sku){
this->hasSkuObject_Sku= _hasSkuObject_Sku;
}
void SkuObject::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("SkuObject");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void SkuObject::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << SkuObjectID;
data["SkuObjectID"]=ss.str();
if(hasSkuObject_Sku!=NULL)
data["hasSkuObject_Sku"]="'" +hasSkuObject_Sku->getname() + "'";
else 
 data["hasSkuObject_Sku"]="null";
dao  = new DAO("SkuObject");
dao->set(data);
delete (dao);
}
void SkuObject::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getSolidObjectID();
data["SkuObjectID"]=ss.str();
if(hasSkuObject_Sku!=NULL)
data["hasSkuObject_Sku"]="'" + hasSkuObject_Sku->getname() + "'";
dao  = new DAO("SkuObject");
dao->insert(data);
delete (dao);
this->set(name);
}

void SkuObject::copy(std::map<std::string,std::string> object){hasSkuObject_Sku=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<SkuObject*> tmp;
this->name = object["SkuObject._NAME"];
this->SkuObjectID = std::atof(object["SkuObject.SkuObjectID"].c_str());
if(this->hasSkuObject_Sku== NULL && object["hasSkuObject_Sku/StockKeepingUnit._NAME"]!=""){
this->hasSkuObject_Sku = new StockKeepingUnit(object["hasSkuObject_Sku/StockKeepingUnit._NAME"]);
}

}std::vector<std::string> SkuObject::Explode(const std::string & str, char separator )
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
