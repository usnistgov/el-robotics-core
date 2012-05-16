#include "WorkTable.h"

WorkTable::WorkTable(std::string name) : BoxyObject(name){
this->name=name;
}WorkTable::~WorkTable(){
delete(dao);
delete(hadByWorkTable_Workstation);
}
std::string WorkTable::getname(){
return this->name;
}
int WorkTable::getWorkTableID(){
return this->WorkTableID;
}
DAO* WorkTable::getdao(){
return this->dao;
}
KittingWorkstation* WorkTable::gethadByWorkTable_Workstation(){
return this->hadByWorkTable_Workstation;
}
void WorkTable::setname(std::string _name){
this->name= _name;
}
void WorkTable::setWorkTableID(int _WorkTableID){
this->WorkTableID= _WorkTableID;
}
void WorkTable::setdao(DAO* _dao){
this->dao= _dao;
}
void WorkTable::sethadByWorkTable_Workstation(KittingWorkstation* _hadByWorkTable_Workstation){
this->hadByWorkTable_Workstation= _hadByWorkTable_Workstation;
}
void WorkTable::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);
 BoxyObject::copy(temp);
delete (dao);
dao  = new DAO("WorkTable");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void WorkTable::set(std::string name){
 dao  = new DAO("WorkTable");
 dao->set(name);
delete (dao);
}

void WorkTable::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["WorkTable._NAME"];
this->WorkTableID = std::atof(object["WorkTable.WorkTableID"].c_str());
this->hadByWorkTable_Workstation = new KittingWorkstation(" ");
this->hadByWorkTable_Workstation->sethadByWorkTable_Workstation(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,27) == "hadByWorkTable_Workstation/"){
mapTemp[it->first.substr(27,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hadByWorkTable_Workstation->copy(mapTemp);

}std::vector<std::string> WorkTable::Explode(const std::string & str, char separator )
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
