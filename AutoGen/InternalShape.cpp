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

#include "InternalShape.h"


 #include "DAO.h"
 #include "SolidObject.h"

InternalShape::InternalShape(std::string name) : ShapeDesign(name){
dao = NULL;
hadByInternalShape_SolidObject = NULL;

}InternalShape::~InternalShape(){
delete(hadByInternalShape_SolidObject);
}
int InternalShape::getInternalShapeID(){
return InternalShapeID;
}
DAO* InternalShape::getdao(){
return dao;
}
SolidObject* InternalShape::gethadByInternalShape_SolidObject(){
return hadByInternalShape_SolidObject;
}
void InternalShape::setdao(DAO* _dao){
this->dao= _dao;
}
void InternalShape::sethadByInternalShape_SolidObject(SolidObject* _hadByInternalShape_SolidObject){
this->hadByInternalShape_SolidObject= _hadByInternalShape_SolidObject;
}
void InternalShape::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("ShapeDesign");
 temp = dao->get(name);delete (dao);
 ShapeDesign::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("InternalShape");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void InternalShape::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
ShapeDesign* temp0 = (ShapeDesign*) this;
temp0->set(name);
DataThing* temp1 = (DataThing*) this;
temp1->set(name);
data["name"]=name;
ss.str("");
ss << InternalShapeID;
data["InternalShapeID"]=ss.str();
if(hadByInternalShape_SolidObject!=NULL)
data["hadByInternalShape_SolidObject"]=hadByInternalShape_SolidObject->getname();
dao  = new DAO("InternalShape");
dao->set(data);
delete (dao);
}

void InternalShape::copy(std::map<std::string,std::string> object){delete(hadByInternalShape_SolidObject);
hadByInternalShape_SolidObject=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<InternalShape*> tmp;
this->name = object["InternalShape._NAME"];
this->InternalShapeID = std::atof(object["InternalShape.InternalShapeID"].c_str());
if(this->hadByInternalShape_SolidObject== NULL && object["hadByInternalShape_SolidObject/SolidObject._NAME"]!=""){
this->hadByInternalShape_SolidObject = new SolidObject(object["hadByInternalShape_SolidObject/SolidObject._NAME"]);
}

}std::vector<std::string> InternalShape::Explode(const std::string & str, char separator )
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
