#include "VacuumEffectorMultiCup.h"

VacuumEffectorMultiCup::VacuumEffectorMultiCup(std::string name) : VacuumEffector(name){
this->name=name;
}VacuumEffectorMultiCup::~VacuumEffectorMultiCup(){
delete(dao);
}
std::string VacuumEffectorMultiCup::gethasMultiCup_ArrayNumber(){
return this->hasMultiCup_ArrayNumber;
}
double VacuumEffectorMultiCup::gethasMultiCup_ArrayRadius(){
return this->hasMultiCup_ArrayRadius;
}
std::string VacuumEffectorMultiCup::getname(){
return this->name;
}
int VacuumEffectorMultiCup::getVacuumEffectorMultiCupID(){
return this->VacuumEffectorMultiCupID;
}
DAO* VacuumEffectorMultiCup::getdao(){
return this->dao;
}
void VacuumEffectorMultiCup::sethasMultiCup_ArrayNumber(std::string _hasMultiCup_ArrayNumber){
this->hasMultiCup_ArrayNumber= _hasMultiCup_ArrayNumber;
}
void VacuumEffectorMultiCup::sethasMultiCup_ArrayRadius(double _hasMultiCup_ArrayRadius){
this->hasMultiCup_ArrayRadius= _hasMultiCup_ArrayRadius;
}
void VacuumEffectorMultiCup::setname(std::string _name){
this->name= _name;
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
 temp = dao->get(name);
 VacuumEffector::copy(temp);
delete (dao);
dao  = new DAO("VacuumEffectorMultiCup");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void VacuumEffectorMultiCup::set(std::string name){
 dao  = new DAO("VacuumEffectorMultiCup");
 dao->set(name);
delete (dao);
}

void VacuumEffectorMultiCup::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasMultiCup_ArrayNumber = object["VacuumEffectorMultiCup.hasMultiCup_ArrayNumber"];
this->hasMultiCup_ArrayRadius = std::atof(object["VacuumEffectorMultiCup.hasMultiCup_ArrayRadius"].c_str());
this->name = object["VacuumEffectorMultiCup._NAME"];
this->VacuumEffectorMultiCupID = std::atof(object["VacuumEffectorMultiCup.VacuumEffectorMultiCupID"].c_str());

}std::vector<std::string> VacuumEffectorMultiCup::Explode(const std::string & str, char separator )
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
