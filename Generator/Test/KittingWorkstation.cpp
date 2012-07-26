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
 #include "KitDesign.h"
 #include "StockKeepingUnit.h"
 #include "EndEffectorChangingStation.h"
 #include "DAO.h"
 #include "WorkTable.h"

KittingWorkstation::KittingWorkstation(std::string name) : SolidObject(name){
dao = NULL;
hasWorkstation_ChangingStation = NULL;
hasWorkstation_WorkTable = NULL;
hasWorkstation_Robot = NULL;

}KittingWorkstation::~KittingWorkstation(){
delete(dao);
delete(hasWorkstation_ChangingStation);
delete(hasWorkstation_WorkTable);
delete(hasWorkstation_Robot);
for(std::size_t i = 0; i < hadByKitDesign_Workstation.size(); i++)
delete(hadByKitDesign_Workstation[i]);
for(std::size_t i = 0; i < hasWorkstation_OtherObstacles.size(); i++)
delete(hasWorkstation_OtherObstacles[i]);
for(std::size_t i = 0; i < hadBySku_Workstation.size(); i++)
delete(hadBySku_Workstation[i]);
}
std::string KittingWorkstation::gethasWorkstation_LengthUnit(){
return hasWorkstation_LengthUnit;
}
std::string KittingWorkstation::gethasWorkstation_AngleUnit(){
return hasWorkstation_AngleUnit;
}
std::string KittingWorkstation::gethasWorkstation_WeightUnit(){
return hasWorkstation_WeightUnit;
}
int KittingWorkstation::getKittingWorkstationID(){
return KittingWorkstationID;
}
DAO* KittingWorkstation::getdao(){
return dao;
}
std::vector<KitDesign*>* KittingWorkstation::gethadByKitDesign_Workstation(){
return &hadByKitDesign_Workstation;
}
EndEffectorChangingStation* KittingWorkstation::gethasWorkstation_ChangingStation(){
return hasWorkstation_ChangingStation;
}
WorkTable* KittingWorkstation::gethasWorkstation_WorkTable(){
return hasWorkstation_WorkTable;
}
std::vector<BoxVolume*>* KittingWorkstation::gethasWorkstation_OtherObstacles(){
return &hasWorkstation_OtherObstacles;
}
std::vector<StockKeepingUnit*>* KittingWorkstation::gethadBySku_Workstation(){
return &hadBySku_Workstation;
}
Robot* KittingWorkstation::gethasWorkstation_Robot(){
return hasWorkstation_Robot;
}
void KittingWorkstation::sethasWorkstation_LengthUnit(std::string _hasWorkstation_LengthUnit){
this->hasWorkstation_LengthUnit= _hasWorkstation_LengthUnit;
}
void KittingWorkstation::sethasWorkstation_AngleUnit(std::string _hasWorkstation_AngleUnit){
this->hasWorkstation_AngleUnit= _hasWorkstation_AngleUnit;
}
void KittingWorkstation::sethasWorkstation_WeightUnit(std::string _hasWorkstation_WeightUnit){
this->hasWorkstation_WeightUnit= _hasWorkstation_WeightUnit;
}
void KittingWorkstation::setdao(DAO* _dao){
this->dao= _dao;
}
void KittingWorkstation::sethadByKitDesign_Workstation(std::vector<KitDesign*> _hadByKitDesign_Workstation){
this->hadByKitDesign_Workstation= _hadByKitDesign_Workstation;
}
void KittingWorkstation::sethasWorkstation_ChangingStation(EndEffectorChangingStation* _hasWorkstation_ChangingStation){
this->hasWorkstation_ChangingStation= _hasWorkstation_ChangingStation;
}
void KittingWorkstation::sethasWorkstation_WorkTable(WorkTable* _hasWorkstation_WorkTable){
this->hasWorkstation_WorkTable= _hasWorkstation_WorkTable;
}
void KittingWorkstation::sethasWorkstation_OtherObstacles(std::vector<BoxVolume*> _hasWorkstation_OtherObstacles){
this->hasWorkstation_OtherObstacles= _hasWorkstation_OtherObstacles;
}
void KittingWorkstation::sethadBySku_Workstation(std::vector<StockKeepingUnit*> _hadBySku_Workstation){
this->hadBySku_Workstation= _hadBySku_Workstation;
}
void KittingWorkstation::sethasWorkstation_Robot(Robot* _hasWorkstation_Robot){
this->hasWorkstation_Robot= _hasWorkstation_Robot;
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
SolidObject* temp = (SolidObject*) this;
temp->set(name);
data["hasWorkstation_LengthUnit"]=hasWorkstation_LengthUnit;
data["hasWorkstation_AngleUnit"]=hasWorkstation_AngleUnit;
data["hasWorkstation_WeightUnit"]=hasWorkstation_WeightUnit;
data["name"]=name;
ss.str("");
ss << KittingWorkstationID;
data["KittingWorkstationID"]=ss.str();
for(unsigned int i=0;i<hadByKitDesign_Workstation.size();++i){
ss.str("");
hadByKitDesign_Workstation[i]->get(hadByKitDesign_Workstation[i]->getname());
ss << hadByKitDesign_Workstation[i]->getKitDesignID();
data["hadByKitDesign_Workstation"]=data["hadByKitDesign_Workstation"]+" "+ss.str();
}
if(hasWorkstation_ChangingStation!=NULL)
data["hasWorkstation_ChangingStation"]=hasWorkstation_ChangingStation->getname();
if(hasWorkstation_WorkTable!=NULL)
data["hasWorkstation_WorkTable"]=hasWorkstation_WorkTable->getname();
for(unsigned int i=0;i<hasWorkstation_OtherObstacles.size();++i){
ss.str("");
hasWorkstation_OtherObstacles[i]->get(hasWorkstation_OtherObstacles[i]->getname());
ss << hasWorkstation_OtherObstacles[i]->getBoxVolumeID();
data["hasWorkstation_OtherObstacles"]=data["hasWorkstation_OtherObstacles"]+" "+ss.str();
}
for(unsigned int i=0;i<hadBySku_Workstation.size();++i){
ss.str("");
hadBySku_Workstation[i]->get(hadBySku_Workstation[i]->getname());
ss << hadBySku_Workstation[i]->getStockKeepingUnitID();
data["hadBySku_Workstation"]=data["hadBySku_Workstation"]+" "+ss.str();
}
if(hasWorkstation_Robot!=NULL)
data["hasWorkstation_Robot"]=hasWorkstation_Robot->getname();
dao  = new DAO("KittingWorkstation");
dao->set(data);
delete (dao);
}

