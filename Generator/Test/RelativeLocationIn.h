
#ifndef RELATIVELOCATIONIN_H_
#define RELATIVELOCATIONIN_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "RelativeLocation.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class RelativeLocationIn: public RelativeLocation{private:
std::string hasRelativeLocationIn_Description;
std::string name;
int RelativeLocationInID;
DAO* dao;
public:
RelativeLocationIn(std::string name);
~RelativeLocationIn();
 void get(int id);
 void get(std::string name);
void set(int id, RelativeLocationIn* obj);
void set(std::string name);
std::string gethasRelativeLocationIn_Description();
void sethasRelativeLocationIn_Description(std::string _hasRelativeLocationIn_Description);
std::string getname();
void setname(std::string _name);
int getRelativeLocationInID();
void setRelativeLocationInID(int _RelativeLocationInID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* RELATIVELOCATIONIN_H_ */