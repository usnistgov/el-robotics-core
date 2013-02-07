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
void ShapeDesign::printMe()
{
  std::cout << "ShapeDesign's printMe() function should be overwritten\n";
}

ShapeDesign::ShapeDesign(std::string name) : DataThing(name){
dao = NULL;
hasShapeDesign_GraspPose = NULL;

}ShapeDesign::~ShapeDesign(){
delete(hasShapeDesign_GraspPose);
for(std::size_t i = 0; i < hasSku_Shape.size(); i++)
delete(hasSku_Shape[i]);
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
PoseLocation* ShapeDesign::gethasShapeDesign_GraspPose(){
return hasShapeDesign_GraspPose;
}
std::vector<StockKeepingUnit*> ShapeDesign::gethasSku_Shape(){
return hasSku_Shape;
}
void ShapeDesign::sethasShapeDesign_Description(std::string _hasShapeDesign_Description){
this->hasShapeDesign_Description= _hasShapeDesign_Description;
}
void ShapeDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void ShapeDesign::sethasShapeDesign_GraspPose(PoseLocation* _hasShapeDesign_GraspPose){
this->hasShapeDesign_GraspPose= _hasShapeDesign_GraspPose;
}
void ShapeDesign::sethasSku_Shape(std::vector<StockKeepingUnit*> _hasSku_Shape){
this->hasSku_Shape= _hasSku_Shape;
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
data["hasShapeDesign_Description"]=hasShapeDesign_Description;
data["name"]=name;
ss.str("");
ss << ShapeDesignID;
data["ShapeDesignID"]=ss.str();
if(hasShapeDesign_GraspPose!=NULL)
data["hasShapeDesign_GraspPose"]=hasShapeDesign_GraspPose->getname();
for(unsigned int i=0;i<hasSku_Shape.size();++i){
ss.str("");
hasSku_Shape[i]->get(hasSku_Shape[i]->getname());
ss << hasSku_Shape[i]->getStockKeepingUnitID();
data["hasSku_Shape"]=data["hasSku_Shape"]+" "+ss.str();
}
dao  = new DAO("ShapeDesign");
dao->set(data);
delete (dao);
}

void ShapeDesign::copy(std::map<std::string,std::string> object){delete(hasShapeDesign_GraspPose);
hasShapeDesign_GraspPose=NULL;
for(std::size_t i = 0; i < hasSku_Shape.size(); i++){
delete(hasSku_Shape[i]);
hasSku_Shape[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<ShapeDesign*> tmp;
this->hasShapeDesign_Description = object["ShapeDesign.hasShapeDesign_Description"];
this->name = object["ShapeDesign._NAME"];
this->ShapeDesignID = std::atof(object["ShapeDesign.ShapeDesignID"].c_str());
if(this->hasShapeDesign_GraspPose== NULL && object["hasShapeDesign_GraspPose/PoseLocation._NAME"]!=""){
this->hasShapeDesign_GraspPose = new PoseLocation(object["hasShapeDesign_GraspPose/PoseLocation._NAME"]);
}
if(this->hasSku_Shape.empty() && object["hasSku_Shape/StockKeepingUnit._NAME"]!=""){
temp = Explode(object["hasSku_Shape/StockKeepingUnit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSku_Shape.push_back(new StockKeepingUnit(temp[i]));
}
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
