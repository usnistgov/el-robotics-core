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

#include "StockKeepingUnit.h"


 #include "KittingWorkstation.h"
 #include "KitDesign.h"
 #include "SkuObject.h"
 #include "ExternalShape.h"
 #include "DAO.h"
 #include "InternalShape.h"
 #include "PartRefAndPose.h"
 #include "EndEffector.h"
 #include "PartsVessel.h"

StockKeepingUnit::StockKeepingUnit(std::string name) : DataThing(name){
dao = NULL;
hadBySku_KittingWorkstation = NULL;
hasStockKeepingUnit_InternalShape = NULL;
hadByExternalShape_StockKeepingUnit = NULL;

}StockKeepingUnit::~StockKeepingUnit(){
delete(hadBySku_KittingWorkstation);
delete(hasStockKeepingUnit_InternalShape);
delete(hadByExternalShape_StockKeepingUnit);
for(std::size_t i = 0; i < hasStockKeepingUnit_EndEffector.size(); i++)
delete(hasStockKeepingUnit_EndEffector[i]);
for(std::size_t i = 0; i < hasPartsVessel_PartSku.size(); i++)
delete(hasPartsVessel_PartSku[i]);
for(std::size_t i = 0; i < hasPartRefAndPose_Sku.size(); i++)
delete(hasPartRefAndPose_Sku[i]);
for(std::size_t i = 0; i < hasKitDesign_KitTraySku.size(); i++)
delete(hasKitDesign_KitTraySku[i]);
for(std::size_t i = 0; i < hasSkuObject_Sku.size(); i++)
delete(hasSkuObject_Sku[i]);
}
std::string StockKeepingUnit::gethasStockKeepingUnit_Description(){
return hasStockKeepingUnit_Description;
}
double StockKeepingUnit::gethasStockKeepingUnit_Weight(){
return hasStockKeepingUnit_Weight;
}
int StockKeepingUnit::getStockKeepingUnitID(){
return StockKeepingUnitID;
}
DAO* StockKeepingUnit::getdao(){
return dao;
}
KittingWorkstation* StockKeepingUnit::gethadBySku_KittingWorkstation(){
return hadBySku_KittingWorkstation;
}
InternalShape* StockKeepingUnit::gethasStockKeepingUnit_InternalShape(){
return hasStockKeepingUnit_InternalShape;
}
ExternalShape* StockKeepingUnit::gethadByExternalShape_StockKeepingUnit(){
return hadByExternalShape_StockKeepingUnit;
}
std::vector<EndEffector*> StockKeepingUnit::gethasStockKeepingUnit_EndEffector(){
return hasStockKeepingUnit_EndEffector;
}
std::vector<PartsVessel*> StockKeepingUnit::gethasPartsVessel_PartSku(){
return hasPartsVessel_PartSku;
}
std::vector<PartRefAndPose*> StockKeepingUnit::gethasPartRefAndPose_Sku(){
return hasPartRefAndPose_Sku;
}
std::vector<KitDesign*> StockKeepingUnit::gethasKitDesign_KitTraySku(){
return hasKitDesign_KitTraySku;
}
std::vector<SkuObject*> StockKeepingUnit::gethasSkuObject_Sku(){
return hasSkuObject_Sku;
}
void StockKeepingUnit::sethasStockKeepingUnit_Description(std::string _hasStockKeepingUnit_Description){
this->hasStockKeepingUnit_Description= _hasStockKeepingUnit_Description;
}
void StockKeepingUnit::sethasStockKeepingUnit_Weight(double _hasStockKeepingUnit_Weight){
this->hasStockKeepingUnit_Weight= _hasStockKeepingUnit_Weight;
}
void StockKeepingUnit::setStockKeepingUnitID(int _StockKeepingUnitID){
this->StockKeepingUnitID= _StockKeepingUnitID;
}
void StockKeepingUnit::setdao(DAO* _dao){
this->dao= _dao;
}
void StockKeepingUnit::sethadBySku_KittingWorkstation(KittingWorkstation* _hadBySku_KittingWorkstation){
this->hadBySku_KittingWorkstation= _hadBySku_KittingWorkstation;
}
void StockKeepingUnit::sethasStockKeepingUnit_InternalShape(InternalShape* _hasStockKeepingUnit_InternalShape){
this->hasStockKeepingUnit_InternalShape= _hasStockKeepingUnit_InternalShape;
}
void StockKeepingUnit::sethadByExternalShape_StockKeepingUnit(ExternalShape* _hadByExternalShape_StockKeepingUnit){
this->hadByExternalShape_StockKeepingUnit= _hadByExternalShape_StockKeepingUnit;
}
void StockKeepingUnit::sethasStockKeepingUnit_EndEffector(std::vector<EndEffector*> _hasStockKeepingUnit_EndEffector){
this->hasStockKeepingUnit_EndEffector= _hasStockKeepingUnit_EndEffector;
}
void StockKeepingUnit::sethasPartsVessel_PartSku(std::vector<PartsVessel*> _hasPartsVessel_PartSku){
this->hasPartsVessel_PartSku= _hasPartsVessel_PartSku;
}
void StockKeepingUnit::sethasPartRefAndPose_Sku(std::vector<PartRefAndPose*> _hasPartRefAndPose_Sku){
this->hasPartRefAndPose_Sku= _hasPartRefAndPose_Sku;
}
void StockKeepingUnit::sethasKitDesign_KitTraySku(std::vector<KitDesign*> _hasKitDesign_KitTraySku){
this->hasKitDesign_KitTraySku= _hasKitDesign_KitTraySku;
}
void StockKeepingUnit::sethasSkuObject_Sku(std::vector<SkuObject*> _hasSkuObject_Sku){
this->hasSkuObject_Sku= _hasSkuObject_Sku;
}
void StockKeepingUnit::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("StockKeepingUnit");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void StockKeepingUnit::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["hasStockKeepingUnit_Description"]="'" + hasStockKeepingUnit_Description + "'";
ss.str("");
ss << hasStockKeepingUnit_Weight;
data["hasStockKeepingUnit_Weight"]=ss.str();
data["name"]="'" + name + "'";
ss.str("");
ss << StockKeepingUnitID;
data["StockKeepingUnitID"]=ss.str();
if(hadBySku_KittingWorkstation!=NULL)
data["hadBySku_KittingWorkstation"]="'" +hadBySku_KittingWorkstation->getname() + "'";
else 
 data["hadBySku_KittingWorkstation"]="null";
