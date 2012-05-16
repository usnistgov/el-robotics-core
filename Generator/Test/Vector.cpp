#include "Vector.h"

Vector::Vector(std::string name) : DataThing(name){
this->name=name;
}Vector::~Vector(){
delete(dao);
}
double Vector::gethasVector_K(){
return this->hasVector_K;
}
double Vector::gethasVector_J(){
return this->hasVector_J;
}
double Vector::gethasVector_I(){
return this->hasVector_I;
}
std::string Vector::getname(){
return this->name;
}
int Vector::getVectorID(){
return this->VectorID;
}
DAO* Vector::getdao(){
return this->dao;
}
void Vector::sethasVector_K(double _hasVector_K){
this->hasVector_K= _hasVector_K;
}
void Vector::sethasVector_J(double _hasVector_J){
this->hasVector_J= _hasVector_J;
}
void Vector::sethasVector_I(double _hasVector_I){
this->hasVector_I= _hasVector_I;
}
void Vector::setname(std::string _name){
this->name= _name;
}
void Vector::setVectorID(int _VectorID){
this->VectorID= _VectorID;
}
void Vector::setdao(DAO* _dao){
this->dao= _dao;
}
void Vector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("Vector");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void Vector::set(std::string name){
 dao  = new DAO("Vector");
 dao->set(name);
delete (dao);
}

void Vector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasVector_K = std::atof(object["Vector.hasVector_K"].c_str());
this->hasVector_J = std::atof(object["Vector.hasVector_J"].c_str());
this->hasVector_I = std::atof(object["Vector.hasVector_I"].c_str());
this->name = object["Vector._NAME"];
this->VectorID = std::atof(object["Vector.VectorID"].c_str());

}std::vector<std::string> Vector::Explode(const std::string & str, char separator )
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
