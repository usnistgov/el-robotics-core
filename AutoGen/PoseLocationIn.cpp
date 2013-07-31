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

#include "PoseLocationIn.h"


 #include "DAO.h"

PoseLocationIn::PoseLocationIn(std::string name) : PoseLocation(name){
dao = NULL;

}PoseLocationIn::~PoseLocationIn(){
}
int PoseLocationIn::getPoseLocationInID(){
return PoseLocationInID;
}
DAO* PoseLocationIn::getdao(){
return dao;
}
void PoseLocationIn::setPoseLocationInID(int _PoseLocationInID){
this->PoseLocationInID= _PoseLocationInID;
}
void PoseLocationIn::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseLocationIn::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("PoseLocation");
 temp = dao->get(name);delete (dao);
 PoseLocation::copy(temp);
dao  = new DAO("PhysicalLocation");
 temp = dao->get(name);delete (dao);
 PhysicalLocation::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("PoseLocationIn");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PoseLocationIn::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
PoseLocation* temp0 = (PoseLocation*) this;
temp0->set(name);
PhysicalLocation* temp1 = (PhysicalLocation*) this;
temp1->set(name);
DataThing* temp2 = (DataThing*) this;
temp2->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << PoseLocationInID;
data["PoseLocationInID"]=ss.str();
dao  = new DAO("PoseLocationIn");
dao->set(data);
delete (dao);
}
void PoseLocationIn::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp2 = (DataThing*) this;
temp2->insert(name);
temp2->get(name);
PhysicalLocation* temp1 = (PhysicalLocation*) this;
temp1->setPhysicalLocationID(temp2->getDataThingID());
temp1->insert(name);
PoseLocation* temp0 = (PoseLocation*) this;
temp0->setPoseLocationID(temp2->getDataThingID());
temp0->insert(name);
ss.str("");
ss << temp2->getDataThingID();
data["PoseLocationInID"]=ss.str();
dao  = new DAO("PoseLocationIn");
dao->insert(data);
delete (dao);
this->set(name);
}

void PoseLocationIn::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseLocationIn*> tmp;
this->name = object["PoseLocationIn._NAME"];
this->PoseLocationInID = std::atof(object["PoseLocationIn.PoseLocationInID"].c_str());

}std::vector<std::string> PoseLocationIn::Explode(const std::string & str, char separator )
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
