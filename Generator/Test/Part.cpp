#include "Part.h"

Part::Part(std::string name) : SolidObject(name){
this->name=name;
}Part::~Part(){
delete(dao);
}
std::string Part::gethasPart_SerialNumber(){
return this->hasPart_SerialNumber;
}
std::string Part::gethasPart_SkuRef(){
return this->hasPart_SkuRef;
}
std::string Part::getname(){
return this->name;
}
int Part::getPartID(){
return this->PartID;
}
DAO* Part::getdao(){
return this->dao;
}
void Part::sethasPart_SerialNumber(std::string _hasPart_SerialNumber){
this->hasPart_SerialNumber= _hasPart_SerialNumber;
}
void Part::sethasPart_SkuRef(std::string _hasPart_SkuRef){
this->hasPart_SkuRef= _hasPart_SkuRef;
}
void Part::setname(std::string _name){
this->name= _name;
}
void Part::setPartID(int _PartID){
this->PartID= _PartID;
}
void Part::setdao(DAO* _dao){
this->dao= _dao;
}
void Part::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("Part");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void Part::set(std::string name){
 dao  = new DAO("Part");
 dao->set(name);
delete (dao);
}

void Part::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasPart_SerialNumber = object["Part.hasPart_SerialNumber"];
this->hasPart_SkuRef = object["Part.hasPart_SkuRef"];
this->name = object["Part._NAME"];
this->PartID = std::atof(object["Part.PartID"].c_str());

}std::vector<std::string> Part::Explode(const std::string & str, char separator )
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
