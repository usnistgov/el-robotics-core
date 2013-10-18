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


#ifndef DAO_H_
#define DAO_H_
#include <cstdlib>
#include <iostream>

#include <map>
#include <vector>
#include <sstream>
#include <typeinfo>

#include "Connection.h"
class DAO {
private:
std::vector<std::string> className;
Connection* connection;
std::vector<std::string> nameDone;
std::map<std::string, std::string> map;
std::string path;
std::string pathmulti;

static std::map<std::string,std::string>getSqlQueriesDataSingle;
static std::map<std::string,std::vector<std::string> > getSqlQueriesDataMulti;
static std::map<std::string,std::vector<std::string> > getSqlQueriesObjectSingle;
static std::map<std::string,std::vector<std::string> > getSqlQueriesObjectMulti;
static std::map<std::string,std::vector<std::string> > setSqlQueries;
static std::map<std::string,std::vector<std::string> > updateSqlQueries;
void fillGetSqlQueries();public:
 DAO(std::string name);
 ~DAO();
std::vector<std::string> getclassName();
void setclassName(std::vector<std::string> _className);
Connection* getconnection();
void setconnection(Connection* _connection);
	std::map<std::string, std::string> get(std::string name);
void set(std::map<std::string,std::string> data);
void insert(std::map<std::string,std::string> data);
std::vector<std::string> Explode(const std::string & str, char separator);
bool toAdd(std::string s);
std::map<std::string, std::vector<std::string> > getAll(std::vector<std::string> attributesList, std::string table);
}; 
#endif /* DAO_H_ */