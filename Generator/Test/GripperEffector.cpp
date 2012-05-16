#include "GripperEffector.h"

GripperEffector::GripperEffector(std::string name) : EndEffector(name){
this->name=name;
}GripperEffector::~GripperEffector(){
delete(dao);
}
std::string GripperEffector::getname(){
return this->name;
}
int GripperEffector::getGripperEffectorID(){
return this->GripperEffectorID;
}
DAO* GripperEffector::getdao(){
return this->dao;
}
void GripperEffector::setname(std::string _name){
this->name= _name;
}
void GripperEffector::setGripperEffectorID(int _GripperEffectorID){
this->GripperEffectorID= _GripperEffectorID;
}
void GripperEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void GripperEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("EndEffector");
 temp = dao->get(name);
 EndEffector::copy(temp);
delete (dao);
dao  = new DAO("GripperEffector");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void GripperEffector::set(std::string name){
 dao  = new DAO("GripperEffector");
 dao->set(name);
delete (dao);
}

void GripperEffector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["GripperEffector._NAME"];
this->GripperEffectorID = std::atof(object["GripperEffector.GripperEffectorID"].c_str());

}std::vector<std::string> GripperEffector::Explode(const std::string & str, char separator )
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
