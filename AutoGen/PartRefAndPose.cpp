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

#include "PartRefAndPose.h"


 #include "StockKeepingUnit.h"
 #include "Slot.h"
 #include "DAO.h"
 #include "Vector.h"
 #include "KitDesign.h"
 #include "Point.h"

PartRefAndPose::PartRefAndPose(std::string name) : DataThing(name){
dao = NULL;
hasPartRefAndPose_Sku = NULL;
hasPartRefAndPose_ZAxis = NULL;
hadByPartRefAndPose_KitDesign = NULL;
hasPartRefAndPose_Point = NULL;
hasPartRefAndPose_XAxis = NULL;

}PartRefAndPose::~PartRefAndPose(){
delete(hasPartRefAndPose_Sku);
delete(hasPartRefAndPose_ZAxis);
delete(hadByPartRefAndPose_KitDesign);
delete(hasPartRefAndPose_Point);
delete(hasPartRefAndPose_XAxis);
for(std::size_t i = 0; i < hasSlot_PartRefAndPose.size(); i++)
delete(hasSlot_PartRefAndPose[i]);
}
int PartRefAndPose::getPartRefAndPoseID(){
return PartRefAndPoseID;
}
DAO* PartRefAndPose::getdao(){
return dao;
}
StockKeepingUnit* PartRefAndPose::gethasPartRefAndPose_Sku(){
return hasPartRefAndPose_Sku;
}
Vector* PartRefAndPose::gethasPartRefAndPose_ZAxis(){
return hasPartRefAndPose_ZAxis;
}
KitDesign* PartRefAndPose::gethadByPartRefAndPose_KitDesign(){
return hadByPartRefAndPose_KitDesign;
}
Point* PartRefAndPose::gethasPartRefAndPose_Point(){
return hasPartRefAndPose_Point;
}
Vector* PartRefAndPose::gethasPartRefAndPose_XAxis(){
return hasPartRefAndPose_XAxis;
}
std::vector<Slot*> PartRefAndPose::gethasSlot_PartRefAndPose(){
return hasSlot_PartRefAndPose;
}
void PartRefAndPose::setPartRefAndPoseID(int _PartRefAndPoseID){
this->PartRefAndPoseID= _PartRefAndPoseID;
}
void PartRefAndPose::setdao(DAO* _dao){
this->dao= _dao;
}
void PartRefAndPose::sethasPartRefAndPose_Sku(StockKeepingUnit* _hasPartRefAndPose_Sku){
this->hasPartRefAndPose_Sku= _hasPartRefAndPose_Sku;
}
void PartRefAndPose::sethasPartRefAndPose_ZAxis(Vector* _hasPartRefAndPose_ZAxis){
this->hasPartRefAndPose_ZAxis= _hasPartRefAndPose_ZAxis;
}
void PartRefAndPose::sethadByPartRefAndPose_KitDesign(KitDesign* _hadByPartRefAndPose_KitDesign){
this->hadByPartRefAndPose_KitDesign= _hadByPartRefAndPose_KitDesign;
}
void PartRefAndPose::sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point){
this->hasPartRefAndPose_Point= _hasPartRefAndPose_Point;
}
void PartRefAndPose::sethasPartRefAndPose_XAxis(Vector* _hasPartRefAndPose_XAxis){
this->hasPartRefAndPose_XAxis= _hasPartRefAndPose_XAxis;
}
void PartRefAndPose::sethasSlot_PartRefAndPose(std::vector<Slot*> _hasSlot_PartRefAndPose){
this->hasSlot_PartRefAndPose= _hasSlot_PartRefAndPose;
}
void PartRefAndPose::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("PartRefAndPose");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PartRefAndPose::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << PartRefAndPoseID;
data["PartRefAndPoseID"]=ss.str();
if(hasPartRefAndPose_Sku!=NULL)
data["hasPartRefAndPose_Sku"]=hasPartRefAndPose_Sku->getname();
if(hasPartRefAndPose_ZAxis!=NULL)
data["hasPartRefAndPose_ZAxis"]=hasPartRefAndPose_ZAxis->getname();
if(hadByPartRefAndPose_KitDesign!=NULL)
data["hadByPartRefAndPose_KitDesign"]=hadByPartRefAndPose_KitDesign->getname();
if(hasPartRefAndPose_Point!=NULL)
data["hasPartRefAndPose_Point"]=hasPartRefAndPose_Point->getname();
if(hasPartRefAndPose_XAxis!=NULL)
data["hasPartRefAndPose_XAxis"]=hasPartRefAndPose_XAxis->getname();
for(unsigned int i=0;i<hasSlot_PartRefAndPose.size();++i){
ss.str("");
hasSlot_PartRefAndPose[i]->get(hasSlot_PartRefAndPose[i]->getname());
ss << hasSlot_PartRefAndPose[i]->getSlotID();
data["hasSlot_PartRefAndPose"]=data["hasSlot_PartRefAndPose"]+" "+ss.str();
}
dao  = new DAO("PartRefAndPose");
dao->set(data);
delete (dao);
}
void PartRefAndPose::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getDataThingID();
data["PartRefAndPoseID"]=ss.str();
if(hasPartRefAndPose_Sku!=NULL)
data["hasPartRefAndPose_Sku"]=hasPartRefAndPose_Sku->getname();
if(hasPartRefAndPose_ZAxis!=NULL)
data["hasPartRefAndPose_ZAxis"]=hasPartRefAndPose_ZAxis->getname();
if(hadByPartRefAndPose_KitDesign!=NULL)
data["hadByPartRefAndPose_KitDesign"]=hadByPartRefAndPose_KitDesign->getname();
if(hasPartRefAndPose_Point!=NULL)
data["hasPartRefAndPose_Point"]=hasPartRefAndPose_Point->getname();
if(hasPartRefAndPose_XAxis!=NULL)
data["hasPartRefAndPose_XAxis"]=hasPartRefAndPose_XAxis->getname();
dao  = new DAO("PartRefAndPose");
dao->insert(data);
delete (dao);
this->set(name);
}

