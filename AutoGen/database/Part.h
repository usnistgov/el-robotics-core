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


#ifndef PART_H_
#define PART_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class StockKeepingUnit;
 class PartsTrayWithParts;
 class Slot;
 class Kit;
 class DAO;
class Part: public SolidObject{private:
std::string hasPart_SerialNumber;
int PartID;
DAO* dao;
Kit* hadByPart_Kit;
PartsTrayWithParts* hadByPart_PartsTrayWithParts;
StockKeepingUnit* hasPart_Sku;
std::vector<Slot*> hasSlot_Part;
public:
Part(std::string name);
~Part();
 void get(int id);
 void get(std::string name);
void set(int id, Part* obj);
void set(std::string name);
std::string gethasPart_SerialNumber();
void sethasPart_SerialNumber(std::string _hasPart_SerialNumber);
int getPartID();
DAO* getdao();
void setdao(DAO* _dao);
Kit* gethadByPart_Kit();
void sethadByPart_Kit(Kit* _hadByPart_Kit);
PartsTrayWithParts* gethadByPart_PartsTrayWithParts();
void sethadByPart_PartsTrayWithParts(PartsTrayWithParts* _hadByPart_PartsTrayWithParts);
StockKeepingUnit* gethasPart_Sku();
void sethasPart_Sku(StockKeepingUnit* _hasPart_Sku);
std::vector<Slot*> gethasSlot_Part();
void sethasSlot_Part(std::vector<Slot*> _hasSlot_Part);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PART_H_ */