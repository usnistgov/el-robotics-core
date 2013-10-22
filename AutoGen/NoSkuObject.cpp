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

#include "NoSkuObject.h"


 #include "ExternalShape.h"
 #include "DAO.h"
 #include "InternalShape.h"

NoSkuObject::NoSkuObject(std::string name) : SolidObject(name){
dao = NULL;
hasNoSkuObject_InternalShape = NULL;
hadByExternalShape_NoSkuObject = NULL;

}NoSkuObject::~NoSkuObject(){
delete(hasNoSkuObject_InternalShape);
delete(hadByExternalShape_NoSkuObject);
}
int NoSkuObject::getNoSkuObjectID(){
return NoSkuObjectID;
}
DAO* NoSkuObject::getdao(){
return dao;
}
InternalShape* NoSkuObject::gethasNoSkuObject_InternalShape(){
return hasNoSkuObject_InternalShape;
}
ExternalShape* NoSkuObject::gethadByExternalShape_NoSkuObject(){
return hadByExternalShape_NoSkuObject;
}
void NoSkuObject::setNoSkuObjectID(int _NoSkuObjectID){
this->NoSkuObjectID= _NoSkuObjectID;
}
void NoSkuObject::setdao(DAO* _dao){
this->dao= _dao;
}
void NoSkuObject::sethasNoSkuObject_InternalShape(InternalShape* _hasNoSkuObject_InternalShape){
this->hasNoSkuObject_InternalShape= _hasNoSkuObject_InternalShape;
}
void NoSkuObject::sethadByExternalShape_NoSkuObject(ExternalShape* _hadByExternalShape_NoSkuObject){
this->hadByExternalShape_NoSkuObject= _hadByExternalShape_NoSkuObject;
}
void NoSkuObject::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("NoSkuObject");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void NoSkuObject::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << NoSkuObjectID;
data["NoSkuObjectID"]=ss.str();
if(hasNoSkuObject_InternalShape!=NULL)
data["hasNoSkuObject_InternalShape"]="'" +hasNoSkuObject_InternalShape->getname() + "'";
else 
 data["hasNoSkuObject_InternalShape"]="null";
if(hadByExternalShape_NoSkuObject!=NULL)
data["hadByExternalShape_NoSkuObject"]="'" +hadByExternalShape_NoSkuObject->getname() + "'";
else 
 data["hadByExternalShape_NoSkuObject"]="null";
dao  = new DAO("NoSkuObject");
dao->set(data);
delete (dao);
}
void NoSkuObject::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getSolidObjectID();
data["NoSkuObjectID"]=ss.str();
if(hasNoSkuObject_InternalShape!=NULL)
data["hasNoSkuObject_InternalShape"]="'" + hasNoSkuObject_InternalShape->getname() + "'";
if(hadByExternalShape_NoSkuObject!=NULL)
data["hadByExternalShape_NoSkuObject"]="'" + hadByExternalShape_NoSkuObject->getname() + "'";
dao  = new DAO("NoSkuObject");
dao->insert(data);
delete (dao);
this->set(name);
}

void NoSkuObject::copy(std::map<std::string,std::string> object){hasNoSkuObject_InternalShape=NULL;
hadByExternalShape_NoSkuObject=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<NoSkuObject*> tmp;
this->name = object["NoSkuObject._NAME"];
this->NoSkuObjectID = std::atof(object["NoSkuObject.NoSkuObjectID"].c_str());
if(this->hasNoSkuObject_InternalShape== NULL && object["hasNoSkuObject_InternalShape/InternalShape._NAME"]!=""){
this->hasNoSkuObject_InternalShape = new InternalShape(object["hasNoSkuObject_InternalShape/InternalShape._NAME"]);
}
if(this->hadByExternalShape_NoSkuObject== NULL && object["hadByExternalShape_NoSkuObject/ExternalShape._NAME"]!=""){
this->hadByExternalShape_NoSkuObject = new ExternalShape(object["hadByExternalShape_NoSkuObject/ExternalShape._NAME"]);
}

}std::vector<std::string> NoSkuObject::Explode(const std::string & str, char separator )
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
