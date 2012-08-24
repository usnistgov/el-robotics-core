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

#include "PartRefAndPose.h"


 #include "DAO.h"
 #include "Vector.h"
 #include "KitDesign.h"
 #include "Point.h"

PartRefAndPose::PartRefAndPose(std::string name) : DataThing(name){
dao = NULL;
hasPartRefAndPose_ZAxis = NULL;
hadByPartRefAndPose_KitDesign = NULL;
hasPartRefAndPose_Point = NULL;
hasPartRefAndPose_XAxis = NULL;

}PartRefAndPose::~PartRefAndPose(){
delete(dao);
delete(hasPartRefAndPose_ZAxis);
delete(hadByPartRefAndPose_KitDesign);
delete(hasPartRefAndPose_Point);
delete(hasPartRefAndPose_XAxis);
}
std::string PartRefAndPose::gethasPartRefAndPose_Ref(){
return hasPartRefAndPose_Ref;
}
int PartRefAndPose::getPartRefAndPoseID(){
return PartRefAndPoseID;
}
DAO* PartRefAndPose::getdao(){
return dao;
}
Vector* PartRefAndPose::gethasPartRefAndPose_ZAxis(){
return hasPartRefAndPose_ZAxis;
}
KitDesign* PartRefAndPose::gethadByPartRefAndPose_KitDesign(){
return hadByPartRefAndPose_KitDesign;
}
Point* PartRefAndPose::gethasPartRefAndPose_Point(){
return hasPartRefAndPose_Point;
}
Vector* PartRefAndPose::gethasPartRefAndPose_XAxis(){
return hasPartRefAndPose_XAxis;
}
void PartRefAndPose::sethasPartRefAndPose_Ref(std::string _hasPartRefAndPose_Ref){
this->hasPartRefAndPose_Ref= _hasPartRefAndPose_Ref;
}
void PartRefAndPose::setdao(DAO* _dao){
this->dao= _dao;
}
void PartRefAndPose::sethasPartRefAndPose_ZAxis(Vector* _hasPartRefAndPose_ZAxis){
this->hasPartRefAndPose_ZAxis= _hasPartRefAndPose_ZAxis;
}
void PartRefAndPose::sethadByPartRefAndPose_KitDesign(KitDesign* _hadByPartRefAndPose_KitDesign){
this->hadByPartRefAndPose_KitDesign= _hadByPartRefAndPose_KitDesign;
}
void PartRefAndPose::sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point){
this->hasPartRefAndPose_Point= _hasPartRefAndPose_Point;
}
void PartRefAndPose::sethasPartRefAndPose_XAxis(Vector* _hasPartRefAndPose_XAxis){
this->hasPartRefAndPose_XAxis= _hasPartRefAndPose_XAxis;
}
void PartRefAndPose::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("PartRefAndPose");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PartRefAndPose::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["hasPartRefAndPose_Ref"]=hasPartRefAndPose_Ref;
data["name"]=name;
ss.str("");
ss << PartRefAndPoseID;
data["PartRefAndPoseID"]=ss.str();
if(hasPartRefAndPose_ZAxis!=NULL)
data["hasPartRefAndPose_ZAxis"]=hasPartRefAndPose_ZAxis->getname();
if(hadByPartRefAndPose_KitDesign!=NULL)
data["hadByPartRefAndPose_KitDesign"]=hadByPartRefAndPose_KitDesign->getname();
if(hasPartRefAndPose_Point!=NULL)
data["hasPartRefAndPose_Point"]=hasPartRefAndPose_Point->getname();
if(hasPartRefAndPose_XAxis!=NULL)
data["hasPartRefAndPose_XAxis"]=hasPartRefAndPose_XAxis->getname();
dao  = new DAO("PartRefAndPose");
dao->set(data);
delete (dao);
}

void PartRefAndPose::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartRefAndPose*> tmp;
this->hasPartRefAndPose_Ref = object["PartRefAndPose.hasPartRefAndPose_Ref"];
this->name = object["PartRefAndPose._NAME"];
this->PartRefAndPoseID = std::atof(object["PartRefAndPose.PartRefAndPoseID"].c_str());
if(this->hasPartRefAndPose_ZAxis== NULL && object["hasPartRefAndPose_ZAxis/Vector._NAME"]!=""){
this->hasPartRefAndPose_ZAxis = new Vector(object["hasPartRefAndPose_ZAxis/Vector._NAME"]);
}
if(this->hadByPartRefAndPose_KitDesign== NULL && object["hadByPartRefAndPose_KitDesign/KitDesign._NAME"]!=""){
this->hadByPartRefAndPose_KitDesign = new KitDesign(object["hadByPartRefAndPose_KitDesign/KitDesign._NAME"]);
}
if(this->hasPartRefAndPose_Point== NULL && object["hasPartRefAndPose_Point/Point._NAME"]!=""){
this->hasPartRefAndPose_Point = new Point(object["hasPartRefAndPose_Point/Point._NAME"]);
}
if(this->hasPartRefAndPose_XAxis== NULL && object["hasPartRefAndPose_XAxis/Vector._NAME"]!=""){
this->hasPartRefAndPose_XAxis = new Vector(object["hasPartRefAndPose_XAxis/Vector._NAME"]);
}

}std::vector<std::string> PartRefAndPose::Explode(const std::string & str, char separator )
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
