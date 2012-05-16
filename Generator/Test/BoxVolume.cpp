#include "BoxVolume.h"

BoxVolume::BoxVolume(std::string name) : DataThing(name){
this->name=name;
}BoxVolume::~BoxVolume(){
delete(dao);
delete(hasBoxVolume_MaximumPoint);
delete(hasBoxVolume_MinimumPoint);
for(size_t i = 0; i < hasWorkstation_OtherObstacles.size(); i++)
delete(hasWorkstation_OtherObstacles[i]);
for(size_t i = 0; i < hasRobot_WorkVolume.size(); i++)
delete(hasRobot_WorkVolume[i]);
}
std::string BoxVolume::getname(){
return this->name;
}
int BoxVolume::getBoxVolumeID(){
return this->BoxVolumeID;
}
DAO* BoxVolume::getdao(){
return this->dao;
}
Point* BoxVolume::gethasBoxVolume_MaximumPoint(){
return this->hasBoxVolume_MaximumPoint;
}
Point* BoxVolume::gethasBoxVolume_MinimumPoint(){
return this->hasBoxVolume_MinimumPoint;
}
std::vector<KittingWorkstation*> BoxVolume::gethasWorkstation_OtherObstacles(){
return this->hasWorkstation_OtherObstacles;
}
std::vector<Robot*> BoxVolume::gethasRobot_WorkVolume(){
return this->hasRobot_WorkVolume;
}
void BoxVolume::setname(std::string _name){
this->name= _name;
}
void BoxVolume::setBoxVolumeID(int _BoxVolumeID){
this->BoxVolumeID= _BoxVolumeID;
}
void BoxVolume::setdao(DAO* _dao){
this->dao= _dao;
}
void BoxVolume::sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint){
this->hasBoxVolume_MaximumPoint= _hasBoxVolume_MaximumPoint;
}
void BoxVolume::sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint){
this->hasBoxVolume_MinimumPoint= _hasBoxVolume_MinimumPoint;
}
void BoxVolume::sethasWorkstation_OtherObstacles(std::vector<KittingWorkstation*> _hasWorkstation_OtherObstacles){
this->hasWorkstation_OtherObstacles= _hasWorkstation_OtherObstacles;
}
void BoxVolume::sethasRobot_WorkVolume(std::vector<Robot*> _hasRobot_WorkVolume){
this->hasRobot_WorkVolume= _hasRobot_WorkVolume;
}
void BoxVolume::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("BoxVolume");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void BoxVolume::set(std::string name){
 dao  = new DAO("BoxVolume");
 dao->set(name);
delete (dao);
}

void BoxVolume::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["BoxVolume._NAME"];
this->BoxVolumeID = std::atof(object["BoxVolume.BoxVolumeID"].c_str());
this->hasBoxVolume_MaximumPoint = new Point(" ");
this->hasBoxVolume_MaximumPoint->sethasBoxVolume_MaximumPoint(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,26) == "hasBoxVolume_MaximumPoint/"){
mapTemp[it->first.substr(26,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasBoxVolume_MaximumPoint->copy(mapTemp);
this->hasBoxVolume_MinimumPoint = new Point(" ");
this->hasBoxVolume_MinimumPoint->sethasBoxVolume_MinimumPoint(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,26) == "hasBoxVolume_MinimumPoint/"){
mapTemp[it->first.substr(26,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasBoxVolume_MinimumPoint->copy(mapTemp);
mapTemp.clear();
mapTempBis.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,30) == "hasWorkstation_OtherObstacles/"){
mapTemp[it->first.substr(30,it->first.length())] = it->second;
nbVal=Explode(it->second,' ').size();
}
}
nbValCurrent=0;
if(nbValCurrent<=nbVal){
for (std::map<std::string, std::string>::iterator it = mapTemp.begin(); it
!= mapTemp.end(); it++) {
mapTempBis[it->first]=Explode(it->second,' ')[nbValCurrent];
if(!mapTempBis.empty()){
this->hasWorkstation_OtherObstacles.push_back(new KittingWorkstation(" "));
this->hasWorkstation_OtherObstacles.back()->gethasWorkstation_OtherObstacles().push_back(this);
this->hasWorkstation_OtherObstacles.back()->copy(mapTempBis);
}
}
nbValCurrent++;
}
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
this->hasRobot_WorkVolume.push_back(new Robot(" "));
this->hasRobot_WorkVolume.back()->gethasRobot_WorkVolume().push_back(this);
this->hasRobot_WorkVolume.back()->copy(mapTempBis);
}
}
nbValCurrent++;
}

}std::vector<std::string> BoxVolume::Explode(const std::string & str, char separator )
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