if(hasStockKeepingUnit_InternalShape!=NULL)
data["hasStockKeepingUnit_InternalShape"]="'" +hasStockKeepingUnit_InternalShape->getname() + "'";
else 
 data["hasStockKeepingUnit_InternalShape"]="null";
if(hadByExternalShape_StockKeepingUnit!=NULL)
data["hadByExternalShape_StockKeepingUnit"]="'" +hadByExternalShape_StockKeepingUnit->getname() + "'";
else 
 data["hadByExternalShape_StockKeepingUnit"]="null";
for(unsigned int i=0;i<hasStockKeepingUnit_EndEffector.size();++i){
ss.str("");
hasStockKeepingUnit_EndEffector[i]->get(hasStockKeepingUnit_EndEffector[i]->getname());
ss << hasStockKeepingUnit_EndEffector[i]->getEndEffectorID();
data["hasStockKeepingUnit_EndEffector"]=data["hasStockKeepingUnit_EndEffector"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartsVessel_PartSku.size();++i){
ss.str("");
hasPartsVessel_PartSku[i]->get(hasPartsVessel_PartSku[i]->getname());
ss << hasPartsVessel_PartSku[i]->getPartsVesselID();
data["hasPartsVessel_PartSku"]=data["hasPartsVessel_PartSku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartRefAndPose_Sku.size();++i){
ss.str("");
hasPartRefAndPose_Sku[i]->get(hasPartRefAndPose_Sku[i]->getname());
ss << hasPartRefAndPose_Sku[i]->getPartRefAndPoseID();
data["hasPartRefAndPose_Sku"]=data["hasPartRefAndPose_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasKitDesign_KitTraySku.size();++i){
ss.str("");
hasKitDesign_KitTraySku[i]->get(hasKitDesign_KitTraySku[i]->getname());
ss << hasKitDesign_KitTraySku[i]->getKitDesignID();
data["hasKitDesign_KitTraySku"]=data["hasKitDesign_KitTraySku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasSkuObject_Sku.size();++i){
ss.str("");
hasSkuObject_Sku[i]->get(hasSkuObject_Sku[i]->getname());
ss << hasSkuObject_Sku[i]->getSkuObjectID();
data["hasSkuObject_Sku"]=data["hasSkuObject_Sku"]+" "+ss.str();
}
dao  = new DAO("StockKeepingUnit");
dao->set(data);
delete (dao);
}
void StockKeepingUnit::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
data["hasStockKeepingUnit_Description"]="'" + hasStockKeepingUnit_Description+ "'";
ss.str("");
ss << hasStockKeepingUnit_Weight;
data["hasStockKeepingUnit_Weight"]=ss.str();
ss.str("");
ss << temp0->getDataThingID();
data["StockKeepingUnitID"]=ss.str();
if(hadBySku_KittingWorkstation!=NULL)
data["hadBySku_KittingWorkstation"]="'" + hadBySku_KittingWorkstation->getname() + "'";
if(hasStockKeepingUnit_InternalShape!=NULL)
data["hasStockKeepingUnit_InternalShape"]="'" + hasStockKeepingUnit_InternalShape->getname() + "'";
if(hadByExternalShape_StockKeepingUnit!=NULL)
data["hadByExternalShape_StockKeepingUnit"]="'" + hadByExternalShape_StockKeepingUnit->getname() + "'";
dao  = new DAO("StockKeepingUnit");
dao->insert(data);
delete (dao);
this->set(name);
}

void StockKeepingUnit::copy(std::map<std::string,std::string> object){hadBySku_KittingWorkstation=NULL;
hasStockKeepingUnit_InternalShape=NULL;
hadByExternalShape_StockKeepingUnit=NULL;
for(std::size_t i = 0; i < hasStockKeepingUnit_EndEffector.size(); i++){
hasStockKeepingUnit_EndEffector[i]=NULL;}
hasStockKeepingUnit_EndEffector.clear();
for(std::size_t i = 0; i < hasPartsVessel_PartSku.size(); i++){
hasPartsVessel_PartSku[i]=NULL;}
hasPartsVessel_PartSku.clear();
for(std::size_t i = 0; i < hasPartRefAndPose_Sku.size(); i++){
hasPartRefAndPose_Sku[i]=NULL;}
hasPartRefAndPose_Sku.clear();
for(std::size_t i = 0; i < hasKitDesign_KitTraySku.size(); i++){
hasKitDesign_KitTraySku[i]=NULL;}
hasKitDesign_KitTraySku.clear();
for(std::size_t i = 0; i < hasSkuObject_Sku.size(); i++){
hasSkuObject_Sku[i]=NULL;}
hasSkuObject_Sku.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<StockKeepingUnit*> tmp;
this->hasStockKeepingUnit_Description = object["StockKeepingUnit.hasStockKeepingUnit_Description"];
this->hasStockKeepingUnit_Weight = std::atof(object["StockKeepingUnit.hasStockKeepingUnit_Weight"].c_str());
this->name = object["StockKeepingUnit._NAME"];
this->StockKeepingUnitID = std::atof(object["StockKeepingUnit.StockKeepingUnitID"].c_str());
if(this->hadBySku_KittingWorkstation== NULL && object["hadBySku_KittingWorkstation/KittingWorkstation._NAME"]!=""){
this->hadBySku_KittingWorkstation = new KittingWorkstation(object["hadBySku_KittingWorkstation/KittingWorkstation._NAME"]);
}
if(this->hasStockKeepingUnit_InternalShape== NULL && object["hasStockKeepingUnit_InternalShape/InternalShape._NAME"]!=""){
this->hasStockKeepingUnit_InternalShape = new InternalShape(object["hasStockKeepingUnit_InternalShape/InternalShape._NAME"]);
}
if(this->hadByExternalShape_StockKeepingUnit== NULL && object["hadByExternalShape_StockKeepingUnit/ExternalShape._NAME"]!=""){
this->hadByExternalShape_StockKeepingUnit = new ExternalShape(object["hadByExternalShape_StockKeepingUnit/ExternalShape._NAME"]);
}
if(this->hasStockKeepingUnit_EndEffector.empty() && object["hasStockKeepingUnit_EndEffector/EndEffector._NAME"]!=""){
temp = Explode(object["hasStockKeepingUnit_EndEffector/EndEffector._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasStockKeepingUnit_EndEffector.push_back(new EndEffector(temp[i]));
}
}
if(this->hasPartsVessel_PartSku.empty() && object["hasPartsVessel_PartSku/PartsVessel._NAME"]!=""){
temp = Explode(object["hasPartsVessel_PartSku/PartsVessel._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartsVessel_PartSku.push_back(new PartsVessel(temp[i]));
}
}
if(this->hasPartRefAndPose_Sku.empty() && object["hasPartRefAndPose_Sku/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hasPartRefAndPose_Sku/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartRefAndPose_Sku.push_back(new PartRefAndPose(temp[i]));
}
}
if(this->hasKitDesign_KitTraySku.empty() && object["hasKitDesign_KitTraySku/KitDesign._NAME"]!=""){
temp = Explode(object["hasKitDesign_KitTraySku/KitDesign._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasKitDesign_KitTraySku.push_back(new KitDesign(temp[i]));
}
}
if(this->hasSkuObject_Sku.empty() && object["hasSkuObject_Sku/SkuObject._NAME"]!=""){
temp = Explode(object["hasSkuObject_Sku/SkuObject._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSkuObject_Sku.push_back(new SkuObject(temp[i]));
}
}

}std::vector<std::string> StockKeepingUnit::Explode(const std::string & str, char separator )
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
