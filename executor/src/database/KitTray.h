
#ifndef KITTRAY_H_
#define KITTRAY_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "BoxyObject.h"
 class LargeBoxWithEmptyKitTrays;
 class Kit;
 class DAO;
class KitTray: public BoxyObject{private:
std::string hasKitTray_SkuRef;
std::string hasKitTray_SerialNumber;
std::string name;
int KitTrayID;
DAO* dao;
Kit* hasKit_Tray;
LargeBoxWithEmptyKitTrays* hadByKitTray_LargeBoxWithEmptyKitTrays;
public:
KitTray(std::string name);
~KitTray();
 void get(int id);
 void get(std::string name);
void set(int id, KitTray* obj);
void set(std::string name);
std::string gethasKitTray_SkuRef();
void sethasKitTray_SkuRef(std::string _hasKitTray_SkuRef);
std::string gethasKitTray_SerialNumber();
void sethasKitTray_SerialNumber(std::string _hasKitTray_SerialNumber);
std::string getname();
int getKitTrayID();
DAO* getdao();
void setdao(DAO* _dao);
Kit* gethasKit_Tray();
void sethasKit_Tray(Kit* _hasKit_Tray);
LargeBoxWithEmptyKitTrays* gethadByKitTray_LargeBoxWithEmptyKitTrays();
void sethadByKitTray_LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTrays* _hadByKitTray_LargeBoxWithEmptyKitTrays);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITTRAY_H_ */