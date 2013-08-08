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
hadByEndEffectorHolder_EndEffectorChangingStation = NULL;
hasEndEffectorHolder_EndEffector = NULL;

}EndEffectorHolder::~EndEffectorHolder(){
delete(hadByEndEffectorHolder_EndEffectorChangingStation);
delete(hasEndEffectorHolder_EndEffector);
}
int EndEffectorHolder::getEndEffectorHolderID(){
return EndEffectorHolderID;
}
DAO* EndEffectorHolder::getdao(){
return dao;
}
EndEffectorChangingStation* EndEffectorHolder::gethadByEndEffectorHolder_EndEffectorChangingStation(){
return hadByEndEffectorHolder_EndEffectorChangingStation;
}
EndEffector* EndEffectorHolder::gethasEndEffectorHolder_EndEffector(){
return hasEndEffectorHolder_EndEffector;
}
void EndEffectorHolder::setEndEffectorHolderID(int _EndEffectorHolderID){
this->EndEffectorHolderID= _EndEffectorHolderID;
}
void EndEffectorHolder::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorHolder::sethadByEndEffectorHolder_EndEffectorChangingStation(EndEffectorChangingStation* _hadByEndEffectorHolder_EndEffectorChangingStation){
this->hadByEndEffectorHolder_EndEffectorChangingStation= _hadByEndEffectorHolder_EndEffectorChangingStation;
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
data["name"]="'" + name + "'";
ss.str("");
ss << EndEffectorHolderID;
data["EndEffectorHolderID"]=ss.str();
if(hadByEndEffectorHolder_EndEffectorChangingStation!=NULL)
data["hadByEndEffectorHolder_EndEffectorChangingStation"]="'" +hadByEndEffectorHolder_EndEffectorChangingStation->getname() + "'";
else 
 data["hadByEndEffectorHolder_EndEffectorChangingStation"]="null";
if(hasEndEffectorHolder_EndEffector!=NULL)
data["hasEndEffectorHolder_EndEffector"]="'" +hasEndEffectorHolder_EndEffector->getname() + "'";
else 
 data["hasEndEffectorHolder_EndEffector"]="null";
dao  = new DAO("EndEffectorHolder");
dao->set(data);
delete (dao);
}
void EndEffectorHolder::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getSolidObjectID();
data["EndEffectorHolderID"]=ss.str();
if(hadByEndEffectorHolder_EndEffectorChangingStation!=NULL)
data["hadByEndEffectorHolder_EndEffectorChangingStation"]="'" + hadByEndEffectorHolder_EndEffectorChangingStation->getname() + "'";
if(hasEndEffectorHolder_EndEffector!=NULL)
data["hasEndEffectorHolder_EndEffector"]="'" + hasEndEffectorHolder_EndEffector->getname() + "'";
dao  = new DAO("EndEffectorHolder");
dao->insert(data);
delete (dao);
this->set(name);
}

void EndEffectorHolder::copy(std::map<std::string,std::string> object){delete(hadByEndEffectorHolder_EndEffectorChangingStation);
hadByEndEffectorHolder_EndEffectorChangingStation=NULL;
delete(hasEndEffectorHolder_EndEffector);
hasEndEffectorHolder_EndEffector=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffectorHolder*> tmp;
this->name = object["EndEffectorHolder._NAME"];
this->EndEffectorHolderID = std::atof(object["EndEffectorHolder.EndEffectorHolderID"].c_str());
if(this->hadByEndEffectorHolder_EndEffectorChangingStation== NULL && object["hadByEndEffectorHolder_EndEffectorChangingStation/EndEffectorChangingStation._NAME"]!=""){
this->hadByEndEffectorHolder_EndEffectorChangingStation = new EndEffectorChangingStation(object["hadByEndEffectorHolder_EndEffectorChangingStation/EndEffectorChangingStation._NAME"]);
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
