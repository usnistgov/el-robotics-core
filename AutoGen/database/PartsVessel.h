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


#ifndef PARTSVESSEL_H_
#define PARTSVESSEL_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SkuObject.h"
 class StockKeepingUnit;
 class DAO;
 class Part;
class PartsVessel: public SkuObject{private:
std::string hasPartsVessel_PartQuantity;
std::string hasPartsVessel_SerialNumber;
int PartsVesselID;
DAO* dao;
StockKeepingUnit* hasPartsVessel_PartSku;
std::vector<Part*> hadByPart_PartsVessel;
public:
PartsVessel(std::string name);
~PartsVessel();
 void get(int id);
 void get(std::string name);
void set(int id, PartsVessel* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasPartsVessel_PartQuantity();
void sethasPartsVessel_PartQuantity(std::string _hasPartsVessel_PartQuantity);
std::string gethasPartsVessel_SerialNumber();
void sethasPartsVessel_SerialNumber(std::string _hasPartsVessel_SerialNumber);
int getPartsVesselID();
void setPartsVesselID(int _PartsVesselID);
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethasPartsVessel_PartSku();
void sethasPartsVessel_PartSku(StockKeepingUnit* _hasPartsVessel_PartSku);
std::vector<Part*> gethadByPart_PartsVessel();
void sethadByPart_PartsVessel(std::vector<Part*> _hadByPart_PartsVessel);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSVESSEL_H_ */