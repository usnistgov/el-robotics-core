
#ifndef VECTOR_H_
#define VECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "DataThing.h"
 class DAO;
class Vector: public DataThing{private:
double hasVector_K;
double hasVector_J;
double hasVector_I;
std::string name;
int VectorID;
DAO* dao;
public:
Vector(std::string name);
~Vector();
 void get(int id);
 void get(std::string name);
void set(int id, Vector* obj);
void set(std::string name);
double gethasVector_K();
void sethasVector_K(double _hasVector_K);
double gethasVector_J();
void sethasVector_J(double _hasVector_J);
double gethasVector_I();
void sethasVector_I(double _hasVector_I);
std::string getname();
int getVectorID();
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* VECTOR_H_ */