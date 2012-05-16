#include "KittingWorkstation.h"

KittingWorkstation::KittingWorkstation(std::string name) : SolidObject(name){
this->name=name;
}KittingWorkstation::~KittingWorkstation(){
delete(dao);
delete(hadByChangingStation_Workstation);
delete(hadByWorkTable_Workstation);
delete(hadByRobot_Workstation);
for(size_t i = 0; i < hasWorkstation_OtherObstacles.size(); i++)
delete(hasWorkstation_OtherObstacles[i]);
}
std::string KittingWorkstation::gethasWorkstation_LengthUnit(){
return this->hasWorkstation_LengthUnit;
}
std::string KittingWorkstation::gethasWorkstation_WeightUnit(){
return this->hasWorkstation_WeightUnit;
}
std::string KittingWorkstation::gethasWorkstation_AngleUnit(){
return this->hasWorkstation_AngleUnit;
}
std::string KittingWorkstation::getname(){
return this->name;
}
int KittingWorkstation::getKittingWorkstationID(){
return this->KittingWorkstationID;
}
DAO* KittingWorkstation::getdao(){
return this->dao;
}
EndEffectorChangingStation* KittingWorkstation::gethadByChangingStation_Workstation(){
return this->hadByChangingStation_Workstation;
}
std::vector<BoxVolume*> KittingWorkstation::gethasWorkstation_OtherObstacles(){
return this->hasWorkstation_OtherObstacles;
}
WorkTable* KittingWorkstation::gethadByWorkTable_Workstation(){
return this->hadByWorkTable_Workstation;
}
Robot* KittingWorkstation::gethadByRobot_Workstation(){
return this->hadByRobot_Workstation;
}
void KittingWorkstation::sethasWorkstation_LengthUnit(std::string _hasWorkstation_LengthUnit){
this->hasWorkstation_LengthUnit= _hasWorkstation_LengthUnit;
}
void KittingWorkstation::sethasWorkstation_WeightUnit(std::string _hasWorkstation_WeightUnit){
this->hasWorkstation_WeightUnit= _hasWorkstation_WeightUnit;
}
void KittingWorkstation::sethasWorkstation_AngleUnit(std::string _hasWorkstation_AngleUnit){
this->hasWorkstation_AngleUnit= _hasWorkstation_AngleUnit;
}
void KittingWorkstation::setname(std::string _name){
this->name= _name;
}
void KittingWorkstation::setKittingWorkstationID(int _KittingWorkstationID){
this->KittingWorkstationID= _KittingWorkstationID;
}
void KittingWorkstation::setdao(DAO* _dao){
this->dao= _dao;
}
void KittingWorkstation::sethadByChangingStation_Workstation(EndEffectorChangingStation* _hadByChangingStation_Workstation){
this->hadByChangingStation_Workstation= _hadByChangingStation_Workstation;
}
void KittingWorkstation::sethasWorkstation_OtherObstacles(std::vector<BoxVolume*> _hasWorkstation_OtherObstacles){
this->hasWorkstation_OtherObstacles= _hasWorkstation_OtherObstacles;
}
void KittingWorkstation::sethadByWorkTable_Workstation(WorkTable* _hadByWorkTable_Workstation){
this->hadByWorkTable_Workstation= _hadByWorkTable_Workstation;
}
void KittingWorkstation::sethadByRobot_Workstation(Robot* _hadByRobot_Workstation){
this->hadByRobot_Workstation= _hadByRobot_Workstation;
}
void KittingWorkstation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("KittingWorkstation");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void KittingWorkstation::set(std::string name){
 dao  = new DAO("KittingWorkstation");
 dao->set(name);
delete (dao);
}

void KittingWorkstation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasWorkstation_LengthUnit = object["KittingWorkstation.hasWorkstation_LengthUnit"];
this->hasWorkstation_WeightUnit = object["KittingWorkstation.hasWorkstation_WeightUnit"];
this->hasWorkstation_AngleUnit = object["KittingWorkstation.hasWorkstation_AngleUnit"];
this->name = object["KittingWorkstation._NAME"];
this->KittingWorkstationID = std::atof(object["KittingWorkstation.KittingWorkstationID"].c_str());
this->hadByChangingStation_Workstation = new EndEffectorChangingStation(" ");
this->hadByChangingStation_Workstation->sethadByChangingStation_Workstation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,33) == "hadByChangingStation_Workstation/"){
mapTemp[it->first.substr(33,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByChangingStation_Workstation->copy(mapTemp);
mapTemp.clear();
mapTempBis.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,30) == "hasWorkstation_OtherObstacles/"){
mapTemp[it->first.substr(30,it->first.length())] = it->second;
nbVal=Explode(it->second,' ').size();
}
}
nbValCurrent=0;
if(nbValCurrent<=nbVal){
for (std::map<std::string, std::string>::iterator it = mapTemp.begin(); it
!= mapTemp.end(); it++) {
mapTempBis[it->first]=Explode(it->second,' ')[nbValCurrent];
if(!mapTempBis.empty()){
this->hasWorkstation_OtherObstacles.push_back(new BoxVolume(" "));
this->hasWorkstation_OtherObstacles.back()->gethasWorkstation_OtherObstacles().push_back(this);
this->hasWorkstation_OtherObstacles.back()->copy(mapTempBis);
}
}
nbValCurrent++;
}
this->hadByWorkTable_Workstation = new WorkTable(" ");
this->hadByWorkTable_Workstation->sethadByWorkTable_Workstation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,27) == "hadByWorkTable_Workstation/"){
mapTemp[it->first.substr(27,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByWorkTable_Workstation->copy(mapTemp);
this->hadByRobot_Workstation = new Robot(" ");
this->hadByRobot_Workstation->sethadByRobot_Workstation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,23) == "hadByRobot_Workstation/"){
mapTemp[it->first.substr(23,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByRobot_Workstation->copy(mapTemp);

}std::vector<std::string> KittingWorkstation::Explode(const std::string & str, char separator )
{
   std::vector< std::string > result;
   size_t pos1 = 0;
   size_t pos2 = 0;
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
