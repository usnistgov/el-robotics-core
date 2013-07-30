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

#include "RelativeLocation.h"


 #include "DAO.h"

RelativeLocation::RelativeLocation(std::string name) : PhysicalLocation(name){
dao = NULL;

}RelativeLocation::~RelativeLocation(){
}
std::string RelativeLocation::gethasRelativeLocation_Description(){
return hasRelativeLocation_Description;
}
int RelativeLocation::getRelativeLocationID(){
return RelativeLocationID;
}
DAO* RelativeLocation::getdao(){
return dao;
}
void RelativeLocation::sethasRelativeLocation_Description(std::string _hasRelativeLocation_Description){
this->hasRelativeLocation_Description= _hasRelativeLocation_Description;
}
void RelativeLocation::setRelativeLocationID(int _RelativeLocationID){
this->RelativeLocationID= _RelativeLocationID;
}
void RelativeLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);delete (dao);
 PhysicalLocation::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("RelativeLocation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void RelativeLocation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
PhysicalLocation* temp0 = (PhysicalLocation*) this;
temp0->set(name);
DataThing* temp1 = (DataThing*) this;
temp1->set(name);
data["hasRelativeLocation_Description"]="'" + hasRelativeLocation_Description + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << RelativeLocationID;
data["RelativeLocationID"]=ss.str();
dao  = new DAO("RelativeLocation");
dao->set(data);
delete (dao);
}
void RelativeLocation::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp1 = (DataThing*) this;
temp1->insert(name);
temp1->get(name);
PhysicalLocation* temp0 = (PhysicalLocation*) this;
temp0->setPhysicalLocationID(temp1->getDataThingID());
temp0->insert(name);
data["hasRelativeLocation_Description"]="'" + hasRelativeLocation_Description+ "'";
ss.str("");
ss << temp1->getDataThingID();
data["RelativeLocationID"]=ss.str();
dao  = new DAO("RelativeLocation");
dao->insert(data);
delete (dao);
this->set(name);
}

void RelativeLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<RelativeLocation*> tmp;
this->hasRelativeLocation_Description = object["RelativeLocation.hasRelativeLocation_Description"];
this->name = object["RelativeLocation._NAME"];
this->RelativeLocationID = std::atof(object["RelativeLocation.RelativeLocationID"].c_str());

}std::vector<std::string> RelativeLocation::Explode(const std::string & str, char separator )
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
