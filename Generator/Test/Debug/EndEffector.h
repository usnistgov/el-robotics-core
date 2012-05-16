
#ifndef ENDEFFECTOR_H_
#define ENDEFFECTOR_H_
#include <cstdlib>
#include <iostream>

#include "SolidObject.h"
 #include "DAO.h"
 class DAO;
 #include <string>
class EndEffector: public SolidObject{private:
float hasEndEffector_Weight;
float hasEffector_MaximumLoadWeight;
std::string hasEndEffector_Description;
std::string hasEndEffector_Id;
std::string name;
int id;
DAO* dao;
public:
EndEffector(std::string name);
 void get(int id);
 void get(std::string name);
void set(int id, EndEffector* obj);
void set(std::string name, EndEffector* obj);
float gethasEndEffector_Weight();
void sethasEndEffector_Weight(float _hasEndEffector_Weight);
float gethasEffector_MaximumLoadWeight();
void sethasEffector_MaximumLoadWeight(float _hasEffector_MaximumLoadWeight);
std::string gethasEndEffector_Description();
void sethasEndEffector_Description(std::string _hasEndEffector_Description);
std::string gethasEndEffector_Id();
void sethasEndEffector_Id(std::string _hasEndEffector_Id);
std::string getname();
void setname(std::string _name);
int getid();
void setid(int _id);
DAO* getdao();
void setdao(DAO* _dao);
void copy(const EndEffector &object);
}; 
#endif /* ENDEFFECTOR_H_ */