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
hasKittingWorkstation_Robot = NULL;

}Robot::~Robot(){
delete(hadByEndEffector_Robot);
delete(hasKittingWorkstation_Robot);
for(std::size_t i = 0; i < hadByWorkVolume_Robot.size(); i++)
delete(hadByWorkVolume_Robot[i]);
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
std::vector<BoxVolume*> Robot::gethadByWorkVolume_Robot(){
return hadByWorkVolume_Robot;
}
KittingWorkstation* Robot::gethasKittingWorkstation_Robot(){
return hasKittingWorkstation_Robot;
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
void Robot::sethadByWorkVolume_Robot(std::vector<BoxVolume*> _hadByWorkVolume_Robot){
this->hadByWorkVolume_Robot= _hadByWorkVolume_Robot;
}
void Robot::sethasKittingWorkstation_Robot(KittingWorkstation* _hasKittingWorkstation_Robot){
this->hasKittingWorkstation_Robot= _hasKittingWorkstation_Robot;
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
for(unsigned int i=0;i<hadByWorkVolume_Robot.size();++i){
ss.str("");
hadByWorkVolume_Robot[i]->get(hadByWorkVolume_Robot[i]->getname());
ss << hadByWorkVolume_Robot[i]->getBoxVolumeID();
data["hadByWorkVolume_Robot"]=data["hadByWorkVolume_Robot"]+" "+ss.str();
}
if(hasKittingWorkstation_Robot!=NULL)
data["hasKittingWorkstation_Robot"]=hasKittingWorkstation_Robot->getname();
dao  = new DAO("Robot");
dao->set(data);
delete (dao);
}

void Robot::copy(std::map<std::string,std::string> object){delete(hadByEndEffector_Robot);
hadByEndEffector_Robot=NULL;
delete(hasKittingWorkstation_Robot);
hasKittingWorkstation_Robot=NULL;
for(std::size_t i = 0; i < hadByWorkVolume_Robot.size(); i++){
delete(hadByWorkVolume_Robot[i]);
hadByWorkVolume_Robot[i]=NULL;}
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
if(this->hadByWorkVolume_Robot.empty() && object["hadByWorkVolume_Robot/BoxVolume._NAME"]!=""){
temp = Explode(object["hadByWorkVolume_Robot/BoxVolume._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByWorkVolume_Robot.push_back(new BoxVolume(temp[i]));
}
}
if(this->hasKittingWorkstation_Robot== NULL && object["hasKittingWorkstation_Robot/KittingWorkstation._NAME"]!=""){
this->hasKittingWorkstation_Robot = new KittingWorkstation(object["hasKittingWorkstation_Robot/KittingWorkstation._NAME"]);
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
