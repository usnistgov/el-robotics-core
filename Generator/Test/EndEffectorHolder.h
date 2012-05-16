
#ifndef ENDEFFECTORHOLDER_H_
#define ENDEFFECTORHOLDER_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class EndEffectorHolder: public SolidObject{private:
std::string name;
int EndEffectorHolderID;
DAO* dao;
public:
EndEffectorHolder(std::string name);
~EndEffectorHolder();
 void get(int id);
 void get(std::string name);
void set(int id, EndEffectorHolder* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getEndEffectorHolderID();
void setEndEffectorHolderID(int _EndEffectorHolderID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ENDEFFECTORHOLDER_H_ */