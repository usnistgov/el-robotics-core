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

#include "PartsTrayWithParts.h"


 #include "DAO.h"
 #include "Part.h"
 #include "PartsTray.h"

PartsTrayWithParts::PartsTrayWithParts(std::string name) : SolidObject(name){
dao = NULL;
hasPartsTrayWithParts_PartsTray = NULL;

}PartsTrayWithParts::~PartsTrayWithParts(){
delete(hasPartsTrayWithParts_PartsTray);
for(std::size_t i = 0; i < hadByPart_PartsTrayWithParts.size(); i++)
delete(hadByPart_PartsTrayWithParts[i]);
}
int PartsTrayWithParts::getPartsTrayWithPartsID(){
return PartsTrayWithPartsID;
}
DAO* PartsTrayWithParts::getdao(){
return dao;
}
PartsTray* PartsTrayWithParts::gethasPartsTrayWithParts_PartsTray(){
return hasPartsTrayWithParts_PartsTray;
}
std::vector<Part*> PartsTrayWithParts::gethadByPart_PartsTrayWithParts(){
return hadByPart_PartsTrayWithParts;
}
void PartsTrayWithParts::setPartsTrayWithPartsID(int _PartsTrayWithPartsID){
this->PartsTrayWithPartsID= _PartsTrayWithPartsID;
}
void PartsTrayWithParts::setdao(DAO* _dao){
this->dao= _dao;
}
void PartsTrayWithParts::sethasPartsTrayWithParts_PartsTray(PartsTray* _hasPartsTrayWithParts_PartsTray){
this->hasPartsTrayWithParts_PartsTray= _hasPartsTrayWithParts_PartsTray;
}
void PartsTrayWithParts::sethadByPart_PartsTrayWithParts(std::vector<Part*> _hadByPart_PartsTrayWithParts){
this->hadByPart_PartsTrayWithParts= _hadByPart_PartsTrayWithParts;
}
void PartsTrayWithParts::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("PartsTrayWithParts");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void PartsTrayWithParts::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]="'" + name + "'";
ss.str("");
ss << PartsTrayWithPartsID;
data["PartsTrayWithPartsID"]=ss.str();
if(hasPartsTrayWithParts_PartsTray!=NULL)
data["hasPartsTrayWithParts_PartsTray"]=hasPartsTrayWithParts_PartsTray->getname();
for(unsigned int i=0;i<hadByPart_PartsTrayWithParts.size();++i){
ss.str("");
hadByPart_PartsTrayWithParts[i]->get(hadByPart_PartsTrayWithParts[i]->getname());
ss << hadByPart_PartsTrayWithParts[i]->getPartID();
data["hadByPart_PartsTrayWithParts"]=data["hadByPart_PartsTrayWithParts"]+" "+ss.str();
}
dao  = new DAO("PartsTrayWithParts");
dao->set(data);
delete (dao);
}
void PartsTrayWithParts::insert(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
data["_Name"]="'" + name + "'";

SolidObject* temp0 = (SolidObject*) this;
temp0->insert(name);
temp0->get(name);
ss.str("");
ss << temp0->getSolidObjectID();
data["PartsTrayWithPartsID"]=ss.str();
if(hasPartsTrayWithParts_PartsTray!=NULL)
data["hasPartsTrayWithParts_PartsTray"]=hasPartsTrayWithParts_PartsTray->getname();
dao  = new DAO("PartsTrayWithParts");
dao->insert(data);
delete (dao);
this->set(name);
}

void PartsTrayWithParts::copy(std::map<std::string,std::string> object){delete(hasPartsTrayWithParts_PartsTray);
hasPartsTrayWithParts_PartsTray=NULL;
for(std::size_t i = 0; i < hadByPart_PartsTrayWithParts.size(); i++){
delete(hadByPart_PartsTrayWithParts[i]);
hadByPart_PartsTrayWithParts[i]=NULL;}
std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<PartsTrayWithParts*> tmp;
this->name = object["PartsTrayWithParts._NAME"];
this->PartsTrayWithPartsID = std::atof(object["PartsTrayWithParts.PartsTrayWithPartsID"].c_str());
if(this->hasPartsTrayWithParts_PartsTray== NULL && object["hasPartsTrayWithParts_PartsTray/PartsTray._NAME"]!=""){
this->hasPartsTrayWithParts_PartsTray = new PartsTray(object["hasPartsTrayWithParts_PartsTray/PartsTray._NAME"]);
}
if(this->hadByPart_PartsTrayWithParts.empty() && object["hadByPart_PartsTrayWithParts/Part._NAME"]!=""){
temp = Explode(object["hadByPart_PartsTrayWithParts/Part._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByPart_PartsTrayWithParts.push_back(new Part(temp[i]));
}
}

}std::vector<std::string> PartsTrayWithParts::Explode(const std::string & str, char separator )
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
