
#ifndef RELATIVELOCATIONIN_H_
#define RELATIVELOCATIONIN_H_
#include <cstdlib>
#include <iostream>

#include "RelativeLocation.h"
 #include "DAO.h"
class RelativeLocationIn: public RelativeLocation {private:
std::string hasRelativeLocationIn_Description;
std::string name;
int id;
DAO* dao;
public:
RelativeLocationIn(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocationIn* obj);
void set(std::string name, RelativeLocationIn* obj);
std::string gethasRelativeLocationIn_Description();
void sethasRelativeLocationIn_Description(std::string _hasRelativeLocationIn_Description);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(RelativeLocationIn const& object);
}; 
#endif /* RELATIVELOCATIONIN_H_ */