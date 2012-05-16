#include "RelativeLocation.h"

RelativeLocation::RelativeLocation(std::string name) : PhysicalLocation(name){
this->name=name;
}RelativeLocation::~RelativeLocation(){
delete(dao);
}
std::string RelativeLocation::getname(){
return this->name;
}
int RelativeLocation::getRelativeLocationID(){
return this->RelativeLocationID;
}
DAO* RelativeLocation::getdao(){
return this->dao;
}
void RelativeLocation::setname(std::string _name){
this->name= _name;
}
void RelativeLocation::setRelativeLocationID(int _RelativeLocationID){
this->RelativeLocationID= _RelativeLocationID;
}
void RelativeLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);
 PhysicalLocation::copy(temp);
delete (dao);
dao  = new DAO("RelativeLocation");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void RelativeLocation::set(std::string name){
 dao  = new DAO("RelativeLocation");
 dao->set(name);
delete (dao);
}

void RelativeLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["RelativeLocation._NAME"];
this->RelativeLocationID = std::atof(object["RelativeLocation.RelativeLocationID"].c_str());

}std::vector<std::string> RelativeLocation::Explode(const std::string & str, char separator )
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
