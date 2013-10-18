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


#include "PartsVessel.h"
 class DAO;
class PartsBin: public PartsVessel{private:
int PartsBinID;
DAO* dao;
public:
PartsBin(std::string name);
~PartsBin();
 void get(int id);
 void get(std::string name);
void set(int id, PartsBin* obj);
void set(std::string name);
void insert(std::string name);
int getPartsBinID();
void setPartsBinID(int _PartsBinID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSBIN_H_ */