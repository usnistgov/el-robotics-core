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


#ifndef CYLINDRICALSHAPE_H_
#define CYLINDRICALSHAPE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "InternalShape.h"
 class DAO;
class CylindricalShape: public InternalShape{private:
double hasCylindricalShape_Height;
bool hasCylindricalShape_HasTop;
double hasCylindricalShape_Diameter;
int CylindricalShapeID;
DAO* dao;
public:
CylindricalShape(std::string name);
~CylindricalShape();
 void get(int id);
 void get(std::string name);
void set(int id, CylindricalShape* obj);
void set(std::string name);
double gethasCylindricalShape_Height();
void sethasCylindricalShape_Height(double _hasCylindricalShape_Height);
bool gethasCylindricalShape_HasTop();
void sethasCylindricalShape_HasTop(bool _hasCylindricalShape_HasTop);
double gethasCylindricalShape_Diameter();
void sethasCylindricalShape_Diameter(double _hasCylindricalShape_Diameter);
int getCylindricalShapeID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* CYLINDRICALSHAPE_H_ */