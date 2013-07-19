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


#ifndef RELATIVELOCATION_H_
#define RELATIVELOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "PhysicalLocation.h"
 class DAO;
class RelativeLocation: public PhysicalLocation{private:
std::string hasRelativeLocation_Description;
int RelativeLocationID;
DAO* dao;
public:
RelativeLocation(std::string name);
~RelativeLocation();
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocation* obj);
void set(std::string name);
std::string gethasRelativeLocation_Description();
void sethasRelativeLocation_Description(std::string _hasRelativeLocation_Description);
int getRelativeLocationID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATION_H_ */