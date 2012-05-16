
#ifndef PARTSTRAYWITHPARTS_H_
#define PARTSTRAYWITHPARTS_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
 #include "PartsTray.h"
 class PartsTray;
class PartsTrayWithParts: public SolidObject{private:
std::string name;
int PartsTrayWithPartsID;
DAO* dao;
PartsTray* hadByPartsTray_PartsTrayWithParts;
public:
PartsTrayWithParts(std::string name);
~PartsTrayWithParts();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTrayWithParts* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getPartsTrayWithPartsID();
void setPartsTrayWithPartsID(int _PartsTrayWithPartsID);
DAO* getdao();
void setdao(DAO* _dao);
PartsTray* gethadByPartsTray_PartsTrayWithParts();
void sethadByPartsTray_PartsTrayWithParts(PartsTray* _hadByPartsTray_PartsTrayWithParts);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAYWITHPARTS_H_ */