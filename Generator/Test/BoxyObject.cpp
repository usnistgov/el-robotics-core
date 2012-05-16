#include "BoxyObject.h"

BoxyObject::BoxyObject(std::string name) : SolidObject(name){
this->name=name;
}BoxyObject::~BoxyObject(){
delete(dao);
}
double BoxyObject::gethasBox_Width(){
return this->hasBox_Width;
}
double BoxyObject::gethasBox_Height(){
return this->hasBox_Height;
}
double BoxyObject::gethasBox_Length(){
return this->hasBox_Length;
}
std::string BoxyObject::getname(){
return this->name;
}
int BoxyObject::getBoxyObjectID(){
return this->BoxyObjectID;
}
DAO* BoxyObject::getdao(){
return this->dao;
}
void BoxyObject::sethasBox_Width(double _hasBox_Width){
this->hasBox_Width= _hasBox_Width;
}
void BoxyObject::sethasBox_Height(double _hasBox_Height){
this->hasBox_Height= _hasBox_Height;
}
void BoxyObject::sethasBox_Length(double _hasBox_Length){
this->hasBox_Length= _hasBox_Length;
}
void BoxyObject::setname(std::string _name){
this->name= _name;
}
void BoxyObject::setBoxyObjectID(int _BoxyObjectID){
this->BoxyObjectID= _BoxyObjectID;
}
void BoxyObject::setdao(DAO* _dao){
this->dao= _dao;
}
void BoxyObject::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);
 SolidObject::copy(temp);
delete (dao);
dao  = new DAO("BoxyObject");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void BoxyObject::set(std::string name){
 dao  = new DAO("BoxyObject");
 dao->set(name);
delete (dao);
}

void BoxyObject::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasBox_Width = std::atof(object["BoxyObject.hasBox_Width"].c_str());
this->hasBox_Height = std::atof(object["BoxyObject.hasBox_Height"].c_str());
this->hasBox_Length = std::atof(object["BoxyObject.hasBox_Length"].c_str());
this->name = object["BoxyObject._NAME"];
this->BoxyObjectID = std::atof(object["BoxyObject.BoxyObjectID"].c_str());

}std::vector<std::string> BoxyObject::Explode(const std::string & str, char separator )
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
