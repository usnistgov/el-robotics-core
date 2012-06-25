#include "Vector.h"


 #include "DAO.h"

Vector::Vector(std::string name) : DataThing(name){
this->name=name;dao = NULL;

}Vector::~Vector(){
delete(dao);
}
double Vector::gethasVector_K(){
return hasVector_K;
}
double Vector::gethasVector_J(){
return hasVector_J;
}
double Vector::gethasVector_I(){
return hasVector_I;
}
std::string Vector::getname(){
return name;
}
int Vector::getVectorID(){
return VectorID;
}
DAO* Vector::getdao(){
return dao;
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
void Vector::setdao(DAO* _dao){
this->dao= _dao;
}
void Vector::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("Vector");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Vector::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["hasVector_K"]=hasVector_K;
data["hasVector_J"]=hasVector_J;
data["hasVector_I"]=hasVector_I;
data["name"]=name;
data["VectorID"]=VectorID;
dao  = new DAO("Vector");
dao->set(data);
delete (dao);
}

void Vector::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Vector*> tmp;
this->hasVector_K = std::atof(object["Vector.hasVector_K"].c_str());
this->hasVector_J = std::atof(object["Vector.hasVector_J"].c_str());
this->hasVector_I = std::atof(object["Vector.hasVector_I"].c_str());
this->name = object["Vector._NAME"];
this->VectorID = std::atof(object["Vector.VectorID"].c_str());

}std::vector<std::string> Vector::Explode(const std::string & str, char separator )
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
