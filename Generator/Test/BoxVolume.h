
#ifndef BOXVOLUME_H_
#define BOXVOLUME_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
 #include "Point.h"
class BoxVolume: public DataThing {private:
std::string name;
int id;
DAO* dao;
Point* hasBoxVolume_MaximumPoint;
Point* hasBoxVolume_MinimumPoint;
public:
BoxVolume(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, BoxVolume* obj);
void set(std::string name, BoxVolume* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
Point* gethasBoxVolume_MaximumPoint();
void sethasBoxVolume_MaximumPoint(Point* _hasBoxVolume_MaximumPoint);
Point* gethasBoxVolume_MinimumPoint();
void sethasBoxVolume_MinimumPoint(Point* _hasBoxVolume_MinimumPoint);
void copy(BoxVolume const& object);
}; 
#endif /* BOXVOLUME_H_ */