
#ifndef ENDEFFECTOR_H_
#define ENDEFFECTOR_H_
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


#include "SolidObject.h"
 class Robot;
 class DAO;
 class EndEffectorHolder;
class EndEffector: public SolidObject{private:
double hasEndEffector_Weight;
double hasEffector_MaximumLoadWeight;
std::string hasEndEffector_Description;
std::string hasEndEffector_Id;
std::string name;
int EndEffectorID;
DAO* dao;
Robot* hadByEndEffector_Robot;
EndEffectorHolder* hasEndEffectorHolder_EndEffector;
public:
EndEffector(std::string name);
~EndEffector();
 void get(int id);
 void get(std::string name);
void set(int id, EndEffector* obj);
void set(std::string name);
double gethasEndEffector_Weight();
void sethasEndEffector_Weight(double _hasEndEffector_Weight);
double gethasEffector_MaximumLoadWeight();
void sethasEffector_MaximumLoadWeight(double _hasEffector_MaximumLoadWeight);
std::string gethasEndEffector_Description();
void sethasEndEffector_Description(std::string _hasEndEffector_Description);
std::string gethasEndEffector_Id();
void sethasEndEffector_Id(std::string _hasEndEffector_Id);
std::string getname();
int getEndEffectorID();
DAO* getdao();
void setdao(DAO* _dao);
Robot* gethadByEndEffector_Robot();
void sethadByEndEffector_Robot(Robot* _hadByEndEffector_Robot);
EndEffectorHolder* gethasEndEffectorHolder_EndEffector();
void sethasEndEffectorHolder_EndEffector(EndEffectorHolder* _hasEndEffectorHolder_EndEffector);
void copy(std::map<std::string,std::string> object);std::vector<std::string> Explode(const std::string & str, char separator );
}; 
#endif /* ENDEFFECTOR_H_ */