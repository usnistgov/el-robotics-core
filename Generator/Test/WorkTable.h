
#ifndef WORKTABLE_H_
#define WORKTABLE_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "BoxyObject.h"
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include "DAO.h"
 class DAO;
 #include <string>
class WorkTable: public BoxyObject{private:
std::string name;
int WorkTableID;
DAO* dao;
KittingWorkstation* hadByWorkTable_Workstation;
public:
WorkTable(std::string name);
~WorkTable();
 void get(int id);
 void get(std::string name);
void set(int id, WorkTable* obj);
void set(std::string name);
std::string getname();
void setname(std::string _name);
int getWorkTableID();
void setWorkTableID(int _WorkTableID);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByWorkTable_Workstation();
void sethadByWorkTable_Workstation(KittingWorkstation* _hadByWorkTable_Workstation);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* WORKTABLE_H_ */