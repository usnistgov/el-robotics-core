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


#ifndef LARGEBOXWITHEMPTYKITTRAYS_H_
#define LARGEBOXWITHEMPTYKITTRAYS_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class KitTray;
 class LargeContainer;
 class DAO;
class LargeBoxWithEmptyKitTrays: public SolidObject{private:
std::string name;
int LargeBoxWithEmptyKitTraysID;
DAO* dao;
LargeContainer* hasLargeBoxWithEmptyKitTrays_LargeContainer;
std::vector<KitTray*> hadByKitTray_LargeBoxWithEmptyKitTrays;
public:
LargeBoxWithEmptyKitTrays(std::string name);
~LargeBoxWithEmptyKitTrays();
 void get(int id);
 void get(std::string name);
void set(int id, LargeBoxWithEmptyKitTrays* obj);
void set(std::string name);
std::string getname();
int getLargeBoxWithEmptyKitTraysID();
DAO* getdao();
void setdao(DAO* _dao);
LargeContainer* gethasLargeBoxWithEmptyKitTrays_LargeContainer();
void sethasLargeBoxWithEmptyKitTrays_LargeContainer(LargeContainer* _hasLargeBoxWithEmptyKitTrays_LargeContainer);
std::vector<KitTray*>* gethadByKitTray_LargeBoxWithEmptyKitTrays();
void sethadByKitTray_LargeBoxWithEmptyKitTrays(std::vector<KitTray*> _hadByKitTray_LargeBoxWithEmptyKitTrays);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* LARGEBOXWITHEMPTYKITTRAYS_H_ */