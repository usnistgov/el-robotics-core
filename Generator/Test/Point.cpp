#include "Point.h"

Point::Point(std::string name) : DataThing(name){
this->name=name;
}Point::~Point(){
delete(dao);
delete(hasPose_Point);
delete(hasPartRefAndPose_Point);
delete(hasBoxVolume_MaximumPoint);
delete(hasBoxVolume_MinimumPoint);
}
double Point::gethasPoint_X(){
return this->hasPoint_X;
}
double Point::gethasPoint_Y(){
return this->hasPoint_Y;
}
double Point::gethasPoint_Z(){
return this->hasPoint_Z;
}
std::string Point::getname(){
return this->name;
}
int Point::getPointID(){
return this->PointID;
}
DAO* Point::getdao(){
return this->dao;
}
Pose* Point::gethasPose_Point(){
return this->hasPose_Point;
}
PartRefAndPose* Point::gethasPartRefAndPose_Point(){
return this->hasPartRefAndPose_Point;
}
BoxVolume* Point::gethasBoxVolume_MaximumPoint(){
return this->hasBoxVolume_MaximumPoint;
}
BoxVolume* Point::gethasBoxVolume_MinimumPoint(){
return this->hasBoxVolume_MinimumPoint;
}
void Point::sethasPoint_X(double _hasPoint_X){
this->hasPoint_X= _hasPoint_X;
}
void Point::sethasPoint_Y(double _hasPoint_Y){
this->hasPoint_Y= _hasPoint_Y;
}
void Point::sethasPoint_Z(double _hasPoint_Z){
this->hasPoint_Z= _hasPoint_Z;
}
void Point::setname(std::string _name){
this->name= _name;
}
void Point::setPointID(int _PointID){
this->PointID= _PointID;
}
void Point::setdao(DAO* _dao){
this->dao= _dao;
}
void Point::sethasPose_Point(Pose* _hasPose_Point){
this->hasPose_Point= _hasPose_Point;
}
void Point::sethasPartRefAndPose_Point(PartRefAndPose* _hasPartRefAndPose_Point){
this->hasPartRefAndPose_Point= _hasPartRefAndPose_Point;
}
void Point::sethasBoxVolume_MaximumPoint(BoxVolume* _hasBoxVolume_MaximumPoint){
this->hasBoxVolume_MaximumPoint= _hasBoxVolume_MaximumPoint;
}
void Point::sethasBoxVolume_MinimumPoint(BoxVolume* _hasBoxVolume_MinimumPoint){
this->hasBoxVolume_MinimumPoint= _hasBoxVolume_MinimumPoint;
}
void Point::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("Point");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void Point::set(std::string name){
 dao  = new DAO("Point");
 dao->set(name);
delete (dao);
}

void Point::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasPoint_X = std::atof(object["Point.hasPoint_X"].c_str());
this->hasPoint_Y = std::atof(object["Point.hasPoint_Y"].c_str());
this->hasPoint_Z = std::atof(object["Point.hasPoint_Z"].c_str());
this->name = object["Point._NAME"];
this->PointID = std::atof(object["Point.PointID"].c_str());
this->hasPose_Point = new Pose(" ");
this->hasPose_Point->sethasPose_Point(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,14) == "hasPose_Point/"){
mapTemp[it->first.substr(14,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPose_Point->copy(mapTemp);
this->hasPartRefAndPose_Point = new PartRefAndPose(" ");
this->hasPartRefAndPose_Point->sethasPartRefAndPose_Point(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,24) == "hasPartRefAndPose_Point/"){
mapTemp[it->first.substr(24,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasPartRefAndPose_Point->copy(mapTemp);
this->hasBoxVolume_MaximumPoint = new BoxVolume(" ");
this->hasBoxVolume_MaximumPoint->sethasBoxVolume_MaximumPoint(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,26) == "hasBoxVolume_MaximumPoint/"){
mapTemp[it->first.substr(26,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasBoxVolume_MaximumPoint->copy(mapTemp);
this->hasBoxVolume_MinimumPoint = new BoxVolume(" ");
this->hasBoxVolume_MinimumPoint->sethasBoxVolume_MinimumPoint(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,26) == "hasBoxVolume_MinimumPoint/"){
mapTemp[it->first.substr(26,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasBoxVolume_MinimumPoint->copy(mapTemp);

}std::vector<std::string> Point::Explode(const std::string & str, char separator )
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
