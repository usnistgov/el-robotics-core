
#ifndef POSEONLYLOCATION_H_
#define POSEONLYLOCATION_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "PoseLocation.h"
 class DAO;
class PoseOnlyLocation: public PoseLocation{private:
std::string name;
int PoseOnlyLocationID;
DAO* dao;
public:
PoseOnlyLocation(std::string name);
~PoseOnlyLocation();
 void get(int id);
 void get(std::string name);
void set(int id, PoseOnlyLocation* obj);
void set(std::string name);
std::string getname();
int getPoseOnlyLocationID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* POSEONLYLOCATION_H_ */