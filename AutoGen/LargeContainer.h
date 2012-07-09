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


#ifndef LARGECONTAINER_H_
#define LARGECONTAINER_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "BoxyObject.h"
 class LargeBoxWithKits;
 class LargeBoxWithEmptyKitTrays;
 class DAO;
class LargeContainer: public BoxyObject{private:
std::string hasLargeContainer_SkuRef;
std::string hasLargeContainer_SerialNumber;
std::string name;
int LargeContainerID;
DAO* dao;
LargeBoxWithKits* hasLargeBoxWithKits_LargeContainer;
LargeBoxWithEmptyKitTrays* hasLargeBoxWithEmptyKitTrays_LargeContainer;
public:
LargeContainer(std::string name);
~LargeContainer();
 void get(int id);
 void get(std::string name);
void set(int id, LargeContainer* obj);
void set(std::string name);
std::string gethasLargeContainer_SkuRef();
void sethasLargeContainer_SkuRef(std::string _hasLargeContainer_SkuRef);
std::string gethasLargeContainer_SerialNumber();
void sethasLargeContainer_SerialNumber(std::string _hasLargeContainer_SerialNumber);
std::string getname();
int getLargeContainerID();
DAO* getdao();
void setdao(DAO* _dao);
LargeBoxWithKits* gethasLargeBoxWithKits_LargeContainer();
void sethasLargeBoxWithKits_LargeContainer(LargeBoxWithKits* _hasLargeBoxWithKits_LargeContainer);
LargeBoxWithEmptyKitTrays* gethasLargeBoxWithEmptyKitTrays_LargeContainer();
void sethasLargeBoxWithEmptyKitTrays_LargeContainer(LargeBoxWithEmptyKitTrays* _hasLargeBoxWithEmptyKitTrays_LargeContainer);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* LARGECONTAINER_H_ */