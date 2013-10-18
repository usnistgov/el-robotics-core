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


#ifndef HUMAN_H_
#define HUMAN_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "NoSkuObject.h"
 class DAO;
class Human: public NoSkuObject{private:
int HumanID;
DAO* dao;
public:
Human(std::string name);
~Human();
 void get(int id);
 void get(std::string name);
void set(int id, Human* obj);
void set(std::string name);
void insert(std::string name);
int getHumanID();
void setHumanID(int _HumanID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* HUMAN_H_ */