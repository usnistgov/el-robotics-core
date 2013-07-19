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


#ifndef KITDESIGN_H_
#define KITDESIGN_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class StockKeepingUnit;
 class Kit;
 class KittingWorkstation;
 class DAO;
 class PartRefAndPose;
 class LargeBoxWithKits;
class KitDesign: public DataThing{private:
int KitDesignID;
DAO* dao;
KittingWorkstation* hadByKitDesign_Workstation;
StockKeepingUnit* hasKitDesign_KitTraySku;
std::vector<LargeBoxWithKits*> hasLargeBoxWithKits_KitDesign;
std::vector<PartRefAndPose*> hadByPartRefAndPose_KitDesign;
std::vector<Kit*> hasKit_Design;
public:
KitDesign(std::string name);
~KitDesign();
 void get(int id);
 void get(std::string name);
void set(int id, KitDesign* obj);
void set(std::string name);
int getKitDesignID();
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByKitDesign_Workstation();
void sethadByKitDesign_Workstation(KittingWorkstation* _hadByKitDesign_Workstation);
StockKeepingUnit* gethasKitDesign_KitTraySku();
void sethasKitDesign_KitTraySku(StockKeepingUnit* _hasKitDesign_KitTraySku);
std::vector<LargeBoxWithKits*> gethasLargeBoxWithKits_KitDesign();
void sethasLargeBoxWithKits_KitDesign(std::vector<LargeBoxWithKits*> _hasLargeBoxWithKits_KitDesign);
std::vector<PartRefAndPose*> gethadByPartRefAndPose_KitDesign();
void sethadByPartRefAndPose_KitDesign(std::vector<PartRefAndPose*> _hadByPartRefAndPose_KitDesign);
std::vector<Kit*> gethasKit_Design();
void sethasKit_Design(std::vector<Kit*> _hasKit_Design);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITDESIGN_H_ */