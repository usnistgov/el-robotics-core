#include "VacuumEffectorSingleCup.h"

VacuumEffectorSingleCup::VacuumEffectorSingleCup(std::string name) : VacuumEffector(name){
this->name=name;
}VacuumEffectorSingleCup::~VacuumEffectorSingleCup(){
delete(dao);
}
std::string VacuumEffectorSingleCup::getname(){
return this->name;
}
int VacuumEffectorSingleCup::getVacuumEffectorSingleCupID(){
return this->VacuumEffectorSingleCupID;
}
DAO* VacuumEffectorSingleCup::getdao(){
return this->dao;
}
void VacuumEffectorSingleCup::setname(std::string _name){
this->name= _name;
}
void VacuumEffectorSingleCup::setVacuumEffectorSingleCupID(int _VacuumEffectorSingleCupID){
this->VacuumEffectorSingleCupID= _VacuumEffectorSingleCupID;
}
void VacuumEffectorSingleCup::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffectorSingleCup::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("VacuumEffector");
 temp = dao->get(name);
 VacuumEffector::copy(temp);
delete (dao);
dao  = new DAO("VacuumEffectorSingleCup");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void VacuumEffectorSingleCup::set(std::string name){
 dao  = new DAO("VacuumEffectorSingleCup");
 dao->set(name);
delete (dao);
}

void VacuumEffectorSingleCup::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["VacuumEffectorSingleCup._NAME"];
this->VacuumEffectorSingleCupID = std::atof(object["VacuumEffectorSingleCup.VacuumEffectorSingleCupID"].c_str());

}std::vector<std::string> VacuumEffectorSingleCup::Explode(const std::string & str, char separator )
{
   std::vector< std::string > result;
   size_t pos1 = 0;
   size_t pos2 = 0;
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
