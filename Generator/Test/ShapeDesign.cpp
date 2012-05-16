#include "ShapeDesign.h"

ShapeDesign::ShapeDesign(std::string name) : DataThing(name){
this->name=name;
}ShapeDesign::~ShapeDesign(){
delete(dao);
delete(hasSku_Shape);
}
std::string ShapeDesign::gethasShapeDesign_Description(){
return this->hasShapeDesign_Description;
}
std::string ShapeDesign::getname(){
return this->name;
}
int ShapeDesign::getShapeDesignID(){
return this->ShapeDesignID;
}
DAO* ShapeDesign::getdao(){
return this->dao;
}
StockKeepingUnit* ShapeDesign::gethasSku_Shape(){
return this->hasSku_Shape;
}
void ShapeDesign::sethasShapeDesign_Description(std::string _hasShapeDesign_Description){
this->hasShapeDesign_Description= _hasShapeDesign_Description;
}
void ShapeDesign::setname(std::string _name){
this->name= _name;
}
void ShapeDesign::setShapeDesignID(int _ShapeDesignID){
this->ShapeDesignID= _ShapeDesignID;
}
void ShapeDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void ShapeDesign::sethasSku_Shape(StockKeepingUnit* _hasSku_Shape){
this->hasSku_Shape= _hasSku_Shape;
}
void ShapeDesign::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("ShapeDesign");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void ShapeDesign::set(std::string name){
 dao  = new DAO("ShapeDesign");
 dao->set(name);
delete (dao);
}

void ShapeDesign::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasShapeDesign_Description = object["ShapeDesign.hasShapeDesign_Description"];
this->name = object["ShapeDesign._NAME"];
this->ShapeDesignID = std::atof(object["ShapeDesign.ShapeDesignID"].c_str());
this->hasSku_Shape = new StockKeepingUnit(" ");
this->hasSku_Shape->sethasSku_Shape(this);
mapTemp.clear();
for (std::map<std::string, std::string>::iterator it = object.begin(); it
!= object.end(); it++) {
if (it->first.substr(0,13) == "hasSku_Shape/"){
mapTemp[it->first.substr(13,it->first.length())] = it->second;
}
}
if(!mapTemp.empty())this->hasSku_Shape->copy(mapTemp);

}std::vector<std::string> ShapeDesign::Explode(const std::string & str, char separator )
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
