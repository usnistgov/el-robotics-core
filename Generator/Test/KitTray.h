
#ifndef KITTRAY_H_
#define KITTRAY_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "BoxyObject.h"
 #include "KitInstance.h"
 class KitInstance;
 #include "DAO.h"
 class DAO;
 #include <string>
class KitTray: public BoxyObject{private:
std::string hasKitTray_SerialNumber;
std::string hasKitTray_SkuRef;
std::string name;
int KitTrayID;
DAO* dao;
KitInstance* hadByKitTray_KitInstance;
public:
KitTray(std::string name);
~KitTray();
 void get(int id);
 void get(std::string name);
void set(int id, KitTray* obj);
void set(std::string name);
std::string gethasKitTray_SerialNumber();
void sethasKitTray_SerialNumber(std::string _hasKitTray_SerialNumber);
std::string gethasKitTray_SkuRef();
void sethasKitTray_SkuRef(std::string _hasKitTray_SkuRef);
std::string getname();
void setname(std::string _name);
int getKitTrayID();
void setKitTrayID(int _KitTrayID);
DAO* getdao();
void setdao(DAO* _dao);
KitInstance* gethadByKitTray_KitInstance();
void sethadByKitTray_KitInstance(KitInstance* _hadByKitTray_KitInstance);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITTRAY_H_ */