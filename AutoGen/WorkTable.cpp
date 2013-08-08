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

#include "WorkTable.h"


 #include "SolidObject.h"
 #include "DAO.h"

WorkTable::WorkTable(std::string name) : SolidObject(name){
dao = NULL;

}WorkTable::~WorkTable(){
for(std::size_t i = 0; i < hadBySolidObject_WorkTable.size(); i++)
delete(hadBySolidObject_WorkTable[i]);
}
int WorkTable::getWorkTableID(){
return WorkTableID;
}
DAO* WorkTable::getdao(){
return dao;
}
std::vector<SolidObject*> WorkTable::gethadBySolidObject_WorkTable(){
return hadBySolidObject_WorkTable;
}
void WorkTable::setWorkTableID(int _WorkTableID){
this->WorkTableID= _WorkTableID;
}
void WorkTable::setdao(DAO* _dao){
this->dao= _dao;
}
void WorkTable::sethadBySolidObject_WorkTable(std::vector<SolidObject*> _hadBySolidObject_WorkTable){
this->hadBySolidObject_WorkTable= _hadBySolidObject_WorkTable;
}
void WorkTable::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("WorkTable");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void WorkTable::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << WorkTableID;
data["WorkTableID"]=ss.str();
for(unsigned int i=0;i<hadBySolidObject_WorkTable.size();++i){
ss.str("");
hadBySolidObject_WorkTable[i]->get(hadBySolidObject_WorkTable[i]->getname());
ss << hadBySolidObject_WorkTable[i]->getSolidObjectID();
data["hadBySolidObject_WorkTable"]=data["hadBySolidObject_WorkTable"]+" "+ss.str();
}
dao  = new DAO("WorkTable");
dao->set(data);
delete (dao);
}
void WorkTable::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getSolidObjectID();
data["WorkTableID"]=ss.str();
dao  = new DAO("WorkTable");
dao->insert(data);
delete (dao);
this->set(name);
}

void WorkTable::copy(std::map<std::string,std::string> object){for(std::size_t i = 0; i < hadBySolidObject_WorkTable.size(); i++){
delete(hadBySolidObject_WorkTable[i]);
hadBySolidObject_WorkTable[i]=NULL;}
hadBySolidObject_WorkTable.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<WorkTable*> tmp;
this->name = object["WorkTable._NAME"];
this->WorkTableID = std::atof(object["WorkTable.WorkTableID"].c_str());
if(this->hadBySolidObject_WorkTable.empty() && object["hadBySolidObject_WorkTable/SolidObject._NAME"]!=""){
temp = Explode(object["hadBySolidObject_WorkTable/SolidObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadBySolidObject_WorkTable.push_back(new SolidObject(temp[i]));
}
}

}std::vector<std::string> WorkTable::Explode(const std::string & str, char separator )
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
