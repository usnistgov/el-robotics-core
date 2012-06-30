#include "Robot.h"


 #include "BoxVolume.h"
 #include "EndEffector.h"
 #include "KittingWorkstation.h"
 #include "DAO.h"

Robot::Robot(std::string name) : SolidObject(name){
this->name=name;dao = NULL;
hadByEndEffector_Robot = NULL;
hasWorkstation_Robot = NULL;

}Robot::~Robot(){
delete(dao);
delete(hadByEndEffector_Robot);
delete(hasWorkstation_Robot);
for(std::size_t i = 0; i < hasRobot_WorkVolume.size(); i++)
delete(hasRobot_WorkVolume[i]);
}
std::string Robot::gethasRobot_Description(){
return hasRobot_Description;
}
std::string Robot::gethasRobot_Id(){
return hasRobot_Id;
}
double Robot::gethasRobot_MaximumLoadWeight(){
return hasRobot_MaximumLoadWeight;
}
std::string Robot::getname(){
return name;
}
int Robot::getRobotID(){
return RobotID;
}
DAO* Robot::getdao(){
return dao;
}
EndEffector* Robot::gethadByEndEffector_Robot(){
return hadByEndEffector_Robot;
}
std::vector<BoxVolume*>* Robot::gethasRobot_WorkVolume(){
return &hasRobot_WorkVolume;
}
KittingWorkstation* Robot::gethasWorkstation_Robot(){
return hasWorkstation_Robot;
}
void Robot::sethasRobot_Description(std::string _hasRobot_Description){
this->hasRobot_Description= _hasRobot_Description;
}
void Robot::sethasRobot_Id(std::string _hasRobot_Id){
this->hasRobot_Id= _hasRobot_Id;
}
void Robot::sethasRobot_MaximumLoadWeight(double _hasRobot_MaximumLoadWeight){
this->hasRobot_MaximumLoadWeight= _hasRobot_MaximumLoadWeight;
}
void Robot::setdao(DAO* _dao){
this->dao= _dao;
}
void Robot::sethadByEndEffector_Robot(EndEffector* _hadByEndEffector_Robot){
this->hadByEndEffector_Robot= _hadByEndEffector_Robot;
}
void Robot::sethasRobot_WorkVolume(std::vector<BoxVolume*> _hasRobot_WorkVolume){
this->hasRobot_WorkVolume= _hasRobot_WorkVolume;
}
void Robot::sethasWorkstation_Robot(KittingWorkstation* _hasWorkstation_Robot){
this->hasWorkstation_Robot= _hasWorkstation_Robot;
}
void Robot::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("Robot");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Robot::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasRobot_Description"]=hasRobot_Description;
data["hasRobot_Id"]=hasRobot_Id;
data["hasRobot_MaximumLoadWeight"]=hasRobot_MaximumLoadWeight;
data["name"]=name;
data["RobotID"]=RobotID;
data["hadByEndEffector_Robot"]=hadByEndEffector_Robot->getname();
for(unsigned int i=0;i<hasRobot_WorkVolume.size();++i){
ss.flush();
ss << hasRobot_WorkVolume[i]->getBoxVolumeID();
data["hasRobot_WorkVolume"]=data["hasRobot_WorkVolume"]+" "+ss.str();
}
data["hasWorkstation_Robot"]=hasWorkstation_Robot->getname();
dao  = new DAO("Robot");
dao->set(data);
delete (dao);
}

void Robot::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Robot*> tmp;
this->hasRobot_Description = object["Robot.hasRobot_Description"];
this->hasRobot_Id = object["Robot.hasRobot_Id"];
this->hasRobot_MaximumLoadWeight = std::atof(object["Robot.hasRobot_MaximumLoadWeight"].c_str());
this->name = object["Robot._NAME"];
this->RobotID = std::atof(object["Robot.RobotID"].c_str());
if(this->hadByEndEffector_Robot== NULL && object["hadByEndEffector_Robot/EndEffector._NAME"]!=""){
this->hadByEndEffector_Robot = new EndEffector(object["hadByEndEffector_Robot/EndEffector._NAME"]);
}
if(this->hasRobot_WorkVolume.empty() && object["hasRobot_WorkVolume/BoxVolume._NAME"]!=""){
temp = Explode(object["hasRobot_WorkVolume/BoxVolume._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasRobot_WorkVolume.push_back(new BoxVolume(temp[i]));
}
}
if(this->hasWorkstation_Robot== NULL && object["hasWorkstation_Robot/KittingWorkstation._NAME"]!=""){
this->hasWorkstation_Robot = new KittingWorkstation(object["hasWorkstation_Robot/KittingWorkstation._NAME"]);
}

}std::vector<std::string> Robot::Explode(const std::string & str, char separator )
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
