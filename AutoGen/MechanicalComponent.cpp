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

#include "MechanicalComponent.h"


 #include "EndEffectorChangingStation.h"
 #include "DAO.h"

MechanicalComponent::MechanicalComponent(std::string name) : NoSkuObject(name){
dao = NULL;
hasEndEffectorChangingStation_Base = NULL;

}MechanicalComponent::~MechanicalComponent(){
delete(hasEndEffectorChangingStation_Base);
}
int MechanicalComponent::getMechanicalComponentID(){
return MechanicalComponentID;
}
DAO* MechanicalComponent::getdao(){
return dao;
}
EndEffectorChangingStation* MechanicalComponent::gethasEndEffectorChangingStation_Base(){
return hasEndEffectorChangingStation_Base;
}
void MechanicalComponent::setMechanicalComponentID(int _MechanicalComponentID){
this->MechanicalComponentID= _MechanicalComponentID;
}
void MechanicalComponent::setdao(DAO* _dao){
this->dao= _dao;
}
void MechanicalComponent::sethasEndEffectorChangingStation_Base(EndEffectorChangingStation* _hasEndEffectorChangingStation_Base){
this->hasEndEffectorChangingStation_Base= _hasEndEffectorChangingStation_Base;
}
void MechanicalComponent::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("NoSkuObject");
 temp = dao->get(name);delete (dao);
 NoSkuObject::copy(temp);
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("MechanicalComponent");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void MechanicalComponent::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
NoSkuObject* temp0 = (NoSkuObject*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << MechanicalComponentID;
data["MechanicalComponentID"]=ss.str();
if(hasEndEffectorChangingStation_Base!=NULL)
data["hasEndEffectorChangingStation_Base"]="'" +hasEndEffectorChangingStation_Base->getname() + "'";
else 
 data["hasEndEffectorChangingStation_Base"]="null";
dao  = new DAO("MechanicalComponent");
dao->set(data);
delete (dao);
}
void MechanicalComponent::insert(std::string name){
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
data["MechanicalComponentID"]=ss.str();
if(hasEndEffectorChangingStation_Base!=NULL)
data["hasEndEffectorChangingStation_Base"]="'" + hasEndEffectorChangingStation_Base->getname() + "'";
dao  = new DAO("MechanicalComponent");
dao->insert(data);
delete (dao);
this->set(name);
}

void MechanicalComponent::copy(std::map<std::string,std::string> object){hasEndEffectorChangingStation_Base=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<MechanicalComponent*> tmp;
this->name = object["MechanicalComponent._NAME"];
this->MechanicalComponentID = std::atof(object["MechanicalComponent.MechanicalComponentID"].c_str());
if(this->hasEndEffectorChangingStation_Base== NULL && object["hasEndEffectorChangingStation_Base/EndEffectorChangingStation._NAME"]!=""){
this->hasEndEffectorChangingStation_Base = new EndEffectorChangingStation(object["hasEndEffectorChangingStation_Base/EndEffectorChangingStation._NAME"]);
}

}std::vector<std::string> MechanicalComponent::Explode(const std::string & str, char separator )
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
