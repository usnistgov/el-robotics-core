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


#ifndef ENDEFFECTOR_H_
#define ENDEFFECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "NoSkuObject.h"
 class Robot;
 class StockKeepingUnit;
 class DAO;
 class SolidObject;
 class EndEffectorHolder;
class EndEffector: public NoSkuObject{private:
std::string hasEndEffector_Description;
double hasEndEffector_Weight;
double hasEndEffector_MaximumLoadWeight;
int EndEffectorID;
DAO* dao;
SolidObject* hasEndEffector_HeldObject;
Robot* hadByEndEffector_Robot;
EndEffectorHolder* hasEndEffectorHolder_EndEffector;
std::vector<StockKeepingUnit*> hasStockKeepingUnit_EndEffector;
public:
EndEffector(std::string name);
~EndEffector();
 void get(int id);
 void get(std::string name);
void set(int id, EndEffector* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasEndEffector_Description();
void sethasEndEffector_Description(std::string _hasEndEffector_Description);
double gethasEndEffector_Weight();
void sethasEndEffector_Weight(double _hasEndEffector_Weight);
double gethasEndEffector_MaximumLoadWeight();
void sethasEndEffector_MaximumLoadWeight(double _hasEndEffector_MaximumLoadWeight);
int getEndEffectorID();
void setEndEffectorID(int _EndEffectorID);
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethasEndEffector_HeldObject();
void sethasEndEffector_HeldObject(SolidObject* _hasEndEffector_HeldObject);
Robot* gethadByEndEffector_Robot();
void sethadByEndEffector_Robot(Robot* _hadByEndEffector_Robot);
EndEffectorHolder* gethasEndEffectorHolder_EndEffector();
void sethasEndEffectorHolder_EndEffector(EndEffectorHolder* _hasEndEffectorHolder_EndEffector);
std::vector<StockKeepingUnit*> gethasStockKeepingUnit_EndEffector();
void sethasStockKeepingUnit_EndEffector(std::vector<StockKeepingUnit*> _hasStockKeepingUnit_EndEffector);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ENDEFFECTOR_H_ */