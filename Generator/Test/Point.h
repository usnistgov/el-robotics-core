
#ifndef POINT_H_
#define POINT_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "DataThing.h"
 #include "BoxVolume.h"
 class BoxVolume;
 #include "DAO.h"
 class DAO;
 #include <string>
 #include "PartRefAndPose.h"
 class PartRefAndPose;
 #include "Pose.h"
 class Pose;
class Point: public DataThing{private:
double hasPoint_X;
double hasPoint_Y;
double hasPoint_Z;
std::string name;
int PointID;
DAO* dao;
Pose* hasPose_Point;
PartRefAndPose* hasPartRefAndPose_Point;
BoxVolume* hasBoxVolume_MaximumPoint;
BoxVolume* hasBoxVolume_MinimumPoint;
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
std::string getname();
void setname(std::string _name);
int getPointID();
void setPointID(int _PointID);
DAO* getdao();
void setdao(DAO* _dao);
Pose* gethasPose_Point();
void sethasPose_Point(Pose* _hasPose_Point);
PartRefAndPose* gethasPartRefAndPose_Point();
void sethasPartRefAndPose_Point(PartRefAndPose* _hasPartRefAndPose_Point);
BoxVolume* gethasBoxVolume_MaximumPoint();
void sethasBoxVolume_MaximumPoint(BoxVolume* _hasBoxVolume_MaximumPoint);
BoxVolume* gethasBoxVolume_MinimumPoint();
void sethasBoxVolume_MinimumPoint(BoxVolume* _hasBoxVolume_MinimumPoint);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POINT_H_ */