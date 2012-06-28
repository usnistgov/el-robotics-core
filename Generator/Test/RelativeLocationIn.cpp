#include "RelativeLocationIn.h"


 #include "DAO.h"

RelativeLocationIn::RelativeLocationIn(std::string name) : RelativeLocation(name){
this->name=name;dao = NULL;

}RelativeLocationIn::~RelativeLocationIn(){
delete(dao);
}
std::string RelativeLocationIn::gethasRelativeLocationIn_Description(){
return hasRelativeLocationIn_Description;
}
std::string RelativeLocationIn::getname(){
return name;
}
int RelativeLocationIn::getRelativeLocationInID(){
return RelativeLocationInID;
}
DAO* RelativeLocationIn::getdao(){
return dao;
}
void RelativeLocationIn::sethasRelativeLocationIn_Description(std::string _hasRelativeLocationIn_Description){
this->hasRelativeLocationIn_Description= _hasRelativeLocationIn_Description;
}
void RelativeLocationIn::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocationIn::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("RelativeLocation");
 temp = dao->get(name);delete (dao);
 RelativeLocation::copy(temp);
dao  = new DAO("RelativeLocationIn");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void RelativeLocationIn::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasRelativeLocationIn_Description"]=hasRelativeLocationIn_Description;
data["name"]=name;
ss.str("");
ss << RelativeLocationInID;
data["RelativeLocationInID"]=ss.str();
dao  = new DAO("RelativeLocationIn");
dao->set(data);
delete (dao);
}

void RelativeLocationIn::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<RelativeLocationIn*> tmp;
this->hasRelativeLocationIn_Description = object["RelativeLocationIn.hasRelativeLocationIn_Description"];
this->name = object["RelativeLocationIn._NAME"];
this->RelativeLocationInID = std::atof(object["RelativeLocationIn.RelativeLocationInID"].c_str());

}std::vector<std::string> RelativeLocationIn::Explode(const std::string & str, char separator )
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
