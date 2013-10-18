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


#ifndef EXTERNALSHAPE_H_
#define EXTERNALSHAPE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "ShapeDesign.h"
 class StockKeepingUnit;
 class NoSkuObject;
 class DAO;
class ExternalShape: public ShapeDesign{private:
std::string hasExternalShape_ModelFormatName;
std::string hasExternalShape_ModelName;
std::string hasExternalShape_ModelFileName;
int ExternalShapeID;
DAO* dao;
StockKeepingUnit* hadByExternalShape_StockKeepingUnit;
NoSkuObject* hadByExternalShape_NoSkuObject;
public:
ExternalShape(std::string name);
~ExternalShape();
 void get(int id);
 void get(std::string name);
void set(int id, ExternalShape* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasExternalShape_ModelFormatName();
void sethasExternalShape_ModelFormatName(std::string _hasExternalShape_ModelFormatName);
std::string gethasExternalShape_ModelName();
void sethasExternalShape_ModelName(std::string _hasExternalShape_ModelName);
std::string gethasExternalShape_ModelFileName();
void sethasExternalShape_ModelFileName(std::string _hasExternalShape_ModelFileName);
int getExternalShapeID();
void setExternalShapeID(int _ExternalShapeID);
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethadByExternalShape_StockKeepingUnit();
void sethadByExternalShape_StockKeepingUnit(StockKeepingUnit* _hadByExternalShape_StockKeepingUnit);
NoSkuObject* gethadByExternalShape_NoSkuObject();
void sethadByExternalShape_NoSkuObject(NoSkuObject* _hadByExternalShape_NoSkuObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* EXTERNALSHAPE_H_ */