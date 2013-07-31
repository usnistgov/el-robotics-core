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

#include "Slot.h"


 #include "Kit.h"
 #include "DAO.h"
 #include "Part.h"
 #include "PartRefAndPose.h"

Slot::Slot(std::string name) : DataThing(name){
dao = NULL;
hadBySlot_Kit = NULL;
hasSlot_PartRefAndPose = NULL;
hasSlot_Part = NULL;

}Slot::~Slot(){
delete(hadBySlot_Kit);
delete(hasSlot_PartRefAndPose);
delete(hasSlot_Part);
}
int Slot::getSlotID(){
return SlotID;
}
DAO* Slot::getdao(){
return dao;
}
Kit* Slot::gethadBySlot_Kit(){
return hadBySlot_Kit;
}
PartRefAndPose* Slot::gethasSlot_PartRefAndPose(){
return hasSlot_PartRefAndPose;
}
Part* Slot::gethasSlot_Part(){
return hasSlot_Part;
}
void Slot::setSlotID(int _SlotID){
this->SlotID= _SlotID;
}
void Slot::setdao(DAO* _dao){
this->dao= _dao;
}
void Slot::sethadBySlot_Kit(Kit* _hadBySlot_Kit){
this->hadBySlot_Kit= _hadBySlot_Kit;
}
void Slot::sethasSlot_PartRefAndPose(PartRefAndPose* _hasSlot_PartRefAndPose){
this->hasSlot_PartRefAndPose= _hasSlot_PartRefAndPose;
}
void Slot::sethasSlot_Part(Part* _hasSlot_Part){
this->hasSlot_Part= _hasSlot_Part;
}
void Slot::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("Slot");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Slot::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
DataThing* temp0 = (DataThing*) this;
temp0->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << SlotID;
data["SlotID"]=ss.str();
if(hadBySlot_Kit!=NULL)
data["hadBySlot_Kit"]=hadBySlot_Kit->getname();
if(hasSlot_PartRefAndPose!=NULL)
data["hasSlot_PartRefAndPose"]=hasSlot_PartRefAndPose->getname();
if(hasSlot_Part!=NULL)
data["hasSlot_Part"]=hasSlot_Part->getname();
dao  = new DAO("Slot");
dao->set(data);
delete (dao);
}
void Slot::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

DataThing* temp0 = (DataThing*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getDataThingID();
data["SlotID"]=ss.str();
if(hadBySlot_Kit!=NULL)
data["hadBySlot_Kit"]=hadBySlot_Kit->getname();
if(hasSlot_PartRefAndPose!=NULL)
data["hasSlot_PartRefAndPose"]=hasSlot_PartRefAndPose->getname();
if(hasSlot_Part!=NULL)
data["hasSlot_Part"]=hasSlot_Part->getname();
dao  = new DAO("Slot");
dao->insert(data);
delete (dao);
this->set(name);
}

void Slot::copy(std::map<std::string,std::string> object){delete(hadBySlot_Kit);
hadBySlot_Kit=NULL;
delete(hasSlot_PartRefAndPose);
hasSlot_PartRefAndPose=NULL;
delete(hasSlot_Part);
hasSlot_Part=NULL;
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Slot*> tmp;
this->name = object["Slot._NAME"];
this->SlotID = std::atof(object["Slot.SlotID"].c_str());
if(this->hadBySlot_Kit== NULL && object["hadBySlot_Kit/Kit._NAME"]!=""){
this->hadBySlot_Kit = new Kit(object["hadBySlot_Kit/Kit._NAME"]);
}
if(this->hasSlot_PartRefAndPose== NULL && object["hasSlot_PartRefAndPose/PartRefAndPose._NAME"]!=""){
this->hasSlot_PartRefAndPose = new PartRefAndPose(object["hasSlot_PartRefAndPose/PartRefAndPose._NAME"]);
}
if(this->hasSlot_Part== NULL && object["hasSlot_Part/Part._NAME"]!=""){
this->hasSlot_Part = new Part(object["hasSlot_Part/Part._NAME"]);
}

}std::vector<std::string> Slot::Explode(const std::string & str, char separator )
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
