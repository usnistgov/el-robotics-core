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

#include "RelativeLocationOn.h"


 #include "DAO.h"

RelativeLocationOn::RelativeLocationOn(std::string name) : RelativeLocation(name){
dao = NULL;

}RelativeLocationOn::~RelativeLocationOn(){
}
int RelativeLocationOn::getRelativeLocationOnID(){
return RelativeLocationOnID;
}
DAO* RelativeLocationOn::getdao(){
return dao;
}
void RelativeLocationOn::setRelativeLocationOnID(int _RelativeLocationOnID){
this->RelativeLocationOnID= _RelativeLocationOnID;
}
void RelativeLocationOn::setdao(DAO* _dao){
this->dao= _dao;
}
void RelativeLocationOn::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("RelativeLocation");
 temp = dao->get(name);delete (dao);
 RelativeLocation::copy(temp);
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);delete (dao);
 PhysicalLocation::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("RelativeLocationOn");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void RelativeLocationOn::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
RelativeLocation* temp0 = (RelativeLocation*) this;
temp0->set(name);
PhysicalLocation* temp1 = (PhysicalLocation*) this;
temp1->set(name);
DataThing* temp2 = (DataThing*) this;
temp2->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << RelativeLocationOnID;
data["RelativeLocationOnID"]=ss.str();
dao  = new DAO("RelativeLocationOn");
dao->set(data);
delete (dao);
}
void RelativeLocationOn::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp2 = (DataThing*) this;
temp2->insert(name);
temp2->get(name);
PhysicalLocation* temp1 = (PhysicalLocation*) this;
temp1->setPhysicalLocationID(temp2->getDataThingID());
temp1->insert(name);
RelativeLocation* temp0 = (RelativeLocation*) this;
temp0->setRelativeLocationID(temp2->getDataThingID());
temp0->insert(name);
ss.str("");
ss << temp2->getDataThingID();
data["RelativeLocationOnID"]=ss.str();
dao  = new DAO("RelativeLocationOn");
dao->insert(data);
delete (dao);
this->set(name);
}

void RelativeLocationOn::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<RelativeLocationOn*> tmp;
this->name = object["RelativeLocationOn._NAME"];
this->RelativeLocationOnID = std::atof(object["RelativeLocationOn.RelativeLocationOnID"].c_str());

}std::vector<std::string> RelativeLocationOn::Explode(const std::string & str, char separator )
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
