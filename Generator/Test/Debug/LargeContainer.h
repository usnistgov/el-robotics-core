
#ifndef LARGECONTAINER_H_
#define LARGECONTAINER_H_
#include <cstdlib>
#include <iostream>

#include "BoxyObject.h"
 #include "LargeBoxWithKits.h"
 class LargeBoxWithKits;
 #include "LargeBoxWithEmptyKitTrays.h"
 class LargeBoxWithEmptyKitTrays;
 #include "DAO.h"
 class DAO;
 #include <string>
class LargeContainer: public BoxyObject{private:
std::string hasLargeContainer_SkuRef;
std::string hasLargeContainer_SerialNumber;
std::string name;
int id;
DAO* dao;
LargeBoxWithKits* hadByLargeContainer_LargeBoxWithKits;
LargeBoxWithEmptyKitTrays* hadByLargeContainer_LargeBoxWithEmptyKitTrays;
public:
LargeContainer(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, LargeContainer* obj);
void set(std::string name, LargeContainer* obj);
std::string gethasLargeContainer_SkuRef();
void sethasLargeContainer_SkuRef(std::string _hasLargeContainer_SkuRef);
std::string gethasLargeContainer_SerialNumber();
void sethasLargeContainer_SerialNumber(std::string _hasLargeContainer_SerialNumber);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
LargeBoxWithKits* gethadByLargeContainer_LargeBoxWithKits();
void sethadByLargeContainer_LargeBoxWithKits(LargeBoxWithKits* _hadByLargeContainer_LargeBoxWithKits);
LargeBoxWithEmptyKitTrays* gethadByLargeContainer_LargeBoxWithEmptyKitTrays();
void sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByLargeContainer_LargeBoxWithEmptyKitTrays);
void copy(const LargeContainer &object);
}; 
#endif /* LARGECONTAINER_H_ */