
#ifndef PARTSTRAYWITHPARTS_H_
#define PARTSTRAYWITHPARTS_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class DAO;
 class Part;
 class PartsTray;
class PartsTrayWithParts: public SolidObject{private:
std::string name;
int PartsTrayWithPartsID;
DAO* dao;
PartsTray* hasPartsTrayWithParts_Tray;
std::vector<Part*> hadByPart_PartsTrayWithParts;
public:
PartsTrayWithParts(std::string name);
~PartsTrayWithParts();
 void get(int id);
 void get(std::string name);
void set(int id, PartsTrayWithParts* obj);
void set(std::string name);
std::string getname();
int getPartsTrayWithPartsID();
DAO* getdao();
void setdao(DAO* _dao);
PartsTray* gethasPartsTrayWithParts_Tray();
void sethasPartsTrayWithParts_Tray(PartsTray* _hasPartsTrayWithParts_Tray);
std::vector<Part*>* gethadByPart_PartsTrayWithParts();
void sethadByPart_PartsTrayWithParts(std::vector<Part*> _hadByPart_PartsTrayWithParts);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PARTSTRAYWITHPARTS_H_ */