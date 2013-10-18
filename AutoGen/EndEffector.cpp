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

EndEffector::EndEffector(std::string name) : NoSkuObject(name){
dao = NULL;
hasEndEffector_HeldObject = NULL;
hadByEndEffector_Robot = NULL;
hasEndEffectorHolder_EndEffector = NULL;

}EndEffector::~EndEffector(){
delete(hasEndEffector_HeldObject);
delete(hadByEndEffector_Robot);
delete(hasEndEffectorHolder_EndEffector);
for(std::size_t i = 0; i < hasStockKeepingUnit_EndEffector.size(); i++)
delete(hasStockKeepingUnit_EndEffector[i]);
}
std::string EndEffector::gethasEndEffector_Description(){
return hasEndEffector_Description;
}
double EndEffector::gethasEndEffector_Weight(){
return hasEndEffector_Weight;
}
double EndEffector::gethasEndEffector_MaximumLoadWeight(){
return hasEndEffector_MaximumLoadWeight;
}
int EndEffector::getEndEffectorID(){
return EndEffectorID;
}
DAO* EndEffector::getdao(){
return dao;
}
SolidObject* EndEffector::gethasEndEffector_HeldObject(){
return hasEndEffector_HeldObject;
}
Robot* EndEffector::gethadByEndEffector_Robot(){
return hadByEndEffector_Robot;
}
EndEffectorHolder* EndEffector::gethasEndEffectorHolder_EndEffector(){
return hasEndEffectorHolder_EndEffector;
}
std::vector<StockKeepingUnit*> EndEffector::gethasStockKeepingUnit_EndEffector(){
return hasStockKeepingUnit_EndEffector;
}
void EndEffector::sethasEndEffector_Description(std::string _hasEndEffector_Description){
this->hasEndEffector_Description= _hasEndEffector_Description;
}
void EndEffector::sethasEndEffector_Weight(double _hasEndEffector_Weight){
this->hasEndEffector_Weight= _hasEndEffector_Weight;
}
void EndEffector::sethasEndEffector_MaximumLoadWeight(double _hasEndEffector_MaximumLoadWeight){
this->hasEndEffector_MaximumLoadWeight= _hasEndEffector_MaximumLoadWeight;
}
void EndEffector::setEndEffectorID(int _EndEffectorID){
this->EndEffectorID= _EndEffectorID;
}
void EndEffector::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffector::sethasEndEffector_HeldObject(SolidObject* _hasEndEffector_HeldObject){
this->hasEndEffector_HeldObject= _hasEndEffector_HeldObject;
}
void EndEffector::sethadByEndEffector_Robot(Robot* _hadByEndEffector_Robot){
this->hadByEndEffector_Robot= _hadByEndEffector_Robot;
}
void EndEffector::sethasEndEffectorHolder_EndEffector(EndEffectorHolder* _hasEndEffectorHolder_EndEffector){
this->hasEndEffectorHolder_EndEffector= _hasEndEffectorHolder_EndEffector;
}
void EndEffector::sethasStockKeepingUnit_EndEffector(std::vector<StockKeepingUnit*> _hasStockKeepingUnit_EndEffector){
this->hasStockKeepingUnit_EndEffector= _hasStockKeepingUnit_EndEffector;
}
void EndEffector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("NoSkuObject");
 temp = dao->get(name);delete (dao);
 NoSkuObject::copy(temp);
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
NoSkuObject* temp0 = (NoSkuObject*) this;
temp0->set(name);
SolidObject* temp1 = (SolidObject*) this;
temp1->set(name);
data["hasEndEffector_Description"]="'" + hasEndEffector_Description + "'";
ss.str("");
ss << hasEndEffector_Weight;
data["hasEndEffector_Weight"]=ss.str();
ss.str("");
ss << hasEndEffector_MaximumLoadWeight;
data["hasEndEffector_MaximumLoadWeight"]=ss.str();
data["name"]="'" + name + "'";
ss.str("");
ss << EndEffectorID;
data["EndEffectorID"]=ss.str();
if(hasEndEffector_HeldObject!=NULL)
data["hasEndEffector_HeldObject"]="'" +hasEndEffector_HeldObject->getname() + "'";
else 
 data["hasEndEffector_HeldObject"]="null";
if(hadByEndEffector_Robot!=NULL)
data["hadByEndEffector_Robot"]="'" +hadByEndEffector_Robot->getname() + "'";
else 
 data["hadByEndEffector_Robot"]="null";
