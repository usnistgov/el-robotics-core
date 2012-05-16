#include "VacuumEffector.h"

VacuumEffector::VacuumEffector(std::string name) : EndEffector(name){
this->name=name;
}VacuumEffector::~VacuumEffector(){
delete(dao);
}
double VacuumEffector::gethasVacuumEffector_CupDiameter(){
return this->hasVacuumEffector_CupDiameter;
}
double VacuumEffector::gethasVacuumEffector_Length(){
return this->hasVacuumEffector_Length;
}
std::string VacuumEffector::getname(){
return this->name;
}
int VacuumEffector::getVacuumEffectorID(){
return this->VacuumEffectorID;
}
DAO* VacuumEffector::getdao(){
return this->dao;
}
void VacuumEffector::sethasVacuumEffector_CupDiameter(double _hasVacuumEffector_CupDiameter){
this->hasVacuumEffector_CupDiameter= _hasVacuumEffector_CupDiameter;
}
void VacuumEffector::sethasVacuumEffector_Length(double _hasVacuumEffector_Length){
this->hasVacuumEffector_Length= _hasVacuumEffector_Length;
}
void VacuumEffector::setname(std::string _name){
this->name= _name;
}
void VacuumEffector::setVacuumEffectorID(int _VacuumEffectorID){
this->VacuumEffectorID= _VacuumEffectorID;
}
void VacuumEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void VacuumEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("EndEffector");
 temp = dao->get(name);
 EndEffector::copy(temp);
delete (dao);
dao  = new DAO("VacuumEffector");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void VacuumEffector::set(std::string name){
 dao  = new DAO("VacuumEffector");
 dao->set(name);
delete (dao);
}

void VacuumEffector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasVacuumEffector_CupDiameter = std::atof(object["VacuumEffector.hasVacuumEffector_CupDiameter"].c_str());
this->hasVacuumEffector_Length = std::atof(object["VacuumEffector.hasVacuumEffector_Length"].c_str());
this->name = object["VacuumEffector._NAME"];
this->VacuumEffectorID = std::atof(object["VacuumEffector.VacuumEffectorID"].c_str());

}std::vector<std::string> VacuumEffector::Explode(const std::string & str, char separator )
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
