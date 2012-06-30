
#ifndef PARTREFANDPOSE_H_
#define PARTREFANDPOSE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class DAO;
 class Vector;
 class KitDesign;
 class Point;
class PartRefAndPose: public DataThing{private:
std::string hasPartRefAndPose_Ref;
std::string name;
int PartRefAndPoseID;
DAO* dao;
Vector* hasPartRefAndPose_ZAxis;
KitDesign* hadByPartRefAndPose_KitDesign;
Point* hasPartRefAndPose_Point;
Vector* hasPartRefAndPose_XAxis;
public:
PartRefAndPose(std::string name);
~PartRefAndPose();
 void get(int id);
 void get(std::string name);
void set(int id, PartRefAndPose* obj);
void set(std::string name);
std::string gethasPartRefAndPose_Ref();
void sethasPartRefAndPose_Ref(std::string _hasPartRefAndPose_Ref);
std::string getname();
int getPartRefAndPoseID();
DAO* getdao();
void setdao(DAO* _dao);
Vector* gethasPartRefAndPose_ZAxis();
void sethasPartRefAndPose_ZAxis(Vector* _hasPartRefAndPose_ZAxis);
KitDesign* gethadByPartRefAndPose_KitDesign();
void sethadByPartRefAndPose_KitDesign(KitDesign* _hadByPartRefAndPose_KitDesign);
Point* gethasPartRefAndPose_Point();
void sethasPartRefAndPose_Point(Point* _hasPartRefAndPose_Point);
Vector* gethasPartRefAndPose_XAxis();
void sethasPartRefAndPose_XAxis(Vector* _hasPartRefAndPose_XAxis);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTREFANDPOSE_H_ */