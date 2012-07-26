/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/


#ifndef KITTINGWORKSTATION_H_
#define KITTINGWORKSTATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class Robot;
 class BoxVolume;
 class KitDesign;
 class StockKeepingUnit;
 class EndEffectorChangingStation;
 class DAO;
 class WorkTable;
class KittingWorkstation: public SolidObject{private:
std::string hasWorkstation_LengthUnit;
std::string hasWorkstation_AngleUnit;
std::string hasWorkstation_WeightUnit;
int KittingWorkstationID;
DAO* dao;
std::vector<KitDesign*> hadByKitDesign_Workstation;
EndEffectorChangingStation* hasWorkstation_ChangingStation;
WorkTable* hasWorkstation_WorkTable;
std::vector<BoxVolume*> hasWorkstation_OtherObstacles;
std::vector<StockKeepingUnit*> hadBySku_Workstation;
Robot* hasWorkstation_Robot;
public:
KittingWorkstation(std::string name);
~KittingWorkstation();
 void get(int id);
 void get(std::string name);
void set(int id, KittingWorkstation* obj);
void set(std::string name);
std::string gethasWorkstation_LengthUnit();
void sethasWorkstation_LengthUnit(std::string _hasWorkstation_LengthUnit);
std::string gethasWorkstation_AngleUnit();
void sethasWorkstation_AngleUnit(std::string _hasWorkstation_AngleUnit);
std::string gethasWorkstation_WeightUnit();
void sethasWorkstation_WeightUnit(std::string _hasWorkstation_WeightUnit);
int getKittingWorkstationID();
DAO* getdao();
void setdao(DAO* _dao);
std::vector<KitDesign*>* gethadByKitDesign_Workstation();
void sethadByKitDesign_Workstation(std::vector<KitDesign*> _hadByKitDesign_Workstation);
EndEffectorChangingStation* gethasWorkstation_ChangingStation();
void sethasWorkstation_ChangingStation(EndEffectorChangingStation* _hasWorkstation_ChangingStation);
WorkTable* gethasWorkstation_WorkTable();
void sethasWorkstation_WorkTable(WorkTable* _hasWorkstation_WorkTable);
std::vector<BoxVolume*>* gethasWorkstation_OtherObstacles();
void sethasWorkstation_OtherObstacles(std::vector<BoxVolume*> _hasWorkstation_OtherObstacles);
std::vector<StockKeepingUnit*>* gethadBySku_Workstation();
void sethadBySku_Workstation(std::vector<StockKeepingUnit*> _hadBySku_Workstation);
Robot* gethasWorkstation_Robot();
void sethasWorkstation_Robot(Robot* _hasWorkstation_Robot);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITTINGWORKSTATION_H_ */