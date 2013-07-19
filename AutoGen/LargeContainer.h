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


#ifndef LARGECONTAINER_H_
#define LARGECONTAINER_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class StockKeepingUnit;
 class LargeBoxWithKits;
 class LargeBoxWithEmptyKitTrays;
 class DAO;
class LargeContainer: public SolidObject{private:
std::string hasLargeContainer_SerialNumber;
int LargeContainerID;
DAO* dao;
LargeBoxWithKits* hasLargeBoxWithKits_LargeContainer;
StockKeepingUnit* hasLargeContainer_Sku;
LargeBoxWithEmptyKitTrays* hasLargeBoxWithEmptyKitTrays_LargeContainer;
public:
LargeContainer(std::string name);
~LargeContainer();
 void get(int id);
 void get(std::string name);
void set(int id, LargeContainer* obj);
void set(std::string name);
std::string gethasLargeContainer_SerialNumber();
void sethasLargeContainer_SerialNumber(std::string _hasLargeContainer_SerialNumber);
int getLargeContainerID();
DAO* getdao();
void setdao(DAO* _dao);
LargeBoxWithKits* gethasLargeBoxWithKits_LargeContainer();
void sethasLargeBoxWithKits_LargeContainer(LargeBoxWithKits* _hasLargeBoxWithKits_LargeContainer);
StockKeepingUnit* gethasLargeContainer_Sku();
void sethasLargeContainer_Sku(StockKeepingUnit* _hasLargeContainer_Sku);
LargeBoxWithEmptyKitTrays* gethasLargeBoxWithEmptyKitTrays_LargeContainer();
void sethasLargeBoxWithEmptyKitTrays_LargeContainer(LargeBoxWithEmptyKitTrays* _hasLargeBoxWithEmptyKitTrays_LargeContainer);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* LARGECONTAINER_H_ */