void KittingWorkstation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<KittingWorkstation*> tmp;
this->hasWorkstation_LengthUnit = object["KittingWorkstation.hasWorkstation_LengthUnit"];
this->hasWorkstation_AngleUnit = object["KittingWorkstation.hasWorkstation_AngleUnit"];
this->hasWorkstation_WeightUnit = object["KittingWorkstation.hasWorkstation_WeightUnit"];
this->name = object["KittingWorkstation._NAME"];
this->KittingWorkstationID = std::atof(object["KittingWorkstation.KittingWorkstationID"].c_str());
if(this->hadByKitDesign_Workstation.empty() && object["hadByKitDesign_Workstation/KitDesign._NAME"]!=""){
temp = Explode(object["hadByKitDesign_Workstation/KitDesign._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByKitDesign_Workstation.push_back(new KitDesign(temp[i]));
}
}
if(this->hasWorkstation_ChangingStation== NULL && object["hasWorkstation_ChangingStation/EndEffectorChangingStation._NAME"]!=""){
this->hasWorkstation_ChangingStation = new EndEffectorChangingStation(object["hasWorkstation_ChangingStation/EndEffectorChangingStation._NAME"]);
}
if(this->hasWorkstation_WorkTable== NULL && object["hasWorkstation_WorkTable/WorkTable._NAME"]!=""){
this->hasWorkstation_WorkTable = new WorkTable(object["hasWorkstation_WorkTable/WorkTable._NAME"]);
}
if(this->hasWorkstation_OtherObstacles.empty() && object["hasWorkstation_OtherObstacles/BoxVolume._NAME"]!=""){
temp = Explode(object["hasWorkstation_OtherObstacles/BoxVolume._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasWorkstation_OtherObstacles.push_back(new BoxVolume(temp[i]));
}
}
if(this->hadBySku_Workstation.empty() && object["hadBySku_Workstation/StockKeepingUnit._NAME"]!=""){
temp = Explode(object["hadBySku_Workstation/StockKeepingUnit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadBySku_Workstation.push_back(new StockKeepingUnit(temp[i]));
}
}
if(this->hasWorkstation_Robot== NULL && object["hasWorkstation_Robot/Robot._NAME"]!=""){
this->hasWorkstation_Robot = new Robot(object["hasWorkstation_Robot/Robot._NAME"]);
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
