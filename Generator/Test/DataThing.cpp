#include "DataThing.h"


 #include "DAO.h"

DataThing::DataThing(std::string name){
this->name=name;dao = NULL;

}DataThing::~DataThing(){
delete(dao);
}
std::string DataThing::getname(){
return name;
}
int DataThing::getDataThingID(){
return DataThingID;
}
DAO* DataThing::getdao(){
return dao;
}
void DataThing::setdao(DAO* _dao){
this->dao= _dao;
}
void DataThing::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void DataThing::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["name"]=name;
ss.str("");
ss << DataThingID;
data["DataThingID"]=ss.str();
dao  = new DAO("DataThing");
dao->set(data);
delete (dao);
}

void DataThing::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<DataThing*> tmp;
this->name = object["DataThing._NAME"];
this->DataThingID = std::atof(object["DataThing.DataThingID"].c_str());

}std::vector<std::string> DataThing::Explode(const std::string & str, char separator )
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
