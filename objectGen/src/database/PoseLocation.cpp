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

#include "PoseLocation.h"


 #include "DAO.h"
 #include "ShapeDesign.h"
 #include "Vector.h"
 #include "Point.h"

PoseLocation::PoseLocation(std::string name) : PhysicalLocation(name){
dao = NULL;
hasPoseLocation_Point = NULL;
hasPoseLocation_ZAxis = NULL;
hasPoseLocation_XAxis = NULL;

}PoseLocation::~PoseLocation(){
delete(hasPoseLocation_Point);
delete(hasPoseLocation_ZAxis);
delete(hasPoseLocation_XAxis);
for(std::size_t i = 0; i < hasShapeDesign_GraspPose.size(); i++)
delete(hasShapeDesign_GraspPose[i]);
}
int PoseLocation::getPoseLocationID(){
return PoseLocationID;
}
DAO* PoseLocation::getdao(){
return dao;
}
Point* PoseLocation::gethasPoseLocation_Point(){
return hasPoseLocation_Point;
}
Vector* PoseLocation::gethasPoseLocation_ZAxis(){
return hasPoseLocation_ZAxis;
}
Vector* PoseLocation::gethasPoseLocation_XAxis(){
return hasPoseLocation_XAxis;
}
std::vector<ShapeDesign*> PoseLocation::gethasShapeDesign_GraspPose(){
return hasShapeDesign_GraspPose;
}
void PoseLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseLocation::sethasPoseLocation_Point(Point* _hasPoseLocation_Point){
this->hasPoseLocation_Point= _hasPoseLocation_Point;
}
void PoseLocation::sethasPoseLocation_ZAxis(Vector* _hasPoseLocation_ZAxis){
this->hasPoseLocation_ZAxis= _hasPoseLocation_ZAxis;
}
void PoseLocation::sethasPoseLocation_XAxis(Vector* _hasPoseLocation_XAxis){
this->hasPoseLocation_XAxis= _hasPoseLocation_XAxis;
}
void PoseLocation::sethasShapeDesign_GraspPose(std::vector<ShapeDesign*> _hasShapeDesign_GraspPose){
this->hasShapeDesign_GraspPose= _hasShapeDesign_GraspPose;
}
void PoseLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);delete (dao);
 PhysicalLocation::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("PoseLocation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PoseLocation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
PhysicalLocation* temp0 = (PhysicalLocation*) this;
temp0->set(name);
DataThing* temp1 = (DataThing*) this;
temp1->set(name);
data["name"]=name;
ss.str("");
ss << PoseLocationID;
data["PoseLocationID"]=ss.str();
if(hasPoseLocation_Point!=NULL)
data["hasPoseLocation_Point"]=hasPoseLocation_Point->getname();
if(hasPoseLocation_ZAxis!=NULL)
data["hasPoseLocation_ZAxis"]=hasPoseLocation_ZAxis->getname();
if(hasPoseLocation_XAxis!=NULL)
data["hasPoseLocation_XAxis"]=hasPoseLocation_XAxis->getname();
for(unsigned int i=0;i<hasShapeDesign_GraspPose.size();++i){
ss.str("");
hasShapeDesign_GraspPose[i]->get(hasShapeDesign_GraspPose[i]->getname());
ss << hasShapeDesign_GraspPose[i]->getShapeDesignID();
data["hasShapeDesign_GraspPose"]=data["hasShapeDesign_GraspPose"]+" "+ss.str();
}
dao  = new DAO("PoseLocation");
dao->set(data);
delete (dao);
}

void PoseLocation::copy(std::map<std::string,std::string> object){delete(hasPoseLocation_Point);
hasPoseLocation_Point=NULL;
delete(hasPoseLocation_ZAxis);
hasPoseLocation_ZAxis=NULL;
delete(hasPoseLocation_XAxis);
hasPoseLocation_XAxis=NULL;
for(std::size_t i = 0; i < hasShapeDesign_GraspPose.size(); i++){
delete(hasShapeDesign_GraspPose[i]);
hasShapeDesign_GraspPose[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseLocation*> tmp;
this->name = object["PoseLocation._NAME"];
this->PoseLocationID = std::atof(object["PoseLocation.PoseLocationID"].c_str());
if(this->hasPoseLocation_Point== NULL && object["hasPoseLocation_Point/Point._NAME"]!=""){
this->hasPoseLocation_Point = new Point(object["hasPoseLocation_Point/Point._NAME"]);
}
if(this->hasPoseLocation_ZAxis== NULL && object["hasPoseLocation_ZAxis/Vector._NAME"]!=""){
this->hasPoseLocation_ZAxis = new Vector(object["hasPoseLocation_ZAxis/Vector._NAME"]);
}
if(this->hasPoseLocation_XAxis== NULL && object["hasPoseLocation_XAxis/Vector._NAME"]!=""){
this->hasPoseLocation_XAxis = new Vector(object["hasPoseLocation_XAxis/Vector._NAME"]);
}
if(this->hasShapeDesign_GraspPose.empty() && object["hasShapeDesign_GraspPose/ShapeDesign._NAME"]!=""){
temp = Explode(object["hasShapeDesign_GraspPose/ShapeDesign._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasShapeDesign_GraspPose.push_back(new ShapeDesign(temp[i]));
}
}

}std::vector<std::string> PoseLocation::Explode(const std::string & str, char separator )
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
