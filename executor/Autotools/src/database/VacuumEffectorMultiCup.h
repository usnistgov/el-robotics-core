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


#ifndef VACUUMEFFECTORMULTICUP_H_
#define VACUUMEFFECTORMULTICUP_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "VacuumEffector.h"
 class DAO;
class VacuumEffectorMultiCup: public VacuumEffector{private:
std::string hasMultiCup_ArrayNumber;
double hasMultiCup_ArrayRadius;
int VacuumEffectorMultiCupID;
DAO* dao;
public:
VacuumEffectorMultiCup(std::string name);
~VacuumEffectorMultiCup();
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffectorMultiCup* obj);
void set(std::string name);
std::string gethasMultiCup_ArrayNumber();
void sethasMultiCup_ArrayNumber(std::string _hasMultiCup_ArrayNumber);
double gethasMultiCup_ArrayRadius();
void sethasMultiCup_ArrayRadius(double _hasMultiCup_ArrayRadius);
int getVacuumEffectorMultiCupID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VACUUMEFFECTORMULTICUP_H_ */