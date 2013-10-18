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
 class KitDesign;
 class SkuObject;
 class ExternalShape;
 class DAO;
 class InternalShape;
 class PartRefAndPose;
 class EndEffector;
 class PartsVessel;
class StockKeepingUnit: public DataThing{private:
std::string hasStockKeepingUnit_Description;
double hasStockKeepingUnit_Weight;
int StockKeepingUnitID;
DAO* dao;
KittingWorkstation* hadBySku_KittingWorkstation;
InternalShape* hasStockKeepingUnit_InternalShape;
ExternalShape* hadByExternalShape_StockKeepingUnit;
std::vector<EndEffector*> hasStockKeepingUnit_EndEffector;
std::vector<PartsVessel*> hasPartsVessel_PartSku;
std::vector<PartRefAndPose*> hasPartRefAndPose_Sku;
std::vector<KitDesign*> hasKitDesign_KitTraySku;
std::vector<SkuObject*> hasSkuObject_Sku;
public:
StockKeepingUnit(std::string name);
~StockKeepingUnit();
 void get(int id);
 void get(std::string name);
void set(int id, StockKeepingUnit* obj);
void set(std::string name);
void insert(std::string name);
std::string gethasStockKeepingUnit_Description();
void sethasStockKeepingUnit_Description(std::string _hasStockKeepingUnit_Description);
double gethasStockKeepingUnit_Weight();
void sethasStockKeepingUnit_Weight(double _hasStockKeepingUnit_Weight);
int getStockKeepingUnitID();
void setStockKeepingUnitID(int _StockKeepingUnitID);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadBySku_KittingWorkstation();
void sethadBySku_KittingWorkstation(KittingWorkstation* _hadBySku_KittingWorkstation);
InternalShape* gethasStockKeepingUnit_InternalShape();
void sethasStockKeepingUnit_InternalShape(InternalShape* _hasStockKeepingUnit_InternalShape);
ExternalShape* gethadByExternalShape_StockKeepingUnit();
void sethadByExternalShape_StockKeepingUnit(ExternalShape* _hadByExternalShape_StockKeepingUnit);
std::vector<EndEffector*> gethasStockKeepingUnit_EndEffector();
void sethasStockKeepingUnit_EndEffector(std::vector<EndEffector*> _hasStockKeepingUnit_EndEffector);
std::vector<PartsVessel*> gethasPartsVessel_PartSku();
void sethasPartsVessel_PartSku(std::vector<PartsVessel*> _hasPartsVessel_PartSku);
std::vector<PartRefAndPose*> gethasPartRefAndPose_Sku();
void sethasPartRefAndPose_Sku(std::vector<PartRefAndPose*> _hasPartRefAndPose_Sku);
std::vector<KitDesign*> gethasKitDesign_KitTraySku();
void sethasKitDesign_KitTraySku(std::vector<KitDesign*> _hasKitDesign_KitTraySku);
std::vector<SkuObject*> gethasSkuObject_Sku();
void sethasSkuObject_Sku(std::vector<SkuObject*> _hasSkuObject_Sku);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* STOCKKEEPINGUNIT_H_ */