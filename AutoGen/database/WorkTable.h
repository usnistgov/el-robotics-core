/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/


#ifndef WORKTABLE_H_
#define WORKTABLE_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "NoSkuObject.h"
 class SolidObject;
 class DAO;
class WorkTable: public NoSkuObject{private:
int WorkTableID;
DAO* dao;
std::vector<SolidObject*> hadByObjectOnTable_WorkTable;
public:
WorkTable(std::string name);
~WorkTable();
 void get(int id);
 void get(std::string name);
void set(int id, WorkTable* obj);
void set(std::string name);
void insert(std::string name);
int getWorkTableID();
void setWorkTableID(int _WorkTableID);
DAO* getdao();
void setdao(DAO* _dao);
std::vector<SolidObject*> gethadByObjectOnTable_WorkTable();
void sethadByObjectOnTable_WorkTable(std::vector<SolidObject*> _hadByObjectOnTable_WorkTable);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* WORKTABLE_H_ */