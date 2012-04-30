
#ifndef POSE_H_
#define POSE_H_
#include <cstdlib>
#include <iostream>

#include "PhysicalLocation.h"
 #include "DAO.h"
 #include "Point.h"
 #include "RollPitchYaw.h"
class Pose: public PhysicalLocation {private:
std::string name;
int id;
DAO* dao;
Point* hasPose_Point;
RollPitchYaw* hasPose_Rpy;
public:
Pose(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, Pose* obj);
void set(std::string name, Pose* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
Point* gethasPose_Point();
void sethasPose_Point(Point* _hasPose_Point);
RollPitchYaw* gethasPose_Rpy();
void sethasPose_Rpy(RollPitchYaw* _hasPose_Rpy);
void copy(Pose const& object);
}; 
#endif /* POSE_H_ */