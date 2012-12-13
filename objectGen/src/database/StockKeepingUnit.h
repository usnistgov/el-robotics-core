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

#include "Part.h"
#include "DataThing.h"
 class PartsBin;
 class KittingWorkstation;
 class KitTray;
 class ShapeDesign;
 class LargeContainer;
 class PartsTray;
 class PartRefAndPose;
 class EndEffector;
 class KitDesign;
 class DAO;
class StockKeepingUnit: public DataThing{private:
std::string hasSku_Description;
double hasSku_Weight;
int StockKeepingUnitID;
DAO* dao;
KittingWorkstation* hadBySku_Workstation;
std::vector<EndEffector*> hasSku_EndEffectors;
ShapeDesign* hasSku_Shape;
std::vector<PartsBin*> hasPartsBin_Sku;
std::vector<PartsBin*> hasPartsBin_PartSku;
std::vector<LargeContainer*> hasLargeContainer_Sku;
std::vector<Part*> hasPart_Sku;
std::vector<PartsTray*> hasPartsTray_Sku;
std::vector<PartRefAndPose*> hasPartRefAndPose_Sku;
std::vector<KitTray*> hasKitTray_Sku;
std::vector<KitDesign*> hasKitDesign_KitTraySku;
public:
StockKeepingUnit(std::string name);
~StockKeepingUnit();
 void get(int id);
 void get(std::string name);
void set(int id, StockKeepingUnit* obj);
void set(std::string name);
std::string gethasSku_Description();
void sethasSku_Description(std::string _hasSku_Description);
double gethasSku_Weight();
void sethasSku_Weight(double _hasSku_Weight);
int getStockKeepingUnitID();
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadBySku_Workstation();
void sethadBySku_Workstation(KittingWorkstation* _hadBySku_Workstation);
std::vector<EndEffector*> gethasSku_EndEffectors();
void sethasSku_EndEffectors(std::vector<EndEffector*> _hasSku_EndEffectors);
ShapeDesign* gethasSku_Shape();
void sethasSku_Shape(ShapeDesign* _hasSku_Shape);
std::vector<PartsBin*> gethasPartsBin_Sku();
void sethasPartsBin_Sku(std::vector<PartsBin*> _hasPartsBin_Sku);
std::vector<PartsBin*> gethasPartsBin_PartSku();
void sethasPartsBin_PartSku(std::vector<PartsBin*> _hasPartsBin_PartSku);
std::vector<LargeContainer*> gethasLargeContainer_Sku();
void sethasLargeContainer_Sku(std::vector<LargeContainer*> _hasLargeContainer_Sku);
std::vector<Part*> gethasPart_Sku();
void sethasPart_Sku(std::vector<Part*> _hasPart_Sku);
std::vector<PartsTray*> gethasPartsTray_Sku();
void sethasPartsTray_Sku(std::vector<PartsTray*> _hasPartsTray_Sku);
std::vector<PartRefAndPose*> gethasPartRefAndPose_Sku();
void sethasPartRefAndPose_Sku(std::vector<PartRefAndPose*> _hasPartRefAndPose_Sku);
std::vector<KitTray*> gethasKitTray_Sku();
void sethasKitTray_Sku(std::vector<KitTray*> _hasKitTray_Sku);
std::vector<KitDesign*> gethasKitDesign_KitTraySku();
void sethasKitDesign_KitTraySku(std::vector<KitDesign*> _hasKitDesign_KitTraySku);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* STOCKKEEPINGUNIT_H_ */
