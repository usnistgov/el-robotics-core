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


#ifndef SHAPEDESIGN_H_
#define SHAPEDESIGN_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class DAO;
 class PoseLocation;
class ShapeDesign: public DataThing{private:
std::string hasShapeDesign_Description;
int ShapeDesignID;
DAO* dao;
PoseLocation* hadByGraspPose_ShapeDesign;
public:
ShapeDesign(std::string name);
~ShapeDesign();
 void get(int id);
 void get(std::string name);
void set(int id, ShapeDesign* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasShapeDesign_Description();
void sethasShapeDesign_Description(std::string _hasShapeDesign_Description);
int getShapeDesignID();
void setShapeDesignID(int _ShapeDesignID);
DAO* getdao();
void setdao(DAO* _dao);
PoseLocation* gethadByGraspPose_ShapeDesign();
void sethadByGraspPose_ShapeDesign(PoseLocation* _hadByGraspPose_ShapeDesign);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SHAPEDESIGN_H_ */