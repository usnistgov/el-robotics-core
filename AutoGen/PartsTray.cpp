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

#include "PartsTray.h"


 #include "StockKeepingUnit.h"
 #include "PartsTrayWithParts.h"
 #include "DAO.h"

PartsTray::PartsTray(std::string name) : SolidObject(name){
dao = NULL;
hasPartsTray_Sku = NULL;
hasPartsTrayWithParts_PartsTray = NULL;

}PartsTray::~PartsTray(){
delete(hasPartsTray_Sku);
delete(hasPartsTrayWithParts_PartsTray);
}
std::string PartsTray::gethasPartsTray_SerialNumber(){
return hasPartsTray_SerialNumber;
}
int PartsTray::getPartsTrayID(){
return PartsTrayID;
}
DAO* PartsTray::getdao(){
return dao;
}
StockKeepingUnit* PartsTray::gethasPartsTray_Sku(){
return hasPartsTray_Sku;
}
PartsTrayWithParts* PartsTray::gethasPartsTrayWithParts_PartsTray(){
return hasPartsTrayWithParts_PartsTray;
}
void PartsTray::sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber){
this->hasPartsTray_SerialNumber= _hasPartsTray_SerialNumber;
}
void PartsTray::setPartsTrayID(int _PartsTrayID){
this->PartsTrayID= _PartsTrayID;
}
void PartsTray::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTray::sethasPartsTray_Sku(StockKeepingUnit* _hasPartsTray_Sku){
this->hasPartsTray_Sku= _hasPartsTray_Sku;
}
void PartsTray::sethasPartsTrayWithParts_PartsTray(PartsTrayWithParts* _hasPartsTrayWithParts_PartsTray){
this->hasPartsTrayWithParts_PartsTray= _hasPartsTrayWithParts_PartsTray;
}
void PartsTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("PartsTray");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PartsTray::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasPartsTray_SerialNumber"]="'" + hasPartsTray_SerialNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << PartsTrayID;
data["PartsTrayID"]=ss.str();
if(hasPartsTray_Sku!=NULL)
data["hasPartsTray_Sku"]=hasPartsTray_Sku->getname();
if(hasPartsTrayWithParts_PartsTray!=NULL)
data["hasPartsTrayWithParts_PartsTray"]=hasPartsTrayWithParts_PartsTray->getname();
dao  = new DAO("PartsTray");
dao->set(data);
delete (dao);
}
void PartsTray::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
data["hasPartsTray_SerialNumber"]="'" + hasPartsTray_SerialNumber+ "'";
ss.str("");
ss << temp0->getSolidObjectID();
data["PartsTrayID"]=ss.str();
if(hasPartsTray_Sku!=NULL)
data["hasPartsTray_Sku"]=hasPartsTray_Sku->getname();
if(hasPartsTrayWithParts_PartsTray!=NULL)
data["hasPartsTrayWithParts_PartsTray"]=hasPartsTrayWithParts_PartsTray->getname();
dao  = new DAO("PartsTray");
dao->insert(data);
delete (dao);
this->set(name);
}

void PartsTray::copy(std::map<std::string,std::string> object){delete(hasPartsTray_Sku);
hasPartsTray_Sku=NULL;
delete(hasPartsTrayWithParts_PartsTray);
hasPartsTrayWithParts_PartsTray=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartsTray*> tmp;
this->hasPartsTray_SerialNumber = object["PartsTray.hasPartsTray_SerialNumber"];
this->name = object["PartsTray._NAME"];
this->PartsTrayID = std::atof(object["PartsTray.PartsTrayID"].c_str());
if(this->hasPartsTray_Sku== NULL && object["hasPartsTray_Sku/StockKeepingUnit._NAME"]!=""){
this->hasPartsTray_Sku = new StockKeepingUnit(object["hasPartsTray_Sku/StockKeepingUnit._NAME"]);
}
if(this->hasPartsTrayWithParts_PartsTray== NULL && object["hasPartsTrayWithParts_PartsTray/PartsTrayWithParts._NAME"]!=""){
this->hasPartsTrayWithParts_PartsTray = new PartsTrayWithParts(object["hasPartsTrayWithParts_PartsTray/PartsTrayWithParts._NAME"]);
}

}std::vector<std::string> PartsTray::Explode(const std::string & str, char separator )
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
