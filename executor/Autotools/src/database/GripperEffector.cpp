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

#include "GripperEffector.h"


 #include "DAO.h"

GripperEffector::GripperEffector(std::string name) : EndEffector(name){
dao = NULL;

}GripperEffector::~GripperEffector(){
delete(dao);
}
int GripperEffector::getGripperEffectorID(){
return GripperEffectorID;
}
DAO* GripperEffector::getdao(){
return dao;
}
void GripperEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void GripperEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("EndEffector");
 temp = dao->get(name);delete (dao);
 EndEffector::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("GripperEffector");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void GripperEffector::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
EndEffector* temp0 = (EndEffector*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["name"]=name;
ss.str("");
ss << GripperEffectorID;
data["GripperEffectorID"]=ss.str();
dao  = new DAO("GripperEffector");
dao->set(data);
delete (dao);
}

void GripperEffector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<GripperEffector*> tmp;
this->name = object["GripperEffector._NAME"];
this->GripperEffectorID = std::atof(object["GripperEffector.GripperEffectorID"].c_str());

}std::vector<std::string> GripperEffector::Explode(const std::string & str, char separator )
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
