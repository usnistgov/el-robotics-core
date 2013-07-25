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

#include "Human.h"


 #include "DAO.h"

Human::Human(std::string name) : SolidObject(name){
dao = NULL;

}Human::~Human(){
}
int Human::getHumanID(){
return HumanID;
}
DAO* Human::getdao(){
return dao;
}
void Human::setdao(DAO* _dao){
this->dao= _dao;
}
void Human::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("SolidObject");
 temp = dao->get(name);delete (dao);
 SolidObject::copy(temp);
dao  = new DAO("Human");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void Human::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
SolidObject* temp0 = (SolidObject*) this;
temp0->set(name);
data["name"]=name;
ss.str("");
ss << HumanID;
data["HumanID"]=ss.str();
dao  = new DAO("Human");
dao->set(data);
delete (dao);
}

void Human::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<Human*> tmp;
this->name = object["Human._NAME"];
this->HumanID = std::atof(object["Human.HumanID"].c_str());

}std::vector<std::string> Human::Explode(const std::string & str, char separator )
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
