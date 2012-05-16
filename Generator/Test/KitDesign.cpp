#include "KitDesign.h"

KitDesign::KitDesign(std::string name) : DataThing(name){
this->name=name;
}KitDesign::~KitDesign(){
delete(dao);
}
std::string KitDesign::gethasKitDesign_Id(){
return this->hasKitDesign_Id;
}
std::string KitDesign::gethasKitDesign_KitTraySkuRef(){
return this->hasKitDesign_KitTraySkuRef;
}
std::string KitDesign::getname(){
return this->name;
}
int KitDesign::getKitDesignID(){
return this->KitDesignID;
}
DAO* KitDesign::getdao(){
return this->dao;
}
void KitDesign::sethasKitDesign_Id(std::string _hasKitDesign_Id){
this->hasKitDesign_Id= _hasKitDesign_Id;
}
void KitDesign::sethasKitDesign_KitTraySkuRef(std::string _hasKitDesign_KitTraySkuRef){
this->hasKitDesign_KitTraySkuRef= _hasKitDesign_KitTraySkuRef;
}
void KitDesign::setname(std::string _name){
this->name= _name;
}
void KitDesign::setKitDesignID(int _KitDesignID){
this->KitDesignID= _KitDesignID;
}
void KitDesign::setdao(DAO* _dao){
this->dao= _dao;
}
void KitDesign::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("DataThing");
 temp = dao->get(name);
 DataThing::copy(temp);
delete (dao);
dao  = new DAO("KitDesign");
 temp = dao->get(name);
 copy(temp);
delete (dao);
}
 void KitDesign::set(std::string name){
 dao  = new DAO("KitDesign");
 dao->set(name);
delete (dao);
}

void KitDesign::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
this->hasKitDesign_Id = object["KitDesign.hasKitDesign_Id"];
this->hasKitDesign_KitTraySkuRef = object["KitDesign.hasKitDesign_KitTraySkuRef"];
this->name = object["KitDesign._NAME"];
this->KitDesignID = std::atof(object["KitDesign.KitDesignID"].c_str());

}std::vector<std::string> KitDesign::Explode(const std::string & str, char separator )
{
   std::vector< std::string > result;
   size_t pos1 = 0;
   size_t pos2 = 0;
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
