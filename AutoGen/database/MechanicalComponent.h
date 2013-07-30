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


#ifndef MECHANICALCOMPONENT_H_
#define MECHANICALCOMPONENT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class EndEffectorChangingStation;
 class DAO;
class MechanicalComponent: public SolidObject{private:
int MechanicalComponentID;
DAO* dao;
EndEffectorChangingStation* hasEndEffectorChangingStation_Base;
public:
MechanicalComponent(std::string name);
~MechanicalComponent();
 void get(int id);
 void get(std::string name);
void set(int id, MechanicalComponent* obj);
void set(std::string name);
void insert(std::string name);
int getMechanicalComponentID();
void setMechanicalComponentID(int _MechanicalComponentID);
DAO* getdao();
void setdao(DAO* _dao);
EndEffectorChangingStation* gethasEndEffectorChangingStation_Base();
void sethasEndEffectorChangingStation_Base(EndEffectorChangingStation* _hasEndEffectorChangingStation_Base);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* MECHANICALCOMPONENT_H_ */