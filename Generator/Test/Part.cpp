#include "Part.h"


 #include "PartsTrayWithParts.h"
 #include "KitInstance.h"
 #include "DAO.h"

Part::Part(std::string name) : SolidObject(name){
this->name=name;dao = NULL;
hadByPart_KitInstance = NULL;
hadByPart_PartsTrayWithParts = NULL;

}Part::~Part(){
delete(dao);
delete(hadByPart_KitInstance);
delete(hadByPart_PartsTrayWithParts);
}
std::string Part::gethasPart_SerialNumber(){
return hasPart_SerialNumber;
}
std::string Part::gethasPart_SkuRef(){
return hasPart_SkuRef;
}
std::string Part::getname(){
return name;
}
int Part::getPartID(){
return PartID;
}
DAO* Part::getdao(){
return dao;
}
KitInstance* Part::gethadByPart_KitInstance(){
return hadByPart_KitInstance;
}
PartsTrayWithParts* Part::gethadByPart_PartsTrayWithParts(){
return hadByPart_PartsTrayWithParts;
}
void Part::sethasPart_SerialNumber(std::string _hasPart_SerialNumber){
this->hasPart_SerialNumber= _hasPart_SerialNumber;
}
void Part::sethasPart_SkuRef(std::string _hasPart_SkuRef){
this->hasPart_SkuRef= _hasPart_SkuRef;
}
void Part::setdao(DAO* _dao){
this->dao= _dao;
}
void Part::sethadByPart_KitInstance(KitInstance* _hadByPart_KitInstance){
this->hadByPart_KitInstance= _hadByPart_KitInstance;
}
void Part::sethadByPart_PartsTrayWithParts(PartsTrayWithParts* _hadByPart_PartsTrayWithParts){
this->hadByPart_PartsTrayWithParts= _hadByPart_PartsTrayWithParts;
}
void Part::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("Part");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Part::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasPart_SerialNumber"]=hasPart_SerialNumber;
data["hasPart_SkuRef"]=hasPart_SkuRef;
data["name"]=name;
ss.str("");
ss << PartID;
data["PartID"]=ss.str();
data["hadByPart_KitInstance"]=hadByPart_KitInstance->getname();
data["hadByPart_PartsTrayWithParts"]=hadByPart_PartsTrayWithParts->getname();
dao  = new DAO("Part");
dao->set(data);
delete (dao);
}

void Part::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Part*> tmp;
this->hasPart_SerialNumber = object["Part.hasPart_SerialNumber"];
this->hasPart_SkuRef = object["Part.hasPart_SkuRef"];
this->name = object["Part._NAME"];
this->PartID = std::atof(object["Part.PartID"].c_str());
if(this->hadByPart_KitInstance== NULL && object["hadByPart_KitInstance/KitInstance._NAME"]!=""){
this->hadByPart_KitInstance = new KitInstance(object["hadByPart_KitInstance/KitInstance._NAME"]);
}
if(this->hadByPart_PartsTrayWithParts== NULL && object["hadByPart_PartsTrayWithParts/PartsTrayWithParts._NAME"]!=""){
this->hadByPart_PartsTrayWithParts = new PartsTrayWithParts(object["hadByPart_PartsTrayWithParts/PartsTrayWithParts._NAME"]);
}

}std::vector<std::string> Part::Explode(const std::string & str, char separator )
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
