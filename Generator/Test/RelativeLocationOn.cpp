#include "RelativeLocationOn.h"

RelativeLocationOn::RelativeLocationOn(std::string name) : RelativeLocation(name){
this->name=name;
}RelativeLocationOn::~RelativeLocationOn(){
delete(dao);
}
std::string RelativeLocationOn::gethasRelativeLocationOn_Description(){
return this->hasRelativeLocationOn_Description;
}
std::string RelativeLocationOn::getname(){
return this->name;
}
int RelativeLocationOn::getRelativeLocationOnID(){
return this->RelativeLocationOnID;
}
DAO* RelativeLocationOn::getdao(){
return this->dao;
}
void RelativeLocationOn::sethasRelativeLocationOn_Description(std::string _hasRelativeLocationOn_Description){
this->hasRelativeLocationOn_Description= _hasRelativeLocationOn_Description;
}
void RelativeLocationOn::setname(std::string _name){
this->name= _name;
}
void RelativeLocationOn::setRelativeLocationOnID(int _RelativeLocationOnID){
this->RelativeLocationOnID= _RelativeLocationOnID;
}
void RelativeLocationOn::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocationOn::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("RelativeLocation");
 temp = dao->get(name);
 RelativeLocation::copy(temp);
delete (dao);
dao  = new DAO("RelativeLocationOn");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void RelativeLocationOn::set(std::string name){
 dao  = new DAO("RelativeLocationOn");
 dao->set(name);
delete (dao);
}

void RelativeLocationOn::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasRelativeLocationOn_Description = object["RelativeLocationOn.hasRelativeLocationOn_Description"];
this->name = object["RelativeLocationOn._NAME"];
this->RelativeLocationOnID = std::atof(object["RelativeLocationOn.RelativeLocationOnID"].c_str());

}std::vector<std::string> RelativeLocationOn::Explode(const std::string & str, char separator )
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
