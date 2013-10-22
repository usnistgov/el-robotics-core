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


#ifndef SKUOBJECT_H_
#define SKUOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class StockKeepingUnit;
 class DAO;
class SkuObject: public SolidObject{private:
int SkuObjectID;
DAO* dao;
StockKeepingUnit* hasSkuObject_Sku;
public:
SkuObject(std::string name);
~SkuObject();
 void get(int id);
 void get(std::string name);
void set(int id, SkuObject* obj);
void set(std::string name);
void insert(std::string name);
int getSkuObjectID();
void setSkuObjectID(int _SkuObjectID);
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethasSkuObject_Sku();
void sethasSkuObject_Sku(StockKeepingUnit* _hasSkuObject_Sku);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SKUOBJECT_H_ */