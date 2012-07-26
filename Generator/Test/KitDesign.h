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
 class KittingWorkstation;
 class DAO;
 class PartRefAndPose;
class KitDesign: public DataThing{private:
std::string hasKitDesign_Id;
std::string hasKitDesign_KitTraySkuRef;
int KitDesignID;
DAO* dao;
KittingWorkstation* hadByKitDesign_Workstation;
std::vector<PartRefAndPose*> hadByPartRefAndPose_KitDesign;
public:
KitDesign(std::string name);
~KitDesign();
 void get(int id);
 void get(std::string name);
void set(int id, KitDesign* obj);
void set(std::string name);
std::string gethasKitDesign_Id();
void sethasKitDesign_Id(std::string _hasKitDesign_Id);
std::string gethasKitDesign_KitTraySkuRef();
void sethasKitDesign_KitTraySkuRef(std::string _hasKitDesign_KitTraySkuRef);
int getKitDesignID();
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByKitDesign_Workstation();
void sethadByKitDesign_Workstation(KittingWorkstation* _hadByKitDesign_Workstation);
std::vector<PartRefAndPose*>* gethadByPartRefAndPose_KitDesign();
void sethadByPartRefAndPose_KitDesign(std::vector<PartRefAndPose*> _hadByPartRefAndPose_KitDesign);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITDESIGN_H_ */