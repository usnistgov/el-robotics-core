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


#ifndef PARTREFANDPOSE_H_
#define PARTREFANDPOSE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class StockKeepingUnit;
 class Slot;
 class DAO;
 class Vector;
 class KitDesign;
 class Point;
class PartRefAndPose: public DataThing{private:
int PartRefAndPoseID;
DAO* dao;
StockKeepingUnit* hasPartRefAndPose_Sku;
Vector* hasPartRefAndPose_ZAxis;
KitDesign* hadByPartRefAndPose_KitDesign;
Point* hasPartRefAndPose_Point;
Vector* hasPartRefAndPose_XAxis;
std::vector<Slot*> hasSlot_PartRefAndPose;
public:
PartRefAndPose(std::string name);
~PartRefAndPose();
 void get(int id);
 void get(std::string name);
void set(int id, PartRefAndPose* obj);
void set(std::string name);
int getPartRefAndPoseID();
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethasPartRefAndPose_Sku();
void sethasPartRefAndPose_Sku(StockKeepingUnit* _hasPartRefAndPose_Sku);
Vector* gethasPartRefAndPose_ZAxis();
void sethasPartRefAndPose_ZAxis(Vector* _hasPartRefAndPose_ZAxis);
KitDesign* gethadByPartRefAndPose_KitDesign();
void sethadByPartRefAndPose_KitDesign(KitDesign* _hadByPartRefAndPose_KitDesign);
Point* gethasPartRefAndPose_Point();
void sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point);
Vector* gethasPartRefAndPose_XAxis();
void sethasPartRefAndPose_XAxis(Vector* _hasPartRefAndPose_XAxis);
std::vector<Slot*> gethasSlot_PartRefAndPose();
void sethasSlot_PartRefAndPose(std::vector<Slot*> _hasSlot_PartRefAndPose);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTREFANDPOSE_H_ */