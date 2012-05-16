
#ifndef BOXYOBJECT_H_
#define BOXYOBJECT_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class BoxyObject: public SolidObject{private:
float hasBox_Width;
float hasBox_Height;
float hasBox_Length;
std::string name;
int id;
DAO* dao;
public:
BoxyObject(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, BoxyObject* obj);
void set(std::string name, BoxyObject* obj);
float gethasBox_Width();
void sethasBox_Width(float _hasBox_Width);
float gethasBox_Height();
void sethasBox_Height(float _hasBox_Height);
float gethasBox_Length();
void sethasBox_Length(float _hasBox_Length);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const BoxyObject &object);
}; 
#endif /* BOXYOBJECT_H_ */