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


 #include "SolidObject.h"
 #include "DAO.h"

InternalShape::InternalShape(std::string name) : ShapeDesign(name){
dao = NULL;

}InternalShape::~InternalShape(){
for(std::size_t i = 0; i < hasSolidObject_InternalShape.size(); i++)
delete(hasSolidObject_InternalShape[i]);
}
int InternalShape::getInternalShapeID(){
return InternalShapeID;
}
DAO* InternalShape::getdao(){
return dao;
}
std::vector<SolidObject*> InternalShape::gethasSolidObject_InternalShape(){
return hasSolidObject_InternalShape;
}
void InternalShape::setdao(DAO* _dao){
this->dao= _dao;
}
void InternalShape::sethasSolidObject_InternalShape(std::vector<SolidObject*> _hasSolidObject_InternalShape){
this->hasSolidObject_InternalShape= _hasSolidObject_InternalShape;
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
for(unsigned int i=0;i<hasSolidObject_InternalShape.size();++i){
ss.str("");
hasSolidObject_InternalShape[i]->get(hasSolidObject_InternalShape[i]->getname());
ss << hasSolidObject_InternalShape[i]->getSolidObjectID();
data["hasSolidObject_InternalShape"]=data["hasSolidObject_InternalShape"]+" "+ss.str();
}
dao  = new DAO("InternalShape");
dao->set(data);
delete (dao);
}

void InternalShape::copy(std::map<std::string,std::string> object){for(std::size_t i = 0; i < hasSolidObject_InternalShape.size(); i++){
delete(hasSolidObject_InternalShape[i]);
hasSolidObject_InternalShape[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<InternalShape*> tmp;
this->name = object["InternalShape._NAME"];
this->InternalShapeID = std::atof(object["InternalShape.InternalShapeID"].c_str());
if(this->hasSolidObject_InternalShape.empty() && object["hasSolidObject_InternalShape/SolidObject._NAME"]!=""){
temp = Explode(object["hasSolidObject_InternalShape/SolidObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSolidObject_InternalShape.push_back(new SolidObject(temp[i]));
}
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
