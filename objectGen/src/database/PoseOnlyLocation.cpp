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

#include "PoseOnlyLocation.h"


 #include "DAO.h"

PoseOnlyLocation::PoseOnlyLocation(std::string name) : PoseLocation(name){
dao = NULL;

}PoseOnlyLocation::~PoseOnlyLocation(){
delete(dao);
}
int PoseOnlyLocation::getPoseOnlyLocationID(){
return PoseOnlyLocationID;
}
DAO* PoseOnlyLocation::getdao(){
return dao;
}
void PoseOnlyLocation::setdao(DAO* _dao){
this->dao= _dao;
}
void PoseOnlyLocation::get(std::string name){
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
dao  = new DAO("PoseOnlyLocation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PoseOnlyLocation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
PoseLocation* temp0 = (PoseLocation*) this;
temp0->set(name);
PhysicalLocation* temp1 = (PhysicalLocation*) this;
temp1->set(name);
DataThing* temp2 = (DataThing*) this;
temp2->set(name);
data["name"]=name;
ss.str("");
ss << PoseOnlyLocationID;
data["PoseOnlyLocationID"]=ss.str();
dao  = new DAO("PoseOnlyLocation");
dao->set(data);
delete (dao);
}

void PoseOnlyLocation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PoseOnlyLocation*> tmp;
this->name = object["PoseOnlyLocation._NAME"];
this->PoseOnlyLocationID = std::atof(object["PoseOnlyLocation.PoseOnlyLocationID"].c_str());

}std::vector<std::string> PoseOnlyLocation::Explode(const std::string & str, char separator )
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
