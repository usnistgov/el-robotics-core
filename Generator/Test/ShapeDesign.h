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


#ifndef SHAPEDESIGN_H_
#define SHAPEDESIGN_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class StockKeepingUnit;
 class DAO;
class ShapeDesign: public DataThing{private:
std::string hasShapeDesign_Description;
int ShapeDesignID;
DAO* dao;
std::vector<StockKeepingUnit*> hasSku_Shape;
public:
ShapeDesign(std::string name);
~ShapeDesign();
 void get(int id);
 void get(std::string name);
void set(int id, ShapeDesign* obj);
void set(std::string name);
std::string gethasShapeDesign_Description();
void sethasShapeDesign_Description(std::string _hasShapeDesign_Description);
int getShapeDesignID();
DAO* getdao();
void setdao(DAO* _dao);
std::vector<StockKeepingUnit*>* gethasSku_Shape();
void sethasSku_Shape(std::vector<StockKeepingUnit*> _hasSku_Shape);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SHAPEDESIGN_H_ */