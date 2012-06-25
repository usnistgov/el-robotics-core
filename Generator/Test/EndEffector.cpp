#include "EndEffector.h"


 #include "Robot.h"
 #include "DAO.h"
 #include "EndEffectorHolder.h"

EndEffector::EndEffector(std::string name) : SolidObject(name){
this->name=name;dao = NULL;
hadByEndEffector_Robot = NULL;
hasEndEffectorHolder_EndEffector = NULL;

}EndEffector::~EndEffector(){
delete(dao);
delete(hadByEndEffector_Robot);
delete(hasEndEffectorHolder_EndEffector);
}
double EndEffector::gethasEndEffector_Weight(){
return hasEndEffector_Weight;
}
double EndEffector::gethasEffector_MaximumLoadWeight(){
return hasEffector_MaximumLoadWeight;
}
std::string EndEffector::gethasEndEffector_Description(){
return hasEndEffector_Description;
}
std::string EndEffector::gethasEndEffector_Id(){
return hasEndEffector_Id;
}
std::string EndEffector::getname(){
return name;
}
int EndEffector::getEndEffectorID(){
return EndEffectorID;
}
DAO* EndEffector::getdao(){
return dao;
}
Robot* EndEffector::gethadByEndEffector_Robot(){
return hadByEndEffector_Robot;
}
EndEffectorHolder* EndEffector::gethasEndEffectorHolder_EndEffector(){
return hasEndEffectorHolder_EndEffector;
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
void EndEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffector::sethadByEndEffector_Robot(Robot* _hadByEndEffector_Robot){
this->hadByEndEffector_Robot= _hadByEndEffector_Robot;
}
void EndEffector::sethasEndEffectorHolder_EndEffector(EndEffectorHolder* _hasEndEffectorHolder_EndEffector){
this->hasEndEffectorHolder_EndEffector= _hasEndEffectorHolder_EndEffector;
}
void EndEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("EndEffector");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void EndEffector::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasEndEffector_Weight"]=hasEndEffector_Weight;
data["hasEffector_MaximumLoadWeight"]=hasEffector_MaximumLoadWeight;
data["hasEndEffector_Description"]=hasEndEffector_Description;
data["hasEndEffector_Id"]=hasEndEffector_Id;
data["name"]=name;
data["EndEffectorID"]=EndEffectorID;
data["hadByEndEffector_Robot"]=hadByEndEffector_Robot->getname();
data["hasEndEffectorHolder_EndEffector"]=hasEndEffectorHolder_EndEffector->getname();
dao  = new DAO("EndEffector");
dao->set(data);
delete (dao);
}

void EndEffector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffector*> tmp;
this->hasEndEffector_Weight = std::atof(object["EndEffector.hasEndEffector_Weight"].c_str());
this->hasEffector_MaximumLoadWeight = std::atof(object["EndEffector.hasEffector_MaximumLoadWeight"].c_str());
this->hasEndEffector_Description = object["EndEffector.hasEndEffector_Description"];
this->hasEndEffector_Id = object["EndEffector.hasEndEffector_Id"];
this->name = object["EndEffector._NAME"];
this->EndEffectorID = std::atof(object["EndEffector.EndEffectorID"].c_str());
if(this->hadByEndEffector_Robot== NULL && object["hadByEndEffector_Robot/Robot._NAME"]!=""){
this->hadByEndEffector_Robot = new Robot(object["hadByEndEffector_Robot/Robot._NAME"]);
}
if(this->hasEndEffectorHolder_EndEffector== NULL && object["hasEndEffectorHolder_EndEffector/EndEffectorHolder._NAME"]!=""){
this->hasEndEffectorHolder_EndEffector = new EndEffectorHolder(object["hasEndEffectorHolder_EndEffector/EndEffectorHolder._NAME"]);
}

}std::vector<std::string> EndEffector::Explode(const std::string & str, char separator )
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
