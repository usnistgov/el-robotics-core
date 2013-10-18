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


 #include "DAO.h"

PartsTray::PartsTray(std::string name) : PartsVessel(name){
dao = NULL;

}PartsTray::~PartsTray(){
}
int PartsTray::getPartsTrayID(){
return PartsTrayID;
}
DAO* PartsTray::getdao(){
return dao;
}
void PartsTray::setPartsTrayID(int _PartsTrayID){
this->PartsTrayID= _PartsTrayID;
}
void PartsTray::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTray::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PartsVessel");
 temp = dao->get(name);delete (dao);
 PartsVessel::copy(temp);
dao  = new DAO("SkuObject");
 temp = dao->get(name);delete (dao);
 SkuObject::copy(temp);
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
PartsVessel* temp0 = (PartsVessel*) this;
temp0->set(name);
SkuObject* temp1 = (SkuObject*) this;
temp1->set(name);
SolidObject* temp2 = (SolidObject*) this;
temp2->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << PartsTrayID;
data["PartsTrayID"]=ss.str();
dao  = new DAO("PartsTray");
dao->set(data);
delete (dao);
}
void PartsTray::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp2 = (SolidObject*) this;
temp2->insert(name);
temp2->get(name);
SkuObject* temp1 = (SkuObject*) this;
temp1->setSkuObjectID(temp2->getSolidObjectID());
temp1->insert(name);
PartsVessel* temp0 = (PartsVessel*) this;
temp0->setPartsVesselID(temp2->getSolidObjectID());
temp0->insert(name);
ss.str("");
ss << temp2->getSolidObjectID();
data["PartsTrayID"]=ss.str();
dao  = new DAO("PartsTray");
dao->insert(data);
delete (dao);
this->set(name);
}

void PartsTray::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartsTray*> tmp;
this->name = object["PartsTray._NAME"];
this->PartsTrayID = std::atof(object["PartsTray.PartsTrayID"].c_str());

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
