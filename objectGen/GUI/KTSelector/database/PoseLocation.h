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


#ifndef POSELOCATION_H_
#define POSELOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "PhysicalLocation.h"
 class DAO;
 class ShapeDesign;
 class Vector;
 class Point;
class PoseLocation: public PhysicalLocation{private:
int PoseLocationID;
DAO* dao;
Point* hasPoseLocation_Point;
Vector* hasPoseLocation_ZAxis;
Vector* hasPoseLocation_XAxis;
std::vector<ShapeDesign*> hasShapeDesign_GraspPose;
public:
PoseLocation(std::string name);
~PoseLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PoseLocation* obj);
void set(std::string name);
int getPoseLocationID();
DAO* getdao();
void setdao(DAO* _dao);
Point* gethasPoseLocation_Point();
void sethasPoseLocation_Point(Point* _hasPoseLocation_Point);
Vector* gethasPoseLocation_ZAxis();
void sethasPoseLocation_ZAxis(Vector* _hasPoseLocation_ZAxis);
Vector* gethasPoseLocation_XAxis();
void sethasPoseLocation_XAxis(Vector* _hasPoseLocation_XAxis);
std::vector<ShapeDesign*> gethasShapeDesign_GraspPose();
void sethasShapeDesign_GraspPose(std::vector<ShapeDesign*> _hasShapeDesign_GraspPose);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POSELOCATION_H_ */