
#ifndef DATATHING_H_
#define DATATHING_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


 class DAO;
class DataThing{private:
std::string name;
int DataThingID;
DAO* dao;
public:
DataThing(std::string name);
~DataThing();
 void get(int id);
 void get(std::string name);
void set(int id, DataThing* obj);
void set(std::string name);
std::string getname();
int getDataThingID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* DATATHING_H_ */