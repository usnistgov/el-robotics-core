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


#ifndef PHYSICALLOCATION_H_
#define PHYSICALLOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class DAO;
 class SolidObject;
class PhysicalLocation: public DataThing{private:
std::string hasPhysicalLocation_Timestamp;
int PhysicalLocationID;
DAO* dao;
SolidObject* hadBySecondaryLocation_SolidObject;
SolidObject* hasPhysicalLocation_RefObject;
SolidObject* hasSolidObject_PrimaryLocation;
public:
PhysicalLocation(std::string name);
~PhysicalLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PhysicalLocation* obj);
void set(std::string name);
std::string gethasPhysicalLocation_Timestamp();
void sethasPhysicalLocation_Timestamp(std::string _hasPhysicalLocation_Timestamp);
int getPhysicalLocationID();
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethadBySecondaryLocation_SolidObject();
void sethadBySecondaryLocation_SolidObject(SolidObject* _hadBySecondaryLocation_SolidObject);
SolidObject* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject);
SolidObject* gethasSolidObject_PrimaryLocation();
void sethasSolidObject_PrimaryLocation(SolidObject* _hasSolidObject_PrimaryLocation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PHYSICALLOCATION_H_ */