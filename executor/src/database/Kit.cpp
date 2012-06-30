#include "Kit.h"


 #include "LargeBoxWithKits.h"
 #include "KitTray.h"
 #include "DAO.h"
 #include "Part.h"

Kit::Kit(std::string name) : SolidObject(name){
this->name=name;dao = NULL;
hadByKit_LargeBoxWithKits = NULL;
hasKit_Tray = NULL;

}Kit::~Kit(){
delete(dao);
delete(hadByKit_LargeBoxWithKits);
delete(hasKit_Tray);
for(std::size_t i = 0; i < hadByPart_Kit.size(); i++)
delete(hadByPart_Kit[i]);
}
std::string Kit::gethasKit_DesignRef(){
return hasKit_DesignRef;
}
bool Kit::getisKit_Finished(){
return isKit_Finished;
}
std::string Kit::getname(){
return name;
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
KitTray* Kit::gethasKit_Tray(){
return hasKit_Tray;
}
std::vector<Part*>* Kit::gethadByPart_Kit(){
return &hadByPart_Kit;
}
void Kit::sethasKit_DesignRef(std::string _hasKit_DesignRef){
this->hasKit_DesignRef= _hasKit_DesignRef;
}
void Kit::setisKit_Finished(bool _isKit_Finished){
this->isKit_Finished= _isKit_Finished;
}
void Kit::setdao(DAO* _dao){
this->dao= _dao;
}
void Kit::sethadByKit_LargeBoxWithKits(LargeBoxWithKits* _hadByKit_LargeBoxWithKits){
this->hadByKit_LargeBoxWithKits= _hadByKit_LargeBoxWithKits;
}
void Kit::sethasKit_Tray(KitTray* _hasKit_Tray){
this->hasKit_Tray= _hasKit_Tray;
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
data["hasKit_DesignRef"]=hasKit_DesignRef;
data["isKit_Finished"]=isKit_Finished;
data["name"]=name;
data["KitID"]=KitID;
data["hadByKit_LargeBoxWithKits"]=hadByKit_LargeBoxWithKits->getname();
data["hasKit_Tray"]=hasKit_Tray->getname();
for(unsigned int i=0;i<hadByPart_Kit.size();++i){
ss.flush();
ss << hadByPart_Kit[i]->getPartID();
data["hadByPart_Kit"]=data["hadByPart_Kit"]+" "+ss.str();
}
dao  = new DAO("Kit");
dao->set(data);
delete (dao);
}

void Kit::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Kit*> tmp;
this->hasKit_DesignRef = object["Kit.hasKit_DesignRef"];
this->isKit_Finished = std::atof(object["Kit.isKit_Finished"].c_str());
this->name = object["Kit._NAME"];
this->KitID = std::atof(object["Kit.KitID"].c_str());
if(this->hadByKit_LargeBoxWithKits== NULL && object["hadByKit_LargeBoxWithKits/LargeBoxWithKits._NAME"]!=""){
this->hadByKit_LargeBoxWithKits = new LargeBoxWithKits(object["hadByKit_LargeBoxWithKits/LargeBoxWithKits._NAME"]);
}
if(this->hasKit_Tray== NULL && object["hasKit_Tray/KitTray._NAME"]!=""){
this->hasKit_Tray = new KitTray(object["hasKit_Tray/KitTray._NAME"]);
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
