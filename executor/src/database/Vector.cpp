#include "Vector.h"


 #include "DAO.h"
 #include "PartRefAndPose.h"
 #include "PoseLocation.h"

Vector::Vector(std::string name) : DataThing(name){
this->name=name;dao = NULL;

}Vector::~Vector(){
delete(dao);
for(std::size_t i = 0; i < hasPartRefAndPose_ZAxis.size(); i++)
delete(hasPartRefAndPose_ZAxis[i]);
for(std::size_t i = 0; i < hasPartRefAndPose_XAxis.size(); i++)
delete(hasPartRefAndPose_XAxis[i]);
for(std::size_t i = 0; i < hasPoseLocation_ZAxis.size(); i++)
delete(hasPoseLocation_ZAxis[i]);
for(std::size_t i = 0; i < hasPoseLocation_XAxis.size(); i++)
delete(hasPoseLocation_XAxis[i]);
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
std::vector<PartRefAndPose*>* Vector::gethasPartRefAndPose_ZAxis(){
return &hasPartRefAndPose_ZAxis;
}
std::vector<PartRefAndPose*>* Vector::gethasPartRefAndPose_XAxis(){
return &hasPartRefAndPose_XAxis;
}
std::vector<PoseLocation*>* Vector::gethasPoseLocation_ZAxis(){
return &hasPoseLocation_ZAxis;
}
std::vector<PoseLocation*>* Vector::gethasPoseLocation_XAxis(){
return &hasPoseLocation_XAxis;
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
void Vector::sethasPartRefAndPose_ZAxis(std::vector<PartRefAndPose*> _hasPartRefAndPose_ZAxis){
this->hasPartRefAndPose_ZAxis= _hasPartRefAndPose_ZAxis;
}
void Vector::sethasPartRefAndPose_XAxis(std::vector<PartRefAndPose*> _hasPartRefAndPose_XAxis){
this->hasPartRefAndPose_XAxis= _hasPartRefAndPose_XAxis;
}
void Vector::sethasPoseLocation_ZAxis(std::vector<PoseLocation*> _hasPoseLocation_ZAxis){
this->hasPoseLocation_ZAxis= _hasPoseLocation_ZAxis;
}
void Vector::sethasPoseLocation_XAxis(std::vector<PoseLocation*> _hasPoseLocation_XAxis){
this->hasPoseLocation_XAxis= _hasPoseLocation_XAxis;
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
for(unsigned int i=0;i<hasPartRefAndPose_ZAxis.size();++i){
ss.flush();
ss << hasPartRefAndPose_ZAxis[i]->getPartRefAndPoseID();
data["hasPartRefAndPose_ZAxis"]=data["hasPartRefAndPose_ZAxis"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartRefAndPose_XAxis.size();++i){
ss.flush();
ss << hasPartRefAndPose_XAxis[i]->getPartRefAndPoseID();
data["hasPartRefAndPose_XAxis"]=data["hasPartRefAndPose_XAxis"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPoseLocation_ZAxis.size();++i){
ss.flush();
ss << hasPoseLocation_ZAxis[i]->getPoseLocationID();
data["hasPoseLocation_ZAxis"]=data["hasPoseLocation_ZAxis"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPoseLocation_XAxis.size();++i){
ss.flush();
ss << hasPoseLocation_XAxis[i]->getPoseLocationID();
data["hasPoseLocation_XAxis"]=data["hasPoseLocation_XAxis"]+" "+ss.str();
}
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
if(this->hasPartRefAndPose_ZAxis.empty() && object["hasPartRefAndPose_ZAxis/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hasPartRefAndPose_ZAxis/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartRefAndPose_ZAxis.push_back(new PartRefAndPose(temp[i]));
}
}
if(this->hasPartRefAndPose_XAxis.empty() && object["hasPartRefAndPose_XAxis/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hasPartRefAndPose_XAxis/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartRefAndPose_XAxis.push_back(new PartRefAndPose(temp[i]));
}
}
if(this->hasPoseLocation_ZAxis.empty() && object["hasPoseLocation_ZAxis/PoseLocation._NAME"]!=""){
temp = Explode(object["hasPoseLocation_ZAxis/PoseLocation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPoseLocation_ZAxis.push_back(new PoseLocation(temp[i]));
}
}
if(this->hasPoseLocation_XAxis.empty() && object["hasPoseLocation_XAxis/PoseLocation._NAME"]!=""){
temp = Explode(object["hasPoseLocation_XAxis/PoseLocation._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPoseLocation_XAxis.push_back(new PoseLocation(temp[i]));
}
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
