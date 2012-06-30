
#ifndef RELATIVELOCATIONON_H_
#define RELATIVELOCATIONON_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "RelativeLocation.h"
 class DAO;
class RelativeLocationOn: public RelativeLocation{private:
std::string name;
int RelativeLocationOnID;
DAO* dao;
public:
RelativeLocationOn(std::string name);
~RelativeLocationOn();
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocationOn* obj);
void set(std::string name);
std::string getname();
int getRelativeLocationOnID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATIONON_H_ */