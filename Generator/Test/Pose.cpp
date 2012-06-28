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

#include "Pose.h"


 #include "DAO.h"
 #include "Point.h"
 #include "RollPitchYaw.h"

Pose::Pose(std::string name) : PhysicalLocation(name){
this->name=name;dao = NULL;
hasPose_Point = NULL;
hasPose_Rpy = NULL;

}Pose::~Pose(){
delete(dao);
delete(hasPose_Point);
delete(hasPose_Rpy);
}
std::string Pose::getname(){
return name;
}
int Pose::getPoseID(){
return PoseID;
}
DAO* Pose::getdao(){
return dao;
}
Point* Pose::gethasPose_Point(){
return hasPose_Point;
}
RollPitchYaw* Pose::gethasPose_Rpy(){
return hasPose_Rpy;
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
 temp = dao->get(name);delete (dao);
 PhysicalLocation::copy(temp);
dao  = new DAO("Pose");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Pose::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
PhysicalLocation* temp = (PhysicalLocation*) this;
temp->set(name);
data["name"]=name;
ss.str("");
ss << PoseID;
data["PoseID"]=ss.str();
if(hasPose_Point!=NULL)
data["hasPose_Point"]=hasPose_Point->getname();
if(hasPose_Rpy!=NULL)
data["hasPose_Rpy"]=hasPose_Rpy->getname();
dao  = new DAO("Pose");
dao->set(data);
delete (dao);
}

void Pose::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Pose*> tmp;
this->name = object["Pose._NAME"];
this->PoseID = std::atof(object["Pose.PoseID"].c_str());
if(this->hasPose_Point== NULL && object["hasPose_Point/Point._NAME"]!=""){
this->hasPose_Point = new Point(object["hasPose_Point/Point._NAME"]);
}
if(this->hasPose_Rpy== NULL && object["hasPose_Rpy/RollPitchYaw._NAME"]!=""){
this->hasPose_Rpy = new RollPitchYaw(object["hasPose_Rpy/RollPitchYaw._NAME"]);
}

}std::vector<std::string> Pose::Explode(const std::string & str, char separator )
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
