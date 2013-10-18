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

#include "VacuumEffectorMultiCup.h"


 #include "DAO.h"

VacuumEffectorMultiCup::VacuumEffectorMultiCup(std::string name) : VacuumEffector(name){
dao = NULL;

}VacuumEffectorMultiCup::~VacuumEffectorMultiCup(){
}
double VacuumEffectorMultiCup::gethasVacuumEffectorMultiCup_ArrayRadius(){
return hasVacuumEffectorMultiCup_ArrayRadius;
}
std::string VacuumEffectorMultiCup::gethasVacuumEffectorMultiCup_ArrayNumber(){
return hasVacuumEffectorMultiCup_ArrayNumber;
}
int VacuumEffectorMultiCup::getVacuumEffectorMultiCupID(){
return VacuumEffectorMultiCupID;
}
DAO* VacuumEffectorMultiCup::getdao(){
return dao;
}
void VacuumEffectorMultiCup::sethasVacuumEffectorMultiCup_ArrayRadius(double _hasVacuumEffectorMultiCup_ArrayRadius){
this->hasVacuumEffectorMultiCup_ArrayRadius= _hasVacuumEffectorMultiCup_ArrayRadius;
}
void VacuumEffectorMultiCup::sethasVacuumEffectorMultiCup_ArrayNumber(std::string _hasVacuumEffectorMultiCup_ArrayNumber){
this->hasVacuumEffectorMultiCup_ArrayNumber= _hasVacuumEffectorMultiCup_ArrayNumber;
}
void VacuumEffectorMultiCup::setVacuumEffectorMultiCupID(int _VacuumEffectorMultiCupID){
this->VacuumEffectorMultiCupID= _VacuumEffectorMultiCupID;
}
void VacuumEffectorMultiCup::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffectorMultiCup::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("VacuumEffector");
 temp = dao->get(name);delete (dao);
 VacuumEffector::copy(temp);
dao  = new DAO("EndEffector");
 temp = dao->get(name);delete (dao);
 EndEffector::copy(temp);
dao  = new DAO("NoSkuObject");
 temp = dao->get(name);delete (dao);
 NoSkuObject::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("VacuumEffectorMultiCup");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void VacuumEffectorMultiCup::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
VacuumEffector* temp0 = (VacuumEffector*) this;
temp0->set(name);
EndEffector* temp1 = (EndEffector*) this;
temp1->set(name);
NoSkuObject* temp2 = (NoSkuObject*) this;
temp2->set(name);
SolidObject* temp3 = (SolidObject*) this;
temp3->set(name);
ss.str("");
ss << hasVacuumEffectorMultiCup_ArrayRadius;
data["hasVacuumEffectorMultiCup_ArrayRadius"]=ss.str();
data["hasVacuumEffectorMultiCup_ArrayNumber"]="'" + hasVacuumEffectorMultiCup_ArrayNumber + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << VacuumEffectorMultiCupID;
data["VacuumEffectorMultiCupID"]=ss.str();
dao  = new DAO("VacuumEffectorMultiCup");
dao->set(data);
delete (dao);
}
void VacuumEffectorMultiCup::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp3 = (SolidObject*) this;
temp3->insert(name);
temp3->get(name);
NoSkuObject* temp2 = (NoSkuObject*) this;
temp2->setNoSkuObjectID(temp3->getSolidObjectID());
temp2->insert(name);
EndEffector* temp1 = (EndEffector*) this;
temp1->setEndEffectorID(temp3->getSolidObjectID());
temp1->insert(name);
VacuumEffector* temp0 = (VacuumEffector*) this;
temp0->setVacuumEffectorID(temp3->getSolidObjectID());
temp0->insert(name);
ss.str("");
ss << hasVacuumEffectorMultiCup_ArrayRadius;
data["hasVacuumEffectorMultiCup_ArrayRadius"]=ss.str();
data["hasVacuumEffectorMultiCup_ArrayNumber"]="'" + hasVacuumEffectorMultiCup_ArrayNumber+ "'";
ss.str("");
ss << temp3->getSolidObjectID();
data["VacuumEffectorMultiCupID"]=ss.str();
dao  = new DAO("VacuumEffectorMultiCup");
dao->insert(data);
delete (dao);
this->set(name);
}

void VacuumEffectorMultiCup::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<VacuumEffectorMultiCup*> tmp;
this->hasVacuumEffectorMultiCup_ArrayRadius = std::atof(object["VacuumEffectorMultiCup.hasVacuumEffectorMultiCup_ArrayRadius"].c_str());
this->hasVacuumEffectorMultiCup_ArrayNumber = object["VacuumEffectorMultiCup.hasVacuumEffectorMultiCup_ArrayNumber"];
this->name = object["VacuumEffectorMultiCup._NAME"];
this->VacuumEffectorMultiCupID = std::atof(object["VacuumEffectorMultiCup.VacuumEffectorMultiCupID"].c_str());

}std::vector<std::string> VacuumEffectorMultiCup::Explode(const std::string & str, char separator )
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
