
#ifndef PARTSTRAYWITHPARTS_H_
#define PARTSTRAYWITHPARTS_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
 #include "PartsTray.h"
 class PartsTray;
class PartsTrayWithParts: public SolidObject{private:
std::string name;
int id;
DAO* dao;
PartsTray* hadByPartsTray_PartsTrayWithParts;
public:
PartsTrayWithParts(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, PartsTrayWithParts* obj);
void set(std::string name, PartsTrayWithParts* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
PartsTray* gethadByPartsTray_PartsTrayWithParts();
void sethadByPartsTray_PartsTrayWithParts(PartsTray* _hadByPartsTray_PartsTrayWithParts);
void copy(const PartsTrayWithParts &object);
}; 
#endif /* PARTSTRAYWITHPARTS_H_ */