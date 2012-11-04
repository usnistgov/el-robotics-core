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

#include "EndEffectorHolder.h"


 #include "EndEffector.h"
 #include "EndEffectorChangingStation.h"
 #include "DAO.h"

EndEffectorHolder::EndEffectorHolder(std::string name) : SolidObject(name){
dao = NULL;
hadByEndEffectorHolder_ChangingStation = NULL;
hasEndEffectorHolder_EndEffector = NULL;

}EndEffectorHolder::~EndEffectorHolder(){
delete(dao);
delete(hadByEndEffectorHolder_ChangingStation);
delete(hasEndEffectorHolder_EndEffector);
}
int EndEffectorHolder::getEndEffectorHolderID(){
return EndEffectorHolderID;
}
DAO* EndEffectorHolder::getdao(){
return dao;
}
EndEffectorChangingStation* EndEffectorHolder::gethadByEndEffectorHolder_ChangingStation(){
return hadByEndEffectorHolder_ChangingStation;
}
EndEffector* EndEffectorHolder::gethasEndEffectorHolder_EndEffector(){
return hasEndEffectorHolder_EndEffector;
}
void EndEffectorHolder::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorHolder::sethadByEndEffectorHolder_ChangingStation(EndEffectorChangingStation* _hadByEndEffectorHolder_ChangingStation){
this->hadByEndEffectorHolder_ChangingStation= _hadByEndEffectorHolder_ChangingStation;
}
void EndEffectorHolder::sethasEndEffectorHolder_EndEffector(EndEffector* _hasEndEffectorHolder_EndEffector){
this->hasEndEffectorHolder_EndEffector= _hasEndEffectorHolder_EndEffector;
}
void EndEffectorHolder::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("EndEffectorHolder");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void EndEffectorHolder::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]=name;
ss.str("");
ss << EndEffectorHolderID;
data["EndEffectorHolderID"]=ss.str();
if(hadByEndEffectorHolder_ChangingStation!=NULL)
data["hadByEndEffectorHolder_ChangingStation"]=hadByEndEffectorHolder_ChangingStation->getname();
if(hasEndEffectorHolder_EndEffector!=NULL)
data["hasEndEffectorHolder_EndEffector"]=hasEndEffectorHolder_EndEffector->getname();
dao  = new DAO("EndEffectorHolder");
dao->set(data);
delete (dao);
}

void EndEffectorHolder::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffectorHolder*> tmp;
this->name = object["EndEffectorHolder._NAME"];
this->EndEffectorHolderID = std::atof(object["EndEffectorHolder.EndEffectorHolderID"].c_str());
if(this->hadByEndEffectorHolder_ChangingStation== NULL && object["hadByEndEffectorHolder_ChangingStation/EndEffectorChangingStation._NAME"]!=""){
this->hadByEndEffectorHolder_ChangingStation = new EndEffectorChangingStation(object["hadByEndEffectorHolder_ChangingStation/EndEffectorChangingStation._NAME"]);
}
if(this->hasEndEffectorHolder_EndEffector== NULL && object["hasEndEffectorHolder_EndEffector/EndEffector._NAME"]!=""){
this->hasEndEffectorHolder_EndEffector = new EndEffector(object["hasEndEffectorHolder_EndEffector/EndEffector._NAME"]);
}

}std::vector<std::string> EndEffectorHolder::Explode(const std::string & str, char separator )
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
