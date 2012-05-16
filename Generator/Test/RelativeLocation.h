
#ifndef RELATIVELOCATION_H_
#define RELATIVELOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "PhysicalLocation.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class RelativeLocation: public PhysicalLocation{private:
std::string name;
int RelativeLocationID;
DAO* dao;
public:
RelativeLocation(std::string name);
~RelativeLocation();
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocation* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getRelativeLocationID();
void setRelativeLocationID(int _RelativeLocationID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATION_H_ */