void PartRefAndPose::copy(std::map<std::string,std::string> object){delete(hasPartRefAndPose_Sku);
hasPartRefAndPose_Sku=NULL;
delete(hasPartRefAndPose_ZAxis);
hasPartRefAndPose_ZAxis=NULL;
delete(hadByPartRefAndPose_KitDesign);
hadByPartRefAndPose_KitDesign=NULL;
delete(hasPartRefAndPose_Point);
hasPartRefAndPose_Point=NULL;
delete(hasPartRefAndPose_XAxis);
hasPartRefAndPose_XAxis=NULL;
for(std::size_t i = 0; i < hasSlot_PartRefAndPose.size(); i++){
delete(hasSlot_PartRefAndPose[i]);
hasSlot_PartRefAndPose[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartRefAndPose*> tmp;
this->name = object["PartRefAndPose._NAME"];
this->PartRefAndPoseID = std::atof(object["PartRefAndPose.PartRefAndPoseID"].c_str());
if(this->hasPartRefAndPose_Sku== NULL && object["hasPartRefAndPose_Sku/StockKeepingUnit._NAME"]!=""){
this->hasPartRefAndPose_Sku = new StockKeepingUnit(object["hasPartRefAndPose_Sku/StockKeepingUnit._NAME"]);
}
if(this->hasPartRefAndPose_ZAxis== NULL && object["hasPartRefAndPose_ZAxis/Vector._NAME"]!=""){
this->hasPartRefAndPose_ZAxis = new Vector(object["hasPartRefAndPose_ZAxis/Vector._NAME"]);
}
if(this->hadByPartRefAndPose_KitDesign== NULL && object["hadByPartRefAndPose_KitDesign/KitDesign._NAME"]!=""){
this->hadByPartRefAndPose_KitDesign = new KitDesign(object["hadByPartRefAndPose_KitDesign/KitDesign._NAME"]);
}
if(this->hasPartRefAndPose_Point== NULL && object["hasPartRefAndPose_Point/Point._NAME"]!=""){
this->hasPartRefAndPose_Point = new Point(object["hasPartRefAndPose_Point/Point._NAME"]);
}
if(this->hasPartRefAndPose_XAxis== NULL && object["hasPartRefAndPose_XAxis/Vector._NAME"]!=""){
this->hasPartRefAndPose_XAxis = new Vector(object["hasPartRefAndPose_XAxis/Vector._NAME"]);
}
if(this->hasSlot_PartRefAndPose.empty() && object["hasSlot_PartRefAndPose/Slot._NAME"]!=""){
temp = Explode(object["hasSlot_PartRefAndPose/Slot._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSlot_PartRefAndPose.push_back(new Slot(temp[i]));
}
}

}std::vector<std::string> PartRefAndPose::Explode(const std::string & str, char separator )
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
