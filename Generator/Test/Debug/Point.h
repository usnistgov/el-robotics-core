
#ifndef POINT_H_
#define POINT_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
class Point: public DataThing {private:
float hasPoint_X;
float hasPoint_Y;
float hasPoint_Z;
std::string name;
int id;
DAO* dao;
public:
Point(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, Point* obj);
void set(std::string name, Point* obj);
float gethasPoint_X();
void sethasPoint_X(float _hasPoint_X);
float gethasPoint_Y();
void sethasPoint_Y(float _hasPoint_Y);
float gethasPoint_Z();
void sethasPoint_Z(float _hasPoint_Z);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(Point const& object);
}; 
#endif /* POINT_H_ */