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


#ifndef INTERNALSHAPE_H_
#define INTERNALSHAPE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "ShapeDesign.h"
 class DAO;
 class SolidObject;
class InternalShape: public ShapeDesign{private:
int InternalShapeID;
DAO* dao;
SolidObject* hadByInternalShape_SolidObject;
public:
InternalShape(std::string name);
~InternalShape();
 void get(int id);
 void get(std::string name);
void set(int id, InternalShape* obj);
void set(std::string name);
int getInternalShapeID();
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethadByInternalShape_SolidObject();
void sethadByInternalShape_SolidObject(SolidObject* _hadByInternalShape_SolidObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* INTERNALSHAPE_H_ */