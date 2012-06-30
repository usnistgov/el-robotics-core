#include "PoseLocationOn.h"


 #include "DAO.h"

PoseLocationOn::PoseLocationOn(std::string name) : PoseLocation(name){
this->name=name;dao = NULL;

}PoseLocationOn::~PoseLocationOn(){
delete(dao);
}
std::string PoseLocationOn::getname(){
return name;
}
int PoseLocationOn::getPoseLocationOnID(){
return PoseLocationOnID;
}
DAO* PoseLocationOn::getdao(){
return dao;
}
void PoseLocationOn::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseLocationOn::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PoseLocation");
 temp = dao->get(name);delete (dao);
 PoseLocation::copy(temp);
dao  = new DAO("PoseLocationOn");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PoseLocationOn::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["name"]=name;
data["PoseLocationOnID"]=PoseLocationOnID;
dao  = new DAO("PoseLocationOn");
dao->set(data);
delete (dao);
}

void PoseLocationOn::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseLocationOn*> tmp;
this->name = object["PoseLocationOn._NAME"];
this->PoseLocationOnID = std::atof(object["PoseLocationOn.PoseLocationOnID"].c_str());

}std::vector<std::string> PoseLocationOn::Explode(const std::string & str, char separator )
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
