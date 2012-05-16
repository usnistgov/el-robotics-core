
#ifndef ENDEFFECTORHOLDER_H_
#define ENDEFFECTORHOLDER_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class EndEffectorHolder: public SolidObject{private:
std::string name;
int id;
DAO* dao;
public:
EndEffectorHolder(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, EndEffectorHolder* obj);
void set(std::string name, EndEffectorHolder* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const EndEffectorHolder &object);
}; 
#endif /* ENDEFFECTORHOLDER_H_ */