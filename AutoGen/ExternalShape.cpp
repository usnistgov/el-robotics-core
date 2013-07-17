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

#include "ExternalShape.h"


 #include "SolidObject.h"
 #include "DAO.h"

ExternalShape::ExternalShape(std::string name) : ShapeDesign(name){
dao = NULL;

}ExternalShape::~ExternalShape(){
for(std::size_t i = 0; i < hasSolidObject_ExternalShape.size(); i++)
delete(hasSolidObject_ExternalShape[i]);
}
std::string ExternalShape::gethasExternalShape_ModelTypeName(){
return hasExternalShape_ModelTypeName;
}
std::string ExternalShape::gethasExternalShape_ModelName(){
return hasExternalShape_ModelName;
}
std::string ExternalShape::gethasExternalShape_ModelFileName(){
return hasExternalShape_ModelFileName;
}
int ExternalShape::getExternalShapeID(){
return ExternalShapeID;
}
DAO* ExternalShape::getdao(){
return dao;
}
std::vector<SolidObject*> ExternalShape::gethasSolidObject_ExternalShape(){
return hasSolidObject_ExternalShape;
}
void ExternalShape::sethasExternalShape_ModelTypeName(std::string _hasExternalShape_ModelTypeName){
this->hasExternalShape_ModelTypeName= _hasExternalShape_ModelTypeName;
}
void ExternalShape::sethasExternalShape_ModelName(std::string _hasExternalShape_ModelName){
this->hasExternalShape_ModelName= _hasExternalShape_ModelName;
}
void ExternalShape::sethasExternalShape_ModelFileName(std::string _hasExternalShape_ModelFileName){
this->hasExternalShape_ModelFileName= _hasExternalShape_ModelFileName;
}
void ExternalShape::setdao(DAO* _dao){
this->dao= _dao;
}
void ExternalShape::sethasSolidObject_ExternalShape(std::vector<SolidObject*> _hasSolidObject_ExternalShape){
this->hasSolidObject_ExternalShape= _hasSolidObject_ExternalShape;
}
void ExternalShape::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("ShapeDesign");
 temp = dao->get(name);delete (dao);
 ShapeDesign::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("ExternalShape");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void ExternalShape::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
ShapeDesign* temp0 = (ShapeDesign*) this;
temp0->set(name);
DataThing* temp1 = (DataThing*) this;
temp1->set(name);
data["hasExternalShape_ModelTypeName"]=hasExternalShape_ModelTypeName;
data["hasExternalShape_ModelName"]=hasExternalShape_ModelName;
data["hasExternalShape_ModelFileName"]=hasExternalShape_ModelFileName;
data["name"]=name;
ss.str("");
ss << ExternalShapeID;
data["ExternalShapeID"]=ss.str();
for(unsigned int i=0;i<hasSolidObject_ExternalShape.size();++i){
ss.str("");
hasSolidObject_ExternalShape[i]->get(hasSolidObject_ExternalShape[i]->getname());
ss << hasSolidObject_ExternalShape[i]->getSolidObjectID();
data["hasSolidObject_ExternalShape"]=data["hasSolidObject_ExternalShape"]+" "+ss.str();
}
dao  = new DAO("ExternalShape");
dao->set(data);
delete (dao);
}

void ExternalShape::copy(std::map<std::string,std::string> object){for(std::size_t i = 0; i < hasSolidObject_ExternalShape.size(); i++){
delete(hasSolidObject_ExternalShape[i]);
hasSolidObject_ExternalShape[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<ExternalShape*> tmp;
this->hasExternalShape_ModelTypeName = object["ExternalShape.hasExternalShape_ModelTypeName"];
this->hasExternalShape_ModelName = object["ExternalShape.hasExternalShape_ModelName"];
this->hasExternalShape_ModelFileName = object["ExternalShape.hasExternalShape_ModelFileName"];
this->name = object["ExternalShape._NAME"];
this->ExternalShapeID = std::atof(object["ExternalShape.ExternalShapeID"].c_str());
if(this->hasSolidObject_ExternalShape.empty() && object["hasSolidObject_ExternalShape/SolidObject._NAME"]!=""){
temp = Explode(object["hasSolidObject_ExternalShape/SolidObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSolidObject_ExternalShape.push_back(new SolidObject(temp[i]));
}
}

}std::vector<std::string> ExternalShape::Explode(const std::string & str, char separator )
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
