
#ifndef LARGEBOXWITHEMPTYKITTRAYS_H_
#define LARGEBOXWITHEMPTYKITTRAYS_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "LargeContainer.h"
 class LargeContainer;
 #include "DAO.h"
 class DAO;
 #include <string>
class LargeBoxWithEmptyKitTrays: public SolidObject{private:
std::string name;
int LargeBoxWithEmptyKitTraysID;
DAO* dao;
LargeContainer* hadByLargeContainer_LargeBoxWithEmptyKitTrays;
public:
LargeBoxWithEmptyKitTrays(std::string name);
~LargeBoxWithEmptyKitTrays();
 void get(int id);
 void get(std::string name);
void set(int id, LargeBoxWithEmptyKitTrays* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getLargeBoxWithEmptyKitTraysID();
void setLargeBoxWithEmptyKitTraysID(int _LargeBoxWithEmptyKitTraysID);
DAO* getdao();
void setdao(DAO* _dao);
LargeContainer* gethadByLargeContainer_LargeBoxWithEmptyKitTrays();
void sethadByLargeContainer_LargeBoxWithEmptyKitTrays(LargeContainer* _hadByLargeContainer_LargeBoxWithEmptyKitTrays);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* LARGEBOXWITHEMPTYKITTRAYS_H_ */