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

#include "ShapeDesign.h"


 #include "StockKeepingUnit.h"
 #include "DAO.h"
 #include "PoseLocation.h"

ShapeDesign::ShapeDesign(std::string name) : DataThing(name){
dao = NULL;
hadByGraspPose_ShapeDesign = NULL;
hasStockKeepingUnit_Shape = NULL;

}ShapeDesign::~ShapeDesign(){
delete(hadByGraspPose_ShapeDesign);
delete(hasStockKeepingUnit_Shape);
}
std::string ShapeDesign::gethasShapeDesign_Description(){
return hasShapeDesign_Description;
}
int ShapeDesign::getShapeDesignID(){
return ShapeDesignID;
}
DAO* ShapeDesign::getdao(){
return dao;
}
PoseLocation* ShapeDesign::gethadByGraspPose_ShapeDesign(){
return hadByGraspPose_ShapeDesign;
}
StockKeepingUnit* ShapeDesign::gethasStockKeepingUnit_Shape(){
return hasStockKeepingUnit_Shape;
}
void ShapeDesign::sethasShapeDesign_Description(std::string _hasShapeDesign_Description){
this->hasShapeDesign_Description= _hasShapeDesign_Description;
}
void ShapeDesign::setShapeDesignID(int _ShapeDesignID){
this->ShapeDesignID= _ShapeDesignID;
}
void ShapeDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void ShapeDesign::sethadByGraspPose_ShapeDesign(PoseLocation* _hadByGraspPose_ShapeDesign){
this->hadByGraspPose_ShapeDesign= _hadByGraspPose_ShapeDesign;
}
void ShapeDesign::sethasStockKeepingUnit_Shape(StockKeepingUnit* _hasStockKeepingUnit_Shape){
this->hasStockKeepingUnit_Shape= _hasStockKeepingUnit_Shape;
}
void ShapeDesign::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("ShapeDesign");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void ShapeDesign::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["hasShapeDesign_Description"]="'" + hasShapeDesign_Description + "'";
data["name"]="'" + name + "'";
ss.str("");
ss << ShapeDesignID;
data["ShapeDesignID"]=ss.str();
if(hadByGraspPose_ShapeDesign!=NULL)
data["hadByGraspPose_ShapeDesign"]="'" +hadByGraspPose_ShapeDesign->getname() + "'";
else 
 data["hadByGraspPose_ShapeDesign"]="null";
if(hasStockKeepingUnit_Shape!=NULL)
data["hasStockKeepingUnit_Shape"]="'" +hasStockKeepingUnit_Shape->getname() + "'";
else 
 data["hasStockKeepingUnit_Shape"]="null";
dao  = new DAO("ShapeDesign");
dao->set(data);
delete (dao);
}
void ShapeDesign::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
data["hasShapeDesign_Description"]="'" + hasShapeDesign_Description+ "'";
ss.str("");
ss << temp0->getDataThingID();
data["ShapeDesignID"]=ss.str();
if(hadByGraspPose_ShapeDesign!=NULL)
data["hadByGraspPose_ShapeDesign"]="'" + hadByGraspPose_ShapeDesign->getname() + "'";
if(hasStockKeepingUnit_Shape!=NULL)
data["hasStockKeepingUnit_Shape"]="'" + hasStockKeepingUnit_Shape->getname() + "'";
dao  = new DAO("ShapeDesign");
dao->insert(data);
delete (dao);
this->set(name);
}

void ShapeDesign::copy(std::map<std::string,std::string> object){delete(hadByGraspPose_ShapeDesign);
hadByGraspPose_ShapeDesign=NULL;
delete(hasStockKeepingUnit_Shape);
hasStockKeepingUnit_Shape=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<ShapeDesign*> tmp;
this->hasShapeDesign_Description = object["ShapeDesign.hasShapeDesign_Description"];
this->name = object["ShapeDesign._NAME"];
this->ShapeDesignID = std::atof(object["ShapeDesign.ShapeDesignID"].c_str());
if(this->hadByGraspPose_ShapeDesign== NULL && object["hadByGraspPose_ShapeDesign/PoseLocation._NAME"]!=""){
this->hadByGraspPose_ShapeDesign = new PoseLocation(object["hadByGraspPose_ShapeDesign/PoseLocation._NAME"]);
}
if(this->hasStockKeepingUnit_Shape== NULL && object["hasStockKeepingUnit_Shape/StockKeepingUnit._NAME"]!=""){
this->hasStockKeepingUnit_Shape = new StockKeepingUnit(object["hasStockKeepingUnit_Shape/StockKeepingUnit._NAME"]);
}

}std::vector<std::string> ShapeDesign::Explode(const std::string & str, char separator )
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
