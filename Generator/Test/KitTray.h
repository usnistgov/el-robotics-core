
#ifndef KITTRAY_H_
#define KITTRAY_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "BoxyObject.h"
 class KitInstance;
 class LargeBoxWithEmptyKitTrays;
 class DAO;
class KitTray: public BoxyObject{private:
std::string hasKitTray_SerialNumber;
std::string hasKitTray_SkuRef;
std::string name;
int KitTrayID;
DAO* dao;
LargeBoxWithEmptyKitTrays* hadByKitTray_LargeBoxWithEmptyKitTrays;
KitInstance* hasKitInstance_Tray;
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
int getKitTrayID();
DAO* getdao();
void setdao(DAO* _dao);
LargeBoxWithEmptyKitTrays* gethadByKitTray_LargeBoxWithEmptyKitTrays();
void sethadByKitTray_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByKitTray_LargeBoxWithEmptyKitTrays);
KitInstance* gethasKitInstance_Tray();
void sethasKitInstance_Tray(KitInstance* _hasKitInstance_Tray);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITTRAY_H_ */