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


#ifndef VACUUMEFFECTOR_H_
#define VACUUMEFFECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "EndEffector.h"
 class DAO;
class VacuumEffector: public EndEffector{private:
double hasVacuumEffector_CupDiameter;
double hasVacuumEffector_Length;
int VacuumEffectorID;
DAO* dao;
public:
VacuumEffector(std::string name);
~VacuumEffector();
 void get(int id);
 void get(std::string name);
void set(int id, VacuumEffector* obj);
void set(std::string name);
void insert(std::string name);
double gethasVacuumEffector_CupDiameter();
void sethasVacuumEffector_CupDiameter(double _hasVacuumEffector_CupDiameter);
double gethasVacuumEffector_Length();
void sethasVacuumEffector_Length(double _hasVacuumEffector_Length);
int getVacuumEffectorID();
void setVacuumEffectorID(int _VacuumEffectorID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VACUUMEFFECTOR_H_ */