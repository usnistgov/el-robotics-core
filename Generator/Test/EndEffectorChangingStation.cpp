#include "EndEffectorChangingStation.h"


 #include "KittingWorkstation.h"
 #include "DAO.h"
 #include "EndEffectorHolder.h"

EndEffectorChangingStation::EndEffectorChangingStation(std::string name) : SolidObject(name){
this->name=name;dao = NULL;
hasWorkstation_ChangingStation = NULL;

}EndEffectorChangingStation::~EndEffectorChangingStation(){
delete(dao);
delete(hasWorkstation_ChangingStation);
for(std::size_t i = 0; i < hadByEndEffectorHolder_ChangingStation.size(); i++)
delete(hadByEndEffectorHolder_ChangingStation[i]);
}
std::string EndEffectorChangingStation::getname(){
return name;
}
int EndEffectorChangingStation::getEndEffectorChangingStationID(){
return EndEffectorChangingStationID;
}
DAO* EndEffectorChangingStation::getdao(){
return dao;
}
std::vector<EndEffectorHolder*>* EndEffectorChangingStation::gethadByEndEffectorHolder_ChangingStation(){
return &hadByEndEffectorHolder_ChangingStation;
}
KittingWorkstation* EndEffectorChangingStation::gethasWorkstation_ChangingStation(){
return hasWorkstation_ChangingStation;
}
void EndEffectorChangingStation::setdao(DAO* _dao){
this->dao= _dao;
}
void EndEffectorChangingStation::sethadByEndEffectorHolder_ChangingStation(std::vector<EndEffectorHolder*> _hadByEndEffectorHolder_ChangingStation){
this->hadByEndEffectorHolder_ChangingStation= _hadByEndEffectorHolder_ChangingStation;
}
void EndEffectorChangingStation::sethasWorkstation_ChangingStation(KittingWorkstation* _hasWorkstation_ChangingStation){
this->hasWorkstation_ChangingStation= _hasWorkstation_ChangingStation;
}
void EndEffectorChangingStation::get(std::string name){
std::map<std::string,std::string> temp;
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
data["name"]=name;
ss.str("");
ss << EndEffectorChangingStationID;
data["EndEffectorChangingStationID"]=ss.str();
for(unsigned int i=0;i<hadByEndEffectorHolder_ChangingStation.size();++i){
ss.str("");
hadByEndEffectorHolder_ChangingStation[i]->get(hadByEndEffectorHolder_ChangingStation[i]->getname());
ss << hadByEndEffectorHolder_ChangingStation[i]->getEndEffectorHolderID();
data["hadByEndEffectorHolder_ChangingStation"]=data["hadByEndEffectorHolder_ChangingStation"]+" "+ss.str();
}
data["hasWorkstation_ChangingStation"]=hasWorkstation_ChangingStation->getname();
dao  = new DAO("EndEffectorChangingStation");
dao->set(data);
delete (dao);
}

void EndEffectorChangingStation::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<EndEffectorChangingStation*> tmp;
this->name = object["EndEffectorChangingStation._NAME"];
this->EndEffectorChangingStationID = std::atof(object["EndEffectorChangingStation.EndEffectorChangingStationID"].c_str());
if(this->hadByEndEffectorHolder_ChangingStation.empty() && object["hadByEndEffectorHolder_ChangingStation/EndEffectorHolder._NAME"]!=""){
temp = Explode(object["hadByEndEffectorHolder_ChangingStation/EndEffectorHolder._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByEndEffectorHolder_ChangingStation.push_back(new EndEffectorHolder(temp[i]));
}
}
if(this->hasWorkstation_ChangingStation== NULL && object["hasWorkstation_ChangingStation/KittingWorkstation._NAME"]!=""){
this->hasWorkstation_ChangingStation = new KittingWorkstation(object["hasWorkstation_ChangingStation/KittingWorkstation._NAME"]);
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
