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


 #include "ShapeDesign.h"
 #include "DAO.h"
 #include "Vector.h"
 #include "Point.h"

PoseLocation::PoseLocation(std::string name) : PhysicalLocation(name){
dao = NULL;
hadByGraspPose_ShapeDesign = NULL;
hasPoseLocation_XAxis = NULL;
hasPoseLocation_ZAxis = NULL;
hasPoseLocation_Point = NULL;

}PoseLocation::~PoseLocation(){
delete(hadByGraspPose_ShapeDesign);
delete(hasPoseLocation_XAxis);
delete(hasPoseLocation_ZAxis);
delete(hasPoseLocation_Point);
}
double PoseLocation::gethasPoseLocation_OrientationStandardDeviation(){
return hasPoseLocation_OrientationStandardDeviation;
}
double PoseLocation::gethasPoseLocation_PositionStandardDeviation(){
return hasPoseLocation_PositionStandardDeviation;
}
int PoseLocation::getPoseLocationID(){
return PoseLocationID;
}
DAO* PoseLocation::getdao(){
return dao;
}
ShapeDesign* PoseLocation::gethadByGraspPose_ShapeDesign(){
return hadByGraspPose_ShapeDesign;
}
Vector* PoseLocation::gethasPoseLocation_XAxis(){
return hasPoseLocation_XAxis;
}
Vector* PoseLocation::gethasPoseLocation_ZAxis(){
return hasPoseLocation_ZAxis;
}
Point* PoseLocation::gethasPoseLocation_Point(){
return hasPoseLocation_Point;
}
void PoseLocation::sethasPoseLocation_OrientationStandardDeviation(double _hasPoseLocation_OrientationStandardDeviation){
this->hasPoseLocation_OrientationStandardDeviation= _hasPoseLocation_OrientationStandardDeviation;
}
void PoseLocation::sethasPoseLocation_PositionStandardDeviation(double _hasPoseLocation_PositionStandardDeviation){
this->hasPoseLocation_PositionStandardDeviation= _hasPoseLocation_PositionStandardDeviation;
}
void PoseLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseLocation::sethadByGraspPose_ShapeDesign(ShapeDesign* _hadByGraspPose_ShapeDesign){
this->hadByGraspPose_ShapeDesign= _hadByGraspPose_ShapeDesign;
}
void PoseLocation::sethasPoseLocation_XAxis(Vector* _hasPoseLocation_XAxis){
this->hasPoseLocation_XAxis= _hasPoseLocation_XAxis;
}
void PoseLocation::sethasPoseLocation_ZAxis(Vector* _hasPoseLocation_ZAxis){
this->hasPoseLocation_ZAxis= _hasPoseLocation_ZAxis;
}
void PoseLocation::sethasPoseLocation_Point(Point* _hasPoseLocation_Point){
this->hasPoseLocation_Point= _hasPoseLocation_Point;
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
ss.str("");
ss << hasPoseLocation_OrientationStandardDeviation;
data["hasPoseLocation_OrientationStandardDeviation"]=ss.str();
ss.str("");
ss << hasPoseLocation_PositionStandardDeviation;
data["hasPoseLocation_PositionStandardDeviation"]=ss.str();
data["name"]=name;
ss.str("");
ss << PoseLocationID;
data["PoseLocationID"]=ss.str();
if(hadByGraspPose_ShapeDesign!=NULL)
data["hadByGraspPose_ShapeDesign"]=hadByGraspPose_ShapeDesign->getname();
if(hasPoseLocation_XAxis!=NULL)
data["hasPoseLocation_XAxis"]=hasPoseLocation_XAxis->getname();
if(hasPoseLocation_ZAxis!=NULL)
data["hasPoseLocation_ZAxis"]=hasPoseLocation_ZAxis->getname();
if(hasPoseLocation_Point!=NULL)
data["hasPoseLocation_Point"]=hasPoseLocation_Point->getname();
dao  = new DAO("PoseLocation");
dao->set(data);
delete (dao);
}

void PoseLocation::copy(std::map<std::string,std::string> object){delete(hadByGraspPose_ShapeDesign);
hadByGraspPose_ShapeDesign=NULL;
delete(hasPoseLocation_XAxis);
hasPoseLocation_XAxis=NULL;
delete(hasPoseLocation_ZAxis);
hasPoseLocation_ZAxis=NULL;
delete(hasPoseLocation_Point);
hasPoseLocation_Point=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseLocation*> tmp;
this->hasPoseLocation_OrientationStandardDeviation = std::atof(object["PoseLocation.hasPoseLocation_OrientationStandardDeviation"].c_str());
this->hasPoseLocation_PositionStandardDeviation = std::atof(object["PoseLocation.hasPoseLocation_PositionStandardDeviation"].c_str());
this->name = object["PoseLocation._NAME"];
this->PoseLocationID = std::atof(object["PoseLocation.PoseLocationID"].c_str());
if(this->hadByGraspPose_ShapeDesign== NULL && object["hadByGraspPose_ShapeDesign/ShapeDesign._NAME"]!=""){
this->hadByGraspPose_ShapeDesign = new ShapeDesign(object["hadByGraspPose_ShapeDesign/ShapeDesign._NAME"]);
}
if(this->hasPoseLocation_XAxis== NULL && object["hasPoseLocation_XAxis/Vector._NAME"]!=""){
this->hasPoseLocation_XAxis = new Vector(object["hasPoseLocation_XAxis/Vector._NAME"]);
}
if(this->hasPoseLocation_ZAxis== NULL && object["hasPoseLocation_ZAxis/Vector._NAME"]!=""){
this->hasPoseLocation_ZAxis = new Vector(object["hasPoseLocation_ZAxis/Vector._NAME"]);
}
if(this->hasPoseLocation_Point== NULL && object["hasPoseLocation_Point/Point._NAME"]!=""){
this->hasPoseLocation_Point = new Point(object["hasPoseLocation_Point/Point._NAME"]);
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
