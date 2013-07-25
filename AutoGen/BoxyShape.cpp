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

#include "BoxyShape.h"


 #include "DAO.h"

BoxyShape::BoxyShape(std::string name) : InternalShape(name){
dao = NULL;

}BoxyShape::~BoxyShape(){
}
double BoxyShape::gethasBoxyShape_Width(){
return hasBoxyShape_Width;
}
double BoxyShape::gethasBoxyShape_Height(){
return hasBoxyShape_Height;
}
double BoxyShape::gethasBoxyShape_Length(){
return hasBoxyShape_Length;
}
bool BoxyShape::gethasBoxyShape_HasTop(){
return hasBoxyShape_HasTop;
}
int BoxyShape::getBoxyShapeID(){
return BoxyShapeID;
}
DAO* BoxyShape::getdao(){
return dao;
}
void BoxyShape::sethasBoxyShape_Width(double _hasBoxyShape_Width){
this->hasBoxyShape_Width= _hasBoxyShape_Width;
}
void BoxyShape::sethasBoxyShape_Height(double _hasBoxyShape_Height){
this->hasBoxyShape_Height= _hasBoxyShape_Height;
}
void BoxyShape::sethasBoxyShape_Length(double _hasBoxyShape_Length){
this->hasBoxyShape_Length= _hasBoxyShape_Length;
}
void BoxyShape::sethasBoxyShape_HasTop(bool _hasBoxyShape_HasTop){
this->hasBoxyShape_HasTop= _hasBoxyShape_HasTop;
}
void BoxyShape::setdao(DAO* _dao){
this->dao= _dao;
}
void BoxyShape::get(std::string name){
std::map<std::string,std::string> temp;
dao  = new DAO("InternalShape");
 temp = dao->get(name);delete (dao);
 InternalShape::copy(temp);
dao  = new DAO("ShapeDesign");
 temp = dao->get(name);delete (dao);
 ShapeDesign::copy(temp);
dao  = new DAO("DataThing");
 temp = dao->get(name);delete (dao);
 DataThing::copy(temp);
dao  = new DAO("BoxyShape");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void BoxyShape::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
InternalShape* temp0 = (InternalShape*) this;
temp0->set(name);
ShapeDesign* temp1 = (ShapeDesign*) this;
temp1->set(name);
DataThing* temp2 = (DataThing*) this;
temp2->set(name);
ss.str("");
ss << hasBoxyShape_Width;
data["hasBoxyShape_Width"]=ss.str();
ss.str("");
ss << hasBoxyShape_Height;
data["hasBoxyShape_Height"]=ss.str();
ss.str("");
ss << hasBoxyShape_Length;
data["hasBoxyShape_Length"]=ss.str();
ss.str("");
ss << hasBoxyShape_HasTop;
data["hasBoxyShape_HasTop"]=ss.str();
data["name"]=name;
ss.str("");
ss << BoxyShapeID;
data["BoxyShapeID"]=ss.str();
dao  = new DAO("BoxyShape");
dao->set(data);
delete (dao);
}

void BoxyShape::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<BoxyShape*> tmp;
this->hasBoxyShape_Width = std::atof(object["BoxyShape.hasBoxyShape_Width"].c_str());
this->hasBoxyShape_Height = std::atof(object["BoxyShape.hasBoxyShape_Height"].c_str());
this->hasBoxyShape_Length = std::atof(object["BoxyShape.hasBoxyShape_Length"].c_str());
this->hasBoxyShape_HasTop = std::atof(object["BoxyShape.hasBoxyShape_HasTop"].c_str());
this->name = object["BoxyShape._NAME"];
this->BoxyShapeID = std::atof(object["BoxyShape.BoxyShapeID"].c_str());

}std::vector<std::string> BoxyShape::Explode(const std::string & str, char separator )
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
