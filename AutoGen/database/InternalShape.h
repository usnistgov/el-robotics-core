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
 class StockKeepingUnit;
 class NoSkuObject;
 class DAO;
class InternalShape: public ShapeDesign{private:
int InternalShapeID;
DAO* dao;
StockKeepingUnit* hasStockKeepingUnit_InternalShape;
NoSkuObject* hasNoSkuObject_InternalShape;
public:
InternalShape(std::string name);
~InternalShape();
 void get(int id);
 void get(std::string name);
void set(int id, InternalShape* obj);
void set(std::string name);
void insert(std::string name);
int getInternalShapeID();
void setInternalShapeID(int _InternalShapeID);
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethasStockKeepingUnit_InternalShape();
void sethasStockKeepingUnit_InternalShape(StockKeepingUnit* _hasStockKeepingUnit_InternalShape);
NoSkuObject* gethasNoSkuObject_InternalShape();
void sethasNoSkuObject_InternalShape(NoSkuObject* _hasNoSkuObject_InternalShape);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* INTERNALSHAPE_H_ */