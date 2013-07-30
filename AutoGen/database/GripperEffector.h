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


#ifndef GRIPPEREFFECTOR_H_
#define GRIPPEREFFECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "EndEffector.h"
 class DAO;
class GripperEffector: public EndEffector{private:
int GripperEffectorID;
DAO* dao;
public:
GripperEffector(std::string name);
~GripperEffector();
 void get(int id);
 void get(std::string name);
void set(int id, GripperEffector* obj);
void set(std::string name);
void insert(std::string name);
int getGripperEffectorID();
void setGripperEffectorID(int _GripperEffectorID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* GRIPPEREFFECTOR_H_ */