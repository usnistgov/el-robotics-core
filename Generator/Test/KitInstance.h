
#ifndef KITINSTANCE_H_
#define KITINSTANCE_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "KitTray.h"
 class KitTray;
 #include "DAO.h"
 class DAO;
 #include <string>
class KitInstance: public SolidObject{private:
bool isKitInstance_Finished;
std::string hasKitInstance_DesignRef;
std::string name;
int KitInstanceID;
DAO* dao;
KitTray* hadByKitTray_KitInstance;
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
void setname(std::string _name);
int getKitInstanceID();
void setKitInstanceID(int _KitInstanceID);
DAO* getdao();
void setdao(DAO* _dao);
KitTray* gethadByKitTray_KitInstance();
void sethadByKitTray_KitInstance(KitTray* _hadByKitTray_KitInstance);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITINSTANCE_H_ */