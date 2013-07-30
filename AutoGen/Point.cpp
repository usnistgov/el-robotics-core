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

#include "Point.h"


 #include "BoxVolume.h"
 #include "DAO.h"
 #include "PoseLocation.h"
 #include "PartRefAndPose.h"

Point::Point(std::string name) : DataThing(name){
dao = NULL;
hasBoxVolume_MaximumPoint = NULL;
hasBoxVolume_MinimumPoint = NULL;
hasPoseLocation_Point = NULL;
hasPartRefAndPose_Point = NULL;

}Point::~Point(){
delete(hasBoxVolume_MaximumPoint);
delete(hasBoxVolume_MinimumPoint);
delete(hasPoseLocation_Point);
delete(hasPartRefAndPose_Point);
}
double Point::gethasPoint_X(){
return hasPoint_X;
}
double Point::gethasPoint_Y(){
return hasPoint_Y;
}
double Point::gethasPoint_Z(){
return hasPoint_Z;
}
int Point::getPointID(){
return PointID;
}
DAO* Point::getdao(){
return dao;
}
BoxVolume* Point::gethasBoxVolume_MaximumPoint(){
return hasBoxVolume_MaximumPoint;
}
BoxVolume* Point::gethasBoxVolume_MinimumPoint(){
return hasBoxVolume_MinimumPoint;
}
PoseLocation* Point::gethasPoseLocation_Point(){
return hasPoseLocation_Point;
}
PartRefAndPose* Point::gethasPartRefAndPose_Point(){
return hasPartRefAndPose_Point;
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
void Point::setPointID(int _PointID){
this->PointID= _PointID;
}
void Point::setdao(DAO* _dao){
this->dao= _dao;
}
void Point::sethasBoxVolume_MaximumPoint(BoxVolume* _hasBoxVolume_MaximumPoint){
this->hasBoxVolume_MaximumPoint= _hasBoxVolume_MaximumPoint;
}
void Point::sethasBoxVolume_MinimumPoint(BoxVolume* _hasBoxVolume_MinimumPoint){
this->hasBoxVolume_MinimumPoint= _hasBoxVolume_MinimumPoint;
}
void Point::sethasPoseLocation_Point(PoseLocation* _hasPoseLocation_Point){
this->hasPoseLocation_Point= _hasPoseLocation_Point;
}
void Point::sethasPartRefAndPose_Point(PartRefAndPose* _hasPartRefAndPose_Point){
this->hasPartRefAndPose_Point= _hasPartRefAndPose_Point;
}
void Point::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("Point");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Point::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
ss.str("");
ss << hasPoint_X;
data["hasPoint_X"]=ss.str();
ss.str("");
ss << hasPoint_Y;
data["hasPoint_Y"]=ss.str();
ss.str("");
ss << hasPoint_Z;
data["hasPoint_Z"]=ss.str();
data["name"]="'" + name + "'";
ss.str("");
ss << PointID;
data["PointID"]=ss.str();
if(hasBoxVolume_MaximumPoint!=NULL)
data["hasBoxVolume_MaximumPoint"]=hasBoxVolume_MaximumPoint->getname();
if(hasBoxVolume_MinimumPoint!=NULL)
data["hasBoxVolume_MinimumPoint"]=hasBoxVolume_MinimumPoint->getname();
if(hasPoseLocation_Point!=NULL)
data["hasPoseLocation_Point"]=hasPoseLocation_Point->getname();
if(hasPartRefAndPose_Point!=NULL)
data["hasPartRefAndPose_Point"]=hasPartRefAndPose_Point->getname();
dao  = new DAO("Point");
dao->set(data);
delete (dao);
}
void Point::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << hasPoint_X;
data["hasPoint_X"]=ss.str();
ss.str("");
ss << hasPoint_Y;
data["hasPoint_Y"]=ss.str();
ss.str("");
ss << hasPoint_Z;
data["hasPoint_Z"]=ss.str();
ss.str("");
ss << temp0->getDataThingID();
data["PointID"]=ss.str();
if(hasBoxVolume_MaximumPoint!=NULL)
data["hasBoxVolume_MaximumPoint"]=hasBoxVolume_MaximumPoint->getname();
if(hasBoxVolume_MinimumPoint!=NULL)
data["hasBoxVolume_MinimumPoint"]=hasBoxVolume_MinimumPoint->getname();
if(hasPoseLocation_Point!=NULL)
data["hasPoseLocation_Point"]=hasPoseLocation_Point->getname();
if(hasPartRefAndPose_Point!=NULL)
data["hasPartRefAndPose_Point"]=hasPartRefAndPose_Point->getname();
dao  = new DAO("Point");
dao->insert(data);
delete (dao);
this->set(name);
}

void Point::copy(std::map<std::string,std::string> object){delete(hasBoxVolume_MaximumPoint);
hasBoxVolume_MaximumPoint=NULL;
delete(hasBoxVolume_MinimumPoint);
hasBoxVolume_MinimumPoint=NULL;
delete(hasPoseLocation_Point);
hasPoseLocation_Point=NULL;
delete(hasPartRefAndPose_Point);
hasPartRefAndPose_Point=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Point*> tmp;
this->hasPoint_X = std::atof(object["Point.hasPoint_X"].c_str());
this->hasPoint_Y = std::atof(object["Point.hasPoint_Y"].c_str());
this->hasPoint_Z = std::atof(object["Point.hasPoint_Z"].c_str());
this->name = object["Point._NAME"];
this->PointID = std::atof(object["Point.PointID"].c_str());
if(this->hasBoxVolume_MaximumPoint== NULL && object["hasBoxVolume_MaximumPoint/BoxVolume._NAME"]!=""){
this->hasBoxVolume_MaximumPoint = new BoxVolume(object["hasBoxVolume_MaximumPoint/BoxVolume._NAME"]);
}
if(this->hasBoxVolume_MinimumPoint== NULL && object["hasBoxVolume_MinimumPoint/BoxVolume._NAME"]!=""){
this->hasBoxVolume_MinimumPoint = new BoxVolume(object["hasBoxVolume_MinimumPoint/BoxVolume._NAME"]);
}
if(this->hasPoseLocation_Point== NULL && object["hasPoseLocation_Point/PoseLocation._NAME"]!=""){
this->hasPoseLocation_Point = new PoseLocation(object["hasPoseLocation_Point/PoseLocation._NAME"]);
}
if(this->hasPartRefAndPose_Point== NULL && object["hasPartRefAndPose_Point/PartRefAndPose._NAME"]!=""){
this->hasPartRefAndPose_Point = new PartRefAndPose(object["hasPartRefAndPose_Point/PartRefAndPose._NAME"]);
}

}std::vector<std::string> Point::Explode(const std::string & str, char separator )
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
