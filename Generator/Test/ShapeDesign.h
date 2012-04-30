
#ifndef SHAPEDESIGN_H_
#define SHAPEDESIGN_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
class ShapeDesign: public DataThing {private:
std::string hasShapeDesign_Description;
std::string name;
int id;
DAO* dao;
public:
ShapeDesign(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, ShapeDesign* obj);
void set(std::string name, ShapeDesign* obj);
std::string gethasShapeDesign_Description();
void sethasShapeDesign_Description(std::string _hasShapeDesign_Description);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(ShapeDesign const& object);
}; 
#endif /* SHAPEDESIGN_H_ */