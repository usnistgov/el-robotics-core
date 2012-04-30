
#ifndef KITDESIGN_H_
#define KITDESIGN_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
class KitDesign: public DataThing {private:
std::string hasKitDesign_Id;
std::string hasKitDesign_KitTraySkuRef;
std::string name;
int id;
DAO* dao;
public:
KitDesign(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, KitDesign* obj);
void set(std::string name, KitDesign* obj);
std::string gethasKitDesign_Id();
void sethasKitDesign_Id(std::string _hasKitDesign_Id);
std::string gethasKitDesign_KitTraySkuRef();
void sethasKitDesign_KitTraySkuRef(std::string _hasKitDesign_KitTraySkuRef);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(KitDesign const& object);
}; 
#endif /* KITDESIGN_H_ */