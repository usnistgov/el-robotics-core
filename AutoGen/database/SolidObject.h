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


 class EndEffector;
 class KittingWorkstation;
 class PhysicalLocation;
 class DAO;
 class PhysicalLocation;
 class WorkTable;
class SolidObject{private:
int SolidObjectID;
DAO* dao;
std::vector<PhysicalLocation*> hadBySecondaryLocation_SolidObject;
KittingWorkstation* hadByObject_KittingWorkstation;
WorkTable* hadByObjectOnTable_WorkTable;
PhysicalLocation* hasSolidObject_PrimaryLocation;
EndEffector* hasEndEffector_HeldObject;
std::vector<PhysicalLocation*> hasPhysicalLocation_RefObject;
protected :
 std::string name;
public:
SolidObject(std::string name);
~SolidObject();
 void get(int id);
 void get(std::string name);
void set(int id, SolidObject* obj);
void set(std::string name);
void insert(std::string name);
std::string getname();
int getSolidObjectID();
void setSolidObjectID(int _SolidObjectID);
DAO* getdao();
void setdao(DAO* _dao);
std::vector<PhysicalLocation*> gethadBySecondaryLocation_SolidObject();
void sethadBySecondaryLocation_SolidObject(std::vector<PhysicalLocation*> _hadBySecondaryLocation_SolidObject);
KittingWorkstation* gethadByObject_KittingWorkstation();
void sethadByObject_KittingWorkstation(KittingWorkstation* _hadByObject_KittingWorkstation);
WorkTable* gethadByObjectOnTable_WorkTable();
void sethadByObjectOnTable_WorkTable(WorkTable* _hadByObjectOnTable_WorkTable);
PhysicalLocation* gethasSolidObject_PrimaryLocation();
void sethasSolidObject_PrimaryLocation(PhysicalLocation* _hasSolidObject_PrimaryLocation);
EndEffector* gethasEndEffector_HeldObject();
void sethasEndEffector_HeldObject(EndEffector* _hasEndEffector_HeldObject);
std::vector<PhysicalLocation*> gethasPhysicalLocation_RefObject();
void sethasPhysicalLocation_RefObject(std::vector<PhysicalLocation*> _hasPhysicalLocation_RefObject);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SOLIDOBJECT_H_ */