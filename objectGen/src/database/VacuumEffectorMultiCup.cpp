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
std::string VacuumEffectorMultiCup::gethasMultiCup_ArrayNumber(){
return hasMultiCup_ArrayNumber;
}
double VacuumEffectorMultiCup::gethasMultiCup_ArrayRadius(){
return hasMultiCup_ArrayRadius;
}
int VacuumEffectorMultiCup::getVacuumEffectorMultiCupID(){
return VacuumEffectorMultiCupID;
}
DAO* VacuumEffectorMultiCup::getdao(){
return dao;
}
void VacuumEffectorMultiCup::sethasMultiCup_ArrayNumber(std::string _hasMultiCup_ArrayNumber){
this->hasMultiCup_ArrayNumber= _hasMultiCup_ArrayNumber;
}
void VacuumEffectorMultiCup::sethasMultiCup_ArrayRadius(double _hasMultiCup_ArrayRadius){
this->hasMultiCup_ArrayRadius= _hasMultiCup_ArrayRadius;
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
SolidObject* temp2 = (SolidObject*) this;
temp2->set(name);
data["hasMultiCup_ArrayNumber"]=hasMultiCup_ArrayNumber;
ss.str("");
ss << hasMultiCup_ArrayRadius;
data["hasMultiCup_ArrayRadius"]=ss.str();
data["name"]=name;
ss.str("");
ss << VacuumEffectorMultiCupID;
data["VacuumEffectorMultiCupID"]=ss.str();
dao  = new DAO("VacuumEffectorMultiCup");
dao->set(data);
delete (dao);
}

void VacuumEffectorMultiCup::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<VacuumEffectorMultiCup*> tmp;
this->hasMultiCup_ArrayNumber = object["VacuumEffectorMultiCup.hasMultiCup_ArrayNumber"];
this->hasMultiCup_ArrayRadius = std::atof(object["VacuumEffectorMultiCup.hasMultiCup_ArrayRadius"].c_str());
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
