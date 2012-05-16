
#ifndef WORKTABLE_H_
#define WORKTABLE_H_
#include <cstdlib>
#include <iostream>

#include "BoxyObject.h"
 #include "KittingWorkstation.h"
 class KittingWorkstation;
 #include "DAO.h"
 class DAO;
 #include <string>
class WorkTable: public BoxyObject{private:
std::string name;
int id;
DAO* dao;
KittingWorkstation* hadByWorkTable_Workstation;
public:
WorkTable(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, WorkTable* obj);
void set(std::string name, WorkTable* obj);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
KittingWorkstation* gethadByWorkTable_Workstation();
void sethadByWorkTable_Workstation(KittingWorkstation* _hadByWorkTable_Workstation);
void copy(const WorkTable &object);
}; 
#endif /* WORKTABLE_H_ */