#include "PartsBin.h"

PartsBin::PartsBin(std::string name) : BoxyObject(name){
this->name=name;
}PartsBin::~PartsBin(){
delete(dao);
}
std::string PartsBin::gethasBin_PartQuantity(){
return this->hasBin_PartQuantity;
}
std::string PartsBin::gethasBin_PartSkuRef(){
return this->hasBin_PartSkuRef;
}
std::string PartsBin::getname(){
return this->name;
}
int PartsBin::getPartsBinID(){
return this->PartsBinID;
}
DAO* PartsBin::getdao(){
return this->dao;
}
void PartsBin::sethasBin_PartQuantity(std::string _hasBin_PartQuantity){
this->hasBin_PartQuantity= _hasBin_PartQuantity;
}
void PartsBin::sethasBin_PartSkuRef(std::string _hasBin_PartSkuRef){
this->hasBin_PartSkuRef= _hasBin_PartSkuRef;
}
void PartsBin::setname(std::string _name){
this->name= _name;
}
void PartsBin::setPartsBinID(int _PartsBinID){
this->PartsBinID= _PartsBinID;
}
void PartsBin::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsBin::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("BoxyObject");
 temp = dao->get(name);
 BoxyObject::copy(temp);
delete (dao);
dao  = new DAO("PartsBin");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void PartsBin::set(std::string name){
 dao  = new DAO("PartsBin");
 dao->set(name);
delete (dao);
}

void PartsBin::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasBin_PartQuantity = object["PartsBin.hasBin_PartQuantity"];
this->hasBin_PartSkuRef = object["PartsBin.hasBin_PartSkuRef"];
this->name = object["PartsBin._NAME"];
this->PartsBinID = std::atof(object["PartsBin.PartsBinID"].c_str());

}std::vector<std::string> PartsBin::Explode(const std::string & str, char separator )
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
