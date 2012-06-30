
#ifndef RELATIVELOCATIONIN_H_
#define RELATIVELOCATIONIN_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "RelativeLocation.h"
 class DAO;
class RelativeLocationIn: public RelativeLocation{private:
std::string name;
int RelativeLocationInID;
DAO* dao;
public:
RelativeLocationIn(std::string name);
~RelativeLocationIn();
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocationIn* obj);
void set(std::string name);
std::string getname();
int getRelativeLocationInID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATIONIN_H_ */