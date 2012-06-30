
#ifndef STOCKKEEPINGUNIT_H_
#define STOCKKEEPINGUNIT_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class KittingWorkstation;
 class ShapeDesign;
 class DAO;
class StockKeepingUnit: public DataThing{private:
std::vector<std::string> hasSku_EndEffectorRefs;
std::string hasSku_Description;
std::string hasSku_Id;
double hasSku_Weight;
std::string name;
int StockKeepingUnitID;
DAO* dao;
KittingWorkstation* hadBySku_Workstation;
ShapeDesign* hasSku_Shape;
public:
StockKeepingUnit(std::string name);
~StockKeepingUnit();
 void get(int id);
 void get(std::string name);
void set(int id, StockKeepingUnit* obj);
void set(std::string name);
std::vector<std::string>* gethasSku_EndEffectorRefs();
void sethasSku_EndEffectorRefs(std::vector<std::string> _hasSku_EndEffectorRefs);
std::string gethasSku_Description();
void sethasSku_Description(std::string _hasSku_Description);
std::string gethasSku_Id();
void sethasSku_Id(std::string _hasSku_Id);
double gethasSku_Weight();
void sethasSku_Weight(double _hasSku_Weight);
std::string getname();
int getStockKeepingUnitID();
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadBySku_Workstation();
void sethadBySku_Workstation(KittingWorkstation* _hadBySku_Workstation);
ShapeDesign* gethasSku_Shape();
void sethasSku_Shape(ShapeDesign* _hasSku_Shape);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* STOCKKEEPINGUNIT_H_ */