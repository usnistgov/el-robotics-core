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


#ifndef POSELOCATIONON_H_
#define POSELOCATIONON_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "PoseLocation.h"
 class DAO;
class PoseLocationOn: public PoseLocation{private:
int PoseLocationOnID;
DAO* dao;
public:
PoseLocationOn(std::string name);
~PoseLocationOn();
 void get(int id);
 void get(std::string name);
void set(int id, PoseLocationOn* obj);
void set(std::string name);
int getPoseLocationOnID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POSELOCATIONON_H_ */