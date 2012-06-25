#include "PartRefAndPose.h"


 #include "DAO.h"
 #include "KitDesign.h"
 #include "Point.h"
 #include "RollPitchYaw.h"

PartRefAndPose::PartRefAndPose(std::string name) : DataThing(name){
this->name=name;dao = NULL;
hadByPartRefAndPose_KitDesign = NULL;
hasPartRefAndPose_Rpy = NULL;
hasPartRefAndPose_Point = NULL;

}PartRefAndPose::~PartRefAndPose(){
delete(dao);
delete(hadByPartRefAndPose_KitDesign);
delete(hasPartRefAndPose_Rpy);
delete(hasPartRefAndPose_Point);
}
std::string PartRefAndPose::gethasPartRefAndPose_Ref(){
return hasPartRefAndPose_Ref;
}
std::string PartRefAndPose::getname(){
return name;
}
int PartRefAndPose::getPartRefAndPoseID(){
return PartRefAndPoseID;
}
DAO* PartRefAndPose::getdao(){
return dao;
}
KitDesign* PartRefAndPose::gethadByPartRefAndPose_KitDesign(){
return hadByPartRefAndPose_KitDesign;
}
RollPitchYaw* PartRefAndPose::gethasPartRefAndPose_Rpy(){
return hasPartRefAndPose_Rpy;
}
Point* PartRefAndPose::gethasPartRefAndPose_Point(){
return hasPartRefAndPose_Point;
}
void PartRefAndPose::sethasPartRefAndPose_Ref(std::string _hasPartRefAndPose_Ref){
this->hasPartRefAndPose_Ref= _hasPartRefAndPose_Ref;
}
void PartRefAndPose::setdao(DAO* _dao){
this->dao= _dao;
}
void PartRefAndPose::sethadByPartRefAndPose_KitDesign(KitDesign* _hadByPartRefAndPose_KitDesign){
this->hadByPartRefAndPose_KitDesign= _hadByPartRefAndPose_KitDesign;
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
data["hasPartRefAndPose_Ref"]=hasPartRefAndPose_Ref;
data["name"]=name;
data["PartRefAndPoseID"]=PartRefAndPoseID;
data["hadByPartRefAndPose_KitDesign"]=hadByPartRefAndPose_KitDesign->getname();
data["hasPartRefAndPose_Rpy"]=hasPartRefAndPose_Rpy->getname();
data["hasPartRefAndPose_Point"]=hasPartRefAndPose_Point->getname();
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
if(this->hadByPartRefAndPose_KitDesign== NULL && object["hadByPartRefAndPose_KitDesign/KitDesign._NAME"]!=""){
this->hadByPartRefAndPose_KitDesign = new KitDesign(object["hadByPartRefAndPose_KitDesign/KitDesign._NAME"]);
}
if(this->hasPartRefAndPose_Rpy== NULL && object["hasPartRefAndPose_Rpy/RollPitchYaw._NAME"]!=""){
this->hasPartRefAndPose_Rpy = new RollPitchYaw(object["hasPartRefAndPose_Rpy/RollPitchYaw._NAME"]);
}
if(this->hasPartRefAndPose_Point== NULL && object["hasPartRefAndPose_Point/Point._NAME"]!=""){
this->hasPartRefAndPose_Point = new Point(object["hasPartRefAndPose_Point/Point._NAME"]);
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
