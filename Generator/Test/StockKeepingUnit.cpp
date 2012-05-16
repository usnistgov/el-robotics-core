#include "StockKeepingUnit.h"

StockKeepingUnit::StockKeepingUnit(std::string name) : DataThing(name){
this->name=name;
}StockKeepingUnit::~StockKeepingUnit(){
delete(dao);
delete(hasSku_Shape);
}
std::vector<std::string> StockKeepingUnit::gethasSku_EndEffectorRefs(){
return this->hasSku_EndEffectorRefs;
}
std::string StockKeepingUnit::gethasSku_Description(){
return this->hasSku_Description;
}
std::string StockKeepingUnit::gethasSku_Id(){
return this->hasSku_Id;
}
double StockKeepingUnit::gethasSku_Weight(){
return this->hasSku_Weight;
}
std::string StockKeepingUnit::getname(){
return this->name;
}
int StockKeepingUnit::getStockKeepingUnitID(){
return this->StockKeepingUnitID;
}
DAO* StockKeepingUnit::getdao(){
return this->dao;
}
ShapeDesign* StockKeepingUnit::gethasSku_Shape(){
return this->hasSku_Shape;
}
void StockKeepingUnit::sethasSku_EndEffectorRefs(std::vector<std::string> _hasSku_EndEffectorRefs){
this->hasSku_EndEffectorRefs= _hasSku_EndEffectorRefs;
}
void StockKeepingUnit::sethasSku_Description(std::string _hasSku_Description){
this->hasSku_Description= _hasSku_Description;
}
void StockKeepingUnit::sethasSku_Id(std::string _hasSku_Id){
this->hasSku_Id= _hasSku_Id;
}
void StockKeepingUnit::sethasSku_Weight(double _hasSku_Weight){
this->hasSku_Weight= _hasSku_Weight;
}
void StockKeepingUnit::setname(std::string _name){
this->name= _name;
}
void StockKeepingUnit::setStockKeepingUnitID(int _StockKeepingUnitID){
this->StockKeepingUnitID= _StockKeepingUnitID;
}
void StockKeepingUnit::setdao(DAO* _dao){
this->dao= _dao;
}
void StockKeepingUnit::sethasSku_Shape(ShapeDesign* _hasSku_Shape){
this->hasSku_Shape= _hasSku_Shape;
}
void StockKeepingUnit::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("StockKeepingUnit");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void StockKeepingUnit::set(std::string name){
 dao  = new DAO("StockKeepingUnit");
 dao->set(name);
delete (dao);
}

void StockKeepingUnit::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
temp = Explode(object["hasSku_EndEffectorRefs"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSku_EndEffectorRefs.push_back(temp[i]);
}
this->hasSku_Description = object["StockKeepingUnit.hasSku_Description"];
this->hasSku_Id = object["StockKeepingUnit.hasSku_Id"];
this->hasSku_Weight = std::atof(object["StockKeepingUnit.hasSku_Weight"].c_str());
this->name = object["StockKeepingUnit._NAME"];
this->StockKeepingUnitID = std::atof(object["StockKeepingUnit.StockKeepingUnitID"].c_str());
this->hasSku_Shape = new ShapeDesign(" ");
this->hasSku_Shape->sethasSku_Shape(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,13) == "hasSku_Shape/"){
mapTemp[it->first.substr(13,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasSku_Shape->copy(mapTemp);

}std::vector<std::string> StockKeepingUnit::Explode(const std::string & str, char separator )
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
