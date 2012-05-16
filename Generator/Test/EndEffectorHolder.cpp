#include "EndEffectorHolder.h"

EndEffectorHolder::EndEffectorHolder(std::string name) : SolidObject(name){
this->name=name;
}EndEffectorHolder::~EndEffectorHolder(){
delete(dao);
}
std::string EndEffectorHolder::getname(){
return this->name;
}
int EndEffectorHolder::getEndEffectorHolderID(){
return this->EndEffectorHolderID;
}
DAO* EndEffectorHolder::getdao(){
return this->dao;
}
void EndEffectorHolder::setname(std::string _name){
this->name= _name;
}
void EndEffectorHolder::setEndEffectorHolderID(int _EndEffectorHolderID){
this->EndEffectorHolderID= _EndEffectorHolderID;
}
void EndEffectorHolder::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorHolder::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("EndEffectorHolder");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void EndEffectorHolder::set(std::string name){
 dao  = new DAO("EndEffectorHolder");
 dao->set(name);
delete (dao);
}

void EndEffectorHolder::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["EndEffectorHolder._NAME"];
this->EndEffectorHolderID = std::atof(object["EndEffectorHolder.EndEffectorHolderID"].c_str());

}std::vector<std::string> EndEffectorHolder::Explode(const std::string & str, char separator )
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
