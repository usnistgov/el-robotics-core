
#ifndef KITTRAY_H_
#define KITTRAY_H_
#include <cstdlib>
#include <iostream>

#include "BoxyObject.h"
 #include "KitInstance.h"
 #include "DAO.h"
class KitTray: public BoxyObject {private:
std::string hasKitTray_SerialNumber;
std::string hasKitTray_SkuRef;
std::string name;
int id;
DAO* dao;
KitInstance* hadByKitTray_KitInstance;
public:
KitTray(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, KitTray* obj);
void set(std::string name, KitTray* obj);
std::string gethasKitTray_SerialNumber();
void sethasKitTray_SerialNumber(std::string _hasKitTray_SerialNumber);
std::string gethasKitTray_SkuRef();
void sethasKitTray_SkuRef(std::string _hasKitTray_SkuRef);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
KitInstance* gethadByKitTray_KitInstance();
void sethadByKitTray_KitInstance(KitInstance* _hadByKitTray_KitInstance);
void copy(KitTray const& object);
}; 
#endif /* KITTRAY_H_ */