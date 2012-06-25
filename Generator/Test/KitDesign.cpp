#include "KitDesign.h"


 #include "KittingWorkstation.h"
 #include "DAO.h"
 #include "PartRefAndPose.h"

KitDesign::KitDesign(std::string name) : DataThing(name){
this->name=name;dao = NULL;
hadByKitDesign_Workstation = NULL;

}KitDesign::~KitDesign(){
delete(dao);
delete(hadByKitDesign_Workstation);
for(std::size_t i = 0; i < hadByPartRefAndPose_KitDesign.size(); i++)
delete(hadByPartRefAndPose_KitDesign[i]);
}
std::string KitDesign::gethasKitDesign_Id(){
return hasKitDesign_Id;
}
std::string KitDesign::gethasKitDesign_KitTraySkuRef(){
return hasKitDesign_KitTraySkuRef;
}
std::string KitDesign::getname(){
return name;
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
std::vector<PartRefAndPose*>* KitDesign::gethadByPartRefAndPose_KitDesign(){
return &hadByPartRefAndPose_KitDesign;
}
void KitDesign::sethasKitDesign_Id(std::string _hasKitDesign_Id){
this->hasKitDesign_Id= _hasKitDesign_Id;
}
void KitDesign::sethasKitDesign_KitTraySkuRef(std::string _hasKitDesign_KitTraySkuRef){
this->hasKitDesign_KitTraySkuRef= _hasKitDesign_KitTraySkuRef;
}
void KitDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void KitDesign::sethadByKitDesign_Workstation(KittingWorkstation* _hadByKitDesign_Workstation){
this->hadByKitDesign_Workstation= _hadByKitDesign_Workstation;
}
void KitDesign::sethadByPartRefAndPose_KitDesign(std::vector<PartRefAndPose*> _hadByPartRefAndPose_KitDesign){
this->hadByPartRefAndPose_KitDesign= _hadByPartRefAndPose_KitDesign;
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
data["hasKitDesign_Id"]=hasKitDesign_Id;
data["hasKitDesign_KitTraySkuRef"]=hasKitDesign_KitTraySkuRef;
data["name"]=name;
data["KitDesignID"]=KitDesignID;
data["hadByKitDesign_Workstation"]=hadByKitDesign_Workstation->getname();
for(unsigned int i=0;i<hadByPartRefAndPose_KitDesign.size();++i){
ss.flush();
ss << hadByPartRefAndPose_KitDesign[i]->getPartRefAndPoseID();
data["hadByPartRefAndPose_KitDesign"]=data["hadByPartRefAndPose_KitDesign"]+" "+ss.str();
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
this->hasKitDesign_Id = object["KitDesign.hasKitDesign_Id"];
this->hasKitDesign_KitTraySkuRef = object["KitDesign.hasKitDesign_KitTraySkuRef"];
this->name = object["KitDesign._NAME"];
this->KitDesignID = std::atof(object["KitDesign.KitDesignID"].c_str());
if(this->hadByKitDesign_Workstation== NULL && object["hadByKitDesign_Workstation/KittingWorkstation._NAME"]!=""){
this->hadByKitDesign_Workstation = new KittingWorkstation(object["hadByKitDesign_Workstation/KittingWorkstation._NAME"]);
}
if(this->hadByPartRefAndPose_KitDesign.empty() && object["hadByPartRefAndPose_KitDesign/PartRefAndPose._NAME"]!=""){
temp = Explode(object["hadByPartRefAndPose_KitDesign/PartRefAndPose._NAME"], ' ' );
for(unsigned int i=0; i<temp.size();i++){
this->hadByPartRefAndPose_KitDesign.push_back(new PartRefAndPose(temp[i]));
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
