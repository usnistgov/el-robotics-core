
#ifndef PART_H_
#define PART_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class Part: public SolidObject{private:
std::string hasPart_SerialNumber;
std::string hasPart_SkuRef;
std::string name;
int PartID;
DAO* dao;
public:
Part(std::string name);
~Part();
 void get(int id);
 void get(std::string name);
void set(int id, Part* obj);
void set(std::string name);
std::string gethasPart_SerialNumber();
void sethasPart_SerialNumber(std::string _hasPart_SerialNumber);
std::string gethasPart_SkuRef();
void sethasPart_SkuRef(std::string _hasPart_SkuRef);
std::string getname();
void setname(std::string _name);
int getPartID();
void setPartID(int _PartID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* PART_H_ */