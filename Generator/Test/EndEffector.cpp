#include "EndEffector.h"

EndEffector::EndEffector(std::string name) : SolidObject(name){
this->name=name;
}EndEffector::~EndEffector(){
delete(dao);
}
double EndEffector::gethasEndEffector_Weight(){
return this->hasEndEffector_Weight;
}
double EndEffector::gethasEffector_MaximumLoadWeight(){
return this->hasEffector_MaximumLoadWeight;
}
std::string EndEffector::gethasEndEffector_Description(){
return this->hasEndEffector_Description;
}
std::string EndEffector::gethasEndEffector_Id(){
return this->hasEndEffector_Id;
}
std::string EndEffector::getname(){
return this->name;
}
int EndEffector::getEndEffectorID(){
return this->EndEffectorID;
}
DAO* EndEffector::getdao(){
return this->dao;
}
void EndEffector::sethasEndEffector_Weight(double _hasEndEffector_Weight){
this->hasEndEffector_Weight= _hasEndEffector_Weight;
}
void EndEffector::sethasEffector_MaximumLoadWeight(double _hasEffector_MaximumLoadWeight){
this->hasEffector_MaximumLoadWeight= _hasEffector_MaximumLoadWeight;
}
void EndEffector::sethasEndEffector_Description(std::string _hasEndEffector_Description){
this->hasEndEffector_Description= _hasEndEffector_Description;
}
void EndEffector::sethasEndEffector_Id(std::string _hasEndEffector_Id){
this->hasEndEffector_Id= _hasEndEffector_Id;
}
void EndEffector::setname(std::string _name){
this->name= _name;
}
void EndEffector::setEndEffectorID(int _EndEffectorID){
this->EndEffectorID= _EndEffectorID;
}
void EndEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("EndEffector");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void EndEffector::set(std::string name){
 dao  = new DAO("EndEffector");
 dao->set(name);
delete (dao);
}

void EndEffector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasEndEffector_Weight = std::atof(object["EndEffector.hasEndEffector_Weight"].c_str());
this->hasEffector_MaximumLoadWeight = std::atof(object["EndEffector.hasEffector_MaximumLoadWeight"].c_str());
this->hasEndEffector_Description = object["EndEffector.hasEndEffector_Description"];
this->hasEndEffector_Id = object["EndEffector.hasEndEffector_Id"];
this->name = object["EndEffector._NAME"];
this->EndEffectorID = std::atof(object["EndEffector.EndEffectorID"].c_str());

}std::vector<std::string> EndEffector::Explode(const std::string & str, char separator )
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
