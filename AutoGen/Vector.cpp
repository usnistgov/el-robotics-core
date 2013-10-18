/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "Vector.h"


 #include "DAO.h"
 #include "PoseLocation.h"
 #include "PartRefAndPose.h"

Vector::Vector(std::string name) : DataThing(name){
dao = NULL;
hasPoseLocation_XAxis = NULL;
hasPoseLocation_ZAxis = NULL;
hasPartRefAndPose_ZAxis = NULL;
hasPartRefAndPose_XAxis = NULL;

}Vector::~Vector(){
delete(hasPoseLocation_XAxis);
delete(hasPoseLocation_ZAxis);
delete(hasPartRefAndPose_ZAxis);
delete(hasPartRefAndPose_XAxis);
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
int Vector::getVectorID(){
return VectorID;
}
DAO* Vector::getdao(){
return dao;
}
PoseLocation* Vector::gethasPoseLocation_XAxis(){
return hasPoseLocation_XAxis;
}
PoseLocation* Vector::gethasPoseLocation_ZAxis(){
return hasPoseLocation_ZAxis;
}
PartRefAndPose* Vector::gethasPartRefAndPose_ZAxis(){
return hasPartRefAndPose_ZAxis;
}
PartRefAndPose* Vector::gethasPartRefAndPose_XAxis(){
return hasPartRefAndPose_XAxis;
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
void Vector::setVectorID(int _VectorID){
this->VectorID= _VectorID;
}
void Vector::setdao(DAO* _dao){
this->dao= _dao;
}
void Vector::sethasPoseLocation_XAxis(PoseLocation* _hasPoseLocation_XAxis){
this->hasPoseLocation_XAxis= _hasPoseLocation_XAxis;
}
void Vector::sethasPoseLocation_ZAxis(PoseLocation* _hasPoseLocation_ZAxis){
this->hasPoseLocation_ZAxis= _hasPoseLocation_ZAxis;
}
void Vector::sethasPartRefAndPose_ZAxis(PartRefAndPose* _hasPartRefAndPose_ZAxis){
this->hasPartRefAndPose_ZAxis= _hasPartRefAndPose_ZAxis;
}
void Vector::sethasPartRefAndPose_XAxis(PartRefAndPose* _hasPartRefAndPose_XAxis){
this->hasPartRefAndPose_XAxis= _hasPartRefAndPose_XAxis;
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
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
ss.str("");
ss << hasVector_K;
data["hasVector_K"]=ss.str();
ss.str("");
ss << hasVector_J;
data["hasVector_J"]=ss.str();
ss.str("");
ss << hasVector_I;
data["hasVector_I"]=ss.str();
data["name"]="'" + name + "'";
ss.str("");
ss << VectorID;
data["VectorID"]=ss.str();
if(hasPoseLocation_XAxis!=NULL)
data["hasPoseLocation_XAxis"]="'" +hasPoseLocation_XAxis->getname() + "'";
else 
 data["hasPoseLocation_XAxis"]="null";
if(hasPoseLocation_ZAxis!=NULL)
data["hasPoseLocation_ZAxis"]="'" +hasPoseLocation_ZAxis->getname() + "'";
else 
 data["hasPoseLocation_ZAxis"]="null";
if(hasPartRefAndPose_ZAxis!=NULL)
data["hasPartRefAndPose_ZAxis"]="'" +hasPartRefAndPose_ZAxis->getname() + "'";
else 
 data["hasPartRefAndPose_ZAxis"]="null";
if(hasPartRefAndPose_XAxis!=NULL)
data["hasPartRefAndPose_XAxis"]="'" +hasPartRefAndPose_XAxis->getname() + "'";
else 
 data["hasPartRefAndPose_XAxis"]="null";
dao  = new DAO("Vector");
dao->set(data);
delete (dao);
}
void Vector::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << hasVector_K;
data["hasVector_K"]=ss.str();
ss.str("");
ss << hasVector_J;
data["hasVector_J"]=ss.str();
ss.str("");
ss << hasVector_I;
data["hasVector_I"]=ss.str();
ss.str("");
ss << temp0->getDataThingID();
data["VectorID"]=ss.str();
if(hasPoseLocation_XAxis!=NULL)
data["hasPoseLocation_XAxis"]="'" + hasPoseLocation_XAxis->getname() + "'";
if(hasPoseLocation_ZAxis!=NULL)
data["hasPoseLocation_ZAxis"]="'" + hasPoseLocation_ZAxis->getname() + "'";
if(hasPartRefAndPose_ZAxis!=NULL)
data["hasPartRefAndPose_ZAxis"]="'" + hasPartRefAndPose_ZAxis->getname() + "'";
if(hasPartRefAndPose_XAxis!=NULL)
data["hasPartRefAndPose_XAxis"]="'" + hasPartRefAndPose_XAxis->getname() + "'";
dao  = new DAO("Vector");
dao->insert(data);
delete (dao);
this->set(name);
}

void Vector::copy(std::map<std::string,std::string> object){hasPoseLocation_XAxis=NULL;
hasPoseLocation_ZAxis=NULL;
hasPartRefAndPose_ZAxis=NULL;
hasPartRefAndPose_XAxis=NULL;
std::vector<std::string> temp;
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
if(this->hasPoseLocation_XAxis== NULL && object["hasPoseLocation_XAxis/PoseLocation._NAME"]!=""){
this->hasPoseLocation_XAxis = new PoseLocation(object["hasPoseLocation_XAxis/PoseLocation._NAME"]);
}
if(this->hasPoseLocation_ZAxis== NULL && object["hasPoseLocation_ZAxis/PoseLocation._NAME"]!=""){
this->hasPoseLocation_ZAxis = new PoseLocation(object["hasPoseLocation_ZAxis/PoseLocation._NAME"]);
}
if(this->hasPartRefAndPose_ZAxis== NULL && object["hasPartRefAndPose_ZAxis/PartRefAndPose._NAME"]!=""){
this->hasPartRefAndPose_ZAxis = new PartRefAndPose(object["hasPartRefAndPose_ZAxis/PartRefAndPose._NAME"]);
}
if(this->hasPartRefAndPose_XAxis== NULL && object["hasPartRefAndPose_XAxis/PartRefAndPose._NAME"]!=""){
this->hasPartRefAndPose_XAxis = new PartRefAndPose(object["hasPartRefAndPose_XAxis/PartRefAndPose._NAME"]);
}

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
