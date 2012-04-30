
#ifndef PARTREFANDPOSE_H_
#define PARTREFANDPOSE_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
 #include "Point.h"
 #include "RollPitchYaw.h"
class PartRefAndPose: public DataThing {private:
std::string hasPartRefAndPose_Ref;
std::string name;
int id;
DAO* dao;
RollPitchYaw* hasPartRefAndPose_Rpy;
Point* hasPartRefAndPose_Point;
public:
PartRefAndPose(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, PartRefAndPose* obj);
void set(std::string name, PartRefAndPose* obj);
std::string gethasPartRefAndPose_Ref();
void sethasPartRefAndPose_Ref(std::string _hasPartRefAndPose_Ref);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
RollPitchYaw* gethasPartRefAndPose_Rpy();
void sethasPartRefAndPose_Rpy(RollPitchYaw* _hasPartRefAndPose_Rpy);
Point* gethasPartRefAndPose_Point();
void sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point);
void copy(PartRefAndPose const& object);
}; 
#endif /* PARTREFANDPOSE_H_ */