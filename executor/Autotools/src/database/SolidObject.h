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


#ifndef SOLIDOBJECT_H_
#define SOLIDOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


 class ExternalShape;
 class PhysicalLocation;
 class DAO;
 class InternalShape;
 class EndEffector;
 class PhysicalLocation;
 class WorkTable;
class SolidObject{private:
int SolidObjectID;
DAO* dao;
std::vector<PhysicalLocation*> hasSolidObject_SecondaryLocation;
InternalShape* hasSolidObject_InternalShape;
PhysicalLocation* hasSolidObject_PrimaryLocation;
WorkTable* hadBySolidObject_WorkTable;
ExternalShape* hasSolidObject_ExternalShape;
std::vector<PhysicalLocation*> hasPhysicalLocation_RefObject;
std::vector<EndEffector*> hasEndEffector_HeldObject;
protected :
 std::string name;
public:
SolidObject(std::string name);
~SolidObject();
 void get(int id);
 void get(std::string name);
void set(int id, SolidObject* obj);
void set(std::string name);
std::string getname();
int getSolidObjectID();
DAO* getdao();
void setdao(DAO* _dao);
std::vector<PhysicalLocation*> gethasSolidObject_SecondaryLocation();
void sethasSolidObject_SecondaryLocation(std::vector<PhysicalLocation*> _hasSolidObject_SecondaryLocation);
InternalShape* gethasSolidObject_InternalShape();
void sethasSolidObject_InternalShape(InternalShape* _hasSolidObject_InternalShape);
PhysicalLocation* gethasSolidObject_PrimaryLocation();
void sethasSolidObject_PrimaryLocation(PhysicalLocation* _hasSolidObject_PrimaryLocation);
WorkTable* gethadBySolidObject_WorkTable();
void sethadBySolidObject_WorkTable(WorkTable* _hadBySolidObject_WorkTable);
ExternalShape* gethasSolidObject_ExternalShape();
void sethasSolidObject_ExternalShape(ExternalShape* _hasSolidObject_ExternalShape);
std::vector<PhysicalLocation*> gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(std::vector<PhysicalLocation*> _hasPhysicalLocation_RefObject);
std::vector<EndEffector*> gethasEndEffector_HeldObject();
void sethasEndEffector_HeldObject(std::vector<EndEffector*> _hasEndEffector_HeldObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SOLIDOBJECT_H_ */