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


#ifndef BOXYSHAPE_H_
#define BOXYSHAPE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "InternalShape.h"
 class DAO;
class BoxyShape: public InternalShape{private:
double hasBoxyShape_Width;
double hasBoxyShape_Height;
double hasBoxyShape_Length;
bool hasBoxyShape_HasTop;
int BoxyShapeID;
DAO* dao;
public:
BoxyShape(std::string name);
~BoxyShape();
 void get(int id);
 void get(std::string name);
void set(int id, BoxyShape* obj);
void set(std::string name);
double gethasBoxyShape_Width();
void sethasBoxyShape_Width(double _hasBoxyShape_Width);
double gethasBoxyShape_Height();
void sethasBoxyShape_Height(double _hasBoxyShape_Height);
double gethasBoxyShape_Length();
void sethasBoxyShape_Length(double _hasBoxyShape_Length);
bool gethasBoxyShape_HasTop();
void sethasBoxyShape_HasTop(bool _hasBoxyShape_HasTop);
int getBoxyShapeID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* BOXYSHAPE_H_ */