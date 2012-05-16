
#ifndef STOCKKEEPINGUNIT_H_
#define STOCKKEEPINGUNIT_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include <string>
 #include <vector>
 #include "ShapeDesign.h"
 class ShapeDesign;
 #include "DAO.h"
 class DAO;
 #include <string>
class StockKeepingUnit: public DataThing{private:
std::vector<std::string> hasSku_EndEffectorRefs;
std::string hasSku_Description;
std::string hasSku_Id;
float hasSku_Weight;
std::string name;
int id;
DAO* dao;
ShapeDesign* hasSku_Shape;
public:
StockKeepingUnit(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, StockKeepingUnit* obj);
void set(std::string name, StockKeepingUnit* obj);
std::vector<std::string> gethasSku_EndEffectorRefs();
void sethasSku_EndEffectorRefs(std::vector<std::string> _hasSku_EndEffectorRefs);
std::string gethasSku_Description();
void sethasSku_Description(std::string _hasSku_Description);
std::string gethasSku_Id();
void sethasSku_Id(std::string _hasSku_Id);
float gethasSku_Weight();
void sethasSku_Weight(float _hasSku_Weight);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
ShapeDesign* gethasSku_Shape();
void sethasSku_Shape(ShapeDesign* _hasSku_Shape);
void copy(const StockKeepingUnit &object);
}; 
#endif /* STOCKKEEPINGUNIT_H_ */