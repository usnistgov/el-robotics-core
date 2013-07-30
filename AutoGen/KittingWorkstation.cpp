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

#include "KittingWorkstation.h"


 #include "Robot.h"
 #include "BoxVolume.h"
 #include "SolidObject.h"
 #include "KitDesign.h"
 #include "StockKeepingUnit.h"
 #include "EndEffectorChangingStation.h"
 #include "DAO.h"

KittingWorkstation::KittingWorkstation(std::string name) : SolidObject(name){
dao = NULL;
hasKittingWorkstation_ChangingStation = NULL;
hasKittingWorkstation_Robot = NULL;

}KittingWorkstation::~KittingWorkstation(){
delete(hasKittingWorkstation_ChangingStation);
delete(hasKittingWorkstation_Robot);
for(std::size_t i = 0; i < hadBySku_KittingWorkstation.size(); i++)
delete(hadBySku_KittingWorkstation[i]);
for(std::size_t i = 0; i < hadByKitDesign_KittingWorkstation.size(); i++)
delete(hadByKitDesign_KittingWorkstation[i]);
for(std::size_t i = 0; i < hadByOtherObstacle_KittingWorkstation.size(); i++)
delete(hadByOtherObstacle_KittingWorkstation[i]);
for(std::size_t i = 0; i < hadByObject_KittingWorkstation.size(); i++)
delete(hadByObject_KittingWorkstation[i]);
}
std::string KittingWorkstation::gethasKittingWorkstation_LengthUnit(){
return hasKittingWorkstation_LengthUnit;
}
std::string KittingWorkstation::gethasKittingWorkstation_WeightUnit(){
return hasKittingWorkstation_WeightUnit;
}
std::string KittingWorkstation::gethasKittingWorkstation_AngleUnit(){
return hasKittingWorkstation_AngleUnit;
}
int KittingWorkstation::getKittingWorkstationID(){
return KittingWorkstationID;
}
DAO* KittingWorkstation::getdao(){
return dao;
}
std::vector<StockKeepingUnit*> KittingWorkstation::gethadBySku_KittingWorkstation(){
return hadBySku_KittingWorkstation;
}
std::vector<KitDesign*> KittingWorkstation::gethadByKitDesign_KittingWorkstation(){
return hadByKitDesign_KittingWorkstation;
}
std::vector<BoxVolume*> KittingWorkstation::gethadByOtherObstacle_KittingWorkstation(){
return hadByOtherObstacle_KittingWorkstation;
}
EndEffectorChangingStation* KittingWorkstation::gethasKittingWorkstation_ChangingStation(){
return hasKittingWorkstation_ChangingStation;
}
Robot* KittingWorkstation::gethasKittingWorkstation_Robot(){
return hasKittingWorkstation_Robot;
}
std::vector<SolidObject*> KittingWorkstation::gethadByObject_KittingWorkstation(){
return hadByObject_KittingWorkstation;
}
void KittingWorkstation::sethasKittingWorkstation_LengthUnit(std::string _hasKittingWorkstation_LengthUnit){
this->hasKittingWorkstation_LengthUnit= _hasKittingWorkstation_LengthUnit;
}
void KittingWorkstation::sethasKittingWorkstation_WeightUnit(std::string _hasKittingWorkstation_WeightUnit){
this->hasKittingWorkstation_WeightUnit= _hasKittingWorkstation_WeightUnit;
}
void KittingWorkstation::sethasKittingWorkstation_AngleUnit(std::string _hasKittingWorkstation_AngleUnit){
this->hasKittingWorkstation_AngleUnit= _hasKittingWorkstation_AngleUnit;
}
void KittingWorkstation::setKittingWorkstationID(int _KittingWorkstationID){
this->KittingWorkstationID= _KittingWorkstationID;
}
void KittingWorkstation::setdao(DAO* _dao){
this->dao= _dao;
}
void KittingWorkstation::sethadBySku_KittingWorkstation(std::vector<StockKeepingUnit*> _hadBySku_KittingWorkstation){
this->hadBySku_KittingWorkstation= _hadBySku_KittingWorkstation;
}
void KittingWorkstation::sethadByKitDesign_KittingWorkstation(std::vector<KitDesign*> _hadByKitDesign_KittingWorkstation){
this->hadByKitDesign_KittingWorkstation= _hadByKitDesign_KittingWorkstation;
}
void KittingWorkstation::sethadByOtherObstacle_KittingWorkstation(std::vector<BoxVolume*> _hadByOtherObstacle_KittingWorkstation){
this->hadByOtherObstacle_KittingWorkstation= _hadByOtherObstacle_KittingWorkstation;
}
void KittingWorkstation::sethasKittingWorkstation_ChangingStation(EndEffectorChangingStation* _hasKittingWorkstation_ChangingStation){
this->hasKittingWorkstation_ChangingStation= _hasKittingWorkstation_ChangingStation;
}
void KittingWorkstation::sethasKittingWorkstation_Robot(Robot* _hasKittingWorkstation_Robot){
this->hasKittingWorkstation_Robot= _hasKittingWorkstation_Robot;
}
void KittingWorkstation::sethadByObject_KittingWorkstation(std::vector<SolidObject*> _hadByObject_KittingWorkstation){
this->hadByObject_KittingWorkstation= _hadByObject_KittingWorkstation;
}
void KittingWorkstation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("KittingWorkstation");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void KittingWorkstation::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["hasKittingWorkstation_LengthUnit"]="'" + hasKittingWorkstation_LengthUnit + "'";
data["hasKittingWorkstation_WeightUnit"]="'" + hasKittingWorkstation_WeightUnit + "'";
data["hasKittingWorkstation_AngleUnit"]="'" + hasKittingWorkstation_AngleUnit + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << KittingWorkstationID;
data["KittingWorkstationID"]=ss.str();
for(unsigned int i=0;i<hadBySku_KittingWorkstation.size();++i){
ss.str("");
hadBySku_KittingWorkstation[i]->get(hadBySku_KittingWorkstation[i]->getname());
ss << hadBySku_KittingWorkstation[i]->getStockKeepingUnitID();
data["hadBySku_KittingWorkstation"]=data["hadBySku_KittingWorkstation"]+" "+ss.str();
}
for(unsigned int i=0;i<hadByKitDesign_KittingWorkstation.size();++i){
ss.str("");
hadByKitDesign_KittingWorkstation[i]->get(hadByKitDesign_KittingWorkstation[i]->getname());
ss << hadByKitDesign_KittingWorkstation[i]->getKitDesignID();
data["hadByKitDesign_KittingWorkstation"]=data["hadByKitDesign_KittingWorkstation"]+" "+ss.str();
}
for(unsigned int i=0;i<hadByOtherObstacle_KittingWorkstation.size();++i){
ss.str("");
hadByOtherObstacle_KittingWorkstation[i]->get(hadByOtherObstacle_KittingWorkstation[i]->getname());
ss << hadByOtherObstacle_KittingWorkstation[i]->getBoxVolumeID();
data["hadByOtherObstacle_KittingWorkstation"]=data["hadByOtherObstacle_KittingWorkstation"]+" "+ss.str();
}
if(hasKittingWorkstation_ChangingStation!=NULL)
data["hasKittingWorkstation_ChangingStation"]=hasKittingWorkstation_ChangingStation->getname();
if(hasKittingWorkstation_Robot!=NULL)
data["hasKittingWorkstation_Robot"]=hasKittingWorkstation_Robot->getname();
for(unsigned int i=0;i<hadByObject_KittingWorkstation.size();++i){
ss.str("");
hadByObject_KittingWorkstation[i]->get(hadByObject_KittingWorkstation[i]->getname());
ss << hadByObject_KittingWorkstation[i]->getSolidObjectID();
data["hadByObject_KittingWorkstation"]=data["hadByObject_KittingWorkstation"]+" "+ss.str();
}
dao  = new DAO("KittingWorkstation");
dao->set(data);
delete (dao);
}
void KittingWorkstation::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
data["hasKittingWorkstation_LengthUnit"]="'" + hasKittingWorkstation_LengthUnit+ "'";
data["hasKittingWorkstation_WeightUnit"]="'" + hasKittingWorkstation_WeightUnit+ "'";
data["hasKittingWorkstation_AngleUnit"]="'" + hasKittingWorkstation_AngleUnit+ "'";
ss.str("");
ss << temp0->getSolidObjectID();
data["KittingWorkstationID"]=ss.str();
if(hasKittingWorkstation_ChangingStation!=NULL)
data["hasKittingWorkstation_ChangingStation"]=hasKittingWorkstation_ChangingStation->getname();
if(hasKittingWorkstation_Robot!=NULL)
data["hasKittingWorkstation_Robot"]=hasKittingWorkstation_Robot->getname();
dao  = new DAO("KittingWorkstation");
dao->insert(data);
delete (dao);
this->set(name);
}

