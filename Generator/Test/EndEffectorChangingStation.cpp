#include "EndEffectorChangingStation.h"

EndEffectorChangingStation::EndEffectorChangingStation(std::string name) : SolidObject(name){
this->name=name;
}EndEffectorChangingStation::~EndEffectorChangingStation(){
delete(dao);
delete(hadByChangingStation_Workstation);
}
std::string EndEffectorChangingStation::getname(){
return this->name;
}
int EndEffectorChangingStation::getEndEffectorChangingStationID(){
return this->EndEffectorChangingStationID;
}
DAO* EndEffectorChangingStation::getdao(){
return this->dao;
}
KittingWorkstation* EndEffectorChangingStation::gethadByChangingStation_Workstation(){
return this->hadByChangingStation_Workstation;
}
void EndEffectorChangingStation::setname(std::string _name){
this->name= _name;
}
void EndEffectorChangingStation::setEndEffectorChangingStationID(int _EndEffectorChangingStationID){
this->EndEffectorChangingStationID= _EndEffectorChangingStationID;
}
void EndEffectorChangingStation::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorChangingStation::sethadByChangingStation_Workstation(KittingWorkstation* _hadByChangingStation_Workstation){
this->hadByChangingStation_Workstation= _hadByChangingStation_Workstation;
}
void EndEffectorChangingStation::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("EndEffectorChangingStation");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void EndEffectorChangingStation::set(std::string name){
 dao  = new DAO("EndEffectorChangingStation");
 dao->set(name);
delete (dao);
}

void EndEffectorChangingStation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["EndEffectorChangingStation._NAME"];
this->EndEffectorChangingStationID = std::atof(object["EndEffectorChangingStation.EndEffectorChangingStationID"].c_str());
this->hadByChangingStation_Workstation = new KittingWorkstation(" ");
this->hadByChangingStation_Workstation->sethadByChangingStation_Workstation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,33) == "hadByChangingStation_Workstation/"){
mapTemp[it->first.substr(33,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByChangingStation_Workstation->copy(mapTemp);

}std::vector<std::string> EndEffectorChangingStation::Explode(const std::string & str, char separator )
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
