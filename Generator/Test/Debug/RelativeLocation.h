
#ifndef RELATIVELOCATION_H_
#define RELATIVELOCATION_H_
#include <cstdlib>
#include <iostream>

#include "PhysicalLocation.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class RelativeLocation: public PhysicalLocation{private:
std::string name;
int id;
DAO* dao;
public:
RelativeLocation(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocation* obj);
void set(std::string name, RelativeLocation* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const RelativeLocation &object);
}; 
#endif /* RELATIVELOCATION_H_ */