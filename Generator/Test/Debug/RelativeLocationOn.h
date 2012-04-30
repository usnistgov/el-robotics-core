
#ifndef RELATIVELOCATIONON_H_
#define RELATIVELOCATIONON_H_
#include <cstdlib>
#include <iostream>

#include "RelativeLocation.h"
 #include "DAO.h"
class RelativeLocationOn: public RelativeLocation {private:
std::string hasRelativeLocationOn_Description;
std::string name;
int id;
DAO* dao;
public:
RelativeLocationOn(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocationOn* obj);
void set(std::string name, RelativeLocationOn* obj);
std::string gethasRelativeLocationOn_Description();
void sethasRelativeLocationOn_Description(std::string _hasRelativeLocationOn_Description);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(RelativeLocationOn const& object);
}; 
#endif /* RELATIVELOCATIONON_H_ */