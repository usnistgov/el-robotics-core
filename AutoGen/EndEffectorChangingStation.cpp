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

#include "EndEffectorChangingStation.h"


 #include "MechanicalComponent.h"
 #include "KittingWorkstation.h"
 #include "DAO.h"
 #include "EndEffectorHolder.h"

EndEffectorChangingStation::EndEffectorChangingStation(std::string name) : NoSkuObject(name){
dao = NULL;
hasEndEffectorChangingStation_Base = NULL;
hasKittingWorkstation_ChangingStation = NULL;

}EndEffectorChangingStation::~EndEffectorChangingStation(){
delete(hasEndEffectorChangingStation_Base);
delete(hasKittingWorkstation_ChangingStation);
for(std::size_t i = 0; i < hadByEndEffectorHolder_EndEffectorChangingStation.size(); i++)
delete(hadByEndEffectorHolder_EndEffectorChangingStation[i]);
}
int EndEffectorChangingStation::getEndEffectorChangingStationID(){
return EndEffectorChangingStationID;
}
DAO* EndEffectorChangingStation::getdao(){
return dao;
}
MechanicalComponent* EndEffectorChangingStation::gethasEndEffectorChangingStation_Base(){
return hasEndEffectorChangingStation_Base;
}
std::vector<EndEffectorHolder*> EndEffectorChangingStation::gethadByEndEffectorHolder_EndEffectorChangingStation(){
return hadByEndEffectorHolder_EndEffectorChangingStation;
}
KittingWorkstation* EndEffectorChangingStation::gethasKittingWorkstation_ChangingStation(){
return hasKittingWorkstation_ChangingStation;
}
void EndEffectorChangingStation::setEndEffectorChangingStationID(int _EndEffectorChangingStationID){
this->EndEffectorChangingStationID= _EndEffectorChangingStationID;
}
void EndEffectorChangingStation::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorChangingStation::sethasEndEffectorChangingStation_Base(MechanicalComponent* _hasEndEffectorChangingStation_Base){
this->hasEndEffectorChangingStation_Base= _hasEndEffectorChangingStation_Base;
}
void EndEffectorChangingStation::sethadByEndEffectorHolder_EndEffectorChangingStation(std::vector<EndEffectorHolder*> _hadByEndEffectorHolder_EndEffectorChangingStation){
this->hadByEndEffectorHolder_EndEffectorChangingStation= _hadByEndEffectorHolder_EndEffectorChangingStation;
}
void EndEffectorChangingStation::sethasKittingWorkstation_ChangingStation(KittingWorkstation* _hasKittingWorkstation_ChangingStation){
this->hasKittingWorkstation_ChangingStation= _hasKittingWorkstation_ChangingStation;
}
void EndEffectorChangingStation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("NoSkuObject");
 temp = dao->get(name);delete (dao);
 NoSkuObject::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("EndEffectorChangingStation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void EndEffectorChangingStation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
NoSkuObject* temp0 = (NoSkuObject*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << EndEffectorChangingStationID;
data["EndEffectorChangingStationID"]=ss.str();
if(hasEndEffectorChangingStation_Base!=NULL)
data["hasEndEffectorChangingStation_Base"]="'" +hasEndEffectorChangingStation_Base->getname() + "'";
else 
 data["hasEndEffectorChangingStation_Base"]="null";
for(unsigned int i=0;i<hadByEndEffectorHolder_EndEffectorChangingStation.size();++i){
ss.str("");
hadByEndEffectorHolder_EndEffectorChangingStation[i]->get(hadByEndEffectorHolder_EndEffectorChangingStation[i]->getname());
ss << hadByEndEffectorHolder_EndEffectorChangingStation[i]->getEndEffectorHolderID();
data["hadByEndEffectorHolder_EndEffectorChangingStation"]=data["hadByEndEffectorHolder_EndEffectorChangingStation"]+" "+ss.str();
}
if(hasKittingWorkstation_ChangingStation!=NULL)
data["hasKittingWorkstation_ChangingStation"]="'" +hasKittingWorkstation_ChangingStation->getname() + "'";
else 
 data["hasKittingWorkstation_ChangingStation"]="null";
dao  = new DAO("EndEffectorChangingStation");
dao->set(data);
delete (dao);
}
void EndEffectorChangingStation::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp1 = (SolidObject*) this;
temp1->insert(name);
temp1->get(name);
NoSkuObject* temp0 = (NoSkuObject*) this;
temp0->setNoSkuObjectID(temp1->getSolidObjectID());
temp0->insert(name);
ss.str("");
ss << temp1->getSolidObjectID();
data["EndEffectorChangingStationID"]=ss.str();
if(hasEndEffectorChangingStation_Base!=NULL)
data["hasEndEffectorChangingStation_Base"]="'" + hasEndEffectorChangingStation_Base->getname() + "'";
if(hasKittingWorkstation_ChangingStation!=NULL)
data["hasKittingWorkstation_ChangingStation"]="'" + hasKittingWorkstation_ChangingStation->getname() + "'";
dao  = new DAO("EndEffectorChangingStation");
dao->insert(data);
delete (dao);
this->set(name);
}

void EndEffectorChangingStation::copy(std::map<std::string,std::string> object){hasEndEffectorChangingStation_Base=NULL;
for(std::size_t i = 0; i < hadByEndEffectorHolder_EndEffectorChangingStation.size(); i++){
hadByEndEffectorHolder_EndEffectorChangingStation[i]=NULL;}
hadByEndEffectorHolder_EndEffectorChangingStation.clear();
hasKittingWorkstation_ChangingStation=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffectorChangingStation*> tmp;
this->name = object["EndEffectorChangingStation._NAME"];
this->EndEffectorChangingStationID = std::atof(object["EndEffectorChangingStation.EndEffectorChangingStationID"].c_str());
if(this->hasEndEffectorChangingStation_Base== NULL && object["hasEndEffectorChangingStation_Base/MechanicalComponent._NAME"]!=""){
this->hasEndEffectorChangingStation_Base = new MechanicalComponent(object["hasEndEffectorChangingStation_Base/MechanicalComponent._NAME"]);
}
if(this->hadByEndEffectorHolder_EndEffectorChangingStation.empty() && object["hadByEndEffectorHolder_EndEffectorChangingStation/EndEffectorHolder._NAME"]!=""){
temp = Explode(object["hadByEndEffectorHolder_EndEffectorChangingStation/EndEffectorHolder._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByEndEffectorHolder_EndEffectorChangingStation.push_back(new EndEffectorHolder(temp[i]));
}
}
if(this->hasKittingWorkstation_ChangingStation== NULL && object["hasKittingWorkstation_ChangingStation/KittingWorkstation._NAME"]!=""){
this->hasKittingWorkstation_ChangingStation = new KittingWorkstation(object["hasKittingWorkstation_ChangingStation/KittingWorkstation._NAME"]);
}

}std::vector<std::string> EndEffectorChangingStation::Explode(const std::string & str, char separator )
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
