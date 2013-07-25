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
 class ShapeDesign;
 class DAO;
 class Vector;
 class Point;
class PoseLocation: public PhysicalLocation{private:
double hasPoseLocation_OrientationStandardDeviation;
double hasPoseLocation_PositionStandardDeviation;
int PoseLocationID;
DAO* dao;
ShapeDesign* hadByGraspPose_ShapeDesign;
Vector* hasPoseLocation_XAxis;
Vector* hasPoseLocation_ZAxis;
Point* hasPoseLocation_Point;
public:
PoseLocation(std::string name);
~PoseLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PoseLocation* obj);
void set(std::string name);
double gethasPoseLocation_OrientationStandardDeviation();
void sethasPoseLocation_OrientationStandardDeviation(double _hasPoseLocation_OrientationStandardDeviation);
double gethasPoseLocation_PositionStandardDeviation();
void sethasPoseLocation_PositionStandardDeviation(double _hasPoseLocation_PositionStandardDeviation);
int getPoseLocationID();
DAO* getdao();
void setdao(DAO* _dao);
ShapeDesign* gethadByGraspPose_ShapeDesign();
void sethadByGraspPose_ShapeDesign(ShapeDesign* _hadByGraspPose_ShapeDesign);
Vector* gethasPoseLocation_XAxis();
void sethasPoseLocation_XAxis(Vector* _hasPoseLocation_XAxis);
Vector* gethasPoseLocation_ZAxis();
void sethasPoseLocation_ZAxis(Vector* _hasPoseLocation_ZAxis);
Point* gethasPoseLocation_Point();
void sethasPoseLocation_Point(Point* _hasPoseLocation_Point);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POSELOCATION_H_ */