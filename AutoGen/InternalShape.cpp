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


 #include "StockKeepingUnit.h"
 #include "NoSkuObject.h"
 #include "DAO.h"

InternalShape::InternalShape(std::string name) : ShapeDesign(name){
dao = NULL;
hasStockKeepingUnit_InternalShape = NULL;
hasNoSkuObject_InternalShape = NULL;

}InternalShape::~InternalShape(){
delete(hasStockKeepingUnit_InternalShape);
delete(hasNoSkuObject_InternalShape);
}
int InternalShape::getInternalShapeID(){
return InternalShapeID;
}
DAO* InternalShape::getdao(){
return dao;
}
StockKeepingUnit* InternalShape::gethasStockKeepingUnit_InternalShape(){
return hasStockKeepingUnit_InternalShape;
}
NoSkuObject* InternalShape::gethasNoSkuObject_InternalShape(){
return hasNoSkuObject_InternalShape;
}
void InternalShape::setInternalShapeID(int _InternalShapeID){
this->InternalShapeID= _InternalShapeID;
}
void InternalShape::setdao(DAO* _dao){
this->dao= _dao;
}
void InternalShape::sethasStockKeepingUnit_InternalShape(StockKeepingUnit* _hasStockKeepingUnit_InternalShape){
this->hasStockKeepingUnit_InternalShape= _hasStockKeepingUnit_InternalShape;
}
void InternalShape::sethasNoSkuObject_InternalShape(NoSkuObject* _hasNoSkuObject_InternalShape){
this->hasNoSkuObject_InternalShape= _hasNoSkuObject_InternalShape;
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
data["name"]="'" + name + "'";
ss.str("");
ss << InternalShapeID;
data["InternalShapeID"]=ss.str();
if(hasStockKeepingUnit_InternalShape!=NULL)
data["hasStockKeepingUnit_InternalShape"]="'" +hasStockKeepingUnit_InternalShape->getname() + "'";
else 
 data["hasStockKeepingUnit_InternalShape"]="null";
if(hasNoSkuObject_InternalShape!=NULL)
data["hasNoSkuObject_InternalShape"]="'" +hasNoSkuObject_InternalShape->getname() + "'";
else 
 data["hasNoSkuObject_InternalShape"]="null";
dao  = new DAO("InternalShape");
dao->set(data);
delete (dao);
}
void InternalShape::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp1 = (DataThing*) this;
temp1->insert(name);
temp1->get(name);
ShapeDesign* temp0 = (ShapeDesign*) this;
temp0->setShapeDesignID(temp1->getDataThingID());
temp0->insert(name);
ss.str("");
ss << temp1->getDataThingID();
data["InternalShapeID"]=ss.str();
if(hasStockKeepingUnit_InternalShape!=NULL)
data["hasStockKeepingUnit_InternalShape"]="'" + hasStockKeepingUnit_InternalShape->getname() + "'";
if(hasNoSkuObject_InternalShape!=NULL)
data["hasNoSkuObject_InternalShape"]="'" + hasNoSkuObject_InternalShape->getname() + "'";
dao  = new DAO("InternalShape");
dao->insert(data);
delete (dao);
this->set(name);
}

void InternalShape::copy(std::map<std::string,std::string> object){hasStockKeepingUnit_InternalShape=NULL;
hasNoSkuObject_InternalShape=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<InternalShape*> tmp;
this->name = object["InternalShape._NAME"];
this->InternalShapeID = std::atof(object["InternalShape.InternalShapeID"].c_str());
if(this->hasStockKeepingUnit_InternalShape== NULL && object["hasStockKeepingUnit_InternalShape/StockKeepingUnit._NAME"]!=""){
this->hasStockKeepingUnit_InternalShape = new StockKeepingUnit(object["hasStockKeepingUnit_InternalShape/StockKeepingUnit._NAME"]);
}
if(this->hasNoSkuObject_InternalShape== NULL && object["hasNoSkuObject_InternalShape/NoSkuObject._NAME"]!=""){
this->hasNoSkuObject_InternalShape = new NoSkuObject(object["hasNoSkuObject_InternalShape/NoSkuObject._NAME"]);
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
