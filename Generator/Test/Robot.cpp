#include "Robot.h"

Robot::Robot(std::string name) : SolidObject(name){
this->name=name;
}Robot::~Robot(){
delete(dao);
delete(hadByRobot_Workstation);
for(size_t i = 0; i < hasRobot_WorkVolume.size(); i++)
delete(hasRobot_WorkVolume[i]);
}
std::string Robot::gethasRobot_Id(){
return this->hasRobot_Id;
}
double Robot::gethasRobot_MaximumLoadWeight(){
return this->hasRobot_MaximumLoadWeight;
}
std::string Robot::gethasRobot_Description(){
return this->hasRobot_Description;
}
std::string Robot::getname(){
return this->name;
}
int Robot::getRobotID(){
return this->RobotID;
}
DAO* Robot::getdao(){
return this->dao;
}
KittingWorkstation* Robot::gethadByRobot_Workstation(){
return this->hadByRobot_Workstation;
}
std::vector<BoxVolume*> Robot::gethasRobot_WorkVolume(){
return this->hasRobot_WorkVolume;
}
void Robot::sethasRobot_Id(std::string _hasRobot_Id){
this->hasRobot_Id= _hasRobot_Id;
}
void Robot::sethasRobot_MaximumLoadWeight(double _hasRobot_MaximumLoadWeight){
this->hasRobot_MaximumLoadWeight= _hasRobot_MaximumLoadWeight;
}
void Robot::sethasRobot_Description(std::string _hasRobot_Description){
this->hasRobot_Description= _hasRobot_Description;
}
void Robot::setname(std::string _name){
this->name= _name;
}
void Robot::setRobotID(int _RobotID){
this->RobotID= _RobotID;
}
void Robot::setdao(DAO* _dao){
this->dao= _dao;
}
void Robot::sethadByRobot_Workstation(KittingWorkstation* _hadByRobot_Workstation){
this->hadByRobot_Workstation= _hadByRobot_Workstation;
}
void Robot::sethasRobot_WorkVolume(std::vector<BoxVolume*> _hasRobot_WorkVolume){
this->hasRobot_WorkVolume= _hasRobot_WorkVolume;
}
void Robot::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("Robot");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void Robot::set(std::string name){
 dao  = new DAO("Robot");
 dao->set(name);
delete (dao);
}

void Robot::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasRobot_Id = object["Robot.hasRobot_Id"];
this->hasRobot_MaximumLoadWeight = std::atof(object["Robot.hasRobot_MaximumLoadWeight"].c_str());
this->hasRobot_Description = object["Robot.hasRobot_Description"];
this->name = object["Robot._NAME"];
this->RobotID = std::atof(object["Robot.RobotID"].c_str());
this->hadByRobot_Workstation = new KittingWorkstation(" ");
this->hadByRobot_Workstation->sethadByRobot_Workstation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,23) == "hadByRobot_Workstation/"){
mapTemp[it->first.substr(23,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByRobot_Workstation->copy(mapTemp);
mapTemp.clear();
mapTempBis.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,20) == "hasRobot_WorkVolume/"){
mapTemp[it->first.substr(20,it->first.length())] = it->second;
nbVal=Explode(it->second,' ').size();
}
}
nbValCurrent=0;
if(nbValCurrent<=nbVal){
for (std::map<std::string, std::string>::iterator it = mapTemp.begin(); it
!= mapTemp.end(); it++) {
mapTempBis[it->first]=Explode(it->second,' ')[nbValCurrent];
if(!mapTempBis.empty()){
this->hasRobot_WorkVolume.push_back(new BoxVolume(" "));
this->hasRobot_WorkVolume.back()->gethasRobot_WorkVolume().push_back(this);
this->hasRobot_WorkVolume.back()->copy(mapTempBis);
}
}
nbValCurrent++;
}

}std::vector<std::string> Robot::Explode(const std::string & str, char separator )
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
