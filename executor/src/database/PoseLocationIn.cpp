#include "PoseLocationIn.h"


 #include "DAO.h"

PoseLocationIn::PoseLocationIn(std::string name) : PoseLocation(name){
this->name=name;dao = NULL;

}PoseLocationIn::~PoseLocationIn(){
delete(dao);
}
std::string PoseLocationIn::getname(){
return name;
}
int PoseLocationIn::getPoseLocationInID(){
return PoseLocationInID;
}
DAO* PoseLocationIn::getdao(){
return dao;
}
void PoseLocationIn::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseLocationIn::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PoseLocation");
 temp = dao->get(name);delete (dao);
 PoseLocation::copy(temp);
dao  = new DAO("PoseLocationIn");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PoseLocationIn::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["name"]=name;
data["PoseLocationInID"]=PoseLocationInID;
dao  = new DAO("PoseLocationIn");
dao->set(data);
delete (dao);
}

void PoseLocationIn::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseLocationIn*> tmp;
this->name = object["PoseLocationIn._NAME"];
this->PoseLocationInID = std::atof(object["PoseLocationIn.PoseLocationInID"].c_str());

}std::vector<std::string> PoseLocationIn::Explode(const std::string & str, char separator )
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
