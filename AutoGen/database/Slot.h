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


#ifndef SLOT_H_
#define SLOT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class Kit;
 class DAO;
 class Part;
 class PartRefAndPose;
class Slot: public DataThing{private:
int SlotID;
DAO* dao;
Kit* hadBySlot_Kit;
PartRefAndPose* hasSlot_PartRefAndPose;
Part* hasSlot_Part;
public:
Slot(std::string name);
~Slot();
 void get(int id);
 void get(std::string name);
void set(int id, Slot* obj);
void set(std::string name);
int getSlotID();
DAO* getdao();
void setdao(DAO* _dao);
Kit* gethadBySlot_Kit();
void sethadBySlot_Kit(Kit* _hadBySlot_Kit);
PartRefAndPose* gethasSlot_PartRefAndPose();
void sethasSlot_PartRefAndPose(PartRefAndPose* _hasSlot_PartRefAndPose);
Part* gethasSlot_Part();
void sethasSlot_Part(Part* _hasSlot_Part);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SLOT_H_ */