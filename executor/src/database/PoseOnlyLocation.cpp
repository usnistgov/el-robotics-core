#include "PoseOnlyLocation.h"


 #include "DAO.h"

PoseOnlyLocation::PoseOnlyLocation(std::string name) : PoseLocation(name){
this->name=name;dao = NULL;

}PoseOnlyLocation::~PoseOnlyLocation(){
delete(dao);
}
std::string PoseOnlyLocation::getname(){
return name;
}
int PoseOnlyLocation::getPoseOnlyLocationID(){
return PoseOnlyLocationID;
}
DAO* PoseOnlyLocation::getdao(){
return dao;
}
void PoseOnlyLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseOnlyLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PoseLocation");
 temp = dao->get(name);delete (dao);
 PoseLocation::copy(temp);
dao  = new DAO("PoseOnlyLocation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PoseOnlyLocation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["name"]=name;
data["PoseOnlyLocationID"]=PoseOnlyLocationID;
dao  = new DAO("PoseOnlyLocation");
dao->set(data);
delete (dao);
}

void PoseOnlyLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseOnlyLocation*> tmp;
this->name = object["PoseOnlyLocation._NAME"];
this->PoseOnlyLocationID = std::atof(object["PoseOnlyLocation.PoseOnlyLocationID"].c_str());

}std::vector<std::string> PoseOnlyLocation::Explode(const std::string & str, char separator )
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
