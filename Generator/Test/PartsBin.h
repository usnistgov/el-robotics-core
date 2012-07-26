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


#ifndef PARTSBIN_H_
#define PARTSBIN_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "BoxyObject.h"
 class DAO;
class PartsBin: public BoxyObject{private:
std::string hasBin_PartQuantity;
std::string hasBin_PartSkuRef;
int PartsBinID;
DAO* dao;
public:
PartsBin(std::string name);
~PartsBin();
 void get(int id);
 void get(std::string name);
void set(int id, PartsBin* obj);
void set(std::string name);
std::string gethasBin_PartQuantity();
void sethasBin_PartQuantity(std::string _hasBin_PartQuantity);
std::string gethasBin_PartSkuRef();
void sethasBin_PartSkuRef(std::string _hasBin_PartSkuRef);
int getPartsBinID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSBIN_H_ */