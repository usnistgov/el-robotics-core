
#ifndef BOXYOBJECT_H_
#define BOXYOBJECT_H_
#include <cstdlib>
#include <iostream>
#include <map>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class BoxyObject: public SolidObject{private:
double hasBox_Width;
double hasBox_Height;
double hasBox_Length;
std::string name;
int BoxyObjectID;
DAO* dao;
public:
BoxyObject(std::string name);
~BoxyObject();
 void get(int id);
 void get(std::string name);
void set(int id, BoxyObject* obj);
void set(std::string name);
double gethasBox_Width();
void sethasBox_Width(double _hasBox_Width);
double gethasBox_Height();
void sethasBox_Height(double _hasBox_Height);
double gethasBox_Length();
void sethasBox_Length(double _hasBox_Length);
std::string getname();
void setname(std::string _name);
int getBoxyObjectID();
void setBoxyObjectID(int _BoxyObjectID);
DAO* getdao();
void setdao(DAO* _dao);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* BOXYOBJECT_H_ */