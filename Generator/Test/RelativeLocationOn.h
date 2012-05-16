
#ifndef RELATIVELOCATIONON_H_
#define RELATIVELOCATIONON_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "RelativeLocation.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class RelativeLocationOn: public RelativeLocation{private:
std::string hasRelativeLocationOn_Description;
std::string name;
int RelativeLocationOnID;
DAO* dao;
public:
RelativeLocationOn(std::string name);
~RelativeLocationOn();
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocationOn* obj);
void set(std::string name);
std::string gethasRelativeLocationOn_Description();
void sethasRelativeLocationOn_Description(std::string _hasRelativeLocationOn_Description);
std::string getname();
void setname(std::string _name);
int getRelativeLocationOnID();
void setRelativeLocationOnID(int _RelativeLocationOnID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATIONON_H_ */