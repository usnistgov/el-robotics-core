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
 class SolidObject;
 class DAO;
 class SolidObject;
class PhysicalLocation: public DataThing{private:
int PhysicalLocationID;
DAO* dao;
SolidObject* hasPhysicalLocation_RefObject;
std::vector<SolidObject*> hasSolidObject_SecondaryLocation;
std::vector<SolidObject*> hasSolidObject_PrimaryLocation;
public:
PhysicalLocation(std::string name);
~PhysicalLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PhysicalLocation* obj);
void set(std::string name);
int getPhysicalLocationID();
DAO* getdao();
void setdao(DAO* _dao);
SolidObject* gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(SolidObject* _hasPhysicalLocation_RefObject);
std::vector<SolidObject*> gethasSolidObject_SecondaryLocation();
void sethasSolidObject_SecondaryLocation(std::vector<SolidObject*> _hasSolidObject_SecondaryLocation);
std::vector<SolidObject*> gethasSolidObject_PrimaryLocation();
void sethasSolidObject_PrimaryLocation(std::vector<SolidObject*> _hasSolidObject_PrimaryLocation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PHYSICALLOCATION_H_ */