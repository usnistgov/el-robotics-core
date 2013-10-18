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

#include "GripperEffector.h"


 #include "DAO.h"

GripperEffector::GripperEffector(std::string name) : EndEffector(name){
dao = NULL;

}GripperEffector::~GripperEffector(){
}
int GripperEffector::getGripperEffectorID(){
return GripperEffectorID;
}
DAO* GripperEffector::getdao(){
return dao;
}
void GripperEffector::setGripperEffectorID(int _GripperEffectorID){
this->GripperEffectorID= _GripperEffectorID;
}
void GripperEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void GripperEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("EndEffector");
 temp = dao->get(name);delete (dao);
 EndEffector::copy(temp);
dao  = new DAO("NoSkuObject");
 temp = dao->get(name);delete (dao);
 NoSkuObject::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("GripperEffector");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void GripperEffector::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
EndEffector* temp0 = (EndEffector*) this;
temp0->set(name);
NoSkuObject* temp1 = (NoSkuObject*) this;
temp1->set(name);
SolidObject* temp2 = (SolidObject*) this;
temp2->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << GripperEffectorID;
data["GripperEffectorID"]=ss.str();
dao  = new DAO("GripperEffector");
dao->set(data);
delete (dao);
}
void GripperEffector::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp2 = (SolidObject*) this;
temp2->insert(name);
temp2->get(name);
NoSkuObject* temp1 = (NoSkuObject*) this;
temp1->setNoSkuObjectID(temp2->getSolidObjectID());
temp1->insert(name);
EndEffector* temp0 = (EndEffector*) this;
temp0->setEndEffectorID(temp2->getSolidObjectID());
temp0->insert(name);
ss.str("");
ss << temp2->getSolidObjectID();
data["GripperEffectorID"]=ss.str();
dao  = new DAO("GripperEffector");
dao->insert(data);
delete (dao);
this->set(name);
}

void GripperEffector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<GripperEffector*> tmp;
this->name = object["GripperEffector._NAME"];
this->GripperEffectorID = std::atof(object["GripperEffector.GripperEffectorID"].c_str());

}std::vector<std::string> GripperEffector::Explode(const std::string & str, char separator )
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
