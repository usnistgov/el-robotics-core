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

#include "PartsBin.h"


 #include "StockKeepingUnit.h"
 #include "DAO.h"

PartsBin::PartsBin(std::string name) : SolidObject(name){
dao = NULL;
hasPartsBin_Sku = NULL;
hasPartsBin_PartSku = NULL;

}PartsBin::~PartsBin(){
delete(dao);
delete(hasPartsBin_Sku);
delete(hasPartsBin_PartSku);
}
std::string PartsBin::gethasPartsBin_PartQuantity(){
return hasPartsBin_PartQuantity;
}
std::string PartsBin::gethasPartsBin_SerialNumber(){
return hasPartsBin_SerialNumber;
}
int PartsBin::getPartsBinID(){
return PartsBinID;
}
DAO* PartsBin::getdao(){
return dao;
}
StockKeepingUnit* PartsBin::gethasPartsBin_Sku(){
return hasPartsBin_Sku;
}
StockKeepingUnit* PartsBin::gethasPartsBin_PartSku(){
return hasPartsBin_PartSku;
}
void PartsBin::sethasPartsBin_PartQuantity(std::string _hasPartsBin_PartQuantity){
this->hasPartsBin_PartQuantity= _hasPartsBin_PartQuantity;
}
void PartsBin::sethasPartsBin_SerialNumber(std::string _hasPartsBin_SerialNumber){
this->hasPartsBin_SerialNumber= _hasPartsBin_SerialNumber;
}
void PartsBin::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsBin::sethasPartsBin_Sku(StockKeepingUnit* _hasPartsBin_Sku){
this->hasPartsBin_Sku= _hasPartsBin_Sku;
}
void PartsBin::sethasPartsBin_PartSku(StockKeepingUnit* _hasPartsBin_PartSku){
this->hasPartsBin_PartSku= _hasPartsBin_PartSku;
}
void PartsBin::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("PartsBin");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PartsBin::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasPartsBin_PartQuantity"]=hasPartsBin_PartQuantity;
data["hasPartsBin_SerialNumber"]=hasPartsBin_SerialNumber;
data["name"]=name;
ss.str("");
ss << PartsBinID;
data["PartsBinID"]=ss.str();
if(hasPartsBin_Sku!=NULL)
data["hasPartsBin_Sku"]=hasPartsBin_Sku->getname();
if(hasPartsBin_PartSku!=NULL)
data["hasPartsBin_PartSku"]=hasPartsBin_PartSku->getname();
dao  = new DAO("PartsBin");
dao->set(data);
delete (dao);
}

void PartsBin::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartsBin*> tmp;
this->hasPartsBin_PartQuantity = object["PartsBin.hasPartsBin_PartQuantity"];
this->hasPartsBin_SerialNumber = object["PartsBin.hasPartsBin_SerialNumber"];
this->name = object["PartsBin._NAME"];
this->PartsBinID = std::atof(object["PartsBin.PartsBinID"].c_str());
if(this->hasPartsBin_Sku== NULL && object["hasPartsBin_Sku/StockKeepingUnit._NAME"]!=""){
this->hasPartsBin_Sku = new StockKeepingUnit(object["hasPartsBin_Sku/StockKeepingUnit._NAME"]);
}
if(this->hasPartsBin_PartSku== NULL && object["hasPartsBin_PartSku/StockKeepingUnit._NAME"]!=""){
this->hasPartsBin_PartSku = new StockKeepingUnit(object["hasPartsBin_PartSku/StockKeepingUnit._NAME"]);
}

}std::vector<std::string> PartsBin::Explode(const std::string & str, char separator )
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
