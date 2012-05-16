#include "DataThing.h"

DataThing::DataThing(std::string name){
this->name=name;
}DataThing::~DataThing(){
delete(dao);
}
std::string DataThing::getname(){
return this->name;
}
int DataThing::getDataThingID(){
return this->DataThingID;
}
DAO* DataThing::getdao(){
return this->dao;
}
void DataThing::setname(std::string _name){
this->name= _name;
}
void DataThing::setDataThingID(int _DataThingID){
this->DataThingID= _DataThingID;
}
void DataThing::setdao(DAO* _dao){
this->dao= _dao;
}
void DataThing::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void DataThing::set(std::string name){
 dao  = new DAO("DataThing");
 dao->set(name);
delete (dao);
}

void DataThing::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->name = object["DataThing._NAME"];
this->DataThingID = std::atof(object["DataThing.DataThingID"].c_str());

}std::vector<std::string> DataThing::Explode(const std::string & str, char separator )
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
