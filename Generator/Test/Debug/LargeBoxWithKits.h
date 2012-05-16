
#ifndef LARGEBOXWITHKITS_H_
#define LARGEBOXWITHKITS_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "LargeContainer.h"
 class LargeContainer;
 #include "DAO.h"
 class DAO;
 #include <string>
class LargeBoxWithKits: public SolidObject{private:
std::string hasLargeBoxWithKits_Capacity;
std::string hasLargeBoxWithKits_KitDesignRef;
std::string name;
int id;
DAO* dao;
LargeContainer* hadByLargeContainer_LargeBoxWithKits;
public:
LargeBoxWithKits(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, LargeBoxWithKits* obj);
void set(std::string name, LargeBoxWithKits* obj);
std::string gethasLargeBoxWithKits_Capacity();
void sethasLargeBoxWithKits_Capacity(std::string _hasLargeBoxWithKits_Capacity);
std::string gethasLargeBoxWithKits_KitDesignRef();
void sethasLargeBoxWithKits_KitDesignRef(std::string _hasLargeBoxWithKits_KitDesignRef);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
LargeContainer* gethadByLargeContainer_LargeBoxWithKits();
void sethadByLargeContainer_LargeBoxWithKits(LargeContainer* _hadByLargeContainer_LargeBoxWithKits);
void copy(const LargeBoxWithKits &object);
}; 
#endif /* LARGEBOXWITHKITS_H_ */