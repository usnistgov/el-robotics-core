
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
 class Vector;
 class Point;
class PoseLocation: public PhysicalLocation{private:
std::string name;
int PoseLocationID;
DAO* dao;
Point* hasPoseLocation_Point;
Vector* hasPoseLocation_ZAxis;
Vector* hasPoseLocation_XAxis;
public:
PoseLocation(std::string name);
~PoseLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PoseLocation* obj);
void set(std::string name);
std::string getname();
int getPoseLocationID();
DAO* getdao();
void setdao(DAO* _dao);
Point* gethasPoseLocation_Point();
void sethasPoseLocation_Point(Point* _hasPoseLocation_Point);
Vector* gethasPoseLocation_ZAxis();
void sethasPoseLocation_ZAxis(Vector* _hasPoseLocation_ZAxis);
Vector* gethasPoseLocation_XAxis();
void sethasPoseLocation_XAxis(Vector* _hasPoseLocation_XAxis);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POSELOCATION_H_ */