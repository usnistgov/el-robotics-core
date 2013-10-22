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


#ifndef NOSKUOBJECT_H_
#define NOSKUOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class ExternalShape;
 class DAO;
 class InternalShape;
class NoSkuObject: public SolidObject{private:
int NoSkuObjectID;
DAO* dao;
InternalShape* hasNoSkuObject_InternalShape;
ExternalShape* hadByExternalShape_NoSkuObject;
public:
NoSkuObject(std::string name);
~NoSkuObject();
 void get(int id);
 void get(std::string name);
void set(int id, NoSkuObject* obj);
void set(std::string name);
void insert(std::string name);
int getNoSkuObjectID();
void setNoSkuObjectID(int _NoSkuObjectID);
DAO* getdao();
void setdao(DAO* _dao);
InternalShape* gethasNoSkuObject_InternalShape();
void sethasNoSkuObject_InternalShape(InternalShape* _hasNoSkuObject_InternalShape);
ExternalShape* gethadByExternalShape_NoSkuObject();
void sethadByExternalShape_NoSkuObject(ExternalShape* _hadByExternalShape_NoSkuObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* NOSKUOBJECT_H_ */