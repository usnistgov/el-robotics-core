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

#include "EndEffector.h"


 #include "Robot.h"
 #include "StockKeepingUnit.h"
 #include "DAO.h"
 #include "SolidObject.h"
 #include "EndEffectorHolder.h"

EndEffector::EndEffector(std::string name) : SolidObject(name){
dao = NULL;
hadByEndEffector_Robot = NULL;
hasEndEffector_HeldObject = NULL;
hasEndEffectorHolder_EndEffector = NULL;

}EndEffector::~EndEffector(){
delete(hadByEndEffector_Robot);
delete(hasEndEffector_HeldObject);
delete(hasEndEffectorHolder_EndEffector);
for(std::size_t i = 0; i < hasSku_EndEffectors.size(); i++)
delete(hasSku_EndEffectors[i]);
}
std::string EndEffector::gethasEndEffector_Description(){
return hasEndEffector_Description;
}
double EndEffector::gethasEndEffector_Weight(){
return hasEndEffector_Weight;
}
double EndEffector::gethasEffector_MaximumLoadWeight(){
return hasEffector_MaximumLoadWeight;
}
int EndEffector::getEndEffectorID(){
return EndEffectorID;
}
DAO* EndEffector::getdao(){
return dao;
}
Robot* EndEffector::gethadByEndEffector_Robot(){
return hadByEndEffector_Robot;
}
SolidObject* EndEffector::gethasEndEffector_HeldObject(){
return hasEndEffector_HeldObject;
}
EndEffectorHolder* EndEffector::gethasEndEffectorHolder_EndEffector(){
return hasEndEffectorHolder_EndEffector;
}
std::vector<StockKeepingUnit*> EndEffector::gethasSku_EndEffectors(){
return hasSku_EndEffectors;
}
void EndEffector::sethasEndEffector_Description(std::string _hasEndEffector_Description){
this->hasEndEffector_Description= _hasEndEffector_Description;
}
void EndEffector::sethasEndEffector_Weight(double _hasEndEffector_Weight){
this->hasEndEffector_Weight= _hasEndEffector_Weight;
}
void EndEffector::sethasEffector_MaximumLoadWeight(double _hasEffector_MaximumLoadWeight){
this->hasEffector_MaximumLoadWeight= _hasEffector_MaximumLoadWeight;
}
void EndEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffector::sethadByEndEffector_Robot(Robot* _hadByEndEffector_Robot){
this->hadByEndEffector_Robot= _hadByEndEffector_Robot;
}
void EndEffector::sethasEndEffector_HeldObject(SolidObject* _hasEndEffector_HeldObject){
this->hasEndEffector_HeldObject= _hasEndEffector_HeldObject;
}
void EndEffector::sethasEndEffectorHolder_EndEffector(EndEffectorHolder* _hasEndEffectorHolder_EndEffector){
this->hasEndEffectorHolder_EndEffector= _hasEndEffectorHolder_EndEffector;
}
void EndEffector::sethasSku_EndEffectors(std::vector<StockKeepingUnit*> _hasSku_EndEffectors){
this->hasSku_EndEffectors= _hasSku_EndEffectors;
}
void EndEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("EndEffector");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void EndEffector::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasEndEffector_Description"]=hasEndEffector_Description;
ss.str("");
ss << hasEndEffector_Weight;
data["hasEndEffector_Weight"]=ss.str();
ss.str("");
ss << hasEffector_MaximumLoadWeight;
data["hasEffector_MaximumLoadWeight"]=ss.str();
data["name"]=name;
ss.str("");
ss << EndEffectorID;
data["EndEffectorID"]=ss.str();
if(hadByEndEffector_Robot!=NULL)
data["hadByEndEffector_Robot"]=hadByEndEffector_Robot->getname();
if(hasEndEffector_HeldObject!=NULL)
data["hasEndEffector_HeldObject"]=hasEndEffector_HeldObject->getname();
if(hasEndEffectorHolder_EndEffector!=NULL)
data["hasEndEffectorHolder_EndEffector"]=hasEndEffectorHolder_EndEffector->getname();
for(unsigned int i=0;i<hasSku_EndEffectors.size();++i){
ss.str("");
hasSku_EndEffectors[i]->get(hasSku_EndEffectors[i]->getname());
ss << hasSku_EndEffectors[i]->getStockKeepingUnitID();
data["hasSku_EndEffectors"]=data["hasSku_EndEffectors"]+" "+ss.str();
}
dao  = new DAO("EndEffector");
dao->set(data);
delete (dao);
}

void EndEffector::copy(std::map<std::string,std::string> object){delete(hadByEndEffector_Robot);
hadByEndEffector_Robot=NULL;
delete(hasEndEffector_HeldObject);
hasEndEffector_HeldObject=NULL;
delete(hasEndEffectorHolder_EndEffector);
hasEndEffectorHolder_EndEffector=NULL;
for(std::size_t i = 0; i < hasSku_EndEffectors.size(); i++){
delete(hasSku_EndEffectors[i]);
hasSku_EndEffectors[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffector*> tmp;
this->hasEndEffector_Description = object["EndEffector.hasEndEffector_Description"];
this->hasEndEffector_Weight = std::atof(object["EndEffector.hasEndEffector_Weight"].c_str());
this->hasEffector_MaximumLoadWeight = std::atof(object["EndEffector.hasEffector_MaximumLoadWeight"].c_str());
this->name = object["EndEffector._NAME"];
this->EndEffectorID = std::atof(object["EndEffector.EndEffectorID"].c_str());
if(this->hadByEndEffector_Robot== NULL && object["hadByEndEffector_Robot/Robot._NAME"]!=""){
this->hadByEndEffector_Robot = new Robot(object["hadByEndEffector_Robot/Robot._NAME"]);
}
if(this->hasEndEffector_HeldObject== NULL && object["hasEndEffector_HeldObject/SolidObject._NAME"]!=""){
this->hasEndEffector_HeldObject = new SolidObject(object["hasEndEffector_HeldObject/SolidObject._NAME"]);
}
if(this->hasEndEffectorHolder_EndEffector== NULL && object["hasEndEffectorHolder_EndEffector/EndEffectorHolder._NAME"]!=""){
this->hasEndEffectorHolder_EndEffector = new EndEffectorHolder(object["hasEndEffectorHolder_EndEffector/EndEffectorHolder._NAME"]);
}
if(this->hasSku_EndEffectors.empty() && object["hasSku_EndEffectors/StockKeepingUnit._NAME"]!=""){
temp = Explode(object["hasSku_EndEffectors/StockKeepingUnit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSku_EndEffectors.push_back(new StockKeepingUnit(temp[i]));
}
}

}std::vector<std::string> EndEffector::Explode(const std::string & str, char separator )
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
