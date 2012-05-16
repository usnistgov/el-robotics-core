
#ifndef PARTSBIN_H_
#define PARTSBIN_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "BoxyObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class PartsBin: public BoxyObject{private:
std::string hasBin_PartQuantity;
std::string hasBin_PartSkuRef;
std::string name;
int PartsBinID;
DAO* dao;
public:
PartsBin(std::string name);
~PartsBin();
 void get(int id);
 void get(std::string name);
void set(int id, PartsBin* obj);
void set(std::string name);
std::string gethasBin_PartQuantity();
void sethasBin_PartQuantity(std::string _hasBin_PartQuantity);
std::string gethasBin_PartSkuRef();
void sethasBin_PartSkuRef(std::string _hasBin_PartSkuRef);
std::string getname();
void setname(std::string _name);
int getPartsBinID();
void setPartsBinID(int _PartsBinID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSBIN_H_ */