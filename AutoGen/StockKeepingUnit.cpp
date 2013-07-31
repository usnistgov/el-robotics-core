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


 #include "PartsBin.h"
 #include "KittingWorkstation.h"
 #include "KitTray.h"
 #include "ShapeDesign.h"
 #include "LargeContainer.h"
 #include "PartsTray.h"
 #include "PartRefAndPose.h"
 #include "EndEffector.h"
 #include "KitDesign.h"
 #include "DAO.h"
 #include "Part.h"

StockKeepingUnit::StockKeepingUnit(std::string name) : DataThing(name){
dao = NULL;
hadBySku_KittingWorkstation = NULL;
hasStockKeepingUnit_Shape = NULL;

}StockKeepingUnit::~StockKeepingUnit(){
delete(hadBySku_KittingWorkstation);
delete(hasStockKeepingUnit_Shape);
for(std::size_t i = 0; i < hasStockKeepingUnit_EndEffector.size(); i++)
delete(hasStockKeepingUnit_EndEffector[i]);
for(std::size_t i = 0; i < hasPartsBin_Sku.size(); i++)
delete(hasPartsBin_Sku[i]);
for(std::size_t i = 0; i < hasPartsBin_PartSku.size(); i++)
delete(hasPartsBin_PartSku[i]);
for(std::size_t i = 0; i < hasLargeContainer_Sku.size(); i++)
delete(hasLargeContainer_Sku[i]);
for(std::size_t i = 0; i < hasPart_Sku.size(); i++)
delete(hasPart_Sku[i]);
for(std::size_t i = 0; i < hasPartsTray_Sku.size(); i++)
delete(hasPartsTray_Sku[i]);
for(std::size_t i = 0; i < hasPartRefAndPose_Sku.size(); i++)
delete(hasPartRefAndPose_Sku[i]);
for(std::size_t i = 0; i < hasKitTray_Sku.size(); i++)
delete(hasKitTray_Sku[i]);
for(std::size_t i = 0; i < hasKitDesign_KitTraySku.size(); i++)
delete(hasKitDesign_KitTraySku[i]);
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
ShapeDesign* StockKeepingUnit::gethasStockKeepingUnit_Shape(){
return hasStockKeepingUnit_Shape;
}
std::vector<EndEffector*> StockKeepingUnit::gethasStockKeepingUnit_EndEffector(){
return hasStockKeepingUnit_EndEffector;
}
std::vector<PartsBin*> StockKeepingUnit::gethasPartsBin_Sku(){
return hasPartsBin_Sku;
}
std::vector<PartsBin*> StockKeepingUnit::gethasPartsBin_PartSku(){
return hasPartsBin_PartSku;
}
std::vector<LargeContainer*> StockKeepingUnit::gethasLargeContainer_Sku(){
return hasLargeContainer_Sku;
}
std::vector<Part*> StockKeepingUnit::gethasPart_Sku(){
return hasPart_Sku;
}
std::vector<PartsTray*> StockKeepingUnit::gethasPartsTray_Sku(){
return hasPartsTray_Sku;
}
std::vector<PartRefAndPose*> StockKeepingUnit::gethasPartRefAndPose_Sku(){
return hasPartRefAndPose_Sku;
}
std::vector<KitTray*> StockKeepingUnit::gethasKitTray_Sku(){
return hasKitTray_Sku;
}
std::vector<KitDesign*> StockKeepingUnit::gethasKitDesign_KitTraySku(){
return hasKitDesign_KitTraySku;
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
void StockKeepingUnit::sethasStockKeepingUnit_Shape(ShapeDesign* _hasStockKeepingUnit_Shape){
this->hasStockKeepingUnit_Shape= _hasStockKeepingUnit_Shape;
}
void StockKeepingUnit::sethasStockKeepingUnit_EndEffector(std::vector<EndEffector*> _hasStockKeepingUnit_EndEffector){
this->hasStockKeepingUnit_EndEffector= _hasStockKeepingUnit_EndEffector;
}
void StockKeepingUnit::sethasPartsBin_Sku(std::vector<PartsBin*> _hasPartsBin_Sku){
this->hasPartsBin_Sku= _hasPartsBin_Sku;
}
void StockKeepingUnit::sethasPartsBin_PartSku(std::vector<PartsBin*> _hasPartsBin_PartSku){
this->hasPartsBin_PartSku= _hasPartsBin_PartSku;
}
void StockKeepingUnit::sethasLargeContainer_Sku(std::vector<LargeContainer*> _hasLargeContainer_Sku){
this->hasLargeContainer_Sku= _hasLargeContainer_Sku;
}
void StockKeepingUnit::sethasPart_Sku(std::vector<Part*> _hasPart_Sku){
this->hasPart_Sku= _hasPart_Sku;
}
void StockKeepingUnit::sethasPartsTray_Sku(std::vector<PartsTray*> _hasPartsTray_Sku){
this->hasPartsTray_Sku= _hasPartsTray_Sku;
}
void StockKeepingUnit::sethasPartRefAndPose_Sku(std::vector<PartRefAndPose*> _hasPartRefAndPose_Sku){
this->hasPartRefAndPose_Sku= _hasPartRefAndPose_Sku;
}
void StockKeepingUnit::sethasKitTray_Sku(std::vector<KitTray*> _hasKitTray_Sku){
this->hasKitTray_Sku= _hasKitTray_Sku;
}
void StockKeepingUnit::sethasKitDesign_KitTraySku(std::vector<KitDesign*> _hasKitDesign_KitTraySku){
this->hasKitDesign_KitTraySku= _hasKitDesign_KitTraySku;
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
data["hadBySku_KittingWorkstation"]=hadBySku_KittingWorkstation->getname();
if(hasStockKeepingUnit_Shape!=NULL)
data["hasStockKeepingUnit_Shape"]=hasStockKeepingUnit_Shape->getname();
for(unsigned int i=0;i<hasStockKeepingUnit_EndEffector.size();++i){
ss.str("");
hasStockKeepingUnit_EndEffector[i]->get(hasStockKeepingUnit_EndEffector[i]->getname());
ss << hasStockKeepingUnit_EndEffector[i]->getEndEffectorID();
data["hasStockKeepingUnit_EndEffector"]=data["hasStockKeepingUnit_EndEffector"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartsBin_Sku.size();++i){
ss.str("");
hasPartsBin_Sku[i]->get(hasPartsBin_Sku[i]->getname());
ss << hasPartsBin_Sku[i]->getPartsBinID();
data["hasPartsBin_Sku"]=data["hasPartsBin_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartsBin_PartSku.size();++i){
ss.str("");
hasPartsBin_PartSku[i]->get(hasPartsBin_PartSku[i]->getname());
ss << hasPartsBin_PartSku[i]->getPartsBinID();
data["hasPartsBin_PartSku"]=data["hasPartsBin_PartSku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasLargeContainer_Sku.size();++i){
ss.str("");
hasLargeContainer_Sku[i]->get(hasLargeContainer_Sku[i]->getname());
ss << hasLargeContainer_Sku[i]->getLargeContainerID();
data["hasLargeContainer_Sku"]=data["hasLargeContainer_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPart_Sku.size();++i){
ss.str("");
hasPart_Sku[i]->get(hasPart_Sku[i]->getname());
ss << hasPart_Sku[i]->getPartID();
data["hasPart_Sku"]=data["hasPart_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartsTray_Sku.size();++i){
ss.str("");
hasPartsTray_Sku[i]->get(hasPartsTray_Sku[i]->getname());
ss << hasPartsTray_Sku[i]->getPartsTrayID();
data["hasPartsTray_Sku"]=data["hasPartsTray_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasPartRefAndPose_Sku.size();++i){
ss.str("");
hasPartRefAndPose_Sku[i]->get(hasPartRefAndPose_Sku[i]->getname());
ss << hasPartRefAndPose_Sku[i]->getPartRefAndPoseID();
data["hasPartRefAndPose_Sku"]=data["hasPartRefAndPose_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasKitTray_Sku.size();++i){
ss.str("");
hasKitTray_Sku[i]->get(hasKitTray_Sku[i]->getname());
ss << hasKitTray_Sku[i]->getKitTrayID();
data["hasKitTray_Sku"]=data["hasKitTray_Sku"]+" "+ss.str();
}
for(unsigned int i=0;i<hasKitDesign_KitTraySku.size();++i){
ss.str("");
hasKitDesign_KitTraySku[i]->get(hasKitDesign_KitTraySku[i]->getname());
ss << hasKitDesign_KitTraySku[i]->getKitDesignID();
data["hasKitDesign_KitTraySku"]=data["hasKitDesign_KitTraySku"]+" "+ss.str();
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
data["hadBySku_KittingWorkstation"]=hadBySku_KittingWorkstation->getname();
if(hasStockKeepingUnit_Shape!=NULL)
data["hasStockKeepingUnit_Shape"]=hasStockKeepingUnit_Shape->getname();
dao  = new DAO("StockKeepingUnit");
dao->insert(data);
delete (dao);
this->set(name);
}

void StockKeepingUnit::copy(std::map<std::string,std::string> object){delete(hadBySku_KittingWorkstation);
hadBySku_KittingWorkstation=NULL;
delete(hasStockKeepingUnit_Shape);
hasStockKeepingUnit_Shape=NULL;
for(std::size_t i = 0; i < hasStockKeepingUnit_EndEffector.size(); i++){
delete(hasStockKeepingUnit_EndEffector[i]);
hasStockKeepingUnit_EndEffector[i]=NULL;}
for(std::size_t i = 0; i < hasPartsBin_Sku.size(); i++){
delete(hasPartsBin_Sku[i]);
hasPartsBin_Sku[i]=NULL;}
for(std::size_t i = 0; i < hasPartsBin_PartSku.size(); i++){
delete(hasPartsBin_PartSku[i]);
hasPartsBin_PartSku[i]=NULL;}
for(std::size_t i = 0; i < hasLargeContainer_Sku.size(); i++){
delete(hasLargeContainer_Sku[i]);
hasLargeContainer_Sku[i]=NULL;}
for(std::size_t i = 0; i < hasPart_Sku.size(); i++){
delete(hasPart_Sku[i]);
hasPart_Sku[i]=NULL;}
for(std::size_t i = 0; i < hasPartsTray_Sku.size(); i++){
delete(hasPartsTray_Sku[i]);
hasPartsTray_Sku[i]=NULL;}
for(std::size_t i = 0; i < hasPartRefAndPose_Sku.size(); i++){
delete(hasPartRefAndPose_Sku[i]);
hasPartRefAndPose_Sku[i]=NULL;}
for(std::size_t i = 0; i < hasKitTray_Sku.size(); i++){
delete(hasKitTray_Sku[i]);
hasKitTray_Sku[i]=NULL;}
for(std::size_t i = 0; i < hasKitDesign_KitTraySku.size(); i++){
delete(hasKitDesign_KitTraySku[i]);
hasKitDesign_KitTraySku[i]=NULL;}
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
if(this->hasStockKeepingUnit_Shape== NULL && object["hasStockKeepingUnit_Shape/ShapeDesign._NAME"]!=""){
this->hasStockKeepingUnit_Shape = new ShapeDesign(object["hasStockKeepingUnit_Shape/ShapeDesign._NAME"]);
}
if(this->hasStockKeepingUnit_EndEffector.empty() && object["hasStockKeepingUnit_EndEffector/EndEffector._NAME"]!=""){
temp = Explode(object["hasStockKeepingUnit_EndEffector/EndEffector._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasStockKeepingUnit_EndEffector.push_back(new EndEffector(temp[i]));
}
}
if(this->hasPartsBin_Sku.empty() && object["hasPartsBin_Sku/PartsBin._NAME"]!=""){
temp = Explode(object["hasPartsBin_Sku/PartsBin._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartsBin_Sku.push_back(new PartsBin(temp[i]));
}
}
if(this->hasPartsBin_PartSku.empty() && object["hasPartsBin_PartSku/PartsBin._NAME"]!=""){
temp = Explode(object["hasPartsBin_PartSku/PartsBin._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartsBin_PartSku.push_back(new PartsBin(temp[i]));
}
}
if(this->hasLargeContainer_Sku.empty() && object["hasLargeContainer_Sku/LargeContainer._NAME"]!=""){
temp = Explode(object["hasLargeContainer_Sku/LargeContainer._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasLargeContainer_Sku.push_back(new LargeContainer(temp[i]));
}
}
if(this->hasPart_Sku.empty() && object["hasPart_Sku/Part._NAME"]!=""){
temp = Explode(object["hasPart_Sku/Part._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPart_Sku.push_back(new Part(temp[i]));
}
}
if(this->hasPartsTray_Sku.empty() && object["hasPartsTray_Sku/PartsTray._NAME"]!=""){
temp = Explode(object["hasPartsTray_Sku/PartsTray._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartsTray_Sku.push_back(new PartsTray(temp[i]));
}
}
if(this->hasPartRefAndPose_Sku.empty() && object["hasPartRefAndPose_Sku/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hasPartRefAndPose_Sku/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasPartRefAndPose_Sku.push_back(new PartRefAndPose(temp[i]));
}
}
if(this->hasKitTray_Sku.empty() && object["hasKitTray_Sku/KitTray._NAME"]!=""){
temp = Explode(object["hasKitTray_Sku/KitTray._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasKitTray_Sku.push_back(new KitTray(temp[i]));
}
}
if(this->hasKitDesign_KitTraySku.empty() && object["hasKitDesign_KitTraySku/KitDesign._NAME"]!=""){
temp = Explode(object["hasKitDesign_KitTraySku/KitDesign._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasKitDesign_KitTraySku.push_back(new KitDesign(temp[i]));
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
