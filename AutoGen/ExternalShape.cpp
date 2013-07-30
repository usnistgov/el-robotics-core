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


 #include "DAO.h"
 #include "SolidObject.h"

ExternalShape::ExternalShape(std::string name) : ShapeDesign(name){
dao = NULL;
hadByExternalShape_SolidObject = NULL;

}ExternalShape::~ExternalShape(){
delete(hadByExternalShape_SolidObject);
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
SolidObject* ExternalShape::gethadByExternalShape_SolidObject(){
return hadByExternalShape_SolidObject;
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
void ExternalShape::setExternalShapeID(int _ExternalShapeID){
this->ExternalShapeID= _ExternalShapeID;
}
void ExternalShape::setdao(DAO* _dao){
this->dao= _dao;
}
void ExternalShape::sethadByExternalShape_SolidObject(SolidObject* _hadByExternalShape_SolidObject){
this->hadByExternalShape_SolidObject= _hadByExternalShape_SolidObject;
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
data["hasExternalShape_ModelTypeName"]="'" + hasExternalShape_ModelTypeName + "'";
data["hasExternalShape_ModelName"]="'" + hasExternalShape_ModelName + "'";
data["hasExternalShape_ModelFileName"]="'" + hasExternalShape_ModelFileName + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << ExternalShapeID;
data["ExternalShapeID"]=ss.str();
if(hadByExternalShape_SolidObject!=NULL)
data["hadByExternalShape_SolidObject"]=hadByExternalShape_SolidObject->getname();
dao  = new DAO("ExternalShape");
dao->set(data);
delete (dao);
}
void ExternalShape::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp1 = (DataThing*) this;
temp1->insert(name);
temp1->get(name);
ShapeDesign* temp0 = (ShapeDesign*) this;
temp0->setShapeDesignID(temp1->getDataThingID());
temp0->insert(name);
data["hasExternalShape_ModelTypeName"]="'" + hasExternalShape_ModelTypeName+ "'";
data["hasExternalShape_ModelName"]="'" + hasExternalShape_ModelName+ "'";
data["hasExternalShape_ModelFileName"]="'" + hasExternalShape_ModelFileName+ "'";
ss.str("");
ss << temp1->getDataThingID();
data["ExternalShapeID"]=ss.str();
if(hadByExternalShape_SolidObject!=NULL)
data["hadByExternalShape_SolidObject"]=hadByExternalShape_SolidObject->getname();
dao  = new DAO("ExternalShape");
dao->insert(data);
delete (dao);
this->set(name);
}

void ExternalShape::copy(std::map<std::string,std::string> object){delete(hadByExternalShape_SolidObject);
hadByExternalShape_SolidObject=NULL;
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
if(this->hadByExternalShape_SolidObject== NULL && object["hadByExternalShape_SolidObject/SolidObject._NAME"]!=""){
this->hadByExternalShape_SolidObject = new SolidObject(object["hadByExternalShape_SolidObject/SolidObject._NAME"]);
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
