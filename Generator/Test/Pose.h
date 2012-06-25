
#ifndef POSE_H_
#define POSE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "PhysicalLocation.h"
 class DAO;
 class Point;
 class RollPitchYaw;
class Pose: public PhysicalLocation{private:
std::string name;
int PoseID;
DAO* dao;
Point* hasPose_Point;
RollPitchYaw* hasPose_Rpy;
public:
Pose(std::string name);
~Pose();
 void get(int id);
 void get(std::string name);
void set(int id, Pose* obj);
void set(std::string name);
std::string getname();
int getPoseID();
DAO* getdao();
void setdao(DAO* _dao);
Point* gethasPose_Point();
void sethasPose_Point(Point* _hasPose_Point);
RollPitchYaw* gethasPose_Rpy();
void sethasPose_Rpy(RollPitchYaw* _hasPose_Rpy);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POSE_H_ */