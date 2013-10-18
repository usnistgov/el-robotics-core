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


#include "NoSkuObject.h"
 class Robot;
 class BoxVolume;
 class SolidObject;
 class KitDesign;
 class StockKeepingUnit;
 class EndEffectorChangingStation;
 class DAO;
class KittingWorkstation: public NoSkuObject{private:
std::string hasKittingWorkstation_LengthUnit;
std::string hasKittingWorkstation_WeightUnit;
std::string hasKittingWorkstation_AngleUnit;
int KittingWorkstationID;
DAO* dao;
std::vector<StockKeepingUnit*> hadBySku_KittingWorkstation;
std::vector<KitDesign*> hadByKitDesign_KittingWorkstation;
std::vector<BoxVolume*> hadByOtherObstacle_KittingWorkstation;
EndEffectorChangingStation* hasKittingWorkstation_ChangingStation;
Robot* hasKittingWorkstation_Robot;
std::vector<SolidObject*> hadByObject_KittingWorkstation;
public:
KittingWorkstation(std::string name);
~KittingWorkstation();
 void get(int id);
 void get(std::string name);
void set(int id, KittingWorkstation* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasKittingWorkstation_LengthUnit();
void sethasKittingWorkstation_LengthUnit(std::string _hasKittingWorkstation_LengthUnit);
std::string gethasKittingWorkstation_WeightUnit();
void sethasKittingWorkstation_WeightUnit(std::string _hasKittingWorkstation_WeightUnit);
std::string gethasKittingWorkstation_AngleUnit();
void sethasKittingWorkstation_AngleUnit(std::string _hasKittingWorkstation_AngleUnit);
int getKittingWorkstationID();
void setKittingWorkstationID(int _KittingWorkstationID);
DAO* getdao();
void setdao(DAO* _dao);
std::vector<StockKeepingUnit*> gethadBySku_KittingWorkstation();
void sethadBySku_KittingWorkstation(std::vector<StockKeepingUnit*> _hadBySku_KittingWorkstation);
std::vector<KitDesign*> gethadByKitDesign_KittingWorkstation();
void sethadByKitDesign_KittingWorkstation(std::vector<KitDesign*> _hadByKitDesign_KittingWorkstation);
std::vector<BoxVolume*> gethadByOtherObstacle_KittingWorkstation();
void sethadByOtherObstacle_KittingWorkstation(std::vector<BoxVolume*> _hadByOtherObstacle_KittingWorkstation);
EndEffectorChangingStation* gethasKittingWorkstation_ChangingStation();
void sethasKittingWorkstation_ChangingStation(EndEffectorChangingStation* _hasKittingWorkstation_ChangingStation);
Robot* gethasKittingWorkstation_Robot();
void sethasKittingWorkstation_Robot(Robot* _hasKittingWorkstation_Robot);
std::vector<SolidObject*> gethadByObject_KittingWorkstation();
void sethadByObject_KittingWorkstation(std::vector<SolidObject*> _hadByObject_KittingWorkstation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITTINGWORKSTATION_H_ */