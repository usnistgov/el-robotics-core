
#ifndef PARTSTRAY_H_
#define PARTSTRAY_H_
#include <cstdlib>
#include <iostream>

#include "BoxyObject.h"
 #include "PartsTrayWithParts.h"
 #include "DAO.h"
class PartsTray: public BoxyObject {private:
std::string hasPartsTray_SkuRef;
std::string hasPartsTray_SerialNumber;
std::string name;
int id;
DAO* dao;
PartsTrayWithParts* hadByPartsTray_PartsTrayWithParts;
public:
PartsTray(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, PartsTray* obj);
void set(std::string name, PartsTray* obj);
std::string gethasPartsTray_SkuRef();
void sethasPartsTray_SkuRef(std::string _hasPartsTray_SkuRef);
std::string gethasPartsTray_SerialNumber();
void sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
PartsTrayWithParts* gethadByPartsTray_PartsTrayWithParts();
void sethadByPartsTray_PartsTrayWithParts(PartsTrayWithParts* _hadByPartsTray_PartsTrayWithParts);
void copy(PartsTray const& object);
}; 
#endif /* PARTSTRAY_H_ */