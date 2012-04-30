
#ifndef PARTSBIN_H_
#define PARTSBIN_H_
#include <cstdlib>
#include <iostream>

#include "BoxyObject.h"
 #include "DAO.h"
class PartsBin: public BoxyObject {private:
std::string hasBin_PartQuantity;
std::string hasBin_PartSkuRef;
std::string name;
int id;
DAO* dao;
public:
PartsBin(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, PartsBin* obj);
void set(std::string name, PartsBin* obj);
std::string gethasBin_PartQuantity();
void sethasBin_PartQuantity(std::string _hasBin_PartQuantity);
std::string gethasBin_PartSkuRef();
void sethasBin_PartSkuRef(std::string _hasBin_PartSkuRef);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(PartsBin const& object);
}; 
#endif /* PARTSBIN_H_ */