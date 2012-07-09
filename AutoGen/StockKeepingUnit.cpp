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
 #include "ShapeDesign.h"
 #include "DAO.h"

StockKeepingUnit::StockKeepingUnit(std::string name) : DataThing(name){
this->name=name;dao = NULL;
hadBySku_Workstation = NULL;
hasSku_Shape = NULL;

}StockKeepingUnit::~StockKeepingUnit(){
delete(dao);
delete(hadBySku_Workstation);
delete(hasSku_Shape);
}
std::vector<std::string>* StockKeepingUnit::gethasSku_EndEffectorRefs(){
return &hasSku_EndEffectorRefs;
}
std::string StockKeepingUnit::gethasSku_Description(){
return hasSku_Description;
}
std::string StockKeepingUnit::gethasSku_Id(){
return hasSku_Id;
}
double StockKeepingUnit::gethasSku_Weight(){
return hasSku_Weight;
}
std::string StockKeepingUnit::getname(){
return name;
}
int StockKeepingUnit::getStockKeepingUnitID(){
return StockKeepingUnitID;
}
DAO* StockKeepingUnit::getdao(){
return dao;
}
KittingWorkstation* StockKeepingUnit::gethadBySku_Workstation(){
return hadBySku_Workstation;
}
ShapeDesign* StockKeepingUnit::gethasSku_Shape(){
return hasSku_Shape;
}
void StockKeepingUnit::sethasSku_EndEffectorRefs(std::vector<std::string> _hasSku_EndEffectorRefs){
this->hasSku_EndEffectorRefs= _hasSku_EndEffectorRefs;
}
void StockKeepingUnit::sethasSku_Description(std::string _hasSku_Description){
this->hasSku_Description= _hasSku_Description;
}
void StockKeepingUnit::sethasSku_Id(std::string _hasSku_Id){
this->hasSku_Id= _hasSku_Id;
}
void StockKeepingUnit::sethasSku_Weight(double _hasSku_Weight){
this->hasSku_Weight= _hasSku_Weight;
}
void StockKeepingUnit::setdao(DAO* _dao){
this->dao= _dao;
}
void StockKeepingUnit::sethadBySku_Workstation(KittingWorkstation* _hadBySku_Workstation){
this->hadBySku_Workstation= _hadBySku_Workstation;
}
void StockKeepingUnit::sethasSku_Shape(ShapeDesign* _hasSku_Shape){
this->hasSku_Shape= _hasSku_Shape;
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
DataThing* temp = (DataThing*) this;
temp->set(name);
for(unsigned int i=0;i<hasSku_EndEffectorRefs.size();++i){
data["hasSku_EndEffectorRefs"]=data["hasSku_EndEffectorRefs"]+" "+hasSku_EndEffectorRefs[i];
}
data["hasSku_Description"]=hasSku_Description;
data["hasSku_Id"]=hasSku_Id;
ss.str("");
ss << hasSku_Weight;
data["hasSku_Weight"]=ss.str();
data["name"]=name;
ss.str("");
ss << StockKeepingUnitID;
data["StockKeepingUnitID"]=ss.str();
if(hadBySku_Workstation!=NULL)
data["hadBySku_Workstation"]=hadBySku_Workstation->getname();
if(hasSku_Shape!=NULL)
data["hasSku_Shape"]=hasSku_Shape->getname();
dao  = new DAO("StockKeepingUnit");
dao->set(data);
delete (dao);
}

void StockKeepingUnit::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<StockKeepingUnit*> tmp;
temp = Explode(object["hasSku_EndEffectorRefs"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasSku_EndEffectorRefs.push_back(temp[i]);
}
this->hasSku_Description = object["StockKeepingUnit.hasSku_Description"];
this->hasSku_Id = object["StockKeepingUnit.hasSku_Id"];
this->hasSku_Weight = std::atof(object["StockKeepingUnit.hasSku_Weight"].c_str());
this->name = object["StockKeepingUnit._NAME"];
this->StockKeepingUnitID = std::atof(object["StockKeepingUnit.StockKeepingUnitID"].c_str());
if(this->hadBySku_Workstation== NULL && object["hadBySku_Workstation/KittingWorkstation._NAME"]!=""){
this->hadBySku_Workstation = new KittingWorkstation(object["hadBySku_Workstation/KittingWorkstation._NAME"]);
}
if(this->hasSku_Shape== NULL && object["hasSku_Shape/ShapeDesign._NAME"]!=""){
this->hasSku_Shape = new ShapeDesign(object["hasSku_Shape/ShapeDesign._NAME"]);
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
