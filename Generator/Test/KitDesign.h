
#ifndef KITDESIGN_H_
#define KITDESIGN_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "DataThing.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class KitDesign: public DataThing{private:
std::string hasKitDesign_Id;
std::string hasKitDesign_KitTraySkuRef;
std::string name;
int KitDesignID;
DAO* dao;
public:
KitDesign(std::string name);
~KitDesign();
 void get(int id);
 void get(std::string name);
void set(int id, KitDesign* obj);
void set(std::string name);
std::string gethasKitDesign_Id();
void sethasKitDesign_Id(std::string _hasKitDesign_Id);
std::string gethasKitDesign_KitTraySkuRef();
void sethasKitDesign_KitTraySkuRef(std::string _hasKitDesign_KitTraySkuRef);
std::string getname();
void setname(std::string _name);
int getKitDesignID();
void setKitDesignID(int _KitDesignID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* KITDESIGN_H_ */