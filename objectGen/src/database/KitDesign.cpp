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

#include "KitDesign.h"


 #include "StockKeepingUnit.h"
 #include "Kit.h"
 #include "KittingWorkstation.h"
 #include "DAO.h"
 #include "PartRefAndPose.h"
 #include "LargeBoxWithKits.h"

KitDesign::KitDesign(std::string name) : DataThing(name){
dao = NULL;
hadByKitDesign_Workstation = NULL;
hasKitDesign_KitTraySku = NULL;

}KitDesign::~KitDesign(){
delete(dao);
delete(hadByKitDesign_Workstation);
delete(hasKitDesign_KitTraySku);
for(std::size_t i = 0; i < hasLargeBoxWithKits_KitDesign.size(); i++)
delete(hasLargeBoxWithKits_KitDesign[i]);
for(std::size_t i = 0; i < hadByPartRefAndPose_KitDesign.size(); i++)
delete(hadByPartRefAndPose_KitDesign[i]);
for(std::size_t i = 0; i < hasKit_Design.size(); i++)
delete(hasKit_Design[i]);
}
int KitDesign::getKitDesignID(){
return KitDesignID;
}
DAO* KitDesign::getdao(){
return dao;
}
KittingWorkstation* KitDesign::gethadByKitDesign_Workstation(){
return hadByKitDesign_Workstation;
}
StockKeepingUnit* KitDesign::gethasKitDesign_KitTraySku(){
return hasKitDesign_KitTraySku;
}
std::vector<LargeBoxWithKits*> KitDesign::gethasLargeBoxWithKits_KitDesign(){
return hasLargeBoxWithKits_KitDesign;
}
std::vector<PartRefAndPose*> KitDesign::gethadByPartRefAndPose_KitDesign(){
return hadByPartRefAndPose_KitDesign;
}
std::vector<Kit*> KitDesign::gethasKit_Design(){
return hasKit_Design;
}
void KitDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void KitDesign::sethadByKitDesign_Workstation(KittingWorkstation* _hadByKitDesign_Workstation){
this->hadByKitDesign_Workstation= _hadByKitDesign_Workstation;
}
void KitDesign::sethasKitDesign_KitTraySku(StockKeepingUnit* _hasKitDesign_KitTraySku){
this->hasKitDesign_KitTraySku= _hasKitDesign_KitTraySku;
}
void KitDesign::sethasLargeBoxWithKits_KitDesign(std::vector<LargeBoxWithKits*> _hasLargeBoxWithKits_KitDesign){
this->hasLargeBoxWithKits_KitDesign= _hasLargeBoxWithKits_KitDesign;
}
void KitDesign::sethadByPartRefAndPose_KitDesign(std::vector<PartRefAndPose*> _hadByPartRefAndPose_KitDesign){
this->hadByPartRefAndPose_KitDesign= _hadByPartRefAndPose_KitDesign;
}
void KitDesign::sethasKit_Design(std::vector<Kit*> _hasKit_Design){
this->hasKit_Design= _hasKit_Design;
}
void KitDesign::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("KitDesign");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void KitDesign::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["name"]=name;
ss.str("");
ss << KitDesignID;
data["KitDesignID"]=ss.str();
if(hadByKitDesign_Workstation!=NULL)
data["hadByKitDesign_Workstation"]=hadByKitDesign_Workstation->getname();
if(hasKitDesign_KitTraySku!=NULL)
data["hasKitDesign_KitTraySku"]=hasKitDesign_KitTraySku->getname();
for(unsigned int i=0;i<hasLargeBoxWithKits_KitDesign.size();++i){
ss.str("");
hasLargeBoxWithKits_KitDesign[i]->get(hasLargeBoxWithKits_KitDesign[i]->getname());
ss << hasLargeBoxWithKits_KitDesign[i]->getLargeBoxWithKitsID();
data["hasLargeBoxWithKits_KitDesign"]=data["hasLargeBoxWithKits_KitDesign"]+" "+ss.str();
}
for(unsigned int i=0;i<hadByPartRefAndPose_KitDesign.size();++i){
ss.str("");
hadByPartRefAndPose_KitDesign[i]->get(hadByPartRefAndPose_KitDesign[i]->getname());
ss << hadByPartRefAndPose_KitDesign[i]->getPartRefAndPoseID();
data["hadByPartRefAndPose_KitDesign"]=data["hadByPartRefAndPose_KitDesign"]+" "+ss.str();
}
for(unsigned int i=0;i<hasKit_Design.size();++i){
ss.str("");
hasKit_Design[i]->get(hasKit_Design[i]->getname());
ss << hasKit_Design[i]->getKitID();
data["hasKit_Design"]=data["hasKit_Design"]+" "+ss.str();
}
dao  = new DAO("KitDesign");
dao->set(data);
delete (dao);
}

void KitDesign::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<KitDesign*> tmp;
this->name = object["KitDesign._NAME"];
this->KitDesignID = std::atof(object["KitDesign.KitDesignID"].c_str());
if(this->hadByKitDesign_Workstation== NULL && object["hadByKitDesign_Workstation/KittingWorkstation._NAME"]!=""){
this->hadByKitDesign_Workstation = new KittingWorkstation(object["hadByKitDesign_Workstation/KittingWorkstation._NAME"]);
}
if(this->hasKitDesign_KitTraySku== NULL && object["hasKitDesign_KitTraySku/StockKeepingUnit._NAME"]!=""){
this->hasKitDesign_KitTraySku = new StockKeepingUnit(object["hasKitDesign_KitTraySku/StockKeepingUnit._NAME"]);
}
if(this->hasLargeBoxWithKits_KitDesign.empty() && object["hasLargeBoxWithKits_KitDesign/LargeBoxWithKits._NAME"]!=""){
temp = Explode(object["hasLargeBoxWithKits_KitDesign/LargeBoxWithKits._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasLargeBoxWithKits_KitDesign.push_back(new LargeBoxWithKits(temp[i]));
}
}
if(this->hadByPartRefAndPose_KitDesign.empty() && object["hadByPartRefAndPose_KitDesign/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hadByPartRefAndPose_KitDesign/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByPartRefAndPose_KitDesign.push_back(new PartRefAndPose(temp[i]));
}
}
if(this->hasKit_Design.empty() && object["hasKit_Design/Kit._NAME"]!=""){
temp = Explode(object["hasKit_Design/Kit._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hasKit_Design.push_back(new Kit(temp[i]));
}
}

}std::vector<std::string> KitDesign::Explode(const std::string & str, char separator )
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
