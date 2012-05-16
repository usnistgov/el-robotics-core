
#ifndef LARGEBOXWITHKITS_H_
#define LARGEBOXWITHKITS_H_
#include <cstdlib>
#include <iostream>
#include <map>

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
int LargeBoxWithKitsID;
DAO* dao;
LargeContainer* hadByLargeContainer_LargeBoxWithKits;
public:
LargeBoxWithKits(std::string name);
~LargeBoxWithKits();
 void get(int id);
 void get(std::string name);
void set(int id, LargeBoxWithKits* obj);
void set(std::string name);
std::string gethasLargeBoxWithKits_Capacity();
void sethasLargeBoxWithKits_Capacity(std::string _hasLargeBoxWithKits_Capacity);
std::string gethasLargeBoxWithKits_KitDesignRef();
void sethasLargeBoxWithKits_KitDesignRef(std::string _hasLargeBoxWithKits_KitDesignRef);
std::string getname();
void setname(std::string _name);
int getLargeBoxWithKitsID();
void setLargeBoxWithKitsID(int _LargeBoxWithKitsID);
DAO* getdao();
void setdao(DAO* _dao);
LargeContainer* gethadByLargeContainer_LargeBoxWithKits();
void sethadByLargeContainer_LargeBoxWithKits(LargeContainer* _hadByLargeContainer_LargeBoxWithKits);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* LARGEBOXWITHKITS_H_ */