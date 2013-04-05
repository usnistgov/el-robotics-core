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

MechanicalComponent::MechanicalComponent(std::string name) : SolidObject(name){
dao = NULL;

}MechanicalComponent::~MechanicalComponent(){
for(std::size_t i = 0; i < hasChangingStation_Base.size(); i++)
delete(hasChangingStation_Base[i]);
}
int MechanicalComponent::getMechanicalComponentID(){
return MechanicalComponentID;
}
DAO* MechanicalComponent::getdao(){
return dao;
}
std::vector<EndEffectorChangingStation*> MechanicalComponent::gethasChangingStation_Base(){
return hasChangingStation_Base;
}
void MechanicalComponent::setdao(DAO* _dao){
this->dao= _dao;
}
void MechanicalComponent::sethasChangingStation_Base(std::vector<EndEffectorChangingStation*> _hasChangingStation_Base){
this->hasChangingStation_Base= _hasChangingStation_Base;
}
void MechanicalComponent::get(std::string name){
std::map<std::string,std::string> temp;
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
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]=name;
ss.str("");
ss << MechanicalComponentID;
data["MechanicalComponentID"]=ss.str();
for(unsigned int i=0;i<hasChangingStation_Base.size();++i){
ss.str("");
hasChangingStation_Base[i]->get(hasChangingStation_Base[i]->getname());
ss << hasChangingStation_Base[i]->getEndEffectorChangingStationID();
data["hasChangingStation_Base"]=data["hasChangingStation_Base"]+" "+ss.str();
}
dao  = new DAO("MechanicalComponent");
dao->set(data);
delete (dao);
}

void MechanicalComponent::copy(std::map<std::string,std::string> object){for(std::size_t i = 0; i < hasChangingStation_Base.size(); i++){
delete(hasChangingStation_Base[i]);
hasChangingStation_Base[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<MechanicalComponent*> tmp;
this->name = object["MechanicalComponent._NAME"];
this->MechanicalComponentID = std::atof(object["MechanicalComponent.MechanicalComponentID"].c_str());
if(this->hasChangingStation_Base.empty() && object["hasChangingStation_Base/EndEffectorChangingStation._NAME"]!=""){
temp = Explode(object["hasChangingStation_Base/EndEffectorChangingStation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasChangingStation_Base.push_back(new EndEffectorChangingStation(temp[i]));
}
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
