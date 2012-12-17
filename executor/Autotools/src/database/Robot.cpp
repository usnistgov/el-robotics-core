/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "Robot.h"


 #include "BoxVolume.h"
 #include "EndEffector.h"
 #include "KittingWorkstation.h"
 #include "DAO.h"

Robot::Robot(std::string name) : SolidObject(name){
dao = NULL;
hadByEndEffector_Robot = NULL;
hasWorkstation_Robot = NULL;

}Robot::~Robot(){
delete(hadByEndEffector_Robot);
delete(hasWorkstation_Robot);
for(std::size_t i = 0; i < hasRobot_WorkVolume.size(); i++)
delete(hasRobot_WorkVolume[i]);
}
std::string Robot::gethasRobot_Description(){
return hasRobot_Description;
}
double Robot::gethasRobot_MaximumLoadWeight(){
return hasRobot_MaximumLoadWeight;
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
std::vector<BoxVolume*> Robot::gethasRobot_WorkVolume(){
return hasRobot_WorkVolume;
}
KittingWorkstation* Robot::gethasWorkstation_Robot(){
return hasWorkstation_Robot;
}
void Robot::sethasRobot_Description(std::string _hasRobot_Description){
this->hasRobot_Description= _hasRobot_Description;
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
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasRobot_Description"]=hasRobot_Description;
ss.str("");
ss << hasRobot_MaximumLoadWeight;
data["hasRobot_MaximumLoadWeight"]=ss.str();
data["name"]=name;
ss.str("");
ss << RobotID;
data["RobotID"]=ss.str();
if(hadByEndEffector_Robot!=NULL)
data["hadByEndEffector_Robot"]=hadByEndEffector_Robot->getname();
for(unsigned int i=0;i<hasRobot_WorkVolume.size();++i){
ss.str("");
hasRobot_WorkVolume[i]->get(hasRobot_WorkVolume[i]->getname());
ss << hasRobot_WorkVolume[i]->getBoxVolumeID();
data["hasRobot_WorkVolume"]=data["hasRobot_WorkVolume"]+" "+ss.str();
}
if(hasWorkstation_Robot!=NULL)
data["hasWorkstation_Robot"]=hasWorkstation_Robot->getname();
dao  = new DAO("Robot");
dao->set(data);
delete (dao);
}

void Robot::copy(std::map<std::string,std::string> object){delete(hadByEndEffector_Robot);
hadByEndEffector_Robot=NULL;
delete(hasWorkstation_Robot);
hasWorkstation_Robot=NULL;
for(std::size_t i = 0; i < hasRobot_WorkVolume.size(); i++){
delete(hasRobot_WorkVolume[i]);
hasRobot_WorkVolume[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Robot*> tmp;
this->hasRobot_Description = object["Robot.hasRobot_Description"];
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
