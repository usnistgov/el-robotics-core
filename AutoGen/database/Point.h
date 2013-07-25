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


#ifndef POINT_H_
#define POINT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class BoxVolume;
 class DAO;
 class PoseLocation;
 class PartRefAndPose;
class Point: public DataThing{private:
double hasPoint_X;
double hasPoint_Y;
double hasPoint_Z;
int PointID;
DAO* dao;
BoxVolume* hasBoxVolume_MaximumPoint;
BoxVolume* hasBoxVolume_MinimumPoint;
PoseLocation* hasPoseLocation_Point;
PartRefAndPose* hasPartRefAndPose_Point;
public:
Point(std::string name);
~Point();
 void get(int id);
 void get(std::string name);
void set(int id, Point* obj);
void set(std::string name);
double gethasPoint_X();
void sethasPoint_X(double _hasPoint_X);
double gethasPoint_Y();
void sethasPoint_Y(double _hasPoint_Y);
double gethasPoint_Z();
void sethasPoint_Z(double _hasPoint_Z);
int getPointID();
DAO* getdao();
void setdao(DAO* _dao);
BoxVolume* gethasBoxVolume_MaximumPoint();
void sethasBoxVolume_MaximumPoint(BoxVolume* _hasBoxVolume_MaximumPoint);
BoxVolume* gethasBoxVolume_MinimumPoint();
void sethasBoxVolume_MinimumPoint(BoxVolume* _hasBoxVolume_MinimumPoint);
PoseLocation* gethasPoseLocation_Point();
void sethasPoseLocation_Point(PoseLocation* _hasPoseLocation_Point);
PartRefAndPose* gethasPartRefAndPose_Point();
void sethasPartRefAndPose_Point(PartRefAndPose* _hasPartRefAndPose_Point);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POINT_H_ */