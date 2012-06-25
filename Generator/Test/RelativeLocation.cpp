#include "RelativeLocation.h"


 #include "DAO.h"

RelativeLocation::RelativeLocation(std::string name) : PhysicalLocation(name){
this->name=name;dao = NULL;

}RelativeLocation::~RelativeLocation(){
delete(dao);
}
std::string RelativeLocation::getname(){
return name;
}
int RelativeLocation::getRelativeLocationID(){
return RelativeLocationID;
}
DAO* RelativeLocation::getdao(){
return dao;
}
void RelativeLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);delete (dao);
 PhysicalLocation::copy(temp);
dao  = new DAO("RelativeLocation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void RelativeLocation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["name"]=name;
data["RelativeLocationID"]=RelativeLocationID;
dao  = new DAO("RelativeLocation");
dao->set(data);
delete (dao);
}

void RelativeLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<RelativeLocation*> tmp;
this->name = object["RelativeLocation._NAME"];
this->RelativeLocationID = std::atof(object["RelativeLocation.RelativeLocationID"].c_str());

}std::vector<std::string> RelativeLocation::Explode(const std::string & str, char separator )
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
