#include "PartRefAndPose.h"

PartRefAndPose::PartRefAndPose(std::string name) : DataThing(name){
this->name=name;
}PartRefAndPose::~PartRefAndPose(){
delete(dao);
delete(hasPartRefAndPose_Rpy);
delete(hasPartRefAndPose_Point);
}
std::string PartRefAndPose::gethasPartRefAndPose_Ref(){
return this->hasPartRefAndPose_Ref;
}
std::string PartRefAndPose::getname(){
return this->name;
}
int PartRefAndPose::getPartRefAndPoseID(){
return this->PartRefAndPoseID;
}
DAO* PartRefAndPose::getdao(){
return this->dao;
}
RollPitchYaw* PartRefAndPose::gethasPartRefAndPose_Rpy(){
return this->hasPartRefAndPose_Rpy;
}
Point* PartRefAndPose::gethasPartRefAndPose_Point(){
return this->hasPartRefAndPose_Point;
}
void PartRefAndPose::sethasPartRefAndPose_Ref(std::string _hasPartRefAndPose_Ref){
this->hasPartRefAndPose_Ref= _hasPartRefAndPose_Ref;
}
void PartRefAndPose::setname(std::string _name){
this->name= _name;
}
void PartRefAndPose::setPartRefAndPoseID(int _PartRefAndPoseID){
this->PartRefAndPoseID= _PartRefAndPoseID;
}
void PartRefAndPose::setdao(DAO* _dao){
this->dao= _dao;
}
void PartRefAndPose::sethasPartRefAndPose_Rpy(RollPitchYaw* _hasPartRefAndPose_Rpy){
this->hasPartRefAndPose_Rpy= _hasPartRefAndPose_Rpy;
}
void PartRefAndPose::sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point){
this->hasPartRefAndPose_Point= _hasPartRefAndPose_Point;
}
void PartRefAndPose::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("PartRefAndPose");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void PartRefAndPose::set(std::string name){
 dao  = new DAO("PartRefAndPose");
 dao->set(name);
delete (dao);
}

void PartRefAndPose::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasPartRefAndPose_Ref = object["PartRefAndPose.hasPartRefAndPose_Ref"];
this->name = object["PartRefAndPose._NAME"];
this->PartRefAndPoseID = std::atof(object["PartRefAndPose.PartRefAndPoseID"].c_str());
this->hasPartRefAndPose_Rpy = new RollPitchYaw(" ");
this->hasPartRefAndPose_Rpy->sethasPartRefAndPose_Rpy(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,22) == "hasPartRefAndPose_Rpy/"){
mapTemp[it->first.substr(22,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPartRefAndPose_Rpy->copy(mapTemp);
this->hasPartRefAndPose_Point = new Point(" ");
this->hasPartRefAndPose_Point->sethasPartRefAndPose_Point(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,24) == "hasPartRefAndPose_Point/"){
mapTemp[it->first.substr(24,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPartRefAndPose_Point->copy(mapTemp);

}std::vector<std::string> PartRefAndPose::Explode(const std::string & str, char separator )
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
