
#ifndef DATATHING_H_
#define DATATHING_H_
#include <cstdlib>
#include <iostream>

 #include "DAO.h"
class DataThing {private:
std::string name;
int id;
DAO* dao;
public:
DataThing(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, DataThing* obj);
void set(std::string name, DataThing* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(DataThing const& object);
}; 
#endif /* DATATHING_H_ */