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


#ifndef PARTSTRAY_H_
#define PARTSTRAY_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class StockKeepingUnit;
 class PartsTrayWithParts;
 class DAO;
class PartsTray: public SolidObject{private:
std::string hasPartsTray_PartQuantity;
std::string hasPartsTray_SerialNumber;
int PartsTrayID;
DAO* dao;
StockKeepingUnit* hasPartsTray_Sku;
StockKeepingUnit* hasPartsTray_PartSku;
PartsTrayWithParts* hasPartsTrayWithParts_PartsTray;
public:
PartsTray(std::string name);
~PartsTray();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTray* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasPartsTray_PartQuantity();
void sethasPartsTray_PartQuantity(std::string _hasPartsTray_PartQuantity);
std::string gethasPartsTray_SerialNumber();
void sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber);
int getPartsTrayID();
void setPartsTrayID(int _PartsTrayID);
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethasPartsTray_Sku();
void sethasPartsTray_Sku(StockKeepingUnit* _hasPartsTray_Sku);
StockKeepingUnit* gethasPartsTray_PartSku();
void sethasPartsTray_PartSku(StockKeepingUnit* _hasPartsTray_PartSku);
PartsTrayWithParts* gethasPartsTrayWithParts_PartsTray();
void sethasPartsTrayWithParts_PartsTray(PartsTrayWithParts* _hasPartsTrayWithParts_PartsTray);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAY_H_ */