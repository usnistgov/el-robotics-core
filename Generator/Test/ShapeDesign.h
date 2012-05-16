
#ifndef SHAPEDESIGN_H_
#define SHAPEDESIGN_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "DataThing.h"
 #include "StockKeepingUnit.h"
 class StockKeepingUnit;
 #include "DAO.h"
 class DAO;
 #include <string>
class ShapeDesign: public DataThing{private:
std::string hasShapeDesign_Description;
std::string name;
int ShapeDesignID;
DAO* dao;
StockKeepingUnit* hasSku_Shape;
public:
ShapeDesign(std::string name);
~ShapeDesign();
 void get(int id);
 void get(std::string name);
void set(int id, ShapeDesign* obj);
void set(std::string name);
std::string gethasShapeDesign_Description();
void sethasShapeDesign_Description(std::string _hasShapeDesign_Description);
std::string getname();
void setname(std::string _name);
int getShapeDesignID();
void setShapeDesignID(int _ShapeDesignID);
DAO* getdao();
void setdao(DAO* _dao);
StockKeepingUnit* gethasSku_Shape();
void sethasSku_Shape(StockKeepingUnit* _hasSku_Shape);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* SHAPEDESIGN_H_ */