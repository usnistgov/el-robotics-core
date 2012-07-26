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

#include "VacuumEffectorSingleCup.h"


 #include "DAO.h"

VacuumEffectorSingleCup::VacuumEffectorSingleCup(std::string name) : VacuumEffector(name){
dao = NULL;

}VacuumEffectorSingleCup::~VacuumEffectorSingleCup(){
delete(dao);
}
int VacuumEffectorSingleCup::getVacuumEffectorSingleCupID(){
return VacuumEffectorSingleCupID;
}
DAO* VacuumEffectorSingleCup::getdao(){
return dao;
}
void VacuumEffectorSingleCup::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffectorSingleCup::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("VacuumEffector");
 temp = dao->get(name);delete (dao);
 VacuumEffector::copy(temp);
dao  = new DAO("VacuumEffectorSingleCup");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void VacuumEffectorSingleCup::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
VacuumEffector* temp = (VacuumEffector*) this;
temp->set(name);
data["name"]=name;
ss.str("");
ss << VacuumEffectorSingleCupID;
data["VacuumEffectorSingleCupID"]=ss.str();
dao  = new DAO("VacuumEffectorSingleCup");
dao->set(data);
delete (dao);
}

void VacuumEffectorSingleCup::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<VacuumEffectorSingleCup*> tmp;
this->name = object["VacuumEffectorSingleCup._NAME"];
this->VacuumEffectorSingleCupID = std::atof(object["VacuumEffectorSingleCup.VacuumEffectorSingleCupID"].c_str());

}std::vector<std::string> VacuumEffectorSingleCup::Explode(const std::string & str, char separator )
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
