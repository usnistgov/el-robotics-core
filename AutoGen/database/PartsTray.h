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


#include "PartsVessel.h"
 class DAO;
class PartsTray: public PartsVessel{private:
int PartsTrayID;
DAO* dao;
public:
PartsTray(std::string name);
~PartsTray();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTray* obj);
void set(std::string name);
void insert(std::string name);
int getPartsTrayID();
void setPartsTrayID(int _PartsTrayID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAY_H_ */