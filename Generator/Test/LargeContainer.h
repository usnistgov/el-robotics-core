
#ifndef LARGECONTAINER_H_
#define LARGECONTAINER_H_
#include <cstdlib>
#include <iostream>
#include <map>

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
int LargeContainerID;
DAO* dao;
LargeBoxWithKits* hadByLargeContainer_LargeBoxWithKits;
LargeBoxWithEmptyKitTrays* hadByLargeContainer_LargeBoxWithEmptyKitTrays;
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
void setname(std::string _name);
int getLargeContainerID();
void setLargeContainerID(int _LargeContainerID);
DAO* getdao();
void setdao(DAO* _dao);
LargeBoxWithKits* gethadByLargeContainer_LargeBoxWithKits();
void sethadByLargeContainer_LargeBoxWithKits(LargeBoxWithKits* _hadByLargeContainer_LargeBoxWithKits);
LargeBoxWithEmptyKitTrays* gethadByLargeContainer_LargeBoxWithEmptyKitTrays();
void sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByLargeContainer_LargeBoxWithEmptyKitTrays);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* LARGECONTAINER_H_ */