void KittingWorkstation::copy(std::map<std::string,std::string> object){delete(hasKittingWorkstation_ChangingStation);
hasKittingWorkstation_ChangingStation=NULL;
delete(hasKittingWorkstation_Robot);
hasKittingWorkstation_Robot=NULL;
for(std::size_t i = 0; i < hadBySku_KittingWorkstation.size(); i++){
delete(hadBySku_KittingWorkstation[i]);
hadBySku_KittingWorkstation[i]=NULL;}
for(std::size_t i = 0; i < hadByKitDesign_KittingWorkstation.size(); i++){
delete(hadByKitDesign_KittingWorkstation[i]);
hadByKitDesign_KittingWorkstation[i]=NULL;}
for(std::size_t i = 0; i < hadByOtherObstacle_KittingWorkstation.size(); i++){
delete(hadByOtherObstacle_KittingWorkstation[i]);
hadByOtherObstacle_KittingWorkstation[i]=NULL;}
for(std::size_t i = 0; i < hadByObject_KittingWorkstation.size(); i++){
delete(hadByObject_KittingWorkstation[i]);
hadByObject_KittingWorkstation[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<KittingWorkstation*> tmp;
this->hasKittingWorkstation_LengthUnit = object["KittingWorkstation.hasKittingWorkstation_LengthUnit"];
this->hasKittingWorkstation_WeightUnit = object["KittingWorkstation.hasKittingWorkstation_WeightUnit"];
this->hasKittingWorkstation_AngleUnit = object["KittingWorkstation.hasKittingWorkstation_AngleUnit"];
this->name = object["KittingWorkstation._NAME"];
this->KittingWorkstationID = std::atof(object["KittingWorkstation.KittingWorkstationID"].c_str());
if(this->hadBySku_KittingWorkstation.empty() && object["hadBySku_KittingWorkstation/StockKeepingUnit._NAME"]!=""){
temp = Explode(object["hadBySku_KittingWorkstation/StockKeepingUnit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadBySku_KittingWorkstation.push_back(new StockKeepingUnit(temp[i]));
}
}
if(this->hadByKitDesign_KittingWorkstation.empty() && object["hadByKitDesign_KittingWorkstation/KitDesign._NAME"]!=""){
temp = Explode(object["hadByKitDesign_KittingWorkstation/KitDesign._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByKitDesign_KittingWorkstation.push_back(new KitDesign(temp[i]));
}
}
if(this->hadByOtherObstacle_KittingWorkstation.empty() && object["hadByOtherObstacle_KittingWorkstation/BoxVolume._NAME"]!=""){
temp = Explode(object["hadByOtherObstacle_KittingWorkstation/BoxVolume._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByOtherObstacle_KittingWorkstation.push_back(new BoxVolume(temp[i]));
}
}
if(this->hasKittingWorkstation_ChangingStation== NULL && object["hasKittingWorkstation_ChangingStation/EndEffectorChangingStation._NAME"]!=""){
this->hasKittingWorkstation_ChangingStation = new EndEffectorChangingStation(object["hasKittingWorkstation_ChangingStation/EndEffectorChangingStation._NAME"]);
}
if(this->hasKittingWorkstation_Robot== NULL && object["hasKittingWorkstation_Robot/Robot._NAME"]!=""){
this->hasKittingWorkstation_Robot = new Robot(object["hasKittingWorkstation_Robot/Robot._NAME"]);
}
if(this->hadByObject_KittingWorkstation.empty() && object["hadByObject_KittingWorkstation/SolidObject._NAME"]!=""){
temp = Explode(object["hadByObject_KittingWorkstation/SolidObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByObject_KittingWorkstation.push_back(new SolidObject(temp[i]));
}
}

}std::vector<std::string> KittingWorkstation::Explode(const std::string & str, char separator )
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
