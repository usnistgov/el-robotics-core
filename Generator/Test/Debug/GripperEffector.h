
#ifndef GRIPPEREFFECTOR_H_
#define GRIPPEREFFECTOR_H_
#include <cstdlib>
#include <iostream>

#include "EndEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class GripperEffector: public EndEffector{private:
std::string name;
int id;
DAO* dao;
public:
GripperEffector(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, GripperEffector* obj);
void set(std::string name, GripperEffector* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const GripperEffector &object);
}; 
#endif /* GRIPPEREFFECTOR_H_ */