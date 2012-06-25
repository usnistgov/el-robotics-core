
#ifndef KITINSTANCE_H_
#define KITINSTANCE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class LargeBoxWithKits;
 class KitTray;
 class DAO;
 class Part;
class KitInstance: public SolidObject{private:
bool isKitInstance_Finished;
std::string hasKitInstance_DesignRef;
std::string name;
int KitInstanceID;
DAO* dao;
std::vector<Part*> hadByPart_KitInstance;
KitTray* hasKitInstance_Tray;
LargeBoxWithKits* hadByKitInstance_LargeBoxWithKits;
public:
KitInstance(std::string name);
~KitInstance();
 void get(int id);
 void get(std::string name);
void set(int id, KitInstance* obj);
void set(std::string name);
bool getisKitInstance_Finished();
void setisKitInstance_Finished(bool _isKitInstance_Finished);
std::string gethasKitInstance_DesignRef();
void sethasKitInstance_DesignRef(std::string _hasKitInstance_DesignRef);
std::string getname();
int getKitInstanceID();
DAO* getdao();
void setdao(DAO* _dao);
std::vector<Part*>* gethadByPart_KitInstance();
void sethadByPart_KitInstance(std::vector<Part*> _hadByPart_KitInstance);
KitTray* gethasKitInstance_Tray();
void sethasKitInstance_Tray(KitTray* _hasKitInstance_Tray);
LargeBoxWithKits* gethadByKitInstance_LargeBoxWithKits();
void sethadByKitInstance_LargeBoxWithKits(LargeBoxWithKits* _hadByKitInstance_LargeBoxWithKits);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITINSTANCE_H_ */