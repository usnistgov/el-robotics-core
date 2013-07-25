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

#include "CylindricalShape.h"


 #include "DAO.h"

CylindricalShape::CylindricalShape(std::string name) : InternalShape(name){
dao = NULL;

}CylindricalShape::~CylindricalShape(){
}
double CylindricalShape::gethasCylindricalShape_Height(){
return hasCylindricalShape_Height;
}
bool CylindricalShape::gethasCylindricalShape_HasTop(){
return hasCylindricalShape_HasTop;
}
double CylindricalShape::gethasCylindricalShape_Diameter(){
return hasCylindricalShape_Diameter;
}
int CylindricalShape::getCylindricalShapeID(){
return CylindricalShapeID;
}
DAO* CylindricalShape::getdao(){
return dao;
}
void CylindricalShape::sethasCylindricalShape_Height(double _hasCylindricalShape_Height){
this->hasCylindricalShape_Height= _hasCylindricalShape_Height;
}
void CylindricalShape::sethasCylindricalShape_HasTop(bool _hasCylindricalShape_HasTop){
this->hasCylindricalShape_HasTop= _hasCylindricalShape_HasTop;
}
void CylindricalShape::sethasCylindricalShape_Diameter(double _hasCylindricalShape_Diameter){
this->hasCylindricalShape_Diameter= _hasCylindricalShape_Diameter;
}
void CylindricalShape::setdao(DAO* _dao){
this->dao= _dao;
}
void CylindricalShape::get(std::string name){
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
dao  = new DAO("CylindricalShape");
 temp = dao->get(name);
delete (dao); 
copy(temp);
}
 void CylindricalShape::set(std::string name){
std::map<std::string, std::string> data;
std::stringstream ss;
InternalShape* temp0 = (InternalShape*) this;
temp0->set(name);
ShapeDesign* temp1 = (ShapeDesign*) this;
temp1->set(name);
DataThing* temp2 = (DataThing*) this;
temp2->set(name);
ss.str("");
ss << hasCylindricalShape_Height;
data["hasCylindricalShape_Height"]=ss.str();
ss.str("");
ss << hasCylindricalShape_HasTop;
data["hasCylindricalShape_HasTop"]=ss.str();
ss.str("");
ss << hasCylindricalShape_Diameter;
data["hasCylindricalShape_Diameter"]=ss.str();
data["name"]=name;
ss.str("");
ss << CylindricalShapeID;
data["CylindricalShapeID"]=ss.str();
dao  = new DAO("CylindricalShape");
dao->set(data);
delete (dao);
}

void CylindricalShape::copy(std::map<std::string,std::string> object){std::vector<std::string> temp;
std::map<std::string,std::string> mapTemp;
std::map<std::string,std::string> mapTempBis;
int nbVal=0;
int nbValCurrent=0;
std::vector<CylindricalShape*> tmp;
this->hasCylindricalShape_Height = std::atof(object["CylindricalShape.hasCylindricalShape_Height"].c_str());
this->hasCylindricalShape_HasTop = std::atof(object["CylindricalShape.hasCylindricalShape_HasTop"].c_str());
this->hasCylindricalShape_Diameter = std::atof(object["CylindricalShape.hasCylindricalShape_Diameter"].c_str());
this->name = object["CylindricalShape._NAME"];
this->CylindricalShapeID = std::atof(object["CylindricalShape.CylindricalShapeID"].c_str());

}std::vector<std::string> CylindricalShape::Explode(const std::string & str, char separator )
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
