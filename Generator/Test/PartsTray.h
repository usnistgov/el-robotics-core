
#ifndef PARTSTRAY_H_
#define PARTSTRAY_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "BoxyObject.h"
 #include "PartsTrayWithParts.h"
 class PartsTrayWithParts;
 #include "DAO.h"
 class DAO;
 #include <string>
class PartsTray: public BoxyObject{private:
std::string hasPartsTray_SkuRef;
std::string hasPartsTray_SerialNumber;
std::string name;
int PartsTrayID;
DAO* dao;
PartsTrayWithParts* hadByPartsTray_PartsTrayWithParts;
public:
PartsTray(std::string name);
~PartsTray();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTray* obj);
void set(std::string name);
std::string gethasPartsTray_SkuRef();
void sethasPartsTray_SkuRef(std::string _hasPartsTray_SkuRef);
std::string gethasPartsTray_SerialNumber();
void sethasPartsTray_SerialNumber(std::string _hasPartsTray_SerialNumber);
std::string getname();
void setname(std::string _name);
int getPartsTrayID();
void setPartsTrayID(int _PartsTrayID);
DAO* getdao();
void setdao(DAO* _dao);
PartsTrayWithParts* gethadByPartsTray_PartsTrayWithParts();
void sethadByPartsTray_PartsTrayWithParts(PartsTrayWithParts* _hadByPartsTray_PartsTrayWithParts);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAY_H_ */