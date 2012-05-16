
#ifndef GRIPPEREFFECTOR_H_
#define GRIPPEREFFECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "EndEffector.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class GripperEffector: public EndEffector{private:
std::string name;
int GripperEffectorID;
DAO* dao;
public:
GripperEffector(std::string name);
~GripperEffector();
 void get(int id);
 void get(std::string name);
void set(int id, GripperEffector* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getGripperEffectorID();
void setGripperEffectorID(int _GripperEffectorID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* GRIPPEREFFECTOR_H_ */