if(hasEndEffectorHolder_EndEffector!=NULL)
data["hasEndEffectorHolder_EndEffector"]="'" +hasEndEffectorHolder_EndEffector->getname() + "'";
else 
 data["hasEndEffectorHolder_EndEffector"]="null";
for(unsigned int i=0;i<hasStockKeepingUnit_EndEffector.size();++i){
ss.str("");
hasStockKeepingUnit_EndEffector[i]->get(hasStockKeepingUnit_EndEffector[i]->getname());
ss << hasStockKeepingUnit_EndEffector[i]->getStockKeepingUnitID();
data["hasStockKeepingUnit_EndEffector"]=data["hasStockKeepingUnit_EndEffector"]+" "+ss.str();
}
dao  = new DAO("EndEffector");
dao->set(data);
delete (dao);
}
void EndEffector::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp1 = (SolidObject*) this;
temp1->insert(name);
temp1->get(name);
NoSkuObject* temp0 = (NoSkuObject*) this;
temp0->setNoSkuObjectID(temp1->getSolidObjectID());
temp0->insert(name);
data["hasEndEffector_Description"]="'" + hasEndEffector_Description+ "'";
ss.str("");
ss << hasEndEffector_Weight;
data["hasEndEffector_Weight"]=ss.str();
ss.str("");
ss << hasEndEffector_MaximumLoadWeight;
data["hasEndEffector_MaximumLoadWeight"]=ss.str();
ss.str("");
ss << temp1->getSolidObjectID();
data["EndEffectorID"]=ss.str();
if(hasEndEffector_HeldObject!=NULL)
data["hasEndEffector_HeldObject"]="'" + hasEndEffector_HeldObject->getname() + "'";
if(hadByEndEffector_Robot!=NULL)
data["hadByEndEffector_Robot"]="'" + hadByEndEffector_Robot->getname() + "'";
if(hasEndEffectorHolder_EndEffector!=NULL)
data["hasEndEffectorHolder_EndEffector"]="'" + hasEndEffectorHolder_EndEffector->getname() + "'";
dao  = new DAO("EndEffector");
dao->insert(data);
delete (dao);
this->set(name);
}

void EndEffector::copy(std::map<std::string,std::string> object){hasEndEffector_HeldObject=NULL;
hadByEndEffector_Robot=NULL;
hasEndEffectorHolder_EndEffector=NULL;
for(std::size_t i = 0; i < hasStockKeepingUnit_EndEffector.size(); i++){
hasStockKeepingUnit_EndEffector[i]=NULL;}
hasStockKeepingUnit_EndEffector.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffector*> tmp;
this->hasEndEffector_Description = object["EndEffector.hasEndEffector_Description"];
this->hasEndEffector_Weight = std::atof(object["EndEffector.hasEndEffector_Weight"].c_str());
this->hasEndEffector_MaximumLoadWeight = std::atof(object["EndEffector.hasEndEffector_MaximumLoadWeight"].c_str());
this->name = object["EndEffector._NAME"];
this->EndEffectorID = std::atof(object["EndEffector.EndEffectorID"].c_str());
if(this->hasEndEffector_HeldObject== NULL && object["hasEndEffector_HeldObject/SolidObject._NAME"]!=""){
this->hasEndEffector_HeldObject = new SolidObject(object["hasEndEffector_HeldObject/SolidObject._NAME"]);
}
if(this->hadByEndEffector_Robot== NULL && object["hadByEndEffector_Robot/Robot._NAME"]!=""){
this->hadByEndEffector_Robot = new Robot(object["hadByEndEffector_Robot/Robot._NAME"]);
}
if(this->hasEndEffectorHolder_EndEffector== NULL && object["hasEndEffectorHolder_EndEffector/EndEffectorHolder._NAME"]!=""){
this->hasEndEffectorHolder_EndEffector = new EndEffectorHolder(object["hasEndEffectorHolder_EndEffector/EndEffectorHolder._NAME"]);
}
if(this->hasStockKeepingUnit_EndEffector.empty() && object["hasStockKeepingUnit_EndEffector/StockKeepingUnit._NAME"]!=""){
temp = Explode(object["hasStockKeepingUnit_EndEffector/StockKeepingUnit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasStockKeepingUnit_EndEffector.push_back(new StockKeepingUnit(temp[i]));
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
