
#ifndef VECTOR_H_
#define VECTOR_H_
#include <cstdlib>
#include <iostream>

#include "DataThing.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class Vector: public DataThing{private:
float hasVector_K;
float hasVector_J;
float hasVector_I;
std::string name;
int id;
DAO* dao;
public:
Vector(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, Vector* obj);
void set(std::string name, Vector* obj);
float gethasVector_K();
void sethasVector_K(float _hasVector_K);
float gethasVector_J();
void sethasVector_J(float _hasVector_J);
float gethasVector_I();
void sethasVector_I(float _hasVector_I);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const Vector &object);
}; 
#endif /* VECTOR_H_ */