
#ifndef RELATIVELOCATION_H_
#define RELATIVELOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "PhysicalLocation.h"
 class DAO;
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
int getRelativeLocationID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATION_H_ */