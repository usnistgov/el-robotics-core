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

#include "Kit.h"


 #include "Slot.h"
 #include "LargeBoxWithKits.h"
 #include "KitTray.h"
 #include "DAO.h"
 #include "Part.h"
 #include "KitDesign.h"

Kit::Kit(std::string name) : SolidObject(name){
dao = NULL;
hadByKit_LargeBoxWithKits = NULL;
hasKit_KitTray = NULL;
hasKit_Design = NULL;

}Kit::~Kit(){
delete(hadByKit_LargeBoxWithKits);
delete(hasKit_KitTray);
delete(hasKit_Design);
for(std::size_t i = 0; i < hadBySlot_Kit.size(); i++)
delete(hadBySlot_Kit[i]);
for(std::size_t i = 0; i < hadByPart_Kit.size(); i++)
delete(hadByPart_Kit[i]);
}
bool Kit::gethasKit_Finished(){
return hasKit_Finished;
}
int Kit::getKitID(){
return KitID;
}
DAO* Kit::getdao(){
return dao;
}
LargeBoxWithKits* Kit::gethadByKit_LargeBoxWithKits(){
return hadByKit_LargeBoxWithKits;
}
KitTray* Kit::gethasKit_KitTray(){
return hasKit_KitTray;
}
KitDesign* Kit::gethasKit_Design(){
return hasKit_Design;
}
std::vector<Slot*> Kit::gethadBySlot_Kit(){
return hadBySlot_Kit;
}
std::vector<Part*> Kit::gethadByPart_Kit(){
return hadByPart_Kit;
}
void Kit::sethasKit_Finished(bool _hasKit_Finished){
this->hasKit_Finished= _hasKit_Finished;
}
void Kit::setKitID(int _KitID){
this->KitID= _KitID;
}
void Kit::setdao(DAO* _dao){
this->dao= _dao;
}
void Kit::sethadByKit_LargeBoxWithKits(LargeBoxWithKits* _hadByKit_LargeBoxWithKits){
this->hadByKit_LargeBoxWithKits= _hadByKit_LargeBoxWithKits;
}
void Kit::sethasKit_KitTray(KitTray* _hasKit_KitTray){
this->hasKit_KitTray= _hasKit_KitTray;
}
void Kit::sethasKit_Design(KitDesign* _hasKit_Design){
this->hasKit_Design= _hasKit_Design;
}
void Kit::sethadBySlot_Kit(std::vector<Slot*> _hadBySlot_Kit){
this->hadBySlot_Kit= _hadBySlot_Kit;
}
void Kit::sethadByPart_Kit(std::vector<Part*> _hadByPart_Kit){
this->hadByPart_Kit= _hadByPart_Kit;
}
void Kit::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("Kit");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Kit::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
ss.str("");
ss << hasKit_Finished;
data["hasKit_Finished"]=ss.str();
data["name"]="'" + name + "'";
ss.str("");
ss << KitID;
data["KitID"]=ss.str();
if(hadByKit_LargeBoxWithKits!=NULL)
data["hadByKit_LargeBoxWithKits"]="'" +hadByKit_LargeBoxWithKits->getname() + "'";
else 
 data["hadByKit_LargeBoxWithKits"]="null";
if(hasKit_KitTray!=NULL)
data["hasKit_KitTray"]="'" +hasKit_KitTray->getname() + "'";
else 
 data["hasKit_KitTray"]="null";
if(hasKit_Design!=NULL)
data["hasKit_Design"]="'" +hasKit_Design->getname() + "'";
else 
 data["hasKit_Design"]="null";
for(unsigned int i=0;i<hadBySlot_Kit.size();++i){
ss.str("");
hadBySlot_Kit[i]->get(hadBySlot_Kit[i]->getname());
ss << hadBySlot_Kit[i]->getSlotID();
data["hadBySlot_Kit"]=data["hadBySlot_Kit"]+" "+ss.str();
}
for(unsigned int i=0;i<hadByPart_Kit.size();++i){
ss.str("");
hadByPart_Kit[i]->get(hadByPart_Kit[i]->getname());
ss << hadByPart_Kit[i]->getPartID();
data["hadByPart_Kit"]=data["hadByPart_Kit"]+" "+ss.str();
}
dao  = new DAO("Kit");
dao->set(data);
delete (dao);
}
void Kit::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << hasKit_Finished;
data["hasKit_Finished"]=ss.str();
ss.str("");
ss << temp0->getSolidObjectID();
data["KitID"]=ss.str();
if(hadByKit_LargeBoxWithKits!=NULL)
data["hadByKit_LargeBoxWithKits"]="'" + hadByKit_LargeBoxWithKits->getname() + "'";
if(hasKit_KitTray!=NULL)
data["hasKit_KitTray"]="'" + hasKit_KitTray->getname() + "'";
if(hasKit_Design!=NULL)
data["hasKit_Design"]="'" + hasKit_Design->getname() + "'";
dao  = new DAO("Kit");
dao->insert(data);
delete (dao);
this->set(name);
}

void Kit::copy(std::map<std::string,std::string> object){delete(hadByKit_LargeBoxWithKits);
hadByKit_LargeBoxWithKits=NULL;
delete(hasKit_KitTray);
hasKit_KitTray=NULL;
delete(hasKit_Design);
hasKit_Design=NULL;
for(std::size_t i = 0; i < hadBySlot_Kit.size(); i++){
delete(hadBySlot_Kit[i]);
hadBySlot_Kit[i]=NULL;}
hadBySlot_Kit.clear();
for(std::size_t i = 0; i < hadByPart_Kit.size(); i++){
delete(hadByPart_Kit[i]);
hadByPart_Kit[i]=NULL;}
hadByPart_Kit.clear();
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Kit*> tmp;
this->hasKit_Finished = std::atof(object["Kit.hasKit_Finished"].c_str());
this->name = object["Kit._NAME"];
this->KitID = std::atof(object["Kit.KitID"].c_str());
if(this->hadByKit_LargeBoxWithKits== NULL && object["hadByKit_LargeBoxWithKits/LargeBoxWithKits._NAME"]!=""){
this->hadByKit_LargeBoxWithKits = new LargeBoxWithKits(object["hadByKit_LargeBoxWithKits/LargeBoxWithKits._NAME"]);
}
if(this->hasKit_KitTray== NULL && object["hasKit_KitTray/KitTray._NAME"]!=""){
this->hasKit_KitTray = new KitTray(object["hasKit_KitTray/KitTray._NAME"]);
}
if(this->hasKit_Design== NULL && object["hasKit_Design/KitDesign._NAME"]!=""){
this->hasKit_Design = new KitDesign(object["hasKit_Design/KitDesign._NAME"]);
}
if(this->hadBySlot_Kit.empty() && object["hadBySlot_Kit/Slot._NAME"]!=""){
temp = Explode(object["hadBySlot_Kit/Slot._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadBySlot_Kit.push_back(new Slot(temp[i]));
}
}
if(this->hadByPart_Kit.empty() && object["hadByPart_Kit/Part._NAME"]!=""){
temp = Explode(object["hadByPart_Kit/Part._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByPart_Kit.push_back(new Part(temp[i]));
}
}

}std::vector<std::string> Kit::Explode(const std::string & str, char separator )
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
