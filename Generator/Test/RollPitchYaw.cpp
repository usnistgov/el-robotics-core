#include "RollPitchYaw.h"

RollPitchYaw::RollPitchYaw(std::string name) : DataThing(name){
this->name=name;
}RollPitchYaw::~RollPitchYaw(){
delete(dao);
delete(hasPose_Rpy);
delete(hasPartRefAndPose_Rpy);
}
double RollPitchYaw::gethasRpy_Roll(){
return this->hasRpy_Roll;
}
double RollPitchYaw::gethasRpy_Pitch(){
return this->hasRpy_Pitch;
}
double RollPitchYaw::gethasRpy_Yaw(){
return this->hasRpy_Yaw;
}
std::string RollPitchYaw::getname(){
return this->name;
}
int RollPitchYaw::getRollPitchYawID(){
return this->RollPitchYawID;
}
DAO* RollPitchYaw::getdao(){
return this->dao;
}
Pose* RollPitchYaw::gethasPose_Rpy(){
return this->hasPose_Rpy;
}
PartRefAndPose* RollPitchYaw::gethasPartRefAndPose_Rpy(){
return this->hasPartRefAndPose_Rpy;
}
void RollPitchYaw::sethasRpy_Roll(double _hasRpy_Roll){
this->hasRpy_Roll= _hasRpy_Roll;
}
void RollPitchYaw::sethasRpy_Pitch(double _hasRpy_Pitch){
this->hasRpy_Pitch= _hasRpy_Pitch;
}
void RollPitchYaw::sethasRpy_Yaw(double _hasRpy_Yaw){
this->hasRpy_Yaw= _hasRpy_Yaw;
}
void RollPitchYaw::setname(std::string _name){
this->name= _name;
}
void RollPitchYaw::setRollPitchYawID(int _RollPitchYawID){
this->RollPitchYawID= _RollPitchYawID;
}
void RollPitchYaw::setdao(DAO* _dao){
this->dao= _dao;
}
void RollPitchYaw::sethasPose_Rpy(Pose* _hasPose_Rpy){
this->hasPose_Rpy= _hasPose_Rpy;
}
void RollPitchYaw::sethasPartRefAndPose_Rpy(PartRefAndPose* _hasPartRefAndPose_Rpy){
this->hasPartRefAndPose_Rpy= _hasPartRefAndPose_Rpy;
}
void RollPitchYaw::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("RollPitchYaw");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void RollPitchYaw::set(std::string name){
 dao  = new DAO("RollPitchYaw");
 dao->set(name);
delete (dao);
}

void RollPitchYaw::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasRpy_Roll = std::atof(object["RollPitchYaw.hasRpy_Roll"].c_str());
this->hasRpy_Pitch = std::atof(object["RollPitchYaw.hasRpy_Pitch"].c_str());
this->hasRpy_Yaw = std::atof(object["RollPitchYaw.hasRpy_Yaw"].c_str());
this->name = object["RollPitchYaw._NAME"];
this->RollPitchYawID = std::atof(object["RollPitchYaw.RollPitchYawID"].c_str());
this->hasPose_Rpy = new Pose(" ");
this->hasPose_Rpy->sethasPose_Rpy(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,12) == "hasPose_Rpy/"){
mapTemp[it->first.substr(12,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPose_Rpy->copy(mapTemp);
this->hasPartRefAndPose_Rpy = new PartRefAndPose(" ");
this->hasPartRefAndPose_Rpy->sethasPartRefAndPose_Rpy(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,22) == "hasPartRefAndPose_Rpy/"){
mapTemp[it->first.substr(22,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPartRefAndPose_Rpy->copy(mapTemp);

}std::vector<std::string> RollPitchYaw::Explode(const std::string & str, char separator )
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
