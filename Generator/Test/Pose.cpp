#include "Pose.h"

Pose::Pose(std::string name) : PhysicalLocation(name){
this->name=name;
}Pose::~Pose(){
delete(dao);
delete(hasPose_Point);
delete(hasPose_Rpy);
}
std::string Pose::getname(){
return this->name;
}
int Pose::getPoseID(){
return this->PoseID;
}
DAO* Pose::getdao(){
return this->dao;
}
Point* Pose::gethasPose_Point(){
return this->hasPose_Point;
}
RollPitchYaw* Pose::gethasPose_Rpy(){
return this->hasPose_Rpy;
}
void Pose::setname(std::string _name){
this->name= _name;
}
void Pose::setPoseID(int _PoseID){
this->PoseID= _PoseID;
}
void Pose::setdao(DAO* _dao){
this->dao= _dao;
}
void Pose::sethasPose_Point(Point* _hasPose_Point){
this->hasPose_Point= _hasPose_Point;
}
void Pose::sethasPose_Rpy(RollPitchYaw* _hasPose_Rpy){
this->hasPose_Rpy= _hasPose_Rpy;
}
void Pose::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);
 PhysicalLocation::copy(temp);
delete (dao);
dao  = new DAO("Pose");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void Pose::set(std::string name){
 dao  = new DAO("Pose");
 dao->set(name);
delete (dao);
}

void Pose::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["Pose._NAME"];
this->PoseID = std::atof(object["Pose.PoseID"].c_str());
this->hasPose_Point = new Point(" ");
this->hasPose_Point->sethasPose_Point(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,14) == "hasPose_Point/"){
mapTemp[it->first.substr(14,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPose_Point->copy(mapTemp);
this->hasPose_Rpy = new RollPitchYaw(" ");
this->hasPose_Rpy->sethasPose_Rpy(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,12) == "hasPose_Rpy/"){
mapTemp[it->first.substr(12,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPose_Rpy->copy(mapTemp);

}std::vector<std::string> Pose::Explode(const std::string & str, char separator )
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
