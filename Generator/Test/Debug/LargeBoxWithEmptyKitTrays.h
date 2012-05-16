
#ifndef LARGEBOXWITHEMPTYKITTRAYS_H_
#define LARGEBOXWITHEMPTYKITTRAYS_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "LargeContainer.h"
 class LargeContainer;
 #include "DAO.h"
 class DAO;
 #include <string>
class LargeBoxWithEmptyKitTrays: public SolidObject{private:
std::string name;
int id;
DAO* dao;
LargeContainer* hadByLargeContainer_LargeBoxWithEmptyKitTrays;
public:
LargeBoxWithEmptyKitTrays(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, LargeBoxWithEmptyKitTrays* obj);
void set(std::string name, LargeBoxWithEmptyKitTrays* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
LargeContainer* gethadByLargeContainer_LargeBoxWithEmptyKitTrays();
void sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeContainer* _hadByLargeContainer_LargeBoxWithEmptyKitTrays);
void copy(const LargeBoxWithEmptyKitTrays &object);
}; 
#endif /* LARGEBOXWITHEMPTYKITTRAYS_H_ */