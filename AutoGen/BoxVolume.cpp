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

#include "BoxVolume.h"


 #include "Robot.h"
 #include "KittingWorkstation.h"
 #include "DAO.h"
 #include "Point.h"

BoxVolume::BoxVolume(std::string name) : DataThing(name){
dao = NULL;
hadByOtherObstacle_KittingWorkstation = NULL;
hadByWorkVolume_Robot = NULL;
hasBoxVolume_MaximumPoint = NULL;
hasBoxVolume_MinimumPoint = NULL;

}BoxVolume::~BoxVolume(){
delete(hadByOtherObstacle_KittingWorkstation);
delete(hadByWorkVolume_Robot);
delete(hasBoxVolume_MaximumPoint);
delete(hasBoxVolume_MinimumPoint);
}
int BoxVolume::getBoxVolumeID(){
return BoxVolumeID;
}
DAO* BoxVolume::getdao(){
return dao;
}
KittingWorkstation* BoxVolume::gethadByOtherObstacle_KittingWorkstation(){
return hadByOtherObstacle_KittingWorkstation;
}
Robot* BoxVolume::gethadByWorkVolume_Robot(){
return hadByWorkVolume_Robot;
}
Point* BoxVolume::gethasBoxVolume_MaximumPoint(){
return hasBoxVolume_MaximumPoint;
}
Point* BoxVolume::gethasBoxVolume_MinimumPoint(){
return hasBoxVolume_MinimumPoint;
}
void BoxVolume::setdao(DAO* _dao){
this->dao= _dao;
}
void BoxVolume::sethadByOtherObstacle_KittingWorkstation(KittingWorkstation* _hadByOtherObstacle_KittingWorkstation){
this->hadByOtherObstacle_KittingWorkstation= _hadByOtherObstacle_KittingWorkstation;
}
void BoxVolume::sethadByWorkVolume_Robot(Robot* _hadByWorkVolume_Robot){
this->hadByWorkVolume_Robot= _hadByWorkVolume_Robot;
}
void BoxVolume::sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint){
this->hasBoxVolume_MaximumPoint= _hasBoxVolume_MaximumPoint;
}
void BoxVolume::sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint){
this->hasBoxVolume_MinimumPoint= _hasBoxVolume_MinimumPoint;
}
void BoxVolume::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("BoxVolume");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void BoxVolume::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["name"]=name;
ss.str("");
ss << BoxVolumeID;
data["BoxVolumeID"]=ss.str();
if(hadByOtherObstacle_KittingWorkstation!=NULL)
data["hadByOtherObstacle_KittingWorkstation"]=hadByOtherObstacle_KittingWorkstation->getname();
if(hadByWorkVolume_Robot!=NULL)
data["hadByWorkVolume_Robot"]=hadByWorkVolume_Robot->getname();
if(hasBoxVolume_MaximumPoint!=NULL)
data["hasBoxVolume_MaximumPoint"]=hasBoxVolume_MaximumPoint->getname();
if(hasBoxVolume_MinimumPoint!=NULL)
data["hasBoxVolume_MinimumPoint"]=hasBoxVolume_MinimumPoint->getname();
dao  = new DAO("BoxVolume");
dao->set(data);
delete (dao);
}

void BoxVolume::copy(std::map<std::string,std::string> object){delete(hadByOtherObstacle_KittingWorkstation);
hadByOtherObstacle_KittingWorkstation=NULL;
delete(hadByWorkVolume_Robot);
hadByWorkVolume_Robot=NULL;
delete(hasBoxVolume_MaximumPoint);
hasBoxVolume_MaximumPoint=NULL;
delete(hasBoxVolume_MinimumPoint);
hasBoxVolume_MinimumPoint=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<BoxVolume*> tmp;
this->name = object["BoxVolume._NAME"];
this->BoxVolumeID = std::atof(object["BoxVolume.BoxVolumeID"].c_str());
if(this->hadByOtherObstacle_KittingWorkstation== NULL && object["hadByOtherObstacle_KittingWorkstation/KittingWorkstation._NAME"]!=""){
this->hadByOtherObstacle_KittingWorkstation = new KittingWorkstation(object["hadByOtherObstacle_KittingWorkstation/KittingWorkstation._NAME"]);
}
if(this->hadByWorkVolume_Robot== NULL && object["hadByWorkVolume_Robot/Robot._NAME"]!=""){
this->hadByWorkVolume_Robot = new Robot(object["hadByWorkVolume_Robot/Robot._NAME"]);
}
if(this->hasBoxVolume_MaximumPoint== NULL && object["hasBoxVolume_MaximumPoint/Point._NAME"]!=""){
this->hasBoxVolume_MaximumPoint = new Point(object["hasBoxVolume_MaximumPoint/Point._NAME"]);
}
if(this->hasBoxVolume_MinimumPoint== NULL && object["hasBoxVolume_MinimumPoint/Point._NAME"]!=""){
this->hasBoxVolume_MinimumPoint = new Point(object["hasBoxVolume_MinimumPoint/Point._NAME"]);
}

}std::vector<std::string> BoxVolume::Explode(const std::string & str, char separator )
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
