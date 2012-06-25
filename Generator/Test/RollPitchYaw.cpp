#include "RollPitchYaw.h"


 #include "Pose.h"
 #include "DAO.h"
 #include "PartRefAndPose.h"

RollPitchYaw::RollPitchYaw(std::string name) : DataThing(name){
this->name=name;dao = NULL;

}RollPitchYaw::~RollPitchYaw(){
delete(dao);
for(std::size_t i = 0; i < hasPose_Rpy.size(); i++)
delete(hasPose_Rpy[i]);
for(std::size_t i = 0; i < hasPartRefAndPose_Rpy.size(); i++)
delete(hasPartRefAndPose_Rpy[i]);
}
double RollPitchYaw::gethasRpy_Roll(){
return hasRpy_Roll;
}
double RollPitchYaw::gethasRpy_Pitch(){
return hasRpy_Pitch;
}
double RollPitchYaw::gethasRpy_Yaw(){
return hasRpy_Yaw;
}
std::string RollPitchYaw::getname(){
return name;
}
int RollPitchYaw::getRollPitchYawID(){
return RollPitchYawID;
}
DAO* RollPitchYaw::getdao(){
return dao;
}
std::vector<Pose*>* RollPitchYaw::gethasPose_Rpy(){
return &hasPose_Rpy;
}
std::vector<PartRefAndPose*>* RollPitchYaw::gethasPartRefAndPose_Rpy(){
return &hasPartRefAndPose_Rpy;
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
void RollPitchYaw::setdao(DAO* _dao){
this->dao= _dao;
}
void RollPitchYaw::sethasPose_Rpy(std::vector<Pose*> _hasPose_Rpy){
this->hasPose_Rpy= _hasPose_Rpy;
}
void RollPitchYaw::sethasPartRefAndPose_Rpy(std::vector<PartRefAndPose*> _hasPartRefAndPose_Rpy){
this->hasPartRefAndPose_Rpy= _hasPartRefAndPose_Rpy;
}
void RollPitchYaw::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("RollPitchYaw");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void RollPitchYaw::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasRpy_Roll"]=hasRpy_Roll;
data["hasRpy_Pitch"]=hasRpy_Pitch;
data["hasRpy_Yaw"]=hasRpy_Yaw;
data["name"]=name;
data["RollPitchYawID"]=RollPitchYawID;
for(unsigned int i=0;i<hasPose_Rpy.size();++i){
ss.flush();
ss << hasPose_Rpy[i]->getPoseID();
data["hasPose_Rpy"]=data["hasPose_Rpy"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartRefAndPose_Rpy.size();++i){
ss.flush();
ss << hasPartRefAndPose_Rpy[i]->getPartRefAndPoseID();
data["hasPartRefAndPose_Rpy"]=data["hasPartRefAndPose_Rpy"]+" "+ss.str();
}
dao  = new DAO("RollPitchYaw");
dao->set(data);
delete (dao);
}

void RollPitchYaw::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<RollPitchYaw*> tmp;
this->hasRpy_Roll = std::atof(object["RollPitchYaw.hasRpy_Roll"].c_str());
this->hasRpy_Pitch = std::atof(object["RollPitchYaw.hasRpy_Pitch"].c_str());
this->hasRpy_Yaw = std::atof(object["RollPitchYaw.hasRpy_Yaw"].c_str());
this->name = object["RollPitchYaw._NAME"];
this->RollPitchYawID = std::atof(object["RollPitchYaw.RollPitchYawID"].c_str());
if(this->hasPose_Rpy.empty() && object["hasPose_Rpy/Pose._NAME"]!=""){
temp = Explode(object["hasPose_Rpy/Pose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPose_Rpy.push_back(new Pose(temp[i]));
}
}
if(this->hasPartRefAndPose_Rpy.empty() && object["hasPartRefAndPose_Rpy/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hasPartRefAndPose_Rpy/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartRefAndPose_Rpy.push_back(new PartRefAndPose(temp[i]));
}
}

}std::vector<std::string> RollPitchYaw::Explode(const std::string & str, char separator )
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
